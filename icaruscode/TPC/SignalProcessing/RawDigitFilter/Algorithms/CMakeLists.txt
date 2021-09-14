
include_directories(${ICARUS_FFTW_INCLUDE_DIRS})
link_directories(${ICARUS_FFTW_LIBRARY_DIRS})

add_definitions(-DEIGEN_FFTW_DEFAULT)

art_make(
	LIB_LIBRARIES
		lardataobj::RawData
		lardataobj::RecoBase
		lardata::Utilities
		fhiclcpp::fhiclcpp
		cetlib::cetlib
		cetlib_except::cetlib_except
		larcorealg::Geometry
		larcore::Geometry_Geometry_service
		lardata::Utilities
		larevt::Filters
		lardataobj::RawData
		larevt::CalibrationDBI_IOVData
		larevt::CalibrationDBI_Providers
		lardataobj::RecoBase
		icaruscode::TPC_Utilities_SignalShapingICARUSService_service
		${ICARUS_FFTW_LIBRARIES}
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
		cetlib::cetlib
		cetlib_except::cetlib_except
		ROOT::Geom
		ROOT::XMLIO
		${ROOT_GDML}
		${ROOT_FFTW}

	TOOL_LIBRARIES
		icaruscode::TPC_SignalProcessing_RawDigitFilter_Algorithms
		icaruscode::TPC_Utilities_SignalShapingICARUSService_service
		lardataobj::RawData
		lardataobj::RecoBase
		lardata::Utilities
		fhiclcpp::fhiclcpp
		cetlib::cetlib cetlib_except::cetlib_except
		larcorealg::Geometry
		larcore::Geometry_Geometry_service
		larevt::CalibrationDBI_IOVData
		larevt::CalibrationDBI_Providers
		${ICARUS_FFTW_LIBRARIES}
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
		cetlib::cetlib cetlib_except::cetlib_except
		ROOT::Geom
		${ROOT_FFTW}

)

install_headers()
install_fhicl()
install_source()
