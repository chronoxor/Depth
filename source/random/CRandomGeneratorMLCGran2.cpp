/*!
 *  \file    CRandomGeneratorMLCGran2.cpp Press's combined MLCG "ran2" random
 *           number generator.
 *  \brief   Press's combined MLCG "ran2" random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Press's combined MLCG "ran2" random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 03:55:02

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
#include <Depth/include/random/CRandomGeneratorMLCGran2.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORMLCGRAN2_CPP__
#define __CRANDOMGENERATORMLCGRAN2_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
#define IM1     2147483563
#define IM2     2147483399
#define IA1     40014
#define IA2     40692
#define IQ1     53668
#define IQ2     52774
#define IR1     12211
#define IR2     3791
#define IMM1    2147483562
#define NTAB    32
/*----------------------------------------------------------------------------*/
Tbool CRandomGeneratorMLCGran2::set(const CRandomGeneratorMLCGran2& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorMLCGran2 class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_idum1 = a_crInstance.m_idum1;
  m_idum2 = a_crInstance.m_idum2;
  m_iy = a_crInstance.m_iy;
  for (Tuint i = 0; i < 32; ++i)
    m_iv[i] = a_crInstance.m_iv[i];
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorMLCGran2::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value.
  m_MaxInteger = IMM1;

  // Initialize shuffle table using the seed: iv and idum1, idum2, iy.
  m_idum1 = m_Seed;

  // Was previously: idum2 = 123456789L;
  m_idum2 = m_idum1;

  // Load shuffle table (after 8 warm-ups).
  for (Tsint j = NTAB + 7; j >= 0; j--)
  {
    Tsint k = m_idum1 / IQ1;
    m_idum1 = IA1 * (m_idum1 - k * IQ1) - IR1 * k;
    if (m_idum1 < 0)
      m_idum1 += IM1;
    if (j < NTAB)
      m_iv[j] = m_idum1;
  }
  m_iy = m_iv[0];
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorMLCGran2::randomInteger()
{ CALL
  Tsint j, k;

  // Start here when not initializing.
  k = m_idum1 / IQ1;

  // Compute idum=mod(IA1*idum,IM1) without overflows by Schrage's method.
  m_idum1 = IA1 * (m_idum1 - k * IQ1) - IR1 * k;
  if (m_idum1 < 0)
    m_idum1 += IM1;

  // Compute idum2=mod(IA2*idum2,IM2) likewise.
  k = m_idum2 / IQ2;

  // Compute idum=mod(IA1*idum,IM1) without overflows by Schrage's method.
  m_idum2 = IA2 * (m_idum2 - k * IQ2) - IR2 * k;
  if (m_idum2 < 0)
    m_idum2 += IM2;

  // Will be in the range 0..NTAB-1.
  j = m_iy / (1 + IMM1 / NTAB);

  // Output previously stored value and refill the shuffle table.
  m_iy = m_iv[j] - m_idum2;
  m_iv[j] = m_idum1;
  if (m_iy < 1)
    m_iy += IMM1;

  // Return random integer number.
  return m_iy;
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorMLCGran2::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorMLCGran2::swap(CRandomGeneratorMLCGran2& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_idum1, a_rInstance.m_idum1);
  NAlgorithms::NCommon::swap(m_idum2, a_rInstance.m_idum2);
  NAlgorithms::NCommon::swap(m_iy, a_rInstance.m_iy);
  NAlgorithms::NCommon::swap(m_iv, a_rInstance.m_iv, 32);
}
/*----------------------------------------------------------------------------*/
#undef IM1
#undef IM2
#undef IA1
#undef IA2
#undef IQ1
#undef IQ2
#undef IR1
#undef IR2
#undef IMM1
#undef NTAB
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
