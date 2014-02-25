/*!
 *  \file    CDate.inl Date class represents a date with year, month and day
 *           values.
 *  \brief   Date class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Date class (inline).

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
#ifndef __CDATE_INL__
#define __CDATE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CDate::CDate(const Tsint a_cYear, const Tuint a_cMonth, const Tuint a_cDay) :
  m_Year(0),
  m_Month(0),
  m_Day(0)
{ CALL
  set(a_cYear, a_cMonth, a_cDay);
}
/*--------------------------------------------------------------------------*/
inline CDate::CDate(const CTimeStamp& a_crTimeStamp) :
  m_Year(0),
  m_Month(0),
  m_Day(0)
{ CALL
  set(a_crTimeStamp);
}
/*--------------------------------------------------------------------------*/
inline CDate::CDate(const CDate& a_crInstance) :
  m_Year(0),
  m_Month(0),
  m_Day(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CDate::~CDate()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() == a_crTimeStamp.getTimeStampForDate());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CDate& a_crInstance1, const CDate& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Year == a_crInstance2.m_Year) && (a_crInstance1.m_Month == a_crInstance2.m_Month) && (a_crInstance1.m_Day == a_crInstance2.m_Day));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForDate() == a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() != a_crTimeStamp.getTimeStampForDate());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CDate& a_crInstance1, const CDate& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Year != a_crInstance2.m_Year) || (a_crInstance1.m_Month != a_crInstance2.m_Month) || (a_crInstance1.m_Day != a_crInstance2.m_Day));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForDate() != a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() < a_crTimeStamp.getTimeStampForDate());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForDate() < a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() > a_crTimeStamp.getTimeStampForDate());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForDate() > a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() <= a_crTimeStamp.getTimeStampForDate());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForDate() <= a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() >= a_crTimeStamp.getTimeStampForDate());
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForDate() >= a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() + a_crTimeStamp.getTimeStampForDate());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CDate& a_crInstance1, const CDate& a_crInstance2)
{ CALL
  return (a_crInstance1.getTimeStamp() + a_crInstance2.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator + (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForDate() + a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CDate& a_crInstance, const CTimeStamp& a_crTimeStamp)
{ CALL
  return (a_crInstance.getTimeStamp() - a_crTimeStamp.getTimeStampForDate());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CDate& a_crInstance1, const CDate& a_crInstance2)
{ CALL
  return (a_crInstance1.getTimeStamp() - a_crInstance2.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline BASE_API CTimeStamp operator - (const CTimeStamp& a_crTimeStamp, const CDate& a_crInstance)
{ CALL
  return (a_crTimeStamp.getTimeStampForDate() - a_crInstance.getTimeStamp());
}
/*--------------------------------------------------------------------------*/
inline CDate& CDate::operator = (const CTimeStamp& a_crTimeStamp)
{ CALL
  set(a_crTimeStamp);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDate& CDate::operator = (const CDate& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDate& CDate::operator += (const CTimeStamp& a_crTimeStamp)
{ CALL
  set(getTimeStamp() + a_crTimeStamp.getTimeStampForDate());
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDate& CDate::operator += (const CDate& a_crInstance)
{ CALL
  set(getTimeStamp() + a_crInstance.getTimeStamp());
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDate& CDate::operator -= (const CTimeStamp& a_crTimeStamp)
{ CALL
  set(getTimeStamp() - a_crTimeStamp.getTimeStampForDate());
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDate& CDate::operator -= (const CDate& a_crInstance)
{ CALL
  set(getTimeStamp() - a_crInstance.getTimeStamp());
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CDate::operator CTimeStamp () const
{
  return getTimeStamp();
}
/*--------------------------------------------------------------------------*/
inline void CDate::set(const CDate& a_crInstance)
{ CALL
  m_Year = a_crInstance.m_Year;
  m_Month = a_crInstance.m_Month;
  m_Day = a_crInstance.m_Day;
}
/*--------------------------------------------------------------------------*/
inline Tbool CDate::isBC() const
{ CALL
  return (m_Year < 0);
}
/*--------------------------------------------------------------------------*/
inline Tbool CDate::isAD() const
{ CALL
  return (m_Year >= 0);
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CDate::getTimeStamp() const
{
  return CTimeStamp(0, 0, 0, 0, getTotalDays());
}
/*--------------------------------------------------------------------------*/
inline Tsint CDate::getYear() const
{ CALL
  return m_Year;
}
/*--------------------------------------------------------------------------*/
inline Tuint CDate::getMonth() const
{ CALL
  return (m_Month + 1);
}
/*--------------------------------------------------------------------------*/
inline Tuint CDate::getDay() const
{ CALL
  return (m_Day + 1);
}
/*--------------------------------------------------------------------------*/
inline Tsint CDate::getClearYears() const
{ CALL
  return m_Year;
}
/*--------------------------------------------------------------------------*/
inline Tuint CDate::getClearMonths() const
{ CALL
  return m_Month;
}
/*--------------------------------------------------------------------------*/
inline Tuint CDate::getClearDays() const
{ CALL
  return m_Day;
}
/*--------------------------------------------------------------------------*/
inline Tsint CDate::getTotalYears() const
{ CALL
  return m_Year;
}
/*--------------------------------------------------------------------------*/
inline Tsint CDate::getTotalMonths() const
{ CALL
  return ((m_Year * 12) + m_Month);
}
/*--------------------------------------------------------------------------*/
inline Tsint CDate::getTotalDays() const
{ CALL
  return getEpochDays(m_Year, m_Month + 1, m_Day + 1);
}
/*--------------------------------------------------------------------------*/
inline CDate CDate::addYears(const Tsint a_cYears) const
{ CALL
  return CDate(m_Year + a_cYears, m_Month + 1, m_Day + 1);
}
/*--------------------------------------------------------------------------*/
inline CDate CDate::addMonths(const Tsint a_cMonths) const
{ CALL
  return CDate(m_Year + ((m_Month + a_cMonths) / 12), ((m_Month + a_cMonths) % 12) + 1, m_Day + 1);
}
/*--------------------------------------------------------------------------*/
inline CDate CDate::addWeeks(const Tsint a_cWeeks) const
{ CALL
  return CDate(getTimeStamp() + a_cWeeks * 7 * 24 * 60 * 60 * 1000);
}
/*--------------------------------------------------------------------------*/
inline CDate CDate::addDays(const Tsint a_cDays) const
{ CALL
  return CDate(getTimeStamp() + a_cDays * 24 * 60 * 60 * 1000);
}
/*--------------------------------------------------------------------------*/
inline Tbool CDate::isLeapYear(const Tsint a_cYear)
{ CALL
  return ((a_cYear & 3) == 0) && (((a_cYear % 100) != 0) || ((a_cYear % 400) == 0));
}
/*--------------------------------------------------------------------------*/
inline CDate CDate::getMin()
{ CALL
  return CDate(CTimeStamp::getMin());
}
/*--------------------------------------------------------------------------*/
inline CDate CDate::getMax()
{ CALL
  return CDate(CTimeStamp::getMax());
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CDate::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTime::CDate")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Year, STR("m_Year")));
    CHECK(a_rArchive.doValue(m_Month, STR("m_Month")));
    CHECK(a_rArchive.doValue(m_Day, STR("m_Day")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CDate::swap(CDate& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Year, a_rInstance.m_Year);
  NAlgorithms::NCommon::swap(m_Month, a_rInstance.m_Month);
  NAlgorithms::NCommon::swap(m_Day, a_rInstance.m_Day);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* INLINE SERIALIZATION FUNCTION IMPLEMENTATIONS                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool load(T_Archive& a_rArchive, NTime::CDate::EWeekDay& a_rInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTime::CDate::EWeekDay")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());

  // Set three boolean state value.
  switch (value)
  {
    case 0:
      a_rInstance = NTime::CDate::e_SUNDAY;
      break;
    case 1:
      a_rInstance = NTime::CDate::e_MONDAY;
      break;
    case 2:
      a_rInstance = NTime::CDate::e_TUESDAY;
      break;
    case 3:
      a_rInstance = NTime::CDate::e_WEDNESDAY;
      break;
    case 4:
      a_rInstance = NTime::CDate::e_THURSDAY;
      break;
    case 5:
      a_rInstance = NTime::CDate::e_FRIDAY;
      break;
    case 6:
      a_rInstance = NTime::CDate::e_SATURDAY;
      break;
    default:
      WARNING(STR("Cannot load invalid week days enumeration value from the archive."));
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool save(T_Archive& a_rArchive, const NTime::CDate::EWeekDay& a_crInstance)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint value;

  // Get three boolean state value.
  switch (a_crInstance)
  {
    case NTime::CDate::e_SUNDAY:
      value = 0;
      break;
    case NTime::CDate::e_MONDAY:
      value = 1;
      break;
    case NTime::CDate::e_TUESDAY:
      value = 2;
      break;
    case NTime::CDate::e_WEDNESDAY:
      value = 3;
      break;
    case NTime::CDate::e_THURSDAY:
      value = 4;
      break;
    case NTime::CDate::e_FRIDAY:
      value = 5;
      break;
    case NTime::CDate::e_SATURDAY:
      value = 6;
      break;
    default:
      WARNING(STR("Cannot save invalid week days enumeration value into the archive."));
      return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTime::CDate::EWeekDay")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(value, STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool serialize(T_Archive& a_rArchive, NTime::CDate::EWeekDay& a_rInstance)
{ CALL
  // Split 'serialize()' free function into 'load()' and 'save()' ones.
  return serializeSplitFunction(a_rArchive, a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
