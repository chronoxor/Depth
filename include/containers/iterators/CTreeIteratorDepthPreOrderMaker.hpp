/*!
 *  \file    CTreeIteratorDepthPreOrderMaker.hpp Utility class that helps
 *           to create CTreeIteratorDepthPreOrder instances from specific
 *           values.
 *  \brief   Tree depth pre-order iterator maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree depth pre-order iterator maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   14.07.2006 23:24:17

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
#ifndef __CTREEITERATORDEPTHPREORDERMAKER_HPP__
#define __CTREEITERATORDEPTHPREORDERMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/containers/iterators/CTreeIteratorDepthPreOrder.hpp>
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
//! Tree depth pre-order iterator maker class.
/*!
    With this utility class template CTreeIteratorDepthPreOrder instances  can
    be created without specifying template arguments.
*/
class BASE_API CTreeIteratorDepthPreOrderMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CTreeIteratorDepthPreOrder instance from specified tree iterator.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator class.
      \return CTreeIteratorDepthPreOrder class instance.
  */
  template <class T_TreeIterator>
  static CTreeIteratorDepthPreOrder<T_TreeIterator> make(const T_TreeIterator& a_crTreeIterator);

  //! Make CTreeIteratorDepthPreOrder instance from specified CTreeIteratorDepthPreOrder class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorDepthPreOrder class.
      \return CTreeIteratorDepthPreOrder class instance.
  */
  template <class T_TreeIterator>
  static CTreeIteratorDepthPreOrder<T_TreeIterator> make(const CTreeIteratorDepthPreOrder<T_TreeIterator>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CTreeIteratorDepthPreOrderMaker.inl>
/*==========================================================================*/
#endif
