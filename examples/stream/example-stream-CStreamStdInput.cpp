/*!
 *  \file    example-stream-CStreamStdInput.cpp Example of using the
 *           CStreamStdInput class.
 *  \brief   Example of using the CStreamStdInput class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CStreamStdInput class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream examples
    VERSION:   1.0
    CREATED:   25.08.2008 20:18:45

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
#include <Depth/include/stream/CStreamStdInput.hpp>
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

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    // Show usage information.
    stdoutput << STR("Please input some text: ");

    // Use standard input stream of the current process.
    CStreamStdInput stdinput(true);

    // Text read from the standard input stream.
    Tschar schar_buffer[5];
    Tschar wchar_buffer[5];
    stdinput.setTextMode();
    stdinput.readBuffer(schar_buffer, 5);
    stdinput.readBuffer(wchar_buffer, 5);

    stdoutput << STR("Buffer (schar) = { ") << schar_buffer[0] << STR(", ") << schar_buffer[1] << STR(", ") << schar_buffer[2] << STR(", ") << schar_buffer[3] << STR(", ") << schar_buffer[4] << STR(" }") << ln;
    stdoutput << STR("Buffer (wchar) = { ") << wchar_buffer[0] << STR(", ") << wchar_buffer[1] << STR(", ") << wchar_buffer[2] << STR(", ") << wchar_buffer[3] << STR(", ") << wchar_buffer[4] << STR(" }") << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
