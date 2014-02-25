/*!
 *  \file    example-time-CDateTime.cpp Example of using the CDateTime class.
 *  \brief   Example of using the CDateTime class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.03.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CDate class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth time examples
    VERSION:   1.0
    CREATED:   04.03.2010 20:18:35

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
#include <Depth/include/time/CDateTime.hpp>
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

    stdoutput << STR("Process date & time is: "); show(stdoutput, CDateTime::getProcessDateTime());
    stdoutput << STR("System date & time in UTC time is: "); show(stdoutput, CDateTime::getSystemDateTime(true));
    stdoutput << STR("System date & time in local time is: "); show(stdoutput, CDateTime::getSystemDateTime(false));

    // Set new system local date & time.
    Tbool restore;
    CDateTime systemNew(2000, 10, 5, 23, 0, 0, 0);
    CDateTime systemOld = CDateTime::getSystemDateTime(false);
    if (CDateTime::setSystemDateTimeLocal(systemNew))
    {
      stdoutput << STR("New system local date & time was successfully set to "); show(stdoutput, CDateTime::getSystemDateTime(false));
      restore = true;
    }
    else
    {
      stdoutput << STR("New system local date & time was not successfully set to "); show(stdoutput, systemNew);
      restore = false;
    }

    CDateTime processStart = CDateTime::getProcessDateTime();

    // Perform some job...
    for (Tuint i = 0; i < 10000000; ++i)
    {
      Treal job = CMath::sin(CONSTR(0.65)) * CMath::cos(CONSTR(0.65));

      IGNORE_UNUSED(job);
    }

    CDateTime processEnd = CDateTime::getProcessDateTime();

    stdoutput << STR("Job date & time is: "); show(stdoutput, processEnd - processStart);

    // Restore system local date & time.
    if (restore)
    {
      if (CDateTime::setSystemDateTimeLocal(systemOld + (processEnd - processStart)))
      {
        stdoutput << STR("Old system local date & time was successfully restored to "); show(stdoutput, CDateTime::getSystemDateTime(false));
      }
      else
      {
        stdoutput << STR("Old system local date & time was not successfully restored to "); show(stdoutput, systemOld);
      }
    }

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CDateTime class into the given writer.
  static void show(IWriter& writer, const CDateTime& a_crDateTime)
  { CALL
    writer << fill_0 << width(2) << a_crDateTime.getDate().getDay() << STR('.');
    writer << fill_0 << width(2) << a_crDateTime.getDate().getMonth() << STR('.');
    writer << fill_0 << width(4) << a_crDateTime.getDate().getYear() << STR(' ');
    writer << fill_0 << width(2) << a_crDateTime.getTime().getHour() << STR(':');
    writer << fill_0 << width(2) << a_crDateTime.getTime().getMinute() << STR(':');
    writer << fill_0 << width(2) << a_crDateTime.getTime().getSecond() << STR('-');
    writer << fill_0 << width(4) << a_crDateTime.getTime().getMillisecond() << ln;
  }
} the_Application;
/*==========================================================================*/
