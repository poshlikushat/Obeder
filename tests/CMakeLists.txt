add_library(ObederLib
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/Calculator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/Ledger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../src/Parser.cpp
)
target_include_directories(ObederLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include/Obeder)

add_executable(ObederApp ../src/main.cpp)
add_dependencies(ObederApp copy_data)
target_link_libraries(ObederApp PRIVATE ObederLib)

if (BUILD_TESTING)
    add_executable(ObederTest test_calculator.cpp test_ledger.cpp test_parser.cpp)
    target_link_libraries(ObederTest PRIVATE ObederLib GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(ObederTest)
endif()