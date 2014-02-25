/*!
 *  \file    test-containers-CStack.cpp Testing of the CStack class.
 *  \brief   Testing of the CStack class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.02.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CStack class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   07.02.2007 21:53:22

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
#include <Depth/include/containers/CStack.hpp>
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
    CStack<Tsint> a;
    UT_ASSERT_ZERO(a.getSize());

    // Fill the stack.
    UT_ASSERT_CHECK_FILL(a);
    UT_ASSERT_EQUAL(a.getSize(), 6);

    // Show the stack.
    UT_ASSERT_CHECK_SHOW(a, true);

    // Copy the stack.
    CStack<Tsint> b(a);
    UT_ASSERT_EQUAL(b.getSize(), 6);

    // Reverse the stack.
    b.reverse();

    // Show the reversed stack.
    UT_ASSERT_CHECK_SHOW(b, false);

    // Remove items from the stack.
    UT_ASSERT_CHECK_REMOVE(a, true);
    UT_ASSERT_ZERO(a.getSize());

    // Clear the reversed stack.
    UT_ASSERT(b.clear());
    UT_ASSERT_ZERO(b.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CStack<Tsint>.
  void UT_ASSERT_CHECK_FILL(CStack<Tsint>& a_rStack)
  { CALL
    UT_ASSERT(a_rStack.insertTop(1));
    UT_ASSERT(a_rStack.insertTop(2));
    UT_ASSERT(a_rStack.insertTop(3));
    UT_ASSERT(a_rStack.insertTop(4));
    UT_ASSERT(a_rStack.insertTop(5));
    UT_ASSERT(a_rStack.insertTop(6));
  }

  // Check the show functionality of the CStack<Tsint>.
  void UT_ASSERT_CHECK_SHOW(const CStack<Tsint>& a_crStack, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 6 : 1);
    CStack<Tsint>::TIteratorConst it = a_crStack.getItTop();
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        (a_cDirectOrder) ? --value : ++value;
      } while (it.stepForward() == 1);
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder) ? 0 : 7));
  }

  // Check the remove functionality of the CStack<Tsint>.
  void UT_ASSERT_CHECK_REMOVE(CStack<Tsint>& a_rStack, Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 6 : 1);
    CStack<Tsint>::TIterator it = a_rStack.getItTop();
    while (it.isValid())
    {
      UT_ASSERT_EQUAL(*it, value);
      (a_cDirectOrder) ? --value : ++value;
      UT_ASSERT(it.removeForward());
    }
    UT_ASSERT_EQUAL(value, ((a_cDirectOrder) ? 0 : 7));
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CStack<Tsint> instance;

    // Fill the stack.
    UT_ASSERT_CHECK_FILL(instance);

    // Show the stack before serialization.
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

    // Show the stack after serialization.
    UT_ASSERT_CHECK_SHOW(instance, true);
  }
} the_Test;
/*==========================================================================*/
