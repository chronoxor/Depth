/*!
 *  \file    CBoolean.inl Boolean value template class wraps operations with
 *           boolean values.
 *  \brief   Boolean values template wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Boolean value template wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   31.01.2006 02:49:35

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
#ifndef __CBOOLEAN_INL__
#define __CBOOLEAN_INL__
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
inline CBoolean<T_Type>::CBoolean(const T_Type a_cValue/* = (T_Type)false */) :
  m_Value(a_cValue)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CBoolean<T_Type>::CBoolean(const CBoolean<T_OtherType>& a_crInstance) :
  m_Value(a_crInstance.m_Value)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type>::~CBoolean()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const CBoolean<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value == a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator == (const CBoolean<T_Type>& a_crInstance1, const CBoolean<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value == (T_Type)a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const T_Type a_cValue, const CBoolean<T_Type>& a_crInstance)
{ CALL
  return (a_cValue == a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const CBoolean<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value != a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator != (const CBoolean<T_Type>& a_crInstance1, const CBoolean<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value != (T_Type)a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const T_Type a_cValue, const CBoolean<T_Type>& a_crInstance)
{ CALL
  return (a_cValue != a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator && (const CBoolean<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value && a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator && (const CBoolean<T_Type>& a_crInstance1, const CBoolean<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value && (T_Type)a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator && (const T_Type a_cValue, const CBoolean<T_Type>& a_crInstance)
{ CALL
  return (a_cValue && a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator || (const CBoolean<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value || a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator || (const CBoolean<T_Type>& a_crInstance1, const CBoolean<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value || (T_Type)a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator || (const T_Type a_cValue, const CBoolean<T_Type>& a_crInstance)
{ CALL
  return (a_cValue || a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type> operator ! (const CBoolean<T_Type>& a_crInstance)
{ CALL
  return CBoolean<T_Type>(!a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type> operator & (const CBoolean<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CBoolean<T_Type>(a_crInstance.m_Value & a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBoolean<T_Type> operator & (const CBoolean<T_Type>& a_crInstance1, const CBoolean<T_OtherType>& a_crInstance2)
{ CALL
  return CBoolean<T_Type>(a_crInstance1.m_Value & (T_Type)a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type> operator & (const T_Type a_cValue, const CBoolean<T_Type>& a_crInstance)
{ CALL
  return CBoolean<T_Type>(a_cValue & a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type> operator | (const CBoolean<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CBoolean<T_Type>(a_crInstance.m_Value | a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBoolean<T_Type> operator | (const CBoolean<T_Type>& a_crInstance1, const CBoolean<T_OtherType>& a_crInstance2)
{ CALL
  return CBoolean<T_Type>(a_crInstance1.m_Value | (T_Type)a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type> operator | (const T_Type a_cValue, const CBoolean<T_Type>& a_crInstance)
{ CALL
  return CBoolean<T_Type>(a_cValue | a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type> operator ^ (const CBoolean<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CBoolean<T_Type>(a_crInstance.m_Value ^ a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBoolean<T_Type> operator ^ (const CBoolean<T_Type>& a_crInstance1, const CBoolean<T_OtherType>& a_crInstance2)
{ CALL
  return CBoolean<T_Type>(a_crInstance1.m_Value ^ (T_Type)a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type> operator ^ (const T_Type a_cValue, const CBoolean<T_Type>& a_crInstance)
{ CALL
  return CBoolean<T_Type>(a_cValue ^ a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type>& CBoolean<T_Type>::operator = (const T_Type a_cValue)
{ CALL
  set(a_cValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CBoolean<T_Type>& CBoolean<T_Type>::operator = (const CBoolean<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type>& CBoolean<T_Type>::operator &= (const T_Type a_cValue)
{ CALL
  m_Value &= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CBoolean<T_Type>& CBoolean<T_Type>::operator &= (const CBoolean<T_OtherType>& a_crInstance)
{ CALL
  m_Value &= (T_Type)a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type>& CBoolean<T_Type>::operator |= (const T_Type a_cValue)
{ CALL
  m_Value |= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CBoolean<T_Type>& CBoolean<T_Type>::operator |= (const CBoolean<T_OtherType>& a_crInstance)
{ CALL
  m_Value |= (T_Type)a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type>& CBoolean<T_Type>::operator ^= (const T_Type a_cValue)
{ CALL
  m_Value ^= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CBoolean<T_Type>& CBoolean<T_Type>::operator ^= (const CBoolean<T_OtherType>& a_crInstance)
{ CALL
  m_Value ^= (T_Type)a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type>::operator T_Type& ()
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type>::operator const T_Type& () const
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type>::operator T_Type* ()
{ CALL
  return &m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type>::operator const T_Type* () const
{ CALL
  return &m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBoolean<T_Type>::operator Tbool () const
{ CALL
  return isTrue();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CBoolean<T_Type>::operator ! () const
{ CALL
  return isFalse();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBoolean<T_Type>::set(const T_Type a_cValue)
{ CALL
  m_Value = a_cValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CBoolean<T_Type>::set(const CBoolean<T_OtherType>& a_crInstance)
{ CALL
  m_Value = (T_Type)a_crInstance.m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CBoolean<T_Type>::getValue() const
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CBoolean<T_Type>::isTrue() const
{ CALL
  return (m_Value == ((T_Type)true));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CBoolean<T_Type>::isFalse() const
{ CALL
  return (m_Value == ((T_Type)false));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBoolean<T_Type>::setTrue()
{ CALL
  m_Value = (T_Type)true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBoolean<T_Type>::setFalse()
{ CALL
  m_Value = (T_Type)false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBoolean<T_Type>::flip()
{ CALL
  m_Value = !m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CBoolean<T_Type>::getTrue()
{ CALL
  return (T_Type)true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CBoolean<T_Type>::getFalse()
{ CALL
  return (T_Type)false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CBoolean<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NBase::CBoolean<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Value, STR("m_Value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBoolean<T_Type>::swap(CBoolean<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Value, a_rInstance.m_Value);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
