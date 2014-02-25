/*!
 *  \file    test-utility-CPtrAuto.cpp Testing of the CPtrAuto class.
 *  \brief   Testing of the CPtrAuto class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CPtrAuto class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth utility tests
    VERSION:   1.0
    CREATED:   30.06.2007 20:44:57

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
#include <Depth/include/utility/CPtrAuto.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NUtility;
/*==========================================================================*/
static Tuint the_Counter = 0;
/*--------------------------------------------------------------------------*/
class CTestClass
{
public:
  CTestClass()
  { CALL
    ++the_Counter;
  }
 ~CTestClass()
  { CALL
    --the_Counter;
  }
};
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_ZERO(the_Counter);
    {
      CPtrAuto<CTestClass> scope(new CTestClass[2], true);
      UT_ASSERT_EQUAL(the_Counter, 2);
    }
    UT_ASSERT_ZERO(the_Counter);
    {
      CPtrAuto<CTestClass> scope1(new CTestClass);
      CPtrAuto<CTestClass> scope2(scope1);
      CPtrAuto<CTestClass> scope3(scope2.release());
      UT_ASSERT_EQUAL(the_Counter, 1);
    }
    UT_ASSERT_ZERO(the_Counter);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
