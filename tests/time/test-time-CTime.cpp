/*!
 *  \file    test-time-CTime.cpp Testing of the CTime class.
 *  \brief   Testing of the CTime class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CTime class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth time tests
    VERSION:   1.0
    CREATED:   25.02.2010 03:01:27

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
#include <Depth/include/time/CTime.hpp>
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
    // Check time defualt constructor.
    CTime time1;
    UT_ASSERT_EQUAL(time1.getClearHours(), CTime::getSystemTime(false).getClearHours());
    UT_ASSERT_EQUAL(time1.getClearMinutes(), CTime::getSystemTime(false).getClearMinutes());
    UT_ASSERT_EQUAL(time1.getClearSeconds(), CTime::getSystemTime(false).getClearSeconds());

    // Check time initialization constructor.
    CTime time2(20, 35, 25, 500);
    UT_ASSERT_EQUAL(time2.getClearHours(), 20);
    UT_ASSERT_EQUAL(time2.getClearMinutes(), 35);
    UT_ASSERT_EQUAL(time2.getClearSeconds(), 25);
    UT_ASSERT_EQUAL(time2.getClearMilliseconds(), 500);
    UT_ASSERT_EQUAL(time2.getHour(), 20);
    UT_ASSERT_EQUAL(time2.getMinute(), 35);
    UT_ASSERT_EQUAL(time2.getSecond(), 25);
    UT_ASSERT_EQUAL(time2.getMillisecond(), 500);

    // Set new system local time.
    CTime systemNew(23, 0, 0, 0);
    CTime systemOld = CTime::getSystemTime(false);
    Tbool restore = CTime::setSystemTimeLocal(systemNew);
    UT_ASSERT(restore);
    UT_ASSERT_EQUAL(systemNew.getClearHours(), CTime::getSystemTime(false).getClearHours());
    UT_ASSERT_EQUAL(systemNew.getClearMinutes(), CTime::getSystemTime(false).getClearMinutes());
    UT_ASSERT_EQUAL(systemNew.getClearSeconds(), CTime::getSystemTime(false).getClearSeconds());

    CTime processStart = CTime::getProcessTime();

    // Perform some job...
    for (Tuint i = 0; i < 1000000; ++i)
    {
      Treal job = CMath::sin(CONSTR(0.65)) * CMath::cos(CONSTR(0.65));

      IGNORE_UNUSED(job);
    }

    CTime processEnd = CTime::getProcessTime();

    // Check process time.
    UT_ASSERT_LESS_EQUAL(processStart, processEnd);

    // Restore system local time.
    if (restore)
    {
      UT_ASSERT(CTime::setSystemTimeLocal(systemOld + (processEnd - processStart)));
    }

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
