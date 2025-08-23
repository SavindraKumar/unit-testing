#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
//production code includes
#include "TemperatureSensor.hpp"

class MockAdcReader : public HAL::IAdc
{
public:
    int value = 0;
    int readChannel(int) override { return value; }
};

TEST_GROUP(TemperatureSensor)
{
};

TEST(TemperatureSensor, DetectsFever)
{
    MockAdcReader mock;
    mock.value = 5000; // raw value, simulates >38C
    App::TemperatureSensor sensor(mock);
    CHECK_TRUE(sensor.hasFever(0));
}
