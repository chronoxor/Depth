/*!
 *  \file    test-stream-CStreamStringUnicode.cpp Testing of the
 *           CStreamStringUnicode class.
 *  \brief   Testing of the CStreamStringUnicode class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CStreamStringUnicode class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream tests
    VERSION:   1.0
    CREATED:   02.09.2008 00:51:38

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
#include <Depth/include/stream/text/CStreamStringUnicode.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NStream;
using namespace NDepth::NStream::NText;
using namespace NDepth::NString;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CStringUnicode buffer(UNC("abcdefghij"));
    CStreamStringUnicode stream(buffer);

    // Open stream.
    UT_ASSERT(stream.open(IStream::e_OPEN_READWRITE));
    UT_ASSERT(stream.isOpened());

    // Read from the Unicode string.
    Twchar read_buffer[5];
    UT_ASSERT_EQUAL(stream.readBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);

    // Write into the Unicode string.
    UT_ASSERT_EQUAL(stream.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);

    // Close stream.
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    // Check Unicode string content.
    UT_ASSERT_EQUAL(stream[CONSTU(5)], UNC('a'));
    UT_ASSERT_EQUAL(stream[CONSTU(6)], UNC('b'));
    UT_ASSERT_EQUAL(stream[CONSTU(7)], UNC('c'));
    UT_ASSERT_EQUAL(stream[CONSTU(8)], UNC('d'));
    UT_ASSERT_EQUAL(stream[CONSTU(9)], UNC('e'));

    // Open stream.
    UT_ASSERT(stream.open(IStream::e_OPEN_WRITE));
    UT_ASSERT(stream.isOpened());

    // Write into the Unicode string.
    UT_ASSERT_EQUAL(stream.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);
    UT_ASSERT_EQUAL(stream.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);
    UT_ASSERT_EQUAL(stream.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 15);

    // Close stream.
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
