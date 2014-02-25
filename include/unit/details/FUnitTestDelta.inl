/*!
 *  \file    FUnitTestDelta.inl Helper function that checks if x equals to y
 *           up to delta (|x - y| <= delta).
 *  \brief   Unit test delta helper function (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test delta helper function (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unit test details
    VERSION:   1.0
    CREATED:   31.01.2009 21:59:18

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
#ifndef __FUNITTESTDELTA_INL__
#define __FUNITTESTDELTA_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE FUNCTION IMPLEMENTATIONS                                          */
/*==========================================================================*/
template <typename T_TypeX, typename T_TypeY, typename T_TypeDelta>
inline Tbool unitTestDelta(const T_TypeX& a_crX, const T_TypeY& a_crY, const T_TypeDelta& a_crDelta)
{ CALL
   return ((a_crY >= (a_crX - a_crDelta)) && (a_crY <= (a_crX + a_crDelta)));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
