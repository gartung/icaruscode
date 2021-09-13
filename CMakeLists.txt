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

# cetbuildtools contains our cmake modules ### MIGRATE-ACTION-REQUIRED: remove

list(APPEND CMAKE_MODULE_PATH $ENV{CANVAS_ROOT_IO_DIR}/Modules $ENV{ART_DIR}/Modules ) ### MIGRATE-ACTION-REQUIRED: remove

include(CetCMakeEnv)
cet_cmake_env()

cet_set_compiler_flags(DIAGS CAUTIOUS
  WERROR
  NO_UNDEFINED
  EXTRA_FLAGS -pedantic -I $ENV{CLANG_FQ_DIR}/include/c++/v1 
)

cet_report_compiler_flags(REPORT_THRESHOLD VERBOSE)

# these are minimum required versions, not the actual product versions
find_package( larsoft ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( libwda ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( PostgreSQL ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( Eigen3 ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( fftw ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( ifdh_art ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( guideline_sl ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking

find_package( sbnobj ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( sbncode ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( icarus_signal_processing ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( icarusalg ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( icarusutil ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( icarus_data ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking

find_package( artdaq_core ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( sbndaq_artdaq_core ) ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking

cet_find_library( PQ NAMES pq PATHS ENV POSTGRESQL_LIBRARIES NO_DEFAULT_PATH ) ### MIGRATE-ACTION-RECOMMENDED: use of ENV ... may be UPS-dependent ### MIGRATE-ACTION-RECOMMENDED: use cet_find_package() with target semantics for linking
find_package( larcoreobj )
find_package( larcorealg )
find_package( lardataobj )
find_package( lardataalg )
find_package( larcore )
find_package( lardata )
find_package( larsim )
find_package( larevt )
find_package( larreco )
find_package( larana )
find_package( larpandora )
find_package( larpandoracontent )
find_package( nusimdata )
find_package( nurandom )
find_package( nug4 )
find_package( art )
find_package( canvas )
find_package( messagefacility )
find_package( libwda )
find_package( fftw )
find_package( libwda )
find_package( ifdh_art )
find_package( guideline_sl )
find_package( ROOT )
find_package( Boost COMPONENTS system)
find_package( protobuf )

find_package( artdaq_core )
find_package( sbndaq_artdaq_core )

cet_find_library( PQ NAMES pq PATHS ENV POSTGRESQL_LIBRARIES NO_DEFAULT_PATH )
cet_find_library( NURANDOM_RANDOMUTILS_NURANDOMSERVICE_SERVICE
                  NAMES nurandom_RandomUtils_NuRandomService_service
                  PATHS ENV NURANDOM_LIB ) ### MIGRATE-ACTION-RECOMMENDED: use of ENV ... may be UPS-dependent

# deal with fftw
cet_find_library(ICARUS_FFTW3_LIBRARY  NAMES fftw3  PATHS ENV FFTW_LIBRARY )
cet_find_library(ICARUS_FFTW3F_LIBRARY NAMES fftw3f PATHS ENV FFTW_LIBRARY )
cet_find_library(ICARUS_FFTW3L_LIBRARY NAMES fftw3l PATHS ENV FFTW_LIBRARY )
cet_find_library(ICARUS_FFTW3Q_LIBRARY NAMES fftw3q PATHS ENV FFTW_LIBRARY )
set(ICARUS_FFTW_LIBRARIES ICARUS_FFTW3_LIBRARY ICARUS_FFTW3F_LIBRARY ICARUS_FFTW3L_LIBRARY ICARUS_FFTW3Q_LIBRARY)

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
