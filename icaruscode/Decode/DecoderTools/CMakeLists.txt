cet_enable_asserts()

##include_directories($ENV{LIBWDA_FQ_DIR}/include)

include_directories(${FFTW3_INCLUDE_DIRS})

add_subdirectory("Dumpers")

art_make(SUBDIRS details
	LIB_LIBRARIES
                lardataalg::DetectorInfo
		icaruscode::Utilities
		sbnobj::Common_PMT_Data
		messagefacility::MF_MessageLogger
		fhiclcpp::fhiclcpp
		cetlib_except::cetlib_except
		cetlib::cetlib
		ROOT::RIO
		ROOT::Core
		art::Framework_Services_Registry
	TOOL_LIBRARIES
		sbndaq-artdaq-core::Overlays_ICARUS
		artdaq_core::artdaq-core_Utilities
		icarus_signal_processing::icarus_signal_processing
		icarus_signal_processing::Detection
		icarus_signal_processing::Filters
		icaruscode::TPC_Utilities_SignalShapingICARUSService_service
		icaruscode::Decode_DecoderTools
		icaruscode::Decode_DecoderTools_Dumpers
		icaruscode::Utilities
		larcorealg::Geometry
		larcore::Geometry_Geometry_service
		lardata::Utilities
		lardataalg::DetectorInfo
		larevt::Filters
		lardataobj::RawData
		lardata::ArtDataHelper
		ROOT::Core
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
	)

install_headers()
install_fhicl()
install_source()
