/*!
 *  \file    example-stream-CStreamStdError.cpp Example of using the
 *           CStreamStdError class.
 *  \brief   Example of using the CStreamStdError class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CStreamStdError class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream examples
    VERSION:   1.0
    CREATED:   25.08.2008 20:15:24

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
#include <Depth/include/stream/CStreamStdError.hpp>
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

    // Use standard error stream of the current process.
    CStreamStdError stderror(true);

    // Text write into the standard error stream.
    stderror.setTextMode();
    stderror.writeBuffer("ASCII string", 12);
    stderror.writeLineEnd(true);
    stderror.writeBuffer(L"Unicode string", 14);
    stderror.writeLineEnd(false);
    stderror.writeBuffer(L"\x0024", 1);
    stderror.writeBuffer(L"\x00A2", 1);
    stderror.writeBuffer(L"\x05D0", 1);
    stderror.writeBuffer(L"\x20AC", 1);
    stderror.writeLineEnd();

    // Binary write into the standard output stream.
    stderror.setBinaryMode();
    stderror.writeBuffer((Tptr)("Binary ASCII string"), 19 * sizeof(Tschar));
    stderror.writeLineEnd(true);
    stderror.writeBuffer((Tptr)(L"Binary Unicode string"), 21 * sizeof(Twchar));
    stderror.writeLineEnd(false);

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
