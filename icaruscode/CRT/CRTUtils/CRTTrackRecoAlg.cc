#include "CRTTrackRecoAlg.h"

using namespace icarus::crt;

CRTTrackRecoAlg::CRTTrackRecoAlg(const Config& config)
  : hitAlg() {
 
  this->reconfigure(config);
  
  fGeometryService = lar::providerFrom<geo::Geometry>();

}

CRTTrackRecoAlg::CRTTrackRecoAlg(double aveHitDist, double distLim)
  : hitAlg() {

  fAverageHitDistance = aveHitDist;
  fDistanceLimit = distLim;
  fGeometryService = lar::providerFrom<geo::Geometry>();
}

CRTTrackRecoAlg::~CRTTrackRecoAlg(){}

void CRTTrackRecoAlg::reconfigure(const Config& config){

  fTimeLimit          = config.TimeLimit();
  fAverageHitDistance = config.AverageHitDistance();
  fDistanceLimit      = config.DistanceLimit();

  return;

}

std::vector<std::vector<art::Ptr<sbn::crt::CRTHit>>> CRTTrackRecoAlg::CreateCRTTzeros(std::vector<art::Ptr<sbn::crt::CRTHit>> hits)
{

  std::vector<std::vector<art::Ptr<sbn::crt::CRTHit>>> crtTzeroVect;
  int iflag[2000] = {};

  // Sort CRTHits by time
  std::sort(hits.begin(), hits.end(), [](auto& left, auto& right)->bool{
              return left->ts0_ns < right->ts0_ns;});

  // Loop over crt hits
  for(size_t i = 0; i<hits.size(); i++){
      //if hit unused
      if(iflag[i] == 0){
	vector<art::Ptr<sbn::crt::CRTHit>> crtTzero;
          double time_ns_A = hits[i]->ts0_ns;
          iflag[i]=1;
          crtTzero.push_back(hits[i]);

          // Sort into a Tzero collection
          // Loop over all the other CRT hits
          for(size_t j = i+1; j<hits.size(); j++){

              //if hit unused
              if(iflag[j] == 0){
                  // If ts1_ns - ts1_ns < diff then put them in a vector
                  double time_ns_B = hits[j]->ts0_ns;
                  double diff = std::abs(time_ns_B - time_ns_A) * 1e-3; // [us]
                  if(diff < fTimeLimit){
                      iflag[j] = 1; //mark hit used
                      crtTzero.push_back(hits[j]);
                  }
              }
          }

          crtTzeroVect.push_back(crtTzero);
      }//endif hit unused
  }
  return crtTzeroVect;
}//CRTTrackRecoAlg::CreateCRTTzeros

// Function to make creating CRTTracks easier
sbn::crt::CRTTrack CRTTrackRecoAlg::FillCrtTrack(sbn::crt::CRTHit hit1, sbn::crt::CRTHit hit2, bool complete)
{
  sbn::crt::CRTTrack newtr;
  newtr.ts0_s         = (hit1.ts0_s + hit2.ts0_s)/2.;
  newtr.ts0_s_err     = (uint32_t)((hit1.ts0_s - hit2.ts0_s)/2.);
  newtr.ts0_ns_h1     = hit1.ts0_ns;
  newtr.ts0_ns_err_h1 = hit1.ts0_ns_corr;
  newtr.ts0_ns_h2     = hit2.ts0_ns;
  newtr.ts0_ns_err_h2 = hit2.ts0_ns_corr;
  newtr.ts0_ns        = (uint32_t)((hit1.ts0_ns + hit2.ts0_ns)/2.);
  newtr.ts0_ns_err    = (uint16_t)(sqrt(hit1.ts0_ns_corr*hit1.ts0_ns_corr + hit2.ts0_ns_corr*hit2.ts0_ns_corr)/2.);
  newtr.ts1_ns        = (int32_t)(((double)(int)hit1.ts1_ns + (double)(int)hit2.ts1_ns)/2.);
  newtr.ts1_ns_err    = (uint16_t)(sqrt(hit1.ts0_ns_corr*hit1.ts0_ns_corr + hit2.ts0_ns_corr*hit2.ts0_ns_corr)/2.);
  newtr.peshit        = hit1.peshit+hit2.peshit;
  newtr.x1_pos        = hit1.x_pos;
  newtr.x1_err        = hit1.x_err;
  newtr.y1_pos        = hit1.y_pos;
  newtr.y1_err        = hit1.y_err;
  newtr.z1_pos        = hit1.z_pos;
  newtr.z1_err        = hit1.z_err;
  newtr.x2_pos        = hit2.x_pos;
  newtr.x2_err        = hit2.x_err;
  newtr.y2_pos        = hit2.y_pos;
  newtr.y2_err        = hit2.y_err;
  newtr.z2_pos        = hit2.z_pos;
  newtr.z2_err        = hit2.z_err;
  float deltax        = hit1.x_pos - hit2.x_pos;
  float deltay        = hit1.y_pos - hit2.y_pos;
  float deltaz        = hit1.z_pos - hit2.z_pos;
  newtr.length        = sqrt(deltax*deltax + deltay*deltay+deltaz*deltaz);
  newtr.thetaxy       = atan2(deltax,deltay);
  newtr.phizy         = atan2(deltaz,deltay);
  newtr.plane1        = hit1.plane;
  newtr.plane2        = hit2.plane;
  newtr.complete      = complete;

  return(newtr);

} // CRTTrackRecoAlg::FillCrtTrack()

// Function to average hits within a certain distance of each other w/associations
vector<pair<sbn::crt::CRTHit, vector<int>>> CRTTrackRecoAlg::AverageHits(vector<art::Ptr<sbn::crt::CRTHit>> hits, map<art::Ptr<sbn::crt::CRTHit>, int> hitIds)
{
    vector<pair<sbn::crt::CRTHit, vector<int>>> returnHits;
    vector<art::Ptr<sbn::crt::CRTHit>> aveHits;
    vector<art::Ptr<sbn::crt::CRTHit>> spareHits;

    //if we have CRTHits
    if (hits.size()>0){

        bool first = true;
        TVector3 middle(0., 0., 0.);

        //loop over CRTHits
        for (size_t i = 0; i < hits.size(); i++){
            // Get the position of the hit
            TVector3 pos(hits[i]->x_pos, hits[i]->y_pos, hits[i]->z_pos);
            // If first then set average = hit pos
            if(first){
                middle = pos;
                first = false;
            }
            // If distance from average < limit then add to average
            if((pos-middle).Mag() < fAverageHitDistance){
                aveHits.push_back(hits[i]);
            }
            // Else add to another vector
            else{
                spareHits.push_back(hits[i]);
            }
        }

	//std::cout << "size of aveHits: " << aveHits.size() << std::endl;
	// Checking if we have Average CRTHits
	if (aveHits.size() > 0){ 
	  //aveHit = DoAverage(aveHits);
	  sbn::crt::CRTHit aveHit = DoAverage(aveHits);
	  vector<int> ids;
        for(size_t i = 0; i < aveHits.size(); i++){
            ids.push_back(hitIds[aveHits[i]]);
        }

        returnHits.push_back(std::make_pair(aveHit, ids));

        //Do this recursively
        vector<pair<sbn::crt::CRTHit, vector<int>>> moreHits = AverageHits(spareHits, hitIds);
        returnHits.insert(returnHits.end(), moreHits.begin(), moreHits.end());
	}
        return returnHits;
       
    }//endif hits
    else { //no hits returns empty vector
        return returnHits;
    }

} // CRTTrackRecoAlg::AverageHits()

//average clustered CRTHits together (w/o keeping associations)
vector<sbn::crt::CRTHit> CRTTrackRecoAlg::AverageHits(vector<art::Ptr<sbn::crt::CRTHit>> hits)
{
    vector<sbn::crt::CRTHit> returnHits;
    vector<art::Ptr<sbn::crt::CRTHit>> aveHits;
    vector<art::Ptr<sbn::crt::CRTHit>> spareHits;

    if (hits.size()>0){
        // loop over size of tx
        bool first = true;
        TVector3 middle(0., 0., 0.);
        for (size_t i = 0; i < hits.size(); i++){
            // Get the position of the hit
            TVector3 pos(hits[i]->x_pos, hits[i]->y_pos, hits[i]->z_pos);
            // If first then set average = hit pos
            if(first){
                middle = pos;
                first = false;
            }
            // If distance from average < limit then add to average
            if((pos-middle).Mag() < fAverageHitDistance){
                aveHits.push_back(hits[i]);
            }
            // Else add to another vector
            else{
                spareHits.push_back(hits[i]);
            }
        }
        sbn::crt::CRTHit aveHit = DoAverage(aveHits);
        returnHits.push_back(aveHit);

        //Do this recursively
        vector<sbn::crt::CRTHit> moreHits = AverageHits(spareHits);
        returnHits.insert(returnHits.end(), moreHits.begin(), moreHits.end());

        return returnHits;

    }
    else {
        return returnHits;
    }
} // CRTTrackRecoAlg::AverageHits()
  
// Take a list of hits and find average parameters
sbn::crt::CRTHit CRTTrackRecoAlg::DoAverage(vector<art::Ptr<sbn::crt::CRTHit>> hits)
{
  //std::cout << "hits inside CRTTrackRecoAlg::DoAverage:++++++++++++++++ "<< hits[0] << std::endl;
  // Initialize values
  std::string tagger = hits[0]->tagger;
  double xpos = 0.; 
  double ypos = 0.;
  double zpos = 0.;
  double xmax = -99999; double xmin = 99999;
  double ymax = -99999; double ymin = 99999;
  double zmax = -99999; double zmin = 99999;
  double ts0_ns = 0., ts1_ns = 0.;
  int nhits = 0;

  // Loop over hits
  for( auto& hit : hits ){
      // Get the mean x,y,z and times
      xpos += hit->x_pos;
      ypos += hit->y_pos;
      zpos += hit->z_pos;
      ts0_ns += (double)(int)hit->ts0_ns;
      ts1_ns += (double)(int)hit->ts1_ns;
      // For the errors get the maximum limits
      if(hit->x_pos + hit->x_err > xmax) xmax = hit->x_pos + hit->x_err;
      if(hit->x_pos - hit->x_err < xmin) xmin = hit->x_pos - hit->x_err;
      if(hit->y_pos + hit->y_err > ymax) ymax = hit->y_pos + hit->y_err;
      if(hit->y_pos - hit->y_err < ymin) ymin = hit->y_pos - hit->y_err;
      if(hit->z_pos + hit->z_err > zmax) zmax = hit->z_pos + hit->z_err;
      if(hit->z_pos - hit->z_err < zmin) zmin = hit->z_pos - hit->z_err;
      // Add all the unique IDs in the vector
      nhits++;
  }

  // Create a hit
  sbn::crt::CRTHit crtHit = hitAlg.FillCRTHit(hits[0]->feb_id, hits[0]->pesmap, hits[0]->peshit, 
                                  (ts0_ns/nhits)*1e-3, (ts1_ns/nhits)*1e-3, hits[0]->plane, xpos/nhits, (xmax-xmin)/2,
                                  ypos/nhits, (ymax-ymin)/2., zpos/nhits, (zmax-zmin)/2., tagger);

  //  std::cout << "hits inside CRTTrackRecoAlg::DoAverage:++++++++++++++++ returning......... line 251"  << std::endl;
  return crtHit;

} // CRTTrackRecoAlg::DoAverage()

// Function to create tracks from tzero hit collections
vector<pair<sbn::crt::CRTTrack, vector<int>>> CRTTrackRecoAlg::CreateTracks(vector<pair<sbn::crt::CRTHit, vector<int>>> hits)
{
    vector<pair<sbn::crt::CRTTrack, vector<int>>> returnTracks;

    //Store list of hit pairs with distance between them
    vector<pair<pair<size_t, size_t>, double>> hitPairDist;
    vector<pair<size_t, size_t>> usedPairs;

    //Calculate the distance between all hits on different planes
    for(size_t i = 0; i < hits.size(); i++){

        sbn::crt::CRTHit hit1 = hits[i].first;

        for(size_t j = 0; j < hits.size(); j++){

            sbn::crt::CRTHit hit2 = hits[j].first;
            pair<size_t, size_t> hitPair = std::make_pair(i, j);
            pair<size_t, size_t> rhitPair = std::make_pair(j, i);

            //Only compare hits on different taggers and don't reuse hits
            if(hit1.tagger!=hit2.tagger && std::find(usedPairs.begin(), usedPairs.end(), rhitPair)==usedPairs.end()){
                //Calculate the distance between hits and store
                TVector3 pos1(hit1.x_pos, hit1.y_pos, hit1.z_pos);
                TVector3 pos2(hit2.x_pos, hit2.y_pos, hit2.z_pos);
                double dist = (pos1 - pos2).Mag();
                usedPairs.push_back(hitPair);
                hitPairDist.push_back(std::make_pair(hitPair, dist));
            }
        }
    }

    //Sort map by distance
    std::sort(hitPairDist.begin(), hitPairDist.end(), [](auto& left, auto& right){
              return left.second > right.second;});

    //Store potential hit collections + distance along 1D hit
    vector<pair<vector<size_t>, double>> tracks;
    for(size_t i = 0; i < hitPairDist.size(); i++){

        size_t hit_i = hitPairDist[i].first.first;
        size_t hit_j = hitPairDist[i].first.second;

        //Make sure bottom plane hit is always hit_i
        if(hits[hit_j].first.tagger=="volTaggerBot_0") std::swap(hit_i, hit_j);
        sbn::crt::CRTHit ihit = hits[hit_i].first;
        sbn::crt::CRTHit jhit = hits[hit_j].first;

        //If the bottom plane hit is a 1D hit
        if(ihit.x_err>100. || ihit.z_err>100.){

            double facMax = 1;
            vector<size_t> nhitsMax;
            double minDist = 99999;

            //Loop over the length of the 1D hit
            for(int i = 0; i<21; i++){

                double fac = (i)/10.;
                vector<size_t> nhits;
                double totalDist = 0.;
                TVector3 start(ihit.x_pos-(1.-fac)*ihit.x_err, ihit.y_pos, ihit.z_pos-(1.-fac)*ihit.z_err);
                TVector3 end(jhit.x_pos, jhit.y_pos, jhit.z_pos);
                TVector3 diff = start - end;

                //Loop over the rest of the hits
                for(size_t k = 0; k < hits.size(); k++){

                    if(k == hit_i || k == hit_j || hits[k].first.tagger == ihit.tagger || hits[k].first.tagger == jhit.tagger) 
                        continue;

                    //Calculate the distance between the track crossing point and the true hit
                    sbn::crt::CRTHit khit = hits[k].first;
                    TVector3 mid(khit.x_pos, khit.y_pos, khit.z_pos);
                    TVector3 cross = CrossPoint(khit, start, diff);
                    double dist = (cross-mid).Mag();

                    //If the distance is less than some limit add the hit to the track and record the distance
                    if(dist < fDistanceLimit){
                      nhits.push_back(k);
                      totalDist += dist;
                    }
                }

                //If the distance down the 1D hit means more hits are included and they are closer to the track record it
                if(nhits.size()>=nhitsMax.size() && totalDist/nhits.size() < minDist){
                    nhitsMax = nhits;
                    facMax = fac;
                    minDist = totalDist/nhits.size();
                }
                nhits.clear();
            }

            //Record the track candidate
            vector<size_t> trackCand;
            trackCand.push_back(hit_i);
            trackCand.push_back(hit_j);
            trackCand.insert(trackCand.end(), nhitsMax.begin(), nhitsMax.end());
            tracks.push_back(std::make_pair(trackCand, facMax));
        }

        //If there is no 1D hit
        else{
            TVector3 start(ihit.x_pos, ihit.y_pos, ihit.z_pos);
            TVector3 end(jhit.x_pos, jhit.y_pos, jhit.z_pos);
            TVector3 diff = start - end;
            vector<size_t> trackCand;
            trackCand.push_back(hit_i);
            trackCand.push_back(hit_j);

            //Loop over all the other hits
            for(size_t k = 0; k < hits.size(); k++){

                if(k == hit_i || k == hit_j || hits[k].first.tagger == ihit.tagger || hits[k].first.tagger == jhit.tagger) 
                    continue;

                //Calculate distance to other hits not on the planes of the track hits
		sbn::crt::CRTHit khit = hits[k].first;
                TVector3 mid(khit.x_pos, khit.y_pos, khit.z_pos);
                TVector3 cross = CrossPoint(khit, start, diff);
                double dist = (cross-mid).Mag();

                //Record any within a certain distance
                if(dist < fDistanceLimit){
                  trackCand.push_back(k);
                }
            }
            tracks.push_back(std::make_pair(trackCand, 1));
        }
    }

    //Sort track candidates by number of hits
    std::sort(tracks.begin(), tracks.end(), [](auto& left, auto& right){
              return left.first.size() > right.first.size();});

    //Record used hits
    vector<size_t> usedHits;

    //Loop over candidates
    for(auto& track : tracks){

        size_t hit_i = track.first[0];
        size_t hit_j = track.first[1];

        // Make sure the first hit is the top high tagger if there are only two hits
        if(hits[hit_j].first.tagger=="volTaggerTopHigh_0") 
            std::swap(hit_i, hit_j);

        sbn::crt::CRTHit ihit = hits[hit_i].first;
        sbn::crt::CRTHit jhit = hits[hit_j].first;

        //Check no hits in track have been used
        bool used = false;

        //Loop over hits in track candidate
        for(size_t i = 0; i < track.first.size(); i++){
            //Check if any of the hits have been used
            if(std::find(usedHits.begin(), usedHits.end(), track.first[i]) != usedHits.end()) 
                used=true;
        }
        //If any of the hits have already been used skip this track
        if(used) 
            continue;

        ihit.x_pos -= (1.-track.second)*ihit.x_err;
        ihit.z_pos -= (1.-track.second)*ihit.z_err;

        //Create track
        sbn::crt::CRTTrack crtTrack = FillCrtTrack(ihit, jhit, true);

        //If only the top two planes are hit create an incomplete/stopping track
        if(track.first.size()==2 && ihit.tagger == "volTaggerTopHigh_0" && jhit.tagger == "volTaggerTopLow_0"){ 
            crtTrack.complete = false;
        }
  
        vector<int> ids;
        for(size_t i = 0; i < track.first.size(); i++){
            ids.insert(ids.end(), hits[i].second.begin(), hits[i].second.end());
        }

        returnTracks.push_back(std::make_pair(crtTrack, ids));

        //Record which hits were used only if the track has more than two hits
        //If there are multiple 2 hit tracks there is no way to distinguish between them
        //TODO: Add charge matching for ambiguous cases
        for(size_t i = 0; i < track.first.size(); i++){
            if(track.first.size()>2) usedHits.push_back(track.first[i]);
        }
    }
    return returnTracks;

} // CRTTrackRecoAlg::CreateTracks()

//Create tracks from CRTHits
vector<sbn::crt::CRTTrack> CRTTrackRecoAlg::CreateTracks(vector<sbn::crt::CRTHit> hits)
{
    vector<sbn::crt::CRTTrack> returnTracks;
    //Store list of hit pairs with distance between them
    vector<pair<pair<size_t, size_t>, double>> hitPairDist;
    vector<pair<size_t, size_t>> usedPairs;

    //Calculate the distance between all hits on different planes
    for(size_t i = 0; i < hits.size(); i++){
        sbn::crt::CRTHit hit1 = hits[i];
        for(size_t j = 0; j < hits.size(); j++){

            sbn::crt::CRTHit hit2 = hits[j];
            pair<size_t, size_t> hitPair = std::make_pair(i, j);
            pair<size_t, size_t> rhitPair = std::make_pair(j, i);

            //Only compare hits on different taggers and don't reuse hits
            if(hit1.tagger!=hit2.tagger && std::find(usedPairs.begin(), usedPairs.end(), rhitPair)==usedPairs.end()){
                //Calculate the distance between hits and store
                TVector3 pos1(hit1.x_pos, hit1.y_pos, hit1.z_pos);
                TVector3 pos2(hit2.x_pos, hit2.y_pos, hit2.z_pos);
                double dist = (pos1 - pos2).Mag();
                usedPairs.push_back(hitPair);
                hitPairDist.push_back(std::make_pair(hitPair, dist));
            }
        }
    }

    //Sort map by distance
    std::sort(hitPairDist.begin(), hitPairDist.end(), [](auto& left, auto& right){
              return left.second > right.second;});

    //Store potential hit collections + distance along 1D hit
    vector<pair<vector<size_t>, double>> tracks;
    for(size_t i = 0; i < hitPairDist.size(); i++){

        size_t hit_i = hitPairDist[i].first.first;
        size_t hit_j = hitPairDist[i].first.second;

        //Make sure bottom plane hit is always hit_i
        if(hits[hit_j].tagger=="volTaggerBot_0") 
            std::swap(hit_i, hit_j);

        sbn::crt::CRTHit ihit = hits[hit_i];
        sbn::crt::CRTHit jhit = hits[hit_j];

        //If the bottom plane hit is a 1D hit
        if(ihit.x_err>100. || ihit.z_err>100.){

            double facMax = 1;
            vector<size_t> nhitsMax;
            double minDist = 99999;

            //Loop over the length of the 1D hit
            for(int i = 0; i<21; i++){

                double fac = (i)/10.;
                vector<size_t> nhits;
                double totalDist = 0.;
                TVector3 start(ihit.x_pos-(1.-fac)*ihit.x_err, ihit.y_pos, ihit.z_pos-(1.-fac)*ihit.z_err);
                TVector3 end(jhit.x_pos, jhit.y_pos, jhit.z_pos);
                TVector3 diff = start - end;

                //Loop over the rest of the hits
                for(size_t k = 0; k < hits.size(); k++){

                    if(k == hit_i || k == hit_j || hits[k].tagger == ihit.tagger || hits[k].tagger == jhit.tagger) 
                        continue;

                    //Calculate the distance between the track crossing point and the true hit
                    sbn::crt::CRTHit khit = hits[k];
                    TVector3 mid(khit.x_pos, khit.y_pos, khit.z_pos);
                    TVector3 cross = CrossPoint(khit, start, diff);
                    double dist = (cross-mid).Mag();

                    //If the distance is less than some limit add the hit to the track and record the distance
                    if(dist < fDistanceLimit){
                        nhits.push_back(k);
                        totalDist += dist;
                    }
                }
                //If the distance down the 1D hit means more hits are included and they are closer to the track record it
                if(nhits.size()>=nhitsMax.size() && totalDist/nhits.size() < minDist){
                    nhitsMax = nhits;
                    facMax = fac;
                    minDist = totalDist/nhits.size();
                }
                nhits.clear();
            }
            //Record the track candidate
            vector<size_t> trackCand;
            trackCand.push_back(hit_i);
            trackCand.push_back(hit_j);
            trackCand.insert(trackCand.end(), nhitsMax.begin(), nhitsMax.end());
            tracks.push_back(std::make_pair(trackCand, facMax));
        }
        //If there is no 1D hit
        else{
            TVector3 start(ihit.x_pos, ihit.y_pos, ihit.z_pos);
            TVector3 end(jhit.x_pos, jhit.y_pos, jhit.z_pos);
            TVector3 diff = start - end;
            vector<size_t> trackCand;
            trackCand.push_back(hit_i);
            trackCand.push_back(hit_j);

            //Loop over all the other hits
            for(size_t k = 0; k < hits.size(); k++){

                if(k == hit_i || k == hit_j || hits[k].tagger == ihit.tagger || hits[k].tagger == jhit.tagger) 
                    continue;

                //Calculate distance to other hits not on the planes of the track hits
		sbn::crt::CRTHit khit = hits[k];
                TVector3 mid(khit.x_pos, khit.y_pos, khit.z_pos);
                TVector3 cross = CrossPoint(khit, start, diff);
                double dist = (cross-mid).Mag();

                //Record any within a certain distance
                if(dist < fDistanceLimit){
                    trackCand.push_back(k);
                }
            }
            tracks.push_back(std::make_pair(trackCand, 1));
        }
    }

    //Sort track candidates by number of hits
    std::sort(tracks.begin(), tracks.end(), [](auto& left, auto& right){
              return left.first.size() > right.first.size();});

    //Record used hits
    vector<size_t> usedHits;

    //Loop over candidates
    for(auto& track : tracks){

        size_t hit_i = track.first[0];
        size_t hit_j = track.first[1];

        // Make sure the first hit is the top high tagger if there are only two hits
        if(hits[hit_j].tagger=="volTaggerTopHigh_0") 
            std::swap(hit_i, hit_j);

        sbn::crt::CRTHit ihit = hits[hit_i];
        sbn::crt::CRTHit jhit = hits[hit_j];

        //Check no hits in track have been used
        bool used = false;
        //Loop over hits in track candidate
        for(size_t i = 0; i < track.first.size(); i++){
            //Check if any of the hits have been used
            if(std::find(usedHits.begin(), usedHits.end(), track.first[i]) != usedHits.end()) 
                used=true;
        }
        //If any of the hits have already been used skip this track
        if(used) 
            continue;
        ihit.x_pos -= (1.-track.second)*ihit.x_err;
        ihit.z_pos -= (1.-track.second)*ihit.z_err;

        //Create track
        sbn::crt::CRTTrack crtTrack = FillCrtTrack(ihit, jhit, true);

        //If only the top two planes are hit create an incomplete/stopping track
        if(track.first.size()==2 && ihit.tagger == "volTaggerTopHigh_0" && jhit.tagger == "volTaggerTopLow_0"){ 
            crtTrack.complete = false;
        }

        returnTracks.push_back(crtTrack);

        //Record which hits were used only if the track has more than two hits
        //If there are multiple 2 hit tracks there is no way to distinguish between them
        //TODO: Add charge matching for ambiguous cases
        for(size_t i = 0; i < track.first.size(); i++){
            if(track.first.size()>2) usedHits.push_back(track.first[i]);
        }
    }
 
   return returnTracks;

} // CRTTrackRecoAlg::CreateTracks()

// Function to calculate the crossing point of a track and tagger
TVector3 CRTTrackRecoAlg::CrossPoint(sbn::crt::CRTHit hit, TVector3 start, TVector3 diff)//FIXME change to DCA
{
    TVector3 cross;
    // Use the error to get the fixed coordinate of a tagger
    // FIXME: can this be done better?
    if(hit.x_err > 0.39 && hit.x_err < 0.41){
        double xc = hit.x_pos;
        TVector3 crossp(xc, 
                        ((xc - start.X()) / (diff.X()) * diff.Y()) + start.Y(), 
                        ((xc - start.X()) / (diff.X()) * diff.Z()) + start.Z());
        cross = crossp;
    }
    else if(hit.y_err > 0.39 && hit.y_err < 0.41){
        double yc = hit.y_pos;
        TVector3 crossp(((yc - start.Y()) / (diff.Y()) * diff.X()) + start.X(), 
                        yc, 
                        ((yc - start.Y()) / (diff.Y()) * diff.Z()) + start.Z());
        cross = crossp;
    }
    else if(hit.z_err > 0.39 && hit.z_err < 0.41){
        double zc = hit.z_pos;
        TVector3 crossp(((zc - start.Z()) / (diff.Z()) * diff.X()) + start.X(), 
                        ((zc - start.Z()) / (diff.Z()) * diff.Y()) + start.Y(), 
                        zc);
        cross = crossp;
    }

    return cross;

} // CRTTrackRecoAlg::CrossPoint()

