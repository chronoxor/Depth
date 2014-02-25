/*!
 *  \file    CTreeIteratorBreadthNextMaker.hpp Utility class that helps to
 *           create CTreeIteratorBreadthNext instances from specific values.
 *  \brief   Tree breadth next iterator maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree breadth next iterator maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   12.07.2006 22:04:26

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
#ifndef __CTREEITERATORBREADTHNEXTMAKER_HPP__
#define __CTREEITERATORBREADTHNEXTMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/containers/iterators/CTreeIteratorBreadthNext.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Tree breadth next iterator maker class.
/*!
    With this utility class template CTreeIteratorBreadthNext instances can be
    created without specifying template arguments.
*/
class BASE_API CTreeIteratorBreadthNextMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CTreeIteratorBreadthNext instance from specified tree iterator.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator class.
      \return CTreeIteratorBreadthNext class instance.
  */
  template <class T_TreeIterator>
  static CTreeIteratorBreadthNext<T_TreeIterator> make(const T_TreeIterator& a_crTreeIterator);
  //! Make CTreeIteratorBreadthNext instance from specified tree iterator and given memory allocator.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator class.
      \param a_crAllocator - Constant reference to the memory allocator.
      \return CTreeIteratorBreadthNext class instance.
  */
  template <class T_TreeIterator, class T_Allocator>
  static CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> make(const T_TreeIterator& a_crTreeIterator, const T_Allocator& a_crAllocator);

  //! Make CTreeIteratorBreadthNext instance from specified CTreeIteratorBreadthNext class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorBreadthNext class.
      \return CTreeIteratorBreadthNext class instance.
  */
  template <class T_TreeIterator, class T_Allocator>
  static CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> make(const CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& a_crInstance);
  //! Make CTreeIteratorBreadthNext instance from specified CTreeIteratorBreadthNext class instance and given memory allocator.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorBreadthNext class.
      \param a_crAllocator - Constant reference to the memory allocator.
      \return CTreeIteratorBreadthNext class instance.
  */
  template <class T_TreeIterator, class T_Allocator, class T_OtherAllocator>
  static CTreeIteratorBreadthNext<T_TreeIterator, T_OtherAllocator> make(const CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& a_crInstance, const T_OtherAllocator& a_crAllocator);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CTreeIteratorBreadthNextMaker.inl>
/*==========================================================================*/
#endif
