/*!
 *  \file    test-tuple-CComparableTuple.cpp Testing of the CComparableTuple
 *           class.
 *  \brief   Testing of the CComparableTuple class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CComparableTuple class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth tuple tests
    VERSION:   1.0
    CREATED:   30.01.2007 00:36:29

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
#include <Depth/include/tuple/CComparableTuple.hpp>
#include <Depth/include/tuple/CComparableTupleMaker.hpp>
#include <Depth/include/tuple/CComparableTupleTier.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NSerialization;
using namespace NDepth::NTuple;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CComparableTuple<Tsint, Tchar, Treal> a(10, STR('A'), CONSTR(100.3));
    CComparableTuple<Tsint, Tchar, Treal> b(10, STR('B'), CONSTR(200.6));
    CComparableTuple<Tsint, Tchar, Treal> c(20, STR('C'), CONSTR(300.9));

    UT_ASSERT( (a == a));
    UT_ASSERT(!(a == b));
    UT_ASSERT( (a != b));
    UT_ASSERT(!(b <  a));
    UT_ASSERT(!(b <= a));
    UT_ASSERT( (c >  b));
    UT_ASSERT( (c >= b));

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CComparableTuple<Tsint, Tchar, Treal> instance(100, STR('Z'), CONSTR(200.3));

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
