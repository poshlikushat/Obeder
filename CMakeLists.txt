cmake_minimum_required(VERSION 3.30)
project(Obeder)

set(CMAKE_CXX_STANDARD 20)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(ObederLib STATIC
        src/Parser.cpp
        src/Ledger.cpp
        src/Calculator.cpp
)
# Указываем, где искать заголовки для ObederLib
target_include_directories(ObederLib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Исполняемый файл
add_executable(Obeder src/main.cpp)
# Линкуем с библиотекой
target_link_libraries(Obeder PRIVATE ObederLib)
