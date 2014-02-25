/*!
 *  \file    CTimeZoneDatabaseCustom.hpp Custom time zone database class
 *           provides custom time zone information (rules, history, country
 *           and region names) which can be read form Olson Time Zone Info
 *           database or composed manually.
 *  \brief   Custom time zone database class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Custom time zone database class.

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
#ifndef __CTIMEZONEDATABASECUSTOM_HPP__
#define __CTIMEZONEDATABASECUSTOM_HPP__
/*==========================================================================*/
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/CStringBuffer.hpp>
#include <Depth/include/stream/IReader.hpp>
#include <Depth/include/time/timezone/CTimeZoneDatabase.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*--------------------------------------------------------------------------*/
namespace NTimezone {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Custom time zone database class.
/*!
    Custom time zone database class  provides  custom  time  zone  information
    (rules, history, country and region names) which  can  be  read  from  the
    Olson Time Zone Info database or composed manually.

    The Olson Time Zone Info database  can  be  loaded  from  the  given  file
    system. Before load a new database an all custom data will be cleared.

    Custom time zones could be created with provided GMT offset and day  light
    saving time rules.
*/
class BASE_API CTimeZoneDatabaseCustom :
  public CTimeZoneDatabase
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CTimeZoneDatabaseCustom TDepthCheckType;

  // Check CTimeZoneDatabaseCustom class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CTimeZoneDatabaseCustom();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneDatabaseCustom class.
  */
  CTimeZoneDatabaseCustom(const CTimeZoneDatabaseCustom& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTimeZoneDatabaseCustom();

  //! Operator: Assign another CTimeZoneDatabaseCustom class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneDatabaseCustom class.
      \return Reference to the current class instance.
  */
  CTimeZoneDatabaseCustom& operator = (const CTimeZoneDatabaseCustom& a_crInstance);

  //! Set another CTimeZoneDatabaseCustom class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneDatabaseCustom class.
      \return true  - if another custom time zone database was successfully set. \n
              false - if another custom time zone database was not successfully set. \n
  */
  Tbool set(const CTimeZoneDatabaseCustom& a_crInstance);

  //! Check if the custom time zone database has valid properties.
  /*!
      \return true  - if the custom time zone database has valid properties. \n
              false - if the custom time zone database has not valid properties. \n
  */
  virtual Tbool isValid() const;

  //! Clear custom time zone database.
  /*!
      \return true  - if the custom time zone database was successfully cleared. \n
              false - if the custom time zone database was not successfully cleared. \n
  */
  virtual Tbool clear();

  //! Serialize CTimeZoneDatabaseCustom class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTimeZoneDatabaseCustom class instances.
  /*!
      \param a_rInstance - Reference to another CTimeZoneDatabaseCustom class instance.
  */
  void swap(CTimeZoneDatabaseCustom& a_rInstance);

protected:
  NContainers::CStringBuffer<Tsstr> m_ZoneCountryCodes;   //!< Time zone country codes collection.
  NContainers::CStringBuffer<Tsstr> m_ZoneCountryNames;   //!< Time zone country names collection.
  NContainers::CStringBuffer<Tsstr> m_ZoneRegionNames;    //!< Time zone region names collection.
  NContainers::CStringBuffer<Tsstr> m_ZoneNames;          //!< Time zone names collection.
  NContainers::CStringBuffer<Tsstr> m_ZoneComments;       //!< Time zone comments collection.
  NContainers::CStringBuffer<Tsstr> m_ZoneHistoryFormats; //!< Time zone history formats collection.
  NContainers::CStringBuffer<Tsstr> m_ZoneRuleNames;      //!< Time zone rule names collection.
  NContainers::CStringBuffer<Tsstr> m_ZoneRuleTypes;      //!< Time zone rule types collection.
  NContainers::CStringBuffer<Tsstr> m_ZoneRuleDayOn;      //!< Time zone rule day on collection.
  NContainers::CStringBuffer<Tsstr> m_ZoneRuleLetters;    //!< Time zone rule letters collection.
  NContainers::CArray<Tdouble>      m_ZoneCoordinates;    //!< Time zone coordinates collection.

  NContainers::CArray<NDetails::STimeZone>          m_TimeZones;          //!< Time zones collection.
  NContainers::CArray<NDetails::STimeZoneHistory>   m_TimeZoneHistory;    //!< Time zone history collection.
  NContainers::CArray<NDetails::STimeZoneRule>      m_TimeZoneRules;      //!< Time zone rules collection.
  NContainers::CArray<NDetails::STimeZoneRuleDayOn> m_TimeZoneRulesDayOn; //!< Time zone rule day on values collection.

  Tbool m_IsValid;                      //!< Time zone valid flag.

  //! Check if the given time zone has valid properties in the custom time zone database.
  /*!
      \param a_crTimeZoneStructure - Constant reference to the instance of the STimeZone structure.
      \return true  - if the given time zone has valid properties. \n
              false - if the given time zone has not valid properties. \n
  */
  virtual Tbool isValidTimeZone(const NDetails::STimeZone& a_crTimeZoneStructure) const;
  //! Check if the given time zone history has valid properties in the custom time zone database.
  /*!
      \param a_crTimeZoneHistoryStructure - Constant reference to the instance of the STimeZoneHistory structure.
      \return true  - if the given time zone history has valid properties. \n
              false - if the given time zone history has not valid properties. \n
  */
  virtual Tbool isValidTimeZoneHistory(const NDetails::STimeZoneHistory& a_crTimeZoneHistoryStructure) const;
  //! Check if the given time zone rule has valid properties in the custom time zone database.
  /*!
      \param a_crTimeZoneRuleStructure - Constant reference to the instance of the STimeZoneRule structure.
      \return true  - if the given time zone rule has valid properties. \n
              false - if the given time zone rule has not valid properties. \n
  */
  virtual Tbool isValidTimeZoneRule(const NDetails::STimeZoneRule& a_crTimeZoneRuleStructure) const;
  //! Check if the given time zone rule day on structure has valid properties in the custom time zone database.
  /*!
      \param a_crTimeZoneRuleDayOnStructure - Constant reference to the instance of the STimeZoneRuleDayOn structure.
      \return true  - if the given time zone rule day on structure has valid properties. \n
              false - if the given time zone rule day on structure has not valid properties. \n
  */
  virtual Tbool isValidTimeZoneRuleDayOn(const NDetails::STimeZoneRuleDayOn& a_crTimeZoneRuleDayOnStructure) const;

  //! Get time zone country code by the given ID.
  /*!
      \param a_cID - Time zone country code ID.
      \return Time zone country code value.
  */
  virtual Tcsstr getZoneCountryCodeByID(const Tuint a_cID) const;
  //! Get time zone country name by the given ID.
  /*!
      \param a_cID - Time zone country name ID.
      \return Time zone country name value.
  */
  virtual Tcsstr getZoneCountryNameByID(const Tuint a_cID) const;
  //! Get time zone region name by the given ID.
  /*!
      \param a_cID - Time zone region name ID.
      \return Time zone region name value.
  */
  virtual Tcsstr getZoneRegionNameByID(const Tuint a_cID) const;
  //! Get time zone name by the given ID.
  /*!
      \param a_cID - Time zone name ID.
      \return Time zone name value.
  */
  virtual Tcsstr getZoneNameByID(const Tuint a_cID) const;
  //! Get time zone comments by the given ID.
  /*!
      \param a_cID - Time zone comments ID.
      \return Time zone comments value.
  */
  virtual Tcsstr getZoneCommentsByID(const Tuint a_cID) const;
  //! Get time zone history format by the given ID.
  /*!
      \param a_cID - Time zone history format ID.
      \return Time zone history format value.
  */
  virtual Tcsstr getZoneHistoryFormatByID(const Tuint a_cID) const;
  //! Get time zone rule name by the given ID.
  /*!
      \param a_cID - Time zone rule name ID.
      \return Time zone rule name value.
  */
  virtual Tcsstr getZoneRuleNameByID(const Tuint a_cID) const;
  //! Get time zone rule type by the given ID.
  /*!
      \param a_cID - Time zone rule type ID.
      \return Time zone rule type value.
  */
  virtual Tcsstr getZoneRuleTypeByID(const Tuint a_cID) const;
  //! Get time zone rule day on by the given ID.
  /*!
      \param a_cID - Time zone rule day on ID.
      \return Time zone rule day on value.
  */
  virtual Tcsstr getZoneRuleDayOnByID(const Tuint a_cID) const;
  //! Get time zone rule day on structure by the given ID.
  /*!
      \param a_cID - Time zone rule day on ID.
      \return Time zone rule day on structure.
  */
  virtual NDetails::STimeZoneRuleDayOn getZoneRuleDayOnStructureByID(const Tuint a_cID) const;
  //! Get time zone rule letters by the given ID.
  /*!
      \param a_cID - Time zone rule letters ID.
      \return Time zone rule letters value.
  */
  virtual Tcsstr getZoneRuleLettersByID(const Tuint a_cID) const;
  //! Get time zone coordinate by the given ID.
  /*!
      \param a_cID - Time zone coordinate ID.
      \return Time zone coordinate value.
  */
  virtual NUtility::CPair<Treal, Treal> getZoneCoordinateByID(const Tuint a_cID) const;
  //! Get time zone by the given ID.
  /*!
      \param a_cID - Time zone ID.
      \return Time zone value.
  */
  virtual CTimeZone getZoneByID(const Tuint a_cID) const;
  //! Get time zone history by the given ID.
  /*!
      \param a_cID - Time zone history ID.
      \return Time zone history value.
  */
  virtual CTimeZoneHistory getZoneHistoryByID(const Tuint a_cID) const;
  //! Get time zone rule by the given ID.
  /*!
      \param a_cID - Time zone rule ID.
      \return Time zone rule value.
  */
  virtual CTimeZoneRule getZoneRuleByID(const Tuint a_cID) const;

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

private:
  //! Parse the next token from the given string.
  /*!
      \param a_rSourceString - Reference to the source string.
      \param a_rTokenString - Reference to the result token string.
      \param a_cAcceptSpaces - Accept spaces flag (default is false).
      \return true  - if the next token was parsed successfully. \n
              false - if the next token was not parsed successfully. \n
  */
  static Tbool parseNextToken(NString::CString& a_rSourceString, NString::CString& a_rTokenString, const Tbool a_cAcceptSpaces = false);
  //! Parse the string table value from the given string.
  /*!
      \param a_crSourceString - Constant reference to the source string.
      \param a_rStringTable - Reference to the string table.
      \param a_rID - Reference to the result ID value.
      \return true  - if the string table value was parsed successfully. \n
              false - if the string table value was not parsed successfully. \n
  */
  static Tbool parseStringTableValue(const NString::CString& a_crSourceString, NContainers::CStringBuffer<Tsstr>& a_rStringTable, Tsint16& a_rID);
  //! Parse the time zone region name value from the given string.
  /*!
      \param a_crSourceString - Constant reference to the source string.
      \param a_rStringTable - Reference to the string table.
      \param a_rID - Reference to the result ID value.
      \return true  - if the time zone region name value was parsed successfully. \n
              false - if the time zone region name value was not parsed successfully. \n
  */
  static Tbool parseRegionNameValue(const NString::CString& a_crSourceString, NContainers::CStringBuffer<Tsstr>& a_rStringTable, Tsint16& a_rID);
  //! Parse the year value from the given string.
  /*!
      \param a_crSourceString - Constant reference to the source string.
      \param a_rYear - Reference to the result year value.
      \param a_cOnlyYear - Only year value (default value is 0).
      \return true  - if the year value was parsed successfully. \n
              false - if the year value was not parsed successfully. \n
  */
  static Tbool parseYearValue(const NString::CString& a_crSourceString, Tsint32& a_rYear, const Tsint32 a_cOnlyYear = 0);
  //! Parse the month value from the given string.
  /*!
      \param a_crSourceString - Constant reference to the source string.
      \param a_rMonth - Reference to the result month value.
      \return true  - if the month value was parsed successfully. \n
              false - if the month value was not parsed successfully. \n
  */
  static Tbool parseMonthValue(const NString::CString& a_crSourceString, Tuint08& a_rMonth);
  //! Parse the day value from the given string.
  /*!
      \param a_crSourceString - Constant reference to the source string.
      \param a_rDay - Reference to the result month value.
      \return true  - if the day value was parsed successfully. \n
              false - if the day value was not parsed successfully. \n
  */
  static Tbool parseDayValue(const NString::CString& a_crSourceString, Tuint08& a_rDay);
  //! Parse the day value from the given string with support of special days (e.g. 'Thu>=8', 'lastFri').
  /*!
      \param a_crSourceString - Constant reference to the source string.
      \param a_rDay - Reference to the result month value.
      \param a_rMonth - Reference to the given month value.
      \param a_rYear - Reference to the given year value.
      \return true  - if the day value was parsed successfully. \n
              false - if the day value was not parsed successfully. \n
  */
  static Tbool parseDayValue(const NString::CString& a_crSourceString, Tuint08& a_rDay, Tuint08& a_rMonth, Tsint32& a_rYear);
  //! Parse the day on value from the given string with support of special days (e.g. 'Thu>=8', 'lastFri').
  /*!
      \param a_crSourceString - Constant reference to the source string.
      \param a_rDayOnTable - Reference to the day on table.
      \param a_rID - Reference to the result ID value.
      \return true  - if the day value was parsed successfully. \n
              false - if the day value was not parsed successfully. \n
  */
  static Tbool parseDayOnValue(const NString::CString& a_crSourceString, NContainers::CArray<NDetails::STimeZoneRuleDayOn>& a_rDayOnTable, Tsint16& a_rID);
  //! Parse the time stamp value from the given string.
  /*!
      \param a_crSourceString - Constant reference to the source string.
      \param a_rTimeStamp - Reference to the result time stamp value.
      \param a_rTimeSuffix - Reference to the result time suffix value.
      \return true  - if the time stamp value was parsed successfully. \n
              false - if the time stamp value was not parsed successfully. \n
  */
  static Tbool parseTimeStampValue(const NString::CString& a_crSourceString, Tsint64& a_rTimeStamp, Tuint08& a_rTimeSuffix);
  //! Parse the coordinate value from the given string.
  /*!
      \param a_crSourceString - Constant reference to the source string.
      \param a_rCoordinate - Reference to the result coordinate value.
      \return true  - if the coordinate value was parsed successfully. \n
              false - if the coordinate value was not parsed successfully. \n
  */
  static Tbool parseCoordinateValue(const NString::CString& a_crSourceString, Tdouble& a_rCoordinate);

  //! Convert year, month and Olson day on token to the time zone rule day on structure.
  /*!
      Method parses Olson day on token (e.g. "Sun>=8", "lastSun") and  returns
      a time zone rule day on structure for the given year and month.

      \param a_crSourceString - Constant reference to the source string.
      \return Time zone rule day on structure which was converted from the given year, month and Olson day on token.
  */
  static NDetails::STimeZoneRuleDayOn convertToDayOnStructure(const NString::CString& a_crSourceString);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/time/timezone/CTimeZoneDatabaseCustom.inl>
/*==========================================================================*/
#endif
