/*!
 *  \file    ACastHelper.inl Contains template implementations of the cast
 *           algorithms.
 *  \brief   Cast algorithms helper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Cast algorithms helper class (inline).

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
#ifndef __ACASTHELPER_INL__
#define __ACASTHELPER_INL__
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
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_DestinationType, typename T_SourceType, Tbool t_IsPolymorphic>
inline T_DestinationType APolymorphicCastHelper<T_DestinationType, T_SourceType, t_IsPolymorphic>::cast(T_SourceType* a_pX)
{ CALL
  return dynamic_cast<T_DestinationType>(a_pX);
}
/*--------------------------------------------------------------------------*/
template <typename T_DestinationType, typename T_SourceType>
inline T_DestinationType APolymorphicCastHelper<T_DestinationType, T_SourceType, false>::cast(T_SourceType* a_pX)
{ CALL
  IGNORE_UNUSED(a_pX);

  return NULL;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
