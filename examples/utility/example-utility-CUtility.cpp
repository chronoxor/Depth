/*!
 *  \file    example-utility-CUtility.cpp Example of using the CUtility class.
 *  \brief   Example of using the CUtility class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CUtility class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth utility examples
    VERSION:   1.0
    CREATED:   11.07.2007 20:46:17

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
#include <Depth/include/algorithms/numeric/ADiv.hpp>
#include <Depth/include/algorithms/numeric/ARotate.hpp>
#include <Depth/include/utility/CUtility.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NNumeric;
using namespace NDepth::NUtility;
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

    stdoutput << STR("BIN8(00001010) = ") << hex << upper << BIN8(00001010) << ln;
    stdoutput << STR("BIN16(00001010, 00001010) = ") << hex << upper << BIN16(00001010, 00001010) << ln;
    stdoutput << STR("BIN24(00001010, 00001010, 00001010) = ") << hex << upper << BIN24(00001010, 00001010, 00001010) << ln;
    stdoutput << STR("BIN32(00001010, 00001010, 00001010, 00001010) = ") << hex << upper << BIN32(00001010, 00001010, 00001010, 00001010) << ln;

    stdoutput << STR("NAlgorithms::NNumeric::div(5, 3) = ") << STR("(") << NDepth::NAlgorithms::NNumeric::div(5, 3).getFirst() << STR(", ") << NDepth::NAlgorithms::NNumeric::div(5, 3).getSecond() << STR(")") << ln;
    stdoutput << STR("NAlgorithms::NNumeric::cyclicRotateLeft(12, 3) = ") << hex << upper << NAlgorithms::NNumeric::cyclicRotateLeft(12, 3) << ln;
    stdoutput << STR("NAlgorithms::NNumeric::cyclicRotateRight(12, 3) = ") << hex << upper << NAlgorithms::NNumeric::cyclicRotateRight(12, 3) << ln;
    stdoutput << STR("NAlgorithms::NNumeric::rotateLeft(12, 3) = ") << hex << upper << NAlgorithms::NNumeric::rotateLeft(12, 3) << ln;
    stdoutput << STR("NAlgorithms::NNumeric::rotateRight(12, 3) = ") << hex << upper << NAlgorithms::NNumeric::rotateRight(12, 3) << ln;

    stdoutput << STR("CUtility::reverseBytes(1024) = ") << hex << upper << CUtility::reverseBytes(CONSTU(1024)) << ln;
    stdoutput << STR("CUtility::reverseBits(1024) = ") << hex << upper << CUtility::reverseBits(CONSTU(1024)) << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
