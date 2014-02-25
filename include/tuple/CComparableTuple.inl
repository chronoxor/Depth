/*!
 *  \file    CComparableTuple.inl Comparable tuple represents template
 *           comparable data structure with many elements inside. It
 *           can be used as a function return value to give ability to
 *           return from function more than one value. Comparison can
 *           be made with '<' operator.
 *  \brief   Comparable tuple template class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable tuple template class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple
    VERSION:   1.0
    CREATED:   30.01.2007 00:03:38

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
#ifndef __CCOMPARABLETUPLE_INL__
#define __CCOMPARABLETUPLE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
inline CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::CComparableTuple() :
  TBase()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
inline CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::CComparableTuple(const T_Type1& a_crValue1, const T_Type2& a_crValue2/* = NBase::CBlank() */, const T_Type3& a_crValue3/* = NBase::CBlank() */, const T_Type4& a_crValue4/* = NBase::CBlank() */, const T_Type5& a_crValue5/* = NBase::CBlank() */, const T_Type6& a_crValue6/* = NBase::CBlank() */, const T_Type7& a_crValue7/* = NBase::CBlank() */, const T_Type8& a_crValue8/* = NBase::CBlank() */, const T_Type9& a_crValue9/* = NBase::CBlank() */, const T_Type10& a_crValue10/* = NBase::CBlank() */) :
  TBase(a_crValue1, CComparableTuple<T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10, NBase::CBlank>(a_crValue2, a_crValue3, a_crValue4, a_crValue5, a_crValue6, a_crValue7, a_crValue8, a_crValue9, a_crValue10))
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
inline CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::CComparableTuple(const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance) :
  TBase(a_crInstance)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
inline CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::~CComparableTuple()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
inline Tbool operator == (const CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance2)
{ CALL
  return NDetails::operator == ((const typename CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
inline Tbool operator != (const CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance2)
{ CALL
  return NDetails::operator != ((const typename CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
inline Tbool operator < (const CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance2)
{ CALL
  return NDetails::operator < ((const typename CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
inline Tbool operator > (const CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance2)
{ CALL
  return NDetails::operator > ((const typename CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
inline Tbool operator <= (const CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance2)
{ CALL
  return NDetails::operator <= ((const typename CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
inline Tbool operator >= (const CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance2)
{ CALL
  return NDetails::operator >= ((const typename CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
inline CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::operator = (const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
inline void CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::set(const T_Type1& a_crValue1, const T_Type2& a_crValue2/* = NBase::CBlank() */, const T_Type3& a_crValue3/* = NBase::CBlank() */, const T_Type4& a_crValue4/* = NBase::CBlank() */, const T_Type5& a_crValue5/* = NBase::CBlank() */, const T_Type6& a_crValue6/* = NBase::CBlank() */, const T_Type7& a_crValue7/* = NBase::CBlank() */, const T_Type8& a_crValue8/* = NBase::CBlank() */, const T_Type9& a_crValue9/* = NBase::CBlank() */, const T_Type10& a_crValue10/* = NBase::CBlank() */)
{ CALL
  return CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase::set(a_crValue1, CComparableTuple<T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10, NBase::CBlank>(a_crValue2, a_crValue3, a_crValue4, a_crValue5, a_crValue6, a_crValue7, a_crValue8, a_crValue9, a_crValue10));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3, typename T_OtherType4, typename T_OtherType5, typename T_OtherType6, typename T_OtherType7, typename T_OtherType8, typename T_OtherType9, typename T_OtherType10>
inline void CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::set(const CComparableTuple<T_OtherType1, T_OtherType2, T_OtherType3, T_OtherType4, T_OtherType5, T_OtherType6, T_OtherType7, T_OtherType8, T_OtherType9, T_OtherType10>& a_crInstance)
{ CALL
  return CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
template <Tsint t_N>
inline typename MComparableTupleType<t_N, typename CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase>::TType& CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::getValue()
{ CALL
  return MComparableTupleValue<t_N, TBase>::getValue(*this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
template <Tsint t_N>
inline const typename MComparableTupleType<t_N, typename CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase>::TType& CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::getValue() const
{ CALL
  return MComparableTupleValue<t_N, TBase>::getValue(*this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
template <class T_Archive>
inline Tbool CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTuple::CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((typename CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
inline void CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::swap(CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((typename CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase&)(*this), (typename CComparableTuple<T_Type1, T_Type2, T_Type3, T_Type4, T_Type5, T_Type6, T_Type7, T_Type8, T_Type9, T_Type10>::TBase&)(a_rInstance));
}
/*==========================================================================*/
template <typename T_Type>
inline CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::CComparableTuple() :
  TBase()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::CComparableTuple(const T_Type& a_crValue1, const NBase::CBlank& a_crValue2/* = NBase::CBlank() */, const NBase::CBlank& a_crValue3/* = NBase::CBlank() */, const NBase::CBlank& a_crValue4/* = NBase::CBlank() */, const NBase::CBlank& a_crValue5/* = NBase::CBlank() */, const NBase::CBlank& a_crValue6/* = NBase::CBlank() */, const NBase::CBlank& a_crValue7/* = NBase::CBlank() */, const NBase::CBlank& a_crValue8/* = NBase::CBlank() */, const NBase::CBlank& a_crValue9/* = NBase::CBlank() */, const NBase::CBlank& a_crValue10/* = NBase::CBlank() */) :
  TBase(a_crValue1)
{ CALL
  IGNORE_UNUSED(a_crValue2);
  IGNORE_UNUSED(a_crValue3);
  IGNORE_UNUSED(a_crValue4);
  IGNORE_UNUSED(a_crValue5);
  IGNORE_UNUSED(a_crValue6);
  IGNORE_UNUSED(a_crValue7);
  IGNORE_UNUSED(a_crValue8);
  IGNORE_UNUSED(a_crValue9);
  IGNORE_UNUSED(a_crValue10);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::CComparableTuple(const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance) :
  TBase(a_crInstance)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::~CComparableTuple()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator == (const CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator == ((const typename CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator != (const CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator != ((const typename CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator < (const CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator < ((const typename CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator > (const CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator > ((const typename CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator <= (const CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator <= ((const typename CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator >= (const CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator >= ((const typename CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::operator = (const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::set(const T_Type& a_crValue1, const NBase::CBlank& a_crValue2/* = NBase::CBlank() */, const NBase::CBlank& a_crValue3/* = NBase::CBlank() */, const NBase::CBlank& a_crValue4/* = NBase::CBlank() */, const NBase::CBlank& a_crValue5/* = NBase::CBlank() */, const NBase::CBlank& a_crValue6/* = NBase::CBlank() */, const NBase::CBlank& a_crValue7/* = NBase::CBlank() */, const NBase::CBlank& a_crValue8/* = NBase::CBlank() */, const NBase::CBlank& a_crValue9/* = NBase::CBlank() */, const NBase::CBlank& a_crValue10/* = NBase::CBlank() */)
{ CALL
  IGNORE_UNUSED(a_crValue2);
  IGNORE_UNUSED(a_crValue3);
  IGNORE_UNUSED(a_crValue4);
  IGNORE_UNUSED(a_crValue5);
  IGNORE_UNUSED(a_crValue6);
  IGNORE_UNUSED(a_crValue7);
  IGNORE_UNUSED(a_crValue8);
  IGNORE_UNUSED(a_crValue9);
  IGNORE_UNUSED(a_crValue10);

  return CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase::set(a_crValue1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::set(const CComparableTuple<T_OtherType, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance)
{ CALL
  return CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <Tsint t_N>
inline typename MComparableTupleType<t_N, typename CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase>::TType& CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::getValue()
{ CALL
  return MComparableTupleValue<t_N, TBase>::getValue(*this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <Tsint t_N>
inline const typename MComparableTupleType<t_N, typename CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase>::TType& CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::getValue() const
{ CALL
  return MComparableTupleValue<t_N, TBase>::getValue(*this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTuple::CComparableTuple<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((typename CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::swap(CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((typename CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(*this), (typename CComparableTuple<T_Type, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_rInstance));
}
/*==========================================================================*/
template <typename T_Type1, typename T_Type2>
inline CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::CComparableTuple() :
  TBase()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::CComparableTuple(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const NBase::CBlank& a_crValue3/* = NBase::CBlank() */, const NBase::CBlank& a_crValue4/* = NBase::CBlank() */, const NBase::CBlank& a_crValue5/* = NBase::CBlank() */, const NBase::CBlank& a_crValue6/* = NBase::CBlank() */, const NBase::CBlank& a_crValue7/* = NBase::CBlank() */, const NBase::CBlank& a_crValue8/* = NBase::CBlank() */, const NBase::CBlank& a_crValue9/* = NBase::CBlank() */, const NBase::CBlank& a_crValue10/* = NBase::CBlank() */) :
  TBase(a_crValue1, a_crValue2)
{ CALL
  IGNORE_UNUSED(a_crValue3);
  IGNORE_UNUSED(a_crValue4);
  IGNORE_UNUSED(a_crValue5);
  IGNORE_UNUSED(a_crValue6);
  IGNORE_UNUSED(a_crValue7);
  IGNORE_UNUSED(a_crValue8);
  IGNORE_UNUSED(a_crValue9);
  IGNORE_UNUSED(a_crValue10);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
template <typename T_OtherType1, typename T_OtherType2>
inline CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::CComparableTuple(const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance) :
  TBase(a_crInstance)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::~CComparableTuple()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_OtherType1, typename T_OtherType2>
inline Tbool operator == (const CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator == ((const typename CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_OtherType1, typename T_OtherType2>
inline Tbool operator != (const CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator != ((const typename CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_OtherType1, typename T_OtherType2>
inline Tbool operator < (const CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator < ((const typename CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_OtherType1, typename T_OtherType2>
inline Tbool operator > (const CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator > ((const typename CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_OtherType1, typename T_OtherType2>
inline Tbool operator <= (const CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator <= ((const typename CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_OtherType1, typename T_OtherType2>
inline Tbool operator >= (const CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance1, const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance2)
{ CALL
  return NDetails::operator >= ((const typename CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance1), (const typename CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
template <typename T_OtherType1, typename T_OtherType2>
inline CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::operator = (const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline void CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::set(const T_Type1& a_crValue1, const T_Type2& a_crValue2, const NBase::CBlank& a_crValue3/* = NBase::CBlank() */, const NBase::CBlank& a_crValue4/* = NBase::CBlank() */, const NBase::CBlank& a_crValue5/* = NBase::CBlank() */, const NBase::CBlank& a_crValue6/* = NBase::CBlank() */, const NBase::CBlank& a_crValue7/* = NBase::CBlank() */, const NBase::CBlank& a_crValue8/* = NBase::CBlank() */, const NBase::CBlank& a_crValue9/* = NBase::CBlank() */, const NBase::CBlank& a_crValue10/* = NBase::CBlank() */)
{ CALL
  IGNORE_UNUSED(a_crValue3);
  IGNORE_UNUSED(a_crValue4);
  IGNORE_UNUSED(a_crValue5);
  IGNORE_UNUSED(a_crValue6);
  IGNORE_UNUSED(a_crValue7);
  IGNORE_UNUSED(a_crValue8);
  IGNORE_UNUSED(a_crValue9);
  IGNORE_UNUSED(a_crValue10);

  return CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase::set(a_crValue1, a_crValue2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
template <typename T_OtherType1, typename T_OtherType2>
inline void CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::set(const CComparableTuple<T_OtherType1, T_OtherType2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_crInstance)
{ CALL
  return CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
template <Tsint t_N>
inline typename MComparableTupleType<t_N, typename CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase>::TType& CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::getValue()
{ CALL
  return MComparableTupleValue<t_N, TBase>::getValue(*this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
template <Tsint t_N>
inline const typename MComparableTupleType<t_N, typename CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase>::TType& CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::getValue() const
{ CALL
  return MComparableTupleValue<t_N, TBase>::getValue(*this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
template <class T_Archive>
inline Tbool CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTuple::CComparableTuple<T_Type1, T_Type2>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((typename CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline void CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::swap(CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((typename CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(*this), (typename CComparableTuple<T_Type1, T_Type2, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank, NBase::CBlank>::TBase&)(a_rInstance));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
