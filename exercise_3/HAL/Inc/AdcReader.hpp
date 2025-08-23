//!
//! \file   AdcReader.hpp
//!
//! \brief  adc reader hardware abstraction layer
//!

//////////////////////////////////////////////////////////////////////
// Copyright (c) 2025  Created by Savindra Kumar
//////////////////////////////////////////////////////////////////////
#ifndef _ADC_READER_HPP
#define _ADC_READER_HPP

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include "IAdc.hpp"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_adc.h"

namespace HAL {

//---------------------------------------------------------------------------
//! \class      AdcReader
//! \brief      AdcReader class
//!
class AdcReader : public IAdc
{
public:
    //! \brief       constructor
    AdcReader(ADC_HandleTypeDef* hadc);

    //! \brief      read adc channel
    int readChannel(int channel) override;

private:
    //! \brief      adc handle pointer
    ADC_HandleTypeDef* m_hadc;

};

} //namespace HAL

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------
