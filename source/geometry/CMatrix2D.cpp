/*!
 *  \file    CMatrix2D.cpp Representation of the transformation matrix on a
 *           plane.
 *  \brief   Transformation matrix on a plane class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Transformation matrix on a plane class (source).

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
#include <Depth/include/geometry.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/geometry/CMatrix2D.hpp>
#include <Depth/include/math/CMathConstants.hpp>
/*==========================================================================*/
#ifndef __CMATRIX2D_CPP__
#define __CMATRIX2D_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
GEOMETRY_API Tbool operator == (const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2)
{ CALL
  return (NMath::CMath::isEqual(a_crInstance1.m_M[0][0], a_crInstance2.m_M[0][0]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[0][1], a_crInstance2.m_M[0][1]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[1][0], a_crInstance2.m_M[1][0]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[1][1], a_crInstance2.m_M[1][1]));
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix2D operator + (const CMatrix2D& a_crInstance)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = +a_crInstance.m_M[0][0];
  result.m_M[0][1] = +a_crInstance.m_M[0][1];
  result.m_M[1][0] = +a_crInstance.m_M[1][0];
  result.m_M[1][1] = +a_crInstance.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix2D operator - (const CMatrix2D& a_crInstance)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = -a_crInstance.m_M[0][0];
  result.m_M[0][1] = -a_crInstance.m_M[0][1];
  result.m_M[1][0] = -a_crInstance.m_M[1][0];
  result.m_M[1][1] = -a_crInstance.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix2D operator + (const CMatrix2D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] + a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] + a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] + a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] + a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix2D operator + (const Treal a_cValue, const CMatrix2D& a_crInstance)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_cValue + a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue + a_crInstance.m_M[0][1];
  result.m_M[1][0] = a_cValue + a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue + a_crInstance.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix2D operator - (const CMatrix2D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] - a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] - a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] - a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] - a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix2D operator - (const Treal a_cValue, const CMatrix2D& a_crInstance)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_cValue - a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue - a_crInstance.m_M[0][1];
  result.m_M[1][0] = a_cValue - a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue - a_crInstance.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix2D operator * (const CMatrix2D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] * a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] * a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] * a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] * a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix2D operator * (const Treal a_cValue, const CMatrix2D& a_crInstance)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_cValue * a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue * a_crInstance.m_M[0][1];
  result.m_M[1][0] = a_cValue * a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue * a_crInstance.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix2D operator / (const CMatrix2D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] / a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] / a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] / a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] / a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix2D operator / (const Treal a_cValue, const CMatrix2D& a_crInstance)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_cValue / a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue / a_crInstance.m_M[0][1];
  result.m_M[1][0] = a_cValue / a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue / a_crInstance.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D& CMatrix2D::operator += (const Treal a_cValue)
{ CALL
  m_M[0][0] += a_cValue;
  m_M[0][1] += a_cValue;
  m_M[1][0] += a_cValue;
  m_M[1][1] += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
CMatrix2D& CMatrix2D::operator -= (const Treal a_cValue)
{ CALL
  m_M[0][0] -= a_cValue;
  m_M[0][1] -= a_cValue;
  m_M[1][0] -= a_cValue;
  m_M[1][1] -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
CMatrix2D& CMatrix2D::operator *= (const Treal a_cValue)
{ CALL
  m_M[0][0] *= a_cValue;
  m_M[0][1] *= a_cValue;
  m_M[1][0] *= a_cValue;
  m_M[1][1] *= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
CMatrix2D& CMatrix2D::operator /= (const Treal a_cValue)
{ CALL
  m_M[0][0] /= a_cValue;
  m_M[0][1] /= a_cValue;
  m_M[1][0] /= a_cValue;
  m_M[1][1] /= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::set(const Treal a_cpMatrixBuffer[])
{ CALL
  // Check if the pointer to the matrix values buffer is not NULL.
  ASSERT((a_cpMatrixBuffer != NULL), STR("Pointer to the matrix values buffer should not be NULL."))
  {
    clear();
  }

  m_M[0][0] = a_cpMatrixBuffer[0];
  m_M[0][1] = a_cpMatrixBuffer[1];
  m_M[1][0] = a_cpMatrixBuffer[2];
  m_M[1][1] = a_cpMatrixBuffer[3];
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::set(const CMatrix2D& a_crInstance)
{ CALL
  m_M[0][0] = a_crInstance.m_M[0][0];
  m_M[0][1] = a_crInstance.m_M[0][1];
  m_M[1][0] = a_crInstance.m_M[1][0];
  m_M[1][1] = a_crInstance.m_M[1][1];
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::set(const CMatrix3D& a_crInstance)
{ CALL
  m_M[0][0] = a_crInstance.m_M[0][0];
  m_M[0][1] = a_crInstance.m_M[0][1];
  m_M[1][0] = a_crInstance.m_M[1][0];
  m_M[1][1] = a_crInstance.m_M[1][1];
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::set(const CMatrix4D& a_crInstance)
{ CALL
  m_M[0][0] = a_crInstance.m_M[0][0];
  m_M[0][1] = a_crInstance.m_M[0][1];
  m_M[1][0] = a_crInstance.m_M[1][0];
  m_M[1][1] = a_crInstance.m_M[1][1];
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::clear(const Tbool a_cIdentityFlag/* = false */)
{ CALL
  m_M[0][0] = (a_cIdentityFlag ? CONSTR(1.0) : CONSTR(0.0));
  m_M[0][1] = 0.0;
  m_M[1][0] = 0.0;
  m_M[1][1] = (a_cIdentityFlag ? CONSTR(1.0) : CONSTR(0.0));
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::absolute()
{ CALL
  m_M[0][0] = NMath::CMath::fabs(m_M[0][0]);
  m_M[0][1] = NMath::CMath::fabs(m_M[0][1]);
  m_M[1][0] = NMath::CMath::fabs(m_M[1][0]);
  m_M[1][1] = NMath::CMath::fabs(m_M[1][1]);
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::negate()
{ CALL
  m_M[0][0] = -m_M[0][0];
  m_M[0][1] = -m_M[0][1];
  m_M[1][0] = -m_M[1][0];
  m_M[1][1] = -m_M[1][1];
}
/*--------------------------------------------------------------------------*/
Treal CMatrix2D::getDeterminant() const
{ CALL
  #define DET22(M00, M01, M10, M11) (M00 * M11 - M01 * M10)
  return DET22(m_M[0][0], m_M[0][1], m_M[1][0], m_M[1][1]);
  #undef DET22
}
/*--------------------------------------------------------------------------*/
Treal CMatrix2D::getRotateAngle() const
{ CALL
  return NMath::CMath::atan2(m_M[0][1], m_M[0][0]);
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::decomposeEigen(CMatrix2D& a_rRotation, CMatrix2D& a_rScale) const
{ CALL
  // Decompose scale matrix.
  Treal trace = m_M[0][0] + m_M[1][1];
  Treal diff = m_M[0][0] - m_M[1][1];
  Treal discr = NMath::CMath::sqrt(diff * diff + CONSTR(4.0) * m_M[1][0] * m_M[1][0]);
  Treal EVal0 = CONSTR(0.5) * (trace - discr);
  Treal EVal1 = CONSTR(0.5) * (trace + discr);
  a_rScale = scale(EVal0, EVal1);

  // Decompose rotate matrix.
  CVector2D row0(m_M[0][0] - EVal0, m_M[1][0]);
  CVector2D row1(m_M[1][0], m_M[1][1] - EVal0);
  Treal length0 = row0.length();
  Treal length1 = row1.length();
  if (length0 > length1)
  {
    if (length0 > NMath::CMath::getEpsilon())
    {
       a_rRotation.m_M[0][0] =  row0.m_Y;
       a_rRotation.m_M[0][1] = -row0.m_X;
       a_rRotation.m_M[1][0] =  row0.m_X;
       a_rRotation.m_M[1][1] =  row0.m_Y;
    }
    else
      a_rRotation = identity();
  }
  else
  {
    if (length1 > NMath::CMath::getEpsilon())
    {
      a_rRotation.m_M[0][0] =  row1.m_Y;
      a_rRotation.m_M[0][1] = -row1.m_X;
      a_rRotation.m_M[1][0] =  row1.m_X;
      a_rRotation.m_M[1][1] =  row1.m_Y;
    }
    else
      a_rRotation = identity();
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::orthonormalize()
{ CALL
  Treal len, dot0;

  // Compute q0.
  len = NMath::CMath::sqrt(m_M[0][0] * m_M[0][0] + m_M[0][1] * m_M[0][1]);
  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;
  m_M[0][0] *= len;
  m_M[0][1] *= len;

  // Compute q1
  dot0 = m_M[0][0] * m_M[1][0] + m_M[0][1] * m_M[1][1];
  m_M[1][0] -= dot0 * m_M[0][0];
  m_M[1][1] -= dot0 * m_M[0][1];
  len = NMath::CMath::sqrt(m_M[1][0] * m_M[1][0] + m_M[1][1] * m_M[1][1]);
  if (!NMath::CMath::isEqualZero(len))
    len = CONSTR(1.0) / len;
  else
    len = 1.0;
  m_M[1][0] *= len;
  m_M[1][1] *= len;
}
/*--------------------------------------------------------------------------*/
CPoint2D<Treal> CMatrix2D::transform(const CPoint2D<Treal>& a_crPoint2D) const
{ CALL
  CPoint2D<Treal> result;

  result.m_X = a_crPoint2D.m_X * m_M[0][0] + a_crPoint2D.m_Y * m_M[1][0];
  result.m_Y = a_crPoint2D.m_X * m_M[0][1] + a_crPoint2D.m_Y * m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CVector2D CMatrix2D::transform(const CVector2D& a_crVector2D) const
{ CALL
  CVector2D result;

  result.m_X = a_crVector2D.m_X * m_M[0][0] + a_crVector2D.m_Y * m_M[1][0];
  result.m_Y = a_crVector2D.m_X * m_M[0][1] + a_crVector2D.m_Y * m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::transform(const CPoint2D<Treal>& a_crPoint2D, CPoint2D<Treal>& a_rResult) const
{ CALL
  a_rResult.m_X = a_crPoint2D.m_X * m_M[0][0] + a_crPoint2D.m_Y * m_M[1][0];
  a_rResult.m_Y = a_crPoint2D.m_X * m_M[0][1] + a_crPoint2D.m_Y * m_M[1][1];
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::transform(const CVector2D& a_crVector2D, CVector2D& a_rResult) const
{ CALL
  a_rResult.m_X = a_crVector2D.m_X * m_M[0][0] + a_crVector2D.m_Y * m_M[1][0];
  a_rResult.m_Y = a_crVector2D.m_X * m_M[0][1] + a_crVector2D.m_Y * m_M[1][1];
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::add(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] + a_crInstance2.m_M[0][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][1] + a_crInstance2.m_M[0][1];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] + a_crInstance2.m_M[1][0];
  result.m_M[1][1] = a_crInstance1.m_M[1][1] + a_crInstance2.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::sub(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] - a_crInstance2.m_M[0][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][1] - a_crInstance2.m_M[0][1];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] - a_crInstance2.m_M[1][0];
  result.m_M[1][1] = a_crInstance1.m_M[1][1] - a_crInstance2.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::mul(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][1];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][0];
  result.m_M[1][1] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::adjoint(const CMatrix2D& a_crInstance)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] =  a_crInstance.m_M[1][1];
  result.m_M[0][1] = -a_crInstance.m_M[0][1];
  result.m_M[1][0] = -a_crInstance.m_M[1][0];
  result.m_M[1][1] =  a_crInstance.m_M[0][0];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::invert(const CMatrix2D& a_crInstance)
{ CALL
  CMatrix2D result;

  // Get determinant of the matrix.
  Treal det = a_crInstance.getDeterminant();

  // Check the determinant not to be 0.
  ASSERT((!NMath::CMath::isEqualZero(det)), STR("Matrix with 0 determinant cannot be inverted."))
  {
    return result;
  }

  det = CONSTR(1.0) / det;
  result.m_M[0][0] =  a_crInstance.m_M[1][1] * det;
  result.m_M[0][1] = -a_crInstance.m_M[0][1] * det;
  result.m_M[1][0] = -a_crInstance.m_M[1][0] * det;
  result.m_M[1][1] =  a_crInstance.m_M[0][0] * det;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::transpose(const CMatrix2D& a_crInstance)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_crInstance.m_M[1][0];
  result.m_M[1][0] = a_crInstance.m_M[0][1];
  result.m_M[1][1] = a_crInstance.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::transposeTimes(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][1];
  result.m_M[1][0] = a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][0];
  result.m_M[1][1] = a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::timesTranspose(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][1];
  result.m_M[0][1] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][1];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[0][1];
  result.m_M[1][1] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][1];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::tensorProduct(const CVector2D& a_crU, const CVector2D& a_crV)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_crU.m_X * a_crV.m_X;
  result.m_M[0][1] = a_crU.m_X * a_crV.m_Y;
  result.m_M[1][0] = a_crU.m_Y * a_crV.m_X;
  result.m_M[1][1] = a_crU.m_Y * a_crV.m_Y;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::scale(const Treal a_cScaleX, const Treal a_cScaleY)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = a_cScaleX;
  result.m_M[0][1] = 0.0;
  result.m_M[1][0] = 0.0;
  result.m_M[1][1] = a_cScaleY;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::shear(const Treal a_cShearXY, const Treal a_cShearYX)
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = 1.0;
  result.m_M[0][1] = a_cShearXY;
  result.m_M[1][0] = a_cShearYX;
  result.m_M[1][1] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::rotate(const Treal a_cAngle)
{ CALL
  CMatrix2D result;
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);

  result.m_M[0][0] =  cos_angle;
  result.m_M[0][1] =  sin_angle;
  result.m_M[1][0] = -sin_angle;
  result.m_M[1][1] =  cos_angle;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::mirrorX()
{ CALL
  CMatrix2D result;

  result.m_M[0][0] = -1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::mirrorY()
{ CALL
  CMatrix2D result;

  result.m_M[0][0] =  1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] = -1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::slerp(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2, const Treal a_cPart)
{ CALL
  CMatrix2D temp = transposeTimes(a_crInstance1, a_crInstance2);
  Treal angle = temp.getRotateAngle();

  return rotate(angle * a_cPart);
}
/*--------------------------------------------------------------------------*/
CMatrix2D CMatrix2D::slerpSpins(const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2, const Treal a_cPart, const Treal a_cSpins)
{ CALL
  CMatrix2D temp = transposeTimes(a_crInstance1, a_crInstance2);
  Treal angle = temp.getRotateAngle();

  return rotate((angle + a_cSpins * NMath::CMathConstants::PI) * a_cPart);
}
/*--------------------------------------------------------------------------*/
void CMatrix2D::swap(CMatrix2D& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_M[0][0], a_rInstance.m_M[0][0]);
  NAlgorithms::NCommon::swap(m_M[0][1], a_rInstance.m_M[0][1]);
  NAlgorithms::NCommon::swap(m_M[1][0], a_rInstance.m_M[1][0]);
  NAlgorithms::NCommon::swap(m_M[1][1], a_rInstance.m_M[1][1]);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
