/*!
 *  \file    CMatrix3D.cpp Representation of the transformation matrix in a
 *           space.
 *  \brief   Transformation matrix in a space class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Transformation matrix in a space class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   01.07.2008 23:27:50

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
#include <Depth/include/geometry/CMatrix3D.hpp>
/*==========================================================================*/
#ifndef __CMATRIX3D_CPP__
#define __CMATRIX3D_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
GEOMETRY_API Tbool operator == (const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2)
{ CALL
  return (NMath::CMath::isEqual(a_crInstance1.m_M[0][0], a_crInstance2.m_M[0][0]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[0][1], a_crInstance2.m_M[0][1]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[0][2], a_crInstance2.m_M[0][2]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[1][0], a_crInstance2.m_M[1][0]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[1][1], a_crInstance2.m_M[1][1]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[1][2], a_crInstance2.m_M[1][2]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[2][0], a_crInstance2.m_M[2][0]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[2][1], a_crInstance2.m_M[2][1]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[2][2], a_crInstance2.m_M[2][2]));
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix3D operator + (const CMatrix3D& a_crInstance)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = +a_crInstance.m_M[0][0];
  result.m_M[0][1] = +a_crInstance.m_M[0][1];
  result.m_M[0][2] = +a_crInstance.m_M[0][2];
  result.m_M[1][0] = +a_crInstance.m_M[1][0];
  result.m_M[1][1] = +a_crInstance.m_M[1][1];
  result.m_M[1][2] = +a_crInstance.m_M[1][2];
  result.m_M[2][0] = +a_crInstance.m_M[2][0];
  result.m_M[2][1] = +a_crInstance.m_M[2][1];
  result.m_M[2][2] = +a_crInstance.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix3D operator - (const CMatrix3D& a_crInstance)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = -a_crInstance.m_M[0][0];
  result.m_M[0][1] = -a_crInstance.m_M[0][1];
  result.m_M[0][2] = -a_crInstance.m_M[0][2];
  result.m_M[1][0] = -a_crInstance.m_M[1][0];
  result.m_M[1][1] = -a_crInstance.m_M[1][1];
  result.m_M[1][2] = -a_crInstance.m_M[1][2];
  result.m_M[2][0] = -a_crInstance.m_M[2][0];
  result.m_M[2][1] = -a_crInstance.m_M[2][1];
  result.m_M[2][2] = -a_crInstance.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix3D operator + (const CMatrix3D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] + a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] + a_cValue;
  result.m_M[0][2] = a_crInstance.m_M[0][2] + a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] + a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] + a_cValue;
  result.m_M[1][2] = a_crInstance.m_M[1][2] + a_cValue;
  result.m_M[2][0] = a_crInstance.m_M[2][0] + a_cValue;
  result.m_M[2][1] = a_crInstance.m_M[2][1] + a_cValue;
  result.m_M[2][2] = a_crInstance.m_M[2][2] + a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix3D operator + (const Treal a_cValue, const CMatrix3D& a_crInstance)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_cValue + a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue + a_crInstance.m_M[0][1];
  result.m_M[0][2] = a_cValue + a_crInstance.m_M[0][2];
  result.m_M[1][0] = a_cValue + a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue + a_crInstance.m_M[1][1];
  result.m_M[1][2] = a_cValue + a_crInstance.m_M[1][2];
  result.m_M[2][0] = a_cValue + a_crInstance.m_M[2][0];
  result.m_M[2][1] = a_cValue + a_crInstance.m_M[2][1];
  result.m_M[2][2] = a_cValue + a_crInstance.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix3D operator - (const CMatrix3D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] - a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] - a_cValue;
  result.m_M[0][2] = a_crInstance.m_M[0][2] - a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] - a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] - a_cValue;
  result.m_M[1][2] = a_crInstance.m_M[1][2] - a_cValue;
  result.m_M[2][0] = a_crInstance.m_M[2][0] - a_cValue;
  result.m_M[2][1] = a_crInstance.m_M[2][1] - a_cValue;
  result.m_M[2][2] = a_crInstance.m_M[2][2] - a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix3D operator - (const Treal a_cValue, const CMatrix3D& a_crInstance)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_cValue - a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue - a_crInstance.m_M[0][1];
  result.m_M[0][2] = a_cValue - a_crInstance.m_M[0][2];
  result.m_M[1][0] = a_cValue - a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue - a_crInstance.m_M[1][1];
  result.m_M[1][2] = a_cValue - a_crInstance.m_M[1][2];
  result.m_M[2][0] = a_cValue - a_crInstance.m_M[2][0];
  result.m_M[2][1] = a_cValue - a_crInstance.m_M[2][1];
  result.m_M[2][2] = a_cValue - a_crInstance.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix3D operator * (const CMatrix3D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] * a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] * a_cValue;
  result.m_M[0][2] = a_crInstance.m_M[0][2] * a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] * a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] * a_cValue;
  result.m_M[1][2] = a_crInstance.m_M[1][2] * a_cValue;
  result.m_M[2][0] = a_crInstance.m_M[2][0] * a_cValue;
  result.m_M[2][1] = a_crInstance.m_M[2][1] * a_cValue;
  result.m_M[2][2] = a_crInstance.m_M[2][2] * a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix3D operator * (const Treal a_cValue, const CMatrix3D& a_crInstance)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_cValue * a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue * a_crInstance.m_M[0][1];
  result.m_M[0][2] = a_cValue * a_crInstance.m_M[0][2];
  result.m_M[1][0] = a_cValue * a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue * a_crInstance.m_M[1][1];
  result.m_M[1][2] = a_cValue * a_crInstance.m_M[1][2];
  result.m_M[2][0] = a_cValue * a_crInstance.m_M[2][0];
  result.m_M[2][1] = a_cValue * a_crInstance.m_M[2][1];
  result.m_M[2][2] = a_cValue * a_crInstance.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix3D operator / (const CMatrix3D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] / a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] / a_cValue;
  result.m_M[0][2] = a_crInstance.m_M[0][2] / a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] / a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] / a_cValue;
  result.m_M[1][2] = a_crInstance.m_M[1][2] / a_cValue;
  result.m_M[2][0] = a_crInstance.m_M[2][0] / a_cValue;
  result.m_M[2][1] = a_crInstance.m_M[2][1] / a_cValue;
  result.m_M[2][2] = a_crInstance.m_M[2][2] / a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix3D operator / (const Treal a_cValue, const CMatrix3D& a_crInstance)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_cValue / a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue / a_crInstance.m_M[0][1];
  result.m_M[0][2] = a_cValue / a_crInstance.m_M[0][2];
  result.m_M[1][0] = a_cValue / a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue / a_crInstance.m_M[1][1];
  result.m_M[1][2] = a_cValue / a_crInstance.m_M[1][2];
  result.m_M[2][0] = a_cValue / a_crInstance.m_M[2][0];
  result.m_M[2][1] = a_cValue / a_crInstance.m_M[2][1];
  result.m_M[2][2] = a_cValue / a_crInstance.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D& CMatrix3D::operator += (const Treal a_cValue)
{ CALL
  m_M[0][0] += a_cValue;
  m_M[0][1] += a_cValue;
  m_M[0][2] += a_cValue;
  m_M[1][0] += a_cValue;
  m_M[1][1] += a_cValue;
  m_M[1][2] += a_cValue;
  m_M[2][0] += a_cValue;
  m_M[2][1] += a_cValue;
  m_M[2][2] += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
CMatrix3D& CMatrix3D::operator -= (const Treal a_cValue)
{ CALL
  m_M[0][0] -= a_cValue;
  m_M[0][1] -= a_cValue;
  m_M[0][2] -= a_cValue;
  m_M[1][0] -= a_cValue;
  m_M[1][1] -= a_cValue;
  m_M[1][2] -= a_cValue;
  m_M[2][0] -= a_cValue;
  m_M[2][1] -= a_cValue;
  m_M[2][2] -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
CMatrix3D& CMatrix3D::operator *= (const Treal a_cValue)
{ CALL
  m_M[0][0] *= a_cValue;
  m_M[0][1] *= a_cValue;
  m_M[0][2] *= a_cValue;
  m_M[1][0] *= a_cValue;
  m_M[1][1] *= a_cValue;
  m_M[1][2] *= a_cValue;
  m_M[2][0] *= a_cValue;
  m_M[2][1] *= a_cValue;
  m_M[2][2] *= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
CMatrix3D& CMatrix3D::operator /= (const Treal a_cValue)
{ CALL
  m_M[0][0] /= a_cValue;
  m_M[0][1] /= a_cValue;
  m_M[0][2] /= a_cValue;
  m_M[1][0] /= a_cValue;
  m_M[1][1] /= a_cValue;
  m_M[1][2] /= a_cValue;
  m_M[2][0] /= a_cValue;
  m_M[2][1] /= a_cValue;
  m_M[2][2] /= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::set(const Treal a_cpMatrixBuffer[])
{ CALL
  // Check if the pointer to the matrix values buffer is not NULL.
  ASSERT((a_cpMatrixBuffer != NULL), STR("Pointer to the matrix values buffer should not be NULL."))
  {
    clear();
  }

  m_M[0][0] = a_cpMatrixBuffer[0];
  m_M[0][1] = a_cpMatrixBuffer[1];
  m_M[0][2] = a_cpMatrixBuffer[2];
  m_M[1][0] = a_cpMatrixBuffer[3];
  m_M[1][1] = a_cpMatrixBuffer[4];
  m_M[1][2] = a_cpMatrixBuffer[5];
  m_M[2][0] = a_cpMatrixBuffer[6];
  m_M[2][1] = a_cpMatrixBuffer[7];
  m_M[2][2] = a_cpMatrixBuffer[8];
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::set(const CMatrix2D& a_crInstance)
{ CALL
  m_M[0][0] = a_crInstance.m_M[0][0];
  m_M[0][1] = a_crInstance.m_M[0][1];
  m_M[0][2] = 0.0;
  m_M[1][0] = a_crInstance.m_M[1][0];
  m_M[1][1] = a_crInstance.m_M[1][1];
  m_M[1][2] = 0.0;
  m_M[2][0] = 0.0;
  m_M[2][1] = 0.0;
  m_M[2][2] = 1.0;
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::set(const CMatrix3D& a_crInstance)
{ CALL
  m_M[0][0] = a_crInstance.m_M[0][0];
  m_M[0][1] = a_crInstance.m_M[0][1];
  m_M[0][2] = a_crInstance.m_M[0][2];
  m_M[1][0] = a_crInstance.m_M[1][0];
  m_M[1][1] = a_crInstance.m_M[1][1];
  m_M[1][2] = a_crInstance.m_M[1][2];
  m_M[2][0] = a_crInstance.m_M[2][0];
  m_M[2][1] = a_crInstance.m_M[2][1];
  m_M[2][2] = a_crInstance.m_M[2][2];
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::set(const CMatrix4D& a_crInstance)
{ CALL
  m_M[0][0] = a_crInstance.m_M[0][0];
  m_M[0][1] = a_crInstance.m_M[0][1];
  m_M[0][2] = a_crInstance.m_M[0][2];
  m_M[1][0] = a_crInstance.m_M[1][0];
  m_M[1][1] = a_crInstance.m_M[1][1];
  m_M[1][2] = a_crInstance.m_M[1][2];
  m_M[2][0] = a_crInstance.m_M[2][0];
  m_M[2][1] = a_crInstance.m_M[2][1];
  m_M[2][2] = a_crInstance.m_M[2][2];
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::clear(const Tbool a_cIdentityFlag/* = false */)
{ CALL
  m_M[0][0] = (a_cIdentityFlag ? CONSTR(1.0) : CONSTR(0.0));
  m_M[0][1] = 0.0;
  m_M[0][2] = 0.0;
  m_M[1][0] = 0.0;
  m_M[1][1] = (a_cIdentityFlag ? CONSTR(1.0) : CONSTR(0.0));
  m_M[1][2] = 0.0;
  m_M[2][0] = 0.0;
  m_M[2][1] = 0.0;
  m_M[2][2] = (a_cIdentityFlag ? CONSTR(1.0) : CONSTR(0.0));
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::absolute()
{ CALL
  m_M[0][0] = NMath::CMath::fabs(m_M[0][0]);
  m_M[0][1] = NMath::CMath::fabs(m_M[0][1]);
  m_M[0][2] = NMath::CMath::fabs(m_M[0][2]);
  m_M[1][0] = NMath::CMath::fabs(m_M[1][0]);
  m_M[1][1] = NMath::CMath::fabs(m_M[1][1]);
  m_M[1][2] = NMath::CMath::fabs(m_M[1][2]);
  m_M[2][0] = NMath::CMath::fabs(m_M[2][0]);
  m_M[2][1] = NMath::CMath::fabs(m_M[2][1]);
  m_M[2][2] = NMath::CMath::fabs(m_M[2][2]);
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::negate()
{ CALL
  m_M[0][0] = -m_M[0][0];
  m_M[0][1] = -m_M[0][1];
  m_M[0][2] = -m_M[0][2];
  m_M[1][0] = -m_M[1][0];
  m_M[1][1] = -m_M[1][1];
  m_M[1][2] = -m_M[1][2];
  m_M[2][0] = -m_M[2][0];
  m_M[2][1] = -m_M[2][1];
  m_M[2][2] = -m_M[2][2];
}
/*--------------------------------------------------------------------------*/
Treal CMatrix3D::getDeterminant() const
{ CALL
  #define DET22(M00, M01, M10, M11) (M00 * M11 - M01 * M10)
  #define DET33(M00, M01, M02, M10, M11, M12, M20, M21, M22) (M00 * DET22(M11, M12, M21, M22) - M01 * DET22(M10, M12, M20, M22) + M02 * DET22(M10, M11, M20, M21))
  return DET33(m_M[0][0], m_M[0][1], m_M[0][2], m_M[1][0], m_M[1][1], m_M[1][2], m_M[2][0], m_M[2][1], m_M[2][2]);
  #undef DET33
  #undef DET22
}
/*--------------------------------------------------------------------------*/
Treal CMatrix3D::getRotateAngle2D() const
{ CALL
  return NMath::CMath::atan2(m_M[0][1], m_M[0][0]);
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::getRotateAxisAngle(CVector3D& a_rAxis, Treal& a_rAngle) const
{ CALL
  // Let (x,y,z) be the unit-length axis and let A be an angle of rotation.
  // The rotation matrix is R = I + sin(A)*P + (1-cos(A))*P^2 where
  // I is the identity and
  //
  //       +-        -+
  //   P = |  0 -z +y |
  //       | +z  0 -x |
  //       | -y +x  0 |
  //       +-        -+
  //
  // If A > 0, R represents a counterclockwise rotation about the axis in
  // the sense of looking from the tip of the axis vector towards the
  // origin.  Some algebra will show that
  //
  //   cos(A) = (trace(R)-1)/2  and  R - R^t = 2*sin(A)*P
  //
  // In the event that A = pi, R-R^t = 0 which prevents us from extracting
  // the axis through P.  Instead note that R = I+2*P^2 when A = pi, so
  // P^2 = (R-I)/2.  The diagonal entries of P^2 are x^2-1, y^2-1, and
  // z^2-1.  We can solve these for axis (x,y,z).  Because the angle is pi,
  // it does not matter which sign you choose on the square roots.

  Treal trace = m_M[0][0] + m_M[1][1] + m_M[2][2];
  Treal cos_angle = CONSTR(0.5) * (trace - CONSTR(1.0));
  a_rAngle = NMath::CMath::acos(cos_angle);

  if (a_rAngle > 0.0)
  {
    if (a_rAngle < NMath::CMathConstants::PI)
    {
      a_rAxis.m_X = m_M[1][2] - m_M[2][1];
      a_rAxis.m_Y = m_M[2][0] - m_M[0][2];
      a_rAxis.m_Z = m_M[0][1] - m_M[1][0];
      a_rAxis.normalize();
    }
    else
    {
      // Angle is PI.
      Treal half_inverse;
      if (m_M[0][0] >= m_M[1][1])
      {
        // r00>=r11.
        if (m_M[0][0] >= m_M[2][2])
        {
          // r00 is maximum diagonal term.
          a_rAxis.m_X = CONSTR(0.5) * NMath::CMath::sqrt(m_M[0][0] - m_M[1][1] - m_M[2][2] + CONSTR(1.0));
          half_inverse = CONSTR(0.5) / a_rAxis.m_X;
          a_rAxis.m_Y = half_inverse * m_M[1][0];
          a_rAxis.m_Z = half_inverse * m_M[2][0];
        }
        else
        {
          // r22 is maximum diagonal term.
          a_rAxis.m_Z = CONSTR(0.5) * NMath::CMath::sqrt(m_M[2][2] - m_M[0][0] - m_M[1][1] + CONSTR(1.0));
          half_inverse = CONSTR(0.5) / a_rAxis.m_Z;
          a_rAxis.m_X = half_inverse * m_M[2][0];
          a_rAxis.m_Y = half_inverse * m_M[2][1];
        }
      }
      else
      {
        // r11 > r00.
        if (m_M[1][1] >= m_M[2][2])
        {
          // r11 is maximum diagonal term.
          a_rAxis.m_Y = CONSTR(0.5) * NMath::CMath::sqrt(m_M[1][1] - m_M[0][0] - m_M[2][2] + CONSTR(1.0));
          half_inverse = CONSTR(0.5) / a_rAxis.m_Y;
          a_rAxis.m_X = half_inverse * m_M[1][0];
          a_rAxis.m_Z = half_inverse * m_M[2][1];
        }
        else
        {
          // r22 is maximum diagonal term.
          a_rAxis.m_Z =CONSTR(0.5) * NMath::CMath::sqrt(m_M[2][2] - m_M[0][0] - m_M[1][1] + CONSTR(1.0));
          half_inverse = CONSTR(0.5) / a_rAxis.m_Z;
          a_rAxis.m_X = half_inverse * m_M[2][0];
          a_rAxis.m_Y = half_inverse * m_M[2][1];
        }
      }
    }
  }
  else
  {
    // The angle is 0 and the matrix is the identity.
    // Any axis will work, so just use the X-axis.
    a_rAxis.m_X = 1.0;
    a_rAxis.m_Y = 0.0;
    a_rAxis.m_Z = 0.0;
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::getRotateAnglesXYZ(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[2][0] < 1.0)
  {
    if (m_M[2][0] > -1.0)
    {
      a_rAngleX = NMath::CMath::atan2(-m_M[2][1], m_M[2][2]);
      a_rAngleY = NMath::CMath::asin(m_M[2][0]);
      a_rAngleZ = NMath::CMath::atan2(-m_M[1][0], m_M[0][0]);
    }
    else
    {
      // WARNING: Not unique. XA - ZA = -atan2(r01, r11)
      a_rAngleX = -NMath::CMath::atan2(m_M[0][1], m_M[1][1]);
      a_rAngleY = -NMath::CMathConstants::PI_2;
      a_rAngleZ =  0.0;
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. XA + ZA = atan2(r01, r11)
    a_rAngleX = NMath::CMath::atan2(m_M[0][1], m_M[1][1]);
    a_rAngleY = NMath::CMathConstants::PI_2;
    a_rAngleZ = 0.0;
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::getRotateAnglesXZY(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[1][0] < 1.0)
  {
    if (m_M[1][0] > -1.0)
    {
      a_rAngleX = NMath::CMath::atan2(m_M[1][2], m_M[1][1]);
      a_rAngleY = NMath::CMath::atan2(m_M[2][0], m_M[0][0]);
      a_rAngleZ = NMath::CMath::asin(-m_M[1][0]);
    }
    else
    {
      // WARNING: Not unique. XA - YA = atan2(r02, r22)
      a_rAngleX = NMath::CMath::atan2(m_M[0][2], m_M[2][2]);
      a_rAngleY = 0.0;
      a_rAngleZ = NMath::CMathConstants::PI_2;
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. XA + YA = atan2(-r02, r22)
    a_rAngleX =  NMath::CMath::atan2(-m_M[0][2], m_M[2][2]);
    a_rAngleY =  0.0;
    a_rAngleZ = -NMath::CMathConstants::PI_2;
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::getRotateAnglesYXZ(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[2][1] < 1.0)
  {
    if (m_M[2][1] > -1.0)
    {
      a_rAngleX = NMath::CMath::asin(-m_M[2][1]);
      a_rAngleY = NMath::CMath::atan2(m_M[2][0], m_M[2][2]);
      a_rAngleZ = NMath::CMath::atan2(m_M[0][1], m_M[1][1]);
    }
    else
    {
      // WARNING: Not unique. YA - ZA = atan2(r10, r00)
      a_rAngleX = NMath::CMathConstants::PI_2;
      a_rAngleY = NMath::CMath::atan2(m_M[1][0], m_M[0][0]);
      a_rAngleZ = 0.0;
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. YA + ZA = atan2(-r10, r00)
    a_rAngleX = -NMath::CMathConstants::PI_2;
    a_rAngleY =  NMath::CMath::atan2(-m_M[1][0], m_M[0][0]);
    a_rAngleZ =  0.0;
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::getRotateAnglesYZX(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[0][1] < 1.0)
  {
    if (m_M[0][1] > -1.0)
    {
      a_rAngleX = NMath::CMath::atan2(-m_M[2][1], m_M[1][1]);
      a_rAngleY = NMath::CMath::atan2(-m_M[0][2], m_M[0][0]);
      a_rAngleZ = NMath::CMath::asin(m_M[0][1]);
    }
    else
    {
      // WARNING: Not unique. YA - XA = -atan2(r12, r22);
      a_rAngleX = 0.0;
      a_rAngleY = -NMath::CMath::atan2(m_M[1][2], m_M[2][2]);
      a_rAngleZ = -NMath::CMathConstants::PI_2;
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. YA + XA = atan2(r12, r22)
    a_rAngleX = 0.0;
    a_rAngleY = NMath::CMath::atan2(m_M[1][2], m_M[2][2]);
    a_rAngleZ = NMath::CMathConstants::PI_2;
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::getRotateAnglesZXY(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[1][2] < 1.0)
  {
    if (m_M[1][2] > -1.0)
    {
      a_rAngleX = NMath::CMath::asin(m_M[1][2]);
      a_rAngleY = NMath::CMath::atan2(-m_M[0][2], m_M[2][2]);
      a_rAngleZ = NMath::CMath::atan2(-m_M[1][0], m_M[1][1]);
    }
    else
    {
      // WARNING: Not unique. ZA - YA = -atan(r20, r00)
      a_rAngleX = -NMath::CMathConstants::PI_2;
      a_rAngleY =  0.0;
      a_rAngleZ = -NMath::CMath::atan2(m_M[2][0], m_M[0][0]);
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. ZA + YA = atan2(r20, r00)
    a_rAngleX = NMath::CMathConstants::PI_2;
    a_rAngleY = 0.0;
    a_rAngleZ = NMath::CMath::atan2(m_M[2][0], m_M[0][0]);
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::getRotateAnglesZYX(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[0][2] < 1.0)
  {
    if (m_M[0][2] > -1.0)
    {
      a_rAngleX = NMath::CMath::atan2(m_M[1][2], m_M[2][2]);
      a_rAngleY = NMath::CMath::asin(-m_M[0][2]);
      a_rAngleZ = NMath::CMath::atan2(m_M[0][1], m_M[0][0]);
    }
    else
    {
      // WARNING: Not unique. ZA - XA = -atan2(r10, r20)
      a_rAngleX =  0.0;
      a_rAngleY =  NMath::CMathConstants::PI_2;
      a_rAngleZ = -NMath::CMath::atan2(m_M[1][0], m_M[2][0]);
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. ZA + XA = atan2(-r10, -r20)
    a_rAngleX =  0.0;
    a_rAngleY = -NMath::CMathConstants::PI_2;
    a_rAngleZ =  NMath::CMath::atan2(-m_M[1][0], -m_M[2][0]);
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
Tbool CMatrix3D::decomposeEigen(CMatrix3D& a_rRotation, CMatrix3D& a_rScale) const
{ CALL
  // Factor M = R * D * transpose(R).
  // The columns of R are the eigenvectors.
  // The diagonal entries of D are the corresponding eigenvalues.
  Treal diag[3], sub_diag[3];
  a_rRotation.set(*this);
  a_rRotation.tridiagonalize(diag, sub_diag);
  if (!a_rRotation.QLAlgorithm(diag, sub_diag))
    return false;

  // The Householder transformation is a reflection.
  // Make the eigenvectors a right--handed system by changing sign on the last column.
  a_rRotation.m_M[0][2] = -a_rRotation.m_M[0][2];
  a_rRotation.m_M[1][2] = -a_rRotation.m_M[1][2];
  a_rRotation.m_M[2][2] = -a_rRotation.m_M[2][2];

  // (Insertion) sort eigenvalues in increasing order, d0 <= d1 <= d2.
  Treal save;
  if (diag[1] < diag[0])
  {
    // Swap d0 and d1.
    save = diag[0];
    diag[0] = diag[1];
    diag[1] = save;
    // Swap V0 and V1.
    save = a_rRotation.m_M[0][0];
    a_rRotation.m_M[0][0] = a_rRotation.m_M[1][0];
    a_rRotation.m_M[1][0] = save;
    save = a_rRotation.m_M[0][1];
    a_rRotation.m_M[0][1] = a_rRotation.m_M[1][1];
    a_rRotation.m_M[1][1] = save;
    save = a_rRotation.m_M[0][2];
    a_rRotation.m_M[0][2] = a_rRotation.m_M[1][2];
    a_rRotation.m_M[1][2] = save;
  }
  if (diag[2] < diag[1])
  {
    // Swap d1 and d2.
    save = diag[1];
    diag[1] = diag[2];
    diag[2] = save;
    // Swap V1 and V2.
    save = a_rRotation.m_M[1][0];
    a_rRotation.m_M[1][0] = a_rRotation.m_M[2][0];
    a_rRotation.m_M[2][0] = save;
    save = a_rRotation.m_M[1][1];
    a_rRotation.m_M[1][1] = a_rRotation.m_M[2][1];
    a_rRotation.m_M[2][1] = save;
    save = a_rRotation.m_M[1][2];
    a_rRotation.m_M[1][2] = a_rRotation.m_M[2][2];
    a_rRotation.m_M[2][2] = save;
  }
  if (diag[1] < diag[0])
  {
    // Swap d0 and d1.
    save = diag[0];
    diag[0] = diag[1];
    diag[1] = save;
    // Swap V0 and V1.
    save = a_rRotation.m_M[0][0];
    a_rRotation.m_M[0][0] = a_rRotation.m_M[1][0];
    a_rRotation.m_M[1][0] = save;
    save = a_rRotation.m_M[0][1];
    a_rRotation.m_M[0][1] = a_rRotation.m_M[1][1];
    a_rRotation.m_M[1][1] = save;
    save = a_rRotation.m_M[0][2];
    a_rRotation.m_M[0][2] = a_rRotation.m_M[1][2];
    a_rRotation.m_M[1][2] = save;
  }
  a_rScale.set(scale(diag[0], diag[1], diag[2]));
  return true;
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::decomposeQDU(CMatrix3D& a_rQ, CMatrix3D& a_rD, CMatrix3D& a_rU) const
{ CALL
  // Factor M = QR = QDU where Q is orthogonal (rotation), D is diagonal
  // (scaling),  and U is upper triangular with ones on its diagonal
  // (shear).  Algorithm uses Gram-Schmidt orthogonalization (the QR
  // algorithm).
  //
  // If M = [ m0 | m1 | m2 ] and Q = [ q0 | q1 | q2 ], then
  //
  //   q0 = m0/|m0|
  //   q1 = (m1-(q0*m1)q0)/|m1-(q0*m1)q0|
  //   q2 = (m2-(q0*m2)q0-(q1*m2)q1)/|m2-(q0*m2)q0-(q1*m2)q1|
  //
  // where |V| indicates length of vector V and A*B indicates dot
  // product of vectors A and B.  The matrix R has entries
  //
  //   r00 = q0*m0  r01 = q0*m1  r02 = q0*m2
  //   r10 = 0      r11 = q1*m1  r12 = q1*m2
  //   r20 = 0      r21 = 0      r22 = q2*m2
  //
  // so D = diag(r00,r11,r22) and U has entries u01 = r01/r00,
  // u02 = r02/r00, and u12 = r12/r11.

  // Build orthogonal matrix Q.
  Treal dot, len;
  len = NMath::CMath::sqrt(m_M[0][0] * m_M[0][0] + m_M[0][1] * m_M[0][1] + m_M[0][2] * m_M[0][2]);
  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;
  a_rQ.m_M[0][0] = m_M[0][0] * len;
  a_rQ.m_M[0][1] = m_M[0][1] * len;
  a_rQ.m_M[0][2] = m_M[0][2] * len;
  dot = a_rQ.m_M[0][0] * m_M[1][0] + a_rQ.m_M[0][1] * m_M[1][1] + a_rQ.m_M[0][2] * m_M[1][2];
  a_rQ.m_M[1][0] = m_M[1][0] - dot * a_rQ.m_M[0][0];
  a_rQ.m_M[1][1] = m_M[1][1] - dot * a_rQ.m_M[0][1];
  a_rQ.m_M[2][1] = m_M[1][2] - dot * a_rQ.m_M[0][2];
  len = NMath::CMath::sqrt(a_rQ.m_M[1][0] * a_rQ.m_M[1][0] + a_rQ.m_M[1][1] * a_rQ.m_M[1][1] + a_rQ.m_M[1][2] * a_rQ.m_M[1][2]);
  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;
  a_rQ.m_M[1][0] *= len;
  a_rQ.m_M[1][1] *= len;
  a_rQ.m_M[1][2] *= len;
  dot = a_rQ.m_M[0][0] * m_M[2][0] + a_rQ.m_M[0][1] * m_M[2][1] + a_rQ.m_M[0][2] * m_M[2][2];
  a_rQ.m_M[2][0] = m_M[2][0] - dot * a_rQ.m_M[0][0];
  a_rQ.m_M[2][1] = m_M[2][1] - dot * a_rQ.m_M[0][1];
  a_rQ.m_M[2][2] = m_M[2][2] - dot * a_rQ.m_M[0][2];
  dot = a_rQ.m_M[1][0] * m_M[2][0] + a_rQ.m_M[1][1] * m_M[2][1] + a_rQ.m_M[1][2] * m_M[2][2];
  a_rQ.m_M[2][0] -= dot * a_rQ.m_M[1][0];
  a_rQ.m_M[2][1] -= dot * a_rQ.m_M[1][1];
  a_rQ.m_M[2][2] -= dot * a_rQ.m_M[1][2];
  len = NMath::CMath::sqrt(a_rQ.m_M[2][0] * a_rQ.m_M[2][0] + a_rQ.m_M[2][1] * a_rQ.m_M[2][1] + a_rQ.m_M[2][2] * a_rQ.m_M[2][2]);
  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;
  a_rQ.m_M[2][0] *= len;
  a_rQ.m_M[2][1] *= len;
  a_rQ.m_M[2][2] *= len;

  // Guarantee that orthogonal matrix has determinant 1 (no reflections).
  Treal det = a_rQ.m_M[0][0] * a_rQ.m_M[1][1] * a_rQ.m_M[2][2] + a_rQ.m_M[1][0] * a_rQ.m_M[2][1] * a_rQ.m_M[0][2] +
              a_rQ.m_M[2][0] * a_rQ.m_M[0][1] * a_rQ.m_M[1][2] - a_rQ.m_M[2][0] * a_rQ.m_M[1][1] * a_rQ.m_M[0][2] -
              a_rQ.m_M[1][0] * a_rQ.m_M[0][1] * a_rQ.m_M[2][2] - a_rQ.m_M[0][0] * a_rQ.m_M[2][1] * a_rQ.m_M[1][2];
  if (det < 0.0)
  {
    a_rQ.m_M[0][0] = -a_rQ.m_M[0][0];
    a_rQ.m_M[0][1] = -a_rQ.m_M[0][1];
    a_rQ.m_M[0][2] = -a_rQ.m_M[0][2];
    a_rQ.m_M[1][0] = -a_rQ.m_M[1][0];
    a_rQ.m_M[1][1] = -a_rQ.m_M[1][1];
    a_rQ.m_M[1][2] = -a_rQ.m_M[1][2];
    a_rQ.m_M[2][0] = -a_rQ.m_M[2][0];
    a_rQ.m_M[2][1] = -a_rQ.m_M[2][1];
    a_rQ.m_M[2][2] = -a_rQ.m_M[2][2];
  }

  // Build "right" matrix R.
  CMatrix3D right;
  right.m_M[0][0] = a_rQ.m_M[0][0] * m_M[0][0] + a_rQ.m_M[0][1] * m_M[0][1] + a_rQ.m_M[0][2] * m_M[0][2];
  right.m_M[1][0] = a_rQ.m_M[0][0] * m_M[1][0] + a_rQ.m_M[0][1] * m_M[1][1] + a_rQ.m_M[0][2] * m_M[1][2];
  right.m_M[1][1] = a_rQ.m_M[1][0] * m_M[1][0] + a_rQ.m_M[1][1] * m_M[1][1] + a_rQ.m_M[1][2] * m_M[1][2];
  right.m_M[2][0] = a_rQ.m_M[0][0] * m_M[2][0] + a_rQ.m_M[0][1] * m_M[2][1] + a_rQ.m_M[0][2] * m_M[2][2];
  right.m_M[2][1] = a_rQ.m_M[1][0] * m_M[2][0] + a_rQ.m_M[1][1] * m_M[2][1] + a_rQ.m_M[1][2] * m_M[2][2];
  right.m_M[2][2] = a_rQ.m_M[2][0] * m_M[2][0] + a_rQ.m_M[2][1] * m_M[2][1] + a_rQ.m_M[2][2] * m_M[2][2];

  // The scaling component.
  a_rD.set(scale(right.m_M[0][0], right.m_M[1][1], right.m_M[2][2]));

  // The shear component.
  a_rU.m_M[0][0] = 1.0;
  a_rU.m_M[0][1] = 0.0;
  a_rU.m_M[0][2] = 0.0;
  a_rU.m_M[1][0] = right.m_M[1][0] / a_rD.m_M[0][0];
  a_rU.m_M[1][1] = 1.0;
  a_rU.m_M[1][2] = 0.0;
  a_rU.m_M[2][0] = right.m_M[2][0] / a_rD.m_M[0][0];
  a_rU.m_M[2][1] = right.m_M[2][1] / a_rD.m_M[1][1];
  a_rU.m_M[2][2] = 1.0;
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::decomposeSingular(CMatrix3D& a_rL, CMatrix3D& a_rS, CMatrix3D& a_rR) const
{ CALL
  const Treal epsilon = NMath::CMath::getEpsilon();
  const Tsint max_iterations = 32;

  CMatrix3D A(*this);

  a_rL.set(identity());
  a_rS.set(identity());
  a_rR.set(identity());
  A.bidiagonalize(a_rL, a_rR);
  for (Tsint i = 0; i < max_iterations; ++i)
  {
    Treal tmp, tmp0, tmp1;
    Treal sin0, cos0, tan0;
    Treal sin1, cos1, tan1;
    Tbool test1 = (NMath::CMath::fabs(A.m_M[1][0]) <= epsilon * (NMath::CMath::fabs(A.m_M[0][0]) + NMath::CMath::fabs(A.m_M[1][1])));
    Tbool test2 = (NMath::CMath::fabs(A.m_M[2][1]) <= epsilon * (NMath::CMath::fabs(A.m_M[1][1]) + NMath::CMath::fabs(A.m_M[2][2])));
    if (test1)
    {
      if (test2)
      {
        a_rS.m_M[0][0] = A.m_M[0][0];
        a_rS.m_M[1][1] = A.m_M[1][1];
        a_rS.m_M[2][2] = A.m_M[2][2];
        break;
      }
      else
      {
        // 2x2 closed form factorization.
        tmp = (A.m_M[1][1] * A.m_M[1][1] - A.m_M[2][2] * A.m_M[2][2] + A.m_M[2][1] * A.m_M[2][1]) / (A.m_M[2][1] * A.m_M[2][2]);
        tan0 = CONSTR(0.5) * (tmp + NMath::CMath::sqrt(tmp * tmp + CONSTR(4.0)));
        cos0 = CONSTR(1.0) / NMath::CMath::sqrt(CONSTR(1.0) + tan0 * tan0);
        sin0 = tan0 * cos0;
        for (Tsint col = 0; col < 3; ++col)
        {
          tmp0 = a_rL.m_M[1][col];
          tmp1 = a_rL.m_M[2][col];
          a_rL.m_M[1][col] = cos0 * tmp0 - sin0 * tmp1;
          a_rL.m_M[2][col] = sin0 * tmp0 + cos0 * tmp1;
        }
        tan1 = (A.m_M[2][1] - A.m_M[2][2] * tan0) / A.m_M[1][1];
        cos1 = CONSTR(1.0) / NMath::CMath::sqrt(CONSTR(1.0) + tan1 * tan1);
        sin1 = -tan1 * cos1;
        for (Tsint row = 0; row < 3; ++row)
        {
          tmp0 = a_rR.m_M[row][1];
          tmp1 = a_rR.m_M[row][2];
          a_rR.m_M[row][1] = cos1 * tmp0 - sin1 * tmp1;
          a_rR.m_M[row][2] = sin1 * tmp0 + cos1 * tmp1;
        }
        a_rS.m_M[0][0] = A.m_M[0][0];
        a_rS.m_M[1][1] = cos0 * cos1 * A.m_M[1][1] - sin1 * (cos0 * A.m_M[2][1] - sin0 * A.m_M[2][2]);
        a_rS.m_M[2][2] = sin0 * sin1 * A.m_M[1][1] + cos1 * (sin0 * A.m_M[2][1] + cos0 * A.m_M[2][2]);
        break;
      }
    }
    else
    {
      if (test2)
      {
        // 2x2 closed form factorization.
        tmp = (A.m_M[0][0] * A.m_M[0][0] + A.m_M[1][1] * A.m_M[1][1] - A.m_M[1][0] * A.m_M[1][0]) / (A.m_M[1][0] * A.m_M[1][1]);
        tan0 = CONSTR(0.5) * (-tmp + NMath::CMath::sqrt(tmp * tmp + CONSTR(4.0)));
        cos0 = CONSTR(1.0) / NMath::CMath::sqrt(CONSTR(1.0) + tan0 * tan0);
        sin0 = tan0 * cos0;
        for (Tsint col = 0; col < 3; ++col)
        {
          tmp0 = a_rL.m_M[0][col];
          tmp1 = a_rL.m_M[1][col];
          a_rL.m_M[0][col] = cos0 * tmp0 - sin0 * tmp1;
          a_rL.m_M[1][col] = sin0 * tmp0 + cos0 * tmp1;
        }
        tan1 = (A.m_M[1][0] - A.m_M[1][1] * tan0) / A.m_M[0][0];
        cos1 = CONSTR(1.0) / NMath::CMath::sqrt(CONSTR(1.0) + tan1 * tan1);
        sin1 = -tan1 * cos1;
        for (Tsint row = 0; row < 3; ++row)
        {
          tmp0 = a_rR.m_M[row][0];
          tmp1 = a_rR.m_M[row][1];
          a_rR.m_M[row][0] = cos1 * tmp0 - sin1 * tmp1;
          a_rR.m_M[row][1] = sin1 * tmp0 + cos1 * tmp1;
        }
        a_rS.m_M[0][0] = cos0 * cos1 * A.m_M[0][0] - sin1 * (cos0 * A.m_M[1][0] - sin0 * A.m_M[1][1]);
        a_rS.m_M[1][1] = sin0 * sin1 * A.m_M[0][0] + cos1 * (sin0 * A.m_M[1][0] + cos0 * A.m_M[1][1]);
        a_rS.m_M[2][2] = A.m_M[2][2];
        break;
      }
      else
        A.golubKahanStep(a_rL, a_rR);
    }
  }

  // Positize diagonal.
  for (Tsint col = 0; col < 3; ++col)
  {
    if (a_rS.m_M[col][col] < 0.0)
    {
      a_rS.m_M[col][col] = -a_rS.m_M[col][col];
      for (Tsint row = 0; row < 3; ++row)
        a_rR.m_M[row][col] = -a_rR.m_M[row][col];
    }
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::tridiagonalize(Treal a_pDiag[3], Treal a_pSubDiag[3])
{ CALL
  // Householder reduction T = Q^t M Q
  //   Input:
  //     this, symmetric 3x3 matrix M
  //   Output:
  //     this, orthogonal matrix Q (a reflection)
  //     Diag, diagonal entries of T
  //     DubDiag, subdiagonal entries of T (T is symmetric)

  Treal A = m_M[0][0];
  Treal B = m_M[1][0];
  Treal C = m_M[2][0];
  Treal D = m_M[1][1];
  Treal E = m_M[2][1];
  Treal F = m_M[2][2];

  a_pDiag[0] = A;
  a_pSubDiag[2] = 0.0;
  if (NMath::CMath::fabs(C) >= NMath::CMath::getEpsilon())
  {
    Treal len, length = NMath::CMath::sqrt(B*B+C*C);
    if (!NMath::CMath::isEqualZero(length))
      len = CONSTR(1.0) / length;
    else
      len = 1.0;
    B *= len;
    C *= len;
    Treal Q = CONSTR(2.0) * B * E + C * (F - D);
    a_pDiag[1] = D + C * Q;
    a_pDiag[2] = F - C * Q;
    a_pSubDiag[0] = length;
    a_pSubDiag[1] = E - B * Q;
    m_M[0][0] =  1.0;
    m_M[0][1] =  0.0;
    m_M[0][2] =  0.0;
    m_M[1][0] =  0.0;
    m_M[1][1] =  B;
    m_M[1][2] =  C;
    m_M[2][0] =  0.0;
    m_M[2][1] =  C;
    m_M[2][2] = -B;
  }
  else
  {
    a_pDiag[1] = D;
    a_pDiag[2] = F;
    a_pSubDiag[0] = B;
    a_pSubDiag[1] = E;
    m_M[0][0] =  1.0;
    m_M[0][1] =  0.0;
    m_M[0][2] =  0.0;
    m_M[1][0] =  0.0;
    m_M[1][1] =  1.0;
    m_M[1][2] =  0.0;
    m_M[2][0] =  0.0;
    m_M[2][1] =  0.0;
    m_M[2][2] = -1.0;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CMatrix3D::QLAlgorithm(Treal a_pDiag[3], Treal a_pSubDiag[3])
{ CALL
  const Tsint max_iterations=32;

  Tsint i0, i1, iter;

  for (i0 = 0; i0 < 3; ++i0)
  {
    for (iter = 0; iter < max_iterations; ++iter)
    {
      for (i1 = i0; i1 <= 1; ++i1)
      {
        Treal sum = NMath::CMath::fabs(a_pDiag[i1]) + NMath::CMath::fabs(a_pDiag[i1 + 1]);
        if (NMath::CMath::isEqual(NMath::CMath::fabs(a_pSubDiag[i1]) + sum, sum))
          break;
      }

      if (i1 == i0)
        break;

      Treal tmp0 = (a_pDiag[i0 + 1] - a_pDiag[i0]) / (CONSTR(2.0) * a_pSubDiag[i0]);
      Treal tmp1 = NMath::CMath::sqrt(tmp0 * tmp0 + CONSTR(1.0));
      if (tmp0 < 0.0)
        tmp0 = a_pDiag[i1] - a_pDiag[i0] + a_pSubDiag[i0] / (tmp0 - tmp1);
      else
        tmp0 = a_pDiag[i1] - a_pDiag[i0] + a_pSubDiag[i0] / (tmp0 + tmp1);

      Treal sin_angle = 1.0;
      Treal cos_angle = 1.0;
      Treal tmp2 = 0.0;
      for (Tsint i2 = i1 - 1; i2 >= i0; --i2)
      {
        Treal tmp3 = sin_angle * a_pSubDiag[i2];
        Treal tmp4 = cos_angle * a_pSubDiag[i2];
        if (NMath::CMath::fabs(tmp3) >= NMath::CMath::fabs(tmp0))
        {
          cos_angle = tmp0 / tmp3;
          tmp1 = NMath::CMath::sqrt(cos_angle * cos_angle + CONSTR(1.0));
          a_pSubDiag[i2 + 1] = tmp3 * tmp1;
          sin_angle = CONSTR(1.0) / tmp1;
          cos_angle *= sin_angle;
        }
        else
        {
          sin_angle = tmp3 / tmp0;
          tmp1 = NMath::CMath::sqrt(sin_angle * sin_angle + CONSTR(1.0));
          a_pSubDiag[i2 + 1] = tmp0 * tmp1;
          cos_angle = CONSTR(1.0) / tmp1;
          sin_angle *= cos_angle;
        }
        tmp0 = a_pDiag[i2 + 1] - tmp2;
        tmp1 = (a_pDiag[i2] - tmp0) * sin_angle + CONSTR(2.0) * tmp4 * cos_angle;
        tmp2 = sin_angle * tmp1;
        a_pDiag[i2 + 1] = tmp0 + tmp2;
        tmp0 = cos_angle * tmp1 - tmp4;
        for (Tsint col = 0; col < 3; ++col)
        {
          tmp3 = m_M[i2 + 1][col];
          m_M[i2 + 1][col] = sin_angle * m_M[i2][col] + cos_angle * tmp3;
          m_M[i2][col] = cos_angle * m_M[i2][col] - sin_angle * tmp3;
        }
      }
      a_pDiag[i0] -= tmp2;
      a_pSubDiag[i0] = tmp0;
      a_pSubDiag[i1] = 0.0;
    }

    if (iter == max_iterations)
    {
      // Should not get here under normal circumstances
      WARNING(STR("QL iteration with implicit shifting to reduce matrix from tridiagonal to diagonal."));
      return false;
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::bidiagonalize(CMatrix3D& a_rLOrthogonal, CMatrix3D& a_rROrthogonal)
{ CALL
  Treal V[3], W[3];
  Treal length, sign, T1, invT1, T2;
  Tbool ident;

  // Map first column to (*, 0, 0).
  length = NMath::CMath::sqrt(m_M[0][0] * m_M[0][0] + m_M[0][1] * m_M[0][1] + m_M[0][2] * m_M[0][2]);
  if (length > 0.0)
  {
    sign = ((m_M[0][0] > 0.0) ? CONSTR(1.0) : CONSTR(-1.0));
    T1 = m_M[0][0] + sign * length;
    invT1 = CONSTR(1.0) / T1;
    V[1] = m_M[0][1] * invT1;
    V[2] = m_M[0][2] * invT1;
    T2 = CONSTR(-2.0) / (CONSTR(1.0) + V[1] * V[1] + V[2] * V[2]);
    W[0] = T2 * (m_M[0][0] + m_M[0][1] * V[1] + m_M[0][2] * V[2]);
    W[1] = T2 * (m_M[1][0] + m_M[1][1] * V[1] + m_M[1][2] * V[2]);
    W[2] = T2 * (m_M[2][0] + m_M[2][1] * V[1] + m_M[2][2] * V[2]);
    m_M[0][0] += W[0];
    m_M[1][0] += W[1];
    m_M[1][1] += V[1] * W[1];
    m_M[1][2] += V[2] * W[1];
    m_M[2][0] += W[2];
    m_M[2][1] += V[1] * W[2];
    m_M[2][2] += V[2] * W[2];
    a_rLOrthogonal.m_M[0][0] = CONSTR(1.0) + T2;
    a_rLOrthogonal.m_M[0][1] = a_rLOrthogonal.m_M[1][0];
    a_rLOrthogonal.m_M[0][2] = a_rLOrthogonal.m_M[2][0];
    a_rLOrthogonal.m_M[1][0] = T2 * V[1];
    a_rLOrthogonal.m_M[1][1] = CONSTR(1.0) + T2 * V[1] * V[1];
    a_rLOrthogonal.m_M[1][2] = a_rLOrthogonal.m_M[2][1];
    a_rLOrthogonal.m_M[2][0] = T2 * V[2];
    a_rLOrthogonal.m_M[2][1] = T2 * V[1] * V[2];
    a_rLOrthogonal.m_M[2][2] = CONSTR(1.0) + T2 * V[2] * V[2];
    ident = false;
  }
  else
  {
    a_rLOrthogonal.set(identity());
    ident = true;
  }

  // Map first row to (*, *, 0).
  length = NMath::CMath::sqrt(m_M[1][0] * m_M[1][0] + m_M[2][0] * m_M[2][0]);
  if (length > 0.0)
  {
    sign = ((m_M[1][0] > 0.0) ? CONSTR(1.0) : CONSTR(-1.0));
    T1 = m_M[1][0] + sign * length;
    V[2] = m_M[2][0] / T1;
    T2 = CONSTR(-2.0) / (CONSTR(1.0) + V[2] * V[2]);
    W[0] = T2 * (m_M[1][0] + m_M[2][0] * V[2]);
    W[1] = T2 * (m_M[1][1] + m_M[2][1] * V[2]);
    W[2] = T2 * (m_M[1][2] + m_M[2][2] * V[2]);
    m_M[1][0] += W[0];
    m_M[1][1] += W[1];
    m_M[1][2] += W[2];
    m_M[2][1] += W[1] * V[2];
    m_M[2][2] += W[2] * V[2];
    a_rROrthogonal.m_M[0][0] = 1.0;
    a_rROrthogonal.m_M[0][1] = 0.0;
    a_rROrthogonal.m_M[0][2] = 0.0;
    a_rROrthogonal.m_M[1][0] = 0.0;
    a_rROrthogonal.m_M[1][1] = CONSTR(1.0) + T2;
    a_rROrthogonal.m_M[1][2] = a_rROrthogonal.m_M[2][1];
    a_rROrthogonal.m_M[2][0] = 0.0;
    a_rROrthogonal.m_M[2][1] = T2 * V[2];
    a_rROrthogonal.m_M[2][2] = CONSTR(1.0) + T2 * V[2] * V[2];
  }
  else
    a_rROrthogonal.set(identity());

  // Map second column to (*, *, 0).
  length = NMath::CMath::sqrt(m_M[1][1] * m_M[1][1] + m_M[1][2] * m_M[1][2]);
  if (length > 0.0)
  {
    sign = ((m_M[1][1] > 0.0) ? CONSTR(1.0) : CONSTR(-1.0));
    T1 = m_M[1][1] + sign * length;
    V[2] = m_M[1][2] / T1;
    T2 = CONSTR(-2.0) / (CONSTR(1.0) + V[2] * V[2]);
    W[1] = T2 * (m_M[1][1] + m_M[1][2] * V[2]);
    W[2] = T2 * (m_M[2][1] + m_M[2][2] * V[2]);
    m_M[1][1] += W[1];
    m_M[2][1] += W[2];
    m_M[2][2] += V[2] * W[2];
    Treal A = CONSTR(1.0) + T2;
    Treal B = T2 * V[2];
    Treal C = CONSTR(1.0) + B * V[2];
    if (ident)
    {
      a_rLOrthogonal.m_M[0][0] = 1.0;
      a_rLOrthogonal.m_M[0][1] = 0.0;
      a_rLOrthogonal.m_M[0][2] = 0.0;
      a_rLOrthogonal.m_M[1][0] = 0.0;
      a_rLOrthogonal.m_M[1][1] = A;
      a_rLOrthogonal.m_M[1][2] = B;
      a_rLOrthogonal.m_M[2][0] = 0.0;
      a_rLOrthogonal.m_M[2][1] = B;
      a_rLOrthogonal.m_M[2][2] = C;
    }
    else
    {
      for (Tsint col = 0; col < 3; ++col)
      {
        Treal tmp0 = a_rLOrthogonal.m_M[1][col];
        Treal tmp1 = a_rLOrthogonal.m_M[2][col];
        a_rLOrthogonal.m_M[1][col] = A * tmp0 + B * tmp1;
        a_rLOrthogonal.m_M[2][col] = B * tmp0 + C * tmp1;
      }
    }
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::golubKahanStep(CMatrix3D& a_rLOrthogonal, CMatrix3D& a_rROrthogonal)
{ CALL
  Treal T11 = m_M[1][0] * m_M[1][0] + m_M[1][1] * m_M[1][1];
  Treal T22 = m_M[2][1] * m_M[2][1] + m_M[2][2] * m_M[2][2];
  Treal T12 = m_M[1][1] * m_M[2][1];
  Treal trace = T11 + T22;
  Treal diff = T11 - T22;
  Treal discr = NMath::CMath::sqrt(diff * diff + CONSTR(4.0) * T12 * T12);
  Treal root1 = CONSTR(0.5) * (trace + discr);
  Treal root2 = CONSTR(0.5) * (trace - discr);

  // Adjust right.
  Treal Y = m_M[0][0] - ((NMath::CMath::fabs(root1 - T22) <= NMath::CMath::fabs(root2 - T22)) ? root1 : root2);
  Treal Z = m_M[1][0];
  Treal inv_length = CONSTR(1.0) / NMath::CMath::sqrt(Y * Y + Z * Z);
  Treal sin_angle =  Z * inv_length;
  Treal cos_angle = -Y * inv_length;
  Treal tmp0 = m_M[0][0];
  Treal tmp1 = m_M[1][0];
  m_M[0][0]=  cos_angle * tmp0 - sin_angle * tmp1;
  m_M[0][1]= -sin_angle * m_M[1][1];
  m_M[1][0]=  sin_angle * tmp0 + cos_angle * tmp1;
  m_M[1][1] *= cos_angle;
  for (Tsint row = 0; row < 3; ++row)
  {
    tmp0 = a_rROrthogonal.m_M[row][0];
    tmp1 = a_rROrthogonal.m_M[row][1];
    a_rROrthogonal.m_M[row][0] = cos_angle * tmp0 - sin_angle * tmp1;
    a_rROrthogonal.m_M[row][1] = sin_angle * tmp0 + cos_angle * tmp1;
  }

  // Adjust left.
  Y = m_M[0][0];
  Z = m_M[0][1];
  inv_length = CONSTR(1.0) / NMath::CMath::sqrt(Y * Y + Z * Z);
  sin_angle=  Z * inv_length;
  cos_angle= -Y * inv_length;
  m_M[0][0] = cos_angle * m_M[0][0] - sin_angle * m_M[0][1];
  tmp0 = m_M[1][0];
  tmp1 = m_M[1][1];
  m_M[1][0]=  cos_angle * tmp0 - sin_angle * tmp1;
  m_M[1][1]=  sin_angle * tmp0 + cos_angle * tmp1;
  m_M[2][0]= -sin_angle * m_M[2][1];
  m_M[2][1] *= cos_angle;
  for (Tsint col = 0; col < 3; ++col)
  {
    tmp0 = a_rLOrthogonal.m_M[0][col];
    tmp1 = a_rLOrthogonal.m_M[1][col];
    a_rLOrthogonal.m_M[0][col] = cos_angle * tmp0 - sin_angle * tmp1;
    a_rLOrthogonal.m_M[1][col] = sin_angle * tmp0 + cos_angle * tmp1;
  }

  // Adjust right.
  Y = m_M[1][0];
  Z = m_M[2][0];
  inv_length = CONSTR(1.0) / NMath::CMath::sqrt(Y * Y + Z * Z);
  sin_angle =  Z * inv_length;
  cos_angle = -Y * inv_length;
  m_M[1][0] = cos_angle * m_M[1][0] - sin_angle * m_M[2][0];
  tmp0 = m_M[1][1];
  tmp1 = m_M[2][1];
  m_M[1][1] =  cos_angle * tmp0 - sin_angle * tmp1;
  m_M[1][2] = -sin_angle * m_M[2][2];
  m_M[2][1] =  sin_angle * tmp0 + cos_angle * tmp1;
  m_M[2][2] *= cos_angle;
  for (Tsint row = 0; row < 3; ++row)
  {
    tmp0 = a_rROrthogonal.m_M[row][1];
    tmp1 = a_rROrthogonal.m_M[row][2];
    a_rROrthogonal.m_M[row][1] = cos_angle * tmp0 - sin_angle * tmp1;
    a_rROrthogonal.m_M[row][2] = sin_angle * tmp0 + cos_angle * tmp1;
  }

  // Adjust left.
  Y = m_M[1][1];
  Z = m_M[1][2];
  inv_length = NMath::CMath::sqrt(Y * Y + Z * Z);
  sin_angle =  Z * inv_length;
  cos_angle = -Y * inv_length;
  m_M[1][1] = cos_angle * m_M[1][1] - sin_angle * m_M[1][2];
  tmp0 = m_M[2][1];
  tmp1 = m_M[2][2];
  m_M[2][1] = cos_angle * tmp0 - sin_angle * tmp1;
  m_M[2][2] = sin_angle * tmp0 + cos_angle * tmp1;
  for (Tsint col = 0; col < 3; ++col)
  {
    tmp0 = a_rLOrthogonal.m_M[1][col];
    tmp1 = a_rLOrthogonal.m_M[2][col];
    a_rLOrthogonal.m_M[1][col] = cos_angle * tmp0 - sin_angle * tmp1;
    a_rLOrthogonal.m_M[2][col] = sin_angle * tmp0 + cos_angle * tmp1;
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::orthonormalize()
{ CALL
  Treal len, dot0, dot1;

  // Compute q0.
  len = NMath::CMath::sqrt(m_M[0][0] * m_M[0][0] + m_M[0][1] * m_M[0][1] + m_M[0][2] * m_M[0][2]);
  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;
  m_M[0][0] *= len;
  m_M[0][1] *= len;
  m_M[0][2] *= len;

  // Compute q1.
  dot0 = m_M[0][0] * m_M[1][0] + m_M[0][1] * m_M[1][1] + m_M[0][2] * m_M[1][2];
  m_M[1][0] -= dot0 * m_M[0][0];
  m_M[1][1] -= dot0 * m_M[0][1];
  m_M[1][2] -= dot0 * m_M[0][2];
  len = NMath::CMath::sqrt(m_M[1][0] * m_M[1][0] + m_M[1][1] * m_M[1][1] + m_M[1][2] * m_M[1][2]);
  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;
  m_M[1][0] *= len;
  m_M[1][1] *= len;
  m_M[1][2] *= len;

  // Compute q2.
  dot0 = m_M[0][0] * m_M[2][0] + m_M[0][1] * m_M[2][1] + m_M[0][2] * m_M[2][2];
  dot1 = m_M[1][0] * m_M[2][0] + m_M[1][1] * m_M[2][1] + m_M[1][2] * m_M[2][2];
  m_M[2][0] -= dot0 * m_M[0][0] + dot1 * m_M[1][0];
  m_M[2][1] -= dot0 * m_M[0][1] + dot1 * m_M[1][1];
  m_M[2][2] -= dot0 * m_M[0][2] + dot1 * m_M[1][2];
  len = NMath::CMath::sqrt(m_M[2][0] * m_M[2][0] + m_M[2][1] * m_M[2][1] + m_M[2][2] * m_M[2][2]);
  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;
  m_M[2][0] *= len;
  m_M[2][1] *= len;
  m_M[2][2] *= len;
}
/*--------------------------------------------------------------------------*/
CPoint2D<Treal> CMatrix3D::rotate(const CPoint2D<Treal>& a_crPoint2D) const
{ CALL
  CPoint2D<Treal> result;

  result.m_X = a_crPoint2D.m_X * m_M[0][0] + a_crPoint2D.m_Y * m_M[1][0];
  result.m_Y = a_crPoint2D.m_X * m_M[0][1] + a_crPoint2D.m_Y * m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CVector2D CMatrix3D::rotate(const CVector2D& a_crVector2D) const
{ CALL
  CVector2D result;

  result.m_X = a_crVector2D.m_X * m_M[0][0] + a_crVector2D.m_Y * m_M[1][0];
  result.m_Y = a_crVector2D.m_X * m_M[0][1] + a_crVector2D.m_Y * m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CPoint2D<Treal> CMatrix3D::transform(const CPoint2D<Treal>& a_crPoint2D) const
{ CALL
  CPoint2D<Treal> result;

  result.m_X = a_crPoint2D.m_X * m_M[0][0] + a_crPoint2D.m_Y * m_M[1][0] + m_M[2][0];
  result.m_Y = a_crPoint2D.m_X * m_M[0][1] + a_crPoint2D.m_Y * m_M[1][1] + m_M[2][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CPoint3D<Treal> CMatrix3D::transform(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  CPoint3D<Treal> result;

  result.m_X = a_crPoint3D.m_X * m_M[0][0] + a_crPoint3D.m_Y * m_M[1][0] + a_crPoint3D.m_Z * m_M[2][0];
  result.m_Y = a_crPoint3D.m_X * m_M[0][1] + a_crPoint3D.m_Y * m_M[1][1] + a_crPoint3D.m_Z * m_M[2][1];
  result.m_Z = a_crPoint3D.m_X * m_M[0][2] + a_crPoint3D.m_Y * m_M[1][2] + a_crPoint3D.m_Z * m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CVector2D CMatrix3D::transform(const CVector2D& a_crVector2D) const
{ CALL
  CVector2D result;

  result.m_X = a_crVector2D.m_X * m_M[0][0] + a_crVector2D.m_Y * m_M[1][0] + m_M[2][0];
  result.m_Y = a_crVector2D.m_X * m_M[0][1] + a_crVector2D.m_Y * m_M[1][1] + m_M[2][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CVector3D CMatrix3D::transform(const CVector3D& a_crVector3D) const
{ CALL
  CVector3D result;

  result.m_X = a_crVector3D.m_X * m_M[0][0] + a_crVector3D.m_Y * m_M[1][0] + a_crVector3D.m_Z * m_M[2][0];
  result.m_Y = a_crVector3D.m_X * m_M[0][1] + a_crVector3D.m_Y * m_M[1][1] + a_crVector3D.m_Z * m_M[2][1];
  result.m_Z = a_crVector3D.m_X * m_M[0][2] + a_crVector3D.m_Y * m_M[1][2] + a_crVector3D.m_Z * m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CVector4D CMatrix3D::transform(const CVector4D& a_crVector4D) const
{ CALL
  CVector4D result;

  result.m_X = a_crVector4D.m_X * m_M[0][0] + a_crVector4D.m_Y * m_M[1][0] + a_crVector4D.m_Z * m_M[2][0];
  result.m_Y = a_crVector4D.m_X * m_M[0][1] + a_crVector4D.m_Y * m_M[1][1] + a_crVector4D.m_Z * m_M[2][1];
  result.m_Z = a_crVector4D.m_X * m_M[0][2] + a_crVector4D.m_Y * m_M[1][2] + a_crVector4D.m_Z * m_M[2][2];
  result.m_W = a_crVector4D.m_W;
  return result;
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::rotate(const CPoint2D<Treal>& a_crPoint2D, CPoint2D<Treal>& a_rResult) const
{ CALL
  a_rResult.m_X = a_crPoint2D.m_X * m_M[0][0] + a_crPoint2D.m_Y * m_M[1][0];
  a_rResult.m_Y = a_crPoint2D.m_X * m_M[0][1] + a_crPoint2D.m_Y * m_M[1][1];
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::rotate(const CVector2D& a_crVector2D, CVector2D& a_rResult) const
{ CALL
  a_rResult.m_X = a_crVector2D.m_X * m_M[0][0] + a_crVector2D.m_Y * m_M[1][0];
  a_rResult.m_Y = a_crVector2D.m_X * m_M[0][1] + a_crVector2D.m_Y * m_M[1][1];
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::transform(const CPoint2D<Treal>& a_crPoint2D, CPoint2D<Treal>& a_rResult) const
{ CALL
  a_rResult.m_X = a_crPoint2D.m_X * m_M[0][0] + a_crPoint2D.m_Y * m_M[1][0] + m_M[2][0];
  a_rResult.m_Y = a_crPoint2D.m_X * m_M[0][1] + a_crPoint2D.m_Y * m_M[1][1] + m_M[2][1];
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::transform(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  a_rResult.m_X = a_crPoint3D.m_X * m_M[0][0] + a_crPoint3D.m_Y * m_M[1][0] + a_crPoint3D.m_Z * m_M[2][0];
  a_rResult.m_Y = a_crPoint3D.m_X * m_M[0][1] + a_crPoint3D.m_Y * m_M[1][1] + a_crPoint3D.m_Z * m_M[2][1];
  a_rResult.m_Z = a_crPoint3D.m_X * m_M[0][2] + a_crPoint3D.m_Y * m_M[1][2] + a_crPoint3D.m_Z * m_M[2][2];
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::transform(const CVector2D& a_crVector2D, CVector2D& a_rResult) const
{ CALL
  a_rResult.m_X = a_crVector2D.m_X * m_M[0][0] + a_crVector2D.m_Y * m_M[1][0] + m_M[2][0];
  a_rResult.m_Y = a_crVector2D.m_X * m_M[0][1] + a_crVector2D.m_Y * m_M[1][1] + m_M[2][1];
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::transform(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  a_rResult.m_X = a_crVector3D.m_X * m_M[0][0] + a_crVector3D.m_Y * m_M[1][0] + a_crVector3D.m_Z * m_M[2][0];
  a_rResult.m_Y = a_crVector3D.m_X * m_M[0][1] + a_crVector3D.m_Y * m_M[1][1] + a_crVector3D.m_Z * m_M[2][1];
  a_rResult.m_Z = a_crVector3D.m_X * m_M[0][2] + a_crVector3D.m_Y * m_M[1][2] + a_crVector3D.m_Z * m_M[2][2];
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::transform(const CVector4D& a_crVector4D, CVector4D& a_rResult) const
{ CALL
  a_rResult.m_X = a_crVector4D.m_X * m_M[0][0] + a_crVector4D.m_Y * m_M[1][0] + a_crVector4D.m_Z * m_M[2][0];
  a_rResult.m_Y = a_crVector4D.m_X * m_M[0][1] + a_crVector4D.m_Y * m_M[1][1] + a_crVector4D.m_Z * m_M[2][1];
  a_rResult.m_Z = a_crVector4D.m_X * m_M[0][2] + a_crVector4D.m_Y * m_M[1][2] + a_crVector4D.m_Z * m_M[2][2];
  a_rResult.m_W = a_crVector4D.m_W;
}
/*--------------------------------------------------------------------------*/
CPoint2D<Treal> CMatrix3D::transformEx(const CPoint2D<Treal>& a_crPoint2D) const
{ CALL
  CPoint2D<Treal> result;

  result.m_X = a_crPoint2D.m_X * m_M[0][0] + a_crPoint2D.m_Y * m_M[1][0] + m_M[2][0];
  result.m_Y = a_crPoint2D.m_X * m_M[0][1] + a_crPoint2D.m_Y * m_M[1][1] + m_M[2][1];
  // Calculate the denominator.
  Treal denom = a_crPoint2D.m_X * m_M[0][2] + a_crPoint2D.m_Y * m_M[1][2] + m_M[2][2];
  if (!NMath::CMath::isEqualZero(denom))
    denom = CONSTR(1.0) / denom;
  else
    denom = 1.0;
  // Correct transformed coordinates.
  result.m_X *= denom;
  result.m_Y *= denom;
  return result;
}
/*--------------------------------------------------------------------------*/
CVector2D CMatrix3D::transformEx(const CVector2D& a_crVector2D) const
{ CALL
  CVector2D result;

  result.m_X = a_crVector2D.m_X * m_M[0][0] + a_crVector2D.m_Y * m_M[1][0] + m_M[2][0];
  result.m_Y = a_crVector2D.m_X * m_M[0][1] + a_crVector2D.m_Y * m_M[1][1] + m_M[2][1];
  // Calculate the denominator.
  Treal denom = a_crVector2D.m_X * m_M[0][2] + a_crVector2D.m_Y * m_M[1][2] + m_M[2][2];
  if (!NMath::CMath::isEqualZero(denom))
    denom = CONSTR(1.0) / denom;
  else
    denom = 1.0;
  // Correct transformed coordinates.
  result.m_X *= denom;
  result.m_Y *= denom;
  return result;
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::transformEx(const CPoint2D<Treal>& a_crPoint2D, CPoint2D<Treal>& a_rResult) const
{ CALL
  a_rResult.m_X = a_crPoint2D.m_X * m_M[0][0] + a_crPoint2D.m_Y * m_M[1][0] + m_M[2][0];
  a_rResult.m_Y = a_crPoint2D.m_X * m_M[0][1] + a_crPoint2D.m_Y * m_M[1][1] + m_M[2][1];
  // Calculate the denominator.
  Treal denom = a_crPoint2D.m_X * m_M[0][2] + a_crPoint2D.m_Y * m_M[1][2] + m_M[2][2];
  if (!NMath::CMath::isEqualZero(denom))
    denom = CONSTR(1.0) / denom;
  else
    denom = 1.0;
  // Correct transformed coordinates.
  a_rResult.m_X *= denom;
  a_rResult.m_Y *= denom;
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::transformEx(const CVector2D& a_crVector2D, CVector2D& a_rResult) const
{ CALL
  a_rResult.m_X = a_crVector2D.m_X * m_M[0][0] + a_crVector2D.m_Y * m_M[1][0] + m_M[2][0];
  a_rResult.m_Y = a_crVector2D.m_X * m_M[0][1] + a_crVector2D.m_Y * m_M[1][1] + m_M[2][1];
  // Calculate the denominator.
  Treal denom = a_crVector2D.m_X * m_M[0][2] + a_crVector2D.m_Y * m_M[1][2] + m_M[2][2];
  if (!NMath::CMath::isEqualZero(denom))
    denom = CONSTR(1.0) / denom;
  else
    denom = 1.0;
  // Correct transformed coordinates.
  a_rResult.m_X *= denom;
  a_rResult.m_Y *= denom;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::add(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] + a_crInstance2.m_M[0][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][1] + a_crInstance2.m_M[0][1];
  result.m_M[0][2] = a_crInstance1.m_M[0][2] + a_crInstance2.m_M[0][2];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] + a_crInstance2.m_M[1][0];
  result.m_M[1][1] = a_crInstance1.m_M[1][1] + a_crInstance2.m_M[1][1];
  result.m_M[1][2] = a_crInstance1.m_M[1][2] + a_crInstance2.m_M[1][2];
  result.m_M[2][0] = a_crInstance1.m_M[2][0] + a_crInstance2.m_M[2][0];
  result.m_M[2][1] = a_crInstance1.m_M[2][1] + a_crInstance2.m_M[2][1];
  result.m_M[2][2] = a_crInstance1.m_M[2][2] + a_crInstance2.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::sub(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] - a_crInstance2.m_M[0][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][1] - a_crInstance2.m_M[0][1];
  result.m_M[0][2] = a_crInstance1.m_M[0][2] - a_crInstance2.m_M[0][2];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] - a_crInstance2.m_M[1][0];
  result.m_M[1][1] = a_crInstance1.m_M[1][1] - a_crInstance2.m_M[1][1];
  result.m_M[1][2] = a_crInstance1.m_M[1][2] - a_crInstance2.m_M[1][2];
  result.m_M[2][0] = a_crInstance1.m_M[2][0] - a_crInstance2.m_M[2][0];
  result.m_M[2][1] = a_crInstance1.m_M[2][1] - a_crInstance2.m_M[2][1];
  result.m_M[2][2] = a_crInstance1.m_M[2][2] - a_crInstance2.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::mul(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[2][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[2][1];
  result.m_M[0][2] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[2][2];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[2][0];
  result.m_M[1][1] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[2][1];
  result.m_M[1][2] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[2][2];
  result.m_M[2][0] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][0];
  result.m_M[2][1] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][1];
  result.m_M[2][2] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::adjoint(const CMatrix3D& a_crInstance)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crInstance.m_M[1][1] * a_crInstance.m_M[2][2] - a_crInstance.m_M[1][2] * a_crInstance.m_M[2][1];
  result.m_M[0][1] = a_crInstance.m_M[0][2] * a_crInstance.m_M[2][1] - a_crInstance.m_M[0][1] * a_crInstance.m_M[2][2];
  result.m_M[0][2] = a_crInstance.m_M[0][1] * a_crInstance.m_M[1][2] - a_crInstance.m_M[0][2] * a_crInstance.m_M[1][1];
  result.m_M[1][0] = a_crInstance.m_M[1][2] * a_crInstance.m_M[2][0] - a_crInstance.m_M[1][0] * a_crInstance.m_M[2][2];
  result.m_M[1][1] = a_crInstance.m_M[0][0] * a_crInstance.m_M[2][2] - a_crInstance.m_M[0][2] * a_crInstance.m_M[2][0];
  result.m_M[1][2] = a_crInstance.m_M[0][2] * a_crInstance.m_M[1][0] - a_crInstance.m_M[0][0] * a_crInstance.m_M[1][2];
  result.m_M[2][0] = a_crInstance.m_M[1][0] * a_crInstance.m_M[2][1] - a_crInstance.m_M[1][1] * a_crInstance.m_M[2][0];
  result.m_M[2][1] = a_crInstance.m_M[0][1] * a_crInstance.m_M[2][0] - a_crInstance.m_M[0][0] * a_crInstance.m_M[2][1];
  result.m_M[2][2] = a_crInstance.m_M[0][0] * a_crInstance.m_M[1][1] - a_crInstance.m_M[0][1] * a_crInstance.m_M[1][0];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::invert(const CMatrix3D& a_crInstance)
{ CALL
  CMatrix3D result;

  // Get determinant of the matrix.
  Treal det = a_crInstance.getDeterminant();

  // Check the determinant not to be 0.
  ASSERT((!NMath::CMath::isEqualZero(det)), STR("Matrix with 0 determinant cannot be inverted."))
  {
    return result;
  }

  det = CONSTR(1.0) / det;
  result.m_M[0][0] = (a_crInstance.m_M[1][1] * a_crInstance.m_M[2][2] - a_crInstance.m_M[1][2] * a_crInstance.m_M[2][1]) * det;
  result.m_M[0][1] = (a_crInstance.m_M[0][2] * a_crInstance.m_M[2][1] - a_crInstance.m_M[0][1] * a_crInstance.m_M[2][2]) * det;
  result.m_M[0][2] = (a_crInstance.m_M[0][1] * a_crInstance.m_M[1][2] - a_crInstance.m_M[0][2] * a_crInstance.m_M[1][1]) * det;
  result.m_M[1][0] = (a_crInstance.m_M[1][2] * a_crInstance.m_M[2][0] - a_crInstance.m_M[1][0] * a_crInstance.m_M[2][2]) * det;
  result.m_M[1][1] = (a_crInstance.m_M[0][0] * a_crInstance.m_M[2][2] - a_crInstance.m_M[0][2] * a_crInstance.m_M[2][0]) * det;
  result.m_M[1][2] = (a_crInstance.m_M[0][2] * a_crInstance.m_M[1][0] - a_crInstance.m_M[0][0] * a_crInstance.m_M[1][2]) * det;
  result.m_M[2][0] = (a_crInstance.m_M[1][0] * a_crInstance.m_M[2][1] - a_crInstance.m_M[1][1] * a_crInstance.m_M[2][0]) * det;
  result.m_M[2][1] = (a_crInstance.m_M[0][1] * a_crInstance.m_M[2][0] - a_crInstance.m_M[0][0] * a_crInstance.m_M[2][1]) * det;
  result.m_M[2][2] = (a_crInstance.m_M[0][0] * a_crInstance.m_M[1][1] - a_crInstance.m_M[0][1] * a_crInstance.m_M[1][0]) * det;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::transpose(const CMatrix3D& a_crInstance)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_crInstance.m_M[1][0];
  result.m_M[0][2] = a_crInstance.m_M[2][0];
  result.m_M[1][0] = a_crInstance.m_M[0][1];
  result.m_M[1][1] = a_crInstance.m_M[1][1];
  result.m_M[1][2] = a_crInstance.m_M[2][1];
  result.m_M[2][0] = a_crInstance.m_M[0][2];
  result.m_M[2][1] = a_crInstance.m_M[1][2];
  result.m_M[2][2] = a_crInstance.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::transposeTimes(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[2][0] * a_crInstance2.m_M[2][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[2][0] * a_crInstance2.m_M[2][1];
  result.m_M[0][2] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[2][0] * a_crInstance2.m_M[2][2];
  result.m_M[1][0] = a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[2][0];
  result.m_M[1][1] = a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[2][1];
  result.m_M[1][2] = a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[2][2];
  result.m_M[2][0] = a_crInstance1.m_M[0][2] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][0];
  result.m_M[2][1] = a_crInstance1.m_M[0][2] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][1];
  result.m_M[2][2] = a_crInstance1.m_M[0][2] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::timesTranspose(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[0][2];
  result.m_M[0][1] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[1][2];
  result.m_M[0][2] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[2][2];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[0][2];
  result.m_M[1][1] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[1][2];
  result.m_M[1][2] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[2][2];
  result.m_M[2][0] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[0][2];
  result.m_M[2][1] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[1][2];
  result.m_M[2][2] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::tensorProduct(const CVector2D& a_crU, const CVector2D& a_crV)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crU.m_X * a_crV.m_X;
  result.m_M[0][1] = a_crU.m_X * a_crV.m_Y;
  result.m_M[0][2] = 0.0;
  result.m_M[1][0] = a_crU.m_Y * a_crV.m_X;
  result.m_M[1][1] = a_crU.m_Y * a_crV.m_Y;
  result.m_M[1][2] = 0.0;
  result.m_M[2][0] = 0.0;
  result.m_M[2][1] = 0.0;
  result.m_M[2][2] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::tensorProduct(const CVector3D& a_crU, const CVector3D& a_crV)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_crU.m_X * a_crV.m_X;
  result.m_M[0][1] = a_crU.m_X * a_crV.m_Y;
  result.m_M[0][2] = a_crU.m_X * a_crV.m_Z;
  result.m_M[1][0] = a_crU.m_Y * a_crV.m_X;
  result.m_M[1][1] = a_crU.m_Y * a_crV.m_Y;
  result.m_M[1][2] = a_crU.m_Y * a_crV.m_Z;
  result.m_M[2][0] = a_crU.m_Z * a_crV.m_X;
  result.m_M[2][1] = a_crU.m_Z * a_crV.m_Y;
  result.m_M[2][2] = a_crU.m_Z * a_crV.m_Z;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::translate2D(const Treal a_cTranslateX, const Treal a_cTranslateY)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = 1.0;
  result.m_M[0][1] = 0.0;
  result.m_M[0][2] = 0.0;
  result.m_M[1][0] = 0.0;
  result.m_M[1][1] = 1.0;
  result.m_M[1][2] = 0.0;
  result.m_M[2][0] = a_cTranslateX;
  result.m_M[2][1] = a_cTranslateY;
  result.m_M[2][2] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::scale2D(const Treal a_cScaleX, const Treal a_cScaleY)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_cScaleX;
  result.m_M[0][1] = 0.0;
  result.m_M[0][2] = 0.0;
  result.m_M[1][0] = 0.0;
  result.m_M[1][1] = a_cScaleY;
  result.m_M[1][2] = 0.0;
  result.m_M[2][0] = 0.0;
  result.m_M[2][1] = 0.0;
  result.m_M[2][2] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::shear2D(const Treal a_cShearXY, const Treal a_cShearYX)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = 1.0;
  result.m_M[0][1] = a_cShearXY;
  result.m_M[0][2] = 0.0;
  result.m_M[1][0] = a_cShearYX;
  result.m_M[1][1] = 1.0;
  result.m_M[1][2] = 0.0;
  result.m_M[2][0] = 0.0;
  result.m_M[2][1] = 0.0;
  result.m_M[2][2] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::rotate2D(const Treal a_cAngle)
{ CALL
  CMatrix3D result;
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);

  result.m_M[0][0] =  cos_angle;
  result.m_M[0][1] =  sin_angle;
  result.m_M[0][2] =  0.0;
  result.m_M[1][0] = -sin_angle;
  result.m_M[1][1] =  cos_angle;
  result.m_M[1][2] = 0.0;
  result.m_M[2][0] = 0.0;
  result.m_M[2][1] = 0.0;
  result.m_M[2][2] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::mirrorX2D()
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = -1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] =  1.0;
  result.m_M[1][2] =  0.0;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::mirrorY2D()
{ CALL
  CMatrix3D result;

  result.m_M[0][0] =  1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] = -1.0;
  result.m_M[1][2] =  0.0;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::scale(const Treal a_cScaleX, const Treal a_cScaleY, const Treal a_cScaleZ)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = a_cScaleX;
  result.m_M[0][1] = 0.0;
  result.m_M[0][2] = 0.0;
  result.m_M[1][0] = 0.0;
  result.m_M[1][1] = a_cScaleY;
  result.m_M[1][2] = 0.0;
  result.m_M[2][0] = 0.0;
  result.m_M[2][1] = 0.0;
  result.m_M[2][2] = a_cScaleZ;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::shear(const Treal a_cShearXY, const Treal a_cShearXZ, const Treal a_cShearYX, const Treal a_cShearYZ, const Treal a_cShearZX, const Treal a_cShearZY)
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = 1.0;
  result.m_M[0][1] = a_cShearXY;
  result.m_M[0][2] = a_cShearXZ;
  result.m_M[1][0] = a_cShearYX;
  result.m_M[1][1] = 1.0;
  result.m_M[1][2] = a_cShearYZ;
  result.m_M[2][0] = a_cShearZX;
  result.m_M[2][1] = a_cShearZY;
  result.m_M[2][2] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::rotate(const CVector3D& a_crAxis, const Treal a_cAngle)
{ CALL
  CMatrix3D result;
  CVector3D axis(a_crAxis);
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);

  axis.normalize();
  result.m_M[0][0] = axis.m_X * axis.m_X + (1 - axis.m_X * axis.m_X) * cos_angle;
  result.m_M[0][1] = axis.m_X * axis.m_Y * (1 - cos_angle) + axis.m_Z * sin_angle;
  result.m_M[0][2] = axis.m_X * axis.m_Z * (1 - cos_angle) - axis.m_Y * sin_angle;
  result.m_M[1][0] = axis.m_X * axis.m_Y * (1 - cos_angle) - axis.m_Z * sin_angle;
  result.m_M[1][1] = axis.m_Y * axis.m_Y + (1 - axis.m_Y * axis.m_Y) * cos_angle;
  result.m_M[1][2] = axis.m_Y * axis.m_Z * (1 - cos_angle) + axis.m_X * sin_angle;
  result.m_M[2][0] = axis.m_X * axis.m_Z * (1 - cos_angle) + axis.m_Y * sin_angle;
  result.m_M[2][1] = axis.m_Y * axis.m_Z * (1 - cos_angle) - axis.m_X * sin_angle;
  result.m_M[2][2] = axis.m_Z * axis.m_Z + (1 - axis.m_Z * axis.m_Z) * cos_angle;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::rotateX(const Treal a_cAngle)
{ CALL
  CMatrix3D result;
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);

  result.m_M[0][0] =  1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] =  cos_angle;
  result.m_M[1][2] =  sin_angle;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] = -sin_angle;
  result.m_M[2][2] =  cos_angle;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::rotateY(const Treal a_cAngle)
{ CALL
  CMatrix3D result;
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);

  result.m_M[0][0] =  cos_angle;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] = -sin_angle;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] =  1.0;
  result.m_M[1][2] =  0.0;
  result.m_M[2][0] =  sin_angle;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] =  cos_angle;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::rotateZ(const Treal a_cAngle)
{ CALL
  CMatrix3D result;
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);

  result.m_M[0][0] =  cos_angle;
  result.m_M[0][1] =  sin_angle;
  result.m_M[0][2] =  0.0;
  result.m_M[1][0] = -sin_angle;
  result.m_M[1][1] =  cos_angle;
  result.m_M[1][2] =  0.0;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::rotateXYZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix3D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] =  cos_angleY * cos_angleZ;
  result.m_M[0][1] =  sin_angleX * sin_angleY * cos_angleZ + cos_angleX * sin_angleZ;
  result.m_M[0][2] = -cos_angleX * sin_angleY * cos_angleZ + sin_angleX * sin_angleZ;
  result.m_M[1][0] = -cos_angleY * sin_angleZ;
  result.m_M[1][1] = -sin_angleX * sin_angleY * sin_angleZ + cos_angleX * cos_angleZ;
  result.m_M[1][2] =  cos_angleX * sin_angleY * sin_angleZ + sin_angleX * cos_angleZ;
  result.m_M[2][0] =  sin_angleY;
  result.m_M[2][1] = -sin_angleX * cos_angleY;
  result.m_M[2][2] =  cos_angleX * cos_angleY;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::rotateXZY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix3D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] =  cos_angleY * cos_angleZ;
  result.m_M[0][1] =  cos_angleX * cos_angleY * sin_angleZ + sin_angleX * sin_angleY;
  result.m_M[0][2] =  cos_angleY * sin_angleX * sin_angleZ - cos_angleX * sin_angleY;
  result.m_M[1][0] = -sin_angleZ;
  result.m_M[1][1] =  cos_angleX * cos_angleZ;
  result.m_M[1][2] =  cos_angleZ * sin_angleX;
  result.m_M[2][0] =  cos_angleZ * sin_angleY;
  result.m_M[2][1] =  cos_angleX * sin_angleY * sin_angleZ - cos_angleY * sin_angleX;
  result.m_M[2][2] =  sin_angleX * sin_angleY * sin_angleZ + cos_angleX * cos_angleY;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::rotateYXZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix3D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] =  sin_angleX * sin_angleY * sin_angleZ + cos_angleY * cos_angleZ;
  result.m_M[0][1] =  cos_angleX * sin_angleZ;
  result.m_M[0][2] =  cos_angleY * sin_angleX * sin_angleZ - cos_angleZ * sin_angleY;
  result.m_M[1][0] =  cos_angleZ * sin_angleX * sin_angleY - cos_angleY * sin_angleZ;
  result.m_M[1][1] =  cos_angleX * cos_angleZ;
  result.m_M[1][2] =  cos_angleY * cos_angleZ * sin_angleX + sin_angleY * sin_angleZ;
  result.m_M[2][0] =  cos_angleX * sin_angleY;
  result.m_M[2][1] = -sin_angleX;
  result.m_M[2][2] =  cos_angleX * cos_angleY;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::rotateYZX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix3D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] =  cos_angleY * cos_angleZ;
  result.m_M[0][1] =  sin_angleZ;
  result.m_M[0][2] = -cos_angleZ * sin_angleY;
  result.m_M[1][0] = -cos_angleX * cos_angleY * sin_angleZ + sin_angleX * sin_angleY;
  result.m_M[1][1] =  cos_angleX * cos_angleZ;
  result.m_M[1][2] =  cos_angleX * sin_angleY * sin_angleZ + cos_angleY * sin_angleX;
  result.m_M[2][0] =  cos_angleY * sin_angleX * sin_angleZ + cos_angleX * sin_angleY;
  result.m_M[2][1] = -cos_angleZ * sin_angleX;
  result.m_M[2][2] = -sin_angleX * sin_angleY * sin_angleZ + cos_angleX * cos_angleY;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::rotateZXY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix3D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] = -sin_angleX * sin_angleY * sin_angleZ + cos_angleY * cos_angleZ;
  result.m_M[0][1] =  cos_angleZ * sin_angleX * sin_angleY + cos_angleY * sin_angleZ;
  result.m_M[0][2] = -cos_angleX * sin_angleY;
  result.m_M[1][0] = -cos_angleX * sin_angleZ;
  result.m_M[1][1] =  cos_angleX * cos_angleZ;
  result.m_M[1][2] =  sin_angleX;
  result.m_M[2][0] =  cos_angleY * sin_angleX * sin_angleZ + cos_angleZ * sin_angleY;
  result.m_M[2][1] = -cos_angleY * cos_angleZ * sin_angleX + sin_angleY * sin_angleZ;
  result.m_M[2][2] =  cos_angleX * cos_angleY;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::rotateZYX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix3D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] =  cos_angleY * cos_angleZ;
  result.m_M[0][1] =  cos_angleY * sin_angleZ;
  result.m_M[0][2] = -sin_angleY;
  result.m_M[1][0] =  cos_angleZ * sin_angleX * sin_angleY - cos_angleX * sin_angleZ;
  result.m_M[1][1] =  sin_angleX * sin_angleY * sin_angleZ + cos_angleX * cos_angleZ;
  result.m_M[1][2] =  cos_angleY * sin_angleX;
  result.m_M[2][0] =  cos_angleX * cos_angleZ * sin_angleY + sin_angleX * sin_angleZ;
  result.m_M[2][1] =  cos_angleX * sin_angleY * sin_angleZ - cos_angleZ * sin_angleX;
  result.m_M[2][2] =  cos_angleX * cos_angleY;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::mirrorX()
{ CALL
  CMatrix3D result;

  result.m_M[0][0] = -1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] =  1.0;
  result.m_M[1][2] =  0.0;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::mirrorY()
{ CALL
  CMatrix3D result;

  result.m_M[0][0] =  1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] = -1.0;
  result.m_M[1][2] =  0.0;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::mirrorZ()
{ CALL
  CMatrix3D result;

  result.m_M[0][0] =  1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] =  1.0;
  result.m_M[1][2] =  0.0;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] = -1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::slerp2D(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2, const Treal a_cPart)
{ CALL
  CMatrix3D temp = transposeTimes(a_crInstance1, a_crInstance2);
  Treal angle = temp.getRotateAngle2D();

  CMatrix3D result = rotate2D(angle * a_cPart);
  result.m_M[2][0] = a_crInstance1.m_M[2][0] + a_cPart * (a_crInstance2.m_M[2][0] - a_crInstance1.m_M[2][0]);
  result.m_M[2][1] = a_crInstance1.m_M[2][1] + a_cPart * (a_crInstance2.m_M[2][1] - a_crInstance1.m_M[2][1]);
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::slerpSpins2D(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2, const Treal a_cPart, const Treal a_cSpins)
{ CALL
  CMatrix3D temp = transposeTimes(a_crInstance1, a_crInstance2);
  Treal angle = temp.getRotateAngle2D();

  CMatrix3D result = rotate2D((angle + a_cSpins * NMath::CMathConstants::PI) * a_cPart);
  result.m_M[2][0] = a_crInstance1.m_M[2][0] + a_cPart * (a_crInstance2.m_M[2][0] - a_crInstance1.m_M[2][0]);
  result.m_M[2][1] = a_crInstance1.m_M[2][1] + a_cPart * (a_crInstance2.m_M[2][1] - a_crInstance1.m_M[2][1]);
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::slerp(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2, const Treal a_cPart)
{ CALL
  CMatrix3D temp = transposeTimes(a_crInstance1, a_crInstance2);
  CVector3D axis;
  Treal angle;
  temp.getRotateAxisAngle(axis, angle);

  return rotate(axis, angle * a_cPart);
}
/*--------------------------------------------------------------------------*/
CMatrix3D CMatrix3D::slerpSpins(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2, const Treal a_cPart, const Treal a_cSpins)
{ CALL
  CMatrix3D temp = transposeTimes(a_crInstance1, a_crInstance2);
  CVector3D axis;
  Treal angle;
  temp.getRotateAxisAngle(axis, angle);

  return rotate(axis, (angle + a_cSpins * NMath::CMathConstants::PI) * a_cPart);
}
/*--------------------------------------------------------------------------*/
void CMatrix3D::swap(CMatrix3D& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_M[0][0], a_rInstance.m_M[0][0]);
  NAlgorithms::NCommon::swap(m_M[0][1], a_rInstance.m_M[0][1]);
  NAlgorithms::NCommon::swap(m_M[0][2], a_rInstance.m_M[0][2]);
  NAlgorithms::NCommon::swap(m_M[1][0], a_rInstance.m_M[1][0]);
  NAlgorithms::NCommon::swap(m_M[1][1], a_rInstance.m_M[1][1]);
  NAlgorithms::NCommon::swap(m_M[1][2], a_rInstance.m_M[1][2]);
  NAlgorithms::NCommon::swap(m_M[2][0], a_rInstance.m_M[2][0]);
  NAlgorithms::NCommon::swap(m_M[2][1], a_rInstance.m_M[2][1]);
  NAlgorithms::NCommon::swap(m_M[2][2], a_rInstance.m_M[2][2]);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
