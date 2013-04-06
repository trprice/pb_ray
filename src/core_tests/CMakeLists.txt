INCLUDE_DIRECTORIES("${CORE_TESTS_DIR}")

# Find the *.cpp files and add them to the executable.
FILE (GLOB CPPSources *.cpp)
ADD_EXECUTABLE (core_tests EXCLUDE_FROM_ALL ${CPPSources})

ADD_DEPENDENCIES (core_tests core)
ADD_DEPENDENCIES (core_tests googletest)

# Specify MainTest's link libraries
TARGET_LINK_LIBRARIES (core_tests ${LINK_LIBS} ${TEST_LIBS} )

