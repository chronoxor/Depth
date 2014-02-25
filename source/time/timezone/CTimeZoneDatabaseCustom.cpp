/*!
 *  \file    CTimeZoneDatabaseCustom.cpp Custom time zone database class
 *           provides custom time zone information (rules, history, country
 *           and region names) which can be read form Olson Time Zone Info
 *           database or composed manually.
 *  \brief   Custom time zone database class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Custom time zone database class (source).

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/algorithms/containers/AFind.hpp>
#include <Depth/include/algorithms/functions/FStringComparator.hpp>
#include <Depth/include/algorithms/string/format/AToValue.hpp>
#include <Depth/include/time/timezone/CTimeZoneDatabaseCustom.hpp>
/*==========================================================================*/
#ifndef __CTIMEZONEDATABASECUSTOM_CPP__
#define __CTIMEZONEDATABASECUSTOM_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*--------------------------------------------------------------------------*/
namespace NTimezone {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CTimeZoneDatabaseCustom::set(const CTimeZoneDatabaseCustom& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CTimeZoneDatabaseCustom class instance."))
  {
    return false;
  }

  // Clear custom time zone database.
  if (!clear())
    return false;

  // Initialize base time zone class.
  if (!CTimeZoneDatabase::set(a_crInstance))
    return false;

  // Copy time zone database tables.
  if (!m_ZoneCountryCodes.set(a_crInstance.m_ZoneCountryCodes))
    return false;
  if (!m_ZoneCountryNames.set(a_crInstance.m_ZoneCountryNames))
    return false;
  if (!m_ZoneRegionNames.set(a_crInstance.m_ZoneRegionNames))
    return false;
  if (!m_ZoneNames.set(a_crInstance.m_ZoneNames))
    return false;
  if (!m_ZoneComments.set(a_crInstance.m_ZoneComments))
    return false;
  if (!m_ZoneHistoryFormats.set(a_crInstance.m_ZoneHistoryFormats))
    return false;
  if (!m_ZoneRuleNames.set(a_crInstance.m_ZoneRuleNames))
    return false;
  if (!m_ZoneRuleTypes.set(a_crInstance.m_ZoneRuleTypes))
    return false;
  if (!m_ZoneRuleDayOn.set(a_crInstance.m_ZoneRuleDayOn))
    return false;
  if (!m_ZoneRuleLetters.set(a_crInstance.m_ZoneRuleLetters))
    return false;
  if (!m_ZoneCoordinates.set(a_crInstance.m_ZoneCoordinates))
    return false;
  if (!m_TimeZones.set(a_crInstance.m_TimeZones))
    return false;
  if (!m_TimeZoneHistory.set(a_crInstance.m_TimeZoneHistory))
    return false;
  if (!m_TimeZoneRules.set(a_crInstance.m_TimeZoneRules))
    return false;
  if (!m_TimeZoneRulesDayOn.set(a_crInstance.m_TimeZoneRulesDayOn))
    return false;

  // Copy time zone database valid state.
  m_IsValid = a_crInstance.m_IsValid;

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::clear()
{ CALL
  // Reset time zone database valid state.
  m_IsValid = false;

  // Clear time zone database tables.
  if (!m_ZoneCountryCodes.clear())
    return false;
  if (!m_ZoneCountryNames.clear())
    return false;
  if (!m_ZoneRegionNames.clear())
    return false;
  if (!m_ZoneNames.clear())
    return false;
  if (!m_ZoneComments.clear())
    return false;
  if (!m_ZoneHistoryFormats.clear())
    return false;
  if (!m_ZoneRuleNames.clear())
    return false;
  if (!m_ZoneRuleTypes.clear())
    return false;
  if (!m_ZoneRuleDayOn.clear())
    return false;
  if (!m_ZoneRuleLetters.clear())
    return false;
  if (!m_ZoneCoordinates.clear())
    return false;
  if (!m_TimeZones.clear())
    return false;
  if (!m_TimeZoneHistory.clear())
    return false;
  if (!m_TimeZoneRules.clear())
    return false;
  if (!m_TimeZoneRulesDayOn.clear())
    return false;

  // Clear base time zone class.
  return CTimeZoneDatabase::clear();
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::isValidTimeZone(const NDetails::STimeZone& a_crTimeZoneStructure) const
{ CALL
  // Check time zone ID.
  if ((a_crTimeZoneStructure.m_ID < 0) || ((Tuint)a_crTimeZoneStructure.m_ID >= m_TimeZones.getSize()))
     return false;
  // Check time zone country code.
  if ((a_crTimeZoneStructure.m_CountryCodeID >= 0) && ((Tuint)a_crTimeZoneStructure.m_CountryCodeID >= m_ZoneCountryCodes.getSize()))
     return false;
  // Check time zone country name.
  if ((a_crTimeZoneStructure.m_CountryNameID >= 0) && ((Tuint)a_crTimeZoneStructure.m_CountryNameID >= m_ZoneCountryNames.getSize()))
     return false;
  // Check time zone region name.
  if ((a_crTimeZoneStructure.m_RegionNameID >= 0) && ((Tuint)a_crTimeZoneStructure.m_RegionNameID >= m_ZoneRegionNames.getSize()))
     return false;
  // Check time zone name.
  if ((a_crTimeZoneStructure.m_ZoneNameID >= 0) && ((Tuint)a_crTimeZoneStructure.m_ZoneNameID >= m_ZoneNames.getSize()))
     return false;
  // Check time zone comments.
  if ((a_crTimeZoneStructure.m_ZoneCommentsID >= 0) && ((Tuint)a_crTimeZoneStructure.m_ZoneCommentsID >= m_ZoneComments.getSize()))
     return false;
  // Check time zone coordinates.
  if ((a_crTimeZoneStructure.m_ZoneCoordinatesID >= 0) && ((Tuint)a_crTimeZoneStructure.m_ZoneCoordinatesID >= m_ZoneCoordinates.getSize()))
     return false;
  // Check time zone history.
  if ((a_crTimeZoneStructure.m_ZoneHistoryID >= 0) && ((Tuint)a_crTimeZoneStructure.m_ZoneHistoryID >= m_TimeZoneHistory.getSize()))
     return false;

  // Everything is ok.
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::isValidTimeZoneHistory(const NDetails::STimeZoneHistory& a_crTimeZoneHistoryStructure) const
{ CALL
  // Check time zone history ID.
  if ((a_crTimeZoneHistoryStructure.m_ID < 0) || ((Tuint)a_crTimeZoneHistoryStructure.m_ID >= m_TimeZoneHistory.getSize()))
     return false;
  // Check time zone history rule.
  if ((a_crTimeZoneHistoryStructure.m_RuleID >= 0) && ((Tuint)a_crTimeZoneHistoryStructure.m_RuleID >= m_TimeZoneRules.getSize()))
     return false;
  // Check time zone history format.
  if ((a_crTimeZoneHistoryStructure.m_FormatID >= 0) && ((Tuint)a_crTimeZoneHistoryStructure.m_FormatID >= m_ZoneHistoryFormats.getSize()))
     return false;
  // Check time zone previous history.
  if ((a_crTimeZoneHistoryStructure.m_HistoryPrevID >= 0) && ((Tuint)a_crTimeZoneHistoryStructure.m_HistoryPrevID >= m_TimeZoneHistory.getSize()))
     return false;
  // Check time zone next history.
  if ((a_crTimeZoneHistoryStructure.m_HistoryNextID >= 0) && ((Tuint)a_crTimeZoneHistoryStructure.m_HistoryNextID >= m_TimeZoneHistory.getSize()))
     return false;

  // Everything is ok.
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::isValidTimeZoneRule(const NDetails::STimeZoneRule& a_crTimeZoneRuleStructure) const
{ CALL
  // Check time zone rule ID.
  if ((a_crTimeZoneRuleStructure.m_ID < 0) || ((Tuint)a_crTimeZoneRuleStructure.m_ID >= m_TimeZoneRules.getSize()))
     return false;
  // Check time zone rule name.
  if ((a_crTimeZoneRuleStructure.m_RuleNameID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_RuleNameID >= m_ZoneRuleNames.getSize()))
     return false;
  // Check time zone rule type.
  if ((a_crTimeZoneRuleStructure.m_RuleTypeID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_RuleTypeID >= m_ZoneRuleTypes.getSize()))
     return false;
  // Check time zone rule in month value.
  if ((a_crTimeZoneRuleStructure.m_MonthIn < 1) || (a_crTimeZoneRuleStructure.m_MonthIn > 12))
     return false;
  // Check time zone rule on day value.
  if ((a_crTimeZoneRuleStructure.m_DayOnID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_DayOnID >= m_ZoneRuleDayOn.getSize()) && ((Tuint)a_crTimeZoneRuleStructure.m_DayOnID >= m_TimeZoneRulesDayOn.getSize()))
     return false;
  // Check time zone rule letters.
  if ((a_crTimeZoneRuleStructure.m_RuleLettersID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_RuleLettersID >= m_ZoneRuleLetters.getSize()))
     return false;
  // Check time zone previous rule.
  if ((a_crTimeZoneRuleStructure.m_RulePrevID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_RulePrevID >= m_TimeZoneRules.getSize()))
     return false;
  // Check time zone next rule.
  if ((a_crTimeZoneRuleStructure.m_RuleNextID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_RuleNextID >= m_TimeZoneRules.getSize()))
     return false;

  // Everything is ok.
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::isValidTimeZoneRuleDayOn(const NDetails::STimeZoneRuleDayOn& a_crTimeZoneRuleDayOnStructure) const
{ CALL
  // Check time zone rule day on ID.
  if ((a_crTimeZoneRuleDayOnStructure.m_ID < 0) || ((Tuint)a_crTimeZoneRuleDayOnStructure.m_ID >= m_TimeZoneRulesDayOn.getSize()))
     return false;
  // Check time zone rule day on last flag.
  if (a_crTimeZoneRuleDayOnStructure.m_LastFlag > 1)
     return false;
  // Check time zone rule day on week day flag.
  if (a_crTimeZoneRuleDayOnStructure.m_WeekDayFlag > 1)
     return false;
  // Check time zone rule day on week day value.
  if ((a_crTimeZoneRuleDayOnStructure.m_WeekDayFlag == 1) && ((a_crTimeZoneRuleDayOnStructure.m_WeekDay < 0) || (a_crTimeZoneRuleDayOnStructure.m_WeekDay > 6)))
     return false;
  // Check time zone rule day on value.
  if ((a_crTimeZoneRuleDayOnStructure.m_Day < 1) || (a_crTimeZoneRuleDayOnStructure.m_Day > 31))
     return false;

  // Everything is ok.
  return true;
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabaseCustom::getZoneCountryCodeByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_ZoneCountryCodes.getSize()), STR("Cannot get custom time zone country code with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_ZoneCountryCodes.getSize())
  {
    return ASC("");
  }

  return m_ZoneCountryCodes[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabaseCustom::getZoneCountryNameByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_ZoneCountryNames.getSize()), STR("Cannot get custom time zone country name with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_ZoneCountryNames.getSize())
  {
    return ASC("");
  }

  return m_ZoneCountryNames[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabaseCustom::getZoneRegionNameByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_ZoneRegionNames.getSize()), STR("Cannot get custom time zone region name with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_ZoneRegionNames.getSize())
  {
    return ASC("");
  }

  return m_ZoneRegionNames[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabaseCustom::getZoneNameByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_ZoneNames.getSize()), STR("Cannot get custom time zone name with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_ZoneNames.getSize())
  {
    return ASC("");
  }

  return m_ZoneNames[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabaseCustom::getZoneCommentsByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_ZoneComments.getSize()), STR("Cannot get custom time zone comments with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_ZoneComments.getSize())
  {
    return ASC("");
  }

  return m_ZoneComments[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabaseCustom::getZoneHistoryFormatByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneHistoryFormats()), STR("Cannot get custom time zone history format with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneHistoryFormats())
  {
    return ASC("");
  }

  return NDetails::the_ZoneHistoryFormats[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabaseCustom::getZoneRuleNameByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_ZoneRuleNames.getSize()), STR("Cannot get custom time zone rule name with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_ZoneRuleNames.getSize())
  {
    return ASC("");
  }

  return m_ZoneRuleNames[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabaseCustom::getZoneRuleTypeByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_ZoneRuleTypes.getSize()), STR("Cannot get custom time zone rule type with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_ZoneRuleTypes.getSize())
  {
    return ASC("");
  }

  return m_ZoneRuleTypes[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabaseCustom::getZoneRuleDayOnByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_ZoneRuleDayOn.getSize()), STR("Cannot get custom time zone rule day on with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_ZoneRuleDayOn.getSize())
  {
    return ASC("");
  }

  return m_ZoneRuleDayOn[a_cID];
}
/*--------------------------------------------------------------------------*/
NDetails::STimeZoneRuleDayOn CTimeZoneDatabaseCustom::getZoneRuleDayOnStructureByID(const Tuint a_cID) const
{
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_TimeZoneRulesDayOn.getSize()), STR("Cannot get custom time zone rule day on structure with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_TimeZoneRulesDayOn.getSize())
  {
    return NDetails::STimeZoneRuleDayOn::INVALID;
  }

  return m_TimeZoneRulesDayOn[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabaseCustom::getZoneRuleLettersByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_ZoneRuleLetters.getSize()), STR("Cannot get custom time zone rule letters with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_ZoneRuleLetters.getSize())
  {
    return ASC("");
  }

  return m_ZoneRuleLetters[a_cID];
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Treal, Treal> CTimeZoneDatabaseCustom::getZoneCoordinateByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < (m_ZoneCoordinates.getSize() >> 1)), STR("Cannot get custom time zone coordinates with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA (m_ZoneCoordinates.getSize() >> 1))
  {
    return NUtility::CPair<Treal, Treal>(0.0, 0.0);
  }

  return NUtility::CPair<Treal, Treal>((Treal)m_ZoneCoordinates[(a_cID << 1) + 0], (Treal)m_ZoneCoordinates[(a_cID << 1) + 1]);
}
/*--------------------------------------------------------------------------*/
CTimeZone CTimeZoneDatabaseCustom::getZoneByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_TimeZones.getSize()), STR("Cannot get custom time zone with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_TimeZones.getSize())
  {
    return CTimeZone(*this);
  }

  return CTimeZone(*this, m_TimeZones[a_cID]);
}
/*--------------------------------------------------------------------------*/
CTimeZoneHistory CTimeZoneDatabaseCustom::getZoneHistoryByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_TimeZoneHistory.getSize()), STR("Cannot get custom time zone history with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_TimeZoneHistory.getSize())
  {
    return CTimeZoneHistory(*this);
  }

  return CTimeZoneHistory(*this, m_TimeZoneHistory[a_cID]);
}
/*--------------------------------------------------------------------------*/
CTimeZoneRule CTimeZoneDatabaseCustom::getZoneRuleByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < m_TimeZoneRules.getSize()), STR("Cannot get custom time zone rule with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA m_TimeZoneRules.getSize())
  {
    return CTimeZoneRule(*this);
  }

  return CTimeZoneRule(*this, m_TimeZoneRules[a_cID]);
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseTimeZoneInfoDatabase(NStream::IReader& a_rReader)
{ CALL
  // Check if the given reader is opened.
  ASSERT(a_rReader.isOpened(), STR("Cannot parse the Olson Time Zone Info database from the closed reader."))
  {
    return false;
  }

  // Cache Time Zone values.
  Tsint cache_rule_id = -1;
  Tsint cache_history_id = -1;
  Tsint cache_zone_id = -1;

  // Iterate through all tokens.
  NString::CString line;
  NString::CString token;
  while (!a_rReader.isEOF() && a_rReader.read(line).getFirst())
  {
    // Get the first token.
    if (!parseNextToken(line, token))
      continue;

    // Try to parse Time Zone Rule.
    if (NString::CString::compareIgnoreCase(token, STR("Rule")) == 0)
    {
      // Reset cache.
      cache_history_id = -1;
      cache_zone_id = -1;

      // Create a new Time Zone Rule.
      NDetails::STimeZoneRule rule = NDetails::STimeZoneRule::INVALID;
      rule.m_ID = (Tsint16)m_TimeZoneRules.getSize();
      rule.m_RulePrevID = (Tsint16)cache_rule_id;
      rule.m_RuleNextID = -1;

      // Get the Time Zone Rule Name token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the Time Zone Rule Name token.
      if (!parseStringTableValue(token, m_ZoneRuleNames, rule.m_RuleNameID))
        return false;

      // Get the Time Zone Rule Year From token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the Time Zone Rule Year From token.
      if (!parseYearValue(token, rule.m_YearFrom))
        return false;

      // Get the Time Zone Rule Year To token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the Time Zone Rule Year To token.
      if (!parseYearValue(token, rule.m_YearTo, rule.m_YearFrom))
        return false;

      // Get the Time Zone Rule Type token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the Time Zone Rule Type token.
      if (NString::CString::compareIgnoreCase(token, STR("-")) == 0)
        if (!token.clear())
          return false;
      if (!parseStringTableValue(token, m_ZoneRuleTypes, rule.m_RuleTypeID))
        return false;

      // Get the Time Zone Rule Month In token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the Time Zone Rule Month In token.
      if (!parseMonthValue(token, rule.m_MonthIn))
        return false;

      // Get the Time Zone Rule Day On token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the Time Zone Rule Day On token.
      if (!parseStringTableValue(token, m_ZoneRuleDayOn, rule.m_DayOnID))
        return false;

      // Parse the Time Zone Rule Day On value.
      if (!parseDayOnValue(token, m_TimeZoneRulesDayOn, rule.m_DayOnID))
        return false;

      // Get the Time Zone Rule Time At token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the Time Zone Rule Time At token.
      if (!parseTimeStampValue(token, rule.m_TimeAt, rule.m_TimeSuffix))
        return false;

      // Get the Time Zone Rule Time Save token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the Time Zone Rule Time Save token.
      Tuint08 temp;
      if (!parseTimeStampValue(token, rule.m_TimeSave, temp))
        return false;

      // Get the Time Zone Rule Letters token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the Time Zone Rule Letters token.
      if (NString::CString::compareIgnoreCase(token, STR("-")) == 0)
        if (!token.clear())
          return false;
      if (!parseStringTableValue(token, m_ZoneRuleLetters, rule.m_RuleLettersID))
        return false;

      // Add the Time Zone Rule to the collection.
      if (!m_TimeZoneRules.insertLast(rule))
        return false;
      else
        cache_rule_id = m_TimeZoneRules.getSize() - 1;

      // Link the Time Zone Rule with previous ones.
      if (rule.m_RulePrevID >= 0)
        m_TimeZoneRules[(Tuint)rule.m_RulePrevID].m_RuleNextID = (Tsint16)cache_rule_id;
    }
    // Try to parse the Time Zone Link.
    else if (NString::CString::compareIgnoreCase(token, STR("Link")) == 0)
    {
      // Reset cache.
      cache_rule_id = -1;
      cache_history_id = -1;
      cache_zone_id = -1;

      // Get the source Time Zone token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the source Time Zone.
      Tsint16 source_zone_id = -1;
      for (Tuint i = 0; i < m_TimeZones.getSize(); ++i)
        if ((m_TimeZones[i].m_ZoneNameID >= 0) && (NString::CString::compareIgnoreCase(token, m_ZoneNames[(Tuint)m_TimeZones[i].m_ZoneNameID]) == 0))
        {
          source_zone_id = (Tsint16)i;
          break;
        }

      // Check the source Time Zone.
      ASSERT((source_zone_id >= 0), STR("Cannot find the link source Time Zone (required Time Zone name \"%X\").") COMMA &token) return false;

      // Get the destination Time Zone token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Check the destination Time Zone.
      ASSERT(!token.isEmpty(), STR("The link destination Time Zone name is empty.")) return false;

      // Parse the destination Time Zone Name.
      Tsint16 destination_zone_name_id = -1;
      if (!parseStringTableValue(token, m_ZoneNames, destination_zone_name_id))
        return false;

      // Parse the destination Time Zone Region Name.
      Tsint16 destination_region_name_id = -1;
      if (!parseRegionNameValue(token, m_ZoneRegionNames, destination_region_name_id))
        return false;

      // Create a new Time Zone.
      NDetails::STimeZone destination_zone = m_TimeZones[(Tuint)source_zone_id];
      destination_zone.m_ID = (Tuint16)m_TimeZones.getSize();
      destination_zone.m_RegionNameID = destination_region_name_id;
      destination_zone.m_ZoneNameID = destination_zone_name_id;

      // Add the destination Time Zone to the collection.
      if (!m_TimeZones.insertLast(destination_zone))
        return false;
      else
        cache_zone_id = m_TimeZones.getSize() - 1;
    }
    // Try to parse the Time Zone.
    else
    {
      // Reset cache.
      cache_rule_id = -1;

      // Create a new Time Zone History.
      NDetails::STimeZoneHistory history = NDetails::STimeZoneHistory::INVALID;
      history.m_ID = (Tsint32)m_TimeZoneHistory.getSize();
      history.m_RuleID = -1;
      history.m_FormatID = -1;
      history.m_Until = NConstants::CConstants::sint64Max;
      history.m_HistoryPrevID = (Tsint16)cache_history_id;
      history.m_HistoryNextID = -1;
      history.m_Padding = 0;

      // Parse the Time Zone information.
      if (NString::CString::compareIgnoreCase(token, STR("Zone")) == 0)
      {
        // Reset cache.
        cache_history_id = -1;
        cache_zone_id = -1;

        // Create a new Time Zone.
        NDetails::STimeZone zone = NDetails::STimeZone::INVALID;
        zone.m_ID = (Tuint16)m_TimeZones.getSize();
        zone.m_CountryCodeID = -1;
        zone.m_CountryNameID = -1;
        zone.m_RegionNameID = -1;
        zone.m_ZoneCommentsID = -1;
        zone.m_ZoneCoordinatesID = -1;
        zone.m_ZoneHistoryID = (Tsint16)m_TimeZoneHistory.getSize();

        // Get the Time Zone Name token.
        ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

        // Parse the Time Zone Name.
        if (!parseStringTableValue(token, m_ZoneNames, zone.m_ZoneNameID))
          return false;

        // Parse the Time Zone Region Name.
        if (!parseRegionNameValue(token, m_ZoneRegionNames, zone.m_RegionNameID))
          return false;

        // Add the Time Zone to the collection.
        if (!m_TimeZones.insertLast(zone))
          return false;
        else
          cache_zone_id = m_TimeZones.getSize() - 1;

        // Get the Time Zone History GMT Offset token.
        ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;
      }

      // Parse the Time Zone History GMT Offset token.
      Tuint08 temp;
      if (!parseTimeStampValue(token, history.m_GMTOffset, temp))
        return false;

      // Get the Time Zone History Rules token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the Time Zone History Rules token.
      if (NString::CString::compareIgnoreCase(token, STR("-")) != 0)
        for (Tuint i = 0; i < m_TimeZoneRules.getSize(); ++i)
          if ((m_TimeZoneRules[i].m_RuleNameID >= 0) && (NString::CString::compareIgnoreCase(token, m_ZoneRuleNames[(Tuint)m_TimeZoneRules[i].m_RuleNameID]) == 0))
          {
            history.m_RuleID = (Tsint16)i;
            break;
          }

      // Get the Time Zone History Format token.
      ASSERT(parseNextToken(line, token), STR("Cannot get the next token (previous token is \"%X\").") COMMA &token) return false;

      // Parse the Time Zone History Format token.
      if (!parseStringTableValue(token, m_ZoneHistoryFormats, history.m_FormatID))
        return false;

      // Get the Time Zone History Until token.
      if (parseNextToken(line, token))
      {
        Tsint32 year = 0;
        Tuint08 month = 0;
        Tuint08 day = 0;
        Tsint64 time = 0;

        // Parse the year value.
        if (!parseYearValue(token, year))
          return false;

        if (parseNextToken(line, token))
        {
          // Parse the month value.
          if (!parseMonthValue(token, month))
            return false;

          if (parseNextToken(line, token))
          {
            // Parse the day value.
            if (!parseDayValue(token, day, month, year))
              return false;

            if (parseNextToken(line, token))
            {
              // Parse the time stamp value.
              Tuint08 temp;
              if (!parseTimeStampValue(token, time, temp))
                return false;
            }
          }
        }

        // Update the Time Zone History Until value.
        CTimeStamp timestamp(time);
        history.m_Until = CDateTime(year, month, day, timestamp.getClearHours(), timestamp.getClearMinutes(), timestamp.getClearSeconds(), timestamp.getClearMilliseconds()).getTimeStamp().getTotalMilliseconds();
      }

      // Add the Time Zone History to the collection.
      if (!m_TimeZoneHistory.insertLast(history))
        return false;
      else
        cache_history_id = m_TimeZoneHistory.getSize() - 1;

      // Link the Time Zone History with previous ones.
      if (history.m_HistoryPrevID >= 0)
        m_TimeZoneHistory[(Tuint)history.m_HistoryPrevID].m_HistoryNextID = (Tsint16)cache_history_id;
    }
  }

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseTimeZoneCountryNamesDatabase(NStream::IReader& a_rReader)
{ CALL
  // Check if the given reader is opened.
  ASSERT(a_rReader.isOpened(), STR("Cannot parse the Olson Time Zone Country Names database from the closed reader."))
  {
    return false;
  }

  // Iterate through all tokens.
  NString::CString line;
  NString::CString token1;
  NString::CString token2;
  while (!a_rReader.isEOF() && a_rReader.read(line).getFirst())
  {
    // Get the Time Zone Country Code.
    if (!parseNextToken(line, token1))
      continue;

    // Get the Time Zone Country Name token.
    ASSERT(parseNextToken(line, token2, true), STR("Cannot get the token for the Time Zone Country Name (Time Zone Country Code is \"%X\").") COMMA &token1) return false;

    // Parse the Time Zone Country Code token.
    Tsint16 county_code_id = -1;
    if (!parseStringTableValue(token1, m_ZoneCountryCodes, county_code_id))
      return false;

    // Parse the Time Zone Country Name token.
    Tsint16 county_name_id = -1;
    if (!parseStringTableValue(token2, m_ZoneCountryNames, county_name_id))
      return false;

    // Update the Time Zone information.
    if ((county_code_id >= 0) && (county_name_id >= 0))
      for (Tuint i = 0; i < m_TimeZones.getSize(); ++i)
        if (m_TimeZones[i].m_CountryCodeID == county_code_id)
          m_TimeZones[i].m_CountryNameID = county_name_id;
  }

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseTimeZoneDescriptionsDatabase(NStream::IReader& a_rReader)
{ CALL
  // Check if the given reader is opened.
  ASSERT(a_rReader.isOpened(), STR("Cannot parse the Olson Time Zone Descriptions database from the closed reader."))
  {
    return false;
  }

  // Iterate through all tokens.
  NString::CString line;
  NString::CString token1;
  NString::CString token2;
  NString::CString token3;
  NString::CString token4;
  while (!a_rReader.isEOF() && a_rReader.read(line).getFirst())
  {
    // Get the Time Zone Country Code.
    if (!parseNextToken(line, token1))
      continue;

    // Get the Time Zone Coordinates token.
    ASSERT(parseNextToken(line, token2), STR("Cannot get the token for the Time Zone Coordinates (Time Zone Country Code is \"%X\").") COMMA &token1) return false;

    // Get the Time Zone Name token.
    ASSERT(parseNextToken(line, token3), STR("Cannot get the token for the Time Zone Name (Time Zone Country Code is \"%X\").") COMMA &token1) return false;

    // Get the Time Zone Comments token.
    parseNextToken(line, token4, true);

    // Find the required Time Zone.
    Tbool found = false;
    for (Tuint i = 0; i < m_TimeZones.getSize(); ++i)
    {
      if ((m_TimeZones[i].m_ZoneNameID >= 0) && (NString::CString::compareIgnoreCase(token3, m_ZoneNames[(Tuint)m_TimeZones[i].m_ZoneNameID]) == 0))
      {
        // Parse the Time Zone Country Code token.
        if (!parseStringTableValue(token1, m_ZoneCountryCodes, m_TimeZones[i].m_CountryCodeID))
          return false;

        // Parse the Time Zone Coordinates token.
        Tdouble latitude = 0.0;
        Tdouble longitude = 0.0;
        switch (token2.getSize())
        {
          // +-DDMM+-DDDMM format, first latitude (+ is north), then longitude (+ is east).
          case 11:
          {
            // Parse latitude.
            if (!parseCoordinateValue(token2.getLeft(5), latitude))
              return false;

            // Parse longitude.
            if (!parseCoordinateValue(token2.getRight(6), longitude))
              return false;
            break;
          }
          // +-DDMMSS+-DDDMMSS format, first latitude (+ is north), then longitude (+ is east).
          case 15:
          {
            // Parse latitude.
            if (!parseCoordinateValue(token2.getLeft(7), latitude))
              return false;

            // Parse longitude.
            if (!parseCoordinateValue(token2.getRight(8), longitude))
              return false;
            break;
          }
          default:
          {
            WARNING(STR("Cannot parse the Time Zone Coordinates (Time Zone Coordinates is \"%X\").") COMMA &token2);
            return false;
          }
        }

        // Add the Time Zone Coordinates to the collection.
        if (!m_ZoneCoordinates.insertLast(latitude) || !m_ZoneCoordinates.insertLast(longitude))
          return false;
        else
          m_TimeZones[i].m_ZoneCoordinatesID = (Tsint16)((m_ZoneCoordinates.getSize() >> 1) - 1);

        // Parse the Time Zone Comments token.
        if (!token4.isEmpty() && !parseStringTableValue(token4, m_ZoneComments, m_TimeZones[i].m_ZoneCommentsID))
          return false;

        found = true;
        break;
      }
    }

    if (!found)
    {
      WARNING(STR("Cannot find the required Time Zone (Time Zone Name is \"%X\").") COMMA &token3);
      return false;
    }
  }

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::checkTimeZoneInfoDatabase() const
{ CALL
  // Check all Time Zones.
  for (Tuint i = 0; i < m_TimeZones.getSize(); ++i)
  {
    NDetails::STimeZone zone = m_TimeZones[i];
    ASSERT((zone.m_ID == (Tsint16)i), STR("Time Zone ID is invalid (ID = %u).") COMMA i);
    ASSERT((zone.m_ZoneNameID >= 0), STR("Time Zone name is invalid (ID = %u).") COMMA i);
    ASSERT((zone.m_ZoneHistoryID >= 0), STR("Time Zone history is invalid (ID = %u).") COMMA i);

    // Check Time Zone History.
    Tsint history_id = zone.m_ZoneHistoryID;
    while (history_id >= 0)
    {
      NDetails::STimeZoneHistory history = m_TimeZoneHistory[history_id];

      // Check Time Zone Rules.
      Tsint rule_id = history.m_RuleID;
      while (rule_id >= 0)
      {
        NDetails::STimeZoneRule rule = m_TimeZoneRules[rule_id];

        ASSERT((rule.m_RuleNameID >= 0), STR("Time Zone Rule name is invalid (ID = %u).") COMMA rule_id);
        ASSERT((rule.m_DayOnID >= 0), STR("Time Zone Rule day on is invalid (ID = %u).") COMMA rule_id);

        // Switch to the next rule.
        rule_id = rule.m_RuleNextID;
      }

      ASSERT((history.m_FormatID >= 0), STR("Time Zone History format is invalid (ID = %u).") COMMA history_id);

      // Switch to the next history.
      history_id = history.m_HistoryNextID;
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseNextToken(NString::CString& a_rSourceString, NString::CString& a_rTokenString, const Tbool a_cAcceptSpaces/* = false */)
{ CALL
  // Clear result token string.
  if (!a_rTokenString.clear())
    return false;

  // Iterate through the source string.
  Tbool result = false;
  Tuint count = 0;
  Tuint size = a_rSourceString.getSize();
  for (Tuint i = 0; i < size; ++i)
  {
    Tchar c = a_rSourceString[i];

    // Increment count of parsed characters.
    ++count;

    // If we met a comments stop parsing.
    if (c == STR('#'))
      break;
    // If we met a space or tabulation stop parsing only if token is parsed.
    else if ((c == STR('\t')) || (!a_cAcceptSpaces && (c == STR(' '))))
    {
      if (result)
        break;
      else
        continue;
    }
    else
    {
      // Parse token.
      result = true;
      if (!a_rTokenString.insertLast(c))
        return false;
    }
  }

  // Remove the token from the source string.
  if (result && !a_rSourceString.removeFirst(count))
    return false;

  return result;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseStringTableValue(const NString::CString& a_crSourceString, NContainers::CStringBuffer<Tsstr>& a_rStringTable, Tsint16& a_rID)
{ CALL
  NString::CStringASCII value(a_crSourceString);
  if (value.insertCEnd())
  {
    NContainers::CStringBuffer<Tsstr>::TIterator it_value = NAlgorithms::NContainers::find(a_rStringTable, a_crSourceString, NAlgorithms::NFunctions::FStringComparator<Tsstr, NString::CStringASCII>());
    if (it_value.isValid())
    {
      a_rID = (Tsint16)it_value.getPosition();
      return true;
    }
    else
    {
      if (a_rStringTable.insertLast(value))
      {
        a_rID = (Tsint16)(a_rStringTable.getSize() - 1);
        return true;
      }
    }
  }
  WARNING(STR("Cannot parse string table token (\"%X\").") COMMA &a_crSourceString);
  return false;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseRegionNameValue(const NString::CString& a_crSourceString, NContainers::CStringBuffer<Tsstr>& a_rStringTable, Tsint16& a_rID)
{ CALL
  Tbool region_found = false;
  NString::CStringASCII zone_region_name;
  for (Tuint i = 0; i < a_crSourceString.getSize(); ++i)
  {
    if (a_crSourceString[i] == ASC('/'))
    {
      region_found = true;
      break;
    }
    else
    {
      if (!zone_region_name.insertLast(a_crSourceString[i]))
        return false;
    }
  }
  if (region_found && !parseStringTableValue(zone_region_name, a_rStringTable, a_rID))
    return false;
  else
    return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseYearValue(const NString::CString& a_crSourceString, Tsint32& a_rYear, const Tsint32 a_cOnlyYear/* = 0 */)
{ CALL
  if (NString::CString::compareIgnoreCase(a_crSourceString, STR("min")) == 0)
    a_rYear = NConstants::CConstants::sint32Min;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("max")) == 0)
    a_rYear = NConstants::CConstants::sint32Max;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("only")) == 0)
    a_rYear = a_cOnlyYear;
  else
  {
    // Check year token.
    for (Tuint i = 0; i < a_crSourceString.getSize(); ++i)
    {
      Tschar c = a_crSourceString[i];
      if ((c < STR('0')) || (c > STR('9')))
      {
        WARNING(STR("Cannot parse year token (\"%X\").") COMMA &a_crSourceString);
        return false;
      }
    }
    a_rYear = (Tsint32)NAlgorithms::NString::NFormat::toSigned(a_crSourceString);
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseMonthValue(const NString::CString& a_crSourceString, Tuint08& a_rMonth)
{ CALL
  if (NString::CString::compareIgnoreCase(a_crSourceString, STR("Jan")) == 0)
    a_rMonth = 1;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("Feb")) == 0)
    a_rMonth = 2;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("Mar")) == 0)
    a_rMonth = 3;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("Apr")) == 0)
    a_rMonth = 4;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("May")) == 0)
    a_rMonth = 5;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("Jun")) == 0)
    a_rMonth = 6;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("Jul")) == 0)
    a_rMonth = 7;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("Aug")) == 0)
    a_rMonth = 8;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("Sep")) == 0)
    a_rMonth = 9;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("Oct")) == 0)
    a_rMonth = 10;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("Nov")) == 0)
    a_rMonth = 11;
  else if (NString::CString::compareIgnoreCase(a_crSourceString, STR("Dec")) == 0)
    a_rMonth = 12;
  else
  {
    WARNING(STR("Cannot parse month token (\"%X\").") COMMA &a_crSourceString);
    return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseDayValue(const NString::CString& a_crSourceString, Tuint08& a_rDay)
{ CALL
  // Check day token.
  for (Tuint i = 0; i < a_crSourceString.getSize(); ++i)
  {
    Tschar c = a_crSourceString[i];
    if ((c < STR('0')) || (c > STR('9')))
    {
      WARNING(STR("Cannot parse day token (\"%X\").") COMMA &a_crSourceString);
      return false;
    }
  }
  a_rDay = (Tuint08)NAlgorithms::NString::NFormat::toUnsigned(a_crSourceString);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseDayValue(const NString::CString& a_crSourceString, Tuint08& a_rDay, Tuint08& a_rMonth, Tsint32& a_rYear)
{ CALL
  // Get time zone day on structure from the given token.
  NDetails::STimeZoneRuleDayOn day_on_structure(convertToDayOnStructure(a_crSourceString));
  if (day_on_structure == NDetails::STimeZoneRuleDayOn::INVALID)
    return false;

  CDate result(convertToDate(a_rYear, a_rMonth, day_on_structure));
  a_rYear = (Tsint32)result.getYear();
  a_rMonth = (Tuint08)result.getMonth();
  a_rDay = (Tuint08)result.getDay();
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseDayOnValue(const NString::CString& a_crSourceString, NContainers::CArray<NDetails::STimeZoneRuleDayOn>& a_rDayOnTable, Tsint16& a_rID)
{ CALL
  // Get time zone day on structure from the given token.
  NDetails::STimeZoneRuleDayOn day_on_structure(convertToDayOnStructure(a_crSourceString));
  if (day_on_structure == NDetails::STimeZoneRuleDayOn::INVALID)
    return false;

  NContainers::CArray<NDetails::STimeZoneRuleDayOn>::TIterator it_value = NAlgorithms::NContainers::find(a_rDayOnTable, day_on_structure);
  if (it_value.isValid())
  {
    a_rID = (Tsint16)it_value.getPosition();
    return true;
  }
  else
  {
    day_on_structure.m_ID = (Tsint08)a_rDayOnTable.getSize();
    if (a_rDayOnTable.insertLast(day_on_structure))
    {
      a_rID = (Tsint16)(a_rDayOnTable.getSize() - 1);
      return true;
    }
    else
      return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseTimeStampValue(const NString::CString& a_crSourceString, Tsint64& a_rTimeStamp, Tuint08& a_rTimeSuffix)
{ CALL
  NString::CString source_first;
  NString::CString source_second;
  NString::CString source_third;
  NString::CString source(a_crSourceString);

  Tuint length = source.getSize();

  // Parse time sign.
  Tbool minus = false;
  if ((length > 0) && ((source[CONSTU(0)] == STR('+')) || (source[CONSTU(0)] == STR('-'))))
  {
    minus = (source[CONSTU(0)] == STR('-'));
    if (source.removeFirst())
      --length;
    else
      return false;
  }

  // Parse time suffix.
  a_rTimeSuffix = 0;
  if ((length > 0) && ((source[length - 1] == STR('s')) || (source[length - 1] == STR('u'))))
  {
    a_rTimeSuffix = (Tuint08)source[length - 1];
    if (source.removeLast())
      --length;
    else
      return false;
  }

  // Parse time seconds.
  if (length > 0)
  {
    Tuint mode = 0;
    Tbool error = false;
    for (Tuint i = length; i > 0; --i)
    {
      Tschar c = source[i - 1];
      if (c == STR(':'))
      {
        if (mode < 2)
        {
          ++mode;
          continue;
        }
        else
        {
          error = true;
          break;
        }
      }
      else if ((c < STR('0')) || (c > STR('9')))
      {
        error = true;
        break;
      }
      else
      {
        switch (mode)
        {
          case 0:
          {
            if (!source_first.insertFirst(c))
              return false;
            break;
          }
          case 1:
          {
            if (!source_second.insertFirst(c))
              return false;
            break;
          }
          case 2:
          {
            if (!source_third.insertFirst(c))
              return false;
            break;
          }
        }
      }
    }
    if (error)
    {
      WARNING(STR("Cannot parse time stamp value from the given string (\"%X\").") COMMA &a_crSourceString);
      return false;
    }

    // Get valid hours, minutes and seconds values.
    Tsint hou = 0;
    Tsint min = 0;
    Tsint sec = 0;
    switch (mode)
    {
      case 0:
      {
        hou = NAlgorithms::NString::NFormat::toSigned(source_first) * (minus ? -1 : 1);
        break;
      }
      case 1:
      {
        hou = NAlgorithms::NString::NFormat::toSigned(source_second) * (minus ? -1 : 1);
        min = NAlgorithms::NString::NFormat::toSigned(source_first) * (minus ? -1 : 1);
        break;
      }
      case 2:
      {
        hou = NAlgorithms::NString::NFormat::toSigned(source_third) * (minus ? -1 : 1);
        min = NAlgorithms::NString::NFormat::toSigned(source_second) * (minus ? -1 : 1);
        sec = NAlgorithms::NString::NFormat::toSigned(source_first) * (minus ? -1 : 1);
        break;
      }
    }

    // Return result time stamp value.
    a_rTimeStamp = CTimeStamp(0, sec, min, hou).getTotalMilliseconds();
    return true;
  }

  return false;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabaseCustom::parseCoordinateValue(const NString::CString& a_crSourceString, Tdouble& a_rCoordinate)
{ CALL
  NString::CString source(a_crSourceString);

  Tuint length = source.getSize();

  // Parse coordinate sign.
  Tbool minus = false;
  if ((length > 0) && ((source[CONSTU(0)] == STR('+')) || (source[CONSTU(0)] == STR('-'))))
  {
    minus = (source[CONSTU(0)] == STR('-'));
    if (source.removeFirst())
      --length;
    else
      return false;
  }
  else
  {
    WARNING(STR("Cannot parse coordinate token (\"%X\").") COMMA &a_crSourceString);
    return false;
  }

  // Check coordinate token.
  for (Tuint i = 0; i < length; ++i)
  {
    Tschar c = source[i];
    if ((c < STR('0')) || (c > STR('9')))
    {
      WARNING(STR("Cannot parse coordinate token (\"%X\").") COMMA &a_crSourceString);
      return false;
    }
  }

  // Parse coordinate token.
  Tdouble degrees = 0.0;
  Tdouble minutes = 0.0;
  Tdouble seconds = 0.0;
  switch (length)
  {
    case 4:
    {
      degrees = ((source[CONSTU(0)] - STR('0')) * 10) + (source[CONSTU(1)] - STR('0'));
      minutes = ((source[CONSTU(2)] - STR('0')) * 10) + (source[CONSTU(3)] - STR('0'));
      break;
    }
    case 5:
    {
      degrees = ((source[CONSTU(0)] - STR('0')) * 100) + ((source[CONSTU(1)] - STR('0')) * 10) + (source[CONSTU(2)] - STR('0'));
      minutes = ((source[CONSTU(3)] - STR('0')) * 10) + (source[CONSTU(4)] - STR('0'));
      break;
    }
    case 6:
    {
      degrees = ((source[CONSTU(0)] - STR('0')) * 10) + (source[CONSTU(1)] - STR('0'));
      minutes = ((source[CONSTU(2)] - STR('0')) * 10) + (source[CONSTU(3)] - STR('0'));
      seconds = ((source[CONSTU(4)] - STR('0')) * 10) + (source[CONSTU(5)] - STR('0'));
      break;
    }
    case 7:
    {
      degrees = ((source[CONSTU(0)] - STR('0')) * 100) + ((source[CONSTU(1)] - STR('0')) * 10) + (source[CONSTU(2)] - STR('0'));
      minutes = ((source[CONSTU(3)] - STR('0')) * 10) + (source[CONSTU(4)] - STR('0'));
      seconds = ((source[CONSTU(5)] - STR('0')) * 10) + (source[CONSTU(6)] - STR('0'));
      break;
    }
  }

  // Convert degrees, minutes and seconds to coordinate value.
  if (minus)
    a_rCoordinate = -degrees - (minutes / 60.0) - (seconds / 3600.0);
  else
    a_rCoordinate = degrees + (minutes / 60.0) + (seconds / 3600.0);

  return true;
}
/*--------------------------------------------------------------------------*/
NDetails::STimeZoneRuleDayOn CTimeZoneDatabaseCustom::convertToDayOnStructure(const NString::CString& a_crSourceString)
{ CALL
  NDetails::STimeZoneRuleDayOn result = NDetails::STimeZoneRuleDayOn::INVALID;

  Tbool error = false;

  // Parse Olson day on token.
  result.m_LastFlag = 0;
  result.m_WeekDayFlag = 0;
  result.m_Day = 0;
  for (Tuint i = 0; i < a_crSourceString.getSize(); ++i)
  {
    switch (a_crSourceString[i])
    {
      // Try to parse 'last' prefix.
      case STR('l'):
      {
        result.m_LastFlag = 1;
        if ((a_crSourceString[i + 1] != STR('a')) || (a_crSourceString[i + 2] != STR('s')) || (a_crSourceString[i + 3] != STR('t')))
          error = true;
        i += 3;
        break;
      }
      // Try to parse 'Sun' or 'Sat' prefixes.
      case STR('S'):
      {
        result.m_WeekDayFlag = 1;
        result.m_WeekDay = 0;
        if ((a_crSourceString[i + 1] != STR('u')) || (a_crSourceString[i + 2] != STR('n')))
        {
          result.m_WeekDay = 6;
          if ((a_crSourceString[i + 1] != STR('a')) || (a_crSourceString[i + 2] != STR('t')))
            error = true;
        }
        i += 2;
        break;
      }
      // Try to parse 'Mon' prefix.
      case STR('M'):
      {
        result.m_WeekDayFlag = 1;
        result.m_WeekDay = 1;
        if ((a_crSourceString[i + 1] != STR('o')) || (a_crSourceString[i + 2] != STR('n')))
          error = true;
        i += 2;
        break;
      }
      // Try to parse 'Tue' or 'Thu' prefixes.
      case STR('T'):
      {
        result.m_WeekDayFlag = 1;
        result.m_WeekDay = 2;
        if ((a_crSourceString[i + 1] != STR('u')) || (a_crSourceString[i + 2] != STR('e')))
        {
          result.m_WeekDay = 4;
          if ((a_crSourceString[i + 1] != STR('h')) || (a_crSourceString[i + 2] != STR('u')))
            error = true;
        }
        i += 2;
        break;
      }
      // Try to parse 'Wed' prefix.
      case STR('W'):
      {
        result.m_WeekDayFlag = 1;
        result.m_WeekDay = 3;
        if ((a_crSourceString[i + 1] != STR('e')) || (a_crSourceString[i + 2] != STR('d')))
          error = true;
        i += 2;
        break;
      }
      // Try to parse 'Fri' prefix.
      case STR('F'):
      {
        result.m_WeekDayFlag = 1;
        result.m_WeekDay = 5;
        if ((a_crSourceString[i + 1] != STR('r')) || (a_crSourceString[i + 2] != STR('i')))
          error = true;
        i += 2;
        break;
      }
      // Skip '>=' prefix.
      case STR('>'):
      {
        if (a_crSourceString[i + 1] != STR('='))
          error = true;
        i += 1;
        break;
      }
      // Try to parse day number.
      default:
      {
        if ((a_crSourceString[i] >= STR('0')) && (a_crSourceString[i] <= STR('9')))
        {
          result.m_Day = (10 * result.m_Day) + (a_crSourceString[i] - STR('0'));
          if (result.m_Day > 31)
            error = true;
        }
        else
          error = true;
        break;
      }
    }

    // Check error.
    if (error)
    {
      WARNING(STR("Cannot parse the given Olson day on token (\"%X\").") COMMA a_crSourceString);
      return NDetails::STimeZoneRuleDayOn::INVALID;
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
void CTimeZoneDatabaseCustom::swap(CTimeZoneDatabaseCustom& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CTimeZoneDatabase&)(*this), (CTimeZoneDatabase&)a_rInstance);
  NAlgorithms::NCommon::swap(m_ZoneCountryCodes, a_rInstance.m_ZoneCountryCodes);
  NAlgorithms::NCommon::swap(m_ZoneCountryNames, a_rInstance.m_ZoneCountryNames);
  NAlgorithms::NCommon::swap(m_ZoneRegionNames, a_rInstance.m_ZoneRegionNames);
  NAlgorithms::NCommon::swap(m_ZoneNames, a_rInstance.m_ZoneNames);
  NAlgorithms::NCommon::swap(m_ZoneComments, a_rInstance.m_ZoneComments);
  NAlgorithms::NCommon::swap(m_ZoneHistoryFormats, a_rInstance.m_ZoneHistoryFormats);
  NAlgorithms::NCommon::swap(m_ZoneRuleNames, a_rInstance.m_ZoneRuleNames);
  NAlgorithms::NCommon::swap(m_ZoneRuleTypes, a_rInstance.m_ZoneRuleTypes);
  NAlgorithms::NCommon::swap(m_ZoneRuleDayOn, a_rInstance.m_ZoneRuleDayOn);
  NAlgorithms::NCommon::swap(m_ZoneRuleLetters, a_rInstance.m_ZoneRuleLetters);
  NAlgorithms::NCommon::swap(m_ZoneCoordinates, a_rInstance.m_ZoneCoordinates);
  NAlgorithms::NCommon::swap(m_TimeZones, a_rInstance.m_TimeZones);
  NAlgorithms::NCommon::swap(m_TimeZoneHistory, a_rInstance.m_TimeZoneHistory);
  NAlgorithms::NCommon::swap(m_TimeZoneRules, a_rInstance.m_TimeZoneRules);
  NAlgorithms::NCommon::swap(m_TimeZoneRulesDayOn, a_rInstance.m_TimeZoneRulesDayOn);
  NAlgorithms::NCommon::swap(m_IsValid, a_rInstance.m_IsValid);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
