/*!
 *  \file    CPoint3D.inl Template representation of the point in a space.
 *  \brief   Point in a space template class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Point in a space template class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   09.02.2006 00:00:32

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
#ifndef __CPOINT3D_INL__
#define __CPOINT3D_INL__
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
inline CPoint3D<T_Type>::CPoint3D() :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>::CPoint3D(const T_Type a_cX, const T_Type a_cY, const T_Type a_cZ) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_cX, a_cY, a_cZ);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>::CPoint3D(const T_Type a_cpCoordinatesBuffer[]) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_cpCoordinatesBuffer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CPoint3D<T_Type>::CPoint3D(const CPoint2D<T_OtherType>& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CPoint3D<T_Type>::CPoint3D(const CPoint3D<T_OtherType>& a_crInstance) :
  m_X(),
  m_Y(),
  m_Z()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>::~CPoint3D()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator == (const CPoint3D<T_Type>& a_crInstance1, const CPoint3D<T_OtherType>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_X == a_crInstance2.m_X) && (a_crInstance1.m_Y == a_crInstance2.m_Y) && (a_crInstance1.m_Z == a_crInstance2.m_Z));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline Tbool operator != (const CPoint3D<T_Type>& a_crInstance1, const CPoint3D<T_OtherType>& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type> operator + (const CPoint3D<T_Type>& a_crInstance)
{ CALL
  return CPoint3D<T_Type>(+a_crInstance.m_X, +a_crInstance.m_Y, +a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type> operator - (const CPoint3D<T_Type>& a_crInstance)
{ CALL
  return CPoint3D<T_Type>(-a_crInstance.m_X, -a_crInstance.m_Y, -a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator + (const CPoint3D<T_Type>& a_crInstance, const T_OtherType a_cValue)
{ CALL
  return CPoint3D<T_Type>(a_crInstance.m_X + a_cValue, a_crInstance.m_Y + a_cValue, a_crInstance.m_Z + a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator + (const CPoint3D<T_Type>& a_crInstance1, const CPoint3D<T_OtherType>& a_crInstance2)
{ CALL
  return CPoint3D<T_Type>(a_crInstance1.m_X + a_crInstance2.m_X, a_crInstance1.m_Y + a_crInstance2.m_Y, a_crInstance1.m_Z + a_crInstance2.m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator + (const T_OtherType a_cValue, const CPoint3D<T_Type>& a_crInstance)
{ CALL
  return CPoint3D<T_Type>(a_cValue + a_crInstance.m_X, a_cValue + a_crInstance.m_Y, a_cValue + a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator - (const CPoint3D<T_Type>& a_crInstance, const T_OtherType a_cValue)
{ CALL
  return CPoint3D<T_Type>(a_crInstance.m_X - a_cValue, a_crInstance.m_Y - a_cValue, a_crInstance.m_Z - a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator - (const CPoint3D<T_Type>& a_crInstance1, const CPoint3D<T_OtherType>& a_crInstance2)
{ CALL
  return CPoint3D<T_Type>(a_crInstance1.m_X - a_crInstance2.m_X, a_crInstance1.m_Y - a_crInstance2.m_Y, a_crInstance1.m_Z - a_crInstance2.m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator - (const T_OtherType a_cValue, const CPoint3D<T_Type>& a_crInstance)
{ CALL
  return CPoint3D<T_Type>(a_cValue - a_crInstance.m_X, a_cValue - a_crInstance.m_Y, a_cValue - a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator * (const CPoint3D<T_Type>& a_crInstance, const T_OtherType a_cValue)
{ CALL
  return CPoint3D<T_Type>(a_crInstance.m_X * a_cValue, a_crInstance.m_Y * a_cValue, a_crInstance.m_Z * a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator * (const CPoint3D<T_Type>& a_crInstance1, const CPoint3D<T_OtherType>& a_crInstance2)
{ CALL
  return CPoint3D<T_Type>(a_crInstance1.m_X * a_crInstance2.m_X, a_crInstance1.m_Y * a_crInstance2.m_Y, a_crInstance1.m_Z * a_crInstance2.m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator * (const T_OtherType a_cValue, const CPoint3D<T_Type>& a_crInstance)
{ CALL
  return CPoint3D<T_Type>(a_cValue * a_crInstance.m_X, a_cValue * a_crInstance.m_Y, a_cValue * a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator / (const CPoint3D<T_Type>& a_crInstance, const T_OtherType a_cValue)
{ CALL
  return CPoint3D<T_Type>(a_crInstance.m_X / a_cValue, a_crInstance.m_Y / a_cValue, a_crInstance.m_Z / a_cValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator / (const CPoint3D<T_Type>& a_crInstance1, const CPoint3D<T_OtherType>& a_crInstance2)
{ CALL
  return CPoint3D<T_Type>(a_crInstance1.m_X / a_crInstance2.m_X, a_crInstance1.m_Y / a_crInstance2.m_Y, a_crInstance1.m_Z / a_crInstance2.m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_OtherType>
inline CPoint3D<T_Type> operator / (const T_OtherType a_cValue, const CPoint3D<T_Type>& a_crInstance)
{ CALL
  return CPoint3D<T_Type>(a_cValue / a_crInstance.m_X, a_cValue / a_crInstance.m_Y, a_cValue / a_crInstance.m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>& CPoint3D<T_Type>::operator = (const T_Type a_cValue)
{ CALL
  set(a_cValue, a_cValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CPoint3D<T_Type>& CPoint3D<T_Type>::operator = (const CPoint2D<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline CPoint3D<T_Type>& CPoint3D<T_Type>::operator = (const CPoint3D<T_OtherType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>& CPoint3D<T_Type>::operator += (const T_Type a_cValue)
{ CALL
  m_X += a_cValue;
  m_Y += a_cValue;
  m_Z += a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>& CPoint3D<T_Type>::operator += (const CPoint3D<T_Type>& a_crInstance)
{ CALL
  m_X += a_crInstance.m_X;
  m_Y += a_crInstance.m_Y;
  m_Z += a_crInstance.m_Z;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>& CPoint3D<T_Type>::operator -= (const T_Type a_cValue)
{ CALL
  m_X -= a_cValue;
  m_Y -= a_cValue;
  m_Z -= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>& CPoint3D<T_Type>::operator -= (const CPoint3D<T_Type>& a_crInstance)
{ CALL
  m_X -= a_crInstance.m_X;
  m_Y -= a_crInstance.m_Y;
  m_Z -= a_crInstance.m_Z;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>& CPoint3D<T_Type>::operator *= (const T_Type a_cValue)
{ CALL
  m_X *= a_cValue;
  m_Y *= a_cValue;
  m_Z *= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>& CPoint3D<T_Type>::operator *= (const CPoint3D<T_Type>& a_crInstance)
{ CALL
  m_X *= a_crInstance.m_X;
  m_Y *= a_crInstance.m_Y;
  m_Z *= a_crInstance.m_Z;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>& CPoint3D<T_Type>::operator /= (const T_Type a_cValue)
{ CALL
  m_X /= a_cValue;
  m_Y /= a_cValue;
  m_Z /= a_cValue;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPoint3D<T_Type>& CPoint3D<T_Type>::operator /= (const CPoint3D<T_Type>& a_crInstance)
{ CALL
  m_X /= a_crInstance.m_X;
  m_Y /= a_crInstance.m_Y;
  m_Z /= a_crInstance.m_Z;
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPoint3D<T_Type>::set(const T_Type a_cX, const T_Type a_cY, const T_Type a_cZ)
{ CALL
  m_X = a_cX;
  m_Y = a_cY;
  m_Z = a_cZ;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPoint3D<T_Type>::set(const T_Type a_cpCoordinatesBuffer[])
{ CALL
  // Check if the pointer to the coordinates buffer is not NULL.
  ASSERT((a_cpCoordinatesBuffer != NULL), STR("Pointer to the coordinates buffer should not be NULL."))
  {
    clear();
  }

  m_X = a_cpCoordinatesBuffer[0];
  m_Y = a_cpCoordinatesBuffer[1];
  m_Z = a_cpCoordinatesBuffer[2];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CPoint3D<T_Type>::set(const CPoint2D<T_OtherType>& a_crInstance)
{ CALL
  m_X = (T_Type)a_crInstance.m_X;
  m_Y = (T_Type)a_crInstance.m_Y;
  m_Z = (T_Type)0;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <typename T_OtherType>
inline void CPoint3D<T_Type>::set(const CPoint3D<T_OtherType>& a_crInstance)
{ CALL
  m_X = (T_Type)a_crInstance.m_X;
  m_Y = (T_Type)a_crInstance.m_Y;
  m_Z = (T_Type)a_crInstance.m_Z;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPoint3D<T_Type>::clear()
{ CALL
  m_X = (T_Type)0;
  m_Y = (T_Type)0;
  m_Z = (T_Type)0;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPoint3D<T_Type>::absolute()
{ CALL
  m_X = NAlgorithms::NNumeric::absolute(m_X);
  m_Y = NAlgorithms::NNumeric::absolute(m_Y);
  m_Z = NAlgorithms::NNumeric::absolute(m_Z);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPoint3D<T_Type>::negate()
{ CALL
  m_X = -m_X;
  m_Y = -m_Y;
  m_Z = -m_Z;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CPoint3D<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NGeometry::CPoint3D<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_X, STR("m_X")));
    CHECK(a_rArchive.doValue(m_Y, STR("m_Y")));
    CHECK(a_rArchive.doValue(m_Z, STR("m_Z")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPoint3D<T_Type>::swap(CPoint3D<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_X, a_rInstance.m_X);
  NAlgorithms::NCommon::swap(m_Y, a_rInstance.m_Y);
  NAlgorithms::NCommon::swap(m_Z, a_rInstance.m_Z);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
