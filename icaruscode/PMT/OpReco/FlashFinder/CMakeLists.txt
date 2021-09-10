include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ) ### MIGRATE-ACTION-RECOMMENDED: use target_link_directories() with target semantics

art_make(  ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
	  LIB_LIBRARIES
		   icarusalg::Geometry
		   larcore::Geometry_Geometry_service
		   larcorealg::Geometry
		   lardataobj::RecoBase
		   ${LARDATA_LIB}
		   canvas::canvas
		   cetlib::cetlib
		   cetlib_except::cetlib_except
		   ${ART_FRAMEWORK_ART}
		   ${ART_FRAMEWORK_CORE}
		   ${ART_FRAMEWORK_PRINCIPAL}
		   ${ART_FRAMEWORK_UTILITIES}
                   ${ART_FRAMEWORK_BASIC}
		   ${ART_FRAMEWORK_SERVICES_REGISTRY}
		   ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
		   ${ART_ROOT_IO_TFILESERVICE_SERVICE}
		   art::Persistency_Common
		   art::Persistency_Provenance
		   art::Utilities
		   ${MF_MESSAGELOGGER}
		   ${FHICLCPP}
		   ${ROOT_GEOM}
		   ${ROOT_XMLIO}
		   ${ROOT_GDML}
		   ${ROOT_BASIC_LIB_LIST}
          MODULE_LIBRARIES
		   icaruscode::PMT_OpReco_FlashFinder
		   icarusalg::Geometry
		   larcore::Geometry_Geometry_service
		   larcorealg::Geometry
		   lardataobj::RecoBase
		   ${LARDATA_LIB}
		   canvas
		   cetlib::cetlib
		   cetlib_except::cetlib_except
		   ${ART_FRAMEWORK_ART}
		   ${ART_FRAMEWORK_CORE}
		   ${ART_FRAMEWORK_PRINCIPAL}
                   ${ART_FRAMEWORK_BASIC}
		   ${ART_FRAMEWORK_SERVICES_REGISTRY}
		   ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
		   ${ART_ROOT_IO_TFILESERVICE_SERVICE}
		   art::Persistency_Common
		   art::Persistency_Provenance
		   art::Utilities
		   ${MF_MESSAGELOGGER}
		   ${FHICLCPP}
		   ${ROOT_GEOM}
		   ${ROOT_XMLIO}
		   ${ROOT_GDML}
		   ${ROOT_BASIC_LIB_LIST}

        )							   

install_headers()
install_source()

