#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
//production code includes
#include "TemperatureSensor.hpp"


class StubAdcReader : public HAL::IAdc
{
public:
    int fixedValue;
    StubAdcReader(int v) : fixedValue(v) {}

    int readChannel(int) override {
        return fixedValue;  // always return same value
    }
};

TEST_GROUP(TemperatureSensorStub)
{
    void setup()
    {

    }

    void teardown()
    {

    }
};

TEST(TemperatureSensorStub, DetectsFever_UsingStub)
{
    StubAdcReader stub(5000);  // fixed ADC value = 5000
    App::TemperatureSensor sensor(stub);

    CHECK_TRUE(sensor.hasFever(0));
}
