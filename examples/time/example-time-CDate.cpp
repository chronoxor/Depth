/*!
 *  \file    example-time-CDate.cpp Example of using the CDate class.
 *  \brief   Example of using the CDate class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CDate class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth time examples
    VERSION:   1.0
    CREATED:   26.02.2010 23:10:04

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
#include <Depth/include/time/CDate.hpp>
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

    stdoutput << STR("Process date is: "); show(stdoutput, CDate::getProcessDate());
    stdoutput << STR("System date in UTC time is: "); show(stdoutput, CDate::getSystemDate(true));
    stdoutput << STR("System date in local time is: "); show(stdoutput, CDate::getSystemDate(false));

    // Set new system local date.
    Tbool restore;
    CDate systemNew(2000, 10, 5);
    CDate systemOld = CDate::getSystemDate(false);
    if (CDate::setSystemDateLocal(systemNew))
    {
      stdoutput << STR("New system local date was successfully set to "); show(stdoutput, CDate::getSystemDate(false));
      restore = true;
    }
    else
    {
      stdoutput << STR("New system local date was not successfully set to "); show(stdoutput, systemNew);
      restore = false;
    }

    CDate processStart = CDate::getProcessDate();

    // Perform some job...
    for (Tuint i = 0; i < 10000000; ++i)
    {
      Treal job = CMath::sin(CONSTR(0.65)) * CMath::cos(CONSTR(0.65));

      IGNORE_UNUSED(job);
    }

    CDate processEnd = CDate::getProcessDate();

    stdoutput << STR("Job date is: "); show(stdoutput, processEnd - processStart);

    // Restore system local date.
    if (restore)
    {
      if (CDate::setSystemDateLocal(systemOld + (processEnd - processStart)))
      {
        stdoutput << STR("Old system local date was successfully restored to "); show(stdoutput, CDate::getSystemDate(false));
      }
      else
      {
        stdoutput << STR("Old system local date was not successfully restored to "); show(stdoutput, systemOld);
      }
    }

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CDate class into the given writer.
  static void show(IWriter& writer, const CDate& a_crDate)
  { CALL
    writer << fill_0 << width(2) << a_crDate.getDay() << STR('.');
    writer << fill_0 << width(2) << a_crDate.getMonth() << STR('.');
    writer << fill_0 << width(4) << a_crDate.getYear() << ln;
  }
} the_Application;
/*==========================================================================*/
