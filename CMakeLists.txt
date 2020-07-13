cmake_minimum_required(VERSION 3.0.0)
project(algos VERSION 0.1.0)

# /media/raf/EXT4STORE/develop/c++/boost/stage/lib
#set(BOOST_ROOT "/media/raf/EXT4STORE/develop/c++/boost")
set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
#set(Boost_USE_STATIC_RUNTIME    OFF)

include(CTest)
enable_testing()

# add_executable(algos main.cpp)
set(SOURCE topo_sort_test.cpp)

find_package(Boost 1.65.1 COMPONENTS thread regex system)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(${PROJECT_NAME} ${SOURCE})
  target_link_libraries(${PROJECT_NAME} ${Boost_TEST_LIBRARY} ${Boost_SYSTEM_LIBRARY})
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

