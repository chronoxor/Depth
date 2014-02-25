/*!
 *  \file    test-stream-CStreamNULL.cpp Testing of the CStreamNULL class.
 *  \brief   Testing of the CStreamNULL class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CStreamNULL class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream tests
    VERSION:   1.0
    CREATED:   17.08.2008 02:48:27

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
#include <Depth/include/stream/CStreamNULL.hpp>
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
    Tbyte buffer[15];
    CStreamNULL stream;

    // Set peek buffer size.
    UT_ASSERT(stream.setPeekBufferSize(10));

    // Open stream.
    UT_ASSERT(stream.open(IStream::e_OPEN_READWRITE));
    UT_ASSERT(stream.isOpened());

    // Read, peek and push buffer.
    UT_ASSERT_EQUAL(stream.readBuffer(buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.peekBuffer(buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.pushBuffer(buffer, 5), 5);
    UT_ASSERT_EQUAL(stream.readBuffer(buffer, 15), 15);

    // Write buffer.
    UT_ASSERT_EQUAL(stream.writeBuffer(buffer, 10), 10);

    // Close stream.
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
