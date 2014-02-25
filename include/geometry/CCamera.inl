/*!
 *  \file    CCamera.inl Representation of the camera in a space.
 *  \brief   Camera in a space class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Camera in a space class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   17.07.2008 22:31:11

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
#ifndef __CCAMERA_INL__
#define __CCAMERA_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CCamera::CCamera(const Tbool a_cOrthogonal/* = false */)
{ CALL
  if (a_cOrthogonal)
    setOrthogonal();
  else
    setFrustum();
}
/*--------------------------------------------------------------------------*/
inline CCamera::CCamera(const Tbool a_cOrthogonal, const CPoint3D<Treal>& a_crLookFrom, const CPoint3D<Treal>& a_crLookAt, const CRect<Treal>& a_crScaleRect, const Treal a_cZnear, const Treal a_cZfar)
{ CALL
  if (a_cOrthogonal)
    setOrthogonal(a_crLookFrom, a_crLookAt, a_crScaleRect, a_cZnear, a_cZfar);
  else
    setFrustum(a_crLookFrom, a_crLookAt, a_crScaleRect, a_cZnear, a_cZfar);
}
/*--------------------------------------------------------------------------*/
inline CCamera::CCamera(const Tbool a_cOrthogonal, const CPoint3D<Treal>& a_crLookFrom, const CPoint3D<Treal>& a_crLookAt, const CVector3D& a_crUp, const CRect<Treal>& a_crScaleRect, const Treal a_cZnear, const Treal a_cZfar)
{ CALL
  if (a_cOrthogonal)
    setOrthogonal(a_crUp, a_crLookFrom, a_crLookAt, a_crScaleRect, a_cZnear, a_cZfar);
  else
    setFrustum(a_crUp, a_crLookFrom, a_crLookAt, a_crScaleRect, a_cZnear, a_cZfar);
}
/*--------------------------------------------------------------------------*/
inline CCamera::CCamera(const CPoint3D<Treal>& a_crLookFrom, const CPoint3D<Treal>& a_crLookAt, const Treal a_cFOV, const Treal a_cAspect, const Treal a_cZnear, const Treal a_cZfar)
{ CALL
  setPerspective(a_crLookFrom, a_crLookAt, a_cFOV, a_cAspect, a_cZnear, a_cZfar);
}
/*--------------------------------------------------------------------------*/
inline CCamera::CCamera(const CPoint3D<Treal>& a_crLookFrom, const CPoint3D<Treal>& a_crLookAt, const CVector3D& a_crUp, const Treal a_cFOV, const Treal a_cAspect, const Treal a_cZnear, const Treal a_cZfar)
{ CALL
  setPerspective(a_crUp, a_crLookFrom, a_crLookAt, a_cFOV, a_cAspect, a_cZnear, a_cZfar);
}
/*--------------------------------------------------------------------------*/
inline CCamera::CCamera(const CCamera& a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CCamera::~CCamera()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CCamera& CCamera::operator = (const CCamera& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbool CCamera::isOrthogonal() const
{ CALL
  return m_OrthoFrustumFlag;
}
/*--------------------------------------------------------------------------*/
inline Tbool CCamera::isFrustum() const
{ CALL
  return !m_OrthoFrustumFlag;
}
/*--------------------------------------------------------------------------*/
inline const CPoint3D<Treal>& CCamera::getPosition() const
{ CALL
  return m_Position;
}
/*--------------------------------------------------------------------------*/
inline void CCamera::getVectors(CVector3D& a_rDirection, CVector3D& a_rUp, CVector3D& a_rRight) const
{ CALL
  a_rDirection = m_Direction;
  a_rUp = m_Up;
  a_rRight = m_Right;
}
/*--------------------------------------------------------------------------*/
inline const CVector3D& CCamera::getDirection() const
{ CALL
  return m_Direction;
}
/*--------------------------------------------------------------------------*/
inline const CVector3D& CCamera::getUp() const
{ CALL
  return m_Up;
}
/*--------------------------------------------------------------------------*/
inline const CVector3D& CCamera::getRight() const
{ CALL
  return m_Right;
}
/*--------------------------------------------------------------------------*/
inline const CRect<Treal>& CCamera::getScaleRect() const
{ CALL
  return m_ScaleRect;
}
/*--------------------------------------------------------------------------*/
inline Treal CCamera::getZnear() const
{ CALL
  return m_Znear;
}
/*--------------------------------------------------------------------------*/
inline Treal CCamera::getZfar() const
{ CALL
  return m_Zfar;
}
/*--------------------------------------------------------------------------*/
inline Treal CCamera::getFOV() const
{ CALL
  return m_FOV;
}
/*--------------------------------------------------------------------------*/
inline Treal CCamera::getAspect() const
{ CALL
  return m_Aspect;
}
/*--------------------------------------------------------------------------*/
inline void CCamera::setDistance(const Treal& a_cDistance)
{ CALL
  m_Distance = a_cDistance;
}
/*--------------------------------------------------------------------------*/
inline Treal CCamera::getDistance() const
{ CALL
  return m_Distance;
}
/*--------------------------------------------------------------------------*/
inline Treal CCamera::getLatitude() const
{ CALL
  return m_Latitude;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CCamera::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CCamera")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_CalculatedMatrixes, STR("m_CalculatedMatrixes")));
    CHECK(a_rArchive.doValue(m_DirectMatrix, STR("m_DirectMatrix")));
    CHECK(a_rArchive.doValue(m_ModelViewMatrix, STR("m_ModelViewMatrix")));
    CHECK(a_rArchive.doValue(m_ProjectionMatrix, STR("m_ProjectionMatrix")));
    CHECK(a_rArchive.doValue(m_InvertMatrix, STR("m_InvertMatrix")));
    CHECK(a_rArchive.doValue(m_InvertModelViewMatrix, STR("m_InvertModelViewMatrix")));
    CHECK(a_rArchive.doValue(m_InvertProjectionMatrix, STR("m_InvertProjectionMatrix")));
    CHECK(a_rArchive.doValue(m_OrthoFrustumFlag, STR("m_OrthoFrustumFlag")));
    CHECK(a_rArchive.doValue(m_Position, STR("m_Position")));
    CHECK(a_rArchive.doValue(m_Direction, STR("m_Direction")));
    CHECK(a_rArchive.doValue(m_Up, STR("m_Up")));
    CHECK(a_rArchive.doValue(m_Right, STR("m_Right")));
    CHECK(a_rArchive.doValue(m_ScaleRect, STR("m_ScaleRect")));
    CHECK(a_rArchive.doValue(m_Znear, STR("m_Znear")));
    CHECK(a_rArchive.doValue(m_Zfar, STR("m_Zfar")));
    CHECK(a_rArchive.doValue(m_FOV, STR("m_FOV")));
    CHECK(a_rArchive.doValue(m_Aspect, STR("m_Aspect")));
    CHECK(a_rArchive.doValue(m_Distance, STR("m_Distance")));
    CHECK(a_rArchive.doValue(m_Latitude, STR("m_Latitude")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
