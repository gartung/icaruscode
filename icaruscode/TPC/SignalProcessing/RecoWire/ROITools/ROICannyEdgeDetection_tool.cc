////////////////////////////////////////////////////////////////////////
/// \file   ROICannyEdgeDetection.cc
/// \author T. Usher
////////////////////////////////////////////////////////////////////////

#include <cmath>
#include "icaruscode/TPC/SignalProcessing/RecoWire/ROITools/IROILocator.h"
#include "art/Utilities/ToolMacros.h"
#include "art/Utilities/make_tool.h"
#include "art_root_io/TFileService.h"
#include "messagefacility/MessageLogger/MessageLogger.h"
#include "cetlib_except/exception.h"
#include "lardata/DetectorInfoServices/DetectorPropertiesService.h"
#include "larcore/Geometry/Geometry.h"
#include "icarus_signal_processing/WaveformTools.h"
#include "icarus_signal_processing/Denoising.h"
#include "icarus_signal_processing/ROIFinder2D.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TProfile.h"

#include <fstream>

namespace icarus_tool
{

class ROICannyEdgeDetection : public IROILocator
{
public:
    explicit ROICannyEdgeDetection(const fhicl::ParameterSet& pset);
    
    ~ROICannyEdgeDetection();
    
    void configure(const fhicl::ParameterSet& pset) override;
    
    void FindROIs(const ArrayFloat&, const geo::PlaneID&, ArrayBool&)    const override;
    
private:

    std::unique_ptr<icarus_signal_processing::HighPassButterworthFilter> fButterworthFilter;
    std::unique_ptr<icarus_signal_processing::IMorphologicalFunctions2D> fMorphologicalFilter;
    std::unique_ptr<icarus_signal_processing::IDenoiser2D>               fDenoiser2D;
    std::unique_ptr<icarus_signal_processing::BilateralFilters>          fBilateralFilters;
    std::unique_ptr<icarus_signal_processing::EdgeDetection>             fEdgeDetection;
    std::unique_ptr<icarus_signal_processing::IROIFinder2D>              fROIFinder2D;

    // fhicl parameters
    std::vector<size_t>  fStructuringElement;         ///< Structuring element for morphological filter
    std::vector<float>   fThreshold;                  ///< Threshold to apply for saving signal

    // Start with parameters for Butterworth Filter
    unsigned int         fButterworthOrder;           ///< Order parameter for Butterworth filter
    unsigned int         fButterworthThreshold;       ///< Threshold for Butterworth filter

    // Parameters for the 2D morphological filter
    unsigned int         fMorph2DStructuringElementX; ///< Structuring element in X
    unsigned int         fMorph2DStructuringElementY; ///< Structuring element in Y

    // Parameters for the denoiser
    unsigned int         fCoherentNoiseGrouping;      ///< Number of consecutive channels in coherent noise subtraction
    unsigned int         fMorphologicalWindow;        ///< Window size for filter
    bool                 fOutputStats;                ///< Output of timiing statistics?
    float                fCoherentThresholdFactor;    ///< Threshold factor for coherent noise removal

    // Parameters for the ROI finding
    unsigned int         fADFilter_SX;                ///< 
    unsigned int         fADFilter_SY;                ///< 
    float                fSigma_x;                    ///<
    float                fSigma_y;                    ///<
    float                fSigma_r;                    ///<
    float                fLowThreshold;               ///<
    float                fHighThreshold;              ///<
    unsigned int         fBinaryClosing_SX;           ///<
    unsigned int         fBinaryClosing_SY;           ///<

    // We need to give to the denoiser the "threshold vector" we will fill during our data loop
    icarus_signal_processing::VectorFloat  fThresholdVec;  ///< "threshold vector" filled during decoding loop

};
    
//----------------------------------------------------------------------
// Constructor.
ROICannyEdgeDetection::ROICannyEdgeDetection(const fhicl::ParameterSet& pset)
{
    configure(pset);
}
    
ROICannyEdgeDetection::~ROICannyEdgeDetection()
{
}
    
void ROICannyEdgeDetection::configure(const fhicl::ParameterSet& pset)
{
    // Start by recovering the parameters
    fStructuringElement = pset.get<std::vector<size_t> >("StructuringElement", std::vector<size_t>()={8,16});
    fThreshold          = pset.get<std::vector<float>  >("Threshold",          std::vector<float>()={2.75,2.75,2.75});

    fButterworthOrder     = pset.get<unsigned int>("ButterworthOrder",     2);
    fButterworthThreshold = pset.get<unsigned int>("ButterworthThreshld", 30);

    fButterworthFilter = std::make_unique<icarus_signal_processing::HighPassButterworthFilter>(fButterworthThreshold,fButterworthOrder,4096);

    fMorph2DStructuringElementX = pset.get<unsigned int>("Morph2DStructuringElementX", 7);
    fMorph2DStructuringElementY = pset.get<unsigned int>("Morph2DStructuringElementX", 28);

    fMorphologicalFilter = std::make_unique<icarus_signal_processing::Dilation2D>(fMorph2DStructuringElementX,fMorph2DStructuringElementY);

    fCoherentNoiseGrouping   = pset.get<unsigned int>("CoherentNoiseGrouping",    32);
    fMorphologicalWindow     = pset.get<unsigned int>("MorphologicalWindow",      10);
    fCoherentThresholdFactor = pset.get<float       >("CoherentThresholdFactor", 2.5);

    fThresholdVec.resize(6560/fCoherentNoiseGrouping,fCoherentThresholdFactor);

    fDenoiser2D = std::make_unique<icarus_signal_processing::Denoiser2D_Hough>(fMorphologicalFilter.get(), fThresholdVec, fCoherentNoiseGrouping, fMorphologicalWindow);

    fADFilter_SX           = pset.get<unsigned int>("ADFilter_SX",        7);
    fADFilter_SY           = pset.get<unsigned int>("ADFilter_SY",        7);
    fSigma_x               = pset.get<float       >("Sigma_x",          5.0);
    fSigma_y               = pset.get<float       >("Sigma_y",          5.0);
    fSigma_r               = pset.get<float       >("Sigma_r",         30.0);
    fLowThreshold          = pset.get<float       >("LowThreshold",     3.0);
    fHighThreshold         = pset.get<float       >("HighThreshold",   15.0);
    fBinaryClosing_SX      = pset.get<unsigned int>("BinaryClosing_SX",  13);
    fBinaryClosing_SY      = pset.get<unsigned int>("BinaryClosing_SY",  13);

    fBilateralFilters = std::make_unique<icarus_signal_processing::BilateralFilters>();
    fEdgeDetection    = std::make_unique<icarus_signal_processing::EdgeDetection>();

    fROIFinder2D = std::make_unique<icarus_signal_processing::ROICannyFilter>(fButterworthFilter.get(), 
                                                                              fDenoiser2D.get(), 
                                                                              fBilateralFilters.get(),
                                                                              fEdgeDetection.get(), 
                                                                              fADFilter_SX,
                                                                              fADFilter_SY,
                                                                              fSigma_x,
                                                                              fSigma_y,
                                                                              fSigma_r,
                                                                              fLowThreshold,
                                                                              fHighThreshold,
                                                                              fBinaryClosing_SX,
                                                                              fBinaryClosing_SY);
    
    return;
}

void ROICannyEdgeDetection::FindROIs(const ArrayFloat& inputImage, const geo::PlaneID& planeID, ArrayBool& outputROIs) const
{
    icarus_signal_processing::ArrayFloat waveLessCoherent(inputImage.size(),icarus_signal_processing::VectorFloat(4096,0.));
    icarus_signal_processing::ArrayFloat medianVals(inputImage.size(),icarus_signal_processing::VectorFloat(4096,0.));
    icarus_signal_processing::ArrayFloat coherentRMS(inputImage.size(),icarus_signal_processing::VectorFloat(4096,0.));
    icarus_signal_processing::ArrayFloat morphedWaveforms(inputImage.size(),icarus_signal_processing::VectorFloat(4096,0.));
    icarus_signal_processing::ArrayFloat finalErosion(inputImage.size(),icarus_signal_processing::VectorFloat(4096,0.));
    icarus_signal_processing::ArrayFloat fullEvent(inputImage.size(),icarus_signal_processing::VectorFloat(4096,0.));

    outputROIs.resize(inputImage.size(),VectorBool(4096,false));

    (*fROIFinder2D)(inputImage,fullEvent,outputROIs,waveLessCoherent,medianVals,coherentRMS,morphedWaveforms,finalErosion);

    std::cout << "--> ROICannyEdgeDetection finished!" << std::endl;
     
    return;
}

DEFINE_ART_CLASS_TOOL(ROICannyEdgeDetection)
}