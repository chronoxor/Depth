/*!
 *  \file    CMemory.cpp Static memory class gives a set of memory allocation
 *           routines and memory manipulation utilities.
 *  \brief   Static memory class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static memory class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory
    VERSION:   1.0
    CREATED:   21.01.2006 01:15:21

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#include <Depth/include/algorithms/containers/ALowerBound.hpp>
#include <Depth/include/algorithms/numeric/AIs2PowN.hpp>
#include <Depth/include/containers/CMap.hpp>
#include <Depth/include/containers/CSet.hpp>
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/memory/gc/CMemoryBlock.hpp>
#include <Depth/include/memory/allocators/CAllocatorSystem.hpp>
#include <Depth/include/memory/managers/CMemoryManagerSystem.hpp>
/*==========================================================================*/
#ifndef __CMEMORY_CPP__
#define __CMEMORY_CPP__
/*==========================================================================*/
/* LOCAL NAMESPACE DECLARATIONS                                             */
/*==========================================================================*/
namespace {
/*==========================================================================*/
/* LOCAL TYPES DECLARATIONS                                                 */
/*==========================================================================*/
//! GC allocated memory blocks container type.
typedef NDepth::NContainers::CSet<NDepth::NMemory::NGC::CMemoryBlock, NDepth::NAlgorithms::NFunctions::FBoolLessThan<const NDepth::NMemory::NGC::CMemoryBlock&>, NDepth::NContainers::CBinTreeRB, NDepth::NMemory::NAllocators::CAllocatorSystem> TBlockContainer;
//! GC smart pointer container type.
typedef NDepth::NContainers::CMap<NDepth::NTypes::Tptr, NDepth::NMemory::NGC::CMemoryBlock*, NDepth::NAlgorithms::NFunctions::FBoolLessThan<const NDepth::NTypes::Tptr&>, NDepth::NContainers::CBinTreeRB, NDepth::NMemory::NAllocators::CAllocatorSystem> TGCPointerContainer;
/*==========================================================================*/
/* LOCAL VARIABLES DECLARATIONS                                             */
/*==========================================================================*/
//! GC allocated memory blocks container.
TBlockContainer loc_Blocks;
//! GC smart pointer container.
TGCPointerContainer loc_GCPointers;
//! GC marker.
NDepth::NTypes::Tbool loc_GCMarker = false;
/*--------------------------------------------------------------------------*/
//! Global system memory manager.
NDepth::NMemory::NManagers::CMemoryManagerSystem loc_SystemMemoryManager;
/*==========================================================================*/
/* LOCAL FUNCTIONS DECLARATIONS & IMPLEMENTATIONS                           */
/*==========================================================================*/
//! Compare two memory blocks with 'lessThan' binary predicate.
/*!
    \param a_crBlock1 - Constant reference to the first comparing block.
    \param a_crBlock2 - Constant reference to the second comparing block.
    \return true  - if first memory block is less than second one. \n
            false - if first memory block is not less than second one. \n
*/
NDepth::NTypes::Tbool compareBlocks(const NDepth::NMemory::NGC::CMemoryBlock& a_crBlock1, const NDepth::NMemory::NGC::CMemoryBlock& a_crBlock2)
{ CALL
  return ((NDepth::NAlgorithms::NCommon::staticCast<const NDepth::NTypes::Tbyte*>(a_crBlock1.getPointer()) + a_crBlock1.getSize()) < NDepth::NAlgorithms::NCommon::staticCast<const NDepth::NTypes::Tbyte*>(a_crBlock2.getPointer()));
}
/*==========================================================================*/
}
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CMemory::ms_isGCEnabled = false;
Tuint CMemory::ms_GCAllocatedSize = 0;
Tuint CMemory::ms_GCAllocatedBlocks = 0;
IMemoryManager* CMemory::ms_pMemoryManager = &loc_SystemMemoryManager;
NProcess::CRWLock CMemory::ms_GCEnabledLocker = NProcess::CRWLock(true);
NProcess::CRWLock CMemory::ms_GCPerformLocker = NProcess::CRWLock(true);
NProcess::CRWLock CMemory::ms_GCRegisterLocker = NProcess::CRWLock(true);
NProcess::CRWLock CMemory::ms_MemoryManagerLocker = NProcess::CRWLock(true);
/*--------------------------------------------------------------------------*/
Tbool CMemory::performGC()
{ CALL
  // Check if the GC mode is enabled.
  ASSERT(CMemory::isGCEnabled(), STR("GC mode is not enabled."))
  {
    return false;
  }

  // Exclusive lock the memory GC under the multi-threaded environment.
  NProcess::CScopeWriter wlocker(CMemory::ms_GCPerformLocker);

  Tbool result = true;

  // Toggle current GC marker.
  loc_GCMarker = !loc_GCMarker;

  // Mark allocated memory blocks.
  {
    // Shared lock the memory GC register under the multi-threaded environment.
    NProcess::CScopeReader rlocker(CMemory::ms_GCRegisterLocker);

    TGCPointerContainer::TIterator it_pointer_first = loc_GCPointers.getItFirst();
    TGCPointerContainer::TIterator it_pointer_current = it_pointer_first;
    while (it_pointer_current.isValid())
    {
      Tptr pointer = it_pointer_current.getKeyRef();
      CMemoryBlock* block = it_pointer_current.getValueRef();

      // Skip marked GC smart pointers.
      if ((block != NULL) && (block->m_IsMarked != loc_GCMarker))
      {
        // Recursive mark root GC smart pointers.
        const CMemoryBlock* root_block = CMemory::getGCBlockByPointer(pointer);
        // Check if GC pointer was registered and linked with allocated memory block.
        if (root_block == NULL)
          CMemory::mark(it_pointer_current.getValueRef());
      }

      // Get new GC smart pointer.
      if ((it_pointer_current.stepForward() == 0) || (it_pointer_current == it_pointer_first))
        break;
    }
  }

  // Sweep unmarked allocated memory blocks.
  TBlockContainer::TIterator it_block_first = loc_Blocks.getItFirst();
  TBlockContainer::TIterator it_block_current = it_block_first;
  TBlockContainer::TIterator it_block_next = it_block_first;
  while (it_block_current.isValid())
  {
    Tbool stop = ((it_block_next.stepForward() == 0) || (it_block_next == it_block_first));

    // Remove unmarked allocated memory block.
    CMemoryBlock* block = NDepth::NAlgorithms::NCommon::constCast<CMemoryBlock*>(it_block_current.getValuePtr());
    if (block->m_IsMarked != loc_GCMarker)
    {
      block->m_IsMarked = loc_GCMarker;
      // Call an object destructor.
      if (block->release())
      {
        // Free corresponding memory block.
        if (CMemory::ms_pMemoryManager->free(block->getPointer()))
        {
          Tuint block_size = block->getSize();
          // Remove freed block from allocated memory blocks container.
          if (it_block_current.remove())
          {
            CMemory::ms_GCAllocatedSize -= block_size;
            CMemory::ms_GCAllocatedBlocks -= 1;
          }
          else
          {
            result = false;
            break;
          }
        }
        else
        {
          result = false;
          break;
        }
      }
    }
    it_block_current = it_block_next;

    if (stop)
      break;
  }

  return result;
}
/*--------------------------------------------------------------------------*/
void CMemory::mark(Tptr a_pRootMemoryBlock)
{ CALL
  CMemoryBlock* block = (CMemoryBlock*)a_pRootMemoryBlock;
  if ((block != NULL) && (block->m_IsMarked != loc_GCMarker))
  {
    // Mark current allocated memory block.
    block->m_IsMarked = loc_GCMarker;
    // Perform recursive mark operation.
    TGCPointerContainer::TIterator it_pointer_first = loc_GCPointers.getItFirst();
    TGCPointerContainer::TIterator it_pointer_current = it_pointer_first;
    while (it_pointer_current.isValid())
    {
      if (block->contains(it_pointer_current.getKeyRef()))
        CMemory::mark(it_pointer_current.getValueRef());
      // Get new GC smart pointer.
      if ((it_pointer_current.stepForward() == 0) || (it_pointer_current == it_pointer_first))
        break;
    }
  }
}
/*--------------------------------------------------------------------------*/
Tbool CMemory::registerGCPointer(Tptr a_pGCPointer)
{ CALL
  // Check if the GC mode is enabled.
  ASSERT(CMemory::isGCEnabled(), STR("GC mode is not enabled."))
  {
    return false;
  }
  // Check if the given pointer is not NULL.
  ASSERT((a_pGCPointer != NULL), STR("GC smart pointer should not be NULL."))
  {
    return false;
  }

  // Exclusive lock the memory GC register under the multi-threaded environment.
  NProcess::CScopeWriter wlocker(CMemory::ms_GCRegisterLocker);

  return loc_GCPointers.insert(a_pGCPointer, NULL);
}
/*--------------------------------------------------------------------------*/
Tbool CMemory::unregisterGCPointer(Tptr a_pGCPointer)
{ CALL
  // Check if the GC mode is enabled.
  ASSERT(CMemory::isGCEnabled(), STR("GC mode is not enabled."))
  {
    return false;
  }
  // Check if the given pointer is not NULL.
  ASSERT((a_pGCPointer != NULL), STR("GC smart pointer should not be NULL."))
  {
    return false;
  }

  // Exclusive lock the memory GC register under the multi-threaded environment.
  NProcess::CScopeWriter wlocker(CMemory::ms_GCRegisterLocker);

  return loc_GCPointers.remove(a_pGCPointer);
}
/*--------------------------------------------------------------------------*/
Tbool CMemory::updateGCPointer(Tptr a_pGCPointer, Tptr a_pObjectPointer, void (*a_fObjectDestructor)(Tptr))
{ CALL
  // Check if the GC mode is enabled.
  ASSERT(CMemory::isGCEnabled(), STR("GC mode is not enabled."))
  {
    return false;
  }
  // Check if the given pointer is not NULL.
  ASSERT((a_pGCPointer != NULL), STR("GC smart pointer should not be NULL."))
  {
    return false;
  }

  // There is no update need for NULL object pointer.
  if (a_pObjectPointer == NULL)
    return true;

  // Exclusive lock the memory GC register under the multi-threaded environment.
  NProcess::CScopeWriter wlocker(CMemory::ms_GCRegisterLocker);

  // Get registered GC smart pointer.
  TGCPointerContainer::TIterator it_pointer = loc_GCPointers.find(a_pGCPointer);
  // Get allocated memory block, which corresponds to the given GC smart pointer.
  const CMemoryBlock* root_block = CMemory::getGCBlockByPointer(a_pObjectPointer);
  // Check if GC pointer was registered and linked with allocated memory block.
  if (it_pointer.isValid() && (root_block != NULL))
  {
    // Update allocated memory block.
    CMemoryBlock* block = NDepth::NAlgorithms::NCommon::constCast<CMemoryBlock*>(root_block);
    block->update(a_pObjectPointer, a_fObjectDestructor);
    // Update GC smart pointer.
    it_pointer.getValueRef() = block;
    return true;
  }
  else
  {
    WARNING(STR("GC smart pointer is not registered - %p.") COMMA a_pGCPointer);
    return false;
  }
}
/*--------------------------------------------------------------------------*/
const CMemoryBlock* CMemory::getFirstGCBlock()
{ CALL
  TBlockContainer::TIterator it = loc_Blocks.getItFirst();
  return (it.isValid() ? it.getValuePtr() : NULL);
}
/*--------------------------------------------------------------------------*/
const CMemoryBlock* CMemory::getLastGCBlock()
{ CALL
  TBlockContainer::TIterator it = loc_Blocks.getItLast();
  return (it.isValid() ? it.getValuePtr() : NULL);
}
/*--------------------------------------------------------------------------*/
const CMemoryBlock* CMemory::getPrevGCBlock(const CMemoryBlock* a_cpGCBlock)
{ CALL
  // Check if the given memory block is not valid.
  ASSERT((a_cpGCBlock != NULL), STR("GC memory block is not valid. It should not be NULL."))
  {
    return NULL;
  }

  Tptr pointer = NAlgorithms::NCommon::constCast<Tptr>(a_cpGCBlock->getPointer());
  TBlockContainer::TIterator it(NAlgorithms::NContainers::lowerBound(loc_Blocks, CMemoryBlock(pointer, 0, FUNCTION_SIGNATURE, FILE, LINE), compareBlocks));
  if (it.isValid() && (it.stepBackward() > 0))
    return (it.isValid() ? it.getValuePtr() : NULL);
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
const CMemoryBlock* CMemory::getNextGCBlock(const CMemoryBlock* a_cpGCBlock)
{ CALL
  // Check if the given memory block is not valid.
  ASSERT((a_cpGCBlock != NULL), STR("GC memory block is not valid. It should not be NULL."))
  {
    return NULL;
  }

  Tptr pointer = NAlgorithms::NCommon::constCast<Tptr>(a_cpGCBlock->getPointer());
  TBlockContainer::TIterator it(NAlgorithms::NContainers::lowerBound(loc_Blocks, CMemoryBlock(pointer, 0, FUNCTION_SIGNATURE, FILE, LINE), compareBlocks));
  if (it.isValid() && (it.stepForward() > 0))
    return (it.isValid() ? it.getValuePtr() : NULL);
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
const CMemoryBlock* CMemory::getGCBlockByPointer(Tcptr a_cpPointer)
{ CALL
  Tptr pointer = NAlgorithms::NCommon::constCast<Tptr>(a_cpPointer);
  TBlockContainer::TIterator it(NAlgorithms::NContainers::lowerBound(loc_Blocks, CMemoryBlock(pointer, 0, FUNCTION_SIGNATURE, FILE, LINE), compareBlocks));
  return ((it.isValid() && it.getValueRef().contains(pointer)) ? it.getValuePtr() : NULL);
}
/*--------------------------------------------------------------------------*/
Tptr CMemory::allocate(const Tuint a_cSize, Tcsstr a_cpFunctionSignature/* = ASC("") */, Tcstr a_cpFileName/* = STR("") */, const Tuint a_cLine/* = 0 */)
{ CALL
  Tptr pointer = NULL;
  {
    // Shared lock the memory manager under the multi-threaded environment.
    NProcess::CScopeReader rlocker(CMemory::ms_MemoryManagerLocker);

    pointer = CMemory::ms_pMemoryManager->allocate(a_cSize);
  }

  // Save GC information.
  if (CMemory::isGCEnabled() && (pointer != NULL))
  {
    // Exclusive lock the memory GC under the multi-threaded environment.
    NProcess::CScopeWriter wlocker(CMemory::ms_GCPerformLocker);

    loc_Blocks.insert(CMemoryBlock(pointer, a_cSize, a_cpFunctionSignature, a_cpFileName, a_cLine, loc_GCMarker));
    CMemory::ms_GCAllocatedSize += a_cSize;
    CMemory::ms_GCAllocatedBlocks += 1;
  }
  return pointer;
}
/*--------------------------------------------------------------------------*/
Tptr CMemory::allocateZero(const Tuint a_cSize, Tcsstr a_cpFunctionSignature/* = ASC("") */, Tcstr a_cpFileName/* = STR("") */, const Tuint a_cLine/* = 0 */)
{ CALL
  Tptr pointer = NULL;
  {
    // Shared lock the memory manager under the multi-threaded environment.
    NProcess::CScopeReader rlocker(CMemory::ms_MemoryManagerLocker);

    pointer = CMemory::ms_pMemoryManager->allocate(a_cSize);
  }

  // Zero memory block.
  if (pointer != NULL)
    CMemory::zero(pointer, a_cSize);
  // Save GC information.
  if (CMemory::isGCEnabled() && (pointer != NULL))
  {
    // Exclusive lock the memory GC under the multi-threaded environment.
    NProcess::CScopeWriter wlocker(CMemory::ms_GCPerformLocker);

    loc_Blocks.insert(CMemoryBlock(pointer, a_cSize, a_cpFunctionSignature, a_cpFileName, a_cLine, loc_GCMarker));
    CMemory::ms_GCAllocatedSize += a_cSize;
    CMemory::ms_GCAllocatedBlocks += 1;
  }
  return pointer;
}
/*--------------------------------------------------------------------------*/
Tptr CMemory::allocateZero(const Tuint a_cOneElementSize, const Tuint a_cElementsCount, Tcsstr a_cpFunctionSignature/* = ASC("") */, Tcstr a_cpFileName/* = STR("") */, const Tuint a_cLine/* = 0 */)
{ CALL
  Tuint size = a_cOneElementSize * a_cElementsCount;
  Tptr pointer = NULL;
  {
    // Shared lock the memory manager under the multi-threaded environment.
    NProcess::CScopeReader rlocker(CMemory::ms_MemoryManagerLocker);

    pointer = CMemory::ms_pMemoryManager->allocate(size);
  }

  // Zero memory block.
  if (pointer != NULL)
    CMemory::zero(pointer, size);
  // Save GC information.
  if (CMemory::isGCEnabled() && (pointer != NULL))
  {
    // Exclusive lock the memory GC under the multi-threaded environment.
    NProcess::CScopeWriter wlocker(CMemory::ms_GCPerformLocker);

    loc_Blocks.insert(CMemoryBlock(pointer, size, a_cpFunctionSignature, a_cpFileName, a_cLine, loc_GCMarker));
    CMemory::ms_GCAllocatedSize += size;
    CMemory::ms_GCAllocatedBlocks += 1;
  }
  return pointer;
}
/*--------------------------------------------------------------------------*/
Tptr CMemory::reallocate(Tptr a_pPointer, const Tuint a_cSize, Tcsstr a_cpFunctionSignature/* = ASC("") */, Tcstr a_cpFileName/* = STR("") */, const Tuint a_cLine/* = 0 */)
{ CALL
  Tptr pointer = NULL;
  {
    // Shared lock the memory manager under the multi-threaded environment.
    NProcess::CScopeReader rlocker(CMemory::ms_MemoryManagerLocker);

    pointer = CMemory::ms_pMemoryManager->reallocate(a_pPointer, a_cSize);
  }

  // Save GC information.
  if (CMemory::isGCEnabled())
  {
    // Exclusive lock the memory GC under the multi-threaded environment.
    NProcess::CScopeWriter wlocker(CMemory::ms_GCPerformLocker);

    // Find and remove old allocated memory block.
    if (a_pPointer != NULL)
    {
      // Find and remove freed memory block.
      TBlockContainer::TIterator it(NAlgorithms::NContainers::lowerBound(loc_Blocks, CMemoryBlock(a_pPointer, 0, a_cpFunctionSignature, a_cpFileName, a_cLine), compareBlocks));
      if (it.isValid() && it.getValueRef().contains(a_pPointer))
      {
        Tuint block_size = it.getValueRef().getSize();
        if (it.remove())
        {
          CMemory::ms_GCAllocatedSize -= block_size;
          CMemory::ms_GCAllocatedBlocks -= 1;
        }
      }
    }
    // Insert new allocated memory block.
    if (pointer != NULL)
    {
      loc_Blocks.insert(CMemoryBlock(pointer, a_cSize, a_cpFunctionSignature, a_cpFileName, a_cLine, loc_GCMarker));
      CMemory::ms_GCAllocatedSize += a_cSize;
      CMemory::ms_GCAllocatedBlocks += 1;
    }
  }
  return pointer;
}
/*--------------------------------------------------------------------------*/
Tbool CMemory::free(Tptr a_pPointer, Tcsstr a_cpFunctionSignature/* = ASC("") */, Tcstr a_cpFileName/* = STR("") */, const Tuint a_cLine/* = 0 */)
{ CALL
  Tbool result = false;
  {
    // Shared lock the memory manager under the multi-threaded environment.
    NProcess::CScopeReader rlocker(CMemory::ms_MemoryManagerLocker);

    result = CMemory::ms_pMemoryManager->free(a_pPointer);
  }

  // Save GC information.
  if (CMemory::isGCEnabled() && (a_pPointer != NULL))
  {
    // Exclusive lock the memory GC under the multi-threaded environment.
    NProcess::CScopeWriter wlocker(CMemory::ms_GCPerformLocker);

    // Find and remove freed memory block.
    TBlockContainer::TIterator it(NAlgorithms::NContainers::lowerBound(loc_Blocks, CMemoryBlock(a_pPointer, 0, a_cpFunctionSignature, a_cpFileName, a_cLine), compareBlocks));
    if (it.isValid() && it.getValueRef().contains(a_pPointer))
    {
      Tuint block_size = it.getValueRef().getSize();
      if (it.remove())
      {
        CMemory::ms_GCAllocatedSize -= block_size;
        CMemory::ms_GCAllocatedBlocks -= 1;
      }
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
Tptr CMemory::allocateAligned(const Tuint a_cSize, const Tuint a_cAlign, const Tuint a_cOffset/* = 0 */, Tcsstr a_cpFunctionSignature/* = ASC("") */, Tcstr a_cpFileName/* = STR("") */, const Tuint a_cLine/* = 0 */)
{ CALL
  // Check if the alignment value is in the 2^N form.
  ASSERT(NAlgorithms::NNumeric::is2PowN(a_cAlign), STR("Alignment value should not be in the 2^N from (align = %u).") COMMA a_cAlign)
  {
    return NULL;
  }

  // Check if the alignment value is in the 2^N form.
  ASSERT((a_cOffset < a_cSize) || ((a_cSize == 0) && (a_cOffset == 0)), STR("Left offset from align bound should not be less than allocation size (offset = %u, size = %u).") COMMA a_cOffset COMMA a_cSize)
  {
    return NULL;
  }

  Tbyte* aligned_pointer;
  Tbyte* temp_pointer;

  // Get the align mask value.
  Tuint align_mask = a_cAlign - 1;

  // Allocate memory buffer with reserved header.
  Tbyte* pointer = (Tbyte*)CMemory::allocate(a_cSize + (align_mask << 1) + sizeof(Tuint), a_cpFunctionSignature, a_cpFileName, a_cLine);

  if (pointer != NULL)
  {
    // Get aligned pointer.
    temp_pointer = pointer + sizeof(Tuint) + a_cOffset;
    aligned_pointer = temp_pointer + (a_cAlign - (((Tuint)temp_pointer) & align_mask));

    // Save offset value into the memory block header (which is also aligned).
    temp_pointer = aligned_pointer - sizeof(Tuint) - a_cOffset;
    temp_pointer = temp_pointer - (((Tuint)temp_pointer) & (sizeof(Tuint) - 1));
    *((Tuint*)temp_pointer) = (Tuint)(aligned_pointer - pointer - a_cOffset);

    // Update pointer value.
    pointer = aligned_pointer - a_cOffset;
  }
  return pointer;
}
/*--------------------------------------------------------------------------*/
Tbool CMemory::freeAligned(Tptr a_pPointer, Tcsstr a_cpFunctionSignature/* = ASC("") */, Tcstr a_cpFileName/* = STR("") */, const Tuint a_cLine/* = 0 */)
{ CALL
  // Check if the pointer to the freed memory block is not NULL.
  ASSERT((a_pPointer != NULL), STR("Pointer to the freed memory block should not be NULL."))
  {
    return false;
  }

  Tbyte* pointer = (Tbyte*)a_pPointer;
  Tbyte* temp_pointer = pointer - sizeof(Tuint) - (((Tuint)pointer) & (sizeof(Tuint) - 1));
  // Get pointer to the memory block header.
  Tuint* size_pointer = (Tuint*)temp_pointer;
  // Move pointer to the start of the real allocated buffer.
  pointer -= *size_pointer;
  // Free the real allocated buffer.
  return free(pointer, a_cpFunctionSignature, a_cpFileName, a_cLine);
}
/*--------------------------------------------------------------------------*/
Tbool CMemory::setMemoryManager(IMemoryManager* a_pMemoryManager)
{ CALL
  // Check if the given pointer to the memory manager is not NULL.
  ASSERT((a_pMemoryManager != NULL), STR("Pointer to the memory manager should not be NULL."))
  {
    return false;
  }

  // Exclusive lock the memory manager under the multi-threaded environment.
  NProcess::CScopeWriter wlocker(CMemory::ms_MemoryManagerLocker);

  CMemory::ms_pMemoryManager = a_pMemoryManager;
  return true;
}
/*--------------------------------------------------------------------------*/
void CMemory::restoreDefaultMemoryManager()
{ CALL
  // Exclusive lock the memory manager under the multi-threaded environment.
  NProcess::CScopeWriter wlocker(CMemory::ms_MemoryManagerLocker);

  CMemory::ms_pMemoryManager = &loc_SystemMemoryManager;
}
/*--------------------------------------------------------------------------*/
Tsint CMemory::compare(Tcptr a_cpFirst, Tcptr a_cpSecond, const Tuint a_cSize)
{ CALL
  Tuint counter = a_cSize;

  if (counter > 0)
  {
    while (--counter && *(Tbuffer)a_cpFirst == *(Tbuffer)a_cpSecond)
    {
      a_cpFirst = (Tbuffer)a_cpFirst + 1;
      a_cpSecond = (Tbuffer)a_cpSecond + 1;
    }
    return (*((Tbuffer)a_cpFirst) - *((Tbuffer)a_cpSecond));
  }
  else
    return 0;
}
/*--------------------------------------------------------------------------*/
Tsint CMemory::compareInverse(Tcptr a_cpFirst, Tcptr a_cpSecond, const Tuint a_cSize)
{ CALL
  Tuint counter = a_cSize;

  a_cpSecond = (Tbuffer)a_cpSecond + counter - 1;
  if (counter > 0)
  {
    while (--counter && *(Tbuffer)a_cpFirst == *(Tbuffer)a_cpSecond)
    {
      a_cpFirst = (Tbuffer)a_cpFirst + 1;
      a_cpSecond = (Tbuffer)a_cpSecond - 1;
    }
    return (*((Tbuffer)a_cpFirst) - *((Tbuffer)a_cpSecond));
  }
  else
    return 0;
}
/*--------------------------------------------------------------------------*/
Tsint CMemory::compareReverse(Tcptr a_cpFirst, Tcptr a_cpSecond, const Tuint a_cSize)
{ CALL
  Tuint counter = a_cSize;

  a_cpFirst = (Tbuffer)a_cpFirst + counter - 1;
  a_cpSecond = (Tbuffer)a_cpSecond + counter - 1;
  if (counter > 0)
  {
    while (--counter && *(Tbuffer)a_cpFirst == *(Tbuffer)a_cpSecond)
    {
      a_cpFirst = (Tbuffer)a_cpFirst - 1;
      a_cpSecond = (Tbuffer)a_cpSecond - 1;
    }
    return (*((Tbuffer)a_cpFirst) - *((Tbuffer)a_cpSecond));
  }
  else
    return 0;
}
/*--------------------------------------------------------------------------*/
void CMemory::copy(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cSize)
{ CALL
  Tuint counter = a_cSize;

  while (counter-- > 0)
  {
    *(Tbuffer)a_pDestination = *(Tbuffer)a_cpSource;
    a_pDestination = (Tbuffer)a_pDestination + 1;
    a_cpSource = (Tbuffer)a_cpSource + 1;
  }
}
/*--------------------------------------------------------------------------*/
void CMemory::copyReverse(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cSize)
{ CALL
  Tuint counter = a_cSize;

  a_cpSource = (Tbuffer)a_cpSource + counter - 1;
  while (counter-- > 0)
  {
    *(Tbuffer)a_pDestination = *(Tbuffer)a_cpSource;
    a_pDestination = (Tbuffer)a_pDestination + 1;
    a_cpSource = (Tbuffer)a_cpSource - 1;
  }
}
/*--------------------------------------------------------------------------*/
void CMemory::move(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cSize)
{ CALL
  Tuint counter = a_cSize;

  if (counter > 0)
  {
    if ((a_pDestination <= a_cpSource) || ((Tbuffer)a_pDestination >= ((Tbuffer)a_cpSource + counter)))
    {
      // Non-overlapping buffers: copy from lower addresses to higher addresses
      while (counter-- > 0)
      {
        *(Tbuffer)a_pDestination = *(Tbuffer)a_cpSource;
        a_pDestination = (Tbuffer)a_pDestination + 1;
        a_cpSource = (Tbuffer)a_cpSource + 1;
      }
    }
    else
    {
      // Overlapping buffers: copy from higher addresses to lower addresses
      a_pDestination = (Tbuffer)a_pDestination + counter - 1;
      a_cpSource = (Tbuffer)a_cpSource + counter - 1;
      while (counter-- > 0)
      {
        *(Tbuffer)a_pDestination = *(Tbuffer)a_cpSource;
        a_pDestination = (Tbuffer)a_pDestination - 1;
        a_cpSource = (Tbuffer)a_cpSource - 1;
      }
    }
  }
}
/*--------------------------------------------------------------------------*/
void CMemory::moveReverse(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cSize)
{ CALL
  Tuint counter = a_cSize;

  if (counter > 0)
  {
    if (((Tbuffer)a_pDestination >= ((Tbuffer)a_cpSource + counter)) || ((Tbuffer)a_cpSource >= ((Tbuffer)a_pDestination + counter)))
    {
      // Non-overlapping buffers: copy from lower addresses to higher addresses
      a_cpSource = (Tbuffer)a_cpSource + counter - 1;
      while (counter-- > 0)
      {
        *(Tbuffer)a_pDestination = *(Tbuffer)a_cpSource;
        a_pDestination = (Tbuffer)a_pDestination + 1;
        a_cpSource = (Tbuffer)a_cpSource - 1;
      }
    }
    else
    {
      // Overlapping buffers: copy from higher addresses to lower addresses
      Tbyte *min, *max, char_counter;
      Tbool first_block_copy;
      Tsint length;
      if ((Tbyte*)a_pDestination >= (Tbyte*)a_cpSource)
      {
        min = (Tbuffer)a_cpSource;
        max = (Tbuffer)a_pDestination;
        first_block_copy = true;
      }
      else
      {
        min = (Tbuffer)a_pDestination;
        max = (Tbuffer)a_cpSource;
        first_block_copy = false;
      }
      length = counter - (max - min);
      min = max;
      max = max + length - 1;
      if (first_block_copy)
      {
        a_cpSource = min - 1;
        a_pDestination = max + 1;
      }
      else
      {
        a_cpSource = min + counter - 1;
        a_pDestination = max - counter + 1;
      }
      length /= 2;
      counter -= length;
      while (length-- > 0)
      {
        char_counter = *min;
        *min = *max;
        *max = char_counter;
        ++min;
        --max;
      }
      if (first_block_copy)
      {
        while (counter-- > 0)
        {
          *(Tbuffer)a_pDestination = *(Tbuffer)a_cpSource;
          a_pDestination = (Tbuffer)a_pDestination + 1;
          a_cpSource = (Tbuffer)a_cpSource - 1;
        }
      }
      else
      {
        while (counter-- > 0)
        {
          *(Tbuffer)a_pDestination = *(Tbuffer)a_cpSource;
          a_pDestination = (Tbuffer)a_pDestination - 1;
          a_cpSource = (Tbuffer)a_cpSource + 1;
        }
      }
    }
  }
}
/*--------------------------------------------------------------------------*/
void CMemory::fill(Tptr a_pBlock, const Tuint a_cSize, const Tbyte a_cValue)
{ CALL
  Tuint counter = a_cSize;

  while (counter-- > 0)
  {
    *(Tbuffer)a_pBlock = a_cValue;
    a_pBlock = (Tbuffer)a_pBlock + 1;
  }
}
/*--------------------------------------------------------------------------*/
void CMemory::fill(Tptr a_pBlock, const Tuint a_cSize, Tcptr a_cpValueBuffer, const Tuint a_cValueSize)
{ CALL
  Tuint counter = a_cSize;

  Tuint value_counter = a_cValueSize;
  Tcptr value_buffer = a_cpValueBuffer;

  while (counter-- > 0)
  {
    *(Tbuffer)a_pBlock = *(Tbuffer)value_buffer;
    a_pBlock = (Tbuffer)a_pBlock + 1;
    if (value_counter-- > 1)
      value_buffer = (Tbuffer)value_buffer + 1;
    else
    {
      value_counter = a_cValueSize;
      value_buffer = a_cpValueBuffer;
    }
  }
}
/*--------------------------------------------------------------------------*/
void CMemory::zero(Tptr a_pBlock, const Tuint a_cSize)
{ CALL
  Tuint counter = a_cSize;

  while (counter-- > 0)
  {
    *(Tbuffer)a_pBlock = (Tbyte)0;
    a_pBlock = (Tbuffer)a_pBlock + 1;
  }
}
/*--------------------------------------------------------------------------*/
void CMemory::xorMask(Tptr a_pBlock, Tcptr a_cpMask, const Tuint a_cSize)
{ CALL
  Tuint counter = a_cSize;

  while (counter-- > 0)
  {
    *(Tbuffer)a_pBlock ^= *(Tbuffer)a_cpMask;
    a_pBlock = (Tbuffer)a_pBlock + 1;
    a_cpMask = (Tbuffer)a_cpMask + 1;
  }
}
/*--------------------------------------------------------------------------*/
void CMemory::xorMask(Tptr a_pDestination, Tcptr a_cpSource, Tcptr a_cpMask, const Tuint a_cSize)
{ CALL
  Tuint counter = a_cSize;

  while (counter-- > 0)
  {
    *(Tbuffer)a_pDestination = *(Tbuffer)a_cpSource ^ *(Tbyte*)a_cpMask;
    a_pDestination = (Tbuffer)a_pDestination + 1;
    a_cpSource = (Tbuffer)a_cpSource + 1;
    a_cpMask = (Tbuffer)a_cpMask + 1;
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
