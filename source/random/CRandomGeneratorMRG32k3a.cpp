/*!
 *  \file    CRandomGeneratorMRG32k3a.cpp L'Ecuyer's 1997 MRG "MRG32k3a"
 *           random number generator.
 *  \brief   L'Ecuyer's 1997 MRG "MRG32k3a" random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    26.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: L'Ecuyer's 1997 MRG "MRG32k3a" random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   26.02.2009 02:18:12

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
#include <Depth/include/random/CRandomGeneratorMRG32k3a.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORMRG32K3A_CPP__
#define __CRANDOMGENERATORMRG32K3A_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CRandomGeneratorMRG32k3a::set(const CRandomGeneratorMRG32k3a& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorMRG32k3a class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_s10 = a_crInstance.m_s10;
  m_s11 = a_crInstance.m_s11;
  m_s12 = a_crInstance.m_s12;
  m_s20 = a_crInstance.m_s20;
  m_s21 = a_crInstance.m_s21;
  m_s22 = a_crInstance.m_s22;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorMRG32k3a::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Make sure that seed is in valid range.
  if (m_Seed == 0)
    m_Seed = 123459876;
  if (m_Seed > CONSTU(4294944442))
    m_Seed >>= 1;

  // Initialize the maximum integer value.
  m_MaxInteger = 0xFFFFFFFF;

  // Initialize generator state.
  m_s10 = (Treal)m_Seed;
  m_s11 = (Treal)m_Seed;
  m_s12 = (Treal)m_Seed;
  m_s20 = (Treal)m_Seed;
  m_s21 = (Treal)m_Seed;
  m_s22 = (Treal)m_Seed;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorMRG32k3a::setSeed(const Tuint a_cSeed10, const Tuint a_cSeed11, const Tuint a_cSeed12, const Tuint a_cSeed20, const Tuint a_cSeed21, const Tuint a_cSeed22)
{ CALL
  // Make some consistency checks on the seeds.
  const Tuint u1 = CONSTU(4294967086);
  const Tuint u2 = CONSTU(4294944442);

  Tuint s10 = a_cSeed10 % CConstants::uint32Max;
  Tuint s11 = a_cSeed11 % CConstants::uint32Max;
  Tuint s12 = a_cSeed12 % CConstants::uint32Max;
  Tuint s20 = a_cSeed20 % CConstants::uint32Max;
  Tuint s21 = a_cSeed21 % CConstants::uint32Max;
  Tuint s22 = a_cSeed22 % CConstants::uint32Max;

  // Make sure that seeds are in valid ranges.
  if (s10 == 0)
    s10 = 123459876;
  if (s10 > u1)
    s10 >>= 1;
  if (s11 == 0)
    s11 = 123459876;
  if (s11 > u1)
    s11 >>= 1;
  if (s12 == 0)
    s12 = 123459876;
  if (s12 > u1)
    s12 >>= 1;
  if (s20 == 0)
    s20 = 123459876;
  if (s20 > u2)
    s20 >>= 1;
  if (s21 == 0)
    s21 = 123459876;
  if (s21 > u2)
    s21 >>= 1;
  if (s22 == 0)
    s22 = 123459876;
  if (s22 > u2)
    s22 >>= 1;

  // Initialize seed value.
  m_Seed = s10 + s11 + s12 + s20 + s21 + s22;

  // Initialize the maximum integer value.
  m_MaxInteger = 0xFFFFFFFF;

  // Initialize generator state.
  m_s10 = (Treal)s10;
  m_s11 = (Treal)s11;
  m_s12 = (Treal)s12;
  m_s20 = (Treal)s20;
  m_s21 = (Treal)s21;
  m_s22 = (Treal)s22;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorMRG32k3a::randomInteger()
{ CALL
  return (Tuint)(randomReal() * m_MaxInteger);
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorMRG32k3a::randomReal()
{ CALL
  // Implementation constants.
  const Treal norm = (Treal)2.328306549295728e-10;
  const Treal m1 = (Treal)4294967087.0;
  const Treal m2 = (Treal)4294944443.0;
  Treal p;
  Tsint k;

  // Component 1.
  p = CONSTR(1403580.0) * m_s11 - CONSTR(810728.0) * m_s10;
  k = (Tsint)(p / m1);
  p -= k * m1;
  if (p < 0.0)
    p += m1;
  m_s10 = m_s11;
  m_s11 = m_s12;
  m_s12 = p;

  // Component 2.
  p = CONSTR(527612.0) * m_s22 - CONSTR(1370589.0) * m_s20;
  k = (Tsint)(p / m2);
  p -= k * m2;
  if (p < 0.0)
    p += m2;
  m_s20 = m_s21;
  m_s21 = m_s22;
  m_s22 = p;

  // Return random real number.
  return (m_s12 <= m_s22) ? ((m_s12 - m_s22 + m1) * norm) : ((m_s12 - m_s22) * norm);
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorMRG32k3a::swap(CRandomGeneratorMRG32k3a& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_s10, a_rInstance.m_s10);
  NAlgorithms::NCommon::swap(m_s11, a_rInstance.m_s11);
  NAlgorithms::NCommon::swap(m_s12, a_rInstance.m_s12);
  NAlgorithms::NCommon::swap(m_s20, a_rInstance.m_s20);
  NAlgorithms::NCommon::swap(m_s21, a_rInstance.m_s21);
  NAlgorithms::NCommon::swap(m_s22, a_rInstance.m_s22);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
