cet_enable_asserts()

art_make(
	EXCLUDE "PMTChannelMapDumper.cxx"
	LIB_LIBRARIES
		art::Utilities
		canvas::canvas
		fhiclcpp::fhiclcpp
		messagefacility::MF_MessageLogger
		cetlib_except::cetlib_except
		cetlib::cetlib
	SERVICE_LIBRARIES
		icaruscode::Decode_ChannelMapping
		lardata::Utilities
		lardata::ArtDataHelper
                larcorealg::CoreUtils
		LIBWDA
		art::Framework_Core
		art::Framework_Principal
		art::Framework_Services_Registry
		art_root_io::tfile_support
		art_root_io::TFileService_service
		art::Utilities
		art::Persistency_Common
		art::Persistency_Provenance
		art::Utilities canvas::canvas
		messagefacility::MF_MessageLogger
		messagefacility::headers
		fhiclcpp::fhiclcpp
		cetlib::cetlib cetlib_except::cetlib_except
		${TBB}
	TOOL_LIBRARIES
		lardata_Utilities
		lardata_ArtDataHelper
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
		${SQLITE3}
		${TBB}
	)

art_make_exec(NAME "PMTChannelMapDumper"
	LIBRARIES
		icaruscode::Decode_ChannelMapping
		messagefacility::MF_MessageLogger
		fhiclcpp::fhiclcpp
		cetlib::cetlib
		cetlib_except::cetlib_except
		Boost::filesystem
	)

install_headers()
install_fhicl()
install_source()

