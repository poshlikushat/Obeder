cmake_minimum_required(VERSION 3.30)
project(Obeder)

set(CMAKE_CXX_STANDARD 20)

add_library( new_target
        include/Obeder/Calculator.h
        src/Calculator.cpp
        include/Obeder/Parser.h
        src/Parser.cpp
        src/Ledger.cpp
        include/Obeder/Ledger.h
)
add_executable(Obeder src/main.cpp src/Parser.cpp)
