/*!
 *  \file    CGenerateNHelper.hpp Contains template implementations of the
 *           iterator generate N items algorithm for different types of
 *           iterators.
 *  \brief   Iterator generate N items algorithm helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator generate N items algorithm helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms details
    VERSION:   1.0
    CREATED:   23.05.2007 22:20:03

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
#ifndef __CGENERATENHELPER_HPP__
#define __CGENERATENHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/concept/functions/MConceptFunction0.hpp>
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
//! Iterator generate N items algorithm helper class.
/*!
    Iterator  generates  N   items   algorithm   helper   class   uses   class
    specialization to implement various kinds of  iterator  generate  N  items
    algorithms.
*/
template <Tuint t_Algorithm>
class CGenerateNHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Algorithm: Generate N forward iterator items using the given generator.
  /*!
      Method generates N items from the current forward iterator. If container
      has less items than N, new items will be created if possible.

      This method has different specifications.

      1'st specification (t_Algorithm == 1) is used for all
      insert forward iterators.

      Other specification are used for all forward iterators.

      \param a_crIterator - Constant reference to the forward iterator.
      \param a_cN - Count of requested items to fill.
      \param a_fGenerator - Generator function.
      \return Count of generated items.
  */
  template <class T_Iterator, typename T_Generator>
  static Tuint generateNNext(const T_Iterator& a_crIterator, const Tuint a_cN, T_Generator a_fGenerator);

  //! Algorithm: Generate N backward iterator items using the given generator.
  /*!
      Method  generates  N  items  from  the  current  backward  iterator.  If
      container has less items than N, new items will be created if possible.

      This method has different specifications.

      1'st specification (t_Algorithm == 1) is used for all
      insert backward iterators.

      Other specification are used for all backward iterators.

      \param a_crIterator - Constant reference to the backward iterator.
      \param a_cN - Count of requested items to fill.
      \param a_fGenerator - Generator function.
      \return Count of generated items.
  */
  template <class T_Iterator, typename T_Generator>
  static Tuint generateNPrev(const T_Iterator& a_crIterator, const Tuint a_cN, T_Generator a_fGenerator);
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
#include <Depth/include/algorithms/iterators/details/CGenerateNHelper.inl>
/*==========================================================================*/
#endif
