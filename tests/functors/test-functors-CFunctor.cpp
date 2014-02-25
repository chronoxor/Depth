/*!
 *  \file    test-functors-CFunctor.cpp Testing of the CFunctor class.
 *  \brief   Testing of the CFunctor class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CFunctor class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth functors tests
    VERSION:   1.0
    CREATED:   11.07.2007 22:35:54

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
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/functors/CFunctor.hpp>
#include <Depth/include/functors/CFunctorMaker.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NFunctors;
using namespace NDepth::NUtility::NObserver;
/*==========================================================================*/
Tbool test0()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool test1(Tfloat a)
{ CALL
  IGNORE_UNUSED(a);

  return true;
}
/*--------------------------------------------------------------------------*/
class CTestClass
{
public:
  Tbool operator() () const
  { CALL
    return true;
  }

  Tbool test1(Tsint a) const
  { CALL
    IGNORE_UNUSED(a);

    return true;
  }
  virtual Tbool test2(Tsint a, Tfloat b)
  { CALL
    IGNORE_UNUSED(a);
    IGNORE_UNUSED(b);

    return true;
  }
};
/*--------------------------------------------------------------------------*/
class CTestObserver :
  public IObserver
{
public:
  virtual ~CTestObserver()
  { CALL
    IObserver::clear();
  }

  Tbool test3(Tchar a, Tsint b, Tfloat c) const
  { CALL
    IGNORE_UNUSED(a);
    IGNORE_UNUSED(b);
    IGNORE_UNUSED(c);

    return true;
  }
};
/*==========================================================================*/
Tbool test_const(const CTestClass& instance)
{ CALL
  CFunctor<Tbool (Tsint)> f(instance, &CTestClass::test1);
  if (f.isValid())
    return f(50);
  else
    return false;
}
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CTestClass test;
    CTestObserver* test_observer = newex CTestObserver();

    CFunctor<Tbool()> a(test0);
    CFunctor<Tbool()> b(a);
    CFunctor<Tbool (Tfloat)> c(test1);
    CFunctor<Tbool (Tsint, Tfloat)> d(test, &CTestClass::test2);
    CFunctor<Tbool (Tchar, Tsint, Tfloat)> e(*test_observer, &CTestObserver::test3);

    // Check 'test' functions.
    UT_ASSERT(a.isValid());
    UT_ASSERT(a());
    UT_ASSERT(b.isValid());
    UT_ASSERT(b());
    UT_ASSERT(c.isValid());
    UT_ASSERT(c(10.0));
    UT_ASSERT(d.isValid());
    UT_ASSERT(d(10, 20.0));
    UT_ASSERT(e.isValid());
    UT_ASSERT(e('!', 10, 20.0));

    // Disconnect 'CTestObserver' from functor.
    delete test_observer;

    // Check disconnected functor.
    UT_ASSERT(!e.isValid());

    // Check constant function.
    UT_ASSERT(test_const(test));

    // Check 'CTest::operator() const' method.
    CFunctor<Tbool()> z(test);
    UT_ASSERT(z.isValid());
    UT_ASSERT(z());

    // Construct and check functor from functor.
    CFunctor<Tbool()> f(a, &CFunctor<Tbool()>::operator());
    UT_ASSERT(f.isValid());
    UT_ASSERT(f());

    // Check functor makers.
    CFunctor<Tbool ()> g = CFunctorMaker::make(test0);
    UT_ASSERT(g.isValid());
    UT_ASSERT(g());
    CFunctor<Tbool ()> h = CFunctorMaker::make(z);
    UT_ASSERT(h.isValid());
    UT_ASSERT(h());

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
