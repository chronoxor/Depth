/*!
 *  \file    CReverseRandomIteratorMaker.inl Utility class that helps to
 *           create CReverseRandomIterator instances from specific values.
 *  \brief   Reverse random access iterator wrapper maker class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reverse random access iterator wrapper maker class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   16.04.2007 02:47:00

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
#ifndef __CREVERSERANDOMITERATORMAKER_INL__
#define __CREVERSERANDOMITERATORMAKER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator> CReverseRandomIteratorMaker::make(const T_RandomIterator& a_crRandomIterator)
{ CALL
  return CReverseRandomIterator<T_RandomIterator>(a_crRandomIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator> CReverseRandomIteratorMaker::make(const CReverseRandomIterator<T_RandomIterator>& a_crInstance)
{ CALL
  return CReverseRandomIterator<T_RandomIterator>(a_crInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
