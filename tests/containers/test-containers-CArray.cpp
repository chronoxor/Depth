/*!
 *  \file    test-containers-CArray.cpp Testing of the CArray class.
 *  \brief   Testing of the CArray class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.02.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CArray class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   14.02.2007 21:01:52

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
#include <Depth/include/containers/CArray.hpp>
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
    CArray<Tsint> a;
    CArray<Tsint> b;
    UT_ASSERT_ZERO(a.getSize());
    UT_ASSERT_ZERO(b.getSize());

    // Fill the first array.
    UT_ASSERT_CHECK_FILL(a, true);
    UT_ASSERT_EQUAL(a.getSize(), 6);
    // Fill the second array.
    UT_ASSERT_CHECK_FILL(b, false);
    UT_ASSERT_EQUAL(b.getSize(), 6);

    // Show the first array.
    UT_ASSERT_CHECK_SHOW(a, true);
    // Show the second array.
    UT_ASSERT_CHECK_SHOW(b, false);

    // Copy arrays.
    CArray<Tsint> c(a);
    CArray<Tsint> d(b);
    UT_ASSERT_EQUAL(c.getSize(), 6);
    UT_ASSERT_EQUAL(d.getSize(), 6);

    // Reverse arrays.
    c.reverse();
    d.reverse();

    // Show the first reversed array.
    UT_ASSERT_CHECK_SHOW_REVERSED(c, true);
    // Show the last reversed array.
    UT_ASSERT_CHECK_SHOW_REVERSED(d, false);

    // Remove items from the first array.
    UT_ASSERT_CHECK_REMOVE(a, true);
    UT_ASSERT_ZERO(a.getSize());
    // Remove items from the second array.
    UT_ASSERT_CHECK_REMOVE(b, false);
    UT_ASSERT_ZERO(b.getSize());

    // Clear the first reversed array.
    UT_ASSERT(c.clear());
    UT_ASSERT_ZERO(c.getSize());
    // Clear the second reversed array.
    UT_ASSERT(d.clear());
    UT_ASSERT_ZERO(d.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CArray<Tsint>.
  void UT_ASSERT_CHECK_FILL(CArray<Tsint>& a_rArray, const Tbool a_cDirectOrder)
  { CALL
    UT_ASSERT(a_cDirectOrder ? a_rArray.insertFirst(6) : a_rArray.insertLast(1));
    UT_ASSERT(a_cDirectOrder ? a_rArray.insertFirst(5) : a_rArray.insertLast(2));
    UT_ASSERT(a_cDirectOrder ? a_rArray.insertFirst(4) : a_rArray.insertLast(3));
    UT_ASSERT(a_cDirectOrder ? a_rArray.insertFirst(3) : a_rArray.insertLast(4));
    UT_ASSERT(a_cDirectOrder ? a_rArray.insertFirst(2) : a_rArray.insertLast(5));
    UT_ASSERT(a_cDirectOrder ? a_rArray.insertFirst(1) : a_rArray.insertLast(6));
  }

  // Check the show functionality of the CArray<Tsint>.
  void UT_ASSERT_CHECK_SHOW(const CArray<Tsint>& a_crArray, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 1 : 6);
    CArray<Tsint>::TIteratorConst it = (a_cDirectOrder ? a_crArray.getItFirst() : a_crArray.getItLast());
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        (a_cDirectOrder) ? ++value : --value;
      } while ((a_cDirectOrder ? it.stepForward() : it.stepBackward()) == 1);
    }
    UT_ASSERT_EQUAL(value, (a_cDirectOrder ? 7 : 0));
  }

  // Check the show reversed functionality of the CArray<Tsint>.
  void UT_ASSERT_CHECK_SHOW_REVERSED(const CArray<Tsint>& a_crArray, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 6 : 1);
    CArray<Tsint>::TIteratorConst it = (a_cDirectOrder ? a_crArray.getItFirst() : a_crArray.getItLast());
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        (a_cDirectOrder) ? --value : ++value;
      } while ((a_cDirectOrder ? it.stepForward() : it.stepBackward()) == 1);
    }
    UT_ASSERT_EQUAL(value, (a_cDirectOrder ? 0 : 7));
  }

  // Check the remove functionality of the CArray<Tsint>.
  void UT_ASSERT_CHECK_REMOVE(CArray<Tsint>& a_rArray, Tbool a_cDirectOrder, const Tbool a_cReversed = false)
  { CALL
    Tsint value = (a_cDirectOrder || a_cReversed) ? 1 : 6;
    CArray<Tsint>::TIterator it = (a_cDirectOrder ? a_rArray.getItFirst() : a_rArray.getItLast());
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
    CArray<Tsint> instance;

    // Fill the array.
    UT_ASSERT_CHECK_FILL(instance, true);

    // Show the array before serialization.
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

    // Show the array after serialization.
    UT_ASSERT_CHECK_SHOW(instance, true);
  }
} the_Test;
/*==========================================================================*/
