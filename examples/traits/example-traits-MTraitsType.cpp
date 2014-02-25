/*!
 *  \file    example-traits-MTraitsType.cpp Example of using the MTraitsType
 *           meta-class.
 *  \brief   Example of using the MTraitsType meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the MTraitsType meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth traits examples
    VERSION:   1.0
    CREATED:   01.01.2007 01:23:30

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
#include <Depth/include/traits/MTraitsType.hpp>
#include <Depth/include/traits/MTraitsRoutine.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NTraits;
/*==========================================================================*/
class CExampleClass
{
public:
  Tsint m_Field;

  Tsint method(Tsint a, Tsint b)
  { CALL
    Tsint result = a + b;
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CExampleClass::method(") << a << STR(", ") << b << STR(") returned ") << result << ln;
    return result;
  }

  Tsint method_const(Tsint a, Tsint b) const
  { CALL
    Tsint result = a + b;
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CExampleClass::method_const(") << a << STR(", ") << b << STR(") returned ") << result << ln;
    return result;
  }

  static Tsint method_static(Tsint a, Tsint b)
  { CALL
    Tsint result = a + b;
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CExampleClass::method_static(") << a << STR(", ") << b << STR(") returned ") << result << ln;
    return result;
  }
};
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

    MTraitsType<Tsint CExampleClass::*>::parent a;
    MTraitsType<Tsint CExampleClass::*>::type field = &CExampleClass::m_Field;
    MTraitsFunction<Tsint (CExampleClass::*)(Tsint, Tsint)>::type method = &CExampleClass::method;
    MTraitsFunction<Tsint (CExampleClass::*)(Tsint, Tsint) const>::type method_const = &CExampleClass::method_const;
    MTraitsFunction<Tsint (*)(Tsint, Tsint)>::type method_static = &CExampleClass::method_static;

    a.*field = (a.*method)(10, 20);
    a.*field = (a.*method_const)(10, 20);
    a.*field = method_static(10, 20);
    stdoutput << STR("CExampleClass::m_Field = ") << a.*field << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
