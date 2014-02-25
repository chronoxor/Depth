/*!
 *  \file    CTreeIteratorIndexedChildMaker.hpp Utility class that helps to
 *           create CTreeIteratorIndexedChild instances from specific values.
 *  \brief   Tree indexed child iterator maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree indexed child iterator maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   11.07.2006 21:51:37

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
#ifndef __CTREEITERATORINDEXEDCHILDMAKER_HPP__
#define __CTREEITERATORINDEXEDCHILDMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/containers/iterators/CTreeIteratorIndexedChild.hpp>
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
//! Tree indexed child iterator maker class.
/*!
    With this utility class template CTreeIteratorIndexedChild  instances  can
    be created without specifying template arguments.
*/
class BASE_API CTreeIteratorIndexedChildMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CTreeIteratorIndexedChild instance from specified tree iterator.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator class.
      \param a_cIndex - Index for child iterations (default is 0).
      \return CTreeIteratorIndexedChild class instance.
  */
  template <class T_TreeIterator>
  static CTreeIteratorIndexedChild<T_TreeIterator> make(const T_TreeIterator& a_crTreeIterator, const Tuint a_cIndex = 0);

  //! Make CTreeIteratorIndexedChild instance from specified CTreeIteratorIndexedChild class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorIndexedChild class.
      \return CTreeIteratorIndexedChild class instance.
  */
  template <class T_TreeIterator>
  static CTreeIteratorIndexedChild<T_TreeIterator> make(const CTreeIteratorIndexedChild<T_TreeIterator>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CTreeIteratorIndexedChildMaker.inl>
/*==========================================================================*/
#endif
