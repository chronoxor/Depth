/*!
 *  \file    example-stream-CFilterUUE.cpp Example of using the CFilterUUE
 *           class.
 *  \brief   Example of using the CFilterUUE class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CFilterUUE class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth stream examples
    VERSION:   1.0
    CREATED:   11.11.2009 02:51:37

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
#include <Depth/include/stream/text/CFilterUUE.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NStream::NText;
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
    CStreamStdOutput stdoutput;

    // Link standard output stream with UUE filter.
    CFilterUUE filter(&stdoutput, true, stdoutput.isTextMode(), stdoutput.getByteOrder(), stdoutput.getLineEnding());

    // Write a string into the last filter.
    filter.open(IStream::e_OPEN_WRITE);
    filter << ASC("Take this kiss upon the brow!") << ln(true);
    filter << ASC("And, in parting from you now,") << ln(true);
    filter << ASC("Thus much let me avow-") << ln(true);
    filter << ASC("You are not wrong, who deem") << ln(true);
    filter << ASC("That my days have been a dream;") << ln(true);
    filter << ASC("Yet if hope has flown away") << ln(true);
    filter << ASC("In a night, or in a day,") << ln(true);
    filter << ASC("In a vision, or in none,") << ln(true);
    filter << ASC("Is it therefore the less gone?") << ln(true);
    filter << ASC("All that we see or seem") << ln(true);
    filter << ASC("Is but a dream within a dream.") << ln(true);
    filter << ln(true);
    filter << ASC("I stand amid the roar") << ln(true);
    filter << ASC("Of a surf-tormented shore,") << ln(true);
    filter << ASC("And I hold within my hand") << ln(true);
    filter << ASC("Grains of the golden sand-") << ln(true);
    filter << ASC("How few! yet how they creep") << ln(true);
    filter << ASC("Through my fingers to the deep,") << ln(true);
    filter << ASC("While I weep-while I weep!") << ln(true);
    filter << ASC("O God! can I not grasp") << ln(true);
    filter << ASC("Them with a tighter clasp?") << ln(true);
    filter << ASC("O God! can I not save") << ln(true);
    filter << ASC("One from the pitiless wave?") << ln(true);
    filter << ASC("Is all that we see or seem") << ln(true);
    filter << ASC("But a dream within a dream?") << ln(true);
    filter.close();

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
