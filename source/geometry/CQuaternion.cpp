/*!
 *  \file    CQuaternion.cpp Representation of the quaternion - hyper-complex
 *           number which extends conception of the rotation in a space.
 *  \brief   Quaternion class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Quaternion class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   07.07.2008 23:28:25

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
#include <Depth/include/geometry/CQuaternion.hpp>
/*==========================================================================*/
#ifndef __CQUATERNION_CPP__
#define __CQUATERNION_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
GEOMETRY_API const CQuaternion CQuaternion::IDENTITY(0.0, 0.0, 0.0, 1.0);
GEOMETRY_API const CQuaternion CQuaternion::ZERO(0.0, 0.0, 0.0, 0.0);
GEOMETRY_API const CQuaternion CQuaternion::UNIT_X(1.0, 0.0, 0.0, 0.0);
GEOMETRY_API const CQuaternion CQuaternion::UNIT_Y(0.0, 1.0, 0.0, 0.0);
GEOMETRY_API const CQuaternion CQuaternion::UNIT_Z(0.0, 0.0, 1.0, 0.0);
GEOMETRY_API const CQuaternion CQuaternion::UNIT_W(0.0, 0.0, 0.0, 1.0);
/*--------------------------------------------------------------------------*/
void CQuaternion::set(const Treal a_cpValuesBuffer[])
{ CALL
  // Check if the pointer to the quaternion values buffer is not NULL.
  ASSERT((a_cpValuesBuffer != NULL), STR("Pointer to the coordinates buffer should not be NULL."))
  {
    clear();
  }

  m_X = a_cpValuesBuffer[0];
  m_Y = a_cpValuesBuffer[1];
  m_Z = a_cpValuesBuffer[2];
  m_W = a_cpValuesBuffer[3];
}
/*--------------------------------------------------------------------------*/
void CQuaternion::setSpherical(const Treal a_cLatitude, const Treal a_cLongitude, const Treal a_cAngle)
{ CALL
  Treal sin_angle = NMath::CMath::sin(a_cAngle * CONSTR(0.5));
  Treal cos_angle = NMath::CMath::cos(a_cAngle * CONSTR(0.5));
  Treal sin_latitude = NMath::CMath::sin(a_cLatitude);
  Treal cos_latitude = NMath::CMath::cos(a_cLatitude);
  Treal sin_longitude = NMath::CMath::sin(a_cLongitude);
  Treal cos_longitude = NMath::CMath::cos(a_cLongitude);

  m_X = cos_latitude * sin_longitude * sin_angle;
  m_Y = sin_latitude * sin_angle;
  m_Z = cos_latitude * cos_longitude * sin_angle;
  m_W = cos_angle;
}
/*--------------------------------------------------------------------------*/
void CQuaternion::getSpherical(Treal& a_rLatitude, Treal& a_rLongitude, Treal& a_rAngle) const
{ CALL
  Treal sin_angle;
  Treal cos_angle;
  Treal angle, temp;

  cos_angle = m_W;
  angle = NMath::CMath::acos(cos_angle);
  sin_angle = NMath::CMath::sin(angle);

  temp = m_Y;
  if (!NMath::CMath::isEqualZero(sin_angle))
    temp /= sin_angle;
  a_rLatitude = NMath::CMath::asin(temp);
  a_rLongitude = NMath::CMath::atan(m_X / m_Z);
  a_rAngle = CONSTR(2.0) * angle;
}
/*--------------------------------------------------------------------------*/
void CQuaternion::setRotateAnglesXYZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  Treal sin_pitch = NMath::CMath::sin(a_cAngleX * CONSTR(0.5));
  Treal cos_pitch = NMath::CMath::cos(a_cAngleX * CONSTR(0.5));
  Treal sin_yaw = NMath::CMath::sin(a_cAngleY * CONSTR(0.5));
  Treal cos_yaw = NMath::CMath::cos(a_cAngleY * CONSTR(0.5));
  Treal sin_roll = NMath::CMath::sin(a_cAngleZ * CONSTR(0.5));
  Treal cos_roll = NMath::CMath::cos(a_cAngleZ * CONSTR(0.5));
  Treal cpcy = cos_pitch * cos_yaw;
  Treal cpsy = cos_pitch * sin_yaw;
  Treal spsy = sin_pitch * sin_yaw;
  Treal spcy = sin_pitch * cos_yaw;

  m_X = cos_roll * spcy + sin_roll * cpsy;
  m_Y = cos_roll * cpsy - sin_roll * spcy;
  m_Z = sin_roll * cpcy - cos_roll * spsy;
  m_W = cos_roll * cpcy + sin_roll * spsy;
}
/*--------------------------------------------------------------------------*/
void CQuaternion::getRotateAnglesXYZ(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  Treal X2, Y2, Z2, WX, WY, WZ, XX, XY, XZ, YY, YZ, ZZ;
  Treal sin_y, cos_y;

  X2 = m_X + m_X;
  Y2 = m_Y + m_Y;
  Z2 = m_Z + m_Z;
  WX = m_W * X2; WY = m_W * Y2; WZ = m_W * Z2;
  XX = m_X * X2; XY = m_X * Y2; XZ = m_X * Z2;
  YY = m_Y * Y2; YZ = m_Y * Z2; ZZ = m_Z * Z2;

  sin_y = XZ + WY;
  cos_y = NMath::CMath::sqrt(CONSTR(1.0) - sin_y * sin_y);
  if (((1.0 - YY - ZZ) < 0.0) && ((1.0 - XX - YY) < 0.0))
    cos_y = -cos_y;
  if (NMath::CMath::isEqualZero(cos_y))
  {
    a_rAngleX = 0.0;
    a_rAngleY = NMath::CMath::asin(sin_y);
    a_rAngleZ = NMath::CMath::atan2(XY - WY, CONSTR(1.0) - XX - ZZ);
  }
  else
  {
    a_rAngleX = NMath::CMath::atan2((WX - YZ) / cos_y, (CONSTR(1.0) - XX - YY) / cos_y);
    a_rAngleY = NMath::CMath::atan2(sin_y, cos_y);
    a_rAngleZ = NMath::CMath::atan2((WZ - XY) / cos_y, (CONSTR(1.0) - YY - ZZ) / cos_y);
  }
}
/*--------------------------------------------------------------------------*/
void CQuaternion::setRotateAxisAngle(const CVector3D& a_crAxis, const Treal a_cAngle)
{ CALL
  // The quaternion representing the rotation is
  // q = cos(A / 2) + sin(A / 2) * (x * i + y * j + z * k)
  Treal sin_angle = NMath::CMath::sin(a_cAngle * CONSTR(0.5));
  Treal cos_angle = NMath::CMath::cos(a_cAngle * CONSTR(0.5));
  Treal len = a_crAxis.length();

  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;

  m_X = a_crAxis.m_X * len * sin_angle;
  m_Y = a_crAxis.m_Y * len * sin_angle;
  m_Z = a_crAxis.m_Z * len * sin_angle;
  m_W = cos_angle;
}
/*--------------------------------------------------------------------------*/
void CQuaternion::getRotateAxisAngle(CVector3D& a_rAxis, Treal& a_rAngle) const
{ CALL
  // The quaternion representing the rotation is
  // q = cos(A / 2) + sin(A / 2) * (x * i + y * j + z * k)
  Treal len = m_X * m_X + m_Y * m_Y + m_Z * m_Z;
  if (len > 0.0)
  {
    len = CONSTR(1.0) / NMath::CMath::sqrt(len);
    a_rAxis.m_X = m_X * len;
    a_rAxis.m_Y = m_Y * len;
    a_rAxis.m_Z = m_Z * len;
    a_rAngle = CONSTR(2.0) * NMath::CMath::acos(m_W);
  }
  else
  {
    // Angle is 0 (mod 2*pi), so any axis will suit.
    a_rAxis.m_X = 1.0;
    a_rAxis.m_Y = 0.0;
    a_rAxis.m_Z = 0.0;
    a_rAngle = 0.0;
  }
}
/*--------------------------------------------------------------------------*/
void CQuaternion::setMatrix(const CMatrix3D& a_crMatrix3D)
{ CALL
  // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
  // article "Quaternion Calculus and Fast Animation".
  const Tsint next[3] = {1,2,0};
  Tsint i, j, k;
  Treal temp[4];
  Treal Tr, S;

  Tr = a_crMatrix3D.m_M[0][0] + a_crMatrix3D.m_M[1][1] + a_crMatrix3D.m_M[2][2];
  if (Tr > 0.0)
  {
    S = NMath::CMath::sqrt(Tr + CONSTR(1.0));
    m_W = CONSTR(0.5) * S;
    S = CONSTR(0.5) / S;
    m_X = (a_crMatrix3D.m_M[1][2] - a_crMatrix3D.m_M[2][1]) * S;
    m_Y = (a_crMatrix3D.m_M[2][0] - a_crMatrix3D.m_M[0][2]) * S;
    m_Z = (a_crMatrix3D.m_M[0][1] - a_crMatrix3D.m_M[1][0]) * S;
  }
  else
  {
    i=0;
    if (a_crMatrix3D.m_M[1][1] > a_crMatrix3D.m_M[0][0])
     i=1;
    if (a_crMatrix3D.m_M[2][2] > a_crMatrix3D.m_M[i][i])
     i=2;
    j = next[i];
    k = next[j];
    S = NMath::CMath::sqrt((a_crMatrix3D.m_M[i][i] - (a_crMatrix3D.m_M[j][j] + a_crMatrix3D.m_M[k][k])) + CONSTR(1.0));
    temp[i] = CONSTR(0.5) * S;
    if (!NMath::CMath::isEqualZero(S))
      S = CONSTR(0.5) / S;
    temp[3] = (a_crMatrix3D.m_M[j][k] - a_crMatrix3D.m_M[k][j]) * S;
    temp[j] = (a_crMatrix3D.m_M[i][j] + a_crMatrix3D.m_M[j][i]) * S;
    temp[k] = (a_crMatrix3D.m_M[i][k] + a_crMatrix3D.m_M[k][i]) * S;
    m_X = temp[0];
    m_Y = temp[1];
    m_Z = temp[2];
    m_W = temp[3];
  }
}
/*--------------------------------------------------------------------------*/
void CQuaternion::setMatrix(const CMatrix4D& a_crMatrix4D)
{ CALL
  // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
  // article "Quaternion Calculus and Fast Animation".
  const Tsint next[3] = {1,2,0};
  Tsint i, j, k;
  Treal temp[4];
  Treal Tr, S;

  Tr = a_crMatrix4D.m_M[0][0] + a_crMatrix4D.m_M[1][1] + a_crMatrix4D.m_M[2][2];
  if (Tr > 0.0)
  {
    S = NMath::CMath::sqrt(Tr + CONSTR(1.0));
    m_W = CONSTR(0.5) * S;
    S = CONSTR(0.5) / S;
    m_X = (a_crMatrix4D.m_M[1][2] - a_crMatrix4D.m_M[2][1]) * S;
    m_Y = (a_crMatrix4D.m_M[2][0] - a_crMatrix4D.m_M[0][2]) * S;
    m_Z = (a_crMatrix4D.m_M[0][1] - a_crMatrix4D.m_M[1][0]) * S;
  }
  else
  {
    i=0;
    if (a_crMatrix4D.m_M[1][1] > a_crMatrix4D.m_M[0][0])
     i=1;
    if (a_crMatrix4D.m_M[2][2] > a_crMatrix4D.m_M[i][i])
     i=2;
    j = next[i];
    k = next[j];
    S = NMath::CMath::sqrt((a_crMatrix4D.m_M[i][i] - (a_crMatrix4D.m_M[j][j] + a_crMatrix4D.m_M[k][k])) + CONSTR(1.0));
    temp[i] = CONSTR(0.5) * S;
    if (!NMath::CMath::isEqualZero(S))
      S = CONSTR(0.5) / S;
    temp[3] = (a_crMatrix4D.m_M[j][k] - a_crMatrix4D.m_M[k][j]) * S;
    temp[j] = (a_crMatrix4D.m_M[i][j] + a_crMatrix4D.m_M[j][i]) * S;
    temp[k] = (a_crMatrix4D.m_M[i][k] + a_crMatrix4D.m_M[k][i]) * S;
    m_X = temp[0];
    m_Y = temp[1];
    m_Z = temp[2];
    m_W = temp[3];
  }
}
/*--------------------------------------------------------------------------*/
void CQuaternion::getMatrix3D(CMatrix3D& a_rMatrix3D) const
{ CALL
  Treal X2, Y2, Z2, WX, WY, WZ, XX, XY, XZ, YY, YZ, ZZ;

  X2 = m_X + m_X;
  Y2 = m_Y + m_Y;
  Z2 = m_Z + m_Z;
  WX = m_W * X2; WY = m_W * Y2; WZ = m_W * Z2;
  XX = m_X * X2; XY = m_X * Y2; XZ = m_X * Z2;
  YY = m_Y * Y2; YZ = m_Y * Z2; ZZ = m_Z * Z2;

  a_rMatrix3D.m_M[0][0] = CONSTR(1.0) - (YY + ZZ);
  a_rMatrix3D.m_M[0][1] = XY + WZ;
  a_rMatrix3D.m_M[0][2] = XZ - WY;
  a_rMatrix3D.m_M[1][0] = XY - WZ;
  a_rMatrix3D.m_M[1][1] = CONSTR(1.0) - (XX + ZZ);
  a_rMatrix3D.m_M[1][2] = YZ + WX;
  a_rMatrix3D.m_M[2][0] = XZ + WY;
  a_rMatrix3D.m_M[2][1] = YZ - WX;
  a_rMatrix3D.m_M[2][2] = CONSTR(1.0) - (XX + YY);
}
/*--------------------------------------------------------------------------*/
void CQuaternion::getMatrix4D(CMatrix4D& a_rMatrix4D) const
{ CALL
  Treal X2, Y2, Z2, WX, WY, WZ, XX, XY, XZ, YY, YZ, ZZ;

  X2 = m_X + m_X;
  Y2 = m_Y + m_Y;
  Z2 = m_Z + m_Z;
  WX = m_W * X2; WY = m_W * Y2; WZ = m_W * Z2;
  XX = m_X * X2; XY = m_X * Y2; XZ = m_X * Z2;
  YY = m_Y * Y2; YZ = m_Y * Z2; ZZ = m_Z * Z2;

  a_rMatrix4D.m_M[0][0] = CONSTR(1.0) - (YY + ZZ);
  a_rMatrix4D.m_M[0][1] = XY + WZ;
  a_rMatrix4D.m_M[0][2] = XZ - WY;
  a_rMatrix4D.m_M[0][3] = 0.0;
  a_rMatrix4D.m_M[1][0] = XY - WZ;
  a_rMatrix4D.m_M[1][1] = CONSTR(1.0) - (XX + ZZ);
  a_rMatrix4D.m_M[1][2] = YZ + WX;
  a_rMatrix4D.m_M[1][3] = 0.0;
  a_rMatrix4D.m_M[2][0] = XZ + WY;
  a_rMatrix4D.m_M[2][1] = YZ - WX;
  a_rMatrix4D.m_M[2][2] = CONSTR(1.0) - (XX + YY);
  a_rMatrix4D.m_M[2][3] = 0.0;
  a_rMatrix4D.m_M[3][0] = 0.0;
  a_rMatrix4D.m_M[3][1] = 0.0;
  a_rMatrix4D.m_M[3][2] = 0.0;
  a_rMatrix4D.m_M[3][3] = 1.0;
}
/*--------------------------------------------------------------------------*/
void CQuaternion::clear(const Tbool a_cIdentityFlag/* = false */)
{ CALL
  m_X = 0.0;
  m_Y = 0.0;
  m_Z = 0.0;
  m_W = (a_cIdentityFlag ? CONSTR(1.0) : CONSTR(0.0));
}
/*--------------------------------------------------------------------------*/
void CQuaternion::normalize()
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
Treal CQuaternion::normalizeLength()
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
CPoint3D<Treal> CQuaternion::rotate(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  CPoint3D<Treal> result;
  CQuaternion temp;
  Treal E = (m_X + m_Z) * (a_crPoint3D.m_X + a_crPoint3D.m_Y);
  Treal F = (m_X - m_Z) * (a_crPoint3D.m_X - a_crPoint3D.m_Y);
  Treal G = (m_W + m_Y) * (                - a_crPoint3D.m_Z);
  Treal H = (m_W - m_Y) * (a_crPoint3D.m_Z                  );

  temp.m_X = (m_W + m_X) * (a_crPoint3D.m_X                  ) - (E + F + G + H) * CONSTR(0.5);
  temp.m_Y = (m_W - m_X) * (a_crPoint3D.m_Y + a_crPoint3D.m_Z) + (E - F + G - H) * CONSTR(0.5);
  temp.m_Z = (m_Y + m_Z) * (                - a_crPoint3D.m_X) + (E - F - G + H) * CONSTR(0.5);
  temp.m_W = (m_Z - m_Y) * (a_crPoint3D.m_Y - a_crPoint3D.m_Z) - (E + F - G - H) * CONSTR(0.5);
  E = (temp.m_X + temp.m_Z) * (-m_X - m_Y);
  F = (temp.m_X - temp.m_Z) * (-m_X + m_Y);
  G = (temp.m_W + temp.m_Y) * ( m_W + m_Z);
  H = (temp.m_W - temp.m_Y) * ( m_W - m_Z);
  result.m_X = (temp.m_W + temp.m_X) * ( m_W - m_X) - (E + F + G + H) * CONSTR(0.5);
  result.m_Y = (temp.m_W - temp.m_X) * (-m_Y - m_Z) + (E - F + G - H) * CONSTR(0.5);
  result.m_Z = (temp.m_Y + temp.m_Z) * ( m_W + m_X) + (E - F - G + H) * CONSTR(0.5);
  return result;
}
/*--------------------------------------------------------------------------*/
CVector3D CQuaternion::rotate(const CVector3D& a_crVector3D) const
{ CALL
  CVector3D result;
  CQuaternion temp;
  Treal E = (m_X + m_Z) * (a_crVector3D.m_X + a_crVector3D.m_Y);
  Treal F = (m_X - m_Z) * (a_crVector3D.m_X - a_crVector3D.m_Y);
  Treal G = (m_W + m_Y) * (                 - a_crVector3D.m_Z);
  Treal H = (m_W - m_Y) * (a_crVector3D.m_Z                  );

  temp.m_X = (m_W + m_X) * (a_crVector3D.m_X                   ) - (E + F + G + H) * CONSTR(0.5);
  temp.m_Y = (m_W - m_X) * (a_crVector3D.m_Y + a_crVector3D.m_Z) + (E - F + G - H) * CONSTR(0.5);
  temp.m_Z = (m_Y + m_Z) * (                 - a_crVector3D.m_X) + (E - F - G + H) * CONSTR(0.5);
  temp.m_W = (m_Z - m_Y) * (a_crVector3D.m_Y - a_crVector3D.m_Z) - (E + F - G - H) * CONSTR(0.5);
  E = (temp.m_X + temp.m_Z) * (-m_X - m_Y);
  F = (temp.m_X - temp.m_Z) * (-m_X + m_Y);
  G = (temp.m_W + temp.m_Y) * ( m_W + m_Z);
  H = (temp.m_W - temp.m_Y) * ( m_W - m_Z);
  result.m_X = (temp.m_W + temp.m_X) * ( m_W - m_X) - (E + F + G + H) * CONSTR(0.5);
  result.m_Y = (temp.m_W - temp.m_X) * (-m_Y - m_Z) + (E - F + G - H) * CONSTR(0.5);
  result.m_Z = (temp.m_Y + temp.m_Z) * ( m_W + m_X) + (E - F - G + H) * CONSTR(0.5);
  return result;
}
/*--------------------------------------------------------------------------*/
CVector4D CQuaternion::rotate(const CVector4D& a_crVector4D) const
{ CALL
  CVector4D result;
  CQuaternion temp;
  Treal E = (m_X + m_Z) * (a_crVector4D.m_X + a_crVector4D.m_Y);
  Treal F = (m_X - m_Z) * (a_crVector4D.m_X - a_crVector4D.m_Y);
  Treal G = (m_W + m_Y) * (a_crVector4D.m_W - a_crVector4D.m_Z);
  Treal H = (m_W - m_Y) * (a_crVector4D.m_W + a_crVector4D.m_Z);

  temp.m_X = (m_W + m_X) * (a_crVector4D.m_W + a_crVector4D.m_X) - (E + F + G + H) * CONSTR(0.5);
  temp.m_Y = (m_W - m_X) * (a_crVector4D.m_Y + a_crVector4D.m_Z) + (E - F + G - H) * CONSTR(0.5);
  temp.m_Z = (m_Y + m_Z) * (a_crVector4D.m_W - a_crVector4D.m_X) + (E - F - G + H) * CONSTR(0.5);
  temp.m_W = (m_Z - m_Y) * (a_crVector4D.m_Y - a_crVector4D.m_Z) - (E + F - G - H) * CONSTR(0.5);
  E = (temp.m_X + temp.m_Z) * (-m_X - m_Y);
  F = (temp.m_X - temp.m_Z) * (-m_X + m_Y);
  G = (temp.m_W + temp.m_Y) * ( m_W + m_Z);
  H = (temp.m_W - temp.m_Y) * ( m_W - m_Z);
  result.m_X = (temp.m_W + temp.m_X) * ( m_W - m_X) - (E + F + G + H) * CONSTR(0.5);
  result.m_Y = (temp.m_W - temp.m_X) * (-m_Y - m_Z) + (E - F + G - H) * CONSTR(0.5);
  result.m_Z = (temp.m_Y + temp.m_Z) * ( m_W + m_X) + (E - F - G + H) * CONSTR(0.5);
  result.m_W = (temp.m_Z - temp.m_Y) * (-m_Y + m_Z) - (E + F - G - H) * CONSTR(0.5);
  return result;
}
/*--------------------------------------------------------------------------*/
void CQuaternion::rotate(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  CQuaternion temp;
  Treal E = (m_X + m_Z) * (a_crPoint3D.m_X + a_crPoint3D.m_Y);
  Treal F = (m_X - m_Z) * (a_crPoint3D.m_X - a_crPoint3D.m_Y);
  Treal G = (m_W + m_Y) * (                - a_crPoint3D.m_Z);
  Treal H = (m_W - m_Y) * (a_crPoint3D.m_Z                  );

  temp.m_X = (m_W + m_X) * (a_crPoint3D.m_X                  ) - (E + F + G + H) * CONSTR(0.5);
  temp.m_Y = (m_W - m_X) * (a_crPoint3D.m_Y + a_crPoint3D.m_Z) + (E - F + G - H) * CONSTR(0.5);
  temp.m_Z = (m_Y + m_Z) * (                - a_crPoint3D.m_X) + (E - F - G + H) * CONSTR(0.5);
  temp.m_W = (m_Z - m_Y) * (a_crPoint3D.m_Y - a_crPoint3D.m_Z) - (E + F - G - H) * CONSTR(0.5);
  E = (temp.m_X + temp.m_Z) * (-m_X - m_Y);
  F = (temp.m_X - temp.m_Z) * (-m_X + m_Y);
  G = (temp.m_W + temp.m_Y) * ( m_W + m_Z);
  H = (temp.m_W - temp.m_Y) * ( m_W - m_Z);
  a_rResult.m_X = (temp.m_W + temp.m_X) * ( m_W - m_X) - (E + F + G + H) * CONSTR(0.5);
  a_rResult.m_Y = (temp.m_W - temp.m_X) * (-m_Y - m_Z) + (E - F + G - H) * CONSTR(0.5);
  a_rResult.m_Z = (temp.m_Y + temp.m_Z) * ( m_W + m_X) + (E - F - G + H) * CONSTR(0.5);
}
/*--------------------------------------------------------------------------*/
void CQuaternion::rotate(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  CQuaternion temp;
  Treal E = (m_X + m_Z) * (a_crVector3D.m_X + a_crVector3D.m_Y);
  Treal F = (m_X - m_Z) * (a_crVector3D.m_X - a_crVector3D.m_Y);
  Treal G = (m_W + m_Y) * (                 - a_crVector3D.m_Z);
  Treal H = (m_W - m_Y) * (a_crVector3D.m_Z                  );

  temp.m_X = (m_W + m_X) * (a_crVector3D.m_X                   ) - (E + F + G + H) * CONSTR(0.5);
  temp.m_Y = (m_W - m_X) * (a_crVector3D.m_Y + a_crVector3D.m_Z) + (E - F + G - H) * CONSTR(0.5);
  temp.m_Z = (m_Y + m_Z) * (                 - a_crVector3D.m_X) + (E - F - G + H) * CONSTR(0.5);
  temp.m_W = (m_Z - m_Y) * (a_crVector3D.m_Y - a_crVector3D.m_Z) - (E + F - G - H) * CONSTR(0.5);
  E = (temp.m_X + temp.m_Z) * (-m_X - m_Y);
  F = (temp.m_X - temp.m_Z) * (-m_X + m_Y);
  G = (temp.m_W + temp.m_Y) * ( m_W + m_Z);
  H = (temp.m_W - temp.m_Y) * ( m_W - m_Z);
  a_rResult.m_X = (temp.m_W + temp.m_X) * ( m_W - m_X) - (E + F + G + H) * CONSTR(0.5);
  a_rResult.m_Y = (temp.m_W - temp.m_X) * (-m_Y - m_Z) + (E - F + G - H) * CONSTR(0.5);
  a_rResult.m_Z = (temp.m_Y + temp.m_Z) * ( m_W + m_X) + (E - F - G + H) * CONSTR(0.5);
}
/*--------------------------------------------------------------------------*/
void CQuaternion::rotate(const CVector4D& a_crVector4D, CVector4D& a_rResult) const
{ CALL
  CQuaternion temp;
  Treal E = (m_X + m_Z) * (a_crVector4D.m_X + a_crVector4D.m_Y);
  Treal F = (m_X - m_Z) * (a_crVector4D.m_X - a_crVector4D.m_Y);
  Treal G = (m_W + m_Y) * (a_crVector4D.m_W - a_crVector4D.m_Z);
  Treal H = (m_W - m_Y) * (a_crVector4D.m_W + a_crVector4D.m_Z);

  temp.m_X = (m_W + m_X) * (a_crVector4D.m_W + a_crVector4D.m_X) - (E + F + G + H) * CONSTR(0.5);
  temp.m_Y = (m_W - m_X) * (a_crVector4D.m_Y + a_crVector4D.m_Z) + (E - F + G - H) * CONSTR(0.5);
  temp.m_Z = (m_Y + m_Z) * (a_crVector4D.m_W - a_crVector4D.m_X) + (E - F - G + H) * CONSTR(0.5);
  temp.m_W = (m_Z - m_Y) * (a_crVector4D.m_Y - a_crVector4D.m_Z) - (E + F - G - H) * CONSTR(0.5);
  E = (temp.m_X + temp.m_Z) * (-m_X - m_Y);
  F = (temp.m_X - temp.m_Z) * (-m_X + m_Y);
  G = (temp.m_W + temp.m_Y) * ( m_W + m_Z);
  H = (temp.m_W - temp.m_Y) * ( m_W - m_Z);
  a_rResult.m_X = (temp.m_W + temp.m_X) * ( m_W - m_X) - (E + F + G + H) * CONSTR(0.5);
  a_rResult.m_Y = (temp.m_W - temp.m_X) * (-m_Y - m_Z) + (E - F + G - H) * CONSTR(0.5);
  a_rResult.m_Z = (temp.m_Y + temp.m_Z) * ( m_W + m_X) + (E - F - G + H) * CONSTR(0.5);
  a_rResult.m_W = (temp.m_Z - temp.m_Y) * (-m_Y + m_Z) - (E + F - G - H) * CONSTR(0.5);
}
/*--------------------------------------------------------------------------*/
CQuaternion CQuaternion::conjugate(const CQuaternion& a_crInstance)
{ CALL
  CQuaternion result;

  result.m_X = -a_crInstance.m_X;
  result.m_Y = -a_crInstance.m_Y;
  result.m_Z = -a_crInstance.m_Z;
  result.m_W =  a_crInstance.m_W;
  return result;
}
/*--------------------------------------------------------------------------*/
CQuaternion CQuaternion::inverse(const CQuaternion& a_crInstance)
{ CALL
  CQuaternion result(a_crInstance);

  result.normalize();
  result.m_X = -result.m_X;
  result.m_Y = -result.m_Y;
  result.m_Z = -result.m_Z;
  return result;
}
/*--------------------------------------------------------------------------*/
CQuaternion CQuaternion::squared(const CQuaternion& a_crInstance)
{ CALL
  CQuaternion result;
  Treal scale = CONSTR(2.0) * a_crInstance.m_W;

  result.m_X = a_crInstance.m_X * scale;
  result.m_Y = a_crInstance.m_Y * scale;
  result.m_Z = a_crInstance.m_Z * scale;
  result.m_W = a_crInstance.m_W * a_crInstance.m_W - a_crInstance.m_X * a_crInstance.m_X - a_crInstance.m_Y * a_crInstance.m_Y - a_crInstance.m_Z * a_crInstance.m_Z;
  return result;
}
/*--------------------------------------------------------------------------*/
CQuaternion CQuaternion::exponent(const CQuaternion& a_crInstance)
{ CALL
  // If q = A * (x * i + y * j + z * k) where (x, y, z) is unit length, then
  // exp(q) = cos(A) + sin(A) * (x * i + y * j + z * k). If sin(A) is near
  // zero, use exp(q) = cos(A) + A * (x * i + y * j + z * k) since A / sin(A)
  // has limit 1.
  CQuaternion result;
  Treal len = NMath::CMath::sqrt(a_crInstance.m_X * a_crInstance.m_X + a_crInstance.m_Y * a_crInstance.m_Y + a_crInstance.m_Z * a_crInstance.m_Z);

  result.m_W = NMath::CMath::cos(len);
  if (len > 0.0)
    len = NMath::CMath::sin(len) / len;
  else
    len = 1.0;
  result.m_X = a_crInstance.m_X * len;
  result.m_Y = a_crInstance.m_Y * len;
  result.m_Z = a_crInstance.m_Z * len;
  return result;
}
/*--------------------------------------------------------------------------*/
CQuaternion CQuaternion::logarithmic(const CQuaternion& a_crInstance)
{ CALL
  // If q = cos(A) + sin(A) * (x * i + y * j + z * k) where (x, y, z) is unit
  // length, then log(q) = A * (x * i + y * j + z * k). If sin(A) is near
  // zero, use log(q) = sin(A) * (x * i + y * j + z * k) since sin(A) / A
  // has limit 1.
  CQuaternion result;
  Treal angle, sin_angle;

  result.m_W = 0.0;
  if (NMath::CMath::fabs(a_crInstance.m_W) < 1.0)
  {
    angle = NMath::CMath::acos(a_crInstance.m_W);
    sin_angle = NMath::CMath::sin(angle);
    if (!NMath::CMath::isEqualZero(sin_angle))
    {
      Treal k = angle / sin_angle;
      result.m_X = a_crInstance.m_X * k;
      result.m_Y = a_crInstance.m_Y * k;
      result.m_Z = a_crInstance.m_Z * k;
      return result;
    }
  }
  result.m_X = a_crInstance.m_X;
  result.m_Y = a_crInstance.m_Y;
  result.m_Z = a_crInstance.m_Z;
  return result;
}
/*--------------------------------------------------------------------------*/
CQuaternion CQuaternion::mul(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  CQuaternion result;
  Treal E = (a_crInstance1.m_X + a_crInstance1.m_Z) * (a_crInstance2.m_X + a_crInstance2.m_Y);
  Treal F = (a_crInstance1.m_X - a_crInstance1.m_Z) * (a_crInstance2.m_X - a_crInstance2.m_Y);
  Treal G = (a_crInstance1.m_W + a_crInstance1.m_Y) * (a_crInstance2.m_W - a_crInstance2.m_Z);
  Treal H = (a_crInstance1.m_W - a_crInstance1.m_Y) * (a_crInstance2.m_W + a_crInstance2.m_Z);

  result.m_X = (a_crInstance1.m_W + a_crInstance1.m_X) * (a_crInstance2.m_W + a_crInstance2.m_X) - (E + F + G + H) * CONSTR(0.5);
  result.m_Y = (a_crInstance1.m_W - a_crInstance1.m_X) * (a_crInstance2.m_Y + a_crInstance2.m_Z) + (E - F + G - H) * CONSTR(0.5);
  result.m_Z = (a_crInstance1.m_Y + a_crInstance1.m_Z) * (a_crInstance2.m_W - a_crInstance2.m_X) + (E - F - G + H) * CONSTR(0.5);
  result.m_W = (a_crInstance1.m_Z - a_crInstance1.m_Y) * (a_crInstance2.m_Y - a_crInstance2.m_Z) - (E + F - G - H) * CONSTR(0.5);
  return result;
}
/*--------------------------------------------------------------------------*/
CQuaternion CQuaternion::div(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  CQuaternion result;
  Treal E = (a_crInstance1.m_X + a_crInstance1.m_Z) * (a_crInstance2.m_X + a_crInstance2.m_Y);
  Treal F = (a_crInstance1.m_X - a_crInstance1.m_Z) * (a_crInstance2.m_X - a_crInstance2.m_Y);
  Treal G = (a_crInstance1.m_W + a_crInstance1.m_Y) * (a_crInstance2.m_W + a_crInstance2.m_Z);
  Treal H = (a_crInstance1.m_W - a_crInstance1.m_Y) * (a_crInstance2.m_W - a_crInstance2.m_Z);

  result.m_X = (a_crInstance1.m_W + a_crInstance1.m_X) * (a_crInstance2.m_W - a_crInstance2.m_X) + (E + F - G - H) * CONSTR(0.5);
  result.m_Y = (a_crInstance1.m_X - a_crInstance1.m_W) * (a_crInstance2.m_Y + a_crInstance2.m_Z) - (E - F - G + H) * CONSTR(0.5);
  result.m_Z = (a_crInstance1.m_Y + a_crInstance1.m_Z) * (a_crInstance2.m_W + a_crInstance2.m_X) - (E - F + G - H) * CONSTR(0.5);
  result.m_W = (a_crInstance1.m_Y - a_crInstance1.m_Z) * (a_crInstance2.m_Y - a_crInstance2.m_Z) + (E + F + G + H) * CONSTR(0.5);
  return result;
}
/*--------------------------------------------------------------------------*/
CQuaternion CQuaternion::slerp(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2, const Treal a_cPart)
{ CALL
  CQuaternion result;
  Treal A, B;
  Treal angle;
  Treal sin_angle, cos_angle;
  Treal flip;

  cos_angle = dot(a_crInstance1, a_crInstance2);
  if (cos_angle < 0.0)
  {
    cos_angle = -cos_angle;
    flip = -1.0;
  }
  else
    flip = 1.0;

  if ((1.0 - cos_angle) < NMath::CMath::getEpsilon())
  {
    A = CONSTR(1.0) - a_cPart;
    B = a_cPart;
  }
  else
  {
    angle = NMath::CMath::acos(cos_angle);
    sin_angle = CONSTR(1.0) / NMath::CMath::sin(angle);
    A = NMath::CMath::sin((CONSTR(1.0) - a_cPart) * angle) * sin_angle;
    B = NMath::CMath::sin(a_cPart * angle) * sin_angle;
  }
  B *= flip;
  result.m_X = A * a_crInstance1.m_X + B * a_crInstance2.m_X;
  result.m_Y = A * a_crInstance1.m_Y + B * a_crInstance2.m_Y;
  result.m_Z = A * a_crInstance1.m_Z + B * a_crInstance2.m_Z;
  result.m_W = A * a_crInstance1.m_W + B * a_crInstance2.m_W;
  return result;
}
/*--------------------------------------------------------------------------*/
CQuaternion CQuaternion::slerpSpins(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2, const Treal a_cPart, const Treal a_cSpins)
{ CALL
  CQuaternion result;
  Treal A, B;
  Treal angle, phase;
  Treal sin_angle, cos_angle;
  Treal flip;

  cos_angle = dot(a_crInstance1, a_crInstance2);
  if (cos_angle < 0.0)
  {
    cos_angle =- cos_angle;
    flip = -1.0;
  }
  else
    flip = 1.0;

  if ((1.0 - cos_angle) < NMath::CMath::getEpsilon())
  {
    A = CONSTR(1.0) - a_cPart;
    B = a_cPart;
  }
  else
  {
    phase = a_cSpins * NMath::CMathConstants::PI * a_cPart;
    angle = NMath::CMath::acos(cos_angle);
    sin_angle = CONSTR(1.0) / NMath::CMath::sin(angle);
    A = NMath::CMath::sin((CONSTR(1.0) - a_cPart) * angle - phase) * sin_angle;
    B = NMath::CMath::sin(a_cPart * angle + phase) * sin_angle;
  }
  B *= flip;
  result.m_X = A * a_crInstance1.m_X + B * a_crInstance2.m_X;
  result.m_Y = A * a_crInstance1.m_Y + B * a_crInstance2.m_Y;
  result.m_Z = A * a_crInstance1.m_Z + B * a_crInstance2.m_Z;
  result.m_W = A * a_crInstance1.m_W + B * a_crInstance2.m_W;
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
