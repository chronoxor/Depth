/*!
 *  \file    CTimeZoneHistory.hpp Time zone history class provides the history
 *           information about the time zone.
 *  \brief   Time zone history class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time zone history class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time zone
    VERSION:   1.0
    CREATED:   10.12.2010 19:35:22

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
#ifndef __CTIMEZONEHISTORY_HPP__
#define __CTIMEZONEHISTORY_HPP__
/*==========================================================================*/
#include <Depth/include/time/timezone/CTimeZoneDatabase.hpp>
/*==========================================================================*/
#if (defined(__CTIMEZONEHISTORY_INCLUDED__) || defined(__DOXYGEN__))
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
//! Time zone history class.
/*!
    Time zone history class provides history information about the time zone.
*/
class BASE_API CTimeZoneHistory
{
  // Friend class: Default time zone database class (CTimeZoneDatabase).
  friend class CTimeZoneDatabase;
  // Friend class: Custom time zone database class (CTimeZoneDatabaseCustom).
  friend class CTimeZoneDatabaseCustom;

  //! Type for the MConceptDepthType constraint checking.
  typedef CTimeZoneHistory TDepthCheckType;

  // Check CTimeZoneHistory class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Create and initialize time zone history class  instance  with  the  time
      zone database.

      \param a_crTimeZoneDatabase - Constant reference to the instance of the CTimeZoneDatabase class (default is NDepth::NTime::NTimezone::CTimeZoneDatabase()).
  */
  CTimeZoneHistory(const CTimeZoneDatabase& a_crTimeZoneDatabase = CTimeZoneDatabase());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneHistory class.
  */
  CTimeZoneHistory(const CTimeZoneHistory& a_crInstance);
  //! Class destructor.
 ~CTimeZoneHistory();

  //! Operator: Assign another CTimeZoneHistory class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneHistory class.
      \return Reference to the current class instance.
  */
  CTimeZoneHistory& operator = (const CTimeZoneHistory& a_crInstance);

  //! Set another CTimeZoneHistory class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZoneHistory class.
  */
  void set(const CTimeZoneHistory& a_crInstance);

  //! Check if the current time zone history has valid properties.
  /*!
      \return true  - if the current time zone history has valid properties. \n
              false - if the current time zone history has not valid properties. \n
  */
  Tbool isValid() const;

  //! Get time zone history ID property.
  /*!
      \return Time zone history ID property.
  */
  Tuint getID() const;
  //! Get time zone history GMTOffset property.
  /*!
      \return Time zone history GMTOffset property.
  */
  CTimeStamp getGMTOffset() const;
  //! Get time zone history Format property.
  /*!
      \return Time zone history Format property.
  */
  Tcsstr getFormat() const;
  //! Get time zone history Until property.
  /*!
      \return Time zone history Until property.
  */
  CTimeStamp getUntil() const;

  //! Get time zone Rule property for the given date & time.
  /*!
      \param a_crDateTime - Constant reference to the instance of the CDateTime class.
      \return Time zone Rule property for the given date & time.
  */
  CTimeZoneRule getRule(const CDateTime& a_crDateTime) const;
  //! Get time zone Rule property for the given date & time and return cutover date & time.
  /*!
      \param a_crDateTime - Constant reference to the instance of the CDateTime class.
      \param a_rCutoverDateTime - Reference to the returned cutover date & time.
      \return Time zone Rule property for the given date & time.
  */
  CTimeZoneRule getRule(const CDateTime& a_crDateTime, CDateTime& a_rCutoverDateTime) const;
  //! Get the first time zone Rule property for the current time zone history.
  /*!
      \return The first time zone Rule property for the current time zone history.
  */
  CTimeZoneRule getRuleFirst() const;
  //! Get the last time zone Rule properties for the current time zone history.
  /*!
      \return The last time zone Rule property for the current time zone history.
  */
  CTimeZoneRule getRuleLast() const;

  //! Get the first time zone history for the same time zone.
  /*!
      \return The first time zone history for the same time zone.
  */
  CTimeZoneHistory getHistoryFirst() const;
  //! Get the previous time zone history for the same time zone.
  /*!
      Method will return invalid time zone history  in  case  of  the  current
      history is the first one.

      \return The previous time zone history for the same time zone.
  */
  CTimeZoneHistory getHistoryPrev() const;
  //! Get the next time zone history for the same time zone.
  /*!
      Method will return invalid time zone history  in  case  of  the  current
      history is the last one.

      \return The next time zone history for the same time zone.
  */
  CTimeZoneHistory getHistoryNext() const;
  //! Get the last time zone history for the same time zone.
  /*!
      \return The last time zone history for the same time zone.
  */
  CTimeZoneHistory getHistoryLast() const;

  //! Get constant reference to the current time zone database.
  /*!
      \return Constant reference to the current time zone database.
  */
  const CTimeZoneDatabase& getDatabase() const;

  //! Serialize CTimeZoneHistory class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTimeZoneHistory class instances.
  /*!
      \param a_rInstance - Reference to another CTimeZoneHistory class instance.
  */
  void swap(CTimeZoneHistory& a_rInstance);

private:
  const CTimeZoneDatabase* m_cpTimeZoneDatabase;         //!< Constant pointer to the time zone database.
  NDetails::STimeZoneHistory m_TimeZoneHistoryStructure; //!< Time zone history internal structure.

  //! Initialize time zone history class with time zone database and time zone history structure.
  /*!
      Create and initialize time zone history class  instance  with  the  time
      zone database and time zone history structure.

      \param a_crTimeZoneDatabase - Constant reference to the instance of the CTimeZoneDatabase class.
      \param a_crTimeZoneHistoryStructure - Constant reference to the instance of the STimeZoneHistory structure.
  */
  CTimeZoneHistory(const CTimeZoneDatabase& a_crTimeZoneDatabase, const NDetails::STimeZoneHistory& a_crTimeZoneHistoryStructure);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/time/timezone/CTimeZoneHistory.inl>
/*==========================================================================*/
#endif
/*==========================================================================*/
#endif
