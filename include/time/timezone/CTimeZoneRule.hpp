/*!
 *  \file    CTimeZoneRule.hpp Time zone rule class provides the rule
 *           information about the time zone.
 *  \brief   Time zone rule class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time zone rule class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time zone
    VERSION:   1.0
    CREATED:   10.12.2010 20:24:46

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
#ifndef __CTIMEZONERULE_HPP__
#define __CTIMEZONERULE_HPP__
/*==========================================================================*/
#include <Depth/include/time/timezone/CTimeZoneDatabase.hpp>
/*==========================================================================*/
#if (defined(__CTIMEZONERULE_INCLUDED__) || defined(__DOXYGEN__))
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
class CTimeZoneDatabase;
class CTimeZoneDatabaseCustom;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Time zone rule class.
/*!
    Time zone rule class provides rule information about the time zone.
*/
class BASE_API CTimeZoneRule
{
  // Friend class: Default time zone database class (CTimeZoneDatabase).
  friend class CTimeZoneDatabase;
  // Friend class: Custom time zone database class (CTimeZoneDatabaseCustom).
  friend class CTimeZoneDatabaseCustom;

  //! Type for the MConceptDepthType constraint checking.
  typedef CTimeZoneRule TDepthCheckType;

  // Check CTimeZoneRule class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Create and initialize time zone rule class instance with the  time  zone
      database.

      \param a_crTimeZoneDatabase - Constant reference to the instance of the CTimeZoneDatabase class (default is NDepth::NTime::NTimezone::CTimeZoneDatabase()).
  */
  CTimeZoneRule(const CTimeZoneDatabase& a_crTimeZoneDatabase = CTimeZoneDatabase());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneRule class.
  */
  CTimeZoneRule(const CTimeZoneRule& a_crInstance);
  //! Class destructor.
 ~CTimeZoneRule();

  //! Operator: Assign another CTimeZoneRule class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneRule class.
      \return Reference to the current class instance.
  */
  CTimeZoneRule& operator = (const CTimeZoneRule& a_crInstance);

  //! Set another CTimeZoneRule class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneRule class.
  */
  void set(const CTimeZoneRule& a_crInstance);

  //! Check if the current time zone rule has valid properties.
  /*!
      \return true  - if the current time zone rule has valid properties. \n
              false - if the current time zone rule has not valid properties. \n
  */
  Tbool isValid() const;

  //! Get time zone rule ID property.
  /*!
      \return Time zone rule ID property.
  */
  Tuint getID() const;
  //! Get time zone rule Name property.
  /*!
      \return Time zone rule Name property.
  */
  Tcsstr getName() const;
  //! Get time zone rule YearFrom property.
  /*!
      \return Time zone rule YearFrom property.
  */
  Tsint getYearFrom() const;
  //! Get time zone rule YearTo property.
  /*!
      \return Time zone rule YearTo property.
  */
  Tsint getYearTo() const;
  //! Get time zone rule Type property.
  /*!
      \return Time zone rule Type property.
  */
  Tcsstr getType() const;
  //! Get time zone rule MonthIn property.
  /*!
      \return Time zone rule MonthIn property.
  */
  Tuint getMonthIn() const;
  //! Get time zone rule DayOn property.
  /*!
      \return Time zone rule DayOn property.
  */
  Tcsstr getDayOn() const;
  //! Get time zone rule TimeAt property.
  /*!
      \return Time zone rule TimeAt property.
  */
  CTimeStamp getTimeAt() const;
  //! Get time zone rule TimeSave property.
  /*!
      \return Time zone rule TimeSave property.
  */
  CTimeStamp getTimeSave() const;
  //! Get time zone rule TimeSuffix property.
  /*!
      \return Time zone rule TimeSuffix property.
  */
  Tschar getTimeSuffix() const;
  //! Get time zone rule Letters property.
  /*!
      \return Time zone rule Letters property.
  */
  Tcsstr getLetters() const;

  //! Get the first time zone rule for the same name.
  /*!
      \return The first time zone rule for the same name.
  */
  CTimeZoneRule getRuleFirst() const;
  //! Get the previous time zone rule with the same name.
  /*!
      Method will return invalid time zone rule in case of the current rule is
      the first one.

      \return The previous time zone rule with the same name.
  */
  CTimeZoneRule getRulePrev() const;
  //! Get the next time zone rule with the same name.
  /*!
      Method will return invalid time zone rule in case of the current rule is
      the last one.

      \return The next time zone rule with the same name.
  */
  CTimeZoneRule getRuleNext() const;
  //! Get the last time zone rule for the same name.
  /*!
      \return The last time zone rule for the same name.
  */
  CTimeZoneRule getRuleLast() const;

  //! Get constant reference to the current time zone database.
  /*!
      \return Constant reference to the current time zone database.
  */
  const CTimeZoneDatabase& getDatabase() const;

  //! Serialize CTimeZoneRule class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTimeZoneRule class instances.
  /*!
      \param a_rInstance - Reference to another CTimeZoneRule class instance.
  */
  void swap(CTimeZoneRule& a_rInstance);

private:
  const CTimeZoneDatabase* m_cpTimeZoneDatabase;   //!< Constant pointer to the time zone database.
  NDetails::STimeZoneRule m_TimeZoneRuleStructure; //!< Time zone rule internal structure.

  //! Initialize time zone rule class with time zone database and time zone rule structure.
  /*!
      Create and initialize time zone rule class instance with the  time  zone
      database and time zone rule structure.

      \param a_crTimeZoneDatabase - Constant reference to the instance of the CTimeZoneDatabase class.
      \param a_crTimeZoneRuleStructure - Constant reference to the instance of the STimeZoneRule structure.
  */
  CTimeZoneRule(const CTimeZoneDatabase& a_crTimeZoneDatabase, const NDetails::STimeZoneRule& a_crTimeZoneRuleStructure);

  //! Get time zone rule DayOn property through the STimeZoneRuleDayOn structure.
  /*!
      \return Time zone rule DayOn property through the STimeZoneRuleDayOn structure.
  */
  NDetails::STimeZoneRuleDayOn getDayOnStructure() const;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/time/timezone/CTimeZoneRule.inl>
/*==========================================================================*/
#endif
/*==========================================================================*/
#endif
