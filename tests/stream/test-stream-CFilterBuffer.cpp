/*!
 *  \file    test-stream-CFilterBuffer.cpp Testing of the CFilterBuffer 
 *           class.
 *  \brief   Testing of the CFilterBuffer class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CFilterBuffer class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream tests
    VERSION:   1.0
    CREATED:   22.03.2009 23:48:10

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
#include <Depth/include/stream/CFilterBuffer.hpp>
#include <Depth/include/stream/text/CStreamString.hpp>
#include <Depth/include/string/CString.hpp>
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
    // Use Unicode string stream.
    CStreamStringUnicode stream;

    // Link string stream with buffer filter.
    CFilterBuffer filter(&stream, 5 * sizeof(Twchar), true, stream.isTextMode(), stream.getByteOrder(), stream.getLineEnding());

    // Open filter.
    UT_ASSERT(filter.open(IStream::e_OPEN_WRITE));
    UT_ASSERT(stream.isOpened());

    // Write into the filter.
    Twchar write_buffer[10] = { UNC('a'), UNC('b'), UNC('c'), UNC('d'), UNC('e'), UNC('f'), UNC('g'), UNC('h'), UNC('i'), UNC('j') };
    UT_ASSERT_EQUAL(filter.writeBuffer(write_buffer, 3), 3);
    UT_ASSERT_EQUAL(stream.getSize(), 0);
    UT_ASSERT_EQUAL(filter.writeBuffer(write_buffer, 3), 3);
    UT_ASSERT_EQUAL(stream.getSize(), 5);
    UT_ASSERT_EQUAL(filter.writeBuffer(write_buffer, 10), 10);
    UT_ASSERT_EQUAL(stream.getSize(), 15);

    // Close filter.
    UT_ASSERT(filter.close());
    UT_ASSERT(!filter.isOpened());
    UT_ASSERT(!stream.isOpened());
    UT_ASSERT_EQUAL(stream.getSize(), 16);

    // Check string stream content.
    UT_ASSERT_EQUAL(stream[CONSTU(0)], UNC('a'));
    UT_ASSERT_EQUAL(stream[CONSTU(1)], UNC('b'));
    UT_ASSERT_EQUAL(stream[CONSTU(2)], UNC('c'));
    UT_ASSERT_EQUAL(stream[CONSTU(3)], UNC('a'));
    UT_ASSERT_EQUAL(stream[CONSTU(4)], UNC('b'));
    UT_ASSERT_EQUAL(stream[CONSTU(5)], UNC('c'));
    UT_ASSERT_EQUAL(stream[CONSTU(6)], UNC('a'));
    UT_ASSERT_EQUAL(stream[CONSTU(7)], UNC('b'));
    UT_ASSERT_EQUAL(stream[CONSTU(8)], UNC('c'));
    UT_ASSERT_EQUAL(stream[CONSTU(9)], UNC('d'));
    UT_ASSERT_EQUAL(stream[CONSTU(10)], UNC('e'));
    UT_ASSERT_EQUAL(stream[CONSTU(11)], UNC('f'));
    UT_ASSERT_EQUAL(stream[CONSTU(12)], UNC('g'));
    UT_ASSERT_EQUAL(stream[CONSTU(13)], UNC('h'));
    UT_ASSERT_EQUAL(stream[CONSTU(14)], UNC('i'));
    UT_ASSERT_EQUAL(stream[CONSTU(15)], UNC('j'));

    // Append some characters to the Unicode string stream.
    UT_ASSERT(stream.insertLast(UNC("abc")));
    UT_ASSERT_EQUAL(stream.getSize(), 19);

    // Open filter.
    UT_ASSERT(filter.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());

    // Read from the filter.
    Twchar read_buffer[10];
    UT_ASSERT_EQUAL(filter.readBuffer(read_buffer, 3), 3);
    UT_ASSERT_EQUAL(stream.getPosition(), 5);
    UT_ASSERT_EQUAL(filter.readBuffer(read_buffer, 3), 3);
    UT_ASSERT_EQUAL(stream.getPosition(), 10);
    UT_ASSERT_EQUAL(filter.readBuffer(read_buffer, 10), 10);
    UT_ASSERT_EQUAL(stream.getPosition(), 16);

    // Close filter.
    UT_ASSERT(filter.close());
    UT_ASSERT(!filter.isOpened());
    UT_ASSERT(!stream.isOpened());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
