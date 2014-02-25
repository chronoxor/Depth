/*!
 *  \file    CRandomGeneratorGGL.cpp Minimal congruential random number
 *           generator.
 *  \brief   Minimal congruential random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    24.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Minimal congruential random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   24.02.2009 21:27:33

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
#include <Depth/include/random/CRandomGeneratorGGL.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORGGL_CPP__
#define __CRANDOMGENERATORGGL_CPP__
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
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorGGL::set(const CRandomGeneratorGGL& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorGGL class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_idum = a_crInstance.m_idum;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorGGL::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Make sure that seed is not the MASK (otherwise zero is returned always).
  if (m_Seed == MASK)
    m_Seed >>= 1;

  // Initialize the maximum integer value.
  m_MaxInteger = IM - 1;

  // Initialize idum using the seed:
  // XORing with MASK allows use of zero
  // and other simple bit patterns for idum.
  m_idum = m_Seed ^ MASK;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorGGL::randomInteger()
{ CALL
  // Compute idum=mod(IA*idum,IM).
  Tsint k = m_idum / IQ;

  // Without overflows by Schrage's method.
  m_idum = IA * (m_idum - k * IQ) - IR * k;
  if (m_idum < 0)
    m_idum += IM;

  // Return random integer number.
  return m_idum;
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorGGL::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorGGL::swap(CRandomGeneratorGGL& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_idum, a_rInstance.m_idum);
}
/*----------------------------------------------------------------------------*/
#undef IM
#undef IA
#undef IQ
#undef IR
#undef MASK
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
