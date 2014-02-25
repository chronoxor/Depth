/*!
 *  \file    CBox.hpp Template representation of the box in a space.
 *  \brief   Box in a space template class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Box in a space template class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   10.02.2006 01:33:56

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
#ifndef __CBOX_HPP__
#define __CBOX_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMax.hpp>
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/algorithms/common/AMinMax.hpp>
#include <Depth/include/concept/base/MConceptNumber.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CPoint3D.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Box in a space template class.
/*!
    Class represents 3-dimension box in a space. It contains two point  values
    for the left-bottom-deep side of the box and for the  right-top-high  side
    of the box [ A(x1, y1, z1), B(x2, y2, z2) ].

    \code
    y ^                                        B(x2, y2, z2)
      |                        +---------------+
      |                       /               /|
      |                     /               /  |
      |              z     +--------------+    |
      |            /       |              |    +
      |          /         |  Rectangle   |   /
      |        /           |              | /
      |      /             +--------------+
      |    /               A(x1, y1, z1)
      |  /
      |/
    --+-----------------------------> x
      |
    \endcode
*/
template <typename T_Type>
class CBox
{
  //! Type for MConceptNumber constraint checking.
  typedef T_Type TNumberCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CBox<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be a number type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptNumber, TNumberCheckType);
  // Check CBox class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Box value template type.
  typedef T_Type TType;

  CPoint3D<T_Type> m_A;                 //!< Rectangle left-bottom-deep point.
  CPoint3D<T_Type> m_B;                 //!< Rectangle right-top-high point.

  //! Default class constructor.
  /*!
      Set box coordinates into begin of the space coordinate system:
      [ A(0.0, 0.0, 0.0), B(0.0, 0.0, 0.0) ].
  */
  CBox();
  //! Initialize box points' coordinates.
  /*!
      \param a_cX1 - X coordinate of the left-bottom-deep point.
      \param a_cY1 - Y coordinate of the left-bottom-deep point.
      \param a_cZ1 - Z coordinate of the left-bottom-deep point.
      \param a_cX2 - X coordinate of the right-top-high point.
      \param a_cY2 - Y coordinate of the right-top-high point.
      \param a_cZ2 - Z coordinate of the right-top-high point.
  */
  CBox(const T_Type a_cX1, const T_Type a_cY1, const T_Type a_cZ1, const T_Type a_cX2, const T_Type a_cY2, const T_Type a_cZ2);
  //! Initialize box points.
  /*!
      \param a_crA - Box's left-bottom-deep point.
      \param a_crB - Box's right-top-high point.
  */
  CBox(const CPoint3D<T_Type>& a_crA, const CPoint3D<T_Type>& a_crB);
  //! Initialize box points' coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
  */
  CBox(const T_Type a_cpCoordinatesBuffer[]);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBox class.
  */
  template <typename T_OtherType>
  CBox(const CBox<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~CBox();

  //! Operator: Equal to another CBox class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBox class.
      \param a_crInstance2 - Constant reference to another instance of the CBox class.
      \return true  - if CBox class instance is equal to another one. \n
              false - if CBox class instance is not equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator == (const CBox<T_OtherType>& a_crInstance1, const CBox<T_OtherOtherType>& a_crInstance2);

  //! Operator: Not equal to another CBox class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CBox class.
      \param a_crInstance2 - Constant reference to another instance of the CBox class.
      \return true  - if CBox class instance is not equal to another one. \n
              false - if CBox class instance is equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator != (const CBox<T_OtherType>& a_crInstance1, const CBox<T_OtherOtherType>& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Applies unary plus operator to all box coordinates.

      \param a_crInstance - Constant reference to the current instance of the CBox class.
      \return New instance of CBox class with applied plus operator.
  */
  template <typename T_OtherType>
  friend CBox<T_OtherType> operator + (const CBox<T_OtherType>& a_crInstance);

  //! Operator: Unary minus.
  /*!
      Applies unary minus operator to all box coordinates.

      \param a_crInstance - Constant reference to the current instance of the CBox class.
      \return New instance of CBox class with applied minus operator.
  */
  template <typename T_OtherType>
  friend CBox<T_OtherType> operator - (const CBox<T_OtherType>& a_crInstance);

  //! Operator: Add number.
  /*!
      Moves all box coordinates by fixed value.

      \param a_crInstance - Constant reference to the current instance of the CBox class.
      \param a_cValue - Number value.
      \return New instance of CBox class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBox<T_OtherType> operator + (const CBox<T_OtherType>& a_crInstance, const T_OtherOtherType a_cValue);
  //! Operator: Add CPoint3D class instance.
  /*!
      Moves all box coordinates by vector in a space.

      \param a_crInstance - Constant reference to the current instance of the CBox class.
      \param a_crPoint - Constant reference to the instance of the CPoint3D class.
      \return New instance of CBox class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBox<T_OtherType> operator + (const CBox<T_OtherType>& a_crInstance, const CPoint3D<T_OtherOtherType>& a_crPoint);
  //! Operator: Add another CBox class instance.
  /*!
      Unite two boxs in a space into single box.

      \param a_crInstance1 - Constant reference to the current instance of the CBox class.
      \param a_crInstance2 - Constant reference to another instance of the CBox class.
      \return New instance of CBox class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBox<T_OtherType> operator + (const CBox<T_OtherType>& a_crInstance1, const CBox<T_OtherOtherType>& a_crInstance2);
  //! Operator: Add number.
  /*!
      Moves all box coordinates by fixed value.

      \param a_cValue - Number value.
      \param a_crInstance - Constant reference to the current instance of the CBox class.
      \return New instance of CBox class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBox<T_OtherType> operator + (const T_OtherOtherType a_cValue, const CBox<T_OtherType>& a_crInstance);
  //! Operator: Add CPoint3D class instance.
  /*!
      Moves all box coordinates by vector in a space.

      \param a_crPoint - Constant reference to the instance of the CPoint3D class.
      \param a_crInstance - Constant reference to the current instance of the CBox class.
      \return New instance of CBox class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBox<T_OtherType> operator + (const CPoint3D<T_OtherOtherType>& a_crPoint, const CBox<T_OtherType>& a_crInstance);

  //! Operator: Sub number.
  /*!
      Moves all box coordinates by fixed value.

      \param a_crInstance - Constant reference to the current instance of the CBox class.
      \param a_cValue - Number value.
      \return New instance of CBox class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBox<T_OtherType> operator - (const CBox<T_OtherType>& a_crInstance, const T_OtherOtherType a_cValue);
  //! Operator: Sub CPoint3D class instance.
  /*!
      Moves all box coordinates by vector in a space.

      \param a_crInstance - Constant reference to the current instance of the CBox class.
      \param a_crPoint - Constant reference to the instance of the CPoint3D class.
      \return New instance of CBox class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBox<T_OtherType> operator - (const CBox<T_OtherType>& a_crInstance, const CPoint3D<T_OtherOtherType>& a_crPoint);
  //! Operator: Sub another CBox class instance.
  /*!
      Find intersection of two boxs in a space as a single box.

      \param a_crInstance1 - Constant reference to the current instance of the CBox class.
      \param a_crInstance2 - Constant reference to another instance of the CBox class.
      \return New instance of CBox class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBox<T_OtherType> operator - (const CBox<T_OtherType>& a_crInstance1, const CBox<T_OtherOtherType>& a_crInstance2);
  //! Operator: Sub number.
  /*!
      Moves all box coordinates by fixed value.

      \param a_cValue - Number value.
      \param a_crInstance - Constant reference to the current instance of the CBox class.
      \return New instance of CBox class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBox<T_OtherType> operator - (const T_OtherOtherType a_cValue, const CBox<T_OtherType>& a_crInstance);
  //! Operator: Sub CPoint3D class instance.
  /*!
      Moves all box coordinates by vector in a space.

      \param a_crPoint - Constant reference to the instance of the CPoint3D class.
      \param a_crInstance - Constant reference to the current instance of the CBox class.
      \return New instance of CBox class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CBox<T_OtherType> operator - (const CPoint3D<T_OtherOtherType>& a_crPoint, const CBox<T_OtherType>& a_crInstance);

  //! Operator: Assign another CBox class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBox class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CBox<T_Type>& operator = (const CBox<T_OtherType>& a_crInstance);

  //! Operator: Add and assign number.
  /*!
      Moves all box coordinates by fixed value.

      \param a_cValue - Number value.
      \return Reference to the current class instance.
  */
  CBox<T_Type>& operator += (const T_Type a_cValue);
  //! Operator: Add and assign CPoint3D class instance.
  /*!
      Moves all box coordinates by vector in a space.

      \param a_crPoint - Constant reference to the instance of the CPoint3D class.
      \return Reference to the current class instance.
  */
  CBox<T_Type>& operator += (const CPoint3D<T_Type>& a_crPoint);
  //! Operator: Add and assign another CBox class instance.
  /*!
      Unite two boxs in a space into single box.

      \param a_crInstance - Constant reference to another instance of the CBox class.
      \return Reference to the current class instance.
  */
  CBox<T_Type>& operator += (const CBox<T_Type>& a_crInstance);

  //! Operator: Sub and assign number.
  /*!
      Moves all box coordinates by fixed value.

      \param a_cValue - Number value.
      \return Reference to the current class instance.
  */
  CBox<T_Type>& operator -= (const T_Type a_cValue);
  //! Operator: Sub and assign CPoint3D class instance.
  /*!
      Moves all box coordinates by vector in a space.

      \param a_crPoint - Constant reference to the instance of the CPoint3D class.
      \return Reference to the current class instance.
  */
  CBox<T_Type>& operator -= (const CPoint3D<T_Type>& a_crPoint);
  //! Operator: Sub and assign another CBox class instance.
  /*!
      Find intersection of two boxs in a space as a single box.

      \param a_crInstance - Constant reference to another instance of the CBox class.
      \return Reference to the current class instance.
  */
  CBox<T_Type>& operator -= (const CBox<T_Type>& a_crInstance);

  //! Set box points' coordinates.
  /*!
      \param a_cX1 - X coordinate of the left-bottom-deep point.
      \param a_cY1 - Y coordinate of the left-bottom-deep point.
      \param a_cZ1 - Z coordinate of the left-bottom-deep point.
      \param a_cX2 - X coordinate of the right-top-high point.
      \param a_cY2 - Y coordinate of the right-top-high point.
      \param a_cZ2 - Z coordinate of the right-top-high point.
  */
  void set(const T_Type a_cX1, const T_Type a_cY1, const T_Type a_cZ1, const T_Type a_cX2, const T_Type a_cY2, const T_Type a_cZ2);
  //! Set box points.
  /*!
      \param a_crA - Box's left-bottom point.
      \param a_crB - Box's right-top point.
  */
  void set(const CPoint3D<T_Type>& a_crA, const CPoint3D<T_Type>& a_crB);
  //! Set box points' coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
  */
  void set(const T_Type a_cpCoordinatesBuffer[]);
  //! Set another CBox class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBox class.
  */
  template <typename T_OtherType>
  void set(const CBox<T_OtherType>& a_crInstance);

  //! Is box 'empty'?
  /*!
      If box left-bottom-deep point  has  X  coordinate  which  is  more  than
      right-top-high point X coordinate or box left-bottom-deep  point  has  Y
      coordinate which is more than right-top-high point Y coordinate  or  the
      same thing with Z coordinate, than our box is  in  'empty'  state.  This
      method helps to check such situation.

      \return true  - if current box is 'empty'. \n
              false - if current box is 'normal'. \n
  */
  Tbool isEmpty() const;
  //! Is box 'normal'?
  /*!
      Opposite method to 'isEmpty()' one.

      \return true  - if current box is 'normal'. \n
              false - if current box is 'empty'. \n
  */
  Tbool isNormal() const;

  //! Is point inside current box?
  /*!
      \param a_crPoint - Constant reference to the instance of the CPoint3D class.
      \return true  - if point is inside current box. \n
              false - if point is not inside current box. \n
  */
  Tbool isInside(const CPoint3D<T_Type>& a_crPoint) const;
  //! Is another box inside current box?
  /*!
      \param a_crBox - Constant reference to another instance of the CBox class.
      \return true  - if another box is inside current box. \n
              false - if another box isn't inside current box. \n
  */
  Tbool isInside(const CBox<T_Type>& a_crBox) const;

  //! Does another box intersect current box?
  /*!
      \param a_crBox - Constant reference to another instance of the CBox class.
      \return true  - if another box intersects current box. \n
              false - if another box does not intersect current box. \n
  */
  Tbool isIntersect(const CBox<T_Type>& a_crBox) const;

  //! Get box width?
  /*!
      \return Rectangle width value.
  */
  T_Type getWidth() const;
  //! Get box height?
  /*!
      \return Rectangle height value.
  */
  T_Type getHeight() const;
  //! Get box depth?
  /*!
      \return Rectangle depth value.
  */
  T_Type getDepth() const;

  //! Get 'empty' box.
  /*!
      Method checks coordinates of current box, adapt them, and return
      'empty' box.

      \return Adapted 'empty' box based on current one.
  */
  CBox<T_Type> getEmpty() const;
  //! Get 'normal' box.
  /*!
      Method checks coordinates of current box, adapt them, and return
      'normal' box.

      \return Adapted 'normal' box based on current one.
  */
  CBox<T_Type> getNormal() const;

  //! Find and get the intersection of two boxs.
  /*!
      \param a_crBox - Constant reference to another instance of the CBox class.
      \return Box as intersection of two other boxs.
  */
  CBox<T_Type> getIntersection(const CBox<T_Type>& a_crBox) const;

  //! Find and get the union of current box and point in a space.
  /*!
      \param a_crPoint - Constant reference to the instance of the CPoint3D class.
      \return Box as union of current box and point in a space.
  */
  CBox<T_Type> getUnion(const CPoint3D<T_Type>& a_crPoint) const;
  //! Find and get the union of two boxs.
  /*!
      \param a_crBox - Constant reference to another instance of the CBox class.
      \return Box as union of two other boxs.
  */
  CBox<T_Type> getUnion(const CBox<T_Type>& a_crBox) const;

  //! Set current CBox coordinates to zeros.
  void clear();
  //! Inverse CBox coordinate.
  void inverse();

  //! Move box by fixed vector among the plane.
  /*!
      \param a_crPoint - Constant reference to the instance of the CPoint3D class.
  */
  void moveBy(const CPoint3D<T_Type>& a_crPoint);
  //! Move box to fixed point in a space.
  /*!
      \param a_crPoint - Constant reference to the instance of the CPoint3D class.
  */
  void moveTo(const CPoint3D<T_Type>& a_crPoint);

  //! Serialize CBox class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBox class instances.
  /*!
      \param a_rInstance - Reference to another CBox class instance.
  */
  void swap(CBox<T_Type>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CBox.inl>
/*==========================================================================*/
//! \example example-geometry-CBox.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CBox.cpp
/*==========================================================================*/
#endif
