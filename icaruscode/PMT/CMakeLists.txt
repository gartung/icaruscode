add_subdirectory(OpticalTools)
add_subdirectory(OpReco)
add_subdirectory(Algorithms)
add_subdirectory(LibraryMappingTools)
add_subdirectory(Trigger)

# Removing AVX instructions because assuming the grid nodes
# being less than 6 year old proved to be pretentious.
# AVX is not so relevant after the last commit anyway
# cet_set_compiler_flags(EXTRA_CXX_FLAGS -mavx)

simple_plugin(SimPMTIcarus "module"
  icaruscode::PMT_Algorithms
  lardataobj::RawData
  lardataobj::Simulation
  nurandom::RandomUtils_NuRandomService_service
  ${ART_FRAMEWORK_CORE}
  ${ART_FRAMEWORK_PRINCIPAL}
  ${ART_FRAMEWORK_SERVICES_REGISTRY}
  ${ART_FRAMEWORK_SERVICES_OPTIONAL_RANDOMNUMBERGENERATOR_SERVICE}
  ${ART_ROOT_IO_TFILESERVICE_SERVICE}
  ${ART_ROOT_IO_TFILE_SUPPORT}
  art::Persistency_Provenance
  ${CANVAS}
  ${MF_MESSAGELOGGER}
  ${FHICLCPP}
  ${CETLIB}
  cetlib_except::cetlib_except
  ${ROOT_BASIC_LIB_LIST}
  ${Boost_SYSTEM_LIBRARY}
  )

simple_plugin(PMTWaveformBaselines "module"
  icaruscode::PMT_Algorithms
  sbnobj_ICARUS_PMT_Data
  larcore::Geometry_Geometry_service
  larcorealg::Geometry
  lardataobj::RawData
  ${ART_ROOT_IO_TFILESERVICE_SERVICE}
  ${ART_ROOT_IO_TFILE_SUPPORT}
  ${ART_FRAMEWORK_SERVICES_REGISTRY}
  ${MF_MESSAGELOGGER}
  ROOT::Hist
  ROOT::Core
  )

simple_plugin(PMTWaveformBaselinesFromReadoutConfiguration "module"
  sbnobj_ICARUS_PMT_Data
  sbnobj_Common_PMT_Data
  larcore::Geometry_Geometry_service
  larcorealg::Geometry
  lardataobj::RawData
  ${ART_ROOT_IO_TFILESERVICE_SERVICE}
  ${ART_ROOT_IO_TFILE_SUPPORT}
  ${ART_FRAMEWORK_SERVICES_REGISTRY}
  ${MF_MESSAGELOGGER}
  ROOT::Hist
  ROOT::Core
  )


simple_plugin(AsymGaussPulseFunctionTool "tool"
  icaruscode::PMT_Algorithms
  )

simple_plugin(AsymExpPulseFunctionTool "tool"
  icaruscode::PMT_Algorithms
  )

simple_plugin(CustomPulseFunctionTool "tool"
  icaruscode::PMT_Algorithms
  ROOT::Hist
  )


art_make( ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
  EXCLUDE
    "SimPMTIcarus_module.cc"
    "PMTWaveformBaselines_module.cc"
    "PMTWaveformBaselinesFromReadoutConfiguration_module.cc"
    "AsymGaussPulseFunctionTool_tool.cc"
    "AsymExpPulseFunctionTool_tool.cc"
    "CustomPulseFunctionTool_tool.cc"
          LIB_LIBRARIES 
            lardataobj::RawData
            lardataobj::RecoBase
            lardata::Utilities
            ${FHICLCPP}
			${CETLIB}
			${ROOT_BASIC_LIB_LIST}
			${Boost_SYSTEM_LIBRARY}
	        MODULE_LIBRARIES larcorealg::Geometry
	  		larcore::Geometry_Geometry_service
	        lardata::Utilities
			larevt::Filters
			lardataobj::RawData
			larevt::CalibrationDBI_IOVData
			larevt::CalibrationDBI_Providers
			lardataobj::RecoBase
			lardata::ArtDataHelper
			nusimdata::SimulationBase
            nurandom::RandomUtils_NuRandomService_service
			${CLHEP}
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
			cetlib_except::cetlib_except
            ${ROOT_GEOM}
            ${ROOT_XMLIO}
            ${ROOT_GDML}
			${ROOT_FFTW}
			${ROOT_BASIC_LIB_LIST}
			${Boost_SYSTEM_LIBRARY}
        )

install_headers()
install_fhicl()
install_source()
install_scripts(
  SUBDIRS scripts
  EXTRAS
    "scripts/MergePhotonLibrary.C"
    "scripts/RecompressROOTtrees.C"
  )

