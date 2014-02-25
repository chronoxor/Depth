/*!
 *  \file    CLimitRandomIteratorMaker.hpp Utility class that helps to
 *           create CLimitRandomIterator instances from specific values.
 *  \brief   Limit random iterator wrapper maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Limit random iterator wrapper maker class.

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
#ifndef __CLIMITRANDOMITERATORMAKER_HPP__
#define __CLIMITRANDOMITERATORMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/utility/iterators/CLimitRandomIterator.hpp>
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
//! Limit random iterator wrapper maker class.
/*!
    With this utility class template  CLimitRandomIterator  instances  can  be
    created without specifying template arguments.
*/
class BASE_API CLimitRandomIteratorMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CLimitRandomIterator instance from specified current random iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current random iterator instance.
      \return CLimitRandomIterator class instance.
  */
  template <class T_RandomIterator>
  static CLimitRandomIterator<T_RandomIterator> make(const T_RandomIterator& a_crCurrentIterator);
  //! Make CLimitRandomIterator instance from specified current random iterator and the end limit value.
  /*!
      \param a_crCurrentIterator - Constant reference to the current random iterator instance.
      \param a_cEndLimit - End limit value.
      \return CLimitRandomIterator class instance.
  */
  template <class T_RandomIterator>
  static CLimitRandomIterator<T_RandomIterator> make(const T_RandomIterator& a_crCurrentIterator, const Tuint a_cEndLimit);
  //! Make CLimitRandomIterator instance from specified current random iterator, the start limit and the end limit values.
  /*!
      \param a_crCurrentIterator - Constant reference to the current random iterator instance.
      \param a_cStartLimit - Start limit value.
      \param a_cEndLimit - End limit value.
      \return CLimitRandomIterator class instance.
  */
  template <class T_RandomIterator>
  static CLimitRandomIterator<T_RandomIterator> make(const T_RandomIterator& a_crCurrentIterator, const Tuint a_cStartLimit, const Tuint a_cEndLimit);

  //! Make CLimitRandomIterator instance from specified CLimitRandomIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CLimitRandomIterator class.
      \return CLimitRandomIterator class instance.
  */
  template <class T_RandomIterator>
  static CLimitRandomIterator<T_RandomIterator> make(const CLimitRandomIterator<T_RandomIterator>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/iterators/CLimitRandomIteratorMaker.inl>
/*==========================================================================*/
#endif
