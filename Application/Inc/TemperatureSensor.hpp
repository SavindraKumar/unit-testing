//!
//! \file   TemperatureSensor.pp
//!
//! \brief  Class declaration for temperature
//!

//////////////////////////////////////////////////////////////////////
// Copyright (c) 2025  Created by Savindra Kumar
//////////////////////////////////////////////////////////////////////
#ifndef _TEMPERATURE_SENSOR_HPP
#define _TEMPERATURE_SENSOR_HPP

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <stdint.h>
#include "IAdc.hpp"


namespace App {


//---------------------------------------------------------------------------
//! \class      TemperatureSensor
//! \brief      TemperatureSensor class
//!
class TemperatureSensor
{
public:
    TemperatureSensor(HAL::IAdc& adcReader);
    float readTemperature(int channel);
    bool hasFever(int channel);

private:
    HAL::IAdc& m_adcReader;
};


} //namespace App

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------
