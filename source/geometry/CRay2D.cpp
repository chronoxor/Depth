/*!
 *  \file    CRay2D.cpp Representation of the ray on a plane.
 *  \brief   Ray on a plane class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Ray on a plane class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   09.07.2008 23:25:34

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
#include <Depth/include/geometry/CRay2D.hpp>
/*==========================================================================*/
#ifndef __CRAY2D_CPP__
#define __CRAY2D_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
void CRay2D::set(const CPoint2D<Treal>& a_crOrigin, const CVector2D& a_crDirection)
{ CALL
  m_Origin.set(a_crOrigin);
  m_Direction.set(a_crDirection);
  m_Direction.normalize();
}
/*--------------------------------------------------------------------------*/
void CRay2D::set(const CPoint2D<Treal>& a_crA, const CPoint2D<Treal>& a_crB)
{ CALL
  m_Origin.set(a_crA);
  m_Direction.set(a_crB - a_crA);
  m_Direction.normalize();
}
/*--------------------------------------------------------------------------*/
CPoint2D<Treal> CRay2D::getOffsetPoint(const Treal a_cOffset) const
{ CALL
  return CPoint2D<Treal>(m_Origin.m_X + m_Direction.m_X * a_cOffset, m_Origin.m_Y + m_Direction.m_Y * a_cOffset);
}
/*--------------------------------------------------------------------------*/
Treal CRay2D::getDistanceToPoint(const CPoint2D<Treal>& a_crPoint2D) const
{ CALL
  return (m_Direction * CVector2D::dot(m_Direction, CVector2D(a_crPoint2D - m_Origin)) + CVector2D(m_Origin - a_crPoint2D)).length();
}
/*--------------------------------------------------------------------------*/
Treal CRay2D::getDistanceToPointSq(const CPoint2D<Treal>& a_crPoint2D) const
{ CALL
  return (m_Direction * CVector2D::dot(m_Direction, CVector2D(a_crPoint2D - m_Origin)) + CVector2D(m_Origin - a_crPoint2D)).lengthSq();
}
/*--------------------------------------------------------------------------*/
CPoint2D<Treal> CRay2D::mirrorPoint(const CPoint2D<Treal>& a_crPoint2D) const
{ CALL
  CVector2D temp(a_crPoint2D - m_Origin);
  CVector2D result = CVector2D::mirror(temp, m_Direction);

  result += m_Origin;
  return CPoint2D<Treal>(result.m_X, result.m_Y);
}
/*--------------------------------------------------------------------------*/
CVector2D CRay2D::mirrorNormal(const CVector2D& a_crNormal) const
{ CALL
  return CVector2D::mirror(a_crNormal, m_Direction);
}
/*--------------------------------------------------------------------------*/
CPoint2D<Treal> CRay2D::project(const CPoint2D<Treal>& a_crPoint2D) const
{ CALL
  return getOffsetPoint(CVector2D::dot(m_Direction, CVector2D(a_crPoint2D - m_Origin)));
}
/*--------------------------------------------------------------------------*/
Tbool CRay2D::isIntersect(const CRay2D& a_crInstance1, const CRay2D& a_crInstance2)
{ CALL
  Treal det = CVector2D::zcomp(a_crInstance2.m_Direction, a_crInstance1.m_Direction);

  return (det * det > a_crInstance1.m_Direction.lengthSq() * a_crInstance2.m_Direction.lengthSq() * NMath::CMath::getEpsilon());
}
/*--------------------------------------------------------------------------*/
Tbool CRay2D::isParallel(const CRay2D& a_crInstance1, const CRay2D& a_crInstance2)
{ CALL
  if (!isIntersect(a_crInstance1, a_crInstance2))
  {
    CVector2D origins_diff = a_crInstance2.m_Origin - a_crInstance1.m_Origin;
    Treal det = CVector2D::zcomp(a_crInstance1.m_Direction, origins_diff);
    return (det * det >= a_crInstance1.m_Direction.lengthSq() * origins_diff.lengthSq() * NMath::CMath::getEpsilon());
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CRay2D::isStraight(const CRay2D& a_crInstance1, const CRay2D& a_crInstance2)
{ CALL
  if (!isIntersect(a_crInstance1, a_crInstance2))
  {
    CVector2D origins_diff = a_crInstance2.m_Origin - a_crInstance1.m_Origin;
    Treal det = CVector2D::zcomp(a_crInstance1.m_Direction, origins_diff);
    return (det * det < a_crInstance1.m_Direction.lengthSq() * origins_diff.lengthSq() * NMath::CMath::getEpsilon());
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CRay2D::intersect(const CRay2D& a_crInstance1, const CRay2D& a_crInstance2, Treal& a_rOffset1, Treal& a_rOffset2)
{ CALL
  // Intersection is a solution to P0+s*D0 = P1+t*D1.  Rewrite as
  // s*D0 - t*D1 = P1 - P0, a 2x2 system of equations.  If D0 = (x0,y0)
  // and D1 = (x1,y1) and P1 - P0 = (c0,c1), then the system is
  // x0*s - x1*t = c0 and y0*s - y1*t = c1.  The error tests are relative
  // to the size of the direction vectors, |Cross(D0,D1)| >= e*|D0|*|D1|
  // rather than absolute tests |Cross(D0,D1)| >= e.  The quantities
  // P1-P0, |D0|^2, and |D1|^2 are returned for use by calling functions.
  Treal det = CVector2D::zcomp(a_crInstance2.m_Direction, a_crInstance1.m_Direction);
  CVector2D origins_diff = a_crInstance2.m_Origin - a_crInstance1.m_Origin;

  if (det * det > a_crInstance1.m_Direction.lengthSq() * a_crInstance2.m_Direction.lengthSq() * NMath::CMath::getEpsilon())
  {
    det = CONSTR(1.0) / det;
    a_rOffset1 = CVector2D::zcomp(a_crInstance2.m_Direction, origins_diff) * det;
    a_rOffset2 = CVector2D::zcomp(a_crInstance1.m_Direction, origins_diff) * det;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CRay2D::intersect(const CRay2D& a_crInstance1, const CRay2D& a_crInstance2, CPoint2D<Treal>& a_rPoint2D)
{ CALL
  Treal offset1, offset2;
  if (intersect(a_crInstance1, a_crInstance2, offset1, offset2))
  {
    // Calculate point on a ray.
    a_rPoint2D = a_crInstance1.getOffsetPoint(offset1);
    return true;
  }
  else
    return false;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
