/*!
 *  \file    test-functors-CClassFunctor.cpp Testing of the CClassFunctor 
 *           class.
 *  \brief   Testing of the CClassFunctor class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.07.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CClassFunctor class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth functors tests
    VERSION:   1.0
    CREATED:   11.07.2007 02:41:58

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
#include <Depth/include/functors/CClassFunctor.hpp>
#include <Depth/include/functors/CClassFunctorMaker.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NFunctors;
/*==========================================================================*/
class CTestClass
{
public:
  Tbool test0()
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
  virtual Tbool test10(Tsint a1, Tsint a2, Tsint a3, Tsint a4, Tsint a5, Tsint a6, Tsint a7, Tsint a8, Tsint a9, Tsint a10) volatile
  { CALL
    IGNORE_UNUSED(a1);
    IGNORE_UNUSED(a2);
    IGNORE_UNUSED(a3);
    IGNORE_UNUSED(a4);
    IGNORE_UNUSED(a5);
    IGNORE_UNUSED(a6);
    IGNORE_UNUSED(a7);
    IGNORE_UNUSED(a8);
    IGNORE_UNUSED(a9);
    IGNORE_UNUSED(a10);

    return true;
  }
};
/*==========================================================================*/
Tbool test_const(const CTestClass& instance, const CClassFunctor<Tbool (CTestClass::*)(Tsint) const>& functor)
{ CALL
  if (functor.isValid())
    return functor(instance, 1000);
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

    CClassFunctor<Tbool (CTestClass::*)()> a(&CTestClass::test0);
    CClassFunctor<Tbool (CTestClass::*)()> b(a);
    CClassFunctor<Tbool (CTestClass::*)(Tsint) const> c(&CTestClass::test1);
    CClassFunctor<Tbool (CTestClass::*)(Tsint, Tfloat)> d(&CTestClass::test2);
    CClassFunctor<Tbool (CTestClass::*)(Tsint, Tsint, Tsint, Tsint, Tsint, Tsint, Tsint, Tsint, Tsint, Tsint) volatile> e(&CTestClass::test10);

    // Check 'test' methods.
    UT_ASSERT(a.isValid());
    UT_ASSERT(a(test));
    UT_ASSERT(b.isValid());
    UT_ASSERT(b(test));
    UT_ASSERT(c.isValid());
    UT_ASSERT(c(test, 10));
    UT_ASSERT(d.isValid());
    UT_ASSERT(d(test, 10, 20.0));
    UT_ASSERT(e.isValid());
    UT_ASSERT(e(test, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));

    // Check constant method.
    UT_ASSERT(test_const(test, c));

    // Check class functor makers.
    CClassFunctor<Tbool (CTestClass::*)(Tsint, Tfloat)> f = CClassFunctorMaker::make(&CTestClass::test2);
    UT_ASSERT(f.isValid());
    UT_ASSERT(f(test, 20, 30.0));
    CClassFunctor<Tbool (CTestClass::*)(Tsint, Tfloat)> g = CClassFunctorMaker::make(f);
    UT_ASSERT(g.isValid());
    UT_ASSERT(g(test, 30, 40.0));

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
