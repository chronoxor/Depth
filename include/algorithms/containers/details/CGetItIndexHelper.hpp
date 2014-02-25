/*!
 *  \file    CGetItIndexHelper.hpp Contains template implementations of the
 *           get indexed container's iterator algorithm for different types
 *           of containers.
 *  \brief   Get indexed container's iterator algorithm helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Get indexed container's iterator algorithm helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms details
    VERSION:   1.0
    CREATED:   28.03.2007 01:48:22

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
#ifndef __CGETITINDEXHELPER_HPP__
#define __CGETITINDEXHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/concept/containers/MConceptRandomConst.hpp>
#include <Depth/include/traits/MTraitsContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Get indexed container's iterator algorithm helper class.
/*!
    Get  indexed  container's  iterator  algorithm  helper  class  uses  class
    specialization to implement various  kinds  of  algorithms  for  different
    container types.
*/
template <Tuint t_Algorithm>
class CGetItIndexHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Algorithm: Get indexed container's iterator.
  /*!
      This method has different specifications.

      1'st specification (t_Algorithm == 1) is used for all
      random accessible containers.

      Other specification are used for all other kinds of containers.

      \param a_rContainer - Reference to the container.
      \param a_cIndex - Indexed position to return.
      \return Iterator to the indexed container's value, or invalid iterator.
  */
  template <class T_Container>
  static typename NTraits::MTraitsContainer<T_Container>::iterator getItIndex(T_Container& a_rContainer, const Tuint a_cIndex);
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
#include <Depth/include/algorithms/containers/details/CGetItIndexHelper.inl>
/*==========================================================================*/
#endif
