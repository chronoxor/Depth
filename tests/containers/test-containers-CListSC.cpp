/*!
 *  \file    test-containers-CListSC.cpp Testing of the CListSC class.
 *  \brief   Testing of the CListSC class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.02.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CListSC class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   11.02.2007 00:12:28

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
#include <Depth/include/containers/CListSC.hpp>
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
    CListSC<Tsint> a;
    UT_ASSERT_ZERO(a.getSize());

    // Fill the single circled list.
    UT_ASSERT_CHECK_FILL(a);
    UT_ASSERT_EQUAL(a.getSize(), 6);

    // Show the single circled list.
    UT_ASSERT_CHECK_SHOW(a, true);

    // Copy the single circled list.
    CListSC<Tsint> b(a);
    UT_ASSERT_EQUAL(b.getSize(), 6);

    // Reverse the single circled list.
    b.reverse();

    // Show the reversed single circled list.
    UT_ASSERT(b.stepForward());
    UT_ASSERT_CHECK_SHOW(b, false);

    // Remove items from the single circled list.
    UT_ASSERT(a.stepForward(5));
    UT_ASSERT_CHECK_REMOVE(a, true);
    UT_ASSERT_ZERO(a.getSize());

    // Clear the reversed single circled list.
    UT_ASSERT(b.clear());
    UT_ASSERT_ZERO(b.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CListSC<Tsint>.
  void UT_ASSERT_CHECK_FILL(CListSC<Tsint>& a_rListSC)
  { CALL
    UT_ASSERT(a_rListSC.insertNext(6));
    UT_ASSERT(a_rListSC.insertNext(5));
    UT_ASSERT(a_rListSC.insertNext(4));
    UT_ASSERT(a_rListSC.insertNext(3));
    UT_ASSERT(a_rListSC.insertNext(2));
    UT_ASSERT(a_rListSC.insertNext(1));
    UT_ASSERT(a_rListSC.stepForward());
  }

  // Check the show functionality of the CListSC<Tsint>.
  void UT_ASSERT_CHECK_SHOW(const CListSC<Tsint>& a_crListSC, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 1 : 6);
    CListSC<Tsint>::TIteratorConst it = a_crListSC.getItCurrent();
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        (a_cDirectOrder) ? ++value : --value;
      } while ((it.stepForward() == 1) && (it != a_crListSC.getItCurrent()));
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder) ? 7 : 0));
  }

  // Check the remove functionality of the CListSC<Tsint>.
  void UT_ASSERT_CHECK_REMOVE(CListSC<Tsint>& a_rListSC, Tbool a_cDirectOrder)
  { CALL
    Tsint removed;
    Tsint value = (a_cDirectOrder ? 1 : 6);
    CListSC<Tsint>::TIterator it = a_rListSC.getItCurrent();
    while (it.isValid())
    {
      UT_ASSERT(it.removeNext(removed));
      UT_ASSERT_EQUAL(removed, value);
      (a_cDirectOrder) ? ++value : --value;
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder) ? 7 : 0));
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CListSC<Tsint> instance;

    // Fill the single circled list.
    UT_ASSERT_CHECK_FILL(instance);

    // Show the single circled list before serialization.
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

    // Show the single circled list after serialization.
    UT_ASSERT_CHECK_SHOW(instance, true);
  }
} the_Test;
/*==========================================================================*/
