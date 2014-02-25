/*!
 *  \file    CMatrix3D.hpp Representation of the transformation matrix in a
 *           space.
 *  \brief   Transformation matrix in a space class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Transformation matrix in a space class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   01.07.2008 23:27:50

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
#ifndef __CMATRIX3D_HPP__
#define __CMATRIX3D_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CPoint2D.hpp>
#include <Depth/include/geometry/CPoint3D.hpp>
#include <Depth/include/geometry/CVector2D.hpp>
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
class CMatrix4D;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Transformation matrix in a space class.
/*!
    Class represents 3-dimension transformation matrix in a space. It provides
    common functionality of the 3D matrix arithmetic and  utility  methods  to
    perform 3D transformation.

    Transformation matrix in a space  uses  right-hand  coordinate  system  to
    perform transformations. In this coordinate system the positive  X  and  Y
    axes point right and up, and the negative Z axis points forward.  Positive
    rotation is counterclockwise about the axis of rotation.
*/
class GEOMETRY_API CMatrix3D
{
  //! Type for MConceptDepthType constraint checking.
  typedef CMatrix3D TDepthCheckType;

  // Check CMatrix3D class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  Treal m_M[3][3];                      //!< Transformation matrix values.

  //! Default class constructor.
  /*!
      Set zero or identity 2D transformation matrix.

      \param a_cIdentityFlag - Make matrix identity flag (default is true).
  */
  CMatrix3D(const Tbool a_cIdentityFlag = true);
  //! Initialize transformation matrix values through the array.
  /*!
      \param a_cpMatrixBuffer - Constant pointer to the matrix values array.
  */
  CMatrix3D(const Treal a_cpMatrixBuffer[]);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix2D class.
  */
  CMatrix3D(const CMatrix2D& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix3D class.
  */
  CMatrix3D(const CMatrix3D& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix4D class.
  */
  CMatrix3D(const CMatrix4D& a_crInstance);
  //! Class destructor.
 ~CMatrix3D();

  //! Operator: Equal to another CMatrix3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix3D class.
      \return true  - if CMatrix3D class instance is equal to another one. \n
              false - if CMatrix3D class instance is not equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator == (const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2);
  //! Operator: Not equal to another CMatrix3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix3D class.
      \return true  - if CMatrix3D class instance is not equal to another one. \n
              false - if CMatrix3D class instance is equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator != (const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Applies unary plus operator to all matrix values.

      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \return New instance of CMatrix3D class with applied plus operator.
  */
  friend GEOMETRY_API CMatrix3D operator + (const CMatrix3D& a_crInstance);
  //! Operator: Unary minus.
  /*!
      Applies unary minus operator to all matrix values.

      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \return New instance of CMatrix3D class with applied minus operator.
  */
  friend GEOMETRY_API CMatrix3D operator - (const CMatrix3D& a_crInstance);

  //! Operator: Add real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix3D class with applied add operator.
  */
  friend GEOMETRY_API CMatrix3D operator + (const CMatrix3D& a_crInstance, const Treal a_cValue);
  //! Operator: Add another CMatrix3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix3D class.
      \return New instance of CMatrix3D class with applied add operator.
  */
  friend GEOMETRY_API CMatrix3D operator + (const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2);
  //! Operator: Add real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \return New instance of CMatrix3D class with applied add operator.
  */
  friend GEOMETRY_API CMatrix3D operator + (const Treal a_cValue, const CMatrix3D& a_crInstance);

  //! Operator: Sub real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix3D class with applied sub operator.
  */
  friend GEOMETRY_API CMatrix3D operator - (const CMatrix3D& a_crInstance, const Treal a_cValue);
  //! Operator: Sub another CMatrix3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix3D class.
      \return New instance of CMatrix3D class with applied sub operator.
  */
  friend GEOMETRY_API CMatrix3D operator - (const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2);
  //! Operator: Sub real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \return New instance of CMatrix3D class with applied sub operator.
  */
  friend GEOMETRY_API CMatrix3D operator - (const Treal a_cValue, const CMatrix3D& a_crInstance);

  //! Operator: Mul real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix3D class with applied mul operator.
  */
  friend GEOMETRY_API CMatrix3D operator * (const CMatrix3D& a_crInstance, const Treal a_cValue);
  //! Operator: Mul another CMatrix3D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix3D class.
      \return New instance of CMatrix3D class with applied mul operator.
  */
  friend GEOMETRY_API CMatrix3D operator * (const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2);
  //! Operator: Mul real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \return New instance of CMatrix3D class with applied mul operator.
  */
  friend GEOMETRY_API CMatrix3D operator * (const Treal a_cValue, const CMatrix3D& a_crInstance);

  //! Operator: Div real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix3D class with applied div operator.
  */
  friend GEOMETRY_API CMatrix3D operator / (const CMatrix3D& a_crInstance, const Treal a_cValue);
  //! Operator: Div real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \return New instance of CMatrix3D class with applied div operator.
  */
  friend GEOMETRY_API CMatrix3D operator / (const Treal a_cValue, const CMatrix3D& a_crInstance);

  //! Transform coordinates of the point on a plane with the current matrix.
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \return CPoint2D result of the transformation.
  */
  friend GEOMETRY_API CPoint2D<Treal> operator * (const CPoint2D<Treal>& a_crPoint2D, const CMatrix3D& a_crInstance);
  //! Transform coordinates of the point in a space with the current matrix.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \return CPoint3D result of the transformation.
  */
  friend GEOMETRY_API CPoint3D<Treal> operator * (const CPoint3D<Treal>& a_crPoint3D, const CMatrix3D& a_crInstance);
  //! Transform coordinates of the vector on a plane with the current matrix.
  /*!
      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \return CVector2D result of the transformation.
  */
  friend GEOMETRY_API CVector2D operator * (const CVector2D& a_crVector2D, const CMatrix3D& a_crInstance);
  //! Transform coordinates of the vector in a space with the current matrix.
  /*!
      \param a_crVector3D - Constant reference to the instance of the CVector3D class.
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \return CVector3D result of the transformation.
  */
  friend GEOMETRY_API CVector3D operator * (const CVector3D& a_crVector3D, const CMatrix3D& a_crInstance);
  //! Transform coordinates of the extended vector in a space with the current matrix.
  /*!
      \param a_crVector4D - Constant reference to the instance of the CVector4D class.
      \param a_crInstance - Constant reference to the current instance of the CMatrix3D class.
      \return CVector4D result of the transformation.
  */
  friend GEOMETRY_API CVector4D operator * (const CVector4D& a_crVector4D, const CMatrix3D& a_crInstance);

  //! Operator: Assign another CMatrix2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix2D class.
      \return Reference to the current class instance.
  */
  CMatrix3D& operator = (const CMatrix2D& a_crInstance);
  //! Operator: Assign another CMatrix3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix3D class.
      \return Reference to the current class instance.
  */
  CMatrix3D& operator = (const CMatrix3D& a_crInstance);
  //! Operator: Assign another CMatrix4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix4D class.
      \return Reference to the current class instance.
  */
  CMatrix3D& operator = (const CMatrix4D& a_crInstance);

  //! Operator: Add and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix3D& operator += (const Treal a_cValue);
  //! Operator: Add and assign another CMatrix3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix3D class.
      \return Reference to the current class instance.
  */
  CMatrix3D& operator += (const CMatrix3D& a_crInstance);
  //! Operator: Sub and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix3D& operator -= (const Treal a_cValue);
  //! Operator: Sub and assign another CMatrix3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix3D class.
      \return Reference to the current class instance.
  */
  CMatrix3D& operator -= (const CMatrix3D& a_crInstance);
  //! Operator: Mul and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix3D& operator *= (const Treal a_cValue);
  //! Operator: Mul and assign another CMatrix3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix3D class.
      \return Reference to the current class instance.
  */
  CMatrix3D& operator *= (const CMatrix3D& a_crInstance);
  //! Operator: Div and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix3D& operator /= (const Treal a_cValue);

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

  //! Get rotating angle from the current matrix (2D version).
  /*!
      \return Rotating angle from the current matrix.
  */
  Treal getRotateAngle2D() const;

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

  //! Perform Eigen matrix decomposition (M = R * S * transpose(R)).
  /*!
      \param a_rRotation - Reference to the decomposed rotation matrix.
      \param a_rScale - Reference to the decomposed scale matrix.
      \return true  - if matrix was successfully decomposed. \n
              false - if matrix was not successfully decomposed. \n
  */
  Tbool decomposeEigen(CMatrix3D& a_rRotation, CMatrix3D& a_rScale) const;
  //! Perform QDU matrix decomposition (M = Q * D * U).
  /*!
      \param a_rQ - Reference to the decomposed orthogonal matrix.
      \param a_rD - Reference to the decomposed diagonal matrix.
      \param a_rU - Reference to the decomposed upper triangular matrix.
  */
  void decomposeQDU(CMatrix3D& a_rQ, CMatrix3D& a_rD, CMatrix3D& a_rU) const;
  //! Perform singular matrix decomposition (M = L * S * R).
  /*!
      \param a_rL - Reference to the decomposed left orthogonal matrix.
      \param a_rS - Reference to the decomposed diagonal matrix.
      \param a_rR - Reference to the decomposed right orthogonal matrix.
  */
  void decomposeSingular(CMatrix3D& a_rL, CMatrix3D& a_rS, CMatrix3D& a_rR) const;

  //! Perform Gram-Schmidt orthonormalization.
  /*!
      Algorithm  uses  Gram-Schmidt  orthogonalization.  If current  matrix is
      M = [m0|m1|m2], then orthonormal output matrix is Q = [q0|q1|q2],

      q0 = m0/|m0|
      q1 = (m1-(q0*m1)q0)/|m1-(q0*m1)q0|
      q2 = (m2-(q0*m2)q0-(q1*m2)q1)/|m2-(q0*m2)q0-(q1*m2)q1|

      where |V| indicates length of vector V and A*B indicates dot product  of
      vectors A and B.
  */
  void orthonormalize();

  //! Rotate coordinates of the point on a plane with the current matrix.
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \return CPoint2D result of the rotation.
  */
  CPoint2D<Treal> rotate(const CPoint2D<Treal>& a_crPoint2D) const;
  //! Rotate coordinates of the point in a space with the current matrix.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return CPoint3D result of the rotation.
  */
  CPoint3D<Treal> rotate(const CPoint3D<Treal>& a_crPoint3D) const;
  //! Rotate coordinates of the vector on a plane with the current matrix.
  /*!
      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \return CVector2D result of the rotation.
  */
  CVector2D rotate(const CVector2D& a_crVector2D) const;
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

  //! Transform coordinates of the point on a plane with the current matrix.
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \return CPoint2D result of the transformation.
  */
  CPoint2D<Treal> transform(const CPoint2D<Treal>& a_crPoint2D) const;
  //! Transform coordinates of the point in a space with the current matrix.
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \return CPoint3D result of the transformation.
  */
  CPoint3D<Treal> transform(const CPoint3D<Treal>& a_crPoint3D) const;
  //! Transform coordinates of the vector on a plane with the current matrix.
  /*!
      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \return CVector2D result of the transformation.
  */
  CVector2D transform(const CVector2D& a_crVector2D) const;
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

  //! Rotate coordinates of the point on a plane with the current matrix (faster version).
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \param a_rResult - Reference to the result rotated instance of the CPoint2D class.
  */
  void rotate(const CPoint2D<Treal>& a_crPoint2D, CPoint2D<Treal>& a_rResult) const;
  //! Rotate coordinates of the point in a space with the current matrix (faster version).
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result rotated instance of the CPoint3D class.
  */
  void rotate(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Rotate coordinates of the vector on a plane with the current matrix (faster version).
  /*!
      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \param a_rResult - Reference to the result rotated instance of the CVector2D class.
  */
  void rotate(const CVector2D& a_crVector2D, CVector2D& a_rResult) const;
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

  //! Transform coordinates of the point on a plane with the current matrix (faster version).
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \param a_rResult - Reference to the result transformed instance of the CPoint2D class.
  */
  void transform(const CPoint2D<Treal>& a_crPoint2D, CPoint2D<Treal>& a_rResult) const;
  //! Transform coordinates of the point in a space with the current matrix (faster version).
  /*!
      \param a_crPoint3D - Constant reference to the instance of the CPoint3D class.
      \param a_rResult - Reference to the result transformed instance of the CPoint3D class.
  */
  void transform(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const;
  //! Transform coordinates of the vector on a plane with the current matrix (faster version).
  /*!
      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \param a_rResult - Reference to the result transformed instance of the CVector2D class.
  */
  void transform(const CVector2D& a_crVector2D, CVector2D& a_rResult) const;
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

  //! Extended transform coordinates of the point on a plane with the current matrix.
  /*!
      Extended transformation uses additional  matrix  column  to  adjust  the
      transformed coordinates.

      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \return CPoint2D result of the transformation.
  */
  CPoint2D<Treal> transformEx(const CPoint2D<Treal>& a_crPoint2D) const;
  //! Extended transform coordinates of the vector on a plane with the current matrix.
  /*!
      Extended transformation uses additional  matrix  column  to  adjust  the
      transformed coordinates.

      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \return CVector2D result of the transformation.
  */
  CVector2D transformEx(const CVector2D& a_crVector2D) const;

  //! Extended transform coordinates of the point on a plane with the current matrix (faster version).
  /*!
      Extended transformation uses additional  matrix  column  to  adjust  the
      transformed coordinates.

      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \param a_rResult - Reference to the result transformed instance of the CPoint2D class.
  */
  void transformEx(const CPoint2D<Treal>& a_crPoint2D, CPoint2D<Treal>& a_rResult) const;
  //! Extended transform coordinates of the vector on a plane with the current matrix (faster version).
  /*!
      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \param a_rResult - Reference to the result transformed instance of the CVector2D class.
  */
  void transformEx(const CVector2D& a_crVector2D, CVector2D& a_rResult) const;

  //! Calculate the addition of two matrixes.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix3D class.
      \return Matrix result of the addition of two matrixes.
  */
  static CMatrix3D add(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2);
  //! Calculate the subtraction of two matrixes.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix3D class.
      \return Matrix result of the subtraction of two matrixes.
  */
  static CMatrix3D sub(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2);
  //! Calculate the multiplication of two matrixes.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix3D class.
      \return Matrix result of the multiplication of two matrixes.
  */
  static CMatrix3D mul(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2);

  //! Get zero matrix.
  /*!
      \return Zero matrix.
  */
  static CMatrix3D zero();
  //! Get identity matrix.
  /*!
      \return Identity matrix.
  */
  static CMatrix3D identity();

  //! Get adjoint matrix of the given one.
  /*!
      \param a_crInstance - Constant reference to the instance of the CMatrix3D class.
      \return Adjoint matrix.
  */
  static CMatrix3D adjoint(const CMatrix3D& a_crInstance);
  //! Get invert matrix of the given one.
  /*!
      \param a_crInstance - Constant reference to the instance of the CMatrix3D class.
      \return Invert matrix.
  */
  static CMatrix3D invert(const CMatrix3D& a_crInstance);
  //! Get transpose matrix of the given one.
  /*!
      \param a_crInstance - Constant reference to the instance of the CMatrix3D class.
      \return Transpose matrix.
  */
  static CMatrix3D transpose(const CMatrix3D& a_crInstance);

  //! Get transpose times matrix of the two given ones (transpose(A) * B).
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix3D class.
      \return Transpose times matrix.
  */
  static CMatrix3D transposeTimes(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2);
  //! Get times transpose matrix of the two given ones (A * transpose(B)).
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix3D class.
      \return Times transpose matrix.
  */
  static CMatrix3D timesTranspose(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2);

  //! Get tensor product matrix of the two given vectors (transpose(U) * V).
  /*!
      \param a_crU - Constant reference to the first instance of the CVector2D class.
      \param a_crV - Constant reference to the second instance of the CVector2D class.
      \return Tensor product matrix.
  */
  static CMatrix3D tensorProduct(const CVector2D& a_crU, const CVector2D& a_crV);
  //! Get tensor product matrix of the two given vectors (transpose(U) * V).
  /*!
      \param a_crU - Constant reference to the first instance of the CVector3D class.
      \param a_crV - Constant reference to the second instance of the CVector3D class.
      \return Tensor product matrix.
  */
  static CMatrix3D tensorProduct(const CVector3D& a_crU, const CVector3D& a_crV);

  //! Get translate matrix on a plane (2D version).
  /*!
      \param a_cTranslateX - Translate value for the X coordinate.
      \param a_cTranslateY - Translate value for the Y coordinate.
      \return Translate matrix on a plane.
  */
  static CMatrix3D translate2D(const Treal a_cTranslateX, const Treal a_cTranslateY);
  //! Get scale matrix on a plane (2D version).
  /*!
      \param a_cScaleX - Scale value for the X coordinate.
      \param a_cScaleY - Scale value for the Y coordinate.
      \return Scale matrix on a plane.
  */
  static CMatrix3D scale2D(const Treal a_cScaleX, const Treal a_cScaleY);
  //! Get shear matrix on a plane (2D version).
  /*!
      \param a_cShearXY - Shear value X by Y.
      \param a_cShearYX - Shear value Y by X.
      \return Shear matrix on a plane.
  */
  static CMatrix3D shear2D(const Treal a_cShearXY, const Treal a_cShearYX);
  //! Get rotate matrix on a plane (2D version).
  /*!
      \param a_cAngle - Rotating angle.
      \return Rotate matrix on a plane.
  */
  static CMatrix3D rotate2D(const Treal a_cAngle);
  //! Get mirror X matrix on a plane (2D version).
  /*!
      \return Mirror X matrix on a plane.
  */
  static CMatrix3D mirrorX2D();
  //! Get mirror Y matrix on a plane (2D version).
  /*!
      \return Mirror Y matrix on a plane.
  */
  static CMatrix3D mirrorY2D();

  //! Get scale matrix in a space.
  /*!
      \param a_cScaleX - Scale value for the X coordinate.
      \param a_cScaleY - Scale value for the Y coordinate.
      \param a_cScaleZ - Scale value for the Z coordinate.
      \return Scale matrix in a space.
  */
  static CMatrix3D scale(const Treal a_cScaleX, const Treal a_cScaleY, const Treal a_cScaleZ);
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
  static CMatrix3D shear(const Treal a_cShearXY, const Treal a_cShearXZ, const Treal a_cShearYX, const Treal a_cShearYZ, const Treal a_cShearZX, const Treal a_cShearZY);
  //! Get rotate matrix in a space from the given axis and rotating angle.
  /*!
      \param a_crAxis - Constant reference to the instance of the axis CVector3D class.
      \param a_cAngle - Rotating angle.
      \return Rotate matrix in a space.
  */
  static CMatrix3D rotate(const CVector3D& a_crAxis, const Treal a_cAngle);
  //! Get rotate matrix in a space by axis X.
  /*!
      \param a_cAngle - Rotating angle.
      \return Rotate matrix in a space by axis X.
  */
  static CMatrix3D rotateX(const Treal a_cAngle);
  //! Get rotate matrix in a space by axis Y.
  /*!
      \param a_cAngle - Rotating angle.
      \return Rotate matrix in a space by axis Y.
  */
  static CMatrix3D rotateY(const Treal a_cAngle);
  //! Get rotate matrix in a space by axis Z.
  /*!
      \param a_cAngle - Rotating angle.
      \return Rotate matrix in a space by axis Z.
  */
  static CMatrix3D rotateZ(const Treal a_cAngle);
  //! Get rotate matrix in a space by axis in order XYZ.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order XYZ.
  */
  static CMatrix3D rotateXYZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space by axis in order XZY.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order XZY.
  */
  static CMatrix3D rotateXZY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space by axis in order YXZ.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order YXZ.
  */
  static CMatrix3D rotateYXZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space by axis in order YZX.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order YZX.
  */
  static CMatrix3D rotateYZX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space by axis in order ZXY.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order ZXY.
  */
  static CMatrix3D rotateZXY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space by axis in order ZYX.
  /*!
      \param a_cAngleX - Rotating angle by axis X.
      \param a_cAngleY - Rotating angle by axis Y.
      \param a_cAngleZ - Rotating angle by axis Z.
      \return Rotate matrix in a space by axis in order ZYX.
  */
  static CMatrix3D rotateZYX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ);
  //! Get rotate matrix in a space in yaw-pitch-roll system.
  /*!
      \param a_cAngleYaw - Rotating angle in xOz plane (yaw angle).
      \param a_cAnglePitch - Rotating angle in yOZ plane (pitch angle).
      \param a_cAngleRoll - Rotating angle in xOy plane (roll angle).
      \return Rotate matrix in a space in yaw-pitch-roll system.
  */
  static CMatrix3D rotateYPR(const Treal a_cAngleYaw, const Treal a_cAnglePitch, const Treal a_cAngleRoll);
  //! Get mirror X matrix in a space.
  /*!
      \return Mirror X matrix in a space.
  */
  static CMatrix3D mirrorX();
  //! Get mirror Y matrix in a space.
  /*!
      \return Mirror Y matrix in a space.
  */
  static CMatrix3D mirrorY();
  //! Get mirror Z matrix in a space.
  /*!
      \return Mirror Z matrix in a space.
  */
  static CMatrix3D mirrorZ();

  //! Calculate the linear spherical interpolation of two matrixes (2D version).
  /*!
      Linear spherical interpolation is calculated as a part matrix  from  the
      first one to the second one.

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix3D class.
      \param a_cPart - Linear interpolation part.
      \return Linear spherical interpolation of two matrixes.
  */
  static CMatrix3D slerp2D(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2, const Treal a_cPart);
  //! Calculate the linear spherical interpolation of two matrixes with extra spins (2D version).
  /*!
      Linear spherical interpolation is calculated as a part matrix  from  the
      first one to the second  one.

      Extra spins regulates count of full rotation spin, could be 0, less than
      0 or more than 0.

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix3D class.
      \param a_cPart - Linear interpolation part.
      \param a_cSpins - Spins count.
      \return Linear spherical interpolation of two matrixes.
  */
  static CMatrix3D slerpSpins2D(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2, const Treal a_cPart, const Treal a_cSpins);

  //! Calculate the linear spherical interpolation of two matrixes.
  /*!
      Linear spherical interpolation is calculated as a part matrix  from  the
      first one to the second one.

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix3D class.
      \param a_cPart - Linear interpolation part.
      \return Linear spherical interpolation of two matrixes.
  */
  static CMatrix3D slerp(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2, const Treal a_cPart);
  //! Calculate the linear spherical interpolation of two matrixes with extra spins.
  /*!
      Linear spherical interpolation is calculated as a part matrix  from  the
      first one to the second  one.

      Extra spins regulates count of full rotation spin, could be 0, less than
      0 or more than 0.

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CMatrix3D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix3D class.
      \param a_cPart - Linear interpolation part.
      \param a_cSpins - Spins count.
      \return Linear spherical interpolation of two matrixes.
  */
  static CMatrix3D slerpSpins(const CMatrix3D& a_crInstance1, const CMatrix3D& a_crInstance2, const Treal a_cPart, const Treal a_cSpins);

  //! Serialize CMatrix3D class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CMatrix3D class instances.
  /*!
      \param a_rInstance - Reference to another CMatrix3D class instance.
  */
  void swap(CMatrix3D& a_rInstance);

private:
  //! Householder reduction T=Q^t*M*Q (support for DecomposeEigen).
  /*!
      \param a_pDiag - Pointer to the diagonal vector.
      \param a_pSubDiag - Pointer to the sub-diagonal vector.
  */
  void tridiagonalize(Treal a_pDiag[3], Treal a_pSubDiag[3]);
  //! QL iteration with implicit shifting to reduce matrix from tridiagonal to diagonal (support for DecomposeEigen).
  /*!
      \param a_pDiag - Pointer to the diagonal vector.
      \param a_pSubDiag - Pointer to the sub-diagonal vector.
      \return true  - if QL iteration was successful. \n
              false - if QL iteration was not successful. \n
  */
  Tbool QLAlgorithm(Treal a_pDiag[3], Treal a_pSubDiag[3]);
  //! Bidiagonalize (support for DecomposeSingular).
  /*!
      \param a_rLOrthogonal - Reference to the left orthogonal instance of the CMatrix3D class.
      \param a_rROrthogonal - Reference to the right orthogonal instance of the CMatrix3D class.
  */
  void bidiagonalize(CMatrix3D& a_rLOrthogonal, CMatrix3D& a_rROrthogonal);
  //! Golub-Kahan step (support for DecomposeSingular).
  /*!
      \param a_rLOrthogonal - Reference to the left orthogonal instance of the CMatrix3D class.
      \param a_rROrthogonal - Reference to the right orthogonal instance of the CMatrix3D class.
  */
  void golubKahanStep(CMatrix3D& a_rLOrthogonal, CMatrix3D& a_rROrthogonal);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CMatrix2D.hpp>
#include <Depth/include/geometry/CMatrix4D.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/geometry/CMatrix3D.inl>
/*==========================================================================*/
//! \example example-geometry-CMatrix3D.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CMatrix3D.cpp
/*==========================================================================*/
#endif
