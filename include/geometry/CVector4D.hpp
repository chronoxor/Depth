/*!
 *  \file    CVector4D.hpp Representation of the vector in a hyperspace.
 *  \brief   Vector in a hyperspace class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Vector in a hyperspace class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   27.06.2008 23:43:19

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
#ifndef __CVECTOR4D_HPP__
#define __CVECTOR4D_HPP__
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
class CVector2D;
class CVector3D;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Vector in a hyperspace class.
/*!
    Class represents 4-dimension vector in  a  hyperspace.  It  contains  four
    coordinates values for each plane axis (x, y, z, w).

    Additionally class of the  vector  in  a  hyperspace  provides  common  3D
    functionality for vectors: complamar detection,  calculation  of  the  dot
    product,  calculation  of  the  cross   product,   normalization,   linear
    interpolation, rotating, etc.
*/
class GEOMETRY_API CVector4D
{
  //! Type for MConceptDepthType constraint checking.
  typedef CVector4D TDepthCheckType;

  // Check CVector4D class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  Treal m_X;                            //!< X coordinate of the vector.
  Treal m_Y;                            //!< Y coordinate of the vector.
  Treal m_Z;                            //!< Z coordinate of the vector.
  Treal m_W;                            //!< W coordinate of the vector.

  static const CVector4D ZERO;          //!< Zero vector on a plane.
  static const CVector4D UNIT_X;        //!< Unit X vector on a plane.
  static const CVector4D UNIT_Y;        //!< Unit Y vector on a plane.
  static const CVector4D UNIT_Z;        //!< Unit Z vector on a plane.
  static const CVector4D UNIT_W;        //!< Unit W vector on a plane.

  //! Default class constructor.
  /*!
      Set vector into begin of the hyperspace coordinate system (0, 0, 0, 0).
  */
  CVector4D();
  //! Initialize vector's coordinates.
  /*!
      \param a_cX - X coordinate of the vector.
      \param a_cY - Y coordinate of the vector.
      \param a_cZ - Z coordinate of the vector.
      \param a_cW - W coordinate of the vector.
  */
  CVector4D(const Treal a_cX, const Treal a_cY, const Treal a_cZ, const Treal a_cW);
  //! Initialize vector's coordinates through the array.
  /*!
      \param a_cpCoordinatesBuffer - Constant pointer to the coordinates array.
  */
  CVector4D(const Treal a_cpCoordinatesBuffer[]);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint2D class.
  */
  CVector4D(const CPoint2D<Treal>& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
  */
  CVector4D(const CPoint3D<Treal>& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector2D class.
  */
  CVector4D(const CVector2D& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector3D class.
  */
  CVector4D(const CVector3D& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector4D class.
  */
  CVector4D(const CVector4D& a_crInstance);
  //! Class destructor.
 ~CVector4D();

  //! Operator: Equal to another CVector4D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector4D class.
      \return true  - if CVector4D class instance is equal to another one. \n
              false - if CVector4D class instance is not equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator == (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Operator: Not equal to another CVector4D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector4D class.
      \return true  - if CVector4D class instance is not equal to another one. \n
              false - if CVector4D class instance is equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator != (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);

  //! Operator: Check if the length of the first vector is less than the length of the second one.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return true  - if the length of the first vector is less than the length of the second one. \n
              false - if the length of the first vector is not less than the length of the second one. \n
  */
  friend GEOMETRY_API Tbool operator < (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Operator: Check if the length of the first vector is greater than the length of the second one.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return true  - if the length of the first vector is greater than the length of the second one. \n
              false - if the length of the first vector is not greater than the length of the second one. \n
  */
  friend GEOMETRY_API Tbool operator > (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Operator: Check if the length of the first vector is less or equal to the length of the second one.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return true  - if the length of the first vector is or equal to the length of the second one. \n
              false - if the length of the first vector is not or equal to the length of the second one. \n
  */
  friend GEOMETRY_API Tbool operator <= (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Operator: Check if the length of the first vector is greater or equal to the length of the second one.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return true  - if the length of the first vector is greater or equal to the length of the second one. \n
              false - if the length of the first vector is not greater or equal to the length of the second one. \n
  */
  friend GEOMETRY_API Tbool operator >= (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Applies unary plus operator to all vector coordinates.

      \param a_crInstance - Constant reference to the current instance of the CVector4D class.
      \return New instance of CVector4D class with applied plus operator.
  */
  friend GEOMETRY_API CVector4D operator + (const CVector4D& a_crInstance);
  //! Operator: Unary minus.
  /*!
      Applies unary minus operator to all vector coordinates.

      \param a_crInstance - Constant reference to the current instance of the CVector4D class.
      \return New instance of CVector4D class with applied minus operator.
  */
  friend GEOMETRY_API CVector4D operator - (const CVector4D& a_crInstance);

  //! Operator: Add real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CVector4D class.
      \param a_cValue - Real number value.
      \return New instance of CVector4D class with applied add operator.
  */
  friend GEOMETRY_API CVector4D operator + (const CVector4D& a_crInstance, const Treal a_cValue);
  //! Operator: Add another CVector4D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector4D class.
      \return New instance of CVector4D class with applied add operator.
  */
  friend GEOMETRY_API CVector4D operator + (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Operator: Add real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CVector4D class.
      \return New instance of CVector4D class with applied add operator.
  */
  friend GEOMETRY_API CVector4D operator + (const Treal a_cValue, const CVector4D& a_crInstance);

  //! Operator: Sub real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CVector4D class.
      \param a_cValue - Real number value.
      \return New instance of CVector4D class with applied sub operator.
  */
  friend GEOMETRY_API CVector4D operator - (const CVector4D& a_crInstance, const Treal a_cValue);
  //! Operator: Sub another CVector4D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector4D class.
      \return New instance of CVector4D class with applied sub operator.
  */
  friend GEOMETRY_API CVector4D operator - (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Operator: Sub real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CVector4D class.
      \return New instance of CVector4D class with applied sub operator.
  */
  friend GEOMETRY_API CVector4D operator - (const Treal a_cValue, const CVector4D& a_crInstance);

  //! Operator: Mul real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CVector4D class.
      \param a_cValue - Real number value.
      \return New instance of CVector4D class with applied mul operator.
  */
  friend GEOMETRY_API CVector4D operator * (const CVector4D& a_crInstance, const Treal a_cValue);
  //! Operator: Mul another CVector4D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector4D class.
      \return New instance of CVector4D class with applied mul operator.
  */
  friend GEOMETRY_API CVector4D operator * (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Operator: Mul real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CVector4D class.
      \return New instance of CVector4D class with applied mul operator.
  */
  friend GEOMETRY_API CVector4D operator * (const Treal a_cValue, const CVector4D& a_crInstance);

  //! Operator: Div real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CVector4D class.
      \param a_cValue - Real number value.
      \return New instance of CVector4D class with applied div operator.
  */
  friend GEOMETRY_API CVector4D operator / (const CVector4D& a_crInstance, const Treal a_cValue);
  //! Operator: Div another CVector4D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector4D class.
      \return New instance of CVector4D class with applied div operator.
  */
  friend GEOMETRY_API CVector4D operator / (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Operator: Div real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CVector4D class.
      \return New instance of CVector4D class with applied div operator.
  */
  friend GEOMETRY_API CVector4D operator / (const Treal a_cValue, const CVector4D& a_crInstance);

  //! Operator: Calculate the dot product of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to another instance of the CVector4D class.
      \return Dot product of two vectors.
  */
  friend GEOMETRY_API Treal operator ^ (const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);

  //! Operator: Assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CVector4D& operator = (const Treal a_cValue);
  //! Operator: Assign another CPoint2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint2D class.
      \return Reference to the current class instance.
  */
  CVector4D& operator = (const CPoint2D<Treal>& a_crInstance);
  //! Operator: Assign another CPoint3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPoint3D class.
      \return Reference to the current class instance.
  */
  CVector4D& operator = (const CPoint3D<Treal>& a_crInstance);
  //! Operator: Assign another CVector2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector2D class.
      \return Reference to the current class instance.
  */
  CVector4D& operator = (const CVector2D& a_crInstance);
  //! Operator: Assign another CVector3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector3D class.
      \return Reference to the current class instance.
  */
  CVector4D& operator = (const CVector3D& a_crInstance);
  //! Operator: Assign another CVector4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector4D class.
      \return Reference to the current class instance.
  */
  CVector4D& operator = (const CVector4D& a_crInstance);

  //! Operator: Add and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CVector4D& operator += (const Treal a_cValue);
  //! Operator: Add and assign another CVector4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector4D class.
      \return Reference to the current class instance.
  */
  CVector4D& operator += (const CVector4D& a_crInstance);
  //! Operator: Sub and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CVector4D& operator -= (const Treal a_cValue);
  //! Operator: Sub and assign another CVector4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector4D class.
      \return Reference to the current class instance.
  */
  CVector4D& operator -= (const CVector4D& a_crInstance);
  //! Operator: Mul and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CVector4D& operator *= (const Treal a_cValue);
  //! Operator: Mul and assign another CVector4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector4D class.
      \return Reference to the current class instance.
  */
  CVector4D& operator *= (const CVector4D& a_crInstance);
  //! Operator: Div and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CVector4D& operator /= (const Treal a_cValue);
  //! Operator: Div and assign another CVector4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CVector4D class.
      \return Reference to the current class instance.
  */
  CVector4D& operator /= (const CVector4D& a_crInstance);

  //! Set vector's coordinates.
  /*!
      \param a_cX - X coordinate of the vector.
      \param a_cY - Y coordinate of the vector.
      \param a_cZ - Z coordinate of the vector.
      \param a_cW - W coordinate of the vector.
  */
  void set(const Treal a_cX, const Treal a_cY, const Treal a_cZ, const Treal a_cW);
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

  //! Set CVector4D coordinates from the axis and rotating angle.
  /*!
      \param a_crAxis - Constant reference to the instance of the axis CVector3D class.
      \param a_cAngle - Rotating angle.
  */
  void setAxis(const CVector3D& a_crAxis, const Treal a_cAngle);
  //! Get axis and rotating angle from the current CVector4D coordinates.
  /*!
      \param a_rAxis - Reference to the returning instance of the axis CVector3D class.
      \param a_rAngle - Reference to the returning rotating angle.
  */
  void getAxis(CVector3D& a_rAxis, Treal& a_rAngle) const;

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
      distance from the beginning of the coordinate system origin (0, 0, 0, 0)
      to the vector coordinates (x, y, z).

      \return Length of the vector.
  */
  Treal length() const;
  //! Get squared length of the vector.
  /*!
      This method returns squared length of the current vector. It  calculates
      as a squared distance from the beginning of the coordinate system origin
      (0, 0, 0, 0) to the vector coordinates (x,  y,  z,  w).  The  method  is
      intended to increase the performance in the geometry calculations.

      \return Squared length of the vector.
  */
  Treal lengthSq() const;

  //! Rotate vector.
  /*!
      \param a_cAngleX - Rotating angle along the X axis.
      \param a_cAngleY - Rotating angle along the Y axis.
      \param a_cAngleZ - Rotating angle along the Z axis.
      \return Rotated vector.
  */
  CVector4D rotate(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ) const;
  //! Rotate vector along the given axis.
  /*!
      \param a_crAxis - Constant reference to the rotating axis.
      \param a_cAngle - Rotating angle.
      \return Rotated vector.
  */
  CVector4D rotate(const CVector3D& a_crAxis, const Treal a_cAngle) const;
  //! Scale vector.
  /*!
      \param a_cScaleX - Scale value along the X axis.
      \param a_cScaleY - Scale value along the Y axis.
      \param a_cScaleZ - Scale value along the Z axis.
      \param a_cScaleW - Scale value along the W axis (default is 1.0).
      \return Scaled vector.
  */
  CVector4D scale(const Treal a_cScaleX, const Treal a_cScaleY, const Treal a_cScaleZ, const Treal a_cScaleW = 1.0) const;
  //! Translate vector.
  /*!
      \param a_cTranslateX - Translate value along the X axis.
      \param a_cTranslateY - Translate value along the Y axis.
      \param a_cTranslateZ - Translate value along the Z axis.
      \param a_cTranslateW - Translate value along the Z axis (default is 0.0).
      \return Translated vector.
  */
  CVector4D translate(const Treal a_cTranslateX, const Treal a_cTranslateY, const Treal a_cTranslateZ, const Treal a_cTranslateW = 0.0) const;

  //! Calculate the distance between two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return Distance between two vectors.
  */
  static Treal distance(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Calculate the squared distance between two vectors.
  /*!
      The method is intended to  increase  the  performance  in  the  geometry
      calculations.

      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return Squared distance between two vectors.
  */
  static Treal distanceSq(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);

  //! Calculate the dot product of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return Dot product of two vectors.
  */
  static Treal dot(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Calculate the cross product of three vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \param a_crInstance3 - Constant reference to the third instance of the CVector4D class.
      \return Cross product of three vectors.
  */
  static CVector4D cross(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2, const CVector4D& a_crInstance3);

  //! Calculate the angle between two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return Angle between two vectors.
  */
  static Treal angle(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Calculate the cosinus of the angle between two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return Cosinus of the angle between two vectors.
  */
  static Treal angleCos(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);

  //! Calculate the mirrored vector.
  /*!
      \param a_crInstance - Constant reference to the instance of the CVector4D class.
      \param a_crMirrorVector - Constant reference to the instance of the mirror CVector4D class.
      \return Mirrored vector.
  */
  static CVector4D mirror(const CVector4D& a_crInstance, const CVector4D& a_crMirrorVector);

  //! Calculate the addition of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return Vector result of the addition of two vectors.
  */
  static CVector4D add(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Calculate the subtraction of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return Vector result of the subtraction of two vectors.
  */
  static CVector4D sub(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Calculate the multiplication of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return Vector result of the multiplication of two vectors.
  */
  static CVector4D mul(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Calculate the division of two vectors.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return Vector result of the division of two vectors.
  */
  static CVector4D div(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);

  //! Calculate the between vector of two vectors.
  /*!
      Between vector is calculated as a difference between the  second  vector
      and the first one: between = v2 - v1.

      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return Between vector of two vectors.
  */
  static CVector4D between(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Calculate the middle vector of two vectors.
  /*!
      Middle vector is calculated as a half summation of the first vector  and
      the second one: middle = (v1 + v2) / 2.

      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \return Middle vector of two vectors.
  */
  static CVector4D middle(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2);
  //! Calculate the linear interpolation of two vectors.
  /*!
      Linear interpolation is calculated as a  part  vector from  the  first
      one to the second one: lerp = v1 + part * (v2 - v1).

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CVector4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CVector4D class.
      \param a_cPart - Linear interpolation part.
      \return Linear interpolation of two vectors.
  */
  static CVector4D lerp(const CVector4D& a_crInstance1, const CVector4D& a_crInstance2, const Treal a_cPart);

  //! Serialize CVector4D class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CVector4D class instances.
  /*!
      \param a_rInstance - Reference to another CVector4D class instance.
  */
  void swap(CVector4D& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CVector2D.hpp>
#include <Depth/include/geometry/CVector3D.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/geometry/CVector4D.inl>
/*==========================================================================*/
//! \example example-geometry-CVector4D.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CVector4D.cpp
/*==========================================================================*/
#endif
