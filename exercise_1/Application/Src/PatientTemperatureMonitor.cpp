//!
//! \file   PatientTemperatureMonitor.cpp
//!
//! \brief  Class implementation for patient temperature monitoring and giving high fever alert.
//!

//////////////////////////////////////////////////////////////////////
// Copyright (c) 2025  Created by Savindra Kumar
//////////////////////////////////////////////////////////////////////



//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
//user defined includes
#include "PatientTemperatureMonitor.hpp"



namespace App {


//---------------------------------------------------------------------------
// public methods
//---------------------------------------------------------------------------
PatientTemperatureMonitor::PatientTemperatureMonitor()
{

}

//---------------------------------------------------------------------------
bool PatientTemperatureMonitor::monitorTemperature(float value, Unit unit)
{
	bool hasFever = false;
	float temperature = 0.0;
	
	if (unit == Unit::Celsius)
	{
		temperature = value;
	}
	else
	{
		temperature = convertFtoC(value);
	}


	if (temperature > HIGH_FEVER_ALERT_LIMIT_IN_C)
	{
		hasFever = true;
	}

	return hasFever;
}


//---------------------------------------------------------------------------
// Private methods
//---------------------------------------------------------------------------
double PatientTemperatureMonitor::convertFtoC(float temperatureInF)
{
	float temperatureInC = (temperatureInF - 32.0) * 5.0 / 9.0;
	
	return temperatureInC;
}


} //namespace App
//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------
