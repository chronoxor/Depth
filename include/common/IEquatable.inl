/*!
 *  \file    IEquatable.inl Interface for all equal comparable classes that
 *           can be compared with 'isEqual()' virtual method.
 *  \brief   Equal comparable interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Equal comparable interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common
    VERSION:   1.0
    CREATED:   11.10.2006 22:52:46

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
#ifndef __IEQUATABLE_INL__
#define __IEQUATABLE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_Class>
inline IEquatable<T_Class>::IEquatable()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline IEquatable<T_Class>::~IEquatable()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline Tbool IEquatable<T_Class>::isNotEqual(const TType& a_crInstance) const
{ CALL
  return (!isEqual(a_crInstance));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
