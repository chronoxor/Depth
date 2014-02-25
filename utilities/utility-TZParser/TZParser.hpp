/*!
 *  \file    TZParser.hpp Olson Time Zone Info database parser is used to
 *           parse time zone info database of Olson 'tzdata' project.
 *  \brief   Olson Time Zone Info database parser.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Olson Time Zone Info database parser.

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
#ifndef __TZPARSER_HPP__
#define __TZPARSER_HPP__
/*==========================================================================*/
// Common headers.
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/CStringBuffer.hpp>
#include <Depth/include/stream/IReader.hpp>
#include <Depth/include/string/CString.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/time/timezone/CTimeZoneDatabaseCustom.hpp>
#include <Depth/include/time/timezone/details/TZTable.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific headers.
using namespace NDepth::NTime::NTimezone;
using namespace NDepth::NTime::NTimezone::NDetails;
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtilities {
/*--------------------------------------------------------------------------*/
namespace NTZParser {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
class CTZUtilityDatabase :              //! Olson Time Zone Info database.
  public CTimeZoneDatabaseCustom
{
public:
  //! Default class constructor.
  CTZUtilityDatabase();

  //! Get time zone country codes collection.
  /*!
      \return Constant reference to the time zone country codes collection.
  */
  const CStringBuffer<Tsstr>& getZoneCountryCodes() const;
  //! Get time zone country names collection.
  /*!
      \return Constant reference to the time zone country names collection.
  */
  const CStringBuffer<Tsstr>& getZoneCountryNames() const;
  //! Get time zone region names collection.
  /*!
      \return Constant reference to the time zone region names collection.
  */
  const CStringBuffer<Tsstr>& getZoneRegionNames() const;
  //! Get time zone names collection.
  /*!
      \return Constant reference to the time zone names collection.
  */
  const CStringBuffer<Tsstr>& getZoneNames() const;
  //! Get time zone comments collection.
  /*!
      \return Constant reference to the time zone comments collection.
  */
  const CStringBuffer<Tsstr>& getZoneComments() const;
  //! Get time zone history formats collection.
  /*!
      \return Constant reference to the time zone history formats collection.
  */
  const CStringBuffer<Tsstr>& getZoneHistoryFormats() const;
  //! Get time zone rule names collection.
  /*!
      \return Constant reference to the time zone rule names collection.
  */
  const CStringBuffer<Tsstr>& getZoneRuleNames() const;
  //! Get time zone rule types collection.
  /*!
      \return Constant reference to the time zone rule types collection.
  */
  const CStringBuffer<Tsstr>& getZoneRuleTypes() const;
  //! Get time zone rule day on collection.
  /*!
      \return Constant reference to the time zone rule day on collection.
  */
  const CStringBuffer<Tsstr>& getZoneRuleDayOn() const;
  //! Get time zone rule letters collection.
  /*!
      \return Constant reference to the time zone rule letters collection.
  */
  const CStringBuffer<Tsstr>& getZoneRuleLetters() const;
  //! Get time zone coordinates collection.
  /*!
      \return Constant reference to the time zone coordinates collection.
  */
  const CArray<Tdouble>& getZoneCoordinates() const;
  //! Get time zones collection.
  /*!
      \return Constant reference to the time zones collection.
  */
  const CArray<STimeZone>& getTimeZones() const;
  //! Get time zone history collection.
  /*!
      \return Constant reference to the time zone history collection.
  */
  const CArray<STimeZoneHistory>& getTimeZoneHistory() const;
  //! Get time zone rules collection.
  /*!
      \return Constant reference to the time zone rules collection.
  */
  const CArray<STimeZoneRule>& getTimeZoneRules() const;
  //! Get time zone rules day on structures collection.
  /*!
      \return Constant reference to the time zone rules day on structures collection.
  */
  const CArray<STimeZoneRuleDayOn>& getTimeZoneRulesDayOn() const;

  //! Parse stream with Olson Time Zone Info database.
  /*!
      \param a_rReader - Reference to the NStream::IReader interface.
      \return true  - if Olson Time Zone Info database was parsed successfully. \n
              false - if Olson Time Zone Info database was not parsed successfully. \n
  */
  Tbool parseTimeZoneInfoDatabase(NStream::IReader& a_rReader);
  //! Parse stream with Olson Time Zone Country Names database.
  /*!
      \param a_rReader - Reference to the NStream::IReader interface.
      \return true  - if Olson Time Zone Country Names database was parsed successfully. \n
              false - if Olson Time Zone Country Names database was not parsed successfully. \n
  */
  Tbool parseTimeZoneCountryNamesDatabase(NStream::IReader& a_rReader);
  //! Parse stream with Olson Time Zone Descriptions database.
  /*!
      \param a_rReader - Reference to the NStream::IReader interface.
      \return true  - if Olson Time Zone Descriptions database was parsed successfully. \n
              false - if Olson Time Zone Descriptions database was not parsed successfully. \n
  */
  Tbool parseTimeZoneDescriptionsDatabase(NStream::IReader& a_rReader);

  //! Check Olson Time Zone Info database for conflicts.
  /*!
      The method is called after parsing to check for any conflicts.

      \return true  - if Olson Time Zone Info database has no conflicts. \n
              false - if Olson Time Zone Info database has some conflicts. \n
  */
  Tbool checkTimeZoneInfoDatabase() const;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
