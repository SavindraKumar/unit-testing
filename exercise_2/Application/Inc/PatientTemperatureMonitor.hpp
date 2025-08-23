//!
//! \file   PatientTemperatureMonitor.pp
//!
//! \brief  Class declaration for patient temperature monitoring
//!

//////////////////////////////////////////////////////////////////////
// Copyright (c) 2025  Created by Savindra Kumar
//////////////////////////////////////////////////////////////////////
#ifndef _PATIENT_TEMPERATURE_MONITOR_HPP
#define _PATIENT_TEMPERATURE_MONITOR_HPP

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <stdint.h>


namespace App {

//---------------------------------------------------------------------------
//! \class      PatientTemperatureMonitor
//! \brief      PatientTemperatureMonitor class
//!
class PatientTemperatureMonitor
{
public:

	enum class Unit { Celsius, Fahrenheit };

	static const uint32_t HIGH_FEVER_ALERT_LIMIT_IN_C = 40.0;

    //! \brief      Default constructor
	PatientTemperatureMonitor();

    //! \brief      monitor temperature.
	void monitorTemperature(float temperatureValue, Unit unit = Unit::Celsius);

	//! \brief      check fever
	bool hasCriticalTempeature();


private:

	bool m_hasFever;

     //! \brief      convert temperature from Fahrenheit to Celsius.
     double convertFtoC(float temperatureInF);

};

} //namespace App

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------
