/*!
 *  \file    ATieComparable.inl Contains general template implementation of
 *           the comparable tie algorithm.
 *  \brief   Comparable tie algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable tie algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   04.09.2006 22:27:44

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
#ifndef __ATIECOMPARABLE_INL__
#define __ATIECOMPARABLE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_Type>
inline NTuple::CComparableTuple<NBase::CReference<T_Type> > tieComparable(T_Type& a_rValue)
{ CALL
  return NTuple::CComparableTupleTier::tie(a_rValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2>
inline NTuple::CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2> > tieComparable(T_Type1& a_rValue1, T_Type2& a_rValue2)
{ CALL
  return NTuple::CComparableTupleTier::tie(a_rValue1, a_rValue2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3>
inline NTuple::CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3> > tieComparable(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3)
{ CALL
  return NTuple::CComparableTupleTier::tie(a_rValue1, a_rValue2, a_rValue3);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4>
inline NTuple::CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4> > tieComparable(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4)
{ CALL
  return NTuple::CComparableTupleTier::tie(a_rValue1, a_rValue2, a_rValue3, a_rValue4);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5>
inline NTuple::CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5> > tieComparable(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5)
{ CALL
  return NTuple::CComparableTupleTier::tie(a_rValue1, a_rValue2, a_rValue3, a_rValue4, a_rValue5);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6>
inline NTuple::CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6> > tieComparable(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6)
{ CALL
  return NTuple::CComparableTupleTier::tie(a_rValue1, a_rValue2, a_rValue3, a_rValue4, a_rValue5, a_rValue6);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7>
inline NTuple::CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7> > tieComparable(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7)
{ CALL
  return NTuple::CComparableTupleTier::tie(a_rValue1, a_rValue2, a_rValue3, a_rValue4, a_rValue5, a_rValue6, a_rValue7);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8>
inline NTuple::CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8> > tieComparable(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8)
{ CALL
  return NTuple::CComparableTupleTier::tie(a_rValue1, a_rValue2, a_rValue3, a_rValue4, a_rValue5, a_rValue6, a_rValue7, a_rValue8);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9>
inline NTuple::CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9> > tieComparable(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8, T_Type9& a_rValue9)
{ CALL
  return NTuple::CComparableTupleTier::tie(a_rValue1, a_rValue2, a_rValue3, a_rValue4, a_rValue5, a_rValue6, a_rValue7, a_rValue8, a_rValue9);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type1, typename T_Type2, typename T_Type3, typename T_Type4, typename T_Type5, typename T_Type6, typename T_Type7, typename T_Type8, typename T_Type9, typename T_Type10>
inline NTuple::CComparableTuple<NBase::CReference<T_Type1>, NBase::CReference<T_Type2>, NBase::CReference<T_Type3>, NBase::CReference<T_Type4>, NBase::CReference<T_Type5>, NBase::CReference<T_Type6>, NBase::CReference<T_Type7>, NBase::CReference<T_Type8>, NBase::CReference<T_Type9>, NBase::CReference<T_Type10> > tieComparable(T_Type1& a_rValue1, T_Type2& a_rValue2, T_Type3& a_rValue3, T_Type4& a_rValue4, T_Type5& a_rValue5, T_Type6& a_rValue6, T_Type7& a_rValue7, T_Type8& a_rValue8, T_Type9& a_rValue9, T_Type10& a_rValue10)
{ CALL
  return NTuple::CComparableTupleTier::tie(a_rValue1, a_rValue2, a_rValue3, a_rValue4, a_rValue5, a_rValue6, a_rValue7, a_rValue8, a_rValue9, a_rValue10);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
