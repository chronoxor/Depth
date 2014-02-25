/*!
 *  \file    CTimeStamp.inl Time stamp class represents a time stamp with a
 *           the 64-bit integer value.
 *  \brief   Time stamp class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time stamp class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time
    VERSION:   1.0
    CREATED:   19.02.2010 20:29:05

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
#ifndef __CTIMESTAMP_INL__
#define __CTIMESTAMP_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTimeStamp::CTimeStamp(const Tsint64 a_cMilliseconds, const Tsint64 a_cSeconds/* = 0 */, const Tsint64 a_cMinutes/* = 0 */, const Tsint64 a_cHours/* = 0 */, const Tsint64 a_cDays/* = 0 */) :
  m_TimeStampValue(0)
{ CALL
  set(a_cMilliseconds, a_cSeconds, a_cMinutes, a_cHours, a_cDays);
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp::CTimeStamp(const CTimeStamp& a_crInstance) :
  m_TimeStampValue(a_crInstance.m_TimeStampValue)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTimeStamp::~CTimeStamp()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CTimeStamp& a_crInstance, const Tsint64 a_cValue)
{ CALL
  return (a_crInstance.m_TimeStampValue == a_cValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2)
{ CALL
  return (a_crInstance1.m_TimeStampValue == a_crInstance2.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const Tsint64 a_cValue, const CTimeStamp& a_crInstance)
{ CALL
  return (a_cValue == a_crInstance.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CTimeStamp& a_crInstance, const Tsint64 a_cValue)
{ CALL
  return (a_crInstance.m_TimeStampValue != a_cValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2)
{ CALL
  return (a_crInstance1.m_TimeStampValue != a_crInstance2.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const Tsint64 a_cValue, const CTimeStamp& a_crInstance)
{ CALL
  return (a_cValue != a_crInstance.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CTimeStamp& a_crInstance, const Tsint64 a_cValue)
{ CALL
  return (a_crInstance.m_TimeStampValue < a_cValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2)
{ CALL
  return (a_crInstance1.m_TimeStampValue < a_crInstance2.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const Tsint64 a_cValue, const CTimeStamp& a_crInstance)
{ CALL
  return (a_cValue < a_crInstance.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CTimeStamp& a_crInstance, const Tsint64 a_cValue)
{ CALL
  return (a_crInstance.m_TimeStampValue > a_cValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2)
{ CALL
  return (a_crInstance1.m_TimeStampValue > a_crInstance2.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const Tsint64 a_cValue, const CTimeStamp& a_crInstance)
{ CALL
  return (a_cValue > a_crInstance.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CTimeStamp& a_crInstance, const Tsint64 a_cValue)
{ CALL
  return (a_crInstance.m_TimeStampValue <= a_cValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2)
{ CALL
  return (a_crInstance1.m_TimeStampValue <= a_crInstance2.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const Tsint64 a_cValue, const CTimeStamp& a_crInstance)
{ CALL
  return (a_cValue <= a_crInstance.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CTimeStamp& a_crInstance, const Tsint64 a_cValue)
{ CALL
  return (a_crInstance.m_TimeStampValue >= a_cValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2)
{ CALL
  return (a_crInstance1.m_TimeStampValue >= a_crInstance2.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const Tsint64 a_cValue, const CTimeStamp& a_crInstance)
{ CALL
  return (a_cValue >= a_crInstance.m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CTimeStamp& a_crInstance)
{ CALL
  CTimeStamp result(a_crInstance);

  result.m_TimeStampValue = +result.m_TimeStampValue;
  return result;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CTimeStamp& a_crInstance)
{ CALL
  CTimeStamp result(a_crInstance);

  result.m_TimeStampValue = -result.m_TimeStampValue;
  return result;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CTimeStamp& a_crInstance, const Tsint64 a_cValue)
{ CALL
  CTimeStamp result(a_crInstance);

  result.m_TimeStampValue += a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2)
{ CALL
  CTimeStamp result(a_crInstance1);

  result.m_TimeStampValue += a_crInstance2.m_TimeStampValue;
  return result;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const Tsint64 a_cValue, const CTimeStamp& a_crInstance)
{ CALL
  CTimeStamp result(a_crInstance);

  result.m_TimeStampValue = a_cValue + result.m_TimeStampValue;
  return result;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CTimeStamp& a_crInstance, const Tsint64 a_cValue)
{ CALL
  CTimeStamp result(a_crInstance);

  result.m_TimeStampValue -= a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CTimeStamp& a_crInstance1, const CTimeStamp& a_crInstance2)
{ CALL
  CTimeStamp result(a_crInstance1);

  result.m_TimeStampValue -= a_crInstance2.m_TimeStampValue;
  return result;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const Tsint64 a_cValue, const CTimeStamp& a_crInstance)
{ CALL
  CTimeStamp result(a_crInstance);

  result.m_TimeStampValue = a_cValue - result.m_TimeStampValue;
  return result;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp& CTimeStamp::operator = (const Tsint64 a_cValue)
{ CALL
  m_TimeStampValue = a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp& CTimeStamp::operator = (const CTimeStamp& a_crInstance)
{ CALL
  m_TimeStampValue = a_crInstance.m_TimeStampValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp& CTimeStamp::operator += (const Tsint64 a_cValue)
{ CALL
  m_TimeStampValue += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp& CTimeStamp::operator += (const CTimeStamp& a_crInstance)
{ CALL
  m_TimeStampValue += a_crInstance.m_TimeStampValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp& CTimeStamp::operator -= (const Tsint64 a_cValue)
{ CALL
  m_TimeStampValue -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp& CTimeStamp::operator -= (const CTimeStamp& a_crInstance)
{ CALL
  m_TimeStampValue -= a_crInstance.m_TimeStampValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp& CTimeStamp::operator ++ ()
{ CALL
  ++m_TimeStampValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CTimeStamp::operator ++ (int)
{ CALL
  CTimeStamp result(*this);

  result.m_TimeStampValue++;
  return result;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp& CTimeStamp::operator -- ()
{ CALL
  --m_TimeStampValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CTimeStamp::operator -- (int)
{ CALL
  CTimeStamp result(*this);

  result.m_TimeStampValue--;
  return result;
}
/*--------------------------------------------------------------------------*/
inline void CTimeStamp::set(const CTimeStamp& a_crInstance)
{ CALL
  m_TimeStampValue = a_crInstance.m_TimeStampValue;
}
/*--------------------------------------------------------------------------*/
inline void CTimeStamp::set(const Tsint64 a_cMilliseconds, const Tsint64 a_cSeconds/* = 0 */, const Tsint64 a_cMinutes/* = 0 */, const Tsint64 a_cHours/* = 0 */, const Tsint64 a_cDays/* = 0 */)
{ CALL
  m_TimeStampValue = a_cMilliseconds + (a_cSeconds + (a_cMinutes + (a_cHours + a_cDays * 24) * 60) * 60) * 1000;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTimeStamp::isZero() const
{ CALL
  return (m_TimeStampValue == 0);
}
/*--------------------------------------------------------------------------*/
inline Tbool CTimeStamp::isPositive() const
{ CALL
  return (m_TimeStampValue > 0);
}
/*--------------------------------------------------------------------------*/
inline Tbool CTimeStamp::isNegative() const
{ CALL
  return (m_TimeStampValue < 0);
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CTimeStamp::getTimeStampForTime() const
{ CALL
  return CTimeStamp(m_TimeStampValue % 86400000);
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CTimeStamp::getTimeStampForDate() const
{ CALL
  return CTimeStamp(m_TimeStampValue - (m_TimeStampValue % 86400000));
}
/*--------------------------------------------------------------------------*/
inline Tsint64 CTimeStamp::getTimeStampValue() const
{ CALL
  return m_TimeStampValue;
}
/*--------------------------------------------------------------------------*/
inline Tsint CTimeStamp::getClearMilliseconds() const
{ CALL
  return getTotalMilliseconds() % 1000;
}
/*--------------------------------------------------------------------------*/
inline Tsint CTimeStamp::getClearSeconds() const
{ CALL
  return (getTotalMilliseconds() / 1000) % 60;
}
/*--------------------------------------------------------------------------*/
inline Tsint CTimeStamp::getClearMinutes() const
{ CALL
  return (getTotalMilliseconds() / (1000 * 60)) % 60;
}
/*--------------------------------------------------------------------------*/
inline Tsint CTimeStamp::getClearHours() const
{ CALL
  return (getTotalMilliseconds() / (1000 * 60 * 60)) % 24;
}
/*--------------------------------------------------------------------------*/
inline Tsint CTimeStamp::getClearDays() const
{ CALL
  return (Tsint)getTotalDays();
}
/*--------------------------------------------------------------------------*/
inline Tsint64 CTimeStamp::getTotalMilliseconds() const
{ CALL
  return m_TimeStampValue;
}
/*--------------------------------------------------------------------------*/
inline Tsint64 CTimeStamp::getTotalSeconds() const
{ CALL
  return getTotalMilliseconds() / 1000;
}
/*--------------------------------------------------------------------------*/
inline Tsint64 CTimeStamp::getTotalMinutes() const
{ CALL
  return getTotalMilliseconds() / (1000 * 60);
}
/*--------------------------------------------------------------------------*/
inline Tsint64 CTimeStamp::getTotalHours() const
{ CALL
  return getTotalMilliseconds() / (1000 * 60 * 60);
}
/*--------------------------------------------------------------------------*/
inline Tsint64 CTimeStamp::getTotalDays() const
{ CALL
  return getTotalMilliseconds() / (1000 * 60 * 60 * 24);
}
/*--------------------------------------------------------------------------*/
inline void CTimeStamp::clear()
{ CALL
  m_TimeStampValue = 0;
}
/*--------------------------------------------------------------------------*/
inline void CTimeStamp::absolute()
{ CALL
  m_TimeStampValue = NAlgorithms::NNumeric::absolute(m_TimeStampValue);
}
/*--------------------------------------------------------------------------*/
inline void CTimeStamp::negate()
{ CALL
  m_TimeStampValue = -m_TimeStampValue;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CTimeStamp::getMin()
{ CALL
  return CTimeStamp(NConstants::CConstants::sint64Min);
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CTimeStamp::getMax()
{ CALL
  return CTimeStamp(NConstants::CConstants::sint64Max);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTimeStamp::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTime::CTimeStamp")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_TimeStampValue, STR("m_TimeStampValue")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CTimeStamp::swap(CTimeStamp& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_TimeStampValue, a_rInstance.m_TimeStampValue);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
