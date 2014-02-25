/*!
 *  \file    test-string-CStringASCII.cpp Testing of the CStringASCII class.
 *  \brief   Testing of the CStringASCII class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CStringASCII class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth string tests
    VERSION:   1.0
    CREATED:   05.08.2008 01:01:52

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
#include <Depth/include/string/CStringASCII.hpp>
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
    CStringASCII a;
    CStringASCII b(ASC('a'));
    CStringASCII c(ASC("abc"));
    CStringASCII d(CStringASCII::EMPTY);
    CStringASCII e(c);

    // Check assign string operations.
    a = b;
    UT_ASSERT_EQUAL(a, b);
    a = ASC('a');
    UT_ASSERT_EQUAL(a, b);
    a = ASC("abc");
    UT_ASSERT_EQUAL(a, c);

    // Check compare string operations.
    UT_ASSERT_EQUAL(d, CStringASCII::EMPTY);
    UT_ASSERT_NOT_EQUAL(e, CStringASCII::EMPTY);
    UT_ASSERT_EQUAL(CStringASCII::compare(e, ASC("abc")), 0);
    UT_ASSERT_NOT_EQUAL(CStringASCII::compare(e, ASC("aBc")), 0);
    UT_ASSERT_NOT_EQUAL(CStringASCII::compare(e, ASC("ABC")), 0);
    UT_ASSERT_EQUAL(CStringASCII::compareIgnoreCase(e, ASC("abc")), 0);
    UT_ASSERT_EQUAL(CStringASCII::compareIgnoreCase(e, ASC("aBc")), 0);
    UT_ASSERT_EQUAL(CStringASCII::compareIgnoreCase(e, ASC("ABC")), 0);

    // Check sub-string string operation.
    a = ASC("abcdef");
    b = a.getLeft(3);
    UT_ASSERT_EQUAL(b[CONSTU(0)], ASC('a'));
    UT_ASSERT_EQUAL(b[CONSTU(1)], ASC('b'));
    UT_ASSERT_EQUAL(b[CONSTU(2)], ASC('c'));
    b = a.getRight(3);
    UT_ASSERT_EQUAL(b[CONSTU(0)], ASC('d'));
    UT_ASSERT_EQUAL(b[CONSTU(1)], ASC('e'));
    UT_ASSERT_EQUAL(b[CONSTU(2)], ASC('f'));
    b = a.getMiddle(1, 4);
    UT_ASSERT_EQUAL(b[CONSTU(0)], ASC('b'));
    UT_ASSERT_EQUAL(b[CONSTU(1)], ASC('c'));
    UT_ASSERT_EQUAL(b[CONSTU(2)], ASC('d'));
    UT_ASSERT_EQUAL(b[CONSTU(3)], ASC('e'));

    // Check reverse string operation.
    a = ASC("abc");
    a.reverse();
    UT_ASSERT_EQUAL(a[CONSTU(0)], ASC('c'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], ASC('b'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], ASC('a'));

    // Check case conversion string operations.
    a = ASC("ABC");
    a.toLowerCase();
    UT_ASSERT_EQUAL(a[CONSTU(0)], ASC('a'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], ASC('b'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], ASC('c'));
    a = ASC("abc");
    a.toUpperCase();
    UT_ASSERT_EQUAL(a[CONSTU(0)], ASC('A'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], ASC('B'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], ASC('C'));
    a = ASC("abc");
    a.toTitleCase();
    UT_ASSERT_EQUAL(a[CONSTU(0)], ASC('A'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], ASC('B'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], ASC('C'));
    a = ASC("aBc");
    a.toToggleCase();
    UT_ASSERT_EQUAL(a[CONSTU(0)], ASC('A'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], ASC('b'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], ASC('C'));

    // Check insert/replace/remove string operations.
    a = ASC("abc");
    UT_ASSERT(a.insertFirst(ASC("^")));
    UT_ASSERT(a.insertLast(ASC("$")));
    UT_ASSERT(a.insertIndex(2, ASC('!')));
    UT_ASSERT(a.insertIndex(4, ASC('?')));
    UT_ASSERT_EQUAL(a[CONSTU(0)], ASC('^'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], ASC('a'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], ASC('!'));
    UT_ASSERT_EQUAL(a[CONSTU(3)], ASC('b'));
    UT_ASSERT_EQUAL(a[CONSTU(4)], ASC('?'));
    UT_ASSERT_EQUAL(a[CONSTU(5)], ASC('c'));
    UT_ASSERT_EQUAL(a[CONSTU(6)], ASC('$'));
    UT_ASSERT_EQUAL(a.getSize(), 7);
    UT_ASSERT(a.replace(2, 3, ASC("...")));
    UT_ASSERT_EQUAL(a[CONSTU(0)], ASC('^'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], ASC('a'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], ASC('.'));
    UT_ASSERT_EQUAL(a[CONSTU(3)], ASC('.'));
    UT_ASSERT_EQUAL(a[CONSTU(4)], ASC('.'));
    UT_ASSERT_EQUAL(a[CONSTU(5)], ASC('c'));
    UT_ASSERT_EQUAL(a[CONSTU(6)], ASC('$'));
    UT_ASSERT_EQUAL(a.getSize(), 7);
    UT_ASSERT(a.remove(0, 2));
    UT_ASSERT(a.remove(3, 2));
    UT_ASSERT_EQUAL(a[CONSTU(0)], ASC('.'));
    UT_ASSERT_EQUAL(a[CONSTU(1)], ASC('.'));
    UT_ASSERT_EQUAL(a[CONSTU(2)], ASC('.'));
    UT_ASSERT_EQUAL(a.getSize(), 3);

    // Check conversion to system string.
    a = ASC("abc");
    UT_ASSERT(a.insertCEnd());
    CSystemString s = a;
    UT_ASSERT_EQUAL(s, CSystemString(ASC("abc"), true));
    UT_ASSERT(a.removeCEnd())

    // Check serialization functionality.
    UT_ASSERT_CHECK_SERIALIZATION();

    UT_ACCEPT;
  }

  // Check the serialization functionality.
  void UT_ASSERT_CHECK_SERIALIZATION()
  { CALL
    CStringASCII instance(ASC("abc"));

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
