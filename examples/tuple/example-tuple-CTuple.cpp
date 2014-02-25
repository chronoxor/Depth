/*!
 *  \file    example-tuple-CTuple.cpp Example of using the CTuple class.
 *  \brief   Example of using the CTuple class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CTuple class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth tuple examples
    VERSION:   1.0
    CREATED:   26.01.2007 00:35:47

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
#include <Depth/include/tuple/CTuple.hpp>
#include <Depth/include/tuple/CTupleMaker.hpp>
#include <Depth/include/tuple/CTupleTier.hpp>
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
using namespace NDepth::NTuple;
/*==========================================================================*/
// Write instance of the template CTuple<T1, T2, T3> class into the given writer.
template <typename T1, typename T2, typename T3>
IWriter& operator << (IWriter& writer, const CTuple<T1, T2, T3>& a_crTuple)
{ CALL
  return writer << STR("CTuple<T1, T2, T3>(") << a_crTuple.getValue<1>() << STR(", ") << a_crTuple.getValue<2>() << STR(", ") << a_crTuple.getValue<3>() << STR(")");
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

    CTuple<Tsint, Tfloat, Tchar>  a(10, 20.3f, STR('A'));
    CTuple<Tfloat, Tsint, Tchar>  b(CTupleMaker::make(10.3f, 20, STR('B')));
    CTuple<Tsint, Tdouble, Tchar> c(b);

    stdoutput << STR("a = ") << a << ln;
    stdoutput << STR("b = ") << b << ln;
    stdoutput << STR("c = ") << c << ln;

    Tsint   first  = 100;
    Tdouble second = 150.3;
    Tchar   third  = STR('X');
    CTuple<CReference<Tsint>, CReference<Tdouble>, CReference<Tchar> > d = CTupleTier::tie(first, second, third);

    stdoutput << STR("d = ") << d << ln;

    first  = 200;
    second = 300.5;
    third  = STR('Z');

    stdoutput << STR("d = ") << d << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
