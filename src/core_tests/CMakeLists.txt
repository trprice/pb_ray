#include_directories("${GTEST_DIR}/include")
INCLUDE_DIRECTORIES("${CORE_TESTS_DIR}")

ADD_EXECUTABLE (core_tests core_tests.cpp Vector_Tests.cpp)

ADD_DEPENDENCIES (core_tests googletest)

ExternalProject_Get_Property(googletest binary_dir)

# Setup the lib extensions to force a static lib.
IF (WIN32)
    SET (LIBRARY_DIR_DEBUG ${binary_dir}/DebugLibs/ ${LIBRARY_DIR_DEBUG})
    SET (LIBRARY_DIR_RELEASE ${binary_dir}/ReleaseLibs/ ${LIBRARY_DIR_RELEASE})
    SET (CMAKE_FIND_LIBRARY_SUFFIXES .lib ${CMAKE_FIND_LIBRARY_SUFFIXES})
ELSE ()
    SET (LIBRARY_DIR_DEBUG ${binary_dir}/ ${LIBRARY_DIR_DEBUG})
    SET (LIBRARY_DIR_RELEASE ${binary_dir}/ ${LIBRARY_DIR_RELEASE})
    SET (CMAKE_FIND_LIBRARY_SUFFIXES .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
ENDIF ()


# Specify MainTest's link libraries
TARGET_LINK_LIBRARIES (core_tests
        debug ${LIBRARY_DIR_DEBUG}${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${LIBRARY_DIR_RELEASE}${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES})

