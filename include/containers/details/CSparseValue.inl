/*!
 *  \file    CSparseValue.inl Template single sparse array value class. Sparse
 *           value represents close interval of array values, which is kept
 *           inside CSparseArray container.
 *  \brief   Sparse array value class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sparse array value class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers details
    VERSION:   1.0
    CREATED:   26.09.2007 03:21:19

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
#ifndef __CSPARSEVALUE_INL__
#define __CSPARSEVALUE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline CSparseValue<T_Type>::CSparseValue() :
  m_FirstIndex(0),
  m_SecondIndex(0),
  m_pBuffer(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CSparseValue<T_Type>::CSparseValue(const Tuint a_cFirstIndex, const Tuint a_cSecondIndex, T_Type* a_pBuffer) :
  m_FirstIndex(a_cFirstIndex),
  m_SecondIndex(a_cSecondIndex),
  m_pBuffer(a_pBuffer)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CSparseValue<T_Type>::CSparseValue(const CSparseValue<T_OtherType>& a_crInstance) :
  m_FirstIndex(a_crInstance.m_FirstIndex),
  m_SecondIndex(a_crInstance.m_SecondIndex),
  m_pBuffer((T_Type*)a_crInstance.m_pBuffer)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CSparseValue<T_Type>::~CSparseValue()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CSparseValue<T_Type>& CSparseValue<T_Type>::operator = (const CSparseValue<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type& CSparseValue<T_Type>::operator [] (const Tuint a_cIndex)
{ CALL
  // Verify the sparse array value to be valid.
  VERIFY(isValid(), STR("Indexing into the invalid sparse array value leads to the error."));
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= m_FirstIndex) || (a_cIndex <= m_SecondIndex)), STR("Cannot get sparse array value with the out of bounds index (index = %u, first = %u, second = %u).") COMMA a_cIndex COMMA m_FirstIndex COMMA m_SecondIndex);

  return m_pBuffer[a_cIndex - m_FirstIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& CSparseValue<T_Type>::operator [] (const Tuint a_cIndex) const
{ CALL
  // Verify the sparse array value to be valid.
  VERIFY(isValid(), STR("Indexing into the invalid sparse array value leads to the error."));
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= m_FirstIndex) || (a_cIndex <= m_SecondIndex)), STR("Cannot get sparse array value with the out of bounds index (index = %u, first = %u, second = %u).") COMMA a_cIndex COMMA m_FirstIndex COMMA m_SecondIndex);

  return m_pBuffer[a_cIndex - m_FirstIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CSparseValue<T_Type>::set(const Tuint a_cFirstIndex, const Tuint a_cSecondIndex, T_Type* a_pBuffer)
{ CALL
  m_FirstIndex = a_cFirstIndex;
  m_SecondIndex = a_cSecondIndex;
  m_pBuffer = a_pBuffer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CSparseValue<T_Type>::set(const CSparseValue<T_OtherType>& a_crInstance)
{ CALL
  m_FirstIndex = a_crInstance.m_FirstIndex;
  m_SecondIndex = a_crInstance.m_SecondIndex;
  m_pBuffer = (T_Type*)a_crInstance.m_pBuffer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CSparseValue<T_Type>::isValid() const
{ CALL
  return (m_pBuffer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CSparseValue<T_Type>::getFirstIndex() const
{ CALL
  return m_FirstIndex;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CSparseValue<T_Type>::getSecondIndex() const
{ CALL
  return m_SecondIndex;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CSparseValue<T_Type>::getLength() const
{ CALL
  return (isValid() ? (getSecondIndex() - getFirstIndex() + 1) : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* CSparseValue<T_Type>::getBuffer()
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type* CSparseValue<T_Type>::getBuffer() const
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CSparseValue<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Sparse array value instance cannot be serialized."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CSparseValue<T_Type>::swap(CSparseValue<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_FirstIndex, a_rInstance.m_FirstIndex);
  NAlgorithms::NCommon::swap(m_SecondIndex, a_rInstance.m_SecondIndex);
  NAlgorithms::NCommon::swap(m_pBuffer, a_rInstance.m_pBuffer);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
