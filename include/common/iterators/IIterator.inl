/*!
 *  \file    IIterator.inl Base interface for all non constant iterators. It
 *           gives ability to check for valid state and get container values.
 *  \brief   Base non constant iterator interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base non constant iterator interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common iterators
    VERSION:   1.0
    CREATED:   20.01.2006 20:34:13

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
#ifndef __IITERATOR_INL__
#define __IITERATOR_INL__
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
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
inline IIterator<T_Iterator, T_Type, T_Return, T_Container>::IIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
inline IIterator<T_Iterator, T_Type, T_Return, T_Container>::~IIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
inline typename IIterator<T_Iterator, T_Type, T_Return, T_Container>::TReturn& IIterator<T_Iterator, T_Type, T_Return, T_Container>::operator* () const
{ CALL
  return getValueRef();
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_Type, typename T_Return, class T_Container>
inline typename IIterator<T_Iterator, T_Type, T_Return, T_Container>::TReturn* IIterator<T_Iterator, T_Type, T_Return, T_Container>::operator-> () const
{ CALL
  return getValuePtr();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
