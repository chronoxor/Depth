/*!
 *  \file    CReverseRandomIteratorMaker.hpp Utility class that helps to
 *           create CReverseRandomIterator instances from specific values.
 *  \brief   Reverse random access iterator wrapper maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reverse random access iterator wrapper maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   16.04.2007 02:47:00

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
#ifndef __CREVERSERANDOMITERATORMAKER_HPP__
#define __CREVERSERANDOMITERATORMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/utility/iterators/CReverseRandomIterator.hpp>
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
//! Reverse iterator wrapper maker class.
/*!
    With this utility class template CReverseRandomIterator instances  can  be
    created without specifying template arguments.
*/
class BASE_API CReverseRandomIteratorMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CReverseRandomIterator instance from specified random access iterator.
  /*!
      \param a_crRandomIterator - Constant reference to the random access iterator class.
      \return CReverseRandomIterator class instance.
  */
  template <class T_RandomIterator>
  static CReverseRandomIterator<T_RandomIterator> make(const T_RandomIterator& a_crRandomIterator);

  //! Make CReverseRandomIterator instance from specified CReverseRandomIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CReverseRandomIterator class.
      \return CReverseRandomIterator class instance.
  */
  template <class T_RandomIterator>
  static CReverseRandomIterator<T_RandomIterator> make(const CReverseRandomIterator<T_RandomIterator>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/iterators/CReverseRandomIteratorMaker.inl>
/*==========================================================================*/
#endif
