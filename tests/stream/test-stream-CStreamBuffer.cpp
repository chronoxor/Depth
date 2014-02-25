/*!
 *  \file    test-stream-CStreamBuffer.cpp Testing of the CStreamBuffer 
 *           class.
 *  \brief   Testing of the CStreamBuffer class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CStreamBuffer class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream tests
    VERSION:   1.0
    CREATED:   25.08.2008 22:39:58

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
#include <Depth/include/stream/CStreamBuffer.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NStream;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    // Create static byte buffer.
    Tbyte buffer[10] = { ASC('a'), ASC('b'), ASC('c'), ASC('d'), ASC('e'), ASC('f'), ASC('g'), ASC('h'), ASC('i'), ASC('j') };
    CStreamBuffer stream(buffer, 10);

    // Open stream.
    UT_ASSERT(stream.open(IStream::e_OPEN_READWRITE));
    UT_ASSERT(stream.isOpened());

    // Read from the byte buffer.
    Tbyte read_buffer[5];
    UT_ASSERT_EQUAL(stream.readBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);

    // Write into the byte buffer.
    UT_ASSERT_EQUAL(stream.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.getSize(), 10);

    // Close stream.
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    // Check static byte buffer.
    UT_ASSERT_EQUAL(buffer[5], ASC('a'));
    UT_ASSERT_EQUAL(buffer[6], ASC('b'));
    UT_ASSERT_EQUAL(buffer[7], ASC('c'));
    UT_ASSERT_EQUAL(buffer[8], ASC('d'));
    UT_ASSERT_EQUAL(buffer[9], ASC('e'));

    // Create dynamic byte buffer content.
    CStreamBuffer dynamic(buffer, 10, false);

    // Open dynamic stream.
    UT_ASSERT(dynamic.open(IStream::e_OPEN_WRITE));
    UT_ASSERT(dynamic.isOpened());

    // Write into the byte buffer.
    UT_ASSERT_EQUAL(dynamic.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(dynamic.getSize(), 10);
    UT_ASSERT_EQUAL(dynamic.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(dynamic.getSize(), 10);
    UT_ASSERT_EQUAL(dynamic.writeBuffer(read_buffer, 5), 5);
    UT_ASSERT_EQUAL(dynamic.getSize(), 15);

    // Close dynamic stream.
    UT_ASSERT(dynamic.close());
    UT_ASSERT(!dynamic.isOpened());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
