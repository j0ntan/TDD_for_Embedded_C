add_subdirectory(HomeAutomation)

add_executable(test_LightSchedulerTest
    AllTests.cpp
    HomeAutomation/LightControllerSpy.c
    HomeAutomation/LightSchedulerTest.cpp
    )
target_link_libraries(test_LightSchedulerTest LightSchedulerTest)

add_executable(test_LightControllerSpyTest
    AllTests.cpp
    HomeAutomation/LightControllerSpy.c
    HomeAutomation/LightControllerSpyTest.cpp
    )
target_link_libraries(test_LightControllerSpyTest LightControllerSpyTest)

add_executable(AllTestsCppUTests
    AllTests.cpp
    HomeAutomation/LightControllerSpy.c
    HomeAutomation/LightControllerSpyTest.cpp
    HomeAutomation/LightSchedulerTest.cpp
    )
target_link_libraries(AllTestsCppUTests
    LightControllerSpyTest
    LightSchedulerTest
    )
