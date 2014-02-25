/*!
 *  \file    CMatrix4D.cpp Representation of the extended transformation
 *           matrix in a space.
 *  \brief   Extended transformation matrix in a space class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Extended transformation matrix in a space class (source).

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
#include <Depth/include/geometry.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/geometry/CMatrix4D.hpp>
/*==========================================================================*/
#ifndef __CMATRIX4D_CPP__
#define __CMATRIX4D_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
GEOMETRY_API Tbool operator == (const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2)
{ CALL
  return (NMath::CMath::isEqual(a_crInstance1.m_M[0][0], a_crInstance2.m_M[0][0]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[0][1], a_crInstance2.m_M[0][1]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[0][2], a_crInstance2.m_M[0][2]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[0][3], a_crInstance2.m_M[0][3]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[1][0], a_crInstance2.m_M[1][0]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[1][1], a_crInstance2.m_M[1][1]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[1][2], a_crInstance2.m_M[1][2]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[1][3], a_crInstance2.m_M[1][3]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[2][0], a_crInstance2.m_M[2][0]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[2][1], a_crInstance2.m_M[2][1]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[2][2], a_crInstance2.m_M[2][2]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[2][3], a_crInstance2.m_M[2][3]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[3][0], a_crInstance2.m_M[3][0]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[3][1], a_crInstance2.m_M[3][1]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[3][2], a_crInstance2.m_M[3][2]) &&
          NMath::CMath::isEqual(a_crInstance1.m_M[3][3], a_crInstance2.m_M[3][3]));
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix4D operator + (const CMatrix4D& a_crInstance)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = +a_crInstance.m_M[0][0];
  result.m_M[0][1] = +a_crInstance.m_M[0][1];
  result.m_M[0][2] = +a_crInstance.m_M[0][2];
  result.m_M[0][3] = +a_crInstance.m_M[0][3];
  result.m_M[1][0] = +a_crInstance.m_M[1][0];
  result.m_M[1][1] = +a_crInstance.m_M[1][1];
  result.m_M[1][2] = +a_crInstance.m_M[1][2];
  result.m_M[1][3] = +a_crInstance.m_M[1][3];
  result.m_M[2][0] = +a_crInstance.m_M[2][0];
  result.m_M[2][1] = +a_crInstance.m_M[2][1];
  result.m_M[2][2] = +a_crInstance.m_M[2][2];
  result.m_M[2][3] = +a_crInstance.m_M[2][3];
  result.m_M[3][0] = +a_crInstance.m_M[3][0];
  result.m_M[3][1] = +a_crInstance.m_M[3][1];
  result.m_M[3][2] = +a_crInstance.m_M[3][2];
  result.m_M[3][3] = +a_crInstance.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix4D operator - (const CMatrix4D& a_crInstance)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = -a_crInstance.m_M[0][0];
  result.m_M[0][1] = -a_crInstance.m_M[0][1];
  result.m_M[0][2] = -a_crInstance.m_M[0][2];
  result.m_M[0][3] = -a_crInstance.m_M[0][3];
  result.m_M[1][0] = -a_crInstance.m_M[1][0];
  result.m_M[1][1] = -a_crInstance.m_M[1][1];
  result.m_M[1][2] = -a_crInstance.m_M[1][2];
  result.m_M[1][3] = -a_crInstance.m_M[1][3];
  result.m_M[2][0] = -a_crInstance.m_M[2][0];
  result.m_M[2][1] = -a_crInstance.m_M[2][1];
  result.m_M[2][2] = -a_crInstance.m_M[2][2];
  result.m_M[2][3] = -a_crInstance.m_M[2][3];
  result.m_M[3][0] = -a_crInstance.m_M[3][0];
  result.m_M[3][1] = -a_crInstance.m_M[3][1];
  result.m_M[3][2] = -a_crInstance.m_M[3][2];
  result.m_M[3][3] = -a_crInstance.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix4D operator + (const CMatrix4D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] + a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] + a_cValue;
  result.m_M[0][2] = a_crInstance.m_M[0][2] + a_cValue;
  result.m_M[0][3] = a_crInstance.m_M[0][3] + a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] + a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] + a_cValue;
  result.m_M[1][2] = a_crInstance.m_M[1][2] + a_cValue;
  result.m_M[1][3] = a_crInstance.m_M[1][3] + a_cValue;
  result.m_M[2][0] = a_crInstance.m_M[2][0] + a_cValue;
  result.m_M[2][1] = a_crInstance.m_M[2][1] + a_cValue;
  result.m_M[2][2] = a_crInstance.m_M[2][2] + a_cValue;
  result.m_M[2][3] = a_crInstance.m_M[2][3] + a_cValue;
  result.m_M[3][0] = a_crInstance.m_M[3][0] + a_cValue;
  result.m_M[3][1] = a_crInstance.m_M[3][1] + a_cValue;
  result.m_M[3][2] = a_crInstance.m_M[3][2] + a_cValue;
  result.m_M[3][3] = a_crInstance.m_M[3][3] + a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix4D operator + (const Treal a_cValue, const CMatrix4D& a_crInstance)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_cValue + a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue + a_crInstance.m_M[0][1];
  result.m_M[0][2] = a_cValue + a_crInstance.m_M[0][2];
  result.m_M[0][3] = a_cValue + a_crInstance.m_M[0][3];
  result.m_M[1][0] = a_cValue + a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue + a_crInstance.m_M[1][1];
  result.m_M[1][2] = a_cValue + a_crInstance.m_M[1][2];
  result.m_M[1][3] = a_cValue + a_crInstance.m_M[1][3];
  result.m_M[2][0] = a_cValue + a_crInstance.m_M[2][0];
  result.m_M[2][1] = a_cValue + a_crInstance.m_M[2][1];
  result.m_M[2][2] = a_cValue + a_crInstance.m_M[2][2];
  result.m_M[2][3] = a_cValue + a_crInstance.m_M[2][3];
  result.m_M[3][0] = a_cValue + a_crInstance.m_M[3][0];
  result.m_M[3][1] = a_cValue + a_crInstance.m_M[3][1];
  result.m_M[3][2] = a_cValue + a_crInstance.m_M[3][2];
  result.m_M[3][3] = a_cValue + a_crInstance.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix4D operator - (const CMatrix4D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] - a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] - a_cValue;
  result.m_M[0][2] = a_crInstance.m_M[0][2] - a_cValue;
  result.m_M[0][3] = a_crInstance.m_M[0][3] - a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] - a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] - a_cValue;
  result.m_M[1][2] = a_crInstance.m_M[1][2] - a_cValue;
  result.m_M[1][3] = a_crInstance.m_M[1][3] - a_cValue;
  result.m_M[2][0] = a_crInstance.m_M[2][0] - a_cValue;
  result.m_M[2][1] = a_crInstance.m_M[2][1] - a_cValue;
  result.m_M[2][2] = a_crInstance.m_M[2][2] - a_cValue;
  result.m_M[2][3] = a_crInstance.m_M[2][3] - a_cValue;
  result.m_M[3][0] = a_crInstance.m_M[3][0] - a_cValue;
  result.m_M[3][1] = a_crInstance.m_M[3][1] - a_cValue;
  result.m_M[3][2] = a_crInstance.m_M[3][2] - a_cValue;
  result.m_M[3][3] = a_crInstance.m_M[3][3] - a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix4D operator - (const Treal a_cValue, const CMatrix4D& a_crInstance)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_cValue - a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue - a_crInstance.m_M[0][1];
  result.m_M[0][2] = a_cValue - a_crInstance.m_M[0][2];
  result.m_M[0][3] = a_cValue - a_crInstance.m_M[0][3];
  result.m_M[1][0] = a_cValue - a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue - a_crInstance.m_M[1][1];
  result.m_M[1][2] = a_cValue - a_crInstance.m_M[1][2];
  result.m_M[1][3] = a_cValue - a_crInstance.m_M[1][3];
  result.m_M[2][0] = a_cValue - a_crInstance.m_M[2][0];
  result.m_M[2][1] = a_cValue - a_crInstance.m_M[2][1];
  result.m_M[2][2] = a_cValue - a_crInstance.m_M[2][2];
  result.m_M[2][3] = a_cValue - a_crInstance.m_M[2][3];
  result.m_M[3][0] = a_cValue - a_crInstance.m_M[3][0];
  result.m_M[3][1] = a_cValue - a_crInstance.m_M[3][1];
  result.m_M[3][2] = a_cValue - a_crInstance.m_M[3][2];
  result.m_M[3][3] = a_cValue - a_crInstance.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix4D operator * (const CMatrix4D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] * a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] * a_cValue;
  result.m_M[0][2] = a_crInstance.m_M[0][2] * a_cValue;
  result.m_M[0][3] = a_crInstance.m_M[0][3] * a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] * a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] * a_cValue;
  result.m_M[1][2] = a_crInstance.m_M[1][2] * a_cValue;
  result.m_M[1][3] = a_crInstance.m_M[1][3] * a_cValue;
  result.m_M[2][0] = a_crInstance.m_M[2][0] * a_cValue;
  result.m_M[2][1] = a_crInstance.m_M[2][1] * a_cValue;
  result.m_M[2][2] = a_crInstance.m_M[2][2] * a_cValue;
  result.m_M[2][3] = a_crInstance.m_M[2][3] * a_cValue;
  result.m_M[3][0] = a_crInstance.m_M[3][0] * a_cValue;
  result.m_M[3][1] = a_crInstance.m_M[3][1] * a_cValue;
  result.m_M[3][2] = a_crInstance.m_M[3][2] * a_cValue;
  result.m_M[3][3] = a_crInstance.m_M[3][3] * a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix4D operator * (const Treal a_cValue, const CMatrix4D& a_crInstance)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_cValue * a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue * a_crInstance.m_M[0][1];
  result.m_M[0][2] = a_cValue * a_crInstance.m_M[0][2];
  result.m_M[0][3] = a_cValue * a_crInstance.m_M[0][3];
  result.m_M[1][0] = a_cValue * a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue * a_crInstance.m_M[1][1];
  result.m_M[1][2] = a_cValue * a_crInstance.m_M[1][2];
  result.m_M[1][3] = a_cValue * a_crInstance.m_M[1][3];
  result.m_M[2][0] = a_cValue * a_crInstance.m_M[2][0];
  result.m_M[2][1] = a_cValue * a_crInstance.m_M[2][1];
  result.m_M[2][2] = a_cValue * a_crInstance.m_M[2][2];
  result.m_M[2][3] = a_cValue * a_crInstance.m_M[2][3];
  result.m_M[3][0] = a_cValue * a_crInstance.m_M[3][0];
  result.m_M[3][1] = a_cValue * a_crInstance.m_M[3][1];
  result.m_M[3][2] = a_cValue * a_crInstance.m_M[3][2];
  result.m_M[3][3] = a_cValue * a_crInstance.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix4D operator / (const CMatrix4D& a_crInstance, const Treal a_cValue)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0] / a_cValue;
  result.m_M[0][1] = a_crInstance.m_M[0][1] / a_cValue;
  result.m_M[0][2] = a_crInstance.m_M[0][2] / a_cValue;
  result.m_M[0][3] = a_crInstance.m_M[0][3] / a_cValue;
  result.m_M[1][0] = a_crInstance.m_M[1][0] / a_cValue;
  result.m_M[1][1] = a_crInstance.m_M[1][1] / a_cValue;
  result.m_M[1][2] = a_crInstance.m_M[1][2] / a_cValue;
  result.m_M[1][3] = a_crInstance.m_M[1][3] / a_cValue;
  result.m_M[2][0] = a_crInstance.m_M[2][0] / a_cValue;
  result.m_M[2][1] = a_crInstance.m_M[2][1] / a_cValue;
  result.m_M[2][2] = a_crInstance.m_M[2][2] / a_cValue;
  result.m_M[2][3] = a_crInstance.m_M[2][3] / a_cValue;
  result.m_M[3][0] = a_crInstance.m_M[3][0] / a_cValue;
  result.m_M[3][1] = a_crInstance.m_M[3][1] / a_cValue;
  result.m_M[3][2] = a_crInstance.m_M[3][2] / a_cValue;
  result.m_M[3][3] = a_crInstance.m_M[3][3] / a_cValue;
  return result;
}
/*--------------------------------------------------------------------------*/
GEOMETRY_API CMatrix4D operator / (const Treal a_cValue, const CMatrix4D& a_crInstance)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_cValue / a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_cValue / a_crInstance.m_M[0][1];
  result.m_M[0][2] = a_cValue / a_crInstance.m_M[0][2];
  result.m_M[0][3] = a_cValue / a_crInstance.m_M[0][3];
  result.m_M[1][0] = a_cValue / a_crInstance.m_M[1][0];
  result.m_M[1][1] = a_cValue / a_crInstance.m_M[1][1];
  result.m_M[1][2] = a_cValue / a_crInstance.m_M[1][2];
  result.m_M[1][3] = a_cValue / a_crInstance.m_M[1][3];
  result.m_M[2][0] = a_cValue / a_crInstance.m_M[2][0];
  result.m_M[2][1] = a_cValue / a_crInstance.m_M[2][1];
  result.m_M[2][2] = a_cValue / a_crInstance.m_M[2][2];
  result.m_M[2][3] = a_cValue / a_crInstance.m_M[2][3];
  result.m_M[3][0] = a_cValue / a_crInstance.m_M[3][0];
  result.m_M[3][1] = a_cValue / a_crInstance.m_M[3][1];
  result.m_M[3][2] = a_cValue / a_crInstance.m_M[3][2];
  result.m_M[3][3] = a_cValue / a_crInstance.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D& CMatrix4D::operator += (const Treal a_cValue)
{ CALL
  m_M[0][0] += a_cValue;
  m_M[0][1] += a_cValue;
  m_M[0][2] += a_cValue;
  m_M[0][3] += a_cValue;
  m_M[1][0] += a_cValue;
  m_M[1][1] += a_cValue;
  m_M[1][2] += a_cValue;
  m_M[1][3] += a_cValue;
  m_M[2][0] += a_cValue;
  m_M[2][1] += a_cValue;
  m_M[2][2] += a_cValue;
  m_M[2][3] += a_cValue;
  m_M[3][0] += a_cValue;
  m_M[3][1] += a_cValue;
  m_M[3][2] += a_cValue;
  m_M[3][3] += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
CMatrix4D& CMatrix4D::operator -= (const Treal a_cValue)
{ CALL
  m_M[0][0] -= a_cValue;
  m_M[0][1] -= a_cValue;
  m_M[0][2] -= a_cValue;
  m_M[0][3] -= a_cValue;
  m_M[1][0] -= a_cValue;
  m_M[1][1] -= a_cValue;
  m_M[1][2] -= a_cValue;
  m_M[1][3] -= a_cValue;
  m_M[2][0] -= a_cValue;
  m_M[2][1] -= a_cValue;
  m_M[2][2] -= a_cValue;
  m_M[2][3] -= a_cValue;
  m_M[3][0] -= a_cValue;
  m_M[3][1] -= a_cValue;
  m_M[3][2] -= a_cValue;
  m_M[3][3] -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
CMatrix4D& CMatrix4D::operator *= (const Treal a_cValue)
{ CALL
  m_M[0][0] *= a_cValue;
  m_M[0][1] *= a_cValue;
  m_M[0][2] *= a_cValue;
  m_M[0][3] *= a_cValue;
  m_M[1][0] *= a_cValue;
  m_M[1][1] *= a_cValue;
  m_M[1][2] *= a_cValue;
  m_M[1][3] *= a_cValue;
  m_M[2][0] *= a_cValue;
  m_M[2][1] *= a_cValue;
  m_M[2][2] *= a_cValue;
  m_M[2][3] *= a_cValue;
  m_M[3][0] *= a_cValue;
  m_M[3][1] *= a_cValue;
  m_M[3][2] *= a_cValue;
  m_M[3][3] *= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
CMatrix4D& CMatrix4D::operator /= (const Treal a_cValue)
{ CALL
  m_M[0][0] /= a_cValue;
  m_M[0][1] /= a_cValue;
  m_M[0][2] /= a_cValue;
  m_M[0][3] /= a_cValue;
  m_M[1][0] /= a_cValue;
  m_M[1][1] /= a_cValue;
  m_M[1][2] /= a_cValue;
  m_M[1][3] /= a_cValue;
  m_M[2][0] /= a_cValue;
  m_M[2][1] /= a_cValue;
  m_M[2][2] /= a_cValue;
  m_M[2][3] /= a_cValue;
  m_M[3][0] /= a_cValue;
  m_M[3][1] /= a_cValue;
  m_M[3][2] /= a_cValue;
  m_M[3][3] /= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::set(const Treal a_cpMatrixBuffer[])
{ CALL
  // Check if the pointer to the matrix values buffer is not NULL.
  ASSERT((a_cpMatrixBuffer != NULL), STR("Pointer to the matrix values buffer should not be NULL."))
  {
    clear();
  }

  m_M[0][0] = a_cpMatrixBuffer[0];
  m_M[0][1] = a_cpMatrixBuffer[1];
  m_M[0][2] = a_cpMatrixBuffer[2];
  m_M[0][3] = a_cpMatrixBuffer[3];
  m_M[1][0] = a_cpMatrixBuffer[4];
  m_M[1][1] = a_cpMatrixBuffer[5];
  m_M[1][2] = a_cpMatrixBuffer[6];
  m_M[1][3] = a_cpMatrixBuffer[7];
  m_M[2][0] = a_cpMatrixBuffer[8];
  m_M[2][1] = a_cpMatrixBuffer[9];
  m_M[2][2] = a_cpMatrixBuffer[10];
  m_M[2][3] = a_cpMatrixBuffer[11];
  m_M[3][0] = a_cpMatrixBuffer[12];
  m_M[3][1] = a_cpMatrixBuffer[13];
  m_M[3][2] = a_cpMatrixBuffer[14];
  m_M[3][3] = a_cpMatrixBuffer[15];
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::set(const CMatrix2D& a_crInstance)
{ CALL
  m_M[0][0] = a_crInstance.m_M[0][0];
  m_M[0][1] = a_crInstance.m_M[0][1];
  m_M[0][2] = 0.0;
  m_M[0][3] = 0.0;
  m_M[1][0] = a_crInstance.m_M[1][0];
  m_M[1][1] = a_crInstance.m_M[1][1];
  m_M[1][2] = 0.0;
  m_M[1][3] = 0.0;
  m_M[2][0] = 0.0;
  m_M[2][1] = 0.0;
  m_M[2][2] = 1.0;
  m_M[2][3] = 0.0;
  m_M[3][0] = 0.0;
  m_M[3][1] = 0.0;
  m_M[3][2] = 0.0;
  m_M[3][3] = 1.0;
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::set(const CMatrix3D& a_crInstance)
{ CALL
  m_M[0][0] = a_crInstance.m_M[0][0];
  m_M[0][1] = a_crInstance.m_M[0][1];
  m_M[0][2] = a_crInstance.m_M[0][2];
  m_M[0][3] = 0.0;
  m_M[1][0] = a_crInstance.m_M[1][0];
  m_M[1][1] = a_crInstance.m_M[1][1];
  m_M[1][2] = a_crInstance.m_M[1][2];
  m_M[1][3] = 0.0;
  m_M[2][0] = a_crInstance.m_M[2][0];
  m_M[2][1] = a_crInstance.m_M[2][1];
  m_M[2][2] = a_crInstance.m_M[2][2];
  m_M[2][3] = 0.0;
  m_M[3][0] = 0.0;
  m_M[3][1] = 0.0;
  m_M[3][2] = 0.0;
  m_M[3][3] = 1.0;
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::set(const CMatrix4D& a_crInstance)
{ CALL
  m_M[0][0] = a_crInstance.m_M[0][0];
  m_M[0][1] = a_crInstance.m_M[0][1];
  m_M[0][2] = a_crInstance.m_M[0][2];
  m_M[0][3] = a_crInstance.m_M[0][3];
  m_M[1][0] = a_crInstance.m_M[1][0];
  m_M[1][1] = a_crInstance.m_M[1][1];
  m_M[1][2] = a_crInstance.m_M[1][2];
  m_M[1][3] = a_crInstance.m_M[1][3];
  m_M[2][0] = a_crInstance.m_M[2][0];
  m_M[2][1] = a_crInstance.m_M[2][1];
  m_M[2][2] = a_crInstance.m_M[2][2];
  m_M[2][3] = a_crInstance.m_M[2][3];
  m_M[3][0] = a_crInstance.m_M[3][0];
  m_M[3][1] = a_crInstance.m_M[3][1];
  m_M[3][2] = a_crInstance.m_M[3][2];
  m_M[3][3] = a_crInstance.m_M[3][3];
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::clear(const Tbool a_cIdentityFlag/* = false */)
{ CALL
  m_M[0][0] = (a_cIdentityFlag ? CONSTR(1.0) : CONSTR(0.0));
  m_M[0][1] = 0.0;
  m_M[0][2] = 0.0;
  m_M[0][3] = 0.0;
  m_M[1][0] = 0.0;
  m_M[1][1] = (a_cIdentityFlag ? CONSTR(1.0) : CONSTR(0.0));
  m_M[1][2] = 0.0;
  m_M[1][3] = 0.0;
  m_M[2][0] = 0.0;
  m_M[2][1] = 0.0;
  m_M[2][2] = (a_cIdentityFlag ? CONSTR(1.0) : CONSTR(0.0));
  m_M[2][3] = 0.0;
  m_M[3][0] = 0.0;
  m_M[3][1] = 0.0;
  m_M[3][2] = 0.0;
  m_M[3][3] = (a_cIdentityFlag ? CONSTR(1.0) : CONSTR(0.0));
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::absolute()
{ CALL
  m_M[0][0] = NMath::CMath::fabs(m_M[0][0]);
  m_M[0][1] = NMath::CMath::fabs(m_M[0][1]);
  m_M[0][2] = NMath::CMath::fabs(m_M[0][2]);
  m_M[0][3] = NMath::CMath::fabs(m_M[0][3]);
  m_M[1][0] = NMath::CMath::fabs(m_M[1][0]);
  m_M[1][1] = NMath::CMath::fabs(m_M[1][1]);
  m_M[1][2] = NMath::CMath::fabs(m_M[1][2]);
  m_M[1][3] = NMath::CMath::fabs(m_M[1][3]);
  m_M[2][0] = NMath::CMath::fabs(m_M[2][0]);
  m_M[2][1] = NMath::CMath::fabs(m_M[2][1]);
  m_M[2][2] = NMath::CMath::fabs(m_M[2][2]);
  m_M[2][3] = NMath::CMath::fabs(m_M[2][3]);
  m_M[3][0] = NMath::CMath::fabs(m_M[3][0]);
  m_M[3][1] = NMath::CMath::fabs(m_M[3][1]);
  m_M[3][2] = NMath::CMath::fabs(m_M[3][2]);
  m_M[3][3] = NMath::CMath::fabs(m_M[3][3]);
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::negate()
{ CALL
  m_M[0][0] = -m_M[0][0];
  m_M[0][1] = -m_M[0][1];
  m_M[0][2] = -m_M[0][2];
  m_M[0][3] = -m_M[0][3];
  m_M[1][0] = -m_M[1][0];
  m_M[1][1] = -m_M[1][1];
  m_M[1][2] = -m_M[1][2];
  m_M[1][3] = -m_M[1][3];
  m_M[2][0] = -m_M[2][0];
  m_M[2][1] = -m_M[2][1];
  m_M[2][2] = -m_M[2][2];
  m_M[2][3] = -m_M[2][3];
  m_M[3][0] = -m_M[3][0];
  m_M[3][1] = -m_M[3][1];
  m_M[3][2] = -m_M[3][2];
  m_M[3][3] = -m_M[3][3];
}
/*--------------------------------------------------------------------------*/
Treal CMatrix4D::getDeterminant() const
{ CALL
  #define DET22(M00, M01, M10, M11) (M00 * M11 - M01 * M10)
  #define DET33(M00, M01, M02, M10, M11, M12, M20, M21, M22) (M00 * DET22(M11, M12, M21, M22) - M01 * DET22(M10, M12, M20, M22) + M02 * DET22(M10, M11, M20, M21))
  #define DET44(M00, M01, M02, M03, M10, M11, M12, M13, M20, M21, M22, M23, M30, M31, M32, M33) (M00 * DET33(M11, M12, M13, M21, M22, M23, M31, M32, M33) - M01 * DET33(M10, M12, M13, M20, M22, M23, M30, M32, M33) + M02 * DET33(M10, M11, M13, M20, M21, M23, M30, M31, M33) - M03 * DET33(M10, M11, M12, M20, M21, M22, M30, M31, M32))
  return DET44(m_M[0][0], m_M[1][0], m_M[2][0], m_M[3][0], m_M[0][1], m_M[1][1], m_M[2][1], m_M[3][1], m_M[0][2], m_M[1][2], m_M[2][2], m_M[3][2], m_M[0][3], m_M[1][3], m_M[2][3], m_M[3][3]);
  #undef DET44
  #undef DET33
  #undef DET22
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::getRotateAxisAngle(CVector3D& a_rAxis, Treal& a_rAngle) const
{ CALL
  // Let (x,y,z) be the unit-length axis and let A be an angle of rotation.
  // The rotation matrix is R = I + sin(A)*P + (1-cos(A))*P^2 where
  // I is the identity and
  //
  //       +-        -+
  //   P = |  0 -z +y |
  //       | +z  0 -x |
  //       | -y +x  0 |
  //       +-        -+
  //
  // If A > 0, R represents a counterclockwise rotation about the axis in
  // the sense of looking from the tip of the axis vector towards the
  // origin.  Some algebra will show that
  //
  //   cos(A) = (trace(R)-1)/2  and  R - R^t = 2*sin(A)*P
  //
  // In the event that A = pi, R-R^t = 0 which prevents us from extracting
  // the axis through P.  Instead note that R = I+2*P^2 when A = pi, so
  // P^2 = (R-I)/2.  The diagonal entries of P^2 are x^2-1, y^2-1, and
  // z^2-1.  We can solve these for axis (x,y,z).  Because the angle is pi,
  // it does not matter which sign you choose on the square roots.

  Treal trace = m_M[0][0] + m_M[1][1] + m_M[2][2];
  Treal cos_angle = CONSTR(0.5) * (trace - CONSTR(1.0));
  a_rAngle = NMath::CMath::acos(cos_angle);

  if (a_rAngle > 0.0)
  {
    if (a_rAngle < NMath::CMathConstants::PI)
    {
      a_rAxis.m_X = m_M[1][2] - m_M[2][1];
      a_rAxis.m_Y = m_M[2][0] - m_M[0][2];
      a_rAxis.m_Z = m_M[0][1] - m_M[1][0];
      a_rAxis.normalize();
    }
    else
    {
      // Angle is PI.
      Treal half_inverse;
      if (m_M[0][0] >= m_M[1][1])
      {
        // r00>=r11.
        if (m_M[0][0] >= m_M[2][2])
        {
          // r00 is maximum diagonal term.
          a_rAxis.m_X = CONSTR(0.5) * NMath::CMath::sqrt(m_M[0][0] - m_M[1][1] - m_M[2][2] + CONSTR(1.0));
          half_inverse = CONSTR(0.5) / a_rAxis.m_X;
          a_rAxis.m_Y = half_inverse * m_M[1][0];
          a_rAxis.m_Z = half_inverse * m_M[2][0];
        }
        else
        {
          // r22 is maximum diagonal term.
          a_rAxis.m_Z = CONSTR(0.5) * NMath::CMath::sqrt(m_M[2][2] - m_M[0][0] - m_M[1][1] + CONSTR(1.0));
          half_inverse = CONSTR(0.5) / a_rAxis.m_Z;
          a_rAxis.m_X = half_inverse * m_M[2][0];
          a_rAxis.m_Y = half_inverse * m_M[2][1];
        }
      }
      else
      {
        // r11 > r00.
        if (m_M[1][1] >= m_M[2][2])
        {
          // r11 is maximum diagonal term.
          a_rAxis.m_Y = CONSTR(0.5) * NMath::CMath::sqrt(m_M[1][1] - m_M[0][0] - m_M[2][2] + CONSTR(1.0));
          half_inverse = CONSTR(0.5) / a_rAxis.m_Y;
          a_rAxis.m_X = half_inverse * m_M[1][0];
          a_rAxis.m_Z = half_inverse * m_M[2][1];
        }
        else
        {
          // r22 is maximum diagonal term.
          a_rAxis.m_Z =CONSTR(0.5) * NMath::CMath::sqrt(m_M[2][2] - m_M[0][0] - m_M[1][1] + CONSTR(1.0));
          half_inverse = CONSTR(0.5) / a_rAxis.m_Z;
          a_rAxis.m_X = half_inverse * m_M[2][0];
          a_rAxis.m_Y = half_inverse * m_M[2][1];
        }
      }
    }
  }
  else
  {
    // The angle is 0 and the matrix is the identity.
    // Any axis will work, so just use the X-axis.
    a_rAxis.m_X = 1.0;
    a_rAxis.m_Y = 0.0;
    a_rAxis.m_Z = 0.0;
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::getRotateAnglesXYZ(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[2][0] < 1.0)
  {
    if (m_M[2][0] > -1.0)
    {
      a_rAngleX = NMath::CMath::atan2(-m_M[2][1], m_M[2][2]);
      a_rAngleY = NMath::CMath::asin(m_M[2][0]);
      a_rAngleZ = NMath::CMath::atan2(-m_M[1][0], m_M[0][0]);
    }
    else
    {
      // WARNING: Not unique. XA - ZA = -atan2(r01, r11)
      a_rAngleX = -NMath::CMath::atan2(m_M[0][1], m_M[1][1]);
      a_rAngleY = -NMath::CMathConstants::PI_2;
      a_rAngleZ =  0.0;
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. XA + ZA = atan2(r01, r11)
    a_rAngleX = NMath::CMath::atan2(m_M[0][1], m_M[1][1]);
    a_rAngleY = NMath::CMathConstants::PI_2;
    a_rAngleZ = 0.0;
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::getRotateAnglesXZY(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[1][0] < 1.0)
  {
    if (m_M[1][0] > -1.0)
    {
      a_rAngleX = NMath::CMath::atan2(m_M[1][2], m_M[1][1]);
      a_rAngleY = NMath::CMath::atan2(m_M[2][0], m_M[0][0]);
      a_rAngleZ = NMath::CMath::asin(-m_M[1][0]);
    }
    else
    {
      // WARNING: Not unique. XA - YA = atan2(r02, r22)
      a_rAngleX = NMath::CMath::atan2(m_M[0][2], m_M[2][2]);
      a_rAngleY = 0.0;
      a_rAngleZ = NMath::CMathConstants::PI_2;
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. XA + YA = atan2(-r02, r22)
    a_rAngleX =  NMath::CMath::atan2(-m_M[0][2], m_M[2][2]);
    a_rAngleY =  0.0;
    a_rAngleZ = -NMath::CMathConstants::PI_2;
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::getRotateAnglesYXZ(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[2][1] < 1.0)
  {
    if (m_M[2][1] > -1.0)
    {
      a_rAngleX = NMath::CMath::asin(-m_M[2][1]);
      a_rAngleY = NMath::CMath::atan2(m_M[2][0], m_M[2][2]);
      a_rAngleZ = NMath::CMath::atan2(m_M[0][1], m_M[1][1]);
    }
    else
    {
      // WARNING: Not unique. YA - ZA = atan2(r10, r00)
      a_rAngleX = NMath::CMathConstants::PI_2;
      a_rAngleY = NMath::CMath::atan2(m_M[1][0], m_M[0][0]);
      a_rAngleZ = 0.0;
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. YA + ZA = atan2(-r10, r00)
    a_rAngleX = -NMath::CMathConstants::PI_2;
    a_rAngleY =  NMath::CMath::atan2(-m_M[1][0], m_M[0][0]);
    a_rAngleZ =  0.0;
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::getRotateAnglesYZX(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[0][1] < 1.0)
  {
    if (m_M[0][1] > -1.0)
    {
      a_rAngleX = NMath::CMath::atan2(-m_M[2][1], m_M[1][1]);
      a_rAngleY = NMath::CMath::atan2(-m_M[0][2], m_M[0][0]);
      a_rAngleZ = NMath::CMath::asin(m_M[0][1]);
    }
    else
    {
      // WARNING: Not unique. YA - XA = -atan2(r12, r22);
      a_rAngleX = 0.0;
      a_rAngleY = -NMath::CMath::atan2(m_M[1][2], m_M[2][2]);
      a_rAngleZ = -NMath::CMathConstants::PI_2;
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. YA + XA = atan2(r12, r22)
    a_rAngleX = 0.0;
    a_rAngleY = NMath::CMath::atan2(m_M[1][2], m_M[2][2]);
    a_rAngleZ = NMath::CMathConstants::PI_2;
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::getRotateAnglesZXY(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[1][2] < 1.0)
  {
    if (m_M[1][2] > -1.0)
    {
      a_rAngleX = NMath::CMath::asin(m_M[1][2]);
      a_rAngleY = NMath::CMath::atan2(-m_M[0][2], m_M[2][2]);
      a_rAngleZ = NMath::CMath::atan2(-m_M[1][0], m_M[1][1]);
    }
    else
    {
      // WARNING: Not unique. ZA - YA = -atan(r20, r00)
      a_rAngleX = -NMath::CMathConstants::PI_2;
      a_rAngleY =  0.0;
      a_rAngleZ = -NMath::CMath::atan2(m_M[2][0], m_M[0][0]);
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. ZA + YA = atan2(r20, r00)
    a_rAngleX = NMath::CMathConstants::PI_2;
    a_rAngleY = 0.0;
    a_rAngleZ = NMath::CMath::atan2(m_M[2][0], m_M[0][0]);
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::getRotateAnglesZYX(Treal& a_rAngleX, Treal& a_rAngleY, Treal& a_rAngleZ) const
{ CALL
  if (m_M[0][2] < 1.0)
  {
    if (m_M[0][2] > -1.0)
    {
      a_rAngleX = NMath::CMath::atan2(m_M[1][2], m_M[2][2]);
      a_rAngleY = NMath::CMath::asin(-m_M[0][2]);
      a_rAngleZ = NMath::CMath::atan2(m_M[0][1], m_M[0][0]);
    }
    else
    {
      // WARNING: Not unique. ZA - XA = -atan2(r10, r20)
      a_rAngleX =  0.0;
      a_rAngleY =  NMath::CMathConstants::PI_2;
      a_rAngleZ = -NMath::CMath::atan2(m_M[1][0], m_M[2][0]);
      WARNING(STR("Rotate angles not unique."));
    }
  }
  else
  {
    // WARNING: Not unique. ZA + XA = atan2(-r10, -r20)
    a_rAngleX =  0.0;
    a_rAngleY = -NMath::CMathConstants::PI_2;
    a_rAngleZ =  NMath::CMath::atan2(-m_M[1][0], -m_M[2][0]);
    WARNING(STR("Rotate angles not unique."));
  }
}
/*--------------------------------------------------------------------------*/
CPoint3D<Treal> CMatrix4D::rotate(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  CPoint3D<Treal> result;

  result.m_X = a_crPoint3D.m_X * m_M[0][0] + a_crPoint3D.m_Y * m_M[1][0] + a_crPoint3D.m_Z * m_M[2][0];
  result.m_Y = a_crPoint3D.m_X * m_M[0][1] + a_crPoint3D.m_Y * m_M[1][1] + a_crPoint3D.m_Z * m_M[2][1];
  result.m_Z = a_crPoint3D.m_X * m_M[0][2] + a_crPoint3D.m_Y * m_M[1][2] + a_crPoint3D.m_Z * m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CVector3D CMatrix4D::rotate(const CVector3D& a_crVector3D) const
{ CALL
  CVector3D result;

  result.m_X = a_crVector3D.m_X * m_M[0][0] + a_crVector3D.m_Y * m_M[1][0] + a_crVector3D.m_Z * m_M[2][0];
  result.m_Y = a_crVector3D.m_X * m_M[0][1] + a_crVector3D.m_Y * m_M[1][1] + a_crVector3D.m_Z * m_M[2][1];
  result.m_Z = a_crVector3D.m_X * m_M[0][2] + a_crVector3D.m_Y * m_M[1][2] + a_crVector3D.m_Z * m_M[2][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CVector4D CMatrix4D::rotate(const CVector4D& a_crVector4D) const
{ CALL
  CVector4D result;

  result.m_X = a_crVector4D.m_X * m_M[0][0] + a_crVector4D.m_Y * m_M[1][0] + a_crVector4D.m_Z * m_M[2][0];
  result.m_Y = a_crVector4D.m_X * m_M[0][1] + a_crVector4D.m_Y * m_M[1][1] + a_crVector4D.m_Z * m_M[2][1];
  result.m_Z = a_crVector4D.m_X * m_M[0][2] + a_crVector4D.m_Y * m_M[1][2] + a_crVector4D.m_Z * m_M[2][2];
  result.m_W = a_crVector4D.m_W;
  return result;
}
/*--------------------------------------------------------------------------*/
CPoint3D<Treal> CMatrix4D::transform(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  CPoint3D<Treal> result;

  result.m_X = a_crPoint3D.m_X * m_M[0][0] + a_crPoint3D.m_Y * m_M[1][0] + a_crPoint3D.m_Z * m_M[2][0] + m_M[3][0];
  result.m_Y = a_crPoint3D.m_X * m_M[0][1] + a_crPoint3D.m_Y * m_M[1][1] + a_crPoint3D.m_Z * m_M[2][1] + m_M[3][1];
  result.m_Z = a_crPoint3D.m_X * m_M[0][2] + a_crPoint3D.m_Y * m_M[1][2] + a_crPoint3D.m_Z * m_M[2][2] + m_M[3][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CVector3D CMatrix4D::transform(const CVector3D& a_crVector3D) const
{ CALL
  CVector3D result;

  result.m_X = a_crVector3D.m_X * m_M[0][0] + a_crVector3D.m_Y * m_M[1][0] + a_crVector3D.m_Z * m_M[2][0] + m_M[3][0];
  result.m_Y = a_crVector3D.m_X * m_M[0][1] + a_crVector3D.m_Y * m_M[1][1] + a_crVector3D.m_Z * m_M[2][1] + m_M[3][1];
  result.m_Z = a_crVector3D.m_X * m_M[0][2] + a_crVector3D.m_Y * m_M[1][2] + a_crVector3D.m_Z * m_M[2][2] + m_M[3][2];
  return result;
}
/*--------------------------------------------------------------------------*/
CVector4D CMatrix4D::transform(const CVector4D& a_crVector4D) const
{ CALL
  CVector4D result;

  result.m_X = a_crVector4D.m_X * m_M[0][0] + a_crVector4D.m_Y * m_M[1][0] + a_crVector4D.m_Z * m_M[2][0] + a_crVector4D.m_W * m_M[3][0];
  result.m_Y = a_crVector4D.m_X * m_M[0][1] + a_crVector4D.m_Y * m_M[1][1] + a_crVector4D.m_Z * m_M[2][1] + a_crVector4D.m_W * m_M[3][1];
  result.m_Z = a_crVector4D.m_X * m_M[0][2] + a_crVector4D.m_Y * m_M[1][2] + a_crVector4D.m_Z * m_M[2][2] + a_crVector4D.m_W * m_M[3][2];
  result.m_W = a_crVector4D.m_X * m_M[0][3] + a_crVector4D.m_Y * m_M[1][3] + a_crVector4D.m_Z * m_M[2][3] + a_crVector4D.m_W * m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::rotate(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  a_rResult.m_X = a_crPoint3D.m_X * m_M[0][0] + a_crPoint3D.m_Y * m_M[1][0] + a_crPoint3D.m_Z * m_M[2][0];
  a_rResult.m_Y = a_crPoint3D.m_X * m_M[0][1] + a_crPoint3D.m_Y * m_M[1][1] + a_crPoint3D.m_Z * m_M[2][1];
  a_rResult.m_Z = a_crPoint3D.m_X * m_M[0][2] + a_crPoint3D.m_Y * m_M[1][2] + a_crPoint3D.m_Z * m_M[2][2];
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::rotate(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  a_rResult.m_X = a_crVector3D.m_X * m_M[0][0] + a_crVector3D.m_Y * m_M[1][0] + a_crVector3D.m_Z * m_M[2][0];
  a_rResult.m_Y = a_crVector3D.m_X * m_M[0][1] + a_crVector3D.m_Y * m_M[1][1] + a_crVector3D.m_Z * m_M[2][1];
  a_rResult.m_Z = a_crVector3D.m_X * m_M[0][2] + a_crVector3D.m_Y * m_M[1][2] + a_crVector3D.m_Z * m_M[2][2];
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::rotate(const CVector4D& a_crVector4D, CVector4D& a_rResult) const
{ CALL
  a_rResult.m_X = a_crVector4D.m_X * m_M[0][0] + a_crVector4D.m_Y * m_M[1][0] + a_crVector4D.m_Z * m_M[2][0];
  a_rResult.m_Y = a_crVector4D.m_X * m_M[0][1] + a_crVector4D.m_Y * m_M[1][1] + a_crVector4D.m_Z * m_M[2][1];
  a_rResult.m_Z = a_crVector4D.m_X * m_M[0][2] + a_crVector4D.m_Y * m_M[1][2] + a_crVector4D.m_Z * m_M[2][2];
  a_rResult.m_W = a_crVector4D.m_W;
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::transform(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  a_rResult.m_X = a_crPoint3D.m_X * m_M[0][0] + a_crPoint3D.m_Y * m_M[1][0] + a_crPoint3D.m_Z * m_M[2][0] + m_M[3][0];
  a_rResult.m_Y = a_crPoint3D.m_X * m_M[0][1] + a_crPoint3D.m_Y * m_M[1][1] + a_crPoint3D.m_Z * m_M[2][1] + m_M[3][1];
  a_rResult.m_Z = a_crPoint3D.m_X * m_M[0][2] + a_crPoint3D.m_Y * m_M[1][2] + a_crPoint3D.m_Z * m_M[2][2] + m_M[3][2];
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::transform(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  a_rResult.m_X = a_crVector3D.m_X * m_M[0][0] + a_crVector3D.m_Y * m_M[1][0] + a_crVector3D.m_Z * m_M[2][0] + m_M[3][0];
  a_rResult.m_Y = a_crVector3D.m_X * m_M[0][1] + a_crVector3D.m_Y * m_M[1][1] + a_crVector3D.m_Z * m_M[2][1] + m_M[3][1];
  a_rResult.m_Z = a_crVector3D.m_X * m_M[0][2] + a_crVector3D.m_Y * m_M[1][2] + a_crVector3D.m_Z * m_M[2][2] + m_M[3][2];
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::transform(const CVector4D& a_crVector4D, CVector4D& a_rResult) const
{ CALL
  a_rResult.m_X = a_crVector4D.m_X * m_M[0][0] + a_crVector4D.m_Y * m_M[1][0] + a_crVector4D.m_Z * m_M[2][0] + a_crVector4D.m_W * m_M[3][0];
  a_rResult.m_Y = a_crVector4D.m_X * m_M[0][1] + a_crVector4D.m_Y * m_M[1][1] + a_crVector4D.m_Z * m_M[2][1] + a_crVector4D.m_W * m_M[3][1];
  a_rResult.m_Z = a_crVector4D.m_X * m_M[0][2] + a_crVector4D.m_Y * m_M[1][2] + a_crVector4D.m_Z * m_M[2][2] + a_crVector4D.m_W * m_M[3][2];
  a_rResult.m_W = a_crVector4D.m_X * m_M[0][3] + a_crVector4D.m_Y * m_M[1][3] + a_crVector4D.m_Z * m_M[2][3] + a_crVector4D.m_W * m_M[3][3];
}
/*--------------------------------------------------------------------------*/
CPoint3D<Treal> CMatrix4D::transformEx(const CPoint3D<Treal>& a_crPoint3D) const
{ CALL
  CPoint3D<Treal> result;

  result.m_X = a_crPoint3D.m_X * m_M[0][0] + a_crPoint3D.m_Y * m_M[1][0] + a_crPoint3D.m_Z * m_M[2][0] + m_M[3][0];
  result.m_Y = a_crPoint3D.m_X * m_M[0][1] + a_crPoint3D.m_Y * m_M[1][1] + a_crPoint3D.m_Z * m_M[2][1] + m_M[3][1];
  result.m_Z = a_crPoint3D.m_X * m_M[0][2] + a_crPoint3D.m_Y * m_M[1][2] + a_crPoint3D.m_Z * m_M[2][2] + m_M[3][2];
  // Calculate the denominator.
  Treal denom = a_crPoint3D.m_X * m_M[0][3] + a_crPoint3D.m_Y * m_M[1][3] + a_crPoint3D.m_Z * m_M[2][3] + m_M[3][3];
  if (!NMath::CMath::isEqualZero(denom))
    denom = CONSTR(1.0) / denom;
  else
    denom = 1.0;
  // Correct transformed coordinates.
  result.m_X *= denom;
  result.m_Y *= denom;
  result.m_Z *= denom;
  return result;
}
/*--------------------------------------------------------------------------*/
CVector3D CMatrix4D::transformEx(const CVector3D& a_crVector3D) const
{ CALL
  CVector3D result;

  result.m_X = a_crVector3D.m_X * m_M[0][0] + a_crVector3D.m_Y * m_M[1][0] + a_crVector3D.m_Z * m_M[2][0] + m_M[3][0];
  result.m_Y = a_crVector3D.m_X * m_M[0][1] + a_crVector3D.m_Y * m_M[1][1] + a_crVector3D.m_Z * m_M[2][1] + m_M[3][1];
  result.m_Z = a_crVector3D.m_X * m_M[0][2] + a_crVector3D.m_Y * m_M[1][2] + a_crVector3D.m_Z * m_M[2][2] + m_M[3][2];
  // Calculate the denominator.
  Treal denom = a_crVector3D.m_X * m_M[0][3] + a_crVector3D.m_Y * m_M[1][3] + a_crVector3D.m_Z * m_M[2][3] + m_M[3][3];
  if (!NMath::CMath::isEqualZero(denom))
    denom = CONSTR(1.0) / denom;
  else
    denom = 1.0;
  // Correct transformed coordinates.
  result.m_X *= denom;
  result.m_Y *= denom;
  result.m_Z *= denom;
  return result;
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::transformEx(const CPoint3D<Treal>& a_crPoint3D, CPoint3D<Treal>& a_rResult) const
{ CALL
  a_rResult.m_X = a_crPoint3D.m_X * m_M[0][0] + a_crPoint3D.m_Y * m_M[1][0] + a_crPoint3D.m_Z * m_M[2][0] + m_M[3][0];
  a_rResult.m_Y = a_crPoint3D.m_X * m_M[0][1] + a_crPoint3D.m_Y * m_M[1][1] + a_crPoint3D.m_Z * m_M[2][1] + m_M[3][1];
  a_rResult.m_Z = a_crPoint3D.m_X * m_M[0][2] + a_crPoint3D.m_Y * m_M[1][2] + a_crPoint3D.m_Z * m_M[2][2] + m_M[3][2];
  // Calculate the denominator.
  Treal denom = a_crPoint3D.m_X * m_M[0][3] + a_crPoint3D.m_Y * m_M[1][3] + a_crPoint3D.m_Z * m_M[2][3] + m_M[3][3];
  if (!NMath::CMath::isEqualZero(denom))
    denom = CONSTR(1.0) / denom;
  else
    denom = 1.0;
  // Correct transformed coordinates.
  a_rResult.m_X *= denom;
  a_rResult.m_Y *= denom;
  a_rResult.m_Z *= denom;
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::transformEx(const CVector3D& a_crVector3D, CVector3D& a_rResult) const
{ CALL
  a_rResult.m_X = a_crVector3D.m_X * m_M[0][0] + a_crVector3D.m_Y * m_M[1][0] + a_crVector3D.m_Z * m_M[2][0] + m_M[3][0];
  a_rResult.m_Y = a_crVector3D.m_X * m_M[0][1] + a_crVector3D.m_Y * m_M[1][1] + a_crVector3D.m_Z * m_M[2][1] + m_M[3][1];
  a_rResult.m_Z = a_crVector3D.m_X * m_M[0][2] + a_crVector3D.m_Y * m_M[1][2] + a_crVector3D.m_Z * m_M[2][2] + m_M[3][2];
  // Calculate the denominator.
  Treal denom = a_crVector3D.m_X * m_M[0][3] + a_crVector3D.m_Y * m_M[1][3] + a_crVector3D.m_Z * m_M[2][3] + m_M[3][3];
  if (!NMath::CMath::isEqualZero(denom))
    denom = CONSTR(1.0) / denom;
  else
    denom = 1.0;
  // Correct transformed coordinates.
  a_rResult.m_X *= denom;
  a_rResult.m_Y *= denom;
  a_rResult.m_Z *= denom;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::add(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] + a_crInstance2.m_M[0][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][1] + a_crInstance2.m_M[0][1];
  result.m_M[0][2] = a_crInstance1.m_M[0][2] + a_crInstance2.m_M[0][2];
  result.m_M[0][3] = a_crInstance1.m_M[0][3] + a_crInstance2.m_M[0][3];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] + a_crInstance2.m_M[1][0];
  result.m_M[1][1] = a_crInstance1.m_M[1][1] + a_crInstance2.m_M[1][1];
  result.m_M[1][2] = a_crInstance1.m_M[1][2] + a_crInstance2.m_M[1][2];
  result.m_M[1][3] = a_crInstance1.m_M[1][3] + a_crInstance2.m_M[1][3];
  result.m_M[2][0] = a_crInstance1.m_M[2][0] + a_crInstance2.m_M[2][0];
  result.m_M[2][1] = a_crInstance1.m_M[2][1] + a_crInstance2.m_M[2][1];
  result.m_M[2][2] = a_crInstance1.m_M[2][2] + a_crInstance2.m_M[2][2];
  result.m_M[2][3] = a_crInstance1.m_M[2][3] + a_crInstance2.m_M[2][3];
  result.m_M[3][0] = a_crInstance1.m_M[3][0] + a_crInstance2.m_M[3][0];
  result.m_M[3][1] = a_crInstance1.m_M[3][1] + a_crInstance2.m_M[3][1];
  result.m_M[3][2] = a_crInstance1.m_M[3][2] + a_crInstance2.m_M[3][2];
  result.m_M[3][3] = a_crInstance1.m_M[3][3] + a_crInstance2.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::sub(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] - a_crInstance2.m_M[0][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][1] - a_crInstance2.m_M[0][1];
  result.m_M[0][2] = a_crInstance1.m_M[0][2] - a_crInstance2.m_M[0][2];
  result.m_M[0][3] = a_crInstance1.m_M[0][3] - a_crInstance2.m_M[0][3];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] - a_crInstance2.m_M[1][0];
  result.m_M[1][1] = a_crInstance1.m_M[1][1] - a_crInstance2.m_M[1][1];
  result.m_M[1][2] = a_crInstance1.m_M[1][2] - a_crInstance2.m_M[1][2];
  result.m_M[1][3] = a_crInstance1.m_M[1][3] - a_crInstance2.m_M[1][3];
  result.m_M[2][0] = a_crInstance1.m_M[2][0] - a_crInstance2.m_M[2][0];
  result.m_M[2][1] = a_crInstance1.m_M[2][1] - a_crInstance2.m_M[2][1];
  result.m_M[2][2] = a_crInstance1.m_M[2][2] - a_crInstance2.m_M[2][2];
  result.m_M[2][3] = a_crInstance1.m_M[2][3] - a_crInstance2.m_M[2][3];
  result.m_M[3][0] = a_crInstance1.m_M[3][0] - a_crInstance2.m_M[3][0];
  result.m_M[3][1] = a_crInstance1.m_M[3][1] - a_crInstance2.m_M[3][1];
  result.m_M[3][2] = a_crInstance1.m_M[3][2] - a_crInstance2.m_M[3][2];
  result.m_M[3][3] = a_crInstance1.m_M[3][3] - a_crInstance2.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::mul(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[0][3] * a_crInstance2.m_M[3][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[0][3] * a_crInstance2.m_M[3][1];
  result.m_M[0][2] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[0][3] * a_crInstance2.m_M[3][2];
  result.m_M[0][3] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][3] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][3] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[2][3] + a_crInstance1.m_M[0][3] * a_crInstance2.m_M[3][3];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[3][0];
  result.m_M[1][1] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[3][1];
  result.m_M[1][2] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[3][2];
  result.m_M[1][3] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][3] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][3] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[2][3] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[3][3];
  result.m_M[2][0] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[3][0];
  result.m_M[2][1] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[3][1];
  result.m_M[2][2] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[3][2];
  result.m_M[2][3] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[0][3] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[1][3] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][3] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[3][3];
  result.m_M[3][0] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[3][0];
  result.m_M[3][1] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[3][1];
  result.m_M[3][2] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[3][2];
  result.m_M[3][3] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[0][3] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[1][3] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[2][3] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::adjoint(const CMatrix4D& a_crInstance)
{ CALL
  CMatrix4D result;
  Treal A0 = a_crInstance.m_M[0][0] * a_crInstance.m_M[1][1] - a_crInstance.m_M[0][1] * a_crInstance.m_M[1][0];
  Treal A1 = a_crInstance.m_M[0][0] * a_crInstance.m_M[1][2] - a_crInstance.m_M[0][2] * a_crInstance.m_M[1][0];
  Treal A2 = a_crInstance.m_M[0][0] * a_crInstance.m_M[1][3] - a_crInstance.m_M[0][3] * a_crInstance.m_M[1][0];
  Treal A3 = a_crInstance.m_M[0][1] * a_crInstance.m_M[1][2] - a_crInstance.m_M[0][2] * a_crInstance.m_M[1][1];
  Treal A4 = a_crInstance.m_M[0][1] * a_crInstance.m_M[1][3] - a_crInstance.m_M[0][3] * a_crInstance.m_M[1][1];
  Treal A5 = a_crInstance.m_M[0][2] * a_crInstance.m_M[1][3] - a_crInstance.m_M[0][3] * a_crInstance.m_M[1][2];
  Treal B0 = a_crInstance.m_M[2][0] * a_crInstance.m_M[3][1] - a_crInstance.m_M[2][1] * a_crInstance.m_M[3][0];
  Treal B1 = a_crInstance.m_M[2][0] * a_crInstance.m_M[3][2] - a_crInstance.m_M[2][2] * a_crInstance.m_M[3][0];
  Treal B2 = a_crInstance.m_M[2][0] * a_crInstance.m_M[3][3] - a_crInstance.m_M[2][3] * a_crInstance.m_M[3][0];
  Treal B3 = a_crInstance.m_M[2][1] * a_crInstance.m_M[3][2] - a_crInstance.m_M[2][2] * a_crInstance.m_M[3][1];
  Treal B4 = a_crInstance.m_M[2][1] * a_crInstance.m_M[3][3] - a_crInstance.m_M[2][3] * a_crInstance.m_M[3][1];
  Treal B5 = a_crInstance.m_M[2][2] * a_crInstance.m_M[3][3] - a_crInstance.m_M[2][3] * a_crInstance.m_M[3][2];

  result.m_M[0][0] = +a_crInstance.m_M[1][1] * B5 - a_crInstance.m_M[1][2] * B4 + a_crInstance.m_M[1][3] * B3;
  result.m_M[0][1] = -a_crInstance.m_M[1][0] * B5 + a_crInstance.m_M[1][2] * B2 - a_crInstance.m_M[1][3] * B1;
  result.m_M[0][2] = +a_crInstance.m_M[1][0] * B4 - a_crInstance.m_M[1][1] * B2 + a_crInstance.m_M[1][3] * B0;
  result.m_M[0][3] = -a_crInstance.m_M[1][0] * B3 + a_crInstance.m_M[1][1] * B1 - a_crInstance.m_M[1][2] * B0;
  result.m_M[1][0] = -a_crInstance.m_M[0][1] * B5 + a_crInstance.m_M[0][2] * B4 - a_crInstance.m_M[0][3] * B3;
  result.m_M[1][1] = +a_crInstance.m_M[0][0] * B5 - a_crInstance.m_M[0][2] * B2 + a_crInstance.m_M[0][3] * B1;
  result.m_M[1][2] = -a_crInstance.m_M[0][0] * B4 + a_crInstance.m_M[0][1] * B2 - a_crInstance.m_M[0][3] * B0;
  result.m_M[1][3] = +a_crInstance.m_M[0][0] * B3 - a_crInstance.m_M[0][1] * B1 + a_crInstance.m_M[0][2] * B0;
  result.m_M[2][0] = +a_crInstance.m_M[3][1] * A5 - a_crInstance.m_M[3][2] * A4 + a_crInstance.m_M[3][3] * A3;
  result.m_M[2][1] = -a_crInstance.m_M[3][0] * A5 + a_crInstance.m_M[3][2] * A2 - a_crInstance.m_M[3][3] * A1;
  result.m_M[2][2] = +a_crInstance.m_M[3][0] * A4 - a_crInstance.m_M[3][1] * A2 + a_crInstance.m_M[3][3] * A0;
  result.m_M[2][3] = -a_crInstance.m_M[3][0] * A3 + a_crInstance.m_M[3][1] * A1 - a_crInstance.m_M[3][2] * A0;
  result.m_M[3][0] = -a_crInstance.m_M[2][1] * A5 + a_crInstance.m_M[2][2] * A4 - a_crInstance.m_M[2][3] * A3;
  result.m_M[3][1] = +a_crInstance.m_M[2][0] * A5 - a_crInstance.m_M[2][2] * A2 + a_crInstance.m_M[2][3] * A1;
  result.m_M[3][2] = -a_crInstance.m_M[2][0] * A4 + a_crInstance.m_M[2][1] * A2 - a_crInstance.m_M[2][3] * A0;
  result.m_M[3][3] = +a_crInstance.m_M[2][0] * A3 - a_crInstance.m_M[2][1] * A1 + a_crInstance.m_M[2][2] * A0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::invert(const CMatrix4D& a_crInstance)
{ CALL
  CMatrix4D result;

  // Get determinant of the matrix.
  Treal det = a_crInstance.getDeterminant();

  // Check the determinant not to be 0.
  ASSERT((!NMath::CMath::isEqualZero(det)), STR("Matrix with 0 determinant cannot be inverted."))
  {
    return result;
  }

  det = CONSTR(1.0) / det;
  #define DET22(M00, M01, M10, M11) (M00 * M11 - M01 * M10)
  #define DET33(M00, M01, M02, M10, M11, M12, M20, M21, M22) (M00 * DET22(M11, M12, M21, M22) - M01 * DET22(M10, M12, M20, M22) + M02 * DET22(M10, M11, M20, M21))
  result.m_M[0][0]=  DET33(a_crInstance.m_M[1][1], a_crInstance.m_M[2][1], a_crInstance.m_M[3][1], a_crInstance.m_M[1][2], a_crInstance.m_M[2][2], a_crInstance.m_M[3][2], a_crInstance.m_M[1][3], a_crInstance.m_M[2][3], a_crInstance.m_M[3][3]) * det;
  result.m_M[0][1]= -DET33(a_crInstance.m_M[0][1], a_crInstance.m_M[2][1], a_crInstance.m_M[3][1], a_crInstance.m_M[0][2], a_crInstance.m_M[2][2], a_crInstance.m_M[3][2], a_crInstance.m_M[0][3], a_crInstance.m_M[2][3], a_crInstance.m_M[3][3]) * det;
  result.m_M[0][2]=  DET33(a_crInstance.m_M[0][1], a_crInstance.m_M[1][1], a_crInstance.m_M[3][1], a_crInstance.m_M[0][2], a_crInstance.m_M[1][2], a_crInstance.m_M[3][2], a_crInstance.m_M[0][3], a_crInstance.m_M[1][3], a_crInstance.m_M[3][3]) * det;
  result.m_M[0][3]= -DET33(a_crInstance.m_M[0][1], a_crInstance.m_M[1][1], a_crInstance.m_M[2][1], a_crInstance.m_M[0][2], a_crInstance.m_M[1][2], a_crInstance.m_M[2][2], a_crInstance.m_M[0][3], a_crInstance.m_M[1][3], a_crInstance.m_M[2][3]) * det;
  result.m_M[1][0]= -DET33(a_crInstance.m_M[1][0], a_crInstance.m_M[2][0], a_crInstance.m_M[3][0], a_crInstance.m_M[1][2], a_crInstance.m_M[2][2], a_crInstance.m_M[3][2], a_crInstance.m_M[1][3], a_crInstance.m_M[2][3], a_crInstance.m_M[3][3]) * det;
  result.m_M[1][1]=  DET33(a_crInstance.m_M[0][0], a_crInstance.m_M[2][0], a_crInstance.m_M[3][0], a_crInstance.m_M[0][2], a_crInstance.m_M[2][2], a_crInstance.m_M[3][2], a_crInstance.m_M[0][3], a_crInstance.m_M[2][3], a_crInstance.m_M[3][3]) * det;
  result.m_M[1][2]= -DET33(a_crInstance.m_M[0][0], a_crInstance.m_M[1][0], a_crInstance.m_M[3][0], a_crInstance.m_M[0][2], a_crInstance.m_M[1][2], a_crInstance.m_M[3][2], a_crInstance.m_M[0][3], a_crInstance.m_M[1][3], a_crInstance.m_M[3][3]) * det;
  result.m_M[1][3]=  DET33(a_crInstance.m_M[0][0], a_crInstance.m_M[1][0], a_crInstance.m_M[2][0], a_crInstance.m_M[0][2], a_crInstance.m_M[1][2], a_crInstance.m_M[2][2], a_crInstance.m_M[0][3], a_crInstance.m_M[1][3], a_crInstance.m_M[2][3]) * det;
  result.m_M[2][0]=  DET33(a_crInstance.m_M[1][0], a_crInstance.m_M[2][0], a_crInstance.m_M[3][0], a_crInstance.m_M[1][1], a_crInstance.m_M[2][1], a_crInstance.m_M[3][1], a_crInstance.m_M[1][3], a_crInstance.m_M[2][3], a_crInstance.m_M[3][3]) * det;
  result.m_M[2][1]= -DET33(a_crInstance.m_M[0][0], a_crInstance.m_M[2][0], a_crInstance.m_M[3][0], a_crInstance.m_M[0][1], a_crInstance.m_M[2][1], a_crInstance.m_M[3][1], a_crInstance.m_M[0][3], a_crInstance.m_M[2][3], a_crInstance.m_M[3][3]) * det;
  result.m_M[2][2]=  DET33(a_crInstance.m_M[0][0], a_crInstance.m_M[1][0], a_crInstance.m_M[3][0], a_crInstance.m_M[0][1], a_crInstance.m_M[1][1], a_crInstance.m_M[3][1], a_crInstance.m_M[0][3], a_crInstance.m_M[1][3], a_crInstance.m_M[3][3]) * det;
  result.m_M[2][3]= -DET33(a_crInstance.m_M[0][0], a_crInstance.m_M[1][0], a_crInstance.m_M[2][0], a_crInstance.m_M[0][1], a_crInstance.m_M[1][1], a_crInstance.m_M[2][1], a_crInstance.m_M[0][3], a_crInstance.m_M[1][3], a_crInstance.m_M[2][3]) * det;
  result.m_M[3][0]= -DET33(a_crInstance.m_M[1][0], a_crInstance.m_M[2][0], a_crInstance.m_M[3][0], a_crInstance.m_M[1][1], a_crInstance.m_M[2][1], a_crInstance.m_M[3][1], a_crInstance.m_M[1][2], a_crInstance.m_M[2][2], a_crInstance.m_M[3][2]) * det;
  result.m_M[3][1]=  DET33(a_crInstance.m_M[0][0], a_crInstance.m_M[2][0], a_crInstance.m_M[3][0], a_crInstance.m_M[0][1], a_crInstance.m_M[2][1], a_crInstance.m_M[3][1], a_crInstance.m_M[0][2], a_crInstance.m_M[2][2], a_crInstance.m_M[3][2]) * det;
  result.m_M[3][2]= -DET33(a_crInstance.m_M[0][0], a_crInstance.m_M[1][0], a_crInstance.m_M[3][0], a_crInstance.m_M[0][1], a_crInstance.m_M[1][1], a_crInstance.m_M[3][1], a_crInstance.m_M[0][2], a_crInstance.m_M[1][2], a_crInstance.m_M[3][2]) * det;
  result.m_M[3][3]=  DET33(a_crInstance.m_M[0][0], a_crInstance.m_M[1][0], a_crInstance.m_M[2][0], a_crInstance.m_M[0][1], a_crInstance.m_M[1][1], a_crInstance.m_M[2][1], a_crInstance.m_M[0][2], a_crInstance.m_M[1][2], a_crInstance.m_M[2][2]) * det;
  #undef DET33
  #undef DET22
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::transpose(const CMatrix4D& a_crInstance)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crInstance.m_M[0][0];
  result.m_M[0][1] = a_crInstance.m_M[1][0];
  result.m_M[0][2] = a_crInstance.m_M[2][0];
  result.m_M[0][3] = a_crInstance.m_M[3][0];
  result.m_M[1][0] = a_crInstance.m_M[0][1];
  result.m_M[1][1] = a_crInstance.m_M[1][1];
  result.m_M[1][2] = a_crInstance.m_M[2][1];
  result.m_M[1][3] = a_crInstance.m_M[3][1];
  result.m_M[2][0] = a_crInstance.m_M[0][2];
  result.m_M[2][1] = a_crInstance.m_M[1][2];
  result.m_M[2][2] = a_crInstance.m_M[2][2];
  result.m_M[2][3] = a_crInstance.m_M[3][2];
  result.m_M[3][0] = a_crInstance.m_M[0][3];
  result.m_M[3][1] = a_crInstance.m_M[1][3];
  result.m_M[3][2] = a_crInstance.m_M[2][3];
  result.m_M[3][3] = a_crInstance.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::transposeTimes(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[2][0] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[3][0] * a_crInstance2.m_M[3][0];
  result.m_M[0][1] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[2][0] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[3][0] * a_crInstance2.m_M[3][1];
  result.m_M[0][2] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[2][0] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[3][0] * a_crInstance2.m_M[3][2];
  result.m_M[0][3] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][3] + a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][3] + a_crInstance1.m_M[2][0] * a_crInstance2.m_M[2][3] + a_crInstance1.m_M[3][0] * a_crInstance2.m_M[3][3];
  result.m_M[1][0] = a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[3][0];
  result.m_M[1][1] = a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[3][1];
  result.m_M[1][2] = a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[3][2];
  result.m_M[1][3] = a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][3] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][3] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[2][3] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[3][3];
  result.m_M[2][0] = a_crInstance1.m_M[0][2] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[3][0];
  result.m_M[2][1] = a_crInstance1.m_M[0][2] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[3][1];
  result.m_M[2][2] = a_crInstance1.m_M[0][2] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[3][2];
  result.m_M[2][3] = a_crInstance1.m_M[0][2] * a_crInstance2.m_M[0][3] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[1][3] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][3] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[3][3];
  result.m_M[3][0] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[3][0];
  result.m_M[3][1] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[3][1];
  result.m_M[3][2] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[3][2];
  result.m_M[3][3] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[0][3] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[1][3] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[2][3] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::timesTranspose(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[0][3] * a_crInstance2.m_M[0][3];
  result.m_M[0][1] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[0][3] * a_crInstance2.m_M[1][3];
  result.m_M[0][2] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[0][3] * a_crInstance2.m_M[2][3];
  result.m_M[0][3] = a_crInstance1.m_M[0][0] * a_crInstance2.m_M[3][0] + a_crInstance1.m_M[0][1] * a_crInstance2.m_M[3][1] + a_crInstance1.m_M[0][2] * a_crInstance2.m_M[3][2] + a_crInstance1.m_M[0][3] * a_crInstance2.m_M[3][3];
  result.m_M[1][0] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[0][3];
  result.m_M[1][1] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[1][3];
  result.m_M[1][2] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[2][3];
  result.m_M[1][3] = a_crInstance1.m_M[1][0] * a_crInstance2.m_M[3][0] + a_crInstance1.m_M[1][1] * a_crInstance2.m_M[3][1] + a_crInstance1.m_M[1][2] * a_crInstance2.m_M[3][2] + a_crInstance1.m_M[1][3] * a_crInstance2.m_M[3][3];
  result.m_M[2][0] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[0][3];
  result.m_M[2][1] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[1][3];
  result.m_M[2][2] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[2][3];
  result.m_M[2][3] = a_crInstance1.m_M[2][0] * a_crInstance2.m_M[3][0] + a_crInstance1.m_M[2][1] * a_crInstance2.m_M[3][1] + a_crInstance1.m_M[2][2] * a_crInstance2.m_M[3][2] + a_crInstance1.m_M[2][3] * a_crInstance2.m_M[3][3];
  result.m_M[3][0] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[0][0] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[0][1] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[0][2] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[0][3];
  result.m_M[3][1] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[1][0] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[1][1] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[1][2] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[1][3];
  result.m_M[3][2] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[2][0] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[2][1] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[2][2] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[2][3];
  result.m_M[3][3] = a_crInstance1.m_M[3][0] * a_crInstance2.m_M[3][0] + a_crInstance1.m_M[3][1] * a_crInstance2.m_M[3][1] + a_crInstance1.m_M[3][2] * a_crInstance2.m_M[3][2] + a_crInstance1.m_M[3][3] * a_crInstance2.m_M[3][3];
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::tensorProduct(const CVector3D& a_crU, const CVector3D& a_crV)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crU.m_X * a_crV.m_X;
  result.m_M[0][1] = a_crU.m_X * a_crV.m_Y;
  result.m_M[0][2] = a_crU.m_X * a_crV.m_Z;
  result.m_M[0][3] = 0.0;
  result.m_M[1][0] = a_crU.m_Y * a_crV.m_X;
  result.m_M[1][1] = a_crU.m_Y * a_crV.m_Y;
  result.m_M[1][2] = a_crU.m_Y * a_crV.m_Z;
  result.m_M[1][3] = 0.0;
  result.m_M[2][0] = a_crU.m_Z * a_crV.m_X;
  result.m_M[2][1] = a_crU.m_Z * a_crV.m_Y;
  result.m_M[2][2] = a_crU.m_Z * a_crV.m_Z;
  result.m_M[2][3] = 0.0;
  result.m_M[3][0] = 0.0;
  result.m_M[3][1] = 0.0;
  result.m_M[3][2] = 0.0;
  result.m_M[3][3] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::tensorProduct(const CVector4D& a_crU, const CVector4D& a_crV)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_crU.m_X * a_crV.m_X;
  result.m_M[0][1] = a_crU.m_X * a_crV.m_Y;
  result.m_M[0][2] = a_crU.m_X * a_crV.m_Z;
  result.m_M[0][3] = a_crU.m_X * a_crV.m_W;
  result.m_M[1][0] = a_crU.m_Y * a_crV.m_X;
  result.m_M[1][1] = a_crU.m_Y * a_crV.m_Y;
  result.m_M[1][2] = a_crU.m_Y * a_crV.m_Z;
  result.m_M[1][3] = a_crU.m_Y * a_crV.m_W;
  result.m_M[2][0] = a_crU.m_Z * a_crV.m_X;
  result.m_M[2][1] = a_crU.m_Z * a_crV.m_Y;
  result.m_M[2][2] = a_crU.m_Z * a_crV.m_Z;
  result.m_M[2][3] = a_crU.m_Z * a_crV.m_W;
  result.m_M[3][0] = a_crU.m_W * a_crV.m_X;
  result.m_M[3][1] = a_crU.m_W * a_crV.m_Y;
  result.m_M[3][2] = a_crU.m_W * a_crV.m_Z;
  result.m_M[3][3] = a_crU.m_W * a_crV.m_W;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::translate(const Treal a_cTranslateX, const Treal a_cTranslateY, const Treal a_cTranslateZ)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = 1.0;
  result.m_M[0][1] = 0.0;
  result.m_M[0][2] = 0.0;
  result.m_M[0][3] = 0.0;
  result.m_M[1][0] = 0.0;
  result.m_M[1][1] = 1.0;
  result.m_M[1][2] = 0.0;
  result.m_M[1][3] = 0.0;
  result.m_M[2][0] = 0.0;
  result.m_M[2][1] = 0.0;
  result.m_M[2][2] = 1.0;
  result.m_M[2][3] = 0.0;
  result.m_M[3][0] = a_cTranslateX;
  result.m_M[3][1] = a_cTranslateY;
  result.m_M[3][2] = a_cTranslateZ;
  result.m_M[3][3] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::scale(const Treal a_cScaleX, const Treal a_cScaleY, const Treal a_cScaleZ)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = a_cScaleX;
  result.m_M[0][1] = 0.0;
  result.m_M[0][2] = 0.0;
  result.m_M[0][3] = 0.0;
  result.m_M[1][0] = 0.0;
  result.m_M[1][1] = a_cScaleY;
  result.m_M[1][2] = 0.0;
  result.m_M[1][3] = 0.0;
  result.m_M[2][0] = 0.0;
  result.m_M[2][1] = 0.0;
  result.m_M[2][2] = a_cScaleZ;
  result.m_M[2][3] = 0.0;
  result.m_M[3][0] = 0.0;
  result.m_M[3][1] = 0.0;
  result.m_M[3][2] = 0.0;
  result.m_M[3][3] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::shear(const Treal a_cShearXY, const Treal a_cShearXZ, const Treal a_cShearYX, const Treal a_cShearYZ, const Treal a_cShearZX, const Treal a_cShearZY)
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = 1.0;
  result.m_M[0][1] = a_cShearXY;
  result.m_M[0][2] = a_cShearXZ;
  result.m_M[0][3] = 0.0;
  result.m_M[1][0] = a_cShearYX;
  result.m_M[1][1] = 1.0;
  result.m_M[1][2] = a_cShearYZ;
  result.m_M[1][3] = 0.0;
  result.m_M[2][0] = a_cShearZX;
  result.m_M[2][1] = a_cShearZY;
  result.m_M[2][2] = 1.0;
  result.m_M[2][3] = 0.0;
  result.m_M[3][0] = 0.0;
  result.m_M[3][1] = 0.0;
  result.m_M[3][2] = 0.0;
  result.m_M[3][3] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::rotate(const CVector3D& a_crAxis, const Treal a_cAngle)
{ CALL
  CMatrix4D result;
  CVector3D axis(a_crAxis);
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);

  axis.normalize();
  result.m_M[0][0] = axis.m_X * axis.m_X + (1 - axis.m_X * axis.m_X) * cos_angle;
  result.m_M[0][1] = axis.m_X * axis.m_Y * (1 - cos_angle) + axis.m_Z * sin_angle;
  result.m_M[0][2] = axis.m_X * axis.m_Z * (1 - cos_angle) - axis.m_Y * sin_angle;
  result.m_M[0][3] = 0.0;
  result.m_M[1][0] = axis.m_X * axis.m_Y * (1 - cos_angle) - axis.m_Z * sin_angle;
  result.m_M[1][1] = axis.m_Y * axis.m_Y + (1 - axis.m_Y * axis.m_Y) * cos_angle;
  result.m_M[1][2] = axis.m_Y * axis.m_Z * (1 - cos_angle) + axis.m_X * sin_angle;
  result.m_M[1][3] = 0.0;
  result.m_M[2][0] = axis.m_X * axis.m_Z * (1 - cos_angle) + axis.m_Y * sin_angle;
  result.m_M[2][1] = axis.m_Y * axis.m_Z * (1 - cos_angle) - axis.m_X * sin_angle;
  result.m_M[2][2] = axis.m_Z * axis.m_Z + (1 - axis.m_Z * axis.m_Z) * cos_angle;
  result.m_M[2][3] = 0.0;
  result.m_M[3][0] = 0.0;
  result.m_M[3][1] = 0.0;
  result.m_M[3][2] = 0.0;
  result.m_M[3][3] = 1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::rotateX(const Treal a_cAngle)
{ CALL
  CMatrix4D result;
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);

  result.m_M[0][0] =  1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] =  0.0;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] =  cos_angle;
  result.m_M[1][2] =  sin_angle;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] = -sin_angle;
  result.m_M[2][2] =  cos_angle;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::rotateY(const Treal a_cAngle)
{ CALL
  CMatrix4D result;
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);

  result.m_M[0][0] =  cos_angle;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] = -sin_angle;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] =  1.0;
  result.m_M[1][2] =  0.0;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  sin_angle;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] =  cos_angle;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::rotateZ(const Treal a_cAngle)
{ CALL
  CMatrix4D result;
  Treal sin_angle = NMath::CMath::sin(a_cAngle);
  Treal cos_angle = NMath::CMath::cos(a_cAngle);

  result.m_M[0][0] =  cos_angle;
  result.m_M[0][1] =  sin_angle;
  result.m_M[0][2] =  0.0;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] = -sin_angle;
  result.m_M[1][1] =  cos_angle;
  result.m_M[1][2] =  0.0;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] =  1.0;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::rotateXYZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix4D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] =  cos_angleY * cos_angleZ;
  result.m_M[0][1] =  sin_angleX * sin_angleY * cos_angleZ + cos_angleX * sin_angleZ;
  result.m_M[0][2] = -cos_angleX * sin_angleY * cos_angleZ + sin_angleX * sin_angleZ;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] = -cos_angleY * sin_angleZ;
  result.m_M[1][1] = -sin_angleX * sin_angleY * sin_angleZ + cos_angleX * cos_angleZ;
  result.m_M[1][2] =  cos_angleX * sin_angleY * sin_angleZ + sin_angleX * cos_angleZ;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  sin_angleY;
  result.m_M[2][1] = -sin_angleX * cos_angleY;
  result.m_M[2][2] =  cos_angleX * cos_angleY;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::rotateXZY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix4D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] =  cos_angleY * cos_angleZ;
  result.m_M[0][1] =  cos_angleX * cos_angleY * sin_angleZ + sin_angleX * sin_angleY;
  result.m_M[0][2] =  cos_angleY * sin_angleX * sin_angleZ - cos_angleX * sin_angleY;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] = -sin_angleZ;
  result.m_M[1][1] =  cos_angleX * cos_angleZ;
  result.m_M[1][2] =  cos_angleZ * sin_angleX;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  cos_angleZ * sin_angleY;
  result.m_M[2][1] =  cos_angleX * sin_angleY * sin_angleZ - cos_angleY * sin_angleX;
  result.m_M[2][2] =  sin_angleX * sin_angleY * sin_angleZ + cos_angleX * cos_angleY;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::rotateYXZ(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix4D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] =  sin_angleX * sin_angleY * sin_angleZ + cos_angleY * cos_angleZ;
  result.m_M[0][1] =  cos_angleX * sin_angleZ;
  result.m_M[0][2] =  cos_angleY * sin_angleX * sin_angleZ - cos_angleZ * sin_angleY;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] =  cos_angleZ * sin_angleX * sin_angleY - cos_angleY * sin_angleZ;
  result.m_M[1][1] =  cos_angleX * cos_angleZ;
  result.m_M[1][2] =  cos_angleY * cos_angleZ * sin_angleX + sin_angleY * sin_angleZ;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  cos_angleX * sin_angleY;
  result.m_M[2][1] = -sin_angleX;
  result.m_M[2][2] =  cos_angleX * cos_angleY;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::rotateYZX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix4D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] =  cos_angleY * cos_angleZ;
  result.m_M[0][1] =  sin_angleZ;
  result.m_M[0][2] = -cos_angleZ * sin_angleY;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] = -cos_angleX * cos_angleY * sin_angleZ + sin_angleX * sin_angleY;
  result.m_M[1][1] =  cos_angleX * cos_angleZ;
  result.m_M[1][2] =  cos_angleX * sin_angleY * sin_angleZ + cos_angleY * sin_angleX;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  cos_angleY * sin_angleX * sin_angleZ + cos_angleX * sin_angleY;
  result.m_M[2][1] = -cos_angleZ * sin_angleX;
  result.m_M[2][2] = -sin_angleX * sin_angleY * sin_angleZ + cos_angleX * cos_angleY;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::rotateZXY(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix4D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] = -sin_angleX * sin_angleY * sin_angleZ + cos_angleY * cos_angleZ;
  result.m_M[0][1] =  cos_angleZ * sin_angleX * sin_angleY + cos_angleY * sin_angleZ;
  result.m_M[0][2] = -cos_angleX * sin_angleY;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] = -cos_angleX * sin_angleZ;
  result.m_M[1][1] =  cos_angleX * cos_angleZ;
  result.m_M[1][2] =  sin_angleX;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  cos_angleY * sin_angleX * sin_angleZ + cos_angleZ * sin_angleY;
  result.m_M[2][1] = -cos_angleY * cos_angleZ * sin_angleX + sin_angleY * sin_angleZ;
  result.m_M[2][2] =  cos_angleX * cos_angleY;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::rotateZYX(const Treal a_cAngleX, const Treal a_cAngleY, const Treal a_cAngleZ)
{ CALL
  CMatrix4D result;
  Treal sin_angleX = NMath::CMath::sin(a_cAngleX);
  Treal cos_angleX = NMath::CMath::cos(a_cAngleX);
  Treal sin_angleY = NMath::CMath::sin(a_cAngleY);
  Treal cos_angleY = NMath::CMath::cos(a_cAngleY);
  Treal sin_angleZ = NMath::CMath::sin(a_cAngleZ);
  Treal cos_angleZ = NMath::CMath::cos(a_cAngleZ);

  result.m_M[0][0] =  cos_angleY * cos_angleZ;
  result.m_M[0][1] =  cos_angleY * sin_angleZ;
  result.m_M[0][2] = -sin_angleY;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] =  cos_angleZ * sin_angleX * sin_angleY - cos_angleX * sin_angleZ;
  result.m_M[1][1] =  sin_angleX * sin_angleY * sin_angleZ + cos_angleX * cos_angleZ;
  result.m_M[1][2] =  cos_angleY * sin_angleX;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  cos_angleX * cos_angleZ * sin_angleY + sin_angleX * sin_angleZ;
  result.m_M[2][1] =  cos_angleX * sin_angleY * sin_angleZ - cos_angleZ * sin_angleX;
  result.m_M[2][2] =  cos_angleX * cos_angleY;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::mirrorX()
{ CALL
  CMatrix4D result;

  result.m_M[0][0] = -1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] =  0.0;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] =  1.0;
  result.m_M[1][2] =  0.0;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] =  1.0;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::mirrorY()
{ CALL
  CMatrix4D result;

  result.m_M[0][0] =  1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] =  0.0;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] = -1.0;
  result.m_M[1][2] =  0.0;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] =  1.0;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::mirrorZ()
{ CALL
  CMatrix4D result;

  result.m_M[0][0] =  1.0;
  result.m_M[0][1] =  0.0;
  result.m_M[0][2] =  0.0;
  result.m_M[0][3] =  0.0;
  result.m_M[1][0] =  0.0;
  result.m_M[1][1] =  1.0;
  result.m_M[1][2] =  0.0;
  result.m_M[1][3] =  0.0;
  result.m_M[2][0] =  0.0;
  result.m_M[2][1] =  0.0;
  result.m_M[2][2] = -1.0;
  result.m_M[2][3] =  0.0;
  result.m_M[3][0] =  0.0;
  result.m_M[3][1] =  0.0;
  result.m_M[3][2] =  0.0;
  result.m_M[3][3] =  1.0;
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::slerp(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2, const Treal a_cPart)
{ CALL
  CMatrix4D temp = transposeTimes(a_crInstance1, a_crInstance2);
  CVector3D axis;
  Treal angle;
  temp.getRotateAxisAngle(axis, angle);

  CMatrix4D result = rotate(axis, angle * a_cPart);
  result.m_M[2][0] = a_crInstance1.m_M[2][0] + a_cPart * (a_crInstance2.m_M[2][0] - a_crInstance1.m_M[2][0]);
  result.m_M[2][1] = a_crInstance1.m_M[2][1] + a_cPart * (a_crInstance2.m_M[2][1] - a_crInstance1.m_M[2][1]);
  result.m_M[2][2] = a_crInstance1.m_M[2][2] + a_cPart * (a_crInstance2.m_M[2][2] - a_crInstance1.m_M[2][2]);
  return result;
}
/*--------------------------------------------------------------------------*/
CMatrix4D CMatrix4D::slerpSpins(const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2, const Treal a_cPart, const Treal a_cSpins)
{ CALL
  CMatrix4D temp = transposeTimes(a_crInstance1, a_crInstance2);
  CVector3D axis;
  Treal angle;
  temp.getRotateAxisAngle(axis, angle);

  CMatrix4D result = rotate(axis, (angle + a_cSpins * NMath::CMathConstants::PI) * a_cPart);
  result.m_M[2][0] = a_crInstance1.m_M[2][0] + a_cPart * (a_crInstance2.m_M[2][0] - a_crInstance1.m_M[2][0]);
  result.m_M[2][1] = a_crInstance1.m_M[2][1] + a_cPart * (a_crInstance2.m_M[2][1] - a_crInstance1.m_M[2][1]);
  result.m_M[2][2] = a_crInstance1.m_M[2][2] + a_cPart * (a_crInstance2.m_M[2][2] - a_crInstance1.m_M[2][2]);
  return result;
}
/*--------------------------------------------------------------------------*/
void CMatrix4D::swap(CMatrix4D& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_M[0][0], a_rInstance.m_M[0][0]);
  NAlgorithms::NCommon::swap(m_M[0][1], a_rInstance.m_M[0][1]);
  NAlgorithms::NCommon::swap(m_M[0][2], a_rInstance.m_M[0][2]);
  NAlgorithms::NCommon::swap(m_M[0][3], a_rInstance.m_M[0][3]);
  NAlgorithms::NCommon::swap(m_M[1][0], a_rInstance.m_M[1][0]);
  NAlgorithms::NCommon::swap(m_M[1][1], a_rInstance.m_M[1][1]);
  NAlgorithms::NCommon::swap(m_M[1][2], a_rInstance.m_M[1][2]);
  NAlgorithms::NCommon::swap(m_M[1][3], a_rInstance.m_M[1][3]);
  NAlgorithms::NCommon::swap(m_M[2][0], a_rInstance.m_M[2][0]);
  NAlgorithms::NCommon::swap(m_M[2][1], a_rInstance.m_M[2][1]);
  NAlgorithms::NCommon::swap(m_M[2][2], a_rInstance.m_M[2][2]);
  NAlgorithms::NCommon::swap(m_M[2][3], a_rInstance.m_M[2][3]);
  NAlgorithms::NCommon::swap(m_M[3][0], a_rInstance.m_M[3][0]);
  NAlgorithms::NCommon::swap(m_M[3][1], a_rInstance.m_M[3][1]);
  NAlgorithms::NCommon::swap(m_M[3][2], a_rInstance.m_M[3][2]);
  NAlgorithms::NCommon::swap(m_M[3][3], a_rInstance.m_M[3][3]);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
