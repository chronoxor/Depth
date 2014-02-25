/*!
 *  \file    test-geometry-CMatrix2D.cpp Testing of the CMatrix2D class.
 *  \brief   Testing of the CMatrix2D class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CMatrix2D class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry tests
    VERSION:   1.0
    CREATED:   03.07.2008 00:32:36

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
#include <Depth/include/geometry/CMatrix2D.hpp>
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
    UT_ASSERT_EQUAL_VECTORS(CMatrix2D::identity().transform(CVector2D(1.0, 1.0)), CVector2D(1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix2D::scale(2.0, 4.0).transform(CVector2D(1.0, 1.0)), CVector2D(2.0, 4.0));
    UT_ASSERT_EQUAL_VECTORS(CMatrix2D::rotate(CMathConstants::PI_2).transform(CVector2D(1.0, 1.0)), CVector2D(-1.0, 1.0));
    UT_ASSERT_EQUAL_VECTORS((CMatrix2D::rotate(CMathConstants::PI_2) * CMatrix2D::scale(2.0, 4.0)).transform(CVector2D(1.0, 1.0)), CVector2D(-2.0, 4.0));

    // Check invert matrix rotation.
    UT_ASSERT_DELTA(CMatrix2D::rotate(CMathConstants::PI_2).getRotateAngle(), CMathConstants::PI_2, 0.0001);

    // Check invert matrix transformations.
    CMatrix2D matrix = CMatrix2D::rotate(CMathConstants::PI_2) * CMatrix2D::scale(2.0, 4.0);
    UT_ASSERT_EQUAL_MATRIXES((matrix * CMatrix2D::invert(matrix)), CMatrix2D::identity());

    UT_ACCEPT;
  }

  // Compare two instances of CMatrix2D class.
  void UT_ASSERT_EQUAL_MATRIXES(const CMatrix2D& m1, const CMatrix2D& m2)
  {
    const Treal delta = CONSTR(0.0001);
    UT_ASSERT_DELTA(m1.m_M[0][0], m2.m_M[0][0], delta);
    UT_ASSERT_DELTA(m1.m_M[0][1], m2.m_M[0][1], delta);
    UT_ASSERT_DELTA(m1.m_M[1][0], m2.m_M[1][0], delta);
    UT_ASSERT_DELTA(m1.m_M[1][1], m2.m_M[1][1], delta);
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
