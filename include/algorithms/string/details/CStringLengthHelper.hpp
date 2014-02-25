/*!
 *  \file    CStringLengthHelper.hpp Helper class for getting string length
 *           based on its type.
 *  \brief   Helper class for string length algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Helper class for string length algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms details
    VERSION:   1.0
    CREATED:   26.11.2009 02:08:02

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
#ifndef __CSTRINGLENGTHHELPER_HPP__
#define __CSTRINGLENGTHHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/algorithms/string/buffer/AStrLen.hpp>
#include <Depth/include/concept/base/MConceptStringConst.hpp>
#include <Depth/include/concept/types/MConceptIStringConst.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Helper class for string length algorithm.
/*!
    Helper class for string length algorithm is intended to get string  length
    by choosing the right specialization and  functionality  based  on  string
    type: 'C' string buffer or string class.
*/
template <Tbool t_IsStringClass>
class CStringLengthHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Get string length based on string type: 'C' string buffer or string class.
  /*!
      \param a_crString - Constant reference to the given string.
      \param a_cStringIndex - String index offset value.
      \param a_cStringLength - Maximal string length value starting from offset.
      \return Length of the given string in characters starting from offset.
  */
  template <typename T_StringType>
  static Tuint stringLength(const T_StringType& a_crString, const Tuint a_cStringIndex, const Tuint a_cStringLength);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/details/CStringLengthHelper.inl>
/*==========================================================================*/
#endif
