/*!
 *  \file    example-unit-CUnitTest.cpp Example of using the CUnitTest class.
 *  \brief   Example of using the CUnitTest class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CUnitTest class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth unit test examples
    VERSION:   1.0
    CREATED:   16.01.2009 02:10:29

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
using namespace NDepth::NContainers;
using namespace NDepth::NString;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NMath;
/*==========================================================================*/
class CExampleUnitTest1 :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_LOG(STR("Logging message!"));
    UT_ERROR(STR("Error message!"));
    UT_WARNING(STR("Warning message!"));
    UT_ACCEPT;
  }
} the_ExampleUnitTest1;
/*--------------------------------------------------------------------------*/
class CExampleUnitTest2 :
  public CUnitTest
{
public:
  // Exception class.
  class CException { };

  // Initialize unit test with a corresponding name and file name.
  CExampleUnitTest2(const CString& a_crName, const CString& a_crFileName) : CUnitTest(a_crName, a_crFileName) { CALL }

protected:
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_THROWS(throwException(), CException);
    UT_ASSERT_THROWS_ANYTHING(throwException());
    UT_ASSERT_THROWS_NOTHING(throwNothing());
    UT_FAIL;
  }

  // Method throws instance of the CException class.
  void throwException()
  { CALL
    throw CException();
  }

  // Method throws nothing.
  void throwNothing() throw()
  { CALL

  }
} the_ExampleUnitTest2(STR("CExampleUnitTest2"), FILE);
/*--------------------------------------------------------------------------*/
class CExampleUnitTest3 :
  public CUnitTest
{
public:
  // Initialize unit test with a corresponding name and file name.
  CExampleUnitTest3(const CString& a_crName, const CString& a_crFileName) : CUnitTest(a_crName, a_crFileName) { CALL }

protected:
  // Install unit test.
  Tbool install()
  { CALL
    m_Z = 100;
    return true;
  }

  // Uninstall unit test.
  Tbool uninstall()
  { CALL
    m_Z = 200;
    return true;
  }

  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT(m_Z == 100);
    UT_ASSERT(m_Z != 100);
    UT_ASSERT_NOT_EQUAL(m_Z, 100);
    UT_ASSERT_NOT_EQUAL(m_Z, 200);
    UT_ASSERT_EQUAL(m_Z, 100);
    UT_ASSERT_EQUAL(m_Z, 200);
    UT_ASSERT_LESS(m_Z, 100);
    UT_ASSERT_LESS(m_Z, 200);
    UT_ASSERT_MORE(m_Z, 100);
    UT_ASSERT_MORE(m_Z, 200);
    UT_ASSERT_LESS_EQUAL(m_Z, 100);
    UT_ASSERT_LESS_EQUAL(m_Z, 200);
    UT_ASSERT_MORE_EQUAL(m_Z, 100);
    UT_ASSERT_MORE_EQUAL(m_Z, 200);
    UT_ASSERT_DELTA(100.1, 100.2, 0.5);
    UT_ASSERT_DELTA(100.1, 100.2, 0.05);

    // Job should not take more than 5000 milliseconds.
    UT_ASSERT_TIMEOUT(job(), 5000);

    UT_ACCEPT;
  }

  // Perform some job.
  void job()
  { CALL
    for (Tuint i = 0; i < 1000; ++i)
    {
      Treal job = CMath::sin(CONSTR(0.65)) * CMath::cos(CONSTR(0.65));

      IGNORE_UNUSED(job);
    }
  }

private:
  Tsint m_Z;
} the_ExampleUnitTest3(STR("CExampleUnitTest3"), FILE);
/*==========================================================================*/
