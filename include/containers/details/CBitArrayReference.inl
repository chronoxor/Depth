/*!
 *  \file    CBitArrayReference.inl Template bit array reference class. Bit
 *           array reference class emulates operations with a single bit of
 *           a bit array
 *  \brief   Bit array reference class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bit array reference class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers details
    VERSION:   1.0
    CREATED:   07.06.2006 23:25:27

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
#ifndef __CBITARRAYREFERENCE_INL__
#define __CBITARRAYREFERENCE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::CBitArrayReference(Tbuffer a_pBytePtr, const Tuint a_cBitMask) :
  m_BitMask(a_cBitMask),
  m_pBytePtr(a_pBytePtr)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::~CBitArrayReference()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator == (const CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return (Tbool(a_crInstance1) == Tbool(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator != (const CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return (Tbool(a_crInstance1) != Tbool(a_crInstance2));
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const Tbool a_cValue)
{ CALL
  set(a_cValue);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator Tbool () const
{ CALL
  // Verify the bit array reference to be the valid one.
  VERIFY((m_pBytePtr != NULL), STR("Cannot get boolean value from the invalid bit array reference."));

  return !!(*m_pBytePtr & m_BitMask);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator ! () const
{ CALL
  // Verify the bit array reference to be the valid one.
  VERIFY((m_pBytePtr != NULL), STR("Cannot inverse boolean value of the invalid bit array reference."));

  return !(*m_pBytePtr & m_BitMask);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const Tbool a_cValue)
{ CALL
  // Verify the bit array reference to be the valid one.
  VERIFY((m_pBytePtr != NULL), STR("Cannot set boolean value of the invalid bit array reference."));

  if (a_cValue)
    *m_pBytePtr |= m_BitMask;
  else
    *m_pBytePtr &= ~m_BitMask;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  operator = (Tbool(a_crInstance));
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::getValue() const
{ CALL
  return Tbool(*this);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::flip()
{ CALL
  // Verify the bit array reference to be the valid one.
  VERIFY((m_pBytePtr != NULL), STR("Cannot flip value of the invalid bit array reference."));

  *m_pBytePtr ^= m_BitMask;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Verify the bit array reference to be the valid one.
  VERIFY((m_pBytePtr != NULL), STR("Cannot load the invalid bit array reference."));

  Tuint mask;
  Tbool value;

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(mask, STR("m_BitMask")));
    CHECK(a_rArchive.doValue(value, STR("m_pBytePtr")));
  CHECK(a_rArchive.end());
  m_BitMask = mask;
  set(value);
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Verify the bit array reference to be the valid one.
  VERIFY((m_pBytePtr != NULL), STR("Cannot save the invalid bit array reference."));

  Tuint mask = m_BitMask;
  Tbool value = getValue();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NDetails::CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(mask, STR("m_BitMask")));
    CHECK(a_rArchive.doValue(value, STR("m_pBytePtr")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>::swap(CBitArrayReference<T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_BitMask, a_rInstance.m_BitMask);
  NAlgorithms::NCommon::swap(m_pBytePtr, a_rInstance.m_pBytePtr);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
