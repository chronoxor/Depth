/*!
 *  \file    CStringSearchHelper.hpp Helper class for (sub)string searching
 *           algorithms.
 *  \brief   Helper class for (sub)string searching algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Helper class for (sub)string searching algorithms.

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
#ifndef __CSTRINGSEARCHHELPER_HPP__
#define __CSTRINGSEARCHHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/AStringLength.hpp>
#include <Depth/include/concept/base/MConceptStringConst.hpp>
#include <Depth/include/concept/types/MConceptIString.hpp>
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
//! Helper class for (sub)string searching algorithms.
/*!
    Helper class for (sub)string searching algorithms is  intended  to  choose
    right specialization and functionality based on string  type:  'C'  string
    buffer or string class.
*/
class BASE_API CStringSearchHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Copy string pattern into the given destination string.
  /*!
      \param a_rDestination - Reference to the destination string.
      \param a_crPattern - Constant reference to the pattern string.
      \param a_cPatternIndex - Index in pattern string.
      \param a_cPatternLength - Maximal pattern string length starting from offset.
      \return true  - if the string pattern was successfully copied. \n
              false - if the string pattern was not successfully copied. \n
  */
  template <class T_StringClass, typename T_StringType>
  static Tbool copyPattern(T_StringClass& a_rDestination, const T_StringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength);
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
#include <Depth/include/algorithms/string/details/CStringSearchHelper.inl>
/*==========================================================================*/
#endif
