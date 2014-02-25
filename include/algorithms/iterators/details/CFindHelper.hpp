/*!
 *  \file    CFindHelper.hpp Contains template implementations of the find
 *           algorithm for different types of iterators.
 *  \brief   Find algorithm helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find algorithm helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   13.09.2006 22:22:52

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
#ifndef __CFINDHELPER_HPP__
#define __CFINDHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyRandom.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Find algorithm helper class.
/*!
    Find algorithm helper class uses class specialization to implement various
    kinds of find algorithms.
*/
template <Tuint t_Algorithm>
class CFindHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Algorithm: Forward searching for the first iterator with given value.
  /*!
      Method searches forward for the first  iterator  with  given  value.  It
      implements searching in container which represented with  given  forward
      iterator. Method stops  searching  process  when  iterator  cannot  step
      forward anymore, or if iteration cycle restarts (for cycled containers).

      This method has different specifications.

      1'st specification (t_Algorithm == 1) is used for all
      random accessible iterators.

      Other specification are used for all other kinds of iterators.

      \param a_crIterator - Constant reference to the container's forward iterator.
      \param a_crValue - Constant reference to the searching value.
      \param a_fEqual - 'Equal' binary predicate.
      \return Forward iterator to found value, or invalid iterator.
  */
  template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
  static T_Iterator findNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/details/CFindHelper.inl>
/*==========================================================================*/
#endif
