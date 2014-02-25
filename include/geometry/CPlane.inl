/*!
 *  \file    CPlane.inl Representation of the plane in a space.
 *  \brief   Plane in a space class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Plane in a space class (inline).

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
#ifndef __CPLANE_INL__
#define __CPLANE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CPlane::CPlane() :
  m_Normal(1.0, 0.0, 0.0),
  m_Distance(0.0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CPlane::CPlane(const Treal a_cA, const Treal a_cB, const Treal a_cC, const Treal a_cD) :
  m_Normal(1.0, 0.0, 0.0),
  m_Distance(0.0)
{ CALL
  set(a_cA, a_cB, a_cC, a_cD);
}
/*--------------------------------------------------------------------------*/
inline CPlane::CPlane(const CVector3D& a_crTangentVector) :
  m_Normal(1.0, 0.0, 0.0),
  m_Distance(0.0)
{ CALL
  set(a_crTangentVector);
}
/*--------------------------------------------------------------------------*/
inline CPlane::CPlane(const CVector3D& a_crNormal, const Treal a_cDistance) :
  m_Normal(1.0, 0.0, 0.0),
  m_Distance(0.0)
{ CALL
  set(a_crNormal, a_cDistance);
}
/*--------------------------------------------------------------------------*/
inline CPlane::CPlane(const CVector3D& a_crNormal, const CPoint3D<Treal>& a_crPoint3D) :
  m_Normal(1.0, 0.0, 0.0),
  m_Distance(0.0)
{ CALL
  set(a_crNormal, a_crPoint3D);
}
/*--------------------------------------------------------------------------*/
inline CPlane::CPlane(const CPoint3D<Treal>& a_crA, const CPoint3D<Treal>& a_crB, const CPoint3D<Treal>& a_crC) :
  m_Normal(1.0, 0.0, 0.0),
  m_Distance(0.0)
{ CALL
  set(a_crA, a_crB, a_crC);
}
/*--------------------------------------------------------------------------*/
inline CPlane::CPlane(const CPlane& a_crInstance) :
  m_Normal(1.0, 0.0, 0.0),
  m_Distance(0.0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CPlane::~CPlane()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator == (const CPlane& a_crInstance1, const CPlane& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Normal == a_crInstance2.m_Normal) && NMath::CMath::isEqual(a_crInstance1.m_Distance, a_crInstance2.m_Distance));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator != (const CPlane& a_crInstance1, const CPlane& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Normal != a_crInstance2.m_Normal) || !NMath::CMath::isEqual(a_crInstance1.m_Distance, a_crInstance2.m_Distance));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CPlane operator + (const CPlane& a_crInstance)
{ CALL
  return CPlane(+a_crInstance.m_Normal, +a_crInstance.m_Distance);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CPlane operator - (const CPlane& a_crInstance)
{ CALL
  return CPlane(-a_crInstance.m_Normal, -a_crInstance.m_Distance);
}
/*--------------------------------------------------------------------------*/
inline CPlane& CPlane::operator = (const CPlane& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CPlane::set(const CPlane& a_crInstance)
{ CALL
  m_Normal.set(a_crInstance.m_Normal);
  m_Distance = a_crInstance.m_Distance;
}
/*--------------------------------------------------------------------------*/
inline void CPlane::negate()
{ CALL
  m_Normal.negate();
  m_Distance = -m_Distance;
}
/*--------------------------------------------------------------------------*/
inline void CPlane::negateNormal()
{ CALL
  m_Normal.negate();
}
/*--------------------------------------------------------------------------*/
inline void CPlane::negateDistance()
{ CALL
  m_Distance = -m_Distance;
}
/*--------------------------------------------------------------------------*/
inline CVector3D CPlane::getTangent() const
{ CALL
  return m_Normal * m_Distance;
}
/*--------------------------------------------------------------------------*/
inline Treal CPlane::getDot(const CVector3D& a_crVector3D) const
{ CALL
  return (m_Normal.m_X * a_crVector3D.m_X + m_Normal.m_Y * a_crVector3D.m_Y + m_Normal.m_Z * a_crVector3D.m_Z);
}
/*--------------------------------------------------------------------------*/
inline Treal CPlane::getDistanceToPoint(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  return ((m_Normal.m_X * a_crPoint3D.m_X + m_Normal.m_Y * a_crPoint3D.m_Y + m_Normal.m_Z * a_crPoint3D.m_Z) - m_Distance);
}
/*--------------------------------------------------------------------------*/
inline CPoint3D<Treal> CPlane::getClosestPoint(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  Treal distance;
  return getClosestPoint(a_crPoint3D, distance);
}
/*--------------------------------------------------------------------------*/
inline Treal CPlane::isIntersect(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  Treal distance = getDistanceToPoint(a_crPoint3D);
  return (NMath::CMath::isEqualZero(distance) ? CONSTR(0.0) : distance);
}
/*--------------------------------------------------------------------------*/
inline Tbool CPlane::isIntersect(const CRay3D& a_crRay3D) const
{ CALL
  return (!NMath::CMath::isEqualZero(CVector3D::dot(m_Normal, a_crRay3D.m_Direction)));
}
/*--------------------------------------------------------------------------*/
inline Tbool CPlane::isIntersect(const CPlane& a_crPlane) const
{ CALL
  return (CVector3D::cross(m_Normal, a_crPlane.m_Normal).lengthSq() >= NMath::CMath::getEpsilon() * NMath::CMath::getEpsilon());
}
/*--------------------------------------------------------------------------*/
inline Treal CPlane::projectPerspective(const CPoint3D<Treal>& a_crProjectOrigin, const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  CVector3D direction = a_crPoint3D - a_crProjectOrigin;
  return projectOrtho(a_crPoint3D - a_crProjectOrigin, a_crPoint3D, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline void CPlane::rotate(const CMatrix3D& a_crMatrix3D)
{ CALL
  m_Normal = a_crMatrix3D.rotate(m_Normal);
  m_Normal.normalize();
}
/*--------------------------------------------------------------------------*/
inline void CPlane::rotate(const CMatrix4D& a_crMatrix4D)
{ CALL
  m_Normal = a_crMatrix4D.rotate(m_Normal);
  m_Normal.normalize();
}
/*--------------------------------------------------------------------------*/
inline void CPlane::rotate(const CQuaternion& a_crQuaternion)
{ CALL
  m_Normal = a_crQuaternion.rotate(m_Normal);
  m_Normal.normalize();
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CPlane::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CPlane")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Normal, STR("m_Normal")));
    CHECK(a_rArchive.doValue(m_Distance, STR("m_Distance")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CPlane::swap(CPlane& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Normal, a_rInstance.m_Normal);
  NAlgorithms::NCommon::swap(m_Distance, a_rInstance.m_Distance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
