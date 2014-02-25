/*!
 *  \file    CPointer.inl Pointer template class emulates pointers thorough
 *           the class wrapper.
 *  \brief   Pointer template wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Pointer template wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   10.10.2006 00:21:33

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
#ifndef __CPOINTER_INL__
#define __CPOINTER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline CPointer<T_Type>::CPointer(T_Type* a_pValue/* = NULL */) :
  NCommon::IPtr<T_Type>(a_pValue)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CPointer<T_Type>::CPointer(const CPointer<T_OtherType>& a_crInstance) :
  NCommon::IPtr<T_Type>(a_crInstance.m_pPointer)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type>::~CPointer()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator + (const CPointer<T_Type>& a_crInstance, const Tsint a_cValue)
{ CALL
  return CPointer<T_Type>(a_crInstance.m_pPointer + a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator + (const CPointer<T_Type>& a_crInstance, const Tuint a_cValue)
{ CALL
  return CPointer<T_Type>(a_crInstance.m_pPointer + a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator + (const CPointer<T_Type>& a_crInstance, const T_Type* a_cpValue)
{ CALL
  return CPointer<T_Type>(a_crInstance.m_pPointer + a_cpValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPointer<T_Type> operator + (const CPointer<T_Type>& a_crInstance1, const CPointer<T_OtherType>& a_crInstance2)
{ CALL
  return CPointer<T_Type>(a_crInstance1.m_pPointer + a_crInstance2.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator + (const Tsint a_cValue, const CPointer<T_Type>& a_crInstance)
{ CALL
  return CPointer<T_Type>(a_cValue + a_crInstance.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator + (const Tuint a_cValue, const CPointer<T_Type>& a_crInstance)
{ CALL
  return CPointer<T_Type>(a_cValue + a_crInstance.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator + (const T_Type* a_cpValue, const CPointer<T_Type>& a_crInstance)
{ CALL
  return CPointer<T_Type>(a_cpValue + a_crInstance.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator - (const CPointer<T_Type>& a_crInstance, const Tsint a_cValue)
{ CALL
  return CPointer<T_Type>(a_crInstance.m_pPointer - a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator - (const CPointer<T_Type>& a_crInstance, const Tuint a_cValue)
{ CALL
  return CPointer<T_Type>(a_crInstance.m_pPointer - a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator - (const CPointer<T_Type>& a_crInstance, const T_Type* a_cpValue)
{ CALL
  return CPointer<T_Type>(a_crInstance.m_pPointer - a_cpValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPointer<T_Type> operator - (const CPointer<T_Type>& a_crInstance1, const CPointer<T_OtherType>& a_crInstance2)
{ CALL
  return CPointer<T_Type>(a_crInstance1.m_pPointer - a_crInstance2.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator - (const Tsint a_cValue, const CPointer<T_Type>& a_crInstance)
{ CALL
  return CPointer<T_Type>(a_cValue - a_crInstance.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator - (const Tuint a_cValue, const CPointer<T_Type>& a_crInstance)
{ CALL
  return CPointer<T_Type>(a_cValue - a_crInstance.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> operator - (const T_Type* a_cpValue, const CPointer<T_Type>& a_crInstance)
{ CALL
  return CPointer<T_Type>(a_cpValue - a_crInstance.m_pPointer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type>& CPointer<T_Type>::operator = (T_Type* a_pValue)
{ CALL
  set(a_pValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CPointer<T_Type>& CPointer<T_Type>::operator = (const CPointer<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type>& CPointer<T_Type>::operator += (const Tsint a_cValue)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type>& CPointer<T_Type>::operator += (const Tuint a_cValue)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type>& CPointer<T_Type>::operator += (const T_Type* a_cpValue)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer += a_cpValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CPointer<T_Type>& CPointer<T_Type>::operator += (const CPointer<T_OtherType>& a_crInstance)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer += a_crInstance.m_pPointer;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type>& CPointer<T_Type>::operator -= (const Tsint a_cValue)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type>& CPointer<T_Type>::operator -= (const Tuint a_cValue)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type>& CPointer<T_Type>::operator -= (const T_Type* a_cpValue)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer -= a_cpValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CPointer<T_Type>& CPointer<T_Type>::operator -= (const CPointer<T_OtherType>& a_crInstance)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer -= a_crInstance.m_pPointer;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type>& CPointer<T_Type>::operator ++ ()
{ CALL
  ++NCommon::IPtr<T_Type>::m_pPointer;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> CPointer<T_Type>::operator ++ (int)
{ CALL
  CPointer<T_Type> temp(*this);

  NCommon::IPtr<T_Type>::m_pPointer++;
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type>& CPointer<T_Type>::operator -- ()
{ CALL
  --NCommon::IPtr<T_Type>::m_pPointer;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPointer<T_Type> CPointer<T_Type>::operator -- (int)
{ CALL
  CPointer<T_Type> temp(*this);

  NCommon::IPtr<T_Type>::m_pPointer--;
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type& CPointer<T_Type>::operator [] (const Tsint a_cIndex)
{ CALL
  return NCommon::IPtr<T_Type>::m_pPointer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type& CPointer<T_Type>::operator [] (const Tuint a_cIndex)
{ CALL
  return NCommon::IPtr<T_Type>::m_pPointer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& CPointer<T_Type>::operator [] (const Tsint a_cIndex) const
{ CALL
  return NCommon::IPtr<T_Type>::m_pPointer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& CPointer<T_Type>::operator [] (const Tuint a_cIndex) const
{ CALL
  return NCommon::IPtr<T_Type>::m_pPointer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPointer<T_Type>::set(T_Type* a_pValue)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer = a_pValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CPointer<T_Type>::set(const CPointer<T_OtherType>& a_crInstance)
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer = a_crInstance.m_pPointer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPointer<T_Type>::clear()
{ CALL
  NCommon::IPtr<T_Type>::m_pPointer = NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* CPointer<T_Type>::getNULL()
{ CALL
  return (T_Type*)NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* CPointer<T_Type>::getMin()
{ CALL
  return (T_Type*)NConstants::CConstants::ptrMin;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* CPointer<T_Type>::getMax()
{ CALL
  return (T_Type*)NConstants::CConstants::ptrMax;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CPointer<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NBase::CPointer<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((NCommon::IPtr<T_Type>&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPointer<T_Type>::swap(CPointer<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((NCommon::IPtr<T_Type>&)(*this), (NCommon::IPtr<T_Type>&)(a_rInstance));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
