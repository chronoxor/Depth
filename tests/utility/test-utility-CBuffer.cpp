/*!
 *  \file    test-utility-CBuffer.cpp Testing of the CBuffer class.
 *  \brief   Testing of the CBuffer class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CBuffer class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth utility tests
    VERSION:   1.0
    CREATED:   20.08.2008 20:25:24

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
#include <Depth/include/utility/CBuffer.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NSerialization;
using namespace NDepth::NUtility;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CBuffer a;
    CBuffer b;
    UT_ASSERT_ZERO(a.getSize());
    UT_ASSERT_ZERO(b.getSize());

    // Fill the first byte buffer.
    UT_ASSERT_CHECK_FILL(a, true);
    UT_ASSERT_EQUAL(a.getSize(), 6);
    // Fill the second byte buffer.
    UT_ASSERT_CHECK_FILL(b, false);
    UT_ASSERT_EQUAL(b.getSize(), 6);

    // Show the first byte buffer.
    UT_ASSERT_CHECK_SHOW(a, true);
    // Show the second byte buffer.
    UT_ASSERT_CHECK_SHOW(b, false);

    // Copy buffers.
    CBuffer c(a);
    CBuffer d(b);
    UT_ASSERT_EQUAL(c.getSize(), 6);
    UT_ASSERT_EQUAL(d.getSize(), 6);

    // Show the first copied byte buffer.
    UT_ASSERT_CHECK_SHOW(c, true);
    // Show the last copied byte buffer.
    UT_ASSERT_CHECK_SHOW(d, false);

    // Remove items from the first byte buffer.
    UT_ASSERT_CHECK_REMOVE(a, true);
    UT_ASSERT_ZERO(a.getSize());
    // Remove items from the second byte buffer.
    UT_ASSERT_CHECK_REMOVE(b, false);
    UT_ASSERT_ZERO(b.getSize());

    // Clear the first reversed byte buffer.
    UT_ASSERT(c.clear());
    UT_ASSERT_ZERO(c.getSize());
    // Clear the second reversed byte buffer.
    UT_ASSERT(d.clear());
    UT_ASSERT_ZERO(d.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CBuffer.
  void UT_ASSERT_CHECK_FILL(CBuffer& a_rBuffer, const Tbool a_cDirectOrder)
  { CALL
    UT_ASSERT(a_cDirectOrder ? a_rBuffer.insertFirst(6) : a_rBuffer.insertLast(1));
    UT_ASSERT(a_cDirectOrder ? a_rBuffer.insertFirst(5) : a_rBuffer.insertLast(2));
    UT_ASSERT(a_cDirectOrder ? a_rBuffer.insertFirst(4) : a_rBuffer.insertLast(3));
    UT_ASSERT(a_cDirectOrder ? a_rBuffer.insertFirst(3) : a_rBuffer.insertLast(4));
    UT_ASSERT(a_cDirectOrder ? a_rBuffer.insertFirst(2) : a_rBuffer.insertLast(5));
    UT_ASSERT(a_cDirectOrder ? a_rBuffer.insertFirst(1) : a_rBuffer.insertLast(6));
  }

  // Check the show functionality of the CBuffer.
  void UT_ASSERT_CHECK_SHOW(const CBuffer& a_crBuffer, const Tbool a_cDirectOrder)
  { CALL
    Tsint value = (a_cDirectOrder ? 1 : 6);
    CBuffer::TIteratorConst it = (a_cDirectOrder ? a_crBuffer.getItFirst() : a_crBuffer.getItLast());
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

  // Check the remove functionality of the CBuffer.
  void UT_ASSERT_CHECK_REMOVE(CBuffer& a_rBuffer, Tbool a_cDirectOrder, const Tbool a_cReversed = false)
  { CALL
    Tsint value = (a_cDirectOrder || a_cReversed) ? 1 : 6;
    CBuffer::TIterator it = (a_cDirectOrder ? a_rBuffer.getItFirst() : a_rBuffer.getItLast());
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
    CBuffer instance;

    // Fill the byte buffer.
    UT_ASSERT_CHECK_FILL(instance, true);

    // Show the byte buffer before serialization.
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

    // Show the byte buffer after serialization.
    UT_ASSERT_CHECK_SHOW(instance, true);
  }
} the_Test;
/*==========================================================================*/
