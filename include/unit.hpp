/*!
 *  \file    unit.hpp Contains unit test library definitions for the Depth
 *           project.
 *  \brief   Unit test definitions for the Depth project.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test library definitions for the Depth project.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unit test
    VERSION:   1.0
    CREATED:   15.01.2009 02:35:05

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

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
#ifndef __UNIT_HPP__
#define __UNIT_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* DEFINE DECLARATIONS                                                      */
/*==========================================================================*/
/*!
    \def UNITTEST_API
    Unit tests API definition
*/
#if (defined(__UNITTEST_DLL__) || defined(__DLL__))
  #if defined(__UNITTEST_EXPORT__)
    #if defined(__DLL_EXPORT__)
      #define UNITTEST_API __declspec(dllexport)
    #else
      #define UNITTEST_API
    #endif
  #else
    #if defined(__DLL_IMPORT__)
      #define UNITTEST_API __declspec(dllimport)
    #else
      #define UNITTEST_API
    #endif
  #endif
#else
  #define UNITTEST_API
#endif
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
/*!
    \namespace NDepth::NUnitTest
    \brief Unit test definitions.

    \namespace NDepth::NUnitTest::NDetails
    \brief Unit test details definitions.
*/
/*==========================================================================*/
#include <Depth/include/unit/details/FUnitTestLog.hpp>
#include <Depth/include/unit/details/FUnitTestLogFixed.hpp>
#include <Depth/include/unit/details/FUnitTestError.hpp>
#include <Depth/include/unit/details/FUnitTestErrorFixed.hpp>
#include <Depth/include/unit/details/FUnitTestWarning.hpp>
#include <Depth/include/unit/details/FUnitTestWarningFixed.hpp>
#include <Depth/include/unit/details/FUnitTestIsNeedStop.hpp>
#include <Depth/include/unit/details/FUnitTestDelta.hpp>
#include <Depth/include/unit/details/FUnitTestLimit.hpp>
#include <Depth/include/unit/details/FUnitTestSameBuffers.hpp>
/*==========================================================================*/
/*!
    \def UT_ACCEPT
    Defines unit test acceptation macros.
*/
#define UT_ACCEPT return NDepth::NUnitTest::e_TEST_SUCCESS;
/*--------------------------------------------------------------------------*/
/*!
    \def UT_FAIL
    Defines unit test failure macros.
*/
#define UT_FAIL return NDepth::NUnitTest::e_TEST_ERROR;
/*--------------------------------------------------------------------------*/
/*!
    \def UT_STOP
    Defines unit test stop macros.
*/
#define UT_STOP return NDepth::NUnitTest::e_TEST_STOPPED;
/*--------------------------------------------------------------------------*/
/*!
    \def UT_CONRET(result)
    Defines unit test flow control macros. If there is no error  in  the  unit
    test is detected, then unit test execution will be continued. Otherwise \a
    result value will be returned from the current function.
*/
#define UT_CONRET(result)                                                     \
{                                                                             \
  if (NDepth::NUnitTest::NDetails::unitTestIsNeedStop())                      \
    return result;                                                            \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_LOG(message)
    Defines unit test logging macros. If code fragment wants to generate  unit
    test logging message it should use this macros and pass describing logging
    \a message. This macros uses common Depth argument formatting algorithm.

*/
#define UT_LOG(message) NDepth::NUnitTest::NDetails::unitTestLog(FUNCTION_SIGNATURE, FILE, LINE, message)
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ERROR(message)
    Defines unit test error macros. If code fragment wants  to  generate  unit
    test error it should use this macros and pass describing error \a message.
    This macros uses common Depth argument formatting algorithm.
*/
#define UT_ERROR(message) NDepth::NUnitTest::NDetails::unitTestError(FUNCTION_SIGNATURE, FILE, LINE, message)
/*--------------------------------------------------------------------------*/
/*!
    \def UT_WARNING(message)
    Defines unit test warning macros. If code fragment wants to generate  unit
    test warning it should use this macros  and  pass  describing  warning  \a
    message. This macros uses common Depth argument formatting algorithm.
*/
#define UT_WARNING(message) NDepth::NUnitTest::NDetails::unitTestWarning(FUNCTION_SIGNATURE, FILE, LINE, message)
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT(condition)
    Defines unit test assertion macros. Checks \a condition expression  to  be
    'true'. If it is 'true' the  execution  flows  normally.  Otherwise  error
    message will be written and the unit test will be treated as failed.
*/
#define UT_ASSERT(condition)                                                                                                    \
{                                                                                                                               \
  if (condition)                                                                                                                \
  {                                                                                                                             \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(condition));   \
  }                                                                                                                             \
  else                                                                                                                          \
  {                                                                                                                             \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(condition)); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(condition));   \
  }                                                                                                                             \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_VALID_PTR(ptr)
    Defines valid pointer unit test assertion macros.  Checks  if  \a  ptr  is
    valid (\a ptr is not NULL). If it is 'true' the execution flows  normally.
    Otherwise error message will be written and the unit test will be  treated
    as failed.
*/
#define UT_ASSERT_VALID_PTR(ptr)                                                                                                     \
{                                                                                                                                    \
  if ((ptr) != NULL)                                                                                                                 \
  {                                                                                                                                  \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(ptr) " != NULL");   \
  }                                                                                                                                  \
  else                                                                                                                               \
  {                                                                                                                                  \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(ptr) " != NULL"); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(ptr) " != NULL");   \
  }                                                                                                                                  \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_INVALID_PTR(ptr)
    Defines invalid pointer unit test assertion macros. Checks if  \a  ptr  is
    invalid (\a ptr is NULL). If it is 'true' the  execution  flows  normally.
    Otherwise error message will be written and the unit test will be  treated
    as failed.
*/
#define UT_ASSERT_INVALID_PTR(ptr)                                                                                                   \
{                                                                                                                                    \
  if ((ptr) == NULL)                                                                                                                 \
  {                                                                                                                                  \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(ptr) " == NULL");   \
  }                                                                                                                                  \
  else                                                                                                                               \
  {                                                                                                                                  \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(ptr) " == NULL"); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(ptr) " == NULL");   \
  }                                                                                                                                  \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_ZERO(value)
    Defines zero equal unit test assertion macros. Checks if \a  value  equals
    to zero. If it is 'true' the execution  flows  normally.  Otherwise  error
    message will be written and the unit test will be treated as failed.
*/
#define UT_ASSERT_ZERO(value)                                                                                                       \
{                                                                                                                                   \
  if ((value) == 0)                                                                                                                 \
  {                                                                                                                                 \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(value) " == 0");   \
  }                                                                                                                                 \
  else                                                                                                                              \
  {                                                                                                                                 \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value) " == 0"); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value) " == 0");   \
  }                                                                                                                                 \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_EQUAL(x, y)
    Defines equal  unit test  assertion macros.  Checks if \a value1 equals to
    \a value2  (\a value1 == \a value2).  If  it   is  'true'  the   execution
    flows normally. Otherwise error message will be written and the unit  test
    will be treated as failed.
*/
#define UT_ASSERT_EQUAL(value1, value2)                                                                                                               \
{                                                                                                                                                     \
  if ((value1) == (value2))                                                                                                                           \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(value1) " == " STRINGIZE(value2));   \
  }                                                                                                                                                   \
  else                                                                                                                                                \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " == " STRINGIZE(value2)); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " == " STRINGIZE(value2));   \
  }                                                                                                                                                   \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_NOT_EQUAL(value1, value2)
    Defines not equal unit test assertion macros.  Checks  if  \a  value1  not
    equals to \a value2 (\a  value1  !=  \a  value2).  If  it  is  'true'  the
    execution flows normally. Otherwise error message will be written and  the
    unit test will be treated as failed.
*/
#define UT_ASSERT_NOT_EQUAL(value1, value2)                                                                                                           \
{                                                                                                                                                     \
  if ((value1) != (value2))                                                                                                                           \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(value1) " != " STRINGIZE(value2));   \
  }                                                                                                                                                   \
  else                                                                                                                                                \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " != " STRINGIZE(value2)); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " != " STRINGIZE(value2));   \
  }                                                                                                                                                   \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_LESS(value1, value2)
    Defines less  unit test assertion macros.  Checks if \a value1  less  then
    \a value2  (\a value1 < \a value2).  If   it   is  'true'   the  execution
    flows normally. Otherwise error message will be written and the unit  test
    will be treated as failed.
*/
#define UT_ASSERT_LESS(value1, value2)                                                                                                                \
{                                                                                                                                                     \
  if ((value1) < (value2))                                                                                                                            \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(value1) " < " STRINGIZE(value2));    \
  }                                                                                                                                                   \
  else                                                                                                                                                \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " < " STRINGIZE(value2));  \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " < " STRINGIZE(value2));    \
  }                                                                                                                                                   \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_MORE(value1, value2)
    Defines more unit test assertion macros.  Checks  if \a value1  more  then
    \a value2 (\a value1 > \a value2). If it is  'true'  the  execution  flows
    normally. Otherwise error message will be written and the unit  test  will
    be treated as failed.
*/
#define UT_ASSERT_MORE(value1, value2)                                                                                                                \
{                                                                                                                                                     \
  if ((value1) > (value2))                                                                                                                            \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(value1) " > " STRINGIZE(value2));    \
  }                                                                                                                                                   \
  else                                                                                                                                                \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " > " STRINGIZE(value2));  \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " > " STRINGIZE(value2));    \
  }                                                                                                                                                   \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_LESS_EQUAL(value1, value2)
    Defines less or equal unit test assertion macros. Checks if \a value1 less
    or equal to \a value2 (\a value1 <=  \a  value2).  If  it  is  'true'  the
    execution flows normally. Otherwise error message will be written and  the
    unit test will be treated as failed.
*/
#define UT_ASSERT_LESS_EQUAL(value1, value2)                                                                                                          \
{                                                                                                                                                     \
  if ((value1) <= (value2))                                                                                                                           \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(value1) " <= " STRINGIZE(value2));   \
  }                                                                                                                                                   \
  else                                                                                                                                                \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " <= " STRINGIZE(value2)); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " <= " STRINGIZE(value2));   \
  }                                                                                                                                                   \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_MORE_EQUAL(value1, value2)
    Defines more or equal unit test assertion macros. Checks if \a value1 more
    or equal to \a value2 (\a value1 >=  \a  value2).  If  it  is  'true'  the
    execution flows normally. Otherwise error message will be written and  the
    unit test will be treated as failed.
*/
#define UT_ASSERT_MORE_EQUAL(value1, value2)                                                                                                          \
{                                                                                                                                                     \
  if ((value1) >= (value2))                                                                                                                           \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(value1) " >= " STRINGIZE(value2));   \
  }                                                                                                                                                   \
  else                                                                                                                                                \
  {                                                                                                                                                   \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " >= " STRINGIZE(value2)); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value1) " >= " STRINGIZE(value2));   \
  }                                                                                                                                                   \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_DELTA(value1, value2, delta)
    Defines delta unit test assertion macros. Checks if \a value1 equals to \a
    value2 up to \a delta (|\a value1 - \a value2| <= delta). If it is  'true'
    the execution flows normally. Otherwise error message will be written  and
    the unit test will be treated as failed.
*/
#define UT_ASSERT_DELTA(value1, value2, delta)                                                                                                                                       \
{                                                                                                                                                                                    \
  if (NDepth::NUnitTest::NDetails::unitTestDelta(value1, value2, delta))                                                                                                             \
  {                                                                                                                                                                                  \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " " | " STRINGIZE(value1) " - " STRINGIZE(value2) " | <= " STRINGIZE(delta));   \
  }                                                                                                                                                                                  \
  else                                                                                                                                                                               \
  {                                                                                                                                                                                  \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " " | " STRINGIZE(value1) " - " STRINGIZE(value2) " | <= " STRINGIZE(delta)); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " " | " STRINGIZE(value1) " - " STRINGIZE(value2) " | <= " STRINGIZE(delta));   \
  }                                                                                                                                                                                  \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_NOT_DELTA(value1, value2, delta)
    Defines not delta unit test assertion macros.  Checks  if  \a  value1  not
    equals to \a value2 up to \a delta (|\a value1 - \a value2| <= delta).  If
    it is 'true' the execution flows normally. Otherwise error message will be
    written and the unit test will be treated as failed.
*/
#define UT_ASSERT_NOT_DELTA(value1, value2, delta)                                                                                                                                  \
{                                                                                                                                                                                   \
  if (!NDepth::NUnitTest::NDetails::unitTestDelta(value1, value2, delta))                                                                                                           \
  {                                                                                                                                                                                 \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " " | " STRINGIZE(value1) " - " STRINGIZE(value2) " | > " STRINGIZE(delta));   \
  }                                                                                                                                                                                 \
  else                                                                                                                                                                              \
  {                                                                                                                                                                                 \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " " | " STRINGIZE(value1) " - " STRINGIZE(value2) " | > " STRINGIZE(delta)); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " " | " STRINGIZE(value1) " - " STRINGIZE(value2) " | > " STRINGIZE(delta));   \
  }                                                                                                                                                                                 \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_LIMIT(alim, blim, value)
    Defines limit unit test assertion  macros.  Checks if \a value  is  in the
    [\a alim, \a blim]   limit.   If   it   is  'true'  the   execution  flows
    normally.  Otherwise  error message will be written and the unit test will
    be treated as failed.
*/
#define UT_ASSERT_LIMIT(alim, blim, value)                                                                                                                                \
{                                                                                                                                                                         \
  if (NDepth::NUnitTest::NDetails::unitTestLimit(alim, blim, value))                                                                                                      \
  {                                                                                                                                                                       \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(alim) " <= " STRINGIZE(value) " <= " STRINGIZE(blim));   \
  }                                                                                                                                                                       \
  else                                                                                                                                                                    \
  {                                                                                                                                                                       \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(alim) " <= " STRINGIZE(value) " <= " STRINGIZE(blim)); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(alim) " <= " STRINGIZE(value) " <= " STRINGIZE(blim));   \
  }                                                                                                                                                                       \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_NOT_LIMIT(alim, blim, value)
    Defines not in limit unit test assertion macros. Checks if \a value is not
    in the [\a alim, \a blim] limit. If  it  is  'true'  the  execution  flows
    normally. Otherwise error message will be written and the unit  test  will
    be treated as failed.
*/
#define UT_ASSERT_NOT_LIMIT(alim, blim, value)                                                                                                                                                  \
{                                                                                                                                                                                               \
  if (!NDepth::NUnitTest::NDetails::unitTestLimit(alim, blim, value))                                                                                                                           \
  {                                                                                                                                                                                             \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(value) " < " STRINGIZE(alim) " or " STRINGIZE(value) " > " STRINGIZE(blim));   \
  }                                                                                                                                                                                             \
  else                                                                                                                                                                                          \
  {                                                                                                                                                                                             \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value) " < " STRINGIZE(alim) " or " STRINGIZE(value) " > " STRINGIZE(blim)); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(value) " < " STRINGIZE(alim) " or " STRINGIZE(value) " > " STRINGIZE(blim));   \
  }                                                                                                                                                                                             \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_SAME_BUFFERS(buffer1, buffer2, size)
    Defines same buffers unit test assertion  macros.  Checks  if  \a  buffer1
    buffer contains same data as in \a buffer2 buffer (two buffers  are  fixed
    \a size). If it is 'true' the execution flows  normally.  Otherwise  error
    message will be written and the unit test will be treated as failed.
*/
#define UT_ASSERT_SAME_BUFFERS(buffer1, buffer2, size)                                                                                                                                                          \
{                                                                                                                                                                                                               \
  if (NDepth::NUnitTest::NDetails::unitTestSameBuffers((NDepth::NTypes::Tcbuffer)buffer1, (NDepth::NTypes::Tcbuffer)buffer2, size))                                                                             \
  {                                                                                                                                                                                                             \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(buffer1) " has the same content as in " STRINGIZE(buffer2) " (size = " STRINGIZE(size) ")");   \
  }                                                                                                                                                                                                             \
  else                                                                                                                                                                                                          \
  {                                                                                                                                                                                                             \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(buffer1) " has the same content as in " STRINGIZE(buffer2) " (size = " STRINGIZE(size) ")"); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(buffer1) " has the same content as in " STRINGIZE(buffer2) " (size = " STRINGIZE(size) ")");   \
  }                                                                                                                                                                                                             \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_DIFFERENT_BUFFERS(buffer1, buffer2, size)
    Defines different buffers unit test assertion macros. Checks if \a buffer1
    buffer contains different data as in \a buffer2 buffer  (two  buffers  are
    fixed \a size). If it is 'true' the execution  flows  normally.  Otherwise
    error message will be written and the unit test will be treated as failed.
*/
#define UT_ASSERT_DIFFERENT_BUFFERS(buffer1, buffer2, size)                                                                                                                                                          \
{                                                                                                                                                                                                                    \
  if (!NDepth::NUnitTest::NDetails::unitTestSameBuffers((NDepth::NTypes::Tcbuffer)buffer1, (NDepth::NTypes::Tcbuffer)buffer2, size))                                                                                 \
  {                                                                                                                                                                                                                  \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(buffer1) " has the different content as in " STRINGIZE(buffer2) " (size = " STRINGIZE(size) ")");   \
  }                                                                                                                                                                                                                  \
  else                                                                                                                                                                                                               \
  {                                                                                                                                                                                                                  \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(buffer1) " has the different content as in " STRINGIZE(buffer2) " (size = " STRINGIZE(size) ")"); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(buffer1) " has the different content as in " STRINGIZE(buffer2) " (size = " STRINGIZE(size) ")");   \
  }                                                                                                                                                                                                                  \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_THROWS(expression, exception)
    Defines  fixed  exception  throws  unit  test  assertion macros. Checks if
    \a expression throws the given \a exception. If it is 'true' the execution
    flows normally. Otherwise error message will be written and the unit  test
    will be treated as failed.
*/
#define UT_ASSERT_THROWS(expression, exception)                                                                                                                  \
{                                                                                                                                                                \
  NDepth::NTypes::Tbool thrown = false;                                                                                                                          \
  try                                                                                                                                                            \
  {                                                                                                                                                              \
    expression;                                                                                                                                                  \
  }                                                                                                                                                              \
  catch (exception)                                                                                                                                              \
  {                                                                                                                                                              \
    thrown = true;                                                                                                                                               \
  }                                                                                                                                                              \
  if (thrown)                                                                                                                                                    \
  {                                                                                                                                                              \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(expression) " throws " STRINGIZE(exception));   \
  }                                                                                                                                                              \
  else                                                                                                                                                           \
  {                                                                                                                                                              \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(expression) " throws " STRINGIZE(exception)); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(expression) " throws " STRINGIZE(exception));   \
  }                                                                                                                                                              \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_THROWS_ANYTHING(expression)
    Defines  any  exception  throws  unit  test  assertion  macros.  Checks if
    \a expression throws any exception. If it is 'true'  the  execution  flows
    normally. Otherwise error message will be written and the unit  test  will
    be treated as failed.
*/
#define UT_ASSERT_THROWS_ANYTHING(expression)                                                                                                        \
{                                                                                                                                                    \
  NDepth::NTypes::Tbool thrown = false;                                                                                                              \
  try                                                                                                                                                \
  {                                                                                                                                                  \
    expression;                                                                                                                                      \
  }                                                                                                                                                  \
  catch (...)                                                                                                                                        \
  {                                                                                                                                                  \
    thrown = true;                                                                                                                                   \
  }                                                                                                                                                  \
  if (thrown)                                                                                                                                        \
  {                                                                                                                                                  \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(expression) " throws exception");   \
  }                                                                                                                                                  \
  else                                                                                                                                               \
  {                                                                                                                                                  \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(expression) " throws exception"); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(expression) " throws exception");   \
  }                                                                                                                                                  \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_THROWS_NOTHING(expression)
    Defines none exception throws unit test assertion  macros.  Checks  if  \a
    expression does not throw any exception. If it  is  'true'  the  execution
    flows normally. Otherwise error message will be written and the unit  test
    will be treated as failed.
*/
#define UT_ASSERT_THROWS_NOTHING(expression)                                                                                                                 \
{                                                                                                                                                            \
  NDepth::NTypes::Tbool thrown = false;                                                                                                                      \
  try                                                                                                                                                        \
  {                                                                                                                                                          \
    expression;                                                                                                                                              \
  }                                                                                                                                                          \
  catch (...)                                                                                                                                                \
  {                                                                                                                                                          \
    thrown = true;                                                                                                                                           \
  }                                                                                                                                                          \
  if (!thrown)                                                                                                                                               \
  {                                                                                                                                                          \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(expression) " does not throw exception");   \
  }                                                                                                                                                          \
  else                                                                                                                                                       \
  {                                                                                                                                                          \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(expression) " does not throw exception"); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(expression) " does not throw exception");   \
  }                                                                                                                                                          \
}
/*--------------------------------------------------------------------------*/
/*!
    \def UT_ASSERT_TIMEOUT(expression, timeout)
    Defines timeout unit test assertion macros. Checks if  \a  expression  was
    executed in  a  less  than  \a  timeout  (should  be  convertible  to  the
    CTimeStamp). If it is 'true' the execution flows normally. Otherwise error
    message will be written and the unit test will be treated as failed.
*/
#define UT_ASSERT_TIMEOUT(expression, timeout)                                                                                                                                     \
{                                                                                                                                                                                  \
  NDepth::NTime::CTimeStamp expression_timeout = NTime::CTimeStamp::getSystemTimeStamp() + NDepth::NTime::CTimeStamp(timeout);                                                     \
  {                                                                                                                                                                                \
    expression;                                                                                                                                                                    \
  }                                                                                                                                                                                \
  if (NTime::CTimeStamp::getSystemTimeStamp() < expression_timeout)                                                                                                                \
  {                                                                                                                                                                                \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION PASSED: " STRINGIZE(expression) " does not reach the timeout " STRINGIZE(timeout));   \
  }                                                                                                                                                                                \
  else                                                                                                                                                                             \
  {                                                                                                                                                                                \
    NDepth::NUnitTest::NDetails::unitTestErrorFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(expression) " does not reach the timeout " STRINGIZE(timeout)); \
    NDepth::NUnitTest::NDetails::unitTestLogFixed(FUNCTION_SIGNATURE, FILE, LINE, "ASSERTION FAILED: " STRINGIZE(expression) " does not reach the timeout " STRINGIZE(timeout));   \
  }                                                                                                                                                                                \
}
/*==========================================================================*/
#endif
