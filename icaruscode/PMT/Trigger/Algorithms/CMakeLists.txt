cet_make(
	SUBDIRS
		"details"
	LIBRARIES
		sbnobj::ICARUS_PMT_Trigger_Data
		icaruscode::PMT_Algorithms
		lardataalg::DetectorInfo
		lardataalg::MCDumpers
		lardataobj::RawData
		nusimdata::SimulationBase
		messagefacility::MF_MessageLogger
		fhiclcpp::fhiclcpp
	)

install_headers(SUBDIRS "details")
install_source(SUBDIRS "details")
install_fhicl(SUBDIRS "details")
