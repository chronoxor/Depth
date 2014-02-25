/*!
 *  \file    test-geometry-CPoint2D.cpp Testing of the CPoint2D class.
 *  \brief   Testing of the CPoint2D class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CPoint2D class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry tests
    VERSION:   1.0
    CREATED:   24.06.2008 22:57:23

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
    CPoint2D<Tsint> point;
    UT_ASSERT_EQUAL_POINTS(point, 0, 0);

    point.set(10, 20);
    UT_ASSERT_EQUAL_POINTS(point, 10, 20);

    point.negate();
    UT_ASSERT_EQUAL_POINTS(point, -10, -20);

    point.absolute();
    UT_ASSERT_EQUAL_POINTS(point, 10, 20);

    point += 20;
    UT_ASSERT_EQUAL_POINTS(point, 30, 40);

    point -= 50;
    UT_ASSERT_EQUAL_POINTS(point, -20, -10);

    point.clear();
    UT_ASSERT_EQUAL_POINTS(point, 0, 0);

    UT_ACCEPT;
  }

  // Compare instance of CPoint2D<Tsint> class with separate point's coordinates.
  void UT_ASSERT_EQUAL_POINTS(const CPoint2D<Tsint>& point, const Tsint x, const Tsint y)
  {
    UT_ASSERT_EQUAL(point.m_X, x);
    UT_ASSERT_EQUAL(point.m_Y, y);
  }
} the_Test;
/*==========================================================================*/
