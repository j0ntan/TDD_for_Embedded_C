cmake_minimum_required(VERSION 3.14)
project(TDD_for_Embedded_C C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# Download and unpack test frameworks at configure time
configure_file(CMakeLists.txt.in test-frameworks-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test-frameworks-download)
if(result)
    message(FATAL_ERROR "CMake step failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test-frameworks-download)
if(result)
    message(FATAL_ERROR "Build step failed: ${result}")
endif()

# Add CppUTest & Unity directly to our build.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/cpputest-src EXCLUDE_FROM_ALL)
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/unity-src EXCLUDE_FROM_ALL)

# Add Unity Extras library
add_library(unity_extras STATIC
        ${CMAKE_BINARY_DIR}/unity-src/extras/fixture/src/unity_fixture.c
        ${CMAKE_BINARY_DIR}/unity-src/extras/memory/src/unity_memory.c
        )
target_include_directories(unity_extras PUBLIC
        ${CMAKE_BINARY_DIR}/unity-src/extras/fixture/src
        ${CMAKE_BINARY_DIR}/unity-src/extras/memory/src
        )
target_link_libraries(unity_extras PUBLIC unity)

# Application code
add_subdirectory(src)

# Mocks
add_subdirectory(mocks)

# Testing code (using Unity framework)
add_subdirectory(unity)

# Testing code (using CppUTest framework)
add_subdirectory(tests)
