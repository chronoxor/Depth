/*!
 *  \file    CVector3D.inl Representation of the vector in a space.
 *  \brief   Vector in a space class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Vector in a space class (inline).

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
#ifndef __CVECTOR3D_INL__
#define __CVECTOR3D_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CVector3D::CVector3D() :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
inline CVector3D::CVector3D(const Treal a_cX, const Treal a_cY, const Treal a_cZ) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_cX, a_cY, a_cZ);
}
/*--------------------------------------------------------------------------*/
inline CVector3D::CVector3D(const Treal a_cpCoordinatesBuffer[]) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_cpCoordinatesBuffer);
}
/*--------------------------------------------------------------------------*/
inline CVector3D::CVector3D(const CPoint2D<Treal>& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector3D::CVector3D(const CPoint3D<Treal>& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector3D::CVector3D(const CVector2D& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector3D::CVector3D(const CVector3D& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector3D::CVector3D(const CVector4D& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector3D::~CVector3D()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator == (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return (NMath::CMath::isEqual(a_crInstance1.m_X, a_crInstance2.m_X) && NMath::CMath::isEqual(a_crInstance1.m_Y, a_crInstance2.m_Y) && NMath::CMath::isEqual(a_crInstance1.m_Z, a_crInstance2.m_Z));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator != (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator < (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() < a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator > (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() > a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator <= (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() <= a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator >= (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() >= a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator + (const CVector3D& a_crInstance)
{ CALL
  return CVector3D(+a_crInstance.m_X, +a_crInstance.m_Y, +a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator - (const CVector3D& a_crInstance)
{ CALL
  return CVector3D(-a_crInstance.m_X, -a_crInstance.m_Y, -a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator + (const CVector3D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector3D(a_crInstance.m_X + a_cValue, a_crInstance.m_Y + a_cValue, a_crInstance.m_Z + a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator + (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return CVector3D::add(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator + (const Treal a_cValue, const CVector3D& a_crInstance)
{ CALL
  return CVector3D(a_cValue + a_crInstance.m_X, a_cValue + a_crInstance.m_Y, a_cValue + a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator - (const CVector3D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector3D(a_crInstance.m_X - a_cValue, a_crInstance.m_Y - a_cValue, a_crInstance.m_Z - a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator - (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return CVector3D::sub(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator - (const Treal a_cValue, const CVector3D& a_crInstance)
{ CALL
  return CVector3D(a_cValue - a_crInstance.m_X, a_cValue - a_crInstance.m_Y, a_cValue - a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator * (const CVector3D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector3D(a_crInstance.m_X * a_cValue, a_crInstance.m_Y * a_cValue, a_crInstance.m_Z * a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator * (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return CVector3D::mul(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator * (const Treal a_cValue, const CVector3D& a_crInstance)
{ CALL
  return CVector3D(a_cValue * a_crInstance.m_X, a_cValue * a_crInstance.m_Y, a_cValue * a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator / (const CVector3D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector3D(a_crInstance.m_X / a_cValue, a_crInstance.m_Y / a_cValue, a_crInstance.m_Z / a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator / (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return CVector3D::div(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator / (const Treal a_cValue, const CVector3D& a_crInstance)
{ CALL
  return CVector3D(a_cValue / a_crInstance.m_X, a_cValue / a_crInstance.m_Y, a_cValue / a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Treal operator ^ (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return CVector3D::dot(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator | (const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return CVector3D::cross(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator = (const Treal a_cValue)
{ CALL
  set(a_cValue, a_cValue, a_cValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator = (const CPoint2D<Treal>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator = (const CPoint3D<Treal>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator = (const CVector2D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator = (const CVector3D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator = (const CVector4D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator += (const Treal a_cValue)
{ CALL
  m_X += a_cValue;
  m_Y += a_cValue;
  m_Z += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator += (const CVector3D& a_crInstance)
{ CALL
  set(add(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator -= (const Treal a_cValue)
{ CALL
  m_X -= a_cValue;
  m_Y -= a_cValue;
  m_Z -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator -= (const CVector3D& a_crInstance)
{ CALL
  set(sub(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator *= (const Treal a_cValue)
{ CALL
  m_X *= a_cValue;
  m_Y *= a_cValue;
  m_Z *= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator *= (const CVector3D& a_crInstance)
{ CALL
  set(mul(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator /= (const Treal a_cValue)
{ CALL
  m_X /= a_cValue;
  m_Y /= a_cValue;
  m_Z /= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator /= (const CVector3D& a_crInstance)
{ CALL
  set(div(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector3D& CVector3D::operator |= (const CVector3D& a_crInstance)
{ CALL
  set(cross(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CVector3D::set(const Treal a_cX, const Treal a_cY, const Treal a_cZ)
{ CALL
  m_X = a_cX;
  m_Y = a_cY;
  m_Z = a_cZ;
}
/*--------------------------------------------------------------------------*/
inline void CVector3D::set(const CPoint2D<Treal>& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
  m_Z = 0.0;
}
/*--------------------------------------------------------------------------*/
inline void CVector3D::set(const CPoint3D<Treal>& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
  m_Z = a_crInstance.m_Z;
}
/*--------------------------------------------------------------------------*/
inline void CVector3D::set(const CVector2D& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
  m_Z = 0.0;
}
/*--------------------------------------------------------------------------*/
inline void CVector3D::set(const CVector3D& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
  m_Z = a_crInstance.m_Z;
}
/*--------------------------------------------------------------------------*/
inline void CVector3D::clear()
{ CALL
  m_X = 0.0;
  m_Y = 0.0;
  m_Z = 0.0;
}
/*--------------------------------------------------------------------------*/
inline void CVector3D::absolute()
{ CALL
  m_X = NMath::CMath::fabs(m_X);
  m_Y = NMath::CMath::fabs(m_Y);
  m_Z = NMath::CMath::fabs(m_Z);
}
/*--------------------------------------------------------------------------*/
inline void CVector3D::negate()
{ CALL
  m_X = -m_X;
  m_Y = -m_Y;
  m_Z = -m_Z;
}
/*--------------------------------------------------------------------------*/
inline Treal CVector3D::length() const
{ CALL
  return NMath::CMath::sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z);
}
/*--------------------------------------------------------------------------*/
inline Treal CVector3D::lengthSq() const
{ CALL
  return (m_X * m_X + m_Y * m_Y + m_Z * m_Z);
}
/*--------------------------------------------------------------------------*/
inline CVector3D CVector3D::scale(const Treal a_cScaleX, const Treal a_cScaleY, const Treal a_cScaleZ) const
{ CALL
  return CVector3D(m_X * a_cScaleX, m_Y * a_cScaleY, m_Z * a_cScaleZ);
}
/*--------------------------------------------------------------------------*/
inline CVector3D CVector3D::translate(const Treal a_cTranslateX, const Treal a_cTranslateY, const Treal a_cTranslateZ) const
{ CALL
  return CVector3D(m_X + a_cTranslateX, m_Y + a_cTranslateY, m_Z + a_cTranslateZ);
}
/*--------------------------------------------------------------------------*/
inline Tbool CVector3D::isCollinear(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return (cross(a_crInstance1, a_crInstance2).lengthSq() < (NMath::CMath::getEpsilon() * NMath::CMath::getEpsilon()));
}
/*--------------------------------------------------------------------------*/
inline Tbool CVector3D::isComplanar(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2, const CVector3D& a_crInstance3)
{ CALL
  return (NMath::CMath::fabs(dot(a_crInstance1, cross(a_crInstance2, a_crInstance3))) < (NMath::CMath::getEpsilon() * NMath::CMath::getEpsilon() * NMath::CMath::getEpsilon()));
}
/*--------------------------------------------------------------------------*/
inline Treal CVector3D::distance(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return sub(a_crInstance1, a_crInstance2).length();
}
/*--------------------------------------------------------------------------*/
inline Treal CVector3D::distanceSq(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return sub(a_crInstance1, a_crInstance2).lengthSq();
}
/*--------------------------------------------------------------------------*/
inline Treal CVector3D::dot(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return (a_crInstance1.m_X * a_crInstance2.m_X + a_crInstance1.m_Y * a_crInstance2.m_Y + a_crInstance1.m_Z * a_crInstance2.m_Z);
}
/*--------------------------------------------------------------------------*/
inline Treal CVector3D::angle(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return NMath::CMath::acos(angleCos(a_crInstance1, a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline CVector3D CVector3D::add(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return CVector3D(a_crInstance1.m_X + a_crInstance2.m_X, a_crInstance1.m_Y + a_crInstance2.m_Y, a_crInstance1.m_Z + a_crInstance2.m_Z);
}
/*--------------------------------------------------------------------------*/
inline CVector3D CVector3D::sub(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return CVector3D(a_crInstance1.m_X - a_crInstance2.m_X, a_crInstance1.m_Y - a_crInstance2.m_Y, a_crInstance1.m_Z - a_crInstance2.m_Z);
}
/*--------------------------------------------------------------------------*/
inline CVector3D CVector3D::mul(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return CVector3D(a_crInstance1.m_X * a_crInstance2.m_X, a_crInstance1.m_Y * a_crInstance2.m_Y, a_crInstance1.m_Z * a_crInstance2.m_Z);
}
/*--------------------------------------------------------------------------*/
inline CVector3D CVector3D::div(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return CVector3D(a_crInstance1.m_X / a_crInstance2.m_X, a_crInstance1.m_Y * a_crInstance2.m_Y, a_crInstance1.m_Z / a_crInstance2.m_Z);
}
/*--------------------------------------------------------------------------*/
inline CVector3D CVector3D::between(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return sub(a_crInstance2, a_crInstance1);
}
/*--------------------------------------------------------------------------*/
inline CVector3D CVector3D::middle(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2)
{ CALL
  return add(a_crInstance1, a_crInstance2) / 2;
}
/*--------------------------------------------------------------------------*/
inline CVector3D CVector3D::lerp(const CVector3D& a_crInstance1, const CVector3D& a_crInstance2, const Treal a_cPart)
{ CALL
  return CVector3D(a_crInstance1.m_X + a_cPart * (a_crInstance2.m_X - a_crInstance1.m_X), a_crInstance1.m_Y + a_cPart * (a_crInstance2.m_Y - a_crInstance1.m_Y), a_crInstance1.m_Z + a_cPart * (a_crInstance2.m_Z - a_crInstance1.m_Z));
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CVector3D::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CVector3D")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_X, STR("m_X")));
    CHECK(a_rArchive.doValue(m_Y, STR("m_Y")));
    CHECK(a_rArchive.doValue(m_Z, STR("m_Z")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CVector3D::swap(CVector3D& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_X, a_rInstance.m_X);
  NAlgorithms::NCommon::swap(m_Y, a_rInstance.m_Y);
  NAlgorithms::NCommon::swap(m_Z, a_rInstance.m_Z);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
