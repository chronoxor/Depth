/*!
 *  \file    CDateTime.cpp Date & Time class represents a date & time with
 *           year, month, day, hours, minutes, seconds and milliseconds
 *           values.
 *  \brief   Date & Time class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.03.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Date & Time class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time
    VERSION:   1.0
    CREATED:   04.03.2010 02:11:01

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
#include <Depth/include/system/CSystemBase.hpp>
#include <Depth/include/time/CDateTime.hpp>
/*==========================================================================*/
#ifndef __CDATETIME_CPP__
#define __CDATETIME_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CDateTime CDateTime::getProcessDateTime()
{ CALL
  return NSystem::CSystemBase::getProcessDateTime();
}
/*--------------------------------------------------------------------------*/
CDateTime CDateTime::getSystemDateTime(const Tbool a_cIsUTC/* = true */)
{ CALL
  return NSystem::CSystemBase::getSystemDateTime(a_cIsUTC);
}
/*--------------------------------------------------------------------------*/
Tbool CDateTime::setSystemDateTimeUTC(const CDateTime& a_crDateTime)
{ CALL
  return NSystem::CSystemBase::setSystemDateTime(a_crDateTime, true);
}
/*--------------------------------------------------------------------------*/
Tbool CDateTime::setSystemDateTimeLocal(const CDateTime& a_crDateTime)
{ CALL
  return NSystem::CSystemBase::setSystemDateTime(a_crDateTime, false);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
