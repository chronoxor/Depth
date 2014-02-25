/*!
 *  \file    CStringSearchHelper.inl Helper class for (sub)string searching
 *           algorithms.
 *  \brief   Helper class for (sub)string searching algorithms (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Helper class for (sub)string searching algorithms (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms details
    VERSION:   1.0
    CREATED:   26.11.2009 02:08:02

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
#ifndef __CSTRINGSEARCHHELPER_INL__
#define __CSTRINGSEARCHHELPER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CALSS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_StringClass, typename T_StringType>
inline Tbool CStringSearchHelper::copyPattern(T_StringClass& a_rDestination, const T_StringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  // Check T_StringClass template argument constraint to be a non constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIString<T_StringClass> >();
  // Check T_StringType template argument constraint to be a constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType> >();

  Tuint length = stringLength(a_crPattern, a_cPatternIndex, a_cPatternLength);

  // Check if the pattern string is not empty.
  ASSERT((length > 0), STR("Pattern string cannot be empty. Its length should be greater than zero."))
  {
    return false;
  }

  // Clear destination string.
  if (!a_rDestination.clear())
    return false;

  // Resize destination string to fit the given pattern.
  if (a_rDestination.resize(length))
  {
    // Copy the given pattern.
    for (Tuint i = 0, j = a_cPatternIndex; i < length; ++i, ++j)
      a_rDestination[i] = a_crPattern[j];
    return true;
  }
  else
    return false;
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
