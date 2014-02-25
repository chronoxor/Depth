/*!
 *  \file    CDate.cpp Date class represents a date with year, month and day
 *           values.
 *  \brief   Date class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Date class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time
    VERSION:   1.0
    CREATED:   26.02.2010 03:35:59

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

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
#include <Depth/include/time/CDate.hpp>
/*==========================================================================*/
#ifndef __CDATE_CPP__
#define __CDATE_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CDate::CDate() :
  m_Year(0),
  m_Month(0),
  m_Day(0)
{ CALL
  set(NSystem::CSystemBase::getSystemDate(false));
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool operator < (const CDate& a_crInstance1, const CDate& a_crInstance2)
{ CALL
  if (a_crInstance1.m_Year < a_crInstance2.m_Year)
    return true;
  if (a_crInstance1.m_Year == a_crInstance2.m_Year)
  {
    if (a_crInstance1.m_Month < a_crInstance2.m_Month)
      return true;
    if (a_crInstance1.m_Month == a_crInstance2.m_Month)
    {
      return (a_crInstance1.m_Day < a_crInstance2.m_Day);
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool operator > (const CDate& a_crInstance1, const CDate& a_crInstance2)
{ CALL
  if (a_crInstance1.m_Year > a_crInstance2.m_Year)
    return true;
  if (a_crInstance1.m_Year == a_crInstance2.m_Year)
  {
    if (a_crInstance1.m_Month > a_crInstance2.m_Month)
      return true;
    if (a_crInstance1.m_Month == a_crInstance2.m_Month)
    {
      return (a_crInstance1.m_Day > a_crInstance2.m_Day);
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool operator <= (const CDate& a_crInstance1, const CDate& a_crInstance2)
{ CALL
  if (a_crInstance1.m_Year < a_crInstance2.m_Year)
    return true;
  if (a_crInstance1.m_Year == a_crInstance2.m_Year)
  {
    if (a_crInstance1.m_Month < a_crInstance2.m_Month)
      return true;
    if (a_crInstance1.m_Month == a_crInstance2.m_Month)
    {
      return (a_crInstance1.m_Day <= a_crInstance2.m_Day);
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool operator >= (const CDate& a_crInstance1, const CDate& a_crInstance2)
{ CALL
  if (a_crInstance1.m_Year > a_crInstance2.m_Year)
    return true;
  if (a_crInstance1.m_Year == a_crInstance2.m_Year)
  {
    if (a_crInstance1.m_Month > a_crInstance2.m_Month)
      return true;
    if (a_crInstance1.m_Month == a_crInstance2.m_Month)
    {
      return (a_crInstance1.m_Day >= a_crInstance2.m_Day);
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
void CDate::set(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay)
{ CALL
  m_Year = a_cYear;
  m_Month = (a_cMonth == 0) ? 0 : ((a_cMonth > 12) ? 11 : (a_cMonth - 1));
  m_Day = getDaysInMonth(m_Year, m_Month + 1);
  m_Day = (a_cDay == 0) ? 0 : ((a_cDay > m_Day) ? (m_Day - 1) : (a_cDay - 1));
}
/*--------------------------------------------------------------------------*/
void CDate::set(const CTimeStamp& a_crTimeStamp)
{ CALL
  const Tuint FOUR = (365 + 365 + 365 + 366);
  const Tuint HUNDRED_1 = ((FOUR * 25) - 1);
  const Tuint HUNDRED_4 = ((FOUR * 100) - 3);
  Tsint blocks, days_left = (Tsint)a_crTimeStamp.getTotalDays();
  Tbool bc_years = (days_left < 0);

  m_Year = 0;

  // How many four-hundred-year blocks are we after the epoch?
  blocks = days_left / HUNDRED_4;
  m_Year += blocks * 400;
  days_left -= blocks * HUNDRED_4;

  // How many one-hundred-year blocks are we after that?
  blocks = days_left / HUNDRED_1;
  m_Year += blocks * 100;
  days_left -= blocks * HUNDRED_1;

  // Oops! went too far.
  if (bc_years)
  {
    if (blocks == -4)
    {
      m_Year += 100;
      days_left -= HUNDRED_1;
    }
  }
  else
  {
    if (blocks == 4)
    {
      m_Year -= 100;
      days_left += HUNDRED_1;
    }
  }

  // How many four-year blocks are we after that?
  blocks = days_left / FOUR;
  m_Year += blocks * 4;
  days_left -= blocks * FOUR;

  // Now we're within four years. Count off the remaining years.
  if (bc_years)
  {
    for (Tuint i = 0; ((days_left <= -365) && (i < 3)); ++i)
    {
      --m_Year;
      days_left += 365;
    }
    if (days_left <= -366)
    {
      --m_Year;
      days_left += 366;
    }
    if (days_left < 0)
    {
      --m_Year;
      days_left += (isLeapYear(m_Year) ? 366 : 365);
    }
  }
  else
  {
    for (Tuint i = 0; ((days_left > 365) && (i < 3)); ++i)
    {
      ++m_Year;
      days_left -= 365;
    }
    if (days_left > 366)
    {
      ++m_Year;
      days_left -= 366;
    }
    if ((days_left <= 0) && !isLeapYear(m_Year))
    {
      --m_Year;
      days_left += 365;
    }
  }

  Tsint correction = ((isLeapYear(m_Year) || bc_years) ? 1 : 0);

  // We got the exact year... let's continue to extract the month and day.
  blocks = days_left + correction;

  // Adjust if past February.
  if ((blocks + 1) > 58)
    blocks += isLeapYear(m_Year) ? 1 : 2;

  // Calculate month value.
  m_Month = (blocks * 100 - 50) / 3057;

  // Current day is calculated form all day count since current month.
  m_Day = days_left - getYearDays(m_Year, m_Month + 1) + correction - 1;
}
/*--------------------------------------------------------------------------*/
CDate::EWeekDay CDate::getWeekDay() const
{ CALL
  Tsint full_days = getTotalDays();

  if (full_days > 0)
    return (CDate::EWeekDay)(e_SUNDAY + ((full_days - 1) % 7));
  else if (full_days < 0)
    return (CDate::EWeekDay)(e_SUNDAY + (full_days % 7) + 6);
  else
    return e_SATURDAY;
}
/*--------------------------------------------------------------------------*/
Tuint CDate::getDaysInMonth(const Tsint a_cYear, const Tuint a_cMonth)
{ CALL
  const Tuint MIN_MONTH_DAYS[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  const Tuint MAX_MONTH_DAYS[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  Tuint month = (a_cMonth == 0) ? 0 : ((a_cMonth > 12) ? 11 : (a_cMonth - 1));

  return isLeapYear(a_cYear) ? MAX_MONTH_DAYS[month] : MIN_MONTH_DAYS[month];
}
/*--------------------------------------------------------------------------*/
Tsint CDate::getEpochDays(const Tsint a_cYear)
{ CALL
  if (a_cYear > 0)
  {
    Tsint prev_year = a_cYear - 1;
    return (366 + (prev_year * 365 + (prev_year / 4) - (prev_year / 100) + (prev_year / 400)));
  }
  else if (a_cYear < 0)
  {
    Tsint next_year = a_cYear + 1;
    return (-365 + (next_year * 365 + (a_cYear / 4) - (a_cYear / 100) + (a_cYear / 400)));
  }
  return 0;
}
/*--------------------------------------------------------------------------*/
Tsint CDate::getEpochDays(const Tsint a_cYear, const Tuint a_cMonth)
{ CALL
  Tsint year = a_cYear;
  Tuint month = (a_cMonth == 0) ? 0 : ((a_cMonth > 12) ? 11 : (a_cMonth - 1));

  return getEpochDays(year) + getYearDays(year, month + 1);
}
/*--------------------------------------------------------------------------*/
Tsint CDate::getEpochDays(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay)
{ CALL
  Tsint year = a_cYear;
  Tuint month = (a_cMonth == 0) ? 0 : ((a_cMonth > 12) ? 11 : (a_cMonth - 1));
  Tuint day = getDaysInMonth(year, month + 1);
  day = (day == 0) ? 0 : ((a_cDay > day) ? (day - 1) : (a_cDay - 1));

  return getEpochDays(year, month + 1) + day;
}
/*--------------------------------------------------------------------------*/
Tsint CDate::getEpochWeeks(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay)
{ CALL
  Tsint epoch_days = getEpochDays(a_cYear, a_cMonth, a_cDay);

  if (epoch_days > 0)
    return (epoch_days + 5) / 7;
  else
    return (epoch_days - 1) / 7;
}
/*--------------------------------------------------------------------------*/
Tsint CDate::getYearDays(const Tsint a_cYear, const Tuint a_cMonth)
{ CALL
  const Tuint MIN_MONTH_DAYS_SUM[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
  const Tuint MAX_MONTH_DAYS_SUM[] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };

  Tsint year = a_cYear;
  Tuint month = (a_cMonth == 0) ? 0 : ((a_cMonth > 12) ? 11 : (a_cMonth - 1));

  return (isLeapYear(year) ? MAX_MONTH_DAYS_SUM[month] : MIN_MONTH_DAYS_SUM[month]);
}
/*--------------------------------------------------------------------------*/
Tsint CDate::getYearDays(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay)
{ CALL
  Tsint year = a_cYear;
  Tuint month = (a_cMonth == 0) ? 0 : ((a_cMonth > 12) ? 11 : (a_cMonth - 1));
  Tuint day = getDaysInMonth(year, month + 1);
  day = (day == 0) ? 0 : ((a_cDay > day) ? (day - 1) : (a_cDay - 1));

  return getYearDays(year, month + 1) + day;
}
/*--------------------------------------------------------------------------*/
Tsint CDate::getYearWeeks(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay)
{ CALL
  Tsint epoch_days = getEpochDays(a_cYear, a_cMonth, a_cDay);
  Tsint year_days = getEpochDays(a_cYear, 1, 1);

  if (epoch_days > 0)
    return (((epoch_days - year_days) + 5) / 7) + 1;
  else
    return (((year_days - epoch_days) - 1) / 7) + 1;
}
/*--------------------------------------------------------------------------*/
CDate CDate::getProcessDate()
{ CALL
  return NSystem::CSystemBase::getProcessDate();
}
/*--------------------------------------------------------------------------*/
CDate CDate::getSystemDate(const Tbool a_cIsUTC/* = true */)
{ CALL
  return NSystem::CSystemBase::getSystemDate(a_cIsUTC);
}
/*--------------------------------------------------------------------------*/
Tbool CDate::setSystemDateUTC(const CDate& a_crDate)
{ CALL
  return NSystem::CSystemBase::setSystemDate(a_crDate, true);
}
/*--------------------------------------------------------------------------*/
Tbool CDate::setSystemDateLocal(const CDate& a_crDate)
{ CALL
  return NSystem::CSystemBase::setSystemDate(a_crDate, false);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
