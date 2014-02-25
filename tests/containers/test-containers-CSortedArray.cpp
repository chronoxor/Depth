/*!
 *  \file    test-containers-CSortedArray.cpp Testing of the CSortedArray 
 *           class.
 *  \brief   Testing of the CSortedArray class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CSortedArray class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   19.03.2007 01:24:52

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
#include <Depth/include/base/CInteger.hpp>
#include <Depth/include/containers/CSortedArray.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NBase;
using namespace NDepth::NContainers;
using namespace NDepth::NSerialization;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CSortedArray<CInteger<Tsint> > a;
    UT_ASSERT_ZERO(a.getSize());

    // Fill the first array.
    UT_ASSERT_CHECK_FILL(a);
    UT_ASSERT_EQUAL(a.getSize(), 18);

    // Show the first array.
    UT_ASSERT_CHECK_SHOW(a);

    // Copy arrays.
    CSortedArray<CInteger<Tsint> > b(a);
    UT_ASSERT_EQUAL(b.getSize(), 18);

    // Show the second array.
    UT_ASSERT_CHECK_SHOW(b);

    // Remove items from the first array.
    UT_ASSERT_CHECK_REMOVE(a);
    UT_ASSERT_ZERO(a.getSize());

    // Clear the second array.
    UT_ASSERT(b.clear());
    UT_ASSERT_ZERO(b.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CSortedArray<CInteger<Tsint> >.
  void UT_ASSERT_CHECK_FILL(CSortedArray<CInteger<Tsint> >& a_rArray)
  { CALL
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(6)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(3)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(7)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(2)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(8)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(1)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(4)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(9)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(5)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(6)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(3)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(7)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(2)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(8)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(1)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(4)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(9)));
    UT_ASSERT(a_rArray.insert(CInteger<Tsint>(5)));
  }

  // Check the show functionality of the CSortedArray<CInteger<Tsint> >.
  void UT_ASSERT_CHECK_SHOW(const CSortedArray<CInteger<Tsint> >& a_crArray)
  { CALL
    Tsint step = 0;
    Tsint value = 1;
    CSortedArray<CInteger<Tsint> >::TIteratorConst it = a_crArray.getItFirst();
    if (it.isValid())
    {
      do
      {
        ++step;
        UT_ASSERT_EQUAL((*it).getValue(), value);
        if (step == 2)
        {
          step = 0;
          ++value;
        }
      } while (it.stepForward() == 1);
    }
    UT_ASSERT_EQUAL(value, 10);
  }

  // Check the remove functionality of the CSortedArray<CInteger<Tsint> >.
  void UT_ASSERT_CHECK_REMOVE(CSortedArray<CInteger<Tsint> >& a_rArray)
  { CALL
    Tsint step = 0;
    Tsint value = 1;
    CSortedArray<CInteger<Tsint> >::TIterator it = a_rArray.getItFirst();
    while (it.isValid())
    {
      ++step;
      UT_ASSERT_EQUAL((*it).getValue(), value);
      if (step == 2)
      {
        step = 0;
        ++value;
      }
      UT_ASSERT(it.removeForward());
    }
    UT_ASSERT_EQUAL(value, 10);
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CSortedArray<CInteger<Tsint> > instance;

    // Fill the array.
    UT_ASSERT_CHECK_FILL(instance);

    // Show the array before serialization.
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

    // Show the array after serialization.
    UT_ASSERT_CHECK_SHOW(instance);
  }
} the_Test;
/*==========================================================================*/
