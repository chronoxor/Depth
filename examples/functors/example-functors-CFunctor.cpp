/*!
 *  \file    example-functors-CFunctor.cpp Example of using the CFunctor 
 *           class.
 *  \brief   Example of using the CFunctor class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CFunctor class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth functors examples
    VERSION:   1.0
    CREATED:   11.07.2007 20:54:33

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
#include <Depth/include/functors/CFunctor.hpp>
#include <Depth/include/functors/CFunctorMaker.hpp>
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
using namespace NDepth::NUtility::NObserver;
/*==========================================================================*/
void example0()
{ CALL
  CStreamStdOutput stdoutput(true);
  stdoutput << STR("example0()") << ln;
}
/*--------------------------------------------------------------------------*/
Tsint example1(Tfloat a)
{ CALL
  CStreamStdOutput stdoutput(true);
  stdoutput << STR("example1(") << a << STR(")") << ln;
  return 0;
}
/*--------------------------------------------------------------------------*/
class CExampleClass
{
public:
  void operator() () const
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CExampleClass::opeartor() const") << ln;
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
};
/*--------------------------------------------------------------------------*/
class CExampleObserver :
  public IObserver
{
public:
  virtual ~CExampleObserver()
  { CALL
    IObserver::clear();
  }

  Tsint example3(Tchar a, Tsint b, Tfloat c) const
  { CALL
    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CExampleObserver::example3(") << a << STR(", ") << b << STR(", ") << c << STR(") const") << ln;
    return 0;
  }

private:
  virtual Tbool onConnect(const IConnector& a_crIConnector)
  { CALL
    IGNORE_UNUSED(a_crIConnector);

    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CExampleObserver connects with something") << ln;
    return true;
  }
  virtual Tbool onDisconnect(const IConnector& a_crIConnector)
  { CALL
    IGNORE_UNUSED(a_crIConnector);

    CStreamStdOutput stdoutput(true);
    stdoutput << STR("CExampleObserver disconnects with something") << ln;
    return true;
  }
};
/*==========================================================================*/
void example_const(const CExampleClass& instance)
{ CALL
  CFunctor<Tsint (Tsint)> f(instance, &CExampleClass::example1);
  if (f.isValid())
    f(50);
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
    CExampleObserver* example_observer = newex CExampleObserver();

    CFunctor<void()> a(example0);
    CFunctor<void()> b(a);
    CFunctor<Tsint (Tfloat)> c(example1);
    CFunctor<Tsint (Tsint, Tfloat)> d(example, &CExampleClass::example2);
    CFunctor<Tsint (Tchar, Tsint, Tfloat)> e(*example_observer, &CExampleObserver::example3);

    // Call 'example' functions.
    if (a.isValid())
      a();
    if (b.isValid())
      b();
    if (c.isValid())
      c(10.0);
    if (d.isValid())
      d(10, 20.0);
    if (e.isValid())
      e(ASC('!'), 10, 20.0);

    // Disconnect 'CExampleObserver' from functor.
    delete example_observer;

    // Call disconnected functor.
    if (e.isValid())
      e(ASC('!'), 10, 20.0);

    // Call constant function.
    example_const(example);

    // Call 'CExample::operator() const' method.
    CFunctor<void()> z(example);
    z();

    // Construct and call functor from functor.
    CFunctor<void()> f(a, &CFunctor<void()>::operator());
      f();

    // Examples of using functor makers.
    CFunctor<void ()> g = CFunctorMaker::make(example0);
    if (g.isValid())
      g();
    CFunctor<void ()> h = CFunctorMaker::make(z);
    if (h.isValid())
      h();

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
