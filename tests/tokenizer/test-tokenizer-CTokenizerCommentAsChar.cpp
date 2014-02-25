/*!
 *  \file    test-tokenizer-CTokenizerCommentAsChar.cpp Testing of the
 *           CTokenizer class with the CTokenizerFunctionCommentAsChar rules.
 *  \brief   Testing of the CTokenizer class with the CTokenizerFunctionCommentAsChar rules.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CTokenizer class with the CTokenizerFunctionCommentAsChar rules.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth tokenizer tests
    VERSION:   1.0
    CREATED:   16.06.2010 19:39:10

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
#include <Depth/include/tokenizer/CTokenizerFunctionCommentAsChar.hpp>
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
    UT_ASSERT(tokenizer.setTokenizerFunction(CTokenizerFunctionCommentAsChar(STR('#'))));

    // Perform testing.
    test = STR("This is a test,\n simple test!\r\nHere comes comment #foo bar\n# foo bar\r\n#foo bar\nAnother one#foo bar");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("This")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("is")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("a")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("test,")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("simple")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("test!")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Here")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("comes")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("comment")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("Another")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("one")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
