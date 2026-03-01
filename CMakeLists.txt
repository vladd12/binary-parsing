# Project definition and settings
cmake_minimum_required(VERSION 3.15)
project(binary-parsing VERSION 0.0.0)

# Language settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# TODO: Qt usage will be done later

# Qt specific options
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

# Finding Qt libraries
#find_package(QT NAMES Qt6 Qt5)

# Old Qt does not provide QT_VERSION_MAJOR
#if(NOT QT_VERSION_MAJOR)
#  string(SUBSTRING ${QT_VERSION} 0 1 QT_VERSION_MAJOR)
#endif()
#message(STATUS "Qt major version: ${QT_VERSION_MAJOR}")

# Find Qt's components
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets REQUIRED)

# Library's options
option(BINPARSING_STATIC_BUILD "Build binary-parsing as static library" ON)
option(BINPARSING_BUILD_TESTS  "Build tests for binary-parsing library" ON) # TODO

set(BINPARSING_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(BINPARSING_SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(BINPARSING_SOURCES
  "${BINPARSING_INCLUDE_DIR}/binary-parsing/export.hpp"
  "${BINPARSING_INCLUDE_DIR}/binary-parsing/binary-parsing.hpp"
  "${BINPARSING_SOURCES_DIR}/binary-parsing.cpp"
)

# Library target
if(BINPARSING_STATIC_BUILD)
  # Compilation static library
  message(STATUS "binary-parsing is static library")
  add_library(binary_parsing STATIC)
  target_compile_definitions(binary_parsing PUBLIC -DSTATIC_BUILD)
else()
  # Compilation dynamic library
  message(STATUS "binary-parsing is shared (dynamic) library")
  add_library(binary_parsing SHARED)
  target_compile_definitions(binary_parsing PRIVATE -DLIB_EXPORT)
  target_compile_definitions(binary_parsing INTERFACE -DLIB_IMPORT)
endif()
target_sources(binary_parsing PRIVATE ${BINPARSING_SOURCES})
target_include_directories(binary_parsing PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
add_library(binary::parsing ALIAS binary_parsing)
