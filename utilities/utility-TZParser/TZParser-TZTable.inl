/*!
 *  \file    TZParser-TZTable.cpp Time Zone Info database generator is used to
 *           generate a time zone info table for internal usage.
 *  \brief   Olson Time Zone Info database generator (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Olson Time Zone Info database generator (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      TZ parser utility
    VERSION:   1.0
    CREATED:   24.06.2010 23:08:29

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#ifndef __TZPARSER_TZTABLE_INL__
#define __TZPARSER_TZTABLE_INL__
/*==========================================================================*/
Tbool TZParser::generateStringTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName, const CStringBuffer<Tsstr>& a_crStringTable)
{ CALL
  Tbool error = false;

  // Open string table file.
  CFile file_StringTable(a_cpFileName);
  CHECK(file_StringTable.open(NStream::IStream::e_OPEN_WRITE));

  a_crOutputStream << STR("Generating") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file...") << ln;

  // Write string table.
  file_StringTable << ascii;
  file_StringTable << a_crHeaderMessage << ln;
  for (Tuint i = 0; i < a_crStringTable.getSize(); ++i)
  {
    file_StringTable << ASC('"') << a_crStringTable[i] << ASC('"') << ((i < (a_crStringTable.getSize() - 1)) ? ASC(',') : ASC(' ')) << ln;
  }

  if (error)
    a_crOutputStream << STR("Cannot generate") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file.") << ln;
  else
    a_crOutputStream << CString(a_cpFileName) << STR(' ') << STR("file successfully generated.") << ln;

  // Close string table file.
  CHECK(file_StringTable.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool TZParser::generateTimeZoneTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName)
{ CALL
  Tbool error = false;

  // Open time zones file.
  CFile file_TimeZones(a_cpFileName);
  CHECK(file_TimeZones.open(NStream::IStream::e_OPEN_WRITE));

  a_crOutputStream << STR("Generating") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file...") << ln;

  // Write time zones database.
  file_TimeZones << ascii;
  file_TimeZones << a_crHeaderMessage << ln;
  file_TimeZones << space << ralign << width(12);
  CArray<STimeZone>::TIteratorConst it = m_TZDatabase.getTimeZones().getItFirst();
  while (it.isValid())
  {
    // Get the current time zone structure.
    const STimeZone& zone = it.getValueRef();

    // Write the current time zone structure.
    file_TimeZones << ASC('{') << ASC(' ');
    file_TimeZones << zone.m_ID << ASC(',') << ASC(' ');
    file_TimeZones << zone.m_CountryCodeID << ASC(',') << ASC(' ');
    file_TimeZones << zone.m_CountryNameID << ASC(',') << ASC(' ');
    file_TimeZones << zone.m_RegionNameID << ASC(',') << ASC(' ');
    file_TimeZones << zone.m_ZoneNameID << ASC(',') << ASC(' ');
    file_TimeZones << zone.m_ZoneCommentsID << ASC(',') << ASC(' ');
    file_TimeZones << zone.m_ZoneHistoryID << ASC(' ') << ASC('}');

    // Take the next value.
    if (it.stepForward() == 0)
    {
      file_TimeZones << ASC(' ') << ln;
      break;
    }
    else
      file_TimeZones << ASC(',') << ln;
  }

  if (error)
    a_crOutputStream << STR("Cannot generate") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file.") << ln;
  else
    a_crOutputStream << CString(a_cpFileName) << STR(' ') << STR("file successfully generated.") << ln;

  // Close time zones file.
  CHECK(file_TimeZones.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool TZParser::generateTimeZoneCoordinateTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName)
{ CALL
  Tbool error = false;

  // Open time zone coordinates file.
  CFile file_TimeZoneCoordinates(a_cpFileName);
  CHECK(file_TimeZoneCoordinates.open(NStream::IStream::e_OPEN_WRITE));

  a_crOutputStream << STR("Generating") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file...") << ln;

  // Write time zone coordinates database.
  file_TimeZoneCoordinates << ascii;
  file_TimeZoneCoordinates << a_crHeaderMessage << ln;
  file_TimeZoneCoordinates << space << ralign << width(12);
  CArray<Tdouble>::TIteratorConst it = m_TZDatabase.getZoneCoordinates().getItFirst();
  while (it.isValid())
  {
    // Get the current time zone latitude.
    Tdouble latitude = it.getValueRef();

    // Write the current time zone latitude.
    file_TimeZoneCoordinates << ASC('{') << ASC(' ');
    file_TimeZoneCoordinates << latitude << ASC(',') << ASC(' ');

    // Take the next value.
    if (it.stepForward() == 0)
    {
      error = true;
      break;
    }

    // Get the current time zone longitude.
    Tdouble longitude = it.getValueRef();

    // Write the current time zone longitude.
    file_TimeZoneCoordinates << longitude << ASC(' ') << ASC('}');

    // Take the next value.
    if (it.stepForward() == 0)
    {
      file_TimeZoneCoordinates << ASC(' ') << ln;
      break;
    }
    else
      file_TimeZoneCoordinates << ASC(',') << ln;
  }

  if (error)
    a_crOutputStream << STR("Cannot generate") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file.") << ln;
  else
    a_crOutputStream << CString(a_cpFileName) << STR(' ') << STR("file successfully generated.") << ln;

  // Close time zone coordinates file.
  CHECK(file_TimeZoneCoordinates.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool TZParser::generateTimeZoneHistoryTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName)
{ CALL
  Tbool error = false;

  // Open time zone history file.
  CFile file_TimeZoneHistory(a_cpFileName);
  CHECK(file_TimeZoneHistory.open(NStream::IStream::e_OPEN_WRITE));

  a_crOutputStream << STR("Generating") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file...") << ln;

  // Write time zone history database.
  file_TimeZoneHistory << ascii;
  file_TimeZoneHistory << a_crHeaderMessage << ln;
  file_TimeZoneHistory << space << ralign << width(12);
  CArray<STimeZoneHistory>::TIteratorConst it = m_TZDatabase.getTimeZoneHistory().getItFirst();
  while (it.isValid())
  {
    // Get the current time zone history structure.
    const STimeZoneHistory& history = it.getValueRef();

    // Write the current time zone history structure.
    file_TimeZoneHistory << ASC('{') << ASC(' ');
    file_TimeZoneHistory << history.m_ID << ASC(',') << ASC(' ');
    file_TimeZoneHistory << width(20) << history.m_GMTOffset << ASC("ull") << width(12) << ASC(',') << ASC(' ');
    file_TimeZoneHistory << history.m_RuleID << ASC(',') << ASC(' ');
    file_TimeZoneHistory << history.m_FormatID << ASC(',') << ASC(' ');
    file_TimeZoneHistory << width(20) << history.m_Until << ASC("ull") << width(12) << ASC(',') << ASC(' ');
    file_TimeZoneHistory << history.m_HistoryPrevID << ASC(',') << ASC(' ');
    file_TimeZoneHistory << history.m_HistoryNextID << ASC(',') << ASC(' ');
    file_TimeZoneHistory << 0 << ASC(' ') << ASC('}');

    // Take the next value.
    if (it.stepForward() == 0)
    {
      file_TimeZoneHistory << ASC(' ') << ln;
      break;
    }
    else
      file_TimeZoneHistory << ASC(',') << ln;
  }

  if (error)
    a_crOutputStream << STR("Cannot generate") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file.") << ln;
  else
    a_crOutputStream << CString(a_cpFileName) << STR(' ') << STR("file successfully generated.") << ln;

  // Close time zone history file.
  CHECK(file_TimeZoneHistory.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool TZParser::generateTimeZoneRuleTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName)
{ CALL
  Tbool error = false;

  // Open time zone rules file.
  CFile file_TimeZoneRules(a_cpFileName);
  CHECK(file_TimeZoneRules.open(NStream::IStream::e_OPEN_WRITE));

  a_crOutputStream << STR("Generating") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file...") << ln;

  // Write time zone rules database.
  file_TimeZoneRules << ascii;
  file_TimeZoneRules << a_crHeaderMessage << ln;
  file_TimeZoneRules << space << ralign << width(12);
  CArray<STimeZoneRule>::TIteratorConst it = m_TZDatabase.getTimeZoneRules().getItFirst();
  while (it.isValid())
  {
    // Get the current time zone rule structure.
    const STimeZoneRule& rule = it.getValueRef();

    // Write the current time zone rule structure.
    file_TimeZoneRules << ASC('{') << ASC(' ');
    file_TimeZoneRules << rule.m_ID << ASC(',') << ASC(' ');
    file_TimeZoneRules << rule.m_RuleNameID << ASC(',') << ASC(' ');
    file_TimeZoneRules << rule.m_YearFrom << ASC(',') << ASC(' ');
    file_TimeZoneRules << rule.m_YearTo << ASC(',') << ASC(' ');
    file_TimeZoneRules << rule.m_RuleTypeID << ASC(',') << ASC(' ');
    file_TimeZoneRules << rule.m_MonthIn << ASC(',') << ASC(' ');
    file_TimeZoneRules << rule.m_DayOnID << ASC(',') << ASC(' ');
    file_TimeZoneRules << width(20) << rule.m_TimeAt << ASC("ull") << width(12) << ASC(',') << ASC(' ');
    file_TimeZoneRules << width(20) << rule.m_TimeSave << ASC("ull") << width(12) << ASC(',') << ASC(' ');
    file_TimeZoneRules << rule.m_TimeSuffix << ASC(',') << ASC(' ');
    file_TimeZoneRules << rule.m_RuleLettersID << ASC(',') << ASC(' ');
    file_TimeZoneRules << rule.m_RulePrevID << ASC(',') << ASC(' ');
    file_TimeZoneRules << rule.m_RuleNextID << ASC(' ') << ASC('}');

    // Take the next value.
    if (it.stepForward() == 0)
    {
      file_TimeZoneRules << ASC(' ') << ln;
      break;
    }
    else
      file_TimeZoneRules << ASC(',') << ln;
  }

  if (error)
    a_crOutputStream << STR("Cannot generate") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file.") << ln;
  else
    a_crOutputStream << CString(a_cpFileName) << STR(' ') << STR("file successfully generated.") << ln;

  // Close time zone rules file.
  CHECK(file_TimeZoneRules.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool TZParser::generateTimeZoneRuleDayOnTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName)
{ CALL
  Tbool error = false;

  // Open time zone rule day on table file.
  CFile file_TimeZoneRuleDayOn(a_cpFileName);
  CHECK(file_TimeZoneRuleDayOn.open(NStream::IStream::e_OPEN_WRITE));

  a_crOutputStream << STR("Generating") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file...") << ln;

  // Write time zone rule day on table database.
  file_TimeZoneRuleDayOn << ascii;
  file_TimeZoneRuleDayOn << a_crHeaderMessage << ln;
  file_TimeZoneRuleDayOn << space << ralign << width(4);
  CArray<STimeZoneRuleDayOn>::TIteratorConst it = m_TZDatabase.getTimeZoneRulesDayOn().getItFirst();
  while (it.isValid())
  {
    // Get the current time zone rule day on structure.
    const STimeZoneRuleDayOn& rule_day_on = it.getValueRef();

    // Write the current time zone rule day on structure.
    file_TimeZoneRuleDayOn << ASC('{') << ASC(' ');
    file_TimeZoneRuleDayOn << rule_day_on.m_ID << ASC(',') << ASC(' ');
    file_TimeZoneRuleDayOn << rule_day_on.m_LastFlag << ASC(',') << ASC(' ');
    file_TimeZoneRuleDayOn << rule_day_on.m_WeekDayFlag << ASC(',') << ASC(' ');
    file_TimeZoneRuleDayOn << rule_day_on.m_WeekDay << ASC(',') << ASC(' ');
    file_TimeZoneRuleDayOn << rule_day_on.m_Day << ASC(' ') << ASC('}');

    // Take the next value.
    if (it.stepForward() == 0)
    {
      file_TimeZoneRuleDayOn << ASC(' ') << ln;
      break;
    }
    else
      file_TimeZoneRuleDayOn << ASC(',') << ln;
  }

  if (error)
    a_crOutputStream << STR("Cannot generate") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file.") << ln;
  else
    a_crOutputStream << CString(a_cpFileName) << STR(' ') << STR("file successfully generated.") << ln;

  // Close time zone rule day on table file.
  CHECK(file_TimeZoneRuleDayOn.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool TZParser::generateTimeZoneTables(CStreamStdOutput& a_crOutputStream)
{ CALL
  Tbool error = false;

  CStringASCII header(ASC("/* This file was auto-generated by TZParser utility. Don't modify it manually! */"));

  // Generate utilities tables.
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("TZTable-ZoneCountryCodes.inl"), m_TZDatabase.getZoneCountryCodes()));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("TZTable-ZoneCountryNames.inl"), m_TZDatabase.getZoneCountryNames()));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("TZTable-ZoneRegionNames.inl"), m_TZDatabase.getZoneRegionNames()));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("TZTable-ZoneNames.inl"), m_TZDatabase.getZoneNames()));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("TZTable-ZoneComments.inl"), m_TZDatabase.getZoneComments()));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("TZTable-ZoneHistoryFormats.inl"), m_TZDatabase.getZoneHistoryFormats()));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("TZTable-ZoneRuleNames.inl"), m_TZDatabase.getZoneRuleNames()));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("TZTable-ZoneRuleTypes.inl"), m_TZDatabase.getZoneRuleTypes()));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("TZTable-ZoneRuleDayOn.inl"), m_TZDatabase.getZoneRuleDayOn()));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("TZTable-ZoneRuleLetters.inl"), m_TZDatabase.getZoneRuleLetters()));
  error |= (error ? false : !generateTimeZoneTable(a_crOutputStream, header, STR("TZTable-TimeZones.inl")));
  error |= (error ? false : !generateTimeZoneCoordinateTable(a_crOutputStream, header, STR("TZTable-ZoneCoordinates.inl")));
  error |= (error ? false : !generateTimeZoneHistoryTable(a_crOutputStream, header, STR("TZTable-TimeZoneHistory.inl")));
  error |= (error ? false : !generateTimeZoneRuleTable(a_crOutputStream, header, STR("TZTable-TimeZoneRules.inl")));
  error |= (error ? false : !generateTimeZoneRuleDayOnTable(a_crOutputStream, header, STR("TZTable-ZoneRuleDayOnTable.inl")));

  return !error;
}
/*==========================================================================*/
#endif
