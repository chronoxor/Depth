/*!
 *  \file    test-utility-CPair.cpp Testing of the CPair class.
 *  \brief   Testing of the CPair class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CPair class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth utility tests
    VERSION:   1.0
    CREATED:   22.01.2007 00:21:52

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
#include <Depth/include/utility/CPair.hpp>
#include <Depth/include/utility/CPairMaker.hpp>
#include <Depth/include/utility/CPairTier.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NBase;
using namespace NDepth::NUtility;
using namespace NDepth::NSerialization;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CPair<Tsint, Tfloat>  a(10, 20.3f);
    CPair<Tfloat, Tsint>  b(CPairMaker::make(10.3f, 20));
    CPair<Tsint, Tdouble> c(b);

    UT_ASSERT_EQUAL(a.getFirst(), 10);
    UT_ASSERT_EQUAL(b.getSecond(), 20);
    UT_ASSERT_EQUAL(c.getFirst(), 10);

    Tsint   first  = 100;
    Tdouble second = 150.3;
    CPair<CReference<Tsint>, CReference<Tdouble> > d = CPairTier::tie(first, second);

    UT_ASSERT_EQUAL((Tsint)d.getFirst(), 100);

    first  = 200;
    second = 300.5;

    UT_ASSERT_EQUAL((Tsint)d.getFirst(), 200);

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CPair<Tsint, Tchar> instance(100, STR('Z'));

    // Save instance.
    SaveArchive saver;
    UT_ASSERT(saver.open());
    UT_ASSERT(saver.serialize(instance));
    UT_ASSERT(saver.close());

    // Clear instance.
    instance.set(0, STR(' '));

    // Load instance.
    LoadArchive loader;
    UT_ASSERT(loader.open());
    UT_ASSERT(loader.serialize(instance));
    UT_ASSERT(loader.close());
    UT_ASSERT_EQUAL(instance.getFirst(), 100);
    UT_ASSERT_EQUAL(instance.getSecond(), STR('Z'));
  }
} the_Test;
/*==========================================================================*/
