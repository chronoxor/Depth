/*!
 *  \file    test-algorithms-ASort.cpp Testing of the iterator sort 
 *           algorithms.
 *  \brief   Testing of the iterator sort algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the iterator sort algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   21.08.2007 02:44:38

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
#include <Depth/include/algorithms/containers/ACopy.hpp>
#include <Depth/include/algorithms/containers/ASortBubble.hpp>
#include <Depth/include/algorithms/containers/ASortChoose.hpp>
#include <Depth/include/algorithms/containers/ASortShell.hpp>
#include <Depth/include/algorithms/containers/ASortQuick.hpp>
#include <Depth/include/algorithms/containers/ASortCopy.hpp>
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/CListDC.hpp>
#include <Depth/include/containers/CListDL.hpp>
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
    CArray<Tsint> array;
    CListDC<Tsint> circle1, circle2, circle3, circle4, circleCopy;
    CListDL<Tsint> list1, list2, list3, list4, listCopy;

    // Fill the array.
    UT_ASSERT(array.insertLast(4));
    UT_ASSERT(array.insertLast(6));
    UT_ASSERT(array.insertLast(3));
    UT_ASSERT(array.insertLast(1));
    UT_ASSERT(array.insertLast(5));
    UT_ASSERT(array.insertLast(2));

    // Copy the array into the double circled list and bubble sort it.
    UT_ASSERT_EQUAL(copy(array, circle1), 6);
    UT_ASSERT(sortBubble(circle1));
    UT_ASSERT_CHECK_LIST(circle1);

    // Copy the array into the double linked list and bubble sort it.
    UT_ASSERT_EQUAL(copy(array, list1), 6);
    UT_ASSERT(sortBubble(list1));
    UT_ASSERT_CHECK_LIST(list1);

    // Copy the array into the double circled list and minimal choose sort it.
    UT_ASSERT_EQUAL(copy(array, circle2), 6);
    UT_ASSERT(sortChoose(circle2));
    UT_ASSERT_CHECK_LIST(circle2);

    // Copy the array into the double linked list and minimal choose sort it.
    UT_ASSERT_EQUAL(copy(array, list2), 6);
    UT_ASSERT(sortChoose(list2));
    UT_ASSERT_CHECK_LIST(list2);

    // Copy the array into the double circled list and shell sort it.
    UT_ASSERT_EQUAL(copy(array, circle3), 6);
    UT_ASSERT(sortShell(circle3));
    UT_ASSERT_CHECK_LIST(circle3);

    // Copy the array into the double linked list and shell sort it.
    UT_ASSERT_EQUAL(copy(array, list3), 6);
    UT_ASSERT(sortShell(list3));
    UT_ASSERT_CHECK_LIST(list3);

    // Copy the array into the double circled list and quick sort it.
    UT_ASSERT_EQUAL(copy(array, circle4), 6);
    UT_ASSERT(sortQuick(circle4));
    UT_ASSERT_CHECK_LIST(circle4);

    // Copy the array into the double linked list and quick sort it.
    UT_ASSERT_EQUAL(copy(array, list4), 6);
    UT_ASSERT(sortQuick(list4));
    UT_ASSERT_CHECK_LIST(list4);

    // Sort the array and copy it into the double circled list.
    UT_ASSERT_EQUAL(sortCopy(array, circleCopy), 6);
    UT_ASSERT_EQUAL(circleCopy.stepForward(3), 3);
    UT_ASSERT_CHECK_LIST(circleCopy);

    // Sort the array and copy it into the double linked list.
    UT_ASSERT_EQUAL(sortCopy(array, listCopy), 6);
    UT_ASSERT_CHECK_LIST(listCopy);

    UT_ACCEPT;
  }

  // Check the given instance of the CListDC<Tsint> class.
  void UT_ASSERT_CHECK_LIST(const CListDC<Tsint>& a_crListDC)
  { CALL
    Tsint value = 1;
    CListDC<Tsint>::TIteratorConst it = a_crListDC.getItCurrent();
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        ++value;
      } while ((it.stepForward() == 1) && (it != a_crListDC.getItCurrent()));
    }
    UT_ASSERT_EQUAL(value, 7);
  }

  // Check the given instance of the CListDL<Tsint> class.
  void UT_ASSERT_CHECK_LIST(const CListDL<Tsint>& a_crListDL)
  { CALL
    Tsint value = 1;
    CListDL<Tsint>::TIteratorConst it = a_crListDL.getItFirst();
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        ++value;
      } while (it.stepForward() == 1);
    }
    UT_ASSERT_EQUAL(value, 7);
  }
} the_Test;
/*==========================================================================*/
