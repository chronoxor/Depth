/*!
 *  \file    CTimeZone.cpp Time zone class provides the all information about
 *           the time zone.
 *  \brief   Time zone class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time zone class (source).

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/algorithms/string/AReplaceStringAll.hpp>
#include <Depth/include/time/timezone/CTimeZone.hpp>
/*==========================================================================*/
#ifndef __CTIMEZONE_CPP__
#define __CTIMEZONE_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*--------------------------------------------------------------------------*/
namespace NTimezone {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CTimeZone::CTimeZone(const CTimeZoneDatabase& a_crTimeZoneDatabase/* = CTimeZoneDatabase() */) :
  m_cpTimeZoneDatabase(&a_crTimeZoneDatabase),
  m_TimeZoneStructure(NDetails::STimeZone::INVALID)
{ CALL

}
/*--------------------------------------------------------------------------*/
CDateTime CTimeZone::convertUTCToLocal(const CDateTime& a_crDateTime) const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return CDateTime(a_crDateTime);
  }

  // Local date & time is a UTC one plus GMT offset of the given time zone.
  return CDateTime(a_crDateTime.getTimeStamp() + getGMTOffset(a_crDateTime));
}
/*--------------------------------------------------------------------------*/
CDateTime CTimeZone::convertLocalToUTC(const CDateTime& a_crDateTime) const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return CDateTime(a_crDateTime);
  }

  // UTC date & time is a local one minus GMT offset of the given time zone.
  return CDateTime(a_crDateTime.getTimeStamp() - getGMTOffset(a_crDateTime));
}
/*--------------------------------------------------------------------------*/
Tuint CTimeZone::getID() const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return 0;
  }

  return m_TimeZoneStructure.m_ID;
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZone::getCountryCode() const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return ASC("");
  }

  // Check the index of the current time zone country code.
  if (m_TimeZoneStructure.m_CountryCodeID < 0)
    return ASC("");

  // Get time zone country code value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneCountryCodeByID((Tuint)m_TimeZoneStructure.m_CountryCodeID);
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZone::getCountryName() const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return ASC("");
  }

  // Check the index of the current time zone country name.
  if (m_TimeZoneStructure.m_CountryNameID < 0)
    return ASC("");

  // Get time zone country name value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneCountryNameByID((Tuint)m_TimeZoneStructure.m_CountryNameID);
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZone::getRegionName() const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return ASC("");
  }

  // Check the index of the current time zone region name.
  if (m_TimeZoneStructure.m_RegionNameID < 0)
    return ASC("");

  // Get time zone region name value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneRegionNameByID((Tuint)m_TimeZoneStructure.m_RegionNameID);
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZone::getZoneName() const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return ASC("");
  }

  // Check the index of the current time zone name.
  if (m_TimeZoneStructure.m_ZoneNameID < 0)
    return ASC("");

  // Get time zone name value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneNameByID((Tuint)m_TimeZoneStructure.m_ZoneNameID);
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZone::getZoneComments() const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return ASC("");
  }

  // Check the index of the current time zone comments.
  if (m_TimeZoneStructure.m_ZoneCommentsID < 0)
    return ASC("");

  // Get time zone comments value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneCommentsByID((Tuint)m_TimeZoneStructure.m_ZoneCommentsID);
}
/*--------------------------------------------------------------------------*/
NUtility::CPair<Treal, Treal> CTimeZone::getZoneCoordinate() const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return NUtility::CPair<Treal, Treal>(0.0, 0.0);
  }

  // Check the index of the current time zone coordinates.
  if (m_TimeZoneStructure.m_ZoneCoordinatesID < 0)
    return NUtility::CPair<Treal, Treal>(0.0, 0.0);

  // Get time zone coordinates value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneCoordinateByID((Tuint)m_TimeZoneStructure.m_ZoneCoordinatesID);
}
/*--------------------------------------------------------------------------*/
CTimeStamp CTimeZone::getGMTOffset(const CDateTime& a_crDateTime) const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return CTimeStamp(0);
  }

  // Try to find suitable time zone history.
  CTimeZoneHistory history(getHistory(a_crDateTime));
  if (history.isValid())
  {
    // Try to find suitable time zone rule.
    CTimeZoneRule rule(history.getRule(a_crDateTime));
    if (rule.isValid())
      return CTimeStamp(history.getGMTOffset() + rule.getTimeSave());
    else
      return CTimeStamp(history.getGMTOffset());
  }
  else
    return CTimeStamp(0);
}
/*--------------------------------------------------------------------------*/
NString::CString CTimeZone::getFormat(const CDateTime& a_crDateTime) const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return NString::CString::EMPTY;
  }

  // Try to find suitable time zone history.
  CTimeZoneHistory history(getHistory(a_crDateTime));
  if (history.isValid())
  {
    // Try to find suitable time zone rule.
    CTimeZoneRule rule(history.getRule(a_crDateTime));
    if (rule.isValid())
    {
      // Replace %s pattern in the found time zone history with the Letters
      // property from the found time zone rule.
      NString::CString result(history.getFormat());
      if (NAlgorithms::NString::replaceStringAll(false, false, result, "%s", rule.getLetters()))
        return result;
      else
        return NString::CString::EMPTY;
    }
    else
      return NString::CString(history.getFormat());
  }
  else
    return NString::CString::EMPTY;
}
/*--------------------------------------------------------------------------*/
CTimeZoneHistory CTimeZone::getHistory(const CDateTime& a_crDateTime) const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return CTimeZoneHistory(getDatabase());
  }

  CTimeStamp timestamp(a_crDateTime.getTimeStamp());
  CTimeZoneHistory current(getHistoryFirst());

  // Iterate through all similar history properties in the current time zone.
  while (current.isValid())
  {
    // Check if the current time zone history is suitable for the given date & time.
    if (timestamp <= current.getUntil())
      return current;

    current = current.getHistoryNext();
  }
  // Required time zone history was not found.
  return CTimeZoneHistory(getDatabase());
}
/*--------------------------------------------------------------------------*/
CTimeZoneHistory CTimeZone::getHistoryFirst() const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return CTimeZoneHistory(getDatabase());
  }

  // Check the index of the current time zone history.
  if (m_TimeZoneStructure.m_ZoneHistoryID < 0)
    return CTimeZoneHistory(getDatabase());

  // Get the first time zone history value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneHistoryByID((Tuint)m_TimeZoneStructure.m_ZoneHistoryID).getHistoryFirst();
}
/*--------------------------------------------------------------------------*/
CTimeZoneHistory CTimeZone::getHistoryLast() const
{ CALL
  // Check if the time zone is valid.
  ASSERT(isValid(), STR("The current time zone is not in the valid state."))
  {
    return CTimeZoneHistory(getDatabase());
  }

  // Check the index of the current time zone history.
  if (m_TimeZoneStructure.m_ZoneHistoryID < 0)
    return CTimeZoneHistory(getDatabase());

  // Get the last time zone history value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneHistoryByID((Tuint)m_TimeZoneStructure.m_ZoneHistoryID).getHistoryLast();
}
/*--------------------------------------------------------------------------*/
void CTimeZone::swap(CTimeZone& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpTimeZoneDatabase, a_rInstance.m_cpTimeZoneDatabase);
  NAlgorithms::NCommon::swap(m_TimeZoneStructure.m_ID, a_rInstance.m_TimeZoneStructure.m_ID);
  NAlgorithms::NCommon::swap(m_TimeZoneStructure.m_CountryCodeID, a_rInstance.m_TimeZoneStructure.m_CountryCodeID);
  NAlgorithms::NCommon::swap(m_TimeZoneStructure.m_CountryNameID, a_rInstance.m_TimeZoneStructure.m_CountryNameID);
  NAlgorithms::NCommon::swap(m_TimeZoneStructure.m_RegionNameID, a_rInstance.m_TimeZoneStructure.m_RegionNameID);
  NAlgorithms::NCommon::swap(m_TimeZoneStructure.m_ZoneNameID, a_rInstance.m_TimeZoneStructure.m_ZoneNameID);
  NAlgorithms::NCommon::swap(m_TimeZoneStructure.m_ZoneCommentsID, a_rInstance.m_TimeZoneStructure.m_ZoneCommentsID);
  NAlgorithms::NCommon::swap(m_TimeZoneStructure.m_ZoneCoordinatesID, a_rInstance.m_TimeZoneStructure.m_ZoneCoordinatesID);
  NAlgorithms::NCommon::swap(m_TimeZoneStructure.m_ZoneHistoryID, a_rInstance.m_TimeZoneStructure.m_ZoneHistoryID);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
