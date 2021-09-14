add_subdirectory(OpticalTools)
add_subdirectory(OpReco)
add_subdirectory(Algorithms)
add_subdirectory(LibraryMappingTools)
add_subdirectory(Trigger)

# Removing AVX instructions because assuming the grid nodes
# being less than 6 year old proved to be pretentious.
# AVX is not so relevant after the last commit anyway
# cet_set_compiler_flags(EXTRA_CXX_FLAGS-mavx)

simple_plugin(SimPMTIcarus "module"
			icaruscode::PMT_Algorithms
			lardataobj::RawData
			lardataobj::Simulation
			nurandom::RandomUtils_NuRandomService_service
			art::Framework_Core
			art::Framework_Principal
			art::Framework_Services_Registry
			art::Framework_Services_Optional_RandomNumberGenerator_service
			art_root_io::TFileService_service
			art_root_io::tfile_support
			art::Persistency_Provenance
			canvas::canvas
			messagefacility::MF_MessageLogger
			fhiclcpp::fhiclcpp
			cetlib::cetlib
			cetlib_except::cetlib_except
			${Boost_SYSTEM_LIBRARY}
			)

simple_plugin(PMTWaveformBaselines "module"
			icaruscode::PMT_Algorithms
			sbnobj::ICARUS_PMT_Data
			larcore::Geometry_Geometry_service
			larcorealg::Geometry
			lardataobj::RawData
			art_root_io::TFileService_service
			art_root_io::tfile_support
			art::Framework_Services_Registry
			messagefacility::MF_MessageLogger
			ROOT::Hist
			ROOT::Core
			)

simple_plugin(PMTWaveformBaselinesFromReadoutConfiguration "module"
			sbnobj::ICARUS_PMT_Data
			sbnobj::Common_PMT_Data
			larcore::Geometry_Geometry_service
			larcorealg::Geometry
			lardataobj::RawData
			art_root_io::TFileService_service
			art_root_io::tfile_support
			art::Framework_Services_Registry
			messagefacility::MF_MessageLogger
			ROOT::Hist
			ROOT::Core
			)


simple_plugin(AsymGaussPulseFunctionTool "tool"
	icaruscode::PMT_Algorithms
	)

simple_plugin(AsymExpPulseFunctionTool "tool"
	icaruscode::PMT_Algorithms
	)

simple_plugin(CustomPulseFunctionTool "tool"
	icaruscode::PMT_Algorithms
	ROOT::Hist
	)


art_make(
	EXCLUDE
		"SimPMTIcarus_module.cc"
		"PMTWaveformBaselines_module.cc"
		"PMTWaveformBaselinesFromReadoutConfiguration_module.cc"
		"AsymGaussPulseFunctionTool_tool.cc"
		"AsymExpPulseFunctionTool_tool.cc"
		"CustomPulseFunctionTool_tool.cc"
	LIB_LIBRARIES
			lardataobj::RawData
			lardataobj::RecoBase
			lardata::Utilities
			fhiclcpp::fhiclcpp
			cetlib::cetlib
			${Boost_SYSTEM_LIBRARY}
	MODULE_LIBRARIES
			larcorealg::Geometry
			larcore::Geometry_Geometry_service
			lardata::Utilities
                        larana::OpticalDetector
			larreco::Calorimetry
			larevt::Filters
			lardataobj::RawData
			larsim::PhotonPropagation
			larevt::CalibrationDBI_IOVData
			larevt::CalibrationDBI_Providers
			lardataobj::RecoBase
			lardata::ArtDataHelper
			nusimdata::SimulationBase
			nurandom::RandomUtils_NuRandomService_service
			CLHEP::Random
			art::Framework_Core
			art::Framework_Principal
			art::Framework_Services_Registry
			art_root_io::tfile_support ROOT::Core
			art_root_io::TFileService_service
			art::Persistency_Common
			art::Persistency_Provenance
			art::Utilities
			canvas::canvas
			messagefacility::MF_MessageLogger
			messagefacility::headers
			fhiclcpp::fhiclcpp
			cetlib::cetlib
			cetlib_except::cetlib_except
			ROOT::Geom
			ROOT::XMLIO
			${ROOT_GDML}
			${ROOT_FFTW}			
			${Boost_SYSTEM_LIBRARY}
)

install_headers()
install_fhicl()
install_source()
install_scripts(
	SUBDIRS scripts
	EXTRAS
		"scripts/MergePhotonLibrary.C"
		"scripts/RecompressROOTtrees.C"
	)

