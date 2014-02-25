/*!
 *  \file    test-stream-CFilterUTF.cpp Testing of the CFilterUTF class.
 *  \brief   Testing of the CFilterUTF class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.10.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CFilterUTF class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream tests
    VERSION:   1.0
    CREATED:   28.10.2009 03:22:04

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
#include <Depth/include/stream/text/CFilterUTF.hpp>
#include <Depth/include/stream/text/CFilterUTF8.hpp>
#include <Depth/include/stream/text/CFilterUTF16.hpp>
#include <Depth/include/stream/text/CFilterUTF32.hpp>
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
  // Launch filter test.
  Tbool testFilter(IFilter& a_crFilter, IReaderWriter& a_crStream)
  { CALL
    CString buffer(STR("The quick brown fox jumps over the lazy dog"));

    // Open filter for writing.
    UT_ASSERT(a_crFilter.open(IStream::e_OPEN_WRITE));
    UT_ASSERT(a_crFilter.isOpened());
    UT_ASSERT(a_crStream.isOpened());

    // Write into the filter.
    UT_ASSERT(a_crFilter.write(buffer).getFirst());

    // Close filter.
    UT_ASSERT(a_crFilter.close());
    UT_ASSERT(!a_crFilter.isOpened());
    UT_ASSERT(!a_crStream.isOpened());

    // Open filter for reading.
    UT_ASSERT(a_crFilter.open(IStream::e_OPEN_READ));
    UT_ASSERT(a_crFilter.isOpened());
    UT_ASSERT(a_crStream.isOpened());

    // Read from the filter.
    CString read_buffer;
    UT_ASSERT(a_crFilter.read(read_buffer).getFirst());

    // Close filter.
    UT_ASSERT(a_crFilter.close());
    UT_ASSERT(!a_crFilter.isOpened());
    UT_ASSERT(!a_crStream.isOpened());

    // Compare strings.
    return (read_buffer == buffer);
  }

  // Launch UTF filter test.
  Tbool testUTFFilter(const CFilterUTF& a_crUTFFilter)
  { CALL
    // Use buffer stream.
    CStreamBuffer stream(0, false, true);

    // Link buffer stream with UTF filter.
    CFilterUTF filter(&stream, a_crUTFFilter.getUTFType(), a_crUTFFilter.isBOMUsed(), stream.isTextMode(), stream.getByteOrder(), stream.getLineEnding());

    // Launch test.
    return testFilter(filter, stream);
  }

  // Launch UTF-8 filter test.
  Tbool testUTF8Filter()
  { CALL
    // Use buffer stream.
    CStreamBuffer stream(0, false, true);

    // Link buffer stream with UTF-8 filter.
    CFilterUTF8 filter(&stream, stream.isTextMode(), stream.getByteOrder(), stream.getLineEnding());

    // Launch test.
    return testFilter(filter, stream);
  }

  // Launch UTF-16 filter test.
  Tbool testUTF16Filter(const CFilterUTF16& a_crUTFFilter)
  { CALL
    // Use buffer stream.
    CStreamBuffer stream(0, false, true);

    // Link buffer stream with UTF-16 filter.
    CFilterUTF16 filter(&stream, a_crUTFFilter.isBigEndian(), stream.isTextMode(), stream.getByteOrder(), stream.getLineEnding());

    // Launch test.
    return testFilter(filter, stream);
  }

  // Launch UTF-32 filter test.
  Tbool testUTF32Filter(const CFilterUTF32& a_crUTFFilter)
  { CALL
    // Use buffer stream.
    CStreamBuffer stream(0, false, true);

    // Link buffer stream with UTF-32 filter.
    CFilterUTF32 filter(&stream, a_crUTFFilter.isBigEndian(), stream.isTextMode(), stream.getByteOrder(), stream.getLineEnding());

    // Launch test.
    return testFilter(filter, stream);
  }

  // Launch unit test.
  EUnitTestResult test()
  { CALL
    // Test CFilterUTF class.
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_AUTODETECT, true)));
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_AUTODETECT, false)));
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_UTF8, true)));
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_UTF8, false)));
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_UTF16BE, true)));
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_UTF16BE, false)));
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_UTF16LE, true)));
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_UTF16LE, false)));
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_UTF32BE, true)));
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_UTF32BE, false)));
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_UTF32LE, true)));
    UT_ASSERT(testUTFFilter(CFilterUTF(CFilterUTF::e_UTF32LE, false)));

    // Test CFilterUTF8 class.
    UT_ASSERT(testUTF8Filter());

    // Test CFilterUTF16 class.
    UT_ASSERT(testUTF16Filter(CFilterUTF16()));
    UT_ASSERT(testUTF16Filter(CFilterUTF16(true)));
    UT_ASSERT(testUTF16Filter(CFilterUTF16(false)));

    // Test CFilterUTF32 class.
    UT_ASSERT(testUTF32Filter(CFilterUTF32()));
    UT_ASSERT(testUTF32Filter(CFilterUTF32(true)));
    UT_ASSERT(testUTF32Filter(CFilterUTF32(false)));

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
