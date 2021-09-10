if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
cet_add_compiler_flags(CXX -Wno-maybe-uninitialized)
endif()
art_make(    LIBRARY_NAME icaruscode_CRTUtils ### MIGRATE-ACTION-RECOMMENDED: use art::make_library(), art::dictionary(), simple_plugin() with explicit source lists
             LIB_LIBRARIES larcorealg::Geometry
                           larcore::Geometry_Geometry_service
                           larsim::Simulation lardataobj::Simulation
                           larsim::MCCheater_BackTrackerService_service
                           larsim::MCCheater_ParticleInventoryService_service
                           lardata::Utilities
                           larevt::Filters
                           lardataobj::RawData
                           lardataobj::RecoBase
                           lardata::RecoObjects  
                           lardataalg::DetectorInfo
                           larpandora::LArPandoraInterface
                           nusimdata::SimulationBase
                           cetlib::cetlib cetlib_except::cetlib_except
                           ${ART_FRAMEWORK_CORE}
                           ${ART_FRAMEWORK_PRINCIPAL}
                           ${ART_FRAMEWORK_SERVICES_REGISTRY}
                           ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
                           ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                           ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
                           art::Persistency_Common 
                           art::Persistency_Provenance 
                           art::Utilities canvas::canvas
                           ${MF_MESSAGELOGGER}
                           ${CLHEP}
                           ${FHICLCPP}
                           ${ROOT_GEOM}
                           ${ROOT_XMLIO}
                           ${ROOT_GDML}
                           ${ROOT_GENVECTOR}
                           ${ROOT_BASIC_LIB_LIST}
                           ${Boost_SYSTEM_LIBRARY}
                           icaruscode::CRT
                           sbnobj_Common_CRT
                           icaruscode::CRTData
                           lardata::DetectorInfoServices_DetectorClocksServiceStandard_service
                           nurandom::RandomUtils_NuRandomService_service
        )

install_headers()
install_fhicl()
install_source()
