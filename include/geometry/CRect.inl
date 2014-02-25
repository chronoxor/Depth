/*!
 *  \file    CRect.inl Template representation of the rectangle on a plane.
 *  \brief   Rectangle on a plane template class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Rectangle on a plane template class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   10.02.2006 21:10:32

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
#ifndef __CRECT_INL__
#define __CRECT_INL__
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
inline CRect<T_Type>::CRect() :
  m_A(),
  m_B()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type>::CRect(const T_Type a_cX1, const T_Type a_cY1, const T_Type a_cX2, const T_Type a_cY2) :
  m_A(),
  m_B()
{ CALL
  set(a_cX1, a_cY1, a_cX2, a_cY2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type>::CRect(const CPoint2D<T_Type>& a_crA, const CPoint2D<T_Type>& a_crB) :
  m_A(),
  m_B()
{ CALL
  set(a_crA, a_crB);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type>::CRect(const T_Type a_cpCoordinatesBuffer[]) :
  m_A(),
  m_B()
{ CALL
  set(a_cpCoordinatesBuffer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CRect<T_Type>::CRect(const CRect<T_OtherType>& a_crInstance) :
  m_A(),
  m_B()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type>::~CRect()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator == (const CRect<T_Type>& a_crInstance1, const CRect<T_OtherType>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_A == a_crInstance2.m_A) && (a_crInstance1.m_B == a_crInstance2.m_B));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator != (const CRect<T_Type>& a_crInstance1, const CRect<T_OtherType>& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type> operator + (const CRect<T_Type>& a_crInstance)
{ CALL
  return CRect<T_Type>(+a_crInstance.m_A, +a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type> operator - (const CRect<T_Type>& a_crInstance)
{ CALL
  return CRect<T_Type>(-a_crInstance.m_A, -a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CRect<T_Type> operator + (const CRect<T_Type>& a_crInstance, const T_OtherType a_cValue)
{ CALL
  return CRect<T_Type>(a_crInstance.m_A + a_cValue, a_crInstance.m_B + a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CRect<T_Type> operator + (const CRect<T_Type>& a_crInstance, const CPoint2D<T_OtherType>& a_crPoint)
{ CALL
  return CRect<T_Type>(a_crInstance.m_A + a_crPoint, a_crInstance.m_B + a_crPoint);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CRect<T_Type> operator + (const CRect<T_Type>& a_crInstance1, const CRect<T_OtherType>& a_crInstance2)
{ CALL
  return a_crInstance1.getUnion(a_crInstance2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CRect<T_Type> operator + (const T_OtherType a_cValue, const CRect<T_Type>& a_crInstance)
{ CALL
  return CRect<T_Type>(a_cValue + a_crInstance.m_A, a_cValue + a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CRect<T_Type> operator + (const CPoint2D<T_OtherType>& a_crPoint, const CRect<T_Type>& a_crInstance)
{ CALL
  return CRect<T_Type>(a_crPoint + a_crInstance.m_A, a_crPoint + a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CRect<T_Type> operator - (const CRect<T_Type>& a_crInstance, const T_OtherType a_cValue)
{ CALL
  return CRect<T_Type>(a_crInstance.m_A - a_cValue, a_crInstance.m_B - a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CRect<T_Type> operator - (const CRect<T_Type>& a_crInstance, const CPoint2D<T_OtherType>& a_crPoint)
{ CALL
  return CRect<T_Type>(a_crInstance.m_A - a_crPoint, a_crInstance.m_B - a_crPoint);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CRect<T_Type> operator - (const CRect<T_Type>& a_crInstance1, const CRect<T_OtherType>& a_crInstance2)
{ CALL
  return a_crInstance1.getIntersection(a_crInstance2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CRect<T_Type> operator - (const T_OtherType a_cValue, const CRect<T_Type>& a_crInstance)
{ CALL
  return CRect<T_Type>(a_cValue - a_crInstance.m_A, a_cValue - a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CRect<T_Type> operator - (const CPoint2D<T_OtherType>& a_crPoint, const CRect<T_Type>& a_crInstance)
{ CALL
  return CRect<T_Type>(a_crPoint - a_crInstance.m_A, a_crPoint - a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CRect<T_Type>& CRect<T_Type>::operator = (const CRect<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type>& CRect<T_Type>::operator += (const T_Type a_cValue)
{ CALL
  m_A += a_cValue;
  m_B += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type>& CRect<T_Type>::operator += (const CPoint2D<T_Type>& a_crPoint)
{ CALL
  m_A += a_crPoint;
  m_B += a_crPoint;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type>& CRect<T_Type>::operator += (const CRect<T_Type>& a_crInstance)
{ CALL
  *this = getUnion(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type>& CRect<T_Type>::operator -= (const T_Type a_cValue)
{ CALL
  m_A -= a_cValue;
  m_B -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type>& CRect<T_Type>::operator -= (const CPoint2D<T_Type>& a_crPoint)
{ CALL
  m_A -= a_crPoint;
  m_B -= a_crPoint;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type>& CRect<T_Type>::operator -= (const CRect<T_Type>& a_crInstance)
{ CALL
  *this = getIntersection(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CRect<T_Type>::set(const T_Type a_cX1, const T_Type a_cY1, const T_Type a_cX2, const T_Type a_cY2)
{ CALL
  m_A.set(a_cX1, a_cY1);
  m_B.set(a_cX2, a_cY2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CRect<T_Type>::set(const CPoint2D<T_Type>& a_crA, const CPoint2D<T_Type>& a_crB)
{ CALL
  m_A.set(a_crA);
  m_B.set(a_crB);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CRect<T_Type>::set(const T_Type a_cpCoordinatesBuffer[])
{ CALL
  // Check if the pointer to the coordinates buffer is not NULL.
  ASSERT((a_cpCoordinatesBuffer != NULL), STR("Pointer to the coordinates buffer should not be NULL."))
  {
    clear();
  }

  m_A.set(a_cpCoordinatesBuffer+0);
  m_B.set(a_cpCoordinatesBuffer+2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CRect<T_Type>::set(const CRect<T_OtherType>& a_crInstance)
{ CALL
  m_A.set(a_crInstance.m_A);
  m_B.set(a_crInstance.m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CRect<T_Type>::isEmpty() const
{ CALL
  return ((m_A.m_X > m_B.m_X) || (m_A.m_Y > m_B.m_Y));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CRect<T_Type>::isNormal() const
{ CALL
  return (!isEmpty());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CRect<T_Type>::isInside(const CPoint2D<T_Type>& a_crPoint) const
{ CALL
  CRect<T_Type> normal = getNormal();

  return (((normal.m_A.m_X <= a_crPoint.m_X) && (a_crPoint.m_X <= normal.m_B.m_X)) && ((normal.m_A.m_Y <= a_crPoint.m_Y) && (a_crPoint.m_Y <= normal.m_B.m_Y)));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CRect<T_Type>::isInside(const CRect<T_Type>& a_crRect) const
{ CALL
  CRect<T_Type> normal1 = getNormal();
  CRect<T_Type> normal2 = a_crRect.getNormal();

  return (((normal1.m_A.m_X <= normal2.m_A.m_X) && (normal1.m_A.m_Y <= normal2.m_A.m_Y)) && ((normal1.m_B.m_X >= normal2.m_B.m_X) && (normal1.m_B.m_Y >= normal2.m_B.m_Y)));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CRect<T_Type>::isIntersect(const CRect<T_Type>& a_crRect) const
{ CALL
  CRect<T_Type> normal1 = getNormal();
  CRect<T_Type> normal2 = a_crRect.getNormal();

  return ((NAlgorithms::NCommon::max(normal1.m_A.m_X, normal2.m_A.m_X) <= NAlgorithms::NCommon::min(normal1.m_B.m_X, normal2.m_B.m_X)) && (NAlgorithms::NCommon::max(normal1.m_A.m_Y, normal2.m_A.m_Y) <= NAlgorithms::NCommon::min(normal1.m_B.m_Y, normal2.m_B.m_Y)));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CRect<T_Type>::getWidth() const
{ CALL
  return (m_B.m_X - m_A.m_X);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type CRect<T_Type>::getHeight() const
{ CALL
  return (m_B.m_Y - m_A.m_Y);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type> CRect<T_Type>::getEmpty() const
{ CALL
  CRect<T_Type> result(*this);

  NAlgorithms::NCommon::minMax(result.m_B.m_X, result.m_A.m_X);
  NAlgorithms::NCommon::minMax(result.m_B.m_Y, result.m_A.m_Y);
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type> CRect<T_Type>::getNormal() const
{ CALL
  CRect<T_Type> result(*this);

  NAlgorithms::NCommon::minMax(result.m_A.m_X, result.m_B.m_X);
  NAlgorithms::NCommon::minMax(result.m_A.m_Y, result.m_B.m_Y);
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type> CRect<T_Type>::getIntersection(const CRect<T_Type>& a_crRect) const
{ CALL
  CRect<T_Type> normal1 = getNormal();
  CRect<T_Type> normal2 = a_crRect.getNormal();

  return CRect<T_Type>(NAlgorithms::NCommon::max(normal1.m_A.m_X, normal2.m_A.m_X), NAlgorithms::NCommon::max(normal1.m_A.m_Y, normal2.m_A.m_Y), NAlgorithms::NCommon::min(normal1.m_B.m_X, normal2.m_B.m_X), NAlgorithms::NCommon::min(normal1.m_B.m_Y, normal2.m_B.m_Y));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type> CRect<T_Type>::getUnion(const CPoint2D<T_Type>& a_crPoint) const
{ CALL
  CRect<T_Type> normal = getNormal();

  return CRect<T_Type>(NAlgorithms::NCommon::min(normal.m_A.m_X, a_crPoint.m_X), NAlgorithms::NCommon::min(normal.m_A.m_Y, a_crPoint.m_Y), NAlgorithms::NCommon::max(normal.m_B.m_X, a_crPoint.m_X), NAlgorithms::NCommon::max(normal.m_B.m_Y, a_crPoint.m_Y));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type> CRect<T_Type>::getUnion(const CRect<T_Type>& a_crRect) const
{ CALL
  CRect<T_Type> normal1 = getNormal();
  CRect<T_Type> normal2 = a_crRect.getNormal();

  return CRect<T_Type>(NAlgorithms::NCommon::min(normal1.m_A.m_X, normal2.m_A.m_X), NAlgorithms::NCommon::min(normal1.m_A.m_Y, normal2.m_A.m_Y), NAlgorithms::NCommon::max(normal1.m_B.m_X, normal2.m_B.m_X), NAlgorithms::NCommon::max(normal1.m_B.m_Y, normal2.m_B.m_Y));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CRect<T_Type>::clear()
{ CALL
  m_A.clear();
  m_B.clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CRect<T_Type>::inverse()
{ CALL
  NAlgorithms::NCommon::swap(m_A, m_B);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CRect<T_Type>::moveBy(const CPoint2D<T_Type>& a_crPoint)
{ CALL
  m_A += a_crPoint;
  m_B += a_crPoint;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CRect<T_Type>::moveTo(const CPoint2D<T_Type>& a_crPoint)
{ CALL
  m_B -= m_A;
  m_A.set(a_crPoint);
  m_B += m_A;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CRect<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CRect<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_A, STR("m_A")));
    CHECK(a_rArchive.doValue(m_B, STR("m_B")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CRect<T_Type>::swap(CRect<T_Type>& a_rInstance)
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
