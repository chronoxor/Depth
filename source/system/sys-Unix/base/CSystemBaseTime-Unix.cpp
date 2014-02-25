/*!
 *  \file    CSystemBaseTime-Unix.cpp Base system class contains common
 *           functionality such as memory routines, math functions, error
 *           handling, standard I/O routines.
 *  \brief   Base system class - Unix OS - date & time methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Unix OS - date & time methods (source).

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
/*--------------------------------------------------------------------------*/
#include "../Unix.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASETIME_WINDOWS_CPP__
#define __CSYSTEMBASETIME_WINDOWS_CPP__
/*==========================================================================*/
#if defined(__UNIX__)
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
  struct timeval tv;

  // Get current date & time since Epoch.
  if (gettimeofday(&tv, NULL) != 0)
  {
    WARNING(STR("Cannot get current date & time since Epoch."));
    return 0;
  }

  // Calculate local time stamp.
  if (!a_cIsUTC)
  {
    struct tm local_time;
    if (localtime_r(&tv.tv_sec, &local_time) != &local_time)
    {
      WARNING(STR("Cannot convert file time to local file time."));
      return 0;
    }

    // Calculate seconds of the local time.
    Tsint hours = local_time.tm_hour - ((tv.tv_sec / (60 * 60)) % 24);
    Tsint minutes = local_time.tm_min - ((tv.tv_sec / 60) % 60);
    Tsint seconds = local_time.tm_sec - (tv.tv_sec % 60);
    tv.tv_sec += seconds + ((minutes + hours * 60) * 60);
  }

  // Calculate and return system time stamp.
  // 719528 days were passed from Epoch to 00:00:00 January 1, 1970 (UTC).
  // 719528 * 24 * 60 * 60 * 1000 = 62167219200000 milliseconds.
  return (Tsint64)(CONSTS64(62167219200000) + ((Tsint64)tv.tv_sec * 1000) + ((Tsint64)tv.tv_usec / 1000));
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::setSystemTime(const NTime::CTime& a_crTime, const Tbool a_cIsUTC/* = true */)
{ CALL
  NTime::CTime adjusted(a_crTime);
  struct timeval tv;
  struct tm tm;

  // Get current date & time since Epoch.
  if (gettimeofday(&tv, NULL) != 0)
  {
    WARNING(STR("Cannot get current date & time since Epoch."));
    return false;
  }

  // Calculate local time.
  if (localtime_r(&tv.tv_sec, &tm) != &tm)
  {
    WARNING(STR("Cannot convert file time to local file time."));
    return false;
  }

  // For UTC mode adjust the local time.
  if (a_cIsUTC)
  {
    // Calculate seconds of the local time.
    Tsint hours = tm.tm_hour - ((tv.tv_sec / (60 * 60)) % 24);
    Tsint minutes = tm.tm_min - ((tv.tv_sec / 60) % 60);
    Tsint seconds = tm.tm_sec - (tv.tv_sec % 60);

    // Calculate new time value to set.
    adjusted = a_crTime.getTimeStamp() - NTime::CTimeStamp(0, seconds, minutes, hours);
  }

  // Use adjusted time.
  tm.tm_hour = adjusted.getClearHours();
  tm.tm_min = adjusted.getClearMinutes();
  tm.tm_sec = adjusted.getClearSeconds();

  // Make new system time.
  if ((tv.tv_sec = mktime(&tm)) == (time_t)-1)
  {
    WARNING(STR("Cannot convert system time in %x form (%u hours, %u minutes, %u seconds, %u milliseconds).") COMMA ((a_cIsUTC ? STR("UTC") : STR("local time"))) COMMA a_crTime.getClearHours() COMMA a_crTime.getClearMinutes() COMMA a_crTime.getClearSeconds() COMMA a_crTime.getClearMilliseconds());
    return false;
  }
  tv.tv_usec = a_crTime.getClearMilliseconds() * 1000;

  // Set new system time.
  if (settimeofday(&tv, NULL) != 0)
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
  struct timeval tv;
  struct tm tm;

  // Get current date & time since Epoch.
  if (gettimeofday(&tv, NULL) != 0)
  {
    WARNING(STR("Cannot get current date & time since Epoch."));
    return false;
  }

  // Calculate local time.
  if (localtime_r(&tv.tv_sec, &tm) != &tm)
  {
    WARNING(STR("Cannot convert file time to local file time."));
    return false;
  }

  // Use the given date.
  tm.tm_year = a_crDate.getClearYears() - 1900;
  tm.tm_mon = a_crDate.getClearMonths();
  tm.tm_mday = a_crDate.getClearDays() + 1;

  // Make new system time.
  if ((tv.tv_sec = mktime(&tm)) == (time_t)-1)
  {
    WARNING(STR("Cannot convert system time in %x form (%u years, %u months, %u days).") COMMA ((a_cIsUTC ? STR("UTC") : STR("local time"))) COMMA a_crDate.getClearYears() COMMA a_crDate.getClearMonths() COMMA a_crDate.getClearDays());
    return false;
  }

  // Set new system time.
  if (settimeofday(&tv, NULL) != 0)
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
  NTime::CDateTime adjusted(a_crDateTime);
  struct timeval tv;
  struct tm tm;

  // Get current date & time since Epoch.
  if (gettimeofday(&tv, NULL) != 0)
  {
    WARNING(STR("Cannot get current date & time since Epoch."));
    return false;
  }

  // Calculate local time.
  if (localtime_r(&tv.tv_sec, &tm) != &tm)
  {
    WARNING(STR("Cannot convert file time to local file time."));
    return false;
  }

  // For UTC mode adjust the local time.
  if (a_cIsUTC)
  {
    // Calculate seconds of the local time.
    Tsint hours = tm.tm_hour - ((tv.tv_sec / (60 * 60)) % 24);
    Tsint minutes = tm.tm_min - ((tv.tv_sec / 60) % 60);
    Tsint seconds = tm.tm_sec - (tv.tv_sec % 60);

    // Calculate new time value to set.
    adjusted = a_crDateTime.getTimeStamp() - NTime::CTimeStamp(0, seconds, minutes, hours);
  }

  // Use adjusted date & time.
  tm.tm_year = adjusted.getDate().getClearYears() - 1900;
  tm.tm_mon = adjusted.getDate().getClearMonths();
  tm.tm_mday = adjusted.getDate().getClearDays() + 1;
  tm.tm_hour = adjusted.getTime().getClearHours();
  tm.tm_min = adjusted.getTime().getClearMinutes();
  tm.tm_sec = adjusted.getTime().getClearSeconds();

  // Make new system time.
  if ((tv.tv_sec = mktime(&tm)) == (time_t)-1)
  {
    WARNING(STR("Cannot convert system time in %x form (%u years, %u months, %u days, %u hours, %u minutes, %u seconds, %u milliseconds).") COMMA ((a_cIsUTC ? STR("UTC") : STR("local time"))) COMMA a_crDateTime.getDate().getClearYears() COMMA a_crDateTime.getDate().getClearMonths() COMMA a_crDateTime.getDate().getClearDays() COMMA a_crDateTime.getTime().getClearHours() COMMA a_crDateTime.getTime().getClearMinutes() COMMA a_crDateTime.getTime().getClearSeconds() COMMA a_crDateTime.getTime().getClearMilliseconds());
    return false;
  }
  tv.tv_usec = a_crDateTime.getTime().getClearMilliseconds() * 1000;

  // Set new system time.
  if (settimeofday(&tv, NULL) != 0)
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
