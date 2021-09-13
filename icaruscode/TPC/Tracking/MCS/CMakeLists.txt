
art_make(  ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
             LIB_LIBRARIES    larsim::MCCheater_BackTrackerService_service
                              larsim::MCCheater_ParticleInventoryService_service
                              lardataobj::RecoBase
                              lardata::ArtDataHelper
                              larsim::Simulation 
                              nug4::ParticleNavigation lardataobj::Simulation
                              larevt::Filters
                              larcorealg::Geometry
                              larcore_Geometry_Geometry_service
                              lardata::RecoObjects
                              lardataobj::AnalysisBase
                              larreco::Calorimetry
                              lardata::Utilities
                              larreco::RecoAlg_ClusterRecoUtil
                              larreco::RecoAlg_CMTool_CMToolBase
                              larreco::RecoAlg_CMTool_CMTAlgMerge
                              larreco::RecoAlg_CMTool_CMTAlgPriority
                              larreco::RecoAlg_CMTool_CMTAlgMatch
                              larreco::RecoAlg_CMTool_CMToolApp
                              ${ROOT_MATHCORE}
                              ${ROOT_GENVECTOR}
                              ${ROOT_GEOM}
                              ${ROOT_BASIC_LIB_LIST}
                              larreco::RecoAlg_TCAlg
                              larreco::RecoAlg_ImagePatternAlgs_DataProvider
                              larreco::RecoAlg_PMAlg
                              nusimdata::SimulationBase
                              ${ART_FRAMEWORK_CORE}
                              ${ART_FRAMEWORK_PRINCIPAL}
                              ${ART_FRAMEWORK_SERVICES_REGISTRY}
                              ${ART_FRAMEWORK_SERVICES_BASIC}
                              ${ART_FRAMEWORK_SERVICES_OPTIONAL}
                              ${ART_FRAMEWORK_SERVICES_OPTIONAL_TFILESERVICE_SERVICE}
                              ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
                              art::Persistency_Common
                              art::Persistency_Provenance
                              art::Utilities
                              canvas::canvas
                              ${MF_MESSAGELOGGER}
                              ${FHICLCPP}
                              cetlib::cetlib cetlib_except::cetlib_except
                              ${CLHEP}
                              ${ROOT_BASIC_LIB_LIST}
                              ${ROOT_MINUIT}
                              ${ROOT_MINUIT2}
             MODULE_LIBRARIES icaruscode_TPC_Tracking_MCS
                              larsim::MCCheater_BackTrackerService_service
                              larsim::MCCheater_ParticleInventoryService_service
                              lardataobj::RecoBase
                              lardata::ArtDataHelper
                              larsim::Simulation 
                              nug4::ParticleNavigation lardataobj::Simulation
                              larevt::Filters
                              larcorealg::Geometry
                              larcore_Geometry_Geometry_service
                              lardata::RecoObjects
                              lardataobj::AnalysisBase
                              larreco::Calorimetry
                              lardata::Utilities
                              larreco::RecoAlg_ClusterRecoUtil
                              larreco::RecoAlg_CMTool_CMToolBase
                              larreco::RecoAlg_CMTool_CMTAlgMerge
                              larreco::RecoAlg_CMTool_CMTAlgPriority
                              larreco::RecoAlg_CMTool_CMTAlgMatch
                              larreco::RecoAlg_CMTool_CMToolApp
                              ${ROOT_MATHCORE}
                              ${ROOT_GENVECTOR}
                              ${ROOT_GEOM}
                              ${ROOT_BASIC_LIB_LIST}
                              larreco::RecoAlg_TCAlg
                              larreco::RecoAlg_ImagePatternAlgs_DataProvider
                              larreco::RecoAlg_PMAlg
                              nusimdata::SimulationBase
                              ${ART_FRAMEWORK_CORE}
                              ${ART_FRAMEWORK_PRINCIPAL}
                              ${ART_FRAMEWORK_SERVICES_REGISTRY}
                              ${ART_FRAMEWORK_SERVICES_BASIC}
                              ${ART_FRAMEWORK_SERVICES_OPTIONAL}
                              ${ART_FRAMEWORK_SERVICES_OPTIONAL_TFILESERVICE_SERVICE}
                              ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
                              art::Persistency_Common
                              art::Persistency_Provenance
                              art::Utilities
                              canvas::canvas
                              ${MF_MESSAGELOGGER}
                              ${FHICLCPP}
                              cetlib::cetlib cetlib_except::cetlib_except
                              ${CLHEP}
                              ${ROOT_BASIC_LIB_LIST}
                              ${ROOT_MINUIT}
                              ${ROOT_MINUIT2}
        )


install_headers()
install_fhicl()
install_source()

