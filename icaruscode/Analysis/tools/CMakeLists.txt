cet_enable_asserts()
add_subdirectory(MCTruth)

add_definitions(-DEIGEN_FFTW_DEFAULT)

art_make( TOOL_LIBRARIES lardataobj::RecoBase ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
                         lardataobj::Simulation
                         lardataalg::DetectorInfo
                         icaruscode::TPC_SignalProcessing_RawDigitFilter_Algorithms
                         larcorealg::Geometry
                         larcore::Geometry_Geometry_service
                         lardata::RecoObjects
                         lardata::Utilities
                         nusimdata::SimulationBase
                         larsim::Simulation
                         ${ART_FRAMEWORK_CORE}
                         ${ART_FRAMEWORK_PRINCIPAL}
                         ${ART_FRAMEWORK_SERVICES_REGISTRY}
                         ${ART_FRAMEWORK_SERVICES_BASIC}
                         ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
                         ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                         ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
                         art::Persistency_Common
                         art::Persistency_Provenance
                         art::Utilities
                         canvas::canvas
                         ${MF_MESSAGELOGGER}
                         ${MF_UTILITIES}
                         ${FHICLCPP}
                         ${CETLIB}
                         cetlib_except::cetlib_except
                         ${Boost_FILESYSTEM_LIBRARY}
                         ${Boost_SYSTEM_LIBRARY}
                         ${CLHEP}
                         ${ROOT_BASIC_LIB_LIST}
                         ${ROOT_MINUIT}
        )

install_headers()
install_source()
install_fhicl()
