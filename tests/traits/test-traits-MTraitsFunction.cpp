/*!
 *  \file    test-traits-MTraitsFunction.cpp Testing of the MTraitsFunction
 *           meta-class.
 *  \brief   Testing of the MTraitsFunction meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the MTraitsFunction meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth traits tests
    VERSION:   1.0
    CREATED:   02.01.2007 23:40:52

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
#include <Depth/include/traits/MIsMemberPointer.hpp>
#include <Depth/include/traits/MTraitsRoutine.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NTraits;
using namespace NDepth::NTraits::NFunctions;
/*==========================================================================*/
class CTestClass
{
public:
  Tsint m_Field;

  Tsint operator() ()
  { CALL
    return 0;
  }

  Tsint method(const Tschar a_cCharValue)
  { CALL
    return (Tsint)((Tsint)a_cCharValue);
  }

  Tsint method_const(const Tschar a_cCharValue, const Tfloat a_cFloatValue) const
  { CALL
    return (Tsint)((Tsint)a_cCharValue+(Tsint)a_cFloatValue);
  }

  static Tsint method_static(const Tschar a_cCharValue, const Tfloat a_cFloatValue, const Tdouble a_cDoubleValue)
  { CALL
    return (Tsint)((Tsint)a_cCharValue+(Tsint)a_cFloatValue+(Tsint)a_cDoubleValue);
  }
};
/*--------------------------------------------------------------------------*/
Tsint function(const Tschar a_cCharValue, const Tfloat a_cFloatValue)
{ CALL
  return (Tsint)((Tsint)a_cCharValue+(Tsint)a_cFloatValue);
}
/*==========================================================================*/
template <typename T>
unsigned checkFunctionArity(T)
{ CALL
  return MTraitsFunction<T>::arity;
}
/*--------------------------------------------------------------------------*/
template <typename T>
unsigned checkMethodArity(T)
{ CALL
  return MTraitsFunction<T>::arity;
}
/*--------------------------------------------------------------------------*/
template <typename T>
Tbool checkMemberPointer(T)
{ CALL
  return MIsMemberPointer<T>::yes;
}
/*--------------------------------------------------------------------------*/
template <typename T>
Tbool checkMemberPointerToObject(T)
{ CALL
  return MIsMemberPointerToObject<T>::yes;
}
/*--------------------------------------------------------------------------*/
template <typename T>
Tbool checkMemberPointerToMethod(T)
{ CALL
  return MIsMemberPointerToMethod<T>::yes;
}
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_EQUAL(checkFunctionArity(function), 2);
    UT_ASSERT_EQUAL(checkFunctionArity(&CTestClass::method_static), 3);

    UT_ASSERT_EQUAL(checkMethodArity(&CTestClass::operator()), 0);
    UT_ASSERT_EQUAL(checkMethodArity(&CTestClass::method), 1);
    UT_ASSERT_EQUAL(checkMethodArity(&CTestClass::method_const), 2);

    UT_ASSERT(checkMemberPointer(&CTestClass::m_Field));
    UT_ASSERT(checkMemberPointer(&CTestClass::method));
    UT_ASSERT(checkMemberPointer(&CTestClass::method_const));
    UT_ASSERT(!checkMemberPointer(&CTestClass::method_static));

    UT_ASSERT(checkMemberPointerToObject(&CTestClass::m_Field));
    UT_ASSERT(!checkMemberPointerToObject(&CTestClass::method));
    UT_ASSERT(!checkMemberPointerToObject(&CTestClass::method_const));
    UT_ASSERT(!checkMemberPointerToObject(&CTestClass::method_static));

    UT_ASSERT(!checkMemberPointerToMethod(&CTestClass::m_Field));
    UT_ASSERT(checkMemberPointerToMethod(&CTestClass::method));
    UT_ASSERT(checkMemberPointerToMethod(&CTestClass::method_const));
    UT_ASSERT(!checkMemberPointerToMethod(&CTestClass::method_static));

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
