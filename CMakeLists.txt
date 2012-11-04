cmake_minimum_required (VERSION 2.6)

project (pb_ray)

# Setup the version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)


# Setup the project directories.
set (PROJECT_SOURCE_DIR src)
set (PROJECT_INCLUDE_DIR include)
set (PROJECT_BUILD_INCLUDE_DIR build/include)
set (PROJECT_BIN_DIR bin)
set (PROJECT_LIB_DIR lib)


# Setup output directories
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR})


# Add the binary directory to the search path.
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_BUILD_INCLUDE_DIR}")


###############
# Setup libraries to be linked.
###############

# Setup gtest
set (GTEST_DIR ${PROJECT_SOURCE_DIR}/gtest)
include_directories("${GTEST_DIR}/include")
add_subdirectory (${GTEST_DIR})

# Setup core
set (CORE_DIR ${PROJECT_SOURCE_DIR}/core)
include_directories("${CORE_DIR}")
add_subdirectory (${CORE_DIR})

set (LINK_LIBS ${LINK_LIBS} core)
set (TEST_LIBS ${TEST_LIBS} gtest)


# Setup core_tests
set (CORE_TESTS_DIR ${PROJECT_SOURCE_DIR}/core_tests)
include_directories("${CORE_TESTS_DIR}")
add_subdirectory (${CORE_TESTS_DIR})


# Add the executable
add_executable (pb_ray ${PROJECT_SOURCE_DIR}/pb_ray.cpp)


# Set compiler flags.
#set_target_properties(Tutorial
#  PROPERTIES
#  COMPILE_FLAGS "-g3")


# Add libraries to be linked
target_link_libraries (pb_ray ${LINK_LIBS})
