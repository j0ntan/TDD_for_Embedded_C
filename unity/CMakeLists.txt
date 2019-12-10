# LedDriver tests
add_subdirectory(LedDriver)

add_executable(AllTests AllTests.c)
target_link_libraries(AllTests LedDriverTests)
