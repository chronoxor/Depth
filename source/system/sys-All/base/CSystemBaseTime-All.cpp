/*!
 *  \file    CSystemBaseTime-All.cpp Base system class contains common
 *           functionality such as memory routines, math functions, error
 *           handling, standard I/O routines.
 *  \brief   Base system class - All OS - date & time methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - All OS - date & time methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   19.02.2010 23:03:54

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
/*==========================================================================*/
#ifndef __CSYSTEMBASETIME_WINDOWS_CPP__
#define __CSYSTEMBASETIME_WINDOWS_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tsint64 CSystemBase::getProcessTimeStamp()
{ CALL
  return getSystemTimeStamp() - ms_ProcessTimeStamp;
}
/*--------------------------------------------------------------------------*/
NTime::CTime CSystemBase::getProcessTime()
{ CALL
  return NTime::CTime(NTime::CTimeStamp::getProcessTimeStamp());
}
/*--------------------------------------------------------------------------*/
NTime::CTime CSystemBase::getSystemTime(const Tbool a_cIsUTC/* = true */)
{ CALL
  return NTime::CTime(NTime::CTimeStamp::getSystemTimeStamp(a_cIsUTC));
}
/*--------------------------------------------------------------------------*/
NTime::CDate CSystemBase::getProcessDate()
{ CALL
  return NTime::CDate(NTime::CTimeStamp::getProcessTimeStamp());
}
/*--------------------------------------------------------------------------*/
NTime::CDate CSystemBase::getSystemDate(const Tbool a_cIsUTC/* = true */)
{ CALL
  return NTime::CDate(NTime::CTimeStamp::getSystemTimeStamp(a_cIsUTC));
}
/*--------------------------------------------------------------------------*/
NTime::CDateTime CSystemBase::getProcessDateTime()
{ CALL
  return NTime::CDateTime(NTime::CTimeStamp::getProcessTimeStamp());
}
/*--------------------------------------------------------------------------*/
NTime::CDateTime CSystemBase::getSystemDateTime(const Tbool a_cIsUTC/* = true */)
{ CALL
  return NTime::CDateTime(NTime::CTimeStamp::getSystemTimeStamp(a_cIsUTC));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
