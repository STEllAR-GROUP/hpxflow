cmake_minimum_required(VERSION 3.0)
project(hpxflowproject)

###############################################################################
## file globbing ##############################################################
###############################################################################

file( GLOB_RECURSE sources ../src/algorithm/*.cpp ../src/algorithm/*.h )
file( GLOB_RECURSE sources_t  ../src/core_layer/*.cpp ../src/core_layer/*.h )
file( GLOB_RECURSE sources_f  ../src/dataflow/*.cpp ../src/dataflow/*.h )
file( GLOB_RECURSE sources_s  ../src/pipeline/*.cpp ../src/pipeline/*.h )

###############################################################################
## target definitions #########################################################
###############################################################################

add_executable(hpxflow ${sources} ${sources_t} ${sources_f} ${sources_s})

target_compile_options(hpxflow PUBLIC -std=c++11 -Wall -Wfloat-conversion)

target_include_directories( hpxflow PUBLIC src/algorithm )
target_include_directories( hpxflow PUBLIC src/core_layer )
target_include_directories( hpxflow PUBLIC src/dataflow )
target_include_directories( hpxflow PUBLIC src/pipeline )


###############################################################################
## dependencies ###############################################################
###############################################################################

find_package(Boost 1.36.0 COMPONENTS filesystem system REQUIRED)

target_link_libraries(hpxflow PUBLIC
  ${Boost_LIBRARIES}
)

###############################################################################
## packaging ##################################################################
###############################################################################

install(TARGETS hpxflow DESTINATION hpx_flow_destination)

install(DIRECTORY resources DESTINATION hpx_flow_destination)


set(CPACK_PACKAGE_NAME "hpx_flow")
set(CPACK_PACKAGE_VERSION "1.0.0")

set(CPACK_MONOLITHIC_INSTALL 1)

# This must be last
include(CPack)
