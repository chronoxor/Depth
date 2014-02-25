/*!
 *  \file    CCamera.hpp Representation of the camera in a space.
 *  \brief   Camera in a space class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Camera in a space class.

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
#ifndef __CCAMERA_HPP__
#define __CCAMERA_HPP__
/*==========================================================================*/
#include <Depth/include/geometry.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CRect.hpp>
#include <Depth/include/geometry/CPoint3D.hpp>
#include <Depth/include/geometry/CVector3D.hpp>
#include <Depth/include/geometry/CMatrix3D.hpp>
#include <Depth/include/geometry/CMatrix4D.hpp>
#include <Depth/include/geometry/CQuaternion.hpp>
#include <Depth/include/math/CMath.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Camera in a space class.
/*!
    Class represents 3-dimension camera in a space. Camera is used to  project
    3-dimension points in a space into the 3-dimension normalized points on  a
    camera plane. For this purpose camera provides two  types  of  matrixes  -
    model view and projection. Camera also gives an ability to perform  invert
    transformation from the  normalized  camera  plane  coordinates  into  the
    3-dimension space ones.

    CCamera class could be used in a three modes:
    \li <b>Orthogonal:</b> Camera   without  perspective   projection.  It  is
        prepared with scale rectangle and z-near, z-far planes.
    \li <b>Frustum:</b> Camera with perspective projection. Camera is prepared
        with scale rectangle and z-near, z-far planes.
    \li <b>Perspective:</b> Camera  with  perspective  projection.  Camera  is
        prepared with FOV angle, aspect ratio and z-near, z-far planes.

    For all modes it is possible  to  provide  additional  camera  parameters:
    camera position, camera direction and camera roll (through up vector).
*/
class GEOMETRY_API CCamera
{
  //! Type for MConceptDepthType constraint checking.
  typedef CCamera TDepthCheckType;

  // Check CCamera class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Default camera is placed into the position (0, 0, 10) and looks  to  the
      origin  of  the  coordinate  system (0, 0, 0).  Camera's  up  vector  is
      (0, 1, 0).  Default  camera   is   orthogonal   (with   scale  rectangle
      (-1, -1, 1, 1)) or perspective (with FOV =  PI/2,  aspect  ratio  =  1),
      z-near clipping plane = 1 and z-far clipping plane = 10.

      With  the  default  camera  settings  it  is  also   possible   to   see
      1-width-height-depth object in the coordinate system origin.

      \param a_cOrthogonal - Orthogonal camera flag (default is false).
  */
  CCamera(const Tbool a_cOrthogonal = false);
  //! Initialize orthogonal/frustum camera with automatic calculation of the 'up' vector.
  /*!
      \param a_cOrthogonal - Orthogonal camera flag.
      \param a_crLookFrom - Constant reference to the 'look from' point in a space.
      \param a_crLookAt - Constant reference to the 'look at' point in a space.
      \param a_crScaleRect - Constant reference to the camera scale rectangle.
      \param a_cZnear - Z-near clipping plane.
      \param a_cZfar - Z-far clipping plane.

      \see NDepth::NGeometry::CCamera::setOrthogonal()
      \see NDepth::NGeometry::CCamera::setFrustum()
  */
  CCamera(const Tbool a_cOrthogonal, const CPoint3D<Treal>& a_crLookFrom, const CPoint3D<Treal>& a_crLookAt, const CRect<Treal>& a_crScaleRect, const Treal a_cZnear, const Treal a_cZfar);
  //! Initialize orthogonal/frustum camera with provided 'up' vector.
  /*!
      \param a_cOrthogonal - Orthogonal camera flag.
      \param a_crLookFrom - Constant reference to the 'look from' point in a space.
      \param a_crLookAt - Constant reference to the 'look at' point in a space.
      \param a_crUp - Constant reference to the 'up' camera vector in a space.
      \param a_crScaleRect - Constant reference to the camera scale rectangle.
      \param a_cZnear - Z-near clipping plane.
      \param a_cZfar - Z-far clipping plane.
  */
  CCamera(const Tbool a_cOrthogonal, const CPoint3D<Treal>& a_crLookFrom, const CPoint3D<Treal>& a_crLookAt, const CVector3D& a_crUp, const CRect<Treal>& a_crScaleRect, const Treal a_cZnear, const Treal a_cZfar);
  //! Initialize perspective camera with automatic calculation of the 'up' vector.
  /*!
      \param a_crLookFrom - Constant reference to the 'look from' point in a space.
      \param a_crLookAt - Constant reference to the 'look at' point in a space.
      \param a_cFOV - Camera FOV (field of view) angle.
      \param a_cAspect - Camera aspect ratio.
      \param a_cZnear - Z-near clipping plane.
      \param a_cZfar - Z-far clipping plane.
  */
  CCamera(const CPoint3D<Treal>& a_crLookFrom, const CPoint3D<Treal>& a_crLookAt, const Treal a_cFOV, const Treal a_cAspect, const Treal a_cZnear, const Treal a_cZfar);
  //! Initialize perspective camera with provided 'up' vector.
  /*!
      \param a_crLookFrom - Constant reference to the 'look from' point in a space.
      \param a_crLookAt - Constant reference to the 'look at' point in a space.
      \param a_crUp - Constant reference to the 'up' camera vector in a space.
      \param a_cFOV - Camera FOV (field of view) angle.
      \param a_cAspect - Camera aspect ratio.
      \param a_cZnear - Z-near clipping plane.
      \param a_cZfar - Z-far clipping plane.
  */
  CCamera(const CPoint3D<Treal>& a_crLookFrom, const CPoint3D<Treal>& a_crLookAt, const CVector3D& a_crUp, const Treal a_cFOV, const Treal a_cAspect, const Treal a_cZnear, const Treal a_cZfar);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCamera class.
  */
  CCamera(const CCamera& a_crInstance);
  //! Class destructor.
 ~CCamera();

  //! Operator: Assign another CCamera class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCamera class.
      \return Reference to the current class instance.
  */
  CCamera& operator = (const CCamera& a_crInstance);

  //! Set another CCamera class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CCamera class.
  */
  void set(const CCamera& a_crInstance);

  //! Is camera works in the orthogonal mode.
  /*!
      \return true  - if camera works in the orthogonal mode. \n
              false - if camera works in the frustum mode. \n
  */
  Tbool isOrthogonal() const;
  //! Is camera works in the frustum mode.
  /*!
      \return true  - if camera works in the frustum mode. \n
              false - if camera works in the orthogonal mode. \n
  */
  Tbool isFrustum() const;

  //! Set orthogonal camera with automatic calculation of the 'up' vector.
  /*!
      \param a_crLookFrom - Constant reference to the 'look from' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 10.0)).
      \param a_crLookAt - Constant reference to the 'look at' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 0.0)).
      \param a_crScaleRect - Constant reference to the camera scale rectangle (default is NDepth::NGeometry::CRect<Treal>(-1.0, -1.0, 1.0, 1.0)).
      \param a_cZnear - Z-near clipping plane (default is 1.0).
      \param a_cZfar - Z-far clipping plane (default is 10.0).
  */
  void setOrthogonal(const CPoint3D<Treal>& a_crLookFrom = CPoint3D<Treal>(0.0, 0.0, 10.0), const CPoint3D<Treal>& a_crLookAt = CPoint3D<Treal>(0.0, 0.0, 0.0), const CRect<Treal>& a_crScaleRect = CRect<Treal>(-1.0, -1.0, 1.0, 1.0), const Treal a_cZnear = 1.0, const Treal a_cZfar = 10.0);
  //! Set orthogonal camera with provided 'up' vector.
  /*!
      \param a_crUp - Constant reference to the 'up' camera vector in a space.
      \param a_crLookFrom - Constant reference to the 'look from' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 10.0)).
      \param a_crLookAt - Constant reference to the 'look at' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 0.0)).
      \param a_crScaleRect - Constant reference to the camera scale rectangle (default is NDepth::NGeometry::CRect<Treal>(-1.0, -1.0, 1.0, 1.0)).
      \param a_cZnear - Z-near clipping plane (default is 1.0).
      \param a_cZfar - Z-far clipping plane (default is 10.0).
  */
  void setOrthogonal(const CVector3D& a_crUp, const CPoint3D<Treal>& a_crLookFrom = CPoint3D<Treal>(0.0, 0.0, 10.0), const CPoint3D<Treal>& a_crLookAt = CPoint3D<Treal>(0.0, 0.0, 0.0), const CRect<Treal>& a_crScaleRect = CRect<Treal>(-1.0, -1.0, 1.0, 1.0), const Treal a_cZnear = 1.0, const Treal a_cZfar = 10.0);

  //! Set frustum camera with automatic calculation of the 'up' vector.
  /*!
      \param a_crLookFrom - Constant reference to the 'look from' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 10.0)).
      \param a_crLookAt - Constant reference to the 'look at' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 0.0)).
      \param a_crScaleRect - Constant reference to the camera scale rectangle (default is NDepth::NGeometry::CRect<Treal>(-1.0, -1.0, 1.0, 1.0)).
      \param a_cZnear - Z-near clipping plane (default is 1.0).
      \param a_cZfar - Z-far clipping plane (default is 10.0).
  */
  void setFrustum(const CPoint3D<Treal>& a_crLookFrom = CPoint3D<Treal>(0.0, 0.0, 10.0), const CPoint3D<Treal>& a_crLookAt = CPoint3D<Treal>(0.0, 0.0, 0.0), const CRect<Treal>& a_crScaleRect = CRect<Treal>(-1.0, -1.0, 1.0, 1.0), const Treal a_cZnear = 1.0, const Treal a_cZfar = 10.0);
  //! Set frustum camera with provided 'up' vector.
  /*!
      \param a_crUp - Constant reference to the 'up' camera vector in a space.
      \param a_crLookFrom - Constant reference to the 'look from' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 10.0)).
      \param a_crLookAt - Constant reference to the 'look at' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 0.0)).
      \param a_crScaleRect - Constant reference to the camera scale rectangle (default is NDepth::NGeometry::CRect<Treal>(-1.0, -1.0, 1.0, 1.0)).
      \param a_cZnear - Z-near clipping plane (default is 1.0).
      \param a_cZfar - Z-far clipping plane (default is 10.0).
  */
  void setFrustum(const CVector3D& a_crUp, const CPoint3D<Treal>& a_crLookFrom = CPoint3D<Treal>(0.0, 0.0, 10.0), const CPoint3D<Treal>& a_crLookAt = CPoint3D<Treal>(0.0, 0.0, 0.0), const CRect<Treal>& a_crScaleRect = CRect<Treal>(-1.0, -1.0, 1.0, 1.0), const Treal a_cZnear = 1.0, const Treal a_cZfar = 10.0);

  //! Set perspective camera with automatic calculation of the 'up' vector.
  /*!
      \param a_crLookFrom - Constant reference to the 'look from' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 10.0)).
      \param a_crLookAt - Constant reference to the 'look at' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 0.0)).
      \param a_cFOV - Camera FOV (field of view) angle (default is NDepth::Math::CMathConstants::PI_2).
      \param a_cAspect - Camera aspect ratio (default is 1.0).
      \param a_cZnear - Z-near clipping plane (default is 1.0).
      \param a_cZfar - Z-far clipping plane (default is 10.0).
  */
  void setPerspective(const CPoint3D<Treal>& a_crLookFrom = CPoint3D<Treal>(0.0, 0.0, 10.0), const CPoint3D<Treal>& a_crLookAt = CPoint3D<Treal>(0.0, 0.0, 0.0), const Treal a_cFOV = NMath::CMathConstants::PI_2, const Treal a_cAspect = 1.0, const Treal a_cZnear = 1.0, const Treal a_cZfar = 10.0);
  //! Set perspective camera with provided 'up' vector.
  /*!
      \param a_crUp - Constant reference to the 'up' camera vector in a space.
      \param a_crLookFrom - Constant reference to the 'look from' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 10.0)).
      \param a_crLookAt - Constant reference to the 'look at' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 0.0)).
      \param a_cFOV - Camera FOV (field of view) angle (default is NDepth::Math::CMathConstants::PI_2).
      \param a_cAspect - Camera aspect ratio (default is 1.0).
      \param a_cZnear - Z-near clipping plane (default is 1.0).
      \param a_cZfar - Z-far clipping plane (default is 10.0).
  */
  void setPerspective(const CVector3D& a_crUp, const CPoint3D<Treal>& a_crLookFrom = CPoint3D<Treal>(0.0, 0.0, 10.0), const CPoint3D<Treal>& a_crLookAt = CPoint3D<Treal>(0.0, 0.0, 0.0), const Treal a_cFOV = NMath::CMathConstants::PI_2, const Treal a_cAspect = 1.0, const Treal a_cZnear = 1.0, const Treal a_cZfar = 10.0);

  //! Set 'look at' camera with automatic calculation of the 'up' vector.
  /*!
      \param a_crLookFrom - Constant reference to the 'look from' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 10.0)).
      \param a_crLookAt - Constant reference to the 'look at' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 0.0)).
  */
  void setLookAt(const CPoint3D<Treal>& a_crLookFrom = CPoint3D<Treal>(0.0, 0.0, 10.0), const CPoint3D<Treal>& a_crLookAt = CPoint3D<Treal>(0.0, 0.0, 0.0));
  //! Set 'look at' camera with provided 'up' vector.
  /*!
      \param a_crUp - Constant reference to the 'up' camera vector in a space.
      \param a_crLookFrom - Constant reference to the 'look from' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 10.0)).
      \param a_crLookAt - Constant reference to the 'look at' point in a space (default is NDepth::NGeometry::CPoint3D<Treal>(0.0, 0.0, 0.0)).
  */
  void setLookAt(const CVector3D& a_crUp, const CPoint3D<Treal>& a_crLookFrom = CPoint3D<Treal>(0.0, 0.0, 10.0), const CPoint3D<Treal>& a_crLookAt = CPoint3D<Treal>(0.0, 0.0, 0.0));

  //! Set camera position.
  /*!
      \param a_crPosition - Constant reference to the camera position point.
  */
  void setPosition(const CPoint3D<Treal>& a_crPosition);
  //! Get camera position.
  /*!
      \return Constant reference to the camera position point.
  */
  const CPoint3D<Treal>& getPosition() const;

  //! Set camera vectors.
  /*!
      \param a_crDirection - Constant reference to the camera 'direction' vector.
      \param a_crUp - Constant reference to the camera 'up' vector.
      \param a_crRight - Constant reference to the camera 'right' vector.
  */
  void setVectors(const CVector3D& a_crDirection, const CVector3D& a_crUp, const CVector3D& a_crRight);
  //! Get camera vectors.
  /*!
      \param a_rDirection - Reference to the returning camera 'direction' vector.
      \param a_rUp - Reference to the returning camera 'up' vector.
      \param a_rRight - Reference to the returning camera 'right' vector.
  */
  void getVectors(CVector3D& a_rDirection, CVector3D& a_rUp, CVector3D& a_rRight) const;

  //! Get camera 'direction' vector.
  /*!
      \return Constant reference to the camera 'direction' vector.
  */
  const CVector3D& getDirection() const;
  //! Get camera 'up' vector.
  /*!
      \return Constant reference to the camera 'up' vector.
  */
  const CVector3D& getUp() const;
  //! Get camera 'right' vector.
  /*!
      \return Constant reference to the camera 'right' vector.
  */
  const CVector3D& getRight() const;

  //! Set camera scale rectangle.
  /*!
      \param a_crScaleRect - Constant reference to the camera scale rectangle.
  */
  void setScaleRect(const CRect<Treal>& a_crScaleRect);
  //! Get camera scale rectangle.
  /*!
      \return Constant reference to the camera scale rectangle.
  */
  const CRect<Treal>& getScaleRect() const;

  //! Set camera clipping planes (Z-near and Z-far).
  /*!
      \param a_cZnear - Z-near clipping plane.
      \param a_cZfar - Z-far clipping plane.
  */
  void setZclipping(const Treal& a_cZnear, const Treal& a_cZfar);

  //! Set camera Z-near clipping plane.
  /*!
      \param a_cZnear - Z-near clipping plane.
  */
  void setZnear(const Treal& a_cZnear);
  //! Get camera Z-near clipping plane.
  /*!
      \return Camera Z-near clipping plane.
  */
  Treal getZnear() const;

  //! Set camera Z-far clipping plane.
  /*!
      \param a_cZfar - Z-far clipping plane.
  */
  void setZfar(const Treal& a_cZfar);
  //! Get camera Z-far clipping plane.
  /*!
      \return Camera Z-far clipping plane.
  */
  Treal getZfar() const;

  //! Set camera FOV (field of view) angle.
  /*!
      \param a_cFOV - Camera FOV (field of view) angle.
  */
  void setFOV(const Treal& a_cFOV);
  //! Get camera FOV (field of view) angle.
  /*!
      \return Camera FOV (field of view) angle.
  */
  Treal getFOV() const;

  //! Set camera aspect ratio.
  /*!
      \param a_cAspect - Camera aspect ratio.
  */
  void setAspect(const Treal& a_cAspect);
  //! Get camera aspect ratio.
  /*!
      \return Camera aspect ratio.
  */
  Treal getAspect() const;

  //! Set camera distance to the observing target.
  /*!
      \param a_cDistance - Camera distance to the observing target.
  */
  void setDistance(const Treal& a_cDistance);
  //! Get camera distance to the observing target.
  /*!
      \return Camera distance to the observing target.
  */
  Treal getDistance() const;

  //! Set camera current latitude value.
  /*!
      \param a_cLatitude - Camera current latitude value.
  */
  void setLatitude(const Treal& a_cLatitude);
  //! Get camera current latitude value.
  /*!
      \return Camera current latitude value.
  */
  Treal getLatitude() const;

  //! Get camera direct matrix.
  /*!
      \return Constant reference to the camera direct matrix.
  */
  const CMatrix4D& getDirectMatrix() const;
  //! Get camera model view matrix.
  /*!
      \return Constant reference to the camera model view matrix.
  */
  const CMatrix4D& getModelViewMatrix() const;
  //! Get camera projection matrix.
  /*!
      \return Constant reference to the camera projection matrix.
  */
  const CMatrix4D& getProjectionMatrix() const;
  //! Get camera invert matrix.
  /*!
      \return Constant reference to the camera invert matrix.
  */
  const CMatrix4D& getInvertMatrix() const;
  //! Get camera invert model view matrix.
  /*!
      \return Constant reference to the camera invert model view matrix.
  */
  const CMatrix4D& getInvertModelViewMatrix() const;
  //! Get camera invert projection matrix.
  /*!
      \return Constant reference to the camera invert projection matrix.
  */
  const CMatrix4D& getInvertProjectionMatrix() const;

  //! Project point from world coordinate system into the camera coordinate system.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result projected instance of the CPoint3D class.
      \return true  - if projection operation was successful. \n
              false - if projection operation was not successful. \n
  */
  Tbool projectWorldToCamera(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Project vector from world coordinate system into the camera coordinate system.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result projected instance of the CVector3D class.
      \return true  - if projection operation was successful. \n
              false - if projection operation was not successful. \n
  */
  Tbool projectWorldToCamera(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;
  //! Project extended vector from world coordinate system into the camera coordinate system.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_rResult - Reference to the result projected instance of the CVector4D class.
      \return true  - if projection operation was successful. \n
              false - if projection operation was not successful. \n
  */
  Tbool projectWorldToCamera(const CVector4D& a_crVector4D, CVector4D& a_rResult) const;

  //! Project point from camera coordinate system into the normalized camera coordinate system.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result projected instance of the CPoint3D class.
      \return true  - if projection operation was successful. \n
              false - if projection operation was not successful. \n
  */
  Tbool projectCameraToNormalized(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Project vector from camera coordinate system into the normalized camera coordinate system.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result projected instance of the CVector3D class.
      \return true  - if projection operation was successful. \n
              false - if projection operation was not successful. \n
  */
  Tbool projectCameraToNormalized(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;
  //! Project extended vector from camera coordinate system into the normalized camera coordinate system.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_rResult - Reference to the result projected instance of the CVector4D class.
      \return true  - if projection operation was successful. \n
              false - if projection operation was not successful. \n
  */
  Tbool projectCameraToNormalized(const CVector4D& a_crVector4D, CVector4D& a_rResult) const;

  //! Project point from world coordinate system into the normalized camera coordinate system.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result projected instance of the CPoint3D class.
      \return true  - if projection operation was successful. \n
              false - if projection operation was not successful. \n
  */
  Tbool projectWorldToNormalized(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Project vector from world coordinate system into the normalized camera coordinate system.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result projected instance of the CVector3D class.
      \return true  - if projection operation was successful. \n
              false - if projection operation was not successful. \n
  */
  Tbool projectWorldToNormalized(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;
  //! Project extended vector from world coordinate system into the normalized camera coordinate system.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_rResult - Reference to the result projected instance of the CVector4D class.
      \return true  - if projection operation was successful. \n
              false - if projection operation was not successful. \n
  */
  Tbool projectWorldToNormalized(const CVector4D& a_crVector4D, CVector4D& a_rResult) const;

  //! Unproject point from the normalized camera coordinate system into the camera coordinate system.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result projected instance of the CPoint3D class.
      \return true  - if unprojection operation was successful. \n
              false - if unprojection operation was not successful. \n
  */
  Tbool unprojectNormalizedToCamera(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Unproject vector from the normalized camera coordinate system into the camera coordinate system.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result projected instance of the CVector3D class.
      \return true  - if unprojection operation was successful. \n
              false - if unprojection operation was not successful. \n
  */
  Tbool unprojectNormalizedToCamera(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;
  //! Unproject extended vector from the normalized camera coordinate system into the camera coordinate system.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_rResult - Reference to the result projected instance of the CVector4D class.
      \return true  - if unprojection operation was successful. \n
              false - if unprojection operation was not successful. \n
  */
  Tbool unprojectNormalizedToCamera(const CVector4D& a_crVector4D, CVector4D& a_rResult) const;

  //! Unproject point from the camera coordinate system into the world coordinate system.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result projected instance of the CPoint3D class.
      \return true  - if unprojection operation was successful. \n
              false - if unprojection operation was not successful. \n
  */
  Tbool unprojectCameraToWorld(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Unproject vector from the camera coordinate system into the world coordinate system.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result projected instance of the CVector3D class.
      \return true  - if unprojection operation was successful. \n
              false - if unprojection operation was not successful. \n
  */
  Tbool unprojectCameraToWorld(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;
  //! Unproject extended vector from the camera coordinate system into the world coordinate system.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_rResult - Reference to the result projected instance of the CVector4D class.
      \return true  - if unprojection operation was successful. \n
              false - if unprojection operation was not successful. \n
  */
  Tbool unprojectCameraToWorld(const CVector4D& a_crVector4D, CVector4D& a_rResult) const;

  //! Unproject point from the normalized camera coordinate system into the world coordinate system.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result projected instance of the CPoint3D class.
      \return true  - if unprojection operation was successful. \n
              false - if unprojection operation was not successful. \n
  */
  Tbool unprojectNormalizedToWorld(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Unproject vector from the normalized camera coordinate system into the world coordinate system.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result projected instance of the CVector3D class.
      \return true  - if unprojection operation was successful. \n
              false - if unprojection operation was not successful. \n
  */
  Tbool unprojectNormalizedToWorld(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;
  //! Unproject extended vector from the normalized camera coordinate system into the world coordinate system.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_rResult - Reference to the result projected instance of the CVector4D class.
      \return true  - if unprojection operation was successful. \n
              false - if unprojection operation was not successful. \n
  */
  Tbool unprojectNormalizedToWorld(const CVector4D& a_crVector4D, CVector4D& a_rResult) const;

  //! Translate camera in a space by XYZ axis.
  /*!
      \param a_cTranslateX - Translate value for the X coordinate.
      \param a_cTranslateY - Translate value for the Y coordinate.
      \param a_cTranslateZ - Translate value for the Z coordinate.
  */
  void translateXYZ(const Treal a_cTranslateX, const Treal a_cTranslateY, const Treal a_cTranslateZ);
  //! Translate camera in yaw-pitch-roll system.
  /*!
      \param a_cTranslateYaw - Translate value for the yaw axis.
      \param a_cTranslatePitch - Translate value for the pitch axis.
      \param a_cTranslateRoll - Translate value for the yaw axis.
  */
  void translateYPR(const Treal a_cTranslateYaw, const Treal a_cTranslatePitch, const Treal a_cTranslateRoll);

  //! Rotate camera in a space by X axis.
  /*!
      \param a_cAngleX - Rotate angle by X axis.
  */
  void rotateX(const Treal a_cAngleX);
  //! Rotate camera in a space by Y axis.
  /*!
      \param a_cAngleY - Rotate angle by Y axis.
  */
  void rotateY(const Treal a_cAngleY);
  //! Rotate camera in a space by Z axis.
  /*!
      \param a_cAngleZ - Rotate angle by Z axis.
  */
  void rotateZ(const Treal a_cAngleZ);

  //! Rotate camera in yaw-pitch-roll system by yaw axis.
  /*!
      \param a_cAngleYaw - Rotating angle in xOz plane (yaw angle).
  */
  void rotateYaw(const Treal a_cAngleYaw);
  //! Rotate camera in yaw-pitch-roll system by pitch axis.
  /*!
      \param a_cAnglePitch - Rotating angle in yOZ plane (pitch angle).
  */
  void rotatePitch(const Treal a_cAnglePitch);
  //! Rotate camera in yaw-pitch-roll system by roll axis.
  /*!
      \param a_cAngleRoll - Rotating angle in xOy plane (roll angle).
  */
  void rotateRoll(const Treal a_cAngleRoll);

  //! Rotate camera in a space by axis in order XYZ.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
  */
  void rotateXYZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Rotate camera in a space by axis in order XZY.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
  */
  void rotateXZY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Rotate camera in a space by axis in order YXZ.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
  */
  void rotateYXZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Rotate camera in a space by axis in order YZX.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
  */
  void rotateYZX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Rotate camera in a space by axis in order ZXY.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
  */
  void rotateZXY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Rotate camera in a space by axis in order ZYX.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
  */
  void rotateZYX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);

  //! Rotate camera in yaw-pitch-roll system.
  /*!
      \param a_cAngleYaw - Rotating angle in xOz plane (yaw angle).
      \param a_cAnglePitch - Rotating angle in yOZ plane (pitch angle).
      \param a_cAngleRoll - Rotating angle in xOy plane (roll angle).
  */
  void rotateYPR(const Treal a_cAngleYaw, const Treal a_cAnglePitch, const Treal a_cAngleRoll);

  //! Rotate camera with 'roll' effect using current distance to target (roll around the target).
  /*!
      \param a_cAngleYaw - Rotating angle in xOz plane (yaw angle).
      \param a_cAnglePitch - Rotating angle in yOZ plane (pitch angle).
      \param a_cAngleRoll - Rotating angle in xOy plane (roll angle).
  */
  void rotateRoll(const Treal a_cAngleYaw, const Treal a_cAnglePitch, const Treal a_cAngleRoll);

  //! Rotate camera with 'walk' effect using current latitude (human walk camera).
  /*!
      \param a_cAngleYaw - Rotating angle in xOz plane (yaw angle).
      \param a_cAnglePitch - Rotating angle in yOZ plane (pitch angle).
  */
  void rotateWalk(const Treal a_cAngleYaw, const Treal a_cAnglePitch);

  //! Rotate current camera's vectors with the transformation matrix in a space.
  /*!
      \param a_crMatrix3D - Constant reference to the instance of the CMatrix3D class.
  */
  void rotate(const CMatrix3D& a_crMatrix3D);
  //! Rotate current camera's vectors with the transformation extended matrix in a space.
  /*!
      \param a_crMatrix4D - Constant reference to the instance of the CMatrix4D class.
  */
  void rotate(const CMatrix4D& a_crMatrix4D);
  //! Rotate current camera's vectors with the quaternion.
  /*!
      \param a_crQuaternion - Constant reference to the instance of the CQuaternion class.
  */
  void rotate(const CQuaternion& a_crQuaternion);

  //! Transform current camera with the transformation matrix in a space.
  /*!
      \param a_crMatrix3D - Constant reference to the instance of the CMatrix3D class.
  */
  void transform(const CMatrix3D& a_crMatrix3D);
  //! Transform current camera with the transformation extended matrix in a space.
  /*!
      \param a_crMatrix4D - Constant reference to the instance of the CMatrix4D class.
  */
  void transform(const CMatrix4D& a_crMatrix4D);
  //! Transform current camera with the quaternion.
  /*!
      \param a_crQuaternion - Constant reference to the instance of the CQuaternion class.
  */
  void transform(const CQuaternion& a_crQuaternion);

  //! Serialize CCamera class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CCamera class instances.
  /*!
      \param a_rInstance - Reference to another CCamera class instance.
  */
  void swap(CCamera& a_rInstance);

private:
  mutable Tuint m_CalculatedMatrixes;         //!< Calculated camera matrixes flag.
  mutable CMatrix4D m_DirectMatrix;           //!< Camera direct matrix.
  mutable CMatrix4D m_ModelViewMatrix;        //!< Camera model view matrix.
  mutable CMatrix4D m_ProjectionMatrix;       //!< Camera projection matrix.
  mutable CMatrix4D m_InvertMatrix;           //!< Camera invert matrix.
  mutable CMatrix4D m_InvertModelViewMatrix;  //!< Camera invert matrix.
  mutable CMatrix4D m_InvertProjectionMatrix; //!< Camera projection matrix.

  Tbool m_OrthoFrustumFlag;             //!< Camera orthogonal/frustum flag.
  CPoint3D<Treal> m_Position;           //!< Camera position.
  CVector3D m_Direction;                //!< Camera 'direction' vector.
  CVector3D m_Up;                       //!< Camera 'up' vector.
  CVector3D m_Right;                    //!< Camera 'right' vector.
  CRect<Treal> m_ScaleRect;             //!< Camera scale rectangle.
  Treal m_Znear;                        //!< Z-near clipping plane.
  Treal m_Zfar;                         //!< Z-far clipping plane.
  Treal m_FOV;                          //!< Camera FOV (field of view) angle.
  Treal m_Aspect;                       //!< Camera aspect ratio.

  Treal m_Distance;                     //!< Distance to the observing target.
  Treal m_Latitude;                     //!< Current latitude value.

  //! Recalculate camera FOV (field of view) angle.
  void recalculateFOV();
  //! Recalculate camera aspect ratio.
  void recalculateAspect();
  //! Recalculate camera scale rectangle.
  void recalculateScaleRect();

  //! Calculate direct camera matrix.
  void calculateDirect() const;
  //! Calculate model view matrix.
  void calculateModelView() const;
  //! Calculate orthogonal projection matrix.
  void calculateOrtho() const;
  //! Calculate frustum projection matrix.
  void calculateFrustum() const;
  //! Calculate invert camera matrix.
  void calculateInvert() const;
  //! Calculate invert model view camera matrix.
  void calculateInvertModelView() const;
  //! Calculate invert projection camera matrix.
  void calculateInvertProjection() const;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CCamera.inl>
/*==========================================================================*/
//! \example example-geometry-CCamera.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CCamera.cpp
/*==========================================================================*/
#endif
