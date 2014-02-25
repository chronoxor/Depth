/*!
 *  \file    CRandomGeneratorMRG.cpp L'Ecuyer's 1996 MRG random number
 *           generator.
 *  \brief   L'Ecuyer's 1996 MRG random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: L'Ecuyer's 1996 MRG random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 21:14:07

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
#include <Depth/include/random/CRandomGeneratorMRG.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORMRG_CPP__
#define __CRANDOMGENERATORMRG_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CRandomGeneratorMRG::set(const CRandomGeneratorMRG& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorMRG class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_x10 = a_crInstance.m_x10;
  m_x11 = a_crInstance.m_x11;
  m_x12 = a_crInstance.m_x12;
  m_x20 = a_crInstance.m_x20;
  m_x21 = a_crInstance.m_x21;
  m_x22 = a_crInstance.m_x22;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorMRG::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value.
  m_MaxInteger = 0x7FFFFFFE;

  // Initialize seeds using the given seed value: the seeds must be within [1,2145483478].
  m_x10 = ((2039845123 ^ m_Seed) & 0x7FFFFFFF) % 2145483478 + 1;
  m_x11 = (( 182401045 ^ m_Seed) & 0x7FFFFFFF) % 2145483478 + 1;
  m_x12 = ((1190945568 ^ m_Seed) & 0x7FFFFFFF) % 2145483478 + 1;
  m_x20 = (( 943583831 ^ m_Seed) & 0x7FFFFFFF) % 2145483478 + 1;
  m_x21 = ((1345908737 ^ m_Seed) & 0x7FFFFFFF) % 2145483478 + 1;
  m_x22 = (( 723161013 ^ m_Seed) & 0x7FFFFFFF) % 2145483478 + 1;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorMRG::randomInteger()
{ CALL
  // Constant numbers
  const Tsint m1 = 2147483647;
  const Tsint m2 = 2145483479;
  const Tsint a12 = 63308;
  const Tsint q12 = 33921;
  const Tsint r12 = 12979;
  const Tsint a13 = -183326;
  const Tsint q13 = 11714;
  const Tsint r13 = 2883;
  const Tsint a21 = 86098;
  const Tsint q21 = 24919;
  const Tsint r21 = 7417;
  const Tsint a23 = -539608;
  const Tsint q23 = 3976;
  const Tsint r23 = 2071;

  Tsint h, p12, p13, p21, p23;

  // Component one...
  h = m_x10 / q13;
  p13 =- a13 * (m_x10 - h * q13) - h * r13;
  h = m_x11 / q12;
  p12 = a12 * (m_x11 - h * q12) - h * r12;
  if (p13 < 0)
    p13 += m1;
  if (p12 < 0)
    p12 += m1;
  m_x10 = m_x11;
  m_x11 = m_x12;
  m_x12 = p12 - p13;
  if (m_x12 < 0)
    m_x12 += m1;

  // Component two...
  h = m_x20 / q23;
  p23 =- a23 * (m_x20 - h * q23) - h * r23;
  h = m_x22 / q21;
  p21 = a21 * (m_x22 - h * q21) - h * r21;
  if (p23 < 0)
    p23 += m2;
  if (p21 < 0)
    p21 += m2;
  m_x20 = m_x21;
  m_x21 = m_x22;
  m_x22 = p21 - p23;
  if (m_x22 < 0)
    m_x22 += m2;

  // Return random integer number.
  return (m_x12 < m_x22) ? (m_x12 - m_x22 + m1) : (m_x12 - m_x22);
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorMRG::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorMRG::swap(CRandomGeneratorMRG& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_x10, a_rInstance.m_x10);
  NAlgorithms::NCommon::swap(m_x11, a_rInstance.m_x11);
  NAlgorithms::NCommon::swap(m_x12, a_rInstance.m_x12);
  NAlgorithms::NCommon::swap(m_x20, a_rInstance.m_x20);
  NAlgorithms::NCommon::swap(m_x21, a_rInstance.m_x21);
  NAlgorithms::NCommon::swap(m_x22, a_rInstance.m_x22);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
