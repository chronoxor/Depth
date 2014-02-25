/*!
 *  \file    CRandomGeneratorTT800.cpp Matsumoto's GFSR "TT800" random number
 *           generator.
 *  \brief   Matsumoto's GFSR "TT800" random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Matsumoto's GFSR "TT800" random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 03:13:07

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
#include <Depth/include/random/CRandomGeneratorTT800.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORTT800_CPP__
#define __CRANDOMGENERATORTT800_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
#define N 25
#define M 7
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorTT800::set(const CRandomGeneratorTT800& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorTT800 class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_k = a_crInstance.m_k;
  for (Tuint i = 0; i < 25; ++i)
    m_x[i] = a_crInstance.m_x[i];
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorTT800::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initial 25 seeds, change as you wish.
  const Tuint x_data[N] =
  {
    0x95F24DAB,0x0B685215,0xE76CCAE7,0xAF3EC239,0x715FAD23,
    0x24A590AD,0x69E4B5EF,0xBF456141,0x96BC1B7B,0xA7BDF825,
    0xC1DE75B7,0x8858A9C9,0x2DA87693,0xB657F9DD,0xFFDC8A9F,
    0x8121DA71,0x8B823ECB,0x885D05F5,0x4E20CD47,0x5A9AD5D9,
    0x512C0C03,0xEA857CCD,0x4CC1D30F,0x8891A8A1,0xA6B7AADB
  };

  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value.
  m_MaxInteger = 0xFFFFFFFF;

  // Initialize seeds.
  m_k = 0;

  // Combine table with given seed.
  for (Tsint i = 0; i < N; i++)
    m_x[i] = x_data[i] ^ m_Seed;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorTT800::randomInteger()
{ CALL
  // This is magic vector `a', don't change.
  const Tuint mag01[2] = { 0x0, 0x8EBFD028 };
  Tuint y;
  Tsint kk;

  if (m_k == N)
  {
    // Generate N words at one time.
    for (kk = 0; kk < N - M; kk++)
      m_x[kk] = m_x[kk + M] ^ (m_x[kk] >> 1) ^ mag01[m_x[kk] % 2];
    for ( ; kk < N; kk++)
      m_x[kk] = m_x[kk + (M - N)] ^ (m_x[kk] >> 1) ^ mag01[m_x[kk] % 2];
    m_k = 0;
  }
  y = m_x[m_k];
  // s and b, magic vectors.
  y ^= (y << 7) & 0x2B5B2500;
  // t and c, magic vectors.
  y ^= (y << 15) & 0xDB8B0000;

  // You may delete this line if word size = 32.
  y &= 0xFFFFFFFF;

  // The following line was added by Makoto Matsumoto in the 1996 version to improve lower bit's corellation.
  // Delete this line to use the code published in 1994. Added to the 1994 version.
  y ^= (y >> 16);
  m_k++;

  // Return random integer number.
  return y;
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorTT800::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorTT800::swap(CRandomGeneratorTT800& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_k, a_rInstance.m_k);
  NAlgorithms::NCommon::swap(m_x, a_rInstance.m_x, 25);
}
/*--------------------------------------------------------------------------*/
#undef N
#undef M
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
