art_make( NO_PLUGINS ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
          LIB_LIBRARIES
	      lardataobj::RecoBase
          lardata::Utilities
	      lardataalg::DetectorInfo
	      larevt::SpaceCharge	
	      larcorealg::Geometry
          ${MF_MESSAGELOGGER}
          cetlib::cetlib cetlib_except::cetlib_except
	      ${ART_FRAMEWORK_CORE}
	      ${ART_FRAMEWORK_PRINCIPAL}
	      ${ART_FRAMEWORK_SERVICES_REGISTRY}
	      ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
          ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
          ${ART_ROOT_IO_TFILESERVICE_SERVICE}
          art::Persistency_Common canvas
          art::Persistency_Provenance canvas
          art::Utilities canvas
	 
	 ${FHICLCPP}
         ${ROOT_BASIC_LIB_LIST}
	 ${Boost_SYSTEM_LIBRARY}
        )
install_headers()
install_fhicl()
install_source()
