/*!
 *  \file    MConceptIAllocator.inl Template checking conception. Checks if
 *           template argument is a memory allocator.
 *  \brief   Memory allocator template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory allocator template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Types conception checking
    VERSION:   1.0
    CREATED:   14.01.2007 21:12:26

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
#ifndef __MCONCEPTIALLOCATOR_INL__
#define __MCONCEPTIALLOCATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NTypes {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <class T_Class>
inline MConceptIAllocator<T_Class>::MConceptIAllocator() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptIAllocator<T_Class>::~MConceptIAllocator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptIAllocator<T_Class>::constraints()
{ CALL
  // Check for IAllocator interface.
  NDepth::NMemory::NAllocators::IAllocator& tempAllocator = m_Allocator;

  // Check for allocation methods.
  Tsint* check1 = tempAllocator.template allocateOne<Tsint>();
  Tsint* check2 = tempAllocator.template allocateMany<Tsint>(2);
  // Check for creation methods.
  Tsint* check3 = tempAllocator.template createOne<Tsint>(0);
  Tsint* check4 = tempAllocator.template createMany<Tsint>(2, 0);
  // Check for initialize methods.
  check1 = tempAllocator.initializeOne(check1, 0);
  check2 = tempAllocator.initializeMany(check2, 2, 0);
  // Check for destroy methods.
  tempAllocator.destroyOne(check3);
  tempAllocator.destroyMany(check4, 2);
  // Check for delete methods.
  tempAllocator.deleteOne(check3);
  tempAllocator.deleteMany(check4, 2);
  // Check for free methods.
  tempAllocator.freeOne(check1);
  tempAllocator.freeMany(check2, 2);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
