/*!
 *  \file    CFillNHelper.hpp Contains template implementations of the
 *           iterator fill N items algorithm for different types of iterators.
 *  \brief   Iterator fill N items algorithm helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator fill N items algorithm helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   22.05.2007 23:44:23

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
#ifndef __CFILLNHELPER_HPP__
#define __CFILLNHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/concept/common/MConceptConvert.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorInsertForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorInsertBackward.hpp>
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
//! Iterator fill N items algorithm helper class.
/*!
    Iterator fill N items algorithm helper class uses class specialization  to
    implement various kinds of iterator fill N items algorithms.
*/
template <Tuint t_Algorithm>
class CFillNHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Algorithm: Fill N forward iterator items with the given value.
  /*!
      Method fills N items from the current forward iterator. If container has
      less items than N, new items will be created if possible.

      This method has different specifications.

      1'st specification (t_Algorithm == 1) is used for all
      insert forward iterators.

      Other specification are used for all forward iterators.

      \param a_crIterator - Constant reference to the forward iterator.
      \param a_cN - Count of requested items to fill.
      \param a_crValue - Constant reference to the filled value.
      \return Count of filled items.
  */
  template <class T_Iterator, typename T_ValueType>
  static Tuint fillNNext(const T_Iterator& a_crIterator, const Tuint a_cN, const T_ValueType& a_crValue);

  //! Algorithm: Fill N backward iterator items with the given value.
  /*!
      Method fills N items from the current backward  iterator.  If  container
      has less items than N, new items will be created if possible.

      This method has different specifications.

      1'st specification (t_Algorithm == 1) is used for all
      insert backward iterators.

      Other specification are used for all backward iterators.

      \param a_crIterator - Constant reference to the backward iterator.
      \param a_cN - Count of requested items to fill.
      \param a_crValue - Constant reference to the filled value.
      \return Count of filled items.
  */
  template <class T_Iterator, typename T_ValueType>
  static Tuint fillNPrev(const T_Iterator& a_crIterator, const Tuint a_cN, const T_ValueType& a_crValue);
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
#include <Depth/include/algorithms/iterators/details/CFillNHelper.inl>
/*==========================================================================*/
#endif
