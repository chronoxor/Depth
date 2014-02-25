/*!
 *  \file    test-memory-GC.cpp Testing of the garbage collection
 *           functionality.
 *  \brief   Testing of the garbage collection functionality.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the garbage collection functionality.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth memory tests
    VERSION:   1.0
    CREATED:   25.06.2007 02:06:42

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
#include <Depth/include/memory/gc/CGCPtr.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NMemory;
/*==========================================================================*/
class A
{
public:
  A() { CALL }
  virtual ~A() { CALL }
};
/*--------------------------------------------------------------------------*/
class B :
  virtual public A
{
public:
  B() { CALL }
  virtual ~B() { CALL }
};
/*--------------------------------------------------------------------------*/
class C :
  virtual public A
{
public:
  C() { CALL }
  virtual ~C() { CALL }
};
/*--------------------------------------------------------------------------*/
class D :
  public B,
  public C
{
public:
  D() { CALL }
  virtual ~D() { CALL }
};
/*--------------------------------------------------------------------------*/
class circle
{
public:
  circle() { CALL }
 ~circle() { CALL }

  CGCPtr<circle> ptr;
};
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    Tuint old_alloc_blocks = CMemory::getGCAllocatedBlocks();
    Tuint old_alloc_size = CMemory::getGCAllocatedSize();

    // Enable GC.
    Tbool enable = false;
    if (!CMemory::isGCEnabled())
    {
      UT_ASSERT(CMemory::enableGC());
    }

    // Line hierarchy.
    {
      CGCPtr<A> ptr1 = newex D();
      CGCPtr<B> ptr2 = newex D();
      CGCPtr<C> ptr3 = NAlgorithms::NCommon::dynamicCast<C*, A*>(ptr1);

      UT_ASSERT_EQUAL(CMemory::getGCAllocatedBlocks(), 2);
    }

    // Circle hierarchy.
    {
      CGCPtr<circle> ptr1 = newex circle();
      CGCPtr<circle> ptr2 = newex circle();
      CGCPtr<circle> ptr3 = newex circle();

      ptr1->ptr = ptr2;
      ptr2->ptr = ptr3;
      ptr3->ptr = ptr1;

      UT_ASSERT_EQUAL(CMemory::getGCAllocatedBlocks(), 5);
    }

    // Perform GC.
    UT_ASSERT(CMemory::performGC());

    // Disable GC.
    if (enable)
    {
      UT_ASSERT(CMemory::disableGC());
    }

    UT_ASSERT_EQUAL(old_alloc_blocks, CMemory::getGCAllocatedBlocks());
    UT_ASSERT_EQUAL(old_alloc_size, CMemory::getGCAllocatedSize());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
