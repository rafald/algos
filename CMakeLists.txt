cmake_minimum_required(VERSION 3.0.0)

project(algos VERSION 0.1.0)

#export VERBOSE=1
set(CMAKE_VERBOSE_MAKEFILE ON)


SET (Boost_ADDITIONAL_VERSIONS "1.67" "1.67.0")
find_package(Boost 1.72 CONFIG REQUIRED COMPONENTS unit_test_framework) 
#set(Boost_DEBUG 1)
#include_directories(${Boost_INCLUDE_DIRS})


include_directories(.)

FILE ( GLOB SOURCES  "${PROJECT_SOURCE_DIR}/src/*.cpp" )
 
#ADD_LIBRARY( algos_lib STATIC "${SOURCES}" )
add_executable(${PROJECT_NAME} "${SOURCES}")
TARGET_LINK_LIBRARIES ( ${PROJECT_NAME} PRIVATE Boost::unit_test_framework )


# TESTS
include(CTest)
#enable_testing()

add_executable(lower_bound_test test/lower_bound_test.cpp)
add_test(lower_bound_test test/lower_bound_test.cpp)

add_executable(topo_sort_test test/topo_sort_test.cpp)
target_link_libraries(topo_sort_test PRIVATE Boost::unit_test_framework)
add_test(topo_sort_test test/topo_sort_test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)