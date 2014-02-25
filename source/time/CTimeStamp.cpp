/*!
 *  \file    CTimeStamp.cpp Time stamp class represents a time stamp with a
 *           the 64-bit integer value.
 *  \brief   Time stamp class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Time stamp class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Time
    VERSION:   1.0
    CREATED:   19.02.2010 20:29:05

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
#include <Depth/include/time/CTimeStamp.hpp>
/*==========================================================================*/
#ifndef __CTIMESTAMP_CPP__
#define __CTIMESTAMP_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTime {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CTimeStamp::CTimeStamp() :
  m_TimeStampValue(0)
{ CALL
  m_TimeStampValue = NSystem::CSystemBase::getSystemTimeStamp(false);
}
/*--------------------------------------------------------------------------*/
CTimeStamp CTimeStamp::getProcessTimeStamp()
{ CALL
  return CTimeStamp(NSystem::CSystemBase::getProcessTimeStamp());
}
/*--------------------------------------------------------------------------*/
CTimeStamp CTimeStamp::getSystemTimeStamp(const Tbool a_cIsUTC/* = true */)
{ CALL
  return CTimeStamp(NSystem::CSystemBase::getSystemTimeStamp(a_cIsUTC));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
