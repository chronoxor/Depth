/*!
 *  \file    test-containers-CWrappedArray.cpp Testing of the CWrappedArray 
 *           class.
 *  \brief   Testing of the CWrappedArray class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CWrappedArray class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   23.04.2007 22:42:46

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
#include <Depth/include/containers/CWrappedArray.hpp>
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
    CWrappedArray<Tsint> a;
    CWrappedArray<Tsint> b;
    UT_ASSERT_ZERO(a.getSize());
    UT_ASSERT_ZERO(b.getSize());

    // Fill the first array.
    UT_ASSERT_CHECK_FILL(a);
    // Fill the second array.
    UT_ASSERT_CHECK_FILL(b);

    // Show the first array.
    UT_ASSERT_CHECK_SHOW(a, true);
    // Show the second array.
    UT_ASSERT_CHECK_SHOW(b, false);

    // Copy array.
    CWrappedArray<Tsint> c(a);
    UT_ASSERT_EQUAL(c.getSize(), 6);

    // Reverse array.
    c.reverse();

    // Show the reversed array.
    UT_ASSERT_CHECK_SHOW_REVERSED(c, true);

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CWrappedArray<Tsint>.
  void UT_ASSERT_CHECK_FILL(CWrappedArray<Tsint>& a_rArray)
  { CALL
    static Tsint array[] = { 1, 2, 3, 4, 5, 6 };

    UT_ASSERT(a_rArray.set(array));
  }

  // Check the show functionality of the CWrappedArray<Tsint>.
  void UT_ASSERT_CHECK_SHOW(const CWrappedArray<Tsint>& a_crArray, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 1 : 6);
    CWrappedArray<Tsint>::TIteratorConst it = (a_cDirectOrder ? a_crArray.getItFirst() : a_crArray.getItLast());
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

  // Check the show reversed functionality of the CWrappedArray<Tsint>.
  void UT_ASSERT_CHECK_SHOW_REVERSED(const CWrappedArray<Tsint>& a_crArray, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 6 : 1);
    CWrappedArray<Tsint>::TIteratorConst it = (a_cDirectOrder ? a_crArray.getItFirst() : a_crArray.getItLast());
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

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CWrappedArray<Tsint> instance;

    // Fill the array.
    UT_ASSERT_CHECK_FILL(instance);

    // Show the array before serialization.
    UT_ASSERT_CHECK_SHOW_REVERSED(instance, true);

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

    // Show the array after serialization.
    UT_ASSERT_CHECK_SHOW_REVERSED(instance, true);
  }
} the_Test;
/*==========================================================================*/
