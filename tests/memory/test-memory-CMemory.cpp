/*!
 *  \file    test-memory-CMemory.cpp Testing of the CMemory class.
 *  \brief   Testing of the CMemory class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CMemory class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth memory tests
    VERSION:   1.0
    CREATED:   28.06.2007 02:22:53

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
// Common headers.
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/memory/managers/CMemoryManagerSystem.hpp>
#include <Depth/include/random/CRandomGenerator.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NMemory;
using namespace NDepth::NRandom;
/*==========================================================================*/
static Tuint the_Counter = 0;
/*--------------------------------------------------------------------------*/
class CTestClass
{
public:
  CTestClass()
  { CALL
    ++the_Counter;
  }
 ~CTestClass()
  { CALL
    --the_Counter;
  }
};
/*==========================================================================*/
class MyMemoryManager :
  public CMemoryManagerSystem
{
protected:
  virtual Tptr allocate(const Tuint a_cSize)
  { CALL
    return CMemoryManagerSystem::allocate(a_cSize);
  }

  virtual Tptr reallocate(Tptr a_pPointer, const Tuint a_cSize)
  { CALL
    return CMemoryManagerSystem::reallocate(a_pPointer, a_cSize);
  }

  virtual Tbool free(Tptr a_pPointer)
  { CALL
    return CMemoryManagerSystem::free(a_pPointer);
  }
};
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    IMemoryManager* old_manager = NULL;
    IMemoryManager* new_manager = newex MyMemoryManager();

    // Get old memory manager.
    old_manager = CMemory::getMemoryManager();

    UT_ASSERT_VALID_PTR(old_manager);
    UT_ASSERT_VALID_PTR(new_manager);

    // Set new memory manager.
    UT_ASSERT(CMemory::setMemoryManager(new_manager));

    UT_ASSERT_CHECK_ALIGN();
    UT_ASSERT_CHECK_BLOCK();
    UT_ASSERT_CHECK_NEWEX();

    // Restore old memory manager.
    CMemory::setMemoryManager(old_manager);
    // Delete new memory manager.
    delete new_manager;

    UT_ACCEPT;
  }

  // Check the aligned memory allocation functionality.
  void UT_ASSERT_CHECK_ALIGN()
  { CALL
    CRandomGenerator generator;
    Tuint n = 1000;

    while (n-- > 0)
    {
      Tuint align = 32;
      Tuint size = generator.randomInteger() % 1000 + 1;
      Tuint offset = generator.randomInteger() % size;

      // Allocate aligned memory block.
      Tptr pointer = CMemory::allocateAligned(size, align, offset);

      UT_ASSERT_VALID_PTR(pointer);

      // Check alignment of the memory block.
      UT_ASSERT_ZERO(((Tuint)pointer + offset) % align);

      // Free aligned memory block.
      UT_ASSERT(CMemory::freeAligned(pointer));
    }
  }

  // Check the memory block allocation functionality.
  void UT_ASSERT_CHECK_BLOCK()
  { CALL
    // Allocate block of memory.
    Tptr block = CMemory::allocate(100);

    UT_ASSERT_VALID_PTR(block);

    // Reallocate block of memory.
    block = CMemory::reallocate(block, 1000);

    UT_ASSERT_VALID_PTR(block);

    // Free block of memory.
    UT_ASSERT(CMemory::free(block));
  }

  // Check the memory allocation functionality with 'newex' operator.
  void UT_ASSERT_CHECK_NEWEX()
  { CALL
    // Create many instances.
    CTestClass* test1 = newex CTestClass();
    UT_ASSERT_VALID_PTR(test1);
    UT_ASSERT_EQUAL(the_Counter, 1);

    // Create many instances.
    CTestClass* test2 = newex CTestClass[1000];
    UT_ASSERT_VALID_PTR(test2);
    UT_ASSERT_EQUAL(the_Counter, 1001);

    // Delete one instance.
    delete test1;
    UT_ASSERT_EQUAL(the_Counter, 1000);

    // Delete many instances.
    delete [] test2;
    UT_ASSERT_EQUAL(the_Counter, 0);
  }
} the_Test;
/*==========================================================================*/
