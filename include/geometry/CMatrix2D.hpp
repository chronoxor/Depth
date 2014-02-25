/*!
 *  \file    CMatrix2D.hpp Representation of the transformation matrix on a
 *           plane.
 *  \brief   Transformation matrix on a plane class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Transformation matrix on a plane class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   01.07.2008 21:26:26

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
#ifndef __CMATRIX2D_HPP__
#define __CMATRIX2D_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/geometry/CPoint2D.hpp>
#include <Depth/include/geometry/CVector2D.hpp>
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
class CMatrix3D;
class CMatrix4D;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Transformation matrix on a plane class.
/*!
    Class represents 2-dimension transformation matrix on a plane. It provides
    common functionality of the 2D matrix arithmetic and  utility  methods  to
    perform 2D transformation.
*/
class GEOMETRY_API CMatrix2D
{
  //! Type for MConceptDepthType constraint checking.
  typedef CMatrix2D TDepthCheckType;

  // Check CMatrix2D class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  Treal m_M[2][2];                      //!< Transformation matrix values.

  //! Default class constructor.
  /*!
      Set zero or identity 2D transformation matrix.

      \param a_cIdentityFlag - Make matrix identity flag (default is true).
  */
  CMatrix2D(const Tbool a_cIdentityFlag = true);
  //! Initialize transformation matrix values through the array.
  /*!
      \param a_cpMatrixBuffer - Constant pointer to the matrix values array.
  */
  CMatrix2D(const Treal a_cpMatrixBuffer[]);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix2D class.
  */
  CMatrix2D(const CMatrix2D& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix3D class.
  */
  CMatrix2D(const CMatrix3D& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix4D class.
  */
  CMatrix2D(const CMatrix4D& a_crInstance);
  //! Class destructor.
 ~CMatrix2D();

  //! Operator: Equal to another CMatrix2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix2D class.
      \return true  - if CMatrix2D class instance is equal to another one. \n
              false - if CMatrix2D class instance is not equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator == (const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2);
  //! Operator: Not equal to another CMatrix2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix2D class.
      \return true  - if CMatrix2D class instance is not equal to another one. \n
              false - if CMatrix2D class instance is equal to another one. \n
  */
  friend GEOMETRY_API Tbool operator != (const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2);

  //! Operator: Unary plus.
  /*!
      Applies unary plus operator to all matrix values.

      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \return New instance of CMatrix2D class with applied plus operator.
  */
  friend GEOMETRY_API CMatrix2D operator + (const CMatrix2D& a_crInstance);
  //! Operator: Unary minus.
  /*!
      Applies unary minus operator to all matrix values.

      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \return New instance of CMatrix2D class with applied minus operator.
  */
  friend GEOMETRY_API CMatrix2D operator - (const CMatrix2D& a_crInstance);

  //! Operator: Add real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix2D class with applied add operator.
  */
  friend GEOMETRY_API CMatrix2D operator + (const CMatrix2D& a_crInstance, const Treal a_cValue);
  //! Operator: Add another CMatrix2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix2D class.
      \return New instance of CMatrix2D class with applied add operator.
  */
  friend GEOMETRY_API CMatrix2D operator + (const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2);
  //! Operator: Add real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \return New instance of CMatrix2D class with applied add operator.
  */
  friend GEOMETRY_API CMatrix2D operator + (const Treal a_cValue, const CMatrix2D& a_crInstance);

  //! Operator: Sub real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix2D class with applied sub operator.
  */
  friend GEOMETRY_API CMatrix2D operator - (const CMatrix2D& a_crInstance, const Treal a_cValue);
  //! Operator: Sub another CMatrix2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix2D class.
      \return New instance of CMatrix2D class with applied sub operator.
  */
  friend GEOMETRY_API CMatrix2D operator - (const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2);
  //! Operator: Sub real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \return New instance of CMatrix2D class with applied sub operator.
  */
  friend GEOMETRY_API CMatrix2D operator - (const Treal a_cValue, const CMatrix2D& a_crInstance);

  //! Operator: Mul real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix2D class with applied mul operator.
  */
  friend GEOMETRY_API CMatrix2D operator * (const CMatrix2D& a_crInstance, const Treal a_cValue);
  //! Operator: Mul another CMatrix2D class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to another instance of the CMatrix2D class.
      \return New instance of CMatrix2D class with applied mul operator.
  */
  friend GEOMETRY_API CMatrix2D operator * (const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2);
  //! Operator: Mul real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \return New instance of CMatrix2D class with applied mul operator.
  */
  friend GEOMETRY_API CMatrix2D operator * (const Treal a_cValue, const CMatrix2D& a_crInstance);

  //! Operator: Div real number.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \param a_cValue - Real number value.
      \return New instance of CMatrix2D class with applied div operator.
  */
  friend GEOMETRY_API CMatrix2D operator / (const CMatrix2D& a_crInstance, const Treal a_cValue);
  //! Operator: Div real number.
  /*!
      \param a_cValue - Real number value.
      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \return New instance of CMatrix2D class with applied div operator.
  */
  friend GEOMETRY_API CMatrix2D operator / (const Treal a_cValue, const CMatrix2D& a_crInstance);

  //! Transform coordinates of the point on a plane with the current matrix.
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \return CPoint2D result of the transformation.
  */
  friend GEOMETRY_API CPoint2D<Treal> operator * (const CPoint2D<Treal>& a_crPoint2D, const CMatrix2D& a_crInstance);
  //! Transform coordinates of the vector on a plane with the current matrix.
  /*!
      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \param a_crInstance - Constant reference to the current instance of the CMatrix2D class.
      \return CVector2D result of the transformation.
  */
  friend GEOMETRY_API CVector2D operator * (const CVector2D& a_crVector2D, const CMatrix2D& a_crInstance);

  //! Operator: Assign another CMatrix2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix2D class.
      \return Reference to the current class instance.
  */
  CMatrix2D& operator = (const CMatrix2D& a_crInstance);
  //! Operator: Assign another CMatrix3D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix3D class.
      \return Reference to the current class instance.
  */
  CMatrix2D& operator = (const CMatrix3D& a_crInstance);
  //! Operator: Assign another CMatrix4D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix4D class.
      \return Reference to the current class instance.
  */
  CMatrix2D& operator = (const CMatrix4D& a_crInstance);

  //! Operator: Add and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix2D& operator += (const Treal a_cValue);
  //! Operator: Add and assign another CMatrix2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix2D class.
      \return Reference to the current class instance.
  */
  CMatrix2D& operator += (const CMatrix2D& a_crInstance);
  //! Operator: Sub and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix2D& operator -= (const Treal a_cValue);
  //! Operator: Sub and assign another CMatrix2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix2D class.
      \return Reference to the current class instance.
  */
  CMatrix2D& operator -= (const CMatrix2D& a_crInstance);
  //! Operator: Mul and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix2D& operator *= (const Treal a_cValue);
  //! Operator: Mul and assign another CMatrix2D class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMatrix2D class.
      \return Reference to the current class instance.
  */
  CMatrix2D& operator *= (const CMatrix2D& a_crInstance);
  //! Operator: Div and assign real number.
  /*!
      \param a_cValue - Real number value.
      \return Reference to the current class instance.
  */
  CMatrix2D& operator /= (const Treal a_cValue);

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

  //! Get rotating angle from the current matrix.
  /*!
      \return Rotating angle from the current matrix.
  */
  Treal getRotateAngle() const;

  //! Perform Eigen matrix decomposition (M = R * S * transpose(R)).
  /*!
      \param a_rRotation - Reference to the decomposed rotation matrix.
      \param a_rScale - Reference to the decomposed scale matrix.
  */
  void decomposeEigen(CMatrix2D& a_rRotation, CMatrix2D& a_rScale) const;

  //! Perform Gram-Schmidt orthonormalization.
  /*!
      Algorithm  uses  Gram-Schmidt  orthogonalization. If  current  matrix is
      M = [m0|m1], then orthonormal output matrix is Q = [q0|q1],

      q0 = m0/|m0|
      q1 = (m1-(q0*m1)q0)/|m1-(q0*m1)q0|

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
  //! Rotate coordinates of the vector on a plane with the current matrix.
  /*!
      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \return CVector2D result of the rotation.
  */
  CVector2D rotate(const CVector2D& a_crVector2D) const;

  //! Transform coordinates of the point on a plane with the current matrix.
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \return CPoint2D result of the transformation.
  */
  CPoint2D<Treal> transform(const CPoint2D<Treal>& a_crPoint2D) const;
  //! Transform coordinates of the vector on a plane with the current matrix.
  /*!
      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \return CVector2D result of the transformation.
  */
  CVector2D transform(const CVector2D& a_crVector2D) const;

  //! Rotate coordinates of the point on a plane with the current matrix (faster version).
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \param a_rResult - Reference to the result rotated instance of the CPoint2D class.
  */
  void rotate(const CPoint2D<Treal>& a_crPoint2D, CPoint2D<Treal>& a_rResult) const;
  //! Rotate coordinates of the vector on a plane with the current matrix (faster version).
  /*!
      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \param a_rResult - Reference to the result rotated instance of the CVector2D class.
  */
  void rotate(const CVector2D& a_crVector2D, CVector2D& a_rResult) const;

  //! Transform coordinates of the point on a plane with the current matrix (faster version).
  /*!
      \param a_crPoint2D - Constant reference to the instance of the CPoint2D class.
      \param a_rResult - Reference to the result transformed instance of the CPoint2D class.
  */
  void transform(const CPoint2D<Treal>& a_crPoint2D, CPoint2D<Treal>& a_rResult) const;
  //! Transform coordinates of the vector on a plane with the current matrix (faster version).
  /*!
      \param a_crVector2D - Constant reference to the instance of the CVector2D class.
      \param a_rResult - Reference to the result transformed instance of the CVector2D class.
  */
  void transform(const CVector2D& a_crVector2D, CVector2D& a_rResult) const;

  //! Calculate the addition of two matrixes.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix2D class.
      \return Matrix result of the addition of two matrixes.
  */
  static CMatrix2D add(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2);
  //! Calculate the subtraction of two matrixes.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix2D class.
      \return Matrix result of the subtraction of two matrixes.
  */
  static CMatrix2D sub(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2);
  //! Calculate the multiplication of two matrixes.
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix2D class.
      \return Matrix result of the multiplication of two matrixes.
  */
  static CMatrix2D mul(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2);

  //! Get zero matrix.
  /*!
      \return Zero matrix.
  */
  static CMatrix2D zero();
  //! Get identity matrix.
  /*!
      \return Identity matrix.
  */
  static CMatrix2D identity();

  //! Get adjoint matrix of the given one.
  /*!
      \param a_crInstance - Constant reference to the instance of the CMatrix2D class.
      \return Adjoint matrix.
  */
  static CMatrix2D adjoint(const CMatrix2D& a_crInstance);
  //! Get invert matrix of the given one.
  /*!
      \param a_crInstance - Constant reference to the instance of the CMatrix2D class.
      \return Invert matrix.
  */
  static CMatrix2D invert(const CMatrix2D& a_crInstance);
  //! Get transpose matrix of the given one.
  /*!
      \param a_crInstance - Constant reference to the instance of the CMatrix2D class.
      \return Transpose matrix.
  */
  static CMatrix2D transpose(const CMatrix2D& a_crInstance);

  //! Get transpose times matrix of the two given ones (transpose(A) * B).
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix2D class.
      \return Transpose times matrix.
  */
  static CMatrix2D transposeTimes(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2);
  //! Get times transpose matrix of the two given ones (A * transpose(B)).
  /*!
      \param a_crInstance1 - Constant reference to the first instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix2D class.
      \return Times transpose matrix.
  */
  static CMatrix2D timesTranspose(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2);

  //! Get tensor product matrix of the two given vectors (transpose(U) * V).
  /*!
      \param a_crU - Constant reference to the first instance of the CVector2D class.
      \param a_crV - Constant reference to the second instance of the CVector2D class.
      \return Tensor product matrix.
  */
  static CMatrix2D tensorProduct(const CVector2D& a_crU, const CVector2D& a_crV);

  //! Get scale matrix on a plane.
  /*!
      \param a_cScaleX - Scale value for the X coordinate.
      \param a_cScaleY - Scale value for the Y coordinate.
      \return Scale matrix on a plane.
  */
  static CMatrix2D scale(const Treal a_cScaleX, const Treal a_cScaleY);
  //! Get shear matrix on a plane.
  /*!
      \param a_cShearXY - Shear value X by Y.
      \param a_cShearYX - Shear value Y by X.
      \return Shear matrix on a plane.
  */
  static CMatrix2D shear(const Treal a_cShearXY, const Treal a_cShearYX);
  //! Get rotate matrix on a plane.
  /*!
      \param a_cAngle - Rotating angle.
      \return Rotate matrix on a plane.
  */
  static CMatrix2D rotate(const Treal a_cAngle);
  //! Get mirror X matrix on a plane.
  /*!
      \return Mirror X matrix on a plane.
  */
  static CMatrix2D mirrorX();
  //! Get mirror Y matrix on a plane.
  /*!
      \return Mirror Y matrix on a plane.
  */
  static CMatrix2D mirrorY();

  //! Calculate the linear spherical interpolation of two matrixes.
  /*!
      Linear spherical interpolation is calculated as a part matrix  from  the
      first one to the second one.

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix2D class.
      \param a_cPart - Linear interpolation part.
      \return Linear spherical interpolation of two matrixes.
  */
  static CMatrix2D slerp(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2, const Treal a_cPart);
  //! Calculate the linear spherical interpolation of two matrixes with extra spins.
  /*!
      Linear spherical interpolation is calculated as a part matrix  from  the
      first one to the second  one.

      Extra spins regulates count of full rotation spin, could be 0, less than
      0 or more than 0.

      Usually linear interpolation part is taken from the range [0, 1].

      \param a_crInstance1 - Constant reference to the first instance of the CMatrix2D class.
      \param a_crInstance2 - Constant reference to the second instance of the CMatrix2D class.
      \param a_cPart - Linear interpolation part.
      \param a_cSpins - Spins count.
      \return Linear spherical interpolation of two matrixes.
  */
  static CMatrix2D slerpSpins(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2, const Treal a_cPart, const Treal a_cSpins);

  //! Serialize CMatrix2D class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CMatrix2D class instances.
  /*!
      \param a_rInstance - Reference to another CMatrix2D class instance.
  */
  void swap(CMatrix2D& a_rInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/geometry/CMatrix3D.hpp>
#include <Depth/include/geometry/CMatrix4D.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/geometry/CMatrix2D.inl>
/*==========================================================================*/
//! \example example-geometry-CMatrix2D.cpp
/*--------------------------------------------------------------------------*/
//! \test test-geometry-CMatrix2D.cpp
/*==========================================================================*/
#endif
