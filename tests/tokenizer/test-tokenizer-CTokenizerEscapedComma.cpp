/*!
 *  \file    test-tokenizer-CTokenizerEscapedComma.cpp Testing of the
 *           CTokenizer class with the CTokenizerFunctionEscapedComma rules.
 *  \brief   Testing of the CTokenizer class with the CTokenizerFunctionEscapedComma rules.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CTokenizer class with the CTokenizerFunctionEscapedComma rules.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth tokenizer tests
    VERSION:   1.0
    CREATED:   24.04.2009 21:13:16

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
#include <Depth/include/tokenizer/CTokenizer.hpp>
#include <Depth/include/tokenizer/CTokenizerFunctionEscapedComma.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NString;
using namespace NDepth::NTokenizer;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CString test;
    CTokenizer tokenizer;
    CTokenizer::TIterator it;

    // Prepare tokenizer with default tokenizer function.
    UT_ASSERT(tokenizer.setTokenizerFunction(CTokenizerFunctionEscapedComma()));
    // Perform simple testing.
    test = STR("Test 1,Test 2,Test 3");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("Test 1")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Test 2")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Test 3")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    // Perform quoted comma testing.
    test = STR("Test 1,\"Test 2,Test 3\",Test 4");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("Test 1")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Test 2,Test 3")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Test 4")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    // Perform escaped quotas testing.
    test = STR("Test 1,\\\"Test 2 with escaped quotes\\\",Test 3");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("Test 1")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("\"Test 2 with escaped quotes\"")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Test 3")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    // Perform escape testing.
    test = STR("Test 1,Test 2 with \\\\ escape,Test 3");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("Test 1")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Test 2 with \\ escape")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Test 3")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    // Perform comma testing.
    test = STR("Test 1,Test 2,Test 3,");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("Test 1")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Test 2")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Test 3")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    // Prepare tokenizer with equal open and close quotes requirement tokenizer function.
    UT_ASSERT(tokenizer.setTokenizerFunction(CTokenizerFunctionEscapedComma(CString(STR("\\")), CString(STR(",")), CString(STR("'\"")), true)));
    // Perform testing.
    test = STR("Test 1,Test 2 with \"abc, 'def', ghi\",Test 3 'remain,");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("Test 1")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Test 2 with abc, 'def', ghi")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Test 3 remain,")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
