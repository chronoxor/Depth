/*!
 *  \file    test-geometry-CQuaternion.cpp Testing of the CQuaternion class.
 *  \brief   Testing of the CQuaternion class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CQuaternion class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry tests
    VERSION:   1.0
    CREATED:   08.07.2008 20:38:15

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
#include <Depth/include/geometry/CQuaternion.hpp>
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
    // Check quaternion transformations.
    UT_ASSERT_EQUAL_VECTORS(CQuaternion::rotateAxisAngle(CVector3D(1.0, 0.0, 0.0), CMathConstants::PI_2).rotate(CVector3D(1.0, 1.0, 1.0)), CVector3D(1.0, -1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS(CQuaternion::rotateAxisAngle(CVector3D(0.0, 1.0, 0.0), CMathConstants::PI_2).rotate(CVector3D(1.0, 1.0, 1.0)), CVector3D(1.0, 1.0, -1.0));
    UT_ASSERT_EQUAL_VECTORS(CQuaternion::rotateAxisAngle(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2).rotate(CVector3D(1.0, 1.0, 1.0)), CVector3D(-1.0, 1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS(CQuaternion::rotateAnglesXYZ(CMathConstants::PI_2, 0.0, 0.0).rotate(CVector3D(1.0, 1.0, 1.0)), CVector3D(1.0, -1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS(CQuaternion::rotateAnglesXYZ(0.0, CMathConstants::PI_2, 0.0).rotate(CVector3D(1.0, 1.0, 1.0)), CVector3D(1.0, 1.0, -1.0));
    UT_ASSERT_EQUAL_VECTORS(CQuaternion::rotateAnglesXYZ(0.0, 0.0, CMathConstants::PI_2).rotate(CVector3D(1.0, 1.0, 1.0)), CVector3D(-1.0, 1.0, 1.0));

    // Check invert quaternion rotation.
    Treal angle;
    CVector3D axis;
    CQuaternion::rotateAxisAngle(CVector3D(1.0, 0.0, 0.0), CMathConstants::PI_2).getRotateAxisAngle(axis, angle);
    UT_ASSERT_EQUAL_VECTORS(axis, CVector3D(1.0, 0.0, 0.0));
    UT_ASSERT_DELTA(angle, CMathConstants::PI_2, 0.0001);
    CQuaternion::rotateAxisAngle(CVector3D(0.0, 1.0, 0.0), CMathConstants::PI_2).getRotateAxisAngle(axis, angle);
    UT_ASSERT_EQUAL_VECTORS(axis, CVector3D(0.0, 1.0, 0.0));
    UT_ASSERT_DELTA(angle, CMathConstants::PI_2, 0.0001);
    CQuaternion::rotateAxisAngle(CVector3D(0.0, 0.0, 1.0), CMathConstants::PI_2).getRotateAxisAngle(axis, angle);
    UT_ASSERT_EQUAL_VECTORS(axis, CVector3D(0.0, 0.0, 1.0));
    UT_ASSERT_DELTA(angle, CMathConstants::PI_2, 0.0001);

    // Check axis ordered invert quaternion rotation.
    Treal angleX, angleY, angleZ;
    CQuaternion::rotateAnglesXYZ(CMathConstants::PI_2, 0.0, 0.0).getRotateAnglesXYZ(angleX, angleY, angleZ);
    UT_ASSERT_DELTA(angleX, CMathConstants::PI_2, 0.0001);
    UT_ASSERT_DELTA(angleY, 0.0, 0.0001);
    UT_ASSERT_DELTA(angleZ, 0.0, 0.0001);
    CQuaternion::rotateAnglesXYZ(0.0, 0.0, CMathConstants::PI_2).getRotateAnglesXYZ(angleX, angleY, angleZ);
    UT_ASSERT_DELTA(angleX, 0.0, 0.0001);
    UT_ASSERT_DELTA(angleY, 0.0, 0.0001);
    UT_ASSERT_DELTA(angleZ, CMathConstants::PI_2, 0.0001);

    // Check quaternion to/from matrix transformations.
    CQuaternion quaternion = CQuaternion::rotateAxisAngle(CVector3D(1.0, 1.0, 1.0), CMathConstants::PI_2);
    CMatrix3D matrix = CMatrix3D::rotate(CVector3D(1.0, 1.0, 1.0), CMathConstants::PI_2);
    UT_ASSERT_EQUAL_MATRIXES(matrix, quaternion.getMatrix3D());
    UT_ASSERT_EQUAL_QUATERNIONS(quaternion, CQuaternion::matrix(matrix));

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

  // Compare two instances of CQuaternion class.
  void UT_ASSERT_EQUAL_QUATERNIONS(const CQuaternion& q1, const CQuaternion& q2)
  {
    const Treal delta = CONSTR(0.0001);
    UT_ASSERT_DELTA(q1.m_X, q2.m_X, delta);
    UT_ASSERT_DELTA(q1.m_Y, q2.m_Y, delta);
    UT_ASSERT_DELTA(q1.m_Z, q2.m_Z, delta);
    UT_ASSERT_DELTA(q1.m_W, q2.m_W, delta);
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
