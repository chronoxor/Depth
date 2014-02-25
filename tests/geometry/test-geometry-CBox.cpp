/*!
 *  \file    test-geometry-CBox.cpp Testing of the CBox class.
 *  \brief   Testing of the CBox class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CBox class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry tests
    VERSION:   1.0
    CREATED:   24.06.2008 00:27:32

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
#include <Depth/include/geometry/CBox.hpp>
#include <Depth/include/geometry/CPoint3D.hpp>
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
    CBox<Tsint> box;
    UT_ASSERT_EQUAL_BOXES(box, 0, 0, 0, 0, 0, 0);

    box.set(10, 20, 30, 40, 50, 60);
    UT_ASSERT_EQUAL_BOXES(box, 10, 20, 30, 40, 50, 60);
    UT_ASSERT_EQUAL(box.getWidth(), 30);
    UT_ASSERT_EQUAL(box.getHeight(), 30);
    UT_ASSERT_EQUAL(box.getDepth(), 30);

    box += 20;
    UT_ASSERT_EQUAL_BOXES(box, 30, 40, 50, 60, 70, 80);

    box -= 50;
    UT_ASSERT_EQUAL_BOXES(box, -20, -10, 0, 10, 20, 30);

    box.moveBy(CPoint3D<Tsint>(10, 20, 30));
    UT_ASSERT_EQUAL_BOXES(box, -10, 10, 30, 20, 40, 60);

    box.moveTo(CPoint3D<Tsint>(0, 0, 0));
    UT_ASSERT_EQUAL_BOXES(box, 0, 0, 0, 30, 30, 30);

    box = box.getEmpty();
    UT_ASSERT_EQUAL_BOXES(box, 30, 30, 30, 0, 0, 0);
    UT_ASSERT(box.isEmpty());
    UT_ASSERT(!box.isNormal());

    box = box.getNormal();
    UT_ASSERT_EQUAL_BOXES(box, 0, 0, 0, 30, 30, 30);
    UT_ASSERT(!box.isEmpty());
    UT_ASSERT(box.isNormal());

    box.inverse();
    UT_ASSERT_EQUAL_BOXES(box, 30, 30, 30, 0, 0, 0);
    UT_ASSERT(box.isEmpty());
    UT_ASSERT(!box.isNormal());

    UT_ASSERT(box.isInside(CPoint3D<Tsint>(10, 10, 10)));
    UT_ASSERT(!box.isInside(CPoint3D<Tsint>(40, 40, 40)));
    UT_ASSERT(box.isInside(CBox<Tsint>(10, 10, 10, 15, 15, 15)));
    UT_ASSERT(!box.isInside(CBox<Tsint>(10, 10, 10, 45, 45, 45)));

    UT_ASSERT(box.isIntersect(CBox<Tsint>(10, 10, 10, 15, 15, 15)));
    UT_ASSERT(box.isIntersect(CBox<Tsint>(10, 10, 10, 45, 45, 45)));
    UT_ASSERT(!box.isIntersect(CBox<Tsint>(40, 40, 40, 65, 65, 65)));

    UT_ASSERT_EQUAL(box.getIntersection(CBox<Tsint>(10, 10, 10, 40, 40, 40)), CBox<Tsint>(10, 10, 10, 30, 30, 30));
    UT_ASSERT_EQUAL(box.getUnion(CPoint3D<Tsint>(40, 10, 0)), CBox<Tsint>(0, 0, 0, 40, 30, 30));
    UT_ASSERT_EQUAL(box.getUnion(CBox<Tsint>(10, 10, 10, 40, 40, 40)), CBox<Tsint>(0, 0, 0, 40, 40, 40));

    box.clear();
    UT_ASSERT_EQUAL_BOXES(box, 0, 0, 0, 0, 0, 0);

    UT_ACCEPT;
  }

  // Compare instance of CBox<Tsint> class with separate box coordinates.
  void UT_ASSERT_EQUAL_BOXES(const CBox<Tsint>& box, const Tsint x1, const Tsint y1, const Tsint z1, const Tsint x2, const Tsint y2, const Tsint z2)
  {
    UT_ASSERT_EQUAL(box.m_A.m_X, x1);
    UT_ASSERT_EQUAL(box.m_A.m_Y, y1);
    UT_ASSERT_EQUAL(box.m_A.m_Z, z1);
    UT_ASSERT_EQUAL(box.m_B.m_X, x2);
    UT_ASSERT_EQUAL(box.m_B.m_Y, y2);
    UT_ASSERT_EQUAL(box.m_B.m_Z, z2);
  }
} the_Test;
/*==========================================================================*/
