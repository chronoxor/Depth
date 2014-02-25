/*!
 *  \file    test-containers-CListSL.cpp Testing of the CListSL class.
 *  \brief   Testing of the CListSL class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.02.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CListSL class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   10.02.2007 20:43:58

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
#include <Depth/include/containers/CListSL.hpp>
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
    CListSL<Tsint> a;
    UT_ASSERT_ZERO(a.getSize());

    // Fill the single linked list.
    UT_ASSERT_CHECK_FILL(a);
    UT_ASSERT_EQUAL(a.getSize(), 6);

    // Show the single linked list.
    UT_ASSERT_CHECK_SHOW(a, true);

    // Copy the single linked list.
    CListSL<Tsint> b(a);
    UT_ASSERT_EQUAL(b.getSize(), 6);

    // Reverse the single linked list.
    b.reverse();

    // Show the reversed single linked list.
    UT_ASSERT_CHECK_SHOW(b, false);

    // Remove items from the single linked list.
    UT_ASSERT_CHECK_REMOVE(a, true);
    UT_ASSERT_ZERO(a.getSize());

    // Clear the reversed single linked list.
    UT_ASSERT(b.clear());
    UT_ASSERT_ZERO(b.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CListSL<Tsint>.
  void UT_ASSERT_CHECK_FILL(CListSL<Tsint>& a_rListSL)
  { CALL
    UT_ASSERT(a_rListSL.insertLast(1));
    UT_ASSERT(a_rListSL.insertLast(2));
    UT_ASSERT(a_rListSL.insertLast(3));
    UT_ASSERT(a_rListSL.insertLast(4));
    UT_ASSERT(a_rListSL.insertLast(5));
    UT_ASSERT(a_rListSL.insertLast(6));
  }

  // Check the show functionality of the CListSL<Tsint>.
  void UT_ASSERT_CHECK_SHOW(const CListSL<Tsint>& a_crListSL, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 1 : 6);
    CListSL<Tsint>::TIteratorConst it = a_crListSL.getItFirst();
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        (a_cDirectOrder) ? ++value : --value;
      } while (it.stepForward() == 1);
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder) ? 7 : 0));
  }

  // Check the remove functionality of the CListSL<Tsint>.
  void UT_ASSERT_CHECK_REMOVE(CListSL<Tsint>& a_rListSL, Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 1 : 6);
    CListSL<Tsint>::TIterator it = a_rListSL.getItFirst();
    while (it.isValid())
    {
      UT_ASSERT_EQUAL(*it, value);
      (a_cDirectOrder) ? ++value : --value;
      UT_ASSERT(it.removeForward());
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder) ? 7 : 0));
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CListSL<Tsint> instance;

    // Fill the single linked list.
    UT_ASSERT_CHECK_FILL(instance);

    // Show the single linked list before serialization.
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

    // Show the single linked list after serialization.
    UT_ASSERT_CHECK_SHOW(instance, true);
  }
} the_Test;
/*==========================================================================*/
