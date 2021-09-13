art_make( ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
 EXCLUDE
        CrtCal.cc
        CrtCalTree.cxx
	CRTTiming.cc
	CRTRawTree.cc
	CRTPreProcessTree.cc
	CRTMergePreProcessTrees.cxx
        BernCRTTranslator.cc
	
 NO_PLUGINS # WAnt different link lists for modues
 BASENAME_ONLY
 LIBRARY_NAME sbndaq-artdaq_ArtModules_Common
 LIB_LIBRARIES sbndaq-artdaq-core_Overlays
               sbndaq-artdaq-core_Overlays_Common

)

art_make_library(
    LIBRARY_NAME
        CRT_CAL
    SOURCE
        CrtCal.cc
    LIBRARIES 
        cetlib_except::cetlib_except
        ${ROOT_LIBRARIES}
        ROOT::Spectrum
        ROOT::Geom
        ROOT::Core
        cetlib::cetlib
)

art_make_library(
    LIBRARY_NAME
        CRT_CAL_TREE
    SOURCE
        CrtCalTree.cxx
    LIBRARIES 
        cetlib_except::cetlib_except
        ROOT::Core
        ${ROOT_LIBRARIES}
        ROOT::Spectrum
        ROOT::Geom
        cetlib::cetlib
)

art_make_library(
    LIBRARY_NAME
        CRT_RAW_TREE
    SOURCE
        CRTRawTree.cc
    LIBRARIES 
        cetlib_except::cetlib_except
        ROOT::Core
        ${ROOT_LIBRARIES}
        ROOT::Spectrum
        ROOT::Geom
        cetlib::cetlib
)

art_make_library(
    LIBRARY_NAME
        CRT_TIMING
    SOURCE
        CRTTiming.cc
    LIBRARIES 
        cetlib_except::cetlib_except
        ROOT::Core
        ${ROOT_LIBRARIES}
        ROOT::Spectrum
        ROOT::Geom
        cetlib::cetlib
	CRT_RAW_TREE
	CRT_PREPROCESS_TREE
)

art_make_library(
    LIBRARY_NAME
        CRT_PREPROCESS_TREE
    SOURCE
        CRTPreProcessTree.cc
    LIBRARIES 
        cetlib_except::cetlib_except
        ROOT::Core
        ${ROOT_LIBRARIES}
        ROOT::Spectrum
        ROOT::Geom
        cetlib::cetlib
)

art_make_library(
    LIBRARY_NAME
        CRT_MERGE_PREPROCESS_TREE
    SOURCE
        CRTMergePreProcessTrees.cxx
    LIBRARIES 
        cetlib_except::cetlib_except
        ROOT::Core
        ${ROOT_LIBRARIES}
        ROOT::Spectrum
        ROOT::Geom
        cetlib::cetlib
	CRT_TIMING
	CRT_PREPROCESS_TREE
)

art_make_library(
    LIBRARY_NAME
        BERN_CRT_TRANSLATOR
    SOURCE
        BernCRTTranslator.cc
    LIBRARIES 
        cetlib_except::cetlib_except
        ${CANVAS}
        ${ARTDAQ_DAQDATA}
        ${ART_FRAMEWORK_PRINCIPAL}
        sbndaq-artdaq-core_Overlays
        sbndaq-artdaq-core_Overlays_Common
        ${ART_PERSISTENCY_PROVENANCE}
        artdaq_core::artdaq-core_Data
)

install_headers()
install_source()

simple_plugin( BernCRTAna "module"
  art::Framework_Services_Registry
  art_root_io::tfile_support
  art_root_io::TFileService_service
  ${ROOT_LIBRARIES}
        ${ARTDAQ-CORE_UTILITIES}
  sbndaq-artdaq-core_Overlays_Common 
  artdaq_core::artdaq-core_Data
  BERN_CRT_TRANSLATOR
)

simple_plugin( CrtNoiseMonTool "module"
  art::Framework_Services_Registry
  art_root_io::tfile_support
  art_root_io::TFileService_service
  #art::Framework_Services_Optional
  #art::Framework_Services_Optional_TFileService_service
  ${ROOT_LIBRARIES}
        ${ARTDAQ-CORE_UTILITIES}
  sbndaq-artdaq-core_Overlays_Common 
  artdaq_core::artdaq-core_Data
  BERN_CRT_TRANSLATOR
)

simple_plugin( CrtCalAnalysis "module"
  art::Framework_Services_Registry
  art_root_io::tfile_support
  art_root_io::TFileService_service
  #art::Framework_Services_Optional
  #art::Framework_Services_Optional_TFileService_service
  ${ROOT_LIBRARIES}
        ${ARTDAQ-CORE_UTILITIES}
  sbndaq-artdaq-core_Overlays_Common 
  artdaq_core::artdaq-core_Data
  CRT_CAL
  BERN_CRT_TRANSLATOR
)

simple_plugin( AnaProducer "module"
  art::Framework_Services_Registry
  art_root_io::tfile_support
  art_root_io::TFileService_service
  #art::Framework_Services_Optional
  #art::Framework_Services_Optional_TFileService_service
  ${ROOT_LIBRARIES}
        ${ARTDAQ-CORE_UTILITIES}
  sbndaq-artdaq-core_Overlays_Common 
  artdaq_core::artdaq-core_Data
  CRT_CAL
  CRT_CAL_TREE
  CRT_RAW_TREE
  CRT_TIMING
  BERN_CRT_TRANSLATOR
)

simple_plugin( CRTEventProducer "module"
  art::Framework_Services_Registry
  art_root_io::tfile_support
  art_root_io::TFileService_service
  #art::Framework_Services_Optional
  #art::Framework_Services_Optional_TFileService_service
  #${ROOT_LIBRARIES}
  CRT_PREPROCESS_TREE
  #CRT_CAL_TREE
  sbnobj_Common_CRT
)

simple_plugin( DecoderICARUSCRT "module"
  art::Framework_Services_Registry
  art_root_io::tfile_support
  art_root_io::TFileService_service
  ${ROOT_LIBRARIES}
  ${ARTDAQ-CORE_UTILITIES}
  sbndaq-artdaq-core_Overlays_Common
  artdaq_core::artdaq-core_Data
  BERN_CRT_TRANSLATOR
  sbnobj_Common_CRT
)

install_fhicl()
