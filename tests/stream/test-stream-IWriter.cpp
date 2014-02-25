/*!
 *  \file    test-stream-IWriter.cpp Testing of the IWriter interface.
 *  \brief   Testing of the IWriter interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the IWriter interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream tests
    VERSION:   1.0
    CREATED:   08.09.2008 00:09:04

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
    CStreamStringUnicode stream;

    // Open stream.
    UT_ASSERT(stream.open(IStream::e_OPEN_WRITE));
    UT_ASSERT(stream.isOpened());
    stream.setTextMode();

    // Write characters into the stream.
    UT_ASSERT(stream.write(ASC('\x24')).getFirst());
    UT_ASSERT(stream.write(ASC('\x41')).getFirst());
    UT_ASSERT(stream.write(ASC('\x5E')).getFirst());
    UT_ASSERT(stream.write(ASC('\x7F')).getFirst());
    UT_ASSERT(stream.write(UNC('\x0024')).getFirst());
    UT_ASSERT(stream.write(UNC('\x00A2')).getFirst());
    UT_ASSERT(stream.write(UNC('\x05D0')).getFirst());
    UT_ASSERT(stream.write(UNC('\x20AC')).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("\x24\x41\x5E\x7F\x0024\x00A2\x05D0\x20AC")));

    // Reset stream.
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    // Write strings into the stream.
    UT_ASSERT(stream.write(ASC("ASCII C string")).getFirst());
    UT_ASSERT(stream.write(UNC("Unicode C string")).getFirst());
    UT_ASSERT(stream.write(CStringASCII(ASC("ASCII string"))).getFirst());
    UT_ASSERT(stream.write(CStringUnicode(UNC("Unicode string"))).getFirst());

    // Reset stream.
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    // Write boolean numbers into the stream.
    UT_ASSERT(stream.write(true).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("1")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(false, IStream::FORMAT_UPPER, 10).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("     FALSE")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(true, 0, 10).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("      true")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(false, IStream::FORMAT_DECIMAL | IStream::FORMAT_LALIGN, 10).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("0         ")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    // Write integer numbers into the stream.
    UT_ASSERT(stream.write(0).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("0")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(-1).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("-1")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(255, IStream::FORMAT_BINARY).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("0B11111111")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(1234, IStream::FORMAT_OCTAL).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("0O2322")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTU64(1234567890123456789), IStream::FORMAT_DECIMAL).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("1234567890123456789")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTS64(-1234567890123456789), IStream::FORMAT_DECIMAL).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("-1234567890123456789")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(1234, IStream::FORMAT_hex).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("0x4d2")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(1234, IStream::FORMAT_HEX).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("0X4d2")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(1234, IStream::FORMAT_HEX | IStream::FORMAT_UPPER).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("0X4D2")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(1234, IStream::FORMAT_HEX | IStream::FORMAT_UPPER | IStream::FORMAT_FILL_0, 0, 6).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("0X04D2")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(1234, IStream::FORMAT_HEX | IStream::FORMAT_UPPER | IStream::FORMAT_LALIGN, 0, 8).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("0X4D2   ")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(1234, IStream::FORMAT_HEX | IStream::FORMAT_UPPER | IStream::FORMAT_RALIGN, 0, 8).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("   0X4D2")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(123, IStream::FORMAT_DECIMAL | IStream::FORMAT_GROUPS).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("123")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(1234, IStream::FORMAT_DECIMAL | IStream::FORMAT_GROUPS).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("1,234")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(12345, IStream::FORMAT_DECIMAL | IStream::FORMAT_GROUPS).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("12,345")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(123456, IStream::FORMAT_DECIMAL | IStream::FORMAT_GROUPS).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("123,456")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(1234567, IStream::FORMAT_DECIMAL | IStream::FORMAT_GROUPS).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("1,234,567")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(1234567, IStream::FORMAT_PLUS | IStream::FORMAT_DECIMAL | IStream::FORMAT_GROUPS).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("+1,234,567")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(1234567, IStream::FORMAT_PLUS | IStream::FORMAT_DECIMAL | IStream::FORMAT_FILL_0 | IStream::FORMAT_GROUPS, 0, 13).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC(" +001,234,567")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(12345678, IStream::FORMAT_PLUS | IStream::FORMAT_DECIMAL | IStream::FORMAT_FILL_0 | IStream::FORMAT_GROUPS, 0, 14).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("+0,012,345,678")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(123456789, IStream::FORMAT_PLUS | IStream::FORMAT_DECIMAL | IStream::FORMAT_FILL_0 | IStream::FORMAT_GROUPS, 0, 15).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("+00,123,456,789")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(123456789, IStream::FORMAT_PLUS | IStream::FORMAT_DECIMAL | IStream::FORMAT_FILL_0 | IStream::FORMAT_GROUPS, 0, 16).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("+000,123,456,789")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    // Write real numbers into the stream.
    UT_ASSERT(stream.write(CMath::getPosInf()).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("1.#INF")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CMath::getNegInf(), IStream::FORMAT_DOT | IStream::FORMAT_RALIGN, 0, 10).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("   -1.#INF")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CMath::getQNan(), IStream::FORMAT_DOT | IStream::FORMAT_LALIGN, 0, 10).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("1.#QNAN   ")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTR(1234.56789), IStream::FORMAT_DEFAULT, 4).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("1234.5679")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTR(1234.56789), IStream::FORMAT_DEFAULT, 3).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("1234.568")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTR(1234.56789), IStream::FORMAT_exp, 3).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("1.235e+003")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTR(1234.56789), IStream::FORMAT_PLUS | IStream::FORMAT_exp | IStream::FORMAT_RALIGN, 2, 15).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("     +1.23e+003")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTR(1234.56789), IStream::FORMAT_PLUS | IStream::FORMAT_EXP | IStream::FORMAT_LALIGN, 2, 15).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("+1.23E+003     ")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTR(1234.56789), IStream::FORMAT_PLUS | IStream::FORMAT_DOT | IStream::FORMAT_FILL_0 | IStream::FORMAT_GROUPS, 2, 15).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("+000,001,234.57")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTR(1234.56789), IStream::FORMAT_PLUS | IStream::FORMAT_DOT | IStream::FORMAT_FILL_0 | IStream::FORMAT_GROUPS, 2, 16).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC(" +000,001,234.57")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTR(1234.56789), IStream::FORMAT_PLUS | IStream::FORMAT_DOT | IStream::FORMAT_FILL_0 | IStream::FORMAT_GROUPS, 2, 17).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("+0,000,001,234.57")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTR(1234.56789), IStream::FORMAT_PLUS | IStream::FORMAT_DOT | IStream::FORMAT_FILL_0 | IStream::FORMAT_GROUPS, 2, 18).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("+00,000,001,234.57")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    UT_ASSERT(stream.write(CONSTR(1234.56789), IStream::FORMAT_PLUS | IStream::FORMAT_DOT | IStream::FORMAT_FILL_0 | IStream::FORMAT_GROUPS, 2, 19).getFirst());
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("+000,000,001,234.57")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    // Write pointer into the stream.
    UT_ASSERT(stream.write(&stream).getFirst());
    UT_ASSERT_EQUAL(stream.getSize(), ((sizeof(Tcptr) << 1) + 2));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    // Write format string into the stream.
    Tbool result;
    Tuint count = 0;
    CStringUnicode strFormat;
    UT_ASSERT(strFormat.set(UNC("abcd %n %s %w abcd")));
    result = stream.writeFormat(&strFormat, &count, ASC('a'), UNC('Z')).getFirst();
    UT_ASSERT(result);
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("abcd  a Z abcd")));
    UT_ASSERT_EQUAL(count, 5);
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    Tchar cstr[] = STR("ABCDEFG");
    Tschar cstrASCII[] = ASC("ABCDEFG");
    Twchar cstrUnicode[] = UNC("ABCDEFG");
    UT_ASSERT(strFormat.set(UNC("abcd %ZS %4ZW %ZX abcd")));
    result = stream.writeFormat(&strFormat, cstrASCII, cstrUnicode, cstr).getFirst();
    UT_ASSERT(result);
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("abcd ABCDEFG ABCD ABCDEFG abcd")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    CString str(UNC("ABCDEFG"));
    CStringASCII strASCII(ASC("ABCDEFG"));
    CStringUnicode strUnicode(UNC("ABCDEFG"));
    UT_ASSERT(strFormat.set(UNC("abcd %S %4W %X abcd")));
    result = stream.writeFormat(&strFormat, &strASCII, &strUnicode, &str).getFirst();
    UT_ASSERT(result);
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("abcd ABCDEFG ABCD ABCDEFG abcd")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    Tsint s = 100;
    Tuint u = 123456;
    Treal r = CONSTR(123.456);
    UT_ASSERT(strFormat.set(UNC("abcd %oi %010,u %+.*r abcd")));
    result = stream.writeFormat(&strFormat, s, u, 3, r).getFirst();
    UT_ASSERT(result);
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("abcd 0o144 00,123,456 +123.456 abcd")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    // Write stream with manipulators.
    stream << UNC("abc") << UNC(' ') << s << UNC(' ') << u << UNC(' ') << prec(3) << r;
    UT_ASSERT_EQUAL(stream, CStringUnicode(UNC("abc 100 123456 123.456")));
    UT_ASSERT(stream.clear());
    UT_ASSERT(stream.setPosition(0));

    // Close stream.
    UT_ASSERT(stream.close());
    UT_ASSERT(!stream.isOpened());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
