/*!
 *  \file    CReal.inl Real number template class wraps operations with
 *           real numbers and also gives methods for getting their limits
 *           values.
 *  \brief   Real number template wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Real number template wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   28.01.2006 23:01:52

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
#ifndef __CREAL_INL__
#define __CREAL_INL__
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
inline CReal<T_Type>::CReal(const T_Type a_cValue/*  = (T_Type)0.0 */) :
  m_Value(a_cValue)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CReal<T_Type>::CReal(const CReal<T_OtherType>& a_crInstance) :
  m_Value(a_crInstance.m_Value)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>::~CReal()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value == a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator == (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value == a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return (a_cValue == a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value != a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator != (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value != a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return (a_cValue != a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator < (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value < a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator < (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value < a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator < (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return (a_cValue < a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator > (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value > a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator > (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value > a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator > (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return (a_cValue > a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator <= (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value <= a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator <= (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value <= a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator <= (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return (a_cValue <= a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator >= (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value >= a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator >= (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value >= a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator >= (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return (a_cValue >= a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator && (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value && a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator && (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value && a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator && (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return (a_cValue && a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator || (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return (a_crInstance.m_Value || a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator || (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return (a_crInstance1.m_Value || a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator || (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return (a_cValue || a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> operator + (const CReal<T_Type>& a_crInstance)
{ CALL
  return CReal<T_Type>(+a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> operator - (const CReal<T_Type>& a_crInstance)
{ CALL
  return CReal<T_Type>(-a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> operator ! (const CReal<T_Type>& a_crInstance)
{ CALL
  return CReal<T_Type>(!a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> operator + (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CReal<T_Type>(a_crInstance.m_Value + a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CReal<T_Type> operator + (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return CReal<T_Type>(a_crInstance1.m_Value + a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> operator + (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return CReal<T_Type>(a_cValue + a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> operator - (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CReal<T_Type>(a_crInstance.m_Value - a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CReal<T_Type> operator - (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return CReal<T_Type>(a_crInstance1.m_Value - a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> operator - (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return CReal<T_Type>(a_cValue - a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> operator * (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CReal<T_Type>(a_crInstance.m_Value * a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CReal<T_Type> operator * (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return CReal<T_Type>(a_crInstance1.m_Value * a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> operator * (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return CReal<T_Type>(a_cValue * a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> operator / (const CReal<T_Type>& a_crInstance, const T_Type a_cValue)
{ CALL
  return CReal<T_Type>(a_crInstance.m_Value / a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CReal<T_Type> operator / (const CReal<T_Type>& a_crInstance1, const CReal<T_OtherType>& a_crInstance2)
{ CALL
  return CReal<T_Type>(a_crInstance1.m_Value / a_crInstance2.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> operator / (const T_Type a_cValue, const CReal<T_Type>& a_crInstance)
{ CALL
  return CReal<T_Type>(a_cValue / a_crInstance.m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>& CReal<T_Type>::operator = (const T_Type a_cValue)
{ CALL
  set(a_cValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CReal<T_Type>& CReal<T_Type>::operator = (const CReal<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>& CReal<T_Type>::operator += (const T_Type a_cValue)
{ CALL
  m_Value += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CReal<T_Type>& CReal<T_Type>::operator += (const CReal<T_OtherType>& a_crInstance)
{ CALL
  m_Value += a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>& CReal<T_Type>::operator -= (const T_Type a_cValue)
{ CALL
  m_Value -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CReal<T_Type>& CReal<T_Type>::operator -= (const CReal<T_OtherType>& a_crInstance)
{ CALL
  m_Value -= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>& CReal<T_Type>::operator *= (const T_Type a_cValue)
{ CALL
  m_Value *= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CReal<T_Type>& CReal<T_Type>::operator *= (const CReal<T_OtherType>& a_crInstance)
{ CALL
  m_Value *= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>& CReal<T_Type>::operator /= (const T_Type a_cValue)
{ CALL
  m_Value /= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CReal<T_Type>& CReal<T_Type>::operator /= (const CReal<T_OtherType>& a_crInstance)
{ CALL
  m_Value /= a_crInstance.m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>& CReal<T_Type>::operator ++ ()
{ CALL
  ++m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> CReal<T_Type>::operator ++ (int)
{ CALL
  CReal<T_Type> temp(*this);

  m_Value++;
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>& CReal<T_Type>::operator -- ()
{ CALL
  --m_Value;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type> CReal<T_Type>::operator -- (int)
{ CALL
  CReal<T_Type> temp(*this);

  m_Value--;
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>::operator T_Type& ()
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>::operator const T_Type& () const
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>::operator T_Type* ()
{ CALL
  return &m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CReal<T_Type>::operator const T_Type* () const
{ CALL
  return &m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CReal<T_Type>::set(const T_Type a_cValue)
{ CALL
  m_Value = a_cValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CReal<T_Type>::set(const CReal<T_OtherType>& a_crInstance)
{ CALL
  m_Value = (T_Type)a_crInstance.getValue();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CReal<T_Type>::getValue() const
{ CALL
  return m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CReal<T_Type>::clear()
{ CALL
  m_Value = (T_Type)0.0;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CReal<T_Type>::absolute()
{ CALL
  m_Value = NAlgorithms::NNumeric::absolute(m_Value);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CReal<T_Type>::negate()
{ CALL
  m_Value = -m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tsint CReal<T_Type>::getBitSize()
{ CALL
  return (Tsint)(sizeof(T_Type) << 3);
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tfloat>::getBitSize()
{ CALL
  return (Tsint)(sizeof(Tfloat) << 3);
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tdouble>::getBitSize()
{ CALL
  return (Tsint)(sizeof(Tdouble) << 3);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tsint CReal<T_Type>::getByteSize()
{ CALL
  return (Tsint)(sizeof(T_Type));
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tfloat>::getByteSize()
{ CALL
  return (Tsint)(sizeof(Tfloat));
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tdouble>::getByteSize()
{ CALL
  return (Tsint)(sizeof(Tdouble));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CReal<T_Type>::getMin()
{ CALL
  return (T_Type)NConstants::CConstants::realMin;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tfloat CReal<Tfloat>::getMin()
{ CALL
  return NConstants::CConstants::floatMin;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tdouble CReal<Tdouble>::getMin()
{ CALL
  return NConstants::CConstants::doubleMin;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CReal<T_Type>::getMax()
{ CALL
  return (T_Type)NConstants::CConstants::realMax;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tfloat CReal<Tfloat>::getMax()
{ CALL
  return NConstants::CConstants::floatMax;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tdouble CReal<Tdouble>::getMax()
{ CALL
  return NConstants::CConstants::doubleMax;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CReal<T_Type>::getEpsilon()
{ CALL
  return (T_Type)NConstants::CConstants::realEps;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tfloat CReal<Tfloat>::getEpsilon()
{ CALL
  return NConstants::CConstants::floatEps;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tdouble CReal<Tdouble>::getEpsilon()
{ CALL
  return NConstants::CConstants::doubleEps;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CReal<T_Type>::getCompareEpsilon()
{ CALL
  return (T_Type)NConstants::CConstants::realCompareEps;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tfloat CReal<Tfloat>::getCompareEpsilon()
{ CALL
  return NConstants::CConstants::floatCompareEps;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tdouble CReal<Tdouble>::getCompareEpsilon()
{ CALL
  return NConstants::CConstants::doubleCompareEps;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tsint CReal<T_Type>::getPrecDigits()
{ CALL
  return NConstants::CConstants::realPrec;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tfloat>::getPrecDigits()
{ CALL
  return NConstants::CConstants::floatPrec;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tdouble>::getPrecDigits()
{ CALL
  return NConstants::CConstants::doublePrec;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tsint CReal<T_Type>::getMantDigits()
{ CALL
  return NConstants::CConstants::realMant;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tfloat>::getMantDigits()
{ CALL
  return NConstants::CConstants::floatMant;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tdouble>::getMantDigits()
{ CALL
  return NConstants::CConstants::doubleMant;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tsint CReal<T_Type>::getMinExp()
{ CALL
  return NConstants::CConstants::realMinExp;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tfloat>::getMinExp()
{ CALL
  return NConstants::CConstants::floatMinExp;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tdouble>::getMinExp()
{ CALL
  return NConstants::CConstants::doubleMinExp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tsint CReal<T_Type>::getMaxExp()
{ CALL
  return NConstants::CConstants::realMaxExp;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tfloat>::getMaxExp()
{ CALL
  return NConstants::CConstants::floatMaxExp;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tdouble>::getMaxExp()
{ CALL
  return NConstants::CConstants::doubleMaxExp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tsint CReal<T_Type>::getMin10Exp()
{ CALL
  return NConstants::CConstants::realMin10Exp;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tfloat>::getMin10Exp()
{ CALL
  return NConstants::CConstants::floatMin10Exp;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tdouble>::getMin10Exp()
{ CALL
  return NConstants::CConstants::doubleMin10Exp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tsint CReal<T_Type>::getMax10Exp()
{ CALL
  return NConstants::CConstants::realMax10Exp;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tfloat>::getMax10Exp()
{ CALL
  return NConstants::CConstants::floatMax10Exp;
}
/*--------------------------------------------------------------------------*/
template <>
inline Tsint CReal<Tdouble>::getMax10Exp()
{ CALL
  return NConstants::CConstants::doubleMax10Exp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CReal<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NBase::CReal<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Value, STR("m_Value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CReal<T_Type>::swap(CReal<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Value, a_rInstance.m_Value);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
