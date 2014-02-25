/*!
 *  \file    CStringBufferHelper.hpp Helper class for manipulations with a
 *           string buffer.
 *  \brief   Helper class for manipulations with a string buffer.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.05.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Helper class for manipulations with a string buffer.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers details
    VERSION:   1.0
    CREATED:   18.05.2010 19:51:36

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
#ifndef __CSTRINGBUFFERHELPER_HPP__
#define __CSTRINGBUFFERHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/buffer/AStrCpy.hpp>
#include <Depth/include/algorithms/string/buffer/AStrLen.hpp>
#include <Depth/include/concept/base/MConceptStringConst.hpp>
#include <Depth/include/concept/types/MConceptIStringConst.hpp>
#include <Depth/include/traits/MAddPointer.hpp>
#include <Depth/include/traits/MRemovePointer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Helper class for manipulations with a string buffer.
/*!
    Helper class for manipulations with a string buffer is  intended  to  work
    with  a  string  buffer  by  choosing   the   right   specialization   and
    functionality based on string type: 'C' string buffer or string class.
*/
template <Tbool t_IsStringClass>
class CStringBufferHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Copy one string to another.
  /*!
      \param a_rpDestination - Reference to the pointer to the destination string.
      \param a_crSource - Constant reference to the source string.
      \param a_rAllocator - Reference to the memory allocator.
      \return true  - if copy operation successfully finished. \n
              false - if copy operation failed. \n
  */
  template <typename T_StringType, class T_Allocator>
  static Tbool copy(typename NTraits::MAddPointer<T_StringType>::type& a_rpDestination, const T_StringType& a_crSource, T_Allocator& a_rAllocator);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/details/CStringBufferHelper.inl>
/*==========================================================================*/
#endif
