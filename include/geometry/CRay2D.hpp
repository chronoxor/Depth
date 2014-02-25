/*!
 *  \file    CRay2D.hpp Representation of the ray on a plane.
 *  \brief   Ray on a plane class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Ray on a plane class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   09.07.2008 23:25:34

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
#ifndef __CRAY2D_HPP__
#define __CRAY2D_HPP__
/*==========================================================================*/
#include <Depth/include/geometry.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CPoint2D.hpp>
#include <Depth/include/geometry/CVector2D.hpp>
#include <Depth/include/geometry/CMatrix2D.hpp>
#include <Depth/include/geometry/CMatrix3D.hpp>
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
//! Ray on a plane class.
/*!
    Class represents 2-dimension ray on a plane. It is defined with the origin
    point and the direction vector.

    Additionally class of the ray on a plane  provides  functionality  to  get
    distance from ray to the given point, to project point on  a  ray  and  to
    detect mutual state of two rays.
*/
class GEOMETRY_API CRay2D
{
  //! Type for MConceptDepthType constraint checking.
  typedef CRay2D TDepthCheckType;

  // Check CRay2D class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  CPoint2D<Treal> m_Origin;             //!< Origin of the ray.
  CVector2D m_Direction;                //!< Direction of the ray.

  //! Default class constructor.
  /*!
      Set ray's origin into begin of the plane coordinate system  (0,  0)  and
      set its direction to the positive X axis (1, 0).
  */
  CRay2D();
  //! Initialize ray from the given origin and direction.
  /*!
      \param a_crOrigin - Constant reference to the ray origin.
      \param a_crDirection - Constant reference to the ray direction.
  */
  CRay2D(const CPoint2D<Treal>& a_crOrigin, const CVector2D& a_crDirection);
  //! Initialize ray from the given two points on a plane.
  /*!
      \param a_crA - Constant reference to the first instance of the CPoint2D class.
      \param a_crB - Constant reference to the second instance of the CPoint2D class.
  */
  CRay2D(const CPoint2D<Treal>& a_crA, const CPoint2D<Treal>& a_crB);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRay2D class.
  */
  CRay2D(const CRay2D& a_crInstance);
  //! Class destructor.
 ~CRay2D();

  //! Operator: Equal to another CRay2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CRay2D class.
      \param a_crInstance2 - Constant reference to another instance of the CRay2D class.
      \return true  - if CRay2D class instance is equal to another one. \n
              false - if CRay2D class instance is not equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator == (const CRay2D& a_crInstance1, const CRay2D& a_crInstance2);
  //! Operator: Not equal to another CRay2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CRay2D class.
      \param a_crInstance2 - Constant reference to another instance of the CRay2D class.
      \return true  - if CRay2D class instance is not equal to another one. \n
              false - if CRay2D class instance is equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator != (const CRay2D& a_crInstance1, const CRay2D& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Keep ray's direction unchanged.

      \param a_crInstance - Constant reference to the current instance of the CRay2D class.
      \return New instance of CRay2D class with applied plus operator.
  */
  friend GEOMETRY_API CRay2D operator + (const CRay2D& a_crInstance);
  //! Operator: Unary minus.
  /*!
      Negative ray's direction to the opposite.

      \param a_crInstance - Constant reference to the current instance of the CRay2D class.
      \return New instance of CRay2D class with applied minus operator.
  */
  friend GEOMETRY_API CRay2D operator - (const CRay2D& a_crInstance);

  //! Operator: Assign another CRay2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRay2D class.
      \return Reference to the current class instance.
  */
  CRay2D& operator = (const CRay2D& a_crInstance);

  //! Set ray from the given origin and direction.
  /*!
      \param a_crOrigin - Constant reference to the ray origin.
      \param a_crDirection - Constant reference to the ray direction.
  */
  void set(const CPoint2D<Treal>& a_crOrigin, const CVector2D& a_crDirection);
  //! Set ray from the given two points on a plane.
  /*!
      \param a_crA - Constant reference to the first instance of the CPoint2D class.
      \param a_crB - Constant reference to the second instance of the CPoint2D class.
  */
  void set(const CPoint2D<Treal>& a_crA, const CPoint2D<Treal>& a_crB);
  //! Set another CRay2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRay2D class.
  */
  void set(const CRay2D& a_crInstance);

  //! Negative ray's direction.
  void negate();

  //! Calculate point on the current ray with the given offset from the ray's origin.
  /*!
      \param a_cOffset - Offset from the ray's origin.
      \return Point on the current ray with the given offset from the ray's origin.
  */
  CPoint2D<Treal> getOffsetPoint(const Treal a_cOffset) const;

  //! Calculate distance from the point on a plane to the current ray.
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \return Distance from the point on a plane to the current ray.
  */
  Treal getDistanceToPoint(const CPoint2D<Treal>& a_crPoint2D) const;
  //! Calculate squared distance from the point on a plane to the current ray.
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \return Squared distance from the point on a plane to the current ray.
  */
  Treal getDistanceToPointSq(const CPoint2D<Treal>& a_crPoint2D) const;

  //! Mirror point on a plane relative to the current ray.
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \return Mirrored point on a plane.
  */
  CPoint2D<Treal> mirrorPoint(const CPoint2D<Treal>& a_crPoint2D) const;
  //! Mirror normal vector relative to the current ray.
  /*!
      \param a_crNormal - Constant reference to the instance of the CVector2D class.
      \return Mirrored normal vector.
  */
  CVector2D mirrorNormal(const CVector2D& a_crNormal) const;

  //! Project point on the current ray.
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \return Projected point on the current ray.
  */
  CPoint2D<Treal> project(const CPoint2D<Treal>& a_crPoint2D) const;

  //! Rotate current ray's direction with the transformation matrix on a plane.
  /*!
      \param a_crMatrix2D - Constant reference to the instance of the CMatrix2D class.
  */
  void rotate(const CMatrix2D& a_crMatrix2D);
  //! Rotate current ray's direction with the transformation extended matrix on a plane.
  /*!
      \param a_crMatrix3D - Constant reference to the instance of the CMatrix3D class.
  */
  void rotate(const CMatrix3D& a_crMatrix3D);

  //! Transform current ray on a plane with the transformation matrix on a plane.
  /*!
      \param a_crMatrix2D - Constant reference to the instance of the CMatrix2D class.
  */
  void transform(const CMatrix2D& a_crMatrix2D);
  //! Transform current ray on a plane with the transformation extended matrix on a plane.
  /*!
      \param a_crMatrix3D - Constant reference to the instance of the CMatrix3D class.
  */
  void transform(const CMatrix3D& a_crMatrix3D);

  //! Check if two rays are collinear.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay2D class.
      \return true  - if two rays are collinear. \n
              false - if two rays are not collinear. \n
  */
  static Tbool isCollinear(const CRay2D& a_crInstance1, const CRay2D& a_crInstance2);
  //! Check if two rays are intersected.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay2D class.
      \return true  - if two rays are intersected. \n
              false - if two rays are not intersected. \n
  */
  static Tbool isIntersect(const CRay2D& a_crInstance1, const CRay2D& a_crInstance2);
  //! Check if two rays are collinear and parallel (not on the same straight line).
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay2D class.
      \return true  - if two rays are parallel. \n
              false - if two rays are not parallel. \n
  */
  static Tbool isParallel(const CRay2D& a_crInstance1, const CRay2D& a_crInstance2);
  //! Check if two rays are collinear and on the same straight line.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay2D class.
      \return true  - if two rays are on the same straight line. \n
              false - if two rays are not on the same straight line. \n
  */
  static Tbool isStraight(const CRay2D& a_crInstance1, const CRay2D& a_crInstance2);

  //! Get two rays intersection result as ray's origin offsets.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay2D class.
      \param a_rOffset1 - Reference to the returning offset of intersection from the first ray's origin.
      \param a_rOffset2 - Reference to the returning offset of intersection from the second ray's origin.
      \return true  - if two rays are intersected. \n
              false - if two rays are not intersected. \n
  */
  static Tbool intersect(const CRay2D& a_crInstance1, const CRay2D& a_crInstance2, Treal& a_rOffset1, Treal& a_rOffset2);
  //! Get two rays intersection result as a point in a plane.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CRay2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CRay2D class.
      \param a_rPoint2D - Reference to the returning instance of the CPoint2D class.
      \return true  - if two rays are intersected. \n
              false - if two rays are not intersected. \n
  */
  static Tbool intersect(const CRay2D& a_crInstance1, const CRay2D& a_crInstance2, CPoint2D<Treal>& a_rPoint2D);

  //! Serialize CRay2D class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRay2D class instances.
  /*!
      \param a_rInstance - Reference to another CRay2D class instance.
  */
  void swap(CRay2D& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CRay2D.inl>
/*==========================================================================*/
//! \example example-geometry-CRay2D.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CRay2D.cpp
/*==========================================================================*/
#endif
