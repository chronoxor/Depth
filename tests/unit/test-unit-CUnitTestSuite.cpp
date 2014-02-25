/*!
 *  \file    test-unit-CUnitTestSuite.cpp Testing of the CUnitTestSuite class.
 *  \brief   Testing of the CUnitTestSuite class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CUnitTestSuite class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth unit tests
    VERSION:   1.0
    CREATED:   08.03.2009 23:16:04

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
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NString;
/*==========================================================================*/
static Tuint the_Counter = 0;
/*--------------------------------------------------------------------------*/
class CExampleUnitTestSuite :
  public CUnitTestSuite
{
public:
  Tsint m_X;
  Tsint m_Y;

  // Initialize unit test suite with a corresponding name and file name.
  CExampleUnitTestSuite(const CString& a_crName, const CString& a_crFileName) : CUnitTestSuite(a_crName, a_crFileName) { CALL }

protected:
  // Install unit test suite.
  Tbool install()
  { CALL
    m_X = 1;
    m_Y = 10;
    return true;
  }

  // Uninstall unit test suite.
  Tbool uninstall()
  { CALL
    m_X = 2;
    m_Y = 20;
    return true;
  }
} the_ExampleUnitTestSuite(STR("CExampleUnitTestSuite"), FILE);
/*--------------------------------------------------------------------------*/
class CExampleUnitTest1 :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_EQUAL(++the_Counter, 1);
    UT_ACCEPT;
  }
} the_ExampleUnitTest1;
/*--------------------------------------------------------------------------*/
class CExampleUnitTest2 :
  public CUnitTest
{
public:
  // Initialize unit test with a corresponding name and file name.
  CExampleUnitTest2(const CString& a_crName, const CString& a_crFileName) : CUnitTest(a_crName, a_crFileName) { CALL }

protected:
  // Install unit test.
  Tbool install()
  { CALL
    m_Z = the_ExampleUnitTestSuite.m_X + the_ExampleUnitTestSuite.m_Y + 100;
    return true;
  }

  // Uninstall unit test.
  Tbool uninstall()
  { CALL
    m_Z = the_ExampleUnitTestSuite.m_X + the_ExampleUnitTestSuite.m_Y + 200;
    return true;
  }

  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_EQUAL(++the_Counter, 2);
    UT_ASSERT_EQUAL(m_Z, 111);
    UT_ACCEPT;
  }

private:
  Tsint m_Z;
} the_ExampleUnitTest2(STR("CExampleUnitTest2"), FILE);
/*==========================================================================*/
