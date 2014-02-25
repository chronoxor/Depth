/*!
 *  \file    test-common-IClonable.cpp Testing of the IClonable interface.
 *  \brief   Testing of the IClonable interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the IClonable interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth common tests
    VERSION:   1.0
    CREATED:   03.01.2007 00:32:53

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
#include <Depth/include/common/IClonable.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NCommon;
/*==========================================================================*/
class CBase :
  public IClonable<CBase>
{

};
/*--------------------------------------------------------------------------*/
class CDerived1 :
  public CBase
{
  CBase* clone() const
  { CALL
    return newex CDerived1();
  }
};
/*--------------------------------------------------------------------------*/
class CDerived2 :
  public CBase
{
  CBase* clone() const
  { CALL
    return newex CDerived2();
  }
};
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CBase* base_ptr = newex CDerived2();
    CBase* base_clon_ptr = base_ptr->clone();

    UT_ASSERT_INVALID_PTR(NAlgorithms::NCommon::dynamicCast<CDerived1*>(base_clon_ptr));
    UT_ASSERT_VALID_PTR(NAlgorithms::NCommon::dynamicCast<CDerived2*>(base_clon_ptr));

    delete base_ptr;
    delete base_clon_ptr;

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
