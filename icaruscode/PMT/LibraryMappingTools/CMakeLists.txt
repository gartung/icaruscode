art_make_library(
		SOURCE
			"ICARUSPhotonMappingTransformations.cxx"
		LIBRARIES
			larsim::PhotonPropagation_LibraryMappingTools
			larcore::Geometry_Geometry_service
			larcorealg:Geometry
                        lardataalg::DetectorInfo
			art::Framework_Services_Registry
			art::Utilities
			canvas::canvas
			${CETLIB_EXCEPT}
			messagefacility::MF_MessageLogger
			fhiclcpp::fhiclcpp
			${ROOT_GENVECTOR}
			${Boost_SYSTEM_LIBRARY}
		)

simple_plugin(ICARUSPhotonMappingTransformations "tool"
		icaruscode::PMT_LibraryMappingTools
		larsim::PhotonPropagation_LibraryMappingTools
		)

install_headers()
install_fhicl()
install_source()
