/*!
 *  \file    CVector3D.cpp Representation of the vector in a space.
 *  \brief   Vector in a space class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Vector in a space class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   27.06.2008 23:12:15

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
#include <Depth/include/geometry/CVector3D.hpp>
/*==========================================================================*/
#ifndef __CVECTOR3D_CPP__
#define __CVECTOR3D_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
GEOMETRY_API const CVector3D CVector3D::ZERO(0.0, 0.0, 0.0);
GEOMETRY_API const CVector3D CVector3D::UNIT_X(1.0, 0.0, 0.0);
GEOMETRY_API const CVector3D CVector3D::UNIT_Y(0.0, 1.0, 0.0);
GEOMETRY_API const CVector3D CVector3D::UNIT_Z(0.0, 0.0, 1.0);
/*--------------------------------------------------------------------------*/
void CVector3D::set(const Treal a_cpCoordinatesBuffer[])
{ CALL
  // Check if the pointer to the coordinates buffer is not NULL.
  ASSERT((a_cpCoordinatesBuffer != NULL), STR("Pointer to the coordinates buffer should not be NULL."))
  {
    clear();
  }

  m_X = a_cpCoordinatesBuffer[0];
  m_Y = a_cpCoordinatesBuffer[1];
  m_Z = a_cpCoordinatesBuffer[2];
}
/*--------------------------------------------------------------------------*/
void CVector3D::set(const CVector4D& a_crInstance)
{ CALL
  if (!NMath::CMath::isEqualZero(a_crInstance.m_W))
  {
    m_X = (a_crInstance.m_X / a_crInstance.m_W);
    m_Y = (a_crInstance.m_Y / a_crInstance.m_W);
    m_Z = (a_crInstance.m_Z / a_crInstance.m_W);
  }
  else
  {
    m_X = a_crInstance.m_X;
    m_Y = a_crInstance.m_Y;
    m_Z = a_crInstance.m_Z;
  }
}
/*--------------------------------------------------------------------------*/
void CVector3D::setCylindrical(const Treal a_cAngle, const Treal a_cRadius, const Treal a_cHeight)
{ CALL
  m_X = a_cRadius * NMath::CMath::cos(a_cAngle);
  m_Y = a_cRadius * NMath::CMath::sin(a_cAngle);
  m_Z = a_cHeight;
}
/*--------------------------------------------------------------------------*/
void CVector3D::getCylindrical(Treal& a_rAngle, Treal& a_rRadius, Treal& a_rHeight) const
{ CALL
  a_rAngle = NMath::CMath::atan2(m_Y, m_X);
  a_rRadius = NMath::CMath::sqrt(m_X * m_X + m_Y * m_Y);
  a_rHeight = m_Z;
}
/*--------------------------------------------------------------------------*/
void CVector3D::setSpherical(const Treal a_cLatitude, const Treal a_cLongitude, const Treal a_cRadius)
{ CALL
  m_X = a_cRadius * NMath::CMath::sin(a_cLatitude) * NMath::CMath::cos(a_cLongitude);
  m_Y = a_cRadius * NMath::CMath::sin(a_cLatitude) * NMath::CMath::sin(a_cLongitude);
  m_Z = a_cRadius * NMath::CMath::cos(a_cLatitude);
}
/*--------------------------------------------------------------------------*/
void CVector3D::getSpherical(Treal& a_rLatitude, Treal& a_rLongitude, Treal& a_rRadius) const
{ CALL
  a_rRadius = length();
  if (NMath::CMath::isEqualZero(a_rRadius))
  {
    a_rLatitude = 0.0;
    a_rLongitude = 0.0;
  }
  else
  {
    a_rLatitude = NMath::CMath::acos(m_Z / a_rRadius);
    a_rLongitude = NMath::CMath::atan2(m_Y, m_X);
  }
}
/*--------------------------------------------------------------------------*/
void CVector3D::normalize()
{ CALL
  Treal len = length();

  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;

  m_X *= len;
  m_Y *= len;
  m_Z *= len;
}
/*--------------------------------------------------------------------------*/
Treal CVector3D::normalizeLength()
{ CALL
  Treal len = length();
  Treal factor;

  if (!NMath::CMath::isEqualZero(len))
    factor = CONSTR(1.0) / len;
  else
    factor = 1.0;

  m_X *= factor;
  m_Y *= factor;
  m_Z *= factor;
  return len;
}
/*--------------------------------------------------------------------------*/
CVector3D CVector3D::rotate(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ) const
{ CALL
  Treal sin_AngleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_AngleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_AngleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_AngleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_AngleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_AngleZ = NMath::CMath::cos(a_cAngleZ);

  return CVector3D(cos_AngleY * cos_AngleZ * m_X - cos_AngleY * sin_AngleZ * m_Y + sin_AngleY * m_Z,
                   sin_AngleX * sin_AngleY * cos_AngleZ + cos_AngleX * sin_AngleZ * m_X - sin_AngleX * sin_AngleY * sin_AngleZ + cos_AngleX * cos_AngleZ * m_Y - sin_AngleX * cos_AngleY * m_Z,
                   -cos_AngleX * sin_AngleY * cos_AngleZ + sin_AngleX * sin_AngleZ * m_X + cos_AngleX * sin_AngleY * sin_AngleZ + sin_AngleX * cos_AngleZ * m_Y + cos_AngleX * cos_AngleY * m_Z);
}
/*--------------------------------------------------------------------------*/
CVector3D CVector3D::rotate(const CVector3D& a_crAxis, const Treal a_cAngle) const
{ CALL
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);
  CVector3D axis(a_crAxis), result(m_X * cos_angle, m_Y * cos_angle, m_Z * cos_angle), temp;

  axis.normalize();
  temp = axis;
  temp *= dot(temp, *this) * (1 - cos_angle);
  result += temp;
  temp = cross(*this, axis);
  temp *= sin_angle;
  result -= temp;
  return result;
}
/*--------------------------------------------------------------------------*/
CVector3D CVector3D::cross(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return CVector3D(a_crInstance1.m_Y * a_crInstance2.m_Z - a_crInstance1.m_Z * a_crInstance2.m_Y,
                   a_crInstance1.m_Z * a_crInstance2.m_X - a_crInstance1.m_X * a_crInstance2.m_Z,
                   a_crInstance1.m_X * a_crInstance2.m_Y - a_crInstance1.m_Y * a_crInstance2.m_X);
}
/*--------------------------------------------------------------------------*/
Treal CVector3D::angleCos(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  Treal len1 = a_crInstance1.length();
  Treal len2 = a_crInstance1.length();

  if (!NMath::CMath::isEqualZero(len1))
    len1 = CONSTR(1.0) / len1;
  else
    len1 = 1.0;

  if (!NMath::CMath::isEqualZero(len2))
    len2 = CONSTR(1.0) / len2;
  else
    len2 = 1.0;

  return dot(a_crInstance1, a_crInstance2) * len1 * len2;
}
/*--------------------------------------------------------------------------*/
CVector3D CVector3D::mirror(const CVector3D& a_crInstance, const CVector3D& a_crMirrorVector)
{ CALL
  CVector3D mirrored(a_crMirrorVector);

  mirrored.normalize();
  mirrored *= CONSTR(2.0) * dot(mirrored, a_crInstance);
  mirrored -= a_crInstance;
  return mirrored;
}
/*--------------------------------------------------------------------------*/
void CVector3D::orthonormalize(CVector3D& a_rInstance1, CVector3D& a_rInstance2, CVector3D& a_rInstance3)
{ CALL
  // Compute u0.
  a_rInstance1.normalize();
  // Compute u1.
  Treal dot0 = dot(a_rInstance1, a_rInstance2);
  a_rInstance2 -= dot0 * a_rInstance1;
  a_rInstance2.normalize();
  // Compute u2.
  Treal dot1 = dot(a_rInstance2, a_rInstance3);
  dot0 = dot(a_rInstance1, a_rInstance3);
  a_rInstance3 -= dot0 * a_rInstance1 + dot1 * a_rInstance2;
  a_rInstance3.normalize();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
