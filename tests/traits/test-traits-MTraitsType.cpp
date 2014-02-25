/*!
 *  \file    test-traits-MTraitsType.cpp Testing of the MTraitsType meta-class.
 *  \brief   Testing of the MTraitsType meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the MTraitsType meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth traits tests
    VERSION:   1.0
    CREATED:   01.01.2007 01:28:53

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
#include <Depth/include/traits/MTraitsType.hpp>
#include <Depth/include/traits/MTraitsRoutine.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NTraits;
/*==========================================================================*/
class CTestClass
{
public:
  Tsint method(Tsint a, Tsint b)
  { CALL
    return a + b;
  }

  Tsint method_const(Tsint a, Tsint b) const
  { CALL
    return a + b;
  }

  static Tsint method_static(Tsint a, Tsint b)
  { CALL
    return a + b;
  }
};
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    MTraitsType<Tsint CTestClass::*>::parent a;
    MTraitsFunction<Tsint (CTestClass::*)(Tsint, Tsint)>::type method = &CTestClass::method;
    MTraitsFunction<Tsint (CTestClass::*)(Tsint, Tsint) const>::type method_const = &CTestClass::method_const;
    MTraitsFunction<Tsint (*)(Tsint, Tsint)>::type method_static = &CTestClass::method_static;

    UT_ASSERT_EQUAL((a.*method)(10, 20), 30);
    UT_ASSERT_EQUAL((a.*method_const)(10, 20), 30);
    UT_ASSERT_EQUAL(method_static(10, 20), 30);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
