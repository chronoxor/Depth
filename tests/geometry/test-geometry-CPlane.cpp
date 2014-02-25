/*!
 *  \file    test-geometry-CPlane.cpp Testing of the CPlane class.
 *  \brief   Testing of the CPlane class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CPlane class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry tests
    VERSION:   1.0
    CREATED:   14.07.2008 23:26:22

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
#include <Depth/include/geometry/CPlane.hpp>
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
    // Check plane's creation.
    CPlane plane1(1.0, 0.0, 0.0, -20.0);
    UT_ASSERT_EQUAL_VECTORS(plane1.m_Normal, CVector3D(1.0, 0.0, 0.0));
    UT_ASSERT_DELTA(plane1.m_Distance, 20.0, 0.0001);
    CPlane plane2(CVector3D(0.0, 0.0, 10.0));
    UT_ASSERT_EQUAL_VECTORS(plane2.m_Normal, CVector3D(0.0, 0.0, 1.0));
    UT_ASSERT_DELTA(plane2.m_Distance, 10.0, 0.0001);
    CPlane plane3(CVector3D(0.0, 10.0, 0.0), 100.0);
    UT_ASSERT_EQUAL_VECTORS(plane3.m_Normal, CVector3D(0.0, 1.0, 0.0));
    UT_ASSERT_DELTA(plane3.m_Distance, 100.0, 0.0001);
    CPlane plane4(CVector3D(0.0, 10.0, 0.0), CPoint3D<Treal>(10.0, 1.0, 10.0));
    UT_ASSERT_EQUAL_VECTORS(plane4.m_Normal, CVector3D(0.0, 1.0, 0.0));
    UT_ASSERT_DELTA(plane4.m_Distance, 1.0, 0.0001);
    CPlane plane5(CPoint3D<Treal>(0.0, 1.0, 0.0), CPoint3D<Treal>(10.0, 1.0, 0.0), CPoint3D<Treal>(10.0, 1.0, 10.0));
    UT_ASSERT_EQUAL_VECTORS(plane5.m_Normal, CVector3D(0.0, 1.0, 0.0));
    UT_ASSERT_DELTA(plane5.m_Distance, 1.0, 0.0001);

    // Check negating plane's direction and distance.
    CPlane plane(CVector3D(0.0, -1.0, 0.0), -1.0);
    plane.negate();
    UT_ASSERT_EQUAL_VECTORS(plane.m_Normal, CVector3D(0.0, 1.0, 0.0));
    UT_ASSERT_DELTA(plane.m_Distance, 1.0, 0.0001);

    // Check plane's tangent vector.
    CVector3D tangent = plane.getTangent();
    UT_ASSERT_EQUAL_VECTORS(tangent, CVector3D(0.0, 1.0, 0.0));

    // Check closest point to the plane.
    Treal distance;
    CPoint3D<Treal> closest;
    closest = plane.getClosestPoint(CPoint3D<Treal>(10.0, 6.0, 10.0), distance);
    UT_ASSERT_EQUAL_POINTS(closest, CPoint3D<Treal>(10.0, 1.0, 10.0));
    UT_ASSERT_DELTA(distance, 5.0, 0.0001);
    closest = plane.getClosestPoint(CPoint3D<Treal>(10.0, 0.0, 10.0), distance);
    UT_ASSERT_EQUAL_POINTS(closest, CPoint3D<Treal>(10.0, 1.0, 10.0));
    UT_ASSERT_DELTA(distance, -1.0, 0.0001);

    // Check plane intersection methods.
    Treal offset;
    CRay3D ray;
    UT_ASSERT_LESS(plane.isIntersect(CPoint3D<Treal>(0.0, 0.0, 0.0)), 0.0);
    UT_ASSERT_EQUAL(plane.isIntersect(CPoint3D<Treal>(0.0, 1.0, 0.0)), 0.0);
    UT_ASSERT_MORE(plane.isIntersect(CPoint3D<Treal>(0.0, 2.0, 0.0)), 0.0);
    UT_ASSERT(plane.isIntersect(CRay3D(CPoint3D<Treal>(0.0, 2.0, 0.0), CVector3D(0.0, -1.0, 0.0))));
    UT_ASSERT(plane.isIntersect(CRay3D(CPoint3D<Treal>(0.0, -1.0, 0.0), CVector3D(0.0, -1.0, 0.0))));
    UT_ASSERT(!plane.isIntersect(CRay3D(CPoint3D<Treal>(0.0, 2.0, 0.0), CVector3D(1.0, 0.0, 0.0))));
    UT_ASSERT(!plane.isIntersect(CRay3D(CPoint3D<Treal>(0.0, 1.0, 0.0), CVector3D(1.0, 0.0, 0.0))));
    UT_ASSERT(!plane.isIntersect(CRay3D(CPoint3D<Treal>(0.0, -1.0, 0.0), CVector3D(1.0, 0.0, 0.0))));
    UT_ASSERT(plane.isIntersect(CRay3D(CPoint3D<Treal>(0.0, 2.0, 0.0), CVector3D(0.0, -1.0, 0.0)), offset));
    UT_ASSERT_DELTA(offset, 1.0, 0.0001);
    UT_ASSERT(plane.isIntersect(CRay3D(CPoint3D<Treal>(0.0, -1.0, 0.0), CVector3D(0.0, -1.0, 0.0)), offset));
    UT_ASSERT_DELTA(offset, -2.0, 0.0001);
    UT_ASSERT(plane.isIntersect(CPlane(CVector3D(1.0, 0.0, 0.0))));
    UT_ASSERT(!plane.isIntersect(CPlane(CVector3D(0.0, 1.0, 0.0))));
    UT_ASSERT(plane.isIntersect(CPlane(CVector3D(1.0, 0.0, 0.0)), ray));
    UT_ASSERT_EQUAL_POINTS(ray.m_Origin, CPoint3D<Treal>(1.0, 1.0, 0.0));
    UT_ASSERT_EQUAL_VECTORS(ray.m_Direction, CVector3D(0.0, 0.0, -1.0));

    // Check point mirroring.
    CPoint3D<Treal> mirror;
    UT_ASSERT_LESS(plane.mirrorPoint(CPoint3D<Treal>(10.0, 6.0, 10.0), mirror), 0.0);
    UT_ASSERT_EQUAL_POINTS(mirror, CPoint3D<Treal>(10.0, -4.0, 10.0));

    // Check point mirroring through matrix.
    CMatrix4D mirrorMatrix = plane.getMirrorMatrix();
    mirror = mirrorMatrix.transform(CPoint3D<Treal>(10.0, 6.0, 10.0));
    UT_ASSERT_EQUAL_POINTS(mirror, CPoint3D<Treal>(10.0, -4.0, 10.0));

    // Check point projection.
    CPoint3D<Treal> projection;
    UT_ASSERT_MORE(plane.projectOrtho(CVector3D(-1.0, -1.0, -1.0), CPoint3D<Treal>(2.0, 2.0, 2.0), projection), 0.0);
    UT_ASSERT_EQUAL_POINTS(projection, CPoint3D<Treal>(1.0, 1.0, 1.0));
    UT_ASSERT_LESS(plane.projectOrtho(CVector3D(-1.0, -1.0, -1.0), CPoint3D<Treal>(0.0, 0.0, 0.0), projection), 0.0);
    UT_ASSERT_EQUAL_POINTS(projection, CPoint3D<Treal>(1.0, 1.0, 1.0));
    UT_ASSERT_LESS(plane.projectOrtho(CVector3D(1.0, 1.0, 1.0), CPoint3D<Treal>(-2.0, -2.0, -2.0), projection), 0.0);
    UT_ASSERT_EQUAL_POINTS(projection, CPoint3D<Treal>(1.0, 1.0, 1.0));
    UT_ASSERT_MORE(plane.projectOrtho(CVector3D(1.0, 1.0, 1.0), CPoint3D<Treal>(2.0, 2.0, 2.0), projection), 0.0);
    UT_ASSERT_EQUAL_POINTS(projection, CPoint3D<Treal>(1.0, 1.0, 1.0));

    // Check point projection through matrix.
    CMatrix4D projMatrix = plane.getOrthoProjectMatrix(CVector3D(-1.0, -1.0, -1.0));
    projection = projMatrix.transform(CPoint3D<Treal>(2.0, 2.0, 2.0));
    UT_ASSERT_EQUAL_POINTS(projection, CPoint3D<Treal>(1.0, 1.0, 1.0));

    // Check plane rotation.
    CPlane rotated(plane);
    rotated.rotate(CMatrix3D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2));
    UT_ASSERT_EQUAL_VECTORS(rotated.m_Normal, CVector3D(-1.0, 0.0, 0.0));
    UT_ASSERT_DELTA(rotated.m_Distance, 1.0, 0.0001);

    // Check plane transformation.
    CPlane transformed(plane);
    transformed.transform(CMatrix4D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2) * CMatrix4D::translate(2.0, 4.0, 8.0));
    UT_ASSERT_EQUAL_VECTORS(transformed.m_Normal, CVector3D(-1.0, 0.0, 0.0));
    UT_ASSERT_DELTA(transformed.m_Distance, -1.0, 0.0001);

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
