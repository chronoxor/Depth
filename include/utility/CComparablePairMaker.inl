/*!
 *  \file    CComparablePairMaker.inl Utility class that helps to make
 *           CComparablePair instances from specified values.
 *  \brief   Comparable pair maker class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable pair maker class (inline).

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
#ifndef __CCOMPARABLEPAIRMAKER_INL__
#define __CCOMPARABLEPAIRMAKER_INL__
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
inline CComparablePair<T_FirstType, T_SecondType> CComparablePairMaker::make(const T_FirstType& a_crFirstValue, const T_SecondType& a_crSecondValue)
{ CALL
  return CComparablePair<T_FirstType, T_SecondType>(a_crFirstValue, a_crSecondValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> CComparablePairMaker::make(const T_FirstType& a_crFirstValue, const T_SecondType& a_crSecondValue, T_FirstLessThanBinaryPredicate a_fFirstLessThan, T_SecondLessThanBinaryPredicate a_fSecondLessThan)
{ CALL
  return CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>(a_crFirstValue, a_crSecondValue, a_fFirstLessThan, a_fSecondLessThan);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
inline CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> CComparablePairMaker::make(const CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance)
{ CALL
  return CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate>
inline CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> CComparablePairMaker::make(const CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_crInstance, T_OtherFirstLessThanBinaryPredicate a_fFirstLessThan, T_OtherSecondLessThanBinaryPredicate a_fSecondLessThan)
{ CALL
  return CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>(a_crInstance, a_fFirstLessThan, a_fSecondLessThan);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
