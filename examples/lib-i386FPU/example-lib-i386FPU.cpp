/*!
 *  \file    example-lib-i386FPU.cpp Example of using the i386FPU static
 *           library.
 *  \brief   Example of using the i386FPU static library functionality.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the i386FPU static library.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      i386FPU static library examples
    VERSION:   1.0
    CREATED:   31.12.2006 03:06:45

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
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*==========================================================================*/
extern "C" double CPREFIX(i386FPU_cos)(double);
extern "C" double CPREFIX(i386FPU_sin)(double);
extern "C" double CPREFIX(i386FPU_tan)(double);
extern "C" double CPREFIX(i386FPU_sqrt)(double);
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

    Tdouble x = 34.256;

    // Invoke i386 FPU functions from the i386FPU static library.
    stdoutput << STR("i386FPU_cos(") << x << STR(") = ") << CPREFIX(i386FPU_cos)(x) << ln;
    stdoutput << STR("i386FPU_sin(") << x << STR(") = ") << CPREFIX(i386FPU_sin)(x) << ln;
    stdoutput << STR("i386FPU_tan(") << x << STR(") = ") << CPREFIX(i386FPU_tan)(x) << ln;
    stdoutput << STR("i386FPU_sqrt(") << x << STR(") = ") << CPREFIX(i386FPU_sqrt)(x) << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
