#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
//production code includes
#include "TemperatureSensor.hpp"

class FakeAdcReader : public HAL::IAdc
{
public:
    int value = 0;
    int readChannel(int) override { return value; }
};

TEST_GROUP(TemperatureSensorFake)
{
    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(TemperatureSensorFake, DetectsFever)
{
    FakeAdcReader fake;

    fake.value = 5000; // raw value, simulates >38C

    App::TemperatureSensor sensor(fake);

    CHECK_TRUE(sensor.hasFever(0));
}
