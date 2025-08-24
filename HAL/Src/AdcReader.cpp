
//!
//! \file   AdcReader.cpp
//!
//! \brief  Class implementation for AdcReader class
//!

//////////////////////////////////////////////////////////////////////
// Copyright (c) 2025  Created by Savindra Kumar
//////////////////////////////////////////////////////////////////////


//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
//user defined includes
#include "AdcReader.hpp"


namespace HAL {


//---------------------------------------------------------------------------
// public methods
//---------------------------------------------------------------------------
AdcReader::AdcReader(ADC_HandleTypeDef* hadc) : m_hadc(hadc)
{

}


//---------------------------------------------------------------------------
int AdcReader::readChannel(int channel)
{
    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel = channel;
    sConfig.Rank = 1;
    sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
    HAL_ADC_ConfigChannel(m_hadc, &sConfig);

    HAL_ADC_Start(m_hadc);
    HAL_ADC_PollForConversion(m_hadc, HAL_MAX_DELAY);
    int value = HAL_ADC_GetValue(m_hadc);
    HAL_ADC_Stop(m_hadc);

    return value;
}

//---------------------------------------------------------------------------
// Private methods
//---------------------------------------------------------------------------


} //namespace HAL
//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------
