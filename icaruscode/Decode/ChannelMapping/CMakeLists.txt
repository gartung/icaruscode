cet_enable_asserts()

art_make( ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
          EXCLUDE "PMTChannelMapDumper.cxx"
          LIB_LIBRARIES
                        art::Utilities
                        canvas::canvas
                        ${FHICLCPP}
                        ${MF_MESSAGELOGGER}
                        cetlib_except::cetlib_except
                        cetlib::cetlib
          SERVICE_LIBRARIES
                        icaruscode_Decode_ChannelMapping
                        lardata_Utilities
                        lardata_ArtDataHelper
                        ${ROOT_BASIC_LIB_LIST}
                        LIBWDA
                        ${ART_FRAMEWORK_CORE}
                        ${ART_FRAMEWORK_PRINCIPAL}
                        ${ART_FRAMEWORK_SERVICES_REGISTRY}
                        ${ART_ROOT_IO_TFILE_SUPPORT}
                        ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                        ${ART_UTILITIES}
                        art::Persistency_Common
                        art::Persistency_Provenance
                        art::Utilities canvas::canvas
                        ${MF_MESSAGELOGGER}
                        ${MF_UTILITIES}
                        ${FHICLCPP}
                        cetlib::cetlib cetlib_except::cetlib_except
                        ${TBB}
          TOOL_LIBRARIES
                        lardata_Utilities
                        lardata_ArtDataHelper
                        ${ROOT_BASIC_LIB_LIST}
                        LIBWDA
                        ${ART_FRAMEWORK_CORE}
                        ${ART_FRAMEWORK_PRINCIPAL}
                        ${ART_FRAMEWORK_SERVICES_REGISTRY}
                        ${ART_ROOT_IO_TFILE_SUPPORT}
                        ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                        ${ART_UTILITIES}
                        art::Persistency_Common canvas::canvas
                        art::Persistency_Provenance
                        art::Utilities
                        ${MF_MESSAGELOGGER}
                        ${MF_UTILITIES}
                        ${FHICLCPP}
                        cetlib::cetlib cetlib_except::cetlib_except
                        ${SQLITE3}
                        ${TBB}
        )

art_make_exec(NAME "PMTChannelMapDumper"
  LIBRARIES
    icaruscode::Decode_ChannelMapping
    ${MF_MESSAGELOGGER}
    ${FHICLCPP}
    cetlib::cetlib
    cetlib_except::cetlib_except
    Boost::filesystem
  )

install_headers()
install_fhicl()
install_source()

