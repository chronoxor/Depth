/*!
 *  \file    TZTable.cpp Olson Time Zone Info table was generated with
 *           TZParser utility and used as a source of Time Zone information.
 *  \brief   Generated Olson Time Zone Info table (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Generated Olson Time Zone Info table (source).

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/algorithms/common/ACountOf.hpp>
#include <Depth/include/time/timezone/details/TZTable.hpp>
/*==========================================================================*/
#ifndef __TZTABLE_CPP__
#define __TZTABLE_CPP__
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
/* STRUCTURE IMPLEMENTATIONS                                                */
/*==========================================================================*/
BASE_API const STimeZone STimeZone::INVALID = { -1, -1, -1, -1, -1, -1, -1, -1 };
BASE_API const STimeZoneHistory STimeZoneHistory::INVALID = { -1, 0, -1, -1, 0, -1, -1, 0 };
BASE_API const STimeZoneRule STimeZoneRule::INVALID = { -1, -1, 0, 0, -1, 0, -1, 0, 0, 0, -1, -1, -1 };
BASE_API const STimeZoneRuleDayOn STimeZoneRuleDayOn::INVALID = { -1, -1, -1, -1, -1 };
/*==========================================================================*/
/* GLOBAL VARIABLES DECLARATIONS                                            */
/*==========================================================================*/
BASE_API Tcsstr the_ZoneCountryCodes[] = {
#include "TZTable-ZoneCountryCodes.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_ZoneCountryNames[] = {
#include "TZTable-ZoneCountryNames.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_ZoneRegionNames[] = {
#include "TZTable-ZoneRegionNames.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_ZoneNames[] = {
#include "TZTable-ZoneNames.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_ZoneComments[] = {
#include "TZTable-ZoneComments.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API const Tdouble the_ZoneCoordinates[][2] = {
#include "TZTable-ZoneCoordinates.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API const STimeZone the_TimeZones[] = {
#include "TZTable-TimeZones.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_ZoneHistoryFormats[] = {
#include "TZTable-ZoneHistoryFormats.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API const STimeZoneHistory the_TimeZoneHistory[] = {
#include "TZTable-TimeZoneHistory.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_ZoneRuleNames[] = {
#include "TZTable-ZoneRuleNames.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_ZoneRuleTypes[] = {
#include "TZTable-ZoneRuleTypes.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_ZoneRuleDayOn[] = {
#include "TZTable-ZoneRuleDayOn.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API const STimeZoneRuleDayOn the_ZoneRuleDayOnTable[] = {
#include "TZTable-ZoneRuleDayOnTable.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API Tcsstr the_ZoneRuleLetters[] = {
#include "TZTable-ZoneRuleLetters.inl"
};
/*--------------------------------------------------------------------------*/
BASE_API const STimeZoneRule the_TimeZoneRules[] = {
#include "TZTable-TimeZoneRules.inl"
};
/*==========================================================================*/
/* GLOBAL FUNCTIONS IMPLEMENTATIONS                                         */
/*==========================================================================*/
BASE_API Tuint getCountOfZoneCountryCodes()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneCountryCodes);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfZoneCountryNames()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneCountryNames);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfZoneRegionNames()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneRegionNames);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfZoneNames()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneNames);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfZoneComments()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneComments);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfZoneCoordinates()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneCoordinates);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfZoneHistoryFormats()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneHistoryFormats);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfZoneRuleNames()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneRuleNames);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfZoneRuleTypes()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneRuleTypes);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfZoneRuleDayOn()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneRuleDayOn);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfZoneRuleDayOnTable()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneRuleDayOnTable);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfZoneRuleLetters()
{ CALL
  return NAlgorithms::NCommon::countOf(the_ZoneRuleLetters);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfTimeZones()
{ CALL
  return NAlgorithms::NCommon::countOf(the_TimeZones);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfTimeZoneHistory()
{ CALL
  return NAlgorithms::NCommon::countOf(the_TimeZoneHistory);
}
/*--------------------------------------------------------------------------*/
BASE_API Tuint getCountOfTimeZoneRules()
{ CALL
  return NAlgorithms::NCommon::countOf(the_TimeZoneRules);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
