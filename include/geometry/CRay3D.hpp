/*!
 *  \file    CRay3D.hpp Representation of the ray in a space.
 *  \brief   Ray in a space class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Ray in a space class.

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
#ifndef __CRAY3D_HPP__
#define __CRAY3D_HPP__
/*==========================================================================*/
#include <Depth/include/geometry.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
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
//! Ray in a space class.
/*!
    Class represents 3-dimension ray in a space. It is defined with the origin
    point and the direction vector.

    Additionally class of the ray in a space  provides  functionality  to  get
    distance from ray to the given point or another ray and to  project  point
    on a ray.
*/
class GEOMETRY_API CRay3D
{
  //! Type for MConceptDepthType constraint checking.
  typedef CRay3D TDepthCheckType;

  // Check CRay3D class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  CPoint3D<Treal> m_Origin;             //!< Origin of the ray.
  CVector3D m_Direction;                //!< Direction of the ray.

  //! Default class constructor.
  /*!
      Set ray's origin into begin of the space coordinate system (0, 0, 0) and
      set its direction to the positive X axis (1, 0, 0).
  */
  CRay3D();
  //! Initialize ray from the given origin and direction.
  /*!
      \param a_crOrigin - Constant reference to the ray origin.
      \param a_crDirection - Constant reference to the ray direction.
  */
  CRay3D(const CPoint3D<Treal>& a_crOrigin, const CVector3D& a_crDirection);
  //! Initialize ray from the given two points in a space.
  /*!
      \param a_crA - Constant reference to the first instance of the CPoint3D class.
      \param a_crB - Constant reference to the second instance of the CPoint3D class.
  */
  CRay3D(const CPoint3D<Treal>& a_crA, const CPoint3D<Treal>& a_crB);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRay3D class.
  */
  CRay3D(const CRay3D& a_crInstance);
  //! Class destructor.
 ~CRay3D();

  //! Operator: Equal to another CRay3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CRay3D class.
      \param a_crInstance2 - Constant reference to another instance of the CRay3D class.
      \return true  - if CRay3D class instance is equal to another one. \n
              false - if CRay3D class instance is not equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator == (const CRay3D& a_crInstance1, const CRay3D& a_crInstance2);
  //! Operator: Not equal to another CRay3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CRay3D class.
      \param a_crInstance2 - Constant reference to another instance of the CRay3D class.
      \return true  - if CRay3D class instance is not equal to another one. \n
              false - if CRay3D class instance is equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator != (const CRay3D& a_crInstance1, const CRay3D& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Keep ray's direction unchanged.

      \param a_crInstance - Constant reference to the current instance of the CRay3D class.
      \return New instance of CRay3D class with applied plus operator.
  */
  friend GEOMETRY_API CRay3D operator + (const CRay3D& a_crInstance);
  //! Operator: Unary minus.
  /*!
      Negative ray's direction to the opposite.

      \param a_crInstance - Constant reference to the current instance of the CRay3D class.
      \return New instance of CRay3D class with applied minus operator.
  */
  friend GEOMETRY_API CRay3D operator - (const CRay3D& a_crInstance);

  //! Operator: Assign another CRay3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRay3D class.
      \return Reference to the current class instance.
  */
  CRay3D& operator = (const CRay3D& a_crInstance);

  //! Set ray from the given origin and direction.
  /*!
      \param a_crOrigin - Constant reference to the ray origin.
      \param a_crDirection - Constant reference to the ray direction.
  */
  void set(const CPoint3D<Treal>& a_crOrigin, const CVector3D& a_crDirection);
  //! Set ray from the given two points in a space.
  /*!
      \param a_crA - Constant reference to the first instance of the CPoint3D class.
      \param a_crB - Constant reference to the second instance of the CPoint3D class.
  */
  void set(const CPoint3D<Treal>& a_crA, const CPoint3D<Treal>& a_crB);
  //! Set another CRay3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRay3D class.
  */
  void set(const CRay3D& a_crInstance);

  //! Negative ray's direction.
  void negate();

  //! Calculate point on the current ray with the given offset from the ray's origin.
  /*!
      \param a_cOffset - Offset from the ray's origin.
      \return Point on the current ray with the given offset from the ray's origin.
  */
  CPoint3D<Treal> getOffsetPoint(const Treal a_cOffset) const;

  //! Calculate distance from the point in a space to the current ray.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return Distance from the point in a space to the current ray.
  */
  Treal getDistanceToPoint(const CPoint3D<Treal>& a_crPoint3D) const;
  //! Calculate squared distance from the point in a space to the current ray.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return Squared distance from the point in a space to the current ray.
  */
  Treal getDistanceToPointSq(const CPoint3D<Treal>& a_crPoint3D) const;

  //! Mirror point in a space relative to the current ray.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return Mirrored point in a space.
  */
  CPoint3D<Treal> mirrorPoint(const CPoint3D<Treal>& a_crPoint3D) const;
  //! Mirror normal vector relative to the current ray.
  /*!
      \param a_crNormal - Constant reference to the instance of the CVector3D class.
      \return Mirrored normal vector.
  */
  CVector3D mirrorNormal(const CVector3D& a_crNormal) const;

  //! Project point on the current ray.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return Projected point on the current ray.
  */
  CPoint3D<Treal> project(const CPoint3D<Treal>& a_crPoint3D) const;

  //! Rotate current ray's direction with the transformation matrix in a space.
  /*!
      \param a_crMatrix3D - Constant reference to the instance of the CMatrix3D class.
  */
  void rotate(const CMatrix3D& a_crMatrix3D);
  //! Rotate current ray's direction with the transformation extended matrix in a space.
  /*!
      \param a_crMatrix4D - Constant reference to the instance of the CMatrix4D class.
  */
  void rotate(const CMatrix4D& a_crMatrix4D);
  //! Rotate current ray's direction with the quaternion.
  /*!
      \param a_crQuaternion - Constant reference to the instance of the CQuaternion class.
  */
  void rotate(const CQuaternion& a_crQuaternion);

  //! Transform current ray on a plane with the transformation matrix in a space.
  /*!
      \param a_crMatrix3D - Constant reference to the instance of the CMatrix3D class.
  */
  void transform(const CMatrix3D& a_crMatrix3D);
  //! Transform current ray on a plane with the transformation extended matrix in a space.
  /*!
      \param a_crMatrix4D - Constant reference to the instance of the CMatrix4D class.
  */
  void transform(const CMatrix4D& a_crMatrix4D);
  //! Transform current ray on a plane with the quaternion.
  /*!
      \param a_crQuaternion - Constant reference to the instance of the CQuaternion class.
  */
  void transform(const CQuaternion& a_crQuaternion);

  //! Check if two rays are collinear.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay3D class.
      \return true  - if two rays are collinear. \n
              false - if two rays are not collinear. \n
  */
  static Tbool isCollinear(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2);
  //! Check if two rays are intersected.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay3D class.
      \return true  - if two rays are intersected. \n
              false - if two rays are not intersected. \n
  */
  static Tbool isIntersect(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2);
  //! Check if two rays are collinear and parallel (not on the same straight line).
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay3D class.
      \return true  - if two rays are parallel. \n
              false - if two rays are not parallel. \n
  */
  static Tbool isParallel(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2);
  //! Check if two rays are collinear and on the same straight line.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay3D class.
      \return true  - if two rays are on the same straight line. \n
              false - if two rays are not on the same straight line. \n
  */
  static Tbool isStraight(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2);

  //! Get shortest distance between two rays. Return result points on rays as ray's origin offsets.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay3D class.
      \param a_rOffset1 - Reference to the returning shortest offset from the first ray's origin.
      \param a_rOffset2 - Reference to the returning shortest offset from the second ray's origin.
      \return Shortest distance between two rays.
  */
  static Treal distance(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2, Treal& a_rOffset1, Treal& a_rOffset2);
  //! Get squared shortest distance between two rays. Return result points on rays as ray's origin offsets.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay3D class.
      \param a_rOffset1 - Reference to the returning shortest offset from the first ray's origin.
      \param a_rOffset2 - Reference to the returning shortest offset from the second ray's origin.
      \return Squared shortest distance between two rays.
  */
  static Treal distanceSq(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2, Treal& a_rOffset1, Treal& a_rOffset2);
  //! Get shortest distance between two rays. Return result points on rays as points in a space.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay3D class.
      \param a_rFirstPoint3D - Reference to the returning first instance of the CPoint3D class.
      \param a_rSecondPoint3D - Reference to the returning second instance of the CPoint3D class.
      \return Shortest distance between two rays.
  */
  static Treal distance(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2, CPoint3D<Treal>& a_rFirstPoint3D, CPoint3D<Treal>& a_rSecondPoint3D);
  //! Get squared shortest distance between two rays. Return result points on rays as points in a space.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay3D class.
      \param a_rFirstPoint3D - Reference to the returning first instance of the CPoint3D class.
      \param a_rSecondPoint3D - Reference to the returning second instance of the CPoint3D class.
      \return Squared shortest distance between two rays.
  */
  static Treal distanceSq(const CRay3D& a_crInstance1, const CRay3D& a_crInstance2, CPoint3D<Treal>& a_rFirstPoint3D, CPoint3D<Treal>& a_rSecondPoint3D);

  //! Serialize CRay3D class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRay3D class instances.
  /*!
      \param a_rInstance - Reference to another CRay3D class instance.
  */
  void swap(CRay3D& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CRay3D.inl>
/*==========================================================================*/
//! \example example-geometry-CRay3D.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CRay3D.cpp
/*==========================================================================*/
#endif
