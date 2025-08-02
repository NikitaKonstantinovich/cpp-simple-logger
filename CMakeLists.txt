cmake_minimum_required(VERSION 3.20)

project(cpp-simple-logger VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(LOGGER_BUILD_TESTS   "Build unit tests"          ON)
option(LOGGER_BUILD_SHARED  "Build shared variant"      ON)

include(cmake/CompilerWarnings.cmake)
enable_default_warnings()

add_library(logger STATIC
    src/LogMessage.cpp
)

target_include_directories(logger
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(logger PROPERTIES
    OUTPUT_NAME logger
)

if (LOGGER_BUILD_TESTS)
    add_subdirectory(tests)
endif()