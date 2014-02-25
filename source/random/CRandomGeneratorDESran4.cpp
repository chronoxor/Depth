/*!
 *  \file    CRandomGeneratorDESran4.cpp Press's pseudo-DES "ran4" random
 *           number generator.
 *  \brief   Press's pseudo-DES "ran4" random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Press's pseudo-DES "ran4" random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 02:07:42

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
#include <Depth/include/random/CRandomGeneratorDESran4.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORDESRAN4_CPP__
#define __CRANDOMGENERATORDESRAN4_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CRandomGeneratorDESran4::set(const CRandomGeneratorDESran4& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorDESran4 class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_idums = a_crInstance.m_idums;
  m_idum = a_crInstance.m_idum;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorDESran4::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value: 0xFFFFFFFF = 2^32-1 = 4294967295.
  m_MaxInteger = 0xFFFFFFFF;

  // Initialize the generator.
  m_idums = m_Seed;

  // First value to be hashed for the sequence associated to seed.
  m_idum = 1;

  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorDESran4::randomInteger()
{ CALL
  const Tuint c1[4] = {0xBAA96887, 0x1E17D32C, 0x03BCDC3C, 0x0F33D1B2};
  const Tuint c2[4] = {0x4B0F3B58, 0xE874F0C3, 0x6955C5A6, 0x55A7CA46};
  Tuint ia, ib, iswap, itmph = 0, itmpl = 0;
  Tuint irword, lword;

  // Next idum.
  irword = m_idum;

  // The seed.
  lword = m_idums;

  // Hash: pseudo-DES hashing algorithm not yet portable to 64-bit machines - use masks!
  // Four iterations of the non-linear pseude-DES mixing.
  for (Tsint i = 0; i < 4; i++)
  {
    ia = (iswap = irword) ^ c1[i];
    itmpl = ia & 0xFFFF;
    itmph = ia >> 16;
    ib = (itmpl * itmpl + ~(itmph * itmph)) & 0xFFFFFFFF;
    irword = (lword ^ (((ia = (ib >> 16) | ((ib & 0xFFFF) << 16)) ^ c2[i]) + itmpl * itmph)) & 0xFFFFFFFF;
    lword = iswap & 0xFFFFFFFF;
  }

  // This sequence is exhausted - skip to next sequence (idums).
  if (m_idum ==0xFFFFFFFF)
  {
    // Reset to start.
    m_idum = 0;
    if (m_idums == 0xFFFFFFFF)
      m_idums = 1;
    else
      // Increment seed to get next sequence.
      m_idums++;
  }
  m_idum++;

  // Return random integer number.
  return irword;
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorDESran4::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorDESran4::swap(CRandomGeneratorDESran4& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_idums, a_rInstance.m_idums);
  NAlgorithms::NCommon::swap(m_idum, a_rInstance.m_idum);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
