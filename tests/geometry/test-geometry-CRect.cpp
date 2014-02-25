/*!
 *  \file    test-geometry-CRect.cpp Testing of the CRect class.
 *  \brief   Testing of the CRect class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CRect class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry tests
    VERSION:   1.0
    CREATED:   24.06.2008 00:17:56

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
#include <Depth/include/geometry/CPoint2D.hpp>
#include <Depth/include/geometry/CRect.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NGeometry;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CRect<Tsint> rect;
    UT_ASSERT_EQUAL_RECTANGLES(rect, 0, 0, 0, 0);

    rect.set(10, 20, 30, 40);
    UT_ASSERT_EQUAL_RECTANGLES(rect, 10, 20, 30, 40);
    UT_ASSERT_EQUAL(rect.getWidth(), 20);
    UT_ASSERT_EQUAL(rect.getHeight(), 20);

    rect += 20;
    UT_ASSERT_EQUAL_RECTANGLES(rect, 30, 40, 50, 60);

    rect -= 50;
    UT_ASSERT_EQUAL_RECTANGLES(rect, -20, -10, 0, 10);

    rect.moveBy(CPoint2D<Tsint>(10, 20));
    UT_ASSERT_EQUAL_RECTANGLES(rect, -10, 10, 10, 30);

    rect.moveTo(CPoint2D<Tsint>(0, 0));
    UT_ASSERT_EQUAL_RECTANGLES(rect, 0, 0, 20, 20);

    rect = rect.getEmpty();
    UT_ASSERT_EQUAL_RECTANGLES(rect, 20, 20, 0, 0);
    UT_ASSERT(rect.isEmpty());
    UT_ASSERT(!rect.isNormal());

    rect = rect.getNormal();
    UT_ASSERT_EQUAL_RECTANGLES(rect, 0, 0, 20, 20);
    UT_ASSERT(!rect.isEmpty());
    UT_ASSERT(rect.isNormal());

    rect.inverse();
    UT_ASSERT_EQUAL_RECTANGLES(rect, 20, 20, 0, 0);
    UT_ASSERT(rect.isEmpty());
    UT_ASSERT(!rect.isNormal());

    UT_ASSERT(rect.isInside(CPoint2D<Tsint>(10, 10)));
    UT_ASSERT(!rect.isInside(CPoint2D<Tsint>(30, 30)));
    UT_ASSERT(rect.isInside(CRect<Tsint>(10, 10, 15, 15)));
    UT_ASSERT(!rect.isInside(CRect<Tsint>(10, 10, 25, 25)));

    UT_ASSERT(rect.isIntersect(CRect<Tsint>(10, 10, 15, 15)));
    UT_ASSERT(rect.isIntersect(CRect<Tsint>(10, 10, 25, 25)));
    UT_ASSERT(!rect.isIntersect(CRect<Tsint>(30, 30, 45, 45)));

    UT_ASSERT_EQUAL(rect.getIntersection(CRect<Tsint>(10, 10, 30, 30)), CRect<Tsint>(10, 10, 20, 20));
    UT_ASSERT_EQUAL(rect.getUnion(CPoint2D<Tsint>(30, 10)), CRect<Tsint>(0, 0, 30, 20));
    UT_ASSERT_EQUAL(rect.getUnion(CRect<Tsint>(10, 10, 30, 30)), CRect<Tsint>(0, 0, 30, 30));

    rect.clear();
    UT_ASSERT_EQUAL_RECTANGLES(rect, 0, 0, 0, 0);

    UT_ACCEPT;
  }

  // Compare instance of CRect<Tsint> class with separate rectangle coordinates.
  void UT_ASSERT_EQUAL_RECTANGLES(const CRect<Tsint>& rect, const Tsint x1, const Tsint y1, const Tsint x2, const Tsint y2)
  {
    UT_ASSERT_EQUAL(rect.m_A.m_X, x1);
    UT_ASSERT_EQUAL(rect.m_A.m_Y, y1);
    UT_ASSERT_EQUAL(rect.m_B.m_X, x2);
    UT_ASSERT_EQUAL(rect.m_B.m_Y, y2);
  }
} the_Test;
/*==========================================================================*/
