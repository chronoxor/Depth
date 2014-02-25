/*!
 *  \file    CLimitForwardIteratorMaker.hpp Utility class that helps to create
 *           CLimitForwardIterator instances from specific values.
 *  \brief   Limit forward iterator wrapper maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Limit forward iterator wrapper maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   03.04.2007 22:19:23

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
#ifndef __CLIMITFORWARDITERATORMAKER_HPP__
#define __CLIMITFORWARDITERATORMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/utility/iterators/CLimitForwardIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Limit forward iterator wrapper maker class.
/*!
    With this utility class template CLimitForwardIterator  instances  can  be
    created without specifying template arguments.
*/
class BASE_API CLimitForwardIteratorMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CLimitForwardIterator instance from specified current forward iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current forward iterator instance.
      \return CLimitForwardIterator class instance.
  */
  template <class T_ForwardIterator>
  static CLimitForwardIterator<T_ForwardIterator> make(const T_ForwardIterator& a_crCurrentIterator);
  //! Make CLimitForwardIterator instance from specified current forward iterator and the end limit value.
  /*!
      \param a_crCurrentIterator - Constant reference to the current forward iterator instance.
      \param a_cEndLimit - End limit value.
      \return CLimitForwardIterator class instance.
  */
  template <class T_ForwardIterator>
  static CLimitForwardIterator<T_ForwardIterator> make(const T_ForwardIterator& a_crCurrentIterator, const Tuint a_cEndLimit);

  //! Make CLimitForwardIterator instance from specified CLimitForwardIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CLimitForwardIterator class.
      \return CLimitForwardIterator class instance.
  */
  template <class T_ForwardIterator>
  static CLimitForwardIterator<T_ForwardIterator> make(const CLimitForwardIterator<T_ForwardIterator>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/iterators/CLimitForwardIteratorMaker.inl>
/*==========================================================================*/
#endif
