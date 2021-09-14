cet_enable_asserts()

cet_find_library(LIBWD ANAMES wda PATHS ENV LIBWDA_LIB)

art_make(
	EXCLUDE
		PMTconfigurationExtraction_module.cc
		DumpPMTconfiguration_module.cc
		DumpArtDAQfragments_module.cc
		DaqDecoderICARUSPMT_module.cc
	MODULE_LIBRARIES
	icarus_signal_processing
	icarus_signal_processing_Detection
	icarus_signal_processing_Filters
	sbndaq-artdaq-core::Overlays_ICARUS
	artdaq_core::artdaq-core_Utilities
	larcorealg::Geometry
	larcore::Geometry_Geometry_service
	lardata::Utilities
	larevt::Filters
	lardataobj::RawData
	lardata::ArtDataHelper
	LIBWDA
	art::Framework_Core
	art::Framework_Principal
	art::Framework_Services_Registry
	art_root_io::tfile_support
	art_root_io::TFileService_service
	art::Utilities
	art::Persistency_Common canvas::canvas
	art::Persistency_Provenance
	art::Utilities
	messagefacility::MF_MessageLogger
	messagefacility::headers
	fhiclcpp::fhiclcpp
	cetlib::cetlib cetlib_except::cetlib_except
	${TBB}
	)

simple_plugin(DaqDecoderICARUSPMT module
	sbnobj::Common_PMT_Data
	icaruscode::Decode_DecoderTools_Dumpers
	icaruscode::Decode_DataProducts # should become sbnobj::Common_Trigger
	icaruscode::Decode_DecoderTools
	sbndaq-artdaq-core::Overlays_Common
	sbndaq-artdaq-core::Overlays
	lardataobj::RawData
	artdaq_core::artdaq-core_Data
	art_root_io::TFileService_service
	art_root_io::tfile_support
	art::Framework_Services_Registry
	messagefacility::MF_MessageLogger
	fhiclcpp::fhiclcpp
	cetlib_except::cetlib_except
	ROOT::Tree
	)

simple_plugin(PMTconfigurationExtraction module
	icaruscode::Decode_DecoderTools
	sbnobj::Common_PMT_Data
	art::Framework_Services_Registry
	fhiclcpp::fhiclcpp
	cetlib_except::cetlib_except
	)

simple_plugin(DumpPMTconfiguration module
	sbnobj::Common_PMT_Data
	messagefacility::MF_MessageLogger
	fhiclcpp::fhiclcpp
	cetlib_except::cetlib_except
	)

simple_plugin(DumpArtDAQfragments module
	icaruscode::Decode_DecoderTools_Dumpers
	artdaq_core::artdaq-core_Data
	messagefacility::MF_MessageLogger
	fhiclcpp::fhiclcpp
	cetlib_except::cetlib_except
	)

install_headers()
install_fhicl()
install_source()

#Addourtoolsdirectory
add_subdirectory(DecoderTools)
add_subdirectory(ChannelMapping)
add_subdirectory(DataProducts)
add_subdirectory(fcl)

