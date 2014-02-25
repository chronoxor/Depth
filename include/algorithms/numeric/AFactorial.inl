/*!
 *  \file    AFactorial.inl Contains general template implementation of the
 *           algorithm for the integer number factorial calculating.
 *  \brief   Integer number factorial calculation algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Integer number factorial calculation algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Numeric algorithms
    VERSION:   1.0
    CREATED:   25.01.2007 00:21:46

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
#ifndef __AFACTORIAL_INL__
#define __AFACTORIAL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NNumeric {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_Type>
inline Treal factorial(const T_Type& a_crX)
{ CALL
  // Check T_Type template argument constraint to be an integer number.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptInteger<T_Type> >();

  // Check the given value not to be less than 0.
  ASSERT((a_crX >= 0), STR("X! - cannot calculate negative factorial. X value must not be less than 0 (X = %i).") COMMA a_crX)
  {
    return 0.0;
  }

  static Treal a[33] = {1.0, 1.0, 2.0, 6.0, 24.0};
  static T_Type ntop = 4;
  T_Type j;

  if (a_crX > 32)
    return NMath::CMath::exp(NMath::CMath::logGamma(a_crX + CONSTR(1.0)));
  while (ntop < a_crX)
  {
    j = ntop++;
    a[ntop] = a[j] * ntop;
  }
  return a[a_crX];
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
