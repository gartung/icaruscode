
#Thexmlfileshereareusedtoinitializepandora
#TheyneedtobefoundviaFW_SEARCH_PATH

#installxmlfiles
file(GLOB xml_file*.xml)
install_fw(LIST${xml_file})
