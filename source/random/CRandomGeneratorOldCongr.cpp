/*!
 *  \file    CRandomGeneratorOldCongr.cpp Press's old congruential with
 *           shuffle random number generator.
 *  \brief   Press's old congruential with shuffle random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Press's old congruential with shuffle random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 02:27:50

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
#include <Depth/include/random/CRandomGeneratorOldCongr.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATOROLDCONGR_CPP__
#define __CRANDOMGENERATOROLDCONGR_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
#define RM 714025
#define RA 1366
#define RC 150889
/*----------------------------------------------------------------------------*/
Tbool CRandomGeneratorOldCongr::set(const CRandomGeneratorOldCongr& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorOldCongr class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  for (Tuint i = 0; i < 98; ++i)
    m_r[i] = a_crInstance.m_r[i];
  m_x = a_crInstance.m_x;
  m_y = a_crInstance.m_y;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorOldCongr::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value.
  m_MaxInteger = RM - 1;

  // Initialize shuffle table r and x, y.
  m_x = -m_Seed;
  if ((m_x = (RC - m_x) % RM) < 0)
    m_x = -m_x;
  for (Tsint j = 1; j <= 97; j++)
    m_r[j] = m_x = (RA * m_x + RC) % RM;
  m_y = m_x = (RA * m_x + RC) % RM;
  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorOldCongr::randomInteger()
{ CALL
  Tsint k = 1 + (97 * m_y) / RM;
  m_y = m_r[k];
  m_r[k] = m_x = (RA * m_x + RC) % RM;

  // Return random integer number.
  return m_y;
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorOldCongr::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorOldCongr::swap(CRandomGeneratorOldCongr& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_r, a_rInstance.m_r, 98);
  NAlgorithms::NCommon::swap(m_x, a_rInstance.m_x);
  NAlgorithms::NCommon::swap(m_y, a_rInstance.m_y);
}
/*----------------------------------------------------------------------------*/
#undef RM
#undef RA
#undef RC
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
