//!
//! \file   Buffer.hpp
//!
//! \brief  Class declaration for patient temperature monitoring
//!

//////////////////////////////////////////////////////////////////////
// Copyright (c) 2025  Created by Savindra Kumar
//////////////////////////////////////////////////////////////////////
#ifndef _BUFFER_H
#define _BUFFER_H

//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <cstddef>


namespace App {


//---------------------------------------------------------------------------
//! \class      Buffer
//! \brief      Buffer class
//!
class Buffer
{
public:
	Buffer();
    ~Buffer();

    void allocate(size_t size);
    void release();
    char* getBuffer();

private:
    char* buffer;
    size_t size;
};


} //namespace App

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
// End of File
//---------------------------------------------------------------------------
