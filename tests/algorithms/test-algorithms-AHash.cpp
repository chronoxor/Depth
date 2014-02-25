/*!
 *  \file    test-algorithms-AHash.cpp Testing of the hash algorithms.
 *  \brief   Testing of the hash algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the hash algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   10.03.2007 21:47:32

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
#include <Depth/include/algorithms/hash/CHashBOB.hpp>
#include <Depth/include/algorithms/hash/CHashDJB2.hpp>
#include <Depth/include/algorithms/hash/CHashDJB2Ex.hpp>
#include <Depth/include/algorithms/hash/CHashELF.hpp>
#include <Depth/include/algorithms/hash/CHashETH.hpp>
#include <Depth/include/algorithms/hash/CHashGCCcc1.hpp>
#include <Depth/include/algorithms/hash/CHashGCCcpp.hpp>
#include <Depth/include/algorithms/hash/CHashKR.hpp>
#include <Depth/include/algorithms/hash/CHashONEAT.hpp>
#include <Depth/include/algorithms/hash/CHashPCC.hpp>
#include <Depth/include/algorithms/hash/CHashPhong.hpp>
#include <Depth/include/algorithms/hash/CHashSDBM.hpp>
#include <Depth/include/algorithms/hash/CHashTorek.hpp>
#include <Depth/include/algorithms/hash/CHashTorekEx.hpp>
#include <Depth/include/algorithms/hash/CHashWAIS.hpp>
#include <Depth/include/algorithms/hash/CHashWeinberger.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NHash;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CHashBOB        hashBOB;
    CHashDJB2       hashDJB2;
    CHashDJB2Ex     hashDJB2Ex;
    CHashELF        hashELF;
    CHashETH        hashETH;
    CHashGCCcc1     hashGCCcc1;
    CHashGCCcpp     hashGCCcpp;
    CHashKR         hashKR;
    CHashONEAT      hashONEAT;
    CHashPCC        hashPCC;
    CHashPhong      hashPhong;
    CHashSDBM       hashSDBM;
    CHashTorek      hashTorek;
    CHashTorekEx    hashTorekEx;
    CHashWAIS       hashWAIS;
    CHashWeinberger hashWeinberger;

    UT_ASSERT_CHECK_HASH(hashBOB);
    UT_ASSERT_CHECK_HASH(hashDJB2);
    UT_ASSERT_CHECK_HASH(hashDJB2Ex);
    UT_ASSERT_CHECK_HASH(hashELF);
    UT_ASSERT_CHECK_HASH(hashETH);
    UT_ASSERT_CHECK_HASH(hashGCCcc1);
    UT_ASSERT_CHECK_HASH(hashGCCcpp);
    UT_ASSERT_CHECK_HASH(hashKR);
    UT_ASSERT_CHECK_HASH(hashONEAT);
    UT_ASSERT_CHECK_HASH(hashPCC);
    UT_ASSERT_CHECK_HASH(hashPhong);
    UT_ASSERT_CHECK_HASH(hashSDBM);
    UT_ASSERT_CHECK_HASH(hashTorek);
    UT_ASSERT_CHECK_HASH(hashTorekEx);
    UT_ASSERT_CHECK_HASH(hashWAIS);
    UT_ASSERT_CHECK_HASH(hashWeinberger);

    UT_ACCEPT;
  }

  // Check the given instance of the IHash interface.
  void UT_ASSERT_CHECK_HASH(IHash& a_rHash)
  { CALL
    Tschar string[] = ASC("Hello world Hello world Hello world");
    Tschar hello[] = ASC("Hello");
    Tschar space[] = ASC(" ");
    Tschar world[] = ASC("world");

    // Hash full string.
    a_rHash.initialize();
    a_rHash.hash((Tcbuffer)string, (sizeof(string) - 1));
    a_rHash.close();
    Tuint hash1 = a_rHash.getHash();

    // Hash partial string.
    a_rHash.initialize();
    a_rHash.hash((Tcbuffer)hello, (sizeof(hello) - 1));
    a_rHash.hash((Tcbuffer)space, (sizeof(space) - 1));
    a_rHash.hash((Tcbuffer)world, (sizeof(world) - 1));
    a_rHash.hash((Tcbuffer)space, (sizeof(space) - 1));
    a_rHash.hash((Tcbuffer)hello, (sizeof(hello) - 1));
    a_rHash.hash((Tcbuffer)space, (sizeof(space) - 1));
    a_rHash.hash((Tcbuffer)world, (sizeof(world) - 1));
    a_rHash.hash((Tcbuffer)space, (sizeof(space) - 1));
    a_rHash.hash((Tcbuffer)hello, (sizeof(hello) - 1));
    a_rHash.hash((Tcbuffer)space, (sizeof(space) - 1));
    a_rHash.hash((Tcbuffer)world, (sizeof(world) - 1));
    a_rHash.close();
    Tuint hash2 = a_rHash.getHash();

    // Test hash values.
    UT_ASSERT_EQUAL(hash1, hash2);
  }
} the_Test;
/*==========================================================================*/
