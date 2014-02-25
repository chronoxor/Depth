/*!
 *  \file    test-utility-CPtrRefCounter.cpp Testing of the CPtrRefCounter class.
 *  \brief   Testing of the CPtrRefCounter class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CPtrRefCounter class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth utility tests
    VERSION:   1.0
    CREATED:   30.06.2007 20:51:30

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
#include <Depth/include/utility/CPtrRefCounter.hpp>
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
      CPtrRefCounter<CTestClass> ptr(new CTestClass[2], true);
      CPtrRefCounter<CTestClass> ptr1(ptr);
      CPtrRefCounter<CTestClass> ptr2(ptr1);
      UT_ASSERT_EQUAL(the_Counter, 2);

      // Check counter value.
      UT_ASSERT_EQUAL(ptr.getRefCount(), 3);
    }
    UT_ASSERT_ZERO(the_Counter);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
