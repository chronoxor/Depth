/*!
 *  \file    test-containers-CBinTreeAA.cpp Testing of the CBinTreeAA class.
 *  \brief   Testing of the CBinTreeAA class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CBinTreeAA class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   24.03.2007 20:45:01

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
#include <Depth/include/containers/CBinTreeAA.hpp>
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
    CBinTreeAA<Tsint> a;
    UT_ASSERT_ZERO(a.getSize());

    // Fill the first binary tree.
    UT_ASSERT_CHECK_FILL(a);
    UT_ASSERT_EQUAL(a.getSize(), 18);

    // Show the first binary tree.
    UT_ASSERT_CHECK_SHOW(a);

    // Copy binary trees.
    CBinTreeAA<Tsint> b(a);
    UT_ASSERT_EQUAL(b.getSize(), 18);

    // Show the second binary tree.
    UT_ASSERT_CHECK_SHOW(b);

    // Remove items from the first binary tree.
    UT_ASSERT_CHECK_REMOVE(a);
    UT_ASSERT_ZERO(a.getSize());

    // Clear the second binary tree.
    UT_ASSERT(b.clear());
    UT_ASSERT_ZERO(b.getSize());

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CBinTreeAA<Tsint>.
  void UT_ASSERT_CHECK_FILL(CBinTreeAA<Tsint>& a_rBinTree)
  { CALL
    UT_ASSERT(a_rBinTree.insert(6));
    UT_ASSERT(a_rBinTree.insert(3));
    UT_ASSERT(a_rBinTree.insert(7));
    UT_ASSERT(a_rBinTree.insert(2));
    UT_ASSERT(a_rBinTree.insert(8));
    UT_ASSERT(a_rBinTree.insert(1));
    UT_ASSERT(a_rBinTree.insert(4));
    UT_ASSERT(a_rBinTree.insert(9));
    UT_ASSERT(a_rBinTree.insert(5));
    UT_ASSERT(a_rBinTree.insert(6));
    UT_ASSERT(a_rBinTree.insert(3));
    UT_ASSERT(a_rBinTree.insert(7));
    UT_ASSERT(a_rBinTree.insert(2));
    UT_ASSERT(a_rBinTree.insert(8));
    UT_ASSERT(a_rBinTree.insert(1));
    UT_ASSERT(a_rBinTree.insert(4));
    UT_ASSERT(a_rBinTree.insert(9));
    UT_ASSERT(a_rBinTree.insert(5));
  }

  // Check the show functionality of the CBinTreeAA<Tsint>.
  void UT_ASSERT_CHECK_SHOW(const CBinTreeAA<Tsint>& a_crBinTree)
  { CALL
    Tsint step = 0;
    Tsint value = 1;
    CBinTreeAA<Tsint>::TIteratorConst it = a_crBinTree.getItFirst();
    if (it.isValid())
    {
      do
      {
        ++step;
        UT_ASSERT_EQUAL(*it, value);
        if (step == 2)
        {
          step = 0;
          ++value;
        }
      } while (it.stepForward() == 1);
    }
    UT_ASSERT_EQUAL(value, 10);
  }

  // Check the remove functionality of the CBinTreeAA<Tsint>.
  void UT_ASSERT_CHECK_REMOVE(CBinTreeAA<Tsint>& a_rBinTree)
  { CALL
    Tsint step = 0;
    Tsint value = 1;
    CBinTreeAA<Tsint>::TIterator it = a_rBinTree.getItFirst();
    while (it.isValid())
    {
      ++step;
      UT_ASSERT_EQUAL(*it, value);
      if (step == 2)
      {
        step = 0;
        ++value;
      }
      UT_ASSERT(it.remove());
    }
    UT_ASSERT_EQUAL(value, 10);
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CBinTreeAA<Tsint> instance;

    // Fill the binary tree.
    UT_ASSERT_CHECK_FILL(instance);

    // Show the binary tree before serialization.
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

    // Show the binary tree after serialization.
    UT_ASSERT_CHECK_SHOW(instance);
  }
} the_Test;
/*==========================================================================*/
