cmake_minimum_required(VERSION 3.0.0)
project(algos VERSION 0.1.0)

#export VERBOSE=1
set(CMAKE_VERBOSE_MAKEFILE ON)
#set(Boost_DEBUG 1)

set(BOOST_ROOT "/home/raf/develop/c++/boost_1_73_0" CACHE STRING "root of boost source code tree") # /stage

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
#SET (Boost_ADDITIONAL_VERSIONS "1.67" "1.67.0")
find_package(Boost 1.73 REQUIRED COMPONENTS unit_test_framework system) # thread regex 
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  #target_link_libraries(topo_sort_test ${Boost_SYSTEM_LIBRARY})
endif()

include(CTest)
#enable_testing()

SET ( PATH_SOURCE  "${PROJECT_SOURCE_DIR}/src" )
SET ( PATH_TEST    "${PROJECT_SOURCE_DIR}/test" )
SET ( NAME_TEST    "test_myproject" )

FILE ( GLOB SOURCES_LIB  "${PATH_SOURCE}/*.c" "${PATH_SOURCE}/*.cpp" )
FILE ( GLOB SOURCES_TEST "${PATH_TEST}/*.c" "${PATH_TEST}/*.cpp" )

include_directories(.)

# add_executable(algos main.cpp)
#set(SOURCE topo_sort_test.cpp)
#add_executable(${PROJECT_NAME} ${SOURCE})

add_executable(topo_sort_test test/topo_sort_test.cpp)
target_link_libraries(topo_sort_test ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_SYSTEM_LIBRARY})
add_test(topo_sort_test test/topo_sort_test)

add_executable(lower_bound_test test/lower_bound_test.cpp)
add_test(lower_bound_test test/lower_bound_test.cpp)

#ADD_LIBRARY( ${NAME_LIB} STATIC "${SOURCES_LIB}" )
#ADD_EXECUTABLE ( ${NAME_TEST} "${SOURCES_TEST}" )
#TARGET_LINK_LIBRARIES ( ${NAME_TEST} "${PATH_BUILD}/${NAME_LIB}" )


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
