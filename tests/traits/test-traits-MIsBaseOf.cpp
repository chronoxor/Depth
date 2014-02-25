/*!
 *  \file    test-traits-MIsBaseOf.cpp Testing of the MIsBaseOf meta-class.
 *  \brief   Testing of the MIsBaseOf meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the MIsBaseOf meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth traits tests
    VERSION:   1.0
    CREATED:   03.01.2007 00:05:37

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
#include <Depth/include/traits/MIsBaseOf.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NTraits;
/*==========================================================================*/
class A {};
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT((MIsBaseOf<A, A>::yes));
    UT_ASSERT((MIsBaseOf<A, B>::yes));
    UT_ASSERT((MIsBaseOf<A, D>::yes));
    UT_ASSERT((MIsBaseOf<B, D>::yes));
    UT_ASSERT((MIsBaseOf<C, D>::yes));
    UT_ASSERT(!(MIsBaseOf<B, C>::yes));

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
