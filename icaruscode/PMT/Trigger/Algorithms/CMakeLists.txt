cet_make( ### MIGRATE-ACTION-RECOMMENDED: use cet_make_library(), build_dictionary(), basic_plugin() with explicit source lists
  SUBDIRS
    "details"
  LIBRARIES
    sbnobj_ICARUS_PMT_Trigger_Data
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
