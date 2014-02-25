/*!
 *  \file    test-algorithms-AFindSub.cpp Testing of the find subsequence 
 *           algorithm.
 *  \brief   Testing of the find subsequence algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the find subsequence algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   17.04.2007 22:40:26

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
#include <Depth/include/algorithms/containers/AFindSub.hpp>
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/CListDC.hpp>
#include <Depth/include/containers/CListDL.hpp>
#include <Depth/include/containers/CStaticArray.hpp>
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
    CListDC<Tsint> circle;
    CListDL<Tsint> list;

    // Fill the array.
    UT_ASSERT(array.insertLast(1));
    UT_ASSERT(array.insertLast(2));
    UT_ASSERT(array.insertLast(3));
    UT_ASSERT(array.insertLast(4));
    UT_ASSERT(array.insertLast(5));
    UT_ASSERT(array.insertLast(6));

    // Fill the double circled list.
    UT_ASSERT(circle.insertCurrentForward(1));
    UT_ASSERT(circle.insertNext(6));
    UT_ASSERT(circle.insertNext(5));
    UT_ASSERT(circle.insertNext(4));
    UT_ASSERT(circle.insertNext(3));
    UT_ASSERT(circle.insertNext(2));

    // Fill the double linked list.
    UT_ASSERT(list.insertLast(1));
    UT_ASSERT(list.insertLast(2));
    UT_ASSERT(list.insertLast(3));
    UT_ASSERT(list.insertLast(4));
    UT_ASSERT(list.insertLast(5));
    UT_ASSERT(list.insertLast(6));

    // Create good subsequence.
    CStaticArray<Tsint, 3> subsequence1;
    subsequence1[CONSTU(0)] = 3;
    subsequence1[CONSTU(1)] = 4;
    subsequence1[CONSTU(2)] = 5;

    // Create bad subsequence.
    CStaticArray<Tsint, 3> subsequence2;
    subsequence2[CONSTU(0)] = 5;
    subsequence2[CONSTU(1)] = 4;
    subsequence2[CONSTU(2)] = 3;

    // Check good subsequence.
    UT_ASSERT_EQUAL(findSub(array, subsequence1).getValueRef(), 3);
    UT_ASSERT_EQUAL(findSubPrev(array.getItLast(), subsequence1.getItLast()).getValueRef(), 5);
    UT_ASSERT_EQUAL(findSub(circle, subsequence1).getValueRef(), 3);
    UT_ASSERT_EQUAL(findSubPrev(circle.getItCurrent().getBackward(), subsequence1.getItLast()).getValueRef(), 5);
    UT_ASSERT_EQUAL(findSub(list, subsequence1).getValueRef(), 3);
    UT_ASSERT_EQUAL(findSubPrev(list.getItLast(), subsequence1.getItLast()).getValueRef(), 5);

    // Check bad subsequence.
    UT_ASSERT(!findSub(array, subsequence2).isValid());
    UT_ASSERT(!findSubPrev(array.getItLast(), subsequence2.getItLast()).isValid());
    UT_ASSERT(!findSub(circle, subsequence2).isValid());
    UT_ASSERT(!findSubPrev(circle.getItCurrent().getBackward(), subsequence2.getItLast()).isValid());
    UT_ASSERT(!findSub(list, subsequence2).isValid());
    UT_ASSERT(!findSubPrev(list.getItLast(), subsequence2.getItLast()).isValid());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
