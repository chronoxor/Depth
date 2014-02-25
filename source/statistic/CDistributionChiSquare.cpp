/*!
 *  \file    CDistributionChiSquare.cpp Chi-square distribution class.
 *  \brief   Chi-square distribution class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Chi-square distribution class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:01:12

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
#include <Depth/include/statistic/CDistributionChiSquare.hpp>
/*==========================================================================*/
#ifndef __CDISTRIBUTIONCHISQUARE_CPP__
#define __CDISTRIBUTIONCHISQUARE_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CDistributionChiSquare::set(const CDistributionChiSquare& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CDistributionChiSquare class instance."))
  {
    return false;
  }

  // Reinitialize distribution.
  if (!CDistributionGamma::set(a_crInstance))
    return false;

  // Copy distribution state.
  m_F = a_crInstance.m_F;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CDistributionChiSquare::setParameters(const Treal a_cFreedom)
{ CALL
  // Check distribution degrees of freedom parameter.
  ASSERT((a_cFreedom > 0.0), STR("Degrees of freedom parameter must be greater than 0.0 (Freedom = %r).") COMMA a_cFreedom)
  {
    return false;
  }
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return false;
  }

  // Set parameters of the base Gamma distribution class.
  if (!CDistributionGamma::setParameters(CONSTR(0.5) * a_cFreedom, CONSTR(1.0)))
    return false;

  // Store parameters.
  m_F = a_cFreedom;
  return true;
}
/*--------------------------------------------------------------------------*/
Treal CDistributionChiSquare::randomReal()
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return 0.0;
  }

  return CONSTR(2.0) * CDistributionGamma::randomReal();
}
/*--------------------------------------------------------------------------*/
void CDistributionChiSquare::swap(CDistributionChiSquare& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CDistributionGamma&)(*this), (CDistributionGamma&)a_rInstance);
  NAlgorithms::NCommon::swap(m_F, a_rInstance.m_F);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
