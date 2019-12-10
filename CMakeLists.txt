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

# Unity headers
set(UNITY_EXTRAS_INCLUDE
        ${CMAKE_BINARY_DIR}/unity-src/extras/fixture/src
        ${CMAKE_BINARY_DIR}/unity-src/extras/memory/src
        )

# Add Unity Extras library
add_library(unity_extras STATIC
        ${CMAKE_BINARY_DIR}/unity-src/extras/fixture/src/unity_fixture.c
        ${CMAKE_BINARY_DIR}/unity-src/extras/memory/src/unity_memory.c
        )
target_include_directories(unity_extras PUBLIC ${UNITY_EXTRAS_INCLUDE})
target_link_libraries(unity_extras PUBLIC unity)

# Application code
add_library(LedDriver STATIC src/LedDriver/LedDriver.c)
target_include_directories(LedDriver PUBLIC
        include/LedDriver
        include/util
        )

# Testing code
add_library(RuntimeErrorStub STATIC mocks/RuntimeErrorStub.c)
target_include_directories(RuntimeErrorStub PUBLIC mocks)

add_executable(AllTests
        unity/AllTests.c
        unity/LedDriver/LedDriverTestRunner.c
        unity/LedDriver/LedDriverTest.c
        )
target_include_directories(AllTests PRIVATE mocks)
target_link_libraries(AllTests PRIVATE
        LedDriver
        RuntimeErrorStub
        unity_extras
        unity
        )
