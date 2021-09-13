cet_enable_asserts()

cet_find_library(LIBWDA NAMES wda PATHS ENV LIBWDA_LIB)

art_make(
          EXCLUDE
                        PMTconfigurationExtraction_module.cc
                        DumpPMTconfiguration_module.cc
                        DumpArtDAQfragments_module.cc
                        DaqDecoderICARUSPMT_module.cc
          MODULE_LIBRARIES
                        icarus_signal_processing
                        icarus_signal_processing_Detection
                        icarus_signal_processing_Filters
                        sbndaq-artdaq-core_Overlays_ICARUS 
                        artdaq_core::artdaq-core_Utilities
                        larcorealg::Geometry
                        larcore::Geometry_Geometry_service
                        lardata::Utilities
                        larevt::Filters
                        lardataobj::RawData
                        lardata::ArtDataHelper
                        ${ROOT_BASIC_LIB_LIST}
                        LIBWDA
                        ${ART_FRAMEWORK_CORE}
                        ${ART_FRAMEWORK_PRINCIPAL}
                        ${ART_FRAMEWORK_SERVICES_REGISTRY}
                        ${ART_ROOT_IO_TFILE_SUPPORT}
                        ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                        ${ART_UTILITIES}
                        art::Persistency_Common canvas
                        art::Persistency_Provenance canvas
                        art::Utilities canvas
                        ${MF_MESSAGELOGGER}
                        ${MF_UTILITIES}
                        ${FHICLCPP}
                        cetlib::cetlib cetlib_except::cetlib_except
                        ${TBB}
        )

simple_plugin(DaqDecoderICARUSPMT module
  sbnobj::Common_PMT_Data
  icaruscode::Decode_DecoderTools_Dumpers
  icaruscode::Decode_DataProducts # should become sbnobj_Common_Trigger
  icaruscode::Decode_DecoderTools
  sbndaq-artdaq-core_Overlays_Common
  sbndaq-artdaq-core_Overlays
  lardataobj::RawData
  artdaq_core::artdaq-core_Data
  ${ART_ROOT_IO_TFILESERVICE_SERVICE}
  ${ART_ROOT_IO_TFILE_SUPPORT}
  ${ART_FRAMEWORK_SERVICES_REGISTRY}
  ${MF_MESSAGELOGGER}
  ${FHICLCPP}
  cetlib_except::cetlib_except
  ROOT::Tree
  )

simple_plugin(PMTconfigurationExtraction module
  icaruscode::Decode_DecoderTools
  sbnobj::Common_PMT_Data
  art::Framework_Services_Registry
  fhiclcpp::fhiclcpp
  cetlib_except::cetlib_except
  )

simple_plugin(DumpPMTconfiguration module
  sbnobj::Common_PMT_Data
  ${MF_MESSAGELOGGER}
  fhiclcpp::fhiclcpp
  cetlib_except::cetlib_except
  )

simple_plugin(DumpArtDAQfragments module
  icaruscode::Decode_DecoderTools_Dumpers
  artdaq_core::artdaq-core_Data
  ${MF_MESSAGELOGGER}
  fhiclcpp::fhiclcpp
  cetlib_except::cetlib_except
  )

install_headers()
install_fhicl()
install_source()

# Add our tools directory
add_subdirectory(DecoderTools)
add_subdirectory(ChannelMapping)
add_subdirectory(DataProducts)
add_subdirectory(fcl)

