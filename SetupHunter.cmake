set(CMAKE_FIND_PACKAGE_PREFER_CONFIG TRUE)

include(FetchContent)
FetchContent_Declare(SetupHunter GIT_REPOSITORY https://github.com/cpp-pm/gate)

set(HUNTER_Boost_COMPONENTS test) 
set(HUNTER_pcre2_CMAKE_ARGS
    PCRE2_BUILD_PCRE2_8=OFF
    PCRE2_BUILD_PCRE2_16=ON
    PCRE2_BUILD_PCRE2_32=OFF
    PCRE2_SUPPORT_JIT=ON)
set(HUNTER_PACKAGES pcre2 GTest Boost) 

FetchContent_MakeAvailable(SetupHunter)
