cmake_minimum_required(VERSION 3.30)
project(Obeder)

set(CMAKE_CXX_STANDARD 20)

add_library( new_target
        src/Calculator.h
        src/Calculator.cpp
        src/Parser.h
        src/Models.h
        src/Parser.cpp
        src/Ledger.cpp
        src/Ledger.h
        src/Models.cpp
    )
add_executable(Obeder src/main.cpp)
