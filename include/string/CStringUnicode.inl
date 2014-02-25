/*!
 *  \file    CStringUnicode.inl Unicode string class provides base string
 *           functionality in the Unicode encoding.
 *  \brief   Unicode string class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode string class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   02.08.2008 21:36:34

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
#ifndef __CSTRINGUNICODE_INL__
#define __CSTRINGUNICODE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CStringUnicode::CStringUnicode(const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IRandom<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  if (a_cAppendZero)
    set(STR('\0'));
  else
    clear();
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::CStringUnicode(const Tschar a_cASCIICharacter, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IRandom<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cASCIICharacter, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::CStringUnicode(const Twchar a_cUnicodeCharacter, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IRandom<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cUnicodeCharacter, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::CStringUnicode(Tcsstr a_cpASCIIString, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IRandom<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cpASCIIString, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::CStringUnicode(Tcwstr a_cpUnicodeString, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IRandom<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cpUnicodeString, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::CStringUnicode(Tcsstr a_cpBuffer, const Tuint a_cSize) :
  NCommon::NContainers::IRandom<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::CStringUnicode(Tcwstr a_cpBuffer, const Tuint a_cSize) :
  NCommon::NContainers::IRandom<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::CStringUnicode(const CSystemString& a_crInstance) :
  NCommon::NContainers::IRandom<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::CStringUnicode(const CStringASCII& a_crInstance) :
  NCommon::NContainers::IRandom<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::CStringUnicode(const CStringUnicode& a_crInstance) :
  NCommon::NContainers::IRandom<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::~CStringUnicode()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2)
{ CALL
  return CStringUnicode::compare(a_crInstance1, a_crInstance2) < 0;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2)
{ CALL
  return CStringUnicode::compare(a_crInstance1, a_crInstance2) > 0;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2)
{ CALL
  return CStringUnicode::compare(a_crInstance1, a_crInstance2) <= 0;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2)
{ CALL
  return CStringUnicode::compare(a_crInstance1, a_crInstance2) >= 0;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CStringUnicode operator + (const CStringUnicode& a_crInstance, const CStringUnicode& a_crString)
{ CALL
  CStringUnicode result(a_crInstance);
  result.insertLast(a_crString);
  return result;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode& CStringUnicode::operator = (const Tschar a_cASCIICharacter)
{ CALL
  set(a_cASCIICharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode& CStringUnicode::operator = (const Twchar a_cUnicodeCharacter)
{ CALL
  set(a_cUnicodeCharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode& CStringUnicode::operator = (Tcsstr a_cpASCIIString)
{ CALL
  set(a_cpASCIIString);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode& CStringUnicode::operator = (Tcwstr a_cpUnicodeString)
{ CALL
  set(a_cpUnicodeString);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode& CStringUnicode::operator = (const CSystemString& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode& CStringUnicode::operator = (const CStringASCII& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode& CStringUnicode::operator = (const CStringUnicode& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode& CStringUnicode::operator += (const CStringUnicode& a_crString)
{ CALL
  insertLast(a_crString);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Twchar& CStringUnicode::operator [] (const Tsint a_cIndex)
{ CALL
  // Verify index value and the Unicode string bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the single character of the Unicode string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline Twchar& CStringUnicode::operator [] (const Tuint a_cIndex)
{ CALL
  // Verify index value and the Unicode string bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the single character of the Unicode string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline const Twchar& CStringUnicode::operator [] (const Tsint a_cIndex) const
{ CALL
  // Verify index value and the Unicode string bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the single character of the Unicode string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline const Twchar& CStringUnicode::operator [] (const Tuint a_cIndex) const
{ CALL
  // Verify index value and the Unicode string bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the single character of the Unicode string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::operator Twstr ()
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::operator Tcwstr () const
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicode::operator CSystemString () const
{ CALL
  CSystemString result;
  getSystemString(result);
  return result;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pBuffer == NULL));
}
/*--------------------------------------------------------------------------*/
inline Tuint CStringUnicode::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
inline Tuint CStringUnicode::getFreeSize() const
{ CALL
  return (getHiCapacity() - getSize());
}
/*--------------------------------------------------------------------------*/
inline Tuint CStringUnicode::getLoCapacity() const
{ CALL
  return (m_HiCapacity / 3);
}
/*--------------------------------------------------------------------------*/
inline Tuint CStringUnicode::getHiCapacity() const
{ CALL
  return m_HiCapacity;
}
/*--------------------------------------------------------------------------*/
inline Twstr CStringUnicode::getBuffer()
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline Tcwstr CStringUnicode::getBuffer() const
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::insertFirst(const Twchar& a_crItem)
{ CALL
  return insertIndex(0, a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::insertFirst(const CStringUnicode& a_crItem)
{ CALL
  return insertIndex(0, a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::insertLast(const Twchar& a_crItem)
{ CALL
  return insertIndex(m_Size, a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::insertLast(const CStringUnicode& a_crItem)
{ CALL
  return insertIndex(m_Size, a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::removeFirst()
{ CALL
  return removeIndex(0);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::removeFirst(Twchar& a_rItem)
{ CALL
  return removeIndex(0, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::removeFirst(const Tuint a_cSize)
{ CALL
  return removeIndex(0, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::removeFirst(const Tuint a_cSize, CStringUnicode& a_rItem)
{ CALL
  return removeIndex(0, a_cSize, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::removeLast()
{ CALL
  return removeIndex(getSize() - 1);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::removeLast(Twchar& a_rItem)
{ CALL
  return removeIndex(getSize() - 1, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::removeLast(const Tuint a_cSize)
{ CALL
  return removeIndex(getSize() - 1, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::removeLast(const Tuint a_cSize, CStringUnicode& a_rItem)
{ CALL
  return removeIndex(getSize() - 1, a_cSize, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  return removeIndex(a_cIndex, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::resizeBy(const Tsint a_cSize, const Twchar a_cValue/* = UNC('\0') */)
{ CALL
  return resize((((a_cSize < 0) && (m_Size < (Tuint)-a_cSize)) ? 0 : (m_Size + a_cSize)), a_cValue);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicode::replace(const Tuint a_cIndex, const Tuint a_cSize, const CStringUnicode& a_crString)
{ CALL
  if (removeIndex(a_cIndex, a_cSize))
    return insertIndex(a_cIndex, a_crString);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStringUnicode::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint count = 0;
  Tuint size = 0;

  // Clear the current Unicode string.
  CHECK(clear());

  // Load the Unicode string header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::CStringUnicode")));
    CHECK(a_rArchive.doProperty(count, STR("count")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the Unicode string content.
  if (size > 0)
  {
    // Allocate required buffer in UTF-8 encoding.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate UTF-8 string buffer for loading Unicode string (requested size is %u bytes).") COMMA size);
      return false;
    }

    // Load Unicode string content in UTF-8 encoding.
    if (!(a_rArchive.doValue(buffer, size, STR("m_pBuffer"))))
    {
      delete [] buffer;
      return false;
    }

    // Get size of same string in Unicode encoding in bytes.
    Tuint str_size = 0;
    if (!CStringUnicode::UTF8ToUnicodeCount(buffer, count, str_size))
    {
      delete [] buffer;
      WARNING(STR("Cannot get required buffer size to convert string from UTF-8 encoding to Unicode one. Content of the Unicode string has to be checked."));
      return false;
    }

    // Allocate required buffer in Unicode encoding.
    Tuint bound = str_size / sizeof(Twchar);
    Tuint buffer_size = (bound + (bound >> 1)) * sizeof(Twchar);
    Tbuffer str_buffer = newex Tbyte[buffer_size];
    if (str_buffer == NULL)
    {
      delete [] buffer;
      WARNING(STR("Cannot allocate Unicode string buffer for loading Unicode string (requested size is %u bytes).") COMMA buffer_size);
      return false;
    }

    // Convert Unicode string from UTF-8 encoding.
    if (!CStringUnicode::UTF8ToUnicode(str_buffer, buffer, count, str_size))
    {
      delete [] buffer;
      delete [] str_buffer;
      WARNING(STR("Cannot convert string from UTF-8 encoding to Unicode one. Content of the Unicode string has to be checked."));
      return false;
    }

    // Update Unicode string attributes.
    m_Size = bound;
    m_HiCapacity = m_Size + (m_Size >> 1);
    m_pBuffer = (Twstr)str_buffer;

    // Delete temporary buffer.
    delete [] buffer;
  }

  // Load the Unicode string end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStringUnicode::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint count = 0;
  Tuint size = 0;

  // Get count of Unicode string characters.
  if (!CStringUnicode::getUnicodeCharsCount(m_pBuffer, m_Size * sizeof(Twchar), count))
  {
    WARNING(STR("Cannot get count of Unicode string characters in the current Unicode string. Content of the Unicode string has to be checked."));
    return false;
  }

  // Get size of same string in UTF-8 encoding in bytes.
  if (!CStringUnicode::UnicodeToUTF8Count(m_pBuffer, count, size))
  {
    WARNING(STR("Cannot get required buffer size to convert string from Unicode encoding to UTF-8 one. Content of the Unicode string has to be checked."));
    return false;
  }

  // Save the Unicode string header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::CStringUnicode")));
    CHECK(a_rArchive.doProperty(count, STR("count")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the Unicode string content.
  if (size > 0)
  {
    // Allocate required buffer.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate UTF-8 string buffer for saving Unicode string (requested size is %u bytes).") COMMA size);
      return false;
    }

    // Convert Unicode string in UTF-8 encoding.
    if (!CStringUnicode::UnicodeToUTF8(buffer, m_pBuffer, count, size))
    {
      delete [] buffer;
      WARNING(STR("Cannot convert string from Unicode encoding to UTF-8 one. Content of the Unicode string has to be checked."));
      return false;
    }

    // Save Unicode string content in UTF-8 encoding.
    if (!(a_rArchive.doValue(buffer, size, STR("m_pBuffer"))))
    {
       delete [] buffer;
       return false;
    }

    // Delete temporary buffer.
    delete [] buffer;
  }

  // Save the Unicode string end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStringUnicode::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void CStringUnicode::swap(CStringUnicode& a_rInstance)
{ CALL
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
