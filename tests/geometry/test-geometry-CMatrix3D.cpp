/*!
 *  \file    test-geometry-CMatrix3D.cpp Testing of the CMatrix3D class.
 *  \brief   Testing of the CMatrix3D class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CMatrix3D class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry tests
    VERSION:   1.0
    CREATED:   03.07.2008 22:21:17

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
#include <Depth/include/geometry/CMatrix3D.hpp>
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
    // Check matrix transformations.
    UT_ASSERT_EQUAL_VECTORS(CMatrix3D::identity().transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(1.0, 1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix3D::scale(2.0, 4.0, 6.0).transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(2.0, 4.0, 6.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix3D::rotate(CVector3D(1.0, 0.0, 0.0), CMathConstants::PI_2).transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(1.0, -1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix3D::rotate(CVector3D(0.0, 1.0, 0.0), CMathConstants::PI_2).transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(1.0, 1.0, -1.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix3D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2).transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(-1.0, 1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix3D::rotateX(CMathConstants::PI_2).transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(1.0, -1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix3D::rotateY(CMathConstants::PI_2).transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(1.0, 1.0, -1.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix3D::rotateZ(CMathConstants::PI_2).transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(-1.0, 1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix3D::rotateXYZ(CMathConstants::PI_2, 0.0, 0.0).transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(1.0, -1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix3D::rotateYXZ(0.0, CMathConstants::PI_2, 0.0).transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(1.0, 1.0, -1.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix3D::rotateZYX(0.0, 0.0, CMathConstants::PI_2).transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(-1.0, 1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS((CMatrix3D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2) * CMatrix3D::scale(2.0, 4.0, 6.0)).transform(CVector3D(1.0, 1.0, 1.0)), CVector3D(-2.0, 4.0, 6.0));

    // Check invert matrix rotation.
    Treal angle;
    CVector3D axis;
    CMatrix3D::rotate(CVector3D(1.0, 0.0, 0.0), CMathConstants::PI_2).getRotateAxisAngle(axis, angle);
    UT_ASSERT_EQUAL_VECTORS(axis, CVector3D(1.0, 0.0, 0.0));
    UT_ASSERT_DELTA(angle, CMathConstants::PI_2, 0.0001);
    CMatrix3D::rotate(CVector3D(0.0, 1.0, 0.0), CMathConstants::PI_2).getRotateAxisAngle(axis, angle);
    UT_ASSERT_EQUAL_VECTORS(axis, CVector3D(0.0, 1.0, 0.0));
    UT_ASSERT_DELTA(angle, CMathConstants::PI_2, 0.0001);
    CMatrix3D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2).getRotateAxisAngle(axis, angle);
    UT_ASSERT_EQUAL_VECTORS(axis, CVector3D(0.0, 0.0, 1.0));
    UT_ASSERT_DELTA(angle, CMathConstants::PI_2, 0.0001);

    // Check axis ordered invert matrix rotation.
    Treal angleX, angleY, angleZ;
    CMatrix3D::rotateXYZ(CMathConstants::PI_2, 0.0, 0.0).getRotateAnglesXYZ(angleX, angleY, angleZ);
    UT_ASSERT_DELTA(angleX, CMathConstants::PI_2, 0.0001);
    UT_ASSERT_DELTA(angleY, 0.0, 0.0001);
    UT_ASSERT_DELTA(angleZ, 0.0, 0.0001);
    CMatrix3D::rotateYXZ(0.0, CMathConstants::PI_2, 0.0).getRotateAnglesXYZ(angleX, angleY, angleZ);
    UT_ASSERT_DELTA(angleX, 0.0, 0.0001);
    UT_ASSERT_DELTA(angleY, CMathConstants::PI_2, 0.0001);
    UT_ASSERT_DELTA(angleZ, 0.0, 0.0001);
    CMatrix3D::rotateZYX(0.0, 0.0, CMathConstants::PI_2).getRotateAnglesXYZ(angleX, angleY, angleZ);
    UT_ASSERT_DELTA(angleX, 0.0, 0.0001);
    UT_ASSERT_DELTA(angleY, 0.0, 0.0001);
    UT_ASSERT_DELTA(angleZ, CMathConstants::PI_2, 0.0001);

    // Check invert matrix transformations.
    CMatrix3D matrix = CMatrix3D::rotate(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2) * CMatrix3D::scale(2.0, 4.0, 6.0);
    UT_ASSERT_EQUAL_MATRIXES((matrix * CMatrix3D::invert(matrix)), CMatrix3D::identity());

    UT_ACCEPT;
  }

  // Compare two instances of CMatrix3D class.
  void UT_ASSERT_EQUAL_MATRIXES(const CMatrix3D& m1, const CMatrix3D& m2)
  {
    const Treal delta = CONSTR(0.0001);
    UT_ASSERT_DELTA(m1.m_M[0][0], m2.m_M[0][0], delta);
    UT_ASSERT_DELTA(m1.m_M[0][1], m2.m_M[0][1], delta);
    UT_ASSERT_DELTA(m1.m_M[0][2], m2.m_M[0][2], delta);
    UT_ASSERT_DELTA(m1.m_M[1][0], m2.m_M[1][0], delta);
    UT_ASSERT_DELTA(m1.m_M[1][1], m2.m_M[1][1], delta);
    UT_ASSERT_DELTA(m1.m_M[1][2], m2.m_M[1][2], delta);
    UT_ASSERT_DELTA(m1.m_M[2][0], m2.m_M[2][0], delta);
    UT_ASSERT_DELTA(m1.m_M[2][1], m2.m_M[2][1], delta);
    UT_ASSERT_DELTA(m1.m_M[2][2], m2.m_M[2][2], delta);
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
