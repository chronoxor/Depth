/*!
 *  \file    CRandomGeneratorMLCGran1.cpp Press's MLCG "ran1" random number
 *           generator.
 *  \brief   Press's MLCG "ran1" random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Press's MLCG "ran1" random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 03:47:43

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
#include <Depth/include/random/CRandomGeneratorMLCGran1.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORMLCGRAN1_CPP__
#define __CRANDOMGENERATORMLCGRAN1_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
#define IM      2147483647
#define IA      16807
#define IQ      127773
#define IR      2836
#define MASK    123459876
#define NTAB    32
/*----------------------------------------------------------------------------*/
Tbool CRandomGeneratorMLCGran1::set(const CRandomGeneratorMLCGran1& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorMLCGran1 class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_idum = a_crInstance.m_idum;
  m_iy = a_crInstance.m_iy;
  for (Tuint i = 0; i < 32; ++i)
    m_iv[i] = a_crInstance.m_iv[i];
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorMLCGran1::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value.
  m_MaxInteger = IM - 1;

  // Initialize shuffle table using the seed: iv and idum, iy.
  m_idum = m_Seed;

  // Load shuffle table (after 8 warm-ups).
  for (Tsint j = NTAB + 7; j >= 0; j--)
  {
    Tsint k = m_idum / IQ;
    m_idum = IA * (m_idum - k * IQ) - IR * k;
    if (m_idum < 0)
      m_idum += IM;
    if (j < NTAB)
      m_iv[j] = m_idum;
  }
  m_iy = m_iv[0];
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorMLCGran1::randomInteger()
{ CALL
  Tsint j, k;

  // Start here when not initializing.
  k = m_idum / IQ;

  // Compute idum=mod(IA1*idum,IM1) without overflows by Schrage's method.
  m_idum = IA * (m_idum - k * IQ) - IR * k;
  if (m_idum < 0)
    m_idum += IM;

  // Will be in the range 0..NTAB-1.
  j = m_iy / (1 + (IM - 1) / NTAB);

  // Output previously stored value and refill the shuffle table.
  m_iy = m_iv[j];
  m_iv[j] = m_idum;

  // Return random integer number.
  return m_iy;
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorMLCGran1::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorMLCGran1::swap(CRandomGeneratorMLCGran1& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_idum, a_rInstance.m_idum);
  NAlgorithms::NCommon::swap(m_iy, a_rInstance.m_iy);
  NAlgorithms::NCommon::swap(m_iv, a_rInstance.m_iv, 32);
}
/*----------------------------------------------------------------------------*/
#undef IM
#undef IA
#undef IQ
#undef IR
#undef MASK
#undef NTAB
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
