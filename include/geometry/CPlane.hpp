/*!
 *  \file    CPlane.hpp Representation of the plane in a space.
 *  \brief   Plane in a space class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Plane in a space class.

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
#ifndef __CPLANE_HPP__
#define __CPLANE_HPP__
/*==========================================================================*/
#include <Depth/include/geometry.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CPoint3D.hpp>
#include <Depth/include/geometry/CRay3D.hpp>
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
//! Plane in a space class.
/*!
    Class represents 3-dimension plane in a space.  It  is  defined  with  the
    normal vector and the distance to the plane  from  the  coordinate  system
    origin.

    Additionally class of the plane in a space provides functionality to  find
    origin point on a plane, to get distance  from  the  given  point  to  the
    plane, to calculate mirror and projection matrixes and to get mutual state
    of the point, line, ray and plane.
*/
class GEOMETRY_API CPlane
{
  //! Type for MConceptDepthType constraint checking.
  typedef CPlane TDepthCheckType;

  // Check CPlane class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  CVector3D m_Normal;                   //!< Normal of the plane.
  Treal m_Distance;                     //!< Distance to the plane.

  //! Default class constructor.
  /*!
      Set plane's  origin  point  into  begin  of the space coordinate  system
      (0, 0, 0) and set its normal to the positive X axis (1, 0, 0).
  */
  CPlane();
  //! Initialize plane as coefficients of the Ax + By + Cz + D = 0 polynome.
  /*!
      \param a_cA - A coefficient of the plane polynome.
      \param a_cB - B coefficient of the plane polynome.
      \param a_cC - C coefficient of the plane polynome.
      \param a_cD - D coefficient of the plane polynome.
  */
  CPlane(const Treal a_cA, const Treal a_cB, const Treal a_cC, const Treal a_cD);
  //! Initialize plane with the given tangent vector in a space.
  /*!
      \param a_crTangentVector - Constant reference to the tangent vector in a space.
  */
  CPlane(const CVector3D& a_crTangentVector);
  //! Initialize plane from the given normal vector and distance.
  /*!
      \param a_crNormal - Constant reference to the plane normal vector.
      \param a_cDistance - Distance to the plane.
  */
  CPlane(const CVector3D& a_crNormal, const Treal a_cDistance);
  //! Initialize plane from the given normal vector and point on a plane.
  /*!
      \param a_crNormal - Constant reference to the plane normal vector.
      \param a_crPoint3D - Constant reference to the point on a plane.
  */
  CPlane(const CVector3D& a_crNormal, const CPoint3D<Treal>& a_crPoint3D);
  //! Initialize plane from the given three points in a space.
  /*!
      \param a_crA - Constant reference to the first instance of the CPoint3D class.
      \param a_crB - Constant reference to the second instance of the CPoint3D class.
      \param a_crC - Constant reference to the third instance of the CPoint3D class.
  */
  CPlane(const CPoint3D<Treal>& a_crA, const CPoint3D<Treal>& a_crB, const CPoint3D<Treal>& a_crC);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPlane class.
  */
  CPlane(const CPlane& a_crInstance);
  //! Class destructor.
 ~CPlane();

  //! Operator: Equal to another CPlane class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CPlane class.
      \param a_crInstance2 - Constant reference to another instance of the CPlane class.
      \return true  - if CPlane class instance is equal to another one. \n
              false - if CPlane class instance is not equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator == (const CPlane& a_crInstance1, const CPlane& a_crInstance2);
  //! Operator: Not equal to another CPlane class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CPlane class.
      \param a_crInstance2 - Constant reference to another instance of the CPlane class.
      \return true  - if CPlane class instance is not equal to another one. \n
              false - if CPlane class instance is equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator != (const CPlane& a_crInstance1, const CPlane& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Keep plane's normal direction and distance unchanged.

      \param a_crInstance - Constant reference to the current instance of the CPlane class.
      \return New instance of CPlane class with applied plus operator.
  */
  friend GEOMETRY_API CPlane operator + (const CPlane& a_crInstance);
  //! Operator: Unary minus.
  /*!
      Negative plane's normal direction and distance to the opposite.

      \param a_crInstance - Constant reference to the current instance of the CPlane class.
      \return New instance of CPlane class with applied minus operator.
  */
  friend GEOMETRY_API CPlane operator - (const CPlane& a_crInstance);

  //! Operator: Assign another CPlane class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPlane class.
      \return Reference to the current class instance.
  */
  CPlane& operator = (const CPlane& a_crInstance);

  //! Set plane as coefficients of the Ax + By + Cz + D = 0 polynome.
  /*!
      \param a_cA - A coefficient of the plane polynome.
      \param a_cB - B coefficient of the plane polynome.
      \param a_cC - C coefficient of the plane polynome.
      \param a_cD - D coefficient of the plane polynome.
  */
  void set(const Treal a_cA, const Treal a_cB, const Treal a_cC, const Treal a_cD);
  //! Set plane with the given tangent vector in a space.
  /*!
      \param a_crTangentVector - Constant reference to the tangent vector in a space.
  */
  void set(const CVector3D& a_crTangentVector);
  //! Set plane from the given normal vector and distance.
  /*!
      \param a_crNormal - Constant reference to the plane normal vector.
      \param a_cDistance - Distance to the plane.
  */
  void set(const CVector3D& a_crNormal, const Treal a_cDistance);
  //! Set plane from the given normal vector and point on a plane.
  /*!
      \param a_crNormal - Constant reference to the plane normal vector.
      \param a_crPoint3D - Constant reference to the point on a plane.
  */
  void set(const CVector3D& a_crNormal, const CPoint3D<Treal>& a_crPoint3D);
  //! Set ray from the given three points in a space.
  /*!
      \param a_crA - Constant reference to the first instance of the CPoint3D class.
      \param a_crB - Constant reference to the second instance of the CPoint3D class.
      \param a_crC - Constant reference to the third instance of the CPoint3D class.
  */
  void set(const CPoint3D<Treal>& a_crA, const CPoint3D<Treal>& a_crB, const CPoint3D<Treal>& a_crC);
  //! Set another CPlane class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPlane class.
  */
  void set(const CPlane& a_crInstance);

  //! Negative plane's normal direction and distance.
  void negate();
  //! Negative only plane's normal direction.
  void negateNormal();
  //! Negative only plane's distance.
  void negateDistance();

  //! Get tangent vector of the current plane.
  /*!
      \return Tangent vector of the current plane.
  */
  CVector3D getTangent() const;

  //! Calculate dot product of the current plane normal vector and given vector in a space.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \return Dot product of the current plane normal vector and given vector in a space.
  */
  Treal getDot(const CVector3D& a_crVector3D) const;

  //! Calculate distance from the point in a space to the current plane.
  /*!
      Note that the calculated distance could be negative when point is behind
      the plane (in the negative subspace of the plane).

      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return Distance from the point in a space to the current plane.
  */
  Treal getDistanceToPoint(const CPoint3D<Treal>& a_crPoint3D) const;

  //! Get point on the current plane which is closest to the given one.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return Closest point on a plane.
  */
  CPoint3D<Treal> getClosestPoint(const CPoint3D<Treal>& a_crPoint3D) const;
  //! Get point on the current plane which is closest to the given one (returns distance).
  /*!
      Method also returns  distance  to  the  closest  point.  Note  that  the
      calculated distance could be negative when point is behind the plane (in
      the negative subspace of the plane).

      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rDistance - Reference to the returning distance to the closest point on a plane.
      \return Closest point on a plane.
  */
  CPoint3D<Treal> getClosestPoint(const CPoint3D<Treal>& a_crPoint3D, Treal& a_rDistance) const;

  //! Get extended matrix in a space to mirror points in a space or normals vectors relative to the current plane.
  /*!
      \param a_cMirrorNormals - Mirror normals vector rather than points flag (default if 'false').
      \return Mirror extended matrix in a space.
  */
  CMatrix4D getMirrorMatrix(const Tbool a_cMirrorNormals = false) const;
  //! Get extended matrix in a space to orthogonal points projection on the current plane.
  /*!
      \param a_crProjectDirection - Constant reference to the direction vector of the projection.
      \return Orthogonal projection extended matrix in a space.
  */
  CMatrix4D getOrthoProjectMatrix(const CVector3D& a_crProjectDirection) const;
  //! Get extended matrix in a space to perspective points projection on the current plane.
  /*!
      \param a_crProjectOrigin - Constant reference to the perspective projection origin point.
      \return Perspective projection extended matrix in a space.
  */
  CMatrix4D getPerspectiveProjectMatrix(const CPoint3D<Treal>& a_crProjectOrigin) const;

  //! Check if the point in a space is on the current plane.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return Distance from the point to the plane. Could be one of the following values: \n
            <0.0 - if the point is behind a plane (in the negative subspace of the plane). \n
            =0.0 - if the point is on a plane. \n
            >0.0 - if the point is before a plane (in the positive subspace of the plane). \n
  */
  Treal isIntersect(const CPoint3D<Treal>& a_crPoint3D) const;
  //! Check if the ray is intersects with the current plane.
  /*!
      \param a_crRay3D - Constant reference to the instance of the CRay3D class.
      \return true  - if the ray is intersects with the current plane. \n
              false - if the ray is orthogonal with the current plane. \n
  */
  Tbool isIntersect(const CRay3D& a_crRay3D) const;
  //! Check if the ray is intersects with the current plane (returns ray's offset to the point of intersection).
  /*!
      \param a_crRay3D - Constant reference to the instance of the CRay3D class.
      \param a_rOffset - Reference to the returning offset from the ray's origin to the point of intersection.
      \return true  - if the ray is intersects with the current plane. \n
              false - if the ray is orthogonal with the current plane. \n
  */
  Tbool isIntersect(const CRay3D& a_crRay3D, Treal& a_rOffset) const;
  //! Check if the ray is intersects with the current plane (returns point of intersection).
  /*!
      \param a_crRay3D - Constant reference to the instance of the CRay3D class.
      \param a_rPoint3D - Reference to the returning point of intersection.
      \return true  - if the ray is intersects with the current plane. \n
              false - if the ray is orthogonal with the current plane. \n
  */
  Tbool isIntersect(const CRay3D& a_crRay3D, CPoint3D<Treal>& a_rPoint3D) const;
  //! Check if another plane is intersects with the current plane.
  /*!
      \param a_crPlane - Constant reference to the instance of the CPlane class.
      \return true  - if another plane is intersects with the current plane. \n
              false - if another plane is orthogonal with the current plane. \n
  */
  Tbool isIntersect(const CPlane& a_crPlane) const;
  //! Check if another plane is intersects with the current plane (returns ray of intersection).
  /*!
      \param a_crPlane - Constant reference to the instance of the CPlane class.
      \param a_rRay3D - Reference to the returning ray of intersection.
      \return true  - if another plane is intersects with the current plane. \n
              false - if another plane is orthogonal with the current plane. \n
  */
  Tbool isIntersect(const CPlane& a_crPlane, CRay3D& a_rRay3D) const;

  //! Mirror point in a space relative to the current plane.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return Mirrored point in a space.
  */
  CPoint3D<Treal> mirrorPoint(const CPoint3D<Treal>& a_crPoint3D) const;
  //! Mirror normal vector relative to the current plane.
  /*!
      \param a_crNormal - Constant reference to the instance of the CVector3D class.
      \return Mirrored normal vector.
  */
  CVector3D mirrorNormal(const CVector3D& a_crNormal) const;
  //! Mirror another plane relative to the current plane.
  /*!
      \param a_crPlane - Constant reference to the instance of the CPlane class.
      \return Mirrored plane.
  */
  CPlane mirrorPlane(const CPlane& a_crPlane) const;

  //! Mirror point in a space relative to the current plane and return its plane state.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result mirrored instance of the CPoint3D class.
      \return One of the following values: \n
            <0.0 - if the mirrored point is behind a plane (in the negative subspace of the plane). \n
            =0.0 - if the mirrored point is on a plane. \n
            >0.0 - if the mirrored point is before a plane (in the positive subspace of the plane). \n
  */
  Treal mirrorPoint(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Mirror normal vector relative to the current plane and return its plane state.
  /*!
      \param a_crNormal - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result mirrored instance of the CVector3D class.
      \return One of the following values: \n
            <0.0 - if the mirrored normal vector is not directed with the plane's normal (in the negative subspace of the plane). \n
            =0.0 - if the mirrored normal vector is orthogonal to the plane's normal. \n
            >0.0 - if the mirrored normal vector is directed with the plane's normal (in the positive subspace of the plane). \n
  */
  Treal mirrorNormal(const CVector3D& a_crNormal, CVector3D& a_rResult) const;

  //! Orthogonal project point in a space on the current plane and return its plane state.
  /*!
      \param a_crProjectDirection - Constant reference to the direction vector of the projection.
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result projected instance of the CPoint3D class.
      \return One of the following values: \n
            <0.0 - if the projected point is on a plane, but point to project is behind a plane (in the negative subspace of the plane). \n
            =0.0 - if the projected point is out of plane (bad projection). \n
            >0.0 - if the projected point is on a plane. \n
  */
  Treal projectOrtho(const CVector3D& a_crProjectDirection, const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Perspective project point in a space on the current plane and return its plane state.
  /*!
      \param a_crProjectOrigin - Constant reference to the perspective projection origin point.
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result projected instance of the CPoint3D class.
      \return One of the following values: \n
            <0.0 - if the projected point is on a plane, but point to project is behind a plane (in the negative subspace of the plane). \n
            =0.0 - if the projected point is out of plane (bad projection). \n
            >0.0 - if the projected point is on a plane. \n
  */
  Treal projectPerspective(const CPoint3D<Treal>& a_crProjectOrigin, const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;

  //! Rotate current plane's normal with the transformation matrix in a space.
  /*!
      \param a_crMatrix3D - Constant reference to the instance of the CMatrix3D class.
  */
  void rotate(const CMatrix3D& a_crMatrix3D);
  //! Rotate current plane's normal with the transformation extended matrix in a space.
  /*!
      \param a_crMatrix4D - Constant reference to the instance of the CMatrix4D class.
  */
  void rotate(const CMatrix4D& a_crMatrix4D);
  //! Rotate current plane's normal with the quaternion.
  /*!
      \param a_crQuaternion - Constant reference to the instance of the CQuaternion class.
  */
  void rotate(const CQuaternion& a_crQuaternion);

  //! Transform current plane with the transformation matrix in a space.
  /*!
      \param a_crMatrix3D - Constant reference to the instance of the CMatrix3D class.
  */
  void transform(const CMatrix3D& a_crMatrix3D);
  //! Transform current plane with the transformation extended matrix in a space.
  /*!
      \param a_crMatrix4D - Constant reference to the instance of the CMatrix4D class.
  */
  void transform(const CMatrix4D& a_crMatrix4D);
  //! Transform current plane with the quaternion.
  /*!
      \param a_crQuaternion - Constant reference to the instance of the CQuaternion class.
  */
  void transform(const CQuaternion& a_crQuaternion);

  //! Serialize CPlane class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CPlane class instances.
  /*!
      \param a_rInstance - Reference to another CPlane class instance.
  */
  void swap(CPlane& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CPlane.inl>
/*==========================================================================*/
//! \example example-geometry-CPlane.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CPlane.cpp
/*==========================================================================*/
#endif
