/*!
 *  \file    test-geometry-CRay2D.cpp Testing of the CRay2D class.
 *  \brief   Testing of the CRay2D class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CRay2D class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry tests
    VERSION:   1.0
    CREATED:   09.07.2008 01:54:30

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
#include <Depth/include/geometry/CRay2D.hpp>
#include <Depth/include/math/CMathConstants.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NGeometry;
using namespace NDepth::NMath;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    // Check ray's creation.
    CRay2D ray(CPoint2D<Treal>(0.0, 0.0), CVector2D(-1.0, -1.0));
    UT_ASSERT_EQUAL_POINTS(ray.m_Origin, CPoint2D<Treal>(0.0, 0.0));
    UT_ASSERT_EQUAL_VECTORS(ray.m_Direction, CVector2D(-CMath::sqrt(2.0) / CONSTR(2.0), -CMath::sqrt(2.0) / CONSTR(2.0)));

    // Check negating ray's direction.
    ray.negate();
    UT_ASSERT_EQUAL_POINTS(ray.m_Origin, CPoint2D<Treal>(0.0, 0.0));
    UT_ASSERT_EQUAL_VECTORS(ray.m_Direction, CVector2D(CMath::sqrt(2.0) / CONSTR(2.0), CMath::sqrt(2.0) / CONSTR(2.0)));

    // Check offset point.
    CPoint2D<Treal> point = ray.getOffsetPoint(5.0);
    UT_ASSERT_EQUAL_POINTS(point, CPoint2D<Treal>(CONSTR(5.0) * CMath::sqrt(2.0) / CONSTR(2.0), CONSTR(5.0) * CMath::sqrt(2.0) / CONSTR(2.0)));

    // Check distance to point.
    Treal distance = ray.getDistanceToPoint(CPoint2D<Treal>(0.0, 4.0));
    UT_ASSERT_DELTA(distance, CMath::sqrt(8.0), 0.0001);

    // Check mirroring relative to the ray.
    CPoint2D<Treal> mirror = ray.mirrorPoint(CPoint2D<Treal>(2.0, 6.0));
    UT_ASSERT_EQUAL_POINTS(mirror, CPoint2D<Treal>(6.0, 2.0));

    // Check projection on the ray.
    CPoint2D<Treal> projection = ray.project(CPoint2D<Treal>(6.0, 0.0));
    UT_ASSERT_EQUAL_POINTS(projection, CPoint2D<Treal>(3.0, 3.0));

    // Check ray rotation.
    CRay2D rotated(ray);
    rotated.rotate(CMatrix2D::rotate(CMathConstants::PI_2));
    UT_ASSERT_EQUAL_POINTS(rotated.m_Origin, CPoint2D<Treal>(0.0, 0.0));
    UT_ASSERT_EQUAL_VECTORS(rotated.m_Direction, CVector2D(-CMath::sqrt(2.0) / CONSTR(2.0), CMath::sqrt(2.0) / CONSTR(2.0)));

    // Check ray transformation.
    CRay2D transformed(ray);
    transformed.transform(CMatrix3D::rotate2D(CMathConstants::PI_2) * CMatrix3D::translate2D(2.0, 4.0));
    UT_ASSERT_EQUAL_POINTS(transformed.m_Origin, CPoint2D<Treal>(2.0, 4.0));
    UT_ASSERT_EQUAL_VECTORS(transformed.m_Direction, CVector2D(-CMath::sqrt(2.0) / CONSTR(2.0), CMath::sqrt(2.0) / CONSTR(2.0)));

    // Check ray to ray intersection states.
    UT_ASSERT(CRay2D::isCollinear(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(0.0, 1.0), CVector2D(1.0, 1.0))));
    UT_ASSERT(CRay2D::isCollinear(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(1.0, 1.0), CVector2D(1.0, 1.0))));
    UT_ASSERT(!CRay2D::isCollinear(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(-1.0, 1.0), CVector2D(1.0, -1.0))));
    UT_ASSERT(!CRay2D::isCollinear(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(1.0, -1.0), CVector2D(1.0, -1.0))));
    UT_ASSERT(!CRay2D::isIntersect(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(0.0, 1.0), CVector2D(1.0, 1.0))));
    UT_ASSERT(!CRay2D::isIntersect(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(1.0, 1.0), CVector2D(1.0, 1.0))));
    UT_ASSERT(CRay2D::isIntersect(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(-1.0, 1.0), CVector2D(1.0, -1.0))));
    UT_ASSERT(CRay2D::isIntersect(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(1.0, -1.0), CVector2D(1.0, -1.0))));
    UT_ASSERT(!CRay2D::isParallel(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(-1.0, 1.0), CVector2D(1.0, -1.0))));
    UT_ASSERT(!CRay2D::isParallel(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(1.0, 1.0), CVector2D(1.0, 1.0))));
    UT_ASSERT(CRay2D::isParallel(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(0.0, 1.0), CVector2D(1.0, 1.0))));
    UT_ASSERT(!CRay2D::isStraight(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(-1.0, 1.0), CVector2D(1.0, -1.0))));
    UT_ASSERT(CRay2D::isStraight(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(1.0, 1.0), CVector2D(1.0, 1.0))));
    UT_ASSERT(!CRay2D::isStraight(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(0.0, 1.0), CVector2D(1.0, 1.0))));

    // Check ray to ray intersection.
    Treal offset1, offset2;
    UT_ASSERT(CRay2D::intersect(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(-1.0, 2.0), CVector2D(1.0, -2.0)), offset1, offset2));
    UT_ASSERT_DELTA(offset1, 0.0, 0.0001);
    UT_ASSERT_DELTA(offset2, CMath::sqrt(5.0), 0.0001);
    CPoint2D<Treal> intersection;
    UT_ASSERT(CRay2D::intersect(CRay2D(CPoint2D<Treal>(0.0, 0.0), CVector2D(1.0, 1.0)), CRay2D(CPoint2D<Treal>(1.0, -1.0), CVector2D(1.0, -1.0)), intersection));
    UT_ASSERT_EQUAL_POINTS(intersection, CPoint2D<Treal>(0.0, 0.0));

    UT_ACCEPT;
  }

  // Compare two instances of CPoint2D<Treal> class.
  void UT_ASSERT_EQUAL_POINTS(const CPoint2D<Treal>& p1, const CPoint2D<Treal>& p2)
  {
    const Treal delta = CONSTR(0.0001);
    UT_ASSERT_DELTA(p1.m_X, p2.m_X, delta);
    UT_ASSERT_DELTA(p1.m_Y, p2.m_Y, delta);
  }

  // Compare two instances of CVector2D class.
  void UT_ASSERT_EQUAL_VECTORS(const CVector2D& v1, const CVector2D& v2)
  {
    const Treal delta = CONSTR(0.0001);
    UT_ASSERT_DELTA(v1.m_X, v2.m_X, delta);
    UT_ASSERT_DELTA(v1.m_Y, v2.m_Y, delta);
  }
} the_Test;
/*==========================================================================*/
