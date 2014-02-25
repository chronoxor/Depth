/*!
 *  \file    test-string-CSystemString.cpp Testing of the CSystemString 
 *           class.
 *  \brief   Testing of the CSystemString class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.04.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CSystemString class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth string tests
    VERSION:   1.0
    CREATED:   29.04.2008 23:26:14

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
#include <Depth/include/string/CSystemString.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NSerialization;
using namespace NDepth::NString;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CSystemString a;
    CSystemString b(ASC('a'));
    CSystemString c(UNC('a'));
    CSystemString d(ASC("abc"));
    CSystemString e(UNC("abc"));
    CSystemString f(CSystemString::EMPTY);
    CSystemString g(e);

    // Check assign string operations.
    a = b;
    UT_ASSERT_EQUAL(a, b);
    a = ASC('a');
    UT_ASSERT_EQUAL(a, b);
    a = UNC('a');
    UT_ASSERT_EQUAL(a, c);
    a = ASC("abc");
    UT_ASSERT_EQUAL(a, d);
    a = UNC("abc");
    UT_ASSERT_EQUAL(a, e);

    // Check compare string operations.
    UT_ASSERT_EQUAL(b, c);
    UT_ASSERT_EQUAL(d, e);
    UT_ASSERT_EQUAL(f, CSystemString::EMPTY);
    UT_ASSERT_NOT_EQUAL(g, CSystemString::EMPTY);

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CSystemString instance(L"abc");

    // Save instance.
    SaveArchive saver;
    UT_ASSERT(saver.open());
    UT_ASSERT(saver.serialize(instance));
    UT_ASSERT(saver.close());

    Tuint size = instance.getSize();

    // Clear instance.
    UT_ASSERT(instance.clear());

    // Load instance.
    LoadArchive loader;
    UT_ASSERT(loader.open());
    UT_ASSERT(loader.serialize(instance));
    UT_ASSERT(loader.close());
    UT_ASSERT_EQUAL(instance.getSize(), size);
  }
} the_Test;
/*==========================================================================*/
