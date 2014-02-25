/*!
 *  \file    CDistributionLogNormal.cpp Log-normal distribution class.
 *  \brief   Log-normal distribution class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Log-normal distribution class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:15:23

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
#include <Depth/include/statistic/CDistributionLogNormal.hpp>
/*==========================================================================*/
#ifndef __CDISTRIBUTIONLOGNORMAL_CPP__
#define __CDISTRIBUTIONLOGNORMAL_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CDistributionLogNormal::set(const CDistributionLogNormal& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CDistributionLogNormal class instance."))
  {
    return false;
  }

  // Reinitialize distribution.
  if (!CDistributionNormal::set(a_crInstance))
    return false;

  // Copy distribution state.
  m_MLog = a_crInstance.m_MLog;
  m_SLog = a_crInstance.m_SLog;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CDistributionLogNormal::setParameters(const Treal a_cMean, const Treal a_cStdDev)
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return false;
  }

  // Set parameters of the base normal (Gaussian) distribution class.
  if (!CDistributionNormal::setParameters(a_cMean, a_cStdDev))
    return false;

  // Set mean and standard deviation of the log-normal distribution.
  m_MLog = a_cMean;
  m_SLog = a_cStdDev;

  // Mean "M" and standard deviation "S" of the corresponding
  // normal distribution which is a base class of this class.
  Treal m2 = m_MLog * m_MLog;
  Treal s2 = m_SLog * m_SLog;
  Treal sm2 = s2 + m2;
  m_M = NMath::CMath::log(m2 / NMath::CMath::sqrt(sm2));
  m_S = NMath::CMath::sqrt(NMath::CMath::log(sm2 / m2));
  return true;
}
/*--------------------------------------------------------------------------*/
Treal CDistributionLogNormal::randomReal()
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return 0.0;
  }

  return NMath::CMath::exp(CDistributionNormal::randomReal());
}
/*--------------------------------------------------------------------------*/
void CDistributionLogNormal::swap(CDistributionLogNormal& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CDistributionNormal&)(*this), (CDistributionNormal&)a_rInstance);
  NAlgorithms::NCommon::swap(m_MLog, a_rInstance.m_MLog);
  NAlgorithms::NCommon::swap(m_SLog, a_rInstance.m_SLog);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
