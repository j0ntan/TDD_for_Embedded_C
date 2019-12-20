add_subdirectory(HomeAutomation)

add_executable(test_LightSchedulerTest
    AllTests.cpp
    HomeAutomation/LightControllerSpy.c
    HomeAutomation/LightSchedulerTest.cpp
    HomeAutomation/FakeTimeService.c
    )
target_link_libraries(test_LightSchedulerTest LightSchedulerTest LightScheduler)

add_executable(test_LightControllerSpyTest
    AllTests.cpp
    HomeAutomation/LightControllerSpy.c
    HomeAutomation/LightControllerSpyTest.cpp
    )
target_link_libraries(test_LightControllerSpyTest LightControllerSpyTest)

add_executable(test_FakeTimeServiceTest
    AllTests.cpp
    HomeAutomation/FakeTimeService.c
    HomeAutomation/FakeTimeServiceTest.cpp
    )
target_link_libraries(test_FakeTimeServiceTest FakeTimeServiceTest)

add_executable(AllTestsCppUTests
    AllTests.cpp
    HomeAutomation/LightControllerSpy.c
    HomeAutomation/LightControllerSpyTest.cpp
    HomeAutomation/LightSchedulerTest.cpp
    HomeAutomation/FakeTimeService.c
    HomeAutomation/FakeTimeServiceTest.cpp
    )
target_link_libraries(AllTestsCppUTests
    LightControllerSpyTest
    LightSchedulerTest
    FakeTimeServiceTest
    )
