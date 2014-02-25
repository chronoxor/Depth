/*!
 *  \file    CDateTime.inl Date & Time class represents a date & time with
 *           year, month, day, hours, minutes, seconds and milliseconds
 *           values.
 *  \brief   Date & Time class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.03.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Date & Time class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time
    VERSION:   1.0
    CREATED:   04.03.2010 02:11:01

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
#ifndef __CDATETIME_INL__
#define __CDATETIME_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CDateTime::CDateTime() :
  m_Date(),
  m_Time()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDateTime::CDateTime(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay, const Tuint a_cHours/* = 0 */, const Tuint a_cMinutes/* = 0 */, const Tuint a_cSeconds/* = 0 */, const Tuint a_cMilliseconds/* = 0 */) :
  m_Date(a_cYear, a_cMonth, a_cDay),
  m_Time(a_cHours, a_cMinutes, a_cSeconds, a_cMilliseconds)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDateTime::CDateTime(const CDate& a_crDate, const CTime& a_crTime) :
  m_Date(a_crDate),
  m_Time(a_crTime)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDateTime::CDateTime(const CTimeStamp& a_crTimeStamp) :
  m_Date(a_crTimeStamp),
  m_Time(a_crTimeStamp)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDateTime::CDateTime(const CDateTime& a_crInstance) :
  m_Date(a_crInstance.m_Date),
  m_Time(a_crInstance.m_Time)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDateTime::~CDateTime()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() == a_crTimeStamp);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Date == a_crInstance2.m_Date) && (a_crInstance1.m_Time == a_crInstance2.m_Time));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance)
{ CALL
  return (a_crTimeStamp == a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() != a_crTimeStamp);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Date != a_crInstance2.m_Date) || (a_crInstance1.m_Time != a_crInstance2.m_Time));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance)
{ CALL
  return (a_crTimeStamp != a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() < a_crTimeStamp);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Date < a_crInstance2.m_Date) || ((a_crInstance1.m_Date == a_crInstance2.m_Date) && (a_crInstance1.m_Time < a_crInstance2.m_Time)));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance)
{ CALL
  return (a_crTimeStamp < a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() > a_crTimeStamp);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Date > a_crInstance2.m_Date) || ((a_crInstance1.m_Date == a_crInstance2.m_Date) && (a_crInstance1.m_Time > a_crInstance2.m_Time)));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance)
{ CALL
  return (a_crTimeStamp > a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() <= a_crTimeStamp);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Date < a_crInstance2.m_Date) || ((a_crInstance1.m_Date == a_crInstance2.m_Date) && (a_crInstance1.m_Time <= a_crInstance2.m_Time)));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance)
{ CALL
  return (a_crTimeStamp <= a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() >= a_crTimeStamp);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Date > a_crInstance2.m_Date) || ((a_crInstance1.m_Date == a_crInstance2.m_Date) && (a_crInstance1.m_Time >= a_crInstance2.m_Time)));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance)
{ CALL
  return (a_crTimeStamp >= a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() + a_crTimeStamp);
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2)
{ CALL
  return (a_crInstance1.getTimeStamp() + a_crInstance2.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance)
{ CALL
  return (a_crTimeStamp + a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CDateTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() - a_crTimeStamp);
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CDateTime& a_crInstance1, const CDateTime& a_crInstance2)
{ CALL
  return (a_crInstance1.getTimeStamp() - a_crInstance2.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CTimeStamp& a_crTimeStamp, const CDateTime& a_crInstance)
{ CALL
  return (a_crTimeStamp - a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline CDateTime& CDateTime::operator = (const CTimeStamp& a_crTimeStamp)
{ CALL
  set(a_crTimeStamp);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDateTime& CDateTime::operator = (const CDateTime& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDateTime& CDateTime::operator += (const CTimeStamp& a_crTimeStamp)
{ CALL
  set(getTimeStamp() + a_crTimeStamp);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDateTime& CDateTime::operator += (const CDateTime& a_crInstance)
{ CALL
  set(getTimeStamp() + a_crInstance.getTimeStamp());
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDateTime& CDateTime::operator -= (const CTimeStamp& a_crTimeStamp)
{ CALL
  set(getTimeStamp() - a_crTimeStamp);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDateTime& CDateTime::operator -= (const CDateTime& a_crInstance)
{ CALL
  set(getTimeStamp() - a_crInstance.getTimeStamp());
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDateTime::operator const CDate& () const
{
  return getDate();
}
/*--------------------------------------------------------------------------*/
inline CDateTime::operator const CTime& () const
{
  return getTime();
}
/*--------------------------------------------------------------------------*/
inline CDateTime::operator CTimeStamp () const
{
  return getTimeStamp();
}
/*--------------------------------------------------------------------------*/
inline void CDateTime::set(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay, const Tuint a_cHours/* = 0 */, const Tuint a_cMinutes/* = 0 */, const Tuint a_cSeconds/* = 0 */, const Tuint a_cMilliseconds/* = 0 */)
{ CALL
  m_Date.set(a_cYear, a_cMonth, a_cDay);
  m_Time.set(a_cHours, a_cMinutes, a_cSeconds, a_cMilliseconds);
}
/*--------------------------------------------------------------------------*/
inline void CDateTime::set(const CDate& a_crDate, const CTime& a_crTime)
{ CALL
  m_Date.set(a_crDate);
  m_Time.set(a_crTime);
}
/*--------------------------------------------------------------------------*/
inline void CDateTime::set(const CTimeStamp& a_crTimeStamp)
{ CALL
  m_Date.set(a_crTimeStamp);
  m_Time.set(a_crTimeStamp);
}
/*--------------------------------------------------------------------------*/
inline void CDateTime::set(const CDateTime& a_crInstance)
{ CALL
  m_Date.set(a_crInstance.getDate());
  m_Time.set(a_crInstance.getTime());
}
/*--------------------------------------------------------------------------*/
inline const CDate& CDateTime::getDate() const
{ CALL
  return m_Date;
}
/*--------------------------------------------------------------------------*/
inline const CTime& CDateTime::getTime() const
{ CALL
  return m_Time;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CDateTime::getTimeStamp() const
{
  return CTimeStamp(m_Time.getClearMilliseconds(), m_Time.getClearSeconds(), m_Time.getClearMinutes(), m_Time.getClearHours(), m_Date.getTotalDays());
}
/*--------------------------------------------------------------------------*/
inline CDateTime CDateTime::addYears(const Tsint a_cYears) const
{ CALL
  return CDateTime(m_Date.getClearYears() + a_cYears, m_Date.getClearMonths() + 1, m_Date.getClearDays() + 1, m_Time.getClearHours(), m_Time.getClearMinutes(), m_Time.getClearSeconds(), m_Time.getClearMilliseconds());
}
/*--------------------------------------------------------------------------*/
inline CDateTime CDateTime::addMonths(const Tsint a_cMonths) const
{ CALL
  return CDateTime(m_Date.getClearYears() + ((m_Date.getClearMonths() + a_cMonths) / 12), ((m_Date.getClearMonths() + a_cMonths) % 12) + 1, m_Date.getClearDays() + 1, m_Time.getClearHours(), m_Time.getClearMinutes(), m_Time.getClearSeconds(), m_Time.getClearMilliseconds());
}
/*--------------------------------------------------------------------------*/
inline CDateTime CDateTime::addWeeks(const Tsint a_cWeeks) const
{ CALL
  return CDateTime(getTimeStamp() + a_cWeeks * 7 * 24 * 60 * 60 * 1000);
}
/*--------------------------------------------------------------------------*/
inline CDateTime CDateTime::addDays(const Tsint a_cDays) const
{ CALL
  return CDateTime(getTimeStamp() + a_cDays * 24 * 60 * 60 * 1000);
}
/*--------------------------------------------------------------------------*/
inline CDateTime CDateTime::addHours(const Tsint a_cHours) const
{ CALL
  return CDateTime(getTimeStamp() + a_cHours * 60 * 60 * 1000);
}
/*--------------------------------------------------------------------------*/
inline CDateTime CDateTime::addMinutes(const Tsint a_cMinutes) const
{ CALL
  return CDateTime(getTimeStamp() + a_cMinutes * 60 * 1000);
}
/*--------------------------------------------------------------------------*/
inline CDateTime CDateTime::addSeconds(const Tsint a_cSeconds) const
{ CALL
  return CDateTime(getTimeStamp() + a_cSeconds * 1000);
}
/*--------------------------------------------------------------------------*/
inline CDateTime CDateTime::addMilliseconds(const Tsint a_cMilliseconds) const
{ CALL
  return CDateTime(getTimeStamp() + a_cMilliseconds);
}
/*--------------------------------------------------------------------------*/
inline CDateTime CDateTime::getMin()
{ CALL
  return CDateTime(CTimeStamp::getMin());
}
/*--------------------------------------------------------------------------*/
inline CDateTime CDateTime::getMax()
{ CALL
  return CDateTime(CTimeStamp::getMax());
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CDateTime::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTime::CDateTime")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Date, STR("m_Date")));
    CHECK(a_rArchive.doValue(m_Time, STR("m_Time")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CDateTime::swap(CDateTime& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Date, a_rInstance.m_Date);
  NAlgorithms::NCommon::swap(m_Time, a_rInstance.m_Time);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
