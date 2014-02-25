/*!
 *  \file    test-geometry-CRay3D.cpp Testing of the CRay3D class.
 *  \brief   Testing of the CRay3D class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CRay3D class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry tests
    VERSION:   1.0
    CREATED:   10.07.2008 01:39:10

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
#include <Depth/include/geometry/CRay3D.hpp>
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
    CRay3D ray(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(-1.0, -1.0, 0.0));
    UT_ASSERT_EQUAL_POINTS(ray.m_Origin, CPoint3D<Treal>(0.0, 0.0, 0.0));
    UT_ASSERT_EQUAL_VECTORS(ray.m_Direction, CVector3D(-CMath::sqrt(2.0) / CONSTR(2.0), -CMath::sqrt(2.0) / CONSTR(2.0), 0.0));

    // Check negating ray's direction.
    ray.negate();
    UT_ASSERT_EQUAL_POINTS(ray.m_Origin, CPoint3D<Treal>(0.0, 0.0, 0.0));
    UT_ASSERT_EQUAL_VECTORS(ray.m_Direction, CVector3D(CMath::sqrt(2.0) / CONSTR(2.0), CMath::sqrt(2.0) / CONSTR(2.0), 0.0));

    // Check offset point.
    CPoint3D<Treal> point = ray.getOffsetPoint(5.0);
    UT_ASSERT_EQUAL_POINTS(point, CPoint3D<Treal>(CONSTR(5.0) * CMath::sqrt(2.0) / CONSTR(2.0), CONSTR(5.0) * CMath::sqrt(2.0) / CONSTR(2.0), 0.0));

    // Check distance to point.
    Treal distance = ray.getDistanceToPoint(CPoint3D<Treal>(0.0, 4.0, 0.0));
    UT_ASSERT_DELTA(distance, CMath::sqrt(8.0), 0.0001);

    // Check mirroring relative to the ray.
    CPoint3D<Treal> mirror = ray.mirrorPoint(CPoint3D<Treal>(2.0, 6.0, 8.0));
    UT_ASSERT_EQUAL_POINTS(mirror, CPoint3D<Treal>(6.0, 2.0, -8.0));

    // Check projection on the ray.
    CPoint3D<Treal> projection = ray.project(CPoint3D<Treal>(6.0, 0.0, 0.0));
    UT_ASSERT_EQUAL_POINTS(projection, CPoint3D<Treal>(3.0, 3.0, 0.0));

    // Check ray rotation.
    CRay3D rotated(ray);
    rotated.rotate(CMatrix3D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2));
    UT_ASSERT_EQUAL_POINTS(rotated.m_Origin, CPoint3D<Treal>(0.0, 0.0, 0.0));
    UT_ASSERT_EQUAL_VECTORS(rotated.m_Direction, CVector3D(-CMath::sqrt(2.0) / CONSTR(2.0), CMath::sqrt(2.0) / CONSTR(2.0), 0.0));

    // Check ray transformation.
    CRay3D transformed(ray);
    transformed.transform(CMatrix4D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2) * CMatrix4D::translate(2.0, 4.0, 8.0));
    UT_ASSERT_EQUAL_POINTS(transformed.m_Origin, CPoint3D<Treal>(2.0, 4.0, 8.0));
    UT_ASSERT_EQUAL_VECTORS(transformed.m_Direction, CVector3D(-CMath::sqrt(2.0) / CONSTR(2.0), CMath::sqrt(2.0) / CONSTR(2.0), 0.0));

    // Check ray to ray intersection states.
    UT_ASSERT(CRay3D::isCollinear(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(0.0, 1.0, 0.0), CVector3D(1.0, 1.0, 0.0))));
    UT_ASSERT(CRay3D::isCollinear(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(1.0, 1.0, 0.0), CVector3D(1.0, 1.0, 0.0))));
    UT_ASSERT(!CRay3D::isCollinear(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(-1.0, 1.0, 0.0), CVector3D(1.0, -1.0, 0.0))));
    UT_ASSERT(!CRay3D::isCollinear(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(1.0, -1.0, 0.0), CVector3D(1.0, -1.0, 0.0))));
    UT_ASSERT(!CRay3D::isIntersect(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(0.0, 1.0, 0.0), CVector3D(1.0, 1.0, 0.0))));
    UT_ASSERT(!CRay3D::isIntersect(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(1.0, 1.0, 0.0), CVector3D(1.0, 1.0, 0.0))));
    UT_ASSERT(CRay3D::isIntersect(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(-1.0, 1.0, 0.0), CVector3D(1.0, -1.0, 0.0))));
    UT_ASSERT(CRay3D::isIntersect(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(1.0, -1.0, 0.0), CVector3D(1.0, -1.0, 0.0))));
    UT_ASSERT(!CRay3D::isParallel(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(-1.0, 1.0, 0.0), CVector3D(1.0, -1.0, 0.0))));
    UT_ASSERT(!CRay3D::isParallel(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(1.0, 1.0, 0.0), CVector3D(1.0, 1.0, 0.0))));
    UT_ASSERT(CRay3D::isParallel(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(0.0, 1.0, 0.0), CVector3D(1.0, 1.0, 0.0))));
    UT_ASSERT(!CRay3D::isStraight(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(-1.0, 1.0, 0.0), CVector3D(1.0, -1.0, 0.0))));
    UT_ASSERT(CRay3D::isStraight(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(1.0, 1.0, 0.0), CVector3D(1.0, 1.0, 0.0))));
    UT_ASSERT(!CRay3D::isStraight(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 1.0, 0.0)), CRay3D(CPoint3D<Treal>(0.0, 1.0, 0.0), CVector3D(1.0, 1.0, 0.0))));

    // Check ray to ray intersection.
    Treal offset1, offset2;
    UT_ASSERT(CRay3D::distance(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 0.0, 0.0)), CRay3D(CPoint3D<Treal>(0.0, 3.0, 3.0), CVector3D(0.0, 0.0, 1.0)), offset1, offset2));
    UT_ASSERT_DELTA(offset1, 0.0, 0.0001);
    UT_ASSERT_DELTA(offset2, -3.0, 0.0001);
    CPoint3D<Treal> point1, point2;
    UT_ASSERT(CRay3D::distance(CRay3D(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(1.0, 0.0, 0.0)), CRay3D(CPoint3D<Treal>(0.0, 3.0, 3.0), CVector3D(0.0, 0.0, 1.0)), point1, point2));
    UT_ASSERT_EQUAL_POINTS(point1, CPoint3D<Treal>(0.0, 0.0, 0.0));
    UT_ASSERT_EQUAL_POINTS(point2, CPoint3D<Treal>(0.0, 3.0, 0.0));

    UT_ACCEPT;
  }

  // Compare two instances of CPoint3D<Treal> class.
  void UT_ASSERT_EQUAL_POINTS(const CPoint3D<Treal>& p1, const CPoint3D<Treal>& p2)
  {
    const Treal delta = CONSTR(0.0001);
    UT_ASSERT_DELTA(p1.m_X, p2.m_X, delta);
    UT_ASSERT_DELTA(p1.m_Y, p2.m_Y, delta);
    UT_ASSERT_DELTA(p1.m_Z, p2.m_Z, delta);
  }

  // Compare two instances of CVector3D class.
  void UT_ASSERT_EQUAL_VECTORS(const CVector3D& v1, const CVector3D& v2)
  {
    const Treal delta = CONSTR(0.0001);
    UT_ASSERT_DELTA(v1.m_X, v2.m_X, delta);
    UT_ASSERT_DELTA(v1.m_Y, v2.m_Y, delta);
    UT_ASSERT_DELTA(v1.m_Z, v2.m_Z, delta);
  }
} the_Test;
/*==========================================================================*/
