set(BINPARSING_CURL_TESTS_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/cli.cpp
)

add_executable(binary_parsing_curl_tests ${BINPARSING_CURL_TESTS_SOURCES})
target_link_libraries(binary_parsing_curl_tests PUBLIC
  gtest
  binary::parsing
)
