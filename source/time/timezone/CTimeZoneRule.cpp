/*!
 *  \file    CTimeZoneRule.cpp Time zone rule class provides the rule
 *           information about the time zone.
 *  \brief   Time zone rule class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.12.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time zone rule class (source).

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/time/timezone/CTimeZoneRule.hpp>
/*==========================================================================*/
#ifndef __CTIMEZONERULE_CPP__
#define __CTIMEZONERULE_CPP__
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
CTimeZoneRule::CTimeZoneRule(const CTimeZoneDatabase& a_crTimeZoneDatabase/* = CTimeZoneDatabase() */) :
  m_cpTimeZoneDatabase(&a_crTimeZoneDatabase),
  m_TimeZoneRuleStructure(NDetails::STimeZoneRule::INVALID)
{ CALL

}
/*--------------------------------------------------------------------------*/
Tuint CTimeZoneRule::getID() const
{ CALL
  // Check if the time zone rule is valid.
  ASSERT(isValid(), STR("The current time zone rule is not in the valid state."))
  {
    return 0;
  }

  return m_TimeZoneRuleStructure.m_ID;
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneRule::getName() const
{ CALL
  // Check if the time zone rule is valid.
  ASSERT(isValid(), STR("The current time zone rule is not in the valid state."))
  {
    return ASC("");
  }

  // Check the index of the current time zone rule name.
  if (m_TimeZoneRuleStructure.m_RuleNameID < 0)
    return ASC("");

  // Get time zone rule name value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneRuleNameByID((Tuint)m_TimeZoneRuleStructure.m_RuleNameID);
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneRule::getType() const
{ CALL
  // Check if the time zone rule is valid.
  ASSERT(isValid(), STR("The current time zone rule is not in the valid state."))
  {
    return ASC("");
  }

  // Check the index of the current time zone rule type.
  if (m_TimeZoneRuleStructure.m_RuleTypeID < 0)
    return ASC("");

  // Get time zone rule type value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneRuleTypeByID((Tuint)m_TimeZoneRuleStructure.m_RuleTypeID);
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneRule::getDayOn() const
{ CALL
  // Check if the time zone rule is valid.
  ASSERT(isValid(), STR("The current time zone rule is not in the valid state."))
  {
    return ASC("");
  }

  // Check the index of the current time zone rule on day value.
  if (m_TimeZoneRuleStructure.m_DayOnID < 0)
    return ASC("");

  // Get time zone rule on day value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneRuleDayOnByID((Tuint)m_TimeZoneRuleStructure.m_DayOnID);
}
/*--------------------------------------------------------------------------*/
NDetails::STimeZoneRuleDayOn CTimeZoneRule::getDayOnStructure() const
{ CALL
  // Check if the time zone rule is valid.
  ASSERT(isValid(), STR("The current time zone rule is not in the valid state."))
  {
    return NDetails::STimeZoneRuleDayOn::INVALID;
  }

  // Check the index of the current time zone rule on day value.
  if (m_TimeZoneRuleStructure.m_DayOnID < 0)
    return NDetails::STimeZoneRuleDayOn::INVALID;

  // Get time zone rule on day structure from the current time zone database.
  NDetails::STimeZoneRuleDayOn result = m_cpTimeZoneDatabase->getZoneRuleDayOnStructureByID((Tuint)m_TimeZoneRuleStructure.m_DayOnID);

  // Check if the result time zone rule on day structure is valid.
  ASSERT(m_cpTimeZoneDatabase->isValidTimeZoneRuleDayOn(result), STR("The current time zone rule has invalid day on property."))
  {
    return NDetails::STimeZoneRuleDayOn::INVALID;
  }

  return result;
}
/*--------------------------------------------------------------------------*/
Tcsstr CTimeZoneRule::getLetters() const
{ CALL
  // Check if the time zone rule is valid.
  ASSERT(isValid(), STR("The current time zone rule is not in the valid state."))
  {
    return ASC("");
  }

  // Check the index of the current time zone rule letters.
  if (m_TimeZoneRuleStructure.m_RuleLettersID < 0)
    return ASC("");

  // Get time zone rule letters value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneRuleLettersByID((Tuint)m_TimeZoneRuleStructure.m_RuleLettersID);
}
/*--------------------------------------------------------------------------*/
CTimeZoneRule CTimeZoneRule::getRuleFirst() const
{ CALL
  // Check if the time zone rule is valid.
  ASSERT(isValid(), STR("The current time zone rule is not in the valid state."))
  {
    return CTimeZoneRule(getDatabase());
  }

  CTimeZoneRule current(*this);

  // Iterate backward through all similar rule properties in the current time zone database.
  while (current.m_TimeZoneRuleStructure.m_RulePrevID >= 0)
  {
    current = m_cpTimeZoneDatabase->getZoneRuleByID((Tuint)current.m_TimeZoneRuleStructure.m_RulePrevID);
    if (!current.isValid())
      break;
  }
  return current;
}
/*--------------------------------------------------------------------------*/
CTimeZoneRule CTimeZoneRule::getRulePrev() const
{ CALL
  // Check if the time zone rule is valid.
  ASSERT(isValid(), STR("The current time zone rule is not in the valid state."))
  {
    return CTimeZoneRule(getDatabase());
  }

  // Check the index of the previous time zone rule.
  if (m_TimeZoneRuleStructure.m_RulePrevID < 0)
    return CTimeZoneRule(getDatabase());

  // Get previous time zone rule value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneRuleByID((Tuint)m_TimeZoneRuleStructure.m_RulePrevID);
}
/*--------------------------------------------------------------------------*/
CTimeZoneRule CTimeZoneRule::getRuleNext() const
{ CALL
  // Check if the time zone rule is valid.
  ASSERT(isValid(), STR("The current time zone rule is not in the valid state."))
  {
    return CTimeZoneRule(getDatabase());
  }

  // Check the index of the next time zone rule.
  if (m_TimeZoneRuleStructure.m_RuleNextID < 0)
    return CTimeZoneRule(getDatabase());

  // Get next time zone rule value from the current time zone database.
  return m_cpTimeZoneDatabase->getZoneRuleByID((Tuint)m_TimeZoneRuleStructure.m_RuleNextID);
}
/*--------------------------------------------------------------------------*/
CTimeZoneRule CTimeZoneRule::getRuleLast() const
{ CALL
  // Check if the time zone rule is valid.
  ASSERT(isValid(), STR("The current time zone rule is not in the valid state."))
  {
    return CTimeZoneRule(getDatabase());
  }

  CTimeZoneRule current(*this);

  // Iterate forward through all similar rule properties in the current time zone database.
  while (current.m_TimeZoneRuleStructure.m_RuleNextID >= 0)
  {
    current = m_cpTimeZoneDatabase->getZoneRuleByID((Tuint)current.m_TimeZoneRuleStructure.m_RuleNextID);
    if (!current.isValid())
      break;
  }
  return current;
}
/*--------------------------------------------------------------------------*/
void CTimeZoneRule::swap(CTimeZoneRule& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpTimeZoneDatabase, a_rInstance.m_cpTimeZoneDatabase);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_ID, a_rInstance.m_TimeZoneRuleStructure.m_ID);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_RuleNameID, a_rInstance.m_TimeZoneRuleStructure.m_RuleNameID);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_YearFrom, a_rInstance.m_TimeZoneRuleStructure.m_YearFrom);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_YearTo, a_rInstance.m_TimeZoneRuleStructure.m_YearTo);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_RuleTypeID, a_rInstance.m_TimeZoneRuleStructure.m_RuleTypeID);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_MonthIn, a_rInstance.m_TimeZoneRuleStructure.m_MonthIn);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_DayOnID, a_rInstance.m_TimeZoneRuleStructure.m_DayOnID);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_TimeAt, a_rInstance.m_TimeZoneRuleStructure.m_TimeAt);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_TimeSave, a_rInstance.m_TimeZoneRuleStructure.m_TimeSave);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_TimeSuffix, a_rInstance.m_TimeZoneRuleStructure.m_TimeSuffix);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_RuleLettersID, a_rInstance.m_TimeZoneRuleStructure.m_RuleLettersID);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_RulePrevID, a_rInstance.m_TimeZoneRuleStructure.m_RulePrevID);
  NAlgorithms::NCommon::swap(m_TimeZoneRuleStructure.m_RuleNextID, a_rInstance.m_TimeZoneRuleStructure.m_RuleNextID);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
