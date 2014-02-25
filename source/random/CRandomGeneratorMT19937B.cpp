/*!
 *  \file    CRandomGeneratorMT19937B.cpp Matsumoto's GFSR "MT19937B" random
 *           number generator.
 *  \brief   Matsumoto's GFSR "MT19937B" random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Matsumoto's GFSR "MT19937B" random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 03:19:00

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
#include <Depth/include/random/CRandomGeneratorMT19937B.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORMT19937B_CPP__
#define __CRANDOMGENERATORMT19937B_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
// Period parameters.
#define N       624
#define M       397
#define MATRIX  0x9908B0DF
#define UP_MASK 0x80000000
#define LO_MASK 0x7FFFFFFF
// For tempering.
#define TMP_MASK_B      0x9D2C5680
#define TMP_MASK_C      0xEFC60000
#define TMP_SHIFT_U(y)  (y>>11)
#define TMP_SHIFT_S(y)  (y<<7)
#define TMP_SHIFT_T(y)  (y<<15)
#define TMP_SHIFT_L(y)  (y>>18)
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorMT19937B::set(const CRandomGeneratorMT19937B& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorMT19937B class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_k = a_crInstance.m_k;
  for (Tuint i = 0; i < 624; ++i)
    m_ptgfsr[i] = a_crInstance.m_ptgfsr[i];
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorMT19937B::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value.
  m_MaxInteger = 0xFFFFFFFF;

  // Setting initial seeds to ptgfsr[N] using
  // the generator Line 25 of Table 1 in
  // [KNUTH 1981, The Art of Computer Programming
  // Vol. 2 (2nd Ed.), pp102].
  m_ptgfsr[0] = m_Seed & 0xFFFFFFFF;
  for (Tsint i = 1; i < N; i++)
    m_ptgfsr[i] = (69069 * m_ptgfsr[i - 1]) & 0xFFFFFFFF;

  // Set initial index.
  m_k = 1;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorMT19937B::randomInteger()
{ CALL
  // Calculate: mag01[x] = x * MATRIX_A for x=0,1.
  const Tuint mag01[2] = { 0x0, MATRIX };
  Tuint y;
  Tsint kk;

  // Generate N words at one time.
  if (m_k == N)
  {
    for (kk = 0; kk < N - M; kk++)
    {
      y = (m_ptgfsr[kk] & UP_MASK) | (m_ptgfsr[kk + 1] & LO_MASK);
      m_ptgfsr[kk] = m_ptgfsr[kk + M] ^ (y >> 1) ^ mag01[y & 0x1];
    }
    for ( ; kk < N - 1; kk++)
    {
      y = (m_ptgfsr[kk] & UP_MASK) | (m_ptgfsr[kk + 1] & LO_MASK);
      m_ptgfsr[kk] = m_ptgfsr[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1];
    }
    y = (m_ptgfsr[N - 1] & UP_MASK) | (m_ptgfsr[0] & LO_MASK);
    m_ptgfsr[N - 1] = m_ptgfsr[M - 1] ^ (y >> 1) ^ mag01[y & 0x1];
    m_k = 0;
  }
  y = m_ptgfsr[m_k++];
  y ^= TMP_SHIFT_U(y);
  y ^= TMP_SHIFT_S(y) & TMP_MASK_B;
  y ^= TMP_SHIFT_T(y) & TMP_MASK_C;

  // You may delete this line if word size = 32.
  y &= 0xFFFFFFFF;
  y ^= TMP_SHIFT_L(y);

  // Return random integer number.
  return y;
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorMT19937B::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorMT19937B::swap(CRandomGeneratorMT19937B& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_k, a_rInstance.m_k);
  NAlgorithms::NCommon::swap(m_ptgfsr, a_rInstance.m_ptgfsr, 624);
}
/*--------------------------------------------------------------------------*/
// Period parameters.
#undef N
#undef M
#undef MATRIX
#undef UP_MASK
#undef LO_MASK
// For tempering.
#undef TMP_MASK_B
#undef TMP_MASK_C
#undef TMP_SHIFT_U
#undef TMP_SHIFT_S
#undef TMP_SHIFT_T
#undef TMP_SHIFT_L
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
