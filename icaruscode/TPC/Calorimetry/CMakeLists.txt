add_subdirectory(Algorithms)

#Buildthemodule
art_make(MODULE_LIBRARIES
		icaruscode::TPC_Calorimetry_Algorithms
		larcorealg::Geometry
		larreco::Calorimetry
		lardataobj::RecoBase
		lardata::ArtDataHelper
		lardataalg::DetectorInfo
		larcorealg::Geometry
		lardataobj::AnalysisBase
		art::Framework_Services_Registry
		art::Utilities
		canvas::canvas
		fhiclcpp::fhiclcpp
		cetlib_except::cetlib_except
		ROOT::Core
		ROOT::Physics
		ROOT::Core
		ROOT::Hist
		ROOT::Physics
		messagefacility::MF_MessageLogger
		)

install_headers()
install_fhicl()
install_source()
