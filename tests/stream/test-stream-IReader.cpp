/*!
 *  \file    test-stream-IReader.cpp Testing of the IReader interface.
 *  \brief   Testing of the IReader interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the IReader interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream tests
    VERSION:   1.0
    CREATED:   12.09.2008 20:10:48

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
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/stream/text/CStreamString.hpp>
#include <Depth/include/string/CString.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NBase;
using namespace NDepth::NMath;
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
    CStreamString stream;

    // Read characters from the stream.
    Tchar c[8];
    UT_ASSERT(stream.set(STR("\x24\x41\x5E\x7F\x0024\x00A2\x00D0\x00FF")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(c[0]).getFirst());
    UT_ASSERT(stream.read(c[1]).getFirst());
    UT_ASSERT(stream.read(c[2]).getFirst());
    UT_ASSERT(stream.read(c[3]).getFirst());
    UT_ASSERT(stream.read(c[4]).getFirst());
    UT_ASSERT(stream.read(c[5]).getFirst());
    UT_ASSERT(stream.read(c[6]).getFirst());
    UT_ASSERT(stream.read(c[7]).getFirst());
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    // Read strings from the string stream.
    Tstr stringC = NULL;
    Tsstr stringCASCII = NULL;
    Twstr stringCUnicode = NULL;
    UT_ASSERT(stream.set(STR("abcdef\nabcdef\r\nabcdef")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(stringC).getFirst());
    UT_ASSERT(stream.read(stringCASCII).getFirst());
    UT_ASSERT(stream.read(stringCUnicode).getFirst());
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());
    UT_ASSERT_EQUAL(CString(stringC), CString(STR("abcdef")));
    UT_ASSERT_EQUAL(CStringASCII(stringCASCII), CStringASCII(ASC("abcdef")));
    UT_ASSERT_EQUAL(CStringUnicode(stringCUnicode), CStringUnicode(UNC("abcdef")));
    delete [] stringC;
    delete [] stringCASCII;
    delete [] stringCUnicode;

    stringC = NULL;
    UT_ASSERT(stream.set(STR("abcdef\nabcdef\r\nabcdef")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(stringC, NConstants::CConstants::uintMax).getFirst());
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());
    UT_ASSERT_EQUAL(CString(stringC), stream);
    delete [] stringC;

    CStringASCII stringASCII;
    CStringUnicode stringUnicode;
    CSystemString stringSystem;
    UT_ASSERT(stream.set(STR("abcdef\nabcdef\r\nabcdef")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(stringASCII).getFirst());
    UT_ASSERT(stream.read(stringUnicode).getFirst());
    UT_ASSERT(stream.read(stringSystem).getFirst());
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());
    UT_ASSERT_EQUAL(stringASCII, CStringASCII(ASC("abcdef")));
    UT_ASSERT_EQUAL(stringUnicode, CStringUnicode(UNC("abcdef")));
    UT_ASSERT_EQUAL(stringSystem, CString(STR("abcdef")).operator CSystemString());

    CString string;
    UT_ASSERT(stream.set(STR("abcdef\nabcdef\r\nabcdef")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(string, NConstants::CConstants::uintMax).getFirst());
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());
    UT_ASSERT_EQUAL(string, stream);

    // Read boolean numbers from the string stream.
    Tbool bool_value;
    UT_ASSERT(stream.set(STR("0 1 false true FaLsE tRuE invalid")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(bool_value).getFirst());
    UT_ASSERT(!bool_value);
    UT_ASSERT(stream.read(bool_value).getFirst());
    UT_ASSERT(bool_value);
    UT_ASSERT(stream.read(bool_value).getFirst());
    UT_ASSERT(!bool_value);
    UT_ASSERT(stream.read(bool_value).getFirst());
    UT_ASSERT(bool_value);
    UT_ASSERT(stream.read(bool_value).getFirst());
    UT_ASSERT(!bool_value);
    UT_ASSERT(stream.read(bool_value).getFirst());
    UT_ASSERT(bool_value);
    UT_ASSERT(!stream.read(bool_value).getFirst());
    UT_ASSERT(!stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    // Read integer numbers from the string stream.
    Tsint int_value;
    UT_ASSERT(stream.set(STR("0 -123 +1234 0b1001 0O1234567 0x123ABC 1,234,567,890")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(int_value).getFirst());
    UT_ASSERT_EQUAL(int_value, 0);
    UT_ASSERT(stream.read(int_value).getFirst());
    UT_ASSERT_EQUAL(int_value, -123);
    UT_ASSERT(stream.read(int_value).getFirst());
    UT_ASSERT_EQUAL(int_value, 1234);
    UT_ASSERT(stream.read(int_value).getFirst());
    UT_ASSERT_EQUAL(int_value, 9);
    UT_ASSERT(stream.read(int_value).getFirst());
    UT_ASSERT_EQUAL(int_value, 342391);
    UT_ASSERT(stream.read(int_value).getFirst());
    UT_ASSERT_EQUAL(int_value, 1194684);
    UT_ASSERT(stream.read(int_value).getFirst());
    UT_ASSERT_EQUAL(int_value, 1234567890);
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    // Read real numbers from the string stream.
    Treal real_value;
    UT_ASSERT(stream.set(STR("0 -123 +1234 1,234,567,890")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, 0.0, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, -123.0, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, 1234.0, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, 1234567890.0, 100.0);
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    UT_ASSERT(stream.set(STR(".123 +.123 -.123 0.123 -123.123 +1234.123 1,234,567,890.123")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, 0.123, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, 0.123, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, -0.123, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, 0.123, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, -123.123, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, 1234.123, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, 1234567890.123, 100.0);
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    UT_ASSERT(stream.set(STR(".123e+0 +.123e-0 -.123e+3 0.123E-3")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, 0.123, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, 0.123, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, -123, 0.0001);
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT_DELTA(real_value, 0.000123, 0.0001);
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    UT_ASSERT(stream.set(STR("-1.#inf 1.#inf 1.#qnan")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT(CMath::isNegInf(real_value));
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT(CMath::isPosInf(real_value));
    UT_ASSERT(stream.read(real_value).getFirst());
    UT_ASSERT(CMath::isQNan(real_value));
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    // Read pointer values from the string stream.
    Tptr pointer_value;
    UT_ASSERT(stream.set(STR("0 0x123ABC 0xFFFFFFFF")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    UT_ASSERT(stream.read(pointer_value).getFirst());
    UT_ASSERT_EQUAL(pointer_value, (Tptr)0x00000000);
    UT_ASSERT(stream.read(pointer_value).getFirst());
    UT_ASSERT_EQUAL(pointer_value, (Tptr)0x00123ABC);
    UT_ASSERT(stream.read(pointer_value).getFirst());
    UT_ASSERT_EQUAL(pointer_value, (Tptr)0xFFFFFFFF);
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    // Read new line symbols from the stream.
    UT_ASSERT(stream.set(STR("asd\nasd\r\nasd\nasd\r\nasd")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    for (Tuint i = 0; i < 3; ++i)
    {
      UT_ASSERT(stream.read(c[0]).getFirst());
      UT_ASSERT(stream.read(c[1]).getFirst());
      UT_ASSERT(stream.read(c[2]).getFirst());
      UT_ASSERT(stream.readLineEnd().getFirst());
    }
    UT_ASSERT(stream.readToLineEnd().getFirst());
    UT_ASSERT(!stream.readToLineEnd().getFirst());
    UT_ASSERT(!stream.read(c[0]).getFirst());
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    // Read format string from the stream.
    Tbool result;
    Tschar s;
    Twchar w;
    Tsint i;
    Tuint u;
    Tfloat f;
    Tdouble d;
    Treal r;
    UT_ASSERT(stream.set(STR("abc % a Z 123 -123 +12345 -123.456 +1.234e+12 -1.2345e-2 abc")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    result = stream.readFormat(STR("abc %% %s %w %-i %i %u %f %d %r abc"), &s, &w, &i, &u, &f, &d, &r).getFirst();
    UT_ASSERT(result);
    UT_ASSERT_EQUAL(s, ASC('a'));
    UT_ASSERT_EQUAL(w, UNC('Z'));
    UT_ASSERT_EQUAL(i, -123);
    UT_ASSERT_EQUAL(u, 12345);
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    Tuint count = 3;
    CStringASCII strASCII;
    CStringUnicode strUnicode;
    UT_ASSERT(stream.set(STR("abc abcd\r\n efgh ijkl abc")));
    UT_ASSERT(stream.open(IStream::e_OPEN_READ));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();
    result = stream.readFormat(STR("abc %-S %3Sh %*Wl abc"), &strASCII, count, &strUnicode).getFirst();
    UT_ASSERT(result);
    UT_ASSERT_EQUAL(strASCII, CStringASCII(ASC("efg")));
    UT_ASSERT_EQUAL(strUnicode, CStringUnicode(UNC("ijk")));
    UT_ASSERT(stream.isEOF());
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
