/*!
 *  \file    test-application-IApplication.cpp Testing of the IApplication
 *           interface.
 *  \brief   Testing of the IApplication interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the IApplication interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth application tests
    VERSION:   1.0
    CREATED:   12.01.2009 01:20:11

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
#include <Depth/include/application/IApplication.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NApplication;
using namespace NDepth::NString;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT(IApplication::isCreated());
    UT_ASSERT(IApplication::isRunning());
    UT_ASSERT_MORE(IApplication::getCurrentRef().getArguments().getSize(), 0);
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(1)], CString(STR("test")));
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(2)], CString(STR("test\\test")));
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(3)], CString(STR("test\\\\test")));
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(4)], CString(STR("test\"test")));
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(5)], CString(STR("test'test")));
    UT_ASSERT_EQUAL(IApplication::getCurrentRef().getArguments()[CONSTU(6)], CString(STR("test test")));
    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
