set(BINPARSING_TESTS_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/simple_test.cpp
)

add_executable(binary_parsing_tests ${BINPARSING_TESTS_SOURCES})
target_link_libraries(binary_parsing_tests PUBLIC
  GTest::GTest
  binary::parsing
)

add_test(
  NAME binary_parsing_tests
  COMMAND binary_parsing_tests
)
