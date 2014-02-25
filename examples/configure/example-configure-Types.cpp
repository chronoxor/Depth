/*!
 *  \file    example-configure-Types.cpp Example of using Depth types.
 *  \brief   Example of using Depth types.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using Depth types.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth configure examples
    VERSION:   1.0
    CREATED:   04.06.2008 21:16:47

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
#include <Depth/include/types.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NTypes;
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

    stdoutput << STR("sizeof(Tbool) = ") << sizeof(Tbool) << ln;

    stdoutput << STR("sizeof(Tchar) = ") << sizeof(Tchar) << ln;
    stdoutput << STR("sizeof(Tschar) = ") << sizeof(Tschar) << ln;
    stdoutput << STR("sizeof(Twchar) = ") << sizeof(Twchar) << ln;

    stdoutput << STR("sizeof(Tsint) = ") << sizeof(Tsint) << ln;
    stdoutput << STR("sizeof(Tuint) = ") << sizeof(Tuint) << ln;
    stdoutput << STR("sizeof(Tsint08) = ") << sizeof(Tsint08) << ln;
    stdoutput << STR("sizeof(Tsint16) = ") << sizeof(Tsint16) << ln;
    stdoutput << STR("sizeof(Tsint32) = ") << sizeof(Tsint32) << ln;
    stdoutput << STR("sizeof(Tsint64) = ") << sizeof(Tsint64) << ln;
    stdoutput << STR("sizeof(Tuint08) = ") << sizeof(Tuint08) << ln;
    stdoutput << STR("sizeof(Tuint16) = ") << sizeof(Tuint16) << ln;
    stdoutput << STR("sizeof(Tuint32) = ") << sizeof(Tuint32) << ln;
    stdoutput << STR("sizeof(Tuint64) = ") << sizeof(Tuint64) << ln;

    stdoutput << STR("sizeof(Tfloat) = ") << sizeof(Tfloat) << ln;
    stdoutput << STR("sizeof(Tdouble) = ") << sizeof(Tdouble) << ln;
    stdoutput << STR("sizeof(Treal) = ") << sizeof(Treal) << ln;

    stdoutput << STR("sizeof(Tbyte) = ") << sizeof(Tbyte) << ln;
    stdoutput << STR("sizeof(Tptr) = ") << sizeof(Tptr) << ln;
    stdoutput << STR("sizeof(Tcptr) = ") << sizeof(Tcptr) << ln;

    stdoutput << STR("sizeof(Tbuffer) = ") << sizeof(Tbuffer) << ln;
    stdoutput << STR("sizeof(Tcbuffer) = ") << sizeof(Tcbuffer) << ln;

    stdoutput << STR("sizeof(Tstr) = ") << sizeof(Tstr) << ln;
    stdoutput << STR("sizeof(Tsstr) = ") << sizeof(Tsstr) << ln;
    stdoutput << STR("sizeof(Twstr) = ") << sizeof(Twstr) << ln;
    stdoutput << STR("sizeof(Tcstr) = ") << sizeof(Tcstr) << ln;
    stdoutput << STR("sizeof(Tcsstr) = ") << sizeof(Tcsstr) << ln;
    stdoutput << STR("sizeof(Tcwstr) = ") << sizeof(Tcwstr) << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
