/*!
 *  \file    CMemoryManagerSystem.cpp Memory manager class which uses system
 *           memory allocation.
 *  \brief   Memory manager class which uses system memory allocation (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory manager class which uses system memory allocation (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory managers
    VERSION:   1.0
    CREATED:   28.06.2007 02:16:18

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/memory/managers/CMemoryManagerSystem.hpp>
#include <Depth/include/system/CSystemBase.hpp>
/*==========================================================================*/
#ifndef __CMEMORYMANAGERSYSTEM_CPP__
#define __CMEMORYMANAGERSYSTEM_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NManagers {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tptr CMemoryManagerSystem::allocate(const Tuint a_cSize)
{ CALL
  return NSystem::CSystemBase::memoryAllocate(a_cSize);
}
/*--------------------------------------------------------------------------*/
Tptr CMemoryManagerSystem::reallocate(Tptr a_pPointer, const Tuint a_cSize)
{ CALL
  // Check if the pointer to the reallocated memory block is not NULL.
  ASSERT((a_pPointer != NULL), STR("Pointer to the reallocated memory block should not be NULL."))
  {
    return NULL;
  }

  return NSystem::CSystemBase::memoryReallocate(a_pPointer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CMemoryManagerSystem::free(Tptr a_pPointer)
{ CALL
  // Check if the pointer to the freed memory block is not NULL.
  ASSERT((a_pPointer != NULL), STR("Pointer to the freed memory block should not be NULL."))
  {
    return false;
  }

  return NSystem::CSystemBase::memoryFree(a_pPointer);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
