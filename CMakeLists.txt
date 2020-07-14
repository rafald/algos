cmake_minimum_required(VERSION 3.0.0)
project(algos VERSION 0.1.0)

#set(Boost_DEBUG 1)

set(BOOST_ROOT "/media/raf/EXT4STORE/develop/c++/boost_1_73_0") # /stage

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
#SET (Boost_ADDITIONAL_VERSIONS "1.67" "1.67.0")

include(CTest)
enable_testing()

# add_executable(algos main.cpp)
set(SOURCE topo_sort_test.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

find_package(Boost 1.73 REQUIRED COMPONENTS unit_test_framework system) # thread regex 
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  target_link_libraries(${PROJECT_NAME} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${Boost_SYSTEM_LIBRARY})
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

