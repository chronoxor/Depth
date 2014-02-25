/*!
 *  \file    test-time-CDate.cpp Testing of the CDate class.
 *  \brief   Testing of the CDate class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.03.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CDate class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth time tests
    VERSION:   1.0
    CREATED:   01.03.2010 02:27:55

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
#include <Depth/include/time/CDate.hpp>
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
    // Check date defualt constructor.
    CDate date1;
    UT_ASSERT_EQUAL(date1.getClearYears(), CDate::getSystemDate(false).getClearYears());
    UT_ASSERT_EQUAL(date1.getClearMonths(), CDate::getSystemDate(false).getClearMonths());
    UT_ASSERT_EQUAL(date1.getClearDays(), CDate::getSystemDate(false).getClearDays());

    // Check date initialization constructor.
    CDate date2(2000, 12, 10);
    UT_ASSERT_EQUAL(date2.getClearYears(), 2000);
    UT_ASSERT_EQUAL(date2.getClearMonths(), 11);
    UT_ASSERT_EQUAL(date2.getClearDays(), 9);
    UT_ASSERT_EQUAL(date2.getYear(), 2000);
    UT_ASSERT_EQUAL(date2.getMonth(), 12);
    UT_ASSERT_EQUAL(date2.getDay(), 10);

    // Check date <---> time stamp conversions.
    /*
    for (Tsint i = 3000; i >= -3000; --i)
      for (Tsint j = 1; j <= 12; ++j)
        for (Tsint k = 1; k <= 31; ++k)
          UT_ASSERT_EQUAL(CDate(i, j, k), CDate(CDate(i, j, k).getTimeStamp()));
    */

    // Check addition of common years.
    UT_ASSERT_EQUAL(CDate(1582,  1,  1) + CTimeStamp(0, 0, 0, 0, 365), CDate(1583,  1,  1));
    UT_ASSERT_EQUAL(CDate(1582,  2, 15) + CTimeStamp(0, 0, 0, 0, 365), CDate(1583,  2, 15));
    UT_ASSERT_EQUAL(CDate(1582,  2, 28) + CTimeStamp(0, 0, 0, 0, 365), CDate(1583,  2, 28));
    UT_ASSERT_EQUAL(CDate(1582,  3,  1) + CTimeStamp(0, 0, 0, 0, 365), CDate(1583,  3,  1));
    UT_ASSERT_EQUAL(CDate(1582,  9, 30) + CTimeStamp(0, 0, 0, 0, 365), CDate(1583,  9, 30));
    UT_ASSERT_EQUAL(CDate(1582, 10,  1) + CTimeStamp(0, 0, 0, 0, 365), CDate(1583, 10,  1));
    UT_ASSERT_EQUAL(CDate(1582, 10,  4) + CTimeStamp(0, 0, 0, 0, 365), CDate(1583, 10,  4));
    UT_ASSERT_EQUAL(CDate(1582, 10, 15) + CTimeStamp(0, 0, 0, 0, 365), CDate(1583, 10, 15));
    UT_ASSERT_EQUAL(CDate(1582, 10, 16) + CTimeStamp(0, 0, 0, 0, 365), CDate(1583, 10, 16));

    // Check addition of leap years.
    UT_ASSERT_EQUAL(CDate(1580,  1,  1) + CTimeStamp(0, 0, 0, 0, (365 + 365 + 365 + 366)), CDate(1584,  1,  1));
    UT_ASSERT_EQUAL(CDate(1580,  2, 29) + CTimeStamp(0, 0, 0, 0, (365 + 365 + 365 + 366)), CDate(1584,  2, 29));
    UT_ASSERT_EQUAL(CDate(1580, 10,  1) + CTimeStamp(0, 0, 0, 0, (365 + 365 + 365 + 366)), CDate(1584, 10,  1));
    UT_ASSERT_EQUAL(CDate(1580, 10, 10) + CTimeStamp(0, 0, 0, 0, (365 + 365 + 365 + 366)), CDate(1584, 10, 10));
    UT_ASSERT_EQUAL(CDate(1580, 10, 15) + CTimeStamp(0, 0, 0, 0, (365 + 365 + 365 + 366)), CDate(1584, 10, 15));
    UT_ASSERT_EQUAL(CDate(1580, 12, 31) + CTimeStamp(0, 0, 0, 0, (365 + 365 + 365 + 366)), CDate(1584, 12, 31));

    // Check addition of days.
    UT_ASSERT_EQUAL(CDate(1582, 10,  3) + CTimeStamp(0, 0, 0, 0,  1), CDate(1582, 10,  4));
    UT_ASSERT_EQUAL(CDate(1582, 10, 14) + CTimeStamp(0, 0, 0, 0,  1), CDate(1582, 10, 15));
    UT_ASSERT_EQUAL(CDate(1582, 10, 15) + CTimeStamp(0, 0, 0, 0,  1), CDate(1582, 10, 16));
    UT_ASSERT_EQUAL(CDate(1582,  9, 30) + CTimeStamp(0, 0, 0, 0, 10), CDate(1582, 10, 10));
    UT_ASSERT_EQUAL(CDate(1582, 10, 14) + CTimeStamp(0, 0, 0, 0, 10), CDate(1582, 10, 24));
    UT_ASSERT_EQUAL(CDate(1582, 10, 15) + CTimeStamp(0, 0, 0, 0, 10), CDate(1582, 10, 25));
    UT_ASSERT_EQUAL(CDate(1582, 11,  5) + CTimeStamp(0, 0, 0, 0, 28), CDate(1582, 12,  3));
    UT_ASSERT_EQUAL(CDate(1582, 12,  5) + CTimeStamp(0, 0, 0, 0, 28), CDate(1583,  1,  2));
    UT_ASSERT_EQUAL(CDate(2005, 11,  5) + CTimeStamp(0, 0, 0, 0, 28), CDate(2005, 12,  3));
    UT_ASSERT_EQUAL(CDate(2005, 12,  5) + CTimeStamp(0, 0, 0, 0, 28), CDate(2006,  1,  2));

    // Check BC years.
    UT_ASSERT_EQUAL(CDate(-1582,  1,  1) - CTimeStamp(0, 0, 0, 0, 365), CDate(-1583,  1,  1));
    UT_ASSERT_EQUAL(CDate(-1582,  1,  1) + CTimeStamp(0, 0, 0, 0, 365), CDate(-1581,  1,  1));
    UT_ASSERT_EQUAL(CDate(-1580,  1,  1) - CTimeStamp(0, 0, 0, 0, (365 + 365 + 365 + 366)), CDate(-1584,  1,  1));
    UT_ASSERT_EQUAL(CDate(-1580,  1,  1) + CTimeStamp(0, 0, 0, 0, (365 + 365 + 365 + 366)), CDate(-1576,  1,  1));

    // Check leap years.
    UT_ASSERT(CDate::isLeapYear(-2000));
    UT_ASSERT(!CDate::isLeapYear(-1000));
    UT_ASSERT(!CDate::isLeapYear(-500));
    UT_ASSERT(CDate::isLeapYear(-400));
    UT_ASSERT(!CDate::isLeapYear(-395));
    UT_ASSERT(CDate::isLeapYear(-392));
    UT_ASSERT(CDate::isLeapYear(-4));
    UT_ASSERT(!CDate::isLeapYear(-1));
    UT_ASSERT(CDate::isLeapYear(0));
    UT_ASSERT(!CDate::isLeapYear(1));
    UT_ASSERT(CDate::isLeapYear(4));
    UT_ASSERT(CDate::isLeapYear(392));
    UT_ASSERT(!CDate::isLeapYear(395));
    UT_ASSERT(CDate::isLeapYear(400));
    UT_ASSERT(!CDate::isLeapYear(500));
    UT_ASSERT(!CDate::isLeapYear(1000));
    UT_ASSERT(CDate::isLeapYear(2000));

    // Check Epoch days of the year.
    UT_ASSERT_EQUAL(CDate::getEpochDays(-5), -(365 + 365 + 365 + 366 + 365));
    UT_ASSERT_EQUAL(CDate::getEpochDays(-4), -(365 + 365 + 365 + 366));
    UT_ASSERT_EQUAL(CDate::getEpochDays(-3), -(365 + 365 + 365));
    UT_ASSERT_EQUAL(CDate::getEpochDays(-2), -(365 + 365));
    UT_ASSERT_EQUAL(CDate::getEpochDays(-1), -(365));
    UT_ASSERT_EQUAL(CDate::getEpochDays( 0), 0);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 1), (366));
    UT_ASSERT_EQUAL(CDate::getEpochDays( 2), (366 + 365));
    UT_ASSERT_EQUAL(CDate::getEpochDays( 3), (366 + 365 + 365));
    UT_ASSERT_EQUAL(CDate::getEpochDays( 4), (366 + 365 + 365 + 365));
    UT_ASSERT_EQUAL(CDate::getEpochDays( 5), (366 + 365 + 365 + 365 + 366));

    // Check Epoch days of the month.
    UT_ASSERT_EQUAL(CDate::getEpochDays(-2, 12), -396);
    UT_ASSERT_EQUAL(CDate::getEpochDays(-1, 10), -92);
    UT_ASSERT_EQUAL(CDate::getEpochDays(-1, 11), -61);
    UT_ASSERT_EQUAL(CDate::getEpochDays(-1, 12), -31);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 0,  1), 0);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 0,  2), 31);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 0,  3), 60);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 1,  1), 366);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 1,  2), 397);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 1,  3), 425);

    // Check Epoch days of the date.
    UT_ASSERT_EQUAL(CDate::getEpochDays(-4, 12, 31), -1096);
    UT_ASSERT_EQUAL(CDate::getEpochDays(-3,  1,  1), -1095);
    UT_ASSERT_EQUAL(CDate::getEpochDays(-2, 12, 31), -366);
    UT_ASSERT_EQUAL(CDate::getEpochDays(-1,  1,  1), -365);
    UT_ASSERT_EQUAL(CDate::getEpochDays(-1, 11, 30), -32);
    UT_ASSERT_EQUAL(CDate::getEpochDays(-1, 12,  1), -31);
    UT_ASSERT_EQUAL(CDate::getEpochDays(-1, 12,  2), -30);
    UT_ASSERT_EQUAL(CDate::getEpochDays(-1, 12, 30), -2);
    UT_ASSERT_EQUAL(CDate::getEpochDays(-1, 12, 31), -1);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 0,  1,  1),  0);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 0,  1,  2),  1);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 0,  1, 10),  9);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 0,  2,  1), 31);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 0,  3,  1), 60);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 0, 12, 31), 365);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 1,  1,  1), 366);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 2,  1,  1), 731);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 3,  1,  1), 1096);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 4,  1,  1), 1461);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 4, 12, 31), 1826);
    UT_ASSERT_EQUAL(CDate::getEpochDays( 5,  1,  1), 1827);

    // Check Epoch weeks of the date.
    UT_ASSERT_EQUAL(CDate::getEpochWeeks(-2010, 3, 3), -104868);
    UT_ASSERT_EQUAL(CDate::getEpochWeeks(-1, 12, 26), -1);
    UT_ASSERT_EQUAL(CDate::getEpochWeeks(-1, 12, 27),  0);
    UT_ASSERT_EQUAL(CDate::getEpochWeeks(-1, 12, 31),  0);
    UT_ASSERT_EQUAL(CDate::getEpochWeeks( 0,  1,  1),  0);
    UT_ASSERT_EQUAL(CDate::getEpochWeeks( 0,  1,  2),  0);
    UT_ASSERT_EQUAL(CDate::getEpochWeeks( 0,  1,  3),  1);
    UT_ASSERT_EQUAL(CDate::getEpochWeeks( 0,  1,  9),  1);
    UT_ASSERT_EQUAL(CDate::getEpochWeeks( 0,  1, 10),  2);
    UT_ASSERT_EQUAL(CDate::getEpochWeeks( 2010, 3, 3), 104886);

    // Check year weeks of the date.
    UT_ASSERT_EQUAL(CDate::getYearWeeks( 2010, 1, 1),  1);
    UT_ASSERT_EQUAL(CDate::getYearWeeks( 2010, 2, 1),  6);
    UT_ASSERT_EQUAL(CDate::getYearWeeks( 2010, 3, 1), 10);

    // Check week days.
    UT_ASSERT_EQUAL(CDate(-2010,  3,  1).getWeekDay(), CDate::e_THURSDAY);
    UT_ASSERT_EQUAL(CDate(-1970,  1,  1).getWeekDay(), CDate::e_TUESDAY);
    UT_ASSERT_EQUAL(CDate(-1000,  5,  1).getWeekDay(), CDate::e_THURSDAY);
    UT_ASSERT_EQUAL(CDate( -500,  9,  1).getWeekDay(), CDate::e_SATURDAY);
    UT_ASSERT_EQUAL(CDate(   -1,  1,  1).getWeekDay(), CDate::e_FRIDAY);
    UT_ASSERT_EQUAL(CDate(   -1, 12, 31).getWeekDay(), CDate::e_FRIDAY);
    UT_ASSERT_EQUAL(CDate(    0,  1,  1).getWeekDay(), CDate::e_SATURDAY);
    UT_ASSERT_EQUAL(CDate(    0,  1,  2).getWeekDay(), CDate::e_SUNDAY);
    UT_ASSERT_EQUAL(CDate(    1,  1,  1).getWeekDay(), CDate::e_MONDAY);
    UT_ASSERT_EQUAL(CDate(  500,  9,  1).getWeekDay(), CDate::e_WEDNESDAY);
    UT_ASSERT_EQUAL(CDate( 1000,  5,  1).getWeekDay(), CDate::e_THURSDAY);
    UT_ASSERT_EQUAL(CDate( 1970,  1,  1).getWeekDay(), CDate::e_THURSDAY);
    UT_ASSERT_EQUAL(CDate( 2010,  3,  1).getWeekDay(), CDate::e_MONDAY);

    // Set new system local date.
    CDate systemNew(2000, 10, 5);
    CDate systemOld = CDate::getSystemDate(false);
    Tbool restore = CDate::setSystemDateLocal(systemNew);
    UT_ASSERT(restore);
    UT_ASSERT_EQUAL(systemNew.getClearYears(), CDate::getSystemDate(false).getClearYears());
    UT_ASSERT_EQUAL(systemNew.getClearMonths(), CDate::getSystemDate(false).getClearMonths());
    UT_ASSERT_EQUAL(systemNew.getClearDays(), CDate::getSystemDate(false).getClearDays());

    CDate processStart = CDate::getProcessDate();

    // Perform some job...
    for (Tuint i = 0; i < 1000000; ++i)
    {
      Treal job = CMath::sin(CONSTR(0.65)) * CMath::cos(CONSTR(0.65));

      IGNORE_UNUSED(job);
    }

    CDate processEnd = CDate::getProcessDate();

    // Check process date.
    UT_ASSERT_LESS_EQUAL(processStart, processEnd);

    // Restore system local date.
    if (restore)
    {
      UT_ASSERT(CDate::setSystemDateLocal(systemOld + (processEnd - processStart)));
    }

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
