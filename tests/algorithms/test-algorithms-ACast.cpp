/*!
 *  \file    test-algorithms-ACast.cpp Testing of the cast algorithms.
 *  \brief   Testing of the cast algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the cast algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   17.01.2007 23:18:36

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
#include <Depth/include/algorithms/common/ACast.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NCommon;
/*==========================================================================*/
class CNonPolymorphicBase
{
public:
  Tuint test()
  { CALL
    return 0;
  }
};
/*--------------------------------------------------------------------------*/
class CNonPolymorphicDerived :
  public CNonPolymorphicBase
{
public:
  Tuint test()
  { CALL
    return 1;
  }
};
/*==========================================================================*/
class CPolymorphicBase
{
public:
  virtual ~CPolymorphicBase()
  {

  }

  virtual Tuint test()
  { CALL
    return 0;
  }
};
/*--------------------------------------------------------------------------*/
class CPolymorphicDerived :
  public CPolymorphicBase
{
public:
  virtual ~CPolymorphicDerived()
  {

  }

  virtual Tuint test()
  { CALL
    return 1;
  }
};
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    // Non polymorphic cast.
    CNonPolymorphicBase* a = newex CNonPolymorphicDerived();
    CNonPolymorphicDerived* b = nonPolymorphicCast<CNonPolymorphicDerived*>(a);
    UT_ASSERT_INVALID_PTR(b);
    delete a;

    // Polymorphic cast.
    CPolymorphicBase* c = newex CPolymorphicDerived();
    CPolymorphicDerived* d = nonPolymorphicCast<CPolymorphicDerived*>(c);
    UT_ASSERT_VALID_PTR(d);
    delete c;

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
