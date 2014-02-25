/*!
 *  \file    CRect.hpp Template representation of the rectangle on a plane.
 *  \brief   Rectangle on a plane template class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Rectangle on a plane template class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   10.02.2006 21:10:32

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
#ifndef __CRECT_HPP__
#define __CRECT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMax.hpp>
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/algorithms/common/AMinMax.hpp>
#include <Depth/include/concept/base/MConceptNumber.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CPoint2D.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Rectangle on a plane template class.
/*!
    Class represents 2-dimension rectangle on a plane. It contains  two  point
    values for the left-bottom side of the rectangle  and  for  the  right-top
    side of the rectangle [ A(x1, y1), B(x2, y2) ].

    \code
    y ^
      |                    B(x2, y2)
      |     +--------------+
      |     |              |
      |     |  Rectangle   |
      |     |              |
      |     +--------------+
      |     A(x1, y1)
      |
      |
    --+-----------------------------> x
      |
    \endcode
*/
template <typename T_Type>
class CRect
{
  //! Type for MConceptNumber constraint checking.
  typedef T_Type TNumberCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CRect<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be a number type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptNumber, TNumberCheckType);
  // Check CRect class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Rectangle value template type.
  typedef T_Type TType;

  CPoint2D<T_Type> m_A;                 //!< Rectangle left-bottom point.
  CPoint2D<T_Type> m_B;                 //!< Rectangle right-top point.

  //! Default class constructor.
  /*!
      Set rectangle coordinates into begin of the plane coordinate system:
      [ A(0.0, 0.0), B(0.0, 0.0) ].
  */
  CRect();
  //! Initialize rectangle points' coordinates.
  /*!
      \param a_cX1 - X coordinate of the left-bottom point.
      \param a_cY1 - Y coordinate of the left-bottom point.
      \param a_cX2 - X coordinate of the right-top point.
      \param a_cY2 - Y coordinate of the right-top point.
  */
  CRect(const T_Type a_cX1, const T_Type a_cY1, const T_Type a_cX2, const T_Type a_cY2);
  //! Initialize rectangle points.
  /*!
      \param a_crA - Rectangle's left-bottom point.
      \param a_crB - Rectangle's right-top point.
  */
  CRect(const CPoint2D<T_Type>& a_crA, const CPoint2D<T_Type>& a_crB);
  //! Initialize rectangle points' coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
  */
  CRect(const T_Type a_cpCoordinatesBuffer[]);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRect class.
  */
  template <typename T_OtherType>
  CRect(const CRect<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~CRect();

  //! Operator: Equal to another CRect class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CRect class.
      \param a_crInstance2 - Constant reference to another instance of the CRect class.
      \return true  - if CRect class instance is equal to another one. \n
              false - if CRect class instance is not equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator == (const CRect<T_OtherType>& a_crInstance1, const CRect<T_OtherOtherType>& a_crInstance2);

  //! Operator: Not equal to another CRect class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CRect class.
      \param a_crInstance2 - Constant reference to another instance of the CRect class.
      \return true  - if CRect class instance is not equal to another one. \n
              false - if CRect class instance is equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator != (const CRect<T_OtherType>& a_crInstance1, const CRect<T_OtherOtherType>& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Applies unary plus operator to all rectangle coordinates.

      \param a_crInstance - Constant reference to the current instance of the CRect class.
      \return New instance of CRect class with applied plus operator.
  */
  template <typename T_OtherType>
  friend CRect<T_OtherType> operator + (const CRect<T_OtherType>& a_crInstance);
  //! Operator: Unary minus.
  /*!
      Applies unary minus operator to all rectangle coordinates.

      \param a_crInstance - Constant reference to the current instance of the CRect class.
      \return New instance of CRect class with applied minus operator.
  */
  template <typename T_OtherType>
  friend CRect<T_OtherType> operator - (const CRect<T_OtherType>& a_crInstance);

  //! Operator: Add number.
  /*!
      Moves all rectangle coordinates by fixed value.

      \param a_crInstance - Constant reference to the current instance of the CRect class.
      \param a_cValue - Number value.
      \return New instance of CRect class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CRect<T_OtherType> operator + (const CRect<T_OtherType>& a_crInstance, const T_OtherOtherType a_cValue);
  //! Operator: Add CPoint2D class instance.
  /*!
      Moves all rectangle coordinates by vector on a plane.

      \param a_crInstance - Constant reference to the current instance of the CRect class.
      \param a_crPoint - Constant reference to the instance of the CPoint2D class.
      \return New instance of CRect class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CRect<T_OtherType> operator + (const CRect<T_OtherType>& a_crInstance, const CPoint2D<T_OtherOtherType>& a_crPoint);
  //! Operator: Add another CRect class instance.
  /*!
      Unite two rectangles on a plane into single rectangle.

      \param a_crInstance1 - Constant reference to the current instance of the CRect class.
      \param a_crInstance2 - Constant reference to another instance of the CRect class.
      \return New instance of CRect class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CRect<T_OtherType> operator + (const CRect<T_OtherType>& a_crInstance1, const CRect<T_OtherOtherType>& a_crInstance2);
  //! Operator: Add number.
  /*!
      Moves all rectangle coordinates by fixed value.

      \param a_cValue - Number value.
      \param a_crInstance - Constant reference to the current instance of the CRect class.
      \return New instance of CRect class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CRect<T_OtherType> operator + (const T_OtherOtherType a_cValue, const CRect<T_OtherType>& a_crInstance);
  //! Operator: Add CPoint2D class instance.
  /*!
      Moves all rectangle coordinates by vector on a plane.

      \param a_crPoint - Constant reference to the instance of the CPoint2D class.
      \param a_crInstance - Constant reference to the current instance of the CRect class.
      \return New instance of CRect class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CRect<T_OtherType> operator + (const CPoint2D<T_OtherOtherType>& a_crPoint, const CRect<T_OtherType>& a_crInstance);

  //! Operator: Sub number.
  /*!
      Moves all rectangle coordinates by fixed value.

      \param a_crInstance - Constant reference to the current instance of the CRect class.
      \param a_cValue - Number value.
      \return New instance of CRect class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CRect<T_OtherType> operator - (const CRect<T_OtherType>& a_crInstance, const T_OtherOtherType a_cValue);
  //! Operator: Sub CPoint2D class instance.
  /*!
      Moves all rectangle coordinates by vector on a plane.

      \param a_crInstance - Constant reference to the current instance of the CRect class.
      \param a_crPoint - Constant reference to the instance of the CPoint2D class.
      \return New instance of CRect class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CRect<T_OtherType> operator - (const CRect<T_OtherType>& a_crInstance, const CPoint2D<T_OtherOtherType>& a_crPoint);
  //! Operator: Sub another CRect class instance.
  /*!
      Find intersection of two rectangles on a plane as a single rectangle.

      \param a_crInstance1 - Constant reference to the current instance of the CRect class.
      \param a_crInstance2 - Constant reference to another instance of the CRect class.
      \return New instance of CRect class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CRect<T_OtherType> operator - (const CRect<T_OtherType>& a_crInstance1, const CRect<T_OtherOtherType>& a_crInstance2);
  //! Operator: Sub number.
  /*!
      Moves all rectangle coordinates by fixed value.

      \param a_cValue - Number value.
      \param a_crInstance - Constant reference to the current instance of the CRect class.
      \return New instance of CRect class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CRect<T_OtherType> operator - (const T_OtherOtherType a_cValue, const CRect<T_OtherType>& a_crInstance);
  //! Operator: Sub CPoint2D class instance.
  /*!
      Moves all rectangle coordinates by vector on a plane.

      \param a_crPoint - Constant reference to the instance of the CPoint2D class.
      \param a_crInstance - Constant reference to the current instance of the CRect class.
      \return New instance of CRect class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CRect<T_OtherType> operator - (const CPoint2D<T_OtherOtherType>& a_crPoint, const CRect<T_OtherType>& a_crInstance);

  //! Operator: Assign another CRect class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRect class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CRect<T_Type>& operator = (const CRect<T_OtherType>& a_crInstance);

  //! Operator: Add and assign number.
  /*!
      Moves all rectangle coordinates by fixed value.

      \param a_cValue - Number value.
      \return Reference to the current class instance.
  */
  CRect<T_Type>& operator += (const T_Type a_cValue);
  //! Operator: Add and assign CPoint2D class instance.
  /*!
      Moves all rectangle coordinates by vector on a plane.

      \param a_crPoint - Constant reference to the instance of the CPoint2D class.
      \return Reference to the current class instance.
  */
  CRect<T_Type>& operator += (const CPoint2D<T_Type>& a_crPoint);
  //! Operator: Add and assign another CRect class instance.
  /*!
      Unite two rectangles on a plane into single rectangle.

      \param a_crInstance - Constant reference to another instance of the CRect class.
      \return Reference to the current class instance.
  */
  CRect<T_Type>& operator += (const CRect<T_Type>& a_crInstance);

  //! Operator: Sub and assign number.
  /*!
      Moves all rectangle coordinates by fixed value.

      \param a_cValue - Number value.
      \return Reference to the current class instance.
  */
  CRect<T_Type>& operator -= (const T_Type a_cValue);
  //! Operator: Sub and assign CPoint2D class instance.
  /*!
      Moves all rectangle coordinates by vector on a plane.

      \param a_crPoint - Constant reference to the instance of the CPoint2D class.
      \return Reference to the current class instance.
  */
  CRect<T_Type>& operator -= (const CPoint2D<T_Type>& a_crPoint);
  //! Operator: Sub and assign another CRect class instance.
  /*!
      Find intersection of two rectangles on a plane as a single rectangle.

      \param a_crInstance - Constant reference to another instance of the CRect class.
      \return Reference to the current class instance.
  */
  CRect<T_Type>& operator -= (const CRect<T_Type>& a_crInstance);

  //! Set rectangle points' coordinates.
  /*!
      \param a_cX1 - X coordinate of the left-bottom point.
      \param a_cY1 - Y coordinate of the left-bottom point.
      \param a_cX2 - X coordinate of the right-top point.
      \param a_cY2 - Y coordinate of the right-top point.
  */
  void set(const T_Type a_cX1, const T_Type a_cY1, const T_Type a_cX2, const T_Type a_cY2);
  //! Set rectangle points.
  /*!
      \param a_crA - Rectangle's left-bottom point.
      \param a_crB - Rectangle's right-top point.
  */
  void set(const CPoint2D<T_Type>& a_crA, const CPoint2D<T_Type>& a_crB);
  //! Set rectangle points' coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
  */
  void set(const T_Type a_cpCoordinatesBuffer[]);
  //! Set another CRect class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRect class.
  */
  template <typename T_OtherType>
  void set(const CRect<T_OtherType>& a_crInstance);

  //! Is rectangle 'empty'?
  /*!
      If rectangle left-bottom point has  X  coordinate  which  is  more  than
      right-top point X  coordinate  or  rectangle  left-bottom  point  has  Y
      coordinate which is more than right-top point  Y  coordinate,  than  our
      rectangle  is  in  'empty'  state.  This  method  helps  to  check  such
      situation.

      \return true  - if current rectangle is 'empty'. \n
              false - if current rectangle is 'normal'. \n
  */
  Tbool isEmpty() const;
  //! Is rectangle 'normal'?
  /*!
      Opposite method to 'isEmpty()' one.

      \return true  - if current rectangle is 'normal'. \n
              false - if current rectangle is 'empty'. \n
  */
  Tbool isNormal() const;

  //! Is point inside current rectangle?
  /*!
      \param a_crPoint - Constant reference to the instance of the CPoint2D class.
      \return true  - if point is inside current rectangle. \n
              false - if point is not inside current rectangle. \n
  */
  Tbool isInside(const CPoint2D<T_Type>& a_crPoint) const;
  //! Is another rectangle inside current rectangle?
  /*!
      \param a_crRect - Constant reference to another instance of the CRect class.
      \return true  - if another rectangle is inside current rectangle. \n
              false - if another rectangle isn't inside current rectangle. \n
  */
  Tbool isInside(const CRect<T_Type>& a_crRect) const;

  //! Does another rectangle intersect current rectangle?
  /*!
      \param a_crRect - Constant reference to another instance of the CRect class.
      \return true  - if another rectangle intersects current rectangle. \n
              false - if another rectangle does not intersect current rectangle. \n
  */
  Tbool isIntersect(const CRect<T_Type>& a_crRect) const;

  //! Get rectangle width?
  /*!
      \return Rectangle width value.
  */
  T_Type getWidth() const;
  //! Get rectangle height?
  /*!
      \return Rectangle height value.
  */
  T_Type getHeight() const;

  //! Get 'empty' rectangle.
  /*!
      Method checks coordinates of current rectangle, adapt them,  and  return
      'empty' rectangle.

      \return Adapted 'empty' rectangle based on current one.
  */
  CRect<T_Type> getEmpty() const;
  //! Get 'normal' rectangle.
  /*!
      Method checks coordinates of current rectangle, adapt them,  and  return
      'normal' rectangle.

      \return Adapted 'normal' rectangle based on current one.
  */
  CRect<T_Type> getNormal() const;

  //! Find and get the intersection of two rectangles.
  /*!
      \param a_crRect - Constant reference to another instance of the CRect class.
      \return Rectangle as intersection of two other rectangles.
  */
  CRect<T_Type> getIntersection(const CRect<T_Type>& a_crRect) const;

  //! Find and get the union of current rectangle and point on a plane.
  /*!
      \param a_crPoint - Constant reference to the instance of the CPoint2D class.
      \return Rectangle as union of current rectangle and point on a plane.
  */
  CRect<T_Type> getUnion(const CPoint2D<T_Type>& a_crPoint) const;
  //! Find and get the union of two rectangles.
  /*!
      \param a_crRect - Constant reference to another instance of the CRect class.
      \return Rectangle as union of two other rectangles.
  */
  CRect<T_Type> getUnion(const CRect<T_Type>& a_crRect) const;

  //! Set current CRect coordinates to zeros.
  void clear();
  //! Inverse CRect coordinate.
  void inverse();

  //! Move rectangle by fixed vector among the plane.
  /*!
      \param a_crPoint - Constant reference to the instance of the CPoint2D class.
  */
  void moveBy(const CPoint2D<T_Type>& a_crPoint);
  //! Move rectangle to fixed point on a plane.
  /*!
      \param a_crPoint - Constant reference to the instance of the CPoint2D class.
  */
  void moveTo(const CPoint2D<T_Type>& a_crPoint);

  //! Serialize CRect class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRect class instances.
  /*!
      \param a_rInstance - Reference to another CRect class instance.
  */
  void swap(CRect<T_Type>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CRect.inl>
/*==========================================================================*/
//! \example example-geometry-CRect.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CRect.cpp
/*==========================================================================*/
#endif
