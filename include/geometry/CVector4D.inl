/*!
 *  \file    CVector4D.inl Representation of the vector in a hyperspace.
 *  \brief   Vector in a hyperspace class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Vector in a hyperspace class (inline).

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
#ifndef __CVECTOR4D_INL__
#define __CVECTOR4D_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CVector4D::CVector4D() :
  m_X(),
  m_Y(),
  m_Z(),
  m_W()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
inline CVector4D::CVector4D(const Treal a_cX, const Treal a_cY, const Treal a_cZ, const Treal a_cW) :
  m_X(),
  m_Y(),
  m_Z(),
  m_W()
{ CALL
  set(a_cX, a_cY, a_cZ, a_cW);
}
/*--------------------------------------------------------------------------*/
inline CVector4D::CVector4D(const Treal a_cpCoordinatesBuffer[]) :
  m_X(),
  m_Y(),
  m_Z(),
  m_W()
{ CALL
  set(a_cpCoordinatesBuffer);
}
/*--------------------------------------------------------------------------*/
inline CVector4D::CVector4D(const CPoint2D<Treal>& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z(),
  m_W()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector4D::CVector4D(const CPoint3D<Treal>& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z(),
  m_W()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector4D::CVector4D(const CVector2D& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z(),
  m_W()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector4D::CVector4D(const CVector3D& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector4D::CVector4D(const CVector4D& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector4D::~CVector4D()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator == (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return (NMath::CMath::isEqual(a_crInstance1.m_X, a_crInstance2.m_X) && NMath::CMath::isEqual(a_crInstance1.m_Y, a_crInstance2.m_Y) && NMath::CMath::isEqual(a_crInstance1.m_Z, a_crInstance2.m_Z) && NMath::CMath::isEqual(a_crInstance1.m_W, a_crInstance2.m_W));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator != (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator < (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() < a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator > (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() > a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator <= (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() <= a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator >= (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() >= a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator + (const CVector4D& a_crInstance)
{ CALL
  return CVector4D(+a_crInstance.m_X, +a_crInstance.m_Y, +a_crInstance.m_Z, +a_crInstance.m_W);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator - (const CVector4D& a_crInstance)
{ CALL
  return CVector4D(-a_crInstance.m_X, -a_crInstance.m_Y, -a_crInstance.m_Z, -a_crInstance.m_W);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator + (const CVector4D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector4D(a_crInstance.m_X + a_cValue, a_crInstance.m_Y + a_cValue, a_crInstance.m_Z + a_cValue, a_crInstance.m_W + a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator + (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return CVector4D::add(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator + (const Treal a_cValue, const CVector4D& a_crInstance)
{ CALL
  return CVector4D(a_cValue + a_crInstance.m_X, a_cValue + a_crInstance.m_Y, a_cValue + a_crInstance.m_Z, a_cValue + a_crInstance.m_W);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator - (const CVector4D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector4D(a_crInstance.m_X - a_cValue, a_crInstance.m_Y - a_cValue, a_crInstance.m_Z - a_cValue, a_crInstance.m_W - a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator - (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return CVector4D::sub(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator - (const Treal a_cValue, const CVector4D& a_crInstance)
{ CALL
  return CVector4D(a_cValue - a_crInstance.m_X, a_cValue - a_crInstance.m_Y, a_cValue - a_crInstance.m_Z, a_cValue - a_crInstance.m_W);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator * (const CVector4D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector4D(a_crInstance.m_X * a_cValue, a_crInstance.m_Y * a_cValue, a_crInstance.m_Z * a_cValue, a_crInstance.m_W * a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator * (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return CVector4D::mul(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator * (const Treal a_cValue, const CVector4D& a_crInstance)
{ CALL
  return CVector4D(a_cValue * a_crInstance.m_X, a_cValue * a_crInstance.m_Y, a_cValue * a_crInstance.m_Z, a_cValue * a_crInstance.m_W);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator / (const CVector4D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector4D(a_crInstance.m_X / a_cValue, a_crInstance.m_Y / a_cValue, a_crInstance.m_Z / a_cValue, a_crInstance.m_W / a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator / (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return CVector4D::div(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator / (const Treal a_cValue, const CVector4D& a_crInstance)
{ CALL
  return CVector4D(a_cValue / a_crInstance.m_X, a_cValue / a_crInstance.m_Y, a_cValue / a_crInstance.m_Z, a_cValue / a_crInstance.m_W);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Treal operator ^ (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return CVector4D::dot(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator = (const Treal a_cValue)
{ CALL
  set(a_cValue, a_cValue, a_cValue, a_cValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator = (const CPoint2D<Treal>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator = (const CPoint3D<Treal>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator = (const CVector2D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator = (const CVector3D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator = (const CVector4D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator += (const Treal a_cValue)
{ CALL
  m_X += a_cValue;
  m_Y += a_cValue;
  m_Z += a_cValue;
  m_W += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator += (const CVector4D& a_crInstance)
{ CALL
  set(add(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator -= (const Treal a_cValue)
{ CALL
  m_X -= a_cValue;
  m_Y -= a_cValue;
  m_Z -= a_cValue;
  m_W -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator -= (const CVector4D& a_crInstance)
{ CALL
  set(sub(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator *= (const Treal a_cValue)
{ CALL
  m_X *= a_cValue;
  m_Y *= a_cValue;
  m_Z *= a_cValue;
  m_W *= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator *= (const CVector4D& a_crInstance)
{ CALL
  set(mul(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator /= (const Treal a_cValue)
{ CALL
  m_X /= a_cValue;
  m_Y /= a_cValue;
  m_Z /= a_cValue;
  m_W /= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector4D& CVector4D::operator /= (const CVector4D& a_crInstance)
{ CALL
  set(div(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::set(const Treal a_cX, const Treal a_cY, const Treal a_cZ, const Treal a_cW)
{ CALL
  m_X = a_cX;
  m_Y = a_cY;
  m_Z = a_cZ;
  m_W = a_cW;
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::set(const CPoint2D<Treal>& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
  m_Z = 0.0;
  m_W = 0.0;
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::set(const CPoint3D<Treal>& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
  m_Z = a_crInstance.m_Z;
  m_W = 0.0;
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::set(const CVector2D& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
  m_Z = 0.0;
  m_W = 0.0;
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::set(const CVector3D& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
  m_Z = a_crInstance.m_Z;
  m_W = 0.0;
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::set(const CVector4D& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
  m_Z = a_crInstance.m_Z;
  m_W = a_crInstance.m_W;
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::setAxis(const CVector3D& a_crAxis, const Treal a_cAngle)
{ CALL
  m_X = a_crAxis.m_X;
  m_Y = a_crAxis.m_Y;
  m_Z = a_crAxis.m_Z;
  m_W = a_cAngle;
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::getAxis(CVector3D& a_rAxis, Treal& a_rAngle) const
{ CALL
  a_rAxis.m_X = m_X;
  a_rAxis.m_Y = m_Y;
  a_rAxis.m_Z = m_Z;
  a_rAngle = m_W;
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::clear()
{ CALL
  m_X = 0.0;
  m_Y = 0.0;
  m_Z = 0.0;
  m_W = 0.0;
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::absolute()
{ CALL
  m_X = NMath::CMath::fabs(m_X);
  m_Y = NMath::CMath::fabs(m_Y);
  m_Z = NMath::CMath::fabs(m_Z);
  m_W = NMath::CMath::fabs(m_W);
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::negate()
{ CALL
  m_X = -m_X;
  m_Y = -m_Y;
  m_Z = -m_Z;
  m_W = -m_W;
}
/*--------------------------------------------------------------------------*/
inline Treal CVector4D::length() const
{ CALL
  return NMath::CMath::sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z + m_W * m_W);
}
/*--------------------------------------------------------------------------*/
inline Treal CVector4D::lengthSq() const
{ CALL
  return (m_X * m_X + m_Y * m_Y + m_Z * m_Z + m_W * m_W);
}
/*--------------------------------------------------------------------------*/
inline CVector4D CVector4D::scale(const Treal a_cScaleX, const Treal a_cScaleY, const Treal a_cScaleZ, const Treal a_cScaleW/* = 1.0 */) const
{ CALL
  return CVector4D(m_X * a_cScaleX, m_Y * a_cScaleY, m_Z * a_cScaleZ, m_W * a_cScaleW);
}
/*--------------------------------------------------------------------------*/
inline CVector4D CVector4D::translate(const Treal a_cTranslateX, const Treal a_cTranslateY, const Treal a_cTranslateZ, const Treal a_cTranslateW/* = 0.0 */) const
{ CALL
  return CVector4D(m_X + a_cTranslateX, m_Y + a_cTranslateY, m_Z + a_cTranslateZ, m_W + a_cTranslateW);
}
/*--------------------------------------------------------------------------*/
inline Treal CVector4D::distance(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return sub(a_crInstance1, a_crInstance2).length();
}
/*--------------------------------------------------------------------------*/
inline Treal CVector4D::distanceSq(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return sub(a_crInstance1, a_crInstance2).lengthSq();
}
/*--------------------------------------------------------------------------*/
inline Treal CVector4D::dot(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return (a_crInstance1.m_X * a_crInstance2.m_X + a_crInstance1.m_Y * a_crInstance2.m_Y + a_crInstance1.m_Z * a_crInstance2.m_Z + a_crInstance1.m_W * a_crInstance2.m_W);
}
/*--------------------------------------------------------------------------*/
inline Treal CVector4D::angle(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return NMath::CMath::acos(angleCos(a_crInstance1, a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline CVector4D CVector4D::add(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return CVector4D(a_crInstance1.m_X + a_crInstance2.m_X, a_crInstance1.m_Y + a_crInstance2.m_Y, a_crInstance1.m_Z + a_crInstance2.m_Z, a_crInstance1.m_W + a_crInstance2.m_W);
}
/*--------------------------------------------------------------------------*/
inline CVector4D CVector4D::sub(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return CVector4D(a_crInstance1.m_X - a_crInstance2.m_X, a_crInstance1.m_Y - a_crInstance2.m_Y, a_crInstance1.m_Z - a_crInstance2.m_Z, a_crInstance1.m_W - a_crInstance2.m_W);
}
/*--------------------------------------------------------------------------*/
inline CVector4D CVector4D::mul(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return CVector4D(a_crInstance1.m_X * a_crInstance2.m_X, a_crInstance1.m_Y * a_crInstance2.m_Y, a_crInstance1.m_Z * a_crInstance2.m_Z, a_crInstance1.m_W * a_crInstance2.m_W);
}
/*--------------------------------------------------------------------------*/
inline CVector4D CVector4D::div(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return CVector4D(a_crInstance1.m_X / a_crInstance2.m_X, a_crInstance1.m_Y * a_crInstance2.m_Y, a_crInstance1.m_Z / a_crInstance2.m_Z, a_crInstance1.m_W / a_crInstance2.m_W);
}
/*--------------------------------------------------------------------------*/
inline CVector4D CVector4D::between(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return sub(a_crInstance2, a_crInstance1);
}
/*--------------------------------------------------------------------------*/
inline CVector4D CVector4D::middle(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2)
{ CALL
  return add(a_crInstance1, a_crInstance2) / 2;
}
/*--------------------------------------------------------------------------*/
inline CVector4D CVector4D::lerp(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2, const Treal a_cPart)
{ CALL
  return CVector4D(a_crInstance1.m_X + a_cPart * (a_crInstance2.m_X - a_crInstance1.m_X), a_crInstance1.m_Y + a_cPart * (a_crInstance2.m_Y - a_crInstance1.m_Y), a_crInstance1.m_Z + a_cPart * (a_crInstance2.m_Z - a_crInstance1.m_Z), a_crInstance1.m_W + a_cPart * (a_crInstance2.m_W - a_crInstance1.m_W));
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CVector4D::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CVector4D")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_X, STR("m_X")));
    CHECK(a_rArchive.doValue(m_Y, STR("m_Y")));
    CHECK(a_rArchive.doValue(m_Z, STR("m_Z")));
    CHECK(a_rArchive.doValue(m_W, STR("m_W")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CVector4D::swap(CVector4D& a_rInstance)
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
