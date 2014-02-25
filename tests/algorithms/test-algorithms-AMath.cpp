/*!
 *  \file    test-algorithms-AMath.cpp Testing of the math algorithms.
 *  \brief   Testing of the math algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the math algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   18.01.2007 00:09:28

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
#include <Depth/include/algorithms/math/ASqrt.hpp>
#include <Depth/include/algorithms/math/ALn.hpp>
#include <Depth/include/algorithms/math/ALog.hpp>
#include <Depth/include/algorithms/math/ASin.hpp>
#include <Depth/include/algorithms/math/ACos.hpp>
#include <Depth/include/algorithms/math/ATan.hpp>
#include <Depth/include/algorithms/math/AASin.hpp>
#include <Depth/include/algorithms/math/AACos.hpp>
#include <Depth/include/algorithms/math/AATan.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_DELTA(NAlgorithms::NMath::sqrt(20.0), 4.472136, 0.0001);
    UT_ASSERT_DELTA(NAlgorithms::NMath::ln(20.0), 2.995732, 0.0001);
    UT_ASSERT_DELTA(NAlgorithms::NMath::log(20.0, 30.0), 0.880787, 0.0001);
    UT_ASSERT_DELTA(NAlgorithms::NMath::sin(20.0), 0.912945, 0.0001);
    UT_ASSERT_DELTA(NAlgorithms::NMath::cos(20.0), 0.408082, 0.0001);
    UT_ASSERT_DELTA(NAlgorithms::NMath::tan(20.0), 2.237157, 0.0001);
    UT_ASSERT_DELTA(NAlgorithms::NMath::asin(0.5), 0.523598, 0.0001);
    UT_ASSERT_DELTA(NAlgorithms::NMath::acos(0.5), 1.047197, 0.0001);
    UT_ASSERT_DELTA(NAlgorithms::NMath::atan(0.5), 0.463647, 0.0001);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
