/*!
 *  \file    ACast.inl Contains general template implementation of the cast
 *           algorithms.
 *  \brief   Cast algorithms (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Cast algorithms (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   08.05.2006 21:56:53

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
#ifndef __ACAST_INL__
#define __ACAST_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType constCast(T_SourceType a_X)
{ CALL
  return const_cast<T_DestinationType>(a_X);
}
/*--------------------------------------------------------------------------*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType dynamicCast(T_SourceType a_X)
{ CALL
  return dynamic_cast<T_DestinationType>(a_X);
}
/*--------------------------------------------------------------------------*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType reinterpretCast(T_SourceType a_X)
{ CALL
  return reinterpret_cast<T_DestinationType>(a_X);
}
/*--------------------------------------------------------------------------*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType staticCast(T_SourceType a_X)
{ CALL
  return static_cast<T_DestinationType>(a_X);
}
/*--------------------------------------------------------------------------*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType polymorphicCast(T_SourceType* a_pX)
{ CALL
  return dynamic_cast<T_DestinationType>(a_pX);
}
/*--------------------------------------------------------------------------*/
template <typename T_DestinationType, typename T_SourceType>
T_DestinationType nonPolymorphicCast(T_SourceType* a_pX)
{ CALL
  return NDetails::APolymorphicCastHelper<T_DestinationType, T_SourceType, NTraits::MIsPolymorphic<T_SourceType>::yes>::cast(a_pX);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
