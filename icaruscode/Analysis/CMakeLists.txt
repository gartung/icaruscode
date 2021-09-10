add_subdirectory(tools)
add_subdirectory(overburden)

art_make( MODULE_LIBRARIES larcorealg::Geometry ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
                           larcore::Geometry_Geometry_service
                           larsim::Simulation nug4_ParticleNavigation
                           lardataobj::Simulation
                           lardata::Utilities
                           larevt::Filters
                           larsim::MCCheater_BackTrackerService_service
                           larsim::MCCheater_ParticleInventoryService_service
                           lardataobj::RawData
                           larevt::CalibrationDBI_Providers
                           nurandom::RandomUtils_NuRandomService_service
			   sbnobj_Common_Analysis
                           ${ART_FRAMEWORK_CORE}
                           ${ART_FRAMEWORK_PRINCIPAL}
                           ${ART_FRAMEWORK_SERVICES_REGISTRY}
                           ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
                           ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
                           ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                           art::Persistency_Common
                           art::Persistency_Provenance
                           art::Utilities
                           canvas::canvas
                           ${MF_MESSAGELOGGER}
                           ${MF_UTILITIES}
                           ${FHICLCPP}
                           ${CETLIB}
                           cetlib_except::cetlib_except
                           ${CLHEP}
                           ${ROOT_GEOM}
                           ${ROOT_XMLIO}
                           ${ROOT_GDML}
                           ${ROOT_BASIC_LIB_LIST}
                           icaruscode::RecoUtils
        )

#install_headers()
install_fhicl()
install_source()
