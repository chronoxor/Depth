/*!
 *  \file    CDistributionNormal.cpp Normal (Gaussian) distribution class.
 *  \brief   Normal (Gaussian) distribution class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Normal (Gaussian) distribution class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:17:11

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
#include <Depth/include/statistic/CDistributionNormal.hpp>
/*==========================================================================*/
#ifndef __CDISTRIBUTIONNORMAL_CPP__
#define __CDISTRIBUTIONNORMAL_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CDistributionNormal::set(const CDistributionNormal& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CDistributionNormal class instance."))
  {
    return false;
  }

  // Reinitialize distribution.
  if (!IDistribution::set(a_crInstance))
    return false;

  // Copy distribution state.
  m_Cached = a_crInstance.m_Cached;
  m_Cache = a_crInstance.m_Cache;
  m_M = a_crInstance.m_M;
  m_S = a_crInstance.m_S;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CDistributionNormal::setParameters(const Treal a_cMean, const Treal a_cStdDev)
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return false;
  }

  // Store parameters.
  m_Cached = false;
  m_M = a_cMean;
  m_S = a_cStdDev;
  return true;
}
/*--------------------------------------------------------------------------*/
Treal CDistributionNormal::randomReal()
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return 0.0;
  }

  // We have an extra deviate, so unset the flag and return it.
  if (m_Cached)
  {
    m_Cached = false;
    return (m_Cache * m_S + m_M);
  }
  // We don't have an extra deviate.
  else
  {
    // Pick two uniform numbers in the square extending from -1 tp +1
    // in each direction and check if they are in the unit circle.
    Treal v1, v2, r;
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
    return (v2 * f * m_S + m_M);
  }
}
/*--------------------------------------------------------------------------*/
void CDistributionNormal::swap(CDistributionNormal& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IDistribution&)(*this), (IDistribution&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Cached, a_rInstance.m_Cached);
  NAlgorithms::NCommon::swap(m_Cache, a_rInstance.m_Cache);
  NAlgorithms::NCommon::swap(m_M, a_rInstance.m_M);
  NAlgorithms::NCommon::swap(m_S, a_rInstance.m_S);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
