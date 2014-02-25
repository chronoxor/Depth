/*!
 *  \file    CTreeIteratorSiblingsMaker.hpp Utility class that helps to
 *           create CTreeIteratorSiblings instances from specific values.
 *  \brief   Tree siblings iterator maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree siblings iterator maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   11.07.2006 23:45:14

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
#ifndef __CTREEITERATORSIBLINGSMAKER_HPP__
#define __CTREEITERATORSIBLINGSMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/containers/iterators/CTreeIteratorSiblings.hpp>
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
//! Tree siblings iterator maker class.
/*!
    With this utility class template CTreeIteratorSiblings  instances  can  be
    created without specifying template arguments.
*/
class BASE_API CTreeIteratorSiblingsMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CTreeIteratorSiblings instance from specified tree iterator.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator class.
      \return CTreeIteratorSiblings class instance.
  */
  template <class T_TreeIterator>
  static CTreeIteratorSiblings<T_TreeIterator> make(const T_TreeIterator& a_crTreeIterator);

  //! Make CTreeIteratorSiblings instance from specified CTreeIteratorSiblings class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorSiblings class.
      \return CTreeIteratorSiblings class instance.
  */
  template <class T_TreeIterator>
  static CTreeIteratorSiblings<T_TreeIterator> make(const CTreeIteratorSiblings<T_TreeIterator>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CTreeIteratorSiblingsMaker.inl>
/*==========================================================================*/
#endif
