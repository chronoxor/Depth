/*!
 *  \file    test-geometry-CViewPort.cpp Testing of the CViewPort class.
 *  \brief   Testing of the CViewPort class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CViewPort class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry tests
    VERSION:   1.0
    CREATED:   24.07.2008 02:51:32

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
#include <Depth/include/geometry/CViewPort.hpp>
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
    CViewPort viewport(0.0, 0.0, 640.0, 480.0);

    CVector3D normalized(0.0, 0.0, 0.0);
    CVector3D screen;

    UT_ASSERT(viewport.projectNormalizedToScreen(normalized, screen));
    UT_ASSERT_EQUAL_VECTORS(screen, CVector3D(320.0, 240.0, 0.5));
    UT_ASSERT(viewport.unprojectScreenToNormalized(screen, normalized));
    UT_ASSERT_EQUAL_VECTORS(normalized, CVector3D(0.0, 0.0, 0.0));
    UT_ACCEPT;
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
