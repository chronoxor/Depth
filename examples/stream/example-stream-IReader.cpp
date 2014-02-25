/*!
 *  \file    example-stream-IReader.cpp Example of using the IReader 
 *           interface.
 *  \brief   Example of using the IReader interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the IReader interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream examples
    VERSION:   1.0
    CREATED:   12.09.2008 03:19:00

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
#include <Depth/include/stream/text/CStreamString.hpp>
#include <Depth/include/string/CString.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NStream::NText;
using namespace NDepth::NString;
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    CStreamStdOutput streamOut;
    CStreamString streamIn;

    // Open output stream.
    streamOut.open();
    streamOut.setTextMode();

    // Read characters from the string stream.
    Tchar c[3];
    streamIn.set(STR("abc"));
    streamIn.open(IStream::e_OPEN_READ);
    streamIn.setTextMode();
    streamIn.read(c[0]);
    streamIn.read(c[1]);
    streamIn.read(c[2]);
    streamIn.close();
    streamOut.writeBuffer(c, 3);
    streamOut.writeLineEnd();

    // Read strings from the string stream.
    Tstr stringC = NULL;
    Tsstr stringCASCII = NULL;
    Twstr stringCUnicode = NULL;
    streamIn.set(STR("abcd\nabcd\r\nabcd"));
    streamIn.open(IStream::e_OPEN_READ);
    streamIn.setTextMode();
    streamIn.read(stringC);
    streamIn.read(stringCASCII);
    streamIn.read(stringCUnicode);
    streamIn.close();
    streamOut.write(stringC);
    streamOut.writeLineEnd();
    streamOut.write(stringCASCII);
    streamOut.writeLineEnd();
    streamOut.write(stringCUnicode);
    streamOut.writeLineEnd();
    delete [] stringC;
    delete [] stringCASCII;
    delete [] stringCUnicode;

    CStringASCII stringASCII;
    CStringUnicode stringUnicode;
    CSystemString stringSystem;
    streamIn.set(STR("abcde\nabcde\r\nabcde"));
    streamIn.open(IStream::e_OPEN_READ);
    streamIn.setTextMode();
    streamIn.read(stringASCII);
    streamIn.read(stringUnicode);
    streamIn.read(stringSystem);
    streamIn.close();
    streamOut.write(stringASCII);
    streamOut.writeLineEnd();
    streamOut.write(stringUnicode);
    streamOut.writeLineEnd();
    streamOut.write(stringSystem);
    streamOut.writeLineEnd();

    // Read boolean numbers from the string stream.
    Tbool bool_values[6];
    streamIn.set(STR("0 1 false true FaLsE tRuE"));
    streamIn.open(IStream::e_OPEN_READ);
    streamIn.setTextMode();
    streamIn.read(bool_values[0]);
    streamIn.read(bool_values[1]);
    streamIn.read(bool_values[2]);
    streamIn.read(bool_values[3]);
    streamIn.read(bool_values[4]);
    streamIn.read(bool_values[5]);
    streamIn.close();
    streamOut.write(bool_values[0]);
    streamOut.writeLineEnd();
    streamOut.write(bool_values[1]);
    streamOut.writeLineEnd();
    streamOut.write(bool_values[2]);
    streamOut.writeLineEnd();
    streamOut.write(bool_values[3]);
    streamOut.writeLineEnd();
    streamOut.write(bool_values[4]);
    streamOut.writeLineEnd();
    streamOut.write(bool_values[5]);
    streamOut.writeLineEnd();

    // Read integer numbers from the string stream.
    Tsint int_values[7];
    streamIn.set(STR("0 -123 +1234 0b1001 0O1234567 0x123ABC 1,234,567,890"));
    streamIn.open(IStream::e_OPEN_READ);
    streamIn.setTextMode();
    streamIn.read(int_values[0]);
    streamIn.read(int_values[1]);
    streamIn.read(int_values[2]);
    streamIn.read(int_values[3]);
    streamIn.read(int_values[4]);
    streamIn.read(int_values[5]);
    streamIn.read(int_values[6]);
    streamIn.close();
    streamOut.write(int_values[0]);
    streamOut.writeLineEnd();
    streamOut.write(int_values[1]);
    streamOut.writeLineEnd();
    streamOut.write(int_values[2]);
    streamOut.writeLineEnd();
    streamOut.write(int_values[3]);
    streamOut.writeLineEnd();
    streamOut.write(int_values[4]);
    streamOut.writeLineEnd();
    streamOut.write(int_values[5]);
    streamOut.writeLineEnd();
    streamOut.write(int_values[6]);
    streamOut.writeLineEnd();

    // Read real numbers from the string stream.
    Treal real_values[6];
    streamIn.set(STR("0.0 -12.3 +12.34 1.234e+005 1.234E-005 12,345,678.90"));
    streamIn.open(IStream::e_OPEN_READ);
    streamIn.setTextMode();
    streamIn.read(real_values[0]);
    streamIn.read(real_values[1]);
    streamIn.read(real_values[2]);
    streamIn.read(real_values[3]);
    streamIn.read(real_values[4]);
    streamIn.read(real_values[5]);
    streamIn.close();
    streamOut.write(real_values[0]);
    streamOut.writeLineEnd();
    streamOut.write(real_values[1]);
    streamOut.writeLineEnd();
    streamOut.write(real_values[2]);
    streamOut.writeLineEnd();
    streamOut.write(real_values[3]);
    streamOut.writeLineEnd();
    streamOut.write(real_values[4]);
    streamOut.writeLineEnd();
    streamOut.write(real_values[5]);
    streamOut.writeLineEnd();

    // Close output stream.
    streamOut.close();

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
