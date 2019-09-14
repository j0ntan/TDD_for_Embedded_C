#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver)
{
    RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
    RUN_TEST_CASE(LedDriver, TurnOnLedOne);
    RUN_TEST_CASE(LedDriver, TurnOffLedOne);
    RUN_TEST_CASE(LedDriver, TurnONMultipleLeds);
    RUN_TEST_CASE(LedDriver, AllOn);
    RUN_TEST_CASE(LedDriver, TurnOffAnyLed);
    RUN_TEST_CASE(LedDriver, LedMemoryIsNotReadable);
    RUN_TEST_CASE(LedDriver, UpperAndLowerBounds);
    RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOnDoesNoHarm);
    RUN_TEST_CASE(LedDriver, OutOfBoundsTurnOffDoesNoHarm);
}
