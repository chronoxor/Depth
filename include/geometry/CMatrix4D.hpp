/*!
 *  \file    CMatrix4D.hpp Representation of the extended transformation
 *           matrix in a space.
 *  \brief   Extended transformation matrix in a space class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Extended transformation matrix in a space class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   01.07.2008 00:17:18

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
#ifndef __CMATRIX4D_HPP__
#define __CMATRIX4D_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CPoint3D.hpp>
#include <Depth/include/geometry/CVector3D.hpp>
#include <Depth/include/geometry/CVector4D.hpp>
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
class CMatrix2D;
class CMatrix3D;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Extended transformation matrix in a space class.
/*!
    Class represents 3-dimension extended transformation matrix in a space. It
    provides common functionality of the extended  3D  matrix  arithmetic  and
    utility methods to perform extended 3D transformation.

    Extended transformation matrix  in  a  space  uses  right-hand  coordinate
    system to perform transformations. In this coordinate system the  positive
    X and Y axes point right and up, and the negative Z axis  points  forward.
    Positive rotation is counterclockwise about the axis of rotation.
*/
class GEOMETRY_API CMatrix4D
{
  //! Type for MConceptDepthType constraint checking.
  typedef CMatrix4D TDepthCheckType;

  // Check CMatrix4D class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  Treal m_M[4][4];                      //!< Transformation matrix values.

  //! Default class constructor.
  /*!
      Set zero or identity 2D transformation matrix.

      \param a_cIdentityFlag - Make matrix identity flag (default is true).
  */
  CMatrix4D(const Tbool a_cIdentityFlag = true);
  //! Initialize transformation matrix values through the array.
  /*!
      \param a_cpMatrixBuffer - Constant pointer to the matrix values array.
  */
  CMatrix4D(const Treal a_cpMatrixBuffer[]);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix2D class.
  */
  CMatrix4D(const CMatrix2D& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix3D class.
  */
  CMatrix4D(const CMatrix3D& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix4D class.
  */
  CMatrix4D(const CMatrix4D& a_crInstance);
  //! Class destructor.
 ~CMatrix4D();

  //! Operator: Equal to another CMatrix4D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix4D class.
      \return true  - if CMatrix4D class instance is equal to another one. \n
              false - if CMatrix4D class instance is not equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator == (const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2);
  //! Operator: Not equal to another CMatrix4D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix4D class.
      \return true  - if CMatrix4D class instance is not equal to another one. \n
              false - if CMatrix4D class instance is equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator != (const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Applies unary plus operator to all matrix values.

      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \return New instance of CMatrix4D class with applied plus operator.
  */
  friend GEOMETRY_API CMatrix4D operator + (const CMatrix4D& a_crInstance);
  //! Operator: Unary minus.
  /*!
      Applies unary minus operator to all matrix values.

      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \return New instance of CMatrix4D class with applied minus operator.
  */
  friend GEOMETRY_API CMatrix4D operator - (const CMatrix4D& a_crInstance);

  //! Operator: Add real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix4D class with applied add operator.
  */
  friend GEOMETRY_API CMatrix4D operator + (const CMatrix4D& a_crInstance, const Treal a_cValue);
  //! Operator: Add another CMatrix4D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix4D class.
      \return New instance of CMatrix4D class with applied add operator.
  */
  friend GEOMETRY_API CMatrix4D operator + (const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2);
  //! Operator: Add real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \return New instance of CMatrix4D class with applied add operator.
  */
  friend GEOMETRY_API CMatrix4D operator + (const Treal a_cValue, const CMatrix4D& a_crInstance);

  //! Operator: Sub real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix4D class with applied sub operator.
  */
  friend GEOMETRY_API CMatrix4D operator - (const CMatrix4D& a_crInstance, const Treal a_cValue);
  //! Operator: Sub another CMatrix4D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix4D class.
      \return New instance of CMatrix4D class with applied sub operator.
  */
  friend GEOMETRY_API CMatrix4D operator - (const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2);
  //! Operator: Sub real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \return New instance of CMatrix4D class with applied sub operator.
  */
  friend GEOMETRY_API CMatrix4D operator - (const Treal a_cValue, const CMatrix4D& a_crInstance);

  //! Operator: Mul real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix4D class with applied mul operator.
  */
  friend GEOMETRY_API CMatrix4D operator * (const CMatrix4D& a_crInstance, const Treal a_cValue);
  //! Operator: Mul another CMatrix4D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix4D class.
      \return New instance of CMatrix4D class with applied mul operator.
  */
  friend GEOMETRY_API CMatrix4D operator * (const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2);
  //! Operator: Mul real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \return New instance of CMatrix4D class with applied mul operator.
  */
  friend GEOMETRY_API CMatrix4D operator * (const Treal a_cValue, const CMatrix4D& a_crInstance);

  //! Operator: Div real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix4D class with applied div operator.
  */
  friend GEOMETRY_API CMatrix4D operator / (const CMatrix4D& a_crInstance, const Treal a_cValue);
  //! Operator: Div real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \return New instance of CMatrix4D class with applied div operator.
  */
  friend GEOMETRY_API CMatrix4D operator / (const Treal a_cValue, const CMatrix4D& a_crInstance);

  //! Transform coordinates of the point in a space with the current matrix.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \return CPoint3D result of the transformation.
  */
  friend GEOMETRY_API CPoint3D<Treal> operator * (const CPoint3D<Treal>& a_crPoint3D, const CMatrix4D& a_crInstance);
  //! Transform coordinates of the vector in a space with the current matrix.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \return CVector3D result of the transformation.
  */
  friend GEOMETRY_API CVector3D operator * (const CVector3D& a_crVector3D, const CMatrix4D& a_crInstance);
  //! Transform coordinates of the extended vector in a space with the current matrix.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_crInstance - Constant reference to the current instance of the CMatrix4D class.
      \return CVector4D result of the transformation.
  */
  friend GEOMETRY_API CVector4D operator * (const CVector4D& a_crVector4D, const CMatrix4D& a_crInstance);

  //! Operator: Assign another CMatrix2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix2D class.
      \return Reference to the current class instance.
  */
  CMatrix4D& operator = (const CMatrix2D& a_crInstance);
  //! Operator: Assign another CMatrix3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix3D class.
      \return Reference to the current class instance.
  */
  CMatrix4D& operator = (const CMatrix3D& a_crInstance);
  //! Operator: Assign another CMatrix4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix4D class.
      \return Reference to the current class instance.
  */
  CMatrix4D& operator = (const CMatrix4D& a_crInstance);

  //! Operator: Add and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix4D& operator += (const Treal a_cValue);
  //! Operator: Add and assign another CMatrix4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix4D class.
      \return Reference to the current class instance.
  */
  CMatrix4D& operator += (const CMatrix4D& a_crInstance);
  //! Operator: Sub and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix4D& operator -= (const Treal a_cValue);
  //! Operator: Sub and assign another CMatrix4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix4D class.
      \return Reference to the current class instance.
  */
  CMatrix4D& operator -= (const CMatrix4D& a_crInstance);
  //! Operator: Mul and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix4D& operator *= (const Treal a_cValue);
  //! Operator: Mul and assign another CMatrix4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix4D class.
      \return Reference to the current class instance.
  */
  CMatrix4D& operator *= (const CMatrix4D& a_crInstance);
  //! Operator: Div and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix4D& operator /= (const Treal a_cValue);

  //! Set matrix coordinates through the array.
  /*!
      \param a_cpMatrixBuffer - Constant pointer to the matrix values array.
  */
  void set(const Treal a_cpMatrixBuffer[]);
  //! Set another CMatrix2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix2D class.
  */
  void set(const CMatrix2D& a_crInstance);
  //! Set another CMatrix3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix3D class.
  */
  void set(const CMatrix3D& a_crInstance);
  //! Set another CMatrix4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix4D class.
  */
  void set(const CMatrix4D& a_crInstance);

  //! Set matrix coordinates to zeros or make matrix identity.
  /*!
      \param a_cIdentityFlag - Make matrix identity flag (default is false).
  */
  void clear(const Tbool a_cIdentityFlag = false);
  //! Set matrix values to their absolute values.
  void absolute();
  //! Negative matrix values.
  void negate();

  //! Get determinant of the current matrix.
  /*!
      \return Determinant value of the current matrix.
  */
  Treal getDeterminant() const;

  //! Get axis and rotating angle from the current matrix.
  /*!
      \param a_rAxis - Reference to the returning instance of the axis CVector3D class.
      \param a_rAngle - Reference to the returning rotating angle.
  */
  void getRotateAxisAngle(CVector3D& a_rAxis, Treal& a_rAngle) const;

  //! Get rotating angles from the current matrix in order XYZ.
  /*!
      \param a_rAngleX - Reference to the returning rotating angle by axis X.
      \param a_rAngleY - Reference to the returning rotating angle by axis Y.
      \param a_rAngleZ - Reference to the returning rotating angle by axis Z.
  */
  void getRotateAnglesXYZ(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const;
  //! Get rotating angles from the current matrix in order XZY.
  /*!
      \param a_rAngleX - Reference to the returning rotating angle by axis X.
      \param a_rAngleY - Reference to the returning rotating angle by axis Y.
      \param a_rAngleZ - Reference to the returning rotating angle by axis Z.
  */
  void getRotateAnglesXZY(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const;
  //! Get rotating angles from the current matrix in order YXZ.
  /*!
      \param a_rAngleX - Reference to the returning rotating angle by axis X.
      \param a_rAngleY - Reference to the returning rotating angle by axis Y.
      \param a_rAngleZ - Reference to the returning rotating angle by axis Z.
  */
  void getRotateAnglesYXZ(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const;
  //! Get rotating angles from the current matrix in order YZX.
  /*!
      \param a_rAngleX - Reference to the returning rotating angle by axis X.
      \param a_rAngleY - Reference to the returning rotating angle by axis Y.
      \param a_rAngleZ - Reference to the returning rotating angle by axis Z.
  */
  void getRotateAnglesYZX(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const;
  //! Get rotating angles from the current matrix in order ZXY.
  /*!
      \param a_rAngleX - Reference to the returning rotating angle by axis X.
      \param a_rAngleY - Reference to the returning rotating angle by axis Y.
      \param a_rAngleZ - Reference to the returning rotating angle by axis Z.
  */
  void getRotateAnglesZXY(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const;
  //! Get rotating angles from the current matrix in order ZYX.
  /*!
      \param a_rAngleX - Reference to the returning rotating angle by axis X.
      \param a_rAngleY - Reference to the returning rotating angle by axis Y.
      \param a_rAngleZ - Reference to the returning rotating angle by axis Z.
  */
  void getRotateAnglesZYX(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const;

  //! Get rotating angles from the current matrix in yaw-pitch-roll system.
  /*!
      \param a_rAngleYaw - Reference to the returning rotating angle in xOz plane (yaw angle).
      \param a_rAnglePitch - Reference to the returning rotating angle in yOZ plane (pitch angle).
      \param a_rAngleRoll - Reference to the returning rotating angle in xOy plane (roll angle).
  */
  void getRotateAnglesYPR(Treal& a_rAngleYaw, Treal& a_rAnglePitch, Treal& a_rAngleRoll) const;

  //! Rotate coordinates of the point in a space with the current matrix.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return CPoint3D result of the rotation.
  */
  CPoint3D<Treal> rotate(const CPoint3D<Treal>& a_crPoint3D) const;
  //! Rotate coordinates of the vector in a space with the current matrix.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \return CVector3D result of the rotation.
  */
  CVector3D rotate(const CVector3D& a_crVector3D) const;
  //! Rotate coordinates of the extended vector in a space with the current matrix.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \return CVector4D result of the rotation.
  */
  CVector4D rotate(const CVector4D& a_crVector4D) const;

  //! Transform coordinates of the point in a space with the current matrix.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return CPoint3D result of the transformation.
  */
  CPoint3D<Treal> transform(const CPoint3D<Treal>& a_crPoint3D) const;
  //! Transform coordinates of the vector in a space with the current matrix.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \return CVector3D result of the transformation.
  */
  CVector3D transform(const CVector3D& a_crVector3D) const;
  //! Transform coordinates of the extended vector in a space with the current matrix.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \return CVector4D result of the transformation.
  */
  CVector4D transform(const CVector4D& a_crVector4D) const;

  //! Rotate coordinates of the point in a space with the current matrix (faster version).
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result rotated instance of the CPoint3D class.
  */
  void rotate(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Rotate coordinates of the vector in a space with the current matrix (faster version).
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result rotated instance of the CVector3D class.
  */
  void rotate(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;
  //! Rotate coordinates of the extended vector in a space with the current matrix (faster version).
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_rResult - Reference to the result rotated instance of the CVector4D class.
  */
  void rotate(const CVector4D& a_crVector4D, CVector4D& a_rResult) const;

  //! Transform coordinates of the point in a space with the current matrix (faster version).
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result transformed instance of the CPoint3D class.
  */
  void transform(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Transform coordinates of the vector in a space with the current matrix (faster version).
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result transformed instance of the CVector3D class.
  */
  void transform(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;
  //! Transform coordinates of the extended vector in a space with the current matrix (faster version).
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_rResult - Reference to the result transformed instance of the CVector4D class.
  */
  void transform(const CVector4D& a_crVector4D, CVector4D& a_rResult) const;

  //! Extended transform coordinates of the point in a space with the current matrix.
  /*!
      Extended transformation uses additional  matrix  column  to  adjust  the
      transformed coordinates.

      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return CPoint3D result of the transformation.
  */
  CPoint3D<Treal> transformEx(const CPoint3D<Treal>& a_crPoint3D) const;
  //! Extended transform coordinates of the vector in a space with the current matrix.
  /*!
      Extended transformation uses additional  matrix  column  to  adjust  the
      transformed coordinates.

      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \return CVector3D result of the transformation.
  */
  CVector3D transformEx(const CVector3D& a_crVector3D) const;

  //! Extended transform coordinates of the point in a space with the current matrix (faster version).
  /*!
      Extended transformation uses additional  matrix  column  to  adjust  the
      transformed coordinates.

      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result transformed instance of the CPoint3D class.
  */
  void transformEx(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Extended transform coordinates of the vector in a space with the current matrix (faster version).
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_rResult - Reference to the result transformed instance of the CVector3D class.
  */
  void transformEx(const CVector3D& a_crVector3D, CVector3D& a_rResult) const;

  //! Calculate the addition of two matrixes.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix4D class.
      \return Matrix result of the addition of two matrixes.
  */
  static CMatrix4D add(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2);
  //! Calculate the subtraction of two matrixes.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix4D class.
      \return Matrix result of the subtraction of two matrixes.
  */
  static CMatrix4D sub(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2);
  //! Calculate the multiplication of two matrixes.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix4D class.
      \return Matrix result of the multiplication of two matrixes.
  */
  static CMatrix4D mul(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2);

  //! Get zero matrix.
  /*!
      \return Zero matrix.
  */
  static CMatrix4D zero();
  //! Get identity matrix.
  /*!
      \return Identity matrix.
  */
  static CMatrix4D identity();

  //! Get adjoint matrix of the given one.
  /*!
      \param a_crInstance - Constant reference to the instance of the CMatrix4D class.
      \return Adjoint matrix.
  */
  static CMatrix4D adjoint(const CMatrix4D& a_crInstance);
  //! Get invert matrix of the given one.
  /*!
      \param a_crInstance - Constant reference to the instance of the CMatrix4D class.
      \return Invert matrix.
  */
  static CMatrix4D invert(const CMatrix4D& a_crInstance);
  //! Get transpose matrix of the given one.
  /*!
      \param a_crInstance - Constant reference to the instance of the CMatrix4D class.
      \return Transpose matrix.
  */
  static CMatrix4D transpose(const CMatrix4D& a_crInstance);

  //! Get transpose times matrix of the two given ones (transpose(A) * B).
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix4D class.
      \return Transpose times matrix.
  */
  static CMatrix4D transposeTimes(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2);
  //! Get times transpose matrix of the two given ones (A * transpose(B)).
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix4D class.
      \return Times transpose matrix.
  */
  static CMatrix4D timesTranspose(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2);

  //! Get tensor product matrix of the two given vectors (transpose(U) * V).
  /*!
      \param a_crU - Constant reference to the first instance of the CVector3D class.
      \param a_crV - Constant reference to the second instance of the CVector3D class.
      \return Tensor product matrix.
  */
  static CMatrix4D tensorProduct(const CVector3D& a_crU, const CVector3D& a_crV);
  //! Get tensor product matrix of the two given vectors (transpose(U) * V).
  /*!
      \param a_crU - Constant reference to the first instance of the CVector4D class.
      \param a_crV - Constant reference to the second instance of the CVector4D class.
      \return Tensor product matrix.
  */
  static CMatrix4D tensorProduct(const CVector4D& a_crU, const CVector4D& a_crV);

  //! Get translate matrix in a space.
  /*!
      \param a_cTranslateX - Translate value for the X coordinate.
      \param a_cTranslateY - Translate value for the Y coordinate.
      \param a_cTranslateZ - Translate value for the Z coordinate.
      \return Translate matrix in a space.
  */
  static CMatrix4D translate(const Treal a_cTranslateX, const Treal a_cTranslateY, const Treal a_cTranslateZ);
  //! Get scale matrix in a space.
  /*!
      \param a_cScaleX - Scale value for the X coordinate.
      \param a_cScaleY - Scale value for the Y coordinate.
      \param a_cScaleZ - Scale value for the Z coordinate.
      \return Scale matrix in a space.
  */
  static CMatrix4D scale(const Treal a_cScaleX, const Treal a_cScaleY, const Treal a_cScaleZ);
  //! Get shear matrix in a space.
  /*!
      \param a_cShearXY - Shear value X by Y.
      \param a_cShearXZ - Shear value X by Z.
      \param a_cShearYX - Shear value Y by X.
      \param a_cShearYZ - Shear value Y by Z.
      \param a_cShearZX - Shear value Z by X.
      \param a_cShearZY - Shear value Z by Y.
      \return Shear matrix in a space.
  */
  static CMatrix4D shear(const Treal a_cShearXY, const Treal a_cShearXZ, const Treal a_cShearYX, const Treal a_cShearYZ, const Treal a_cShearZX, const Treal a_cShearZY);
  //! Get rotate matrix in a space from the given axis and rotating angle.
  /*!
      \param a_crAxis - Constant reference to the instance of the axis CVector3D class.
      \param a_cAngle - Rotating angle.
      \return Rotate matrix in a space.
  */
  static CMatrix4D rotate(const CVector3D& a_crAxis, const Treal a_cAngle);
  //! Get rotate matrix in a space by axis X.
  /*!
      \param a_cAngle - Rotating angle.
      \return Rotate matrix in a space by axis X.
  */
  static CMatrix4D rotateX(const Treal a_cAngle);
  //! Get rotate matrix in a space by axis Y.
  /*!
      \param a_cAngle - Rotating angle.
      \return Rotate matrix in a space by axis Y.
  */
  static CMatrix4D rotateY(const Treal a_cAngle);
  //! Get rotate matrix in a space by axis Z.
  /*!
      \param a_cAngle - Rotating angle.
      \return Rotate matrix in a space by axis Z.
  */
  static CMatrix4D rotateZ(const Treal a_cAngle);
  //! Get rotate matrix in a space by axis in order XYZ.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order XYZ.
  */
  static CMatrix4D rotateXYZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space by axis in order XZY.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order XZY.
  */
  static CMatrix4D rotateXZY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space by axis in order YXZ.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order YXZ.
  */
  static CMatrix4D rotateYXZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space by axis in order YZX.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order YZX.
  */
  static CMatrix4D rotateYZX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space by axis in order ZXY.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order ZXY.
  */
  static CMatrix4D rotateZXY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space by axis in order ZYX.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order ZYX.
  */
  static CMatrix4D rotateZYX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space in yaw-pitch-roll system.
  /*!
      \param a_cAngleYaw - Rotating angle in xOz plane (yaw angle).
      \param a_cAnglePitch - Rotating angle in yOZ plane (pitch angle).
      \param a_cAngleRoll - Rotating angle in xOy plane (roll angle).
      \return Rotate matrix in a space in yaw-pitch-roll system.
  */
  static CMatrix4D rotateYPR(const Treal a_cAngleYaw, const Treal a_cAnglePitch, const Treal a_cAngleRoll);
  //! Get mirror X matrix in a space.
  /*!
      \return Mirror X matrix in a space.
  */
  static CMatrix4D mirrorX();
  //! Get mirror Y matrix in a space.
  /*!
      \return Mirror Y matrix in a space.
  */
  static CMatrix4D mirrorY();
  //! Get mirror Z matrix in a space.
  /*!
      \return Mirror Z matrix in a space.
  */
  static CMatrix4D mirrorZ();

  //! Calculate the linear spherical interpolation of two matrixes.
  /*!
      Linear spherical interpolation is calculated as a part matrix  from  the
      first one to the second one.

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix4D class.
      \param a_cPart - Linear interpolation part.
      \return Linear spherical interpolation of two matrixes.
  */
  static CMatrix4D slerp(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2, const Treal a_cPart);
  //! Calculate the linear spherical interpolation of two matrixes with extra spins.
  /*!
      Linear spherical interpolation is calculated as a part matrix  from  the
      first one to the second  one.

      Extra spins regulates count of full rotation spin, could be 0, less than
      0 or more than 0.

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CMatrix4D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix4D class.
      \param a_cPart - Linear interpolation part.
      \param a_cSpins - Spins count.
      \return Linear spherical interpolation of two matrixes.
  */
  static CMatrix4D slerpSpins(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2, const Treal a_cPart, const Treal a_cSpins);

  //! Serialize CMatrix4D class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CMatrix4D class instances.
  /*!
      \param a_rInstance - Reference to another CMatrix4D class instance.
  */
  void swap(CMatrix4D& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CMatrix2D.hpp>
#include <Depth/include/geometry/CMatrix3D.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/geometry/CMatrix4D.inl>
/*==========================================================================*/
//! \example example-geometry-CMatrix4D.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CMatrix4D.cpp
/*==========================================================================*/
#endif
