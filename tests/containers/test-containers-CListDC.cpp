/*!
 *  \file    test-containers-CListDC.cpp Testing of the CListDC class.
 *  \brief   Testing of the CListDC class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.02.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CListDC class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   11.02.2007 03:48:36

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
#include <Depth/include/containers/CListDC.hpp>
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
    CListDC<Tsint> a;
    CListDC<Tsint> b;
    UT_ASSERT_ZERO(a.getSize());
    UT_ASSERT_ZERO(b.getSize());

    // Fill the first double linked list.
    UT_ASSERT_CHECK_FILL(a, true);
    UT_ASSERT_EQUAL(a.getSize(), 6);
    // Fill the second double linked list.
    UT_ASSERT_CHECK_FILL(b, false);
    UT_ASSERT_EQUAL(b.getSize(), 6);

    // Show the first double linked list.
    UT_ASSERT_CHECK_SHOW(a, true);
    // Show the second double linked list.
    UT_ASSERT_CHECK_SHOW(b, false);

    // Copy double linked lists.
    CListDC<Tsint> c(a);
    CListDC<Tsint> d(b);
    UT_ASSERT_EQUAL(c.getSize(), 6);
    UT_ASSERT_EQUAL(d.getSize(), 6);

    // Reverse double linked lists.
    c.reverse();
    d.reverse();

    // Show the first reversed double linked list.
    UT_ASSERT_CHECK_SHOW_REVERSED(c, true);
    // Show the last reversed double linked list.
    UT_ASSERT_CHECK_SHOW_REVERSED(d, false);

    // Remove items from the first double linked list.
    UT_ASSERT_CHECK_REMOVE(a, true);
    UT_ASSERT_ZERO(a.getSize());
    // Remove items from the second double linked list.
    UT_ASSERT_CHECK_REMOVE(b, false);
    UT_ASSERT_ZERO(b.getSize());

    // Clear the first reversed double linked list.
    UT_ASSERT(c.clear());
    UT_ASSERT_ZERO(c.getSize());
    // Clear the second reversed double linked list.
    UT_ASSERT(d.clear());
    UT_ASSERT_ZERO(d.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CListDC<Tsint>.
  void UT_ASSERT_CHECK_FILL(CListDC<Tsint>& a_rListDC, const Tbool a_cDirectOrder)
  { CALL
    UT_ASSERT(a_cDirectOrder ? a_rListDC.insertCurrentForward(6) : a_rListDC.insertCurrentBackward(1));
    UT_ASSERT(a_cDirectOrder ? a_rListDC.insertCurrentForward(5) : a_rListDC.insertCurrentBackward(2));
    UT_ASSERT(a_cDirectOrder ? a_rListDC.insertCurrentForward(4) : a_rListDC.insertCurrentBackward(3));
    UT_ASSERT(a_cDirectOrder ? a_rListDC.insertCurrentForward(3) : a_rListDC.insertCurrentBackward(4));
    UT_ASSERT(a_cDirectOrder ? a_rListDC.insertCurrentForward(2) : a_rListDC.insertCurrentBackward(5));
    UT_ASSERT(a_cDirectOrder ? a_rListDC.insertCurrentForward(1) : a_rListDC.insertCurrentBackward(6));
  }

  // Check the show functionality of the CListDC<Tsint>.
  void UT_ASSERT_CHECK_SHOW(const CListDC<Tsint>& a_crListDC, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 1 : 6);
    CListDC<Tsint>::TIteratorConst it = a_crListDC.getItCurrent();
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        (a_cDirectOrder) ? ++value : --value;
      } while (((a_cDirectOrder ? it.stepForward() : it.stepBackward()) == 1) && (it != a_crListDC.getItCurrent()));
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder) ? 7 : 0));
  }

  // Check the show reversed functionality of the CListDC<Tsint>.
  void UT_ASSERT_CHECK_SHOW_REVERSED(const CListDC<Tsint>& a_crListDC, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 1 : 6);
    CListDC<Tsint>::TIteratorConst it = a_crListDC.getItCurrent();
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        (a_cDirectOrder) ? ++value : --value;
      } while (((a_cDirectOrder ? it.stepBackward() : it.stepForward()) == 1) && (it != a_crListDC.getItCurrent()));
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder) ? 7 : 0));
  }

  // Check the remove functionality of the CListDC<Tsint>.
  void UT_ASSERT_CHECK_REMOVE(CListDC<Tsint>& a_rListDC, Tbool a_cDirectOrder, const Tbool a_cReversed = false)
  { CALL
    Tsint value = (a_cDirectOrder || a_cReversed) ? 1 : 6;
    CListDC<Tsint>::TIterator it = a_rListDC.getItCurrent();
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
    CListDC<Tsint> instance;

    // Fill the double linked list.
    UT_ASSERT_CHECK_FILL(instance, true);

    // Show the double linked list before serialization.
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

    // Show the double linked list after serialization.
    UT_ASSERT_CHECK_SHOW(instance, true);
  }
} the_Test;
/*==========================================================================*/
