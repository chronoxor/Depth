/*!
 *  \file    example-algorithms-AMath.cpp Example of using the math 
 *           algorithms.
 *  \brief   Example of using the math algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the math algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   17.01.2007 23:52:26

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
#include <Depth/include/algorithms/math/ASqrt.hpp>
#include <Depth/include/algorithms/math/ALn.hpp>
#include <Depth/include/algorithms/math/ALog.hpp>
#include <Depth/include/algorithms/math/ASin.hpp>
#include <Depth/include/algorithms/math/ACos.hpp>
#include <Depth/include/algorithms/math/ATan.hpp>
#include <Depth/include/algorithms/math/AASin.hpp>
#include <Depth/include/algorithms/math/AACos.hpp>
#include <Depth/include/algorithms/math/AATan.hpp>
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

    stdoutput << STR("NAlgorithms::NMath::sqrt(20.0) = ") << NAlgorithms::NMath::sqrt(20.0) << ln;
    stdoutput << STR("NAlgorithms::NMath::ln(20.0) = ") << NAlgorithms::NMath::ln(20.0) << ln;
    stdoutput << STR("NAlgorithms::NMath::log(20.0, 30.0) = ") << NAlgorithms::NMath::log(20.0, 30.0) << ln;
    stdoutput << STR("NAlgorithms::NMath::sin(20.0) = ") << NAlgorithms::NMath::sin(20.0) << ln;
    stdoutput << STR("NAlgorithms::NMath::cos(20.0) = ") << NAlgorithms::NMath::cos(20.0) << ln;
    stdoutput << STR("NAlgorithms::NMath::tan(20.0) = ") << NAlgorithms::NMath::tan(20.0) << ln;
    stdoutput << STR("NAlgorithms::NMath::asin(0.5) = ") << NAlgorithms::NMath::asin(0.5) << ln;
    stdoutput << STR("NAlgorithms::NMath::acos(0.5) = ") << NAlgorithms::NMath::acos(0.5) << ln;
    stdoutput << STR("NAlgorithms::NMath::atan(0.5) = ") << NAlgorithms::NMath::atan(0.5) << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
