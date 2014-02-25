/*!
 *  \file    test-tuple-CTuple.cpp Testing of the CTuple class.
 *  \brief   Testing of the CTuple class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CTuple class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth tuple tests
    VERSION:   1.0
    CREATED:   28.01.2007 01:18:52

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
#include <Depth/include/tuple/CTuple.hpp>
#include <Depth/include/tuple/CTupleMaker.hpp>
#include <Depth/include/tuple/CTupleTier.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NBase;
using namespace NDepth::NMath;
using namespace NDepth::NSerialization;
using namespace NDepth::NTuple;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CTuple<Tsint, Tfloat, Tchar>  a(10, 20.3f, STR('A'));
    CTuple<Tfloat, Tsint, Tchar>  b(CTupleMaker::make(10.3f, 20, STR('B')));
    CTuple<Tsint, Tdouble, Tchar> c(b);

    UT_ASSERT_EQUAL(a.getValue<1>(), 10);
    UT_ASSERT_EQUAL(a.getValue<3>(), STR('A'));
    UT_ASSERT_EQUAL(b.getValue<2>(), 20);
    UT_ASSERT_EQUAL(b.getValue<3>(), STR('B'));
    UT_ASSERT_EQUAL(c.getValue<1>(), 10);
    UT_ASSERT_EQUAL(c.getValue<3>(), STR('B'));

    Tsint   first  = 100;
    Tdouble second = 150.3;
    Tchar   third  = STR('X');
    CTuple<CReference<Tsint>, CReference<Tdouble>, CReference<Tchar> > d = CTupleTier::tie(first, second, third);

    UT_ASSERT_EQUAL((Tsint)d.getValue<1>(), 100);
    UT_ASSERT_EQUAL((Tchar)d.getValue<3>(), STR('X'));

    first  = 200;
    second = 300.5;
    third  = STR('Z');

    UT_ASSERT_EQUAL((Tsint)d.getValue<1>(), 200);
    UT_ASSERT_EQUAL((Tchar)d.getValue<3>(), STR('Z'));

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CTuple<Tsint, Tchar, Treal> instance(100, STR('Z'), CONSTR(200.3));

    // Save instance.
    SaveArchive saver;
    UT_ASSERT(saver.open());
    UT_ASSERT(saver.serialize(instance));
    UT_ASSERT(saver.close());

    // Clear instance.
    instance.set(0, STR(' '), CONSTR(0.0));

    // Load instance.
    LoadArchive loader;
    UT_ASSERT(loader.open());
    UT_ASSERT(loader.serialize(instance));
    UT_ASSERT(loader.close());
    UT_ASSERT_EQUAL(instance.getValue<1>(), 100);
    UT_ASSERT_EQUAL(instance.getValue<2>(), STR('Z'));
    UT_ASSERT_DELTA(instance.getValue<3>(), 200.3, 0.0001);
  }
} the_Test;
/*==========================================================================*/
