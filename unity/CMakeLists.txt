# LedDriver tests
add_subdirectory(LedDriver)

add_executable(AllTestsUnity AllTests.c)
target_link_libraries(AllTestsUnity LedDriverTests)
