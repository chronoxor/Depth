/*!
 *  \file    test-random-IRandomGenerator.cpp Testing of the IRandomGenerator
 *           interface and different random number generators.
 *  \brief   Testing of the IRandomGenerator interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the IRandomGenerator interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth random tests
    VERSION:   1.0
    CREATED:   24.02.2009 23:08:09

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
#include <Depth/include/random/CRandomGeneratorDESran4.hpp>
#include <Depth/include/random/CRandomGeneratorFibonacci.hpp>
#include <Depth/include/random/CRandomGeneratorFibonacciEx.hpp>
#include <Depth/include/random/CRandomGeneratorGGL.hpp>
#include <Depth/include/random/CRandomGeneratorMLCGran1.hpp>
#include <Depth/include/random/CRandomGeneratorMLCGran2.hpp>
#include <Depth/include/random/CRandomGeneratorMRG.hpp>
#include <Depth/include/random/CRandomGeneratorMRG32k3a.hpp>
#include <Depth/include/random/CRandomGeneratorMT19937B.hpp>
#include <Depth/include/random/CRandomGeneratorMZran13.hpp>
#include <Depth/include/random/CRandomGeneratorOldCongr.hpp>
#include <Depth/include/random/CRandomGeneratorR250.hpp>
#include <Depth/include/random/CRandomGeneratorRANLUX.hpp>
#include <Depth/include/random/CRandomGeneratorRANMAR.hpp>
#include <Depth/include/random/CRandomGeneratorTaus88.hpp>
#include <Depth/include/random/CRandomGeneratorTT800.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NRandom;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorGGL(12345),         CONSTU(2147483646), CONSTU(589656753),  CONSTU(2023554599), CONSTU(1408254115), CONSTU(2140612989));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorMLCGran1(12345),    CONSTU(2147483646), CONSTU(1982386332), CONSTU(303841923),  CONSTU(804508593),  CONSTU(810580700));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorMLCGran2(12345),    CONSTU(2147483562), CONSTU(58410101),   CONSTU(2004938505), CONSTU(1331649083), CONSTU(577395875));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorDESran4(12345),     CONSTU(4294967295), CONSTU(3353424467), CONSTU(3966958577), CONSTU(4289278815), CONSTU(2480732950));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorOldCongr(12345),    CONSTU(714024),     CONSTU(686380),     CONSTU(616319),     CONSTU(153771),     CONSTU(239822));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorMZran13(12345),     CONSTU(4294967295), CONSTU(1052706368), CONSTU(687250605),  CONSTU(51473094),   CONSTU(3582282851));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorFibonacci(12345),   CONSTU(2147483647), CONSTU(1304083890), CONSTU(1658702573), CONSTU(896362911),  CONSTU(1030774531));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorFibonacciEx(12345), CONSTU(2147483647), CONSTU(889586421),  CONSTU(815638537),  CONSTU(879476249),  CONSTU(1214974513));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorTaus88(12345),      CONSTU(4294967295), CONSTU(3281060548), CONSTU(2391611431), CONSTU(1676961172), CONSTU(3790720786));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorMRG(12345),         CONSTU(2147483646), CONSTU(116468639),  CONSTU(500596688),  CONSTU(582711399),  CONSTU(2067771271));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorR250(12345),        CONSTU(4294967295), CONSTU(3054506754), CONSTU(33543961),   CONSTU(3752165226), CONSTU(1340387679));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorTT800(12345),       CONSTU(4294967295), CONSTU(2799819379), CONSTU(1668953686), CONSTU(1918430507), CONSTU(4228924999));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorMT19937B(12345),    CONSTU(4294967295), CONSTU(2147128715), CONSTU(1145868003), CONSTU(560920153),  CONSTU(2878843637));

    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorRANMAR(12345), CONSTR(0.52472335),  CONSTR(0.18112272), CONSTR(0.75604242), CONSTR(0.58903533));
    UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorRANLUX(12345), CONSTR(0.075406313), CONSTR(0.43825424), CONSTR(0.93767196), CONSTR(0.93397456));
    // Do not test L'Ecuyer's 1997 MRG "MRG32k3a" random number generator because big miscalculation.
    // UT_ASSERT_CHECK_RANDOM_GENERATOR(CRandomGeneratorMRG32k3a(12345), CONSTR(0.12701118), CONSTR(0.56652272), CONSTR(0.041585326), CONSTR(0.87518477));

    UT_ACCEPT;
  }

  // Check the random number generator (integer number version).
  /*!
     Checks the correct installation of the pseudo-random number generator ran
     by comparing the calculated  1-st,  50001-th,  100001-th  and  1100002-th
     random number of the sequence with the expected values given as arguments
     A, B, C and respectively D. Also the correct  returning  of  the  maximum
     value MaxInteger is tested.
  */
  template <class T_RandomGenerator>
  void UT_ASSERT_CHECK_RANDOM_GENERATOR(const T_RandomGenerator& a_rRandomGenerator, const Tuint a_cMaxInteger, const Tuint a_cA, const Tuint a_cB, const Tuint a_cC, const Tuint a_cD)
  { CALL
    T_RandomGenerator random(a_rRandomGenerator);

    // Check maximum integer number of the given random number generator.
    UT_ASSERT_EQUAL(random.getMaxInteger(), a_cMaxInteger);

    // Check 1-st integer value of the given random number generator.
    UT_ASSERT_EQUAL(random.randomInteger(), a_cA);

    // Check 50001-th integer value of the given random number generator.
    for (Tuint i = 0; i < 49999; i++) random.randomInteger();
    UT_ASSERT_EQUAL(random.randomInteger(), a_cB);

    // Check 100001-th integer value of the given random number generator.
    for (Tuint i = 0; i < 49999; i++) random.randomInteger();
    UT_ASSERT_EQUAL(random.randomInteger(), a_cC);

    // Check 1100002-th integer value of the given random number generator.
    for (Tuint i = 0; i < 1000000; i++) random.randomInteger();
    UT_ASSERT_EQUAL(random.randomInteger(), a_cD);

    // Check integer values of the given random number generator with system seed.
    T_RandomGenerator random_with_system_seed;
    for (Tuint i = 0; i < 1000; i++) UT_ASSERT_LESS_EQUAL(random_with_system_seed.randomInteger(), a_cMaxInteger);
  }

  // Check the random number generator (real number version).
  /*!
     Checks the correct installation of the pseudo-random number generator ran
     by comparing the calculated  1-st,  50001-th,  100001-th  and  1100002-th
     random number of the sequence with the expected values given as arguments
     A, B, C and respectively D.
  */
  template <class T_RandomGenerator>
  void UT_ASSERT_CHECK_RANDOM_GENERATOR(const T_RandomGenerator& a_rRandomGenerator, const Treal a_cA, const Treal a_cB, const Treal a_cC, const Treal a_cD)
  { CALL
    T_RandomGenerator random(a_rRandomGenerator);

    // Check 1-st real value of the given random number generator.
    UT_ASSERT_DELTA(random.randomReal(), a_cA, 0.0001);

    // Check 50001-th real value of the given random number generator.
    for (Tuint i = 0; i < 49999; i++) random.randomReal();
    UT_ASSERT_DELTA(random.randomReal(), a_cB, 0.0001);

    // Check 100001-th real value of the given random number generator.
    for (Tuint i = 0; i < 49999; i++) random.randomReal();
    UT_ASSERT_DELTA(random.randomReal(), a_cC, 0.0001);

    // Check 1100002-th real value of the given random number generator.
    for (Tuint i = 0; i < 1000000; i++) random.randomReal();
    UT_ASSERT_DELTA(random.randomReal(), a_cD, 0.0001);
  }
} the_Test;
/*==========================================================================*/
