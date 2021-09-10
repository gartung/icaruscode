add_subdirectory(tools)

add_definitions(-DEIGEN_FFTW_DEFAULT)

art_make(  ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
          EXCLUDE SimWireICARUS_module.cc 
          MODULE_LIBRARIES larcorealg::Geometry
                           larcore::Geometry_Geometry_service
                           larsim::Simulation 
                           nug4::ParticleNavigation lardataobj::Simulation
                           lardata::Utilities
                           larevt::Filters
                           lardataobj::RawData
                           icaruscode::TPC_Utilities_SignalShapingICARUSService_service
		           larevt::CalibrationDBI_Providers
                           nurandom::RandomUtils_NuRandomService_service
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
                           ${CLHEP}
                           ${ROOT_GEOM}
                           ${ROOT_XMLIO}
                           ${ROOT_GDML}
                           ${ROOT_BASIC_LIB_LIST}
        )

simple_plugin(SimWireICARUS "module"
                           larcorealg::Geometry
                           larcore::Geometry_Geometry_service
                           larsim::Simulation 
                           nug4::ParticleNavigation lardataobj::Simulation
                           lardata::Utilities
                           lardataalg_DetectorInfo
                           larevt::Filters
                           lardataobj::RawData
                           icaruscode::TPC_Utilities_SignalShapingICARUSService_service
                           larevt::CalibrationDBI_Providers
                           nurandom::RandomUtils_NuRandomService_service
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
                           ${CLHEP}
                           ${ROOT_GEOM}
                           ${ROOT_XMLIO}
                           ${ROOT_GDML}
                           ${ROOT_BASIC_LIB_LIST}
        )

#install_headers()
install_fhicl()
install_source()
