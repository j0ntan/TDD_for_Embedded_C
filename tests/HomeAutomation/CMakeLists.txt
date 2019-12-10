add_library(LightControllerSpy INTERFACE)

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
