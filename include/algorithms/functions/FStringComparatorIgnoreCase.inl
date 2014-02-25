/*!
 *  \file    FStringComparatorIgnoreCase.inl String comparator function
 *           class (ignore case version).
 *  \brief   String comparator function class (ignore case version) (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: String comparator function class (ignore case version) (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   24.06.2010 21:35:56

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
#ifndef __FSTRINGCOMPARATORIGNORECASE_INL__
#define __FSTRINGCOMPARATORIGNORECASE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_Argument1, typename T_Argument2>
inline Tbool FStringComparatorIgnoreCase<T_Argument1, T_Argument2>::operator () (const T_Argument1& a_crArgument1, const T_Argument2& a_crArgument2) const
{ CALL
  return (NString::stringCompareIgnoreCase(a_crArgument1, a_crArgument2) == 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Argument1, typename T_Argument2>
template <class T_Archive>
inline Tbool FStringComparatorIgnoreCase<T_Argument1, T_Argument2>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NFunctions::FStringComparatorIgnoreCase<T_Argument1, T_Argument2>")));
  CHECK(a_rArchive.body());
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Argument1, typename T_Argument2>
inline void FStringComparatorIgnoreCase<T_Argument1, T_Argument2>::swap(FStringComparatorIgnoreCase<T_Argument1, T_Argument2>& a_rInstance)
{ CALL
  IGNORE_UNUSED(a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
