/*!
 *  \file    test-containers-CListDL.cpp Testing of the CListDL class.
 *  \brief   Testing of the CListDL class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.02.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CListDL class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   11.02.2007 01:25:37

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
#include <Depth/include/containers/CListDL.hpp>
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
    CListDL<Tsint> a;
    CListDL<Tsint> b;
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
    CListDL<Tsint> c(a);
    CListDL<Tsint> d(b);
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

  // Check the fill functionality of the CListDL<Tsint>.
  void UT_ASSERT_CHECK_FILL(CListDL<Tsint>& a_rListDL, const Tbool a_cDirectOrder)
  { CALL
    UT_ASSERT(a_cDirectOrder ? a_rListDL.insertFirst(6) : a_rListDL.insertLast(1));
    UT_ASSERT(a_cDirectOrder ? a_rListDL.insertFirst(5) : a_rListDL.insertLast(2));
    UT_ASSERT(a_cDirectOrder ? a_rListDL.insertFirst(4) : a_rListDL.insertLast(3));
    UT_ASSERT(a_cDirectOrder ? a_rListDL.insertFirst(3) : a_rListDL.insertLast(4));
    UT_ASSERT(a_cDirectOrder ? a_rListDL.insertFirst(2) : a_rListDL.insertLast(5));
    UT_ASSERT(a_cDirectOrder ? a_rListDL.insertFirst(1) : a_rListDL.insertLast(6));
  }

  // Check the show functionality of the CListDL<Tsint>.
  void UT_ASSERT_CHECK_SHOW(const CListDL<Tsint>& a_crListDL, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 1 : 6);
    CListDL<Tsint>::TIteratorConst it = (a_cDirectOrder ? a_crListDL.getItFirst() : a_crListDL.getItLast());
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

  // Check the show reversed functionality of the CListDL<Tsint>.
  void UT_ASSERT_CHECK_SHOW_REVERSED(const CListDL<Tsint>& a_crListDL, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 6 : 1);
    CListDL<Tsint>::TIteratorConst it = (a_cDirectOrder ? a_crListDL.getItFirst() : a_crListDL.getItLast());
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        (a_cDirectOrder) ? --value : ++value;
      } while ((a_cDirectOrder ? it.stepForward() : it.stepBackward()) == 1);
    }
    UT_ASSERT_EQUAL(value, (a_cDirectOrder) ? 0 : 7);
  }

  // Check the remove functionality of the CListDL<Tsint>.
  void UT_ASSERT_CHECK_REMOVE(CListDL<Tsint>& a_rListDL, Tbool a_cDirectOrder, const Tbool a_cReversed = false)
  { CALL
    Tsint value = (a_cDirectOrder || a_cReversed) ? 1 : 6;
    CListDL<Tsint>::TIterator it = (a_cDirectOrder ? a_rListDL.getItFirst() : a_rListDL.getItLast());
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
    CListDL<Tsint> instance;

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
