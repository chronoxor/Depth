/*!
 *  \file    CBoundRandomIteratorMaker.hpp Utility class that helps to
 *           create CBoundRandomIterator instances from specific values.
 *  \brief   Bound random iterator wrapper maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bound random iterator wrapper maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   04.04.2007 02:29:52

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
#ifndef __CBOUNDRANDOMITERATORMAKER_HPP__
#define __CBOUNDRANDOMITERATORMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/utility/iterators/CBoundRandomIterator.hpp>
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
//! Bound random iterator wrapper maker class.
/*!
    With this utility class template  CBoundRandomIterator  instances  can  be
    created without specifying template arguments.
*/
class BASE_API CBoundRandomIteratorMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CBoundRandomIterator instance from specified current random iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current random iterator instance.
      \return CBoundRandomIterator class instance.
  */
  template <class T_RandomIterator>
  static CBoundRandomIterator<T_RandomIterator> make(const T_RandomIterator& a_crCurrentIterator);
  //! Make CBoundRandomIterator instance from specified current random iterator and the end bound iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current random iterator instance.
      \param a_crEndBoundIterator - Constant reference to the end bound random iterator instance.
      \return CBoundRandomIterator class instance.
  */
  template <class T_RandomIterator>
  static CBoundRandomIterator<T_RandomIterator> make(const T_RandomIterator& a_crCurrentIterator, const T_RandomIterator& a_crEndBoundIterator);
  //! Make CBoundRandomIterator instance from specified current random iterator, the start bound iterator and the end bound iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current random iterator instance.
      \param a_crStartBoundIterator - Constant reference to the start bound random iterator instance.
      \param a_crEndBoundIterator - Constant reference to the end bound random iterator instance.
      \return CBoundRandomIterator class instance.
  */
  template <class T_RandomIterator>
  static CBoundRandomIterator<T_RandomIterator> make(const T_RandomIterator& a_crCurrentIterator, const T_RandomIterator& a_crStartBoundIterator, const T_RandomIterator& a_crEndBoundIterator);

  //! Make CBoundRandomIterator instance from specified CBoundRandomIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoundRandomIterator class.
      \return CBoundRandomIterator class instance.
  */
  template <class T_RandomIterator>
  static CBoundRandomIterator<T_RandomIterator> make(const CBoundRandomIterator<T_RandomIterator>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/iterators/CBoundRandomIteratorMaker.inl>
/*==========================================================================*/
#endif
