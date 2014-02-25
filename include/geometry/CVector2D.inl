/*!
 *  \file    CVector2D.inl Representation of the vector on a plane.
 *  \brief   Vector on a plane class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Vector on a plane class (inline).

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
#ifndef __CVECTOR2D_INL__
#define __CVECTOR2D_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CVector2D::CVector2D() :
  m_X(),
  m_Y()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
inline CVector2D::CVector2D(const Treal a_cX, const Treal a_cY) :
  m_X(),
  m_Y()
{ CALL
  set(a_cX, a_cY);
}
/*--------------------------------------------------------------------------*/
inline CVector2D::CVector2D(const Treal a_cpCoordinatesBuffer[]) :
  m_X(),
  m_Y()
{ CALL
  set(a_cpCoordinatesBuffer);
}
/*--------------------------------------------------------------------------*/
inline CVector2D::CVector2D(const CPoint2D<Treal>& a_crInstance) :
  m_X(),
  m_Y()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector2D::CVector2D(const CPoint3D<Treal>& a_crInstance) :
  m_X(),
  m_Y()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector2D::CVector2D(const CVector2D& a_crInstance) :
  m_X(),
  m_Y()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector2D::CVector2D(const CVector3D& a_crInstance) :
  m_X(),
  m_Y()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector2D::CVector2D(const CVector4D& a_crInstance) :
  m_X(),
  m_Y()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CVector2D::~CVector2D()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator == (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return (NMath::CMath::isEqual(a_crInstance1.m_X, a_crInstance2.m_X) && NMath::CMath::isEqual(a_crInstance1.m_Y, a_crInstance2.m_Y));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator != (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator < (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() < a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator > (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() > a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator <= (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() <= a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator >= (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return (a_crInstance1.lengthSq() >= a_crInstance2.lengthSq());
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator + (const CVector2D& a_crInstance)
{ CALL
  return CVector2D(+a_crInstance.m_X, +a_crInstance.m_Y);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator - (const CVector2D& a_crInstance)
{ CALL
  return CVector2D(-a_crInstance.m_X, -a_crInstance.m_Y);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator + (const CVector2D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector2D(a_crInstance.m_X + a_cValue, a_crInstance.m_Y + a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator + (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return CVector2D::add(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator + (const Treal a_cValue, const CVector2D& a_crInstance)
{ CALL
  return CVector2D(a_cValue + a_crInstance.m_X, a_cValue + a_crInstance.m_Y);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator - (const CVector2D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector2D(a_crInstance.m_X - a_cValue, a_crInstance.m_Y - a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator - (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return CVector2D::sub(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator - (const Treal a_cValue, const CVector2D& a_crInstance)
{ CALL
  return CVector2D(a_cValue - a_crInstance.m_X, a_cValue - a_crInstance.m_Y);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator * (const CVector2D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector2D(a_crInstance.m_X * a_cValue, a_crInstance.m_Y * a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator * (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return CVector2D::mul(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator * (const Treal a_cValue, const CVector2D& a_crInstance)
{ CALL
  return CVector2D(a_cValue * a_crInstance.m_X, a_cValue * a_crInstance.m_Y);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator / (const CVector2D& a_crInstance, const Treal a_cValue)
{ CALL
  return CVector2D(a_crInstance.m_X / a_cValue, a_crInstance.m_Y / a_cValue);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator / (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return CVector2D::div(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator / (const Treal a_cValue, const CVector2D& a_crInstance)
{ CALL
  return CVector2D(a_cValue / a_crInstance.m_X, a_cValue / a_crInstance.m_Y);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Treal operator ^ (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return CVector2D::dot(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Treal operator | (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return CVector2D::zcomp(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator = (const Treal a_cValue)
{ CALL
  set(a_cValue, a_cValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator = (const CPoint2D<Treal>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator = (const CPoint3D<Treal>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator = (const CVector2D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator = (const CVector3D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator = (const CVector4D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator += (const Treal a_cValue)
{ CALL
  m_X += a_cValue;
  m_Y += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator += (const CVector2D& a_crInstance)
{ CALL
  set(add(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator -= (const Treal a_cValue)
{ CALL
  m_X -= a_cValue;
  m_Y -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator -= (const CVector2D& a_crInstance)
{ CALL
  set(sub(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator *= (const Treal a_cValue)
{ CALL
  m_X *= a_cValue;
  m_Y *= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator *= (const CVector2D& a_crInstance)
{ CALL
  set(mul(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator /= (const Treal a_cValue)
{ CALL
  m_X /= a_cValue;
  m_Y /= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CVector2D& CVector2D::operator /= (const CVector2D& a_crInstance)
{ CALL
  set(div(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CVector2D::set(const Treal a_cX, const Treal a_cY)
{ CALL
  m_X = a_cX;
  m_Y = a_cY;
}
/*--------------------------------------------------------------------------*/
inline void CVector2D::set(const CPoint2D<Treal>& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
}
/*--------------------------------------------------------------------------*/
inline void CVector2D::set(const CVector2D& a_crInstance)
{ CALL
  m_X = a_crInstance.m_X;
  m_Y = a_crInstance.m_Y;
}
/*--------------------------------------------------------------------------*/
inline void CVector2D::set(const CVector4D& a_crInstance)
{ CALL
  set((CVector3D)a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline void CVector2D::clear()
{ CALL
  m_X = 0.0;
  m_Y = 0.0;
}
/*--------------------------------------------------------------------------*/
inline void CVector2D::absolute()
{ CALL
  m_X = NMath::CMath::fabs(m_X);
  m_Y = NMath::CMath::fabs(m_Y);
}
/*--------------------------------------------------------------------------*/
inline void CVector2D::negate()
{ CALL
  m_X = -m_X;
  m_Y = -m_Y;
}
/*--------------------------------------------------------------------------*/
inline Treal CVector2D::length() const
{ CALL
  return NMath::CMath::sqrt(m_X * m_X + m_Y * m_Y);
}
/*--------------------------------------------------------------------------*/
inline Treal CVector2D::lengthSq() const
{ CALL
  return (m_X * m_X + m_Y * m_Y);
}
/*--------------------------------------------------------------------------*/
inline CVector2D CVector2D::scale(const Treal a_cScaleX, const Treal a_cScaleY) const
{ CALL
  return CVector2D(m_X * a_cScaleX, m_Y * a_cScaleY);
}
/*--------------------------------------------------------------------------*/
inline CVector2D CVector2D::translate(const Treal a_cTranslateX, const Treal a_cTranslateY) const
{ CALL
  return CVector2D(m_X + a_cTranslateX, m_Y + a_cTranslateY);
}
/*--------------------------------------------------------------------------*/
inline Tbool CVector2D::isCollinear(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return (dot(ortho(a_crInstance1), a_crInstance2) < NMath::CMath::getEpsilon());
}
/*--------------------------------------------------------------------------*/
inline Tbool CVector2D::isOrthogonal(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return (dot(a_crInstance1, a_crInstance2) < NMath::CMath::getEpsilon());
}
/*--------------------------------------------------------------------------*/
inline Treal CVector2D::distance(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return sub(a_crInstance1, a_crInstance2).length();
}
/*--------------------------------------------------------------------------*/
inline Treal CVector2D::distanceSq(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return sub(a_crInstance1, a_crInstance2).lengthSq();
}
/*--------------------------------------------------------------------------*/
inline Treal CVector2D::dot(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return (a_crInstance1.m_X * a_crInstance2.m_X + a_crInstance1.m_Y * a_crInstance2.m_Y);
}
/*--------------------------------------------------------------------------*/
inline Treal CVector2D::zcomp(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return (a_crInstance1.m_X * a_crInstance2.m_Y - a_crInstance1.m_Y * a_crInstance2.m_X);
}
/*--------------------------------------------------------------------------*/
inline Treal CVector2D::angle(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return NMath::CMath::acos(angleCos(a_crInstance1, a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline CVector2D CVector2D::ortho(const CVector2D& a_crInstance)
{ CALL
  return CVector2D(-a_crInstance.m_Y, a_crInstance.m_X);
}
/*--------------------------------------------------------------------------*/
inline CVector2D CVector2D::add(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return CVector2D(a_crInstance1.m_X + a_crInstance2.m_X, a_crInstance1.m_Y + a_crInstance2.m_Y);
}
/*--------------------------------------------------------------------------*/
inline CVector2D CVector2D::sub(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return CVector2D(a_crInstance1.m_X - a_crInstance2.m_X, a_crInstance1.m_Y - a_crInstance2.m_Y);
}
/*--------------------------------------------------------------------------*/
inline CVector2D CVector2D::mul(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return CVector2D(a_crInstance1.m_X * a_crInstance2.m_X, a_crInstance1.m_Y * a_crInstance2.m_Y);
}
/*--------------------------------------------------------------------------*/
inline CVector2D CVector2D::div(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return CVector2D(a_crInstance1.m_X / a_crInstance2.m_X, a_crInstance1.m_Y / a_crInstance2.m_Y);
}
/*--------------------------------------------------------------------------*/
inline CVector2D CVector2D::between(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return sub(a_crInstance2, a_crInstance1);
}
/*--------------------------------------------------------------------------*/
inline CVector2D CVector2D::middle(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2)
{ CALL
  return add(a_crInstance1, a_crInstance2) / 2;
}
/*--------------------------------------------------------------------------*/
inline CVector2D CVector2D::lerp(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2, const Treal a_cPart)
{ CALL
  return CVector2D(a_crInstance1.m_X + a_cPart * (a_crInstance2.m_X - a_crInstance1.m_X), a_crInstance1.m_Y + a_cPart * (a_crInstance2.m_Y - a_crInstance1.m_Y));
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CVector2D::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CVector2D")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_X, STR("m_X")));
    CHECK(a_rArchive.doValue(m_Y, STR("m_Y")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CVector2D::swap(CVector2D& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_X, a_rInstance.m_X);
  NAlgorithms::NCommon::swap(m_Y, a_rInstance.m_Y);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
