/*!
 *  \file    CRay3D.inl Representation of the ray in a space.
 *  \brief   Ray in a space class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Ray in a space class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   10.07.2008 23:31:54

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
#ifndef __CRAY3D_INL__
#define __CRAY3D_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CRay3D::CRay3D() :
  m_Origin(0.0, 0.0, 0.0),
  m_Direction(1.0, 0.0, 0.0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CRay3D::CRay3D(const CPoint3D<Treal>& a_crOrigin, const CVector3D& a_crDirection) :
  m_Origin(0.0, 0.0, 0.0),
  m_Direction(1.0, 0.0, 0.0)
{ CALL
  set(a_crOrigin, a_crDirection);
}
/*--------------------------------------------------------------------------*/
inline CRay3D::CRay3D(const CPoint3D<Treal>& a_crA, const CPoint3D<Treal>& a_crB) :
  m_Origin(0.0, 0.0, 0.0),
  m_Direction(1.0, 0.0, 0.0)
{ CALL
  set(a_crA, a_crB);
}
/*--------------------------------------------------------------------------*/
inline CRay3D::CRay3D(const CRay3D& a_crInstance) :
  m_Origin(0.0, 0.0, 0.0),
  m_Direction(1.0, 0.0, 0.0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CRay3D::~CRay3D()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator == (const CRay3D& a_crInstance1, const CRay3D& a_crInstance2)
{ CALL
  return (NMath::CMath::isEqual(a_crInstance1.m_Origin.m_X, a_crInstance2.m_Origin.m_X) && NMath::CMath::isEqual(a_crInstance1.m_Origin.m_Y, a_crInstance2.m_Origin.m_Y) && NMath::CMath::isEqual(a_crInstance1.m_Origin.m_Z, a_crInstance2.m_Origin.m_Z) && (a_crInstance1.m_Direction == a_crInstance2.m_Direction));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator != (const CRay3D& a_crInstance1, const CRay3D& a_crInstance2)
{ CALL
  return (!NMath::CMath::isEqual(a_crInstance1.m_Origin.m_X, a_crInstance2.m_Origin.m_X) || !NMath::CMath::isEqual(a_crInstance1.m_Origin.m_Y, a_crInstance2.m_Origin.m_Y) || !NMath::CMath::isEqual(a_crInstance1.m_Origin.m_Z, a_crInstance2.m_Origin.m_Z) || (a_crInstance1.m_Direction != a_crInstance2.m_Direction));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CRay3D operator + (const CRay3D& a_crInstance)
{ CALL
  return CRay3D(a_crInstance.m_Origin, +a_crInstance.m_Direction);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CRay3D operator - (const CRay3D& a_crInstance)
{ CALL
  return CRay3D(a_crInstance.m_Origin, -a_crInstance.m_Direction);
}
/*--------------------------------------------------------------------------*/
inline CRay3D& CRay3D::operator = (const CRay3D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CRay3D::set(const CRay3D& a_crInstance)
{ CALL
  m_Origin.set(a_crInstance.m_Origin);
  m_Direction.set(a_crInstance.m_Direction);
}
/*--------------------------------------------------------------------------*/
inline void CRay3D::negate()
{ CALL
  m_Direction.negate();
}
/*--------------------------------------------------------------------------*/
inline void CRay3D::rotate(const CMatrix3D& a_crMatrix3D)
{ CALL
  m_Direction = a_crMatrix3D.rotate(m_Direction);
  m_Direction.normalize();
}
/*--------------------------------------------------------------------------*/
inline void CRay3D::rotate(const CMatrix4D& a_crMatrix4D)
{ CALL
  m_Direction = a_crMatrix4D.rotate(m_Direction);
  m_Direction.normalize();
}
/*--------------------------------------------------------------------------*/
inline void CRay3D::rotate(const CQuaternion& a_crQuaternion)
{ CALL
  m_Direction = a_crQuaternion.rotate(m_Direction);
  m_Direction.normalize();
}
/*--------------------------------------------------------------------------*/
inline void CRay3D::transform(const CMatrix3D& a_crMatrix3D)
{ CALL
  m_Origin = a_crMatrix3D.transform(m_Origin);
  m_Direction = a_crMatrix3D.rotate(m_Direction);
  m_Direction.normalize();
}
/*--------------------------------------------------------------------------*/
inline void CRay3D::transform(const CMatrix4D& a_crMatrix4D)
{ CALL
  m_Origin = a_crMatrix4D.transform(m_Origin);
  m_Direction = a_crMatrix4D.rotate(m_Direction);
  m_Direction.normalize();
}
/*--------------------------------------------------------------------------*/
inline void CRay3D::transform(const CQuaternion& a_crQuaternion)
{ CALL
  m_Origin = a_crQuaternion.rotate(m_Origin);
  m_Direction = a_crQuaternion.rotate(m_Direction);
  m_Direction.normalize();
}
/*--------------------------------------------------------------------------*/
inline Treal CRay3D::distance(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2, Treal& a_rOffset1, Treal& a_rOffset2)
{ CALL
  return NMath::CMath::sqrt(distanceSq(a_crInstance1, a_crInstance2, a_rOffset1, a_rOffset2));
}
/*--------------------------------------------------------------------------*/
inline Treal CRay3D::distance(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2, CPoint3D<Treal>& a_rFirstPoint3D, CPoint3D<Treal>& a_rSecondPoint3D)
{ CALL
  return NMath::CMath::sqrt(distanceSq(a_crInstance1, a_crInstance2, a_rFirstPoint3D, a_rSecondPoint3D));
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CRay3D::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CRay3D")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Origin, STR("m_Origin")));
    CHECK(a_rArchive.doValue(m_Direction, STR("m_Direction")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CRay3D::swap(CRay3D& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Origin, a_rInstance.m_Origin);
  NAlgorithms::NCommon::swap(m_Direction, a_rInstance.m_Direction);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
