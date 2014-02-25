/*!
 *  \file    example-utility-CBuffer.cpp Example of using the CBuffer class.
 *  \brief   Example of using the CBuffer class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CBuffer class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth utility examples
    VERSION:   1.0
    CREATED:   20.08.2008 20:12:28

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
#include <Depth/include/utility/CBuffer.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NUtility;
/*==========================================================================*/
// Write instance of the CBuffer class into the given writer.
IWriter& operator << (IWriter& writer, const CBuffer& a_crBuffer)
{ CALL
  writer << STR("CBuffer(") << STR("size = ") << a_crBuffer.getSize() << STR(")") << ln;
  CBuffer::TIteratorConst it = a_crBuffer.getItFirst();
  if (it.isValid())
  {
    writer << STR("{") << ln;
    do
    {
      writer << STR(" item = ") << *it << ln;
    } while (it.stepForward() == 1);
    writer << STR("}") << ln;
  }
  return writer;
}
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

    Tbyte values[] = { 3, 4, 5 };

    // Create static buffer.
    CBuffer static_buffer(values, sizeof(values));

    // Change fixed values.
    static_buffer[CONSTU(0)] = 30;
    static_buffer[CONSTU(1)] = 40;
    static_buffer[CONSTU(2)] = 50;

    // Show the static buffer.
    stdoutput << static_buffer << ln;

    // Create dynamic buffer.
    CBuffer dynamic_buffer(values, sizeof(values), false);

    // Fill the dynamic buffer.
    dynamic_buffer.insertFirst(20);
    dynamic_buffer.insertFirst(10);
    dynamic_buffer.insertLast(60);
    dynamic_buffer.insertLast(70);

    // Show the dynamic buffer.
    stdoutput << static_buffer << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
