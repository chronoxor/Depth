/*!
 *  \file    example-stream-CStreamDebugger.cpp Example of using the
 *           CStreamDebugger class.
 *  \brief   Example of using the CStreamDebugger class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CStreamDebugger class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream examples
    VERSION:   1.0
    CREATED:   01.09.2008 01:57:50

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
#include <Depth/include/stream/CStreamDebugger.hpp>
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

    CStreamDebugger stream;

    // Text write into the debugger stream.
    stream.open();
    stream.setTextMode();
    stream.writeBuffer("ASCII string", 12);
    stream.writeLineEnd(true);
    stream.writeBuffer(L"Unicode string", 14);
    stream.writeLineEnd(false);
    stream.writeBuffer(L"\x0024", 1);
    stream.writeBuffer(L"\x00A2", 1);
    stream.writeBuffer(L"\x05D0", 1);
    stream.writeBuffer(L"\x20AC", 1);
    stream.writeLineEnd();
    stream.close();

    // Binary write into the debugger stream.
    stream.open();
    stream.setBinaryMode();
    stream.writeBuffer((Tptr)("Binary ASCII string"), 19 * sizeof(Tschar));
    stream.writeLineEnd(true);
    stream.writeBuffer((Tptr)(L"Binary Unicode string"), 21 * sizeof(Twchar));
    stream.writeLineEnd(false);
    stream.close();

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
