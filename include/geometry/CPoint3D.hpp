/*!
 *  \file    CPoint3D.hpp Template representation of the point in a space.
 *  \brief   Point in a space template class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Point in a space template class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   09.02.2006 00:00:32

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
#ifndef __CPOINT3D_HPP__
#define __CPOINT3D_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/numeric/AAbsolute.hpp>
#include <Depth/include/concept/base/MConceptNumber.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
template <typename T_Type>
class CPoint2D;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Point in a space template class.
/*!
    Class  represents  3-dimension  point  in  a  space.  It  contains   three
    coordinates values for each plane axis (x, y, z).
*/
template <typename T_Type>
class CPoint3D
{
  //! Type for MConceptNumber constraint checking.
  typedef T_Type TNumberCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CPoint3D<T_Type> TDepthCheckType;

  // Check T_Type template argument constraint to be a number type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptNumber, TNumberCheckType);
  // Check CPoint3D class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Point in a space value template type.
  typedef T_Type TType;

  T_Type m_X;                           //!< X coordinate of the point.
  T_Type m_Y;                           //!< Y coordinate of the point.
  T_Type m_Z;                           //!< Z coordinate of the point.

  //! Default class constructor.
  /*!
      Set point into begin of the plane coordinate system (0, 0, 0).
  */
  CPoint3D();
  //! Initialize point's coordinates.
  /*!
      \param a_cX - X coordinate of the point.
      \param a_cY - Y coordinate of the point.
      \param a_cZ - Z coordinate of the point.
  */
  CPoint3D(const T_Type a_cX, const T_Type a_cY, const T_Type a_cZ);
  //! Initialize point's coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
  */
  CPoint3D(const T_Type a_cpCoordinatesBuffer[]);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint2D class.
  */
  template <typename T_OtherType>
  CPoint3D(const CPoint2D<T_OtherType>& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
  */
  template <typename T_OtherType>
  CPoint3D(const CPoint3D<T_OtherType>& a_crInstance);
  //! Class destructor.
 ~CPoint3D();

  //! Operator: Equal to another CPoint3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CPoint3D class.
      \param a_crInstance2 - Constant reference to another instance of the CPoint3D class.
      \return true  - if CPoint3D class instance is equal to another one. \n
              false - if CPoint3D class instance is not equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator == (const CPoint3D<T_OtherType>& a_crInstance1, const CPoint2D<T_OtherOtherType>& a_crInstance2);

  //! Operator: Not equal to another CPoint3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CPoint3D class.
      \param a_crInstance2 - Constant reference to another instance of the CPoint3D class.
      \return true  - if CPoint3D class instance is not equal to another one. \n
              false - if CPoint3D class instance is equal to another one. \n
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend Tbool operator != (const CPoint3D<T_OtherType>& a_crInstance1, const CPoint2D<T_OtherOtherType>& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Applies unary plus operator to all point coordinates.

      \param a_crInstance - Constant reference to the current instance of the CPoint3D class.
      \return New instance of CPoint3D class with applied plus operator.
  */
  template <typename T_OtherType>
  friend CPoint3D<T_OtherType> operator + (const CPoint2D<T_OtherType>& a_crInstance);
  //! Operator: Unary minus.
  /*!
      Applies unary minus operator to all point coordinates.

      \param a_crInstance - Constant reference to the current instance of the CPoint3D class.
      \return New instance of CPoint3D class with applied minus operator.
  */
  template <typename T_OtherType>
  friend CPoint3D<T_OtherType> operator - (const CPoint2D<T_OtherType>& a_crInstance);

  //! Operator: Add number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CPoint3D class.
      \param a_cValue - Number value.
      \return New instance of CPoint3D class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator + (const CPoint2D<T_OtherType>& a_crInstance, const T_OtherType a_cValue);
  //! Operator: Add another CPoint3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CPoint3D class.
      \param a_crInstance2 - Constant reference to another instance of the CPoint3D class.
      \return New instance of CPoint3D class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator + (const CPoint3D<T_OtherType>& a_crInstance1, const CPoint2D<T_OtherOtherType>& a_crInstance2);
  //! Operator: Add number.
  /*!
      \param a_cValue - Number value.
      \param a_crInstance - Constant reference to the current instance of the CPoint3D class.
      \return New instance of CPoint3D class with applied add operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator + (const T_OtherOtherType a_cValue, const CPoint3D<T_OtherType>& a_crInstance);

  //! Operator: Sub number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CPoint3D class.
      \param a_cValue - Number value.
      \return New instance of CPoint3D class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator - (const CPoint2D<T_OtherType>& a_crInstance, const T_OtherOtherType a_cValue);
  //! Operator: Sub another CPoint3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CPoint3D class.
      \param a_crInstance2 - Constant reference to another instance of the CPoint3D class.
      \return New instance of CPoint3D class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator - (const CPoint3D<T_OtherType>& a_crInstance1, const CPoint2D<T_OtherOtherType>& a_crInstance2);
  //! Operator: Sub number.
  /*!
      \param a_cValue - Number value.
      \param a_crInstance - Constant reference to the current instance of the CPoint3D class.
      \return New instance of CPoint3D class with applied sub operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator - (const T_OtherOtherType a_cValue, const CPoint3D<T_OtherType>& a_crInstance);

  //! Operator: Mul number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CPoint3D class.
      \param a_cValue - Number value.
      \return New instance of CPoint3D class with applied mul operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator * (const CPoint2D<T_OtherType>& a_crInstance, const T_OtherOtherType a_cValue);
  //! Operator: Mul another CPoint3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CPoint3D class.
      \param a_crInstance2 - Constant reference to another instance of the CPoint3D class.
      \return New instance of CPoint3D class with applied mul operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator * (const CPoint3D<T_OtherType>& a_crInstance1, const CPoint2D<T_OtherOtherType>& a_crInstance2);
  //! Operator: Mul number.
  /*!
      \param a_cValue - Number value.
      \param a_crInstance - Constant reference to the current instance of the CPoint3D class.
      \return New instance of CPoint3D class with applied mul operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator * (const T_OtherOtherType a_cValue, const CPoint3D<T_OtherType>& a_crInstance);

  //! Operator: Div number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CPoint3D class.
      \param a_cValue - Number value.
      \return New instance of CPoint3D class with applied div operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator / (const CPoint2D<T_OtherType>& a_crInstance, const T_OtherOtherType a_cValue);
  //! Operator: Div another CPoint3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CPoint3D class.
      \param a_crInstance2 - Constant reference to another instance of the CPoint3D class.
      \return New instance of CPoint3D class with applied div operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator / (const CPoint3D<T_OtherType>& a_crInstance1, const CPoint2D<T_OtherOtherType>& a_crInstance2);
  //! Operator: Div number.
  /*!
      \param a_cValue - Number value.
      \param a_crInstance - Constant reference to the current instance of the CPoint3D class.
      \return New instance of CPoint3D class with applied div operator.
  */
  template <typename T_OtherType, typename T_OtherOtherType>
  friend CPoint3D<T_OtherType> operator / (const T_OtherOtherType a_cValue, const CPoint3D<T_OtherType>& a_crInstance);

  //! Operator: Assign number.
  /*!
      \param a_cValue - Number value.
      \return Reference to the current class instance.
  */
  CPoint3D<T_Type>& operator = (const T_Type a_cValue);
  //! Operator: Assign another CPoint2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint2D class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CPoint3D<T_Type>& operator = (const CPoint2D<T_OtherType>& a_crInstance);
  //! Operator: Assign another CPoint3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
      \return Reference to the current class instance.
  */
  template <typename T_OtherType>
  CPoint3D<T_Type>& operator = (const CPoint3D<T_OtherType>& a_crInstance);

  //! Operator: Add and assign number.
  /*!
      \param a_cValue - Number value.
      \return Reference to the current class instance.
  */
  CPoint3D<T_Type>& operator += (const T_Type a_cValue);
  //! Operator: Add and assign another CPoint3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
      \return Reference to the current class instance.
  */
  CPoint3D<T_Type>& operator += (const CPoint3D<T_Type>& a_crInstance);
  //! Operator: Sub and assign number.
  /*!
      \param a_cValue - Number value.
      \return Reference to the current class instance.
  */
  CPoint3D<T_Type>& operator -= (const T_Type a_cValue);
  //! Operator: Sub and assign another CPoint3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
      \return Reference to the current class instance.
  */
  CPoint3D<T_Type>& operator -= (const CPoint3D<T_Type>& a_crInstance);
  //! Operator: Mul and assign number.
  /*!
      \param a_cValue - Number value.
      \return Reference to the current class instance.
  */
  CPoint3D<T_Type>& operator *= (const T_Type a_cValue);
  //! Operator: Mul and assign another CPoint3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
      \return Reference to the current class instance.
  */
  CPoint3D<T_Type>& operator *= (const CPoint3D<T_Type>& a_crInstance);
  //! Operator: Div and assign number.
  /*!
      \param a_cValue - Number value.
      \return Reference to the current class instance.
  */
  CPoint3D<T_Type>& operator /= (const T_Type a_cValue);
  //! Operator: Div and assign another CPoint3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
      \return Reference to the current class instance.
  */
  CPoint3D<T_Type>& operator /= (const CPoint3D<T_Type>& a_crInstance);

  //! Set point's coordinates.
  /*!
      \param a_cX - X coordinate of the point.
      \param a_cY - Y coordinate of the point.
      \param a_cZ - Z coordinate of the point.
  */
  void set(const T_Type a_cX, const T_Type a_cY, const T_Type a_cZ);
  //! Set point's coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
  */
  void set(const T_Type a_cpCoordinatesBuffer[]);
  //! Set another CPoint2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint2D class.
  */
  template <typename T_OtherType>
  void set(const CPoint2D<T_OtherType>& a_crInstance);
  //! Set another CPoint3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
  */
  template <typename T_OtherType>
  void set(const CPoint3D<T_OtherType>& a_crInstance);

  //! Set point coordinates to zeros.
  void clear();
  //! Set point coordinates to their absolute values.
  void absolute();
  //! Negative point coordinate.
  void negate();

  //! Serialize CPoint3D class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CPoint3D class instances.
  /*!
      \param a_rInstance - Reference to another CPoint3D class instance.
  */
  void swap(CPoint3D<T_Type>& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CPoint2D.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/geometry/CPoint3D.inl>
/*==========================================================================*/
//! \example example-geometry-CPoint3D.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CPoint3D.cpp
/*==========================================================================*/
#endif
