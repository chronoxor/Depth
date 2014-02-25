/*!
 *  \file    CQuaternion.hpp Representation of the quaternion - hyper-complex
 *           number which extends conception of the rotation in a space.
 *  \brief   Quaternion class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Quaternion class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   07.07.2008 23:28:25

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
#ifndef __CQUATERNION_HPP__
#define __CQUATERNION_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CPoint3D.hpp>
#include <Depth/include/geometry/CVector3D.hpp>
#include <Depth/include/geometry/CVector4D.hpp>
#include <Depth/include/geometry/CMatrix3D.hpp>
#include <Depth/include/geometry/CMatrix4D.hpp>
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
//! Quaternion class.
/*!
    Quaternions extend the concept of rotation in three dimensions to rotation
    in four dimensions. This avoids the problem of  "gimbal-lock"  and  allows
    for the implementation of smooth and continuous rotation. In effect,  they
    may be  considered  to  add  a  additional  rotation  angle  to  spherical
    coordinates ie. Longitude, Latitude and Rotation angles  A  Quaternion  is
    defined using  four  floating  point  values  (x,  y,  z,  w).  These  are
    calculated from the combination of the three coordinates of  the  rotation
    axis and the rotation angle.
*/
class GEOMETRY_API CQuaternion
{
  //! Type for MConceptDepthType constraint checking.
  typedef CQuaternion TDepthCheckType;

  // Check CQuaternion class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  Treal m_X;                            //!< X value of the quaternion.
  Treal m_Y;                            //!< Y value of the quaternion.
  Treal m_Z;                            //!< Z value of the quaternion.
  Treal m_W;                            //!< W value of the quaternion.

  static const CQuaternion IDENTITY;    //!< Identity quaternion.
  static const CQuaternion ZERO;        //!< Zero quaternion.
  static const CQuaternion UNIT_X;      //!< Unit X quaternion.
  static const CQuaternion UNIT_Y;      //!< Unit Y quaternion.
  static const CQuaternion UNIT_Z;      //!< Unit Z quaternion.
  static const CQuaternion UNIT_W;      //!< Unit W quaternion.

  //! Default class constructor.
  /*!
      Set zero or identity quaternion.

      \param a_cIdentityFlag - Make quaternion identity flag (default is true).
  */
  CQuaternion(const Tbool a_cIdentityFlag = true);
  //! Initialize quaternion's values.
  /*!
      \param a_cX - X value of the quaternion.
      \param a_cY - Y value of the quaternion.
      \param a_cZ - Z value of the quaternion.
      \param a_cW - W value of the quaternion.
  */
  CQuaternion(const Treal a_cX, const Treal a_cY, const Treal a_cZ, const Treal a_cW);
  //! Initialize quaternion's values through the array.
  /*!
      \param a_cpValuesBuffer - Constant pointer to the values array.
  */
  CQuaternion(const Treal a_cpValuesBuffer[]);
  //! Initialize quaternion's values through the extended vector in a space.
  /*!
      \param a_crVector4D - Constant reference to another instance of the CVector4D class.
  */
  CQuaternion(const CVector4D& a_crVector4D);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CQuaternion class.
  */
  CQuaternion(const CQuaternion& a_crInstance);
  //! Class destructor.
 ~CQuaternion();

  //! Operator: Equal to another CQuaternion class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to another instance of the CQuaternion class.
      \return true  - if CQuaternion class instance is equal to another one. \n
              false - if CQuaternion class instance is not equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator == (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);
  //! Operator: Not equal to another CQuaternion class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to another instance of the CQuaternion class.
      \return true  - if CQuaternion class instance is not equal to another one. \n
              false - if CQuaternion class instance is equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator != (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Applies unary plus operator to all quaternion coordinates.

      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \return New instance of CQuaternion class with applied plus operator.
  */
  friend GEOMETRY_API CQuaternion operator + (const CQuaternion& a_crInstance);
  //! Operator: Unary minus.
  /*!
      Calculates and returns inverse quaternion.

      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \return New instance of CQuaternion class with applied minus operator (inverse quaternion).
  */
  friend GEOMETRY_API CQuaternion operator - (const CQuaternion& a_crInstance);
  //! Operator: Unary not.
  /*!
      Calculates and returns conjugate quaternion.

      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \return New instance of CQuaternion class with applied minus operator (conjugate quaternion).
  */
  friend GEOMETRY_API CQuaternion operator ! (const CQuaternion& a_crInstance);

  //! Operator: Add real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \param a_cValue - Real number value.
      \return New instance of CQuaternion class with applied add operator.
  */
  friend GEOMETRY_API CQuaternion operator + (const CQuaternion& a_crInstance, const Treal a_cValue);
  //! Operator: Add another CQuaternion class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to another instance of the CQuaternion class.
      \return New instance of CQuaternion class with applied add operator.
  */
  friend GEOMETRY_API CQuaternion operator + (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);
  //! Operator: Add real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \return New instance of CQuaternion class with applied add operator.
  */
  friend GEOMETRY_API CQuaternion operator + (const Treal a_cValue, const CQuaternion& a_crInstance);

  //! Operator: Sub real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \param a_cValue - Real number value.
      \return New instance of CQuaternion class with applied sub operator.
  */
  friend GEOMETRY_API CQuaternion operator - (const CQuaternion& a_crInstance, const Treal a_cValue);
  //! Operator: Sub another CQuaternion class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to another instance of the CQuaternion class.
      \return New instance of CQuaternion class with applied sub operator.
  */
  friend GEOMETRY_API CQuaternion operator - (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);
  //! Operator: Sub real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \return New instance of CQuaternion class with applied sub operator.
  */
  friend GEOMETRY_API CQuaternion operator - (const Treal a_cValue, const CQuaternion& a_crInstance);

  //! Operator: Mul real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \param a_cValue - Real number value.
      \return New instance of CQuaternion class with applied mul operator.
  */
  friend GEOMETRY_API CQuaternion operator * (const CQuaternion& a_crInstance, const Treal a_cValue);
  //! Operator: Mul another CQuaternion class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to another instance of the CQuaternion class.
      \return New instance of CQuaternion class with applied mul operator.
  */
  friend GEOMETRY_API CQuaternion operator * (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);
  //! Operator: Mul real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \return New instance of CQuaternion class with applied mul operator.
  */
  friend GEOMETRY_API CQuaternion operator * (const Treal a_cValue, const CQuaternion& a_crInstance);

  //! Operator: Div real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \param a_cValue - Real number value.
      \return New instance of CQuaternion class with applied div operator.
  */
  friend GEOMETRY_API CQuaternion operator / (const CQuaternion& a_crInstance, const Treal a_cValue);
  //! Operator: Div another CQuaternion class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to another instance of the CQuaternion class.
      \return New instance of CQuaternion class with applied div operator.
  */
  friend GEOMETRY_API CQuaternion operator / (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);
  //! Operator: Div real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \return New instance of CQuaternion class with applied div operator.
  */
  friend GEOMETRY_API CQuaternion operator / (const Treal a_cValue, const CQuaternion& a_crInstance);

  //! Operator: Calculate the dot product of two quaternions.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to another instance of the CQuaternion class.
      \return Dot product of two quaternions.
  */
  friend GEOMETRY_API Treal operator ^ (const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);

  //! Transform coordinates of the point in a space with the current quaternion.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \return CPoint3D result of the transformation.
  */
  friend GEOMETRY_API CPoint3D<Treal> operator * (const CPoint3D<Treal>& a_crPoint3D, const CQuaternion& a_crInstance);
  //! Transform coordinates of the vector in a space with the current quaternion.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \return CVector3D result of the transformation.
  */
  friend GEOMETRY_API CVector3D operator * (const CVector3D& a_crVector3D, const CQuaternion& a_crInstance);
  //! Transform coordinates of the extended vector in a space with the current quaternion.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_crInstance - Constant reference to the current instance of the CQuaternion class.
      \return CVector4D result of the transformation.
  */
  friend GEOMETRY_API CVector4D operator * (const CVector4D& a_crVector4D, const CQuaternion& a_crInstance);

  //! Operator: Assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CQuaternion& operator = (const Treal a_cValue);
  //! Operator: Assign another CVector4D class instance.
  /*!
      \param a_crVector4D - Constant reference to another instance of the CVector4D class.
      \return Reference to the current class instance.
  */
  CQuaternion& operator = (const CVector4D& a_crVector4D);
  //! Operator: Assign another CQuaternion class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CQuaternion class.
      \return Reference to the current class instance.
  */
  CQuaternion& operator = (const CQuaternion& a_crInstance);

  //! Operator: Add and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CQuaternion& operator += (const Treal a_cValue);
  //! Operator: Add and assign another CQuaternion class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CQuaternion class.
      \return Reference to the current class instance.
  */
  CQuaternion& operator += (const CQuaternion& a_crInstance);
  //! Operator: Sub and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CQuaternion& operator -= (const Treal a_cValue);
  //! Operator: Sub and assign another CQuaternion class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CQuaternion class.
      \return Reference to the current class instance.
  */
  CQuaternion& operator -= (const CQuaternion& a_crInstance);
  //! Operator: Mul and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CQuaternion& operator *= (const Treal a_cValue);
  //! Operator: Mul and assign another CQuaternion class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CQuaternion class.
      \return Reference to the current class instance.
  */
  CQuaternion& operator *= (const CQuaternion& a_crInstance);
  //! Operator: Div and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CQuaternion& operator /= (const Treal a_cValue);
  //! Operator: Div and assign another CQuaternion class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CQuaternion class.
      \return Reference to the current class instance.
  */
  CQuaternion& operator /= (const CQuaternion& a_crInstance);

  //! Set quaternion's values.
  /*!
      \param a_cX - X value of the quaternion.
      \param a_cY - Y value of the quaternion.
      \param a_cZ - Z value of the quaternion.
      \param a_cW - W value of the quaternion.
  */
  void set(const Treal a_cX, const Treal a_cY, const Treal a_cZ, const Treal a_cW);
  //! Set quaternion's values through the array.
  /*!
      \param a_cpValuesBuffer - Constant pointer to the values array.
  */
  void set(const Treal a_cpValuesBuffer[]);
  //! Set quaternion's values through the extended vector in a space.
  /*!
      \param a_crVector4D - Constant reference to another instance of the CVector4D class.
  */
  void set(const CVector4D& a_crVector4D);
  //! Set another CQuaternion class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CQuaternion class.
  */
  void set(const CQuaternion& a_crInstance);

  //! Set quaternion from the spherical coordinates and rotating angle.
  /*!
      \param a_cLatitude - Latitude.
      \param a_cLongitude - Longitude.
      \param a_cAngle - Rotating angle.
  */
  void setSpherical(const Treal a_cLatitude, const Treal a_cLongitude, const Treal a_cAngle);
  //! Get spherical coordinates and rotating angle from the current quaternion.
  /*!
      \param a_rLatitude - Reference to the returning latitude.
      \param a_rLongitude - Reference to the returning longitude.
      \param a_rAngle - Reference to the returning rotating angle.
  */
  void getSpherical(Treal& a_rLatitude, Treal& a_rLongitude, Treal& a_rAngle) const;

  //! Set quaternion from the Euler's rotating angles.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
  */
  void setRotateAnglesXYZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get Euler's rotating angles from the current quaternion.
  /*!
      \param a_rAngleX - Reference to the returning rotating angle by axis X.
      \param a_rAngleY - Reference to the returning rotating angle by axis Y.
      \param a_rAngleZ - Reference to the returning rotating angle by axis Z.
  */
  void getRotateAnglesXYZ(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const;

  //! Set quaternion from the axis and rotating angle.
  /*!
      \param a_crAxis - Constant reference to the instance of the axis CVector3D class.
      \param a_cAngle - Rotating angle.
  */
  void setRotateAxisAngle(const CVector3D& a_crAxis, const Treal a_cAngle);
  //! Get axis and rotating angle from the current quaternion.
  /*!
      \param a_rAxis - Reference to the returning instance of the axis CVector3D class.
      \param a_rAngle - Reference to the returning rotating angle.
  */
  void getRotateAxisAngle(CVector3D& a_rAxis, Treal& a_rAngle) const;

  //! Set quaternion from the matrix in a space.
  /*!
      \param a_crMatrix3D - Constant reference to the instance of the CMatrix3D class.
  */
  void setMatrix(const CMatrix3D& a_crMatrix3D);
  //! Set quaternion from the extended matrix in a space.
  /*!
      \param a_crMatrix4D - Constant reference to the instance of the CMatrix4D class.
  */
  void setMatrix(const CMatrix4D& a_crMatrix4D);
  //! Get matrix in a space from the current quaternion.
  /*!
      \param a_rMatrix3D - Reference to the returning instance of the CMatrix3D class.
  */
  void getMatrix3D(CMatrix3D& a_rMatrix3D) const;
  //! Get extended matrix in a space from the current quaternion.
  /*!
      \param a_rMatrix4D - Reference to the returning instance of the CMatrix4D class.
  */
  void getMatrix4D(CMatrix4D& a_rMatrix4D) const;

  //! Get rotating matrix in a space from the current quaternion.
  /*!
      \return Rotating matrix in a space equivalent to the current quaternion.
  */
  CMatrix3D getMatrix3D() const;
  //! Get extended rotating matrix in a space from the current quaternion.
  /*!
      \return Extended rotating matrix in a space equivalent to the current quaternion.
  */
  CMatrix4D getMatrix4D() const;

  //! Get conjugate quaternion of the current one.
  /*!
      \return Result conjugate quaternion of the current one.
  */
  CQuaternion getConjugate() const;
  //! Get inverse quaternion of the current one.
  /*!
      \return Result inverse quaternion of the current one.
  */
  CQuaternion getInverse() const;
  //! Get squared quaternion of the current one.
  /*!
      \return Result squared quaternion of the current one.
  */
  CQuaternion getSquared() const;
  //! Get exponent quaternion of the current one.
  /*!
      \return Result exponent quaternion of the current one.
  */
  CQuaternion getExponent() const;
  //! Get logarithmic quaternion of the current one.
  /*!
      \return Result logarithmic quaternion of the current one.
  */
  CQuaternion getLogarithmic() const;

  //! Set quaternion coordinates to zeros or make quaternion identity.
  /*!
      \param a_cIdentityFlag - Make quaternion identity flag (default is false).
  */
  void clear(const Tbool a_cIdentityFlag = false);

  //! Normalize quaternion.
  /*!
      This method makes the length of the current quaternion to be equal to 1,
      but keeps quaternion's direction.
  */
  void normalize();
  //! Normalize quaternion and get its previous length.
  /*!
      This method normalizes current quaternion, but also returns its previous
      length. The method is  intended  to  increase  the  performance  in  the
      geometry calculations.

      \return Length of the quaternion before the normalization.
  */
  Treal normalizeLength();

  //! Get length of the quaternion.
  /*!
      This method returns length of the current quaternion. It calculates as a
      distance from the beginning of the coordinate system origin (0, 0, 0, 0)
      to the quaternion coordinates (x, y, z).

      \return Length of the quaternion.
  */
  Treal length() const;
  //! Get squared length of the quaternion.
  /*!
      This method  returns  squared  length  of  the  current  quaternion.  It
      calculates as a squared distance from the beginning  of  the  coordinate
      system origin (0, 0, 0, 0) to the quaternion coordinates (x, y,  z,  w).
      The method is intended to  increase  the  performance  in  the  geometry
      calculations.

      \return Squared length of the quaternion.
  */
  Treal lengthSq() const;

  //! Rotate coordinates of the point in a space with the current quaternion.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return CPoint3D result of the rotation.
  */
  CPoint3D<Treal> rotate(const CPoint3D<Treal>& a_crPoint3D) const;
  //! Rotate coordinates of the vector in a space with the current quaternion.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \return CVector3D result of the rotation.
  */
  CVector3D rotate(const CVector3D& a_crVector3D) const;
  //! Rotate coordinates of the extended vector in a space with the current quaternion.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \return CVector4D result of the rotation.
  */
  CVector4D rotate(const CVector4D& a_crVector4D) const;

  //! Rotate coordinates of the point in a space with the current quaternion (faster version).
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result rotated instance of the CPoint3D class.
  */
  void rotate(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Rotate coordinates of the vector in a space with the current quaternion (faster version).
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result rotated instance of the CVector3D class.
  */
  void rotate(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;
  //! Rotate coordinates of the extended vector in a space with the current quaternion (faster version).
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_rResult - Reference to the result rotated instance of the CVector4D class.
  */
  void rotate(const CVector4D& a_crVector4D, CVector4D& a_rResult) const;

  //! Calculate conjugate quaternion.
  /*!
      \param a_crInstance - Constant reference to the instance of the CQuaternion class.
      \return Result conjugate quaternion.
  */
  static CQuaternion conjugate(const CQuaternion& a_crInstance);
  //! Calculate inverse quaternion.
  /*!
      \param a_crInstance - Constant reference to the instance of the CQuaternion class.
      \return Result inverse quaternion.
  */
  static CQuaternion inverse(const CQuaternion& a_crInstance);
  //! Calculate squared quaternion.
  /*!
      \param a_crInstance - Constant reference to the instance of the CQuaternion class.
      \return Result squared quaternion.
  */
  static CQuaternion squared(const CQuaternion& a_crInstance);
  //! Calculate exponent quaternion.
  /*!
      \param a_crInstance - Constant reference to the instance of the CQuaternion class.
      \return Result exponent quaternion.
  */
  static CQuaternion exponent(const CQuaternion& a_crInstance);
  //! Calculate logarithmic quaternion.
  /*!
      \param a_crInstance - Constant reference to the instance of the CQuaternion class.
      \return Result logarithmic quaternion.
  */
  static CQuaternion logarithmic(const CQuaternion& a_crInstance);

  //! Calculate the dot product of two quaternions.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to the second instance of the CQuaternion class.
      \return Dot product of two quaternions.
  */
  static Treal dot(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);

  //! Calculate the addition of two quaternions.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to the second instance of the CQuaternion class.
      \return Quaternion result of the addition of two quaternions.
  */
  static CQuaternion add(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);
  //! Calculate the subtraction of two quaternions.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to the second instance of the CQuaternion class.
      \return Quaternion result of the subtraction of two quaternions.
  */
  static CQuaternion sub(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);
  //! Calculate the multiplication of two quaternions.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to the second instance of the CQuaternion class.
      \return Quaternion result of the multiplication of two quaternions.
  */
  static CQuaternion mul(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);
  //! Calculate the division of two quaternions.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to the second instance of the CQuaternion class.
      \return Quaternion result of the division of two quaternions.
  */
  static CQuaternion div(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2);

  //! Calculate quaternion from the spherical coordinates and rotating angle.
  /*!
      \param a_cLatitude - Latitude.
      \param a_cLongitude - Longitude.
      \param a_cAngle - Rotating angle.
      \return Quaternion result, calculated from the spherical coordinates and rotating angle.
  */
  static CQuaternion spherical(const Treal a_cLatitude, const Treal a_cLongitude, const Treal a_cAngle);
  //! Calculate quaternion from the Euler's rotating angles.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Quaternion result, calculated from the Euler's rotating angles.
  */
  static CQuaternion rotateAnglesXYZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Calculate quaternion from the axis and rotating angle.
  /*!
      \param a_crAxis - Constant reference to the instance of the axis CVector3D class.
      \param a_cAngle - Rotating angle.
      \return Quaternion result, calculated from the axis and rotating angle.
  */
  static CQuaternion rotateAxisAngle(const CVector3D& a_crAxis, const Treal a_cAngle);
  //! Calculate quaternion from the matrix in a space.
  /*!
      \param a_crMatrix3D - Constant reference to the instance of the CMatrix3D class.
      \return Quaternion result, calculated from the matrix in a space.
  */
  static CQuaternion matrix(const CMatrix3D& a_crMatrix3D);
  //! Calculate quaternion from the extended matrix in a space.
  /*!
      \param a_crMatrix4D - Constant reference to the instance of the CMatrix3D class.
      \return Quaternion result, calculated from the extended matrix in a space.
  */
  static CQuaternion matrix(const CMatrix4D& a_crMatrix4D);

  //! Calculate the linear spherical interpolation of two quaternions.
  /*!
      Linear spherical interpolation is calculated as a part  quaternion  from
      the first one to the second one.

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to the second instance of the CQuaternion class.
      \param a_cPart - Linear interpolation part.
      \return Linear spherical interpolation of two quaternions.
  */
  static CQuaternion slerp(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2, const Treal a_cPart);
  //! Calculate the linear spherical interpolation of two quaternions with extra spins.
  /*!
      Linear spherical interpolation is calculated as a part  quaternion  from
      the first one to the second one.

      Extra spins regulates count of full rotation spin, could be 0, less than
      0 or more than 0.

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CQuaternion class.
      \param a_crInstance2 - Constant reference to the second instance of the CQuaternion class.
      \param a_cPart - Linear interpolation part.
      \param a_cSpins - Spins count.
      \return Linear spherical interpolation of two quaternions.
  */
  static CQuaternion slerpSpins(const CQuaternion& a_crInstance1, const CQuaternion& a_crInstance2, const Treal a_cPart, const Treal a_cSpins);

  //! Serialize CQuaternion class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CQuaternion class instances.
  /*!
      \param a_rInstance - Reference to another CQuaternion class instance.
  */
  void swap(CQuaternion& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CQuaternion.inl>
/*==========================================================================*/
//! \example example-geometry-CQuaternion.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CQuaternion.cpp
/*==========================================================================*/
#endif
