/*!
 *  \file    CTimeZoneDatabase.hpp Default time zone database class provides
 *           all common time zone information (rules, history, country and
 *           region names). Default time zone database uses time zone tables
 *           which are prepared by the TZParser utility.
 *  \brief   Default time zone database class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Default time zone database class.

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
#ifndef __CTIMEZONEDATABASE_HPP__
#define __CTIMEZONEDATABASE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/string/CString.hpp>
#include <Depth/include/time/CDateTime.hpp>
#include <Depth/include/time/CTimeStamp.hpp>
#include <Depth/include/time/timezone/details/TZTable.hpp>
#include <Depth/include/utility/CPair.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*--------------------------------------------------------------------------*/
namespace NTimezone {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
class CTimeZone;
class CTimeZoneHistory;
class CTimeZoneRule;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Default time zone database class.
/*!
    Default time zone  database  class  provides  all  time  zone  information
    (rules, history, country and region names).

    Default time zone database uses time zone tables which are prepared by the
    TZParser utility.
*/
class BASE_API CTimeZoneDatabase
{
  // Friend class: Time zone class (CTimeZone).
  friend class CTimeZone;
  // Friend class: Time zone history class (CTimeZoneHistory).
  friend class CTimeZoneHistory;
  // Friend class: Time zone rule class (CTimeZoneRule).
  friend class CTimeZoneRule;

  //! Type for the MConceptDepthType constraint checking.
  typedef CTimeZoneDatabase TDepthCheckType;

  // Check CTimeZoneDatabase class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CTimeZoneDatabase();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneDatabase class.
  */
  CTimeZoneDatabase(const CTimeZoneDatabase& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTimeZoneDatabase();

  //! Operator: Assign another CTimeZoneDatabase class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneDatabase class.
      \return Reference to the current class instance.
  */
  CTimeZoneDatabase& operator = (const CTimeZoneDatabase& a_crInstance);

  //! Set another CTimeZoneDatabase class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneDatabase class.
      \return true  - if another time zone database was successfully set. \n
              false - if another time zone database was not successfully set. \n
  */
  Tbool set(const CTimeZoneDatabase& a_crInstance);

  //! Check if the current time zone database has valid properties.
  /*!
      For the default time zone class this method will always returns 'true'.

      \return true  - if the current time zone database has valid properties. \n
              false - if the current time zone database has not valid properties. \n
  */
  virtual Tbool isValid() const;

  //! Clear time zone database.
  /*!
      For the default time zone class this method will always returns 'true'.

      \return true  - if the time zone database was successfully cleared. \n
              false - if the time zone database was not successfully cleared. \n
  */
  virtual Tbool clear();

  //! Serialize CTimeZoneDatabase class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTimeZoneDatabase class instances.
  /*!
      \param a_rInstance - Reference to another CTimeZoneDatabase class instance.
  */
  void swap(CTimeZoneDatabase& a_rInstance);

protected:
  //! Check if the given time zone has valid properties in the current time zone database.
  /*!
      \param a_crTimeZoneStructure - Constant reference to the instance of the STimeZone structure.
      \return true  - if the given time zone has valid properties. \n
              false - if the given time zone has not valid properties. \n
  */
  virtual Tbool isValidTimeZone(const NDetails::STimeZone& a_crTimeZoneStructure) const;
  //! Check if the given time zone history has valid properties in the current time zone database.
  /*!
      \param a_crTimeZoneHistoryStructure - Constant reference to the instance of the STimeZoneHistory structure.
      \return true  - if the given time zone history has valid properties. \n
              false - if the given time zone history has not valid properties. \n
  */
  virtual Tbool isValidTimeZoneHistory(const NDetails::STimeZoneHistory& a_crTimeZoneHistoryStructure) const;
  //! Check if the given time zone rule has valid properties in the current time zone database.
  /*!
      \param a_crTimeZoneRuleStructure - Constant reference to the instance of the STimeZoneRule structure.
      \return true  - if the given time zone rule has valid properties. \n
              false - if the given time zone rule has not valid properties. \n
  */
  virtual Tbool isValidTimeZoneRule(const NDetails::STimeZoneRule& a_crTimeZoneRuleStructure) const;
  //! Check if the given time zone rule day on structure has valid properties in the current time zone database.
  /*!
      \param a_crTimeZoneRuleDayOnStructure - Constant reference to the instance of the STimeZoneRuleDayOn structure.
      \return true  - if the given time zone rule day on structure has valid properties. \n
              false - if the given time zone rule day on structure has not valid properties. \n
  */
  virtual Tbool isValidTimeZoneRuleDayOn(const NDetails::STimeZoneRuleDayOn& a_crTimeZoneRuleDayOnStructure) const;

  //! Get time zone country code by the given ID.
  /*!
      Default implementation of the method tries to get time zone country code
      value by the given ID from the default database prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns empty string.

      \param a_cID - Time zone country code ID.
      \return Time zone country code value.
  */
  virtual Tcsstr getZoneCountryCodeByID(const Tuint a_cID) const;
  //! Get time zone country name by the given ID.
  /*!
      Default implementation of the method tries to get time zone country name
      value by the given ID from the default database prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns empty string.

      \param a_cID - Time zone country name ID.
      \return Time zone country name value.
  */
  virtual Tcsstr getZoneCountryNameByID(const Tuint a_cID) const;
  //! Get time zone region name by the given ID.
  /*!
      Default implementation of the method tries to get time zone region  name
      value by the given ID from the default database prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns empty string.

      \param a_cID - Time zone region name ID.
      \return Time zone region name value.
  */
  virtual Tcsstr getZoneRegionNameByID(const Tuint a_cID) const;
  //! Get time zone name by the given ID.
  /*!
      Default implementation of the method tries to get time zone  name  value
      by the given  ID  from  the  default  database  prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns empty string.

      \param a_cID - Time zone name ID.
      \return Time zone name value.
  */
  virtual Tcsstr getZoneNameByID(const Tuint a_cID) const;
  //! Get time zone comments by the given ID.
  /*!
      Default implementation of the method tries to  get  time  zone  comments
      value by the given ID from the default database prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns empty string.

      \param a_cID - Time zone comments ID.
      \return Time zone comments value.
  */
  virtual Tcsstr getZoneCommentsByID(const Tuint a_cID) const;
  //! Get time zone history format by the given ID.
  /*!
      Default implementation of the method tries  to  get  time  zone  history
      format value by the given ID from the  default  database  prepared  with
      TZParser utility. If the index is out of bounds warning message will  be
      generated and method returns empty string.

      \param a_cID - Time zone history format ID.
      \return Time zone history format value.
  */
  virtual Tcsstr getZoneHistoryFormatByID(const Tuint a_cID) const;
  //! Get time zone rule name by the given ID.
  /*!
      Default implementation of the method tries to get time  zone  rule  name
      value by the given ID from the default database prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns empty string.

      \param a_cID - Time zone rule name ID.
      \return Time zone rule name value.
  */
  virtual Tcsstr getZoneRuleNameByID(const Tuint a_cID) const;
  //! Get time zone rule type by the given ID.
  /*!
      Default implementation of the method tries to get time  zone  rule  type
      value by the given ID from the default database prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns empty string.

      \param a_cID - Time zone rule type ID.
      \return Time zone rule type value.
  */
  virtual Tcsstr getZoneRuleTypeByID(const Tuint a_cID) const;
  //! Get time zone rule day on by the given ID.
  /*!
      Default implementation of the method tries to get time zone rule day  on
      value by the given ID from the default database prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns empty string.

      \param a_cID - Time zone rule day on ID.
      \return Time zone rule day on value.
  */
  virtual Tcsstr getZoneRuleDayOnByID(const Tuint a_cID) const;
  //! Get time zone rule day on structure by the given ID.
  /*!
      Default implementation of the method tries to get time zone rule day  on
      structure by the given  ID  from  the  default  database  prepared  with
      TZParser utility. If the index is out of bounds warning message will  be
      generated and method returns invalid time zone rule day on structure.

      \param a_cID - Time zone rule day on ID.
      \return Time zone rule day on structure.
  */
  virtual NDetails::STimeZoneRuleDayOn getZoneRuleDayOnStructureByID(const Tuint a_cID) const;
  //! Get time zone rule letters by the given ID.
  /*!
      Default implementation of the method tries to get time zone rule letters
      value by the given ID from the default database prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns empty string.

      \param a_cID - Time zone rule letters ID.
      \return Time zone rule letters value.
  */
  virtual Tcsstr getZoneRuleLettersByID(const Tuint a_cID) const;
  //! Get time zone coordinate by the given ID.
  /*!
      Default implementation of the method tries to get time  zone  coordinate
      value by the given ID from the default database prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns empty pair (0.0, 0.0).

      \param a_cID - Time zone coordinate ID.
      \return Time zone coordinate value.
  */
  virtual NUtility::CPair<Treal, Treal> getZoneCoordinateByID(const Tuint a_cID) const;
  //! Get time zone by the given ID.
  /*!
      Default implementation of the method tries to get time zone value by the
      given ID from the default database prepared with  TZParser  utility.  If
      the index is out of bounds warning message will be generated and  method
      returns invalid time zone.

      \param a_cID - Time zone ID.
      \return Time zone value.
  */
  virtual CTimeZone getZoneByID(const Tuint a_cID) const;
  //! Get time zone history by the given ID.
  /*!
      Default implementation of the method tries  to  get  time  zone  history
      value by the given ID from the default database prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns invalid time zone history.

      \param a_cID - Time zone history ID.
      \return Time zone history value.
  */
  virtual CTimeZoneHistory getZoneHistoryByID(const Tuint a_cID) const;
  //! Get time zone rule by the given ID.
  /*!
      Default implementation of the method tries to get time zone  rule  value
      by the given  ID  from  the  default  database  prepared  with  TZParser
      utility. If the index is out of bounds warning message will be generated
      and method returns invalid time zone rule.

      \param a_cID - Time zone rule ID.
      \return Time zone rule value.
  */
  virtual CTimeZoneRule getZoneRuleByID(const Tuint a_cID) const;

  //! Get date with first week day occurrence starting from the given date.
  /*!
      Method search forward required date with a given week day starting  from
      the given date. For example we need to know the date of the first Sunday
      starting from the 1st of December of 2010. This method will  return  the
      5th of December 2010, which is Sunday.

      \param a_crDate - Constant reference to the instance of the CDateTime class.
      \param a_cWeekDay - Constant reference to the required week day.
      \return Date with first week day occurrence starting from the given date.
  */
  static CDate getFirstWeekDayOccurrence(const CDate& a_crDate, const CDate::EWeekDay a_cWeekDay);
  //! Get date with last week day occurrence starting from the given date.
  /*!
      Method search backward required date with a given week day starting from
      the given date. For example we need to know the date of the last  Sunday
      starting from the 31th of December of 2010. This method will return  the
      26th of December 2010, which is Sunday.

      \param a_crDate - Constant reference to the instance of the CDateTime class.
      \param a_cWeekDay - Constant reference to the required week day.
      \return Date with last week day occurrence starting from the given date.
  */
  static CDate getLastWeekDayOccurrence(const CDate& a_crDate, const CDate::EWeekDay a_cWeekDay);

  //! Convert year, month and Olson day on value to the date value.
  /*!
      Method analyzes Olson  day  on  value  (e.g.  "Sun>=8",  "lastSun")  and
      returns a valid date value for the given year and month.

      \param a_cYear - Year value.
      \param a_cMonth - Month value in range from 1 to 12.
      \param a_crTimeZoneRuleDayOnStructure - Constant reference to the instance of the STimeZoneRuleDayOn structure.
      \return Date which was converted from the given year, month and Olson day on value.
  */
  static CDate convertToDate(const Tsint a_cYear, const Tuint a_cMonth, const NDetails::STimeZoneRuleDayOn& a_crTimeZoneRuleDayOnStructure);

  //! Get cutover date & time for the given time zone rule and year.
  /*!
      Method checks if the given time zone rule has cutover date for the given
      year. If the date is found it is returned.

      \param a_crTimeZoneRule - Constant reference to the instance of the CTimeZoneRule class.
      \param a_cYear - Year value.
      \param a_rCutoverDateTime - Reference to the returned cutover date & time.
      \return true  - if the cutover date & time was found in the given time zone rule for the given year. \n
              false - if the cutover date & time was not found in the given time zone rule for the given year. \n
  */
  static Tbool getCutoverDateTime(const CTimeZoneRule& a_crTimeZoneRule, const Tsint a_cYear, CDateTime& a_rCutoverDateTime);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#if (!defined(__CTIMEZONE_INCLUDED__) && !defined(__CTIMEZONEHISTORY_INCLUDED__) && !defined(__CTIMEZONERULE_INCLUDED__))
#define __CTIMEZONE_INCLUDED__
#define __CTIMEZONEHISTORY_INCLUDED__
#define __CTIMEZONERULE_INCLUDED__
/*--------------------------------------------------------------------------*/
#undef __CTIMEZONE_HPP__
#include <Depth/include/time/timezone/CTimeZone.hpp>
#undef __CTIMEZONEHISTORY_HPP__
#include <Depth/include/time/timezone/CTimeZoneHistory.hpp>
#undef __CTIMEZONERULE_HPP__
#include <Depth/include/time/timezone/CTimeZoneRule.hpp>
/*--------------------------------------------------------------------------*/
#undef __CTIMEZONE_INCLUDED__
#undef __CTIMEZONEHISTORY_INCLUDED__
#undef __CTIMEZONERULE_INCLUDED__
#endif
/*--------------------------------------------------------------------------*/
#include <Depth/include/time/timezone/CTimeZoneDatabase.inl>
/*==========================================================================*/
#endif
