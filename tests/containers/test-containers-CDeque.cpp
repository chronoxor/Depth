/*!
 *  \file    test-containers-CDeque.cpp Testing of the CDeque class.
 *  \brief   Testing of the CDeque class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.02.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CDeque class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   10.02.2007 21:12:52

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
#include <Depth/include/containers/CDeque.hpp>
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
    CDeque<Tsint> a;
    CDeque<Tsint> b;
    UT_ASSERT_ZERO(a.getSize());
    UT_ASSERT_ZERO(b.getSize());

    // Fill the first deque.
    UT_ASSERT_CHECK_FILL(a, true);
    UT_ASSERT_EQUAL(a.getSize(), 6);
    // Fill the second deque.
    UT_ASSERT_CHECK_FILL(b, false);
    UT_ASSERT_EQUAL(b.getSize(), 6);

    // Show the first deque.
    UT_ASSERT_CHECK_SHOW(a, true);
    // Show the second deque.
    UT_ASSERT_CHECK_SHOW(b, false);

    // Copy deques.
    CDeque<Tsint> c(a);
    CDeque<Tsint> d(b);
    UT_ASSERT_EQUAL(c.getSize(), 6);
    UT_ASSERT_EQUAL(d.getSize(), 6);

    // Reverse deques.
    c.reverse();
    d.reverse();

    // Show the first reversed deque.
    UT_ASSERT_CHECK_SHOW_REVERSED(c, true);
    // Show the last reversed deque.
    UT_ASSERT_CHECK_SHOW_REVERSED(d, false);

    // Remove items from the first deque.
    UT_ASSERT_CHECK_REMOVE(a, true);
    UT_ASSERT_ZERO(a.getSize());
    // Remove items from the second deque.
    UT_ASSERT_CHECK_REMOVE(b, false);
    UT_ASSERT_ZERO(b.getSize());

    // Clear the first reversed deque.
    UT_ASSERT(c.clear());
    UT_ASSERT_ZERO(c.getSize());
    // Clear the second reversed deque.
    UT_ASSERT(d.clear());
    UT_ASSERT_ZERO(d.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CDeque<Tsint>.
  void UT_ASSERT_CHECK_FILL(CDeque<Tsint>& a_rDeque, const Tbool a_cDirectOrder)
  { CALL
    UT_ASSERT(a_cDirectOrder ? a_rDeque.insertFirst(6) : a_rDeque.insertLast(1));
    UT_ASSERT(a_cDirectOrder ? a_rDeque.insertFirst(5) : a_rDeque.insertLast(2));
    UT_ASSERT(a_cDirectOrder ? a_rDeque.insertFirst(4) : a_rDeque.insertLast(3));
    UT_ASSERT(a_cDirectOrder ? a_rDeque.insertFirst(3) : a_rDeque.insertLast(4));
    UT_ASSERT(a_cDirectOrder ? a_rDeque.insertFirst(2) : a_rDeque.insertLast(5));
    UT_ASSERT(a_cDirectOrder ? a_rDeque.insertFirst(1) : a_rDeque.insertLast(6));
  }

  // Check the show functionality of the CDeque<Tsint>.
  void UT_ASSERT_CHECK_SHOW(const CDeque<Tsint>& a_crDeque, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 1 : 6);
    CDeque<Tsint>::TIteratorConst it = (a_cDirectOrder ? a_crDeque.getItFirst() : a_crDeque.getItLast());
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        (a_cDirectOrder) ? ++value : --value;
      } while ((a_cDirectOrder ? it.stepForward() : it.stepBackward()) == 1);
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder) ? 7 : 0));
  }

  // Check the show reversed functionality of the CDeque<Tsint>.
  void UT_ASSERT_CHECK_SHOW_REVERSED(const CDeque<Tsint>& a_crDeque, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 6 : 1);
    CDeque<Tsint>::TIteratorConst it = (a_cDirectOrder ? a_crDeque.getItFirst() : a_crDeque.getItLast());
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        (a_cDirectOrder) ? --value : ++value;
      } while ((a_cDirectOrder ? it.stepForward() : it.stepBackward()) == 1);
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder) ? 0 : 7));
  }

  // Check the remove functionality of the CDeque<Tsint>.
  void UT_ASSERT_CHECK_REMOVE(CDeque<Tsint>& a_rDeque, Tbool a_cDirectOrder, const Tbool a_cReversed = false)
  { CALL
    Tsint value = (a_cDirectOrder || a_cReversed) ? 1 : 6;
    CDeque<Tsint>::TIterator it = (a_cDirectOrder ? a_rDeque.getItFirst() : a_rDeque.getItLast());
    while (it.isValid())
    {
      UT_ASSERT_EQUAL(*it, value);
      (a_cDirectOrder || a_cReversed) ? ++value : --value;
      UT_ASSERT(a_cDirectOrder ? it.removeForward() : it.removeBackward());
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder || a_cReversed) ? 7 : 0));
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CDeque<Tsint> instance;

    // Fill the deque.
    UT_ASSERT_CHECK_FILL(instance, true);

    // Show the deque before serialization.
    UT_ASSERT_CHECK_SHOW(instance, true);

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

    // Show the deque after serialization.
    UT_ASSERT_CHECK_SHOW(instance, true);
  }
} the_Test;
/*==========================================================================*/
