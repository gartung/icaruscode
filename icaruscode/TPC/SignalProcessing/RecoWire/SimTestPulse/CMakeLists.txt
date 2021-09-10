

art_make(   LIB_LIBRARIES ### MIGRATE-ACTION-RECOMMENDED: use art_make_library(), art::dictionary(), simple_plugin() with explicit source lists
                lardataobj::RawData
                lardataobj::RecoBase
                lardata::Utilities
                ${FHICLCPP}
                ${CETLIB}
                ${ROOT_BASIC_LIB_LIST}
            MODULE_LIBRARIES
                icaruscode_TPC_SignalProcessing_RecoWire_SimTestPulse
                icaruscode_TPC_Utilities_SignalShapingICARUSService_service
                lardata::Utilities
                lardata::DetectorInfoServices_DetectorClocksServiceStandard_service
                lardataobj::Simulation
                larcoreobj::SummaryData
                larcorealg::Geometry
                larevt::CalibrationDBI_IOVData
                larevt::CalibrationDBI_Providers
                larreco_HitFinder
                lardataobj::RecoBase
                larcorealg::Geometry
                larcore_Geometry_Geometry_service
                lardata::Utilities
                nurandom::RandomUtils_NuRandomService_service
                lardata::Utilities
                lardataobj::RawData
                larevt::CalibrationDBI_IOVData
                larevt::CalibrationDBI_Providers
                lardataobj::RecoBase
                lardata::ArtDataHelper
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
)

install_fhicl()

