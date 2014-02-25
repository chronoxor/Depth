/*!
 *  \file    CRandomGeneratorRANMAR.cpp James-Marsaglia "RANMAR" random number
 *           generator.
 *  \brief   James-Marsaglia "RANMAR" random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: James-Marsaglia "RANMAR" random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 02:03:00

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
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/random/CRandomGeneratorRANMAR.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORRANMAR_CPP__
#define __CRANDOMGENERATORRANMAR_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CRandomGeneratorRANMAR::set(const CRandomGeneratorRANMAR& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorRANMAR class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  for (Tuint i = 0; i < 97; ++i)
    m_u[i] = a_crInstance.m_u[i];
  m_c = a_crInstance.m_c;
  m_cd = a_crInstance.m_cd;
  m_cm = a_crInstance.m_cm;
  m_i97 = a_crInstance.m_i97;
  m_j97 = a_crInstance.m_j97;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorRANMAR::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Make sure that seed is in valid range.
  if (m_Seed == 0)
    m_Seed = 123459876;
  m_Seed &= 0x7FFFFFFF;
  if (m_Seed > 900000000)
    m_Seed %= 900000001;

  // Initialize the maximum integer value.
  m_MaxInteger = 0xFFFFFFFF;

  // Initializing routine for ranmar: Called by the constructor, can be
  // also called later to reseed the generator.
  // The input value must be in the range:
  //
  //     0 <= ijkl <= 900 000 000
  //
  // Correspondence between the simplified input seed ijkl
  // and the original Marsaglia-Zaman paper (i=12, j=34, k=56, l=78)
  // is found with ijkl = 54217137.
  //
  // (If a two-seed version is used the input values must be in the ranges
  // 0 <= ij <= 31328, 0 <= kl <= 30081 and Marsaglia-Zaman is found with
  // ij=1802, kl=9373).
  Tsint ij = m_Seed % 31329;
  Tsint kl = (m_Seed / 31329) % 30082;
  Tsint i = ((ij / 177) % 177) + 2;
  Tsint j = (ij % 177) + 2;
  Tsint k = ((kl / 169) % 178) + 1;
  Tsint l = kl % 169;
  Tsint m;

  for (Tsint ii = 1; ii <= 97; ii++)
  {
    Treal s = CONSTR(0.0);
    Treal t = CONSTR(0.5);
    for (Tsint jj = 1; jj <= 24; jj++)
    {
      m = (((i * j) % 179) * k) % 179;
      i = j;
      j = k;
      k = m;
      l = (53 * l + 1) % 169;
      if (((l * m) % 64) >= 32)
        s += t;
      t = CONSTR(0.5) * t;
    }
    m_u[ii - 1] = s;
  }
  m_c = CONSTR(362436.0) / CONSTR(16777216.0);
  m_cd = CONSTR(7654321.0) / CONSTR(16777216.0);
  m_cm = CONSTR(16777213.0) / CONSTR(16777216.0);
  m_i97 = 97;
  m_j97 = 33;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorRANMAR::randomInteger()
{ CALL
  return (Tuint)(randomReal() * m_MaxInteger);
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorRANMAR::randomReal()
{ CALL
  Treal uni = m_u[m_i97 - 1] - m_u[m_j97 - 1];

  if (uni < 0)
    uni += CONSTR(1.0);
  m_u[--m_i97] = uni;
  if (m_i97 == 0)
    m_i97 = 97;
  m_j97--;
  if (m_j97 == 0)
    m_j97 = 97;
  m_c -= m_cd;
  if (m_c < 0)
    m_c += m_cm;
  uni -= m_c;
  if (uni < 0)
    uni++;

  // To avoid that the return value is exactly zero (see F. James).
  if (NMath::CMath::isEqualZero(uni))
  {
    // *2^-24
    uni = m_u[m_j97 - 1] / CONSTR(16777216.0);
    if (NMath::CMath::isEqualZero(uni))
    {
      // *2^-48
      uni = CONSTR(1.0) / CONSTR(281474976710656.0);
    }
  }
  // Return random real number.
  return uni;
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorRANMAR::swap(CRandomGeneratorRANMAR& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_u, a_rInstance.m_u, 97);
  NAlgorithms::NCommon::swap(m_c, a_rInstance.m_c);
  NAlgorithms::NCommon::swap(m_cd, a_rInstance.m_cd);
  NAlgorithms::NCommon::swap(m_cm, a_rInstance.m_cm);
  NAlgorithms::NCommon::swap(m_i97, a_rInstance.m_i97);
  NAlgorithms::NCommon::swap(m_j97, a_rInstance.m_j97);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
