cmake_minimum_required(VERSION 3.14)
project(Lab1 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    main_app
    main.cpp
    main_functions.cpp
)

add_executable(
    run_tests
    function_tests.cpp
    main_functions.cpp
)

target_link_libraries(
    run_tests
    PRIVATE
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_tests)