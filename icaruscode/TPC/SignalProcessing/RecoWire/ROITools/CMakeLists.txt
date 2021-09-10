cet_enable_asserts()

add_definitions(-DEIGEN_FFTW_DEFAULT)

art_make(  ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
          TOOL_LIBRARIES  larcorealg::Geometry
                          icarus_signal_processing
                          icarus_signal_processing_Detection
                          icarus_signal_processing_Filters
                          larevt::CalibrationDBI_IOVData
                          larevt::CalibrationDBI_Providers
                          lardataobj::RecoBase
                          larcore::Geometry_Geometry_service
                          lardata::Utilities
                          lardataalg::DetectorInfo
                          icaruscode::TPC_Utilities_SignalShapingICARUSService_service
                          nurandom::RandomUtils_NuRandomService_service
                          ${ART_FRAMEWORK_CORE}
                          ${ART_FRAMEWORK_PRINCIPAL}
                          ${ART_FRAMEWORK_SERVICES_REGISTRY}
                          art::Persistency_Common
                          art::Persistency_Provenance
                          ${ART_FRAMEWORK_SERVICES_BASIC}
                          ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
                          ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
                          ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                          ${ART_FRAMEWORK_SERVICES_SYSTEM_FILECATALOGMETADATA_SERVICE}
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

install_headers()
install_source()
install_fhicl()
