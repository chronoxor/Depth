/*!
 *  \file    CVector2D.hpp Representation of the vector on a plane.
 *  \brief   Vector on a plane class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Vector on a plane class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   27.06.2008 20:11:11

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
#ifndef __CVECTOR2D_HPP__
#define __CVECTOR2D_HPP__
/*==========================================================================*/
#include <Depth/include/geometry.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CPoint2D.hpp>
#include <Depth/include/geometry/CPoint3D.hpp>
#include <Depth/include/math/CMath.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
class CVector3D;
class CVector4D;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Vector on a plane class.
/*!
    Class represents 2-dimension vector on a plane. It contains two coordinates
    values for each plane axis (x, y).

    Additionally  class  of  the  vector  on  a  plane  provides   common   2D
    functionality for vectors: collinear detection,  calculation  of  the  dot
    product, normalization, linear interpolation, rotating, etc.
*/
class GEOMETRY_API CVector2D
{
  //! Type for MConceptDepthType constraint checking.
  typedef CVector2D TDepthCheckType;

  // Check CVector2D class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  Treal m_X;                            //!< X coordinate of the vector.
  Treal m_Y;                            //!< Y coordinate of the vector.

  static const CVector2D ZERO;          //!< Zero vector on a plane.
  static const CVector2D UNIT_X;        //!< Unit X vector on a plane.
  static const CVector2D UNIT_Y;        //!< Unit Y vector on a plane.

  //! Default class constructor.
  /*!
      Set vector into begin of the plane coordinate system (0, 0).
  */
  CVector2D();
  //! Initialize vector's coordinates.
  /*!
      \param a_cX - X coordinate of the vector.
      \param a_cY - Y coordinate of the vector.
  */
  CVector2D(const Treal a_cX, const Treal a_cY);
  //! Initialize vector's coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
  */
  CVector2D(const Treal a_cpCoordinatesBuffer[]);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint2D class.
  */
  CVector2D(const CPoint2D<Treal>& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
  */
  CVector2D(const CPoint3D<Treal>& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector2D class.
  */
  CVector2D(const CVector2D& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector3D class.
  */
  CVector2D(const CVector3D& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector4D class.
  */
  CVector2D(const CVector4D& a_crInstance);
  //! Class destructor.
 ~CVector2D();

  //! Operator: Equal to another CVector2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector2D class.
      \return true  - if CVector2D class instance is equal to another one. \n
              false - if CVector2D class instance is not equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator == (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Operator: Not equal to another CVector2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector2D class.
      \return true  - if CVector2D class instance is not equal to another one. \n
              false - if CVector2D class instance is equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator != (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);

  //! Operator: Check if the length of the first vector is less than the length of the second one.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return true  - if the length of the first vector is less than the length of the second one. \n
              false - if the length of the first vector is not less than the length of the second one. \n
  */
  friend GEOMETRY_API Tbool operator < (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Operator: Check if the length of the first vector is greater than the length of the second one.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return true  - if the length of the first vector is greater than the length of the second one. \n
              false - if the length of the first vector is not greater than the length of the second one. \n
  */
  friend GEOMETRY_API Tbool operator > (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Operator: Check if the length of the first vector is less or equal to the length of the second one.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return true  - if the length of the first vector is or equal to the length of the second one. \n
              false - if the length of the first vector is not or equal to the length of the second one. \n
  */
  friend GEOMETRY_API Tbool operator <= (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Operator: Check if the length of the first vector is greater or equal to the length of the second one.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return true  - if the length of the first vector is greater or equal to the length of the second one. \n
              false - if the length of the first vector is not greater or equal to the length of the second one. \n
  */
  friend GEOMETRY_API Tbool operator >= (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Applies unary plus operator to all vector coordinates.

      \param a_crInstance - Constant reference to the current instance of the CVector2D class.
      \return New instance of CVector2D class with applied plus operator.
  */
  friend GEOMETRY_API CVector2D operator + (const CVector2D& a_crInstance);
  //! Operator: Unary minus.
  /*!
      Applies unary minus operator to all vector coordinates.

      \param a_crInstance - Constant reference to the current instance of the CVector2D class.
      \return New instance of CVector2D class with applied minus operator.
  */
  friend GEOMETRY_API CVector2D operator - (const CVector2D& a_crInstance);

  //! Operator: Add real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CVector2D class.
      \param a_cValue - Real number value.
      \return New instance of CVector2D class with applied add operator.
  */
  friend GEOMETRY_API CVector2D operator + (const CVector2D& a_crInstance, const Treal a_cValue);
  //! Operator: Add another CVector2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector2D class.
      \return New instance of CVector2D class with applied add operator.
  */
  friend GEOMETRY_API CVector2D operator + (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Operator: Add real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CVector2D class.
      \return New instance of CVector2D class with applied add operator.
  */
  friend GEOMETRY_API CVector2D operator + (const Treal a_cValue, const CVector2D& a_crInstance);

  //! Operator: Sub real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CVector2D class.
      \param a_cValue - Real number value.
      \return New instance of CVector2D class with applied sub operator.
  */
  friend GEOMETRY_API CVector2D operator - (const CVector2D& a_crInstance, const Treal a_cValue);
  //! Operator: Sub another CVector2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector2D class.
      \return New instance of CVector2D class with applied sub operator.
  */
  friend GEOMETRY_API CVector2D operator - (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Operator: Sub real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CVector2D class.
      \return New instance of CVector2D class with applied sub operator.
  */
  friend GEOMETRY_API CVector2D operator - (const Treal a_cValue, const CVector2D& a_crInstance);

  //! Operator: Mul real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CVector2D class.
      \param a_cValue - Real number value.
      \return New instance of CVector2D class with applied mul operator.
  */
  friend GEOMETRY_API CVector2D operator * (const CVector2D& a_crInstance, const Treal a_cValue);
  //! Operator: Mul another CVector2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector2D class.
      \return New instance of CVector2D class with applied mul operator.
  */
  friend GEOMETRY_API CVector2D operator * (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Operator: Mul real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CVector2D class.
      \return New instance of CVector2D class with applied mul operator.
  */
  friend GEOMETRY_API CVector2D operator * (const Treal a_cValue, const CVector2D& a_crInstance);

  //! Operator: Div real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CVector2D class.
      \param a_cValue - Real number value.
      \return New instance of CVector2D class with applied div operator.
  */
  friend GEOMETRY_API CVector2D operator / (const CVector2D& a_crInstance, const Treal a_cValue);
  //! Operator: Div another CVector2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector2D class.
      \return New instance of CVector2D class with applied div operator.
  */
  friend GEOMETRY_API CVector2D operator / (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Operator: Div real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CVector2D class.
      \return New instance of CVector2D class with applied div operator.
  */
  friend GEOMETRY_API CVector2D operator / (const Treal a_cValue, const CVector2D& a_crInstance);

  //! Operator: Calculate the dot product of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector2D class.
      \return Dot product of two vectors.
  */
  friend GEOMETRY_API Treal operator ^ (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Operator: Calculate the Z component of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector2D class.
      \return Z component of two vectors.
  */
  friend GEOMETRY_API Treal operator | (const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);

  //! Operator: Assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CVector2D& operator = (const Treal a_cValue);
  //! Operator: Assign another CPoint2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint2D class.
      \return Reference to the current class instance.
  */
  CVector2D& operator = (const CPoint2D<Treal>& a_crInstance);
  //! Operator: Assign another CPoint3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
      \return Reference to the current class instance.
  */
  CVector2D& operator = (const CPoint3D<Treal>& a_crInstance);
  //! Operator: Assign another CVector2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector2D class.
      \return Reference to the current class instance.
  */
  CVector2D& operator = (const CVector2D& a_crInstance);
  //! Operator: Assign another CVector3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector3D class.
      \return Reference to the current class instance.
  */
  CVector2D& operator = (const CVector3D& a_crInstance);
  //! Operator: Assign another CVector4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector4D class.
      \return Reference to the current class instance.
  */
  CVector2D& operator = (const CVector4D& a_crInstance);

  //! Operator: Add and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CVector2D& operator += (const Treal a_cValue);
  //! Operator: Add and assign another CVector2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector2D class.
      \return Reference to the current class instance.
  */
  CVector2D& operator += (const CVector2D& a_crInstance);
  //! Operator: Sub and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CVector2D& operator -= (const Treal a_cValue);
  //! Operator: Sub and assign another CVector2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector2D class.
      \return Reference to the current class instance.
  */
  CVector2D& operator -= (const CVector2D& a_crInstance);
  //! Operator: Mul and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CVector2D& operator *= (const Treal a_cValue);
  //! Operator: Mul and assign another CVector2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector2D class.
      \return Reference to the current class instance.
  */
  CVector2D& operator *= (const CVector2D& a_crInstance);
  //! Operator: Div and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CVector2D& operator /= (const Treal a_cValue);
  //! Operator: Div and assign another CVector2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector2D class.
      \return Reference to the current class instance.
  */
  CVector2D& operator /= (const CVector2D& a_crInstance);

  //! Set vector's coordinates.
  /*!
      \param a_cX - X coordinate of the vector.
      \param a_cY - Y coordinate of the vector.
  */
  void set(const Treal a_cX, const Treal a_cY);
  //! Set vector's coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
  */
  void set(const Treal a_cpCoordinatesBuffer[]);
  //! Set another CPoint2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint2D class.
  */
  void set(const CPoint2D<Treal>& a_crInstance);
  //! Set another CPoint3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
  */
  void set(const CPoint3D<Treal>& a_crInstance);
  //! Set another CVector2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector2D class.
  */
  void set(const CVector2D& a_crInstance);
  //! Set another CVector3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector3D class.
  */
  void set(const CVector3D& a_crInstance);
  //! Set another CVector4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector4D class.
  */
  void set(const CVector4D& a_crInstance);

  //! Set CVector2D coordinates from the polar coordinates.
  /*!
      \param a_cAngle - Rotating angle.
      \param a_cRadius - Polar radius.
  */
  void setPolar(const Treal a_cAngle, const Treal a_cRadius);
  //! Get polar coordinates from the current CVector2D coordinates.
  /*!
      \param a_rAngle - Reference to the returning rotating angle.
      \param a_rRadius - Reference to the returning polar radius.
  */
  void getPolar(Treal& a_rAngle, Treal& a_rRadius) const;

  //! Set vector coordinates to zeros.
  void clear();
  //! Set vector coordinates to their absolute values.
  void absolute();
  //! Negative vector coordinate.
  void negate();

  //! Normalize vector.
  /*!
      This method makes the length of the current vector to be equal to 1, but
      keeps vector's direction.
  */
  void normalize();
  //! Normalize vector and get its previous length.
  /*!
      This method normalizes current vector, but  also  returns  its  previous
      length. The method is  intended  to  increase  the  performance  in  the
      geometry calculations.

      \return Length of the vector before the normalization.
  */
  Treal normalizeLength();

  //! Get length of the vector.
  /*!
      This method returns length of the current vector.  It  calculates  as  a
      distance from the beginning of the coordinate system origin  (0,  0)  to
      the vector coordinates (x, y).

      \return Length of the vector.
  */
  Treal length() const;
  //! Get squared length of the vector.
  /*!
      This method returns squared length of the current vector. It  calculates
      as a squared distance from the beginning of the coordinate system origin
      (0, 0) to the vector coordinates (x,  y).  The  method  is  intended  to
      increase the performance in the geometry calculations.

      \return Squared length of the vector.
  */
  Treal lengthSq() const;

  //! Rotate vector.
  /*!
      \param a_cAngle - Rotating angle.
      \return Rotated vector.
  */
  CVector2D rotate(const Treal a_cAngle) const;
  //! Scale vector.
  /*!
      \param a_cScaleX - Scale value along the X axis.
      \param a_cScaleY - Scale value along the Y axis.
      \return Scaled vector.
  */
  CVector2D scale(const Treal a_cScaleX, const Treal a_cScaleY) const;
  //! Translate vector.
  /*!
      \param a_cTranslateX - Translate value along the X axis.
      \param a_cTranslateY - Translate value along the Y axis.
      \return Translated vector.
  */
  CVector2D translate(const Treal a_cTranslateX, const Treal a_cTranslateY) const;

  //! Check if two vectors are collinear.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return true  - if two vectors are collinear. \n
              false - if two vectors are not collinear. \n
  */
  static Tbool isCollinear(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Check if two vectors are orthogonal.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return true  - if two vectors are orthogonal. \n
              false - if two vectors are not orthogonal. \n
  */
  static Tbool isOrthogonal(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);

  //! Calculate the distance between two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Distance between two vectors.
  */
  static Treal distance(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Calculate the squared distance between two vectors.
  /*!
      The method is intended to  increase  the  performance  in  the  geometry
      calculations.

      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Squared distance between two vectors.
  */
  static Treal distanceSq(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);

  //! Calculate the dot product of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Dot product of two vectors.
  */
  static Treal dot(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Calculate the Z component of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Z component of two vectors.
  */
  static Treal zcomp(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);

  //! Calculate the angle between two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Angle between two vectors.
  */
  static Treal angle(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Calculate the cosinus of the angle between two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Cosinus of the angle between two vectors.
  */
  static Treal angleCos(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);

  //! Calculate the orthogonal vector.
  /*!
      \param a_crInstance - Constant reference to the instance of the CVector2D class.
      \return Vector which orthogonal to the given one.
  */
  static CVector2D ortho(const CVector2D& a_crInstance);
  //! Calculate the mirrored vector.
  /*!
      \param a_crInstance - Constant reference to the instance of the CVector2D class.
      \param a_crMirrorVector - Constant reference to the instance of the mirror CVector2D class.
      \return Mirrored vector.
  */
  static CVector2D mirror(const CVector2D& a_crInstance, const CVector2D& a_crMirrorVector);

  //! Calculate the addition of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Vector result of the addition of two vectors.
  */
  static CVector2D add(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Calculate the subtraction of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Vector result of the subtraction of two vectors.
  */
  static CVector2D sub(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Calculate the multiplication of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Vector result of the multiplication of two vectors.
  */
  static CVector2D mul(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Calculate the division of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Vector result of the division of two vectors.
  */
  static CVector2D div(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);

  //! Calculate the between vector of two vectors.
  /*!
      Between vector is calculated as a difference between the  second  vector
      and the first one: between = v2 - v1.

      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Between vector of two vectors.
  */
  static CVector2D between(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Calculate the middle vector of two vectors.
  /*!
      Middle vector is calculated as a half summation of the first vector  and
      the second one: middle = (v1 + v2) / 2.

      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \return Middle vector of two vectors.
  */
  static CVector2D middle(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2);
  //! Calculate the linear interpolation of two vectors.
  /*!
      Linear interpolation is calculated as a  part  vector from  the  first
      one to the second one: lerp = v1 + part * (v2 - v1).

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CVector2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector2D class.
      \param a_cPart - Linear interpolation part.
      \return Linear interpolation of two vectors.
  */
  static CVector2D lerp(const CVector2D& a_crInstance1, const CVector2D& a_crInstance2, const Treal a_cPart);

  //! Perform the Gram-Schmidt orthonormalization of two vectors.
  /*!
      If  the  input  vectors  are  v0   and   v1,   then   the   Gram-Schmidt
      orthonormalization produces vectors u0 and u1 as follows:

      u0 = v0 / |v0|
      u1 = (v1 - (u0 * v1) u0) / |v1 - (u0 * v1) u0|

      where |A| indicates length of vector A and A*B indicates dot product  of
      vectors A and B.

      \param a_rInstance1 - Reference to the first instance of the CVector2D class.
      \param a_rInstance2 - Reference to the second instance of the CVector2D class.
  */
  static void orthonormalize(CVector2D& a_rInstance1, CVector2D& a_rInstance2);

  //! Serialize CVector2D class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CVector2D class instances.
  /*!
      \param a_rInstance - Reference to another CVector2D class instance.
  */
  void swap(CVector2D& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CVector3D.hpp>
#include <Depth/include/geometry/CVector4D.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/geometry/CVector2D.inl>
/*==========================================================================*/
//! \example example-geometry-CVector2D.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CVector2D.cpp
/*==========================================================================*/
#endif
