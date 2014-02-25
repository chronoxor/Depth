/*!
 *  \file    test-containers-CHashTableChain.cpp Testing of the 
 *           CHashTableChain class.
 *  \brief   Testing of the CHashTableChain class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CHashTableChain class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   17.06.2008 01:45:59

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
#include <Depth/include/containers/CHashTableChain.hpp>
#include <Depth/include/string/CSystemString.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NContainers;
using namespace NDepth::NSerialization;
using namespace NDepth::NString;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CHashTableChain<CSystemString, Tsint> a;
    UT_ASSERT_ZERO(a.getSize());
    UT_ASSERT_CHECK_SHOW(a, true, 0);
    UT_ASSERT_CHECK_SHOW(a, false, 0);

    // Fill the first hash table.
    UT_ASSERT_CHECK_FILL(a);
    UT_ASSERT_EQUAL(a.getSize(), 20);
    UT_ASSERT_CHECK_SHOW(a, true, 20);
    UT_ASSERT_CHECK_SHOW(a, false, 20);

    // Find items in the hash table.
    UT_ASSERT_CHECK_FIND(a);

    // Copy hash tables.
    CHashTableChain<CSystemString, Tsint> b(a);
    UT_ASSERT_EQUAL(b.getSize(), 20);
    UT_ASSERT_CHECK_SHOW(b, true, 20);
    UT_ASSERT_CHECK_SHOW(b, false, 20);

    // Remove single items.
    UT_ASSERT(a.remove(ASC("abc")));
    UT_ASSERT_EQUAL(a.getSize(), 19);
    UT_ASSERT(a.remove(ASC("abcd"), true));
    UT_ASSERT_EQUAL(a.getSize(), 17);

    // Remove items from the first hash table.
    UT_ASSERT_CHECK_REMOVE(a);
    UT_ASSERT_ZERO(a.getSize());
    UT_ASSERT_CHECK_SHOW(a, true, 0);
    UT_ASSERT_CHECK_SHOW(a, false, 0);

    // Clear the second hash table.
    UT_ASSERT(b.clear());
    UT_ASSERT_ZERO(b.getSize());
    UT_ASSERT_CHECK_SHOW(b, true, 0);
    UT_ASSERT_CHECK_SHOW(b, false, 0);

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the fill functionality of the CHashTableChain<CSystemString, Tsint>.
  void UT_ASSERT_CHECK_FILL(CHashTableChain<CSystemString, Tsint>& a_rHashTable)
  { CALL
    UT_ASSERT(a_rHashTable.insert(ASC("abc"), 1));
    UT_ASSERT(a_rHashTable.insert(ASC("abcd"), 2));
    UT_ASSERT(a_rHashTable.insert(ASC("abcde"), 3));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdef"), 4));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefg"), 5));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefgh"), 6));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefghj"), 7));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefghjk"), 8));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefghjkl"), 9));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefghjklm"), 10));
    UT_ASSERT(a_rHashTable.insert(ASC("abc"), 10));
    UT_ASSERT(a_rHashTable.insert(ASC("abcd"), 20));
    UT_ASSERT(a_rHashTable.insert(ASC("abcde"), 30));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdef"), 40));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefg"), 50));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefgh"), 60));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefghj"), 70));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefghjk"), 80));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefghjkl"), 90));
    UT_ASSERT(a_rHashTable.insert(ASC("abcdefghjklm"), 100));
  }

  // Check the find functionality of the CHashTableChain<CSystemString, Tsint>.
  void UT_ASSERT_CHECK_FIND(CHashTableChain<CSystemString, Tsint>& a_rHashTable)
  { CALL
    UT_ASSERT(a_rHashTable[ASC("abc")].getValueRef() == 1);
    UT_ASSERT(a_rHashTable[ASC("abcd")].getValueRef() == 2);
    UT_ASSERT(a_rHashTable[ASC("abcde")].getValueRef() == 3);
    UT_ASSERT(a_rHashTable[ASC("abcdef")].getValueRef() == 4);
    UT_ASSERT(a_rHashTable[ASC("abcdefg")].getValueRef() == 5);
    UT_ASSERT(a_rHashTable[ASC("abcdefgh")].getValueRef() == 6);
    UT_ASSERT(a_rHashTable[ASC("abcdefghj")].getValueRef() == 7);
    UT_ASSERT(a_rHashTable[ASC("abcdefghjk")].getValueRef() == 8);
    UT_ASSERT(a_rHashTable[ASC("abcdefghjkl")].getValueRef() == 9);
    UT_ASSERT(a_rHashTable[ASC("abcdefghjklm")].getValueRef() == 10);
  }

  // Check the show functionality of the CHashTableChain<CSystemString, Tsint>.
  void UT_ASSERT_CHECK_SHOW(const CHashTableChain<CSystemString, Tsint>& a_crHashTable, const Tbool a_cDirectOrder, const Tuint a_cCount)
  { CALL
    Tuint count = 0;
    CHashTableChain<CSystemString, Tsint>::TIteratorConst it = a_cDirectOrder ? a_crHashTable.getItFirst() : a_crHashTable.getItLast();
    if (it.isValid())
    {
      do
      {
        ++count;
      } while ((a_cDirectOrder ? it.stepForward() : it.stepBackward()) == 1);
    }
    UT_ASSERT_EQUAL(count, a_cCount);
  }

  // Check the remove functionality of the CHashTableChain<CSystemString, Tsint>.
  void UT_ASSERT_CHECK_REMOVE(CHashTableChain<CSystemString, Tsint>& a_rHashTable)
  { CALL
    CHashTableChain<CSystemString, Tsint>::TIterator it = a_rHashTable.getItFirst();
    while (it.isValid())
      UT_ASSERT(it.remove());
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CHashTableChain<CSystemString, Tsint> instance;

    // Fill the hash table.
    UT_ASSERT_CHECK_FILL(instance);

    // Check the hash table before serialization.
    UT_ASSERT_EQUAL(instance.getSize(), 20);
    UT_ASSERT_CHECK_SHOW(instance, true, 20);
    UT_ASSERT_CHECK_SHOW(instance, false, 20);

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

    // Check the hash table after serialization.
    UT_ASSERT_EQUAL(instance.getSize(), 20);
    UT_ASSERT_CHECK_SHOW(instance, true, 20);
    UT_ASSERT_CHECK_SHOW(instance, false, 20);
  }
} the_Test;
/*==========================================================================*/
