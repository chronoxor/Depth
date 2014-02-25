/*!
 *  \file    CSystemBaseTime-Dummy.cpp Base system class contains common
 *           functionality such as memory routines, math functions, error
 *           handling, standard I/O routines.
 *  \brief   Base system class - Dummy OS - date & time methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Dummy OS - date & time methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   19.02.2010 23:02:11

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
#ifndef __CSYSTEMBASETIME_DUMMY_CPP__
#define __CSYSTEMBASETIME_DUMMY_CPP__
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
Tsint64 CSystemBase::getSystemTimeStamp(const Tbool a_cIsUTC/* = true */)
{ CALL
  IGNORE_UNUSED(a_cIsUTC);

  return 0;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::setSystemTime(const NTime::CTime& a_crTime, const Tbool a_cIsUTC/* = true */)
{ CALL
  IGNORE_UNUSED(a_crTime);
  IGNORE_UNUSED(a_cIsUTC);

  return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::setSystemDate(const NTime::CDate& a_crDate, const Tbool a_cIsUTC/* = true */)
{ CALL
  IGNORE_UNUSED(a_crDate);
  IGNORE_UNUSED(a_cIsUTC);

  return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::setSystemDateTime(const NTime::CDateTime& a_crDateTime, const Tbool a_cIsUTC/* = true */)
{ CALL
  IGNORE_UNUSED(a_crDateTime);
  IGNORE_UNUSED(a_cIsUTC);

  return false;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
