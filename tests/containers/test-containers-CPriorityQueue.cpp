/*!
 *  \file    test-containers-CPriorityQueue.cpp Testing of the 
 *           CPriorityQueue class.
 *  \brief   Testing of the CPriorityQueue class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CPriorityQueue class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   07.05.2007 20:15:42

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
#include <Depth/include/containers/CPriorityQueue.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NContainers;
using namespace NDepth::NSerialization;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CPriorityQueue<Tschar> a;
    UT_ASSERT_ZERO(a.getSize());

    // Fill the first priority queue.
    UT_ASSERT_CHECK_FILL(a);
    UT_ASSERT_EQUAL(a.getSize(), 9);

    // Show the first priority queue.
    UT_ASSERT_CHECK_SHOW(a);

    // Copy priority queues.
    CPriorityQueue<Tschar> b(a);
    UT_ASSERT_EQUAL(b.getSize(), 9);

    // Show the second priority queue.
    UT_ASSERT_CHECK_SHOW(b);

    // Remove items from the first priority queue.
    UT_ASSERT_CHECK_REMOVE(a);
    UT_ASSERT_ZERO(a.getSize());

    // Clear the second priority queue.
    UT_ASSERT(b.clear());
    UT_ASSERT_ZERO(b.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CPriorityQueue<Tschar>.
  void UT_ASSERT_CHECK_FILL(CPriorityQueue<Tschar>& a_rPriorityQueue)
  { CALL
    UT_ASSERT(a_rPriorityQueue.insert(ASC('F'), 6));
    UT_ASSERT(a_rPriorityQueue.insert(ASC('C'), 3));
    UT_ASSERT(a_rPriorityQueue.insert(ASC('G'), 7));
    UT_ASSERT(a_rPriorityQueue.insert(ASC('B'), 2));
    UT_ASSERT(a_rPriorityQueue.insert(ASC('H'), 8));
    UT_ASSERT(a_rPriorityQueue.insert(ASC('A'), 1));
    UT_ASSERT(a_rPriorityQueue.insert(ASC('D'), 4));
    UT_ASSERT(a_rPriorityQueue.insert(ASC('I'), 9));
    UT_ASSERT(a_rPriorityQueue.insert(ASC('E'), 5));
  }

  // Check the show functionality of the CPriorityQueue<Tschar>.
  void UT_ASSERT_CHECK_SHOW(const CPriorityQueue<Tschar>& a_crPriorityQueue)
  { CALL
    Tuint priority = 1;
    Tschar value = ASC('A');
    CPriorityQueue<Tschar>::TIteratorConst it = a_crPriorityQueue.getItLast();
    if (it.isValid())
    {
      do
      {
        UT_ASSERT((it.getPriorityRef() == priority++) && (*it == value++));
      } while (it.stepBackward() == 1);
    }
    UT_ASSERT((priority == 10) && (value == ASC('J')));
  }

  // Check the remove functionality of the CPriorityQueue<Tschar>.
  void UT_ASSERT_CHECK_REMOVE(CPriorityQueue<Tschar>& a_rPriorityQueue)
  { CALL
    Tuint priority = 1;
    Tschar value = ASC('A');
    CPriorityQueue<Tschar>::TIterator it = a_rPriorityQueue.getItLast();
    while (it.isValid())
    {
      UT_ASSERT((it.getPriorityRef() == priority++) && (*it == value++));
      UT_ASSERT(it.remove());
    }
    UT_ASSERT((priority == 10) && (value == ASC('J')));
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CPriorityQueue<Tschar> instance;

    // Fill the priority queue.
    UT_ASSERT_CHECK_FILL(instance);

    // Show the priority queue before serialization.
    UT_ASSERT_CHECK_SHOW(instance);

    // Save instance.
    SaveArchive saver;
    UT_ASSERT(saver.open());
    UT_ASSERT(saver.serialize(instance));
    UT_ASSERT(saver.close());

    // Clear instance.
    UT_ASSERT(instance.clear());

    // Load instance.
    LoadArchive loader;
    UT_ASSERT(loader.open());
    UT_ASSERT(loader.serialize(instance));
    UT_ASSERT(loader.close());

    // Show the priority queue after serialization.
    UT_ASSERT_CHECK_SHOW(instance);
  }
} the_Test;
/*==========================================================================*/
