#Leave this out for the time being. One day the grid will be updated enough ...
#cet_set_compiler_flags(EXTRA_CXX_FLAGS -mavx)

include_directories(${CPPGSL_INC})

art_make(
	LIB_LIBRARIES
		larcorealg::Geometry
		lardataobj::RawData
		icarusalg::Utilities
                lardataalg::DetectorInfo
		#lardataobj::RecoBase
		#lardata::Utilities
		#larcorealg::Geometry
		#lardata::ArtDataHelper
		#nusimdata::SimulationBase
		canvas::canvas
		messagefacility::MF_MessageLogger
		messagefacility::headers
		fhiclcpp::fhiclcpp
		cetlib::cetlib
		cetlib_except::cetlib_except
		${ROOT_FFTW}
		${ROOT_GENVECTOR}
		CLHEP::Random
		#${Boost_SYSTEM_LIBRARY}
	)

install_headers()
install_fhicl()
install_source()
