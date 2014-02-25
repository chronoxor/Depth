/*!
 *  \file    CQuaternion.inl Representation of the quaternion - hyper-complex
 *           number which extends conception of the rotation in a space.
 *  \brief   Quaternion class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Quaternion class (inline).

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
#ifndef __CQUATERNION_INL__
#define __CQUATERNION_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CQuaternion::CQuaternion(const Tbool a_cIdentityFlag/* = true */) :
  m_X(),
  m_Y(),
  m_Z(),
  m_W()
{ CALL
  clear(a_cIdentityFlag);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion::CQuaternion(const Treal a_cX, const Treal a_cY, const Treal a_cZ, const Treal a_cW) :
  m_X(),
  m_Y(),
  m_Z(),
  m_W()
{ CALL
  set(a_cX, a_cY, a_cZ, a_cW);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion::CQuaternion(const Treal a_cpValuesBuffer[]) :
  m_X(),
  m_Y(),
  m_Z(),
  m_W()
{ CALL
  set(a_cpValuesBuffer);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion::CQuaternion(const CVector4D& a_crVector4D) :
  m_X(),
  m_Y(),
  m_Z(),
  m_W()
{ CALL
  set(a_crVector4D);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion::CQuaternion(const CQuaternion& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion::~CQuaternion()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator == (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  return (NMath::CMath::isEqual(a_crInstance1.m_X, a_crInstance2.m_X) && NMath::CMath::isEqual(a_crInstance1.m_Y, a_crInstance2.m_Y) && NMath::CMath::isEqual(a_crInstance1.m_Z, a_crInstance2.m_Z) && NMath::CMath::isEqual(a_crInstance1.m_W, a_crInstance2.m_W));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator != (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator + (const CQuaternion& a_crInstance)
{ CALL
  return CQuaternion(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator - (const CQuaternion& a_crInstance)
{ CALL
  return CQuaternion::inverse(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator ! (const CQuaternion& a_crInstance)
{ CALL
  return CQuaternion::conjugate(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator + (const CQuaternion& a_crInstance, const Treal a_cValue)
{ CALL
  return CQuaternion(a_crInstance.m_X + a_cValue, a_crInstance.m_Y + a_cValue, a_crInstance.m_Z + a_cValue, a_crInstance.m_W + a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator + (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  return CQuaternion::add(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator + (const Treal a_cValue, const CQuaternion& a_crInstance)
{ CALL
  return CQuaternion(a_cValue + a_crInstance.m_X, a_cValue + a_crInstance.m_Y, a_cValue + a_crInstance.m_Z, a_cValue + a_crInstance.m_W);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator - (const CQuaternion& a_crInstance, const Treal a_cValue)
{ CALL
  return CQuaternion(a_crInstance.m_X - a_cValue, a_crInstance.m_Y - a_cValue, a_crInstance.m_Z - a_cValue, a_crInstance.m_W - a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator - (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  return CQuaternion::sub(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator - (const Treal a_cValue, const CQuaternion& a_crInstance)
{ CALL
  return CQuaternion(a_cValue - a_crInstance.m_X, a_cValue - a_crInstance.m_Y, a_cValue - a_crInstance.m_Z, a_cValue - a_crInstance.m_W);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator * (const CQuaternion& a_crInstance, const Treal a_cValue)
{ CALL
  return CQuaternion(a_crInstance.m_X * a_cValue, a_crInstance.m_Y * a_cValue, a_crInstance.m_Z * a_cValue, a_crInstance.m_W * a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator * (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  return CQuaternion::mul(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator * (const Treal a_cValue, const CQuaternion& a_crInstance)
{ CALL
  return CQuaternion(a_cValue * a_crInstance.m_X, a_cValue * a_crInstance.m_Y, a_cValue * a_crInstance.m_Z, a_cValue * a_crInstance.m_W);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator / (const CQuaternion& a_crInstance, const Treal a_cValue)
{ CALL
  return CQuaternion(a_crInstance.m_X / a_cValue, a_crInstance.m_Y / a_cValue, a_crInstance.m_Z / a_cValue, a_crInstance.m_W / a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator / (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  return CQuaternion::div(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CQuaternion operator / (const Treal a_cValue, const CQuaternion& a_crInstance)
{ CALL
  return CQuaternion(a_cValue / a_crInstance.m_X, a_cValue / a_crInstance.m_Y, a_cValue / a_crInstance.m_Z, a_cValue / a_crInstance.m_W);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Treal operator ^ (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  return CQuaternion::dot(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CPoint3D<Treal> operator * (const CPoint3D<Treal>& a_crPoint3D, const CQuaternion& a_crInstance)
{ CALL
  return a_crInstance.rotate(a_crPoint3D);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator * (const CVector3D& a_crVector3D, const CQuaternion& a_crInstance)
{ CALL
  return a_crInstance.rotate(a_crVector3D);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator * (const CVector4D& a_crVector4D, const CQuaternion& a_crInstance)
{ CALL
  return a_crInstance.rotate(a_crVector4D);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion& CQuaternion::operator = (const Treal a_cValue)
{ CALL
  set(a_cValue, a_cValue, a_cValue, a_cValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion& CQuaternion::operator = (const CVector4D& a_crVector4D)
{ CALL
  set(a_crVector4D);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion& CQuaternion::operator = (const CQuaternion& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion& CQuaternion::operator += (const Treal a_cValue)
{ CALL
  m_X += a_cValue;
  m_Y += a_cValue;
  m_Z += a_cValue;
  m_W += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion& CQuaternion::operator += (const CQuaternion& a_crInstance)
{ CALL
  set(add(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion& CQuaternion::operator -= (const Treal a_cValue)
{ CALL
  m_X -= a_cValue;
  m_Y -= a_cValue;
  m_Z -= a_cValue;
  m_W -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion& CQuaternion::operator -= (const CQuaternion& a_crInstance)
{ CALL
  set(sub(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion& CQuaternion::operator *= (const Treal a_cValue)
{ CALL
  m_X *= a_cValue;
  m_Y *= a_cValue;
  m_Z *= a_cValue;
  m_W *= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion& CQuaternion::operator *= (const CQuaternion& a_crInstance)
{ CALL
  set(mul(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion& CQuaternion::operator /= (const Treal a_cValue)
{ CALL
  m_X /= a_cValue;
  m_Y /= a_cValue;
  m_Z /= a_cValue;
  m_W /= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion& CQuaternion::operator /= (const CQuaternion& a_crInstance)
{ CALL
  set(div(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CQuaternion::set(const Treal a_cX, const Treal a_cY, const Treal a_cZ, const Treal a_cW)
{ CALL
  m_X = a_cX;
  m_Y = a_cY;
  m_Z = a_cZ;
  m_W = a_cW;
}
/*--------------------------------------------------------------------------*/
inline void CQuaternion::set(const CVector4D& a_crVector4D)
{ CALL
  m_X = a_crVector4D.m_X;
  m_Y = a_crVector4D.m_Y;
  m_Z = a_crVector4D.m_Z;
  m_W = a_crVector4D.m_W;
}
/*--------------------------------------------------------------------------*/
inline void CQuaternion::set(const CQuaternion& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
  m_Z = a_crInstance.m_Z;
  m_W = a_crInstance.m_W;
}
/*--------------------------------------------------------------------------*/
inline CMatrix3D CQuaternion::getMatrix3D() const
{ CALL
  CMatrix3D result;
  getMatrix3D(result);
  return result;
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D CQuaternion::getMatrix4D() const
{ CALL
  CMatrix4D result;
  getMatrix4D(result);
  return result;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::getConjugate() const
{ CALL
  return CQuaternion::conjugate(*this);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::getInverse() const
{ CALL
  return CQuaternion::inverse(*this);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::getSquared() const
{ CALL
  return CQuaternion::squared(*this);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::getExponent() const
{ CALL
  return CQuaternion::exponent(*this);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::getLogarithmic() const
{ CALL
  return CQuaternion::logarithmic(*this);
}
/*--------------------------------------------------------------------------*/
inline Treal CQuaternion::length() const
{ CALL
  return NMath::CMath::sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z + m_W * m_W);
}
/*--------------------------------------------------------------------------*/
inline Treal CQuaternion::lengthSq() const
{ CALL
  return (m_X * m_X + m_Y * m_Y + m_Z * m_Z + m_W * m_W);
}
/*--------------------------------------------------------------------------*/
inline Treal CQuaternion::dot(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  return (a_crInstance1.m_X * a_crInstance2.m_X + a_crInstance1.m_Y * a_crInstance2.m_Y + a_crInstance1.m_Z * a_crInstance2.m_Z + a_crInstance1.m_W * a_crInstance2.m_W);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::add(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  return CQuaternion(a_crInstance1.m_X + a_crInstance2.m_X, a_crInstance1.m_Y + a_crInstance2.m_Y, a_crInstance1.m_Z + a_crInstance2.m_Z, a_crInstance1.m_W + a_crInstance2.m_W);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::sub(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2)
{ CALL
  return CQuaternion(a_crInstance1.m_X - a_crInstance2.m_X, a_crInstance1.m_Y - a_crInstance2.m_Y, a_crInstance1.m_Z - a_crInstance2.m_Z, a_crInstance1.m_W - a_crInstance2.m_W);
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::spherical(const Treal a_cLatitude, const Treal a_cLongitude, const Treal a_cAngle)
{ CALL
  CQuaternion result;
  result.setSpherical(a_cLatitude, a_cLongitude, a_cAngle);
  return result;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::rotateAnglesXYZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CQuaternion result;
  result.setRotateAnglesXYZ(a_cAngleX, a_cAngleY, a_cAngleZ);
  return result;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::rotateAxisAngle(const CVector3D& a_crAxis, const Treal a_cAngle)
{ CALL
  CQuaternion result;
  result.setRotateAxisAngle(a_crAxis, a_cAngle);
  return result;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::matrix(const CMatrix3D& a_crMatrix3D)
{ CALL
  CQuaternion result;
  result.setMatrix(a_crMatrix3D);
  return result;
}
/*--------------------------------------------------------------------------*/
inline CQuaternion CQuaternion::matrix(const CMatrix4D& a_crMatrix4D)
{ CALL
  CQuaternion result;
  result.setMatrix(a_crMatrix4D);
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CQuaternion::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CQuaternion")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_X, STR("m_X")));
    CHECK(a_rArchive.doValue(m_Y, STR("m_Y")));
    CHECK(a_rArchive.doValue(m_Z, STR("m_Z")));
    CHECK(a_rArchive.doValue(m_W, STR("m_W")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CQuaternion::swap(CQuaternion& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_X, a_rInstance.m_X);
  NAlgorithms::NCommon::swap(m_Y, a_rInstance.m_Y);
  NAlgorithms::NCommon::swap(m_Z, a_rInstance.m_Z);
  NAlgorithms::NCommon::swap(m_W, a_rInstance.m_W);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
