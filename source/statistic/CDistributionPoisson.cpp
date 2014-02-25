/*!
 *  \file    CDistributionPoisson.cpp Poisson distribution class.
 *  \brief   Poisson distribution class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Poisson distribution class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:19:42

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
#include <Depth/include/statistic.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/math/CMathConstants.hpp>
#include <Depth/include/statistic/CDistributionPoisson.hpp>
/*==========================================================================*/
#ifndef __CDISTRIBUTIONPOISSON_CPP__
#define __CDISTRIBUTIONPOISSON_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CDistributionPoisson::set(const CDistributionPoisson& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CDistributionPoisson class instance."))
  {
    return false;
  }

  // Reinitialize distribution.
  if (!IDistribution::set(a_crInstance))
    return false;

  // Copy distribution state.
  m_Scale = a_crInstance.m_Scale;
  m_ScalePI = a_crInstance.m_ScalePI;
  m_M = a_crInstance.m_M;
  m_Sq = a_crInstance.m_Sq;
  m_Alm = a_crInstance.m_Alm;
  m_G = a_crInstance.m_G;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CDistributionPoisson::setParameters(const Treal a_cMean)
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return false;
  }

  // Store parameters.
  m_M = a_cMean;
  m_Scale = CONSTR(1.0) / getRandomGeneratorRef().getMaxInteger();
  if (m_M < 12.0)
  {
    // Direct method...
    m_G = NMath::CMath::exp(-m_M);
  }
  else
  {
    // Rejection method...
    m_ScalePI = NMath::CMathConstants::PI / getRandomGeneratorRef().getMaxInteger();
    m_Sq = NMath::CMath::sqrt(CONSTR(2.0) * m_M);
    m_Alm = NMath::CMath::log(m_M);
    m_G = m_M * m_Alm - NMath::CMath::logGamma(m_M + CONSTR(1.0));
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Treal CDistributionPoisson::randomReal()
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return 0.0;
  }

  Treal em, t, y;

  if (m_M < 12.0)
  {
    // Direct method...
    em = -1.0;
    t = 1.0;
    do
    {
     em += 1.0;
     t *= getRandomGeneratorRef().randomInteger() * m_Scale;
    } while (t > m_G);
  }
  else
  {
    // Rejection method...
    do
    {
      do
      {
       y = NMath::CMath::tan(getRandomGeneratorRef().randomInteger() * m_ScalePI);
       em = m_Sq * y + m_M;
      } while (em < 0.0);
      em = NMath::CMath::floor(em);
      t = CONSTR(0.9) * (CONSTR(1.0) + y * y) * NMath::CMath::exp(em * m_Alm - NMath::CMath::logGamma(em + CONSTR(1.0)) - m_G);
    } while (getRandomGeneratorRef().randomInteger() * m_Scale > t);
  }
  return em;
}
/*--------------------------------------------------------------------------*/
void CDistributionPoisson::swap(CDistributionPoisson& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IDistribution&)(*this), (IDistribution&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Scale, a_rInstance.m_Scale);
  NAlgorithms::NCommon::swap(m_ScalePI, a_rInstance.m_ScalePI);
  NAlgorithms::NCommon::swap(m_M, a_rInstance.m_M);
  NAlgorithms::NCommon::swap(m_Sq, a_rInstance.m_Sq);
  NAlgorithms::NCommon::swap(m_Alm, a_rInstance.m_Alm);
  NAlgorithms::NCommon::swap(m_G, a_rInstance.m_G);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
