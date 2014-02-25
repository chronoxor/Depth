/*!
 *  \file    test-algorithms-AStringSearch.cpp Testing of the string search
 *           algorithms.
 *  \brief   Testing of the string search algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the string search algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   06.01.2010 20:13:27

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
#include <Depth/include/algorithms/string/AStringSearch.hpp>
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
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchBruteForce<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchBruteForce<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchKarpRabin<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchKarpRabin<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchMorrisPratt<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchMorrisPratt<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchKnuthMorrisPratt<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchKnuthMorrisPratt<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchApostolicoCrochemore<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchApostolicoCrochemore<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchNotSoNaive<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchNotSoNaive<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchBoyerMoore<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchBoyerMoore<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchTunedBM<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchTunedBM<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchTurboBM<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchTurboBM<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchApostolicoGiancarlo<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchApostolicoGiancarlo<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchHorspool<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchHorspool<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchQuickSearch<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchQuickSearch<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchSmith<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchSmith<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchRaita<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchRaita<CString>(true), true));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchDFA<CString>(false), false));
    UT_ASSERT(search(NAlgorithms::NString::NSearch::CStringSearchDFA<CString>(true), true));

    UT_ACCEPT;
  }

  // Perform testing of the string searching functionality with the given algorithm.
  template <typename T_StringSearchAlgorithm>
  static Tbool search(T_StringSearchAlgorithm a_StringSearchAlgorithm, const Tbool a_cIgnoreCase)
  { CALL
    Tuint start, end;
    CString source, pattern;

    start = end = 0;
    source = CString(STR("dda"));
    pattern = CString(STR("zs"));
    UT_ASSERT(!NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("sad"));
    UT_ASSERT(!NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("ads"));
    UT_ASSERT(NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 0);
    UT_ASSERT_EQUAL(end, 2);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("aDs"));
    UT_ASSERT(!a_cIgnoreCase || NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("z"));
    UT_ASSERT(NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 3);
    UT_ASSERT_EQUAL(end, 3);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("sz"));
    UT_ASSERT(NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 3);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 4);

    start = end = 0;
    source = CString(STR("gcagabcgcagagagabcgagag"));
    pattern = CString(STR("gcagagag"));
    UT_ASSERT(NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 7);
    UT_ASSERT_EQUAL(end, 14);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("Z"));
    UT_ASSERT(!a_cIgnoreCase || NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("SZ"));
    UT_ASSERT(!a_cIgnoreCase || NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("SZD"));
    UT_ASSERT(!a_cIgnoreCase || NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("asdzsda"));
    pattern = CString(STR("dzs"));
    UT_ASSERT(NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 4);

    start = end = 0;
    source = CString(STR("adssdssda"));
    pattern = CString(STR("ssdss"));
    UT_ASSERT(NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 6);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringSearchNext(start, end, source, 2, 3, pattern, 0, 3, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 4);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringSearchNext(start, end, source, 2, 3, pattern, 1, 1, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 3);
    UT_ASSERT_EQUAL(end, 3);

    start = end = 0;
    source = CString(STR("addsaaddsa"));
    pattern = CString(STR("sz"));
    UT_ASSERT(!NAlgorithms::NString::stringSearchNext(start, end, source, 0, 3, pattern, 0, 2, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("add"));
    pattern = CString(STR("sz"));
    UT_ASSERT(!NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("sad"));
    UT_ASSERT(!NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("ads"));
    UT_ASSERT(NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 0);
    UT_ASSERT_EQUAL(end, 2);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("aDs"));
    UT_ASSERT(!a_cIgnoreCase || NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("z"));
    UT_ASSERT(NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 3);
    UT_ASSERT_EQUAL(end, 3);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("sz"));
    UT_ASSERT(NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 3);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 4);

    start = end = 0;
    source = CString(STR("gcagabcgcagagagabcgagag"));
    pattern = CString(STR("gcagagag"));
    UT_ASSERT(NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 7);
    UT_ASSERT_EQUAL(end, 14);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("Z"));
    UT_ASSERT(!a_cIgnoreCase || NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("SZ"));
    UT_ASSERT(!a_cIgnoreCase || NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("SZD"));
    UT_ASSERT(!a_cIgnoreCase || NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));

    start = end = 0;
    source = CString(STR("asdzsda"));
    pattern = CString(STR("dzs"));
    UT_ASSERT(NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 4);

    start = end = 0;
    source = CString(STR("adssdssda"));
    pattern = CString(STR("ssdss"));
    UT_ASSERT(NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 6);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringSearchPrev(start, end, source, 5, 5, pattern, 0, 3, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 2);
    UT_ASSERT_EQUAL(end, 4);

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("szd"));
    UT_ASSERT(NAlgorithms::NString::stringSearchPrev(start, end, source, 5, 5, pattern, 1, 1, a_StringSearchAlgorithm));
    UT_ASSERT_EQUAL(start, 3);
    UT_ASSERT_EQUAL(end, 3);

    start = end = 0;
    source = CString(STR("addsaaddsa"));
    pattern = CString(STR("sz"));
    UT_ASSERT(!NAlgorithms::NString::stringSearchPrev(start, end, source, 2, 3, pattern, 0, 2, a_StringSearchAlgorithm));

    // Perform search one of...
    UT_ASSERT(searchOneOf(a_StringSearchAlgorithm, a_cIgnoreCase));

    UT_ACCEPT;
  }

  // Perform testing of the string searching functionality with the given one of algorithm.
  template <typename T_StringSearchAlgorithm>
  static Tbool searchOneOf(T_StringSearchAlgorithm a_StringSearchAlgorithm, const Tbool a_cIgnoreCase)
  { CALL
    IGNORE_UNUSED(a_StringSearchAlgorithm);

    Tuint forward[][2] =
    {
      {  0,  0 },
      {  1,  1 },
      {  2,  3 },
      {  7,  7 },
      { 11, 11 },
      { 16, 16 },
      { 17, 17 },
      { 18, 19 },
      { 20, 20 },
      { 24, 24 },
      { 29, 29 },
      { 33, 33 },
      { 34, 35 },
      { 36, 36 }
    };
    Tuint backward[][2] =
    {
      { 36, 36 },
      { 34, 35 },
      { 33, 34 },
      { 33, 33 },
      { 29, 29 },
      { 24, 25 },
      { 24, 24 },
      { 20, 20 },
      { 18, 19 },
      { 17, 18 },
      { 17, 17 },
      { 16, 16 },
      { 11, 12 },
      { 11, 11 },
      {  7,  7 },
      {  2,  3 },
      {  1,  2 },
      {  1,  1 },
      {  0,  0 }
    };

    NAlgorithms::NString::NSearch::CStringSearchOneOf<CString, CString, T_StringSearchAlgorithm> algorithm(a_cIgnoreCase);

    UT_ASSERT(algorithm.getPatterns().insertLast(STR("abc")));
    UT_ASSERT(algorithm.getPatterns().insertLast(STR("ab")));
    UT_ASSERT(algorithm.getPatterns().insertLast(STR("bc")));
    UT_ASSERT(algorithm.getPatterns().insertLast(STR("a")));

    Tuint f = 0, b = 0;
    Tuint start, end;
    CString source, pattern;

    UT_ASSERT(source.set(STR("_abcxyzaxyzabxyz_abc_xyzabxyzaxyzabc_")));
    UT_ASSERT(pattern.set(STR("_")));

    start = end = 0;
    while (end + 1 < source.getSize())
    {
      UT_ASSERT(NAlgorithms::NString::stringSearchNext(start, end, source, end, source.getSize() - end, pattern, 0, pattern.getSize(), algorithm));
      UT_ASSERT_EQUAL(start, forward[f][0]);
      UT_ASSERT_EQUAL(end, forward[f][1]);
      ++start;
      ++end;
      ++f;
    }

    start = end = source.getSize();
    while (end > 0)
    {
      --start;
      --end;
      UT_ASSERT(NAlgorithms::NString::stringSearchPrev(start, end, source, end, end + 1, pattern, 0, pattern.getSize(), algorithm));
      UT_ASSERT_EQUAL(start, backward[b][0]);
      UT_ASSERT_EQUAL(end, backward[b][1]);
      ++b;
    }

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
