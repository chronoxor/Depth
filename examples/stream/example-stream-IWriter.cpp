/*!
 *  \file    example-stream-IWriter.cpp Example of using the IWriter 
 *           interface.
 *  \brief   Example of using the IWriter interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the IWriter interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream examples
    VERSION:   1.0
    CREATED:   08.09.2008 22:20:54

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
#include <Depth/include/application/IApplication.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/stream/CStreamStdOutput.hpp>
#include <Depth/include/string/CString.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    CStreamStdOutput stream;

    // Open stream.
    stream.open();
    stream.setTextMode();

    // Write characters into the standard output stream.
    stream.write(ASC('\x24'));
    stream.write(ASC('\x41'));
    stream.write(ASC('\x5E'));
    stream.write(ASC('\x7F'));
    stream.write(UNC('\x0024'));
    stream.write(UNC('\x00A2'));
    stream.write(UNC('\x05D0'));
    stream.write(UNC('\x20AC'));
    stream.writeLineEnd();

    // Write strings into the standard output stream.
    stream.write(ASC("ASCII C string"));
    stream.writeLineEnd();
    stream.write(UNC("Unicode C string"));
    stream.writeLineEnd();
    stream.write(CStringASCII(ASC("ASCII string")));
    stream.writeLineEnd();
    stream.write(CStringUnicode(UNC("Unicode string")));
    stream.writeLineEnd();

    // Write boolean numbers into the standard output stream.
    stream.write(true);
    stream.writeLineEnd();
    stream.write(false, IStream::FORMAT_UPPER, 10);
    stream.writeLineEnd();
    stream.write(true, IStream::FORMAT_DECIMAL, 10);
    stream.writeLineEnd();
    stream.write(false, IStream::FORMAT_DECIMAL | IStream::FORMAT_LALIGN, 10);
    stream.writeLineEnd();

    // Write integer numbers into the standard output stream.
    stream.write(0);
    stream.writeLineEnd();
    stream.write(-1);
    stream.writeLineEnd();
    stream.write(255, 0, 2);
    stream.writeLineEnd();
    stream.write(1234567, IStream::FORMAT_SPACE | IStream::FORMAT_DECIMAL | IStream::FORMAT_GROUPS);
    stream.writeLineEnd();
    stream.write(123456789, IStream::FORMAT_PLUS | IStream::FORMAT_DECIMAL | IStream::FORMAT_FILL_0 | IStream::FORMAT_GROUPS, 0, 15);
    stream.writeLineEnd();

    // Write real numbers into the standard output stream.
    stream.write(CONSTR(0));
    stream.writeLineEnd();
    stream.write(CONSTR(1234.5678));
    stream.writeLineEnd();
    stream.write(CONSTR(1234.5678), IStream::FORMAT_SPACE | IStream::FORMAT_exp);
    stream.writeLineEnd();
    stream.write(CONSTR(1234.5678), IStream::FORMAT_PLUS | IStream::FORMAT_EXP | IStream::FORMAT_RALIGN, 2, 15);
    stream.writeLineEnd();
    stream.write(CONSTR(1234.5678), IStream::FORMAT_PLUS | IStream::FORMAT_DOT | IStream::FORMAT_FILL_0 | IStream::FORMAT_GROUPS, 2, 15);
    stream.writeLineEnd();

    // Write pointers into the standard output stream.
    stream.write(&stream);
    stream.writeLineEnd();
    stream.write(&stream, IStream::FORMAT_HEX | IStream::FORMAT_LOWER, 20);
    stream.writeLineEnd();

    // Write format string into the stream.
    Tuint count = 0;
    CString strFormat;
    CStringASCII strASCII(ASC("ABCDEFG"));
    CStringUnicode strUnicode(UNC("ABCDEFG"));
    strFormat.set(STR("abcd %n %s %w abcd"));
    stream.writeFormat(&strFormat, &count, ASC('a'), UNC('Z'));
    stream.writeLineEnd();
    strFormat.set(STR("abcd %S %4W abcd"));
    stream.writeFormat(&strFormat, &strASCII, &strUnicode);
    stream.writeLineEnd();

    Tsint s = 100;
    Tuint u = 123456;
    Treal r = CONSTR(123.456);
    strFormat.set(STR("abcd %oi %010,u %+.*r abcd"));
    stream.writeFormat(&strFormat, s, u, 3, r);
    stream.writeLineEnd();

    // Write stream with manipulators.
    stream << STR("abc") << STR(' ') << s << STR(' ') << u << STR(' ') << prec(3) << r << ln;

    // Close stream.
    stream.close();

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
