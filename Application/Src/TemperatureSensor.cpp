//!
//! \file   TemperatureSensor.cpp
//!
//! \brief  Class implementation for temperature sensor
//!

//////////////////////////////////////////////////////////////////////
// Copyright (c) 2025  Created by Savindra Kumar
//////////////////////////////////////////////////////////////////////



//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
//user defined includes
#include "TemperatureSensor.hpp"



namespace App {


//---------------------------------------------------------------------------
// public methods
//---------------------------------------------------------------------------
TemperatureSensor::TemperatureSensor(HAL::IAdc& adcReader) : m_adcReader(adcReader)
{

}

//---------------------------------------------------------------------------
float TemperatureSensor::readTemperature(int channel)
{
    int var = m_adcReader.readChannel(channel);

    return (var * 3.3f / 4095.0f) * 100.0f; // dummy conversion
}

//---------------------------------------------------------------------------
bool TemperatureSensor::hasFever(int channel)
{
    return readTemperature(channel) > 38.0f;
}
//---------------------------------------------------------------------------
// Private methods
//---------------------------------------------------------------------------



} //namespace App
//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------
