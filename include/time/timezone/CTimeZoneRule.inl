/*!
 *  \file    CTimeZoneRule.inl Time zone rule class provides the rule
 *           information about the time zone.
 *  \brief   Time zone rule class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time zone rule class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time zone
    VERSION:   1.0
    CREATED:   10.12.2010 20:24:46

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
#ifndef __CTIMEZONERULE_INL__
#define __CTIMEZONERULE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*--------------------------------------------------------------------------*/
namespace NTimezone {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTimeZoneRule::CTimeZoneRule(const CTimeZoneDatabase& a_crTimeZoneDatabase, const NDetails::STimeZoneRule& a_crTimeZoneRuleStructure) :
  m_cpTimeZoneDatabase(&a_crTimeZoneDatabase),
  m_TimeZoneRuleStructure(a_crTimeZoneRuleStructure)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTimeZoneRule::CTimeZoneRule(const CTimeZoneRule& a_crInstance) :
  m_cpTimeZoneDatabase(a_crInstance.m_cpTimeZoneDatabase),
  m_TimeZoneRuleStructure(a_crInstance.m_TimeZoneRuleStructure)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTimeZoneRule::~CTimeZoneRule()
{ CALL
  m_cpTimeZoneDatabase = NULL;
}
/*--------------------------------------------------------------------------*/
inline CTimeZoneRule& CTimeZoneRule::operator = (const CTimeZoneRule& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CTimeZoneRule::set(const CTimeZoneRule& a_crInstance)
{ CALL
  m_cpTimeZoneDatabase = a_crInstance.m_cpTimeZoneDatabase;
  m_TimeZoneRuleStructure = a_crInstance.m_TimeZoneRuleStructure;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTimeZoneRule::isValid() const
{ CALL
  return (m_cpTimeZoneDatabase != NULL) && (m_cpTimeZoneDatabase->isValidTimeZoneRule(m_TimeZoneRuleStructure));
}
/*--------------------------------------------------------------------------*/
inline Tsint CTimeZoneRule::getYearFrom() const
{ CALL
  return m_TimeZoneRuleStructure.m_YearFrom;
}
/*--------------------------------------------------------------------------*/
inline Tsint CTimeZoneRule::getYearTo() const
{ CALL
  return m_TimeZoneRuleStructure.m_YearTo;
}
/*--------------------------------------------------------------------------*/
inline Tuint CTimeZoneRule::getMonthIn() const
{ CALL
  return m_TimeZoneRuleStructure.m_MonthIn;
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CTimeZoneRule::getTimeAt() const
{ CALL
  return CTimeStamp(m_TimeZoneRuleStructure.m_TimeAt);
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CTimeZoneRule::getTimeSave() const
{ CALL
  return CTimeStamp(m_TimeZoneRuleStructure.m_TimeSave);
}
/*--------------------------------------------------------------------------*/
inline Tschar CTimeZoneRule::getTimeSuffix() const
{ CALL
  return (Tschar)m_TimeZoneRuleStructure.m_TimeSuffix;
}
/*--------------------------------------------------------------------------*/
inline const CTimeZoneDatabase& CTimeZoneRule::getDatabase() const
{ CALL
  // Verify the current time zone database to be the valid one.
  VERIFY((m_cpTimeZoneDatabase != NULL), STR("Taking reference to the invalid time zone database value leads to the error."));

  return *m_cpTimeZoneDatabase;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTimeZoneRule::serialize(T_Archive& a_rArchive)
{ CALL
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTime::NTimezone::CTimeZoneRule")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_ID, STR("m_TimeZoneRuleStructure.m_ID")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_RuleNameID, STR("m_TimeZoneRuleStructure.m_RuleNameID")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_YearFrom, STR("m_TimeZoneRuleStructure.m_YearFrom")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_YearTo, STR("m_TimeZoneRuleStructure.m_YearTo")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_RuleTypeID, STR("m_TimeZoneRuleStructure.m_RuleTypeID")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_MonthIn, STR("m_TimeZoneRuleStructure.m_MonthIn")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_DayOnID, STR("m_TimeZoneRuleStructure.m_DayOnID")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_TimeAt, STR("m_TimeZoneRuleStructure.m_TimeAt")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_TimeSave, STR("m_TimeZoneRuleStructure.m_TimeSave")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_TimeSuffix, STR("m_TimeZoneRuleStructure.m_TimeSuffix")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_RuleLettersID, STR("m_TimeZoneRuleStructure.m_RuleLettersID")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_RulePrevID, STR("m_TimeZoneRuleStructure.m_RulePrevID")));
    CHECK(a_rArchive.doValue(m_TimeZoneRuleStructure.m_RuleNextID, STR("m_TimeZoneRuleStructure.m_RuleNextID")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
