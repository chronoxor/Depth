/*!
 *  \file    example-containers-CSpan.cpp Example of using the CSpan class.
 *  \brief   Example of using the CSpan class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.09.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CSpan class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   14.09.2007 03:25:24

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
#include <Depth/include/containers/CSpan.hpp>
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

    CSpan<Tsint> a;

    // Fill the span.
    a.insert(0);
    a.insert(1, 20, true, true);
    a.insert(25);
    a.insert(30, 40, false, true);
    a.insert(45);
    a.insert(50, 60, false, false);
    a.insert(65);
    a.insert(70, 80, false, false);
    a.insert(85);
    a.insert(90, 100, true, true);
    a.insert(101);

    // Show the span.
    show(stdoutput, a);

    // Join intervals.
    a.insert(30, 80, true, true);

    // Show the span.
    show(stdoutput, a);

    // Copy the span.
    CSpan<Tsint> b(a);

    // Show the copied span.
    show(stdoutput, b);

    // Remove items from the span.
    a.remove(0);
    a.remove(10, 35, true, false);
    a.remove(55);
    a.remove(70, 85, true, true);
    a.remove(90);
    a.remove(95, 97, false, true);
    a.remove(101);

    // Show the span.
    show(stdoutput, a);

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Write instance of the CSpan<Tsint> class into the given writer.
  static void show(IWriter& writer, const CSpan<Tsint>& a_crSpan)
  { CALL
    writer << STR("CSpan<Tsint>(") << STR("size = ") << a_crSpan.getSize() << STR(")") << ln;
    CSpan<Tsint>::TIteratorConst it = a_crSpan.getItFirst();
    if (it.isValid())
    {
      writer << STR("{") << ln;
      do
      {
        writer << STR(" item = ") << (it.getValueRef().isIncludeFirst() ? STR('[') : STR('(')) << it.getValueRef().getFirst() << STR(", ") << it.getValueRef().getSecond() << (it.getValueRef().isIncludeSecond() ? STR(']') : STR(')')) << ln;
      } while (it.stepForward() == 1);
      writer << STR("}") << ln;
    }
  }
} the_Application;
/*==========================================================================*/
