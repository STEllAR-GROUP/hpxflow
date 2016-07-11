cmake_minimum_required(VERSION 3.0)
project(hpx_flow_project)

###############################################################################
## file globbing ##############################################################
###############################################################################

file( GLOB_RECURSE sources src/algorithm/*.cpp src/algorithm/*.h )
file( GLOB_RECURSE sources_t  src/core_layer/*.cpp src/core_layer/*.h )
file( GLOB_RECURSE sources_f  src/dataflow/*.cpp src/dataflow/*.h )
file( GLOB_RECURSE sources_s  src/pipeline/*.cpp src/pipeline/*.h )

###############################################################################
## target definitions #########################################################
###############################################################################

add_executable( hpx_flow ${sources} ${sources_t} ${sources_f} ${sources_s} )

target_compile_options(hpx_flow PUBLIC -std=c++11 -Wall -Wfloat-conversion)

target_include_directories( hpx_flow PUBLIC src/algorithm )
target_include_directories( hpx_flow PUBLIC src/core_layer )
target_include_directories( hpx_flow PUBLIC src/dataflow )
target_include_directories( hpx_flow PUBLIC src/pipeline )


###############################################################################
## dependencies ###############################################################
###############################################################################

find_package(Boost 1.36.0 COMPONENTS filesystem system REQUIRED)

target_link_libraries(hpx_flow PUBLIC
  ${Boost_LIBRARIES}
)

###############################################################################
## packaging ##################################################################
###############################################################################

install(TARGETS hpx_flow DESTINATION hpx_flow_destination)

install(DIRECTORY resources DESTINATION hpx_flow_destination)


set(CPACK_PACKAGE_NAME "hpx_flow")
set(CPACK_PACKAGE_VERSION "1.0.0")

set(CPACK_MONOLITHIC_INSTALL 1)

# This must be last
include(CPack)
