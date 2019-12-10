add_library(LedDriver STATIC LedDriver/LedDriver.c)
target_include_directories(LedDriver PUBLIC
        ${CMAKE_SOURCE_DIR}/include/LedDriver
        ${CMAKE_SOURCE_DIR}/include/util
        )
