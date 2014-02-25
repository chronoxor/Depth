/*!
 *  \file    ASwapHelper.hpp Contains template implementations of the swap
 *           algorithm for different data types.
 *  \brief   Swap algorithm helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Swap algorithm helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms details
    VERSION:   1.0
    CREATED:   15.04.2006 02:01:31

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
#ifndef __ASWAPHELPER_HPP__
#define __ASWAPHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/concept/class/MConceptAssignCopy.hpp>
#include <Depth/include/concept/class/MConceptSwappable.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Swap algorithm helper class.
/*!
    Swap algorithm helper class uses class specialization to implement various
    kinds of swap algorithms.
*/
template <Tuint t_Algorithm>
class ASwapHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Algorithm method: Swap two values.
  /*!
      This method has different specifications.

      1'st specification (t_Algorithm == 0) is used for all types that can
      be swapped.

      Other specification are used for all kinds of types.

      \param a_rFirst - Reference to the first value.
      \param a_rSecond - Reference to the second value.
  */
  template <typename T_Type>
  static void swap(T_Type& a_rFirst, T_Type& a_rSecond);
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
#include <Depth/include/algorithms/common/details/ASwapHelper.inl>
/*==========================================================================*/
#endif
