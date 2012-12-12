#include_directories("${GTEST_DIR}/include")
include_directories("${CORE_TESTS_DIR}")

add_executable (core_tests core_tests.cpp Vector_Tests.cpp)

add_dependencies (core_tests googletest)

# Specify MainTest's link libraries
ExternalProject_Get_Property(googletest binary_dir)
TARGET_LINK_LIBRARIES (core_tests
        debug ${binary_dir}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${binary_dir}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES})

