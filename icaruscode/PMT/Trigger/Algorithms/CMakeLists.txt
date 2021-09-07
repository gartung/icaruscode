cet_make( ### MIGRATE-ACTION-RECOMMENDED: use cet_make_library(), build_dictionary(), basic_plugin() with explicit source lists
  SUBDIRS
    "details"
  LIBRARIES
    sbnobj_ICARUS_PMT_Trigger_Data
    icaruscode_PMT_Algorithms
    lardataalg_DetectorInfo
    lardataalg_MCDumpers
    lardataobj_RawData
    nusimdata_SimulationBase
    MF_MessageLogger
    fhiclcpp
  )

install_headers(SUBDIRS "details")
install_source(SUBDIRS "details")
install_fhicl(SUBDIRS "details")
