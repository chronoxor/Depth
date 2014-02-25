/*!
 *  \file    CRandomGeneratorFibonacciEx.cpp Extended Knuth's lagged Fibonacci
 *           random number generator.
 *  \brief   Extended Knuth's lagged Fibonacci random number generator class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Extended Knuth's lagged Fibonacci random number generator class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 20:55:36

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
#include <Depth/include/random/CRandomGeneratorFibonacciEx.hpp>
/*==========================================================================*/
#ifndef __CRANDOMGENERATORFIBONACCIEX_CPP__
#define __CRANDOMGENERATORFIBONACCIEX_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CRandomGeneratorFibonacciEx::set(const CRandomGeneratorFibonacciEx& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CRandomGeneratorFibonacciEx class instance."))
  {
    return false;
  }

  // Reinitialize generator.
  IRandomGenerator::set(a_crInstance);

  // Copy generator state.
  m_j55 = a_crInstance.m_j55;
  m_k55 = a_crInstance.m_k55;
  for (Tuint i = 0; i < 55; ++i)
    m_s55[i] = a_crInstance.m_s55[i];
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CRandomGeneratorFibonacciEx::setSeed(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */)
{ CALL
  Tsint i, ii, j, k;

  // Initialize seed value.
  m_Seed = a_cSeed % CConstants::uint32Max;

  // Initialize the maximum integer value.
  m_MaxInteger = 0x7FFFFFFF;

  // Initialize table: XORing with MASK allows use of zero and other simple bit patterns for idum.
  m_s55[0] = j = m_Seed ^ 123459876;
  k = 1;
  for (i = 1; i < 55; i++)
  {
    ii = (21 * i) % 55;
    m_s55[ii] = k;
    k = j - k;
    j = m_s55[ii];
  }

  // Invariance (b-a-24)%55=0.
  m_j55 = 0;
  m_k55 = 24;

  // Warm up table three times.
  for (i = 0; i < 55; i++)
    randomInteger();

  return true;
}
/*--------------------------------------------------------------------------*/
Tuint CRandomGeneratorFibonacciEx::randomInteger()
{ CALL
  // The mask 0x7fffffff assures that the result is a positive 32 bit signed long.
  // Inline the Fibonacci step three times in order to remove correlations.
  // One...
  (m_k55) ? (m_k55--) : (m_k55 = 54);
  (m_j55) ? (m_j55--) : (m_j55 = 54);
  m_s55[m_j55] -= m_s55[m_k55];

  // Two...
  (m_k55) ? (m_k55--) : (m_k55 = 54);
  (m_j55) ? (m_j55--) : (m_j55 = 54);
  m_s55[m_j55] -= m_s55[m_k55];

  // Three...
  (m_k55) ? (m_k55--) : (m_k55 = 54);
  (m_j55) ? (m_j55--) : (m_j55 = 54);

  // Return random integer number.
  return (m_s55[m_j55] -= m_s55[m_k55]) & 0x7FFFFFFF;
}
/*--------------------------------------------------------------------------*/
Treal CRandomGeneratorFibonacciEx::randomReal()
{ CALL
  return (((Treal)randomInteger())/((Treal)m_MaxInteger));
}
/*--------------------------------------------------------------------------*/
void CRandomGeneratorFibonacciEx::swap(CRandomGeneratorFibonacciEx& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IRandomGenerator&)(*this), (IRandomGenerator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_j55, a_rInstance.m_j55);
  NAlgorithms::NCommon::swap(m_k55, a_rInstance.m_k55);
  NAlgorithms::NCommon::swap(m_s55, a_rInstance.m_s55, 55);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
