/*!
 *  \file    example-stream-CStreamStringASCII.cpp Example of using the
 *           CStreamStringASCII class.
 *  \brief   Example of using the CStreamStringASCII class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CStreamStringASCII class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream examples
    VERSION:   1.0
    CREATED:   02.09.2008 20:31:59

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
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/stream/text/CStreamStringASCII.hpp>
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

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    CStringASCII buffer(ASC("abcdefghij"));
    CStreamStringASCII stream(buffer);

    // Show ASCII string buffer.
    show(stdoutput, stream.getBuffer(), 10);

    // Open stream.
    stream.open(IStream::e_OPEN_READWRITE);

    // Read from the ASCII string.
    Tschar read_buffer[5];
    stream.readBuffer(read_buffer, 5);

    // Show read buffer.
    show(stdoutput, read_buffer, 5);

    // Write into the ASCII string.
    stream.writeBuffer(read_buffer, 5);

    // Close stream.
    stream.close();

    // Show ASCII string buffer.
    show(stdoutput, stream.getBuffer(), 10);

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write content of the fixed size ASCII string buffer into the given writer.
  static void show(IWriter& writer, Tcsstr a_cpBuffer, const Tuint a_cSize)
  { CALL
    writer << STR("Buffer(") << STR("size = ") << a_cSize << STR(") = { ");
    for (Tuint i = 0; i < a_cSize; ++i)
      writer << a_cpBuffer[i] << ((i == (a_cSize - 1)) ? STR(" }") : STR(", "));
    writer << ln;
  }
} the_Application;
/*==========================================================================*/
