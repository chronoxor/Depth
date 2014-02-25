/*!
 *  \file    test-containers-CSpan.cpp Testing of the CSpan class.
 *  \brief   Testing of the CSpan class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CSpan class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers tests
    VERSION:   1.0
    CREATED:   19.09.2007 02:14:15

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
#include <Depth/include/containers/CSpan.hpp>
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
    CSpan<Tsint> span;

    // Fill the span.
    UT_ASSERT(span.insert(1, 20, true, true) && UT_ASSERT_CHECK_SHOW(span, 1));
    UT_ASSERT(span.insert(25) && UT_ASSERT_CHECK_SHOW(span, 2));
    UT_ASSERT(span.insert(30, 40, false, true) && UT_ASSERT_CHECK_SHOW(span, 3));
    UT_ASSERT(span.insert(45) && UT_ASSERT_CHECK_SHOW(span, 4));
    UT_ASSERT(span.insert(50, 60, false, false) && UT_ASSERT_CHECK_SHOW(span, 5));
    UT_ASSERT(span.insert(65) && UT_ASSERT_CHECK_SHOW(span, 6));
    UT_ASSERT(span.insert(70, 80, false, false) && UT_ASSERT_CHECK_SHOW(span, 7));
    UT_ASSERT(span.insert(85) && UT_ASSERT_CHECK_SHOW(span, 8));
    UT_ASSERT(span.insert(90, 100, true, true) && UT_ASSERT_CHECK_SHOW(span, 9));

    // Insert test.
    UT_ASSERT_CHECK_INSERT(span);
    // Remove test.
    UT_ASSERT_CHECK_REMOVE(span);
    // Random test.
    UT_ASSERT_CHECK_RANDOM(100);

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION(span);

    UT_ACCEPT;
  }

  // Check the show functionality of the CSpan<Tsint>.
  Tbool UT_ASSERT_CHECK_SHOW(const CSpan<Tsint>& a_crSpan, const Tuint a_cSize, const Tbool a_cCheckSize = true)
  { CALL
    // Check span size.
    if (a_cCheckSize)
      UT_ASSERT_EQUAL(a_crSpan.getSize(), a_cSize);

    // UT_LOG(STR("CSpan<Tsint> size = %u") COMMA a_crSpan.getSize());

    // Check span content.
    CSpan<Tsint>::TIteratorConst it = a_crSpan.getItFirst();
    CSpan<Tsint>::TIteratorConst it_next = a_crSpan.getItFirst();
    if (it.isValid())
    {
      // UT_LOG(STR("item = %x%i, %i%x") COMMA (it.getValueRef().isIncludeFirst() ? STR('[') : STR('(')) COMMA it.getValueRef().getFirst() COMMA it.getValueRef().getSecond() COMMA (it.getValueRef().isIncludeSecond() ? STR(']') : STR(')')));

      while ((it_next.stepForward() > 0) && (it_next != a_crSpan.getItFirst()))
      {
        // UT_LOG(STR("item = %x%i, %i%x") COMMA (it_next.getValueRef().isIncludeFirst() ? STR('[') : STR('(')) COMMA it_next.getValueRef().getFirst() COMMA it_next.getValueRef().getSecond() COMMA (it_next.getValueRef().isIncludeSecond() ? STR(']') : STR(')')));

        if (it.getValueRef().getSecond() > it_next.getValueRef().getFirst())
          return false;
        if ((it.getValueRef().getSecond() == it_next.getValueRef().getFirst()) && (it.getValueRef().isIncludeSecond() || it_next.getValueRef().isIncludeFirst()))
          return false;
        it = it_next;
      }
    }
    return true;
  }

  // Check the insert functionality of the CSpan<Tsint>.
  void UT_ASSERT_CHECK_INSERT(const CSpan<Tsint>& a_crSpan)
  { CALL
    CSpan<Tsint> span;

    // Check single item insertions.
    span = a_crSpan;
    UT_ASSERT(span.insert(0) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.insert(28) && UT_ASSERT_CHECK_SHOW(span, 11));
    UT_ASSERT(span.insert(50) && UT_ASSERT_CHECK_SHOW(span, 11));
    UT_ASSERT(span.insert(55) && UT_ASSERT_CHECK_SHOW(span, 11));
    UT_ASSERT(span.insert(60) && UT_ASSERT_CHECK_SHOW(span, 11));
    UT_ASSERT(span.insert(88) && UT_ASSERT_CHECK_SHOW(span, 12));
    UT_ASSERT(span.insert(101) && UT_ASSERT_CHECK_SHOW(span, 13));

    // Check single item joining insertions.
    span = a_crSpan;
    UT_ASSERT(span.insert(45, 50, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(60, 65, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(50) && UT_ASSERT_CHECK_SHOW(span, 8));
    UT_ASSERT(span.insert(60) && UT_ASSERT_CHECK_SHOW(span, 7));

    // Check simple span insertions.
    span = a_crSpan;
    UT_ASSERT(span.insert(21, 24, false, false) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.insert(26, 30, false, true) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.insert(60, 64, false, true) && UT_ASSERT_CHECK_SHOW(span, 11));

    // Check left span insertions.
    span = a_crSpan;
    UT_ASSERT(span.insert(0, 1, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(-1, 0, false, true) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(-2, 50, false, true) && UT_ASSERT_CHECK_SHOW(span, 5));
    UT_ASSERT(span.insert(-2, 105, true, true) && UT_ASSERT_CHECK_SHOW(span, 1));

    // Check right span insertions.
    span = a_crSpan;
    UT_ASSERT(span.insert(100, 101, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(100, 102, true, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(60, 103, true, false) && UT_ASSERT_CHECK_SHOW(span, 5));
    UT_ASSERT(span.insert(-2, 105, true, true) && UT_ASSERT_CHECK_SHOW(span, 1));

    // Check inside span insertions.
    span = a_crSpan;
    UT_ASSERT(span.insert(35, 75, false, false) && UT_ASSERT_CHECK_SHOW(span, 5));
    span = a_crSpan;
    UT_ASSERT(span.insert(30, 80, true, true) && UT_ASSERT_CHECK_SHOW(span, 5));

    // Check complex joining insertions.
    span = a_crSpan;
    UT_ASSERT(span.insert(45, 50, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(60, 65, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(50, 60, true, true) && UT_ASSERT_CHECK_SHOW(span, 7));

    // Check inner insertions.
    span = a_crSpan;
    UT_ASSERT(span.insert(50) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(55) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(60) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(51, 59, true, true) && UT_ASSERT_CHECK_SHOW(span, 9));

    // Check close inner insertions.
    span = a_crSpan;
    UT_ASSERT(span.insert(50, 60, true, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(50, 60, false, true) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.insert(50, 60, true, true) && UT_ASSERT_CHECK_SHOW(span, 9));
  }

  // Check the remove functionality of the CSpan<Tsint>.
  void UT_ASSERT_CHECK_REMOVE(const CSpan<Tsint>& a_crSpan)
  { CALL
    CSpan<Tsint> span;

    // Check single item remove.
    span = a_crSpan;
    UT_ASSERT(span.remove(0) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(1) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(15) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(20) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(23) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(25) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(28) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(30) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(35) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(40) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(43) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(45) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(48) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(50) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(55) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(60) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(63) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(65) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(68) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(70) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(75) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(80) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(83) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(85) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(88) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(90) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(95) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(100) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(101) && UT_ASSERT_CHECK_SHOW(span, 10));

    // Check simple span remove.
    span = a_crSpan;
    UT_ASSERT(span.remove(23, 24, true, true) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(86, 89, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    span = a_crSpan;
    UT_ASSERT(span.remove(1, 20, true, true) && UT_ASSERT_CHECK_SHOW(span, 8));
    UT_ASSERT(span.remove(30, 40, true, true) && UT_ASSERT_CHECK_SHOW(span, 7));
    UT_ASSERT(span.remove(50, 60, true, true) && UT_ASSERT_CHECK_SHOW(span, 6));
    UT_ASSERT(span.remove(70, 80, true, true) && UT_ASSERT_CHECK_SHOW(span, 5));
    UT_ASSERT(span.remove(90, 100, true, true) && UT_ASSERT_CHECK_SHOW(span, 4));
    span = a_crSpan;
    UT_ASSERT(span.remove(1, 20, false, false) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(30, 40, false, false) && UT_ASSERT_CHECK_SHOW(span, 10));
    UT_ASSERT(span.remove(50, 60, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(70, 80, false, false) && UT_ASSERT_CHECK_SHOW(span, 8));
    UT_ASSERT(span.remove(90, 100, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    span = a_crSpan;
    UT_ASSERT(span.remove(1, 20, true, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(30, 40, true, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(50, 60, true, false) && UT_ASSERT_CHECK_SHOW(span, 8));
    UT_ASSERT(span.remove(70, 80, true, false) && UT_ASSERT_CHECK_SHOW(span, 7));
    UT_ASSERT(span.remove(90, 100, true, false) && UT_ASSERT_CHECK_SHOW(span, 7));
    span = a_crSpan;
    UT_ASSERT(span.remove(1, 20, false, true) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(30, 40, false, true) && UT_ASSERT_CHECK_SHOW(span, 8));
    UT_ASSERT(span.remove(50, 60, false, true) && UT_ASSERT_CHECK_SHOW(span, 7));
    UT_ASSERT(span.remove(70, 80, false, true) && UT_ASSERT_CHECK_SHOW(span, 6));
    UT_ASSERT(span.remove(90, 100, false, true) && UT_ASSERT_CHECK_SHOW(span, 6));

    // Check left span remove.
    span = a_crSpan;
    UT_ASSERT(span.remove(0, 1, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(0, 5, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(0, 10, false, true) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(0, 20, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(0, 23, false, true) && UT_ASSERT_CHECK_SHOW(span, 8));
    UT_ASSERT(span.remove(0, 48, false, true) && UT_ASSERT_CHECK_SHOW(span, 5));
    UT_ASSERT(span.remove(0, 101, false, false) && UT_ASSERT_CHECK_SHOW(span, 0));

    // Check right span remove.
    span = a_crSpan;
    UT_ASSERT(span.remove(100, 101, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(98, 101, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(93, 101, true, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(90, 101, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    UT_ASSERT(span.remove(88, 101, true, false) && UT_ASSERT_CHECK_SHOW(span, 8));
    UT_ASSERT(span.remove(63, 101, true, false) && UT_ASSERT_CHECK_SHOW(span, 5));
    UT_ASSERT(span.remove(0, 101, false, false) && UT_ASSERT_CHECK_SHOW(span, 0));

    // Check inner span remove.
    span = a_crSpan;
    UT_ASSERT(span.remove(1, 25, false, true) && UT_ASSERT_CHECK_SHOW(span, 8));
    UT_ASSERT(span.remove(30, 55, false, false) && UT_ASSERT_CHECK_SHOW(span, 6));
    UT_ASSERT(span.remove(55, 95, false, true) && UT_ASSERT_CHECK_SHOW(span, 3));

    // Check complex inner span remove.
    span = a_crSpan;
    UT_ASSERT(span.remove(35, 43, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    span = a_crSpan;
    UT_ASSERT(span.remove(35, 45, false, false) && UT_ASSERT_CHECK_SHOW(span, 9));
    span = a_crSpan;
    UT_ASSERT(span.remove(35, 45, false, true) && UT_ASSERT_CHECK_SHOW(span, 8));
    span = a_crSpan;
    UT_ASSERT(span.remove(35, 48, false, false) && UT_ASSERT_CHECK_SHOW(span, 8));
    span = a_crSpan;
    UT_ASSERT(span.remove(35, 60, false, false) && UT_ASSERT_CHECK_SHOW(span, 7));
    span = a_crSpan;
    UT_ASSERT(span.remove(35, 63, false, false) && UT_ASSERT_CHECK_SHOW(span, 7));
    span = a_crSpan;
    UT_ASSERT(span.remove(35, 75, false, false) && UT_ASSERT_CHECK_SHOW(span, 6));
    span = a_crSpan;
    UT_ASSERT(span.remove(35, 100, false, false) && UT_ASSERT_CHECK_SHOW(span, 4));
  }

  // Check the random insert/remove functionality of the CSpan<Tsint>.
  Tbool UT_ASSERT_CHECK_RANDOM(const Tuint a_cCount)
  { CALL
    CRandomGenerator generator;
    CSpan<Tsint> span;

    Tuint count = a_cCount;
    while (count-- > 0)
    {
      // Choose the action (insert/remove).
      Tbool insert = ((generator.randomInteger() % 2) == 0);

      // Choose the span values.
      Tuint a = (generator.randomInteger() % 100);
      Tuint b = (generator.randomInteger() % 100);
      Tbool include_a = ((generator.randomInteger() % 2) == 0);
      Tbool include_b = ((generator.randomInteger() % 2) == 0);

      // Perform an action.
      if (insert)
      {
        // UT_LOG(STR("insert: %x%i, %i%x") COMMA (include_a ? STR('[') : STR('(')) COMMA a COMMA b COMMA (include_b ? STR(']') : STR(')')));
        UT_ASSERT(span.insert(a, b, include_a, include_b));
      }
      else
      {
        // UT_LOG(STR("remove: %x%i, %i%x") COMMA (include_a ? STR('[') : STR('(')) COMMA a COMMA b COMMA (include_b ? STR(']') : STR(')')));
        UT_ASSERT(span.remove(a, b, include_a, include_b));
      }

      // Perform a span content test.
      UT_ASSERT(UT_ASSERT_CHECK_SHOW(span, 0, false));

      UT_CONRET(false);
    }
    return true;
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION(CSpan<Tsint>& a_rSpan)
  { CALL
    Tuint size = a_rSpan.getSize();

    // Check span before serialization.
    UT_ASSERT(UT_ASSERT_CHECK_SHOW(a_rSpan, size));

    // Save instance.
    SaveArchive saver;
    UT_ASSERT(saver.open());
    UT_ASSERT(saver.serialize(a_rSpan));
    UT_ASSERT(saver.close());

    // Load instance.
    LoadArchive loader;
    UT_ASSERT(loader.open());
    UT_ASSERT(loader.serialize(a_rSpan));
    UT_ASSERT(loader.close());

    // Check span after serialization.
    UT_ASSERT(UT_ASSERT_CHECK_SHOW(a_rSpan, size));
  }
} the_Test;
/*==========================================================================*/
