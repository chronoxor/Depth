/*!
 *  \file    CLimitRandomIteratorMaker.inl Utility class that helps to
 *           create CLimitRandomIterator instances from specific values.
 *  \brief   Limit random iterator wrapper maker class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Limit random iterator wrapper maker class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   04.04.2007 02:29:52

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
#ifndef __CLIMITRANDOMITERATORMAKER_INL__
#define __CLIMITRANDOMITERATORMAKER_INL__
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
inline CLimitRandomIterator<T_RandomIterator> CLimitRandomIteratorMaker::make(const T_RandomIterator& a_crCurrentIterator)
{ CALL
  return CLimitRandomIterator<T_RandomIterator>(a_crCurrentIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> CLimitRandomIteratorMaker::make(const T_RandomIterator& a_crCurrentIterator, const Tuint a_cEndLimit)
{ CALL
  return CLimitRandomIterator<T_RandomIterator>(a_crCurrentIterator, a_cEndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> CLimitRandomIteratorMaker::make(const T_RandomIterator& a_crCurrentIterator, const Tuint a_cStartLimit, const Tuint a_cEndLimit)
{ CALL
  return CLimitRandomIterator<T_RandomIterator>(a_crCurrentIterator, a_cStartLimit, a_cEndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> CLimitRandomIteratorMaker::make(const CLimitRandomIterator<T_RandomIterator>& a_crInstance)
{ CALL
  return CLimitRandomIterator<T_RandomIterator>(a_crInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
