/*!
 *  \file    test-stream-CFilterFork.cpp Testing of the CFilterFork class.
 *  \brief   Testing of the CFilterFork class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CFilterFork class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream tests
    VERSION:   1.0
    CREATED:   19.03.2009 01:00:44

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
#include <Depth/include/stream/CFilterFork.hpp>
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
    // Use string stream.
    CString buffer(STR("abcdefghij"));
    CStreamString stream(buffer);
    CStreamString dupstream;

    // Link string stream with some copy filters.
    CFilterFork filter(&stream, &dupstream, stream.isTextMode(), stream.getByteOrder(), stream.getLineEnding());

    // Open filter.
    UT_ASSERT(filter.open(IStream::e_OPEN_READWRITE));
    UT_ASSERT(filter.isOpened());
    UT_ASSERT(stream.isOpened());
    UT_ASSERT(dupstream.isOpened());

    // Read from the filter.
    Tschar read_buffer[5];
    UT_ASSERT_EQUAL(filter.readBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);
    UT_ASSERT_EQUAL(dupstream.getSize(), 5);

    // Write into the filter.
    UT_ASSERT_EQUAL(filter.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);
    UT_ASSERT_EQUAL(dupstream.getSize(), 10);

    // Close filter.
    UT_ASSERT(filter.close());
    UT_ASSERT(!filter.isOpened());
    UT_ASSERT(!stream.isOpened());
    UT_ASSERT(!dupstream.isOpened());

    // Check string stream content.
    UT_ASSERT_EQUAL(stream[CONSTU(5)], STR('a'));
    UT_ASSERT_EQUAL(stream[CONSTU(6)], STR('b'));
    UT_ASSERT_EQUAL(stream[CONSTU(7)], STR('c'));
    UT_ASSERT_EQUAL(stream[CONSTU(8)], STR('d'));
    UT_ASSERT_EQUAL(stream[CONSTU(9)], STR('e'));

    // Open filter.
    UT_ASSERT(filter.open(IStream::e_OPEN_WRITE));
    UT_ASSERT(filter.isOpened());
    UT_ASSERT(stream.isOpened());
    UT_ASSERT(dupstream.isOpened());

    // Write into the filter.
    UT_ASSERT_EQUAL(filter.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);
    UT_ASSERT_EQUAL(dupstream.getSize(), 10);
    UT_ASSERT_EQUAL(filter.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);
    UT_ASSERT_EQUAL(dupstream.getSize(), 10);
    UT_ASSERT_EQUAL(filter.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 15);
    UT_ASSERT_EQUAL(dupstream.getSize(), 15);

    // Close filter.
    UT_ASSERT(filter.close());
    UT_ASSERT(!filter.isOpened());
    UT_ASSERT(!stream.isOpened());
    UT_ASSERT(!dupstream.isOpened());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
