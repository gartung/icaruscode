art_make(  ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
          MODULE_LIBRARIES
                        icarusalg::Utilities
                        larcorealg::Geometry
                        larcore::Geometry_Geometry_service
                        larsim::Simulation 
                        nug4::ParticleNavigation
                        lardataobj::Simulation
                        lardata::Utilities
                        larevt::Filters
                        lardataalg_MCDumpers
                        lardataobj::RawData
                        lardataobj::RecoBase
                        lardata::RecoObjects
                        nusimdata::SimulationBase
                        ${ART_FRAMEWORK_CORE}
                        ${ART_FRAMEWORK_PRINCIPAL}
                        ${ART_FRAMEWORK_SERVICES_REGISTRY}
                        ${ROOT_CORE}
                        art::Persistency_Common 
                        art::Persistency_Provenance 
                        art::Utilities 
                        ${MF_MESSAGELOGGER}
                        ${MF_UTILITIES}
                        ${FHICLCPP}
                        ${CETLIB}
                        ${CETLIB_EXCEPT}
                        ROOT::EG
                        ${ROOT_GEOM}
                        ${ROOT_XMLIO}
                        ${ROOT_GDML}
                        ${ROOT_GENVECTOR}
                        ${ROOT_BASIC_LIB_LIST}
        )

# install_headers()
install_fhicl()
install_source()

