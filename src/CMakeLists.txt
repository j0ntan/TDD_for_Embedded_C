add_library(LedDriver STATIC LedDriver/LedDriver.c)
target_include_directories(LedDriver PUBLIC
        ${INCLUDE_DIR}/LedDriver
        ${INCLUDE_DIR}/util
        )
