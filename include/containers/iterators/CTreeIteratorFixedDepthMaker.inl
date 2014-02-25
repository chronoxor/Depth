/*!
 *  \file    CTreeIteratorFixedDepthMaker.inl Utility class that helps to
 *           create CTreeIteratorFixedDepth instances from specific values.
 *  \brief   Tree fixed depth iterator maker class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree fixed depth iterator maker class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   14.07.2006 20:01:28

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
#ifndef __CTREEITERATORFIXEDDEPTHMAKER_INL__
#define __CTREEITERATORFIXEDDEPTHMAKER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_TreeIterator>
inline CTreeIteratorFixedDepth<T_TreeIterator> CTreeIteratorFixedDepthMaker::make(const T_TreeIterator& a_crTreeIterator)
{ CALL
  return CTreeIteratorFixedDepth<T_TreeIterator>(a_crTreeIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorFixedDepth<T_TreeIterator> CTreeIteratorFixedDepthMaker::make(const CTreeIteratorFixedDepth<T_TreeIterator>& a_crInstance)
{ CALL
  return CTreeIteratorFixedDepth<T_TreeIterator>(a_crInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
