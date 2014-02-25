/*!
 *  \file    CRandomGeneratorTaus88.cpp L'Ecuyer's 1996 Tausworthe "taus88"
 *           random number generator.
 *  \brief   L'Ecuyer's 1996 Tausworthe "taus88" random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: L'Ecuyer's 1996 Tausworthe "taus88" random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 21:05:12

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
#include <Depth/include/random/CRandomGeneratorTaus88.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORTAUS88_CPP__
#define __CRANDOMGENERATORTAUS88_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CRandomGeneratorTaus88::set(const CRandomGeneratorTaus88& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorTaus88 class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_s1 = a_crInstance.m_s1;
  m_s2 = a_crInstance.m_s2;
  m_s3 = a_crInstance.m_s3;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorTaus88::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value.
  m_MaxInteger = CONSTU(4294967295);

  // Initialize seeds using the given seed value taking care of the
  // requirements. The constants below are arbitrary otherwise.
  m_s1 = CONSTU(1243598713) ^ m_Seed; if (m_s1 < 2)  m_s1 = CONSTU(1243598713);
  m_s2 = CONSTU(3093459404) ^ m_Seed; if (m_s2 < 8)  m_s2 = CONSTU(3093459404);
  m_s3 = CONSTU(1821928721) ^ m_Seed; if (m_s3 < 16) m_s3 = CONSTU(1821928721);
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorTaus88::randomInteger()
{ CALL
  Tuint b;

  b = (((m_s1 << 13) & 0xFFFFFFFF) ^ m_s1) >> 19;
  m_s1 = (((m_s1 & CONSTU(4294967294)) << 12) & 0xFFFFFFFF) ^ b;
  b = (((m_s2 << 2) & 0xFFFFFFFF) ^ m_s2) >> 25;
  m_s2 = (((m_s2 & CONSTU(4294967288)) << 4) & 0xFFFFFFFF) ^ b;
  b = (((m_s3 << 3) & 0xFFFFFFFF) ^ m_s3) >> 11;
  m_s3 = (((m_s3 & CONSTU(4294967280)) << 17) & 0xFFFFFFFF) ^ b;

  // Return random integer number.
  return (m_s1 ^ m_s2 ^ m_s3);
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorTaus88::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorTaus88::swap(CRandomGeneratorTaus88& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_s1, a_rInstance.m_s1);
  NAlgorithms::NCommon::swap(m_s2, a_rInstance.m_s2);
  NAlgorithms::NCommon::swap(m_s3, a_rInstance.m_s3);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
