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
        art::Framework_Core
        art::Framework_IO_Sources
        art::Framework_Principal
        art_root_io::TFileService_service
        canvas::canvas
        art::Framework_Services_Registry
        messagefacility::MF_MessageLogger
        messagefacility::headers
        fhiclcpp::fhiclcpp
        ${ROOT_LIBRARIES}
        ROOT::Geom
        cetlib::cetlib
)

art_make_library(
    LIBRARY_NAME
        icaruscode_CRT
    SOURCE
        CRTChannelMapAlg.cxx
    LIBRARIES larcorealg::Geometry
        icaruscode::CRTData
        cetlib_except::cetlib_except
        messagefacility::MF_MessageLogger
        messagefacility::headers
        fhiclcpp::fhiclcpp
        ${ROOT_LIBRARIES}
        ROOT::Geom
        cetlib::cetlib
)

simple_plugin(CRTGeometryHelper service
              larcorealg::Geometry
              icaruscode::CRT
              art_root_io::TFileService_service
              art::Framework_Services_Registry
              messagefacility::MF_MessageLogger
              messagefacility::headers
              ${ROOT_LIBRARIES}
)

simple_plugin(CRTDetSim module
              larcorealg::Geometry
              icaruscode::CRT
              icaruscode::CRTData
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              art_root_io::TFileService_service
              lardataalg::DetectorInfo
              nurandom::RandomUtils_NuRandomService_service
              art::Framework_Services_Registry
              art::Framework_Services_Optional_RandomNumberGenerator_service
              messagefacility::MF_MessageLogger
              messagefacility::headers
              ${ROOT_LIBRARIES}
              CLHEP::CLHEP
)

simple_plugin(CRTSimHitProducer module
              larcorealg::Geometry
              icaruscode::CRT
              icaruscode::CRTData
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              art_root_io::TFileService_service
              lardataalg::DetectorInfo
              nurandom::RandomUtils_NuRandomService_service
              art::Framework_Services_Registry
              art::Framework_Services_Optional_RandomNumberGenerator_service
              messagefacility::MF_MessageLogger
              messagefacility::headers
              ${ROOT_LIBRARIES}
              CLHEP::CLHEP
)

simple_plugin( CRTTrueHitProducer module
        larcorealg::Geometry
        icaruscode::CRT
        icaruscode::CRTData
        sbnobj_Common_CRT
        icaruscode::CRTUtils
        art::Framework_Core
        art::Framework_IO_Sources
        art::Framework_Principal
        art_root_io::TFileService_service
        art::Persistency_Provenance
        canvas::canvas
        cetlib_except::cetlib_except
        lardata::DetectorInfoServices_DetectorClocksServiceStandard_service
        art::Framework_Services_Registry
        messagefacility::MF_MessageLogger
        messagefacility::headers
        ${ROOT_LIBRARIES}
        CLHEP::CLHEP
        cetlib::cetlib
)

simple_plugin(CRTTzeroProducer module
              larcorealg::Geometry
              icaruscode::CRT
              icaruscode::CRTData
              sbnobj_Common_CRT
              art_root_io::TFileService_service
              lardataalg::DetectorInfo
              nurandom::RandomUtils_NuRandomService_service
              art::Framework_Services_Registry
              art::Framework_Services_Optional_RandomNumberGenerator_service
              messagefacility::MF_MessageLogger
              messagefacility::headers
              ${ROOT_LIBRARIES}
              CLHEP::CLHEP
)

simple_plugin(CRTTrackProducer module
              larcorealg::Geometry
              icaruscode::CRT
              icaruscode::CRTData
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              art_root_io::TFileService_service
              lardataalg_DetectorInfo
              nurandom::RandomUtils_NuRandomService_service
              art::Framework_Services_Registry
              art::Framework_Services_Optional_RandomNumberGenerator_service
              messagefacility::MF_MessageLogger
              messagefacility::headers
              ${ROOT_LIBRARIES}
              CLHEP::CLHEP
)

simple_plugin(CRTSimAnalysis module
              icaruscode::CRTData
              icaruscode::CRT
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              larcore::Geometry_Geometry_service
              larcorealg::Geometry
              nusimdata::SimulationBase
              art::Framework_Services_Registry
              art_root_io::tfile_support ROOT::Core
              art_root_io::TFileService_service
              messagefacility::MF_MessageLogger
              messagefacility::headers
              ${ROOT_LIBRARIES}
              ROOT::Geom
              ROOT::XMLIO
              ROOT::Gdml
)

simple_plugin(CRTDataAnalysis module
              icaruscode::CRTData
              icaruscode::CRT
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              larcore::Geometry_Geometry_service
              larcorealg::Geometry
              nusimdata::SimulationBase
              art::Framework_Services_Registry
              art_root_io::tfile_support ROOT::Core
              art_root_io::TFileService_service
              messagefacility::MF_MessageLogger
              messagefacility::headers
              ${ROOT_LIBRARIES}
              ROOT::Geom
              ROOT::XMLIO
              ROOT::Gdml
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
              art::Framework_Services_Registry
              art_root_io::tfile_support ROOT::Core
              art_root_io::TFileService_service
              lardataalg::DetectorInfo
              messagefacility::MF_MessageLogger
              messagefacility::headers
              ${ROOT_LIBRARIES}
)

simple_plugin(CRTTruthMatchAnalysis module
              icaruscode::CRTData
              icaruscode::CRT
              sbnobj_Common_CRT
              icaruscode::CRTUtils
              larcore::Geometry_Geometry_service
              larcorealg::Geometry
              nusimdata::SimulationBase
              art::Framework_Services_Registry
              art_root_io::tfile_support ROOT::Core
              art_root_io::TFileService_service
              messagefacility::MF_MessageLogger
              messagefacility::headers
              ${ROOT_LIBRARIES}
              ROOT::Geom
              ROOT::XMLIO
              ROOT::Gdml
)

simple_plugin( CRTAutoVeto module
                        icaruscode::CRTData
                        icaruscode::CRT
                        sbnobj_Common_CRT
                        icaruscode::CRTUtils
                        larcore::Geometry_Geometry_service
                        larcorealg::Geometry
                        nusimdata::SimulationBase
                        art::Framework_Core
                        art::Framework_Principal
                        art::Framework_Services_Registry
                        art_root_io::tfile_support ROOT::Core
                        art_root_io::TFileService_service
                        art::Persistency_Common
                        art::Persistency_Provenance
                        art::Utilities
                        canvas::canvas
                        messagefacility::MF_MessageLogger
                        messagefacility::headers
                        cetlib::cetlib cetlib_except::cetlib_except
                        ${ROOT_LIBRARIES}
                        ROOT::Geom
                        ROOT::XMLIO
                        ROOT::Gdml              
)

simple_plugin( FlashResAna module
                        larcore::Geometry_Geometry_service
                        larcorealg::Geometry
                        nusimdata_SimulationBase
                        lardataobj::RecoBase
                        art::Framework_Core
                        art::Framework_Principal
                        art::Framework_Services_Registry
                        art_root_io::tfile_support ROOT::Core
                        art_root_io::TFileService_service
                        art::Persistency_Common
                        art::Persistency_Provenance
                        art::Utilities
                        canvas::canvas
                        messagefacility::MF_MessageLogger
                        messagefacility::headers
                        cetlib::cetlib cetlib_except::cetlib_except
                        ${ROOT_LIBRARIES}
                        ROOT::Geom
                        ROOT::XMLIO
                        ROOT::Gdml              
)

simple_plugin( PhotBackground module
                        larcore::Geometry_Geometry_service
                        larcorealg::Geometry
                        nusimdata::SimulationBase
                        icaruscode::CRTData
                        icaruscode::CRT
                        sbnobj_Common_CRT
                        icaruscode::CRTUtils
                        art::Framework_Core
                        art::Framework_Principal
                        art::Framework_Services_Registry
                        art_root_io::tfile_support ROOT::Core
                        art_root_io::TFileService_service
                        art::Persistency_Common
                        art::Persistency_Provenance
                        art::Utilities
                        ${ROOT_LIBRARIES}
)

install_headers()
install_fhicl()
install_source()
