art_make( ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
             LIB_LIBRARIES larcorealg::Geometry
                           larcore::Geometry_Geometry_service
                           larsim::Simulation lardataobj::Simulation
                           larsim::MCCheater_BackTrackerService_service
                           larsim::MCCheater_ParticleInventoryService_service
                           lardata::Utilities
                           larevt::Filters
                           lardataobj::RawData
                           lardataobj::RecoBase
                           lardata::RecoObjects
                           larpandora::LArPandoraInterface
                           nusimdata::SimulationBase
                           cetlib::cetlib cetlib_except::cetlib_except
                           art::Framework_Core
                           art::Framework_Principal
                           art::Framework_Services_Registry
                           art_root_io::tfile_support ROOT::Core
                           art_root_io::TFileService_service
                           art::Persistency_Common canvas::canvas
                           art::Persistency_Provenance
                           art::Utilities
                           messagefacility::MF_MessageLogger
                           messagefacility::headers
                           fhiclcpp::fhiclcpp
                           ROOT::Geom
                           ROOT::XMLIO
                           ROOT::Gdml
                           ${ROOT_LIBRARIES}
                           Boost::system
        )

install_headers()
install_fhicl()
install_source()


#art_make( ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
#	  LIB_LIBRARIES larcorealg::Geometry
#	  	        larcore::Geometry_Geometry_service
#		        larsim_Simulation nurandom_ParticleNavigation lardataobj::Simulation
# 	  	        larsim::MCCheater_BackTracker_service
#	  	        lardata::Utilities
#larevt::Filters
#	  	        lardataobj::RawData
#	  	        lardataobj::RecoBase
#	  	        lardata::RecoObjects
#larreco_RecoAlg
#larreco_Calorimetry
#larpandora_LArPandoraInterface
#          	        nusimdata::SimulationBase
#          	        ${LARRECO_LIB}
#          	        ${LARDATA_LIB}
#	  	        messagefacility::MF_MessageLogger
#	  	        messagefacility::headers
#	  	        fhiclcpp::fhiclcpp
#	  	        cetlib::cetlib cetlib_except::cetlib_except
#          	        ROOT::Geom
#          	        ROOT::XMLIO
#          	        ROOT::Gdml
#	  	        ${ROOT_LIBRARIES}
#	  MODULE_LIBRARIES RecoUtils
#          	           art::Framework_Core
#	  	           art::Framework_Principal
#		       	   art::Framework_Services_Registry
#	  	       	   art_root_io::tfile_support ROOT::Core
#			   art_root_io::TFileService_service
#	  	           art::Persistency_Common canvas
#	  	           art::Persistency_Provenance canvas
#	  	           art::Utilities canvas
#        )
#
#install_headers()
##install_fhicl()
#install_source()
##install_scripts()
