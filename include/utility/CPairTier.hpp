/*!
 *  \file    CPairTier.hpp Utility class that helps to tie CPair instances
 *           with specified references to values.
 *  \brief   Pair tier class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Pair tier class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   05.03.2006 22:16:28

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
#ifndef __CPAIRTIER_HPP__
#define __CPAIRTIER_HPP__
/*==========================================================================*/
#include <Depth/include/base/CReference.hpp>
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/utility/CPair.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Pair tier class.
/*!
    With this utility class template CPair instances can be  tied  with  given
    references to values.
*/
class BASE_API CPairTier :
  public NDepth::NCommon::IStatic
{
public:
  //! Tie CPair instance with given references to values.
  /*!
      \param a_rFirstValue - Reference to the first pair value.
      \param a_rSecondValue - Reference to the second pair value.
      \return CPair class instance with tied references.
  */
  template <typename T_FirstType, typename T_SecondType>
  static CPair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> > tie(T_FirstType& a_rFirstValue, T_SecondType& a_rSecondValue);
  //! Tie CPair instance with specified CPair class instance.
  /*!
      \param a_rInstance - Reference to another instance of the CPair class.
      \return CPair class instance with tied references.
  */
  template <typename T_FirstType, typename T_SecondType>
  static CPair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> > tie(CPair<T_FirstType, T_SecondType>& a_rInstance);
  //! Tie CPair instance with another tied CPair class instance.
  /*!
      \param a_rInstance - Reference to another instance of the tied CPair class.
      \return CPair class instance with tied references.
  */
  template <typename T_FirstType, typename T_SecondType>
  static CPair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> > tie(CPair<NBase::CReference<T_FirstType>, NBase::CReference<T_SecondType> >& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/CPairTier.inl>
/*==========================================================================*/
#endif
