#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
//production code includes
#include "TemperatureSensor.hpp"


class MockAdcReader : public HAL::IAdc
{
public:
    int readChannel(int channel) override
    {
        return mock()
            .actualCall("readChannel")
            .withParameter("channel", channel)
            .returnIntValueOrDefault(0);
    }
};

TEST_GROUP(TemperatureSensorMock)
{
    void setup()
    {

    }

    void teardown()
    {
    	mock().clear();
    }
};

TEST(TemperatureSensorMock, DetectsFever_UsingMock)
{
    MockAdcReader mockAdc;
    App::TemperatureSensor sensor(mockAdc);

    // Set expectation: sensor should call readChannel(0), return 5000
    mock().expectOneCall("readChannel")
          .withParameter("channel", 0)
          .andReturnValue(5000);

    CHECK_TRUE(sensor.hasFever(0));

    // Verify expectations met
    mock().checkExpectations();
}

