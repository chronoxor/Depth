/*!
 *  \file    test-string-CStringUnicode.cpp Testing of the CStringUnicode 
 *           class.
 *  \brief   Testing of the CStringUnicode class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CStringUnicode class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth string tests
    VERSION:   1.0
    CREATED:   05.08.2008 01:39:50

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
#include <Depth/include/string/CStringUnicode.hpp>
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
    CStringUnicode a;
    CStringUnicode b(UNC('a'));
    CStringUnicode c(UNC("abc"));
    CStringUnicode d(CStringUnicode::EMPTY);
    CStringUnicode e(c);

    // Check assign string operations.
    a = b;
    UT_ASSERT_EQUAL(a, b);
    a = UNC('a');
    UT_ASSERT_EQUAL(a, b);
    a = UNC("abc");
    UT_ASSERT_EQUAL(a, c);

    // Check compare string operations.
    UT_ASSERT_EQUAL(d, CStringUnicode::EMPTY);
    UT_ASSERT_NOT_EQUAL(e, CStringUnicode::EMPTY);
    UT_ASSERT_EQUAL(CStringUnicode::compare(e, UNC("abc")), 0);
    UT_ASSERT_NOT_EQUAL(CStringUnicode::compare(e, UNC("aBc")), 0);
    UT_ASSERT_NOT_EQUAL(CStringUnicode::compare(e, UNC("ABC")), 0);
    UT_ASSERT_EQUAL(CStringUnicode::compareIgnoreCase(e, UNC("abc")), 0);
    UT_ASSERT_EQUAL(CStringUnicode::compareIgnoreCase(e, UNC("aBc")), 0);
    UT_ASSERT_EQUAL(CStringUnicode::compareIgnoreCase(e, UNC("ABC")), 0);

    // Check sub-string string operation.
    a = UNC("abcdef");
    b = a.getLeft(3);
    UT_ASSERT_EQUAL(b[CONSTU(0)], UNC('a'));
    UT_ASSERT_EQUAL(b[CONSTU(1)], UNC('b'));
    UT_ASSERT_EQUAL(b[CONSTU(2)], UNC('c'));
    b = a.getRight(3);
    UT_ASSERT_EQUAL(b[CONSTU(0)], UNC('d'));
    UT_ASSERT_EQUAL(b[CONSTU(1)], UNC('e'));
    UT_ASSERT_EQUAL(b[CONSTU(2)], UNC('f'));
    b = a.getMiddle(1, 4);
    UT_ASSERT_EQUAL(b[CONSTU(0)], UNC('b'));
    UT_ASSERT_EQUAL(b[CONSTU(1)], UNC('c'));
    UT_ASSERT_EQUAL(b[CONSTU(2)], UNC('d'));
    UT_ASSERT_EQUAL(b[CONSTU(3)], UNC('e'));

    // Check reverse string operation.
    a = UNC("abc");
    a.reverse();
    UT_ASSERT_EQUAL(a[CONSTU(0)], UNC('c'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], UNC('b'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], UNC('a'));

    // Check case conversion string operations.
    a = UNC("ABC");
    a.toLowerCase();
    UT_ASSERT_EQUAL(a[CONSTU(0)], UNC('a'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], UNC('b'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], UNC('c'));
    a = UNC("abc");
    a.toUpperCase();
    UT_ASSERT_EQUAL(a[CONSTU(0)], UNC('A'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], UNC('B'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], UNC('C'));
    a = UNC("abc");
    a.toTitleCase();
    UT_ASSERT_EQUAL(a[CONSTU(0)], UNC('A'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], UNC('B'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], UNC('C'));
    a = UNC("aBc");
    a.toToggleCase();
    UT_ASSERT_EQUAL(a[CONSTU(0)], UNC('A'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], UNC('b'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], UNC('C'));

    // Check append/prepend/insert/replace/remove string operations.
    a = UNC("abc");
    UT_ASSERT(a.insertFirst(UNC("^")));
    UT_ASSERT(a.insertLast(UNC("$")));
    UT_ASSERT(a.insertIndex(2, UNC('!')));
    UT_ASSERT(a.insertIndex(4, UNC('?')));
    UT_ASSERT_EQUAL(a[CONSTU(0)], UNC('^'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], UNC('a'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], UNC('!'));
    UT_ASSERT_EQUAL(a[CONSTU(3)], UNC('b'));
    UT_ASSERT_EQUAL(a[CONSTU(4)], UNC('?'));
    UT_ASSERT_EQUAL(a[CONSTU(5)], UNC('c'));
    UT_ASSERT_EQUAL(a[CONSTU(6)], UNC('$'));
    UT_ASSERT_EQUAL(a.getSize(), 7);
    UT_ASSERT(a.replace(2, 3, UNC("...")));
    UT_ASSERT_EQUAL(a[CONSTU(0)], UNC('^'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], UNC('a'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], UNC('.'));
    UT_ASSERT_EQUAL(a[CONSTU(3)], UNC('.'));
    UT_ASSERT_EQUAL(a[CONSTU(4)], UNC('.'));
    UT_ASSERT_EQUAL(a[CONSTU(5)], UNC('c'));
    UT_ASSERT_EQUAL(a[CONSTU(6)], UNC('$'));
    UT_ASSERT_EQUAL(a.getSize(), 7);
    UT_ASSERT(a.remove(0, 2));
    UT_ASSERT(a.remove(3, 2));
    UT_ASSERT_EQUAL(a[CONSTU(0)], UNC('.'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], UNC('.'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], UNC('.'));
    UT_ASSERT_EQUAL(a.getSize(), 3);

    // Check conversion to system string.
    a = UNC("abc");
    UT_ASSERT(a.insertCEnd());
    CSystemString s = a;
    UT_ASSERT_EQUAL(s, CSystemString(UNC("abc"), true));
    UT_ASSERT(a.removeCEnd())

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CStringUnicode instance(UNC("abc"));

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
