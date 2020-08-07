cmake_minimum_required(VERSION 3.17.0)

INCLUDE( SetupHunter.cmake )
project(algos VERSION 0.1.0)

#export VERBOSE=1
set(CMAKE_VERBOSE_MAKEFILE ON)
#set(HUNTER_STATUS_DEBUG ON)

set(CMAKE_CXX_STANDARD 17) ## 11 or 14 !!
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) ## on g++ this ensures: -std=c++11 and not -std=gnu++11

#SET (Boost_ADDITIONAL_VERSIONS "1.67" "1.67.0" "1.71") 
find_package(Boost 1.64 CONFIG REQUIRED COMPONENTS unit_test_framework) 
#set(Boost_DEBUG 1)
include_directories(${Boost_INCLUDE_DIRS})


include_directories(.)

FILE ( GLOB SOURCES  "${PROJECT_SOURCE_DIR}/src/*.cpp" )
 
#ADD_LIBRARY( algos_lib STATIC "${SOURCES}" )

add_executable(${PROJECT_NAME} "${SOURCES}")
TARGET_LINK_LIBRARIES ( ${PROJECT_NAME} PRIVATE Boost::unit_test_framework )
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17) # example of setting property


### ### ### ### ### ### ### TESTS
include(CTest)
enable_testing()

find_package(GTest CONFIG REQUIRED) 


add_executable(lower_bound_test test/lower_bound_test.cpp)
target_link_libraries(lower_bound_test PRIVATE GTest::gmock_main)
add_test(lower_bound lower_bound_test)

add_executable(topo_sort_test test/topo_sort_test.cpp)
target_link_libraries(topo_sort_test PRIVATE Boost::unit_test_framework)
add_test(topo_sort topo_sort_test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
