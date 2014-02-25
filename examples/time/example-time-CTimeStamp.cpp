/*!
 *  \file    example-time-CTimeStamp.cpp Example of using the CTimeStamp
 *           class.
 *  \brief   Example of using the CTimeStamp class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CTimeStamp class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth time examples
    VERSION:   1.0
    CREATED:   22.02.2010 03:44:09

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
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/time/CTimeStamp.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NMath;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NTime;
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

    stdoutput << STR("Process time stamp is: "); show(stdoutput, CTimeStamp::getProcessTimeStamp());
    stdoutput << STR("System time stamp in UTC time is: "); show(stdoutput, CTimeStamp::getSystemTimeStamp(true));
    stdoutput << STR("System time stamp in local time is: "); show(stdoutput, CTimeStamp::getSystemTimeStamp(false));

    CTimeStamp processStart = CTimeStamp::getProcessTimeStamp();

    // Perform some job...
    for (Tuint i = 0; i < 10000000; ++i)
    {
      Treal job = CMath::sin(CONSTR(0.65)) * CMath::cos(CONSTR(0.65));

      IGNORE_UNUSED(job);
    }

    CTimeStamp processEnd = CTimeStamp::getProcessTimeStamp();

    stdoutput << STR("Job time is: "); show(stdoutput, processEnd - processStart);

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CTimeStamp class into the given writer.
  static void show(IWriter& writer, const CTimeStamp& a_crTimeStamp)
  { CALL
    writer << a_crTimeStamp.getClearDays() << STR(" days, ");
    writer << a_crTimeStamp.getClearHours() << STR(" hours, ");
    writer << a_crTimeStamp.getClearMinutes() << STR(" minutes, ");
    writer << a_crTimeStamp.getClearSeconds() << STR(" seconds, ");
    writer << a_crTimeStamp.getClearMilliseconds() << STR(" milliseconds");
    writer << ln;
  }
} the_Application;
/*==========================================================================*/
