/*!
 *  \file    test-memory-CAllocatorNewEx.cpp Testing of the CAllocatorNewEx
 *           class.
 *  \brief   Testing of the CAllocatorNewEx class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CAllocatorNewEx class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth memory tests
    VERSION:   1.0
    CREATED:   15.01.2007 00:45:32

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
// Temporary headers.
#include <Depth/todo/serialize/serialize.hpp>
/*--------------------------------------------------------------------------*/
// Common headers.
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/memory/allocators/CAllocatorNewEx.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NMemory::NAllocators;
using namespace NDepth::NSerialization;
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
  CTestClass(const Tuint)
  { CALL
    ++the_Counter;
  }
 ~CTestClass()
  { CALL
    --the_Counter;
  }
};
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CAllocatorNewEx allocator;

    // Allocate one instance.
    CTestClass* test1 = allocator.createOne<CTestClass>();
    UT_ASSERT_VALID_PTR(test1);
    UT_ASSERT_EQUAL(the_Counter, 1);

    // Allocate many instances.
    CTestClass* test2 = allocator.createMany<CTestClass>(1000, 20);
    UT_ASSERT_VALID_PTR(test2);
    UT_ASSERT_EQUAL(the_Counter, 1001);

    // Delete instances.
    UT_ASSERT(allocator.deleteOne(test1));
    UT_ASSERT_EQUAL(the_Counter, 1000);
    UT_ASSERT(allocator.deleteMany(test2, 1000));
    UT_ASSERT_EQUAL(the_Counter, 0);

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CAllocatorNewEx instance;

    // Save instance.
    SaveArchive saver;
    UT_ASSERT(saver.open());
    UT_ASSERT(saver.serialize(instance));
    UT_ASSERT(saver.close());

    // Load instance.
    LoadArchive loader;
    UT_ASSERT(loader.open());
    UT_ASSERT(loader.serialize(instance));
    UT_ASSERT(loader.close());
  }
} the_Test;
/*==========================================================================*/
