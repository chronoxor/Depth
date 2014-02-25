/*!
 *  \file    example-random-IRandomGenerator.cpp Example of using the
 *           IRandomGenerator interface and different random number
 *           generators.
 *  \brief   Example of using the IRandomGenerator interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the IRandomGenerator interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth random examples
    VERSION:   1.0
    CREATED:   24.02.2009 22:48:32

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
#include <Depth/include/random/CRandomGeneratorDESran4.hpp>
#include <Depth/include/random/CRandomGeneratorFibonacci.hpp>
#include <Depth/include/random/CRandomGeneratorFibonacciEx.hpp>
#include <Depth/include/random/CRandomGeneratorGGL.hpp>
#include <Depth/include/random/CRandomGeneratorMLCGran1.hpp>
#include <Depth/include/random/CRandomGeneratorMLCGran2.hpp>
#include <Depth/include/random/CRandomGeneratorMRG.hpp>
#include <Depth/include/random/CRandomGeneratorMRG32k3a.hpp>
#include <Depth/include/random/CRandomGeneratorMT19937B.hpp>
#include <Depth/include/random/CRandomGeneratorMZran13.hpp>
#include <Depth/include/random/CRandomGeneratorOldCongr.hpp>
#include <Depth/include/random/CRandomGeneratorR250.hpp>
#include <Depth/include/random/CRandomGeneratorRANLUX.hpp>
#include <Depth/include/random/CRandomGeneratorRANMAR.hpp>
#include <Depth/include/random/CRandomGeneratorTaus88.hpp>
#include <Depth/include/random/CRandomGeneratorTT800.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NRandom;
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

    stdoutput << STR("CRandomGeneratorDESran4().randomInteger() = ") << CRandomGeneratorDESran4().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorDESran4().randomReal() = ") << CRandomGeneratorDESran4().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorFibonacci().randomInteger() = ") << CRandomGeneratorFibonacci().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorFibonacci().randomReal() = ") << CRandomGeneratorFibonacci().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorFibonacciEx().randomInteger() = ") << CRandomGeneratorFibonacciEx().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorFibonacciEx().randomReal() = ") << CRandomGeneratorFibonacciEx().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorGGL().randomInteger() = ") << CRandomGeneratorGGL().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorGGL().randomReal() = ") << CRandomGeneratorGGL().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorMLCGran1().randomInteger() = ") << CRandomGeneratorMLCGran1().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorMLCGran1().randomReal() = ") << CRandomGeneratorMLCGran1().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorMLCGran2().randomInteger() = ") << CRandomGeneratorMLCGran2().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorMLCGran2().randomReal() = ") << CRandomGeneratorMLCGran2().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorMRG().randomInteger() = ") << CRandomGeneratorMRG().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorMRG().randomReal() = ") << CRandomGeneratorMRG().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorMRG32k3a().randomInteger() = ") << CRandomGeneratorMRG32k3a().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorMRG32k3a().randomReal() = ") << CRandomGeneratorMRG32k3a().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorMT19937B().randomInteger() = ") << CRandomGeneratorMT19937B().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorMT19937B().randomReal() = ") << CRandomGeneratorMT19937B().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorMZran13().randomInteger() = ") << CRandomGeneratorMZran13().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorMZran13().randomReal() = ") << CRandomGeneratorMZran13().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorOldCongr().randomInteger() = ") << CRandomGeneratorOldCongr().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorOldCongr().randomReal() = ") << CRandomGeneratorOldCongr().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorR250().randomInteger() = ") << CRandomGeneratorR250().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorR250().randomReal() = ") << CRandomGeneratorR250().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorRANLUX().randomInteger() = ") << CRandomGeneratorRANLUX().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorRANLUX().randomReal() = ") << CRandomGeneratorRANLUX().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorRANMAR().randomInteger() = ") << CRandomGeneratorRANMAR().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorRANMAR().randomReal() = ") << CRandomGeneratorRANMAR().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorTaus88().randomInteger() = ") << CRandomGeneratorTaus88().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorTaus88().randomReal() = ") << CRandomGeneratorTaus88().randomReal() << ln;
    stdoutput << STR("CRandomGeneratorTT800().randomInteger() = ") << CRandomGeneratorTT800().randomInteger() << ln;
    stdoutput << STR("CRandomGeneratorTT800().randomReal() = ") << CRandomGeneratorTT800().randomReal() << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
