# ======================================================================
#  icaruscode main build file
#
#  cd .../path/to/build/directory
#  source .../path/to/larsoft/ups/setup_for_development <-d|-p>
#  cmake [-DCMAKE_INSTALL_PREFIX=/install/path]
#        -DCMAKE_BUILD_TYPE=$CETPKG_TYPE
#        $CETPKG_SOURCE
#  make
#  make test
#  make install
#  make package (builds distribution tarfile)
# ======================================================================
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
cmake_policy(VERSION 3.18)



find_package(cetmodules 2.25.04 REQUIRED)
project(icaruscode VERSION 09.28.02 LANGUAGES CXX)

message(STATUS
  "\n-- ============================================================================="
  "\n-- === *** Start of configuration of ${PROJECT_NAME} ***"
  "\n-- ===")


list(APPEND CMAKE_MODULE_PATH $ENV{CANVAS_ROOT_IO_DIR}/Modules $ENV{ART_DIR}/Modules)

include(CetCMakeEnv)
cet_cmake_env()

cet_set_compiler_flags(DIAGS CAUTIOUS
	WERROR
	NO_UNDEFINED
	EXTRA_FLAGS -pedantic -I$ENV{CLANG_FQ_DIR}/include/c++/v1
)

cet_report_compiler_flags(REPORT_THRESHOLD VERBOSE)

#these are minimum required versions,not thea ctual product versions
find_package(larsoft)
find_package(libwda)
find_package(PostgreSQL)
find_package(Eigen3)
find_package(ifdh_art)
find_package(guideline_sl)

find_package(sbnobj)
find_package(sbncode)
find_package(sbndaq-artdaq-core)
find_package(icarus_signal_processing)
find_package(icarusalg)
find_package(icarusutil)
find_package(icarus_data)

find_package(artdaq_core)
find_package(sbndaq_artdaq_core)

cet_find_library(PQ NAMES pq PATHS ENV POSTGRESQL_LIBRARIES NO_DEFAULT_PATH)
find_package(larcoreobj)
find_package(larcorealg)
find_package(lardataobj)
find_package(lardataalg)
find_package(larcore)
find_package(lardata)
find_package(larsim)
find_package(larevt)
find_package(larreco)
find_package(larana)
find_package(larpandora)
find_package(larpandoracontent)
find_package(nusimdata)
find_package(nurandom)
find_package(nug4)
find_package(art)
find_package(canvas)
find_package(messagefacility)
find_package(libwda)
find_package(FFTW3${FFTW_PRECISION}) ### FFTW_PRECISION=none(default),f(float),l(long),q(quad)
find_package(libwda)
find_package(ifdh_art)
find_package(guideline_sl)
find_package(ROOT)
find_package(Boost COMPONENTS system)
find_package(protobuf)
find_package(PandoraSDK)
find_package(PandoraMonitoring)

find_package(artdaq_core)
find_package(sbndaq_artdaq_core)

cet_find_library(PQ NAMES pq PATHS ENV POSTGRESQL_LIBRARIES NO_DEFAULT_PATH)
cet_find_library(NURANDOM_RANDOMUTILS_NURANDOMSERVICE_SERVICE
	NAMES nurandom_RandomUtils_NuRandomService_service
	PATHS ENV NURANDOM_LIB)

#deal with fftw
#only one precision of FFTW3 should be foundabove {,f,l,q}
#the corresponding variables are set by the config file for that precision
set(ICARUS_FFTW_LIBRARIES ${FFTW3_LIBRARIES} ${FFTW3F_LIBRARIES} ${FFTW3L_LIBRARIES} ${FFTW3Q_LIBRARIES})
set(ICARUS_FFTW_INCLUDE_DIRS ${FFTW3_INCLUDE_DIRS} ${FFTW3F_INCLUDE_DIRS} ${FFTW3L_INCLUDE_DIRS} ${FFTW3Q_INCLUDE_DIRS})
set(ICARUS_FFTW_LIBRARY_DIRS ${FFTW3_LIBRARY_DIRS} ${FFTW3F_LIRBARY_DIRS} ${FFTW3L_LIBRARY_DIRS} ${FFTW3Q_LIBRARY_DIRS})

# macros for dictionary and simple_plugin
include(ArtDictionary)
include(ArtMake)
include(BuildPlugins)

# ADD SOURCE CODE SUBDIRECTORIES HERE
add_subdirectory(icaruscode)
add_subdirectory(scripts)
add_subdirectory(doc)

# subdirectory for test code
add_subdirectory(test)

# Top level fcl files.
add_subdirectory(fcl)

# ups - table and config files

# packaging utility

message(STATUS
  "\n-- ==="
  "\n-- === *** End of configuration of ${PROJECT_NAME} ***"
  "\n-- ============================================================================="
  "\n-- "
  )

cet_cmake_config()
