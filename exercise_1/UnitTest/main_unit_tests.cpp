
#include <iostream>
#include <cassert>
#include "PatientTemperatureMonitor.hpp"

int main()
{
	App::PatientTemperatureMonitor patient;

	assert(false == patient.monitorTemperature(36.2));

    assert(false == patient.monitorTemperature(40.0));

    assert(true == patient.monitorTemperature(40.1));

    std::cout << "All tests passed successfully!\n";
    return 0;
}


