/*!
 *  \file    CCamera.cpp Representation of the camera in a space.
 *  \brief   Camera in a space class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Camera in a space class (source).

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
#include <Depth/include/geometry.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/geometry/CCamera.hpp>
/*==========================================================================*/
#ifndef __CCAMERA_CPP__
#define __CCAMERA_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
void CCamera::set(const CCamera& a_crInstance)
{ CALL
  m_ModelViewMatrix = a_crInstance.m_ModelViewMatrix;
  m_ProjectionMatrix = a_crInstance.m_ProjectionMatrix;
  m_DirectMatrix = a_crInstance.m_DirectMatrix;
  m_InvertMatrix = a_crInstance.m_InvertMatrix;

  m_OrthoFrustumFlag = a_crInstance.m_OrthoFrustumFlag;
  m_Position = a_crInstance.m_Position;
  m_Direction = a_crInstance.m_Direction;
  m_Up = a_crInstance.m_Up;
  m_Right = a_crInstance.m_Right;
  m_ScaleRect = a_crInstance.m_ScaleRect;
  m_Znear = a_crInstance.m_Znear;
  m_Zfar = a_crInstance.m_Zfar;
  m_FOV = a_crInstance.m_FOV;
  m_Aspect = a_crInstance.m_Aspect;

  m_Distance = a_crInstance.m_Distance;
  m_Latitude = a_crInstance.m_Latitude;
}
/*--------------------------------------------------------------------------*/
void CCamera::setOrthogonal(const CPoint3D<Treal>& a_crLookFrom/* = CPoint3D<Treal>(0.0, 0.0, 10.0) */, const CPoint3D<Treal>& a_crLookAt/* = CPoint3D<Treal>(0.0, 0.0, 0.0) */, const CRect<Treal>& a_crScaleRect/* = CRect<Treal>(-1.0, -1.0, 1.0, 1.0) */, const Treal a_cZnear/* = 1.0 */, const Treal a_cZfar/* = 10.0 */)
{ CALL
  // Check if scale rectangle is valid.
  ASSERT(((a_crScaleRect.m_A.m_X < a_crScaleRect.m_B.m_X) && (a_crScaleRect.m_A.m_Y < a_crScaleRect.m_B.m_Y)), STR("Camera scale rectangle should not be empty (ScaleRect = (%r, %r, %r, %r)).") COMMA a_crScaleRect.m_A.m_X COMMA a_crScaleRect.m_A.m_Y COMMA a_crScaleRect.m_B.m_X COMMA a_crScaleRect.m_B.m_Y);
  // Check if Z-near clipping plane is great than 0.
  ASSERT((a_cZnear > 0.0), STR("Z-near clipping plane should be great than 0 (Znear = %r).") COMMA a_cZnear);
  // Check if Z-near clipping plane is closer to camera than Z-far one.
  ASSERT((a_cZnear < a_cZfar), STR("Z-near clipping plane should be closer to camera than Z-far one (Znear = %r; Zfar = %r).") COMMA a_cZnear COMMA a_cZfar);

  m_OrthoFrustumFlag = true;

  // Find camera position.
  m_Position = a_crLookFrom;
  // Find camera direction vector.
  m_Direction = a_crLookAt - a_crLookFrom;
  // Find distance from camera to target.
  m_Distance = m_Direction.length();
  m_Latitude = 0.0;
  // Find camera 'right' vector.
  if (NMath::CMath::isEqualZero(m_Direction.m_X) && NMath::CMath::isEqualZero(m_Direction.m_Z))
    m_Right.set(1.0, 0.0, 0.0);
  else
    m_Right.set(-m_Direction.m_Z, 0.0, m_Direction.m_X);
  // Find camera 'up' vector.
  m_Up.set(CVector3D::cross(m_Right, m_Direction));

  // Normalize camera vectors.
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Projection settings.
  m_ScaleRect = a_crScaleRect;
  m_Znear = a_cZnear;
  m_Zfar = a_cZfar;
  m_FOV = 0.0;
  m_Aspect = 0.0;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes = 0;
}
/*--------------------------------------------------------------------------*/
void CCamera::setOrthogonal(const CVector3D& a_crUp, const CPoint3D<Treal>& a_crLookFrom/* = CPoint3D<Treal>(0.0, 0.0, 10.0) */, const CPoint3D<Treal>& a_crLookAt/* = CPoint3D<Treal>(0.0, 0.0, 0.0) */, const CRect<Treal>& a_crScaleRect/* = CRect<Treal>(-1.0, -1.0, 1.0, 1.0) */, const Treal a_cZnear/* = 1.0 */, const Treal a_cZfar/* = 10.0 */)
{ CALL
  // Check if scale rectangle is valid.
  ASSERT(((a_crScaleRect.m_A.m_X < a_crScaleRect.m_B.m_X) && (a_crScaleRect.m_A.m_Y < a_crScaleRect.m_B.m_Y)), STR("Camera scale rectangle should not be empty (ScaleRect = (%r, %r, %r, %r)).") COMMA a_crScaleRect.m_A.m_X COMMA a_crScaleRect.m_A.m_Y COMMA a_crScaleRect.m_B.m_X COMMA a_crScaleRect.m_B.m_Y);
  // Check if Z-near clipping plane is great than 0.
  ASSERT((a_cZnear > 0.0), STR("Z-near clipping plane should be great than 0 (Znear = %r).") COMMA a_cZnear);
  // Check if Z-near clipping plane is closer to camera than Z-far one.
  ASSERT((a_cZnear < a_cZfar), STR("Z-near clipping plane should be closer to camera than Z-far one (Znear = %r; Zfar = %r).") COMMA a_cZnear COMMA a_cZfar);

  m_OrthoFrustumFlag = true;

  // Find camera position.
  m_Position = a_crLookFrom;
  // Find camera direction vector.
  m_Direction = a_crLookAt - a_crLookFrom;
  // Find distance from camera to target.
  m_Distance = m_Direction.length();
  m_Latitude = 0.0;
  // Find camera 'right' vector.
  m_Right.set(CVector3D::cross(m_Direction, a_crUp));
  // Find camera 'up' vector.
  m_Up.set(CVector3D::cross(m_Right, m_Direction));

  // Normalize camera vectors.
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Projection settings.
  m_ScaleRect = a_crScaleRect;
  m_Znear = a_cZnear;
  m_Zfar = a_cZfar;
  m_FOV = 0.0;
  m_Aspect = 0.0;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes = 0;
}
/*--------------------------------------------------------------------------*/
void CCamera::setFrustum(const CPoint3D<Treal>& a_crLookFrom/* = CPoint3D<Treal>(0.0, 0.0, 10.0) */, const CPoint3D<Treal>& a_crLookAt/* = CPoint3D<Treal>(0.0, 0.0, 0.0) */, const CRect<Treal>& a_crScaleRect/* = CRect<Treal>(-1.0, -1.0, 1.0, 1.0) */, const Treal a_cZnear/* = 1.0 */, const Treal a_cZfar/* = 10.0 */)
{ CALL
  // Check if scale rectangle is valid.
  ASSERT(((a_crScaleRect.m_A.m_X < a_crScaleRect.m_B.m_X) && (a_crScaleRect.m_A.m_Y < a_crScaleRect.m_B.m_Y)), STR("Camera scale rectangle should not be empty (ScaleRect = (%r, %r, %r, %r)).") COMMA a_crScaleRect.m_A.m_X COMMA a_crScaleRect.m_A.m_Y COMMA a_crScaleRect.m_B.m_X COMMA a_crScaleRect.m_B.m_Y);
  // Check if Z-near clipping plane is great than 0.
  ASSERT((a_cZnear > 0.0), STR("Z-near clipping plane should be great than 0 (Znear = %r).") COMMA a_cZnear);
  // Check if Z-near clipping plane is closer to camera than Z-far one.
  ASSERT((a_cZnear < a_cZfar), STR("Z-near clipping plane should be closer to camera than Z-far one (Znear = %r; Zfar = %r).") COMMA a_cZnear COMMA a_cZfar);

  m_OrthoFrustumFlag = false;

  // Find camera position.
  m_Position = a_crLookFrom;
  // Find camera direction vector.
  m_Direction = a_crLookAt - a_crLookFrom;
  // Find distance from camera to target.
  m_Distance = m_Direction.length();
  m_Latitude = 0.0;
  // Find camera 'right' vector.
  if (NMath::CMath::isEqualZero(m_Direction.m_X) && NMath::CMath::isEqualZero(m_Direction.m_Z))
    m_Right.set(1.0, 0.0, 0.0);
  else
    m_Right.set(-m_Direction.m_Z, 0.0, m_Direction.m_X);
  // Find camera 'up' vector.
  m_Up.set(CVector3D::cross(m_Right, m_Direction));

  // Normalize camera vectors.
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Projection settings.
  m_ScaleRect = a_crScaleRect;
  m_Znear = a_cZnear;
  m_Zfar = a_cZfar;
  recalculateFOV();
  recalculateAspect();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes = 0;
}
/*--------------------------------------------------------------------------*/
void CCamera::setFrustum(const CVector3D& a_crUp, const CPoint3D<Treal>& a_crLookFrom/* = CPoint3D<Treal>(0.0, 0.0, 10.0) */, const CPoint3D<Treal>& a_crLookAt/* = CPoint3D<Treal>(0.0, 0.0, 0.0) */, const CRect<Treal>& a_crScaleRect/* = CRect<Treal>(-1.0, -1.0, 1.0, 1.0) */, const Treal a_cZnear/* = 1.0 */, const Treal a_cZfar/* = 10.0 */)
{ CALL
  // Check if scale rectangle is valid.
  ASSERT(((a_crScaleRect.m_A.m_X < a_crScaleRect.m_B.m_X) && (a_crScaleRect.m_A.m_Y < a_crScaleRect.m_B.m_Y)), STR("Camera scale rectangle should not be empty (ScaleRect = (%r, %r, %r, %r)).") COMMA a_crScaleRect.m_A.m_X COMMA a_crScaleRect.m_A.m_Y COMMA a_crScaleRect.m_B.m_X COMMA a_crScaleRect.m_B.m_Y);
  // Check if Z-near clipping plane is great than 0.
  ASSERT((a_cZnear > 0.0), STR("Z-near clipping plane should be great than 0 (Znear = %r).") COMMA a_cZnear);
  // Check if Z-near clipping plane is closer to camera than Z-far one.
  ASSERT((a_cZnear < a_cZfar), STR("Z-near clipping plane should be closer to camera than Z-far one (Znear = %r; Zfar = %r).") COMMA a_cZnear COMMA a_cZfar);

  m_OrthoFrustumFlag = false;

  // Find camera position.
  m_Position = a_crLookFrom;
  // Find camera direction vector.
  m_Direction = a_crLookAt - a_crLookFrom;
  // Find distance from camera to target.
  m_Distance = m_Direction.length();
  m_Latitude = 0.0;
  // Find camera 'right' vector.
  m_Right.set(CVector3D::cross(m_Direction, a_crUp));
  // Find camera 'up' vector.
  m_Up.set(CVector3D::cross(m_Right, m_Direction));

  // Normalize camera vectors.
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Projection settings.
  m_ScaleRect = a_crScaleRect;
  m_Znear = a_cZnear;
  m_Zfar = a_cZfar;
  recalculateFOV();
  recalculateAspect();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes = 0;
}
/*--------------------------------------------------------------------------*/
void CCamera::setPerspective(const CPoint3D<Treal>& a_crLookFrom/* = CPoint3D<Treal>(0.0, 0.0, 10.0) */, const CPoint3D<Treal>& a_crLookAt/* = CPoint3D<Treal>(0.0, 0.0, 0.0) */, const Treal a_cFOV/* = NMath::CMathConstants::PI_2 */, const Treal a_cAspect/* = 1.0 */, const Treal a_cZnear/* = 1.0 */, const Treal a_cZfar/* = 10.0 */)
{ CALL
  // Check if FOV (field of view) angle is valid.
  ASSERT(((a_cFOV > 0.0) && (a_cFOV < NMath::CMathConstants::PI)), STR("FOV (field of view) angle should be great than 0 and less than PI (FOV = %r).") COMMA a_cFOV);
  // Check if aspect ratio is valid.
  ASSERT((a_cAspect > 0.0), STR("Aspect ratio should be great than 0 (Aspect = %r).") COMMA a_cAspect);
  // Check if Z-near clipping plane is great than 0.
  ASSERT((a_cZnear > 0.0), STR("Z-near clipping plane should be great than 0 (Znear = %r).") COMMA a_cZnear);
  // Check if Z-near clipping plane is closer to camera than Z-far one.
  ASSERT((a_cZnear < a_cZfar), STR("Z-near clipping plane should be closer to camera than Z-far one (Znear = %r; Zfar = %r).") COMMA a_cZnear COMMA a_cZfar);

  m_OrthoFrustumFlag = false;

  // Find camera position.
  m_Position = a_crLookFrom;
  // Find camera direction vector.
  m_Direction = a_crLookAt - a_crLookFrom;
  // Find distance from camera to target.
  m_Distance = m_Direction.length();
  m_Latitude = 0.0;
  // Find camera 'right' vector.
  if (NMath::CMath::isEqualZero(m_Direction.m_X) && NMath::CMath::isEqualZero(m_Direction.m_Z))
    m_Right.set(1.0, 0.0, 0.0);
  else
    m_Right.set(-m_Direction.m_Z, 0.0, m_Direction.m_X);
  // Find camera 'up' vector.
  m_Up.set(CVector3D::cross(m_Right, m_Direction));

  // Normalize camera vectors.
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Projection settings.
  m_Znear = a_cZnear;
  m_Zfar = a_cZfar;
  m_FOV = a_cFOV;
  m_Aspect = a_cAspect;
  recalculateScaleRect();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes = 0;
}
/*--------------------------------------------------------------------------*/
void CCamera::setPerspective(const CVector3D& a_crUp, const CPoint3D<Treal>& a_crLookFrom/* = CPoint3D<Treal>(0.0, 0.0, 10.0) */, const CPoint3D<Treal>& a_crLookAt/* = CPoint3D<Treal>(0.0, 0.0, 0.0) */, const Treal a_cFOV/* = NMath::CMathConstants::PI_2 */, const Treal a_cAspect/* = 1.0 */, const Treal a_cZnear/* = 1.0 */, const Treal a_cZfar/* = 10.0 */)
{ CALL
  // Check if FOV (field of view) angle is valid.
  ASSERT(((a_cFOV > 0.0) && (a_cFOV < NMath::CMathConstants::PI)), STR("FOV (field of view) angle should be great than 0 and less than PI (FOV = %r).") COMMA a_cFOV);
  // Check if aspect ratio is valid.
  ASSERT((a_cAspect > 0.0), STR("Aspect ratio should be great than 0 (Aspect = %r).") COMMA a_cAspect);
  // Check if Z-near clipping plane is great than 0.
  ASSERT((a_cZnear > 0.0), STR("Z-near clipping plane should be great than 0 (Znear = %r).") COMMA a_cZnear);
  // Check if Z-near clipping plane is closer to camera than Z-far one.
  ASSERT((a_cZnear < a_cZfar), STR("Z-near clipping plane should be closer to camera than Z-far one (Znear = %r; Zfar = %r).") COMMA a_cZnear COMMA a_cZfar);

  m_OrthoFrustumFlag = false;

  // Find camera position.
  m_Position = a_crLookFrom;
  // Find camera direction vector.
  m_Direction = a_crLookAt - a_crLookFrom;
  // Find distance from camera to target.
  m_Distance = m_Direction.length();
  m_Latitude = 0.0;
  // Find camera 'right' vector.
  m_Right.set(CVector3D::cross(m_Direction, a_crUp));
  // Find camera 'up' vector.
  m_Up.set(CVector3D::cross(m_Right, m_Direction));

  // Normalize camera vectors.
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Projection settings.
  m_Znear = a_cZnear;
  m_Zfar = a_cZfar;
  m_FOV = a_cFOV;
  m_Aspect = a_cAspect;
  recalculateScaleRect();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes = 0;
}
/*--------------------------------------------------------------------------*/
void CCamera::setLookAt(const CPoint3D<Treal>& a_crLookFrom/* = CPoint3D<Treal>(0.0, 0.0, 10.0) */, const CPoint3D<Treal>& a_crLookAt/* = CPoint3D<Treal>(0.0, 0.0, 0.0) */)
{ CALL
  // Find camera position.
  m_Position = a_crLookFrom;
  // Find camera direction vector.
  m_Direction = a_crLookAt - a_crLookFrom;
  // Find distance from camera to target.
  m_Distance = m_Direction.length();
  m_Latitude = 0.0;
  // Find camera 'right' vector.
  if (NMath::CMath::isEqualZero(m_Direction.m_X) && NMath::CMath::isEqualZero(m_Direction.m_Z))
    m_Right.set(1.0, 0.0, 0.0);
  else
    m_Right.set(-m_Direction.m_Z, 0.0, m_Direction.m_X);
  // Find camera 'up' vector.
  m_Up.set(CVector3D::cross(m_Right, m_Direction));

  // Normalize camera vectors.
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::setLookAt(const CVector3D& a_crUp, const CPoint3D<Treal>& a_crLookFrom/* = CPoint3D<Treal>(0.0, 0.0, 10.0) */, const CPoint3D<Treal>& a_crLookAt/* = CPoint3D<Treal>(0.0, 0.0, 0.0) */)
{ CALL
  // Find camera position.
  m_Position = a_crLookFrom;
  // Find camera direction vector.
  m_Direction = a_crLookAt - a_crLookFrom;
  // Find distance from camera to target.
  m_Distance = m_Direction.length();
  m_Latitude = 0.0;
  // Find camera 'right' vector.
  m_Right.set(CVector3D::cross(m_Direction, a_crUp));
  // Find camera 'up' vector.
  m_Up.set(CVector3D::cross(m_Right, m_Direction));

  // Normalize camera vectors.
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::setPosition(const CPoint3D<Treal>& a_crPosition)
{ CALL
  m_Position = a_crPosition;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::setVectors(const CVector3D& a_crDirection, const CVector3D& a_crUp, const CVector3D& a_crRight)
{ CALL
  m_Direction = a_crDirection;
  m_Up = a_crUp;
  m_Right = a_crRight;

  // Normalize camera vectors.
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::setScaleRect(const CRect<Treal>& a_crScaleRect)
{ CALL
  // Check if scale rectangle is valid.
  ASSERT(((a_crScaleRect.m_A.m_X < a_crScaleRect.m_B.m_X) && (a_crScaleRect.m_A.m_Y < a_crScaleRect.m_B.m_Y)), STR("Camera scale rectangle should not be empty (ScaleRect = (%r, %r, %r, %r)).") COMMA a_crScaleRect.m_A.m_X COMMA a_crScaleRect.m_A.m_Y COMMA a_crScaleRect.m_B.m_X COMMA a_crScaleRect.m_B.m_Y);

  m_ScaleRect = a_crScaleRect;
  recalculateFOV();
  recalculateAspect();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x02 | 0x10);
}
/*--------------------------------------------------------------------------*/
void CCamera::setZclipping(const Treal& a_cZnear, const Treal& a_cZfar)
{ CALL
  // Check if Z-near clipping plane is great than 0.
  ASSERT((a_cZnear > 0.0), STR("Z-near clipping plane should be great than 0 (Znear = %r).") COMMA a_cZnear);
  // Check if Z-near clipping plane is closer to camera than Z-far one.
  ASSERT((a_cZnear < a_cZfar), STR("Z-near clipping plane should be closer to camera than Z-far one (Znear = %r; Zfar = %r).") COMMA a_cZnear COMMA a_cZfar);

  m_Znear = a_cZnear;
  m_Zfar = a_cZfar;
  recalculateFOV();
  recalculateAspect();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x02 | 0x10);
}
/*--------------------------------------------------------------------------*/
void CCamera::setZnear(const Treal& a_cZnear)
{ CALL
  // Check if Z-near clipping plane is great than 0.
  ASSERT((a_cZnear > 0.0), STR("Z-near clipping plane should be great than 0 (Znear = %r).") COMMA a_cZnear);
  // Check if Z-near clipping plane is closer to camera than Z-far one.
  ASSERT((a_cZnear < m_Zfar), STR("Z-near clipping plane should be closer to camera than Z-far one (Znear = %r; Zfar = %r).") COMMA a_cZnear COMMA m_Zfar);

  m_Znear = a_cZnear;
  recalculateFOV();
  recalculateAspect();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x02 | 0x10);
}
/*--------------------------------------------------------------------------*/
void CCamera::setZfar(const Treal& a_cZfar)
{ CALL
  // Check if Z-near clipping plane is closer to camera than Z-far one.
  ASSERT((m_Znear < a_cZfar), STR("Z-near clipping plane should be closer to camera than Z-far one (Znear = %r; Zfar = %r).") COMMA m_Znear COMMA a_cZfar);

  m_Zfar = a_cZfar;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x02 | 0x10);
}
/*--------------------------------------------------------------------------*/
void CCamera::setFOV(const Treal& a_cFOV)
{ CALL
  // Check if FOV (field of view) angle is valid.
  ASSERT(((a_cFOV > 0.0) && (a_cFOV < NMath::CMathConstants::PI)), STR("FOV (field of view) angle should be great than 0 and less than PI (FOV = %r).") COMMA a_cFOV);

  if (!m_OrthoFrustumFlag)
  {
    m_FOV = a_cFOV;
    recalculateScaleRect();

    // Clear matrix calculation flags.
    m_CalculatedMatrixes &= (0x02 | 0x10);
  }
}
/*--------------------------------------------------------------------------*/
void CCamera::setAspect(const Treal& a_cAspect)
{ CALL
  // Check if aspect ratio is valid.
  ASSERT((a_cAspect > 0.0), STR("Aspect ratio should be great than 0 (Aspect = %r).") COMMA a_cAspect);

  if (!m_OrthoFrustumFlag)
  {
    m_Aspect = a_cAspect;
    recalculateScaleRect();

    // Clear matrix calculation flags.
    m_CalculatedMatrixes &= (0x02 | 0x10);
  }
}
/*--------------------------------------------------------------------------*/
void CCamera::setLatitude(const Treal& a_cLatitude)
{ CALL
  // Check if latitude is valid.
  ASSERT(((a_cLatitude >= -NMath::CMathConstants::PI_2) && (a_cLatitude <= NMath::CMathConstants::PI_2)), STR("Camera latitude should be great than -PI/2 and less than PI/2 (latitude = %r).") COMMA a_cLatitude);

  m_Latitude = a_cLatitude;
}
/*--------------------------------------------------------------------------*/
const CMatrix4D& CCamera::getDirectMatrix() const
{ CALL
  // Calculate direct matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x01))
    calculateDirect();

  return m_DirectMatrix;
}
/*--------------------------------------------------------------------------*/
const CMatrix4D& CCamera::getModelViewMatrix() const
{ CALL
  // Calculate model view matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x02))
    calculateModelView();

  return m_ModelViewMatrix;
}
/*--------------------------------------------------------------------------*/
const CMatrix4D& CCamera::getProjectionMatrix() const
{ CALL
  // Calculate projection matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x04))
    (m_OrthoFrustumFlag) ? calculateOrtho() : calculateFrustum();

  return m_ProjectionMatrix;
}
/*--------------------------------------------------------------------------*/
const CMatrix4D& CCamera::getInvertMatrix() const
{ CALL
  // Calculate invert matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x08))
    calculateInvert();

  return m_InvertMatrix;
}
/*--------------------------------------------------------------------------*/
const CMatrix4D& CCamera::getInvertModelViewMatrix() const
{ CALL
  // Calculate invert model view matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x10))
    calculateInvertModelView();

  return m_InvertModelViewMatrix;
}
/*--------------------------------------------------------------------------*/
const CMatrix4D& CCamera::getInvertProjectionMatrix() const
{ CALL
  // Calculate invert projection matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x20))
    calculateInvertProjection();

  return m_InvertProjectionMatrix;
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::projectWorldToCamera(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  // Calculate model view matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x02))
    calculateModelView();

  m_ModelViewMatrix.transform(a_crPoint3D, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::projectWorldToCamera(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  // Calculate model view matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x02))
    calculateModelView();

  m_ModelViewMatrix.transform(a_crVector3D, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::projectWorldToCamera(const CVector4D& a_crVector4D, CVector4D& a_rResult) const
{ CALL
  // Calculate model view matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x02))
    calculateModelView();

  m_ModelViewMatrix.transform(a_crVector4D, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::projectCameraToNormalized(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  // Calculate projection matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x04))
    (m_OrthoFrustumFlag) ? calculateOrtho() : calculateFrustum();

  CVector4D result;
  CVector4D temp(a_crPoint3D.m_X, a_crPoint3D.m_Y, a_crPoint3D.m_Z, 1.0);
  m_ProjectionMatrix.transform(temp, result);
  if (!NMath::CMath::isEqualZero(result.m_W))
  {
    result.m_W = CONSTR(1.0) / result.m_W;
    a_rResult.m_X = result.m_X * result.m_W;
    a_rResult.m_Y = result.m_Y * result.m_W;
    a_rResult.m_Z = result.m_Z * result.m_W;
    return true;
  }
  else
  {
    WARNING(STR("Projection failed. Camera projection matrix is broken."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::projectCameraToNormalized(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  // Calculate projection matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x04))
    (m_OrthoFrustumFlag) ? calculateOrtho() : calculateFrustum();

  CVector4D result;
  CVector4D temp(a_crVector3D.m_X, a_crVector3D.m_Y, a_crVector3D.m_Z, 1.0);
  m_ProjectionMatrix.transform(temp, result);
  if (!NMath::CMath::isEqualZero(result.m_W))
  {
    result.m_W = CONSTR(1.0) / result.m_W;
    a_rResult.m_X = result.m_X * result.m_W;
    a_rResult.m_Y = result.m_Y * result.m_W;
    a_rResult.m_Z = result.m_Z * result.m_W;
    return true;
  }
  else
  {
    WARNING(STR("Projection failed. Camera projection matrix is broken."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::projectCameraToNormalized(const CVector4D& a_crVector4D, CVector4D& a_rResult) const
{ CALL
  // Calculate projection matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x04))
    (m_OrthoFrustumFlag) ? calculateOrtho() : calculateFrustum();

  m_ProjectionMatrix.transform(a_crVector4D, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::projectWorldToNormalized(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  // Calculate direct matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x01))
    calculateDirect();

  CVector4D result;
  CVector4D temp(a_crPoint3D.m_X, a_crPoint3D.m_Y, a_crPoint3D.m_Z, 1.0);
  m_DirectMatrix.transform(temp, result);
  if (!NMath::CMath::isEqualZero(result.m_W))
  {
    result.m_W = CONSTR(1.0) / result.m_W;
    a_rResult.m_X = result.m_X * result.m_W;
    a_rResult.m_Y = result.m_Y * result.m_W;
    a_rResult.m_Z = result.m_Z * result.m_W;
    return true;
  }
  else
  {
    WARNING(STR("Projection failed. Camera direct matrix is broken."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::projectWorldToNormalized(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  // Calculate direct matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x01))
    calculateDirect();

  CVector4D result;
  CVector4D temp(a_crVector3D.m_X, a_crVector3D.m_Y, a_crVector3D.m_Z, 1.0);
  m_DirectMatrix.transform(temp, result);
  if (!NMath::CMath::isEqualZero(result.m_W))
  {
    result.m_W = CONSTR(1.0) / result.m_W;
    a_rResult.m_X = result.m_X * result.m_W;
    a_rResult.m_Y = result.m_Y * result.m_W;
    a_rResult.m_Z = result.m_Z * result.m_W;
    return true;
  }
  else
  {
    WARNING(STR("Projection failed. Camera direct matrix is broken."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::projectWorldToNormalized(const CVector4D& a_crVector4D, CVector4D& a_rResult) const
{ CALL
  // Calculate direct matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x01))
    calculateDirect();

  m_DirectMatrix.transform(a_crVector4D, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::unprojectNormalizedToCamera(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  // Calculate invert projection matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x20))
    calculateInvertProjection();

  CVector4D result;
  CVector4D temp(a_crPoint3D.m_X, a_crPoint3D.m_Y, a_crPoint3D.m_Z, 1.0);
  m_InvertProjectionMatrix.transform(temp, result);
  if (!NMath::CMath::isEqualZero(result.m_W))
  {
    result.m_W = CONSTR(1.0) / result.m_W;
    a_rResult.m_X = result.m_X * result.m_W;
    a_rResult.m_Y = result.m_Y * result.m_W;
    a_rResult.m_Z = result.m_Z * result.m_W;
    return true;
  }
  else
  {
    WARNING(STR("Unprojection failed. Camera invert projection matrix is broken."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::unprojectNormalizedToCamera(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  // Calculate invert projection matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x20))
    calculateInvertProjection();

  CVector4D result;
  CVector4D temp(a_crVector3D.m_X, a_crVector3D.m_Y, a_crVector3D.m_Z, 1.0);
  m_InvertProjectionMatrix.transform(temp, result);
  if (!NMath::CMath::isEqualZero(result.m_W))
  {
    result.m_W = CONSTR(1.0) / result.m_W;
    a_rResult.m_X = result.m_X * result.m_W;
    a_rResult.m_Y = result.m_Y * result.m_W;
    a_rResult.m_Z = result.m_Z * result.m_W;
    return true;
  }
  else
  {
    WARNING(STR("Unprojection failed. Camera invert projection matrix is broken."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::unprojectNormalizedToCamera(const CVector4D& a_crVector4D, CVector4D& a_rResult) const
{ CALL
  // Calculate invert projection matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x20))
    calculateInvertProjection();

  m_InvertProjectionMatrix.transform(a_crVector4D, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::unprojectCameraToWorld(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  // Calculate invert model view matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x10))
    calculateInvertModelView();

  m_InvertModelViewMatrix.transform(a_crPoint3D, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::unprojectCameraToWorld(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  // Calculate invert model view matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x10))
    calculateInvertModelView();

  m_InvertModelViewMatrix.transform(a_crVector3D, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::unprojectCameraToWorld(const CVector4D& a_crVector4D, CVector4D& a_rResult) const
{ CALL
  // Calculate invert model view matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x10))
    calculateInvertModelView();

  m_InvertModelViewMatrix.transform(a_crVector4D, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::unprojectNormalizedToWorld(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  // Calculate invert matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x08))
    calculateInvert();

  CVector4D result;
  CVector4D temp(a_crPoint3D.m_X, a_crPoint3D.m_Y, a_crPoint3D.m_Z, 1.0);
  m_InvertMatrix.transform(temp, result);
  if (!NMath::CMath::isEqualZero(result.m_W))
  {
    result.m_W = CONSTR(1.0) / result.m_W;
    a_rResult.m_X = result.m_X * result.m_W;
    a_rResult.m_Y = result.m_Y * result.m_W;
    a_rResult.m_Z = result.m_Z * result.m_W;
    return true;
  }
  else
  {
    WARNING(STR("Unprojection failed. Camera invert matrix is broken."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::unprojectNormalizedToWorld(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  // Calculate invert matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x08))
    calculateInvert();

  CVector4D result;
  CVector4D temp(a_crVector3D.m_X, a_crVector3D.m_Y, a_crVector3D.m_Z, 1.0);
  m_InvertMatrix.transform(temp, result);
  if (!NMath::CMath::isEqualZero(result.m_W))
  {
    result.m_W = CONSTR(1.0) / result.m_W;
    a_rResult.m_X = result.m_X * result.m_W;
    a_rResult.m_Y = result.m_Y * result.m_W;
    a_rResult.m_Z = result.m_Z * result.m_W;
    return true;
  }
  else
  {
    WARNING(STR("Unprojection failed. Camera invert matrix is broken."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
Tbool CCamera::unprojectNormalizedToWorld(const CVector4D& a_crVector4D, CVector4D& a_rResult) const
{ CALL
  // Calculate invert matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x08))
    calculateInvert();

  m_InvertMatrix.transform(a_crVector4D, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
void CCamera::translateXYZ(const Treal a_cTranslateX, const Treal a_cTranslateY, const Treal a_cTranslateZ)
{ CALL
  m_Position.m_X += a_cTranslateX;
  m_Position.m_Y += a_cTranslateY;
  m_Position.m_Z += a_cTranslateZ;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::translateYPR(const Treal a_cTranslateYaw, const Treal a_cTranslatePitch, const Treal a_cTranslateRoll)
{ CALL
  m_Position.m_X += m_Right.m_X * a_cTranslateYaw + m_Up.m_X * a_cTranslatePitch - m_Direction.m_X * a_cTranslateRoll;
  m_Position.m_Y += m_Right.m_Y * a_cTranslateYaw + m_Up.m_Y * a_cTranslatePitch - m_Direction.m_Y * a_cTranslateRoll;
  m_Position.m_Z += m_Right.m_Z * a_cTranslateYaw + m_Up.m_Z * a_cTranslatePitch - m_Direction.m_Z * a_cTranslateRoll;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateX(const Treal a_cAngleX)
{ CALL
  CVector3D temp;
  Treal sin_angle = NMath::CMath::sin(a_cAngleX);
  Treal cos_angle = NMath::CMath::cos(a_cAngleX);

  temp = m_Direction;
  m_Direction.m_Y = cos_angle * temp.m_Y - sin_angle * temp.m_Z;
  m_Direction.m_Z = sin_angle * temp.m_Y + cos_angle * temp.m_Z;
  temp = m_Up;
  m_Up.m_Y = cos_angle * temp.m_Y - sin_angle * temp.m_Z;
  m_Up.m_Z = sin_angle * temp.m_Y + cos_angle * temp.m_Z;
  temp = m_Right;
  m_Right.m_Y = cos_angle * temp.m_Y - sin_angle * temp.m_Z;
  m_Right.m_Z = sin_angle * temp.m_Y + cos_angle * temp.m_Z;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateY(const Treal a_cAngleY)
{ CALL
  CVector3D temp;
  Treal sin_angle=NMath::CMath::sin(a_cAngleY);
  Treal cos_angle=NMath::CMath::cos(a_cAngleY);

  temp = m_Direction;
  m_Direction.m_X = cos_angle * temp.m_X + sin_angle * temp.m_Z;
  m_Direction.m_Z =-sin_angle * temp.m_X + cos_angle * temp.m_Z;
  temp = m_Up;
  m_Up.m_X = cos_angle * temp.m_X + sin_angle * temp.m_Z;
  m_Up.m_Z =-sin_angle * temp.m_X + cos_angle * temp.m_Z;
  temp = m_Right;
  m_Right.m_X = cos_angle * temp.m_X + sin_angle * temp.m_Z;
  m_Right.m_Z =-sin_angle * temp.m_X + cos_angle * temp.m_Z;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateZ(const Treal a_cAngleZ)
{ CALL
  CVector3D temp;
  Treal sin_angle = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angle = NMath::CMath::cos(a_cAngleZ);

  temp = m_Direction;
  m_Direction.m_X = cos_angle * temp.m_X - sin_angle * temp.m_Y;
  m_Direction.m_Y = sin_angle * temp.m_X + cos_angle * temp.m_Y;
  temp = m_Up;
  m_Up.m_X = cos_angle * temp.m_X - sin_angle * temp.m_Y;
  m_Up.m_Y = sin_angle * temp.m_X + cos_angle * temp.m_Y;
  temp = m_Right;
  m_Right.m_X = cos_angle * temp.m_X - sin_angle * temp.m_Y;
  m_Right.m_Y = sin_angle * temp.m_X + cos_angle * temp.m_Y;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateYaw(const Treal a_cAngleYaw)
{ CALL
  CVector3D temp(m_Right);
  Treal sin_angle = NMath::CMath::sin(a_cAngleYaw);
  Treal cos_angle = NMath::CMath::cos(a_cAngleYaw);

  m_Right.m_X = cos_angle * temp.m_X - sin_angle * m_Direction.m_X;
  m_Right.m_Y = cos_angle * temp.m_Y - sin_angle * m_Direction.m_Y;
  m_Right.m_Z = cos_angle * temp.m_Z - sin_angle * m_Direction.m_Z;
  m_Direction.m_X = cos_angle * m_Direction.m_X + sin_angle * temp.m_X;
  m_Direction.m_Y = cos_angle * m_Direction.m_Y + sin_angle * temp.m_Y;
  m_Direction.m_Z = cos_angle * m_Direction.m_Z + sin_angle * temp.m_Z;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotatePitch(const Treal a_cAnglePitch)
{ CALL
  CVector3D temp(m_Up);
  Treal sin_angle = NMath::CMath::sin(a_cAnglePitch);
  Treal cos_angle = NMath::CMath::cos(a_cAnglePitch);

  m_Up.m_X = cos_angle * temp.m_X - sin_angle * m_Direction.m_X;
  m_Up.m_Y = cos_angle * temp.m_Y - sin_angle * m_Direction.m_Y;
  m_Up.m_Z = cos_angle * temp.m_Z - sin_angle * m_Direction.m_Z;
  m_Direction.m_X = cos_angle * m_Direction.m_X + sin_angle * temp.m_X;
  m_Direction.m_Y = cos_angle * m_Direction.m_Y + sin_angle * temp.m_Y;
  m_Direction.m_Z = cos_angle * m_Direction.m_Z + sin_angle * temp.m_Z;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateRoll(const Treal a_cAngleRoll)
{ CALL
  CVector3D temp(m_Right);
  Treal sin_angle = NMath::CMath::sin(a_cAngleRoll);
  Treal cos_angle = NMath::CMath::cos(a_cAngleRoll);

  m_Right.m_X = cos_angle * temp.m_X + sin_angle * m_Up.m_X;
  m_Right.m_Y = cos_angle * temp.m_Y + sin_angle * m_Up.m_Y;
  m_Right.m_Z = cos_angle * temp.m_Z + sin_angle * m_Up.m_Z;
  m_Up.m_X = cos_angle * m_Up.m_X - sin_angle * temp.m_X;
  m_Up.m_Y = cos_angle * m_Up.m_Y - sin_angle * temp.m_Y;
  m_Up.m_Z = cos_angle * m_Up.m_Z - sin_angle * temp.m_Z;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateXYZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
 CMatrix3D matrix = CMatrix3D::rotateXYZ(a_cAngleX, a_cAngleY, a_cAngleZ);

 m_Direction = matrix.rotate(m_Direction);
 m_Up = matrix.rotate(m_Up);
 m_Right = matrix.rotate(m_Right);

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateXZY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
 CMatrix3D matrix = CMatrix3D::rotateXZY(a_cAngleX, a_cAngleY, a_cAngleZ);

 m_Direction = matrix.rotate(m_Direction);
 m_Up = matrix.rotate(m_Up);
 m_Right = matrix.rotate(m_Right);

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateYXZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
 CMatrix3D matrix = CMatrix3D::rotateYXZ(a_cAngleX, a_cAngleY, a_cAngleZ);

 m_Direction = matrix.rotate(m_Direction);
 m_Up = matrix.rotate(m_Up);
 m_Right = matrix.rotate(m_Right);

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateYZX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
 CMatrix3D matrix = CMatrix3D::rotateYZX(a_cAngleX, a_cAngleY, a_cAngleZ);

 m_Direction = matrix.rotate(m_Direction);
 m_Up = matrix.rotate(m_Up);
 m_Right = matrix.rotate(m_Right);

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateZXY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
 CMatrix3D matrix = CMatrix3D::rotateZXY(a_cAngleX, a_cAngleY, a_cAngleZ);

 m_Direction = matrix.rotate(m_Direction);
 m_Up = matrix.rotate(m_Up);
 m_Right = matrix.rotate(m_Right);

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateZYX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
 CMatrix3D matrix = CMatrix3D::rotateZYX(a_cAngleX, a_cAngleY, a_cAngleZ);

 m_Direction = matrix.rotate(m_Direction);
 m_Up = matrix.rotate(m_Up);
 m_Right = matrix.rotate(m_Right);

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateYPR(const Treal a_cAngleYaw, const Treal a_cAnglePitch, const Treal a_cAngleRoll)
{ CALL
  CVector3D temp;
  Treal sin_yaw = NMath::CMath::sin(a_cAngleYaw);
  Treal cos_yaw = NMath::CMath::cos(a_cAngleYaw);
  Treal sin_pitch = NMath::CMath::sin(a_cAnglePitch);
  Treal cos_pitch = NMath::CMath::cos(a_cAnglePitch);
  Treal sin_roll = NMath::CMath::sin(a_cAngleRoll);
  Treal cos_roll = NMath::CMath::cos(a_cAngleRoll);

  temp = m_Right;
  m_Right.m_X = cos_yaw * temp.m_X - sin_yaw * m_Direction.m_X;
  m_Right.m_Y = cos_yaw * temp.m_Y - sin_yaw * m_Direction.m_Y;
  m_Right.m_Z = cos_yaw * temp.m_Z - sin_yaw * m_Direction.m_Z;
  m_Direction.m_X = cos_yaw * m_Direction.m_X + sin_yaw * temp.m_X;
  m_Direction.m_Y = cos_yaw * m_Direction.m_Y + sin_yaw * temp.m_Y;
  m_Direction.m_Z = cos_yaw * m_Direction.m_Z + sin_yaw * temp.m_Z;
  temp = m_Up;
  m_Up.m_X =cos_pitch * temp.m_X - sin_pitch * m_Direction.m_X;
  m_Up.m_Y =cos_pitch * temp.m_Y - sin_pitch * m_Direction.m_Y;
  m_Up.m_Z =cos_pitch * temp.m_Z - sin_pitch * m_Direction.m_Z;
  m_Direction.m_X = cos_pitch * m_Direction.m_X + sin_pitch * temp.m_X;
  m_Direction.m_Y = cos_pitch * m_Direction.m_Y + sin_pitch * temp.m_Y;
  m_Direction.m_Z = cos_pitch * m_Direction.m_Z + sin_pitch * temp.m_Z;
  temp = m_Right;
  m_Right.m_X = cos_roll * temp.m_X + sin_roll * m_Up.m_X;
  m_Right.m_Y = cos_roll * temp.m_Y + sin_roll * m_Up.m_Y;
  m_Right.m_Z = cos_roll * temp.m_Z + sin_roll * m_Up.m_Z;
  m_Up.m_X = cos_roll * m_Up.m_X - sin_roll * temp.m_X;
  m_Up.m_Y = cos_roll * m_Up.m_Y - sin_roll * temp.m_Y;
  m_Up.m_Z = cos_roll * m_Up.m_Z - sin_roll * temp.m_Z;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateRoll(const Treal a_cAngleYaw, const Treal a_cAnglePitch, const Treal a_cAngleRoll)
{ CALL
  CVector3D new_pos = -m_Direction * m_Distance;
  CVector3D origin = CVector3D(m_Position) - new_pos;
  CVector3D temp;
  Treal sin_yaw=NMath::CMath::sin(a_cAngleYaw);
  Treal cos_yaw=NMath::CMath::cos(a_cAngleYaw);
  Treal sin_pitch=NMath::CMath::sin(a_cAnglePitch);
  Treal cos_pitch=NMath::CMath::cos(a_cAnglePitch);
  Treal sin_roll=NMath::CMath::sin(a_cAngleRoll);
  Treal cos_roll=NMath::CMath::cos(a_cAngleRoll);

  temp = m_Right;
  m_Right.m_X = cos_yaw * temp.m_X - sin_yaw * m_Direction.m_X;
  m_Right.m_Y = cos_yaw * temp.m_Y - sin_yaw * m_Direction.m_Y;
  m_Right.m_Z = cos_yaw * temp.m_Z - sin_yaw * m_Direction.m_Z;
  m_Direction.m_X = cos_yaw * m_Direction.m_X + sin_yaw * temp.m_X;
  m_Direction.m_Y = cos_yaw * m_Direction.m_Y + sin_yaw * temp.m_Y;
  m_Direction.m_Z = cos_yaw * m_Direction.m_Z + sin_yaw * temp.m_Z;
  new_pos = CMatrix3D::rotate(m_Up, -a_cAngleYaw).rotate(new_pos);
  temp = m_Up;
  m_Up.m_X = cos_pitch * temp.m_X - sin_pitch * m_Direction.m_X;
  m_Up.m_Y = cos_pitch * temp.m_Y - sin_pitch * m_Direction.m_Y;
  m_Up.m_Z = cos_pitch * temp.m_Z - sin_pitch * m_Direction.m_Z;
  m_Direction.m_X = cos_pitch * m_Direction.m_X + sin_pitch * temp.m_X;
  m_Direction.m_Y = cos_pitch * m_Direction.m_Y + sin_pitch * temp.m_Y;
  m_Direction.m_Z = cos_pitch * m_Direction.m_Z + sin_pitch * temp.m_Z;
  new_pos = CMatrix3D::rotate(m_Right, a_cAnglePitch).rotate(new_pos);
  temp = m_Right;
  m_Right.m_X = cos_roll * temp.m_X + sin_roll * m_Up.m_X;
  m_Right.m_Y = cos_roll * temp.m_Y + sin_roll * m_Up.m_Y;
  m_Right.m_Z = cos_roll * temp.m_Z + sin_roll * m_Up.m_Z;
  m_Up.m_X = cos_roll * m_Up.m_X - sin_roll * temp.m_X;
  m_Up.m_Y = cos_roll * m_Up.m_Y - sin_roll * temp.m_Y;
  m_Up.m_Z = cos_roll * m_Up.m_Z - sin_roll * temp.m_Z;
  new_pos = CMatrix3D::rotate(m_Direction, a_cAngleRoll).rotate(new_pos);

  origin += new_pos;
  m_Position.set(origin.m_X, origin.m_Y, origin.m_Z);

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotateWalk(const Treal a_cAngleYaw, const Treal a_cAnglePitch)
{ CALL
  // Correct pitch angle.
  Treal angle_pitch = a_cAnglePitch;
  if (m_Latitude + angle_pitch < -NMath::CMathConstants::PI_2)
    angle_pitch = -NMath::CMathConstants::PI_2 - m_Latitude;
  if (m_Latitude + angle_pitch > NMath::CMathConstants::PI_2)
    angle_pitch = NMath::CMathConstants::PI_2 - m_Latitude;

  CVector3D temp;
  Treal sin_yaw = NMath::CMath::sin(a_cAngleYaw);
  Treal cos_yaw = NMath::CMath::cos(a_cAngleYaw);
  Treal sin_pitch = NMath::CMath::sin(angle_pitch);
  Treal cos_pitch = NMath::CMath::cos(angle_pitch);

  temp = m_Direction;
  m_Direction.m_X = cos_yaw * temp.m_X + sin_yaw * temp.m_Z;
  m_Direction.m_Z =-sin_yaw * temp.m_X + cos_yaw * temp.m_Z;
  temp = m_Up;
  m_Up.m_X = cos_yaw * temp.m_X + sin_yaw * temp.m_Z;
  m_Up.m_Z =-sin_yaw * temp.m_X + cos_yaw * temp.m_Z;
  temp = m_Right;
  m_Right.m_X = cos_yaw * temp.m_X + sin_yaw * temp.m_Z;
  m_Right.m_Z =-sin_yaw * temp.m_X + cos_yaw * temp.m_Z;
  temp = m_Up;

  m_Latitude += angle_pitch;

  m_Up.m_X = cos_pitch * temp.m_X - sin_pitch * m_Direction.m_X;
  m_Up.m_Y = cos_pitch * temp.m_Y - sin_pitch * m_Direction.m_Y;
  m_Up.m_Z = cos_pitch * temp.m_Z - sin_pitch * m_Direction.m_Z;
  m_Direction.m_X = cos_pitch * m_Direction.m_X + sin_pitch * temp.m_X;
  m_Direction.m_Y = cos_pitch * m_Direction.m_Y + sin_pitch * temp.m_Y;
  m_Direction.m_Z = cos_pitch * m_Direction.m_Z + sin_pitch * temp.m_Z;

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotate(const CMatrix3D& a_crMatrix3D)
{ CALL
  m_Direction = a_crMatrix3D.rotate(m_Direction);
  m_Up = a_crMatrix3D.rotate(m_Up);
  m_Right = a_crMatrix3D.rotate(m_Right);
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotate(const CMatrix4D& a_crMatrix4D)
{ CALL
  m_Direction = a_crMatrix4D.rotate(m_Direction);
  m_Up = a_crMatrix4D.rotate(m_Up);
  m_Right = a_crMatrix4D.rotate(m_Right);
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::rotate(const CQuaternion& a_crQuaternion)
{ CALL
  m_Direction = a_crQuaternion.rotate(m_Direction);
  m_Up = a_crQuaternion.rotate(m_Up);
  m_Right = a_crQuaternion.rotate(m_Right);
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::transform(const CMatrix3D& a_crMatrix3D)
{ CALL
  m_Position = a_crMatrix3D.transform(m_Position);
  m_Direction = a_crMatrix3D.rotate(m_Direction);
  m_Up = a_crMatrix3D.rotate(m_Up);
  m_Right = a_crMatrix3D.rotate(m_Right);
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::transform(const CMatrix4D& a_crMatrix4D)
{ CALL
  m_Position = a_crMatrix4D.transform(m_Position);
  m_Direction = a_crMatrix4D.rotate(m_Direction);
  m_Up = a_crMatrix4D.rotate(m_Up);
  m_Right = a_crMatrix4D.rotate(m_Right);
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::transform(const CQuaternion& a_crQuaternion)
{ CALL
  m_Position = a_crQuaternion.rotate(m_Position);
  m_Direction = a_crQuaternion.rotate(m_Direction);
  m_Up = a_crQuaternion.rotate(m_Up);
  m_Right = a_crQuaternion.rotate(m_Right);
  m_Direction.normalize();
  m_Up.normalize();
  m_Right.normalize();

  // Clear matrix calculation flags.
  m_CalculatedMatrixes &= (0x04 | 0x20);
}
/*--------------------------------------------------------------------------*/
void CCamera::recalculateFOV()
{ CALL
  m_FOV = CONSTR(2.0) * NMath::CMath::atan2(m_ScaleRect.m_B.m_X - m_ScaleRect.m_A.m_X, CONSTR(2.0) * m_Znear);
}
/*--------------------------------------------------------------------------*/
void CCamera::recalculateAspect()
{ CALL
  m_Aspect = (m_ScaleRect.m_B.m_X - m_ScaleRect.m_A.m_X) / (m_ScaleRect.m_B.m_Y - m_ScaleRect.m_A.m_Y);
}
/*--------------------------------------------------------------------------*/
void CCamera::recalculateScaleRect()
{ CALL
  m_ScaleRect.m_A.m_X = -m_Znear * NMath::CMath::tan(CONSTR(0.5) * m_FOV);
  m_ScaleRect.m_A.m_Y = m_ScaleRect.m_A.m_X / m_Aspect;
  m_ScaleRect.m_B.m_X = -m_ScaleRect.m_A.m_X;
  m_ScaleRect.m_B.m_Y = -m_ScaleRect.m_A.m_Y;
}
/*--------------------------------------------------------------------------*/
void CCamera::calculateDirect() const
{ CALL
  // Calculate model view matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x02))
    calculateModelView();
  // Calculate projection matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x04))
    (m_OrthoFrustumFlag) ? calculateOrtho() : calculateFrustum();

  m_DirectMatrix.set(CMatrix4D::mul(m_ModelViewMatrix, m_ProjectionMatrix));
  m_CalculatedMatrixes |= 0x01;
}
/*--------------------------------------------------------------------------*/
void CCamera::calculateModelView() const
{ CALL
  m_ModelViewMatrix.m_M[0][0] = m_Right.m_X;
  m_ModelViewMatrix.m_M[0][1] = m_Up.m_X;
  m_ModelViewMatrix.m_M[0][2] =-m_Direction.m_X;
  m_ModelViewMatrix.m_M[0][3] = 0.0;
  m_ModelViewMatrix.m_M[1][0] = m_Right.m_Y;
  m_ModelViewMatrix.m_M[1][1] = m_Up.m_Y;
  m_ModelViewMatrix.m_M[1][2] =-m_Direction.m_Y;
  m_ModelViewMatrix.m_M[1][3] = 0.0;
  m_ModelViewMatrix.m_M[2][0] = m_Right.m_Z;
  m_ModelViewMatrix.m_M[2][1] = m_Up.m_Z;
  m_ModelViewMatrix.m_M[2][2] =-m_Direction.m_Z;
  m_ModelViewMatrix.m_M[2][3] = 0.0;
  m_ModelViewMatrix.m_M[3][0] =-CVector3D::dot(m_Right, m_Position);
  m_ModelViewMatrix.m_M[3][1] =-CVector3D::dot(m_Up, m_Position);
  m_ModelViewMatrix.m_M[3][2] = CVector3D::dot(m_Direction, m_Position);
  m_ModelViewMatrix.m_M[3][3] = 1.0;
  m_CalculatedMatrixes |= 0x02;
}
/*--------------------------------------------------------------------------*/
void CCamera::calculateOrtho() const
{ CALL
  Treal scale_x = CONSTR(1.0) / (m_ScaleRect.m_B.m_X - m_ScaleRect.m_A.m_X);
  Treal scale_y = CONSTR(1.0) / (m_ScaleRect.m_B.m_Y - m_ScaleRect.m_A.m_Y);
  Treal scale_z = CONSTR(1.0) / (m_Zfar - m_Znear);

  m_ProjectionMatrix.m_M[0][0] = CONSTR(2.0) * scale_x;
  m_ProjectionMatrix.m_M[0][1] = 0.0;
  m_ProjectionMatrix.m_M[0][2] = 0.0;
  m_ProjectionMatrix.m_M[0][3] = 0.0;
  m_ProjectionMatrix.m_M[1][0] = 0.0;
  m_ProjectionMatrix.m_M[1][1] = CONSTR(2.0) * scale_y;
  m_ProjectionMatrix.m_M[1][2] = 0.0;
  m_ProjectionMatrix.m_M[1][3] = 0.0;
  m_ProjectionMatrix.m_M[2][0] = 0.0;
  m_ProjectionMatrix.m_M[2][1] = 0.0;
  m_ProjectionMatrix.m_M[2][2] = CONSTR(-2.0) * scale_z;
  m_ProjectionMatrix.m_M[2][3] = 0.0;
  m_ProjectionMatrix.m_M[3][0] =-(m_ScaleRect.m_B.m_X + m_ScaleRect.m_A.m_X) * scale_x;
  m_ProjectionMatrix.m_M[3][1] =-(m_ScaleRect.m_B.m_Y + m_ScaleRect.m_A.m_Y) * scale_y;
  m_ProjectionMatrix.m_M[3][2] =-(m_Zfar + m_Znear) * scale_z;
  m_ProjectionMatrix.m_M[3][3] = 1.0;
  m_CalculatedMatrixes |= 0x04;
}
/*--------------------------------------------------------------------------*/
void CCamera::calculateFrustum() const
{ CALL
  Treal scale_x = CONSTR(1.0) / (m_ScaleRect.m_B.m_X - m_ScaleRect.m_A.m_X);
  Treal scale_y = CONSTR(1.0) / (m_ScaleRect.m_B.m_Y - m_ScaleRect.m_A.m_Y);
  Treal scale_z = CONSTR(1.0) / (m_Zfar - m_Znear);

  m_ProjectionMatrix.m_M[0][0] = CONSTR(2.0) * m_Znear * scale_x;
  m_ProjectionMatrix.m_M[0][1] = 0.0;
  m_ProjectionMatrix.m_M[0][2] = 0.0;
  m_ProjectionMatrix.m_M[0][3] = 0.0;
  m_ProjectionMatrix.m_M[1][0] = 0.0;
  m_ProjectionMatrix.m_M[1][1] = CONSTR(2.0) * m_Znear * scale_y;
  m_ProjectionMatrix.m_M[1][2] = 0.0;
  m_ProjectionMatrix.m_M[1][3] = 0.0;
  m_ProjectionMatrix.m_M[2][0] = 0.0;
  m_ProjectionMatrix.m_M[2][1] = 0.0;
  m_ProjectionMatrix.m_M[2][2] =-(m_Zfar + m_Znear) * scale_z;
  m_ProjectionMatrix.m_M[2][3] =-1.0;
  m_ProjectionMatrix.m_M[3][0] = (m_ScaleRect.m_B.m_X + m_ScaleRect.m_A.m_X) * scale_x;
  m_ProjectionMatrix.m_M[3][1] = (m_ScaleRect.m_B.m_Y + m_ScaleRect.m_A.m_Y) * scale_y;
  m_ProjectionMatrix.m_M[3][2] = CONSTR(-2.0) * m_Zfar * m_Znear * scale_z;
  m_ProjectionMatrix.m_M[3][3] = 0.0;
  m_CalculatedMatrixes |= 0x04;
}
/*--------------------------------------------------------------------------*/
void CCamera::calculateInvert() const
{ CALL
  // Calculate model view matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x02))
    calculateModelView();
  // Calculate projection matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x04))
    (m_OrthoFrustumFlag) ? calculateOrtho() : calculateFrustum();

  m_InvertMatrix.set(CMatrix4D::invert(CMatrix4D::mul(m_ProjectionMatrix, m_ModelViewMatrix)));
  m_CalculatedMatrixes |= 0x08;
}
/*--------------------------------------------------------------------------*/
void CCamera::calculateInvertModelView() const
{ CALL
  // Calculate model view matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x02))
    calculateModelView();

  m_InvertModelViewMatrix.set(CMatrix4D::invert(m_ModelViewMatrix));
  m_CalculatedMatrixes |= 0x10;
}
/*--------------------------------------------------------------------------*/
void CCamera::calculateInvertProjection() const
{ CALL
  // Calculate projection matrix if necessary.
  if (!(m_CalculatedMatrixes & 0x04))
    (m_OrthoFrustumFlag) ? calculateOrtho() : calculateFrustum();

  m_InvertProjectionMatrix.set(CMatrix4D::invert(m_ProjectionMatrix));
  m_CalculatedMatrixes |= 0x20;
}
/*--------------------------------------------------------------------------*/
void CCamera::swap(CCamera& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_CalculatedMatrixes, a_rInstance.m_CalculatedMatrixes);
  NAlgorithms::NCommon::swap(m_DirectMatrix, a_rInstance.m_DirectMatrix);
  NAlgorithms::NCommon::swap(m_ModelViewMatrix, a_rInstance.m_ModelViewMatrix);
  NAlgorithms::NCommon::swap(m_ProjectionMatrix, a_rInstance.m_ProjectionMatrix);
  NAlgorithms::NCommon::swap(m_InvertMatrix, a_rInstance.m_InvertMatrix);
  NAlgorithms::NCommon::swap(m_InvertModelViewMatrix, a_rInstance.m_InvertModelViewMatrix);
  NAlgorithms::NCommon::swap(m_InvertProjectionMatrix, a_rInstance.m_InvertProjectionMatrix);
  NAlgorithms::NCommon::swap(m_OrthoFrustumFlag, a_rInstance.m_OrthoFrustumFlag);
  NAlgorithms::NCommon::swap(m_Position, a_rInstance.m_Position);
  NAlgorithms::NCommon::swap(m_Direction, a_rInstance.m_Direction);
  NAlgorithms::NCommon::swap(m_Up, a_rInstance.m_Up);
  NAlgorithms::NCommon::swap(m_Right, a_rInstance.m_Right);
  NAlgorithms::NCommon::swap(m_ScaleRect, a_rInstance.m_ScaleRect);
  NAlgorithms::NCommon::swap(m_Znear, a_rInstance.m_Znear);
  NAlgorithms::NCommon::swap(m_Zfar, a_rInstance.m_Zfar);
  NAlgorithms::NCommon::swap(m_FOV, a_rInstance.m_FOV);
  NAlgorithms::NCommon::swap(m_Aspect, a_rInstance.m_Aspect);
  NAlgorithms::NCommon::swap(m_Distance, a_rInstance.m_Distance);
  NAlgorithms::NCommon::swap(m_Latitude, a_rInstance.m_Latitude);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
