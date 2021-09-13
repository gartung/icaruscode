art_make(  ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
          LIB_LIBRARIES 
                          lardataobj::RawData
                          lardataobj::RecoBase
                          lardata::Utilities
                          ${FHICLCPP}
                          cetlib::cetlib cetlib_except::cetlib_except
                          ${ROOT_BASIC_LIB_LIST}
                          larcorealg::Geometry
                          larcore::Geometry_Geometry_service
                          lardata::Utilities
                          larevt::Filters
                          lardataobj::RawData
                          larevt::CalibrationDBI_IOVData
                          larevt::CalibrationDBI_Providers
                          lardataalg_DetectorInfo
                          lardataobj::RecoBase
                          icaruscode::TPC_Utilities_SignalShapingICARUSService_service
                          ${ICARUS_FFTW_LIBRARIES}
                          ${ART_FRAMEWORK_CORE}
                          ${ART_FRAMEWORK_PRINCIPAL}
                          ${ART_FRAMEWORK_SERVICES_REGISTRY}
                          ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
                          ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                          art::Persistency_Common canvas::canvas
                          art::Persistency_Provenance canvas::canvas
                          art::Utilities canvas::canvas
                          ${MF_MESSAGELOGGER}
                          ${MF_UTILITIES}
                          ${FHICLCPP}
                          cetlib::cetlib cetlib_except::cetlib_except
                          ${ROOT_GEOM}
                          ${ROOT_XMLIO}
                          ${ROOT_GDML}
                          ${ROOT_FFTW}
                          ${ROOT_BASIC_LIB_LIST}

          TOOL_LIBRARIES  icaruscode::TPC_Calorimetry_Algorithms
                          icaruscode::TPC_Utilities_SignalShapingICARUSService_service
                          lardataobj::RawData
                          lardataobj::RecoBase
                          lardata::Utilities
                          ${FHICLCPP}
                          cetlib::cetlib cetlib_except::cetlib_except
                          larcorealg::Geometry
                          larcore::Geometry_Geometry_service
                          larevt::CalibrationDBI_IOVData
                          larevt::CalibrationDBI_Providers
                          ${ICARUS_FFTW_LIBRARIES}
                          ${ART_FRAMEWORK_CORE}
                          ${ART_FRAMEWORK_PRINCIPAL}
                          ${ART_FRAMEWORK_SERVICES_REGISTRY}
                          ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
                          ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                          art::Persistency_Common canvas::canvas
                          art::Persistency_Provenance canvas::canvas
                          art::Utilities canvas::canvas
                          ${MF_MESSAGELOGGER}
                          ${MF_UTILITIES}
                          ${FHICLCPP}
                          cetlib::cetlib cetlib_except::cetlib_except
                          ${ROOT_GEOM}
                          ${ROOT_FFTW}
                          ${ROOT_BASIC_LIB_LIST}
       )

install_headers()
install_fhicl()
install_source()
