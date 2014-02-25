/*!
 *  \file    TZParser.cpp Olson Time Zone Info database parser is used to
 *           parse time zone info database of Olson 'tzdata' project.
 *  \brief   Olson Time Zone Info database parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Olson Time Zone Info database parser (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      TZ parser utility
    VERSION:   1.0
    CREATED:   24.06.2010 22:50:00

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#ifndef __TZPARSER_CPP__
#define __TZPARSER_CPP__
/*==========================================================================*/
// Temporary headers.
#include <Depth/todo/file/CFile.hpp>
/*--------------------------------------------------------------------------*/
// Common headers.
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/tokenizer/CTokenizer.hpp>
#include <Depth/include/tokenizer/CTokenizerFunctionCommentAsChar.hpp>
/*--------------------------------------------------------------------------*/
// Local headers.
#include "TZParser.hpp"
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NStream;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NFiles;
using namespace NDepth::NTokenizer;
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtilities {
/*--------------------------------------------------------------------------*/
namespace NTZParser {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CTZUtilityDatabase::CTZUtilityDatabase() :
  CTimeZoneDatabaseCustom()
{ CALL

}
/*--------------------------------------------------------------------------*/
const CStringBuffer<Tsstr>& CTZUtilityDatabase::getZoneCountryCodes() const
{ CALL
  return CTimeZoneDatabaseCustom::m_ZoneCountryCodes;
}
/*--------------------------------------------------------------------------*/
const CStringBuffer<Tsstr>& CTZUtilityDatabase::getZoneCountryNames() const
{ CALL
  return CTimeZoneDatabaseCustom::m_ZoneCountryNames;
}
/*--------------------------------------------------------------------------*/
const CStringBuffer<Tsstr>& CTZUtilityDatabase::getZoneRegionNames() const
{ CALL
  return CTimeZoneDatabaseCustom::m_ZoneRegionNames;
}
/*--------------------------------------------------------------------------*/
const CStringBuffer<Tsstr>& CTZUtilityDatabase::getZoneNames() const
{ CALL
  return CTimeZoneDatabaseCustom::m_ZoneNames;
}
/*--------------------------------------------------------------------------*/
const CStringBuffer<Tsstr>& CTZUtilityDatabase::getZoneComments() const
{ CALL
  return CTimeZoneDatabaseCustom::m_ZoneComments;
}
/*--------------------------------------------------------------------------*/
const CStringBuffer<Tsstr>& CTZUtilityDatabase::getZoneHistoryFormats() const
{ CALL
  return CTimeZoneDatabaseCustom::m_ZoneHistoryFormats;
}
/*--------------------------------------------------------------------------*/
const CStringBuffer<Tsstr>& CTZUtilityDatabase::getZoneRuleNames() const
{ CALL
  return CTimeZoneDatabaseCustom::m_ZoneRuleNames;
}
/*--------------------------------------------------------------------------*/
const CStringBuffer<Tsstr>& CTZUtilityDatabase::getZoneRuleTypes() const
{ CALL
  return CTimeZoneDatabaseCustom::m_ZoneRuleTypes;
}
/*--------------------------------------------------------------------------*/
const CStringBuffer<Tsstr>& CTZUtilityDatabase::getZoneRuleDayOn() const
{ CALL
  return CTimeZoneDatabaseCustom::m_ZoneRuleDayOn;
}
/*--------------------------------------------------------------------------*/
const CStringBuffer<Tsstr>& CTZUtilityDatabase::getZoneRuleLetters() const
{ CALL
  return CTimeZoneDatabaseCustom::m_ZoneRuleLetters;
}
/*--------------------------------------------------------------------------*/
const CArray<Tdouble>& CTZUtilityDatabase::getZoneCoordinates() const
{ CALL
  return CTimeZoneDatabaseCustom::m_ZoneCoordinates;
}
/*--------------------------------------------------------------------------*/
const CArray<STimeZone>& CTZUtilityDatabase::getTimeZones() const
{ CALL
  return CTimeZoneDatabaseCustom::m_TimeZones;
}
/*--------------------------------------------------------------------------*/
const CArray<STimeZoneHistory>& CTZUtilityDatabase::getTimeZoneHistory() const
{ CALL
  return CTimeZoneDatabaseCustom::m_TimeZoneHistory;
}
/*--------------------------------------------------------------------------*/
const CArray<STimeZoneRule>& CTZUtilityDatabase::getTimeZoneRules() const
{ CALL
  return CTimeZoneDatabaseCustom::m_TimeZoneRules;
}
/*--------------------------------------------------------------------------*/
const CArray<STimeZoneRuleDayOn>& CTZUtilityDatabase::getTimeZoneRulesDayOn() const
{ CALL
  return CTimeZoneDatabaseCustom::m_TimeZoneRulesDayOn;
}
/*--------------------------------------------------------------------------*/
Tbool CTZUtilityDatabase::parseTimeZoneInfoDatabase(NStream::IReader& a_rReader)
{ CALL
  return CTimeZoneDatabaseCustom::parseTimeZoneInfoDatabase(a_rReader);
}
/*--------------------------------------------------------------------------*/
Tbool CTZUtilityDatabase::parseTimeZoneCountryNamesDatabase(NStream::IReader& a_rReader)
{ CALL
  return CTimeZoneDatabaseCustom::parseTimeZoneCountryNamesDatabase(a_rReader);
}
/*--------------------------------------------------------------------------*/
Tbool CTZUtilityDatabase::parseTimeZoneDescriptionsDatabase(NStream::IReader& a_rReader)
{ CALL
  return CTimeZoneDatabaseCustom::parseTimeZoneDescriptionsDatabase(a_rReader);
}
/*--------------------------------------------------------------------------*/
Tbool CTZUtilityDatabase::checkTimeZoneInfoDatabase() const
{ CALL
  return CTimeZoneDatabaseCustom::checkTimeZoneInfoDatabase();
}
/*==========================================================================*/
/* CLASS DECLARATIONS & IMPLEMENTATIONS                                     */
/*==========================================================================*/
class TZParser :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    Tbool error = false;

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    // Show progress information.
    stdoutput << STR("Parsing Olson Time Zone database...") << ln;

    // Parse 'africa' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("africa")));
    // Parse 'antarctica' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("antarctica")));
    // Parse 'asia' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("asia")));
    // Parse 'australasia' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("australasia")));
    // Parse 'europe' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("europe")));
    // Parse 'northamerica' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("northamerica")));
    // Parse 'pacificnew' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("pacificnew")));
    // Parse 'southamerica' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("southamerica")));
    // Parse 'solar87' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("solar87")));
    // Parse 'solar88' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("solar88")));
    // Parse 'solar89' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("solar89")));
    // Parse 'systemv' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("systemv")));
    // Parse 'etcetera' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("etcetera")));
    // Parse 'backward' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("backward")));
    // Try to parse 'custom' file.
    error |= (error ? false : !parseTimeZoneInfoDatabase(stdoutput, STR("custom"), false));

    // Parse 'zone.tab' file.
    error |= (error ? false : !parseTimeZoneDescriptionsDatabase(stdoutput, STR("zone.tab")));
    // Parse 'iso3166.tab' file.
    error |= (error ? false : !parseTimeZoneCountryNamesDatabase(stdoutput, STR("iso3166.tab")));

    // Check if the current Time Zone Info database is valid.
    error |= (error ? false : !checkTimeZoneInfoDatabase());

    // Show progress information.
    stdoutput << STR("Generating Olson Time Zone database table...") << ln;

    // Generate TZTable files.
    error |= (error ? false : !generateTimeZoneTables(stdoutput));

    // Show progress information.
    stdoutput << STR("Done!") << ln;

    return (error ? IApplication::EXIT_WITH_ERROR : IApplication::EXIT_WITH_SUCCESS);
  }

private:
  CTZUtilityDatabase m_TZDatabase;      //!< Utility instance of the Olson Time Zone Info database.

  //! Parse Olson Time Zone Info database.
  Tbool parseTimeZoneInfoDatabase(CStreamStdOutput& a_crOutputStream, const Tcstr a_cpFileName, const Tbool a_cFileNotExistAsError = true);
  //! Parse stream with Olson Time Zone Country Names database.
  Tbool parseTimeZoneCountryNamesDatabase(CStreamStdOutput& a_crOutputStream, const Tcstr a_cpFileName, const Tbool a_cFileNotExistAsError = true);
  //! Parse stream with Olson Time Zone Descriptions database.
  Tbool parseTimeZoneDescriptionsDatabase(CStreamStdOutput& a_crOutputStream, const Tcstr a_cpFileName, const Tbool a_cFileNotExistAsError = true);

  //! Check if the current Time Zone Info database is valid.
  Tbool checkTimeZoneInfoDatabase() const;

  //! Generate string table file.
  Tbool generateStringTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName, const CStringBuffer<Tsstr>& a_crStringTable);
  //! Generate time zones table file.
  Tbool generateTimeZoneTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName);
  //! Generate time zone coordinates file.
  Tbool generateTimeZoneCoordinateTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName);
  //! Generate time zone history table file.
  Tbool generateTimeZoneHistoryTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName);
  //! Generate time zone rules table file.
  Tbool generateTimeZoneRuleTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName);
  //! Generate time zone rule day on table file.
  Tbool generateTimeZoneRuleDayOnTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName);
  //! Generate time zone tables files.
  Tbool generateTimeZoneTables(CStreamStdOutput& a_crOutputStream);
} the_Application;
/*--------------------------------------------------------------------------*/
#include "TZParser-TZOlson.inl"
#include "TZParser-TZTable.inl"
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
