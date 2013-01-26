cmake_minimum_required (VERSION 2.6)

project (pb_ray)

# Setup the version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)


# Setup the project directories.
set (PROJECT_SOURCE_DIR src)
set (PROJECT_INCLUDE_DIR include)
set (PROJECT_BUILD_DIR build)
set (PROJECT_BUILD_INCLUDE_DIR build/include)
set (PROJECT_BIN_DIR bin)
set (PROJECT_LIB_DIR lib)
set (THIRD_PARTY_DIR third_party)


# Setup output directories
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR})


# Add the binary directory to the search path.
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_BUILD_INCLUDE_DIR}")


# Set the configuration type to debug if it wasn't set by `make edit_cache`
#IF (NOT CMAKE_BUILD_TYPE)
#    SET (CMAKE_BUILD_TYPE Debug)
#    SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG")
#ENDIF (NOT CMAKE_BUILD_TYPE)


###############
# Setup libraries to be linked.
###############

# SHOULD GTEST BE ADDED AS A SUBDIRECTORY OF WHATEVER EXECUTABLE NEEDS IT
# INSTEAD OF HERE AT THE TOP LEVEL?
# Setup gtest
#add_subdirectory (${GTEST_DIR})
#include_directories("${GTEST_DIR}")

# Try using ExternalProject_Add( ) for gtest.
# Enable ExternalProject CMake module
INCLUDE (ExternalProject)

# Set default ExternalProject root directory
SET_DIRECTORY_PROPERTIES(PROPERTIES EP_PREFIX ${THIRD_PARTY_DIR})


#   See http://stackoverflow.com/questions/9689183/cmake-googletest/9695234#9695234
#   for an example
ExternalProject_Add(
    googletest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
    TIMEOUT 10
    # Force separate output paths for debug and release builds to allow easy
    # identification of correct lib in subsequent TARGET_LINK_LIBRARIES commands
    CMAKE_ARGS -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
               -Dgtest_force_shared_crt=ON
    # Disable install step
    INSTALL_COMMAND ""
    # Wrap download, configure and build steps in a script to log output
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON)

# Setup the gtest include directories.
ExternalProject_Get_Property(googletest source_dir)
include_directories("${source_dir}/include")

# Setup core
set (CORE_DIR ${PROJECT_SOURCE_DIR}/core)
include_directories("${CORE_DIR}")
add_subdirectory (${CORE_DIR})

set (LINK_LIBS ${LINK_LIBS} core)

ExternalProject_Get_Property(googletest binary_dir)

if (WIN32)
    if (CMAKE_BUILD_TYPE MATCHES Debug)
        set (TEST_LIBS ${TEST_LIBS} ${binary_dir}/DebugLibs/gtest.lib)
    endif if (CMAKE_BUILD_TYPE MATCHES Debug)

    if (CMAKE_BUILD_TYPE MATCHES Release)
        set (TEST_LIBS ${TEST_LIBS} ${binary_dir}/ReleaseLibs/gtest.lib)
    endif if (CMAKE_BUILD_TYPE MATCHES Release)
else (WIN32)
    set (TEST_LIBS ${TEST_LIBS} ${binary_dir}/libgtest.a)
endif (WIN32)


###############
# Setup executables
###############

# Setup core_tests
set (CORE_TESTS_DIR ${PROJECT_SOURCE_DIR}/core_tests)
add_subdirectory (${CORE_TESTS_DIR})


# Add the executable
add_executable (pb_ray ${PROJECT_SOURCE_DIR}/pb_ray.cpp)


# Set compiler flags.
#set_target_properties(Tutorial
#  PROPERTIES
#  COMPILE_FLAGS "-g3")


# Add libraries to be linked
target_link_libraries (pb_ray ${LINK_LIBS})
