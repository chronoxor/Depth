/*!
 *  \file    test-stream-CFilterXXE.cpp Testing of the CFilterXXE class.
 *  \brief   Testing of the CFilterXXE class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CFilterXXE class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream tests
    VERSION:   1.0
    CREATED:   11.11.2009 21:41:37

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
#include <Depth/include/stream/text/CFilterXXE.hpp>
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
    CStreamString buffer;
    UT_ASSERT(buffer.open(IStream::e_OPEN_WRITE));
    UT_ASSERT(buffer.isOpened());
    buffer << STR("Take this kiss upon the brow!") << ln;
    buffer << STR("And, in parting from you now,") << ln;
    buffer << STR("Thus much let me avow-") << ln;
    buffer << STR("You are not wrong, who deem") << ln;
    buffer << STR("That my days have been a dream;") << ln;
    buffer << STR("Yet if hope has flown away") << ln;
    buffer << STR("In a night, or in a day,") << ln;
    buffer << STR("In a vision, or in none,") << ln;
    buffer << STR("Is it therefore the less gone?") << ln;
    buffer << STR("All that we see or seem") << ln;
    buffer << STR("Is but a dream within a dream.") << ln;
    buffer << ln;
    buffer << STR("I stand amid the roar") << ln;
    buffer << STR("Of a surf-tormented shore,") << ln;
    buffer << STR("And I hold within my hand") << ln;
    buffer << STR("Grains of the golden sand-") << ln;
    buffer << STR("How few! yet how they creep") << ln;
    buffer << STR("Through my fingers to the deep,") << ln;
    buffer << STR("While I weep-while I weep!") << ln;
    buffer << STR("O God! can I not grasp") << ln;
    buffer << STR("Them with a tighter clasp?") << ln;
    buffer << STR("O God! can I not save") << ln;
    buffer << STR("One from the pitiless wave?") << ln;
    buffer << STR("Is all that we see or seem") << ln;
    buffer << STR("But a dream within a dream?") << ln;
    UT_ASSERT(buffer.close());

    // Use buffer stream.
    CStreamBuffer stream(0, false, true);

    // Link buffer stream with XXE filter.
    CFilterXXE filter(&stream, true, stream.isTextMode(), stream.getByteOrder(), stream.getLineEnding());

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
    UT_ASSERT(filter.read(read_buffer, NConstants::CConstants::uintMax).getFirst());

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
