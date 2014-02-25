/*!
 *  \file    CCopyPolicyMemory.inl Memory copy policy class. This class uses
 *           direct memory coping methods to copy items from one memory block
 *           to another.
 *  \brief   Memory copy policy class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory copy policy class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers policy
    VERSION:   1.0
    CREATED:   16.03.2006 22:43:31

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
#ifndef __CCOPYPOLICYMEMORY_INL__
#define __CCOPYPOLICYMEMORY_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NPolicy {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline void CCopyPolicyMemory::copy(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount)
{ CALL
  NMemory::CMemory::copy((Tptr)a_pDestination, (Tcptr)a_cpSource, a_cCount * sizeof(T_Type));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CCopyPolicyMemory::copyReverse(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount)
{ CALL
  NMemory::CMemory::copyReverse((Tptr)a_pDestination, (Tcptr)a_cpSource, a_cCount * sizeof(T_Type));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CCopyPolicyMemory::move(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount)
{ CALL
  NMemory::CMemory::move((Tptr)a_pDestination, (Tcptr)a_cpSource, a_cCount * sizeof(T_Type));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CCopyPolicyMemory::moveReverse(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount)
{ CALL
  NMemory::CMemory::moveReverse((Tptr)a_pDestination, (Tcptr)a_cpSource, a_cCount * sizeof(T_Type));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
