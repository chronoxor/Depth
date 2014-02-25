/*!
 *  \file    CPlane.cpp Representation of the plane in a space.
 *  \brief   Plane in a space class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Plane in a space class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   14.07.2008 22:29:03

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
#include <Depth/include/geometry/CPlane.hpp>
/*==========================================================================*/
#ifndef __CPLANE_CPP__
#define __CPLANE_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
void CPlane::set(const Treal a_cA, const Treal a_cB, const Treal a_cC, const Treal a_cD)
{ CALL
  m_Normal.m_X = a_cA;
  m_Normal.m_Y = a_cB;
  m_Normal.m_Z = a_cC;
  m_Normal.normalize();
  m_Distance = -a_cD;
}
/*--------------------------------------------------------------------------*/
void CPlane::set(const CVector3D& a_crTangentVector)
{ CALL
  m_Normal = a_crTangentVector;
  m_Normal.normalize();
  m_Distance = a_crTangentVector.length();
}
/*--------------------------------------------------------------------------*/
void CPlane::set(const CVector3D& a_crNormal, const Treal a_cDistance)
{ CALL
  m_Normal = a_crNormal;
  m_Normal.normalize();
  m_Distance = a_cDistance;
}
/*--------------------------------------------------------------------------*/
void CPlane::set(const CVector3D& a_crNormal, const CPoint3D<Treal>& a_crPoint3D)
{ CALL
  m_Normal = a_crNormal;
  m_Normal.normalize();
  m_Distance = CVector3D::dot(m_Normal, a_crPoint3D);
}
/*--------------------------------------------------------------------------*/
void CPlane::set(const CPoint3D<Treal>& a_crA, const CPoint3D<Treal>& a_crB, const CPoint3D<Treal>& a_crC)
{ CALL
  m_Normal = CVector3D::cross((a_crC - a_crA), (a_crB - a_crA));
  m_Normal.normalize();
  m_Distance = CVector3D::dot(m_Normal, a_crA);
}
/*--------------------------------------------------------------------------*/
CPoint3D<Treal> CPlane::getClosestPoint(const CPoint3D<Treal>& a_crPoint3D, Treal& a_rDistance) const
{ CALL
  CVector3D result(a_crPoint3D);

  a_rDistance = getDistanceToPoint(a_crPoint3D);
  result -= m_Normal * a_rDistance;
  return CPoint3D<Treal>(result.m_X, result.m_Y, result.m_Z);
}
/*--------------------------------------------------------------------------*/
CMatrix4D CPlane::getMirrorMatrix(const Tbool a_cMirrorNormals/* = false */) const
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = CONSTR(-2.0) * m_Normal.m_X * m_Normal.m_X + CONSTR(1.0);
  result.m_M[0][1] = CONSTR(-2.0) * m_Normal.m_Y * m_Normal.m_X;
  result.m_M[0][2] = CONSTR(-2.0) * m_Normal.m_Z * m_Normal.m_X;
  result.m_M[0][3] = 0.0;
  result.m_M[1][0] = CONSTR(-2.0) * m_Normal.m_X * m_Normal.m_Y;
  result.m_M[1][1] = CONSTR(-2.0) * m_Normal.m_Y * m_Normal.m_Y + CONSTR(1.0);
  result.m_M[1][2] = CONSTR(-2.0) * m_Normal.m_Z * m_Normal.m_Y;
  result.m_M[1][3] = 0.0;
  result.m_M[2][0] = CONSTR(-2.0) * m_Normal.m_X * m_Normal.m_Z;
  result.m_M[2][1] = CONSTR(-2.0) * m_Normal.m_Y * m_Normal.m_Z;
  result.m_M[2][2] = CONSTR(-2.0) * m_Normal.m_Z * m_Normal.m_Z + CONSTR(1.0);
  result.m_M[2][3] = 0.0;
  result.m_M[3][0] = a_cMirrorNormals ? CONSTR(0.0) : CONSTR(2.0) * m_Normal.m_X * m_Distance;
  result.m_M[3][1] = a_cMirrorNormals ? CONSTR(0.0) : CONSTR(2.0) * m_Normal.m_Y * m_Distance;
  result.m_M[3][2] = a_cMirrorNormals ? CONSTR(0.0) : CONSTR(2.0) * m_Normal.m_Z * m_Distance;
  result.m_M[3][3] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CPlane::getOrthoProjectMatrix(const CVector3D& a_crProjectDirection) const
{ CALL
  CMatrix4D result;
  Treal N_dir = CVector3D::dot(m_Normal, a_crProjectDirection);
  Treal NX =-(m_Normal.m_X / N_dir);
  Treal NY =-(m_Normal.m_Y / N_dir);
  Treal NZ =-(m_Normal.m_Z / N_dir);
  Treal ND = m_Distance / N_dir;

  result.m_M[0][0] = NX * a_crProjectDirection.m_X + CONSTR(1.0);
  result.m_M[0][1] = NX * a_crProjectDirection.m_Y;
  result.m_M[0][2] = NX * a_crProjectDirection.m_Z;
  result.m_M[0][3] = 0.0;
  result.m_M[1][0] = NY * a_crProjectDirection.m_X;
  result.m_M[1][1] = NY * a_crProjectDirection.m_Y + CONSTR(1.0);
  result.m_M[1][2] = NY * a_crProjectDirection.m_Z;
  result.m_M[1][3] = 0.0;
  result.m_M[2][0] = NZ * a_crProjectDirection.m_X;
  result.m_M[2][1] = NZ * a_crProjectDirection.m_Y;
  result.m_M[2][2] = NZ * a_crProjectDirection.m_Z + CONSTR(1.0);
  result.m_M[2][3] = 0.0;
  result.m_M[3][0] = ND * a_crProjectDirection.m_X;
  result.m_M[3][1] = ND * a_crProjectDirection.m_Y;
  result.m_M[3][2] = ND * a_crProjectDirection.m_Z;
  result.m_M[3][3] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CPlane::getPerspectiveProjectMatrix(const CPoint3D<Treal>& a_crProjectOrigin) const
{ CALL
  CMatrix4D result;
  Treal distance = getDistanceToPoint(a_crProjectOrigin);

  result.m_M[0][0] = -a_crProjectOrigin.m_X * m_Normal.m_X + distance;
  result.m_M[0][1] = -a_crProjectOrigin.m_Y * m_Normal.m_X;
  result.m_M[0][2] = -a_crProjectOrigin.m_Z * m_Normal.m_X;
  result.m_M[0][3] = -m_Normal.m_X;
  result.m_M[1][0] = -a_crProjectOrigin.m_X * m_Normal.m_Y;
  result.m_M[1][1] = -a_crProjectOrigin.m_Y * m_Normal.m_Y + distance;
  result.m_M[1][2] = -a_crProjectOrigin.m_Z * m_Normal.m_Y;
  result.m_M[1][3] = -m_Normal.m_Y;
  result.m_M[2][0] = -a_crProjectOrigin.m_X * m_Normal.m_Z;
  result.m_M[2][1] = -a_crProjectOrigin.m_Y * m_Normal.m_Z;
  result.m_M[2][2] = -a_crProjectOrigin.m_Z * m_Normal.m_Z + distance;
  result.m_M[2][3] = -m_Normal.m_Z;
  result.m_M[3][0] =  a_crProjectOrigin.m_X * m_Distance;
  result.m_M[3][1] =  a_crProjectOrigin.m_Y * m_Distance;
  result.m_M[3][2] =  a_crProjectOrigin.m_Z * m_Distance;
  result.m_M[3][3] =  m_Distance + distance;
  return result;
}
/*--------------------------------------------------------------------------*/
Tbool CPlane::isIntersect(const CRay3D& a_crRay3D, Treal& a_rOffset) const
{ CALL
  Treal N_dir = CVector3D::dot(m_Normal, a_crRay3D.m_Direction);

  if (NMath::CMath::isEqualZero(N_dir))
  {
    a_rOffset = NMath::CMath::getPosInf();
    return false;
  }
  else
  {
    a_rOffset = (m_Distance - CVector3D::dot(m_Normal, a_crRay3D.m_Origin)) / N_dir;
    return true;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CPlane::isIntersect(const CRay3D& a_crRay3D, CPoint3D<Treal>& a_rPoint3D) const
{ CALL
  Treal N_dir = CVector3D::dot(m_Normal, a_crRay3D.m_Direction);

  if (NMath::CMath::isEqualZero(N_dir))
  {
    a_rPoint3D.set(NMath::CMath::getPosInf(), NMath::CMath::getPosInf(), NMath::CMath::getPosInf());
    return false;
  }
  else
  {
    Treal offset = (m_Distance - CVector3D::dot(m_Normal, a_crRay3D.m_Origin)) / N_dir;
    a_rPoint3D.m_X = a_crRay3D.m_Origin.m_X + a_crRay3D.m_Direction.m_X * offset;
    a_rPoint3D.m_Y = a_crRay3D.m_Origin.m_Y + a_crRay3D.m_Direction.m_Y * offset;
    a_rPoint3D.m_Z = a_crRay3D.m_Origin.m_Z + a_crRay3D.m_Direction.m_Z * offset;
    return true;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CPlane::isIntersect(const CPlane& a_crPlane, CRay3D& a_rRay3D) const
{ CALL
  // Determine intersection ray's direction.
  a_rRay3D.m_Direction = CVector3D::cross(m_Normal, a_crPlane.m_Normal);

  // If planes are parallel then fail.
  Treal N_dir = a_rRay3D.m_Direction.length();
  if (NMath::CMath::isEqualZero(N_dir))
  {
    a_rRay3D.m_Origin.set(NMath::CMath::getPosInf(), NMath::CMath::getPosInf(), NMath::CMath::getPosInf());
    return false;
  }
  else
  {
    // Determine intersection point with the best suited coordinate plane.
    Treal curabs;
    Treal maxabs = NMath::CMath::fabs(a_rRay3D.m_Direction.m_X);

    Tsint index = 0;
    if ((curabs = NMath::CMath::fabs(a_rRay3D.m_Direction.m_Y)) > maxabs)
    {
      maxabs = curabs;
      index = 1;
    }
    if ((curabs = NMath::CMath::fabs(a_rRay3D.m_Direction.m_Z)) > maxabs)
    {
      maxabs = curabs;
      index = 2;
    }

    switch (index)
    {
      case 0:
      {
        a_rRay3D.m_Origin.set(0.0, (a_crPlane.m_Normal.m_Z * m_Distance - m_Normal.m_Z * a_crPlane.m_Distance) / a_rRay3D.m_Direction.m_X, (m_Normal.m_Y * a_crPlane.m_Distance - a_crPlane.m_Normal.m_Y * m_Distance) / a_rRay3D.m_Direction.m_X);
        break;
      }
      case 1:
      {
        a_rRay3D.m_Origin.set((m_Normal.m_Z * a_crPlane.m_Distance - a_crPlane.m_Normal.m_Z * m_Distance) / a_rRay3D.m_Direction.m_Y, 0.0, (a_crPlane.m_Normal.m_X * m_Distance - m_Normal.m_X * a_crPlane.m_Distance) / a_rRay3D.m_Direction.m_Y);
        break;
      }
      case 2:
      {
        a_rRay3D.m_Origin.set((a_crPlane.m_Normal.m_Y * m_Distance - m_Normal.m_Y * a_crPlane.m_Distance) / a_rRay3D.m_Direction.m_Z, (m_Normal.m_X * a_crPlane.m_Distance - a_crPlane.m_Normal.m_X * m_Distance) / a_rRay3D.m_Direction.m_Z, 0.0);
        break;
      }
    }
    // Normalize the direction.
    a_rRay3D.m_Direction *= CONSTR(1.0) / N_dir;
    return true;
  }
}
/*--------------------------------------------------------------------------*/
CPoint3D<Treal> CPlane::mirrorPoint(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  CVector3D result(a_crPoint3D);
  Treal distance = CONSTR(2.0) * CVector3D::dot(m_Normal, result) - m_Distance;

  result -= m_Normal * distance;
  return CPoint3D<Treal>(result.m_X, result.m_Y, result.m_Z);
}
/*--------------------------------------------------------------------------*/
CVector3D CPlane::mirrorNormal(const CVector3D& a_crNormal) const
{ CALL
  Treal distance = CONSTR(2.0) * CVector3D::dot(m_Normal, a_crNormal);

  return CVector3D(a_crNormal - m_Normal * distance);
}
/*--------------------------------------------------------------------------*/
CPlane CPlane::mirrorPlane(const CPlane& a_crPlane) const
{ CALL
  CPlane result;
  CVector3D tangent = a_crPlane.getTangent();
  CPoint3D<Treal> old_pos(tangent.m_X, tangent.m_Y, tangent.m_Z);
  CPoint3D<Treal> new_pos;

  a_crPlane.mirrorPoint(old_pos, new_pos);
  a_crPlane.mirrorNormal(a_crPlane.m_Normal, result.m_Normal);
  result.m_Distance = CVector3D::dot(result.m_Normal, new_pos);
  return result;
}
/*--------------------------------------------------------------------------*/
Treal CPlane::mirrorPoint(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  CVector3D result(a_crPoint3D);
  Treal distance = CONSTR(2.0) * (CVector3D::dot(m_Normal, result) - m_Distance);

  result -= m_Normal * distance;
  a_rResult.set(result.m_X, result.m_Y, result.m_Z);
  return -distance;
}
/*--------------------------------------------------------------------------*/
Treal CPlane::mirrorNormal(const CVector3D& a_crNormal, CVector3D& a_rResult) const
{ CALL
  Treal distance = CONSTR(2.0) * CVector3D::dot(m_Normal, a_crNormal);

  a_rResult = a_crNormal - m_Normal * distance;
  return -distance;
}
/*--------------------------------------------------------------------------*/
Treal CPlane::projectOrtho(const CVector3D& a_crProjectDirection, const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  Treal N_dir = CVector3D::dot(m_Normal, a_crProjectDirection);

  if (NMath::CMath::isEqualZero(N_dir))
    return 0.0;
  else
  {
    CVector3D result(a_crPoint3D);
    Treal scale = (m_Distance - CVector3D::dot(m_Normal, a_crPoint3D)) / N_dir;
    result += scale * a_crProjectDirection;
    a_rResult.set(result.m_X, result.m_Y, result.m_Z);
    return ((CVector3D::dot(m_Normal, a_rResult - a_crPoint3D) > 0.0) ? CONSTR(-1.0) : CONSTR(1.0));
  }
}
/*--------------------------------------------------------------------------*/
void CPlane::transform(const CMatrix3D& a_crMatrix3D)
{ CALL
  CVector3D temp(m_Normal * m_Distance);

  m_Normal = a_crMatrix3D.rotate(m_Normal);
  m_Normal.normalize();
  m_Distance = CVector3D::dot(m_Normal, a_crMatrix3D.transform(temp));
}
/*--------------------------------------------------------------------------*/
void CPlane::transform(const CMatrix4D& a_crMatrix4D)
{ CALL
  CVector3D temp(m_Normal * m_Distance);

  m_Normal = a_crMatrix4D.rotate(m_Normal);
  m_Normal.normalize();
  m_Distance = CVector3D::dot(m_Normal, a_crMatrix4D.transform(temp));
}
/*--------------------------------------------------------------------------*/
void CPlane::transform(const CQuaternion& a_crQuaternion)
{ CALL
  CVector3D temp(m_Normal * m_Distance);

  m_Normal = a_crQuaternion.rotate(m_Normal);
  m_Normal.normalize();
  m_Distance = CVector3D::dot(m_Normal, a_crQuaternion.rotate(temp));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
