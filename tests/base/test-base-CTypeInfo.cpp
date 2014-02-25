/*!
 *  \file    test-base-CTypeInfo.cpp Testing of the CTypeInfo class.
 *  \brief   Testing of the CTypeInfo class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.02.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CTypeInfo class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth base tests
    VERSION:   1.0
    CREATED:   16.02.2007 20:23:59

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
#include <Depth/include/base/CTypeInfo.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NBase;
/*==========================================================================*/
class CTestClass { };
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CTypeInfo a;
    CTypeInfo b(typeid(Tuint*));
    CTypeInfo c(typeid(CTestClass&));
    CTypeInfo d(c);

    CTypeInfo z(typeid(Tuint*));

    a = b;

    UT_ASSERT_EQUAL(a, b);
    UT_ASSERT_NOT_EQUAL(a, c);
    UT_ASSERT_NOT_EQUAL(c, b);
    UT_ASSERT_EQUAL(c, d);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
