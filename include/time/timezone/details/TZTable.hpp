/*!
 *  \file    TZTable.hpp Olson Time Zone Info table was generated with
 *           TZParser utility and used as a source of Time Zone information.
 *  \brief   Generated Olson Time Zone Info table.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Generated Olson Time Zone Info table.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time zone details.
    VERSION:   1.0
    CREATED:   15.06.2010 20:27:19

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
#ifndef __TZTABLE_HPP__
#define __TZTABLE_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*--------------------------------------------------------------------------*/
namespace NTimezone {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* STRUCTURE DECLARATIONS                                                   */
/*==========================================================================*/
struct BASE_API STimeZone                   //! Time Zone structure.
{
  Tsint16 m_ID;                             //!< Zone ID (could be -1).
  Tsint16 m_CountryCodeID;                  //!< County code ID (could be -1).
  Tsint16 m_CountryNameID;                  //!< County name ID (could be -1).
  Tsint16 m_RegionNameID;                   //!< Region name ID (could be -1).
  Tsint16 m_ZoneNameID;                     //!< Zone name ID (could be -1).
  Tsint16 m_ZoneCommentsID;                 //!< Zone comments ID (could be -1).
  Tsint16 m_ZoneCoordinatesID;              //!< Zone coordinates ID (could be -1).
  Tsint16 m_ZoneHistoryID;                  //!< Zone history first ID (could be -1).

  static const STimeZone INVALID;           //!< Invalid structure instance.
};
/*--------------------------------------------------------------------------*/
struct BASE_API STimeZoneHistory            //! Time Zone history structure.
{
  Tsint32 m_ID;                             //!< Zone history ID (could be -1).
  Tsint64 m_GMTOffset;                      //!< Zone GMT offset time stamp.
  Tsint16 m_RuleID;                         //!< Zone rule ID (could be -1).
  Tsint16 m_FormatID;                       //!< Zone format ID (could be -1).
  Tsint64 m_Until;                          //!< Zone until time stamp.
  Tsint16 m_HistoryPrevID;                  //!< Zone history previous ID (could be -1).
  Tsint16 m_HistoryNextID;                  //!< Zone history next ID (could be -1).

  // Utility fields.
  Tuint32 m_Padding;                        //!< Structure align padding.

  static const STimeZoneHistory INVALID;    //!< Invalid structure instance.
};
/*--------------------------------------------------------------------------*/
struct BASE_API STimeZoneRule               //! Time Zone rule structure.
{
  Tsint16 m_ID;                             //!< Zone rule ID (could be -1).
  Tsint16 m_RuleNameID;                     //!< Zone rule name ID (could be -1).
  Tsint32 m_YearFrom;                       //!< Zone rule from year value.
  Tsint32 m_YearTo;                         //!< Zone rule to year value.
  Tsint16 m_RuleTypeID;                     //!< Zone rule type ID (could be -1).
  Tuint08 m_MonthIn;                        //!< Zone rule in month value (1 - 12).
  Tsint16 m_DayOnID;                        //!< Zone rule day on value ID (could be -1).
  Tsint64 m_TimeAt;                         //!< Zone rule at time value.
  Tsint64 m_TimeSave;                       //!< Zone rule save time stamp.
  Tuint08 m_TimeSuffix;                     //!< Zone rule save time stamp suffix (default is 0).
  Tsint16 m_RuleLettersID;                  //!< Zone rule letters ID (could be -1).
  Tsint16 m_RulePrevID;                     //!< Zone rule previous ID (could be -1).
  Tsint16 m_RuleNextID;                     //!< Zone rule next ID (could be -1).

  static const STimeZoneRule INVALID;       //!< Invalid structure instance.
};
/*--------------------------------------------------------------------------*/
struct BASE_API STimeZoneRuleDayOn          //! Time Zone rule day on value structure.
{
  Tsint08 m_ID;                             //!< Zone rule day on ID (could be -1).
  Tsint08 m_LastFlag;                       //!< Zone rule day on last flag (could be -1, 0 or 1, e.g. "lastSun").
  Tsint08 m_WeekDayFlag;                    //!< Zone rule day on week day flag (could be -1, 0 or 1, e.g. "lastSun", "Sun>=16").
  Tsint08 m_WeekDay;                        //!< Zone rule day on week day value (could be -1, 0 for "Sun", 1 for "Mon", ..., 6 for "Sat").
  Tsint08 m_Day;                            //!< Zone rule day on value in the range 1 - 31 (could be -1).

  static const STimeZoneRuleDayOn INVALID;  //!< Invalid structure instance.

  //! Operator: Equal to another STimeZoneRuleDayOn structure instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the STimeZoneRuleDayOn structure.
      \param a_crInstance2 - Constant reference to another instance of the STimeZoneRuleDayOn structure.
      \return true  - if STimeZoneRuleDayOn structure instance is equal to another one. \n
              false - if STimeZoneRuleDayOn structure instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const STimeZoneRuleDayOn& a_crInstance1, const STimeZoneRuleDayOn& a_crInstance2);
  //! Operator: Not equal to another STimeZoneRuleDayOn structure instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the STimeZoneRuleDayOn structure.
      \param a_crInstance2 - Constant reference to another instance of the STimeZoneRuleDayOn structure.
      \return true  - if STimeZoneRuleDayOn structure instance is not equal to another one. \n
              false - if STimeZoneRuleDayOn structure instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const STimeZoneRuleDayOn& a_crInstance1, const STimeZoneRuleDayOn& a_crInstance2);
};
/*==========================================================================*/
/* GLOBAL VARIABLES DECLARATIONS                                            */
/*==========================================================================*/
//! Global table of Time Zone country codes.
extern BASE_API Tcsstr the_ZoneCountryCodes[];
//! Global table of Time Zone country names.
extern BASE_API Tcsstr the_ZoneCountryNames[];
//! Global table of Time Zone region names.
extern BASE_API Tcsstr the_ZoneRegionNames[];
//! Global table of Time Zone names.
extern BASE_API Tcsstr the_ZoneNames[];
//! Global table of Time Zone comments.
extern BASE_API Tcsstr the_ZoneComments[];
//! Global table of Time Zone coordinates.
extern BASE_API const Tdouble the_ZoneCoordinates[][2];
//! Global table of the Time Zone Info database.
extern BASE_API const STimeZone the_TimeZones[];
/*--------------------------------------------------------------------------*/
//! Global table of Time Zone History format strings.
extern BASE_API Tcsstr the_ZoneHistoryFormats[];
//! Global table of the Time Zone History database.
extern BASE_API const STimeZoneHistory the_TimeZoneHistory[];
/*--------------------------------------------------------------------------*/
//! Global table of Time Zone Rule names.
extern BASE_API Tcsstr the_ZoneRuleNames[];
//! Global table of Time Zone Rule types.
extern BASE_API Tcsstr the_ZoneRuleTypes[];
//! Global table of Time Zone Rule day on values.
extern BASE_API Tcsstr the_ZoneRuleDayOn[];
//! Global table of Time Zone Rule day on structures.
extern BASE_API const STimeZoneRuleDayOn the_ZoneRuleDayOnTable[];
//! Global table of Time Zone Rule letters.
extern BASE_API Tcsstr the_ZoneRuleLetters[];
//! Global table of the Time Zone Rules database.
extern BASE_API const STimeZoneRule the_TimeZoneRules[];
/*==========================================================================*/
/* GLOBAL FUNCTIONS DECLARATIONS                                            */
/*==========================================================================*/
//! Get count of Time Zone country codes.
/*!
    \return Count of Time Zone country codes.
*/
BASE_API Tuint getCountOfZoneCountryCodes();
//! Get count of Time Zone country names.
/*!
    \return Count of Time Zone country names.
*/
BASE_API Tuint getCountOfZoneCountryNames();
//! Get count of Time Zone region names.
/*!
    \return Count of Time Zone region names.
*/
BASE_API Tuint getCountOfZoneRegionNames();
//! Get count of Time Zone names.
/*!
    \return Count of Time Zone names.
*/
BASE_API Tuint getCountOfZoneNames();
//! Get count of Time Zone comments.
/*!
    \return Count of Time Zone comments.
*/
BASE_API Tuint getCountOfZoneComments();
//! Get count of Time Zone coordinates.
/*!
    \return Count of Time Zone coordinates.
*/
BASE_API Tuint getCountOfZoneCoordinates();
//! Get count of Time Zone History format strings.
/*!
    \return Count of Time Zone History format strings.
*/
BASE_API Tuint getCountOfZoneHistoryFormats();
//! Get count of Time Zone Rule names.
/*!
    \return Count of Time Zone Rule names.
*/
BASE_API Tuint getCountOfZoneRuleNames();
//! Get count of Time Zone Rule types.
/*!
    \return Count of Time Zone Rule types.
*/
BASE_API Tuint getCountOfZoneRuleTypes();
//! Get count of Time Zone Rule day on values.
/*!
    \return Count of Time Zone Rule day on values.
*/
BASE_API Tuint getCountOfZoneRuleDayOn();
//! Get count of Time Zone Rule day on structures.
/*!
    \return Count of Time Zone Rule day on structures.
*/
BASE_API Tuint getCountOfZoneRuleDayOnTable();
//! Get count of Time Zone Rule letters.
/*!
    \return Count of Time Zone Rule letters.
*/
BASE_API Tuint getCountOfZoneRuleLetters();
//! Get count of Time Zone Info database.
/*!
    \return Count of Time Zone Info database.
*/
BASE_API Tuint getCountOfTimeZones();
//! Get count of Time Zone History database.
/*!
    \return Count of Time Zone History database.
*/
BASE_API Tuint getCountOfTimeZoneHistory();
//! Get count of Time Zone Rules database.
/*!
    \return Count of Time Zone Rules database.
*/
BASE_API Tuint getCountOfTimeZoneRules();
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/time/timezone/details/TZTable.inl>
/*==========================================================================*/
#endif
