/*!
 *  \file    CTimeZoneHistory.cpp Time zone history class provides the history
 *           information about the time zone.
 *  \brief   Time zone history class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time zone history class (source).

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/time/timezone/CTimeZoneHistory.hpp>
/*==========================================================================*/
#ifndef __CTIMEZONEHISTORY_CPP__
#define __CTIMEZONEHISTORY_CPP__
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
CTimeZoneHistory::CTimeZoneHistory(const CTimeZoneDatabase& a_crTimeZoneDatabase/* = CTimeZoneDatabase() */) :
  m_cpTimeZoneDatabase(&a_crTimeZoneDatabase),
  m_TimeZoneHistoryStructure(NDetails::STimeZoneHistory::INVALID)
{ CALL

}
/*--------------------------------------------------------------------------*/
Tuint CTimeZoneHistory::getID() const
{ CALL
  // Check if the time zone history is valid.
  ASSERT(isValid(), STR("The current time zone history is not in the valid state."))
  {
    return 0;
  }

  return m_TimeZoneHistoryStructure.m_ID;
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneHistory::getFormat() const
{ CALL
  // Check if the time zone history is valid.
  ASSERT(isValid(), STR("The current time zone history is not in the valid state."))
  {
    return ASC("");
  }

  // Check the index of the current time zone history format.
  if (m_TimeZoneHistoryStructure.m_FormatID < 0)
    return ASC("");

  // Get time zone history format value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneHistoryFormatByID((Tuint)m_TimeZoneHistoryStructure.m_FormatID);
}
/*--------------------------------------------------------------------------*/
CTimeZoneRule CTimeZoneHistory::getRule(const CDateTime& a_crDateTime) const
{ CALL
  CDateTime temp;
  return getRule(a_crDateTime, temp);
}
/*--------------------------------------------------------------------------*/
CTimeZoneRule CTimeZoneHistory::getRule(const CDateTime& a_crDateTime, CDateTime& a_rCutoverDateTime) const
{ CALL
  // Check if the time zone history is valid.
  ASSERT(isValid(), STR("The current time zone history is not in the valid state."))
  {
    return CTimeZoneRule(getDatabase());
  }

  CTimeZoneRule current(getRuleFirst());
  CTimeZoneRule result(getDatabase());

  // Reset cutover date & time.
  a_rCutoverDateTime.set(CDateTime::getMin());

  // Iterate through all similar rule properties in the current time zone history.
  while (current.isValid())
  {
    // Get the year of the given date & time.
    Tsint year = a_crDateTime.getDate().getYear();

    // If the time zone rule year is suitable for the given date...
    if ((year >= current.getYearFrom()) && (year <= (current.getYearTo() + 1)))
    {
      CDateTime cutover;

      // Get cutover date & time for the previous year.
      if (m_cpTimeZoneDatabase->getCutoverDateTime(current, year - 1, cutover) && (cutover > a_rCutoverDateTime) && (cutover < a_crDateTime))
      {
        // We found a new suitable time zone rule.
        a_rCutoverDateTime = cutover;
        result = current;
      }

      // Get cutover date & time for the current year.
      if (m_cpTimeZoneDatabase->getCutoverDateTime(current, year, cutover) && (cutover > a_rCutoverDateTime) && (cutover < a_crDateTime))
      {
        // We found a new suitable time zone rule.
        a_rCutoverDateTime = cutover;
        result = current;
      }
    }

    // Get the next time zone rule.
    current = current.getRuleNext();
  }
  return current;
}
/*--------------------------------------------------------------------------*/
CTimeZoneRule CTimeZoneHistory::getRuleFirst() const
{ CALL
  // Check if the time zone history is valid.
  ASSERT(isValid(), STR("The current time zone history is not in the valid state."))
  {
    return CTimeZoneRule(getDatabase());
  }

  // Check the index of the current time zone history rule.
  if (m_TimeZoneHistoryStructure.m_RuleID < 0)
    return CTimeZoneRule(getDatabase());

  // Get the first time zone history rule value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneRuleByID((Tuint)m_TimeZoneHistoryStructure.m_RuleID).getRuleFirst();
}
/*--------------------------------------------------------------------------*/
CTimeZoneRule CTimeZoneHistory::getRuleLast() const
{ CALL
  // Check if the time zone history is valid.
  ASSERT(isValid(), STR("The current time zone history is not in the valid state."))
  {
    return CTimeZoneRule(getDatabase());
  }

  // Check the index of the current time zone history rule.
  if (m_TimeZoneHistoryStructure.m_RuleID < 0)
    return CTimeZoneRule(getDatabase());

  // Get the last time zone history rule value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneRuleByID((Tuint)m_TimeZoneHistoryStructure.m_RuleID).getRuleLast();
}
/*--------------------------------------------------------------------------*/
CTimeZoneHistory CTimeZoneHistory::getHistoryFirst() const
{ CALL
  // Check if the time zone history is valid.
  ASSERT(isValid(), STR("The current time zone history is not in the valid state."))
  {
    return CTimeZoneHistory(getDatabase());
  }

  CTimeZoneHistory current(*this);

  // Iterate backward through all similar history properties in the current time zone database.
  while (current.m_TimeZoneHistoryStructure.m_HistoryPrevID >= 0)
  {
    current = m_cpTimeZoneDatabase->getZoneHistoryByID((Tuint)current.m_TimeZoneHistoryStructure.m_HistoryPrevID);
    if (!current.isValid())
      break;
  }
  return current;
}
/*--------------------------------------------------------------------------*/
CTimeZoneHistory CTimeZoneHistory::getHistoryPrev() const
{ CALL
  // Check if the time zone history is valid.
  ASSERT(isValid(), STR("The current time zone history is not in the valid state."))
  {
    return CTimeZoneHistory(getDatabase());
  }

  // Check the index of the previous time zone history.
  if (m_TimeZoneHistoryStructure.m_HistoryPrevID < 0)
    return CTimeZoneHistory(getDatabase());

  // Get previous time zone history value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneHistoryByID((Tuint)m_TimeZoneHistoryStructure.m_HistoryPrevID);
}
/*--------------------------------------------------------------------------*/
CTimeZoneHistory CTimeZoneHistory::getHistoryNext() const
{ CALL
  // Check if the time zone history is valid.
  ASSERT(isValid(), STR("The current time zone history is not in the valid state."))
  {
    return CTimeZoneHistory(getDatabase());
  }

  // Check the index of the next time zone history.
  if (m_TimeZoneHistoryStructure.m_HistoryNextID < 0)
    return CTimeZoneHistory(getDatabase());

  // Get next time zone history value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneHistoryByID((Tuint)m_TimeZoneHistoryStructure.m_HistoryNextID);
}
/*--------------------------------------------------------------------------*/
CTimeZoneHistory CTimeZoneHistory::getHistoryLast() const
{ CALL
  // Check if the time zone history is valid.
  ASSERT(isValid(), STR("The current time zone history is not in the valid state."))
  {
    return CTimeZoneHistory(getDatabase());
  }

  CTimeZoneHistory current(*this);

  // Iterate forward through all similar history properties in the current time zone database.
  while (current.m_TimeZoneHistoryStructure.m_HistoryNextID >= 0)
  {
    current = m_cpTimeZoneDatabase->getZoneHistoryByID((Tuint)current.m_TimeZoneHistoryStructure.m_HistoryNextID);
    if (!current.isValid())
      break;
  }
  return current;
}
/*--------------------------------------------------------------------------*/
void CTimeZoneHistory::swap(CTimeZoneHistory& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpTimeZoneDatabase, a_rInstance.m_cpTimeZoneDatabase);
  NAlgorithms::NCommon::swap(m_TimeZoneHistoryStructure.m_ID, a_rInstance.m_TimeZoneHistoryStructure.m_ID);
  NAlgorithms::NCommon::swap(m_TimeZoneHistoryStructure.m_GMTOffset, a_rInstance.m_TimeZoneHistoryStructure.m_GMTOffset);
  NAlgorithms::NCommon::swap(m_TimeZoneHistoryStructure.m_RuleID, a_rInstance.m_TimeZoneHistoryStructure.m_RuleID);
  NAlgorithms::NCommon::swap(m_TimeZoneHistoryStructure.m_FormatID, a_rInstance.m_TimeZoneHistoryStructure.m_FormatID);
  NAlgorithms::NCommon::swap(m_TimeZoneHistoryStructure.m_Until, a_rInstance.m_TimeZoneHistoryStructure.m_Until);
  NAlgorithms::NCommon::swap(m_TimeZoneHistoryStructure.m_HistoryPrevID, a_rInstance.m_TimeZoneHistoryStructure.m_HistoryPrevID);
  NAlgorithms::NCommon::swap(m_TimeZoneHistoryStructure.m_HistoryNextID, a_rInstance.m_TimeZoneHistoryStructure.m_HistoryNextID);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
