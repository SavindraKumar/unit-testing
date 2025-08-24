//Cpputest includes
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
//production code includes
#include "PatientTemperatureMonitor.hpp"



TEST_GROUP(PatientTemperatureMonitorInC)
{

    void setup()
    {

    }

    void teardown()
    {

    }

};

/**
*Test Name: PatientTemperatureBelowCritical
*Member function Under test: monitorTemperature
*Description: This test check if patient is below critical limit
*Precondition:
*/
TEST(PatientTemperatureMonitorInC, PatientTemperatureBelowCritical)
{
	App::PatientTemperatureMonitor patient;

	float temperatureInC = 36.5;

	patient.monitorTemperature(temperatureInC);

    CHECK_FALSE(patient.hasCriticalTempeature());
}

/**
*Test Name: PatientTemperatureAboveCritical
*Member function Under test: monitorTemperature
*Description: This test check if patient is above critical limit
*Precondition:
*/
TEST(PatientTemperatureMonitorInC, PatientTemperatureAboveCritical)
{
	App::PatientTemperatureMonitor patient;

	float temperatureInC = 40.1;

	patient.monitorTemperature(temperatureInC);

    CHECK_TRUE(patient.hasCriticalTempeature());
}


/**
*Test Name: PatientTemperatureOnBoundary
*Member function Under test: monitorTemperature
*Description: This test check if patient temperature is on critical limit boundary
*Precondition:
*/
TEST(PatientTemperatureMonitorInC, PatientTemperatureOnBoundary)
{
	App::PatientTemperatureMonitor patient;

	float temperatureInC = 40.0;

	patient.monitorTemperature(temperatureInC);

    CHECK_FALSE(patient.hasCriticalTempeature());
}


/**
*Test Name: PatientTemperatureNoMonitoring
*Member function Under test: hasCriticalTempeature
*Description: This test check if temperature monitoring not called and checking critical temp.
*Precondition:
*/
TEST(PatientTemperatureMonitorInC, PatientTemperatureNoMonitoring)
{
	App::PatientTemperatureMonitor patient;

    CHECK_FALSE(patient.hasCriticalTempeature());
}



TEST_GROUP(PatientTemperatureMonitorInF)
{

    void setup()
    {

    }

    void teardown()
    {

    }

};

/**
*Test Name: PatientTemperatureBelowCritical
*Member function Under test: monitorTemperature
*Description: This test check if patient is below critical limit
*Precondition:
*/
TEST(PatientTemperatureMonitorInF, PatientTemperatureBelowCritical)
{
	App::PatientTemperatureMonitor patient;

	float temperatureInF = 98.5;

	patient.monitorTemperature(temperatureInF, App::PatientTemperatureMonitor::Unit::Fahrenheit);

    CHECK_FALSE(patient.hasCriticalTempeature());
}

/**
*Test Name: PatientTemperatureAboveCritical
*Member function Under test: monitorTemperature
*Description: This test check if patient is above critical limit
*Precondition:
*/
TEST(PatientTemperatureMonitorInF, PatientTemperatureAboveCritical)
{
	App::PatientTemperatureMonitor patient;

	float temperatureInF = 104.8;

	patient.monitorTemperature(temperatureInF, App::PatientTemperatureMonitor::Unit::Fahrenheit);

    CHECK_TRUE(patient.hasCriticalTempeature());
}


/**
*Test Name: PatientTemperatureOnBoundary
*Member function Under test: monitorTemperature
*Description: This test check if patient temperature is on critical limit boundary
*Precondition:
*/
TEST(PatientTemperatureMonitorInF, PatientTemperatureOnBoundary)
{
	App::PatientTemperatureMonitor patient;

	float temperatureInF = 104.0;

	patient.monitorTemperature(temperatureInF, App::PatientTemperatureMonitor::Unit::Fahrenheit);

    CHECK_FALSE(patient.hasCriticalTempeature());
}


/**
*Test Name: PatientTemperatureNoMonitoring
*Member function Under test: hasCriticalTempeature
*Description: This test check if temperature monitoring not called and checking critical temp.
*Precondition:
*/
TEST(PatientTemperatureMonitorInF, PatientTemperatureNoMonitoring)
{
	App::PatientTemperatureMonitor patient;

    CHECK_FALSE(patient.hasCriticalTempeature());
}

