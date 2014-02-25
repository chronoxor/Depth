/*!
 *  \file    AASin.inl Contains general template implementation of the
 *           inverse sine algorithm.
 *  \brief   Inverse sine algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Inverse sine algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Math algorithms
    VERSION:   1.0
    CREATED:   19.09.2006 00:00:36

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
#ifndef __AASIN_INL__
#define __AASIN_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NMath {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_Type>
T_Type asin(const T_Type& a_crX, const Tuint a_cMaxIterations/* = 100 */)
{ CALL
  // Check T_Type template argument constraint to be a real number.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptReal<T_Type> >();

  Tuint n = a_cMaxIterations;
  T_Type ans = T_Type(a_crX);
  T_Type val2 = T_Type(a_crX * a_crX);
  T_Type numer = T_Type(a_crX);
  T_Type numer_co = T_Type(1);
  T_Type denom = T_Type(1);
  T_Type next = T_Type(1);

  while (n > 0)
  {
    numer_co *= next;
    numer *= val2;
    denom *= next + 1;
    next += 2;
    ans += (numer_co * numer) / (denom * next);
    --n;
  }
  return ans;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
