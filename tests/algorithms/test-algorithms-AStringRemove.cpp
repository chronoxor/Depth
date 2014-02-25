/*!
 *  \file    test-algorithms-AStringRemove.cpp Testing of the string remove
 *           algorithms.
 *  \brief   Testing of the string remove algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the string remove algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   12.01.2010 03:59:47

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
#include <Depth/include/algorithms/string/AStringRemove.hpp>
#include <Depth/include/algorithms/string/AStringRemoveAll.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchBruteForce.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchKarpRabin.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchMorrisPratt.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchKnuthMorrisPratt.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchApostolicoCrochemore.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchNotSoNaive.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchBoyerMoore.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchTunedBM.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchTurboBM.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchApostolicoGiancarlo.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchHorspool.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchQuickSearch.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchSmith.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchRaita.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchDFA.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchOneOf.hpp>
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
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchBruteForce<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchBruteForce<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchKarpRabin<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchKarpRabin<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchMorrisPratt<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchMorrisPratt<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchKnuthMorrisPratt<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchKnuthMorrisPratt<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchApostolicoCrochemore<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchApostolicoCrochemore<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchNotSoNaive<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchNotSoNaive<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchBoyerMoore<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchBoyerMoore<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchTunedBM<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchTunedBM<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchTurboBM<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchTurboBM<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchApostolicoGiancarlo<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchApostolicoGiancarlo<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchHorspool<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchHorspool<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchQuickSearch<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchQuickSearch<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchSmith<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchSmith<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchRaita<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchRaita<CString>(true), true));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchDFA<CString>(false), false));
    UT_ASSERT(remove(NAlgorithms::NString::NSearch::CStringSearchDFA<CString>(true), true));

    UT_ACCEPT;
  }

  // Perform testing of the string remove functionality with the given algorithm.
  template <typename T_StringSearchAlgorithm>
  static Tbool remove(T_StringSearchAlgorithm a_StringSearchAlgorithm, const Tbool a_cIgnoreCase)
  { CALL
    Tuint start, end;
    CString source, pattern;

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("sad"));
    UT_ASSERT(!NAlgorithms::NString::stringRemoveNext(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("ads"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveNext(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 0);
    UT_ASSERT_EQUAL(end, 2);
    UT_ASSERT_EQUAL(source, CString(STR("zdsa")));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("aDs"));
    UT_ASSERT(!a_cIgnoreCase || NAlgorithms::NString::stringRemoveNext(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveNext(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 4);
    UT_ASSERT_EQUAL(source, CString(STR("adsa")));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveNext(start, end, source, 2, 3, pattern, 0, 3, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 4);
    UT_ASSERT_EQUAL(source, CString(STR("adsa")));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveNext(start, end, source, 2, 3, pattern, 1, 1, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 3);
    UT_ASSERT_EQUAL(end, 3);
    UT_ASSERT_EQUAL(source, CString(STR("adsdsa")));

    source = CString(STR("adszdsaadszdsa"));
    pattern = CString(STR("s"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllNext(source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(source, CString(STR("adzdaadzda")));

    source = CString(STR("adszdsaadszdsa"));
    pattern = CString(STR("sz"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllNext(source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(source, CString(STR("addsaaddsa")));

    source = CString(STR("adszdsaadszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllNext(source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(source, CString(STR("adsaadsa")));

    source = CString(STR("adszdsaadszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllNext(source, 2, 3, pattern, 0, 3, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(source, CString(STR("adsaadszdsa")));

    source = CString(STR("adszdsaadszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllNext(source, 7, 7, pattern, 1, 1, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(source, CString(STR("adszdsaadsdsa")));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("sad"));
    UT_ASSERT(!NAlgorithms::NString::stringRemovePrev(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("ads"));
    UT_ASSERT(NAlgorithms::NString::stringRemovePrev(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 0);
    UT_ASSERT_EQUAL(end, 2);
    UT_ASSERT_EQUAL(source, CString(STR("zdsa")));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("aDs"));
    UT_ASSERT(!a_cIgnoreCase || NAlgorithms::NString::stringRemovePrev(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemovePrev(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 4);
    UT_ASSERT_EQUAL(source, CString(STR("adsa")));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemovePrev(start, end, source, 5, 5, pattern, 0, 3, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 4);
    UT_ASSERT_EQUAL(source, CString(STR("adsa")));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemovePrev(start, end, source, 5, 5, pattern, 1, 1, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 3);
    UT_ASSERT_EQUAL(end, 3);
    UT_ASSERT_EQUAL(source, CString(STR("adsdsa")));

    source = CString(STR("adszdsaadszdsa"));
    pattern = CString(STR("s"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllPrev(source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(source, CString(STR("adzdaadzda")));

    source = CString(STR("adszdsaadszdsa"));
    pattern = CString(STR("sz"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllPrev(source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(source, CString(STR("addsaaddsa")));

    source = CString(STR("adszdsaadszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllPrev(source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(source, CString(STR("adsaadsa")));

    source = CString(STR("adszdsaadszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllPrev(source, 4, 3, pattern, 0, 3, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(source, CString(STR("adsaadszdsa")));

    source = CString(STR("adszdsaadszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllPrev(source, 12, 5, pattern, 1, 1, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(source, CString(STR("adszdsaadsdsa")));

    // Perform remove one of...
    UT_ASSERT(removeOneOf(a_StringSearchAlgorithm, a_cIgnoreCase));

    UT_ACCEPT;
  }

  // Perform testing of the string remove functionality with the given one of algorithm.
  template <typename T_StringSearchAlgorithm>
  static Tbool removeOneOf(T_StringSearchAlgorithm a_StringSearchAlgorithm, const Tbool a_cIgnoreCase)
  { CALL
    IGNORE_UNUSED(a_StringSearchAlgorithm);

    NAlgorithms::NString::NSearch::CStringSearchOneOf<CString, CString, T_StringSearchAlgorithm> algorithm(a_cIgnoreCase);

    UT_ASSERT(algorithm.getPatterns().insertLast(STR("abc")));
    UT_ASSERT(algorithm.getPatterns().insertLast(STR("ab")));
    UT_ASSERT(algorithm.getPatterns().insertLast(STR("bc")));
    UT_ASSERT(algorithm.getPatterns().insertLast(STR("a")));

    CString source, pattern;

    UT_ASSERT(pattern.set(STR("_")));

    UT_ASSERT(source.set(STR("_abcxyzaxyzabxyz_abc_xyzabxyzaxyzabc_")));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllNext(source, pattern, algorithm));
    UT_ASSERT_EQUAL(source, CString(STR("xyzxyzbxyzxyzbxyzxyz")));

    UT_ASSERT(source.set(STR("_abcxyzaxyzabxyz_abc_xyzabxyzaxyzabc_")));
    UT_ASSERT(NAlgorithms::NString::stringRemoveAllPrev(source, pattern, algorithm));
    UT_ASSERT_EQUAL(source, CString(STR("xyzxyzxyzxyzxyzxyz")));

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
