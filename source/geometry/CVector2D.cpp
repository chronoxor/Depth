/*!
 *  \file    CVector2D.cpp Representation of the vector on a plane.
 *  \brief   Vector on a plane class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Vector on a plane class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   27.06.2008 20:11:11

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
#include <Depth/include/geometry/CVector2D.hpp>
/*==========================================================================*/
#ifndef __CVECTOR2D_CPP__
#define __CVECTOR2D_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
GEOMETRY_API const CVector2D CVector2D::ZERO(0.0, 0.0);
GEOMETRY_API const CVector2D CVector2D::UNIT_X(1.0, 0.0);
GEOMETRY_API const CVector2D CVector2D::UNIT_Y(0.0, 1.0);
/*--------------------------------------------------------------------------*/
void CVector2D::set(const Treal a_cpCoordinatesBuffer[])
{ CALL
  // Check if the pointer to the coordinates buffer is not NULL.
  ASSERT((a_cpCoordinatesBuffer != NULL), STR("Pointer to the coordinates buffer should not be NULL."))
  {
    clear();
  }

  m_X = a_cpCoordinatesBuffer[0];
  m_Y = a_cpCoordinatesBuffer[1];
}
/*--------------------------------------------------------------------------*/
void CVector2D::set(const CPoint3D<Treal>& a_crInstance)
{ CALL
  if (!NMath::CMath::isEqualZero(a_crInstance.m_Z))
  {
    m_X = (a_crInstance.m_X / a_crInstance.m_Z);
    m_Y = (a_crInstance.m_Y / a_crInstance.m_Z);
  }
  else
  {
    m_X = a_crInstance.m_X;
    m_Y = a_crInstance.m_Y;
  }
}
/*--------------------------------------------------------------------------*/
void CVector2D::set(const CVector3D& a_crInstance)
{ CALL
  if (!NMath::CMath::isEqualZero(a_crInstance.m_Z))
  {
    m_X = (a_crInstance.m_X / a_crInstance.m_Z);
    m_Y = (a_crInstance.m_Y / a_crInstance.m_Z);
  }
  else
  {
    m_X = a_crInstance.m_X;
    m_Y = a_crInstance.m_Y;
  }
}
/*--------------------------------------------------------------------------*/
void CVector2D::setPolar(const Treal a_cAngle, const Treal a_cRadius)
{ CALL
  m_X = a_cRadius * NMath::CMath::cos(a_cAngle);
  m_Y = a_cRadius * NMath::CMath::sin(a_cAngle);
}
/*--------------------------------------------------------------------------*/
void CVector2D::getPolar(Treal& a_rAngle, Treal& a_rRadius) const
{ CALL
  a_rAngle = NMath::CMath::atan2(m_Y, m_X);
  a_rRadius = length();
}
/*--------------------------------------------------------------------------*/
void CVector2D::normalize()
{ CALL
  Treal len = length();

  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;

  m_X *= len;
  m_Y *= len;
}
/*--------------------------------------------------------------------------*/
Treal CVector2D::normalizeLength()
{ CALL
  Treal len = length();
  Treal factor;

  if (!NMath::CMath::isEqualZero(len))
    factor = CONSTR(1.0) / len;
  else
    factor = 1.0;

  m_X *= factor;
  m_Y *= factor;
  return len;
}
/*--------------------------------------------------------------------------*/
CVector2D CVector2D::rotate(const Treal a_cAngle) const
{ CALL
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);

  return CVector2D(m_X * cos_angle - m_Y * sin_angle, m_X * sin_angle + m_Y * cos_angle);
}
/*--------------------------------------------------------------------------*/
Treal CVector2D::angleCos(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
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
CVector2D CVector2D::mirror(const CVector2D& a_crInstance, const CVector2D& a_crMirrorVector)
{ CALL
  CVector2D mirrored(a_crMirrorVector);

  mirrored.normalize();
  mirrored *= CONSTR(2.0) * dot(mirrored, a_crInstance);
  mirrored -= a_crInstance;
  return mirrored;
}
/*--------------------------------------------------------------------------*/
void CVector2D::orthonormalize(CVector2D& a_rInstance1, CVector2D& a_rInstance2)
{ CALL
  // Compute u0.
  a_rInstance1.normalize();
  // Compute u1.
  Treal dot0 = dot(a_rInstance1, a_rInstance2);
  a_rInstance2 -= dot0 * a_rInstance1;
  a_rInstance2.normalize();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
