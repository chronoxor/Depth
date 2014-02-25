/*!
 *  \file    CRay3D.cpp Representation of the ray in a space.
 *  \brief   Ray in a space class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Ray in a space class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   10.07.2008 23:31:54

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
#include <Depth/include/geometry.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/geometry/CRay3D.hpp>
/*==========================================================================*/
#ifndef __CRAY3D_CPP__
#define __CRAY3D_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
void CRay3D::set(const CPoint3D<Treal>& a_crOrigin, const CVector3D& a_crDirection)
{ CALL
  m_Origin.set(a_crOrigin);
  m_Direction.set(a_crDirection);
  m_Direction.normalize();
}
/*--------------------------------------------------------------------------*/
void CRay3D::set(const CPoint3D<Treal>& a_crA, const CPoint3D<Treal>& a_crB)
{ CALL
  m_Origin.set(a_crA);
  m_Direction.set(a_crB - a_crA);
  m_Direction.normalize();
}
/*--------------------------------------------------------------------------*/
CPoint3D<Treal> CRay3D::getOffsetPoint(const Treal a_cOffset) const
{ CALL
  return CPoint3D<Treal>(m_Origin.m_X + m_Direction.m_X * a_cOffset, m_Origin.m_Y + m_Direction.m_Y * a_cOffset, m_Origin.m_Z + m_Direction.m_Z * a_cOffset);
}
/*--------------------------------------------------------------------------*/
Treal CRay3D::getDistanceToPoint(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  return (m_Direction * CVector3D::dot(m_Direction, CVector3D(a_crPoint3D - m_Origin)) + CVector3D(m_Origin - a_crPoint3D)).length();
}
/*--------------------------------------------------------------------------*/
Treal CRay3D::getDistanceToPointSq(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  return (m_Direction * CVector3D::dot(m_Direction, CVector3D(a_crPoint3D - m_Origin)) + CVector3D(m_Origin - a_crPoint3D)).lengthSq();
}
/*--------------------------------------------------------------------------*/
CPoint3D<Treal> CRay3D::mirrorPoint(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  CVector3D temp(a_crPoint3D - m_Origin);
  CVector3D result = CVector3D::mirror(temp, m_Direction);

  result += m_Origin;
  return CPoint3D<Treal>(result.m_X, result.m_Y, result.m_Z);
}
/*--------------------------------------------------------------------------*/
CVector3D CRay3D::mirrorNormal(const CVector3D& a_crNormal) const
{ CALL
  return CVector3D::mirror(a_crNormal, m_Direction);
}
/*--------------------------------------------------------------------------*/
CPoint3D<Treal> CRay3D::project(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  return getOffsetPoint(CVector3D::dot(m_Direction, CVector3D(a_crPoint3D - m_Origin)));
}
/*--------------------------------------------------------------------------*/
Tbool CRay3D::isCollinear(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2)
{ CALL
  Treal A00 = a_crInstance1.m_Direction.lengthSq();
  Treal A01 = -CVector3D::dot(a_crInstance1.m_Direction, a_crInstance2.m_Direction);
  Treal A11 = a_crInstance2.m_Direction.lengthSq();

  return (NMath::CMath::isEqualZero(A00 * A11 - A01 * A01));
}
/*--------------------------------------------------------------------------*/
Tbool CRay3D::isIntersect(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2)
{ CALL
  if (!isCollinear(a_crInstance1, a_crInstance2))
  {
    Treal offset1, offset2;
    return (distanceSq(a_crInstance1, a_crInstance2, offset1, offset2) < NMath::CMath::getEpsilon() * NMath::CMath::getEpsilon());
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CRay3D::isParallel(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2)
{ CALL
  if (isCollinear(a_crInstance1, a_crInstance2))
  {
    CVector3D diff = a_crInstance1.m_Origin - a_crInstance2.m_Origin;
    Treal A00 = a_crInstance1.m_Direction.lengthSq();
    Treal B0 = CVector3D::dot(diff, a_crInstance1.m_Direction);
    return ((B0 * (-B0 / A00) + diff.lengthSq()) >= NMath::CMath::getEpsilon() * NMath::CMath::getEpsilon());
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CRay3D::isStraight(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2)
{ CALL
  if (isCollinear(a_crInstance1, a_crInstance2))
  {
    CVector3D diff = a_crInstance1.m_Origin - a_crInstance2.m_Origin;
    Treal A00 = a_crInstance1.m_Direction.lengthSq();
    Treal B0 = CVector3D::dot(diff, a_crInstance1.m_Direction);
    return ((B0 * (-B0 / A00) + diff.lengthSq()) < NMath::CMath::getEpsilon() * NMath::CMath::getEpsilon());
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Treal CRay3D::distanceSq(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2, Treal& a_rOffset1, Treal& a_rOffset2)
{ CALL
  CVector3D diff = a_crInstance1.m_Origin - a_crInstance2.m_Origin;
  Treal A00 = a_crInstance1.m_Direction.lengthSq();
  Treal A01 = -CVector3D::dot(a_crInstance1.m_Direction, a_crInstance2.m_Direction);
  Treal A11 = a_crInstance2.m_Direction.lengthSq();
  Treal B0 = CVector3D::dot(diff, a_crInstance1.m_Direction);
  Treal C = diff.lengthSq();
  Treal det = NMath::CMath::fabs(A00 * A11 - A01 * A01);

  if (det >= NMath::CMath::getEpsilon())
  {
    // Rays are not parallel.
    Treal B1 = -CVector3D::dot(diff, a_crInstance2.m_Direction);
    det = CONSTR(1.0) / det;
    a_rOffset1 = (A01 * B1 - A11 * B0) * det;
    a_rOffset2 = (A01 * B0 - A00 * B1) * det;
    return (a_rOffset1 * (A00 * a_rOffset1 + A01 * a_rOffset2 + CONSTR(2.0) * B0) + a_rOffset2 * (A01 * a_rOffset1 + A11 * a_rOffset2 + CONSTR(2.0) * B1) + C);
  }
  else
  {
    // Rays are parallel, select any closest pair of points.
    a_rOffset1 = -B0 / A00;
    a_rOffset2 = 0.0;
    return (B0 * a_rOffset1 + C);
  }
}
/*--------------------------------------------------------------------------*/
Treal CRay3D::distanceSq(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2, CPoint3D<Treal>& a_rFirstPoint3D, CPoint3D<Treal>& a_rSecondPoint3D)
{ CALL
  Treal offset1, offset2;
  Treal result = distanceSq(a_crInstance1, a_crInstance2, offset1, offset2);

  // Calculate points on a rays.
  a_rFirstPoint3D = a_crInstance1.getOffsetPoint(offset1);
  a_rSecondPoint3D = a_crInstance2.getOffsetPoint(offset2);
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
