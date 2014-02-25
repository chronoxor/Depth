/*!
 *  \file    CDistributionBinomial.cpp Binomial distribution class.
 *  \brief   Binomial distribution class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Binomial distribution class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:54:41

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
#include <Depth/include/statistic/CDistributionBinomial.hpp>
/*==========================================================================*/
#ifndef __CDISTRIBUTIONBINOMIAL_CPP__
#define __CDISTRIBUTIONBINOMIAL_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CDistributionBinomial::set(const CDistributionBinomial& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CDistributionBinomial class instance."))
  {
    return false;
  }

  // Reinitialize distribution.
  if (!IDistribution::set(a_crInstance))
    return false;

  // Copy distribution state.
  m_N = a_crInstance.m_N;
  m_Sym = a_crInstance.m_Sym;
  m_Scale = a_crInstance.m_Scale;
  m_ScalePI = a_crInstance.m_ScalePI;
  m_P = a_crInstance.m_P;
  m_Pc = a_crInstance.m_Pc;
  m_Plog = a_crInstance.m_Plog;
  m_Pclog = a_crInstance.m_Pclog;
  m_Np = a_crInstance.m_Np;
  m_Npexp = a_crInstance.m_Npexp;
  m_En = a_crInstance.m_En;
  m_En1 = a_crInstance.m_En1;
  m_Gamen1 = a_crInstance.m_Gamen1;
  m_Sq = a_crInstance.m_Sq;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CDistributionBinomial::setParameters(const Treal a_cProb, const Tuint a_cN)
{ CALL
  // Check distribution probability argument.
  ASSERT(((a_cProb >= 0.0) && (a_cProb <= 1.0)), STR("Probability argument of the binomial distribution must be in the [0.0, 1.0] interval (Prob = %r).") COMMA a_cProb)
  {
    return false;
  }
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return false;
  }

  // Store parameters.
  m_Scale = CONSTR(1.0) / getRandomGeneratorRef().getMaxInteger();
  m_ScalePI = NMath::CMathConstants::PI / getRandomGeneratorRef().getMaxInteger();

  if (a_cProb <= 0.5)
  {
    // Use invariance under p <==> 1-p.
    m_P = a_cProb;
    m_Sym = false;
  }
  else
  {
    m_P = CONSTR(1.0) - a_cProb;
    m_Sym = true;
  }

  m_N = a_cN;
  m_Np = m_N * m_P;
  m_Npexp = NMath::CMath::exp(-m_Np);
  m_En = (Treal)m_N;
  m_En1 = m_En + CONSTR(1.0);
  m_Gamen1 = NMath::CMath::logGamma(m_En1);
  m_Pc = CONSTR(1.0) - m_P;
  m_Plog = NMath::CMath::log(m_P);
  m_Pclog = NMath::CMath::log(m_Pc);
  m_Sq = NMath::CMath::sqrt(CONSTR(2.0) * m_Np * m_Pc);
  return true;
}
/*--------------------------------------------------------------------------*/
Treal CDistributionBinomial::randomReal()
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return 0.0;
  }

  Treal bnl;

  if (m_N < 25)
  {
    // Direct method for moderate n.
    bnl = 0.0;
    for (Tuint j = 0; j < m_N; j++)
      if (m_Scale * getRandomGeneratorRef().randomInteger() < m_P)
        bnl++;
  }
  else
  {
    if (m_Np < 1.0)
    {
      // Use direct Poisson method.
      Tuint j;
      Treal t = 1.0;
      for (j = 0; j <= m_N; j++)
      {
        t *= m_Scale * getRandomGeneratorRef().randomInteger();
        if (t < m_Npexp)
          break;
      }
      bnl = (Treal)((j <= m_N) ? j : m_N);
    }
    else
    {
      // Use rejection method.
      Treal em, y, t;
      do
      {
        do
        {
          y = NMath::CMath::tan(m_ScalePI * getRandomGeneratorRef().randomInteger());
          em = m_Sq * y + m_Np;
        } while ((em < 0.0) || (em >= m_En1));
        em = NMath::CMath::floor(em);
        t = CONSTR(1.2) * m_Sq * (CONSTR(1.0) + y * y) * NMath::CMath::exp(m_Gamen1 - NMath::CMath::logGamma(em + CONSTR(1.0)) - NMath::CMath::logGamma(m_En1 - em) + em * m_Plog + (m_En - em) * m_Pclog);
      } while (m_Scale * getRandomGeneratorRef().randomInteger() > t);
      bnl = em;
    }
  }
  if (m_Sym)
  {
    // Undo symmetry transformation.
    bnl = m_N - bnl;
  }
  return bnl;
}
/*--------------------------------------------------------------------------*/
void CDistributionBinomial::swap(CDistributionBinomial& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IDistribution&)(*this), (IDistribution&)a_rInstance);
  NAlgorithms::NCommon::swap(m_N, a_rInstance.m_N);
  NAlgorithms::NCommon::swap(m_Sym, a_rInstance.m_Sym);
  NAlgorithms::NCommon::swap(m_Scale, a_rInstance.m_Scale);
  NAlgorithms::NCommon::swap(m_ScalePI, a_rInstance.m_ScalePI);
  NAlgorithms::NCommon::swap(m_P, a_rInstance.m_P);
  NAlgorithms::NCommon::swap(m_Pc, a_rInstance.m_Pc);
  NAlgorithms::NCommon::swap(m_Plog, a_rInstance.m_Plog);
  NAlgorithms::NCommon::swap(m_Pclog, a_rInstance.m_Pclog);
  NAlgorithms::NCommon::swap(m_Np, a_rInstance.m_Np);
  NAlgorithms::NCommon::swap(m_Npexp, a_rInstance.m_Npexp);
  NAlgorithms::NCommon::swap(m_En, a_rInstance.m_En);
  NAlgorithms::NCommon::swap(m_En1, a_rInstance.m_En1);
  NAlgorithms::NCommon::swap(m_Gamen1, a_rInstance.m_Gamen1);
  NAlgorithms::NCommon::swap(m_Sq, a_rInstance.m_Sq);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
