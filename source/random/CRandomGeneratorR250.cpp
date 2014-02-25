/*!
 *  \file    CRandomGeneratorR250.cpp Kirkpatrick-Stoll "R250" random number
 *           generator.
 *  \brief   Kirkpatrick-Stoll "R250" random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Kirkpatrick-Stoll "R250" random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 03:08:09

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
#include <Depth/include/random/CRandomGeneratorR250.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORR250_CPP__
#define __CRANDOMGENERATORR250_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CRandomGeneratorR250::set(const CRandomGeneratorR250& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorR250 class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_Index = a_crInstance.m_Index;
  for (Tuint i = 0; i < 250; ++i)
    m_Buffer[i] = a_crInstance.m_Buffer[i];
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorR250::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Set initial state in the r250-buffer.
  Tsint j, k, GGL_seed;
  Tuint mask, msb;

  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value.
  m_MaxInteger = 0xFFFFFFFF;

  // Set seed for the auxilliary GGL generator.
  GGL_seed = m_Seed;
  m_Index = 0;

  // Fill r250-buffer with N_BITS-1 bit values.
  for (j = 0; j < 250; j++)
  {
    // Park and Miller's minimal standard random generator 'GGL':
    // An algorithm from CACM 31 no. 10, pp. 1192-1201, October 1988.
    // x[n+1] = (16807 * x[n]) mod (2^31 - 1).
    const Tsint A = 16807;
    const Tsint M = 0x7FFFFFFF;
    const Tsint Q = 127773;
    const Tsint R = 2836;

    GGL_seed = A * (GGL_seed % Q) - R * (GGL_seed / Q);
    if (GGL_seed <= 0)
      GGL_seed += M;
    m_Buffer[j] = GGL_seed;
  }

  // Set some MSBs to 1.
  for (j = 0; j < 250; j++)
  {
    // Park and Miller's minimal standard random generator 'GGL':
    // An algorithm from CACM 31 no. 10, pp. 1192-1201, October 1988.
    // x[n+1] = (16807 * x[n]) mod (2^31 - 1).
    const Tsint A = 16807;
    const Tsint M = 0x7FFFFFFF;
    const Tsint Q = 127773;
    const Tsint R = 2836;

    GGL_seed = A * (GGL_seed % Q) - R * (GGL_seed / Q);
    if (GGL_seed <= 0)
      GGL_seed += M;
    if (GGL_seed > 0x40000000)
      m_Buffer[j] |= 0x80000000;
  }

  // Turn on diagonal bit.
  msb = 0x80000000;

  // Turn off the leftmost bits.
  mask = 0xFFFFFFFF;
  for (j = 0; j < 32; j++)
  {
    // Select a word to operate on.
    k = 7 * j + 3;

    // Turn off bits left of the diagonal.
    m_Buffer[k] &= mask;

    // Turn on the diagonal bit.
    m_Buffer[k] |= msb;

    mask >>= 1;
    msb >>= 1;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorR250::randomInteger()
{ CALL
  Tsint j;
  Tuint new_rand;

  // Wrap pointer around.
  if (m_Index >= 147)
    j = m_Index - 147;
  else
    j = m_Index + 103;

  new_rand = m_Buffer[m_Index] ^ m_Buffer[j];
  m_Buffer[m_Index] = new_rand;

  // Increment pointer for next time.
  if (m_Index >= 249)
    m_Index = 0;
  else
    m_Index++;

  // Return random integer number.
  return new_rand;
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorR250::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorR250::swap(CRandomGeneratorR250& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Index, a_rInstance.m_Index);
  NAlgorithms::NCommon::swap(m_Buffer, a_rInstance.m_Buffer, 250);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
