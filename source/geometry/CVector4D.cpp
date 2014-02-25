/*!
 *  \file    CVector4D.cpp Representation of the vector in a hyperspace.
 *  \brief   Vector in a hyperspace class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Vector in a hyperspace class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   27.06.2008 23:43:19

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
#include <Depth/include/geometry/CVector4D.hpp>
/*==========================================================================*/
#ifndef __CVECTOR4D_CPP__
#define __CVECTOR4D_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
GEOMETRY_API const CVector4D CVector4D::ZERO(0.0, 0.0, 0.0, 0.0);
GEOMETRY_API const CVector4D CVector4D::UNIT_X(1.0, 0.0, 0.0, 0.0);
GEOMETRY_API const CVector4D CVector4D::UNIT_Y(0.0, 1.0, 0.0, 0.0);
GEOMETRY_API const CVector4D CVector4D::UNIT_Z(0.0, 0.0, 1.0, 0.0);
GEOMETRY_API const CVector4D CVector4D::UNIT_W(0.0, 0.0, 0.0, 1.0);
/*--------------------------------------------------------------------------*/
void CVector4D::set(const Treal a_cpCoordinatesBuffer[])
{ CALL
  // Check if the pointer to the coordinates buffer is not NULL.
  ASSERT((a_cpCoordinatesBuffer != NULL), STR("Pointer to the coordinates buffer should not be NULL."))
  {
    clear();
  }

  m_X = a_cpCoordinatesBuffer[0];
  m_Y = a_cpCoordinatesBuffer[1];
  m_Z = a_cpCoordinatesBuffer[2];
  m_W = a_cpCoordinatesBuffer[3];
}
/*--------------------------------------------------------------------------*/
void CVector4D::normalize()
{ CALL
  Treal len = length();

  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;

  m_X *= len;
  m_Y *= len;
  m_Z *= len;
  m_W *= len;
}
/*--------------------------------------------------------------------------*/
Treal CVector4D::normalizeLength()
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
  m_W *= factor;
  return len;
}
/*--------------------------------------------------------------------------*/
CVector4D CVector4D::rotate(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ) const
{ CALL
  Treal sin_AngleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_AngleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_AngleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_AngleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_AngleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_AngleZ = NMath::CMath::cos(a_cAngleZ);

  return CVector4D(cos_AngleY * cos_AngleZ * m_X - cos_AngleY * sin_AngleZ * m_Y + sin_AngleY * m_Z,
                   sin_AngleX * sin_AngleY * cos_AngleZ + cos_AngleX * sin_AngleZ * m_X - sin_AngleX * sin_AngleY * sin_AngleZ + cos_AngleX * cos_AngleZ * m_Y - sin_AngleX * cos_AngleY * m_Z,
                   -cos_AngleX * sin_AngleY * cos_AngleZ + sin_AngleX * sin_AngleZ * m_X + cos_AngleX * sin_AngleY * sin_AngleZ + sin_AngleX * cos_AngleZ * m_Y + cos_AngleX * cos_AngleY * m_Z,
                   m_W);
}
/*--------------------------------------------------------------------------*/
CVector4D CVector4D::rotate(const CVector3D& a_crAxis, const Treal a_cAngle) const
{ CALL
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);
  CVector3D axis(a_crAxis), result(m_X * cos_angle, m_Y * cos_angle, m_Z * cos_angle), temp;

  axis.normalize();
  temp = axis;
  temp *= CVector3D::dot(temp, *this) * (CONSTR(1.0) - cos_angle);
  result += temp;
  temp = CVector3D::cross(*this, axis);
  temp *= sin_angle;
  result -= temp;
  return CVector4D(result.m_X, result.m_Y, result.m_Z, m_W);
}
/*--------------------------------------------------------------------------*/
CVector4D CVector4D::cross(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2, const CVector4D& a_crInstance3)
{ CALL
  return CVector4D(a_crInstance1.m_Y * a_crInstance2.m_Z * a_crInstance3.m_W + a_crInstance1.m_Z * a_crInstance2.m_W * a_crInstance3.m_Y + a_crInstance1.m_W * a_crInstance2.m_Y * a_crInstance3.m_Z - a_crInstance1.m_Y * a_crInstance2.m_W * a_crInstance3.m_Z - a_crInstance1.m_Z * a_crInstance2.m_Y * a_crInstance3.m_W - a_crInstance1.m_W * a_crInstance2.m_Z * a_crInstance3.m_Y,
                   a_crInstance1.m_X * a_crInstance2.m_W * a_crInstance3.m_Z + a_crInstance1.m_Z * a_crInstance2.m_X * a_crInstance3.m_W + a_crInstance1.m_W * a_crInstance2.m_Z * a_crInstance3.m_X - a_crInstance1.m_X * a_crInstance2.m_Z * a_crInstance3.m_W - a_crInstance1.m_Z * a_crInstance2.m_W * a_crInstance3.m_X - a_crInstance1.m_W * a_crInstance2.m_X * a_crInstance3.m_Z,
                   a_crInstance1.m_X * a_crInstance2.m_Y * a_crInstance3.m_W + a_crInstance1.m_Y * a_crInstance2.m_W * a_crInstance3.m_X + a_crInstance1.m_W * a_crInstance2.m_X * a_crInstance3.m_Y - a_crInstance1.m_X * a_crInstance2.m_W * a_crInstance3.m_Y - a_crInstance1.m_Y * a_crInstance2.m_X * a_crInstance3.m_W - a_crInstance1.m_W * a_crInstance2.m_Y * a_crInstance3.m_X,
                   a_crInstance1.m_X * a_crInstance2.m_Z * a_crInstance3.m_Y + a_crInstance1.m_Y * a_crInstance2.m_X * a_crInstance3.m_Z + a_crInstance1.m_Z * a_crInstance2.m_Y * a_crInstance3.m_X - a_crInstance1.m_X * a_crInstance2.m_Y * a_crInstance3.m_Z - a_crInstance1.m_Y * a_crInstance2.m_Z * a_crInstance3.m_X - a_crInstance1.m_Z * a_crInstance2.m_X * a_crInstance3.m_Y);
}
/*--------------------------------------------------------------------------*/
Treal CVector4D::angleCos(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
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
CVector4D CVector4D::mirror(const CVector4D& a_crInstance, const CVector4D& a_crMirrorVector)
{ CALL
  CVector4D mirrored(a_crMirrorVector);

  mirrored.normalize();
  mirrored *= CONSTR(2.0) * dot(mirrored, a_crInstance);
  mirrored -= a_crInstance;
  return mirrored;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
