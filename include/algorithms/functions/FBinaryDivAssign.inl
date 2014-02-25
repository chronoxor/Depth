/*!
 *  \file    FBinaryDivAssign.inl Binary '/=' operator function class.
 *  \brief   Binary '/=' operator function class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Binary '/=' operator function class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   20.07.2006 02:25:28

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
#ifndef __FBINARYDIVASSIGN_INL__
#define __FBINARYDIVASSIGN_INL__
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
template <typename T_Return, typename T_Argument1, typename T_Argument2>
inline T_Return FBinaryDivAssign<T_Return, T_Argument1, T_Argument2>::operator () (T_Argument1 a_Argument1, T_Argument2 a_Argument2) const
{ CALL
  return (T_Return)(a_Argument1 /= a_Argument2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Return, typename T_Argument1, typename T_Argument2>
template <class T_Archive>
inline Tbool FBinaryDivAssign<T_Return, T_Argument1, T_Argument2>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NFunctions::FBinaryDivAssign<T_Return, T_Argument1, T_Argument2>")));
  CHECK(a_rArchive.body());
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Return, typename T_Argument1, typename T_Argument2>
inline void FBinaryDivAssign<T_Return, T_Argument1, T_Argument2>::swap(FBinaryDivAssign<T_Return, T_Argument1, T_Argument2>& a_rInstance)
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
