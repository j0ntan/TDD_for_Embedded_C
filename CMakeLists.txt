cmake_minimum_required(VERSION 3.14)
project(TDD_for_Embedded_C C)

set(CMAKE_C_STANDARD 11)

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

# Add cpputest & Unity directly to our build.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/cpputest-src
        ${CMAKE_CURRENT_BINARY_DIR}/cpputest-build
        EXCLUDE_FROM_ALL)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/unity-src
        ${CMAKE_CURRENT_BINARY_DIR}/unity-build
        EXCLUDE_FROM_ALL)
