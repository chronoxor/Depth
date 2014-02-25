/*!
 *  \file    CSystemBaseTime-WindowsMobile.cpp Base system class contains
 *           common functionality such as memory routines, math functions,
 *           error handling, standard I/O routines.
 *  \brief   Base system class - Windows Mobile OS - date & time methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Windows Mobile OS - date & time methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   19.02.2010 23:27:33

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
#include "../WindowsMobile.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASETIME_WINDOWS_CPP__
#define __CSYSTEMBASETIME_WINDOWS_CPP__
/*==========================================================================*/
#if (defined(__WINDOWS__) && defined(__WINDOWS_MOBILE__))
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
  SYSTEMTIME system_time;
  FILETIME system_file_time;

  // Get system time.
  GetSystemTime(&system_time);

  // Convert system time to system file time.
  if (SystemTimeToFileTime(&system_time, &system_file_time) == FALSE)
  {
    WARNING(STR("Cannot convert system time to system file time."));
    return 0;
  }

  // Calculate local time stamp.
  if (!a_cIsUTC)
  {
    FILETIME local_file_time = system_file_time;
    if (FileTimeToLocalFileTime(&local_file_time, &system_file_time) == FALSE)
    {
      WARNING(STR("Cannot convert UTC file time to local file time."));
      return 0;
    }
  }

  // Calculate and return system time stamp.
  // 584754 days were passed from Epoch to 00:00:00 January 1, 1601 (UTC).
  // 584754 * 24 * 60 * 60 * 1000 = 50522745600000 milliseconds.
  return (Tsint64)(CONSTS64(50522745600000) + (((Tuint64)system_file_time.dwLowDateTime + (((Tuint64)system_file_time.dwHighDateTime) << 32)) / 10000));
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::setSystemTime(const NTime::CTime& a_crTime, const Tbool a_cIsUTC/* = true */)
{ CALL
  SYSTEMTIME system_time;

  // Get system time in UTC or local time form.
  if (a_cIsUTC)
    GetSystemTime(&system_time);
  else
    GetLocalTime(&system_time);

  // Update time fields.
  system_time.wHour = a_crTime.getClearHours();
  system_time.wMinute = a_crTime.getClearMinutes();
  system_time.wSecond = a_crTime.getClearSeconds();
  system_time.wMilliseconds = a_crTime.getClearMilliseconds();

  // Set system time in UTC or local time form.
  BOOL result = (a_cIsUTC) ? SetSystemTime(&system_time) : SetLocalTime(&system_time);
  if (result == FALSE)
  {
    WARNING(STR("Cannot set system time in %x form (%u hours, %u minutes, %u seconds, %u milliseconds).") COMMA ((a_cIsUTC ? STR("UTC") : STR("local time"))) COMMA a_crTime.getClearHours() COMMA a_crTime.getClearMinutes() COMMA a_crTime.getClearSeconds() COMMA a_crTime.getClearMilliseconds());
    return false;
  }

  // Reset start process time stamp.
  CSystemBase::ms_ProcessTimeStamp = CSystemBase::getSystemTimeStamp();

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::setSystemDate(const NTime::CDate& a_crDate, const Tbool a_cIsUTC/* = true */)
{ CALL
  SYSTEMTIME system_time;

  // Get system time in UTC or local time form.
  if (a_cIsUTC)
    GetSystemTime(&system_time);
  else
    GetLocalTime(&system_time);

  // Update time fields.
  system_time.wYear = a_crDate.getClearYears();
  system_time.wMonth = a_crDate.getClearMonths() + 1;
  system_time.wDay = a_crDate.getClearDays() + 1;

  // Set system time in UTC or local time form.
  BOOL result = (a_cIsUTC) ? SetSystemTime(&system_time) : SetLocalTime(&system_time);
  if (result == FALSE)
  {
    WARNING(STR("Cannot set system time in %x form (%u years, %u months, %u days).") COMMA ((a_cIsUTC ? STR("UTC") : STR("local time"))) COMMA a_crDate.getClearYears() COMMA a_crDate.getClearMonths() COMMA a_crDate.getClearDays());
    return false;
  }

  // Reset start process time stamp.
  CSystemBase::ms_ProcessTimeStamp = CSystemBase::getSystemTimeStamp();

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::setSystemDateTime(const NTime::CDateTime& a_crDateTime, const Tbool a_cIsUTC/* = true */)
{ CALL
  SYSTEMTIME system_time;

  // Get system time in UTC or local time form.
  if (a_cIsUTC)
    GetSystemTime(&system_time);
  else
    GetLocalTime(&system_time);

  // Update time fields.
  system_time.wYear = a_crDateTime.getDate().getClearYears();
  system_time.wMonth = a_crDateTime.getDate().getClearMonths() + 1;
  system_time.wDay = a_crDateTime.getDate().getClearDays() + 1;
  system_time.wHour = a_crDateTime.getTime().getClearHours();
  system_time.wMinute = a_crDateTime.getTime().getClearMinutes();
  system_time.wSecond = a_crDateTime.getTime().getClearSeconds();
  system_time.wMilliseconds = a_crDateTime.getTime().getClearMilliseconds();

  // Set system time in UTC or local time form.
  //
  // The system uses UTC internally. Therefore, when  you  call  SetLocalTime,
  // the system  uses  the  current  time  zone  information  to  perform  the
  // conversion, including the daylight saving time  setting.  Note  that  the
  // system uses the daylight saving time setting of the current time, not the
  // new time you are setting. Therefore, to ensure the correct  result,  call
  // SetLocalTime a second time, now that  the  first  call  has  updated  the
  // daylight saving time setting.
  //
  BOOL result = (a_cIsUTC) ? SetSystemTime(&system_time) : (SetLocalTime(&system_time) && SetLocalTime(&system_time));
  if (result == FALSE)
  {
    WARNING(STR("Cannot set system time in %x form (%u years, %u months, %u days, %u hours, %u minutes, %u seconds, %u milliseconds).") COMMA ((a_cIsUTC ? STR("UTC") : STR("local time"))) COMMA a_crDateTime.getDate().getClearYears() COMMA a_crDateTime.getDate().getClearMonths() COMMA a_crDateTime.getDate().getClearDays() COMMA a_crDateTime.getTime().getClearHours() COMMA a_crDateTime.getTime().getClearMinutes() COMMA a_crDateTime.getTime().getClearSeconds() COMMA a_crDateTime.getTime().getClearMilliseconds());
    return false;
  }

  // Reset start process time stamp.
  CSystemBase::ms_ProcessTimeStamp = CSystemBase::getSystemTimeStamp();

  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
