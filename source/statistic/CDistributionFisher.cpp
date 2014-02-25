/*!
 *  \file    CDistributionFisher.cpp Fisher-Snedecor distribution class.
 *  \brief   Fisher-Snedecor distribution class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Fisher-Snedecor distribution class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:12:41

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
#include <Depth/include/base/CReal.hpp>
#include <Depth/include/statistic/CDistributionFisher.hpp>
/*==========================================================================*/
#ifndef __CDISTRIBUTIONFISHER_CPP__
#define __CDISTRIBUTIONFISHER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CDistributionFisher::set(const CDistributionFisher& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CDistributionFisher class instance."))
  {
    return false;
  }

  // Reinitialize distribution.
  if (!IDistribution::set(a_crInstance))
    return false;

  // Copy distribution state.
  m_NF = a_crInstance.m_NF;
  m_DF = a_crInstance.m_DF;
  m_NumChi2 = a_crInstance.m_NumChi2;
  m_DenomChi2 = a_crInstance.m_DenomChi2;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CDistributionFisher::setParameters(const Treal a_cNumF, const Treal a_cDenomF)
{ CALL
  // Check distribution numerator degrees of freedom parameter.
  ASSERT((a_cNumF > 0.0), STR("Numerator degrees of freedom must be greater than 0.0 (NumF = %r).") COMMA a_cNumF)
  {
    return false;
  }
  // Check distribution denominator degrees of freedom parameter.
  ASSERT((a_cDenomF > 0.0), STR("Denominator degrees of freedom must be greater than 0.0 (DenomF = %r).") COMMA a_cDenomF)
  {
    return false;
  }
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return false;
  }

  // Store parameters.
  m_NF = a_cNumF;
  m_DF = a_cDenomF;

  // Initialize numerator and denominator chi-square distributions.
  if (!m_NumChi2.setRandomGenerator(getRandomGeneratorPtr()) || !m_NumChi2.setParameters(m_NF))
    return false;
  if (!m_DenomChi2.setRandomGenerator(getRandomGeneratorPtr()) || !m_DenomChi2.setParameters(m_DF))
    return false;
  return true;
}
/*--------------------------------------------------------------------------*/
Treal CDistributionFisher::randomReal()
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return 0.0;
  }

 Treal numerator = m_NumChi2.randomReal() / m_NF;
 Treal denominator = m_DenomChi2.randomReal() / m_DF;

 // Return avoiding overflow.
 return (denominator <= numerator * NBase::CRealNumber::getMin()) ? NBase::CRealNumber::getMax() : numerator / denominator;
}
/*--------------------------------------------------------------------------*/
void CDistributionFisher::swap(CDistributionFisher& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IDistribution&)(*this), (IDistribution&)a_rInstance);
  NAlgorithms::NCommon::swap(m_NF, a_rInstance.m_NF);
  NAlgorithms::NCommon::swap(m_DF, a_rInstance.m_DF);
  NAlgorithms::NCommon::swap(m_NumChi2, a_rInstance.m_NumChi2);
  NAlgorithms::NCommon::swap(m_DenomChi2, a_rInstance.m_DenomChi2);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
