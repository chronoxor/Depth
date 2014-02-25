/*!
 *  \file    CRandomGeneratorRANLUX.cpp Luescher-James-Marsaglia-Zaman
 *           "RANLUX" random number generator.
 *  \brief   Luescher-James-Marsaglia-Zaman "RANLUX" random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Luescher-James-Marsaglia-Zaman "RANLUX" random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 02:13:00

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

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
#include <Depth/include/random.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/algorithms/numeric/AAbsolute.hpp>
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/random/CRandomGeneratorRANLUX.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORRANLUX_CPP__
#define __CRANDOMGENERATORRANLUX_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CRandomGeneratorRANLUX::set(const CRandomGeneratorRANLUX& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorRANLUX class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_Level = a_crInstance.m_Level;
  m_k1 = a_crInstance.m_k1;
  m_k2 = a_crInstance.m_k2;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorRANLUX::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value.
  m_MaxInteger = 0xFFFFFFFF;

  m_Level = 3;
  m_k1 = 0;
  m_k2 = 0;
  RANLUXGo();
  return true;
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorRANLUX::setLuxury(const Tuint a_cLuxury)
{ CALL
  m_Level = a_cLuxury % CConstants::uint32Max;
  m_k1 = 0;
  m_k2 = 0;
  RANLUXGo();
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorRANLUX::randomInteger()
{ CALL
  return (Tuint)(randomReal() * m_MaxInteger);
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorRANLUX::randomReal()
{ CALL
  Treal x;

  RANLUX(&x);
  return x;
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorRANLUX::RANLUX(Treal* rdum)
{ CALL
  RANLUXDriver(0, rdum, NULL, NULL, NULL, NULL, NULL, 0, 0);
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorRANLUX::RANLUXGo()
{ CALL
  RANLUXDriver(4, NULL, NULL, NULL, NULL, &m_k1, &m_k2, m_Level, m_Seed);
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorRANLUX::RANLUXAt(Tsint* lout, Tsint* inout)
{ CALL
  RANLUXDriver(3, NULL, NULL, lout, inout, &m_k1, &m_k2, 0, 0);
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorRANLUX::RANLUXIn(Tsint* isdext)
{ CALL
  RANLUXDriver(1, NULL, isdext, NULL, NULL, NULL, NULL, 0, 0);
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorRANLUX::RANLUXUt(Tsint* isdext)
{ CALL
  RANLUXDriver(2, NULL, isdext, NULL, NULL, NULL, NULL, 0, 0);
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorRANLUX::RANLUXDriver(Tsint what, Treal* rdum, Tsint* isdext, Tsint* lout, Tsint* inout, Tsint* k1, Tsint* k2, Tsint lux, Tsint ins)
{ CALL
  static Tbool notyet = true;
  static Tsint luxlev = 3;
  static Tsint in24 = 0;
  static Tsint kount = 0;
  static Tsint mkount = 0;
  static Tsint i24 = 24;
  static Tsint j24 = 10;
  static Tsint ndskip[5] = { 0, 24, 73, 199, 365 };
  static Treal carry = 0.0;

  static Tsint next[24];
  static Tsint nskip;
  static Tsint inseed;
  static Treal seeds[24];
  static Treal twom12, twom24;

  // System generated locals.
  Tsint i__1, i__2;

  // Local variables.
  Tsint izip;
  Tsint inner;
  Tsint izip2, i, k, jseed;
  Tsint lp;
  Tsint iseeds[24], iouter, isd, isk;
  Tsint ilx;
  Treal uni;

  // Parameter adjustments to 1-offset.
  if (isdext)
    --isdext;

  switch (what)
  {
    case 1: goto L_rluxin;
    case 2: goto L_rluxut;
    case 3: goto L_rluxat;
    case 4: goto L_rluxgo;
  }

  /*------------------------------------------------------------------------*/
  /*                                     default                            */
  /* Luxury Level      0      1       2   *3*     4                         */
  /* Corresponds to p=24     48      97   223   389                         */
  /* Time factor       1      2       3     6    10  - On slow workstation  */
  /*                   1      1.5     2     3     5  - On fast mainframe    */
  /*------------------------------------------------------------------------*/
  // Notyet is true if no initialization has been performed yet.
  // Default Initialization by Multiplicative Congruential.
  if (notyet)
  {
    notyet = false;
    jseed = 314159265;
    inseed = jseed;

    // Ranlux default initialization.
    luxlev = 3;
    nskip = ndskip[luxlev];
    lp = nskip + 24;
    in24 = 0;
    kount = 0;
    mkount = 0;
    twom24 = 1.0;
    for (i = 1; i <= 24; ++i)
    {
      twom24 *= CONSTR(0.5);
      k = jseed / 53668;
      jseed = (jseed - k * 53668) * 40014 - k * 12211;
      if (jseed < 0)
       jseed += 2147483563;
      iseeds[i - 1] = jseed % 16777216;
    }
    twom12 = twom24 * CONSTR(4096.0);
    for (i = 1; i <= 24; ++i)
    {
      seeds[i - 1] = iseeds[i - 1] * twom24;
      next[i - 1] = i - 1;
    }
    next[0] = 24;
    i24 = 24;
    j24 = 10;
    carry = CONSTR(0.0);
    if (NMath::CMath::isEqualZero(seeds[23]))
      carry = twom24;
  }

  // The Generator proper: "Subtract-with-borrow",
  // as proposed by Marsaglia and Zaman,
  // Florida State University, March, 1989.
  uni = seeds[j24 - 1] - seeds[i24 - 1] - carry;
  if (uni < 0.0)
  {
    uni += CONSTR(1.0);
    carry = twom24;
  }
  else
    carry = CONSTR(0.0);

  seeds[i24 - 1] = uni;
  i24 = next[i24 - 1];
  j24 = next[j24 - 1];
  *rdum = uni;

  // Small numbers (with less than 12 "significant" bits) are "padded".
  if (uni < twom12)
  {
    *rdum += twom24 * seeds[j24 - 1];

    // And zero is forbidden in case someone takes a logarithm.
    if (NMath::CMath::isEqualZero(*rdum))
      *rdum = twom24 * twom24;
  }

  // Skipping to luxury. As proposed by Martin Luscher.
  ++in24;
  if (in24 == 24)
  {
    in24 = 0;
    kount += nskip;
    i__2 = nskip;
    for (isk = 1; isk <= i__2; ++isk)
    {
      uni = seeds[j24 - 1] - seeds[i24 - 1] - carry;
      if (uni < 0.0)
      {
        uni += CONSTR(1.0);
        carry = twom24;
      }
      else
        carry = CONSTR(0.0);
      seeds[i24 - 1] = uni;
      i24 = next[i24 - 1];
      j24 = next[j24 - 1];
    }
  }
  kount++;
  if (kount >= 1000000000)
  {
    ++mkount;
    kount -= 1000000000;
  }
  return;

  /*------------------------------------------------------------------------*/
  /* Entry to input and float integer seeds from previous run               */
  /*------------------------------------------------------------------------*/
L_rluxin:
  twom24 = CONSTR(1.0);
  for (i = 1; i <= 24; ++i)
  {
    next[i - 1] = i - 1;
    twom24 *= CONSTR(0.5);
  }
  next[0] = 24;
  twom12 = twom24 * CONSTR(4096.0);
  for (i = 1; i <= 24; ++i)
    seeds[i - 1] = isdext[i] * twom24;
  carry = CONSTR(0.0);
  if (isdext[25] < 0)
    carry = twom24;
  isd = NAlgorithms::NNumeric::absolute(isdext[25]);
  i24 = isd % 100;
  isd /= 100;
  j24 = isd % 100;
  isd /= 100;
  in24 = isd % 100;
  isd /= 100;
  luxlev = isd;
  if (luxlev <= 4)
    nskip = ndskip[luxlev];
  else
  {
    if (luxlev >= 24)
      nskip = luxlev - 24;
    else
    {
      nskip = ndskip[4];
      luxlev = 4;
    }
  }
  inseed = -1;
  return;

  /*------------------------------------------------------------------------*/
  /* Entry to ouput seeds as integers                                       */
  /*------------------------------------------------------------------------*/
L_rluxut:
  for (i = 1; i <= 24; ++i)
    isdext[i] = (Tsint)(seeds[i - 1] * CONSTR(4096.0) * CONSTR(4096.0));
  isdext[25] = i24 + j24 * 100 + in24 * 10000 + luxlev * 1000000;
  if (carry > 0.0)
    isdext[25] =- isdext[25];
  return;

  /*------------------------------------------------------------------------*/
  /* Entry to output the "convenient" restart point                         */
  /*------------------------------------------------------------------------*/
L_rluxat:
  *lout = luxlev;
  *inout = inseed;
  *k1 = kount;
  *k2 = mkount;
  return;

  /*------------------------------------------------------------------------*/
  /* Entry to initialize from one or three integers                         */
  /*------------------------------------------------------------------------*/
L_rluxgo:
  if (lux < 0)
    luxlev = 3;
  else
  {
    if (lux <= 4)
     luxlev = lux;
    else
    {
      if ((lux < 24) || (lux > 2000))
        luxlev = 4;
      else
      {
        luxlev = lux;
        for (ilx = 0; ilx <= 4; ++ilx)
        {
          if (lux == ndskip[ilx] + 24)
            luxlev = ilx;
        }
      }
    }
  }
  if (luxlev <= 4)
  {
    nskip = ndskip[luxlev];
    i__1 = nskip + 24;
  }
  else
    nskip = luxlev - 24;
  in24 = 0;
  if (ins < 0)
  {
    // Illegal initialization by RLUXGO, negative input seed.
  }
  if (ins > 0)
  {
    // Ranlux initialized by rluxgo from seeds.
    jseed = ins;
  }
  else
  {
    // Ranlux initialized by rluxgo from default seed.
    jseed = 314159265;
  }
  inseed = jseed;
  notyet = false;
  twom24 = CONSTR(1.0);
  for (i = 1; i <= 24; ++i)
  {
    twom24 *= CONSTR(0.5);
    k = jseed / 53668;
    jseed = (jseed - k * 53668) * 40014 - k * 12211;
    if (jseed < 0)
      jseed += 2147483563;
    iseeds[i - 1] = jseed % 16777216;
  }
  twom12 = twom24 * CONSTR(4096.0);
  for (i = 1; i <= 24; ++i)
  {
    seeds[i - 1] = iseeds[i - 1] * twom24;
    next[i - 1] = i - 1;
  }
  next[0] = 24;
  i24 = 24;
  j24 = 10;
  carry = 0.0;
  if (NMath::CMath::isEqualZero(seeds[23]))
    carry = twom24;

  // If restarting at a break point, skip K1 + IGIGA*K2
  // Note that this is the number of numbers delivered to
  // the user PLUS the number skipped (if luxury .GT. 0).
  kount = *k1;
  mkount = *k2;
  if ((*k1 + *k2) != 0)
  {
    i__1 = *k2 + 1;
    for (iouter = 1; iouter <= i__1; ++iouter)
    {
      inner = 1000000000;
      if (iouter == *k2 + 1)
        inner = *k1;
      i__2 = inner;
      for (isk = 1; isk <= i__2; ++isk)
      {
        uni = seeds[j24 - 1] - seeds[i24 - 1] - carry;
        if (uni < 0.0)
        {
          uni += CONSTR(1.0);
          carry = twom24;
        }
        else
          carry = CONSTR(0.0);
        seeds[i24 - 1] = uni;
        i24 = next[i24 - 1];
        j24 = next[j24 - 1];
      }
    }
    // Get the right value of IN24 by direct calculation.
    in24 = kount % (nskip + 24);
    if (mkount > 0)
    {
     izip = 1000000000 % (nskip + 24);
     izip2 = mkount * izip + in24;
     in24 = izip2 % (nskip + 24);
    }
    // Now IN24 had better be between zero and 23 inclusive.
    if (in24 > 23)
    {
      // Error in RESTARTING with RLUXGO: The values Seed,K1,K2 cannot occur at luxury level Level.
      in24 = 0;
    }
  }
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorRANLUX::swap(CRandomGeneratorRANLUX& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Level, a_rInstance.m_Level);
  NAlgorithms::NCommon::swap(m_k1, a_rInstance.m_k1);
  NAlgorithms::NCommon::swap(m_k2, a_rInstance.m_k2);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
