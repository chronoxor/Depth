/*!
 *  \file    example-functors-CClassFunctor.cpp Example of using the
 *           CClassFunctor class.
 *  \brief   Example of using the CClassFunctor class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CClassFunctor class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth functors examples
    VERSION:   1.0
    CREATED:   10.07.2007 03:38:36

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
#include <Depth/include/functors/CClassFunctor.hpp>
#include <Depth/include/functors/CClassFunctorMaker.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NFunctors;
/*==========================================================================*/
class CExampleClass
{
public:
  Tsint example0()
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CExampleClass::example0()") << ln;
    return 0;
  }
  Tsint example1(Tsint a) const
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CExampleClass::example1(") << a << STR(") const") << ln;
    return 0;
  }
  virtual Tsint example2(Tsint a, Tfloat b)
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CExampleClass::example2(") << a << STR(", ") << b << STR(") virtual") << ln;
    return 0;
  }
  virtual Tsint example10(Tsint a1, Tsint a2, Tsint a3, Tsint a4, Tsint a5, Tsint a6, Tsint a7, Tsint a8, Tsint a9, Tsint a10) volatile
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CExampleClass::example10(") << a1 << STR(", ") << a2 << STR(", ") << a3 << STR(", ") << a4 << STR(", ") << a5 << STR(", ") << a6 << STR(", ") << a7 << STR(", ") << a8 << STR(", ") << a9 << STR(", ") << a10 << STR(") virtual volatile") << ln;
    return 0;
  }
};
/*==========================================================================*/
Tsint example_const(const CExampleClass& instance, const CClassFunctor<Tsint (CExampleClass::*)(Tsint) const>& functor)
{ CALL
  if (functor.isValid())
    return functor(instance, 1000);
  else
    return -1;
}
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    CExampleClass example;

    CClassFunctor<Tsint (CExampleClass::*)()> a(&CExampleClass::example0);
    CClassFunctor<Tsint (CExampleClass::*)()> b(a);
    CClassFunctor<Tsint (CExampleClass::*)(Tsint) const> c(&CExampleClass::example1);
    CClassFunctor<Tsint (CExampleClass::*)(Tsint, Tfloat)> d(&CExampleClass::example2);
    CClassFunctor<Tsint (CExampleClass::*)(Tsint, Tsint, Tsint, Tsint, Tsint, Tsint, Tsint, Tsint, Tsint, Tsint) volatile> e(&CExampleClass::example10);

    // Call 'example' methods.
    if (a.isValid())
      a(example);
    if (b.isValid())
      b(example);
    if (c.isValid())
      c(example, 10);
    if (d.isValid())
      d(example, 10, 20.0);
    if (e.isValid())
      e(example, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    // Call constant method.
    example_const(example, c);

    // Examples of using class functor makers.
    CClassFunctor<Tsint (CExampleClass::*)(Tsint, Tfloat)> f = CClassFunctorMaker::make(&CExampleClass::example2);
    if (f.isValid())
      f(example, 20, 30.0);
    CClassFunctor<Tsint (CExampleClass::*)(Tsint, Tfloat)> g = CClassFunctorMaker::make(f);
    if (g.isValid())
      g(example, 30, 40.0);

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
