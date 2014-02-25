/*!
 *  \file    CBox.inl Template representation of the box in a space.
 *  \brief   Box in a space template class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Box in a space template class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   10.02.2006 01:33:56

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
#ifndef __CBOX_INL__
#define __CBOX_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline CBox<T_Type>::CBox() :
  m_A(),
  m_B()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type>::CBox(const T_Type a_cX1, const T_Type a_cY1, const T_Type a_cZ1, const T_Type a_cX2, const T_Type a_cY2, const T_Type a_cZ2) :
  m_A(),
  m_B()
{ CALL
  set(a_cX1, a_cY1, a_cZ1, a_cX2, a_cY2, a_cZ2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type>::CBox(const CPoint3D<T_Type>& a_crA, const CPoint3D<T_Type>& a_crB) :
  m_A(),
  m_B()
{ CALL
  set(a_crA, a_crB);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type>::CBox(const T_Type a_cpCoordinatesBuffer[]) :
  m_A(),
  m_B()
{ CALL
  set(a_cpCoordinatesBuffer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CBox<T_Type>::CBox(const CBox<T_OtherType>& a_crInstance) :
  m_A(),
  m_B()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type>::~CBox()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator == (const CBox<T_Type>& a_crInstance1, const CBox<T_OtherType>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_A == a_crInstance2.m_A) && (a_crInstance1.m_B == a_crInstance2.m_B));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator != (const CBox<T_Type>& a_crInstance1, const CBox<T_OtherType>& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type> operator + (const CBox<T_Type>& a_crInstance)
{ CALL
  return CBox<T_Type>(+a_crInstance.m_A, +a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type> operator - (const CBox<T_Type>& a_crInstance)
{ CALL
  return CBox<T_Type>(-a_crInstance.m_A, -a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBox<T_Type> operator + (const CBox<T_Type>& a_crInstance, const T_OtherType a_cValue)
{ CALL
  return CBox<T_Type>(a_crInstance.m_A + a_cValue, a_crInstance.m_B + a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBox<T_Type> operator + (const CBox<T_Type>& a_crInstance, const CPoint3D<T_OtherType>& a_crPoint)
{ CALL
  return CBox<T_Type>(a_crInstance.m_A + a_crPoint, a_crInstance.m_B + a_crPoint);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBox<T_Type> operator + (const CBox<T_Type>& a_crInstance1, const CBox<T_OtherType>& a_crInstance2)
{ CALL
  return a_crInstance1.getUnion(a_crInstance2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBox<T_Type> operator + (const T_OtherType a_cValue, const CBox<T_Type>& a_crInstance)
{ CALL
  return CBox<T_Type>(a_cValue + a_crInstance.m_A, a_cValue + a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBox<T_Type> operator + (const CPoint3D<T_OtherType>& a_crPoint, const CBox<T_Type>& a_crInstance)
{ CALL
  return CBox<T_Type>(a_crPoint + a_crInstance.m_A, a_crPoint + a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBox<T_Type> operator - (const CBox<T_Type>& a_crInstance, const T_OtherType a_cValue)
{ CALL
  return CBox<T_Type>(a_crInstance.m_A - a_cValue, a_crInstance.m_B - a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBox<T_Type> operator - (const CBox<T_Type>& a_crInstance, const CPoint3D<T_OtherType>& a_crPoint)
{ CALL
  return CBox<T_Type>(a_crInstance.m_A - a_crPoint, a_crInstance.m_B - a_crPoint);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBox<T_Type> operator - (const CBox<T_Type>& a_crInstance1, const CBox<T_OtherType>& a_crInstance2)
{ CALL
  return a_crInstance1.getIntersection(a_crInstance2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBox<T_Type> operator - (const T_OtherType a_cValue, const CBox<T_Type>& a_crInstance)
{ CALL
  return CBox<T_Type>(a_cValue - a_crInstance.m_A, a_cValue - a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CBox<T_Type> operator - (const CPoint3D<T_OtherType>& a_crPoint, const CBox<T_Type>& a_crInstance)
{ CALL
  return CBox<T_Type>(a_crPoint - a_crInstance.m_A, a_crPoint - a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CBox<T_Type>& CBox<T_Type>::operator = (const CBox<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type>& CBox<T_Type>::operator += (const T_Type a_cValue)
{ CALL
  m_A += a_cValue;
  m_B += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type>& CBox<T_Type>::operator += (const CPoint3D<T_Type>& a_crPoint)
{ CALL
  m_A += a_crPoint;
  m_B += a_crPoint;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type>& CBox<T_Type>::operator += (const CBox<T_Type>& a_crInstance)
{ CALL
  *this = getUnion(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type>& CBox<T_Type>::operator -= (const T_Type a_cValue)
{ CALL
  m_A -= a_cValue;
  m_B -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type>& CBox<T_Type>::operator -= (const CPoint3D<T_Type>& a_crPoint)
{ CALL
  m_A -= a_crPoint;
  m_B -= a_crPoint;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type>& CBox<T_Type>::operator -= (const CBox<T_Type>& a_crInstance)
{ CALL
  *this = getIntersection(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBox<T_Type>::set(const T_Type a_cX1, const T_Type a_cY1, const T_Type a_cZ1, const T_Type a_cX2, const T_Type a_cY2, const T_Type a_cZ2)
{ CALL
  m_A.set(a_cX1, a_cY1, a_cZ1);
  m_B.set(a_cX2, a_cY2, a_cZ2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBox<T_Type>::set(const CPoint3D<T_Type>& a_crA, const CPoint3D<T_Type>& a_crB)
{ CALL
  m_A.set(a_crA);
  m_B.set(a_crB);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBox<T_Type>::set(const T_Type a_cpCoordinatesBuffer[])
{ CALL
  // Check if the pointer to the coordinates buffer is not NULL.
  ASSERT((a_cpCoordinatesBuffer != NULL), STR("Pointer to the coordinates buffer should not be NULL."))
  {
    clear();
  }

  m_A.set(a_cpCoordinatesBuffer+0);
  m_B.set(a_cpCoordinatesBuffer+3);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CBox<T_Type>::set(const CBox<T_OtherType>& a_crInstance)
{ CALL
  m_A.set(a_crInstance.m_A);
  m_B.set(a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CBox<T_Type>::isEmpty() const
{ CALL
  return ((m_A.m_X > m_B.m_X) || (m_A.m_Y > m_B.m_Y) || (m_A.m_Z > m_B.m_Z));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CBox<T_Type>::isNormal() const
{ CALL
  return (!isEmpty());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CBox<T_Type>::isInside(const CPoint3D<T_Type>& a_crPoint) const
{ CALL
  CBox<T_Type> normal = getNormal();

  return (((normal.m_A.m_X <= a_crPoint.m_X) && (a_crPoint.m_X <= normal.m_B.m_X)) && ((normal.m_A.m_Y <= a_crPoint.m_Y) && (a_crPoint.m_Y <= normal.m_B.m_Y)) && ((normal.m_A.m_Z <= a_crPoint.m_Z) && (a_crPoint.m_Z <= normal.m_B.m_Z)));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CBox<T_Type>::isInside(const CBox<T_Type>& a_crBox) const
{ CALL
  CBox<T_Type> normal1 = getNormal();
  CBox<T_Type> normal2 = a_crBox.getNormal();

  return (((normal1.m_A.m_X <= normal2.m_A.m_X) && (normal1.m_A.m_Y <= normal2.m_A.m_Y) && (normal1.m_A.m_Z <= normal2.m_A.m_Z)) && ((normal1.m_B.m_X >= normal2.m_B.m_X) && (normal1.m_B.m_Y >= normal2.m_B.m_Y) && (normal1.m_B.m_Z >= normal2.m_B.m_Z)));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CBox<T_Type>::isIntersect(const CBox<T_Type>& a_crBox) const
{ CALL
  CBox<T_Type> normal1 = getNormal();
  CBox<T_Type> normal2 = a_crBox.getNormal();

  return ((NAlgorithms::NCommon::max(normal1.m_A.m_X, normal2.m_A.m_X) <= NAlgorithms::NCommon::min(normal1.m_B.m_X, normal2.m_B.m_X)) && (NAlgorithms::NCommon::max(normal1.m_A.m_Y, normal2.m_A.m_Y) <= NAlgorithms::NCommon::min(normal1.m_B.m_Y, normal2.m_B.m_Y)) && (NAlgorithms::NCommon::max(normal1.m_A.m_Z, normal2.m_A.m_Z) <= NAlgorithms::NCommon::min(normal1.m_B.m_Z, normal2.m_B.m_Z)));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CBox<T_Type>::getWidth() const
{ CALL
  return (m_B.m_X - m_A.m_X);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CBox<T_Type>::getHeight() const
{ CALL
  return (m_B.m_Y - m_A.m_Y);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CBox<T_Type>::getDepth() const
{ CALL
  return (m_B.m_Z - m_A.m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type> CBox<T_Type>::getEmpty() const
{ CALL
  CBox<T_Type> result(*this);

  NAlgorithms::NCommon::minMax(result.m_B.m_X, result.m_A.m_X);
  NAlgorithms::NCommon::minMax(result.m_B.m_Y, result.m_A.m_Y);
  NAlgorithms::NCommon::minMax(result.m_B.m_Z, result.m_A.m_Z);
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type> CBox<T_Type>::getNormal() const
{ CALL
  CBox<T_Type> result(*this);

  NAlgorithms::NCommon::minMax(result.m_A.m_X, result.m_B.m_X);
  NAlgorithms::NCommon::minMax(result.m_A.m_Y, result.m_B.m_Y);
  NAlgorithms::NCommon::minMax(result.m_A.m_Z, result.m_B.m_Z);
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type> CBox<T_Type>::getIntersection(const CBox<T_Type>& a_crBox) const
{ CALL
  CBox<T_Type> normal1 = getNormal();
  CBox<T_Type> normal2 = a_crBox.getNormal();

  return CBox<T_Type>(NAlgorithms::NCommon::max(normal1.m_A.m_X, normal2.m_A.m_X), NAlgorithms::NCommon::max(normal1.m_A.m_Y, normal2.m_A.m_Y), NAlgorithms::NCommon::max(normal1.m_A.m_Z, normal2.m_A.m_Z), NAlgorithms::NCommon::min(normal1.m_B.m_X, normal2.m_B.m_X), NAlgorithms::NCommon::min(normal1.m_B.m_Y, normal2.m_B.m_Y), NAlgorithms::NCommon::min(normal1.m_B.m_Z, normal2.m_B.m_Z));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type> CBox<T_Type>::getUnion(const CPoint3D<T_Type>& a_crPoint) const
{ CALL
  CBox<T_Type> normal = getNormal();

  return CBox<T_Type>(NAlgorithms::NCommon::min(normal.m_A.m_X, a_crPoint.m_X), NAlgorithms::NCommon::min(normal.m_A.m_Y, a_crPoint.m_Y), NAlgorithms::NCommon::min(normal.m_A.m_Z, a_crPoint.m_Z), NAlgorithms::NCommon::max(normal.m_B.m_X, a_crPoint.m_X), NAlgorithms::NCommon::max(normal.m_B.m_Y, a_crPoint.m_Y), NAlgorithms::NCommon::max(normal.m_B.m_Z, a_crPoint.m_Z));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CBox<T_Type> CBox<T_Type>::getUnion(const CBox<T_Type>& a_crBox) const
{ CALL
  CBox<T_Type> normal1 = getNormal();
  CBox<T_Type> normal2 = a_crBox.getNormal();

  return CBox<T_Type>(NAlgorithms::NCommon::min(normal1.m_A.m_X, normal2.m_A.m_X), NAlgorithms::NCommon::min(normal1.m_A.m_Y, normal2.m_A.m_Y), NAlgorithms::NCommon::min(normal1.m_A.m_Z, normal2.m_A.m_Z), NAlgorithms::NCommon::max(normal1.m_B.m_X, normal2.m_B.m_X), NAlgorithms::NCommon::max(normal1.m_B.m_Y, normal2.m_B.m_Y), NAlgorithms::NCommon::max(normal1.m_B.m_Z, normal2.m_B.m_Z));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBox<T_Type>::clear()
{ CALL
  m_A.clear();
  m_B.clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBox<T_Type>::inverse()
{ CALL
  NAlgorithms::NCommon::swap(m_A, m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBox<T_Type>::moveBy(const CPoint3D<T_Type>& a_crPoint)
{ CALL
  m_A += a_crPoint;
  m_B += a_crPoint;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBox<T_Type>::moveTo(const CPoint3D<T_Type>& a_crPoint)
{ CALL
  m_B -= m_A;
  m_A.set(a_crPoint);
  m_B += m_A;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CBox<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CBox<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_A, STR("m_A")));
    CHECK(a_rArchive.doValue(m_B, STR("m_B")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CBox<T_Type>::swap(CBox<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_A, a_rInstance.m_A);
  NAlgorithms::NCommon::swap(m_B, a_rInstance.m_B);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
