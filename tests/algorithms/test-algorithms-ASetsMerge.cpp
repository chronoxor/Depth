/*!
 *  \file    test-algorithms-ASetsMerge.cpp Testing of the iterator sets 
 *           merge algorithms.
 *  \brief   Testing of the iterator sets merge algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the iterator sets merge algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   29.08.2007 21:42:51

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
// Common headers.
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/algorithms/containers/ASetsMerge.hpp>
#include <Depth/include/algorithms/containers/ASetsMergeCopy.hpp>
#include <Depth/include/algorithms/containers/ASetsMergeCount.hpp>
#include <Depth/include/containers/CArray.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NContainers;
using namespace NDepth::NAlgorithms::NIterators;
using namespace NDepth::NContainers;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CArray<Tsint> array1;
    CArray<Tsint> array2;
    CArray<Tsint> array_result;

    // Fill the first array.
    UT_ASSERT(array1.insertLast(1));
    UT_ASSERT(array1.insertLast(3));
    UT_ASSERT(array1.insertLast(4));
    UT_ASSERT(array1.insertLast(4));
    UT_ASSERT(array1.insertLast(5));
    UT_ASSERT(array1.insertLast(5));
    UT_ASSERT(array1.insertLast(6));
    UT_ASSERT(array1.insertLast(7));

    // Fill the last array.
    UT_ASSERT(array2.insertLast(2));
    UT_ASSERT(array2.insertLast(3));
    UT_ASSERT(array2.insertLast(4));
    UT_ASSERT(array2.insertLast(4));
    UT_ASSERT(array2.insertLast(5));

    // Check the count of elements in merge of two sets.
    UT_ASSERT_EQUAL(setsMergeCount(array1, array2), 9);

    // Find and copy merge of two sets.
    UT_ASSERT_EQUAL(setsMergeCopy(array1, array2, array_result), 9);
    UT_ASSERT_CHECK_ARRAY(array_result);

    // Find merge of two sets.
    UT_ASSERT(setsMerge(array1, array2));
    UT_ASSERT_CHECK_ARRAY(array1);

    UT_ACCEPT;
  }

  // Check the given instance of the CArray<Tsint> class.
  void UT_ASSERT_CHECK_ARRAY(const CArray<Tsint>& a_crArray)
  { CALL
    CArray<Tsint>::TIteratorConst it_prev;
    CArray<Tsint>::TIteratorConst it_current = a_crArray.getItFirst();
    if (it_current.isValid())
    {
      it_prev = it_current;
      while (it_current.stepForward() == 1)
      {
        UT_ASSERT_MORE_EQUAL(it_current.getValueRef(), it_prev.getValueRef());
      }
    }
  }
} the_Test;
/*==========================================================================*/
