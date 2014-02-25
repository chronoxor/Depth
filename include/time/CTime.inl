/*!
 *  \file    CTime.inl Time class represents a time with hours, minutes,
 *           seconds and milliseconds values.
 *  \brief   Time class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time class (inline).

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
#ifndef __CTIME_INL__
#define __CTIME_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTime::CTime(const Tuint a_cHours, const Tuint a_cMinutes/* = 0 */, const Tuint a_cSeconds/* = 0 */, const Tuint a_cMilliseconds/* = 0 */) :
  m_Hours(0),
  m_Minutes(0),
  m_Seconds(0),
  m_Milliseconds(0)
{ CALL
  set(a_cHours, a_cMinutes, a_cSeconds, a_cMilliseconds);
}
/*--------------------------------------------------------------------------*/
inline CTime::CTime(const CTimeStamp& a_crTimeStamp) :
  m_Hours(0),
  m_Minutes(0),
  m_Seconds(0),
  m_Milliseconds(0)
{ CALL
  set(a_crTimeStamp);
}
/*--------------------------------------------------------------------------*/
inline CTime::CTime(const CTime& a_crInstance) :
  m_Hours(0),
  m_Minutes(0),
  m_Seconds(0),
  m_Milliseconds(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CTime::~CTime()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() == a_crTimeStamp.getTimeStampForTime());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CTime& a_crInstance1, const CTime& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Hours == a_crInstance2.m_Hours) && (a_crInstance1.m_Minutes == a_crInstance2.m_Minutes) && (a_crInstance1.m_Seconds == a_crInstance2.m_Seconds) && (a_crInstance1.m_Milliseconds == a_crInstance2.m_Milliseconds));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForTime() == a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() != a_crTimeStamp.getTimeStampForTime());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CTime& a_crInstance1, const CTime& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Hours != a_crInstance2.m_Hours) || (a_crInstance1.m_Minutes != a_crInstance2.m_Minutes) || (a_crInstance1.m_Seconds != a_crInstance2.m_Seconds) || (a_crInstance1.m_Milliseconds != a_crInstance2.m_Milliseconds));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForTime() != a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() < a_crTimeStamp.getTimeStampForTime());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForTime() < a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() > a_crTimeStamp.getTimeStampForTime());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForTime() > a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() <= a_crTimeStamp.getTimeStampForTime());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForTime() <= a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() >= a_crTimeStamp.getTimeStampForTime());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForTime() >= a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() + a_crTimeStamp.getTimeStampForTime());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CTime& a_crInstance1, const CTime& a_crInstance2)
{ CALL
  return (a_crInstance1.getTimeStamp() + a_crInstance2.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForTime() + a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CTime& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() - a_crTimeStamp.getTimeStampForTime());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CTime& a_crInstance1, const CTime& a_crInstance2)
{ CALL
  return (a_crInstance1.getTimeStamp() - a_crInstance2.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CTimeStamp& a_crTimeStamp, const CTime& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForTime() - a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline CTime& CTime::operator = (const CTimeStamp& a_crTimeStamp)
{ CALL
  set(a_crTimeStamp);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTime& CTime::operator = (const CTime& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTime& CTime::operator += (const CTimeStamp& a_crTimeStamp)
{ CALL
  set(getTimeStamp() + a_crTimeStamp.getTimeStampForTime());
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTime& CTime::operator -= (const CTimeStamp& a_crTimeStamp)
{ CALL
  set(getTimeStamp() - a_crTimeStamp.getTimeStampForTime());
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTime::operator CTimeStamp () const
{
  return getTimeStamp();
}
/*--------------------------------------------------------------------------*/
inline void CTime::set(const Tuint a_cHours, const Tuint a_cMinutes/* = 0 */, const Tuint a_cSeconds/* = 0 */, const Tuint a_cMilliseconds/* = 0 */)
{ CALL
  m_Hours = a_cHours % 24;
  m_Minutes = a_cMinutes % 60;
  m_Seconds = a_cSeconds % 60;
  m_Milliseconds = a_cMilliseconds % 1000;
}
/*--------------------------------------------------------------------------*/
inline void CTime::set(const CTimeStamp& a_crTimeStamp)
{ CALL
  m_Hours = a_crTimeStamp.getClearHours();
  m_Minutes = a_crTimeStamp.getClearMinutes();
  m_Seconds = a_crTimeStamp.getClearSeconds();
  m_Milliseconds = a_crTimeStamp.getClearMilliseconds();
}
/*--------------------------------------------------------------------------*/
inline void CTime::set(const CTime& a_crInstance)
{ CALL
  m_Hours = a_crInstance.m_Hours;
  m_Minutes = a_crInstance.m_Minutes;
  m_Seconds = a_crInstance.m_Seconds;
  m_Milliseconds = a_crInstance.m_Milliseconds;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTime::isAM() const
{ CALL
  return (m_Hours < 12);
}
/*--------------------------------------------------------------------------*/
inline Tbool CTime::isPM() const
{ CALL
  return (m_Hours >= 12);
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CTime::getTimeStamp() const
{
  return CTimeStamp(m_Milliseconds, m_Seconds, m_Minutes, m_Hours, 0);
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getHour() const
{ CALL
  return m_Hours;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getMinute() const
{ CALL
  return m_Minutes;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getSecond() const
{ CALL
  return m_Seconds;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getMillisecond() const
{ CALL
  return m_Milliseconds;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getClearHours() const
{ CALL
  return m_Hours;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getClearMinutes() const
{ CALL
  return m_Minutes;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getClearSeconds() const
{ CALL
  return m_Seconds;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getClearMilliseconds() const
{ CALL
  return m_Milliseconds;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getTotalHours() const
{ CALL
  return m_Hours;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getTotalMinutes() const
{ CALL
  return m_Minutes + m_Hours * 60;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getTotalSeconds() const
{ CALL
  return m_Seconds + (m_Minutes + m_Hours * 60) * 60;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTime::getTotalMilliseconds() const
{ CALL
  return m_Milliseconds + (m_Seconds + (m_Minutes + m_Hours * 60) * 60) * 1000;
}
/*--------------------------------------------------------------------------*/
inline CTime CTime::addHours(const Tsint a_cHours) const
{ CALL
  return CTime(getTimeStamp() + a_cHours * 60 * 60 * 1000);
}
/*--------------------------------------------------------------------------*/
inline CTime CTime::addMinutes(const Tsint a_cMinutes) const
{ CALL
  return CTime(getTimeStamp() + a_cMinutes * 60 * 1000);
}
/*--------------------------------------------------------------------------*/
inline CTime CTime::addSeconds(const Tsint a_cSeconds) const
{ CALL
  return CTime(getTimeStamp() + a_cSeconds * 1000);
}
/*--------------------------------------------------------------------------*/
inline CTime CTime::addMilliseconds(const Tsint a_cMilliseconds) const
{ CALL
  return CTime(getTimeStamp() + a_cMilliseconds);
}
/*--------------------------------------------------------------------------*/
inline CTime CTime::getMin()
{ CALL
  return CTime(CTimeStamp::getMin());
}
/*--------------------------------------------------------------------------*/
inline CTime CTime::getMax()
{ CALL
  return CTime(CTimeStamp::getMax());
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTime::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTime::CTime")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Hours, STR("m_Hours")));
    CHECK(a_rArchive.doValue(m_Minutes, STR("m_Minutes")));
    CHECK(a_rArchive.doValue(m_Seconds, STR("m_Seconds")));
    CHECK(a_rArchive.doValue(m_Milliseconds, STR("m_Milliseconds")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CTime::swap(CTime& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Hours, a_rInstance.m_Hours);
  NAlgorithms::NCommon::swap(m_Minutes, a_rInstance.m_Minutes);
  NAlgorithms::NCommon::swap(m_Seconds, a_rInstance.m_Seconds);
  NAlgorithms::NCommon::swap(m_Milliseconds, a_rInstance.m_Milliseconds);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
