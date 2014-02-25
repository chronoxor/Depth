/*!
 *  \file    IIteratorMoveAssociative.inl Base interface for all iterators
 *           that can do associative iteration movement.
 *  \brief   Base associative iterator movement interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base associative iterator movement interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   29.07.2006 00:04:27

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
#ifndef __IITERATORMOVEASSOCIATIVE_INL__
#define __IITERATORMOVEASSOCIATIVE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_Iterator, typename T_Key, typename T_Value, typename T_Type, typename T_Return, class T_Container>
inline IIteratorMoveAssociative<T_Iterator, T_Key, T_Value, T_Type, T_Return, T_Container>::IIteratorMoveAssociative()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_Key, typename T_Value, typename T_Type, typename T_Return, class T_Container>
inline IIteratorMoveAssociative<T_Iterator, T_Key, T_Value, T_Type, T_Return, T_Container>::~IIteratorMoveAssociative()
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
