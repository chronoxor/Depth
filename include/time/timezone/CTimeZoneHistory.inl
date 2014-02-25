/*!
 *  \file    CTimeZoneHistory.inl Time zone history class provides the history
 *           information about the time zone.
 *  \brief   Time zone history class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time zone history class (inline).

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
#ifndef __CTIMEZONEHISTORY_INL__
#define __CTIMEZONEHISTORY_INL__
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
inline CTimeZoneHistory::CTimeZoneHistory(const CTimeZoneDatabase& a_crTimeZoneDatabase, const NDetails::STimeZoneHistory& a_crTimeZoneHistoryStructure) :
  m_cpTimeZoneDatabase(&a_crTimeZoneDatabase),
  m_TimeZoneHistoryStructure(a_crTimeZoneHistoryStructure)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTimeZoneHistory::CTimeZoneHistory(const CTimeZoneHistory& a_crInstance) :
  m_cpTimeZoneDatabase(a_crInstance.m_cpTimeZoneDatabase),
  m_TimeZoneHistoryStructure(a_crInstance.m_TimeZoneHistoryStructure)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTimeZoneHistory::~CTimeZoneHistory()
{ CALL
  m_cpTimeZoneDatabase = NULL;
}
/*--------------------------------------------------------------------------*/
inline CTimeZoneHistory& CTimeZoneHistory::operator = (const CTimeZoneHistory& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CTimeZoneHistory::set(const CTimeZoneHistory& a_crInstance)
{ CALL
  m_cpTimeZoneDatabase = a_crInstance.m_cpTimeZoneDatabase;
  m_TimeZoneHistoryStructure = a_crInstance.m_TimeZoneHistoryStructure;
}
/*--------------------------------------------------------------------------*/
inline Tbool CTimeZoneHistory::isValid() const
{ CALL
  return (m_cpTimeZoneDatabase != NULL) && (m_cpTimeZoneDatabase->isValidTimeZoneHistory(m_TimeZoneHistoryStructure));
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CTimeZoneHistory::getGMTOffset() const
{ CALL
  return CTimeStamp(m_TimeZoneHistoryStructure.m_GMTOffset);
}
/*--------------------------------------------------------------------------*/
inline CTimeStamp CTimeZoneHistory::getUntil() const
{ CALL
  return CTimeStamp(m_TimeZoneHistoryStructure.m_Until);
}
/*--------------------------------------------------------------------------*/
inline const CTimeZoneDatabase& CTimeZoneHistory::getDatabase() const
{ CALL
  // Verify the current time zone database to be the valid one.
  VERIFY((m_cpTimeZoneDatabase != NULL), STR("Taking reference to the invalid time zone database value leads to the error."));

  return *m_cpTimeZoneDatabase;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTimeZoneHistory::serialize(T_Archive& a_rArchive)
{ CALL
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTime::NTimezone::CTimeZoneHistory")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_TimeZoneHistoryStructure.m_ID, STR("m_TimeZoneHistoryStructure.m_ID")));
    CHECK(a_rArchive.doValue(m_TimeZoneHistoryStructure.m_GMTOffset, STR("m_TimeZoneHistoryStructure.m_GMTOffset")));
    CHECK(a_rArchive.doValue(m_TimeZoneHistoryStructure.m_RuleID, STR("m_TimeZoneHistoryStructure.m_RuleID")));
    CHECK(a_rArchive.doValue(m_TimeZoneHistoryStructure.m_FormatID, STR("m_TimeZoneHistoryStructure.m_FormatID")));
    CHECK(a_rArchive.doValue(m_TimeZoneHistoryStructure.m_Until, STR("m_TimeZoneHistoryStructure.m_Until")));
    CHECK(a_rArchive.doValue(m_TimeZoneHistoryStructure.m_HistoryPrevID, STR("m_TimeZoneHistoryStructure.m_HistoryPrevID")));
    CHECK(a_rArchive.doValue(m_TimeZoneHistoryStructure.m_HistoryNextID, STR("m_TimeZoneHistoryStructure.m_HistoryNextID")));
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
