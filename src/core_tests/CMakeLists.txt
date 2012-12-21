INCLUDE_DIRECTORIES("${CORE_TESTS_DIR}")

ADD_EXECUTABLE (core_tests core_tests.cpp Vector_Tests.cpp)

ADD_DEPENDENCIES (core_tests core)
ADD_DEPENDENCIES (core_tests googletest)

# Specify MainTest's link libraries
TARGET_LINK_LIBRARIES (core_tests ${LINK_LIBS} ${TEST_LIBS} )

