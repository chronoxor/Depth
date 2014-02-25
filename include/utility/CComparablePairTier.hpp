/*!
 *  \file    CComparablePairTier.hpp Utility class that helps to tie
 *           CComparablePair instances with specified references to values.
 *  \brief   Comparable pair tier class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Comparable pair tier class.

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
#ifndef __CCOMPARABLEPAIRTIER_HPP__
#define __CCOMPARABLEPAIRTIER_HPP__
/*==========================================================================*/
#include <Depth/include/base/CReference.hpp>
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/utility/CComparablePair.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Comparable pair tier class.
/*!
    With this utility class template CComparablePair  instances  can  be  tied
    with given references to values.
*/
class BASE_API CComparablePairTier :
  public NDepth::NCommon::IStatic
{
public:
  //! Tie CComparablePair instance with given references to values.
  /*!
      \param a_rFirstValue - Reference to the first comparable pair value.
      \param a_rSecondValue - Reference to the second comparable pair value.
      \return CComparablePair class instance with tied references.
  */
  template <typename T_FirstType, typename T_SecondType>
  static CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> > tie(T_FirstType& a_rFirstValue, T_SecondType& a_rSecondValue);
  //! Tie CComparablePair instance with given references to values with given 'LessThan' binary predicate comparators.
  /*!
      \param a_rFirstValue - Reference to the first comparable pair value.
      \param a_rSecondValue - Reference to the second comparable pair value.
      \param a_fFirstLessThan - 'LessThan' binary predicate comparator for the first type.
      \param a_fSecondLessThan - 'LessThan' binary predicate comparator for the second type.
      \return CComparablePair class instance with tied references.
  */
  template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
  static CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> tie(T_FirstType& a_rFirstValue, T_SecondType& a_rSecondValue, T_FirstLessThanBinaryPredicate a_fFirstLessThan, T_SecondLessThanBinaryPredicate a_fSecondLessThan);
  //! Tie CComparablePair instance with specified CComparablePair class instance.
  /*!
      \param a_rInstance - Reference to another instance of the CComparablePair class.
      \return CComparablePair class instance with tied references.
  */
  template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
  static CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> tie(CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_rInstance);
  //! Tie CComparablePair instance with specified CComparablePair class instance with given 'LessThan' binary predicate comparators.
  /*!
      \param a_rInstance - Reference to another instance of the CComparablePair class.
      \param a_fFirstLessThan - 'LessThan' binary predicate comparator for the first type.
      \param a_fSecondLessThan - 'LessThan' binary predicate comparator for the second type.
      \return CComparablePair class instance with tied references.
  */
  template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate>
  static CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> tie(CComparablePair<T_FirstType, T_SecondType, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_rInstance, T_OtherFirstLessThanBinaryPredicate a_fFirstLessThan, T_OtherSecondLessThanBinaryPredicate a_fSecondLessThan);
  //! Tie CComparablePair instance with another tied CComparablePair class instance.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparablePair class.
      \return CComparablePair class instance with tied references.
  */
  template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate>
  static CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> tie(CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_rInstance);
  //! Tie CComparablePair instance with another tied CComparablePair class instance with given 'LessThan' binary predicate comparators.
  /*!
      \param a_rInstance - Reference to another instance of the tied CComparablePair class.
      \param a_fFirstLessThan - 'LessThan' binary predicate comparator for the first type.
      \param a_fSecondLessThan - 'LessThan' binary predicate comparator for the second type.
      \return CComparablePair class instance with tied references.
  */
  template <typename T_FirstType, typename T_SecondType, typename T_FirstLessThanBinaryPredicate, typename T_SecondLessThanBinaryPredicate, typename T_OtherFirstLessThanBinaryPredicate, typename T_OtherSecondLessThanBinaryPredicate>
  static CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate> tie(CComparablePair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType>, T_FirstLessThanBinaryPredicate, T_SecondLessThanBinaryPredicate>& a_rInstance, T_OtherFirstLessThanBinaryPredicate a_fFirstLessThan, T_OtherSecondLessThanBinaryPredicate a_fSecondLessThan);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/CComparablePairTier.inl>
/*==========================================================================*/
#endif
