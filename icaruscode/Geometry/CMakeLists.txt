
art_make( ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
  SERVICE_LIBRARIES
      icarusalg_Geometry
      larcorealg_Geometry
      ${ART_UTILITIES}
      ${MF_MESSAGELOGGER}
      ${FHICLCPP}
      ${CETLIB}
      ${CETLIB_EXCEPT}
      ${ROOT_GEOM}
      ${ROOT_XMLIO}
      ${ROOT_GDML}
      ${ROOT_BASIC_LIB_LIST}
  TOOL_LIBRARIES
      icarusalg_Geometry
      larcorealg_Geometry
      ${ART_UTILITIES}
      ${MF_UTILITIES}
      ${FHICLCPP}
      ${CETLIB}
      ${CETLIB_EXCEPT}
      ${ROOT_GEOM}
      ${ROOT_XMLIO}
      ${ROOT_GDML}
      ${ROOT_BASIC_LIB_LIST}    
  )

