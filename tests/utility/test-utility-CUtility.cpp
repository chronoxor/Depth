/*!
 *  \file    test-utility-CUtility.cpp Testing of the CUtility class.
 *  \brief   Testing of the CUtility class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CUtility class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth utility tests
    VERSION:   1.0
    CREATED:   22.01.2007 00:21:52

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
// Temporary headers.
#include <Depth/todo/serialize/serialize.hpp>
/*--------------------------------------------------------------------------*/
// Common headers.
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/algorithms/numeric/ADiv.hpp>
#include <Depth/include/algorithms/numeric/ARotate.hpp>
#include <Depth/include/utility/CUtility.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NBase;
using namespace NDepth::NUtility;
using namespace NDepth::NSerialization;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_EQUAL(BIN8(00001010), 0x0A);
    UT_ASSERT_EQUAL(BIN16(00001010, 00001010), 0x0A0A);
    UT_ASSERT_EQUAL(BIN24(00001010, 00001010, 00001010), 0x0A0A0A);
    UT_ASSERT_EQUAL(BIN32(00001010, 00001010, 00001010, 00001010), 0x0A0A0A0A);

    UT_ASSERT_EQUAL(NAlgorithms::NNumeric::div(5, 3).getFirst(), 0x1);
    UT_ASSERT_EQUAL(NAlgorithms::NNumeric::div(5, 3).getSecond(), 0x2);
    UT_ASSERT_EQUAL(NAlgorithms::NNumeric::cyclicRotateLeft(CONSTU32(12), 3), CONSTU32(0x00000060));
    UT_ASSERT_EQUAL(NAlgorithms::NNumeric::cyclicRotateRight(CONSTU32(12), 3), CONSTU32(-0x7FFFFFFF));
    UT_ASSERT_EQUAL(NAlgorithms::NNumeric::rotateLeft(CONSTU32(12), 3), CONSTU32(0x00000060));
    UT_ASSERT_EQUAL(NAlgorithms::NNumeric::rotateRight(CONSTU32(12), 3), CONSTU32(0x00000001));
    UT_ASSERT_EQUAL(CUtility::reverseBytes(CONSTU32(1024)), CONSTU32(0x00040000));
    UT_ASSERT_EQUAL(CUtility::reverseBits(CONSTU32(1024)), CONSTU32(0x00200000));

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
