/*!
 *  \file    ICombiner.inl Interface for all signal combiner classes. While
 *           creating a new signal combiner type, you should implement base
 *           ICombiner's methods.
 *  \brief   Signal combiner interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Signal combiner interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Signal containers
    VERSION:   1.0
    CREATED:   01.06.2006 20:13:31

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
#ifndef __ICOMBINER_INL__
#define __ICOMBINER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSignals {
/*--------------------------------------------------------------------------*/
namespace NCombiners {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_SlotReturn, typename T_SignalResult>
inline ICombiner<T_SlotReturn, T_SignalResult>::ICombiner()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SlotReturn, typename T_SignalResult>
inline ICombiner<T_SlotReturn, T_SignalResult>::~ICombiner()
{ CALL

}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
