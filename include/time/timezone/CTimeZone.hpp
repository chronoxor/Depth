/*!
 *  \file    CTimeZone.hpp Time zone class provides the all information about
 *           the time zone.
 *  \brief   Time zone class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time zone class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time zone
    VERSION:   1.0
    CREATED:   07.12.2010 20:18:24

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
#ifndef __CTIMEZONE_HPP__
#define __CTIMEZONE_HPP__
/*==========================================================================*/
#include <Depth/include/time/timezone/CTimeZoneDatabase.hpp>
/*==========================================================================*/
#if (defined(__CTIMEZONE_INCLUDED__) || defined(__DOXYGEN__))
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
//! Time zone class.
/*!
    Time zone class provides all information about the time zone.
*/
class BASE_API CTimeZone
{
  // Friend class: Default time zone database class (CTimeZoneDatabase).
  friend class CTimeZoneDatabase;
  // Friend class: Custom time zone database class (CTimeZoneDatabaseCustom).
  friend class CTimeZoneDatabaseCustom;

  //! Type for the MConceptDepthType constraint checking.
  typedef CTimeZone TDepthCheckType;

  // Check CTimeZone class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Create and initialize time  zone  class  instance  with  the  time  zone
      database.

      \param a_crTimeZoneDatabase - Constant reference to the instance of the CTimeZoneDatabase class (default is NDepth::NTime::NTimezone::CTimeZoneDatabase()).
  */
  CTimeZone(const CTimeZoneDatabase& a_crTimeZoneDatabase = CTimeZoneDatabase());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZone class.
  */
  CTimeZone(const CTimeZone& a_crInstance);
  //! Class destructor.
 ~CTimeZone();

  //! Operator: Assign another CTimeZone class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZone class.
      \return Reference to the current class instance.
  */
  CTimeZone& operator = (const CTimeZone& a_crInstance);

  //! Set another CTimeZone class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTimeZone class.
  */
  void set(const CTimeZone& a_crInstance);

  //! Check if the current time zone has valid properties.
  /*!
      \return true  - if the current time zone has valid properties. \n
              false - if the current time zone has not valid properties. \n
  */
  Tbool isValid() const;

  //! Convert the given date & time value from local time to UTC time.
  /*!
      Method gets GMT offset of the current time zone for  the  given  date  &
      time and use it to convert the given date & time value from UTC time  to
      local time.

      \param a_crDateTime - Constant reference to the instance of the CDateTime class.
      \return Date & time value converted from the local time to the UTC time.
  */
  CDateTime convertUTCToLocal(const CDateTime& a_crDateTime) const;
  //! Convert the given date & time value from UTC time to local time.
  /*!
      Method gets GMT offset of the current time zone for  the  given  date  &
      time and use it to convert the given date & time value from UTC time  to
      local time.

      \param a_crDateTime - Constant reference to the instance of the CDateTime class.
      \return Date & time value converted from the UTC time to the local time.
  */
  CDateTime convertLocalToUTC(const CDateTime& a_crDateTime) const;

  //! Get time zone ID property.
  /*!
      \return Time zone ID property.
  */
  Tuint getID() const;
  //! Get time zone CountryCode property.
  /*!
      \return Time zone CountryCode property.
  */
  Tcsstr getCountryCode() const;
  //! Get time zone CountryName property.
  /*!
      \return Time zone CountryName property.
  */
  Tcsstr getCountryName() const;
  //! Get time zone RegionName property.
  /*!
      \return Time zone RegionName property.
  */
  Tcsstr getRegionName() const;
  //! Get time zone ZoneName property.
  /*!
      \return Time zone ZoneName property.
  */
  Tcsstr getZoneName() const;
  //! Get time zone ZoneComments property.
  /*!
      \return Time zone ZoneComments property.
  */
  Tcsstr getZoneComments() const;
  //! Get time zone ZoneCoordinate property.
  /*!
      \return Time zone ZoneCoordinate property.
  */
  NUtility::CPair<Treal, Treal> getZoneCoordinate() const;

  //! Get time zone GMTOffset property for the given date & time.
  /*!
      Method searches for corresponding time zone history  and  rule  for  the
      given date & time. GMTOffset will be calculated using GMTOffset property
      of the found time zone history and TimeSave property of the  found  time
      zone rule.

      \param a_crDateTime - Constant reference to the instance of the CDateTime class.
      \return Time zone GMTOffset property for the given date & time.
  */
  CTimeStamp getGMTOffset(const CDateTime& a_crDateTime) const;
  //! Get time zone Format property for the given date & time.
  /*!
      Method searches for corresponding time zone history  and  rule  for  the
      given date & time. Format will be composed using Format property of  the
      found time zone history and Letters property  of  the  found  time  zone
      rule.

      \param a_crDateTime - Constant reference to the instance of the CDateTime class.
      \return Time zone Format property for the given date & time.
  */
  NString::CString getFormat(const CDateTime& a_crDateTime) const;

  //! Get time zone History property for the given date & time.
  /*!
      \param a_crDateTime - Constant reference to the instance of the CDateTime class.
      \return Time zone History property for the given date & time.
  */
  CTimeZoneHistory getHistory(const CDateTime& a_crDateTime) const;
  //! Get the first time zone History property for the current time zone.
  /*!
      \return The first time zone History property for the current time zone.
  */
  CTimeZoneHistory getHistoryFirst() const;
  //! Get the last time zone History property for the current time zone.
  /*!
      \return The last time zone History property for the current time zone.
  */
  CTimeZoneHistory getHistoryLast() const;

  //! Get constant reference to the current time zone database.
  /*!
      \return Constant reference to the current time zone database.
  */
  const CTimeZoneDatabase& getDatabase() const;

  //! Serialize CTimeZone class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTimeZone class instances.
  /*!
      \param a_rInstance - Reference to another CTimeZone class instance.
  */
  void swap(CTimeZone& a_rInstance);

private:
  const CTimeZoneDatabase* m_cpTimeZoneDatabase; //!< Constant pointer to the time zone database.
  NDetails::STimeZone m_TimeZoneStructure;       //!< Time zone internal structure.

  //! Initialize time zone class with time zone database and time zone structure.
  /*!
      Create and initialize time  zone  class  instance  with  the  time  zone
      database and time zone structure.

      \param a_crTimeZoneDatabase - Constant reference to the instance of the CTimeZoneDatabase class.
      \param a_crTimeZoneStructure - Constant reference to the instance of the STimeZone structure.
  */
  CTimeZone(const CTimeZoneDatabase& a_crTimeZoneDatabase, const NDetails::STimeZone& a_crTimeZoneStructure);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/time/timezone/CTimeZone.inl>
/*==========================================================================*/
#endif
/*==========================================================================*/
#endif
