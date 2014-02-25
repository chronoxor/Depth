/*!
 *  \file    TZTable.inl Olson Time Zone Info table was generated with
 *           TZParser utility and used as a source of Time Zone information.
 *  \brief   Generated Olson Time Zone Info table (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Generated Olson Time Zone Info table (inline).

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
#ifndef __TZTABLE_INL__
#define __TZTABLE_INL__
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
/* INLINE STRUCTURE IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline BASE_API Tbool operator == (const STimeZoneRuleDayOn& a_crInstance1, const STimeZoneRuleDayOn& a_crInstance2)
{ CALL
  // Compare only content without IDs.
  return ((a_crInstance1.m_LastFlag == a_crInstance2.m_LastFlag) && (a_crInstance1.m_WeekDayFlag == a_crInstance2.m_WeekDayFlag) && (a_crInstance1.m_WeekDay == a_crInstance2.m_WeekDay) && (a_crInstance1.m_Day == a_crInstance2.m_Day));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const STimeZoneRuleDayOn& a_crInstance1, const STimeZoneRuleDayOn& a_crInstance2)
{ CALL
  // Compare only content without IDs.
  return ((a_crInstance1.m_LastFlag != a_crInstance2.m_LastFlag) || (a_crInstance1.m_WeekDayFlag != a_crInstance2.m_WeekDayFlag) || (a_crInstance1.m_WeekDay != a_crInstance2.m_WeekDay) || (a_crInstance1.m_Day != a_crInstance2.m_Day));
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
