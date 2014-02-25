/*!
 *  \file    TZParser-TZOlson.cpp Olson Time Zone Info database parser
 *           is used to parse time zone info database of Olson 'tzdata'
 *           project. 'tzdata' parser.
 *  \brief   Olson Time Zone Info database parser. 'tzdata' parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Olson Time Zone Info database parser. 'tzdata' parser (source).

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
#ifndef __TZPARSER_TZOLSON_INL__
#define __TZPARSER_TZOLSON_INL__
/*==========================================================================*/
Tbool TZParser::parseTimeZoneInfoDatabase(CStreamStdOutput& a_crOutputStream, const Tcstr a_cpFileName, const Tbool a_cFileNotExistAsError/* = true */)
{ CALL
  // Open Olson Time Zone Info database file.
  CFile file_TimeZoneInfoDatabase(a_cpFileName);
  if (!file_TimeZoneInfoDatabase.open(NStream::IStream::e_OPEN_READ))
  {
    if (a_cFileNotExistAsError)
    {
      a_crOutputStream << STR("Olson Time Zone Info database file ") << a_cpFileName << STR(" is not exist...") << ln;
      return false;
    }
    else
      return true;
  }

  a_crOutputStream << STR("Parsing ") << a_cpFileName << STR(" file...") << ln;

  // Parse Olson Time Zone Info database file using internal functionality.
  Tbool error = !m_TZDatabase.parseTimeZoneInfoDatabase(file_TimeZoneInfoDatabase);

  if (error)
    a_crOutputStream << STR("Cannot parse ") << a_cpFileName << STR(" file.") << ln;
  else
    a_crOutputStream << a_cpFileName << STR(" file successfully parsed.") << ln;

  // Close Olson Time Zone Info database file.
  CHECK(file_TimeZoneInfoDatabase.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool TZParser::parseTimeZoneCountryNamesDatabase(CStreamStdOutput& a_crOutputStream, const Tcstr a_cpFileName, const Tbool a_cFileNotExistAsError/* = true */)
{ CALL
  // Open Olson Time Zone Country Names database file.
  CFile file_TimeZoneCountryNamesDatabase(a_cpFileName);
  if (!file_TimeZoneCountryNamesDatabase.open(NStream::IStream::e_OPEN_READ))
  {
    if (a_cFileNotExistAsError)
    {
      a_crOutputStream << STR("Olson Time Zone Country Names database file ") << a_cpFileName << STR(" is not exist...") << ln;
      return false;
    }
    else
      return true;
  }

  a_crOutputStream << STR("Parsing ") << a_cpFileName << STR(" file...") << ln;

  // Parse Olson Time Zone Country Names database file using internal functionality.
  Tbool error = !m_TZDatabase.parseTimeZoneCountryNamesDatabase(file_TimeZoneCountryNamesDatabase);

  if (error)
    a_crOutputStream << STR("Cannot parse ") << a_cpFileName << STR(" file.") << ln;
  else
    a_crOutputStream << a_cpFileName << STR(" file successfully parsed.") << ln;

  // Close Olson Time Zone Country Names database file.
  CHECK(file_TimeZoneCountryNamesDatabase.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool TZParser::parseTimeZoneDescriptionsDatabase(CStreamStdOutput& a_crOutputStream, const Tcstr a_cpFileName, const Tbool a_cFileNotExistAsError/* = true */)
{ CALL
  // Open Olson Time Zone Descriptions database file.
  CFile file_TimeZoneDescriptionsDatabase(a_cpFileName);
  if (!file_TimeZoneDescriptionsDatabase.open(NStream::IStream::e_OPEN_READ))
  {
    if (a_cFileNotExistAsError)
    {
      a_crOutputStream << STR("Olson Time Zone Descriptions database file ") << a_cpFileName << STR(" is not exist...") << ln;
      return false;
    }
    else
      return true;
  }

  a_crOutputStream << STR("Parsing ") << a_cpFileName << STR(" file...") << ln;

  // Parse Olson Time Zone Descriptions database file using internal functionality.
  Tbool error = !m_TZDatabase.parseTimeZoneDescriptionsDatabase(file_TimeZoneDescriptionsDatabase);

  if (error)
    a_crOutputStream << STR("Cannot parse ") << a_cpFileName << STR(" file.") << ln;
  else
    a_crOutputStream << a_cpFileName << STR(" file successfully parsed.") << ln;

  // Close Olson Time Zone Descriptions database file.
  CHECK(file_TimeZoneDescriptionsDatabase.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool TZParser::checkTimeZoneInfoDatabase() const
{ CALL
  return m_TZDatabase.checkTimeZoneInfoDatabase();
}
/*==========================================================================*/
#endif
