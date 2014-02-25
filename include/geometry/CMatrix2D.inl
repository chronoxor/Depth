/*!
 *  \file    CMatrix2D.inl Representation of the transformation matrix on a
 *           plane.
 *  \brief   Transformation matrix on a plane class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Transformation matrix on a plane class (inline).

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
#ifndef __CMATRIX2D_INL__
#define __CMATRIX2D_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CMatrix2D::CMatrix2D(const Tbool a_cIdentityFlag/* = true */) :
  m_M()
{ CALL
  clear(a_cIdentityFlag);
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D::CMatrix2D(const Treal a_cpMatrixBuffer[]) :
  m_M()
{ CALL
  set(a_cpMatrixBuffer);
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D::CMatrix2D(const CMatrix2D& a_crInstance) :
  m_M()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D::CMatrix2D(const CMatrix3D& a_crInstance) :
  m_M()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D::CMatrix2D(const CMatrix4D& a_crInstance) :
  m_M()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D::~CMatrix2D()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator != (const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CMatrix2D operator + (const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2)
{ CALL
  return CMatrix2D::add(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CMatrix2D operator - (const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2)
{ CALL
  return CMatrix2D::sub(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CMatrix2D operator * (const CMatrix2D& a_crInstance1, const CMatrix2D& a_crInstance2)
{ CALL
  return CMatrix2D::mul(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CPoint2D<Treal> operator * (const CPoint2D<Treal>& a_crPoint2D, const CMatrix2D& a_crInstance)
{ CALL
  return a_crInstance.transform(a_crPoint2D);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector2D operator * (const CVector2D& a_crVector2D, const CMatrix2D& a_crInstance)
{ CALL
  return a_crInstance.transform(a_crVector2D);
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D& CMatrix2D::operator = (const CMatrix2D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D& CMatrix2D::operator = (const CMatrix3D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D& CMatrix2D::operator = (const CMatrix4D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D& CMatrix2D::operator += (const CMatrix2D& a_crInstance)
{ CALL
  set(add(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D& CMatrix2D::operator -= (const CMatrix2D& a_crInstance)
{ CALL
  set(sub(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D& CMatrix2D::operator *= (const CMatrix2D& a_crInstance)
{ CALL
  set(mul(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D CMatrix2D::zero()
{ CALL
  return CMatrix2D(false);
}
/*--------------------------------------------------------------------------*/
inline CMatrix2D CMatrix2D::identity()
{ CALL
  return CMatrix2D(true);
}
/*--------------------------------------------------------------------------*/
inline CPoint2D<Treal> CMatrix2D::rotate(const CPoint2D<Treal>& a_crPoint2D) const
{ CALL
  return transform(a_crPoint2D);
}
/*--------------------------------------------------------------------------*/
inline CVector2D CMatrix2D::rotate(const CVector2D& a_crVector2D) const
{ CALL
  return transform(a_crVector2D);
}
/*--------------------------------------------------------------------------*/
inline void CMatrix2D::rotate(const CPoint2D<Treal>& a_crPoint2D, CPoint2D<Treal>& a_rResult) const
{ CALL
  transform(a_crPoint2D, a_rResult);
}
/*--------------------------------------------------------------------------*/
inline void CMatrix2D::rotate(const CVector2D& a_crVector2D, CVector2D& a_rResult) const
{ CALL
  transform(a_crVector2D, a_rResult);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CMatrix2D::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CMatrix2D")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_M, 4, STR("m_M")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
