/*!
 *  \file    CMatrix4D.inl Representation of the extended transformation
 *           matrix in a space.
 *  \brief   Extended transformation matrix in a space class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Extended transformation matrix in a space class (inline).

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
#ifndef __CMATRIX4D_INL__
#define __CMATRIX4D_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CMatrix4D::CMatrix4D(const Tbool a_cIdentityFlag/* = true */) :
  m_M()
{ CALL
  clear(a_cIdentityFlag);
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D::CMatrix4D(const Treal a_cpMatrixBuffer[]) :
  m_M()
{ CALL
  set(a_cpMatrixBuffer);
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D::CMatrix4D(const CMatrix2D& a_crInstance) :
  m_M()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D::CMatrix4D(const CMatrix3D& a_crInstance) :
  m_M()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D::CMatrix4D(const CMatrix4D& a_crInstance) :
  m_M()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D::~CMatrix4D()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API Tbool operator != (const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CMatrix4D operator + (const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2)
{ CALL
  return CMatrix4D::add(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CMatrix4D operator - (const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2)
{ CALL
  return CMatrix4D::sub(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CMatrix4D operator * (const CMatrix4D& a_crInstance1, const CMatrix4D& a_crInstance2)
{ CALL
  return CMatrix4D::mul(a_crInstance1, a_crInstance2);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CPoint3D<Treal> operator * (const CPoint3D<Treal>& a_crPoint3D, const CMatrix4D& a_crInstance)
{ CALL
  return a_crInstance.transform(a_crPoint3D);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector3D operator * (const CVector3D& a_crVector3D, const CMatrix4D& a_crInstance)
{ CALL
  return a_crInstance.transform(a_crVector3D);
}
/*--------------------------------------------------------------------------*/
inline GEOMETRY_API CVector4D operator * (const CVector4D& a_crVector4D, const CMatrix4D& a_crInstance)
{ CALL
  return a_crInstance.transform(a_crVector4D);
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D& CMatrix4D::operator = (const CMatrix2D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D& CMatrix4D::operator = (const CMatrix3D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D& CMatrix4D::operator = (const CMatrix4D& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D& CMatrix4D::operator += (const CMatrix4D& a_crInstance)
{ CALL
  set(add(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D& CMatrix4D::operator -= (const CMatrix4D& a_crInstance)
{ CALL
  set(sub(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D& CMatrix4D::operator *= (const CMatrix4D& a_crInstance)
{ CALL
  set(mul(*this, a_crInstance));
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CMatrix4D::getRotateAnglesYPR(Treal& a_rAngleYaw, Treal& a_rAnglePitch, Treal& a_rAngleRoll) const
{ CALL
  getRotateAnglesYXZ(a_rAngleYaw, a_rAnglePitch, a_rAngleRoll);
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D CMatrix4D::zero()
{ CALL
  return CMatrix4D(false);
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D CMatrix4D::identity()
{ CALL
  return CMatrix4D(true);
}
/*--------------------------------------------------------------------------*/
inline CMatrix4D CMatrix4D::rotateYPR(const Treal a_cAngleYaw, const Treal a_cAnglePitch, const Treal a_cAngleRoll)
{ CALL
  return rotateYXZ(a_cAnglePitch, a_cAngleYaw, a_cAngleRoll);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CMatrix4D::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CMatrix4D")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_M, 16, STR("m_M")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
