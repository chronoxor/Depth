/*!
 *  \file    test-algorithms-AString.cpp Testing of the string algorithms.
 *  \brief   Testing of the string algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the string algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   28.03.2008 20:22:43

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
#include <Depth/include/algorithms/string/buffer/AStrBrk.hpp>
#include <Depth/include/algorithms/string/buffer/AStrCat.hpp>
#include <Depth/include/algorithms/string/buffer/AStrChr.hpp>
#include <Depth/include/algorithms/string/buffer/AStrCmp.hpp>
#include <Depth/include/algorithms/string/buffer/AStrICmp.hpp>
#include <Depth/include/algorithms/string/buffer/AStrCpy.hpp>
#include <Depth/include/algorithms/string/buffer/AStrLen.hpp>
#include <Depth/include/algorithms/string/buffer/AStrRChr.hpp>
#include <Depth/include/algorithms/string/buffer/AStrRStr.hpp>
#include <Depth/include/algorithms/string/buffer/AStrSpn.hpp>
#include <Depth/include/algorithms/string/buffer/AStrCSpn.hpp>
#include <Depth/include/algorithms/string/buffer/AStrStr.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNBrk.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNCat.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNChr.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNCmp.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNICmp.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNCpy.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNLen.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNRChr.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNRStr.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNSpn.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNCSpn.hpp>
#include <Depth/include/algorithms/string/buffer/AStrNStr.hpp>
#include <Depth/include/algorithms/string/AFindChar.hpp>
#include <Depth/include/algorithms/string/AFindCharOneOf.hpp>
#include <Depth/include/algorithms/string/AFindString.hpp>
#include <Depth/include/algorithms/string/ARemoveString.hpp>
#include <Depth/include/algorithms/string/ARemoveStringAll.hpp>
#include <Depth/include/algorithms/string/AReplaceString.hpp>
#include <Depth/include/algorithms/string/AReplaceStringAll.hpp>
#include <Depth/include/algorithms/string/AStringLength.hpp>
#include <Depth/include/algorithms/string/AStringSize.hpp>
#include <Depth/include/algorithms/string/AStringCompare.hpp>
#include <Depth/include/algorithms/string/AStringCompareIgnoreCase.hpp>
#include <Depth/include/algorithms/string/AStringCopy.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NString;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    // Testing of the 'strlen()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strLen(ASC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strLen(ASC("asdf")), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strLen(ASC("asdf zxcv")), 9);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strLen(UNC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strLen(UNC("asdf")), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strLen(UNC("asdf zxcv")), 9);
    // Testing of the 'strnlen()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNLen(ASC("asdf"), 10), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNLen(ASC("asdf zxcv"), 5), 5);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNLen(UNC("asdf"), 10), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNLen(UNC("asdf zxcv"), 5), 5);

    // Testing of the 'strcmp()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(ASC(""), ASC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(ASC("asdf"), ASC("")), ASC('a'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(ASC(""), ASC("asdf")), -ASC('a'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(ASC("asdf"), ASC("asdf")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(ASC("asdfghjkl"), ASC("asdf")), ASC('g'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(ASC("asdf"), ASC("asdfghjkl")), -ASC('g'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(UNC(""), UNC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(UNC("asdf"), UNC("")), UNC('a'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(UNC(""), UNC("asdf")), -UNC('a'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(UNC("asdf"), UNC("asdf")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(UNC("asdfghjkl"), UNC("asdf")), UNC('g'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCmp(UNC("asdf"), UNC("asdfghjkl")), -UNC('g'));
    // Testing of the 'strncmp()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCmp(ASC("asdf"), ASC("asdf"), 3), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCmp(ASC("asdfghjkl"), ASC("asdf"), 4), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCmp(ASC("asdf"), ASC("asdfghjkl"), 4), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCmp(UNC("asdf"), UNC("asdf"), 3), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCmp(UNC("asdfghjkl"), UNC("asdf"), 4), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCmp(UNC("asdf"), UNC("asdfghjkl"), 4), 0);

    // Testing of the 'stricmp()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(ASC(""), ASC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(ASC("aSdF"), ASC("")), ASC('a'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(ASC(""), ASC("asDf")), -ASC('a'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(ASC("aSdF"), ASC("asDf")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(ASC("aSdFgHjKl"), ASC("asDf")), ASC('g'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(ASC("aSdF"), ASC("asDfgHjkL")), -ASC('g'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(UNC(""), UNC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(UNC("aSdF"), UNC("")), UNC('a'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(UNC(""), UNC("asDf")), -UNC('a'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(UNC("aSdF"), UNC("asDf")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(UNC("aSdFgHjKl"), UNC("asDf")), UNC('g'));
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strICmp(UNC("aSdF"), UNC("asDfgHjkL")), -UNC('g'));
    // Testing of the 'strnicmp()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNICmp(ASC("aSdF"), ASC("asDf"), 3), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNICmp(ASC("aSdFgHjKl"), ASC("asDf"), 4), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNICmp(ASC("aSdF"), ASC("asDfgHjkL"), 4), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNICmp(UNC("aSdF"), UNC("asDf"), 3), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNICmp(UNC("aSdFgHjKl"), UNC("asDf"), 4), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNICmp(UNC("aSdF"), UNC("asDfgHjkL"), 4), 0);

    // Testing of the 'strbrk()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strBrk(ASC(""), ASC("wsx")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strBrk(ASC("asdf"), ASC("")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strBrk(ASC("asdf"), ASC("wsx")), 1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strBrk(ASC("asdf zxcv"), ASC("wsx")), 1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strBrk(ASC("asdf zxcv qwer"), ASC("ujm")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strBrk(UNC(""), UNC("wsx")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strBrk(UNC("asdf"), UNC("")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strBrk(UNC("asdf"), UNC("wsx")), 1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strBrk(UNC("asdf zxcv"), UNC("wsx")), 1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strBrk(UNC("asdf zxcv qwer"), UNC("ujm")), -1);
    // Testing of the 'strnbrk()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNBrk(ASC("asdf"), 1, ASC("wsx")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNBrk(ASC("asdf zxcv"), 5, ASC("edc")), 2);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNBrk(UNC("asdf"), 1, UNC("wsx")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNBrk(UNC("asdf zxcv"), 5, UNC("edc")), 2);

    // Testing of the 'strchr()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strChr(ASC(""), ASC('w')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strChr(ASC("asdf"), ASC('z')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strChr(ASC("asdf"), ASC('s')), 1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strChr(ASC("asdf zxcv"), ASC('z')), 5);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strChr(UNC(""), UNC('w')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strChr(UNC("asdf"), UNC('z')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strChr(UNC("asdf"), UNC('s')), 1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strChr(UNC("asdf zxcv"), UNC('z')), 5);
    // Testing of the 'strnchr()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNChr(ASC("asdf"), 1, ASC('s')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNChr(ASC("asdf zxcv"), 5, ASC('d')), 2);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNChr(UNC("asdf"), 1, UNC('s')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNChr(UNC("asdf zxcv"), 5, UNC('d')), 2);

    // Testing of the 'strrchr()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRChr(ASC(""), ASC('w')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRChr(ASC("asdf asdf"), ASC('z')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRChr(ASC("asdf asdf"), ASC('s')), 6);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRChr(ASC("asdf asdf asdf"), ASC('s')), 11);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRChr(UNC(""), UNC('w')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRChr(UNC("asdf asdf"), UNC('z')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRChr(UNC("asdf asdf"), UNC('s')), 6);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRChr(UNC("asdf asdf asdf"), UNC('s')), 11);
    // Testing of the 'strnrchr()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNRChr(ASC("asdf asdf"), 1, ASC('s')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNRChr(ASC("asdf asdf asdf"), 8, ASC('s')), 6);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNRChr(UNC("asdf asdf"), 1, UNC('s')), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNRChr(UNC("asdf asdf asdf"), 8, UNC('s')), 6);

    // Testing of the 'strspn()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strSpn(ASC(""), ASC("asd")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strSpn(ASC("asdfghjkl"), ASC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strSpn(ASC("asdfghjkl"), ASC("asdf")), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strSpn(ASC("asdfghjkl"), ASC("jkljkl")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strSpn(UNC(""), UNC("asd")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strSpn(UNC("asdfghjkl"), UNC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strSpn(UNC("asdfghjkl"), UNC("asdf")), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strSpn(UNC("asdfghjkl"), UNC("jkljkl")), 0);
    // Testing of the 'strnspn()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNSpn(ASC("asdfghjkl"), 2, ASC("asdf")), 2);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNSpn(UNC("asdfghjkl"), 2, UNC("asdf")), 2);

    // Testing of the 'strcspn()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCSpn(ASC(""), ASC("asd")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCSpn(ASC("asdfghjkl"), ASC("")), 9);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCSpn(ASC("asdfghjkl"), ASC("ghjk")), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCSpn(ASC("asdfghjkl"), ASC("asdf")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCSpn(UNC(""), UNC("asd")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCSpn(UNC("asdfghjkl"), UNC("")), 9);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCSpn(UNC("asdfghjkl"), UNC("ghjk")), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCSpn(UNC("asdfghjkl"), UNC("asdf")), 0);
    // Testing of the 'strncspn()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCSpn(ASC("asdfghjkl"), 2, ASC("ghjk")), 2);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCSpn(UNC("asdfghjkl"), 2, UNC("ghjk")), 2);

    // Testing of the 'strstr()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strStr(ASC(""), ASC("asd")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strStr(ASC("asdfghjkl"), ASC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strStr(ASC("asdfghjkl"), ASC("fgh")), 3);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strStr(ASC("asdfghjkl"), ASC("jkljkl")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strStr(UNC(""), UNC("asd")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strStr(UNC("asdfghjkl"), UNC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strStr(UNC("asdfghjkl"), UNC("fgh")), 3);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strStr(UNC("asdfghjkl"), UNC("jkljkl")), -1);
    // Testing of the 'strnstr()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNStr(ASC("asdfghjkl"), 5, ASC("fgh")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNStr(UNC("asdfghjkl"), 5, UNC("fgh")), -1);

    // Testing of the 'strrstr()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRStr(ASC(""), ASC("asd")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRStr(ASC("asdfghjkl"), ASC("")), 8);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRStr(ASC("asdfghjkl asdfghjkl asdfghjkl"), ASC("fgh")), 23);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRStr(ASC("asdfghjkl asdfghjkl asdfghjkl"), ASC("jkljkl")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRStr(UNC(""), UNC("asd")), -1);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRStr(UNC("asdfghjkl"), UNC("")), 8);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRStr(UNC("asdfghjkl asdfghjkl asdfghjkl"), UNC("fgh")), 23);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strRStr(UNC("asdfghjkl asdfghjkl asdfghjkl"), UNC("jkljkl")), -1);
    // Testing of the 'strnrstr()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNRStr(ASC("asdfghjkl asdfghjkl asdfghjkl"), 20, ASC("fgh")), 13);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNRStr(UNC("asdfghjkl asdfghjkl asdfghjkl"), 20, UNC("fgh")), 13);

    Tschar dstASCII[256];
    Twchar dstUnicode[256];

    // Testing of the 'strcpy()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCpy(dstASCII, ASC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCpy(dstASCII, ASC("asdfghjkl")), 9);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCpy(dstUnicode, UNC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCpy(dstUnicode, UNC("asdfghjkl")), 9);
    // Testing of the 'strncpy()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCpy(dstASCII, ASC(""), 4), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCpy(dstASCII, ASC("asdf"), 8), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCpy(dstASCII, ASC("asdfghjkl"), 4), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCpy(dstUnicode, UNC(""), 4), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCpy(dstUnicode, UNC("asdf"), 8), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCpy(dstUnicode, UNC("asdfghjkl"), 4), 4);

    // Testing of the 'strcat()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCpy(dstASCII, ASC("asdfghjkl")), 9);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCat(dstASCII, ASC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCat(dstASCII, ASC("asdfghjkl")), 9);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCpy(dstUnicode, UNC("asdfghjkl")), 9);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCat(dstUnicode, UNC("")), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strCat(dstUnicode, UNC("asdfghjkl")), 9);
    // Testing of the 'strncat()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCpy(dstASCII, ASC("asdfghjkl"), 4), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCat(dstASCII, ASC(""), 4), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCat(dstASCII, ASC("asdf"), 8), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCat(dstASCII, ASC("asdfghjkl"), 4), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCpy(dstUnicode, UNC("asdfghjkl"), 4), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCat(dstUnicode, UNC(""), 4), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCat(dstUnicode, UNC("asdf"), 8), 4);
    UT_ASSERT_EQUAL(NAlgorithms::NString::NBuffer::strNCat(dstUnicode, UNC("asdfghjkl"), 4), 4);

    Tuint position;

    // Testing of the 'findChar()' algorithm.
    UT_ASSERT(!NAlgorithms::NString::findChar(false, false, position, CString(STR("adsfdsa")), STR('z')));
    UT_ASSERT(NAlgorithms::NString::findChar(false, false, position, CString(STR("adsfdsa")), STR('s')));
    UT_ASSERT_EQUAL(position, 2);
    UT_ASSERT(NAlgorithms::NString::findChar(false, true, position, CString(STR("adsfdsa")), STR('S')));
    UT_ASSERT_EQUAL(position, 2);
    UT_ASSERT(NAlgorithms::NString::findChar(true, false, position, CString(STR("adsfdsa")), STR('s')));
    UT_ASSERT_EQUAL(position, 5);
    UT_ASSERT(NAlgorithms::NString::findChar(true, true, position, CString(STR("adsfdsa")), STR('S')));
    UT_ASSERT_EQUAL(position, 5);

    // Testing of the 'findCharOneOf()' algorithm.
    UT_ASSERT(!NAlgorithms::NString::findCharOneOf(false, false, position, CString(STR("adsfdsa")), CString(STR("xzy"))));
    UT_ASSERT(NAlgorithms::NString::findCharOneOf(false, false, position, CString(STR("adszdsa")), CString(STR("xzy"))));
    UT_ASSERT_EQUAL(position, 3);
    UT_ASSERT(NAlgorithms::NString::findCharOneOf(false, true, position, CString(STR("adszdsa")), CString(STR("XZY"))));
    UT_ASSERT_EQUAL(position, 3);
    UT_ASSERT(NAlgorithms::NString::findCharOneOf(true, false, position, CString(STR("adszdsa")), CString(STR("xzy"))));
    UT_ASSERT_EQUAL(position, 3);
    UT_ASSERT(NAlgorithms::NString::findCharOneOf(true, true, position, CString(STR("adszdsa")), CString(STR("XZY"))));
    UT_ASSERT_EQUAL(position, 3);

    Tuint position1;
    Tuint position2;

    // Testing of the 'findString()' algorithm.
    UT_ASSERT(!NAlgorithms::NString::findString(false, false, position1, position2, CString(STR("adsfdsa")), CString(STR("sad"))));
    UT_ASSERT(NAlgorithms::NString::findString(false, false, position1, position2, CString(STR("adszdsa")), CString(STR("ads"))));
    UT_ASSERT_EQUAL(position1, 0);
    UT_ASSERT_EQUAL(position2, 2);
    UT_ASSERT(NAlgorithms::NString::findString(false, false, position1, position2, CString(STR("adszdsa")), CString(STR("szd"))));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT(NAlgorithms::NString::findString(false, false, position1, position2, CString(STR("adszdsa")), 2, 3, CString(STR("szd")), 0, 3));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT(NAlgorithms::NString::findString(false, false, position1, position2, CString(STR("adszdsa")), 2, 3, CString(STR("szd")), 1, 1));
    UT_ASSERT_EQUAL(position1, 3);
    UT_ASSERT_EQUAL(position2, 3);
    UT_ASSERT(!NAlgorithms::NString::findString(true, false, position1, position2, CString(STR("adsfdsa")), CString(STR("sad"))));
    UT_ASSERT(NAlgorithms::NString::findString(true, false, position1, position2, CString(STR("adszdsa")), CString(STR("ads"))));
    UT_ASSERT_EQUAL(position1, 0);
    UT_ASSERT_EQUAL(position2, 2);
    UT_ASSERT(NAlgorithms::NString::findString(true, false, position1, position2, CString(STR("adszdsa")), CString(STR("szd"))));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT(NAlgorithms::NString::findString(true, false, position1, position2, CString(STR("adszdsa")), 5, 5, CString(STR("szd")), 0, 3));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT(NAlgorithms::NString::findString(true, false, position1, position2, CString(STR("adszdsa")), 5, 5, CString(STR("szd")), 1, 1));
    UT_ASSERT_EQUAL(position1, 3);
    UT_ASSERT_EQUAL(position2, 3);
    UT_ASSERT(!NAlgorithms::NString::findString(false, false, position1, position2, CString(STR("adsfdsa")), CString(STR("sFd"))));
    UT_ASSERT(NAlgorithms::NString::findString(false, true, position1, position2, CString(STR("adsfdsa")), CString(STR("sFd"))));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);

    CString source;

    // Testing of the 'removeString()' algorithm.
    UT_ASSERT(source.set(STR("adsfdsa")));
    UT_ASSERT(!NAlgorithms::NString::removeString(false, false, position1, position2, source, CString(STR("sad"))));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeString(false, false, position1, position2, source, CString(STR("ads"))));
    UT_ASSERT_EQUAL(position1, 0);
    UT_ASSERT_EQUAL(position2, 2);
    UT_ASSERT_EQUAL(source, CString(STR("zdsa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeString(false, false, position1, position2, source, CString(STR("szd"))));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT_EQUAL(source, CString(STR("adsa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeString(false, false, position1, position2, source, 2, 3, CString(STR("szd")), 0, 3));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT_EQUAL(source, CString(STR("adsa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeString(false, false, position1, position2, source, 2, 3, CString(STR("szd")), 1, 1));
    UT_ASSERT_EQUAL(position1, 3);
    UT_ASSERT_EQUAL(position2, 3);
    UT_ASSERT_EQUAL(source, CString(STR("adsdsa")));
    UT_ASSERT(source.set(STR("adsfdsa")));
    UT_ASSERT(!NAlgorithms::NString::removeString(true, false, position1, position2, source, CString(STR("sad"))));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeString(true, false, position1, position2, source, CString(STR("ads"))));
    UT_ASSERT_EQUAL(position1, 0);
    UT_ASSERT_EQUAL(position2, 2);
    UT_ASSERT_EQUAL(source, CString(STR("zdsa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeString(true, false, position1, position2, source, CString(STR("szd"))));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT_EQUAL(source, CString(STR("adsa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeString(true, false, position1, position2, source, 5, 5, CString(STR("szd")), 0, 3));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT_EQUAL(source, CString(STR("adsa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeString(true, false, position1, position2, source, 5, 5, CString(STR("szd")), 1, 1));
    UT_ASSERT_EQUAL(position1, 3);
    UT_ASSERT_EQUAL(position2, 3);
    UT_ASSERT_EQUAL(source, CString(STR("adsdsa")));
    UT_ASSERT(source.set(STR("adsfdsa")));
    UT_ASSERT(!NAlgorithms::NString::removeString(false, false, position1, position2, source, CString(STR("sFd"))));
    UT_ASSERT(source.set(STR("adsfdsa")));
    UT_ASSERT(NAlgorithms::NString::removeString(false, true, position1, position2, source, CString(STR("sFd"))));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT_EQUAL(source, CString(STR("adsa")));

    // Testing of the 'removeStringAll()' algorithm.
    UT_ASSERT(source.set(STR("adsfdsaadsfdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(false, false, source, CString(STR("sad"))));
    UT_ASSERT_EQUAL(source, CString(STR("adsfdsaadsfdsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(false, false, source, CString(STR("ads"))));
    UT_ASSERT_EQUAL(source, CString(STR("zdsazdsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(false, false, source, CString(STR("szd"))));
    UT_ASSERT_EQUAL(source, CString(STR("adsaadsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(false, false, source, 9, 3, CString(STR("szd")), 0, 3));
    UT_ASSERT_EQUAL(source, CString(STR("adszdsaadsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(false, false, source, 9, 3, CString(STR("szd")), 1, 1));
    UT_ASSERT_EQUAL(source, CString(STR("adszdsaadsdsa")));
    UT_ASSERT(source.set(STR("adsfdsaadsfdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(true, false, source, CString(STR("sad"))));
    UT_ASSERT_EQUAL(source, CString(STR("adsfdsaadsfdsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(true, false, source, CString(STR("ads"))));
    UT_ASSERT_EQUAL(source, CString(STR("zdsazdsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(true, false, source, CString(STR("szd"))));
    UT_ASSERT_EQUAL(source, CString(STR("adsaadsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(true, false, source, 5, 5, CString(STR("szd")), 0, 3));
    UT_ASSERT_EQUAL(source, CString(STR("adsaadszdsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(true, false, source, 5, 5, CString(STR("szd")), 1, 1));
    UT_ASSERT_EQUAL(source, CString(STR("adsdsaadszdsa")));
    UT_ASSERT(source.set(STR("adsfdsaadsfdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(false, false, source, CString(STR("sFd"))));
    UT_ASSERT_EQUAL(source, CString(STR("adsfdsaadsfdsa")));
    UT_ASSERT(source.set(STR("adsfdsaadsfdsa")));
    UT_ASSERT(NAlgorithms::NString::removeStringAll(false, true, source, CString(STR("sFd"))));
    UT_ASSERT_EQUAL(source, CString(STR("adsaadsa")));

    // Testing of the 'replaceString()' algorithm.
    UT_ASSERT(source.set(STR("adsfdsa")));
    UT_ASSERT(!NAlgorithms::NString::replaceString(false, false, position1, position2, source, CString(STR("sad")), CString(STR("!!!"))));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceString(false, false, position1, position2, source, CString(STR("ads")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(position1, 0);
    UT_ASSERT_EQUAL(position2, 2);
    UT_ASSERT_EQUAL(source, CString(STR("!!!zdsa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceString(false, false, position1, position2, source, CString(STR("szd")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT_EQUAL(source, CString(STR("ad!!!sa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceString(false, false, position1, position2, source, 2, 3, CString(STR("szd")), 0, 3, CString(STR("!!!")), 0, 3));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT_EQUAL(source, CString(STR("ad!!!sa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceString(false, false, position1, position2, source, 2, 3, CString(STR("szd")), 1, 1, CString(STR("!!!")), 0, 3));
    UT_ASSERT_EQUAL(position1, 3);
    UT_ASSERT_EQUAL(position2, 3);
    UT_ASSERT_EQUAL(source, CString(STR("ads!!!dsa")));
    UT_ASSERT(source.set(STR("adsfdsa")));
    UT_ASSERT(!NAlgorithms::NString::replaceString(true, false, position1, position2, source, CString(STR("sad")), CString(STR("!!!"))));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceString(true, false, position1, position2, source, CString(STR("ads")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(position1, 0);
    UT_ASSERT_EQUAL(position2, 2);
    UT_ASSERT_EQUAL(source, CString(STR("!!!zdsa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceString(true, false, position1, position2, source, CString(STR("szd")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT_EQUAL(source, CString(STR("ad!!!sa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceString(true, false, position1, position2, source, 5, 5, CString(STR("szd")), 0, 3, CString(STR("!!!")), 0, 3));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT_EQUAL(source, CString(STR("ad!!!sa")));
    UT_ASSERT(source.set(STR("adszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceString(true, false, position1, position2, source, 5, 5, CString(STR("szd")), 1, 1, CString(STR("!!!")), 0, 3));
    UT_ASSERT_EQUAL(position1, 3);
    UT_ASSERT_EQUAL(position2, 3);
    UT_ASSERT_EQUAL(source, CString(STR("ads!!!dsa")));
    UT_ASSERT(source.set(STR("adsfdsa")));
    UT_ASSERT(!NAlgorithms::NString::replaceString(false, false, position1, position2, source, CString(STR("sFd")), CString(STR("!!!"))));
    UT_ASSERT(source.set(STR("adsfdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceString(false, true, position1, position2, source, CString(STR("sFd")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(position1, 2);
    UT_ASSERT_EQUAL(position2, 4);
    UT_ASSERT_EQUAL(source, CString(STR("ad!!!sa")));

    // Testing of the 'replaceStringAll()' algorithm.
    UT_ASSERT(source.set(STR("adsfdsaadsfdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(false, false, source, CString(STR("sad")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(source, CString(STR("adsfdsaadsfdsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(false, false, source, CString(STR("ads")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(source, CString(STR("!!!zdsa!!!zdsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(false, false, source, CString(STR("szd")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(source, CString(STR("ad!!!saad!!!sa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(false, false, source, 9, 3, CString(STR("szd")), 0, 3, CString(STR("!!!")), 0, 3));
    UT_ASSERT_EQUAL(source, CString(STR("adszdsaad!!!sa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(false, false, source, 9, 3, CString(STR("szd")), 1, 1, CString(STR("!!!")), 0, 3));
    UT_ASSERT_EQUAL(source, CString(STR("adszdsaads!!!dsa")));
    UT_ASSERT(source.set(STR("adsfdsaadsfdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(true, false, source, CString(STR("sad")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(source, CString(STR("adsfdsaadsfdsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(true, false, source, CString(STR("ads")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(source, CString(STR("!!!zdsa!!!zdsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(true, false, source, CString(STR("szd")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(source, CString(STR("ad!!!saad!!!sa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(true, false, source, 5, 5, CString(STR("szd")), 0, 3, CString(STR("!!!")), 0, 3));
    UT_ASSERT_EQUAL(source, CString(STR("ad!!!saadszdsa")));
    UT_ASSERT(source.set(STR("adszdsaadszdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(true, false, source, 5, 5, CString(STR("szd")), 1, 1, CString(STR("!!!")), 0, 3));
    UT_ASSERT_EQUAL(source, CString(STR("ads!!!dsaadszdsa")));
    UT_ASSERT(source.set(STR("adsfdsaadsfdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(false, false, source, CString(STR("sFd")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(source, CString(STR("adsfdsaadsfdsa")));
    UT_ASSERT(source.set(STR("adsfdsaadsfdsa")));
    UT_ASSERT(NAlgorithms::NString::replaceStringAll(false, true, source, CString(STR("sFd")), CString(STR("!!!"))));
    UT_ASSERT_EQUAL(source, CString(STR("ad!!!saad!!!sa")));

    // Testing of the 'stringLength()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringLength(ASC("adsfdsa")), 7);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringLength(CStringASCII(ASC("adsfdsa"))), 7);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringLength(UNC("adsfdsa")), 7);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringLength(CStringUnicode(UNC("adsfdsa"))), 7);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringLength(STR("adsfdsa")), 7);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringLength(CString(STR("adsfdsa"))), 7);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringLength(CString(STR("adsfdsa")), 5), 5);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringLength(CString(STR("adsfdsa")), 2, 3), 3);

    // Testing of the 'stringSize()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringSize(ASC("adsfdsa")), 7 * sizeof(Tschar));
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringSize(CStringASCII(ASC("adsfdsa"))), 7 * sizeof(Tschar));
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringSize(UNC("adsfdsa")), 7 * sizeof(Twchar));
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringSize(CStringUnicode(UNC("adsfdsa"))), 7 * sizeof(Twchar));
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringSize(STR("adsfdsa")), 7 * sizeof(Tchar));
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringSize(CString(STR("adsfdsa"))), 7 * sizeof(Tchar));
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringSize(CString(STR("adsfdsa")), 5 * sizeof(Tchar)), 5 * sizeof(Tchar));
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringSize(CString(STR("adsfdsa")), 2, 3 * sizeof(Tchar)), 3 * sizeof(Tchar));

    // Testing of the 'stringCompare()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCompare(CString(STR("adsfdsa")), CString::EMPTY), +7);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCompare(CString::EMPTY, CString(STR("adsfdsa"))), -7);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCompare(CString(STR("adsFdsa")), CString(STR("adsfdsa"))), -32);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCompare(CString(STR("adsfdsa")), CString(STR("adsFdsa"))), +32);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCompare(CString(STR("adsfdsa")), CString(STR("adsfdsa"))), 0);

    // Testing of the 'stringCompareIgnoreCase()' algorithm.
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCompareIgnoreCase(CString(STR("adsfdsa")), CString::EMPTY), +7);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCompareIgnoreCase(CString::EMPTY, CString(STR("adsfdsa"))), -7);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCompareIgnoreCase(CString(STR("adsFdsa")), CString(STR("adsfdsa"))), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCompareIgnoreCase(CString(STR("adsfdsa")), CString(STR("adsFdsa"))), 0);
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCompareIgnoreCase(CString(STR("adsfdsa")), CString(STR("adsfdsa"))), 0);

    // Testing of the 'stringCopy()' algorithm.
    CString copy(STR("zzzzzzz"));
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCopy(copy, CString(STR("adszdsa"))), 7);
    UT_ASSERT_EQUAL(copy, CString(STR("adszdsa")));
    UT_ASSERT_EQUAL(NAlgorithms::NString::stringCopy(copy, 2, 3, CString(STR("yyzzzyy")), 0, 7), 3);
    UT_ASSERT_EQUAL(copy, CString(STR("adyyzsa")));

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
