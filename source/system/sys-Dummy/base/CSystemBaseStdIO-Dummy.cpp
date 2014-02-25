/*!
 *  \file    CSystemBaseStdIO-Dummy.cpp Base system class contains common
 *           functionality such as memory routines, math functions, error
 *           handling, standard I/O routines.
 *  \brief   Base system class - Dummy OS - standard I/O streams methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Dummy OS - standard I/O streams methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   22.08.2008 21:49:23

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the  hope  that  it  will  be  useful,  but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General  Public  License
    for more details.

    You should have received a copy of the GNU General  Public  License  along
    with this program; if not, write to the Free Software Foundation, Inc., 59
    Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/system/CSystemBase.hpp>
/*--------------------------------------------------------------------------*/
#include "../Dummy.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASESTDIO_DUMMY_CPP__
#define __CSYSTEMBASESTDIO_DUMMY_CPP__
/*==========================================================================*/
#if defined(__DUMMY__)
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tuint CSystemBase::stdErrorWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_cpBuffer);
  IGNORE_UNUSED(a_cSize);

  return 0;
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdErrorWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_cpBuffer);
  IGNORE_UNUSED(a_cSize);

  return 0;
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdErrorWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_cpBuffer);
  IGNORE_UNUSED(a_cSize);

  return 0;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::stdErrorFlush()
{ CALL
  return false;
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdInputReadBinary(Tptr a_pBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_cSize);

  return 0;
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdInputReadText(Tsstr a_pBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_cSize);

  return 0;
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdInputReadText(Twstr a_pBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_pBuffer);
  IGNORE_UNUSED(a_cSize);

  return 0;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::stdInputFlush()
{ CALL
  return false;
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdOutputWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_cpBuffer);
  IGNORE_UNUSED(a_cSize);

  return 0;
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdOutputWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_cpBuffer);
  IGNORE_UNUSED(a_cSize);

  return 0;
}
/*--------------------------------------------------------------------------*/
Tuint CSystemBase::stdOutputWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize)
{ CALL
  IGNORE_UNUSED(a_cpBuffer);
  IGNORE_UNUSED(a_cSize);

  return 0;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::stdOutputFlush()
{ CALL
  return false;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
