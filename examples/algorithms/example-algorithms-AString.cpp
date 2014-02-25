/*!
 *  \file    example-algorithms-AString.cpp Example of using the string 
 *           algorithms.
 *  \brief   Example of using the string algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the string algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   28.03.2008 02:39:24

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
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
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
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    // Example of the usage of the 'strlen()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strLen(\"asdf\") = ") << NAlgorithms::NString::NBuffer::strLen("asdf") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strLen(L\"asdf\") = ") << NAlgorithms::NString::NBuffer::strLen(L"asdf") << ln;
    // Example of the usage of the 'strnlen()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNLen(\"asdf\", 3) = ") << NAlgorithms::NString::NBuffer::strNLen("asdf", 3) << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNLen(L\"asdf\", 3) = ") << NAlgorithms::NString::NBuffer::strNLen(L"asdf", 3) << ln;

    // Example of the usage of the 'strcmp()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strCmp(\"asdf\", \"asdf\") = ") << NAlgorithms::NString::NBuffer::strCmp("asdf", "asdf") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strCmp(\"asdfghjkl\", \"asdf\") = ") << NAlgorithms::NString::NBuffer::strCmp("asdfghjkl", "asdf") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strCmp(L\"asdf\", L\"asdf\") = ") << NAlgorithms::NString::NBuffer::strCmp(L"asdf", L"asdf") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strCmp(L\"asdfghjkl\", L\"asdf\") = ") << NAlgorithms::NString::NBuffer::strCmp(L"asdfghjkl", L"asdf") << ln;
    // Example of the usage of the 'strncmp()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNCmp(\"asdf\", \"asdf\", 3) = ") << NAlgorithms::NString::NBuffer::strNCmp("asdf", "asdf", 3) << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNCmp(L\"asdf\", L\"asdf\", 3) = ") << NAlgorithms::NString::NBuffer::strNCmp(L"asdf", L"asdf", 3) << ln;

    // Example of the usage of the 'stricmp()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strICmp(\"aSdF\", \"asDf\") = ") << NAlgorithms::NString::NBuffer::strICmp("aSdF", "asDf") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strICmp(\"aSdFgHjKl\", \"asDf\") = ") << NAlgorithms::NString::NBuffer::strICmp("aSdFgHjKl", "asDf") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strICmp(L\"aSdF\", L\"asDf\") = ") << NAlgorithms::NString::NBuffer::strICmp(L"aSdF", L"asDf") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strICmp(L\"aSdFgHjKl\", L\"asDf\") = ") << NAlgorithms::NString::NBuffer::strICmp(L"aSdFgHjKl", L"asDf") << ln;
    // Example of the usage of the 'strnicmp()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNICmp(\"aSdF\", \"asDf\", 3) = ") << NAlgorithms::NString::NBuffer::strNICmp("aSdF", "asDf", 3) << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNICmp(L\"aSdF\", L\"asDf\", 3) = ") << NAlgorithms::NString::NBuffer::strNICmp(L"aSdF", L"asDf", 3) << ln;

    // Example of the usage of the 'strbrk()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strBrk(\"asdf\", \"wsx\") = ") << NAlgorithms::NString::NBuffer::strBrk("asdf", "wsx") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strBrk(L\"asdf\", L\"wsx\") = ") << NAlgorithms::NString::NBuffer::strBrk(L"asdf", L"wsx") << ln;
    // Example of the usage of the 'strnbrk()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNBrk(\"asdf\", 3, \"wsx\") = ") << NAlgorithms::NString::NBuffer::strNBrk("asdf", 3, "wsx") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNBrk(L\"asdf\", 3, L\"wsx\") = ") << NAlgorithms::NString::NBuffer::strNBrk(L"asdf", 3, L"wsx") << ln;

    // Example of the usage of the 'strchr()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strChr(\"asdf\", 'd') = ") << NAlgorithms::NString::NBuffer::strChr("asdf", 'd') << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strChr(L\"asdf\", L'd') = ") << NAlgorithms::NString::NBuffer::strChr(L"asdf", L'd') << ln;
    // Example of the usage of the 'strnchr()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNChr(\"asdf\", 3, 'd') = ") << NAlgorithms::NString::NBuffer::strNChr("asdf", 3, 'd') << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNChr(L\"asdf\", 3, L'd') = ") << NAlgorithms::NString::NBuffer::strNChr(L"asdf", 3, L'd') << ln;

    // Example of the usage of the 'strrchr()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strRChr(\"asdf asdf asdf\", 'd') = ") << NAlgorithms::NString::NBuffer::strRChr("asdf asdf asdf", 'd') << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strRChr(L\"asdf asdf asdf\", L'd') = ") << NAlgorithms::NString::NBuffer::strRChr(L"asdf asdf asdf", L'd') << ln;
    // Example of the usage of the 'strnrchr()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNRChr(\"asdf asdf asdf\", 6, 'd') = ") << NAlgorithms::NString::NBuffer::strNRChr("asdf asdf asdf", 6, 'd') << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNRChr(L\"asdf asdf asdf\", 6, L'd') = ") << NAlgorithms::NString::NBuffer::strNRChr(L"asdf asdf asdf", 6, L'd') << ln;

    // Example of the usage of the 'strspn()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strSpn(\"asdfghjkl\", \"asdf\") = ") << NAlgorithms::NString::NBuffer::strSpn("asdfghjkl", "asdf") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strSpn(L\"asdfghjkl\", L\"asdf\") = ") << NAlgorithms::NString::NBuffer::strSpn(L"asdfghjkl", L"asdf") << ln;
    // Example of the usage of the 'strnspn()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNSpn(\"asdfghjkl\", 2, \"asdf\") = ") << NAlgorithms::NString::NBuffer::strNSpn("asdfghjkl", 2, "asdf") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNSpn(L\"asdfghjkl\", 2, L\"asdf\") = ") << NAlgorithms::NString::NBuffer::strNSpn(L"asdfghjkl", 2, L"asdf") << ln;

    // Example of the usage of the 'strcspn()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strCSpn(\"asdfghjkl\", \"ghjk\") = ") << NAlgorithms::NString::NBuffer::strCSpn("asdfghjkl", "ghjk") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strCSpn(L\"asdfghjkl\", L\"ghjk\") = ") << NAlgorithms::NString::NBuffer::strCSpn(L"asdfghjkl", L"ghjk") << ln;
    // Example of the usage of the 'strncspn()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNCSpn(\"asdfghjkl\", 2, \"ghjk\") = ") << NAlgorithms::NString::NBuffer::strNCSpn("asdfghjkl", 2, "ghjk") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNCSpn(L\"asdfghjkl\", 2, L\"ghjk\") = ") << NAlgorithms::NString::NBuffer::strNCSpn(L"asdfghjkl", 2, L"ghjk") << ln;

    // Example of the usage of the 'strstr()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strStr(\"asdfghjkl\", \"fgh\") = ") << NAlgorithms::NString::NBuffer::strStr("asdfghjkl", "fgh") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strStr(L\"asdfghjkl\", L\"fgh\") = ") << NAlgorithms::NString::NBuffer::strStr(L"asdfghjkl", L"fgh") << ln;
    // Example of the usage of the 'strnstr()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNStr(\"asdfghjkl\", 3, \"fgh\") = ") << NAlgorithms::NString::NBuffer::strNStr("asdfghjkl", 3, "fgh") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNStr(L\"asdfghjkl\", 3, L\"fgh\") = ") << NAlgorithms::NString::NBuffer::strNStr(L"asdfghjkl", 3, L"fgh") << ln;

    // Example of the usage of the 'strrstr()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strRStr(\"asdfghjkl asdfghjkl asdfghjkl\", \"fgh\") = ") << NAlgorithms::NString::NBuffer::strRStr("asdfghjkl asdfghjkl asdfghjkl", "fgh") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strRStr(L\"asdfghjkl asdfghjkl asdfghjkl\", L\"fgh\") = ") << NAlgorithms::NString::NBuffer::strRStr(L"asdfghjkl asdfghjkl asdfghjkl", L"fgh") << ln;
    // Example of the usage of the 'strnrstr()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNRStr(\"asdfghjkl asdfghjkl asdfghjkl\", 20, \"fgh\") = ") << NAlgorithms::NString::NBuffer::strNRStr("asdfghjkl asdfghjkl asdfghjkl", 20, "fgh") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNRStr(L\"asdfghjkl asdfghjkl asdfghjkl\", 20, L\"fgh\") = ") << NAlgorithms::NString::NBuffer::strNRStr(L"asdfghjkl asdfghjkl asdfghjkl", 20, L"fgh") << ln;

    Tschar dstASCII[256];
    Twchar dstUnicode[256];

    // Example of the usage of the 'strcpy()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strCpy(dstASCII, \"asdfghjkl\") = ") << NAlgorithms::NString::NBuffer::strCpy(dstASCII, "asdfghjkl") << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strCpy(dstUnicode, L\"asdfghjkl\") = ") << NAlgorithms::NString::NBuffer::strCpy(dstUnicode, L"asdfghjkl") << ln;
    // Example of the usage of the 'strncpy()' algorithm.
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNCpy(dstASCII, \"asdfghjkl\", 4) = ") << NAlgorithms::NString::NBuffer::strNCpy(dstASCII, "asdfghjkl", 4) << ln;
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNCpy(dstUnicode, L\"asdfghjkl\", 4) = ") << NAlgorithms::NString::NBuffer::strNCpy(dstUnicode, L"asdfghjkl", 4) << ln;

    // Example of the usage of the 'strcat()' algorithm.
    NAlgorithms::NString::NBuffer::strCpy(dstASCII, "asdfghjkl");
    stdoutput << STR("NAlgorithms::NString::NBuffer::strCat(dstASCII, \"asdfghjkl\") = ") << NAlgorithms::NString::NBuffer::strCat(dstASCII, "asdfghjkl") << ln;
    NAlgorithms::NString::NBuffer::strCpy(dstUnicode, "asdfghjkl");
    stdoutput << STR("NAlgorithms::NString::NBuffer::strCat(dstUnicode, L\"asdfghjkl\") = ") << NAlgorithms::NString::NBuffer::strCat(dstUnicode, L"asdfghjkl") << ln;
    // Example of the usage of the 'strncat()' algorithm.
    NAlgorithms::NString::NBuffer::strCpy(dstASCII, "asdfghjkl");
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNCat(dstASCII, \"asdfghjkl\", 4) = ") << NAlgorithms::NString::NBuffer::strNCat(dstASCII, "asdfghjkl", 4) << ln;
    NAlgorithms::NString::NBuffer::strCpy(dstUnicode, "asdfghjkl");
    stdoutput << STR("NAlgorithms::NString::NBuffer::strNCat(dstUnicode, L\"asdfghjkl\", 4) = ") << NAlgorithms::NString::NBuffer::strNCat(dstUnicode, L"asdfghjkl", 4) << ln;

    Tuint position;

    // Example of the usage of the 'findChar()' algorithm.
    NAlgorithms::NString::findChar(false, false, position, CString(STR("adsfdsa")), STR('s'));
    stdoutput << STR("NAlgorithms::NString::findChar(false, false, position, CString(STR(\"adsfdsa\")), STR('s')) = ") << position << ln;
    NAlgorithms::NString::findChar(false, true, position, CString(STR("adsfdsa")), STR('S'));
    stdoutput << STR("NAlgorithms::NString::findChar(false, true, position, CString(STR(\"adsfdsa\")), STR('S')) = ") << position << ln;
    NAlgorithms::NString::findChar(true, false, position, CString(STR("adsfdsa")), STR('s'));
    stdoutput << STR("NAlgorithms::NString::findChar(true, false, position, CString(STR(\"adsfdsa\")), STR('s')) = ") << position << ln;
    NAlgorithms::NString::findChar(true, true, position, CString(STR("adsfdsa")), STR('S'));
    stdoutput << STR("NAlgorithms::NString::findChar(true, true, position, CString(STR(\"adsfdsa\")), STR('S')) = ") << position << ln;

    // Example of the usage of the 'findCharOneOf()' algorithm.
    NAlgorithms::NString::findCharOneOf(false, false, position, CString(STR("adszdsa")), CString(STR("xzy")));
    stdoutput << STR("NAlgorithms::NString::findCharOneOf(false, false, position, CString(STR(\"adszdsa\")), CString(STR(\"xzy\"))) = ") << position << ln;
    NAlgorithms::NString::findCharOneOf(false, true, position, CString(STR("adszdsa")), CString(STR("XZY")));
    stdoutput << STR("NAlgorithms::NString::findCharOneOf(false, true, position, CString(STR(\"adszdsa\")), CString(STR(\"XZY\"))) = ") << position << ln;
    NAlgorithms::NString::findCharOneOf(true, false, position, CString(STR("adszdsa")), CString(STR("xzy")));
    stdoutput << STR("NAlgorithms::NString::findCharOneOf(true, false, position, CString(STR(\"adszdsa\")), CString(STR(\"xzy\"))) = ") << position << ln;
    NAlgorithms::NString::findCharOneOf(true, true, position, CString(STR("adszdsa")), CString(STR("XZY")));
    stdoutput << STR("NAlgorithms::NString::findCharOneOf(true, true, position, CString(STR(\"adszdsa\")), CString(STR(\"XZY\"))) = ") << position << ln;

    Tuint position1;
    Tuint position2;

    // Example of the usage of the 'findString()' algorithm.
    NAlgorithms::NString::findString(false, false, position1, position2, CString(STR("adszdsa")), CString(STR("sz")));
    stdoutput << STR("NAlgorithms::NString::findString(false, false, position1, position2, CString(STR(\"adszdsa\")), CString(STR(\"sz\"))) = ") << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;
    NAlgorithms::NString::findString(false, true, position1, position2, CString(STR("adszdsa")), CString(STR("sZ")));
    stdoutput << STR("NAlgorithms::NString::findString(false, true, position1, position2, CString(STR(\"adszdsa\")), CString(STR(\"sZ\"))) = ") << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;
    NAlgorithms::NString::findString(true, false, position1, position2, CString(STR("adszdsa")), CString(STR("sz")));
    stdoutput << STR("NAlgorithms::NString::findString(true, false, position1, position2, CString(STR(\"adszdsa\")), CString(STR(\"sz\"))) = ") << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;
    NAlgorithms::NString::findString(true, true, position1, position2, CString(STR("adszdsa")), CString(STR("sZ")));
    stdoutput << STR("NAlgorithms::NString::findString(true, true, position1, position2, CString(STR(\"adszdsa\")), CString(STR(\"sZ\"))) = ") << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;

    CString source;

    // Example of the usage of the 'removeString()' algorithm.
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::removeString(false, false, position1, position2, source, CString(STR("sz")));
    stdoutput << STR("NAlgorithms::NString::removeString(false, false, position1, position2, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sz\"))) = ") << source << STR(' ') << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::removeString(false, true, position1, position2, source, CString(STR("sZ")));
    stdoutput << STR("NAlgorithms::NString::removeString(false, true, position1, position2, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sZ\"))) = ") << source << STR(' ') << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::removeString(true, false, position1, position2, source, CString(STR("sz")));
    stdoutput << STR("NAlgorithms::NString::removeString(true, false, position1, position2, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sz\"))) = ") << source << STR(' ') << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::removeString(true, true, position1, position2, source, CString(STR("sZ")));
    stdoutput << STR("NAlgorithms::NString::removeString(true, true, position1, position2, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sZ\"))) = ") << source << STR(' ') << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;

    // Example of the usage of the 'removeStringAll()' algorithm.
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::removeStringAll(false, false, source, CString(STR("sz")));
    stdoutput << STR("NAlgorithms::NString::removeStringAll(false, false, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sz\"))) = ") << source << STR(' ') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::removeStringAll(false, true, source, CString(STR("sZ")));
    stdoutput << STR("NAlgorithms::NString::removeStringAll(false, true, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sZ\"))) = ") << source << STR(' ') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::removeStringAll(true, false, source, CString(STR("sz")));
    stdoutput << STR("NAlgorithms::NString::removeStringAll(true, false, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sz\"))) = ") << source << STR(' ') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::removeStringAll(true, true, source, CString(STR("sZ")));
    stdoutput << STR("NAlgorithms::NString::removeStringAll(true, true, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sZ\"))) = ") << source << STR(' ') << ln;

    // Example of the usage of the 'replaceString()' algorithm.
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::replaceString(false, false, position1, position2, source, CString(STR("sz")), CString(STR("!!!")));
    stdoutput << STR("NAlgorithms::NString::replaceString(false, false, position1, position2, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sz\")), CString(STR(\"!!!\"))) = ") << source << STR(' ') << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::replaceString(false, true, position1, position2, source, CString(STR("sZ")), CString(STR("!!!")));
    stdoutput << STR("NAlgorithms::NString::replaceString(false, true, position1, position2, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sZ\")), CString(STR(\"!!!\"))) = ") << source << STR(' ') << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::replaceString(true, false, position1, position2, source, CString(STR("sz")), CString(STR("!!!")));
    stdoutput << STR("NAlgorithms::NString::replaceString(true, false, position1, position2, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sz\")), CString(STR(\"!!!\"))) = ") << source << STR(' ') << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::replaceString(true, true, position1, position2, source, CString(STR("sZ")), CString(STR("!!!")));
    stdoutput << STR("NAlgorithms::NString::replaceString(true, true, position1, position2, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sZ\")), CString(STR(\"!!!\"))) = ") << source << STR(' ') << STR('[') << position1 << STR(',') << position2 << STR(']') << ln;

    // Example of the usage of the 'replaceStringAll()' algorithm.
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::replaceStringAll(false, false, source, CString(STR("sz")), CString(STR("!!!")));
    stdoutput << STR("NAlgorithms::NString::replaceStringAll(false, false, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sz\")), CString(STR(\"!!!\"))) = ") << source << STR(' ') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::replaceStringAll(false, true, source, CString(STR("sZ")), CString(STR("!!!")));
    stdoutput << STR("NAlgorithms::NString::replaceStringAll(false, true, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sZ\")), CString(STR(\"!!!\"))) = ") << source << STR(' ') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::replaceStringAll(true, false, source, CString(STR("sz")), CString(STR("!!!")));
    stdoutput << STR("NAlgorithms::NString::replaceStringAll(true, false, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sz\")), CString(STR(\"!!!\"))) = ") << source << STR(' ') << ln;
    source = STR("adszdsaadszdsa");
    NAlgorithms::NString::replaceStringAll(true, true, source, CString(STR("sZ")), CString(STR("!!!")));
    stdoutput << STR("NAlgorithms::NString::replaceStringAll(true, true, CString(STR(\"adszdsaadszdsa\")), CString(STR(\"sZ\")), CString(STR(\"!!!\"))) = ") << source << STR(' ') << ln;

    // Example of the usage of the 'stringLength()' algorithm.
    stdoutput << STR("NAlgorithms::NString::stringLength(STR(\"adszdsa\")) = ") << NAlgorithms::NString::stringLength(STR("adszdsa")) << ln;
    stdoutput << STR("NAlgorithms::NString::stringLength(CString(STR(\"adszdsa\"))) = ") << NAlgorithms::NString::stringLength(CString(STR("adszdsa"))) << ln;
    // Example of the usage of the 'stringSize()' algorithm.
    stdoutput << STR("NAlgorithms::NString::stringSize(STR(\"adszdsa\")) = ") << NAlgorithms::NString::stringSize(STR("adszdsa")) << ln;
    stdoutput << STR("NAlgorithms::NString::stringSize(CString(STR(\"adszdsa\"))) = ") << NAlgorithms::NString::stringSize(CString(STR("adszdsa"))) << ln;

    // Example of the usage of the 'stringCompare()' algorithm.
    stdoutput << STR("NAlgorithms::NString::stringCompare(CString(STR(\"adszdsa\")), STR(\"adszdsa\")) = ") << NAlgorithms::NString::stringCompare(CString(STR("adszdsa")), STR("adszdsa")) << ln;
    stdoutput << STR("NAlgorithms::NString::stringCompare(CString(STR(\"adszdsa\")), STR(\"adsZdsa\")) = ") << NAlgorithms::NString::stringCompare(CString(STR("adszdsa")), STR("adsZdsa")) << ln;
    // Example of the usage of the 'stringCompareIgnoreCase()' algorithm.
    stdoutput << STR("NAlgorithms::NString::stringCompareIgnoreCase(CString(STR(\"adszdsa\")), STR(\"adsZdsa\")) = ") << NAlgorithms::NString::stringCompareIgnoreCase(CString(STR("adszdsa")), STR("adsZdsa")) << ln;

    // Example of the usage of the 'stringCopy()' algorithm.
    CString copy(STR("zzzzzzz"));
    stdoutput << STR("NAlgorithms::NString::stringCopy(copy, STR(\"adszdsa\")) = ") << NAlgorithms::NString::stringCopy(copy, STR("adszdsa")) << STR('[') << copy << STR(']') << ln;
    stdoutput << STR("NAlgorithms::NString::stringCopy(copy, 2, 3, STR(\"yyzzzyy\"), 0, 7) = ") << NAlgorithms::NString::stringCopy(copy, 2, 3, STR("yyzzzyy"), 0, 7) << STR('[') << copy << STR(']') << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
