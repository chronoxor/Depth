/*!
 *  \file    test-containers-CSparseArray.cpp Testing of the CSparseArray 
 *           class.
 *  \brief   Testing of the CSparseArray class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.10.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CSparseArray class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   19.10.2007 22:14:08

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
#include <Depth/include/algorithms/common/AMinMax.hpp>
#include <Depth/include/containers/CSparseArray.hpp>
#include <Depth/include/random/CRandomGenerator.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NContainers;
using namespace NDepth::NRandom;
using namespace NDepth::NSerialization;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    static const Tsint a[] = { 10, 11, 12 };
    static const Tsint b[] = { 20, 21, 22 };
    static const Tsint c[] = { 30, 31, 32 };

    CSparseArray<Tsint> sparse;

    // Fill the sparse array.
    UT_ASSERT(sparse.insertIndex(10, a) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    UT_ASSERT(sparse.insertIndex(15, 15) && UT_ASSERT_CHECK_SHOW(sparse, 4, 2));
    UT_ASSERT(sparse.insertIndex(20, b) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));
    UT_ASSERT(sparse.insertIndex(25, 25) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
    UT_ASSERT(sparse.insertIndex(30, c) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    UT_ASSERT(sparse.insertIndex(35, 35) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));

    // Insert test.
    UT_ASSERT_CHECK_INSERT(sparse);
    // Insert iterator test.
    UT_ASSERT_CHECK_INSERT_ITERATOR(sparse);

    // Remove test.
    UT_ASSERT_CHECK_REMOVE(sparse);
    // Remove iterator test.
    UT_ASSERT_CHECK_REMOVE_ITERATOR(sparse);

    // Fill test.
    UT_ASSERT_CHECK_FILL(sparse);
    // Fill iterator test.
    UT_ASSERT_CHECK_FILL_ITERATOR(sparse);

    // Erase test.
    UT_ASSERT_CHECK_ERASE(sparse);
    // Erase iterator test.
    UT_ASSERT_CHECK_ERASE_ITERATOR(sparse);

    // Random test.
    UT_ASSERT_CHECK_RANDOM(100);

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION(sparse);

    UT_ACCEPT;
  }

  // Check the show functionality of the CSparseArray<Tsint>.
  Tbool UT_ASSERT_CHECK_SHOW(const CSparseArray<Tsint>& a_crSparseArray, const Tuint a_cSize, const Tuint a_cIntervals, const Tbool a_cCheckSize = true)
  { CALL
    // Check sparse array size.
    if (a_cCheckSize)
    {
      UT_ASSERT_EQUAL(a_crSparseArray.getSize(), a_cSize);
      UT_ASSERT_EQUAL(a_crSparseArray.getIntervalsCount(), a_cIntervals);
    }

    // UT_LOG(STR("CSparseArray<Tsint> size = %u --- intervals = %u") COMMA a_crSparseArray.getSize() COMMA a_crSparseArray.getIntervalsCount());

    // Check sparse array content.
    CSparseArray<Tsint>::TIteratorConst it = a_crSparseArray.getItFirst();
    CSparseArray<Tsint>::TIteratorConst it_next = a_crSparseArray.getItFirst();
    if (it.isValid())
    {
      // UT_LOG(STR("index = %u --- item = %d") COMMA it.getPosition() COMMA it.getValueRef());

      while ((it_next.stepForward() > 0) && (it_next != a_crSparseArray.getItFirst()))
      {
        // UT_LOG(STR("index = %u --- item = %d") COMMA it_next.getPosition() COMMA it_next.getValueRef());

        if ((it.getSparse() == it_next.getSparse()) && ((it.getPosition() + 1) != it_next.getPosition()))
          return false;
        if ((it.getSparse() != it_next.getSparse()) && ((it.getPosition() + 1) == it_next.getPosition()))
          return false;
        if (it.getValueRef() > it_next.getValueRef())
          return false;
        it = it_next;
      }
    }
    return true;
  }

  // Check the insert functionality of the CSparseArray<Tsint>.
  void UT_ASSERT_CHECK_INSERT(const CSparseArray<Tsint>& a_crSparseArray)
  { CALL
    CSparseArray<Tsint> sparse;

    // Check single item insertions.
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(0, 0) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(9, 9) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(10, 10) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(11, 11) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(12, 12) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(13, 13) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(14, 14) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(15, 15) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(16, 16) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(17, 17) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(18, 18) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(19, 19) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(20, 20) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(32, 32) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(33, 33) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(34, 34) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(35, 35) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(36, 36) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(37, 37) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));

    // Check interval insertions.
    Tsint i[3];
    i[0] = 0;
    i[1] = 1;
    i[2] = 2;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(0, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 7));
    i[0] = 7;
    i[1] = 8;
    i[2] = 9;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(7, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 7));
    i[0] = 9;
    i[1] = 10;
    i[2] = 10;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(9, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 7));
    i[0] = 10;
    i[1] = 10;
    i[2] = 10;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(10, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 6));
    i[0] = 11;
    i[1] = 11;
    i[2] = 11;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(11, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 6));
    i[0] = 12;
    i[1] = 12;
    i[2] = 12;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(12, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 6));
    i[0] = 13;
    i[1] = 13;
    i[2] = 13;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(13, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 6));
    i[0] = 14;
    i[1] = 14;
    i[2] = 14;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(14, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 7));
    i[0] = 15;
    i[1] = 15;
    i[2] = 15;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(15, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 6));
    i[0] = 16;
    i[1] = 16;
    i[2] = 16;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(16, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 6));
    i[0] = 17;
    i[1] = 17;
    i[2] = 17;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(17, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 7));
    i[0] = 35;
    i[1] = 35;
    i[2] = 35;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(35, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 6));
    i[0] = 36;
    i[1] = 36;
    i[2] = 36;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(36, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 6));
    i[0] = 37;
    i[1] = 37;
    i[2] = 37;
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.insertIndex(37, i) && UT_ASSERT_CHECK_SHOW(sparse, 15, 7));

    // Some special checks.
    static const Tsint a[] = { 10, 11, 12 };
    static const Tsint b[] = { 14, 15, 16 };
    static const Tsint c[] = { 13, 13, 13 };
    UT_ASSERT(sparse.clear());
    UT_ASSERT(sparse.insertIndex(10, a) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    UT_ASSERT(sparse.insertIndex(14, b) && UT_ASSERT_CHECK_SHOW(sparse, 6, 2));
    UT_ASSERT(sparse.insertIndex(13, 13) && UT_ASSERT_CHECK_SHOW(sparse, 7, 2));
    UT_ASSERT(sparse.clear());
    UT_ASSERT(sparse.insertIndex(10, a) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    UT_ASSERT(sparse.insertIndex(14, b) && UT_ASSERT_CHECK_SHOW(sparse, 6, 2));
    UT_ASSERT(sparse.insertIndex(13, c) && UT_ASSERT_CHECK_SHOW(sparse, 9, 2));
  }

  // Check the iterator insert functionality of the CSparseArray<Tsint>.
  void UT_ASSERT_CHECK_INSERT_ITERATOR(const CSparseArray<Tsint>& a_crSparseArray)
  { CALL
    CSparseArray<Tsint> sparse;
    CSparseArray<Tsint>::TIterator it;

    sparse = a_crSparseArray;
    it = sparse.getItIndex(0);
    UT_ASSERT(it.insertForward(3) && (it.getPosition() == 0) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    UT_ASSERT(it.insertBackward(1) && (it.getPosition() == 0) && UT_ASSERT_CHECK_SHOW(sparse, 14, 7));
    UT_ASSERT(it.insertNext(2) && (it.getPosition() == 0) && UT_ASSERT_CHECK_SHOW(sparse, 15, 7));
    UT_ASSERT(it.insertPrev(0) && (it.getPosition() == 1) && UT_ASSERT_CHECK_SHOW(sparse, 16, 7));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(40);
    UT_ASSERT(it.insertForward(43) && (it.getPosition() == 40) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    UT_ASSERT(it.insertBackward(41) && (it.getPosition() == 40) && UT_ASSERT_CHECK_SHOW(sparse, 14, 7));
    UT_ASSERT(it.insertNext(42) && (it.getPosition() == 40) && UT_ASSERT_CHECK_SHOW(sparse, 15, 7));
    UT_ASSERT(it.insertPrev(40) && (it.getPosition() == 41) && UT_ASSERT_CHECK_SHOW(sparse, 16, 7));
    sparse = a_crSparseArray;
    it = sparse.getItFirst();
    UT_ASSERT(it.insertPrev(9) && (it.getPosition() == 11) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    UT_ASSERT(it.insertNext(10) && (it.getPosition() == 11) && UT_ASSERT_CHECK_SHOW(sparse, 14, 6));
    sparse = a_crSparseArray;
    it = sparse.getItLast();
    UT_ASSERT(it.insertNext(36) && (it.getPosition() == 35) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    UT_ASSERT(it.insertPrev(35) && (it.getPosition() == 36) && UT_ASSERT_CHECK_SHOW(sparse, 14, 6));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(100);
    UT_ASSERT(it.insertIndex(9, 9) && (it.getPosition() == 101) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    UT_ASSERT(it.insertIndex(12, 11) && (it.getPosition() == 102) && UT_ASSERT_CHECK_SHOW(sparse, 14, 7));
    UT_ASSERT(it.insertIndex(15, 13) && (it.getPosition() == 103) && UT_ASSERT_CHECK_SHOW(sparse, 15, 7));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(100);
    UT_ASSERT(it.insertIndex(22, 22) && (it.getPosition() == 101) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    UT_ASSERT(it.insertIndex(24, 23) && (it.getPosition() == 102) && UT_ASSERT_CHECK_SHOW(sparse, 14, 6));
    UT_ASSERT(it.insertIndex(25, 24) && (it.getPosition() == 103) && UT_ASSERT_CHECK_SHOW(sparse, 15, 6));
    UT_ASSERT(it.insertIndex(28, 25) && (it.getPosition() == 104) && UT_ASSERT_CHECK_SHOW(sparse, 16, 6));
    UT_ASSERT(it.insertIndex(30, 26) && (it.getPosition() == 105) && UT_ASSERT_CHECK_SHOW(sparse, 17, 6));
    UT_ASSERT(it.insertIndex(31, 27) && (it.getPosition() == 106) && UT_ASSERT_CHECK_SHOW(sparse, 18, 6));
  }

  // Check the remove functionality of the CSparseArray<Tsint>.
  void UT_ASSERT_CHECK_REMOVE(const CSparseArray<Tsint>& a_crSparseArray)
  { CALL
    CSparseArray<Tsint> sparse;

    // Check single item remove.
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(9, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(10, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(11, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(12, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(13, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(14, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(15, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(16, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(19, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(20, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(21, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(22, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(23, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(34, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(35, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(36, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(37, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));

    // Check intervals remove.
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 9) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 10) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 11) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 12) && UT_ASSERT_CHECK_SHOW(sparse, 10, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 13) && UT_ASSERT_CHECK_SHOW(sparse, 9, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 14) && UT_ASSERT_CHECK_SHOW(sparse, 9, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 15) && UT_ASSERT_CHECK_SHOW(sparse, 9, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 16) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 30) && UT_ASSERT_CHECK_SHOW(sparse, 4, 2));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 31) && UT_ASSERT_CHECK_SHOW(sparse, 3, 2));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 32) && UT_ASSERT_CHECK_SHOW(sparse, 2, 2));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 33) && UT_ASSERT_CHECK_SHOW(sparse, 1, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 34) && UT_ASSERT_CHECK_SHOW(sparse, 1, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 35) && UT_ASSERT_CHECK_SHOW(sparse, 1, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 36) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 37) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 38) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(36, 100) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(35, 100) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(34, 100) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(33, 100) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(32, 100) && UT_ASSERT_CHECK_SHOW(sparse, 10, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(31, 100) && UT_ASSERT_CHECK_SHOW(sparse, 9, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(30, 100) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(29, 100) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(28, 100) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(26, 100) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(25, 100) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(24, 100) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(23, 100) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(16, 100) && UT_ASSERT_CHECK_SHOW(sparse, 4, 2));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(15, 100) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(14, 100) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(13, 100) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(12, 100) && UT_ASSERT_CHECK_SHOW(sparse, 2, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(11, 100) && UT_ASSERT_CHECK_SHOW(sparse, 1, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(10, 100) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(9, 100) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(0, 100) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(10, 26) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(11, 11) && UT_ASSERT_CHECK_SHOW(sparse, 7, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(13, 17) && UT_ASSERT_CHECK_SHOW(sparse, 7, 2));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.remove(15, 11) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));

    // Some special checks.
    static const Tsint a[] = { 10, 11, 12 };
    static const Tsint b[] = { 14, 15, 16 };
    UT_ASSERT(sparse.clear());
    UT_ASSERT(sparse.insertIndex(10, a) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    UT_ASSERT(sparse.insertIndex(14, b) && UT_ASSERT_CHECK_SHOW(sparse, 6, 2));
    UT_ASSERT(sparse.remove(13, 1) && UT_ASSERT_CHECK_SHOW(sparse, 6, 1));
    UT_ASSERT(sparse.remove(5, 8) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    UT_ASSERT(sparse.remove(0, 8) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
  }

  // Check the iterator remove functionality of the CSparseArray<Tsint>.
  void UT_ASSERT_CHECK_REMOVE_ITERATOR(const CSparseArray<Tsint>& a_crSparseArray)
  { CALL
    CSparseArray<Tsint> sparse;
    CSparseArray<Tsint>::TIterator it;

    sparse = a_crSparseArray;
    it = sparse.getItIndex(9);
    UT_ASSERT(it.removeNext() && (it.getPosition() == 10) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(10);
    UT_ASSERT(it.removeForward() && (it.getPosition() == 10) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    UT_ASSERT(it.removeNext() && (it.getPosition() == 10) && UT_ASSERT_CHECK_SHOW(sparse, 10, 6));
    UT_ASSERT(it.removeForward() && (it.getPosition() == 12) && UT_ASSERT_CHECK_SHOW(sparse, 9, 5));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(11);
    UT_ASSERT(it.removePrev() && (it.getPosition() == 10) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    UT_ASSERT(it.removeNext() && (it.getPosition() == 10) && UT_ASSERT_CHECK_SHOW(sparse, 10, 6));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(12);
    UT_ASSERT(it.removeBackward() && (it.getPosition() == 11) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    UT_ASSERT(it.removePrev() && (it.getPosition() == 10) && UT_ASSERT_CHECK_SHOW(sparse, 10, 6));
    UT_ASSERT(it.removeBackward() && (it.getPosition() == 12) && UT_ASSERT_CHECK_SHOW(sparse, 9, 5));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(25);
    UT_ASSERT(it.removeForward() && (it.getPosition() == 29) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(25);
    UT_ASSERT(it.removeBackward() && (it.getPosition() == 22) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(25);
    UT_ASSERT(it.remove(25, 50) && (it.getPosition() == 22) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(21);
    UT_ASSERT(it.remove(21, 10) && (it.getPosition() == 21) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
  }

  // Check the fill functionality of the CSparseArray<Tsint>.
  void UT_ASSERT_CHECK_FILL(const CSparseArray<Tsint>& a_crSparseArray)
  { CALL
    CSparseArray<Tsint> sparse;

    // Check single item filling.
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(0, 0) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(9, 9) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(10, 10) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(11, 11) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(12, 12) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(13, 13) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(14, 14) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(15, 15) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(16, 16) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(17, 17) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(18, 18) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(19, 19) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(20, 20) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(32, 32) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(33, 33) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(34, 34) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(35, 35) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(36, 36) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(37, 37) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));

    static Tsint bytes0[] = {  0,   1,   2,   3,   4 };
    static Tsint bytes1[] = {  0,   1,   2,   3,   4,   5,   6,   7,   8,   9 };
    static Tsint bytes2[] = { 10,  11,  12,  13,  14,  15,  16,  17,  18,  19 };
    static Tsint bytes3[] = { 20,  21,  22,  23,  24,  25,  26,  27,  28,  29 };
    static Tsint bytes4[] = { 30,  31,  32,  33,  34,  35,  36,  37,  38,  39 };
    static Tsint bytes5[] = { 40,  41,  42,  43,  44,  45,  46,  47,  48,  49 };

    // Check left interval filling.
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(0, bytes0) && UT_ASSERT_CHECK_SHOW(sparse, 17, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(0, bytes1) && UT_ASSERT_CHECK_SHOW(sparse, 22, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(1, bytes1) && UT_ASSERT_CHECK_SHOW(sparse, 21, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(2, bytes1) && UT_ASSERT_CHECK_SHOW(sparse, 20, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(3, bytes1) && UT_ASSERT_CHECK_SHOW(sparse, 19, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(4, bytes1) && UT_ASSERT_CHECK_SHOW(sparse, 19, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(5, bytes1) && UT_ASSERT_CHECK_SHOW(sparse, 19, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(6, bytes1) && UT_ASSERT_CHECK_SHOW(sparse, 18, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(7, bytes2) && UT_ASSERT_CHECK_SHOW(sparse, 18, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(8, bytes2) && UT_ASSERT_CHECK_SHOW(sparse, 18, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(9, bytes2) && UT_ASSERT_CHECK_SHOW(sparse, 18, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(10, bytes2) && UT_ASSERT_CHECK_SHOW(sparse, 18, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(11, bytes2) && UT_ASSERT_CHECK_SHOW(sparse, 18, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(16, bytes3) && UT_ASSERT_CHECK_SHOW(sparse, 18, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(17, bytes3) && UT_ASSERT_CHECK_SHOW(sparse, 18, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(18, bytes3) && UT_ASSERT_CHECK_SHOW(sparse, 18, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(26, bytes4) && UT_ASSERT_CHECK_SHOW(sparse, 18, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(27, bytes4) && UT_ASSERT_CHECK_SHOW(sparse, 18, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(28, bytes4) && UT_ASSERT_CHECK_SHOW(sparse, 18, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(29, bytes4) && UT_ASSERT_CHECK_SHOW(sparse, 18, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(30, bytes5) && UT_ASSERT_CHECK_SHOW(sparse, 18, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(31, bytes5) && UT_ASSERT_CHECK_SHOW(sparse, 19, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(32, bytes5) && UT_ASSERT_CHECK_SHOW(sparse, 20, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(33, bytes5) && UT_ASSERT_CHECK_SHOW(sparse, 21, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(34, bytes5) && UT_ASSERT_CHECK_SHOW(sparse, 21, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(35, bytes5) && UT_ASSERT_CHECK_SHOW(sparse, 21, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(36, bytes5) && UT_ASSERT_CHECK_SHOW(sparse, 22, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.fillIndex(37, bytes5) && UT_ASSERT_CHECK_SHOW(sparse, 22, 7));

    // Some special checks.
    static const Tsint a[] = { 10, 11, 12 };
    static const Tsint b[] = { 14, 15, 16 };
    static const Tsint c[] = { 11, 12, 13, 14 };
    static const Tsint d[] = { 111, 222, 333, 444, 555, 666, 777, 888, 999 };
    UT_ASSERT(sparse.clear());
    UT_ASSERT(sparse.fillIndex(10, a) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    UT_ASSERT(sparse.fillIndex(14, b) && UT_ASSERT_CHECK_SHOW(sparse, 6, 2));
    UT_ASSERT(sparse.fillIndex(13, 13) && UT_ASSERT_CHECK_SHOW(sparse, 7, 1));
    UT_ASSERT(sparse.clear());
    UT_ASSERT(sparse.fillIndex(10, a) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    UT_ASSERT(sparse.fillIndex(14, b) && UT_ASSERT_CHECK_SHOW(sparse, 6, 2));
    UT_ASSERT(sparse.fillIndex(11, c) && UT_ASSERT_CHECK_SHOW(sparse, 7, 1));
    UT_ASSERT(sparse.clear());
    UT_ASSERT(sparse.fillIndex(10, a) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    UT_ASSERT(sparse.fillIndex(14, b) && UT_ASSERT_CHECK_SHOW(sparse, 6, 2));
    UT_ASSERT(sparse.fillIndex(9, d) && UT_ASSERT_CHECK_SHOW(sparse, 9, 1));
  }

  // Check the iterator fill functionality of the CSparseArray<Tsint>.
  void UT_ASSERT_CHECK_FILL_ITERATOR(const CSparseArray<Tsint>& a_crSparseArray)
  { CALL
    CSparseArray<Tsint> sparse;
    CSparseArray<Tsint>::TIterator it;

    sparse = a_crSparseArray;
    it = sparse.getItIndex(0);
    UT_ASSERT(it.fillForward(3) && (it.getPosition() == 0) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    UT_ASSERT(it.fillBackward(1) && (it.getPosition() == 0) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    UT_ASSERT(it.fillNext(2) && (it.getPosition() == 0) && UT_ASSERT_CHECK_SHOW(sparse, 14, 7));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(40);
    UT_ASSERT(it.fillForward(43) && (it.getPosition() == 40) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    UT_ASSERT(it.fillBackward(41) && (it.getPosition() == 40) && UT_ASSERT_CHECK_SHOW(sparse, 13, 7));
    UT_ASSERT(it.fillNext(42) && (it.getPosition() == 40) && UT_ASSERT_CHECK_SHOW(sparse, 14, 7));
    UT_ASSERT(it.fillPrev(40) && (it.getPosition() == 40) && UT_ASSERT_CHECK_SHOW(sparse, 15, 7));
    sparse = a_crSparseArray;
    it = sparse.getItFirst();
    UT_ASSERT(it.fillPrev(9) && (it.getPosition() == 10) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    UT_ASSERT(it.fillNext(10) && (it.getPosition() == 10) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    sparse = a_crSparseArray;
    it = sparse.getItLast();
    UT_ASSERT(it.fillNext(36) && (it.getPosition() == 35) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    UT_ASSERT(it.fillPrev(35) && (it.getPosition() == 35) && UT_ASSERT_CHECK_SHOW(sparse, 14, 6));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(100);
    UT_ASSERT(it.fillIndex(9, 9) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    UT_ASSERT(it.fillIndex(13, 13) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 14, 6));
    UT_ASSERT(it.fillIndex(14, 14) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 15, 5));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(100);
    UT_ASSERT(it.fillIndex(22, 22) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    UT_ASSERT(it.fillIndex(23, 23) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 13, 6));
    UT_ASSERT(it.fillIndex(24, 24) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 14, 5));
    UT_ASSERT(it.fillIndex(25, 25) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 14, 5));
    UT_ASSERT(it.fillIndex(26, 26) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 15, 5));
    UT_ASSERT(it.fillIndex(27, 27) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 16, 5));
    UT_ASSERT(it.fillIndex(28, 28) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 17, 5));
    UT_ASSERT(it.fillIndex(29, 29) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 18, 4));
    UT_ASSERT(it.fillIndex(30, 30) && (it.getPosition() == 100) && UT_ASSERT_CHECK_SHOW(sparse, 18, 4));
  }

  // Check the erase functionality of the CSparseArray<Tsint>.
  void UT_ASSERT_CHECK_ERASE(const CSparseArray<Tsint>& a_crSparseArray)
  { CALL
    CSparseArray<Tsint> sparse;

    // Check single item erase.
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(9, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(10, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(11, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(12, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(13, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(14, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(15, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(16, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(19, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(20, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(21, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 7));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(22, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(23, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(34, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(35, 1) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(36, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(37, 1) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));

    // Check intervals erase.
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 9) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 10) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 11) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 12) && UT_ASSERT_CHECK_SHOW(sparse, 10, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 13) && UT_ASSERT_CHECK_SHOW(sparse, 9, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 14) && UT_ASSERT_CHECK_SHOW(sparse, 9, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 15) && UT_ASSERT_CHECK_SHOW(sparse, 9, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 16) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 30) && UT_ASSERT_CHECK_SHOW(sparse, 4, 2));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 31) && UT_ASSERT_CHECK_SHOW(sparse, 3, 2));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 32) && UT_ASSERT_CHECK_SHOW(sparse, 2, 2));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 33) && UT_ASSERT_CHECK_SHOW(sparse, 1, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 34) && UT_ASSERT_CHECK_SHOW(sparse, 1, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 35) && UT_ASSERT_CHECK_SHOW(sparse, 1, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 36) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 37) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 38) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(36, 100) && UT_ASSERT_CHECK_SHOW(sparse, 12, 6));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(35, 100) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(34, 100) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(33, 100) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(32, 100) && UT_ASSERT_CHECK_SHOW(sparse, 10, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(31, 100) && UT_ASSERT_CHECK_SHOW(sparse, 9, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(30, 100) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(29, 100) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(28, 100) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(26, 100) && UT_ASSERT_CHECK_SHOW(sparse, 8, 4));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(25, 100) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(24, 100) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(23, 100) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(16, 100) && UT_ASSERT_CHECK_SHOW(sparse, 4, 2));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(15, 100) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(14, 100) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(13, 100) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(12, 100) && UT_ASSERT_CHECK_SHOW(sparse, 2, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(11, 100) && UT_ASSERT_CHECK_SHOW(sparse, 1, 1));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(10, 100) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(9, 100) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(0, 100) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(10, 26) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(11, 11) && UT_ASSERT_CHECK_SHOW(sparse, 7, 5));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(13, 17) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));
    sparse = a_crSparseArray;
    UT_ASSERT(sparse.erase(15, 11) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));

    // Some special checks.
    static const Tsint a[] = { 10, 11, 12 };
    static const Tsint b[] = { 14, 15, 16 };
    UT_ASSERT(sparse.clear());
    UT_ASSERT(sparse.insertIndex(10, a) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    UT_ASSERT(sparse.insertIndex(14, b) && UT_ASSERT_CHECK_SHOW(sparse, 6, 2));
    UT_ASSERT(sparse.erase(13, 1) && UT_ASSERT_CHECK_SHOW(sparse, 6, 2));
    UT_ASSERT(sparse.erase(5, 8) && UT_ASSERT_CHECK_SHOW(sparse, 3, 1));
    UT_ASSERT(sparse.erase(9, 8) && UT_ASSERT_CHECK_SHOW(sparse, 0, 0));

    // Some special intervals checks.
    static const Tsint i[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    UT_ASSERT(sparse.insertIndex(0, i) && UT_ASSERT_CHECK_SHOW(sparse, 10, 1));
    UT_ASSERT(sparse.erase(3, 2) && UT_ASSERT_CHECK_SHOW(sparse, 8, 2));
    UT_ASSERT(sparse.erase(6, 2) && UT_ASSERT_CHECK_SHOW(sparse, 6, 3));
    UT_ASSERT(sparse.erase(3, 6) && UT_ASSERT_CHECK_SHOW(sparse, 4, 2));
  }

  // Check the iterator erase functionality of the CSparseArray<Tsint>.
  void UT_ASSERT_CHECK_ERASE_ITERATOR(const CSparseArray<Tsint>& a_crSparseArray)
  { CALL
    CSparseArray<Tsint> sparse;
    CSparseArray<Tsint>::TIterator it;

    sparse = a_crSparseArray;
    it = sparse.getItIndex(9);
    UT_ASSERT(it.eraseNext() && (it.getPosition() == 11) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(10);
    UT_ASSERT(it.eraseForward() && (it.getPosition() == 11) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    UT_ASSERT(it.eraseNext() && (it.getPosition() == 11) && UT_ASSERT_CHECK_SHOW(sparse, 10, 6));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(11);
    UT_ASSERT(it.erasePrev() && (it.getPosition() == 11) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    UT_ASSERT(it.eraseNext() && (it.getPosition() == 11) && UT_ASSERT_CHECK_SHOW(sparse, 10, 6));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(12);
    UT_ASSERT(it.eraseBackward() && (it.getPosition() == 11) && UT_ASSERT_CHECK_SHOW(sparse, 11, 6));
    UT_ASSERT(it.erasePrev() && (it.getPosition() == 11) && UT_ASSERT_CHECK_SHOW(sparse, 10, 6));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(25);
    UT_ASSERT(it.eraseForward() && (it.getPosition() == 30) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(25);
    UT_ASSERT(it.eraseBackward() && (it.getPosition() == 22) && UT_ASSERT_CHECK_SHOW(sparse, 11, 5));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(25);
    UT_ASSERT(it.erase(25, 50) && (it.getPosition() == 22) && UT_ASSERT_CHECK_SHOW(sparse, 7, 3));
    sparse = a_crSparseArray;
    it = sparse.getItIndex(21);
    UT_ASSERT(it.erase(21, 10) && (it.getPosition() == 20) && UT_ASSERT_CHECK_SHOW(sparse, 8, 5));
  }

  // Check the random insert/remove functionality.
  Tbool UT_ASSERT_CHECK_RANDOM(const Tuint a_cCount)
  { CALL
    static Tsint bytes[] =
    {
       0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
      10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
      20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
      30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
      40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
      50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
      60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
      70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
      80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
      90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
    };

    CRandomGenerator generator;
    CSparseArray<Tsint> sparse;

    Tuint count = a_cCount;
    while (count-- > 0)
    {
      // Choose the action (insert/remove/fill/erase).
      Tuint action = ((generator.randomInteger() % 4) == 0);

      // Choose the sparse array values.
      Tuint a = (generator.randomInteger() % 100);
      Tuint b = (generator.randomInteger() % 100);
      NAlgorithms::NCommon::minMax(a, b);

      // Perform an action.
      switch (action)
      {
        case 0:
        {
          // UT_LOG(STR("insert: [%d, %d]") COMMA a COMMA b);
          UT_ASSERT(sparse.insertIndex(a, &bytes[a], (b - a + 1)));
          break;
        }
        case 1:
        {
          // UT_LOG(STR("remove: [%d, %d]") COMMA a COMMA b);
          UT_ASSERT(sparse.remove(a, (b - a + 1)));
          break;
        }
        case 2:
        {
          // UT_LOG(STR("fill: [%d, %d]") COMMA a COMMA b);
          UT_ASSERT(sparse.fillIndex(a, &bytes[a], (b - a + 1)));
          break;
        }
        case 3:
        {
          // UT_LOG(STR("erase: [%d, %d]") COMMA a COMMA b);
          UT_ASSERT(sparse.erase(a, (b - a + 1)));
          break;
        }
      }

      // Perform a sparse array content test.
      CSparseArray<Tsint>::TIterator it = sparse.getItFirst();
      if (it.isValid())
      {
        do
        {
          it.getValueRef() = it.getPosition();
        } while ((it.stepForward() > 0) && (it != sparse.getItFirst()));
      }
      UT_ASSERT(UT_ASSERT_CHECK_SHOW(sparse, 0, 0, false));

      UT_CONRET(false);
    }
    return true;
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION(CSparseArray<Tsint>& a_rSparseArray)
  { CALL
    Tuint size = a_rSparseArray.getSize();
    Tuint intervals = a_rSparseArray.getIntervalsCount();

    // Check sparse array before serialization.
    UT_ASSERT(UT_ASSERT_CHECK_SHOW(a_rSparseArray, size, intervals));

    // Save instance.
    SaveArchive saver;
    UT_ASSERT(saver.open());
    UT_ASSERT(saver.serialize(a_rSparseArray));
    UT_ASSERT(saver.close());

    // Load instance.
    LoadArchive loader;
    UT_ASSERT(loader.open());
    UT_ASSERT(loader.serialize(a_rSparseArray));
    UT_ASSERT(loader.close());

    // Check sparse array after serialization.
    UT_ASSERT(UT_ASSERT_CHECK_SHOW(a_rSparseArray, size, intervals));
  }
} the_Test;
/*==========================================================================*/
