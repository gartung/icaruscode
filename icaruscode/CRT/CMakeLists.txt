include_directories( ${CMAKE_CURRENT_SOURCE_DIR} ) ### MIGRATE-ACTION-RECOMMENDED: use target_link_directories() with target semantics
include_directories( $ENV{NURANDOM_INC} ) ### MIGRATE-ACTION-RECOMMENDED: use target_link_directories() with target semantics
include_directories( $ENV{IFDHX_FQ_DIR}/inc ) ### MIGRATE-ACTION-RECOMMENDED: use target_link_directories() with target semantics

add_subdirectory(CRTUtils)
add_subdirectory(CRTDecoder)

art_make( ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
    NO_PLUGINS
    EXCLUDE
        CRTChannelMapAlg.cxx
        CRTGeometryHelper_service.cc
        CRTDetSim_module.cc
        CRTSimHitProducer_module.cc
        CRTTrueHitProducer_module.cc
        CRTTzeroProducer_module.cc
        CRTTrackProducer_module.cc
        CRTSimAnalysis_module.cc
        CRTDataAnalysis_module.cc
        CrtOpHitMatchAnalysis_module.cc
        CRTTruthMatchAnalysis_module.cc
        CRTAutoVeto_module.cc
        FlashResAna_module.cc
        PhotBackground_module.cc
    LIBRARY_NAME
        icaruscode_CRTData
    LIB_LIBRARIES
        larcorealg::Geometry
        larcore::Geometry_Geometry_service
        ${ART_FRAMEWORK_CORE}
        ${ART_FRAMEWORK_IO_SOURCES}
        ${ART_FRAMEWORK_PRINCIPAL}
        ${ART_ROOT_IO_TFILESERVICE_SERVICE}
        canvas::canvas
        ${ART_FRAMEWORK_SERVICES_REGISTRY}
        ${MF_MESSAGELOGGER}
        ${MF_UTILITIES}
        ${FHICLCPP}
        ${ROOT_BASIC_LIB_LIST}
        ${ROOT_GEOM}
        ${CETLIB}
)

art_make_library(
    LIBRARY_NAME
        icaruscode_CRT
    SOURCE
        CRTChannelMapAlg.cxx
    LIBRARIES larcorealg::Geometry
        icaruscode::CRTData
        cetlib_except::cetlib_except
        ${MF_MESSAGELOGGER}
        ${MF_UTILITIES}
        ${FHICLCPP}
        ${ROOT_BASIC_LIB_LIST}
        ${ROOT_GEOM}
        ${CETLIB}
)

simple_plugin(CRTGeometryHelper service
              larcorealg::Geometry
              icaruscode::CRT
              ${ART_ROOT_IO_TFILESERVICE_SERVICE}
              ${ART_FRAMEWORK_SERVICES_REGISTRY}
              ${MF_MESSAGELOGGER}
              ${MF_UTILITIES}
              ${ROOT_BASIC_LIB_LIST}
)

simple_plugin(CRTDetSim module
              larcorealg::Geometry
              icaruscode::CRT
              icaruscode::CRTData
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              ${ART_ROOT_IO_TFILESERVICE_SERVICE}
              lardataalg::DetectorInfo
              nurandom::RandomUtils_NuRandomService_service
              ${ART_FRAMEWORK_SERVICES_REGISTRY}
              ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
              ${MF_MESSAGELOGGER}
              ${MF_UTILITIES}
              ${ROOT_BASIC_LIB_LIST}
              ${CLHEP}
)

simple_plugin(CRTSimHitProducer module
              larcorealg::Geometry
              icaruscode::CRT
              icaruscode::CRTData
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              ${ART_ROOT_IO_TFILESERVICE_SERVICE}
              lardataalg::DetectorInfo
              nurandom::RandomUtils_NuRandomService_service
              ${ART_FRAMEWORK_SERVICES_REGISTRY}
              ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
              ${MF_MESSAGELOGGER}
              ${MF_UTILITIES}
              ${ROOT_BASIC_LIB_LIST}
              ${CLHEP}
)

simple_plugin( CRTTrueHitProducer module
        larcorealg::Geometry
        icaruscode::CRT
        icaruscode::CRTData
        sbnobj_Common_CRT
        icaruscode::CRTUtils
        ${ART_FRAMEWORK_CORE}
        ${ART_FRAMEWORK_IO_SOURCES}
        ${ART_FRAMEWORK_PRINCIPAL}
        ${ART_ROOT_IO_TFILESERVICE_SERVICE}
        art::Persistency_Provenance
        canvas::canvas
        cetlib_except::cetlib_except
        lardata::DetectorInfoServices_DetectorClocksServiceStandard_service
        ${ART_FRAMEWORK_SERVICES_REGISTRY}
        ${MF_MESSAGELOGGER}
        ${MF_UTILITIES}
        ${ROOT_BASIC_LIB_LIST}
        ${CLHEP}
        ${CETLIB}
)

simple_plugin(CRTTzeroProducer module
              larcorealg::Geometry
              icaruscode::CRT
              icaruscode::CRTData
              sbnobj_Common_CRT
              ${ART_ROOT_IO_TFILESERVICE_SERVICE}
              lardataalg::DetectorInfo
              nurandom::RandomUtils_NuRandomService_service
              ${ART_FRAMEWORK_SERVICES_REGISTRY}
              ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
              ${MF_MESSAGELOGGER}
              ${MF_UTILITIES}
              ${ROOT_BASIC_LIB_LIST}
              ${CLHEP}
)

simple_plugin(CRTTrackProducer module
              larcorealg::Geometry
              icaruscode::CRT
              icaruscode::CRTData
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              ${ART_ROOT_IO_TFILESERVICE_SERVICE}
              lardataalg_DetectorInfo
              nurandom::RandomUtils_NuRandomService_service
              ${ART_FRAMEWORK_SERVICES_REGISTRY}
              ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
              ${MF_MESSAGELOGGER}
              ${MF_UTILITIES}
              ${ROOT_BASIC_LIB_LIST}
              ${CLHEP}
)

simple_plugin(CRTSimAnalysis module
              icaruscode::CRTData
              icaruscode::CRT
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              larcore::Geometry_Geometry_service
              larcorealg::Geometry
              nusimdata::SimulationBase
              ${ART_FRAMEWORK_SERVICES_REGISTRY}
              ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
              ${ART_ROOT_IO_TFILESERVICE_SERVICE}
              ${MF_MESSAGELOGGER}
              ${MF_UTILITIES}
              ${ROOT_BASIC_LIB_LIST}
              ${ROOT_GEOM}
              ${ROOT_XMLIO}
              ${ROOT_GDML}
)

simple_plugin(CRTDataAnalysis module
              icaruscode::CRTData
              icaruscode::CRT
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              larcore::Geometry_Geometry_service
              larcorealg::Geometry
              nusimdata::SimulationBase
              ${ART_FRAMEWORK_SERVICES_REGISTRY}
              ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
              ${ART_ROOT_IO_TFILESERVICE_SERVICE}
              ${MF_MESSAGELOGGER}
              ${MF_UTILITIES}
              ${ROOT_BASIC_LIB_LIST}
              ${ROOT_GEOM}
              ${ROOT_XMLIO}
              ${ROOT_GDML}
)

simple_plugin(CrtOpHitMatchAnalysis module
              icaruscode::CRTData
              icaruscode::CRT
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              larcore::Geometry_Geometry_service
              larcorealg::Geometry
              nusimdata::SimulationBase
              lardataobj::RecoBase
              ${ART_FRAMEWORK_SERVICES_REGISTRY}
              ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
              ${ART_ROOT_IO_TFILESERVICE_SERVICE}
              lardataalg::DetectorInfo
              ${MF_MESSAGELOGGER}
              ${MF_UTILITIES}
              ${ROOT_BASIC_LIB_LIST}
)

simple_plugin(CRTTruthMatchAnalysis module
              icaruscode::CRTData
              icaruscode::CRT
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              larcore::Geometry_Geometry_service
              larcorealg::Geometry
              nusimdata::SimulationBase
              ${ART_FRAMEWORK_SERVICES_REGISTRY}
              ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
              ${ART_ROOT_IO_TFILESERVICE_SERVICE}
              ${MF_MESSAGELOGGER}
              ${MF_UTILITIES}
              ${ROOT_BASIC_LIB_LIST}
              ${ROOT_GEOM}
              ${ROOT_XMLIO}
              ${ROOT_GDML}
)

simple_plugin( CRTAutoVeto module
                        icaruscode::CRTData
                        icaruscode::CRT
                        sbnobj_Common_CRT
                        icaruscode::CRTUtils
                        larcore::Geometry_Geometry_service
                        larcorealg::Geometry
                        nusimdata::SimulationBase
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
                        cetlib::cetlib cetlib_except::cetlib_except
                        ${ROOT_BASIC_LIB_LIST}
                        ${ROOT_GEOM}
                        ${ROOT_XMLIO}
                        ${ROOT_GDML}              
)

simple_plugin( FlashResAna module
                        larcore::Geometry_Geometry_service
                        larcorealg::Geometry
                        nusimdata_SimulationBase
                        lardataobj::RecoBase
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
                        cetlib::cetlib cetlib_except::cetlib_except
                        ${ROOT_BASIC_LIB_LIST}
                        ${ROOT_GEOM}
                        ${ROOT_XMLIO}
                        ${ROOT_GDML}              
)

simple_plugin( PhotBackground module
                        larcore::Geometry_Geometry_service
                        larcorealg::Geometry
                        nusimdata::SimulationBase
                        icaruscode::CRTData
                        icaruscode::CRT
                        sbnobj_Common_CRT
                        icaruscode::CRTUtils
                        ${ART_FRAMEWORK_CORE}
                        ${ART_FRAMEWORK_PRINCIPAL}
                        ${ART_FRAMEWORK_SERVICES_REGISTRY}
                        ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
                        ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                        art::Persistency_Common
                        art::Persistency_Provenance
                        art::Utilities
                        ${ROOT_BASIC_LIB_LIST}
)

install_headers()
install_fhicl()
install_source()
