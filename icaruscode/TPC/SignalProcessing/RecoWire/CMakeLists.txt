if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
cet_add_compiler_flags(CXX -Wno-maybe-uninitialized)
endif()

# Add the subfolder containing the deconvolution tools
add_subdirectory(DeconTools)
add_subdirectory(ROITools)
add_subdirectory(SimTestPulse)

add_definitions(-DEIGEN_FFTW_DEFAULT)

art_make(  ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
          LIB_LIBRARIES 
            lardataobj::RawData
            lardataobj::RecoBase
            lardata::Utilities
            ${FHICLCPP}
            ${CETLIB}
            ${ROOT_BASIC_LIB_LIST}
          MODULE_LIBRARIES 
            icarus_signal_processing
            icarus_signal_processing_Detection
            icarus_signal_processing_Filters
            larcorealg::Geometry
            larcore::Geometry_Geometry_service
            lardata::Utilities
            lardataalg::DetectorInfo
            larevt::Filters
            lardataobj::RawData
            larevt::CalibrationDBI_IOVData
            larevt::CalibrationDBI_Providers
            lardataobj::RecoBase
            lardata::ArtDataHelper
            icaruscode::TPC_Utilities_SignalShapingICARUSService_service
            ${ART_FRAMEWORK_CORE}
            ${ART_FRAMEWORK_PRINCIPAL}
            ${ART_FRAMEWORK_SERVICES_REGISTRY}
            ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
            ${ART_ROOT_IO_TFILESERVICE_SERVICE}
            art::Persistency_Common
            art::Persistency_Provenance
            art::Utilities
            canvas::canvas
            ${MF_MESSAGELOGGER}
            ${MF_UTILITIES}
            ${FHICLCPP}
            ${CETLIB}
            ${ROOT_FFTW}
            ${ROOT_BASIC_LIB_LIST}
            ${TBB}
        )

install_headers()
install_fhicl()
install_source()
