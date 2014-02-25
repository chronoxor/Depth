/*!
 *  \file    CComparableDuoRecursive.inl Comparable duo template class
 *           represents comparable data structure which contains two
 *           fields (v1, v2) with different data types. Comparison can
 *           be made with '<' operator. Specialization of the recursive
 *           comparable duo.
 *  \brief   Comparable duo template class (recursive comparable duo specialization) (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable duo template class (recursive comparable duo specialization) (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tuple details
    VERSION:   1.0
    CREATED:   30.01.2007 23:15:36

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
#ifndef __CCOMPARABLEDUORECURSIVE_INL__
#define __CCOMPARABLEDUORECURSIVE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTuple {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::CComparableDuo() :
  m_Value1(),
  m_Value2()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::CComparableDuo(const T_Type1& a_crValue1, const CComparableDuo<T_Type2, T_Type3>& a_crValue2) :
  m_Value1(a_crValue1),
  m_Value2(a_crValue2)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
inline CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::CComparableDuo(const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance) :
  m_Value1((T_Type1)a_crInstance.getValue1()),
  m_Value2((CComparableDuo<T_Type2, T_Type3>)a_crInstance.getValue2())
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::~CComparableDuo()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
Tbool operator == (const CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >& a_crInstance1, const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance2)
{ CALL
  return ((!(a_crInstance1.getValue1() < a_crInstance2.getValue1()) && !(a_crInstance2.getValue1() < a_crInstance1.getValue1())) && (!(a_crInstance1.getValue2() < a_crInstance2.getValue2()) && !(a_crInstance2.getValue2() < a_crInstance1.getValue2())));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
Tbool operator != (const CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >& a_crInstance1, const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance2)
{ CALL
  return (((a_crInstance1.getValue1() < a_crInstance2.getValue1()) || (a_crInstance2.getValue1() < a_crInstance1.getValue1())) || ((a_crInstance1.getValue2() < a_crInstance2.getValue2()) || (a_crInstance2.getValue2() < a_crInstance1.getValue2())));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
Tbool operator < (const CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >& a_crInstance1, const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance2)
{ CALL
  return ((a_crInstance1.getValue1() < a_crInstance2.getValue1()) || (!(a_crInstance2.getValue1() < a_crInstance1.getValue1()) && (a_crInstance1.getValue2() < a_crInstance2.getValue2())));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
Tbool operator > (const CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >& a_crInstance1, const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance2)
{ CALL
  return ((a_crInstance2.getValue1() < a_crInstance1.getValue1()) || (!(a_crInstance1.getValue1() < a_crInstance2.getValue1()) && (a_crInstance2.getValue2() < a_crInstance1.getValue2())));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
Tbool operator <= (const CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >& a_crInstance1, const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance2)
{ CALL
  return !(a_crInstance2 < a_crInstance1);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
Tbool operator >= (const CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >& a_crInstance1, const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance2)
{ CALL
  return !(a_crInstance1 < a_crInstance2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
inline CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >& CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::operator = (const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline void CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::set(const T_Type1& a_crValue1, const CComparableDuo<T_Type2, T_Type3>& a_crValue2)
{ CALL
  m_Value1 = a_crValue1;
  m_Value2 = a_crValue2;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
template <typename T_OtherType1, typename T_OtherType2, typename T_OtherType3>
inline void CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::set(const CComparableDuo<T_OtherType1, CComparableDuo<T_OtherType2, T_OtherType3> >& a_crInstance)
{ CALL
  m_Value1 = (T_Type1)a_crInstance.getValue1();
  m_Value2 = a_crInstance.getValue2();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline T_Type1& CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::getValue1()
{ CALL
  return m_Value1;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline const T_Type1& CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::getValue1() const
{ CALL
  return m_Value1;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline CComparableDuo<T_Type2, T_Type3>& CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::getValue2()
{ CALL
  return m_Value2;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline const CComparableDuo<T_Type2, T_Type3>& CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::getValue2() const
{ CALL
  return m_Value2;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
template <class T_Archive>
inline Tbool CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTuple::NDetails::CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Value1, STR("m_Value1")));
    CHECK(a_rArchive.doValue(m_Value2, STR("m_Value2")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline void CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >::swap(CComparableDuo<T_Type1, CComparableDuo<T_Type2, T_Type3> >& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Value1, a_rInstance.m_Value1);
  NAlgorithms::NCommon::swap(m_Value2, a_rInstance.m_Value2);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
