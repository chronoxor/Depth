/*!
 *  \file    test-time-CTimeStamp.cpp Testing of the CTimeStamp class.
 *  \brief   Testing of the CTimeStamp class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CTimeStamp class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth time tests
    VERSION:   1.0
    CREATED:   22.02.2010 03:39:20

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
// Temporary headers.
#include <Depth/todo/serialize/serialize.hpp>
/*--------------------------------------------------------------------------*/
// Common headers.
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/time/CTimeStamp.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NMath;
using namespace NDepth::NTime;
using namespace NDepth::NSerialization;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    // Check time stamp defualt constructor.
    CTimeStamp timestamp1;
    UT_ASSERT_LESS(134774, timestamp1.getClearDays());

    // Check time stamp initialization constructor.
    CTimeStamp timestamp2(500, 25, 35, 20, 3000);
    UT_ASSERT_EQUAL(timestamp2.getClearMilliseconds(), 500);
    UT_ASSERT_EQUAL(timestamp2.getClearSeconds(), 25);
    UT_ASSERT_EQUAL(timestamp2.getClearMinutes(), 35);
    UT_ASSERT_EQUAL(timestamp2.getClearHours(), 20);
    UT_ASSERT_EQUAL(timestamp2.getClearDays(), 3000);

    CTimeStamp processStart = CTimeStamp::getProcessTimeStamp();

    // Perform some job...
    for (Tuint i = 0; i < 1000000; ++i)
    {
      Treal job = CMath::sin(CONSTR(0.65)) * CMath::cos(CONSTR(0.65));

      IGNORE_UNUSED(job);
    }

    CTimeStamp processEnd = CTimeStamp::getProcessTimeStamp();

    // Check process time stamp.
    UT_ASSERT_LESS_EQUAL(processStart, processEnd);

    CTimeStamp system;

    // Check system time stamp in UTC time.
    system = CTimeStamp::getSystemTimeStamp(true);
    UT_ASSERT_LESS(134774, system.getClearDays());

    // Check system time stamp in local time.
    system = CTimeStamp::getSystemTimeStamp(false);
    UT_ASSERT_LESS(134774, system.getClearDays());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
