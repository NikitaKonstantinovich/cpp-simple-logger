cmake_minimum_required(VERSION 3.20)

project(cpp-simple-logger VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(LOGGER_BUILD_TESTS   "Build unit tests"          ON)
option(LOGGER_BUILD_SHARED  "Build shared variant"      ON)

include(cmake/CompilerWarnings.cmake)
enable_default_warnings()
