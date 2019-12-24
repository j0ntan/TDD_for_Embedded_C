add_library(LedDriver STATIC LedDriver/LedDriver.c)
target_include_directories(LedDriver PUBLIC
        ${INCLUDE_DIR}/LedDriver
        ${INCLUDE_DIR}/util
        )

add_library(LightScheduler STATIC HomeAutomation/LightScheduler.c)
target_include_directories(LightScheduler PUBLIC
        ${INCLUDE_DIR}/HomeAutomation
        ${INCLUDE_DIR}/util
        )
