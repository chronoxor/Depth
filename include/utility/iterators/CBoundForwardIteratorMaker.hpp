/*!
 *  \file    CBoundForwardIteratorMaker.hpp Utility class that helps to create
 *           CBoundForwardIterator instances from specific values.
 *  \brief   Bound forward iterator wrapper maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bound forward iterator wrapper maker class.

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
#ifndef __CBOUNDFORWARDITERATORMAKER_HPP__
#define __CBOUNDFORWARDITERATORMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/utility/iterators/CBoundForwardIterator.hpp>
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
//! Bound forward iterator wrapper maker class.
/*!
    With this utility class template CBoundForwardIterator  instances  can  be
    created without specifying template arguments.
*/
class BASE_API CBoundForwardIteratorMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CBoundForwardIterator instance from specified current forward iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current forward iterator instance.
      \return CBoundForwardIterator class instance.
  */
  template <class T_ForwardIterator>
  static CBoundForwardIterator<T_ForwardIterator> make(const T_ForwardIterator& a_crCurrentIterator);
  //! Make CBoundForwardIterator instance from specified current forward iterator and the end bound iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current forward iterator instance.
      \param a_crEndBoundIterator - Constant reference to the end bound forward iterator instance.
      \return CBoundForwardIterator class instance.
  */
  template <class T_ForwardIterator>
  static CBoundForwardIterator<T_ForwardIterator> make(const T_ForwardIterator& a_crCurrentIterator, const T_ForwardIterator& a_crEndBoundIterator);

  //! Make CBoundForwardIterator instance from specified CBoundForwardIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoundForwardIterator class.
      \return CBoundForwardIterator class instance.
  */
  template <class T_ForwardIterator>
  static CBoundForwardIterator<T_ForwardIterator> make(const CBoundForwardIterator<T_ForwardIterator>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/iterators/CBoundForwardIteratorMaker.inl>
/*==========================================================================*/
#endif
