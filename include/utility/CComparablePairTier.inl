/*!
 *  \file    CComparablePairTier.inl Utility class that helps to tie
 *           CComparablePair instances with specified references to values.
 *  \brief   Comparable pair tier class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable pair tier class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   05.03.2006 22:16:28

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
#ifndef __CCOMPARABLEPAIRTIER_INL__
#define __CCOMPARABLEPAIRTIER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_FirstType, typename T_SecondType>
inline CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> > CComparablePairTier::tie(T_FirstType& a_rFirstValue, T_SecondType& a_rSecondValue)
{ CALL
  return CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> >(NBase::CReference<T_FirstType>(a_rFirstValue), NBase::CReference<T_SecondType>(a_rSecondValue));
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> CComparablePairTier::tie(T_FirstType& a_rFirstValue, T_SecondType& a_rSecondValue, T_FirstLessThanBinaryPredicate a_fFirstLessThan, T_SecondLessThanBinaryPredicate a_fSecondLessThan)
{ CALL
  return CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>(NBase::CReference<T_FirstType>(a_rFirstValue), NBase::CReference<T_SecondType>(a_rSecondValue), a_fFirstLessThan, a_fSecondLessThan);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> CComparablePairTier::tie(CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_rInstance)
{ CALL
  return CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>(NBase::CReference<T_FirstType>(a_rInstance.getFirst()), NBase::CReference<T_SecondType>(a_rInstance.getSecond()));
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate>
inline CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> CComparablePairTier::tie(CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_rInstance, T_OtherFirstLessThanBinaryPredicate a_fFirstLessThan, T_OtherSecondLessThanBinaryPredicate a_fSecondLessThan)
{ CALL
  return CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>(NBase::CReference<T_FirstType>(a_rInstance.getFirst()), NBase::CReference<T_SecondType>(a_rInstance.getSecond()), a_fFirstLessThan, a_fSecondLessThan);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> CComparablePairTier::tie(CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_rInstance)
{ CALL
  return CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>(a_rInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate>
inline CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> CComparablePairTier::tie(CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_rInstance, T_OtherFirstLessThanBinaryPredicate a_fFirstLessThan, T_OtherSecondLessThanBinaryPredicate a_fSecondLessThan)
{ CALL
  return CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>(a_rInstance, a_fFirstLessThan, a_fSecondLessThan);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
