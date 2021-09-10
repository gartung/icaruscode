art_make( ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
             LIB_LIBRARIES larcorealg::Geometry
                           larcore::Geometry_Geometry_service
                           larsim::Simulation lardataobj::Simulation
                           larsim::MCCheater_BackTrackerService_service
                           larsim::MCCheater_ParticleInventoryService_service
                           lardata::Utilities
                           larevt::Filters
                           lardataobj::RawData
                           lardataobj::RecoBase
                           lardata::RecoObjects
                           larpandora::LArPandoraInterface
                           nusimdata::SimulationBase
                           cetlib::cetlib cetlib_except::cetlib_except
                           ${ART_FRAMEWORK_CORE}
                           ${ART_FRAMEWORK_PRINCIPAL}
                           ${ART_FRAMEWORK_SERVICES_REGISTRY}
                           ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
                           ${ART_ROOT_IO_TFILESERVICE_SERVICE}
                           art::Persistency_Common canvas::canvas
                           art::Persistency_Provenance
                           art::Utilities
                           ${MF_MESSAGELOGGER}
                           ${MF_UTILITIES}
                           ${FHICLCPP}
                           ${ROOT_GEOM}
                           ${ROOT_XMLIO}
                           ${ROOT_GDML}
                           ${ROOT_BASIC_LIB_LIST}
                           ${Boost_SYSTEM_LIBRARY}
        )

install_headers()
install_fhicl()
install_source()


#art_make( ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art_dictionary(), simple_plugin() with explicit source lists
#	  LIB_LIBRARIES larcorealg::Geometry
#	  	        larcore::Geometry_Geometry_service
#		        larsim_Simulation nurandom_ParticleNavigation lardataobj_Simulation
# 	  	        larsim::MCCheater_BackTracker_service
#	  	        lardata::Utilities
#larevt::Filters
#	  	        lardataobj::RawData
#	  	        lardataobj::RecoBase
#	  	        lardata::RecoObjects
#larreco_RecoAlg
#larreco_Calorimetry
#larpandora_LArPandoraInterface
#          	        nusimdata::SimulationBase
#          	        ${LARRECO_LIB}
#          	        ${LARDATA_LIB}
#	  	        ${MF_MESSAGELOGGER}
#	  	        ${MF_UTILITIES}
#	  	        ${FHICLCPP}
#	  	        cetlib::cetlib cetlib_except::cetlib_except
#          	        ${ROOT_GEOM}
#          	        ${ROOT_XMLIO}
#          	        ${ROOT_GDML}
#	  	        ${ROOT_BASIC_LIB_LIST}
#	  MODULE_LIBRARIES RecoUtils
#          	           ${ART_FRAMEWORK_CORE}
#	  	           ${ART_FRAMEWORK_PRINCIPAL}
#		       	   ${ART_FRAMEWORK_SERVICES_REGISTRY}
#	  	       	   ${ART_ROOT_IO_TFILE_SUPPORT} ${ROOT_CORE}
#			   ${ART_ROOT_IO_TFILESERVICE_SERVICE}
#	  	           art::Persistency_Common canvas
#	  	           art::Persistency_Provenance canvas
#	  	           art::Utilities canvas
#        )
#
#install_headers()
##install_fhicl()
#install_source()
##install_scripts()
