/*!
 *  \file    ASwapHelper.inl Contains template implementations of the swap
 *           algorithm for different data types.
 *  \brief   Swap algorithm helper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Swap algorithm helper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms details
    VERSION:   1.0
    CREATED:   15.04.2006 02:01:31

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
#ifndef __ASWAPHELPER_INL__
#define __ASWAPHELPER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <Tuint t_Algorithm>
template <typename T_Type>
inline void ASwapHelper<t_Algorithm>::swap(T_Type& a_rFirst, T_Type& a_rSecond)
{ CALL
  // Check T_Type template argument constraint to have assign operator and copy constructor.
  NConcept::MConstraint::requiresConcept<NConcept::NClass::MConceptAssignCopy<T_Type> >();

  T_Type temp(a_rFirst);
  a_rFirst = a_rSecond;
  a_rSecond = temp;
}
/*--------------------------------------------------------------------------*/
template <>
template <typename T_Type>
inline void ASwapHelper<0>::swap(T_Type& a_rFirst, T_Type& a_rSecond)
{ CALL
  // Check T_Type template argument constraint to be a swappable type.
  NConcept::MConstraint::requiresConcept<NConcept::NClass::MConceptSwappable<T_Type> >();

  a_rFirst.swap(a_rSecond);
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
