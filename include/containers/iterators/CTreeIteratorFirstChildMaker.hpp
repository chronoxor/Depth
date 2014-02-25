/*!
 *  \file    CTreeIteratorFirstChildMaker.hpp Utility class that helps to
 *           create CTreeIteratorFirstChild instances from specific values.
 *  \brief   Tree first child iterator maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree first child iterator maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   11.07.2006 21:25:16

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
#ifndef __CTREEITERATORFIRSTCHILDMAKER_HPP__
#define __CTREEITERATORFIRSTCHILDMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/containers/iterators/CTreeIteratorFirstChild.hpp>
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
//! Tree first child iterator maker class.
/*!
    With this utility class template CTreeIteratorFirstChild instances can  be
    created without specifying template arguments.
*/
class BASE_API CTreeIteratorFirstChildMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CTreeIteratorFirstChild instance from specified tree iterator.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator class.
      \return CTreeIteratorFirstChild class instance.
  */
  template <class T_TreeIterator>
  static CTreeIteratorFirstChild<T_TreeIterator> make(const T_TreeIterator& a_crTreeIterator);

  //! Make CTreeIteratorFirstChild instance from specified CTreeIteratorFirstChild class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorFirstChild class.
      \return CTreeIteratorFirstChild class instance.
  */
  template <class T_TreeIterator>
  static CTreeIteratorFirstChild<T_TreeIterator> make(const CTreeIteratorFirstChild<T_TreeIterator>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CTreeIteratorFirstChildMaker.inl>
/*==========================================================================*/
#endif
