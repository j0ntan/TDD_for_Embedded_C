add_library(LightControllerSpy INTERFACE)
target_include_directories(LightControllerSpy INTERFACE
    ${CMAKE_SOURCE_DIR}/include/HomeAutomation
    )

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

add_library(FakeTimeService INTERFACE)
target_include_directories(FakeTimeService INTERFACE
    ${CMAKE_SOURCE_DIR}/include/HomeAutomation
    )

add_library(FakeTimeServiceTest INTERFACE)
target_link_libraries(FakeTimeServiceTest INTERFACE FakeTimeService CppUTest)
