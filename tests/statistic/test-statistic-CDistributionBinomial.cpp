/*!
 *  \file    test-statistic-CDistributionBinomial.cpp Testing of the
 *           CDistributionBinomial class.
 *  \brief   Testing of the CDistributionBinomial class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CDistributionBinomial class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth statistic tests
    VERSION:   1.0
    CREATED:   06.03.2009 03:53:17

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
#include <Depth/include/statistic/CDistributionBinomial.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NMath;
using namespace NDepth::NStatistic;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CDistributionBinomial binomial_distribution(0.5, 20);

    // Check random number generator in the distribution.
    UT_ASSERT(binomial_distribution.isValidGenerator());

    // Check binomial distributed values.
    for (Tuint i = 0; i < 1000; ++i)
    {
      Treal x = binomial_distribution.randomReal();
      UT_ASSERT(CMath::isNormal(x));
      UT_ASSERT_EQUAL(x, CMath::ceil(x));
      UT_ASSERT_EQUAL(x, CMath::floor(x));
      UT_ASSERT_LIMIT(0.0, 20.0, x);
    }

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
