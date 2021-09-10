# Leave this out for the time being. One day the grid will be updated enough...
# cet_set_compiler_flags(EXTRA_CXX_FLAGS -mavx)

art_make( ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
  LIB_LIBRARIES 
    larcorealg::Geometry
    lardataobj::RawData
    icarusalg::Utilities
#    lardataobj::RecoBase
#    lardata::Utilities
#    larcorealg::Geometry
#    lardata::ArtDataHelper
#    nusimdata::SimulationBase
     canvas::canvas
     ${MF_MESSAGELOGGER}
     ${MF_UTILITIES}
     ${FHICLCPP}
     ${CETLIB}
     cetlib_except::cetlib_except
     ${ROOT_FFTW}
     ${ROOT_GENVECTOR}
     ${ROOT_BASIC_LIB_LIST}
     ${CLHEP}
#    ${Boost_SYSTEM_LIBRARY}
  )

install_headers()
install_fhicl()
install_source()
