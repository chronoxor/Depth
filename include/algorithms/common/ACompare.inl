/*!
 *  \file    ACompare.inl Contains general template implementation of the
 *           compare algorithm.
 *  \brief   Compare algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Compare algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   03.04.2006 20:38:42

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
#ifndef __ACOMPARE_INL__
#define __ACOMPARE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_Type>
inline Tsint compare(const T_Type& a_crX, const T_Type& a_crY)
{ CALL
  return (NFunctions::FBoolLessThan<const T_Type&>()(a_crX, a_crY) ? -1 : (NFunctions::FBoolLessThan<const T_Type&>()(a_crY, a_crX) ? +1 : 0));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_Comparator>
inline Tsint compare(const T_Type& a_crX, const T_Type& a_crY, T_Comparator a_fComparator)
{ CALL
  // Check T_Comparator constraint to be a suitable binary comparator function.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptFunction2<T_Comparator, Tsint, const T_Type&, const T_Type&> >();

  return a_fComparator(a_crX, a_crY);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
