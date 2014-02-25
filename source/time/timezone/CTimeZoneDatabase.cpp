/*!
 *  \file    CTimeZoneDatabase.cpp Default time zone database class provides
 *           all common time zone information (rules, history, country and
 *           region names). Default time zone database uses time zone tables
 *           which are prepared by the TZParser utility.
 *  \brief   Default time zone database class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Default time zone database class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time zone
    VERSION:   1.0
    CREATED:   07.12.2010 19:40:03

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
#include <Depth/include/time/timezone/CTimeZoneDatabase.hpp>
/*==========================================================================*/
#ifndef __CTIMEZONEDATABASE_CPP__
#define __CTIMEZONEDATABASE_CPP__
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
Tbool CTimeZoneDatabase::set(const CTimeZoneDatabase& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CTimeZoneDatabase class instance."))
  {
    return false;
  }

  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabase::isValidTimeZone(const NDetails::STimeZone& a_crTimeZoneStructure) const
{ CALL
  // Check time zone ID.
  if ((a_crTimeZoneStructure.m_ID < 0) || ((Tuint)a_crTimeZoneStructure.m_ID >= NDetails::getCountOfTimeZones()))
     return false;
  // Check time zone country code.
  if ((a_crTimeZoneStructure.m_CountryCodeID >= 0) && ((Tuint)a_crTimeZoneStructure.m_CountryCodeID >= NDetails::getCountOfZoneCountryCodes()))
     return false;
  // Check time zone country name.
  if ((a_crTimeZoneStructure.m_CountryNameID >= 0) && ((Tuint)a_crTimeZoneStructure.m_CountryNameID >= NDetails::getCountOfZoneCountryNames()))
     return false;
  // Check time zone region name.
  if ((a_crTimeZoneStructure.m_RegionNameID >= 0) && ((Tuint)a_crTimeZoneStructure.m_RegionNameID >= NDetails::getCountOfZoneRegionNames()))
     return false;
  // Check time zone name.
  if ((a_crTimeZoneStructure.m_ZoneNameID >= 0) && ((Tuint)a_crTimeZoneStructure.m_ZoneNameID >= NDetails::getCountOfZoneNames()))
     return false;
  // Check time zone comments.
  if ((a_crTimeZoneStructure.m_ZoneCommentsID >= 0) && ((Tuint)a_crTimeZoneStructure.m_ZoneCommentsID >= NDetails::getCountOfZoneComments()))
     return false;
  // Check time zone coordinates.
  if ((a_crTimeZoneStructure.m_ZoneCoordinatesID >= 0) && ((Tuint)a_crTimeZoneStructure.m_ZoneCoordinatesID >= NDetails::getCountOfZoneCoordinates()))
     return false;
  // Check time zone history.
  if ((a_crTimeZoneStructure.m_ZoneHistoryID >= 0) && ((Tuint)a_crTimeZoneStructure.m_ZoneHistoryID >= NDetails::getCountOfTimeZoneHistory()))
     return false;

  // Everything is ok.
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabase::isValidTimeZoneHistory(const NDetails::STimeZoneHistory& a_crTimeZoneHistoryStructure) const
{ CALL
  // Check time zone history ID.
  if ((a_crTimeZoneHistoryStructure.m_ID < 0) || ((Tuint)a_crTimeZoneHistoryStructure.m_ID >= NDetails::getCountOfTimeZoneHistory()))
     return false;
  // Check time zone history rule.
  if ((a_crTimeZoneHistoryStructure.m_RuleID >= 0) && ((Tuint)a_crTimeZoneHistoryStructure.m_RuleID >= NDetails::getCountOfTimeZoneRules()))
     return false;
  // Check time zone history format.
  if ((a_crTimeZoneHistoryStructure.m_FormatID >= 0) && ((Tuint)a_crTimeZoneHistoryStructure.m_FormatID >= NDetails::getCountOfZoneHistoryFormats()))
     return false;
  // Check time zone previous history.
  if ((a_crTimeZoneHistoryStructure.m_HistoryPrevID >= 0) && ((Tuint)a_crTimeZoneHistoryStructure.m_HistoryPrevID >= NDetails::getCountOfTimeZoneHistory()))
     return false;
  // Check time zone next history.
  if ((a_crTimeZoneHistoryStructure.m_HistoryNextID >= 0) && ((Tuint)a_crTimeZoneHistoryStructure.m_HistoryNextID >= NDetails::getCountOfTimeZoneHistory()))
     return false;

  // Everything is ok.
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabase::isValidTimeZoneRule(const NDetails::STimeZoneRule& a_crTimeZoneRuleStructure) const
{ CALL
  // Check time zone rule ID.
  if ((a_crTimeZoneRuleStructure.m_ID < 0) || ((Tuint)a_crTimeZoneRuleStructure.m_ID >= NDetails::getCountOfTimeZoneRules()))
     return false;
  // Check time zone rule name.
  if ((a_crTimeZoneRuleStructure.m_RuleNameID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_RuleNameID >= NDetails::getCountOfZoneRuleNames()))
     return false;
  // Check time zone rule type.
  if ((a_crTimeZoneRuleStructure.m_RuleTypeID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_RuleTypeID >= NDetails::getCountOfZoneRuleTypes()))
     return false;
  // Check time zone rule in month value.
  if ((a_crTimeZoneRuleStructure.m_MonthIn < 1) || (a_crTimeZoneRuleStructure.m_MonthIn > 12))
     return false;
  // Check time zone rule on day value.
  if ((a_crTimeZoneRuleStructure.m_DayOnID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_DayOnID >= NDetails::getCountOfZoneRuleDayOn()) && ((Tuint)a_crTimeZoneRuleStructure.m_DayOnID >= NDetails::getCountOfZoneRuleDayOnTable()))
     return false;
  // Check time zone rule letters.
  if ((a_crTimeZoneRuleStructure.m_RuleLettersID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_RuleLettersID >= NDetails::getCountOfZoneRuleLetters()))
     return false;
  // Check time zone previous rule.
  if ((a_crTimeZoneRuleStructure.m_RulePrevID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_RulePrevID >= NDetails::getCountOfTimeZoneRules()))
     return false;
  // Check time zone next rule.
  if ((a_crTimeZoneRuleStructure.m_RuleNextID >= 0) && ((Tuint)a_crTimeZoneRuleStructure.m_RuleNextID >= NDetails::getCountOfTimeZoneRules()))
     return false;

  // Everything is ok.
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabase::isValidTimeZoneRuleDayOn(const NDetails::STimeZoneRuleDayOn& a_crTimeZoneRuleDayOnStructure) const
{ CALL
  // Check time zone rule day on ID.
  if ((a_crTimeZoneRuleDayOnStructure.m_ID < 0) || ((Tuint)a_crTimeZoneRuleDayOnStructure.m_ID >= NDetails::getCountOfZoneRuleDayOnTable()))
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
Tcsstr CTimeZoneDatabase::getZoneCountryCodeByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneCountryCodes()), STR("Cannot get default time zone country code with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneCountryCodes())
  {
    return ASC("");
  }

  return NDetails::the_ZoneCountryCodes[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabase::getZoneCountryNameByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneCountryNames()), STR("Cannot get default time zone country name with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneCountryNames())
  {
    return ASC("");
  }

  return NDetails::the_ZoneCountryNames[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabase::getZoneRegionNameByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneRegionNames()), STR("Cannot get default time zone region name with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneRegionNames())
  {
    return ASC("");
  }

  return NDetails::the_ZoneRegionNames[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabase::getZoneNameByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneNames()), STR("Cannot get default time zone name with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneNames())
  {
    return ASC("");
  }

  return NDetails::the_ZoneNames[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabase::getZoneCommentsByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneComments()), STR("Cannot get default time zone comments with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneComments())
  {
    return ASC("");
  }

  return NDetails::the_ZoneComments[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabase::getZoneHistoryFormatByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneHistoryFormats()), STR("Cannot get default time zone history format with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneHistoryFormats())
  {
    return ASC("");
  }

  return NDetails::the_ZoneHistoryFormats[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabase::getZoneRuleNameByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneRuleNames()), STR("Cannot get default time zone rule name with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneRuleNames())
  {
    return ASC("");
  }

  return NDetails::the_ZoneRuleNames[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabase::getZoneRuleTypeByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneRuleTypes()), STR("Cannot get default time zone rule type with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneRuleTypes())
  {
    return ASC("");
  }

  return NDetails::the_ZoneRuleTypes[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabase::getZoneRuleDayOnByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneRuleDayOn()), STR("Cannot get default time zone rule day on with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneRuleDayOn())
  {
    return ASC("");
  }

  return NDetails::the_ZoneRuleDayOn[a_cID];
}
/*--------------------------------------------------------------------------*/
NDetails::STimeZoneRuleDayOn CTimeZoneDatabase::getZoneRuleDayOnStructureByID(const Tuint a_cID) const
{
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneRuleDayOnTable()), STR("Cannot get default time zone rule day on structure with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneRuleDayOnTable())
  {
    return NDetails::STimeZoneRuleDayOn::INVALID;
  }

  return NDetails::the_ZoneRuleDayOnTable[a_cID];
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneDatabase::getZoneRuleLettersByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneRuleLetters()), STR("Cannot get default time zone rule letters with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneRuleLetters())
  {
    return ASC("");
  }

  return NDetails::the_ZoneRuleLetters[a_cID];
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Treal, Treal> CTimeZoneDatabase::getZoneCoordinateByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfZoneCoordinates()), STR("Cannot get default time zone coordinates with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfZoneCoordinates())
  {
    return NUtility::CPair<Treal, Treal>(0.0, 0.0);
  }

  return NUtility::CPair<Treal, Treal>((Treal)NDetails::the_ZoneCoordinates[a_cID][0], (Treal)NDetails::the_ZoneCoordinates[a_cID][1]);
}
/*--------------------------------------------------------------------------*/
CTimeZone CTimeZoneDatabase::getZoneByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfTimeZones()), STR("Cannot get default time zone with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfTimeZones())
  {
    return CTimeZone(*this);
  }

  return CTimeZone(*this, NDetails::the_TimeZones[a_cID]);
}
/*--------------------------------------------------------------------------*/
CTimeZoneHistory CTimeZoneDatabase::getZoneHistoryByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfTimeZoneHistory()), STR("Cannot get default time zone history with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfTimeZoneHistory())
  {
    return CTimeZoneHistory(*this);
  }

  return CTimeZoneHistory(*this, NDetails::the_TimeZoneHistory[a_cID]);
}
/*--------------------------------------------------------------------------*/
CTimeZoneRule CTimeZoneDatabase::getZoneRuleByID(const Tuint a_cID) const
{ CALL
  // Check index value and the collection bounds.
  ASSERT((a_cID < NDetails::getCountOfTimeZoneRules()), STR("Cannot get default time zone rule with the out of bounds index (index = %u, size = %u).") COMMA a_cID COMMA NDetails::getCountOfTimeZoneRules())
  {
    return CTimeZoneRule(*this);
  }

  return CTimeZoneRule(*this, NDetails::the_TimeZoneRules[a_cID]);
}
/*--------------------------------------------------------------------------*/
CDate CTimeZoneDatabase::getFirstWeekDayOccurrence(const CDate& a_crDate, const CDate::EWeekDay a_cWeekDay)
{ CALL
  Tuint wd1 = a_crDate.getWeekDay() - CDate::e_SUNDAY;
  Tuint wd2 = a_cWeekDay - CDate::e_SUNDAY;

  // Get the week day of the given day is equal to required then return this date.
  if (wd1 == wd2)
    return a_crDate;

  if (wd1 > wd2)
    return a_crDate.addDays(7 - (wd1 - wd2));
  else
    return a_crDate.addDays(wd2 - wd1);
}
/*--------------------------------------------------------------------------*/
CDate CTimeZoneDatabase::getLastWeekDayOccurrence(const CDate& a_crDate, const CDate::EWeekDay a_cWeekDay)
{ CALL
  Tuint wd1 = a_crDate.getWeekDay() - CDate::e_SUNDAY;
  Tuint wd2 = a_cWeekDay - CDate::e_SUNDAY;

  // Get the week day of the given day is equal to required then return this date.
  if (wd1 == wd2)
    return a_crDate;

  if (wd1 > wd2)
    return a_crDate.addDays(wd2 - wd1);
  else
    return a_crDate.addDays((wd2 - wd1) - 7);
}
/*--------------------------------------------------------------------------*/
CDate CTimeZoneDatabase::convertToDate(const Tsint a_cYear, const Tuint a_cMonth, const NDetails::STimeZoneRuleDayOn& a_crTimeZoneRuleDayOnStructure)
{ CALL
  CDate result(a_cYear, a_cMonth, 1);

  if ((a_crTimeZoneRuleDayOnStructure.m_LastFlag == 1) && (a_crTimeZoneRuleDayOnStructure.m_WeekDayFlag == 1))
  {
    // Get date with the last week day occurrence.
    return getLastWeekDayOccurrence(result.addMonths(1).addDays(-1), (CDate::EWeekDay)(CDate::e_SUNDAY + a_crTimeZoneRuleDayOnStructure.m_WeekDay));
  }
  else if ((a_crTimeZoneRuleDayOnStructure.m_WeekDayFlag == 1) && (a_crTimeZoneRuleDayOnStructure.m_Day > 0))
  {
    // Get date with the first week day occurrence.
    return getFirstWeekDayOccurrence(result.addDays(a_crTimeZoneRuleDayOnStructure.m_Day - 1), (CDate::EWeekDay)(CDate::e_SUNDAY + a_crTimeZoneRuleDayOnStructure.m_WeekDay));
  }
  else if (a_crTimeZoneRuleDayOnStructure.m_Day > 0)
  {
    // Get date with the given month days.
    result = result.addDays(a_crTimeZoneRuleDayOnStructure.m_Day - 1);

    // Check for month days out of bounds.
    if (result.getMonth() != a_cMonth)
      result = result.addDays(-1 * result.getDay());

    return result;
  }

  // Something goes wrong...
  WARNING(STR("Cannot convert to date the given Olson day on token (ID = %i).") COMMA (Tsint)a_crTimeZoneRuleDayOnStructure.m_ID);
  return result;
}
/*--------------------------------------------------------------------------*/
Tbool CTimeZoneDatabase::getCutoverDateTime(const CTimeZoneRule& a_crTimeZoneRule, const Tsint a_cYear, CDateTime& a_rCutoverDateTime)
{ CALL
  // Check if the year is suitable for the given time zone rule.
  if (a_crTimeZoneRule.isValid() && (a_crTimeZoneRule.getYearFrom() <= a_cYear) && (a_crTimeZoneRule.getYearTo() >= a_cYear))
  {
    a_rCutoverDateTime.set(convertToDate(a_cYear, a_crTimeZoneRule.getMonthIn(), a_crTimeZoneRule.getDayOnStructure()), a_crTimeZoneRule.getTimeAt());
    return true;
  }
  else
  {
    a_rCutoverDateTime.set(CDateTime::getMin());
    return false;
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
