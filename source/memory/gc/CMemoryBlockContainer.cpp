/*!
 *  \file    CMemoryBlockContainer.cpp GC allocated memory blocks container
 *           class.
 *  \brief   GC allocated memory blocks container class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: GC allocated memory blocks container class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory garbage collection
    VERSION:   1.0
    CREATED:   26.06.2007 02:30:49

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
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/memory/gc/CMemoryBlockContainer.hpp>
/*==========================================================================*/
#ifndef __CMEMORYBLOCKCONTAINER_CPP__
#define __CMEMORYBLOCKCONTAINER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NGC {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CMemoryBlockContainer::isEmpty() const
{ CALL
  return (CMemory::getGCAllocatedBlocks() == 0);
}
/*--------------------------------------------------------------------------*/
Tuint CMemoryBlockContainer::getSize() const
{ CALL
  return CMemory::getGCAllocatedBlocks();
}
/*--------------------------------------------------------------------------*/
CMemoryBlockIterator CMemoryBlockContainer::find(const Tcptr& a_cpPointer)
{ CALL
  CMemoryBlockIterator it;

  // Filling iterator inner structure.
  it.m_cpContainer = this;
  it.m_cpBlock = CMemory::getGCBlockByPointer(a_cpPointer);
  return it;
}
/*--------------------------------------------------------------------------*/
CMemoryBlockIterator CMemoryBlockContainer::find(const Tcptr& a_cpPointer) const
{ CALL
  CMemoryBlockIterator it;

  // Filling iterator inner structure.
  it.m_cpContainer = this;
  it.m_cpBlock = CMemory::getGCBlockByPointer(a_cpPointer);
  return it;
}
/*--------------------------------------------------------------------------*/
CMemoryBlockIterator CMemoryBlockContainer::getItFirst()
{ CALL
  CMemoryBlockIterator it;

  // Filling iterator inner structure.
  it.m_cpContainer = this;
  it.m_cpBlock = CMemory::getFirstGCBlock();
  return it;
}
/*--------------------------------------------------------------------------*/
CMemoryBlockIterator CMemoryBlockContainer::getItFirst() const
{ CALL
  CMemoryBlockIterator it;

  // Filling iterator inner structure.
  it.m_cpContainer = this;
  it.m_cpBlock = CMemory::getFirstGCBlock();
  return it;
}
/*--------------------------------------------------------------------------*/
CMemoryBlockIterator CMemoryBlockContainer::getItLast()
{ CALL
  CMemoryBlockIterator it;

  // Filling iterator inner structure.
  it.m_cpContainer = this;
  it.m_cpBlock = CMemory::getLastGCBlock();
  return it;
}
/*--------------------------------------------------------------------------*/
CMemoryBlockIterator CMemoryBlockContainer::getItLast() const
{ CALL
  CMemoryBlockIterator it;

  // Filling iterator inner structure.
  it.m_cpContainer = this;
  it.m_cpBlock = CMemory::getLastGCBlock();
  return it;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
