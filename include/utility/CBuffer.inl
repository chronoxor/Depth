/*!
 *  \file    CBuffer.inl Byte buffer container class provides random access
 *           to the static/dynamic byte buffer.
 *  \brief   Byte buffer container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Byte buffer container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   20.08.2008 23:35:51

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
#ifndef __CBUFFER_INL__
#define __CBUFFER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CBuffer::CBuffer(const Tuint a_cSize/* = 0 */, const Tbool a_cStatic/* = false */) :
  NCommon::NContainers::IRandom<CBuffer, Tbyte, CBufferIterator, CBufferIteratorConst>(),
  NCommon::NContainers::IRandomConst<CBuffer, Tbyte, CBufferIterator, CBufferIteratorConst>(),
  m_IsDynamic(false),
  m_IsLocal(false),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cSize, a_cStatic);
}
/*--------------------------------------------------------------------------*/
inline CBuffer::CBuffer(Tcbuffer a_cpBuffer, const Tuint a_cSize, const Tbool a_cStatic/* = false */) :
  NCommon::NContainers::IRandom<CBuffer, Tbyte, CBufferIterator, CBufferIteratorConst>(),
  NCommon::NContainers::IRandomConst<CBuffer, Tbyte, CBufferIterator, CBufferIteratorConst>(),
  m_IsDynamic(false),
  m_IsLocal(false),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cpBuffer, a_cSize, a_cStatic);
}
/*--------------------------------------------------------------------------*/
inline CBuffer::CBuffer(Tbuffer a_pBuffer, const Tuint a_cSize, const Tbool a_cStatic/* = true */) :
  NCommon::NContainers::IRandom<CBuffer, Tbyte, CBufferIterator, CBufferIteratorConst>(),
  NCommon::NContainers::IRandomConst<CBuffer, Tbyte, CBufferIterator, CBufferIteratorConst>(),
  m_IsDynamic(false),
  m_IsLocal(false),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_pBuffer, a_cSize, a_cStatic);
}
/*--------------------------------------------------------------------------*/
inline CBuffer::CBuffer(const CBuffer& a_crInstance) :
  NCommon::NContainers::IRandom<CBuffer, Tbyte, CBufferIterator, CBufferIteratorConst>(),
  NCommon::NContainers::IRandomConst<CBuffer, Tbyte, CBufferIterator, CBufferIteratorConst>(),
  m_IsDynamic(false),
  m_IsLocal(false),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CBuffer::~CBuffer()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
inline CBuffer& CBuffer::operator = (const CBuffer& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbyte& CBuffer::operator [] (const Tsint a_cIndex)
{ CALL
  // Verify index value and the byte buffer bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the single byte of the byte buffer with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline Tbyte& CBuffer::operator [] (const Tuint a_cIndex)
{ CALL
  // Verify index value and the byte buffer bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the single byte of the byte buffer with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline const Tbyte& CBuffer::operator [] (const Tsint a_cIndex) const
{ CALL
  // Verify index value and the byte buffer bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the single byte of the byte buffer with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline const Tbyte& CBuffer::operator [] (const Tuint a_cIndex) const
{ CALL
  // Verify index value and the byte buffer bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the single byte of the byte buffer with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline CBuffer::operator Tbuffer ()
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline CBuffer::operator Tcbuffer () const
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::isDynamic() const
{ CALL
  return m_IsDynamic;
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::isLocal() const
{ CALL
  return m_IsLocal;
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::isStatic() const
{ CALL
  return !m_IsDynamic;
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pBuffer == NULL));
}
/*--------------------------------------------------------------------------*/
inline Tuint CBuffer::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
inline Tuint CBuffer::getFreeSize() const
{ CALL
  return (getHiCapacity() - getSize());
}
/*--------------------------------------------------------------------------*/
inline Tuint CBuffer::getLoCapacity() const
{ CALL
  return (isDynamic() ? (m_HiCapacity >> 1) : 0);
}
/*--------------------------------------------------------------------------*/
inline Tuint CBuffer::getHiCapacity() const
{ CALL
  return m_HiCapacity;
}
/*--------------------------------------------------------------------------*/
inline Tbuffer CBuffer::getBuffer()
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline Tcbuffer CBuffer::getBuffer() const
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::insertFirst(const Tbyte& a_crItem)
{ CALL
  return insertIndex(0, a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::insertFirst(const CBuffer& a_crItem)
{ CALL
  return insertIndex(0, a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::insertLast(const Tbyte& a_crItem)
{ CALL
  return insertIndex(getSize(), a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::insertLast(const CBuffer& a_crItem)
{ CALL
  return insertIndex(getSize(), a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::removeFirst()
{ CALL
  return removeIndex(0);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::removeFirst(Tbyte& a_rItem)
{ CALL
  return removeIndex(0, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::removeFirst(const Tuint a_cSize)
{ CALL
  return removeIndex(0, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::removeFirst(const Tuint a_cSize, CBuffer& a_rItem)
{ CALL
  return removeIndex(0, a_cSize, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::removeLast()
{ CALL
  return removeIndex(getSize() - 1);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::removeLast(Tbyte& a_rItem)
{ CALL
  return removeIndex(getSize() - 1, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::removeLast(const Tuint a_cSize)
{ CALL
  return removeIndex(getSize() - 1, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::removeLast(const Tuint a_cSize, CBuffer& a_rItem)
{ CALL
  return removeIndex(getSize() - 1, a_cSize, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  return removeIndex(a_cIndex, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBuffer::resizeBy(const Tsint a_cSize, const Tbyte a_cValue/* = 0 */)
{ CALL
  return resize((((a_cSize < 0) && (m_Size < (Tuint)-a_cSize)) ? 0 : (m_Size + a_cSize)), a_cValue);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CBuffer::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tbool dynamic = false;
  Tuint size = 0;

  // Clear the current byte buffer.
  CHECK(clear());

  // Load the byte buffer header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::CBuffer")));
    CHECK(a_rArchive.doProperty(dynamic, STR("dynamic")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Set the dynamic and local flags.
  m_IsDynamic = dynamic;
  m_IsLocal = true;

  // Try to resize the byte buffer.
  CHECK(resize(size));

  // Load the byte buffer content.
  if (size > 0)
  {
    CHECK(a_rArchive.doValue(m_pBuffer, size, STR("m_pBuffer")));
  }

  // Load the byte buffer end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CBuffer::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the byte buffer header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::CBuffer")));
    CHECK(a_rArchive.doProperty(m_IsDynamic, STR("dynamic")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the byte buffer content.
  if (!isEmpty())
  {
    CHECK(a_rArchive.doValue(m_pBuffer, m_Size, STR("m_pBuffer")));
  }

  // Save the byte buffer end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CBuffer::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void CBuffer::swap(CBuffer& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_IsDynamic, a_rInstance.m_IsDynamic);
  NAlgorithms::NCommon::swap(m_IsLocal, a_rInstance.m_IsLocal);
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_HiCapacity, a_rInstance.m_HiCapacity);
  NAlgorithms::NCommon::swap(m_pBuffer, a_rInstance.m_pBuffer);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
