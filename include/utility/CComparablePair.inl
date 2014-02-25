/*!
 *  \file    CComparablePair.inl Comparable pair template class represents
 *           data structure which contains two comparable fields: first (key),
 *           second (value). Comparison can be made with external 'LessThan'
 *           binary predicate comparators.
 *  \brief   Comparable pair template class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable pair template class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   03.03.2006 20:33:27

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
#ifndef __CCOMPARABLEPAIR_INL__
#define __CCOMPARABLEPAIR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::CComparablePair(T_FirstLessThanBinaryPredicate a_fFirstLessThan/* = T_FirstLessThanBinaryPredicate() */, T_SecondLessThanBinaryPredicate a_fSecondLessThan/* = T_SecondLessThanBinaryPredicate() */) :
  m_First(),
  m_Second(),
  m_fFirstLessThan(a_fFirstLessThan),
  m_fSecondLessThan(a_fSecondLessThan)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::CComparablePair(const T_FirstType& a_crFirstValue, const T_SecondType& a_crSecondValue, T_FirstLessThanBinaryPredicate a_fFirstLessThan/* = T_FirstLessThanBinaryPredicate() */, T_SecondLessThanBinaryPredicate a_fSecondLessThan/* = T_SecondLessThanBinaryPredicate() */) :
  m_First(a_crFirstValue),
  m_Second(a_crSecondValue),
  m_fFirstLessThan(a_fFirstLessThan),
  m_fSecondLessThan(a_fSecondLessThan)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate>
inline CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::CComparablePair(const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance, T_FirstLessThanBinaryPredicate a_fFirstLessThan/* = T_FirstLessThanBinaryPredicate() */, T_SecondLessThanBinaryPredicate a_fSecondLessThan/* = T_SecondLessThanBinaryPredicate() */) :
  m_First((T_FirstType)a_crInstance.getFirst()),
  m_Second((T_SecondType)a_crInstance.getSecond()),
  m_fFirstLessThan(a_fFirstLessThan),
  m_fSecondLessThan(a_fSecondLessThan)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::~CComparablePair()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate, typename T_OtherFirstType, typename T_OtherSecondType>
Tbool operator == (const CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance2)
{ CALL
  return ((!(a_crInstance1.isFirstLessThan(a_crInstance1.getFirst(), a_crInstance2.getFirst())) && !(a_crInstance2.isFirstLessThan(a_crInstance2.getFirst(), a_crInstance1.getFirst()))) && (!(a_crInstance1.isSecondLessThan(a_crInstance1.getSecond(), a_crInstance2.getSecond())) && !(a_crInstance2.isSecondLessThan(a_crInstance2.getSecond(), a_crInstance1.getSecond()))));
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate, typename T_OtherFirstType, typename T_OtherSecondType>
Tbool operator != (const CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance2)
{ CALL
  return (((a_crInstance1.isFirstLessThan(a_crInstance1.getFirst(), a_crInstance2.getFirst())) || (a_crInstance2.isFirstLessThan(a_crInstance2.getFirst(), a_crInstance1.getFirst()))) || ((a_crInstance1.isSecondLessThan(a_crInstance1.getSecond(), a_crInstance2.getSecond())) || (a_crInstance2.isSecondLessThan(a_crInstance2.getSecond(), a_crInstance1.getSecond()))));
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate, typename T_OtherFirstType, typename T_OtherSecondType>
Tbool operator < (const CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance2)
{ CALL
  return ((a_crInstance1.isFirstLessThan(a_crInstance1.getFirst(), a_crInstance2.getFirst())) || (!(a_crInstance2.isFirstLessThan(a_crInstance2.getFirst(), a_crInstance1.getFirst())) && (a_crInstance1.isSecondLessThan(a_crInstance1.getSecond(), a_crInstance2.getSecond()))));
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate, typename T_OtherFirstType, typename T_OtherSecondType>
Tbool operator > (const CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance2)
{ CALL
  return ((a_crInstance2.isFirstLessThan(a_crInstance2.getFirst(), a_crInstance1.getFirst())) || (!(a_crInstance1.isFirstLessThan(a_crInstance1.getFirst(), a_crInstance2.getFirst())) && (a_crInstance2.isSecondLessThan(a_crInstance2.getSecond(), a_crInstance1.getSecond()))));
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate, typename T_OtherFirstType, typename T_OtherSecondType>
Tbool operator <= (const CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance2)
{ CALL
  return !(a_crInstance2 < a_crInstance1);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate, typename T_OtherFirstType, typename T_OtherSecondType>
Tbool operator >= (const CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance1, const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance2)
{ CALL
  return !(a_crInstance1 < a_crInstance2);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate>
inline CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::operator = (const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline void CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::set(const T_FirstType& a_crFirstValue, const T_SecondType& a_crSecondValue)
{ CALL
  m_First = a_crFirstValue;
  m_Second = a_crSecondValue;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
template <typename T_OtherFirstType, typename T_OtherSecondType, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate>
inline void CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::set(const CComparablePair<T_OtherFirstType, T_OtherSecondType, T_OtherFirstLessThanBinaryPredicate, T_OtherSecondLessThanBinaryPredicate>& a_crInstance)
{ CALL
  m_First = (T_FirstType)a_crInstance.getFirst();
  m_Second = (T_SecondType)a_crInstance.getSecond();
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline T_FirstType& CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::getFirst()
{ CALL
  return m_First;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline const T_FirstType& CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::getFirst() const
{ CALL
  return m_First;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline T_SecondType& CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::getSecond()
{ CALL
  return m_Second;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline const T_SecondType& CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::getSecond() const
{ CALL
  return m_Second;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline Tbool CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::isFirstLessThan(const T_FirstType& a_crValue1, const T_FirstType& a_crValue2) const
{ CALL
  return m_fFirstLessThan(a_crValue1, a_crValue2);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline Tbool CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::isSecondLessThan(const T_SecondType& a_crValue1, const T_SecondType& a_crValue2) const
{ CALL
  return m_fSecondLessThan(a_crValue1, a_crValue2);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
template <class T_Archive>
inline Tbool CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_First, STR("m_First")));
    CHECK(a_rArchive.doValue(m_Second, STR("m_Second")));
    CHECK(a_rArchive.doValue(m_fFirstLessThan, STR("m_fFirstLessThan")));
    CHECK(a_rArchive.doValue(m_fSecondLessThan, STR("m_fSecondLessThan")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline void CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>::swap(CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_First, a_rInstance.m_First);
  NAlgorithms::NCommon::swap(m_Second, a_rInstance.m_Second);
  NAlgorithms::NCommon::swap(m_fFirstLessThan, a_rInstance.m_fFirstLessThan);
  NAlgorithms::NCommon::swap(m_fSecondLessThan, a_rInstance.m_fSecondLessThan);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
