/*!
 *  \file    test-random-CRandomBufferInteger.cpp Testing of the
 *           CRandomBufferInteger class.
 *  \brief   Testing of the CRandomBufferInteger class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CRandomBufferInteger class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth random tests
    VERSION:   1.0
    CREATED:   02.03.2009 21:35:54

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
#include <Depth/include/containers/CListDL.hpp>
#include <Depth/include/random/CRandomBufferInteger.hpp>
#include <Depth/include/random/CRandomGeneratorGGL.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NContainers;
using namespace NDepth::NRandom;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    Tuint static_buffer[6];
    CRandomBufferInteger<CRandomGeneratorGGL, CListDL> buffer;

    // Fill static buffer.
    static_buffer[1] = buffer.randomIntegerNext();
    static_buffer[2] = buffer.randomIntegerNext();
    static_buffer[3] = buffer.randomIntegerNext();
    static_buffer[4] = buffer.randomIntegerNext();
    static_buffer[5] = buffer.randomIntegerNext();

    // Check static buffer.
    UT_ASSERT_EQUAL(buffer.randomIntegerPrev(), static_buffer[5]);
    UT_ASSERT_EQUAL(buffer.randomIntegerPrev(), static_buffer[4]);
    UT_ASSERT_EQUAL(buffer.randomIntegerPrev(), static_buffer[3]);
    UT_ASSERT_EQUAL(buffer.randomIntegerPrev(), static_buffer[2]);
    UT_ASSERT_EQUAL(buffer.randomIntegerPrev(), static_buffer[1]);

    static_buffer[0] = buffer.randomIntegerCurrent();

    // Check iterator functionality.
    CRandomBufferInteger<CRandomGeneratorGGL, CListDL>::TIteratorConst it = buffer.getItCurrent();
    UT_ASSERT(it.isValid() && (it.getValueRef() == static_buffer[0]) && (it.stepForward() == 1));
    UT_ASSERT(it.isValid() && (it.getValueRef() == static_buffer[1]) && (it.stepForward() == 1));
    UT_ASSERT(it.isValid() && (it.getValueRef() == static_buffer[2]) && (it.stepForward() == 1));
    UT_ASSERT(it.isValid() && (it.getValueRef() == static_buffer[3]) && (it.stepForward() == 1));
    UT_ASSERT(it.isValid() && (it.getValueRef() == static_buffer[4]) && (it.stepForward() == 1));
    UT_ASSERT(it.isValid() && (it.getValueRef() == static_buffer[5]) && (it.stepForward() == 0));

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
