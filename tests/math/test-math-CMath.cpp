/*!
 *  \file    test-math-CMath.cpp Testing of the CMath class.
 *  \brief   Testing of the CMath class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CMath class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth math tests
    VERSION:   1.0
    CREATED:   09.09.2008 01:26:36

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
#include <Depth/include/math/CMath.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NMath;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    // Check real numbers states.
    UT_ASSERT(CMath::isNormal(0.5));
    UT_ASSERT(CMath::isInfinite(CMath::getPosInf()));
    UT_ASSERT(CMath::isInfinite(CMath::getNegInf()));
    UT_ASSERT(CMath::isPosInf(CMath::getPosInf()));
    UT_ASSERT(CMath::isNegInf(CMath::getNegInf()));
    UT_ASSERT(CMath::isNan(CMath::getQNan()));
    UT_ASSERT(CMath::isNan(CMath::getSNan()));
    UT_ASSERT(CMath::isQNan(CMath::getQNan()));

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
