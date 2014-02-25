/*!
 *  \file    CStringASCII.inl ASCII string class provides base string
 *           functionality in the ASCII encoding.
 *  \brief   ASCII string class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: ASCII string class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   02.08.2008 23:53:28

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
#ifndef __CSTRINGASCII_INL__
#define __CSTRINGASCII_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CStringASCII::CStringASCII(const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IRandom<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
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
inline CStringASCII::CStringASCII(const Tschar a_cASCIICharacter, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IRandom<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cASCIICharacter, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::CStringASCII(const Twchar a_cUnicodeCharacter, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IRandom<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cUnicodeCharacter, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::CStringASCII(Tcsstr a_cpASCIIString, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IRandom<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cpASCIIString, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::CStringASCII(Tcwstr a_cpUnicodeString, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IRandom<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cpUnicodeString, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::CStringASCII(Tcsstr a_cpBuffer, const Tuint a_cSize) :
  NCommon::NContainers::IRandom<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::CStringASCII(Tcwstr a_cpBuffer, const Tuint a_cSize) :
  NCommon::NContainers::IRandom<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::CStringASCII(const CSystemString& a_crInstance) :
  NCommon::NContainers::IRandom<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::CStringASCII(const CStringASCII& a_crInstance) :
  NCommon::NContainers::IRandom<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::CStringASCII(const CStringUnicode& a_crInstance) :
  NCommon::NContainers::IRandom<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  NCommon::NContainers::IRandomConst<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>(),
  m_Size(0),
  m_HiCapacity(0),
  m_pBuffer(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::~CStringASCII()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2)
{ CALL
  return CStringASCII::compare(a_crInstance1, a_crInstance2) < 0;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2)
{ CALL
  return CStringASCII::compare(a_crInstance1, a_crInstance2) > 0;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2)
{ CALL
  return CStringASCII::compare(a_crInstance1, a_crInstance2) <= 0;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2)
{ CALL
  return CStringASCII::compare(a_crInstance1, a_crInstance2) >= 0;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CStringASCII operator + (const CStringASCII& a_crInstance, const CStringASCII& a_crString)
{ CALL
  CStringASCII result(a_crInstance);
  result.insertLast(a_crString);
  return result;
}
/*--------------------------------------------------------------------------*/
inline CStringASCII& CStringASCII::operator = (const Tschar a_cASCIICharacter)
{ CALL
  set(a_cASCIICharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringASCII& CStringASCII::operator = (const Twchar a_cUnicodeCharacter)
{ CALL
  set(a_cUnicodeCharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringASCII& CStringASCII::operator = (Tcsstr a_cpASCIIString)
{ CALL
  set(a_cpASCIIString);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringASCII& CStringASCII::operator = (Tcwstr a_cpUnicodeString)
{ CALL
  set(a_cpUnicodeString);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringASCII& CStringASCII::operator = (const CSystemString& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringASCII& CStringASCII::operator = (const CStringASCII& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringASCII& CStringASCII::operator = (const CStringUnicode& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringASCII& CStringASCII::operator += (const CStringASCII& a_crString)
{ CALL
  insertLast(a_crString);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tschar& CStringASCII::operator [] (const Tsint a_cIndex)
{ CALL
  // Verify index value and the ASCII string bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the single character of the ASCII string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline Tschar& CStringASCII::operator [] (const Tuint a_cIndex)
{ CALL
  // Verify index value and the ASCII string bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the single character of the ASCII string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline const Tschar& CStringASCII::operator [] (const Tsint a_cIndex) const
{ CALL
  // Verify index value and the ASCII string bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the single character of the ASCII string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline const Tschar& CStringASCII::operator [] (const Tuint a_cIndex) const
{ CALL
  // Verify index value and the ASCII string bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the single character of the ASCII string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::operator Tsstr ()
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::operator Tcsstr () const
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline CStringASCII::operator CSystemString () const
{ CALL
  CSystemString result;
  getSystemString(result);
  return result;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pBuffer == NULL));
}
/*--------------------------------------------------------------------------*/
inline Tuint CStringASCII::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
inline Tuint CStringASCII::getFreeSize() const
{ CALL
  return (getHiCapacity() - getSize());
}
/*--------------------------------------------------------------------------*/
inline Tuint CStringASCII::getLoCapacity() const
{ CALL
  return (m_HiCapacity >> 1);
}
/*--------------------------------------------------------------------------*/
inline Tuint CStringASCII::getHiCapacity() const
{ CALL
  return m_HiCapacity;
}
/*--------------------------------------------------------------------------*/
inline Tsstr CStringASCII::getBuffer()
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline Tcsstr CStringASCII::getBuffer() const
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::insertFirst(const Tschar& a_crItem)
{ CALL
  return insertIndex(0, a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::insertFirst(const CStringASCII& a_crItem)
{ CALL
  return insertIndex(0, a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::insertLast(const Tschar& a_crItem)
{ CALL
  return insertIndex(getSize(), a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::insertLast(const CStringASCII& a_crItem)
{ CALL
  return insertIndex(getSize(), a_crItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::removeFirst()
{ CALL
  return removeIndex(0);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::removeFirst(Tschar& a_rItem)
{ CALL
  return removeIndex(0, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::removeFirst(const Tuint a_cSize)
{ CALL
  return removeIndex(0, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::removeFirst(const Tuint a_cSize, CStringASCII& a_rItem)
{ CALL
  return removeIndex(0, a_cSize, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::removeLast()
{ CALL
  return removeIndex(getSize() - 1);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::removeLast(Tschar& a_rItem)
{ CALL
  return removeIndex(getSize() - 1, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::removeLast(const Tuint a_cSize)
{ CALL
  return removeIndex(getSize() - 1, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::removeLast(const Tuint a_cSize, CStringASCII& a_rItem)
{ CALL
  return removeIndex(getSize() - 1, a_cSize, a_rItem);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  return removeIndex(a_cIndex, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::resizeBy(const Tsint a_cSize, const Tschar a_cValue/* = ASC('\0') */)
{ CALL
  return resize((((a_cSize < 0) && (m_Size < (Tuint)-a_cSize)) ? 0 : (m_Size + a_cSize)), a_cValue);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringASCII::replace(const Tuint a_cIndex, const Tuint a_cSize, const CStringASCII& a_crString)
{ CALL
  if (removeIndex(a_cIndex, a_cSize))
    return insertIndex(a_cIndex, a_crString);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStringASCII::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint count = 0;
  Tuint size = 0;

  // Clear the current ASCII string.
  CHECK(clear());

  // Load the ASCII string header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::CStringASCII")));
    CHECK(a_rArchive.doProperty(count, STR("count")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the ASCII string content.
  if (size > 0)
  {
    // Allocate required buffer in UTF-8 encoding.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate UTF-8 string buffer for loading ASCII string (requested size is %u bytes).") COMMA size);
      return false;
    }

    // Load ASCII string content in UTF-8 encoding.
    if (!(a_rArchive.doValue(buffer, size, STR("m_pBuffer"))))
    {
      delete [] buffer;
      return false;
    }

    // Get size of same string in ASCII encoding in bytes.
    Tuint str_size = 0;
    if (!CStringASCII::UTF8ToASCIICount(buffer, count, str_size))
    {
      delete [] buffer;
      WARNING(STR("Cannot get required buffer size to convert string from UTF-8 encoding to ASCII one. Content of the ASCII string has to be checked."));
      return false;
    }

    // Allocate required buffer in ASCII encoding.
    Tuint bound = str_size / sizeof(Tschar);
    Tuint buffer_size = (bound + (bound >> 1)) * sizeof(Tschar);
    Tbuffer str_buffer = newex Tbyte[buffer_size];
    if (str_buffer == NULL)
    {
      delete [] buffer;
      WARNING(STR("Cannot allocate ASCII string buffer for loading ASCII string (requested size is %u bytes).") COMMA buffer_size);
      return false;
    }

    // Convert ASCII string from UTF-8 encoding.
    if (!CStringASCII::UTF8ToASCII(str_buffer, buffer, count, str_size))
    {
      delete [] buffer;
      delete [] str_buffer;
      WARNING(STR("Cannot convert string from UTF-8 encoding to ASCII one. Content of the ASCII string has to be checked."));
      return false;
    }

    // Update ASCII string attributes.
    m_Size = bound;
    m_HiCapacity = m_Size + (m_Size >> 1);
    m_pBuffer = (Tsstr)str_buffer;

    // Delete temporary buffer.
    delete [] buffer;
  }

  // Load the ASCII string end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStringASCII::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint count = 0;
  Tuint size = 0;

  // Get count of ASCII string characters.
  if (!CStringASCII::getASCIICharsCount(m_pBuffer, m_Size * sizeof(Tschar), count))
  {
    WARNING(STR("Cannot get count of ASCII string characters in the current ASCII string. Content of the ASCII string has to be checked."));
    return false;
  }

  // Get size of same string in UTF-8 encoding in bytes.
  if (!CStringASCII::ASCIIToUTF8Count(m_pBuffer, count, size))
  {
    WARNING(STR("Cannot get required buffer size to convert string from ASCII encoding to UTF-8 one. Content of the ASCII string has to be checked."));
    return false;
  }

  // Save the ASCII string header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::CStringASCII")));
    CHECK(a_rArchive.doProperty(count, STR("count")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the ASCII string content.
  if (size > 0)
  {
    // Allocate required buffer.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate UTF-8 string buffer for saving ASCII string (requested size is %u bytes).") COMMA size);
      return false;
    }

    // Convert ASCII string in UTF-8 encoding.
    if (!CStringASCII::ASCIIToUTF8(buffer, m_pBuffer, count, size))
    {
      delete [] buffer;
      WARNING(STR("Cannot convert string from ASCII encoding to UTF-8 one. Content of the ASCII string has to be checked."));
      return false;
    }

    // Save ASCII string content in UTF-8 encoding.
    if (!(a_rArchive.doValue(buffer, size, STR("m_pBuffer"))))
    {
       delete [] buffer;
       return false;
    }

    // Delete temporary buffer.
    delete [] buffer;
  }

  // Save the ASCII string end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStringASCII::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void CStringASCII::swap(CStringASCII& a_rInstance)
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
