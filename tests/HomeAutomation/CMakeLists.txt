# Spies & Fakes
add_library(LightControllerSpy INTERFACE)
target_include_directories(LightControllerSpy INTERFACE
    ${INCLUDE_DIR}/HomeAutomation
    )

add_library(FakeTimeService INTERFACE)
target_include_directories(FakeTimeService INTERFACE
    ${INCLUDE_DIR}/HomeAutomation
    )

# Tests
add_library(LightControllerSpyTest INTERFACE)
target_link_libraries(LightControllerSpyTest INTERFACE
    LightControllerSpy
    CppUTest
    )

add_library(LightSchedulerTest INTERFACE)
target_link_libraries(LightSchedulerTest INTERFACE
    LightControllerSpy
    CppUTest
    )

add_library(FakeTimeServiceTest INTERFACE)
target_link_libraries(FakeTimeServiceTest INTERFACE FakeTimeService CppUTest)
