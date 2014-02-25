/*!
 *  \file    CDistributionBeta.cpp Beta distribution class.
 *  \brief   Beta distribution class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    04.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Beta distribution class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   04.03.2009 20:46:14

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
#include <Depth/include/algorithms/common/AMax.hpp>
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/base/CReal.hpp>
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/math/CMathConstants.hpp>
#include <Depth/include/statistic/CDistributionBeta.hpp>
/*==========================================================================*/
#ifndef __CDISTRIBUTIONBETA_CPP__
#define __CDISTRIBUTIONBETA_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CDistributionBeta::set(const CDistributionBeta& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CDistributionBeta class instance."))
  {
    return false;
  }

  // Reinitialize distribution.
  if (!IDistribution::set(a_crInstance))
    return false;

  // Copy distribution state.
  m_AlgorithmBB = a_crInstance.m_AlgorithmBB;
  m_aa = a_crInstance.m_aa;
  m_bb = a_crInstance.m_bb;
  m_scale = a_crInstance.m_scale;
  m_a = a_crInstance.m_a;
  m_alpha = a_crInstance.m_alpha;
  m_b = a_crInstance.m_b;
  m_beta = a_crInstance.m_beta;
  m_delta = a_crInstance.m_delta;
  m_gamma = a_crInstance.m_gamma;
  m_k1 = a_crInstance.m_k1;
  m_k2 = a_crInstance.m_k2;
  m_maxexp = a_crInstance.m_maxexp;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CDistributionBeta::setParameters(const Treal a_cPA, const Treal a_cPB)
{ CALL
  // Check distribution PA parameter.
  ASSERT((a_cPA > 0.0), STR("PA parameter must be greater than 0.0 (PA = %r).") COMMA a_cPA)
  {
    return false;
  }
  // Check distribution PB parameter.
  ASSERT((a_cPB > 0.0), STR("PB parameter must be greater than 0.0 (PB = %r).") COMMA a_cPB)
  {
    return false;
  }
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return false;
  }

  // Store parameters.
  m_aa = a_cPA;
  m_bb = a_cPB;

  // Scale random long to (0, 1) - boundaries are not allowed!
  m_scale = CONSTR(1.0) / (getRandomGeneratorRef().getMaxInteger() + CONSTR(1.0));

  // Maximal exponent for exp() function in evaluation "a * exp(v)" below.
  m_maxexp = NBase::CRealNumber::getMaxExp() * NMath::CMathConstants::LN2 - CONSTR(1.0);
  if (m_a > 1.0)
    m_maxexp -= NMath::CMath::ceil(NMath::CMath::log(m_a));

  m_AlgorithmBB = NAlgorithms::NCommon::min(m_aa, m_bb) > 1.0;

  // Initialize algorithm BB...
  if (m_AlgorithmBB)
  {
    m_a = NAlgorithms::NCommon::min(m_aa, m_bb);
    m_b = NAlgorithms::NCommon::max(m_aa, m_bb);
    m_alpha = m_a + m_b;
    m_beta = NMath::CMath::sqrt((m_alpha - CONSTR(2.0)) / (CONSTR(2.0) * m_a * m_b - m_alpha));
    m_gamma = m_a + CONSTR(1.0) / m_beta;
  }
  // Initialize algorithm BC...
  else
  {
    m_a = NAlgorithms::NCommon::max(m_aa, m_bb);
    m_b = NAlgorithms::NCommon::min(m_aa, m_bb);
    m_alpha = m_a + m_b;
    m_beta = CONSTR(1.0) / m_b;
    m_delta = CONSTR(1.0) + m_a - m_b;
    m_k1 = m_delta * (CONSTR(1.38889E-2) + CONSTR(4.16667E-2) * m_b) / (m_a * m_beta - CONSTR(0.777778));
    m_k2 = CONSTR(0.25) + (CONSTR(0.5) + CONSTR(0.25) / m_delta) * m_b;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Treal CDistributionBeta::randomReal()
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return 0.0;
  }

  Treal w;

  // Algorithm BB...
  if (m_AlgorithmBB)
  {
    Treal r,t;
    do
    {
      Treal u1 = getRandomGeneratorRef().randomInteger() * m_scale;
      Treal u2 = getRandomGeneratorRef().randomInteger() * m_scale;
      Treal v = (m_beta * NMath::CMath::log(u1 / (CONSTR(1.0) - u1)));
      w = (v > m_maxexp) ? NBase::CRealNumber::getMax() : (m_a * NMath::CMath::exp(v));
      Treal z = u1 * u1 * u2;
      r = m_gamma * v - CONSTR(1.3862944);
      Treal s = m_a + r - w;
      if (s + CONSTR(2.609438) >= CONSTR(5.0) * z)
        break;
      t = NMath::CMath::log(z);
      if (s > t)
        break;
    } while (r + m_alpha * NMath::CMath::log(m_alpha / (m_b + w)) < t);
  }
  // Algorithm BC...
  else
  {
loop:
    Treal v, y, z;
    Treal u1 = getRandomGeneratorRef().randomInteger() * m_scale;
    Treal u2 = getRandomGeneratorRef().randomInteger() * m_scale;
    if (u1 < 0.5)
    {
      y = u1 * u2;
      z = u1 * y;
      if (CONSTR(0.25) * u2 + z - y >= m_k1)
        goto loop;
    }
    else
    {
      z = u1 * u1 * u2;
      if (z <= 0.25)
      {
        v = m_beta * NMath::CMath::log(u1 / (CONSTR(1.0) - u1));
        w = (v > m_maxexp) ? NBase::CRealNumber::getMax() : (m_a * NMath::CMath::exp(v));
        goto fin;
      }
      if (z >= m_k2)
        goto loop;
    }
    v = m_beta * NMath::CMath::log(u1 / (CONSTR(1.0) - u1));
    w = (v > m_maxexp) ? NBase::CRealNumber::getMax() : (m_a * NMath::CMath::exp(v));
    if (m_alpha * (NMath::CMath::log(m_alpha / (m_b + w)) + v) - CONSTR(1.3862944) < NMath::CMath::log(z))
      goto loop;
fin:
    NOP;
  }

  // Return result.
  return (NMath::CMath::isEqual(m_a, m_aa)) ? w / (m_b + w) : m_b / (m_b + w);
}
/*--------------------------------------------------------------------------*/
void CDistributionBeta::swap(CDistributionBeta& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IDistribution&)(*this), (IDistribution&)a_rInstance);
  NAlgorithms::NCommon::swap(m_AlgorithmBB, a_rInstance.m_AlgorithmBB);
  NAlgorithms::NCommon::swap(m_aa, a_rInstance.m_aa);
  NAlgorithms::NCommon::swap(m_bb, a_rInstance.m_bb);
  NAlgorithms::NCommon::swap(m_scale, a_rInstance.m_scale);
  NAlgorithms::NCommon::swap(m_a, a_rInstance.m_a);
  NAlgorithms::NCommon::swap(m_alpha, a_rInstance.m_alpha);
  NAlgorithms::NCommon::swap(m_b, a_rInstance.m_b);
  NAlgorithms::NCommon::swap(m_beta, a_rInstance.m_beta);
  NAlgorithms::NCommon::swap(m_delta, a_rInstance.m_delta);
  NAlgorithms::NCommon::swap(m_gamma, a_rInstance.m_gamma);
  NAlgorithms::NCommon::swap(m_k1, a_rInstance.m_k1);
  NAlgorithms::NCommon::swap(m_k2, a_rInstance.m_k2);
  NAlgorithms::NCommon::swap(m_maxexp, a_rInstance.m_maxexp);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
