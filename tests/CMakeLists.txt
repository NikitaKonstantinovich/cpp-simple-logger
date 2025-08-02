add_executable(logger_tests
    LoggerTests.cpp
)
target_link_libraries(logger_tests PRIVATE logger)

add_test(NAME logger_tests COMMAND logger_tests)
