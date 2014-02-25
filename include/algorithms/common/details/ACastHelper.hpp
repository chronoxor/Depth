/*!
 *  \file    ACastHelper.hpp Contains template implementations of the cast
 *           algorithms.
 *  \brief   Cast algorithms helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Cast algorithms helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms details
    VERSION:   1.0
    CREATED:   08.05.2006 22:32:42

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
#ifndef __ACASTHELPER_HPP__
#define __ACASTHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
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
//! Polymorphic cast algorithm helper class.
/*!
    Polymorphic cast algorithms helper  class  uses  class  specialization  to
    choose appropriate casting.
*/
template <typename T_DestinationType, typename T_SourceType, Tbool t_IsPolymorphic>
class APolymorphicCastHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Algorithm method: Polymorphic cast.
  /*!
      This algorithm casting pointer  from  source  type  to  destination.  If
      casting fails  than  return  value  is  NULL.  If  source  type  is  not
      polymorphic than code will not compile and you dive compilation error.

      \param a_pX - Pointer to the source casting value.
      \return Pointer to the destination casting value.
  */
  static T_DestinationType cast(T_SourceType* a_pX);
};
/*--------------------------------------------------------------------------*/
//! Polymorphic cast algorithm helper class (non polymorphic cast specialization).
/*!
    Polymorphic cast algorithms helper  class  uses  class  specialization  to
    choose appropriate casting.
*/
template <typename T_DestinationType, typename T_SourceType>
class APolymorphicCastHelper<T_DestinationType, T_SourceType, false> :
  public NDepth::NCommon::IStatic
{
public:
  //! Algorithm method: Non polymorphic cast.
  /*!
      This algorithm casting pointer  from  source  type  to  destination.  If
      casting fails  than  return  value  is  NULL.  If  source  type  is  not
      polymorphic than code will successfully compile.

      \param a_pX - Pointer to the source casting value.
      \return Pointer to the destination casting value.
  */
  static T_DestinationType cast(T_SourceType* a_pX);
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
#include <Depth/include/algorithms/common/details/ACastHelper.inl>
/*==========================================================================*/
#endif
