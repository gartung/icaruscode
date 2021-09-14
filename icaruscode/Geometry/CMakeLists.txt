
art_make(
	SERVICE_LIBRARIES
		icarusalg::Geometry
		larcorealg::Geometry
		larcore::Geometry_Geometry_service
		art::Utilities
		messagefacility::MF_MessageLogger
		fhiclcpp::fhiclcpp
		cetlib::cetlib
		${CETLIB_EXCEPT}
		ROOT::Geom
		ROOT::XMLIO
		${ROOT_GDML}

	TOOL_LIBRARIES
		icarusalg::Geometry
		larcorealg::Geometry
		larcore::Geometry_Geometry_service
		art::Utilities
		messagefacility::headers
		fhiclcpp::fhiclcpp
		cetlib::cetlib
		${CETLIB_EXCEPT}
		ROOT::Geom
		ROOT::XMLIO
		${ROOT_GDML}

	)

