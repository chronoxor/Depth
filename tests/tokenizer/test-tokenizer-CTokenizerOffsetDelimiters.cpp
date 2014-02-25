/*!
 *  \file    test-tokenizer-CTokenizerOffsetDelimiters.cpp Testing of the
 *           CTokenizer class with the CTokenizerFunctionOffsetDelimiters
 *           rules.
 *  \brief   Testing of the CTokenizer class with the CTokenizerFunctionOffsetDelimiters rules.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CTokenizer class with the CTokenizerFunctionOffsetDelimiters rules.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth tokenizer tests
    VERSION:   1.0
    CREATED:   24.04.2009 02:52:23

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
#include <Depth/include/containers/CWrappedArray.hpp>
#include <Depth/include/tokenizer/CTokenizer.hpp>
#include <Depth/include/tokenizer/CTokenizerFunctionOffsetDelimiters.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NContainers;
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
    Tuint offsets[] = { 1, 2, 3 };
    CWrappedArray<Tuint> offsetarray(offsets);
    CTokenizerFunctionOffsetDelimiters tf;
    CTokenizer tokenizer;
    CTokenizer::TIterator it;

    // Prepare tokenizer with default offset tokenizer function (initialized with a single offset value (1)).
    UT_ASSERT(tokenizer.setTokenizerFunction(tf));
    // Perform testing.
    test = STR("1234567890");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("1")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("2")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("3")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("4")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("5")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("6")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("7")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("8")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("9")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("0")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    // Prepare tokenizer with offset tokenizer function which wraps offsets and returns last partially parser token.
    UT_ASSERT(tf.set(offsetarray.getItFirst(), true, true));
    UT_ASSERT(tokenizer.setTokenizerFunction(tf));
    // Perform testing.
    test = STR("1234567890ABCDEF");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("1")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("23")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("456")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("7")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("89")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("0AB")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("C")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("DE")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("F")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    // Prepare tokenizer with offset tokenizer function which wraps offsets but does not return last partially parser token.
    UT_ASSERT(tf.set(offsetarray.getItFirst(), true, false));
    UT_ASSERT(tokenizer.setTokenizerFunction(tf));
    // Perform testing.
    test = STR("1234567890ABCDEF");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("1")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("23")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("456")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("7")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("89")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("0AB")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("C")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("DE")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    // Prepare tokenizer with offset tokenizer function which does not wrap offsets and return last partially parser token.
    UT_ASSERT(tf.set(true, offsetarray, false, false));
    UT_ASSERT(tokenizer.setTokenizerFunction(tf));
    // Perform testing.
    test = STR("1234567890ABCDEF");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("1")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("23")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("456")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    // Prepare tokenizer with offset tokenizer function which does not wrap offsets but returns last partially parser token.
    UT_ASSERT(tf.set(true, offsetarray, false, true));
    UT_ASSERT(tokenizer.setTokenizerFunction(tf));
    // Perform testing.
    test = STR("12345");
    UT_ASSERT(tokenizer.setInputContainer(test));
    it = tokenizer.getItTop();
    UT_ASSERT_EQUAL(*it, CString(STR("1")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("23")));
    UT_ASSERT_EQUAL(it.stepForward(), 1);
    UT_ASSERT_EQUAL(*it, CString(STR("45")));
    UT_ASSERT_EQUAL(it.stepForward(), 0);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
