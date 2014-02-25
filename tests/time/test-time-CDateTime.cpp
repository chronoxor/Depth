/*!
 *  \file    test-time-CDateTime.cpp Testing of the CDateTime class.
 *  \brief   Testing of the CDateTime class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.03.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CDateTime class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth time tests
    VERSION:   1.0
    CREATED:   04.03.2010 20:47:57

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
#include <Depth/include/time/CDateTime.hpp>
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
    // Check date & time defualt constructor.
    CDateTime date_time1;
    UT_ASSERT_EQUAL(date_time1.getDate().getClearYears(), CDateTime::getSystemDateTime(false).getDate().getClearYears());
    UT_ASSERT_EQUAL(date_time1.getDate().getClearMonths(), CDateTime::getSystemDateTime(false).getDate().getClearMonths());
    UT_ASSERT_EQUAL(date_time1.getDate().getClearDays(), CDateTime::getSystemDateTime(false).getDate().getClearDays());
    UT_ASSERT_EQUAL(date_time1.getTime().getClearHours(), CDateTime::getSystemDateTime(false).getTime().getClearHours());
    UT_ASSERT_EQUAL(date_time1.getTime().getClearMinutes(), CDateTime::getSystemDateTime(false).getTime().getClearMinutes());
    UT_ASSERT_EQUAL(date_time1.getTime().getClearSeconds(), CDateTime::getSystemDateTime(false).getTime().getClearSeconds());

    // Check date & time initialization constructor.
    CDateTime date_time2(2000, 12, 10, 20, 35, 25, 500);
    UT_ASSERT_EQUAL(date_time2.getDate().getClearYears(), 2000);
    UT_ASSERT_EQUAL(date_time2.getDate().getClearMonths(), 11);
    UT_ASSERT_EQUAL(date_time2.getDate().getClearDays(), 9);
    UT_ASSERT_EQUAL(date_time2.getTime().getClearHours(), 20);
    UT_ASSERT_EQUAL(date_time2.getTime().getClearMinutes(), 35);
    UT_ASSERT_EQUAL(date_time2.getTime().getClearSeconds(), 25);
    UT_ASSERT_EQUAL(date_time2.getTime().getClearMilliseconds(), 500);
    UT_ASSERT_EQUAL(date_time2.getDate().getYear(), 2000);
    UT_ASSERT_EQUAL(date_time2.getDate().getMonth(), 12);
    UT_ASSERT_EQUAL(date_time2.getDate().getDay(), 10);
    UT_ASSERT_EQUAL(date_time2.getTime().getHour(), 20);
    UT_ASSERT_EQUAL(date_time2.getTime().getMinute(), 35);
    UT_ASSERT_EQUAL(date_time2.getTime().getSecond(), 25);
    UT_ASSERT_EQUAL(date_time2.getTime().getMillisecond(), 500);

    // Set new system local date & time.
    CDateTime systemNew(2000, 10, 5, 23, 0, 0, 0);
    CDateTime systemOld = CDateTime::getSystemDateTime(false);
    Tbool restore = CDateTime::setSystemDateTimeLocal(systemNew);
    UT_ASSERT(restore);
    UT_ASSERT_EQUAL(systemNew.getDate().getClearYears(), CDateTime::getSystemDateTime(false).getDate().getClearYears());
    UT_ASSERT_EQUAL(systemNew.getDate().getClearMonths(), CDateTime::getSystemDateTime(false).getDate().getClearMonths());
    UT_ASSERT_EQUAL(systemNew.getDate().getClearDays(), CDateTime::getSystemDateTime(false).getDate().getClearDays());
    UT_ASSERT_EQUAL(systemNew.getTime().getClearHours(), CDateTime::getSystemDateTime(false).getTime().getClearHours());
    UT_ASSERT_EQUAL(systemNew.getTime().getClearMinutes(), CDateTime::getSystemDateTime(false).getTime().getClearMinutes());
    UT_ASSERT_EQUAL(systemNew.getTime().getClearSeconds(), CDateTime::getSystemDateTime(false).getTime().getClearSeconds());

    CDateTime processStart = CDateTime::getProcessDateTime();

    // Perform some job...
    for (Tuint i = 0; i < 1000000; ++i)
    {
      Treal job = CMath::sin(CONSTR(0.65)) * CMath::cos(CONSTR(0.65));

      IGNORE_UNUSED(job);
    }

    CDateTime processEnd = CDateTime::getProcessDateTime();

    // Check process date & time.
    UT_ASSERT_LESS_EQUAL(processStart, processEnd);

    // Restore system local date & time.
    if (restore)
    {
      UT_ASSERT(CDateTime::setSystemDateTimeLocal(systemOld + (processEnd - processStart)));
    }

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
