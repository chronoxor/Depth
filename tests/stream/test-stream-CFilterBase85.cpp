/*!
 *  \file    test-stream-CFilterBase85.cpp Testing of the CFilterBase85 
 *           class.
 *  \brief   Testing of the CFilterBase85 class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CFilterBase85 class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream tests
    VERSION:   1.0
    CREATED:   16.11.2009 02:48:09

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
#include <Depth/include/stream/text/CFilterBase85.hpp>
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
    CString buffer(STR("The quick brown fox jumps over the lazy dog"));

    // Use buffer stream.
    CStreamBuffer stream(0, false, true);

    // Link buffer stream with Base85 filter.
    CFilterBase85 filter(&stream, true, stream.isTextMode(), stream.getByteOrder(), stream.getLineEnding());

    // Open filter for writing.
    UT_ASSERT(filter.open(IStream::e_OPEN_WRITE));
    UT_ASSERT(filter.isOpened());
    UT_ASSERT(stream.isOpened());

    // Write into the filter.
    UT_ASSERT(filter.write(buffer).getFirst());

    // Close filter.
    UT_ASSERT(filter.close());
    UT_ASSERT(!filter.isOpened());
    UT_ASSERT(!stream.isOpened());

    // Open filter for reading.
    UT_ASSERT(filter.open(IStream::e_OPEN_READ));
    UT_ASSERT(filter.isOpened());
    UT_ASSERT(stream.isOpened());

    // Read from the filter.
    CString read_buffer;
    UT_ASSERT(filter.read(read_buffer).getFirst());

    // Close filter.
    UT_ASSERT(filter.close());
    UT_ASSERT(!filter.isOpened());
    UT_ASSERT(!stream.isOpened());

    // Compare strings.
    UT_ASSERT_EQUAL(read_buffer, buffer);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
