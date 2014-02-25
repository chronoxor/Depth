/*!
 *  \file    CDistributionErlang.cpp Erlang distribution class.
 *  \brief   Erlang distribution class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Erlang distribution class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:07:33

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
#include <Depth/include/statistic/CDistributionErlang.hpp>
/*==========================================================================*/
#ifndef __CDISTRIBUTIONERLANG_CPP__
#define __CDISTRIBUTIONERLANG_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CDistributionErlang::set(const CDistributionErlang& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CDistributionErlang class instance."))
  {
    return false;
  }

  // Reinitialize distribution.
  if (!IDistribution::set(a_crInstance))
    return false;

  // Copy distribution state.
  m_A = a_crInstance.m_A;
  m_B = a_crInstance.m_B;
  m_a1 = a_crInstance.m_a1;
  m_sq = a_crInstance.m_sq;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CDistributionErlang::setParameters(const Tuint a_cOrder, const Treal a_cLocation)
{ CALL
  // Check distribution order parameter.
  ASSERT((a_cOrder >= 1), STR("Order parameter must be greater or equal to 1 (Order = %u).") COMMA a_cOrder)
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
  m_A = a_cOrder;
  m_B = a_cLocation;

  // Auxilliary...
  m_a1 = m_A - CONSTR(1.0);
  m_sq = NMath::CMath::sqrt(CONSTR(2.0) * m_a1 + CONSTR(1.0));
  return true;
}
/*--------------------------------------------------------------------------*/
Treal CDistributionErlang::randomReal()
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return 0.0;
  }

  if (m_A < 6)
  {
    // Direct method...
    Treal x;
    do
    {
      x = getRandomGeneratorRef().randomReal();
      for (Tuint i = 1; i < m_A; i++)
        x *= getRandomGeneratorRef().randomReal();
    } while (x <= 0.0);
    return -NMath::CMath::log(x) / m_B;
  }
  else
  {
    // Rejection method...
    Treal x, y, b;
    do
    {
      do
      {
        Treal v1, v2;
        do
        {
         v1 = CONSTR(2.0) * getRandomGeneratorRef().randomReal() - CONSTR(1.0);
         v2 = CONSTR(2.0) * getRandomGeneratorRef().randomReal() - CONSTR(1.0);
        } while (NMath::CMath::isEqualZero(v1) || (v1 * v1 + v2 * v2 > 1.0));
        y = v2 / v1;
        x = m_sq * y + m_a1;
      } while (x <= 0.0);
      b = (CONSTR(1.0) + y * y) * NMath::CMath::exp(m_a1 * NMath::CMath::log(x / m_a1) - m_sq * y);
    } while (getRandomGeneratorRef().randomReal() > b);
    return x / m_B;
  }
}
/*--------------------------------------------------------------------------*/
void CDistributionErlang::swap(CDistributionErlang& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IDistribution&)(*this), (IDistribution&)a_rInstance);
  NAlgorithms::NCommon::swap(m_A, a_rInstance.m_A);
  NAlgorithms::NCommon::swap(m_B, a_rInstance.m_B);
  NAlgorithms::NCommon::swap(m_a1, a_rInstance.m_a1);
  NAlgorithms::NCommon::swap(m_sq, a_rInstance.m_sq);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
