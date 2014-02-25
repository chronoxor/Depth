/*!
 *  \file    CInteger.inl Integer number template class wraps operations with
 *           integer numbers and also gives methods for getting their limits
 *           values.
 *  \brief   Integer number template wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Integer number template wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   26.01.2006 23:09:32

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
#ifndef __CINTEGER_INL__
#define __CINTEGER_INL__
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
inline CInteger<T_Type>::CInteger(const T_Type a_cValue/*  = (T_Type)0 */) :
  m_Value(a_cValue)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>::CInteger(const CInteger<T_OtherType>& a_crInstance) :
  m_Value(a_crInstance.m_Value)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>::~CInteger()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value == a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator == (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value == a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return (a_cValue == a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value != a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator != (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value != a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return (a_cValue != a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator < (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value < a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator < (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value < a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator < (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return (a_cValue < a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator > (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value > a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator > (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value > a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator > (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return (a_cValue > a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator <= (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value <= a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator <= (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value <= a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator <= (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return (a_cValue <= a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator >= (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value >= a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator >= (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value >= a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator >= (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return (a_cValue >= a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator && (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value && a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator && (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value && a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator && (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return (a_cValue && a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator || (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value || a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator || (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value || a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator || (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return (a_cValue || a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator + (const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(+a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator - (const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(-a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator ~ (const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(~a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator ! (const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(!a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator + (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CInteger<T_Type>(a_crInstance.m_Value + a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CInteger<T_Type> operator + (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return CInteger<T_Type>(a_crInstance1.m_Value + a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator + (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(a_cValue + a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator - (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CInteger<T_Type>(a_crInstance.m_Value - a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CInteger<T_Type> operator - (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return CInteger<T_Type>(a_crInstance1.m_Value - a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator - (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(a_cValue - a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator * (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CInteger<T_Type>(a_crInstance.m_Value * a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CInteger<T_Type> operator * (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return CInteger<T_Type>(a_crInstance1.m_Value * a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator * (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(a_cValue * a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator / (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CInteger<T_Type>(a_crInstance.m_Value / a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CInteger<T_Type> operator / (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return CInteger<T_Type>(a_crInstance1.m_Value / a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator / (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(a_cValue / a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator % (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CInteger<T_Type>(a_crInstance.m_Value % a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CInteger<T_Type> operator % (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return CInteger<T_Type>(a_crInstance1.m_Value % a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator % (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(a_cValue % a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator & (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CInteger<T_Type>(a_crInstance.m_Value & a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CInteger<T_Type> operator & (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return CInteger<T_Type>(a_crInstance1.m_Value & a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator & (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(a_cValue & a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator | (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CInteger<T_Type>(a_crInstance.m_Value | a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CInteger<T_Type> operator | (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return CInteger<T_Type>(a_crInstance1.m_Value | a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator | (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(a_cValue | a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator ^ (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CInteger<T_Type>(a_crInstance.m_Value ^ a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CInteger<T_Type> operator ^ (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return CInteger<T_Type>(a_crInstance1.m_Value ^ a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator ^ (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(a_cValue ^ a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator << (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CInteger<T_Type>(a_crInstance.m_Value << a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CInteger<T_Type> operator << (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return CInteger<T_Type>(a_crInstance1.m_Value << a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator << (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(a_cValue << a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator >> (const CInteger<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CInteger<T_Type>(a_crInstance.m_Value >> a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CInteger<T_Type> operator >> (const CInteger<T_Type>& a_crInstance1, const CInteger<T_OtherType>& a_crInstance2)
{ CALL
  return CInteger<T_Type>(a_crInstance1.m_Value >> a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> operator >> (const T_Type a_cValue, const CInteger<T_Type>& a_crInstance)
{ CALL
  return CInteger<T_Type>(a_cValue >> a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator = (const T_Type a_cValue)
{ CALL
  set(a_cValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>& CInteger<T_Type>::operator = (const CInteger<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator += (const T_Type a_cValue)
{ CALL
  m_Value += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>& CInteger<T_Type>::operator += (const CInteger<T_OtherType>& a_crInstance)
{ CALL
  m_Value += a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator -= (const T_Type a_cValue)
{ CALL
  m_Value -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>& CInteger<T_Type>::operator -= (const CInteger<T_OtherType>& a_crInstance)
{ CALL
  m_Value -= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator *= (const T_Type a_cValue)
{ CALL
  m_Value *= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>& CInteger<T_Type>::operator *= (const CInteger<T_OtherType>& a_crInstance)
{ CALL
  m_Value *= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator /= (const T_Type a_cValue)
{ CALL
  m_Value /= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>& CInteger<T_Type>::operator /= (const CInteger<T_OtherType>& a_crInstance)
{ CALL
  m_Value /= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator %= (const T_Type a_cValue)
{ CALL
  m_Value %= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>& CInteger<T_Type>::operator %= (const CInteger<T_OtherType>& a_crInstance)
{ CALL
  m_Value %= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator &= (const T_Type a_cValue)
{ CALL
  m_Value &= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>& CInteger<T_Type>::operator &= (const CInteger<T_OtherType>& a_crInstance)
{ CALL
  m_Value &= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator |= (const T_Type a_cValue)
{ CALL
  m_Value |= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>& CInteger<T_Type>::operator |= (const CInteger<T_OtherType>& a_crInstance)
{ CALL
  m_Value |= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator ^= (const T_Type a_cValue)
{ CALL
  m_Value ^= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>& CInteger<T_Type>::operator ^= (const CInteger<T_OtherType>& a_crInstance)
{ CALL
  m_Value ^= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator <<= (const T_Type a_cValue)
{ CALL
  m_Value <<= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>& CInteger<T_Type>::operator <<= (const CInteger<T_OtherType>& a_crInstance)
{ CALL
  m_Value <<= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator >>= (const T_Type a_cValue)
{ CALL
  m_Value >>= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CInteger<T_Type>& CInteger<T_Type>::operator >>= (const CInteger<T_OtherType>& a_crInstance)
{ CALL
  m_Value >>= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator ++ ()
{ CALL
  ++m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> CInteger<T_Type>::operator ++ (int)
{ CALL
  CInteger<T_Type> temp(*this);

  m_Value++;
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>& CInteger<T_Type>::operator -- ()
{ CALL
  --m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type> CInteger<T_Type>::operator -- (int)
{ CALL
  CInteger<T_Type> temp(*this);

  m_Value--;
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>::operator T_Type& ()
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>::operator const T_Type& () const
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>::operator T_Type* ()
{ CALL
  return &m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CInteger<T_Type>::operator const T_Type* () const
{ CALL
  return &m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CInteger<T_Type>::set(const T_Type a_cValue)
{ CALL
  m_Value = a_cValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CInteger<T_Type>::set(const CInteger<T_OtherType>& a_crInstance)
{ CALL
  m_Value = (T_Type)a_crInstance.getValue();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CInteger<T_Type>::getValue() const
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CInteger<T_Type>::clear()
{ CALL
  m_Value = (T_Type)0;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CInteger<T_Type>::absolute()
{ CALL
  m_Value = NAlgorithms::NNumeric::absolute(m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CInteger<T_Type>::negate()
{ CALL
  m_Value = -m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tsint CInteger<T_Type>::getBitSize()
{ CALL
  return (Tsint)(sizeof(T_Type) << 3);
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tsint08>::getBitSize()
{ CALL
  return (Tsint)8;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tsint16>::getBitSize()
{ CALL
  return (Tsint)16;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tsint32>::getBitSize()
{ CALL
  return (Tsint)32;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tsint64>::getBitSize()
{ CALL
  return (Tsint)64;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tuint08>::getBitSize()
{ CALL
  return (Tsint)8;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tuint16>::getBitSize()
{ CALL
  return (Tsint)16;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tuint32>::getBitSize()
{ CALL
  return (Tsint)32;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tuint64>::getBitSize()
{ CALL
  return (Tsint)64;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tsint CInteger<T_Type>::getByteSize()
{ CALL
  return (Tsint)(sizeof(T_Type));
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tsint08>::getByteSize()
{ CALL
  return (Tsint)1;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tsint16>::getByteSize()
{ CALL
  return (Tsint)2;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tsint32>::getByteSize()
{ CALL
  return (Tsint)4;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tsint64>::getByteSize()
{ CALL
  return (Tsint)8;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tuint08>::getByteSize()
{ CALL
  return (Tsint)1;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tuint16>::getByteSize()
{ CALL
  return (Tsint)2;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tuint32>::getByteSize()
{ CALL
  return (Tsint)4;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CInteger<Tuint64>::getByteSize()
{ CALL
  return (Tsint)8;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CInteger<T_Type>::getMin()
{ CALL
  return (T_Type)0;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint08 CInteger<Tsint08>::getMin()
{ CALL
  return NConstants::CConstants::sint08Min;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint16 CInteger<Tsint16>::getMin()
{ CALL
  return NConstants::CConstants::sint16Min;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint32 CInteger<Tsint32>::getMin()
{ CALL
  return NConstants::CConstants::sint32Min;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint64 CInteger<Tsint64>::getMin()
{ CALL
  return NConstants::CConstants::sint64Min;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint08 CInteger<Tuint08>::getMin()
{ CALL
  return NConstants::CConstants::uint08Min;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint16 CInteger<Tuint16>::getMin()
{ CALL
  return NConstants::CConstants::uint16Min;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint32 CInteger<Tuint32>::getMin()
{ CALL
  return NConstants::CConstants::uint32Min;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint64 CInteger<Tuint64>::getMin()
{ CALL
  return NConstants::CConstants::uint64Min;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CInteger<T_Type>::getMax()
{ CALL
  return (T_Type)((Tuint)1 << (sizeof(T_Type) << 3));
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint08 CInteger<Tsint08>::getMax()
{ CALL
  return NConstants::CConstants::sint08Max;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint16 CInteger<Tsint16>::getMax()
{ CALL
  return NConstants::CConstants::sint16Max;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint32 CInteger<Tsint32>::getMax()
{ CALL
  return NConstants::CConstants::sint32Max;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint64 CInteger<Tsint64>::getMax()
{ CALL
  return NConstants::CConstants::sint64Max;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint08 CInteger<Tuint08>::getMax()
{ CALL
  return NConstants::CConstants::uint08Max;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint16 CInteger<Tuint16>::getMax()
{ CALL
  return NConstants::CConstants::uint16Max;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint32 CInteger<Tuint32>::getMax()
{ CALL
  return NConstants::CConstants::uint32Max;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tuint64 CInteger<Tuint64>::getMax()
{ CALL
  return NConstants::CConstants::uint64Max;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CInteger<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NBase::CInteger<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Value, STR("m_Value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CInteger<T_Type>::swap(CInteger<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Value, a_rInstance.m_Value);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
