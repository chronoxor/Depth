/*!
 *  \file    example-utility-CPair.cpp Example of using the CPair class.
 *  \brief   Example of using the CPair class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CPair class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth utility examples
    VERSION:   1.0
    CREATED:   22.01.2007 00:10:52

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
#include <Depth/include/utility/CPair.hpp>
#include <Depth/include/utility/CPairMaker.hpp>
#include <Depth/include/utility/CPairTier.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NBase;
using namespace NDepth::NUtility;
/*==========================================================================*/
// Write instance of the template CPair<T1, T2> class into the given writer.
template <typename T1, typename T2>
IWriter& operator << (IWriter& writer, const CPair<T1, T2>& a_crPair)
{ CALL
  return writer << STR("CPair<T1, T2>(") << a_crPair.getFirst() << STR(", ") << a_crPair.getSecond() << STR(")");
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

    CPair<Tsint, Tfloat>  a(10, 20.3f);
    CPair<Tfloat, Tsint>  b(CPairMaker::make(10.3f, 20));
    CPair<Tsint, Tdouble> c(b);

    stdoutput << STR("a = ") << a << ln;
    stdoutput << STR("b = ") << b << ln;
    stdoutput << STR("c = ") << c << ln;

    Tsint   first  = 100;
    Tdouble second = 150.3;
    CPair<CReference<Tsint>, CReference<Tdouble> > d = CPairTier::tie(first, second);

    stdoutput << STR("d = ") << d << ln;

    first  = 200;
    second = 300.5;

    stdoutput << STR("d = ") << d << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
