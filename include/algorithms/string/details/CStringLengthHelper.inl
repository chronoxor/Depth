/*!
 *  \file    CStringLengthHelper.inl Helper class for getting string length
 *           based on its type.
 *  \brief   Helper class for string length algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Helper class for string length algorithm (inline).

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
#ifndef __CSTRINGLENGTHHELPER_INL__
#define __CSTRINGLENGTHHELPER_INL__
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
template <Tbool t_IsStringClass>
template <typename T_StringType>
inline Tuint CStringLengthHelper<t_IsStringClass>::stringLength(const T_StringType& a_crString, const Tuint a_cStringIndex, const Tuint a_cStringLength)
{ CALL
  // Check T_StringType template argument constraint to be a constant string type.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType> >();

  // Check the given string not to be NULL.
  ASSERT((a_crString != NULL), STR("Algorithm 'stringLength()' cannot work with a NULL string."))
  {
    return 0;
  }

  Tuint count = 0;
  Tuint index = a_cStringIndex;

  while ((a_crString[index++] != 0) && (count < a_cStringLength))
    ++count;

  return count;
}
/*--------------------------------------------------------------------------*/
template <>
template <typename T_StringType>
inline Tuint CStringLengthHelper<true>::stringLength(const T_StringType& a_crString, const Tuint a_cStringIndex, const Tuint a_cStringLength)
{ CALL
  // Check T_StringType template argument constraint to be a constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIStringConst<T_StringType> >();

  Tuint length = a_crString.getSize();

  // Check if the string index is not out of bounds.
  ASSERT((a_cStringIndex <= length), STR("String index is out of bounds (index = %u, length = %u).") COMMA a_cStringIndex COMMA length)
  {
    return 0;
  }

  return NCommon::min(length - a_cStringIndex, a_cStringLength);
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
