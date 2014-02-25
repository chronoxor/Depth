/*!
 *  \file    CTime.cpp Time class represents a time with hours, minutes,
 *           seconds and milliseconds values.
 *  \brief   Time class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time
    VERSION:   1.0
    CREATED:   24.02.2010 21:31:32

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
#include <Depth/include/time/CTime.hpp>
/*==========================================================================*/
#ifndef __CTIME_CPP__
#define __CTIME_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CTime::CTime() :
  m_Hours(0),
  m_Minutes(0),
  m_Seconds(0),
  m_Milliseconds(0)
{ CALL
  set(NSystem::CSystemBase::getSystemTime(false));
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool operator < (const CTime& a_crInstance1, const CTime& a_crInstance2)
{ CALL
  if (a_crInstance1.m_Hours < a_crInstance2.m_Hours)
    return true;
  if (a_crInstance1.m_Hours == a_crInstance2.m_Hours)
  {
    if (a_crInstance1.m_Minutes < a_crInstance2.m_Minutes)
      return true;
    if (a_crInstance1.m_Minutes == a_crInstance2.m_Minutes)
    {
      if (a_crInstance1.m_Seconds < a_crInstance2.m_Seconds)
        return true;
      if (a_crInstance1.m_Seconds == a_crInstance2.m_Seconds)
      {
        return (a_crInstance1.m_Milliseconds < a_crInstance2.m_Milliseconds);
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool operator > (const CTime& a_crInstance1, const CTime& a_crInstance2)
{ CALL
  if (a_crInstance1.m_Hours > a_crInstance2.m_Hours)
    return true;
  if (a_crInstance1.m_Hours == a_crInstance2.m_Hours)
  {
    if (a_crInstance1.m_Minutes > a_crInstance2.m_Minutes)
      return true;
    if (a_crInstance1.m_Minutes == a_crInstance2.m_Minutes)
    {
      if (a_crInstance1.m_Seconds > a_crInstance2.m_Seconds)
        return true;
      if (a_crInstance1.m_Seconds == a_crInstance2.m_Seconds)
      {
        return (a_crInstance1.m_Milliseconds > a_crInstance2.m_Milliseconds);
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool operator <= (const CTime& a_crInstance1, const CTime& a_crInstance2)
{ CALL
  if (a_crInstance1.m_Hours < a_crInstance2.m_Hours)
    return true;
  if (a_crInstance1.m_Hours == a_crInstance2.m_Hours)
  {
    if (a_crInstance1.m_Minutes < a_crInstance2.m_Minutes)
      return true;
    if (a_crInstance1.m_Minutes == a_crInstance2.m_Minutes)
    {
      if (a_crInstance1.m_Seconds < a_crInstance2.m_Seconds)
        return true;
      if (a_crInstance1.m_Seconds == a_crInstance2.m_Seconds)
      {
        return (a_crInstance1.m_Milliseconds <= a_crInstance2.m_Milliseconds);
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool operator >= (const CTime& a_crInstance1, const CTime& a_crInstance2)
{ CALL
  if (a_crInstance1.m_Hours > a_crInstance2.m_Hours)
    return true;
  if (a_crInstance1.m_Hours == a_crInstance2.m_Hours)
  {
    if (a_crInstance1.m_Minutes > a_crInstance2.m_Minutes)
      return true;
    if (a_crInstance1.m_Minutes == a_crInstance2.m_Minutes)
    {
      if (a_crInstance1.m_Seconds > a_crInstance2.m_Seconds)
        return true;
      if (a_crInstance1.m_Seconds == a_crInstance2.m_Seconds)
      {
        return (a_crInstance1.m_Milliseconds >= a_crInstance2.m_Milliseconds);
      }
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
CTime& CTime::operator += (const CTime& a_crInstance)
{ CALL
  m_Hours += a_crInstance.m_Hours;
  m_Minutes += a_crInstance.m_Minutes;
  m_Seconds += a_crInstance.m_Seconds;
  m_Milliseconds += a_crInstance.m_Milliseconds;

  m_Seconds += m_Milliseconds / 1000;
  m_Minutes += m_Seconds / 60;
  m_Hours += m_Minutes / 60;

  m_Milliseconds %= 1000;
  m_Hours %= 24;
  m_Minutes %= 60;
  m_Seconds %= 60;
  return *this;
}
/*--------------------------------------------------------------------------*/
CTime& CTime::operator -= (const CTime& a_crInstance)
{ CALL
  Tsint hours = m_Hours - a_crInstance.m_Hours;
  Tsint minutes = m_Minutes - a_crInstance.m_Minutes;
  Tsint seconds = m_Seconds - a_crInstance.m_Seconds;
  Tsint milliseconds = m_Milliseconds - a_crInstance.m_Milliseconds;

  seconds -= milliseconds / 1000;
  minutes -= seconds / 60;
  hours -= minutes / 60;

  if (milliseconds < 0)
  {
    milliseconds += 1000;
    seconds -= 1;
  }
  if (seconds < 0)
  {
    seconds += 60;
    minutes -= 1;
  }
  if (minutes < 0)
  {
    minutes += 60;
    hours -= 1;
  }
  if (hours < 0)
  {
    hours += 24;
  }

  m_Milliseconds = milliseconds % 1000;
  m_Hours = hours % 24;
  m_Minutes = minutes % 60;
  m_Seconds = seconds % 60;
  return *this;
}
/*--------------------------------------------------------------------------*/
CTime CTime::getProcessTime()
{ CALL
  return NSystem::CSystemBase::getProcessTime();
}
/*--------------------------------------------------------------------------*/
CTime CTime::getSystemTime(const Tbool a_cIsUTC/* = true */)
{ CALL
  return NSystem::CSystemBase::getSystemTime(a_cIsUTC);
}
/*--------------------------------------------------------------------------*/
Tbool CTime::setSystemTimeUTC(const CTime& a_crTime)
{ CALL
  return NSystem::CSystemBase::setSystemTime(a_crTime, true);
}
/*--------------------------------------------------------------------------*/
Tbool CTime::setSystemTimeLocal(const CTime& a_crTime)
{ CALL
  return NSystem::CSystemBase::setSystemTime(a_crTime, false);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
