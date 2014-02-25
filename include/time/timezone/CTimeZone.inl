/*!
 *  \file    CTimeZone.inl Time zone class provides the all information about
 *           the time zone.
 *  \brief   Time zone class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time zone class (inline).

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
#ifndef __CTIMEZONE_INL__
#define __CTIMEZONE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*--------------------------------------------------------------------------*/
namespace NTimezone {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTimeZone::CTimeZone(const CTimeZoneDatabase& a_crTimeZoneDatabase, const NDetails::STimeZone& a_crTimeZoneStructure) :
  m_cpTimeZoneDatabase(&a_crTimeZoneDatabase),
  m_TimeZoneStructure(a_crTimeZoneStructure)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTimeZone::CTimeZone(const CTimeZone& a_crInstance) :
  m_cpTimeZoneDatabase(a_crInstance.m_cpTimeZoneDatabase),
  m_TimeZoneStructure(a_crInstance.m_TimeZoneStructure)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTimeZone::~CTimeZone()
{ CALL
  m_cpTimeZoneDatabase = NULL;
}
/*--------------------------------------------------------------------------*/
inline CTimeZone& CTimeZone::operator = (const CTimeZone& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CTimeZone::set(const CTimeZone& a_crInstance)
{ CALL
  m_cpTimeZoneDatabase = a_crInstance.m_cpTimeZoneDatabase;
  m_TimeZoneStructure = a_crInstance.m_TimeZoneStructure;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTimeZone::isValid() const
{ CALL
  return (m_cpTimeZoneDatabase != NULL) && (m_cpTimeZoneDatabase->isValidTimeZone(m_TimeZoneStructure));
}
/*--------------------------------------------------------------------------*/
inline const CTimeZoneDatabase& CTimeZone::getDatabase() const
{ CALL
  // Verify the current time zone database to be the valid one.
  VERIFY((m_cpTimeZoneDatabase != NULL), STR("Taking reference to the invalid time zone database value leads to the error."));

  return *m_cpTimeZoneDatabase;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTimeZone::serialize(T_Archive& a_rArchive)
{ CALL
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTime::NTimezone::CTimeZone")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_TimeZoneStructure.m_ID, STR("m_TimeZoneStructure.m_ID")));
    CHECK(a_rArchive.doValue(m_TimeZoneStructure.m_CountryCodeID, STR("m_TimeZoneStructure.m_CountryCodeID")));
    CHECK(a_rArchive.doValue(m_TimeZoneStructure.m_CountryNameID, STR("m_TimeZoneStructure.m_CountryNameID")));
    CHECK(a_rArchive.doValue(m_TimeZoneStructure.m_RegionNameID, STR("m_TimeZoneStructure.m_RegionNameID")));
    CHECK(a_rArchive.doValue(m_TimeZoneStructure.m_ZoneNameID, STR("m_TimeZoneStructure.m_ZoneNameID")));
    CHECK(a_rArchive.doValue(m_TimeZoneStructure.m_ZoneCommentsID, STR("m_TimeZoneStructure.m_ZoneCommentsID")));
    CHECK(a_rArchive.doValue(m_TimeZoneStructure.m_ZoneCoordinatesID, STR("m_TimeZoneStructure.m_ZoneCoordinatesID")));
    CHECK(a_rArchive.doValue(m_TimeZoneStructure.m_ZoneHistoryID, STR("m_TimeZoneStructure.m_ZoneHistoryID")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
