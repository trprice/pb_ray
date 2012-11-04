include_directories("${GTEST_DIR}/include")

add_executable (core_tests core_tests.cpp Vector_Tests.cpp)

target_link_libraries (core_tests ${TEST_LIBS})
