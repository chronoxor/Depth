/*!
 *  \file    FSelect1st.inl Unary select 1'st pair value function class.
 *  \brief   Unary select 1'st pair value function class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unary select 1'st pair value function class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   21.05.2007 02:35:22

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
#ifndef __FSELECT1ST_INL__
#define __FSELECT1ST_INL__
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
template <class T_Pair>
inline typename T_Pair::TFirst& FSelect1st<T_Pair>::operator () (T_Pair& a_rPair) const
{ CALL
  return a_rPair.getFirst();
}
/*--------------------------------------------------------------------------*/
template <class T_Pair>
inline const typename T_Pair::TFirst& FSelect1st<T_Pair>::operator () (const T_Pair& a_crPair) const
{ CALL
  return a_crPair.getFirst();
}
/*--------------------------------------------------------------------------*/
template <class T_Pair>
template <class T_Archive>
inline Tbool FSelect1st<T_Pair>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NFunctions::FSelect1st<T_Pair>")));
  CHECK(a_rArchive.body());
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Pair>
inline void FSelect1st<T_Pair>::swap(FSelect1st<T_Pair>& a_rInstance)
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
