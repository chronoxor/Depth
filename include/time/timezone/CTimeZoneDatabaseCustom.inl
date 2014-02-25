/*!
 *  \file    CTimeZoneDatabaseCustom.inl Custom time zone database class
 *           provides custom time zone information (rules, history, country
 *           and region names) which can be read form Olson Time Zone Info
 *           database or composed manually.
 *  \brief   Custom time zone database class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Custom time zone database class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time zone
    VERSION:   1.0
    CREATED:   15.12.2010 21:25:53

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
#ifndef __CTIMEZONEDATABASECUSTOM_INL__
#define __CTIMEZONEDATABASECUSTOM_INL__
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
inline CTimeZoneDatabaseCustom::CTimeZoneDatabaseCustom() :
  CTimeZoneDatabase(),
  m_IsValid(false)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTimeZoneDatabaseCustom::CTimeZoneDatabaseCustom(const CTimeZoneDatabaseCustom& a_crInstance) :
  CTimeZoneDatabase(a_crInstance),
  m_IsValid(false)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CTimeZoneDatabaseCustom::~CTimeZoneDatabaseCustom()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
inline CTimeZoneDatabaseCustom& CTimeZoneDatabaseCustom::operator = (const CTimeZoneDatabaseCustom& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTimeZoneDatabaseCustom::isValid() const
{ CALL
  return m_IsValid;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTimeZoneDatabaseCustom::serialize(T_Archive& a_rArchive)
{ CALL
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTime::NTimezone::CTimeZoneDatabaseCustom")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CTimeZoneDatabase&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_ZoneCountryCodes, STR("m_ZoneCountryCodes")));
    CHECK(a_rArchive.doValue(m_ZoneCountryNames, STR("m_ZoneCountryNames")));
    CHECK(a_rArchive.doValue(m_ZoneRegionNames, STR("m_ZoneRegionNames")));
    CHECK(a_rArchive.doValue(m_ZoneNames, STR("m_ZoneNames")));
    CHECK(a_rArchive.doValue(m_ZoneComments, STR("m_ZoneComments")));
    CHECK(a_rArchive.doValue(m_ZoneHistoryFormats, STR("m_ZoneHistoryFormats")));
    CHECK(a_rArchive.doValue(m_ZoneRuleNames, STR("m_ZoneRuleNames")));
    CHECK(a_rArchive.doValue(m_ZoneRuleTypes, STR("m_ZoneRuleTypes")));
    CHECK(a_rArchive.doValue(m_ZoneRuleDayOn, STR("m_ZoneRuleDayOn")));
    CHECK(a_rArchive.doValue(m_ZoneRuleLetters, STR("m_ZoneRuleLetters")));
    CHECK(a_rArchive.doValue(m_ZoneCoordinates, STR("m_ZoneCoordinates")));
    CHECK(a_rArchive.doValue(m_TimeZones, STR("m_TimeZones")));
    CHECK(a_rArchive.doValue(m_TimeZoneHistory, STR("m_TimeZoneHistory")));
    CHECK(a_rArchive.doValue(m_TimeZoneRules, STR("m_TimeZoneRules")));
    CHECK(a_rArchive.doValue(m_TimeZoneRulesDayOn, STR("m_TimeZoneRulesDayOn")));
    CHECK(a_rArchive.doValue(m_IsValid, STR("m_IsValid")));
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
