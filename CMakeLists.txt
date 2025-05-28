cmake_minimum_required(VERSION 3.30)
project(Obeder)

set(CMAKE_CXX_STANDARD 20)
option(BUILD_TESTING "Enable tests" ON)

add_subdirectory(external/googletest)
enable_testing()

add_subdirectory(input)

add_subdirectory(tests)