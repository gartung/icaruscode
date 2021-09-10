add_subdirectory(Algorithms)

# Build the module
art_make( MODULE_LIBRARIES ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
           icaruscode::TPC_Calorimetry_Algorithms
           larcorealg::Geometry
           larreco::Calorimetry
           lardataobj::RecoBase
           lardata::ArtDataHelper
           lardataalg::DetectorInfo
           larcorealg::Geometry
           lardataobj::AnalysisBase
           ${ART_FRAMEWORK_SERVICES_REGISTRY}
           ${ART_UTILITIES}
           canvas::canvas
           ${FHICLCPP}
           cetlib_except::cetlib_except
           ROOT::Core
           ROOT::Physics
           ROOT::Core
           ROOT::Hist
           ROOT::Physics
           ${MF_MESSAGELOGGER}
         )

install_headers()
install_fhicl()
install_source()
