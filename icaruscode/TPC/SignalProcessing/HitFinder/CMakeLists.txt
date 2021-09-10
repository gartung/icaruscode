add_subdirectory(HitFinderTools)

art_make(  ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
          LIB_LIBRARIES 
			           lardataobj::RawData
                       lardataobj::RecoBase
	                   lardata::Utilities
	                   ${FHICLCPP}
			           ${CETLIB}
			           ${ROOT_BASIC_LIB_LIST}
	  MODULE_LIBRARIES larcorealg::Geometry
	  		           larcore::Geometry_Geometry_service
	                   lardata::Utilities
			           larevt::Filters
			           lardataobj::RawData
			           larevt::CalibrationDBI_IOVData
			           larevt::CalibrationDBI_Providers
			           lardataobj::RecoBase
			           lardata::ArtDataHelper
			           larreco::RecoAlg
                       ${ART_FRAMEWORK_CORE}
			           ${ART_FRAMEWORK_PRINCIPAL}
			           ${ART_FRAMEWORK_SERVICES_REGISTRY}
			           ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
			           ${ART_ROOT_IO_TFILESERVICE_SERVICE}
			           art::Persistency_Common
			           art::Persistency_Provenance
			           art::Utilities
			           canvas::canvas
			           ${MF_MESSAGELOGGER}
			           ${MF_UTILITIES}
	                   ${FHICLCPP}
			           ${CETLIB}
                       ${ROOT_GEOM}
                       ${ROOT_XMLIO}
                       ${ROOT_GDML}
			           ${ROOT_FFTW}
			           ${ROOT_BASIC_LIB_LIST}
        )

install_headers()
install_fhicl()
install_source()

