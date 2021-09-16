include_directories(${TRACE_INC})

art_make(
	EXCLUDE
		CrtCal.cc
		CrtCalTree.cxx
	CRTTiming.cc
	CRTRawTree.cc
	CRTPreProcessTree.cc
	CRTMergePreProcessTrees.cxx
	BernCRTTranslator.cc
	
	NO_PLUGINS
	BASENAME_ONLY
	LIBRARY_NAME sbndaq-artdaq_ArtModules_Common
	LIB_LIBRARIES sbndaq-artdaq-core::Overlays
		sbndaq-artdaq-core::Overlays_Common

)

art_make_library(
	LIBRARY_NAME
		CRT_CAL
	SOURCE
		CrtCal.cc
	LIBRARIES
		cetlib_except::cetlib_except
                ROOT::Graf
		ROOT::Spectrum
		ROOT::Geom
		ROOT::Core
                ROOT::Gpad
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
		ROOT::Spectrum
		ROOT::Geom
		cetlib::cetlib ROOT::Tree
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
		ROOT::Spectrum
		ROOT::Geom
                ROOT::Tree
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
		canvas::canvas
		
		art::Framework_Principal
		sbndaq-artdaq-core::Overlays
		sbndaq-artdaq-core::Overlays_Common
		art::Persistency_Provenance
		artdaq_core::artdaq-core_Data
	)

install_headers()
install_source()

simple_plugin(BernCRTAna "module"
	art::Framework_Services_Registry
	art_root_io::tfile_support
	art_root_io::TFileService_service
	artdaq_core::artdaq-core_Utilities
	sbndaq-artdaq-core::Overlays_Common
	artdaq_core::artdaq-core_Data
	BERN_CRT_TRANSLATOR
	ROOT::Tree ROOT::Hist ROOT::Core
	)

simple_plugin(CrtNoiseMonTool "module"
	art::Framework_Services_Registry
	art_root_io::tfile_support
	art_root_io::TFileService_service
	#art::Framework_Services_Optional
	artdaq_core::artdaq-core_Utilities
	sbndaq-artdaq-core::Overlays_Common
	artdaq_core::artdaq-core_Data
	BERN_CRT_TRANSLATOR
	ROOT::Tree ROOT::Hist ROOT::Core
	)

simple_plugin(CrtCalAnalysis "module"
	art::Framework_Services_Registry
	art_root_io::tfile_support
	art_root_io::TFileService_service
	#art::Framework_Services_Optional
	#art::Framework_Services_Optional_TFileService_service
	artdaq_core::artdaq-core_Utilities
	sbndaq-artdaq-core::Overlays_Common
	artdaq_core::artdaq-core_Data
	CRT_CAL
	BERN_CRT_TRANSLATOR
	ROOT::Tree ROOT::Hist ROOT::Core
	)

simple_plugin(AnaProducer "module"
	art::Framework_Services_Registry
	art_root_io::tfile_support
	art_root_io::TFileService_service
	#art::Framework_Services_Optional
	#art::Framework_Services_Optional_TFileService_service
	artdaq_core::artdaq-core_Utilities
	sbndaq-artdaq-core::Overlays_Common
	artdaq_core::artdaq-core_Data
	CRT_CAL
	CRT_CAL_TREE
	CRT_RAW_TREE
	CRT_TIMING
	BERN_CRT_TRANSLATOR
	ROOT::Tree ROOT::Hist ROOT::Core
	)

simple_plugin(CRTEventProducer "module"
	art::Framework_Services_Registry
	art_root_io::tfile_support
	art_root_io::TFileService_service
	#art::Framework_Services_Optional
	#art::Framework_Services_Optional_TFileService_service
	#
	CRT_PREPROCESS_TREE
	#CRT_CAL_TREE
	sbnobj::Common_CRT
	lardata::Utilities
        larcore::Geometry_StandardGeometryHelper_service
	ROOT::Tree ROOT::Hist ROOT::Core
	)

simple_plugin(DecoderICARUSCRT "module"
	art::Framework_Services_Registry
	art_root_io::tfile_support
	art_root_io::TFileService_service
	artdaq_core::artdaq-core_Utilities
	sbndaq-artdaq-core::Overlays_Common
	artdaq_core::artdaq-core_Data
	BERN_CRT_TRANSLATOR
	sbnobj::Common_CRT
	ROOT::Tree ROOT::Hist ROOT::Core
	)

install_fhicl()
