/*!
 *  \file    test-stream-CFilterCopy.cpp Testing of the CFilterCopy class.
 *  \brief   Testing of the CFilterCopy class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CFilterCopy class.

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
#include <Depth/include/stream/CFilterCopy.hpp>
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

    // Link string stream with some copy filters.
    CFilterCopy filter1(&stream, stream.isTextMode(), stream.getByteOrder(), stream.getLineEnding());
    CFilterCopy filter2(&filter1, filter1.isTextMode(), filter1.getByteOrder(), filter1.getLineEnding());
    CFilterCopy filter3(&filter2, filter2.isTextMode(), filter2.getByteOrder(), filter2.getLineEnding());

    // Open filter.
    UT_ASSERT(filter3.open(IStream::e_OPEN_READWRITE));
    UT_ASSERT(filter3.isOpened());
    UT_ASSERT(filter2.isOpened());
    UT_ASSERT(filter1.isOpened());
    UT_ASSERT(stream.isOpened());

    // Read from the filter.
    Tschar read_buffer[5];
    UT_ASSERT_EQUAL(filter3.readBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);

    // Write into the filter.
    UT_ASSERT_EQUAL(filter3.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);

    // Close filter.
    UT_ASSERT(filter3.close());
    UT_ASSERT(!filter3.isOpened());
    UT_ASSERT(!filter2.isOpened());
    UT_ASSERT(!filter1.isOpened());
    UT_ASSERT(!stream.isOpened());

    // Check string stream content.
    UT_ASSERT_EQUAL(stream[CONSTU(5)], STR('a'));
    UT_ASSERT_EQUAL(stream[CONSTU(6)], STR('b'));
    UT_ASSERT_EQUAL(stream[CONSTU(7)], STR('c'));
    UT_ASSERT_EQUAL(stream[CONSTU(8)], STR('d'));
    UT_ASSERT_EQUAL(stream[CONSTU(9)], STR('e'));

    // Open filter.
    UT_ASSERT(filter3.open(IStream::e_OPEN_WRITE));
    UT_ASSERT(filter3.isOpened());
    UT_ASSERT(filter2.isOpened());
    UT_ASSERT(filter1.isOpened());
    UT_ASSERT(stream.isOpened());

    // Write into the filter.
    UT_ASSERT_EQUAL(filter3.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);
    UT_ASSERT_EQUAL(filter3.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);
    UT_ASSERT_EQUAL(filter3.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 15);

    // Close filter.
    UT_ASSERT(filter3.close());
    UT_ASSERT(!filter3.isOpened());
    UT_ASSERT(!filter2.isOpened());
    UT_ASSERT(!filter1.isOpened());
    UT_ASSERT(!stream.isOpened());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
