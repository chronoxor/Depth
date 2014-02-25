/*!
 *  \file    AMinMaxPair.inl Contains general template implementation of the
 *           min and max algorithm which returns values in pair.
 *  \brief   Min and max pair algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Min and max pair algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   26.04.2006 23:56:57

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
#ifndef __AMINMAXPAIR_INL__
#define __AMINMAXPAIR_INL__
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
inline NUtility::CPair<T_Type, T_Type> minMaxPair(const T_Type& a_crX, const T_Type& a_crY)
{ CALL
  return minMax(a_crX, a_crY, NFunctions::FBoolLessThan<const T_Type&>());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_LessThanBinaryPredicate>
inline NUtility::CPair<T_Type, T_Type> minMaxPair(const T_Type& a_crX, const T_Type& a_crY, T_LessThanBinaryPredicate a_fLessThan)
{ CALL
  // Check T_LessThanBinaryPredicate constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_LessThanBinaryPredicate, const T_Type&, const T_Type&> >();

  if (a_fLessThan(a_crY, a_crX))
    return NUtility::CPair<T_Type, T_Type>(a_crY, a_crX);
  else
    return NUtility::CPair<T_Type, T_Type>(a_crX, a_crY);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
