/*!
 *  \file    CDistributionGamma.cpp Gamma distribution class.
 *  \brief   Gamma distribution class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Gamma distribution class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:13:55

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
#include <Depth/include/algorithms/numeric/ACopySign.hpp>
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/statistic/CDistributionGamma.hpp>
/*==========================================================================*/
#ifndef __CDISTRIBUTIONGAMMA_CPP__
#define __CDISTRIBUTIONGAMMA_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CDistributionGamma::set(const CDistributionGamma& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CDistributionGamma class instance."))
  {
    return false;
  }

  // Reinitialize distribution.
  if (!IDistribution::set(a_crInstance))
    return false;

  // Copy distribution state.
  m_AlgorithmGD = a_crInstance.m_AlgorithmGD;
  m_Cached = a_crInstance.m_Cached;
  m_Cache = a_crInstance.m_Cache;
  m_A = a_crInstance.m_A;
  m_B = a_crInstance.m_B;
  m_s = a_crInstance.m_s;
  m_s2 = a_crInstance.m_s2;
  m_d = a_crInstance.m_d;
  m_r = a_crInstance.m_r;
  m_q0 = a_crInstance.m_q0;
  m_b = a_crInstance.m_b;
  m_si = a_crInstance.m_si;
  m_c = a_crInstance.m_c;
  m_scale = a_crInstance.m_scale;
  m_M = a_crInstance.m_M;
  m_S = a_crInstance.m_S;
  m_MExp = a_crInstance.m_MExp;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CDistributionGamma::setParameters(const Treal a_cOrder, const Treal a_cLocation)
{ CALL
  // Check distribution order parameter.
  ASSERT((a_cOrder > 0.0), STR("Order parameter must be greater than 0.0 (Order = %r).") COMMA a_cOrder)
  {
    return false;
  }
  // Check distribution location parameter.
  ASSERT(!NMath::CMath::isEqualZero(a_cLocation), STR("Location parameter must not be equal to 0.0 (Location = %r).") COMMA a_cLocation)
  {
    return false;
  }
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return false;
  }

  // Store parameters.
  m_Cached = false;
  m_M = 0.0;
  m_S = 1.0;
  m_MExp = 1.0;

  // Store parameters: A is the mean of the standard gamma distribution (b = 0).
  m_A = a_cOrder;
  m_B = a_cLocation;

  // Scale random long to (0,1) - boundaries are not allowed!
  m_scale = CONSTR(1.0) / (getRandomGeneratorRef().getMaxInteger() + CONSTR(1.0));

  // Select algorithm.
  m_AlgorithmGD = (m_A >= 1.0);

  // Initialize algorithm GD...
  if (m_AlgorithmGD)
  {
    // Coefficients q(k) for q0 = sum(q(k) * a ** (-k)).
    const Treal q1 = (Treal)4.166669e-2;
    const Treal q2 = (Treal)2.083148e-2;
    const Treal q3 = (Treal)8.01191e-3;
    const Treal q4 = (Treal)1.44121e-3;
    const Treal q5 = (Treal)-7.388e-5;
    const Treal q6 = (Treal)2.4511e-4;
    const Treal q7 = (Treal)2.424e-4;

    // Calculates s, s2, and d.
    m_s2 = m_A - CONSTR(0.5);
    m_s = NMath::CMath::sqrt(m_s2);
    m_d = NMath::CMath::sqrt(CONSTR(32.0)) - CONSTR(12.0) * m_s;

    // Calculate q0, b, si, and c.
    m_r = CONSTR(1.0) / m_A;
    m_q0 = ((((((q7 * m_r + q6) * m_r + q5) * m_r + q4) * m_r + q3) * m_r + q2) * m_r + q1) * m_r;

    // Approximation depending on size of parameter A.
    // The constants in the expressions for b, si, and
    // c were established by numerical experiments.
    if (m_A <= 3.686)
    {
      // Case 1.0 <= A <= 3.686.
      m_b = CONSTR(0.463) + m_s + CONSTR(0.178) * m_s2;
      m_si = CONSTR(1.235);
      m_c = CONSTR(0.195) / m_s - CONSTR(7.9e-2) + CONSTR(1.6e-1) * m_s;
    }
    else
    {
      if (m_A <= 13.022)
      {
       // Case 3.686 < A <= 13.022.
       m_b = CONSTR(1.654) + CONSTR(7.6e-3) * m_s2;
       m_si = CONSTR(1.68) / m_s + CONSTR(0.275);
       m_c = CONSTR(6.2e-2) / m_s + CONSTR(2.4e-2);
      }
      else
      {
        // Case A > 13.022.
        m_b = CONSTR(1.77);
        m_si = CONSTR(0.75);
        m_c = CONSTR(0.1515) / m_s;
      }
    }
  }
  else
  {
    // Initialize algorithm GS...
    m_b = CONSTR(1.0) + CONSTR(0.3678794) * m_A;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Treal CDistributionGamma::randomReal()
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return 0.0;
  }

  // Algorithm GD for A >= 1.
  if (m_AlgorithmGD)
  {
    // Coefficients a(k) for q = q0 + (t * t / 2) * sum(a(k) * v ** k).
    const Treal a1 = (Treal)0.3333333;
    const Treal a2 = (Treal)-0.250003;
    const Treal a3 = (Treal)0.2000062;
    const Treal a4 = (Treal)-0.1662921;
    const Treal a5 = (Treal)0.1423657;
    const Treal a6 = (Treal)-0.1367177;
    const Treal a7 = (Treal)0.1233795;

    // Coefficients e(k) for exp(q) - 1 = sum(e(k) * q ** k)
    const Treal e1 = (Treal)1.0;
    const Treal e2 = (Treal)0.4999897;
    const Treal e3 = (Treal)0.166829;
    const Treal e4 = (Treal)4.07753E-2;
    const Treal e5 = (Treal)1.0293E-2;

    Treal q,w,gamdis;

    // Standard normal deviate.
    Treal t;

    // We have an extra deviate, so unset the flag and return it.
    if (m_Cached)
    {
      m_Cached = false;
      t = (m_Cache * m_S + m_M);
    }
    // We don't have an extra deviate.
    else
    {
      // Pick two uniform numbers in the square extending from -1 tp +1
      // in each direction and check if they are in the unit circle.
      Treal v1,v2,r;
      do
      {
        // Scale maps the random long to [0.0, 2.0].
        v1 = CONSTR(2.0) * getRandomGeneratorRef().randomReal() - CONSTR(1.0);
        v2 = CONSTR(2.0) * getRandomGeneratorRef().randomReal() - CONSTR(1.0);
        r = v1 * v1 + v2 * v2;
      } while (r >= 1.0);

      Treal f = NMath::CMath::sqrt((CONSTR(-2.0) * NMath::CMath::log(r)) / r);

      // Make Box-Muller transformation to get two normal deviates.
      // Return one and save the other for the next time.
      m_Cache = v1 * f;
      m_Cached = true;
      t = (v2 * f * m_S + m_M);
    }

    // (s,1/2)-normal deviate.
    Treal x = m_s + CONSTR(0.5) * t;

    // Immediate acceptance.
    gamdis = x * x;
    if (t >= 0.0)
      return gamdis / m_B;

    // (0,1) uniform sample, squeeze acceptance.
    Treal u = getRandomGeneratorRef().randomInteger() * m_scale;
    if (m_d * u <= t * t * t)
      return gamdis / m_B;

    // No quotient test if x not positive.
    if (x > 0.0)
    {
      // Calculation of v and quotient q.
      Treal v = t / (m_s + m_s);
      if (NMath::CMath::fabs(v) <= 0.25)
        q = m_q0 + CONSTR(0.5) * t * t * ((((((a7 * v + a6) * v + a5) * v + a4) * v + a3) * v + a2) * v + a1) * v;
      else
        q = m_q0 - m_s * t + CONSTR(0.25) * t * t + (m_s2 + m_s2) * NMath::CMath::log(CONSTR(1.0) + v);

      // Quotient acceptance.
      if (NMath::CMath::log(CONSTR(1.0) - u) <= q)
        return gamdis / m_B;
    }

loop:
    // Stdandard exponential deviate.
    Treal e = -m_MExp * NMath::CMath::log(getRandomGeneratorRef().randomReal());

    // (0,1) uniform deviate.
    u = getRandomGeneratorRef().randomInteger() * m_scale;
    u += (u - CONSTR(1.0));

    // (b,si) double exponential (Laplace).
    t = m_b + NAlgorithms::NNumeric::copySign(m_si * e, u);

    // Rejection if t < tau(1) = -0.71874483771719.
    if (t < -0.71874483771719)
      goto loop;

    // Calculation of v and quotient q.
    Treal v = t / (m_s + m_s);
    if (NMath::CMath::fabs(v) <= 0.25)
      q = m_q0 + CONSTR(0.5) * t * t * ((((((a7 * v + a6) * v + a5) * v + a4) * v + a3) * v + a2) * v + a1) * v;
    else
      q = m_q0 - m_s * t + CONSTR(0.25) * t * t + (m_s2 + m_s2) * NMath::CMath::log(CONSTR(1.0) + v);

    // Hat acceptance.
    if (q <= 0.0)
      goto loop;

    if (q <= 0.5)
      w = ((((e5 * q + e4) * q + e3) * q + e2) * q + e1) * q;
    else
      w = NMath::CMath::exp(q) - CONSTR(1.0);

    // If t is rejected, sample again.
    if (m_c * NMath::CMath::fabs(u) > w * NMath::CMath::exp(e - CONSTR(0.5) * t * t))
      goto loop;

    x = m_s + CONSTR(0.5) * t;
    gamdis = x * x;
    return gamdis / m_B;
  }
  else
  {
    // Algorithm GS for 0 < A < 1.
    Treal gamdis;
    for (;;)
    {
      Treal p = m_b * getRandomGeneratorRef().randomInteger() * m_scale;
      if (p < 1.0)
      {
        gamdis = NMath::CMath::exp(NMath::CMath::log(p) / m_A);
        if (-m_MExp * NMath::CMath::log(getRandomGeneratorRef().randomReal()) >= gamdis)
          return gamdis / m_B;
      }
      else
      {
        gamdis = -NMath::CMath::log((m_b - p) / m_A);
        if (-m_MExp * NMath::CMath::log(getRandomGeneratorRef().randomReal()) >= (CONSTR(1.0) - m_A) * NMath::CMath::log(gamdis))
          return gamdis / m_B;
      }
    }
  }
}
/*--------------------------------------------------------------------------*/
void CDistributionGamma::swap(CDistributionGamma& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IDistribution&)(*this), (IDistribution&)a_rInstance);
  NAlgorithms::NCommon::swap(m_AlgorithmGD, a_rInstance.m_AlgorithmGD);
  NAlgorithms::NCommon::swap(m_Cached, a_rInstance.m_Cached);
  NAlgorithms::NCommon::swap(m_Cache, a_rInstance.m_Cache);
  NAlgorithms::NCommon::swap(m_A, a_rInstance.m_A);
  NAlgorithms::NCommon::swap(m_B, a_rInstance.m_B);
  NAlgorithms::NCommon::swap(m_s, a_rInstance.m_s);
  NAlgorithms::NCommon::swap(m_s2, a_rInstance.m_s2);
  NAlgorithms::NCommon::swap(m_d, a_rInstance.m_d);
  NAlgorithms::NCommon::swap(m_r, a_rInstance.m_r);
  NAlgorithms::NCommon::swap(m_q0, a_rInstance.m_q0);
  NAlgorithms::NCommon::swap(m_b, a_rInstance.m_b);
  NAlgorithms::NCommon::swap(m_si, a_rInstance.m_si);
  NAlgorithms::NCommon::swap(m_c, a_rInstance.m_c);
  NAlgorithms::NCommon::swap(m_scale, a_rInstance.m_scale);
  NAlgorithms::NCommon::swap(m_M, a_rInstance.m_M);
  NAlgorithms::NCommon::swap(m_S, a_rInstance.m_S);
  NAlgorithms::NCommon::swap(m_MExp, a_rInstance.m_MExp);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
