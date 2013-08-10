cmake_minimum_required (VERSION 2.6)

project (pb_ray)

# Set the initial C and CXX Flags and the toolchain
if (WIN32)
    #set (CMAKE_CXX_FLAGS "-Wall")
else (WIN32)
    set (CMAKE_CXX_FLAGS "-Wall -Wextra")
endif (WIN32)

set (_CMAKE_TOOLCHAIN_PREFIX llvm-)

    
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

# Include Pthreads on Linux
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    FIND_PACKAGE (Threads)
    SET (CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} "-pthread")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

# Enable ExternalProject CMake module
INCLUDE (ExternalProject)

# Set default ExternalProject root directory
SET_DIRECTORY_PROPERTIES(PROPERTIES EP_PREFIX ${THIRD_PARTY_DIR})


#   See http://stackoverflow.com/questions/9689183/cmake-googletest/9695234#9695234
#   for an example

# Create patch file for gtest with MSVC 2012
if(MSVC_VERSION EQUAL 1700)
  file(WRITE gtest.patch "Index: cmake/internal_utils.cmake\n")
  file(APPEND gtest.patch "===================================================================\n")
  file(APPEND gtest.patch "--- cmake/internal_utils.cmake   (revision 660)\n")
  file(APPEND gtest.patch "+++ cmake/internal_utils.cmake\n")
  file(APPEND gtest.patch "@@ -66,6 +66,9 @@\n")
  file(APPEND gtest.patch "       # Resolved overload was found by argument-dependent lookup.\n")
  file(APPEND gtest.patch "       set(cxx_base_flags \"\${cxx_base_flags} -wd4675\")\n")
  file(APPEND gtest.patch "     endif()\n")
  file(APPEND gtest.patch "+    if (MSVC_VERSION EQUAL 1700)\n")
  file(APPEND gtest.patch "+      set(cxx_base_flags \"\${cxx_base_flags} -D_VARIADIC_MAX=10\")\n")
  file(APPEND gtest.patch "+    endif ()\n")
  file(APPEND gtest.patch "     set(cxx_base_flags \"\${cxx_base_flags} -D_UNICODE -DUNICODE -DWIN32 -D_WIN32\")\n")
  file(APPEND gtest.patch "     set(cxx_base_flags \"\${cxx_base_flags} -DSTRICT -DWIN32_LEAN_AND_MEAN\")\n")
  file(APPEND gtest.patch "     set(cxx_exception_flags \"-EHsc -D_HAS_EXCEPTIONS=1\")\n")
else()
  file(WRITE gtest.patch "")
endif()

ExternalProject_Add(
    googletest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
    SVN_REVISION -r 660
    TIMEOUT 10
    PATCH_COMMAND svn patch ${CMAKE_SOURCE_DIR}/gtest.patch ${CMAKE_BINARY_DIR}/third_party/src/googletest
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

# Add compiler flag for MSVC 2012
if(MSVC_VERSION EQUAL 1700)
  add_definitions(-D_VARIADIC_MAX=10)
endif()

ExternalProject_Add(
    googlemock
    SVN_REPOSITORY http://googlemock.googlecode.com/svn/trunk/
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
ExternalProject_Get_Property(googlemock source_dir)
include_directories("${source_dir}/include")

# Setup core
set (CORE_DIR ${PROJECT_SOURCE_DIR}/core)
include_directories("${CORE_DIR}")
add_subdirectory (${CORE_DIR})

set (LINK_LIBS ${CMAKE_THREAD_LIBS_INIT} ${LINK_LIBS} core)

ExternalProject_Get_Property(googletest binary_dir)

if (WIN32)
    set (TEST_LIBS ${TEST_LIBS} ${binary_dir}/DebugLibs/gtest.lib)
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
