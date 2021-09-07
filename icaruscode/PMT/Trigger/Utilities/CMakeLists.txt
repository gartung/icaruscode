if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
cet_add_compiler_flags(CXX -Wno-maybe-uninitialized)
endif()

art_make( ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
  LIB_LIBRARIES
    ${ART_ROOT_IO_TFILE_SUPPORT}
    ${MF_MESSAGELOGGER}
    ${CETLIB_EXCEPT}
    ${ROOT_RIO}
    ${ROOT_CORE}
  )

install_headers()
install_source()
install_fhicl()
