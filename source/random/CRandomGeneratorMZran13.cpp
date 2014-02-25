/*!
 *  \file    CRandomGeneratorMZran13.cpp Marsaglia's combined congruential
 *           random number generator.
 *  \brief   Marsaglia's combined congruential random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Marsaglia's combined congruential random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 02:02:01

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
#include <Depth/include/random/CRandomGeneratorMZran13.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORMZRAN13_CPP__
#define __CRANDOMGENERATORMZRAN13_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CRandomGeneratorMZran13::set(const CRandomGeneratorMZran13& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorMZran13 class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_x = a_crInstance.m_x;
  m_y = a_crInstance.m_y;
  m_z = a_crInstance.m_z;
  m_n = a_crInstance.m_n;
  m_c = a_crInstance.m_c;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorMZran13::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value: 0xffffffff = 2^32-1 = 4294967295.
  m_MaxInteger = 0xFFFFFFFF;

  // Initialize the seeds.
  m_x = (m_Seed ^ 521288629) & 0xFFFFFFFF;
  m_y = (m_Seed ^ 362436069) & 0xFFFFFFFF;
  m_z = (m_Seed ^ 16163801) & 0xFFFFFFFF;
  m_n = (m_Seed ^ 1131199209) & 0xFFFFFFFF;
  m_c = (m_y > m_z) ? 1 : 0;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorMZran13::randomInteger()
{ CALL
  Tsint s;

  // The mask 0xffffffff is neccessary in some places to assure that arithmetics
  // is performed modulo 2^32 to make the generater portable to any word length
  // larger than 2^32.
  if (m_y > (m_x + m_c))
  {
    s = m_y - (m_x + m_c);
    m_c = 0;
  }
  else
  {
    s = (m_y - (m_x + m_c) - 18) & 0xFFFFFFFF;
    m_c = 1;
  }
  m_x = m_y;
  m_y = m_z;

  // Return random integer number.
  return ((m_z = s) + (m_n = 69069 * m_n + 1013904243)) & 0xFFFFFFFF;
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorMZran13::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorMZran13::swap(CRandomGeneratorMZran13& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_x, a_rInstance.m_x);
  NAlgorithms::NCommon::swap(m_y, a_rInstance.m_y);
  NAlgorithms::NCommon::swap(m_z, a_rInstance.m_z);
  NAlgorithms::NCommon::swap(m_n, a_rInstance.m_n);
  NAlgorithms::NCommon::swap(m_c, a_rInstance.m_c);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
