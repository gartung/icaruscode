cet_enable_asserts()

cet_find_library(LIBWDA NAMES wda PATHS ENV LIBWDA_LIB ) ### MIGRATE-ACTION-RECOMMENDED: use of ENV ... may be UPS-dependent ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking

include_directories($ENV{LIBWDA_FQ_DIR}/include) ### MIGRATE-ACTION-RECOMMENDED: use target_link_directories() with target semantics

add_subdirectory("Dumpers")

art_make( SUBDIRS details ### MIGRATE-ACTION-RECOMMENDED: use art::make_library(), art::dictionary(), simple_plugin() with explicit source lists
          LIB_LIBRARIES
                        icaruscode::Utilities
                        sbnobj_Common_PMT_Data
                        ${MF_MESSAGELOGGER}
                        ${FHICLCPP}
                        cetlib_except::cetlib_except
                        cetlib::cetlib
                        ROOT::RIO
                        ROOT::Core
          TOOL_LIBRARIES
                        sbndaq-artdaq-core_Overlays_ICARUS 
                        artdaq_core::artdaq-core_Utilities
                        icarus_signal_processing
                        icarus_signal_processing_Detection
                        icarus_signal_processing_Filters
                        icaruscode::TPC_Utilities_SignalShapingICARUSService_service
                        icaruscode::Decode_DecoderTools
                        icaruscode::Decode_DecoderTools_Dumpers
                        icaruscode::Utilities
                        larcorealg::Geometry
                        larcore::Geometry_Geometry_service
                        lardata::Utilities
                        lardataalg_DetectorInfo
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
        )

install_headers()
install_fhicl()
install_source()
