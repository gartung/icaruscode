add_subdirectory(tools)

add_definitions(-DEIGEN_FFTW_DEFAULT)

set( icarus_util_lib_list
                        larcorealg::Geometry
                        larevt::CalibrationDBI_IOVData
                        larevt::CalibrationDBI_Providers
                        larreco::HitFinder
                        lardataobj::RecoBase
                        larcore::Geometry_Geometry_service
                        lardata::Utilities
                        nurandom::RandomUtils_NuRandomService_service
                        ${ICARUS_FFTW_LIBRARIES}
                        ${ART_FRAMEWORK_CORE}
                        ${ART_FRAMEWORK_PRINCIPAL}
                        ${ART_FRAMEWORK_SERVICES_REGISTRY}
                        art::Persistency_Common
                        art::Framework_IO
                        art::Framework_IO_detail
                        art::Persistency_Provenance
                        ${ART_FRAMEWORK_SERVICES_BASIC}
                        ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
                        ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
                        ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                        ${ART_FRAMEWORK_SERVICES_SYSTEM_FILECATALOGMETADATA_SERVICE}
                        art::Framework_Services_System_TriggerNamesService_service
                        art::Utilities
                        canvas::canvas
                        ${MF_MESSAGELOGGER}
                        ${MF_UTILITIES}
                        ${FHICLCPP}
                        ${CETLIB}
                        ${Boost_FILESYSTEM_LIBRARY}
                        ${Boost_SYSTEM_LIBRARY}
                        ${CLHEP}
                        ${ROOT_BASIC_LIB_LIST}
    )

art_make(  ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
#          LIBRARY_NAME  icaruscode_TPC_Utilities
#          LIB_LIBRARIES ${icarus_util_lib_list}
#
          SERVICE_LIBRARIES 
                        ${icarus_util_lib_list}

          MODULE_LIBRARIES
                        ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                        ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
                        ${ART_FRAMEWORK_SERVICES_REGISTRY}
                        ${ART_FRAMEWORK_PRINCIPAL}
                        ${ART_FRAMEWORK_CORE}
                        canvas::canvas
                        ${MF_MESSAGELOGGER}
                        hep_concurrency::hep_concurrency
                        ${FHICLCPP}
                        ${CETLIB}
                        ${ROOT_CORE}
       )


install_headers()
install_source()
install_fhicl()
