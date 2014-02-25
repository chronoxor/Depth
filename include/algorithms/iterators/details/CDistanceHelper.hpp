/*!
 *  \file    CDistanceHelper.hpp Contains template implementations of the
 *           iterator distance algorithm for different types of iterators.
 *  \brief   Iterator distance algorithm helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator distance algorithm helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   03.08.2006 02:43:27

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
#ifndef __CDISTANCEHELPER_HPP__
#define __CDISTANCEHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
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
//! Iterator distance algorithm helper class.
/*!
    Iterator distance algorithm helper  class  uses  class  specialization  to
    implement various kinds of iterator distance algorithms.
*/
template <Tuint t_Algorithm>
class CDistanceHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Algorithm: Find distance to the container's end.
  /*!
      Method finds distance from the current iterator to the container's end.

      This method has different specifications.

      1'st specification (t_Algorithm == 1) is used for all
      random accessible iterators.
      2'nd specification (t_Algorithm == 2) is used for all
      iterators with circled containers.

      Other specification are used for all other kinds of iterators.

      \param a_crIterator - Constant reference to the forward iterator.
      \return Distance from the iterator to the container's end.
  */
  template <class T_Iterator>
  static Tuint distanceNext(const T_Iterator& a_crIterator);
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
#include <Depth/include/algorithms/iterators/details/CDistanceHelper.inl>
/*==========================================================================*/
#endif
