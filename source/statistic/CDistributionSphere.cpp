/*!
 *  \file    CDistributionSphere.cpp Sphere distribution class.
 *  \brief   Sphere distribution class (source).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    09.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sphere distribution class (source).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   09.03.2009 03:59:07

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
#include <Depth/include/statistic/CDistributionSphere.hpp>
/*==========================================================================*/
#ifndef __CDISTRIBUTIONSPHERE_CPP__
#define __CDISTRIBUTIONSPHERE_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CDistributionSphere::set(const CDistributionSphere& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CDistributionSphere class instance."))
  {
    return false;
  }

  // Reinitialize distribution.
  if (!IDistribution::set(a_crInstance))
    return false;

  // Copy distribution state.
  m_Origin = a_crInstance.m_Origin;
  m_Scale = a_crInstance.m_Scale;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CDistributionSphere::setParameters(const NGeometry::CPoint3D<Treal>& a_crOrigin, const NGeometry::CVector3D a_crScale)
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return false;
  }

  // Store parameters.
  m_Origin = a_crOrigin;
  m_Scale = a_crScale;
  return true;
}
/*--------------------------------------------------------------------------*/
NGeometry::CPoint3D<Treal> CDistributionSphere::randomPoint()
{ CALL
  // Check that random number generator is valid for the current distribution.
  ASSERT(isValidGenerator(), STR("Random number generator is not valid for the current distribution."))
  {
    return NGeometry::CPoint3D<Treal>(0.0, 0.0, 0.0);
  }

  Treal x = 0.0;
  Treal y = 0.0;
  Treal z = 0.0;
  while (true)
  {
    Treal d1 = CONSTR(1.0) - CONSTR(2.0) * getRandomGeneratorRef().randomReal();
    Treal d2 = CONSTR(1.0) - CONSTR(2.0) * getRandomGeneratorRef().randomReal();
    Treal dd = d1 * d1 + d2 * d2;
    if (dd < 1.0)
    {
      z = (CONSTR(1.0) - CONSTR(2.0) * dd) * m_Scale.m_Z + m_Origin.m_Z;
      dd = CONSTR(2.0) * NMath::CMath::sqrt(CONSTR(1.0) - dd);
      x = d1 * dd * m_Scale.m_X + m_Origin.m_X;
      y = d2 * dd * m_Scale.m_Y + m_Origin.m_Y;
      break;
    }
  }
  return NGeometry::CPoint3D<Treal>(x, y, z);
}
/*--------------------------------------------------------------------------*/
void CDistributionSphere::swap(CDistributionSphere& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((IDistribution&)(*this), (IDistribution&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Origin, a_rInstance.m_Origin);
  NAlgorithms::NCommon::swap(m_Scale, a_rInstance.m_Scale);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
