/*!
 *  \file    CSystemString.inl System string class provides base string
 *           functionality in the system dependant encoding.
 *  \brief   System string class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.04.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: System string class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   28.04.2008 23:05:50

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
#ifndef __CSYSTEMSTRING_INL__
#define __CSYSTEMSTRING_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CSystemString::CSystemString(const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IContainer<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  NCommon::NContainers::IRandomConst<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  m_Size(0),
  m_pBuffer(CSystemString::ms_pEmptyBuffer)
{ CALL
  if (a_cAppendZero)
    set(STR('\0'));
  else
    clear();
}
/*--------------------------------------------------------------------------*/
inline CSystemString::CSystemString(const Tschar a_cASCIICharacter, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IContainer<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  NCommon::NContainers::IRandomConst<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  m_Size(0),
  m_pBuffer(CSystemString::ms_pEmptyBuffer)
{ CALL
  set(a_cASCIICharacter, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CSystemString::CSystemString(const Twchar a_cUnicodeCharacter, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IContainer<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  NCommon::NContainers::IRandomConst<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  m_Size(0),
  m_pBuffer(CSystemString::ms_pEmptyBuffer)
{ CALL
  set(a_cUnicodeCharacter, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CSystemString::CSystemString(Tcsstr a_cpASCIIString, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IContainer<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  NCommon::NContainers::IRandomConst<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  m_Size(0),
  m_pBuffer(CSystemString::ms_pEmptyBuffer)
{ CALL
  set(a_cpASCIIString, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CSystemString::CSystemString(Tcwstr a_cpUnicodeString, const Tbool a_cAppendZero/* = false */) :
  NCommon::NContainers::IContainer<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  NCommon::NContainers::IRandomConst<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  m_Size(0),
  m_pBuffer(CSystemString::ms_pEmptyBuffer)
{ CALL
  set(a_cpUnicodeString, a_cAppendZero);
}
/*--------------------------------------------------------------------------*/
inline CSystemString::CSystemString(Tcbuffer a_cpBuffer, const Tuint a_cSize) :
  NCommon::NContainers::IContainer<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  NCommon::NContainers::IRandomConst<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  m_Size(0),
  m_pBuffer(CSystemString::ms_pEmptyBuffer)
{ CALL
  set(a_cpBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline CSystemString::CSystemString(const CSystemString& a_crInstance) :
  NCommon::NContainers::IContainer<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  NCommon::NContainers::IRandomConst<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>(),
  m_Size(0),
  m_pBuffer(CSystemString::ms_pEmptyBuffer)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CSystemString::~CSystemString()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2)
{ CALL
  return (!(a_crInstance1 == a_crInstance2));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2)
{ CALL
  return CSystemString::compare(a_crInstance1, a_crInstance2) < 0;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2)
{ CALL
  return CSystemString::compare(a_crInstance1, a_crInstance2) > 0;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2)
{ CALL
  return CSystemString::compare(a_crInstance1, a_crInstance2) <= 0;
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2)
{ CALL
  return CSystemString::compare(a_crInstance1, a_crInstance2) >= 0;
}
/*--------------------------------------------------------------------------*/
inline CSystemString& CSystemString::operator = (const Tschar a_cASCIICharacter)
{ CALL
  set(a_cASCIICharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CSystemString& CSystemString::operator = (const Twchar a_cUnicodeCharacter)
{ CALL
  set(a_cUnicodeCharacter);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CSystemString& CSystemString::operator = (Tcsstr a_cpASCIIString)
{ CALL
  set(a_cpASCIIString);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CSystemString& CSystemString::operator = (Tcwstr a_cpUnicodeString)
{ CALL
  set(a_cpUnicodeString);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CSystemString& CSystemString::operator = (const CSystemString& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Tbyte& CSystemString::operator [] (const Tsint a_cIndex)
{ CALL
  // Verify index value and the system string bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the single character of the system string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline Tbyte& CSystemString::operator [] (const Tuint a_cIndex)
{ CALL
  // Verify index value and the system string bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the single character of the system string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline const Tbyte& CSystemString::operator [] (const Tsint a_cIndex) const
{ CALL
  // Verify index value and the system string bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the single character of the system string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline const Tbyte& CSystemString::operator [] (const Tuint a_cIndex) const
{ CALL
  // Verify index value and the system string bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the single character of the system string with the out of bounds index."));

  return m_pBuffer[a_cIndex];
}
/*--------------------------------------------------------------------------*/
inline CSystemString::operator Tbuffer ()
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline CSystemString::operator Tcbuffer () const
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemString::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pBuffer == NULL));
}
/*--------------------------------------------------------------------------*/
inline Tuint CSystemString::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
inline Tbuffer CSystemString::getBuffer()
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
inline Tcbuffer CSystemString::getBuffer() const
{ CALL
  return m_pBuffer;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CSystemString::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint count = 0;
  Tuint size = 0;

  // Clear the current system string.
  CHECK(clear());

  // Load the system string header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::CSystemString")));
    CHECK(a_rArchive.doProperty(count, STR("count")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Load the system string content.
  if (size > 0)
  {
    // Allocate required buffer in UTF-8 encoding.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate UTF-8 string buffer for loading system string (requested size is %u bytes).") COMMA size);
      return false;
    }

    // Load system string content in UTF-8 encoding.
    if (!(a_rArchive.doValue(buffer, size, STR("m_pBuffer"))))
    {
      delete [] buffer;
      return false;
    }

    // Get size of same string in system encoding in bytes.
    Tuint str_size = 0;
    if (!CSystemString::UTF8ToSystemCount(buffer, count, str_size))
    {
      delete [] buffer;
      WARNING(STR("Cannot get required buffer size to convert string from UTF-8 encoding to system one. Content of the system string has to be checked."));
      return false;
    }

    // Allocate required buffer in system encoding.
    Tbuffer str_buffer = newex Tbyte[str_size];
    if (str_buffer == NULL)
    {
      delete [] buffer;
      WARNING(STR("Cannot allocate system string buffer for loading system string (requested size is %u bytes).") COMMA str_size);
      return false;
    }

    // Convert system string from UTF-8 encoding.
    if (!CSystemString::UTF8ToSystem(str_buffer, buffer, count, str_size))
    {
      delete [] buffer;
      delete [] str_buffer;
      WARNING(STR("Cannot convert string from UTF-8 encoding to system one. Content of the system string has to be checked."));
      return false;
    }

    // Update system string attributes.
    m_Size = str_size;
    m_pBuffer = str_buffer;

    // Delete temporary buffer.
    delete [] buffer;
  }

  // Load the system string end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CSystemString::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint count = 0;
  Tuint size = 0;

  // Get count of system string characters.
  if (!CSystemString::getSystemCharsCount(m_pBuffer, m_Size, count))
  {
    WARNING(STR("Cannot get count of system string characters in the current system string. Content of the system string has to be checked."));
    return false;
  }

  // Get size of same string in UTF-8 encoding in bytes.
  if (!CSystemString::SystemToUTF8Count(m_pBuffer, count, size))
  {
    WARNING(STR("Cannot get required buffer size to convert string from system encoding to UTF-8 one. Content of the system string has to be checked."));
    return false;
  }

  // Save the system string header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::CSystemString")));
    CHECK(a_rArchive.doProperty(count, STR("count")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the system string content.
  if (size > 0)
  {
    // Allocate required buffer.
    Tbuffer buffer = newex Tbyte[size];
    if (buffer == NULL)
    {
      WARNING(STR("Cannot allocate UTF-8 string buffer for saving system string (requested size is %u bytes).") COMMA size);
      return false;
    }

    // Convert system string in UTF-8 encoding.
    if (!CSystemString::SystemToUTF8(buffer, m_pBuffer, count, size))
    {
      delete [] buffer;
      WARNING(STR("Cannot convert string from system encoding to UTF-8 one. Content of the system string has to be checked."));
      return false;
    }

    // Save system string content in UTF-8 encoding.
    if (!(a_rArchive.doValue(buffer, size, STR("m_pBuffer"))))
    {
       delete [] buffer;
       return false;
    }

    // Delete temporary buffer.
    delete [] buffer;
  }

  // Save the system string end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CSystemString::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void CSystemString::swap(CSystemString& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_pBuffer, a_rInstance.m_pBuffer);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
