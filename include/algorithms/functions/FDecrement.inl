/*!
 *  \file    FDecrement.inl Decrement function class is used as decremental
 *           generator functor.
 *  \brief   Decrement function class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Decrement function class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   21.05.2007 21:12:26

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
#ifndef __FDECREMENT_INL__
#define __FDECREMENT_INL__
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
template <typename T_Type>
inline FDecrement<T_Type>::FDecrement() :
  m_Value()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline FDecrement<T_Type>::FDecrement(const T_Type& a_crInitialValue) :
  m_Value(a_crInitialValue)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline FDecrement<T_Type>::FDecrement(const FDecrement<T_OtherType>& a_crInstance) :
  m_Value((T_Type)a_crInstance.m_Value)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline FDecrement<T_Type>::~FDecrement()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline FDecrement<T_Type>& FDecrement<T_Type>::operator = (const FDecrement<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void FDecrement<T_Type>::set(const T_Type& a_crInitialValue)
{ CALL
  m_Value = a_crInitialValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void FDecrement<T_Type>::set(const FDecrement<T_OtherType>& a_crInstance)
{ CALL
  m_Value = (T_Type)a_crInstance.m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type FDecrement<T_Type>::operator () () const
{ CALL
  return m_Value--;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool FDecrement<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NFunctions::FDecrement<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Value, STR("m_Value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void FDecrement<T_Type>::swap(FDecrement<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Value, a_rInstance.m_Value);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
