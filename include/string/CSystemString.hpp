/*!
 *  \file    CSystemString.hpp System string class provides base string
 *           functionality in the system dependant encoding.
 *  \brief   System string class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.04.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: System string class.

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
#ifndef __CSYSTEMSTRING_HPP__
#define __CSYSTEMSTRING_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IContainer.hpp>
#include <Depth/include/common/containers/IRandomConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/traits/MTraitsContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
class CSystemStringIterator;
class CSystemStringIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! System string class.
/*!
    System string class provides  base  string  functionality  in  the  system
    dependant encoding. System string can be taken from any  CString  instance
    or created from any C string buffer. It is  required  because  all  system
    routines work only with  system  strings  in  system  encoding.  Therefore
    system string can be considered as a low-level system string layer.

    Note that system string can contains '\\0' characters, which  are  treated
    as string termination indicator under most systems.  For  the  portability
    purpose it is  highly  recommended  to  prepare  '\\0'  terminated  system
    strings for most system dependant  operations  (file  naming,  networking,
    etc).
*/
class BASE_API CSystemString :
  public NCommon::NContainers::IContainer<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>,
  public NCommon::NContainers::IRandomConst<CSystemString, Tbyte, CSystemStringIterator, CSystemStringIteratorConst>
{
  // Friend class: System string iterator class (CSystemStringIterator).
  friend class NDepth::NString::NIterators::CSystemStringIterator;
  // Friend class: Constant system string iterator class (CSystemStringIteratorConst).
  friend class NDepth::NString::NIterators::CSystemStringIteratorConst;
  // Friend class: ASCII string class (CStringASCII).
  friend class CStringASCII;
  // Friend class: Unicode string class (CStringUnicode).
  friend class CStringUnicode;

  //! Type for the MConceptDepthType constraint checking.
  typedef CSystemString TDepthCheckType;

  // Check CSystemString class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef Tbyte TType;
  //! Container type.
  typedef CSystemString TContainer;
  //! Non constant system string iterator type.
  typedef CSystemStringIterator TIterator;
  //! Constant system string iterator type.
  typedef CSystemStringIteratorConst TIteratorConst;

  static const CSystemString EMPTY;     //!< Empty system string.

  //! Default class constructor.
  /*!
      Creates empty system string without or with '\\0' terminated character.

      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CSystemString(const Tbool a_cAppendZero = false);
  //! Initialize system string with the given single ASCII character.
  /*!
      \param a_cASCIICharacter - ASCII character.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CSystemString(const Tschar a_cASCIICharacter, const Tbool a_cAppendZero = false);
  //! Initialize system string with the given single Unicode character.
  /*!
      \param a_cUnicodeCharacter - Unicode character.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CSystemString(const Twchar a_cUnicodeCharacter, const Tbool a_cAppendZero = false);
  //! Initialize system string with the given ASCII 'C' string.
  /*!
      \param a_cpASCIIString - ASCII 'C' string.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CSystemString(Tcsstr a_cpASCIIString, const Tbool a_cAppendZero = false);
  //! Initialize system string with the given Unicode 'C' string.
  /*!
      \param a_cpUnicodeString - Unicode 'C' string.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CSystemString(Tcwstr a_cpUnicodeString, const Tbool a_cAppendZero = false);
  //! Initialize system string with the given buffer of fixed size in system encoding.
  /*!
      \param a_cpBuffer - Buffer of fixed size in system encoding.
      \param a_cSize - Size of the buffer.
  */
  CSystemString(Tcbuffer a_cpBuffer, const Tuint a_cSize);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSystemString class.
  */
  CSystemString(const CSystemString& a_crInstance);
  //! Class virtual destructor.
  virtual ~CSystemString();

  //! Operator: Equal to another CSystemString class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CSystemString class.
      \param a_crInstance2 - Constant reference to another instance of the CSystemString class.
      \return true  - if CSystemString class instance is equal to another one. \n
              false - if CSystemString class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2);
  //! Operator: Not equal to another CSystemString class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CSystemString class.
      \param a_crInstance2 - Constant reference to another instance of the CSystemString class.
      \return true  - if CSystemString class instance is not equal to another one. \n
              false - if CSystemString class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2);

  //! Operator: Lexicographically less than another CSystemString class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CSystemString class.
      \param a_crInstance2 - Constant reference to another instance of the CSystemString class.
      \return true  - if CSystemString class instance is lexicographically less than another one. \n
              false - if CSystemString class instance is not lexicographically less than another one. \n
  */
  friend BASE_API Tbool operator < (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2);
  //! Operator: Lexicographically more than another CSystemString class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CSystemString class.
      \param a_crInstance2 - Constant reference to another instance of the CSystemString class.
      \return true  - if CSystemString class instance is lexicographically more than another one. \n
              false - if CSystemString class instance is not lexicographically more than another one. \n
  */
  friend BASE_API Tbool operator > (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2);
  //! Operator: Lexicographically less or equal than another CSystemString class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CSystemString class.
      \param a_crInstance2 - Constant reference to another instance of the CSystemString class.
      \return true  - if CSystemString class instance is lexicographically less or equal than another one. \n
              false - if CSystemString class instance is not lexicographically less or equal than another one. \n
  */
  friend BASE_API Tbool operator <= (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2);
  //! Operator: Lexicographically more or equal than another CSystemString class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CSystemString class.
      \param a_crInstance2 - Constant reference to another instance of the CSystemString class.
      \return true  - if CSystemString class instance is lexicographically more or equal than another one. \n
              false - if CSystemString class instance is not lexicographically more or equal than another one. \n
  */
  friend BASE_API Tbool operator >= (const CSystemString& a_crInstance1, const CSystemString& a_crInstance2);

  //! Operator: Assign single ASCII character.
  /*!
      \param a_cASCIICharacter - ASCII character.
      \return Reference to the current class instance.
  */
  CSystemString& operator = (const Tschar a_cASCIICharacter);
  //! Operator: Assign single Unicode character.
  /*!
      \param a_cUnicodeCharacter - Unicode character.
      \return Reference to the current class instance.
  */
  CSystemString& operator = (const Twchar a_cUnicodeCharacter);
  //! Operator: Assign ASCII 'C' string.
  /*!
      \param a_cpASCIIString - ASCII 'C' string.
      \return Reference to the current class instance.
  */
  CSystemString& operator = (Tcsstr a_cpASCIIString);
  //! Operator: Assign Unicode 'C' string.
  /*!
      \param a_cpUnicodeString - Unicode 'C' string.
      \return Reference to the current class instance.
  */
  CSystemString& operator = (Tcwstr a_cpUnicodeString);
  //! Operator: Assign another CSystemString class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSystemString class.
      \return Reference to the current class instance.
  */
  CSystemString& operator = (const CSystemString& a_crInstance);

  //! Operator: Indexing into the non constant system string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Non constant reference to system string byte under the given index.
  */
  Tbyte& operator [] (const Tsint a_cIndex);
  //! Operator: Indexing into the non constant system string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Non constant reference to system string byte under the given index.
  */
  Tbyte& operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the constant system string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Constant reference to system string byte under the given index.
  */
  const Tbyte& operator [] (const Tsint a_cIndex) const;
  //! Operator: Indexing into the constant system string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Constant reference to system string byte under the given index.
  */
  const Tbyte& operator [] (const Tuint a_cIndex) const;

  //! Operator: Get pointer to the system string buffer.
  /*!
      \return Pointer to the system string buffer.
      \see NDepth::NString::CSystemString::getBuffer()
  */
  operator Tbuffer ();
  //! Operator: Get constant pointer to the system string buffer.
  /*!
      \return Constant pointer to the system string buffer.
      \see NDepth::NString::CSystemString::getBuffer()
  */
  operator Tcbuffer () const;

  //! Set single ASCII character.
  /*!
      \param a_cASCIICharacter - ASCII character.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
      \return true  - if single ASCII character was successfully set. \n
              false - if single ASCII character was not successfully set. \n
  */
  Tbool set(const Tschar a_cASCIICharacter, const Tbool a_cAppendZero = false);
  //! Set single Unicode character.
  /*!
      \param a_cUnicodeCharacter - Unicode character.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
      \return true  - if single Unicode character was successfully set. \n
              false - if single Unicode character was not successfully set. \n
  */
  Tbool set(const Twchar a_cUnicodeCharacter, const Tbool a_cAppendZero = false);
  //! Set ASCII 'C' string.
  /*!
      \param a_cpASCIIString - ASCII 'C' string.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
      \return true  - if ASCII 'C' string was successfully set. \n
              false - if ASCII 'C' string was not successfully set. \n
  */
  Tbool set(Tcsstr a_cpASCIIString, const Tbool a_cAppendZero = false);
  //! Set Unicode 'C' string.
  /*!
      \param a_cpUnicodeString - Unicode 'C' string.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
      \return true  - if Unicode 'C' string was successfully set. \n
              false - if Unicode 'C' string was not successfully set. \n
  */
  Tbool set(Tcwstr a_cpUnicodeString, const Tbool a_cAppendZero = false);
  //! Set buffer of fixed size in system encoding.
  /*!
      \param a_cpBuffer - Buffer of fixed size in system encoding.
      \param a_cSize - Size of the buffer.
      \return true  - if buffer of fixed size was successfully set. \n
              false - if buffer of fixed size was not successfully set. \n
  */
  Tbool set(Tcbuffer a_cpBuffer, const Tuint a_cSize);
  //! Set another CSystemString class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSystemString class.
      \return true  - if another system string was successfully set. \n
              false - if another system string was not successfully set. \n
  */
  Tbool set(const CSystemString& a_crInstance);

  //! Is system string empty?
  /*!
      \return true  - if system string is empty. \n
              false - if system string is not empty. \n
  */
  Tbool isEmpty() const;

  //! Get system string size.
  /*!
      \return System string size (in bytes).
  */
  Tuint getSize() const;

  //! Get ponter to the system string buffer.
  /*!
      Method returns pointer to  the  system  string  buffer.  Using  of  this
      pointer is quite dangerous cause it may lead to memory errors.  That  is
      why you always have to check  string  bounds  while  working  with  this
      pointer.

      \return Pointer to the system string buffer.
  */
  Tbuffer getBuffer();
  //! Get constant ponter to the system string buffer.
  /*!
      Method returns constant pointer to the system string  buffer.  Using  of
      this pointer is quite dangerous cause it may lead to memory errors. That
      is why you always have to check string bounds while  working  with  this
      pointer.

      \return Constant pointer to the system string buffer.
  */
  Tcbuffer getBuffer() const;

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IRandomConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;
  virtual TIterator      getItIndex(const Tuint a_cIndex);
  virtual TIteratorConst getItIndex(const Tuint a_cIndex) const;

  //! Compare two system strings taken into account their cases.
  /*!
      Method  returns  value  less  than  0  if  the   first   system   string
      lexicographically less than the second one. Method returns  value  great
      than 0 if the first  system  string  lexicographically  great  than  the
      second  one.   Method   returns   0   if   the   first   system   string
      lexicographically equals to the second one.

      If sizes of  the  system  strings  are  different,  method  returns  the
      difference between the first system string size and the second one.

      If sizes of the system strings are equal, method returns the  difference
      between the first two different characters on a same place in the system
      strings.

      \param a_crString1 - Constant reference to the first system string.
      \param a_crString2 - Constant reference to the second system string.
      \return One of the following values: \n
              <0 - if the first system string is lexicographically less than the second one. \n
              =0 - two system strings are equal. \n
              >0 - if the first system string is lexicographically great than the second one. \n
  */
  static Tsint compare(const CSystemString& a_crString1, const CSystemString& a_crString2);
  //! Compare two system strings ignoring their cases.
  /*!
      Method  returns  value  less  than  0  if  the   first   system   string
      lexicographically less than the second one. Method returns  value  great
      than 0 if the first  system  string  lexicographically  great  than  the
      second  one.   Method   returns   0   if   the   first   system   string
      lexicographically equals to the second one.

      If sizes of  the  system  strings  are  different,  method  returns  the
      difference between the first system string size and the second one.

      If sizes of the system strings are equal, method returns the  difference
      between the first two different characters in lowercase on a same  place
      in the system strings.

      \param a_crString1 - Constant reference to the first system string.
      \param a_crString2 - Constant reference to the second system string.
      \return One of the following values: \n
              <0 - if the first system string is lexicographically less than the second one. \n
              =0 - two system strings are equal. \n
              >0 - if the first system string is lexicographically great than the second one. \n
  */
  static Tsint compareIgnoreCase(const CSystemString& a_crString1, const CSystemString& a_crString2);

  //! Serialization load CSystemString class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CSystemString class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CSystemString class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSystemString class instances.
  /*!
      \param a_rInstance - Reference to another CSystemString class instance.
  */
  void swap(CSystemString& a_rInstance);

private:
  Tuint   m_Size;                       //!< System string size.
  Tbuffer m_pBuffer;                    //!< System string buffer.

  static Tbuffer ms_pEmptyBuffer;       //!< System string empty buffer.

  //! Get count of system encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getSystemCharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);

  //! Count required buffer size to convert characters from system encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool SystemToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-8 encoding into system encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToSystemCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Convert characters from system encoding into UTF-8 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF8Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool SystemToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-8 encoding into system encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerSystemChar().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF8ToSystem(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* CONTAINER TRAITS SPECIALIZATION DECLARATIONS                             */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: System string container traits specialization.
template <>
class MTraitsContainer<NString::CSystemString> :
  public MType<NString::CSystemString>
{
public:
  //! Container value type.
  typedef NString::CSystemString::TType value;
  //! Container type.
  typedef NString::CSystemString::TContainer container;
  //! Container non constant iterator type.
  typedef NString::CSystemString::TIterator iterator;
  //! Container constant iterator type.
  typedef NString::CSystemString::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = true;  //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = true;  //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = true;  //!< Is container constant random?
  static const Tbool isAssociative      = false; //!< Is container non constant associative?
  static const Tbool isAssociativeConst = false; //!< Is container constant associative?
  static const Tbool isTree             = false; //!< Is container non constant tree?
  static const Tbool isTreeConst        = false; //!< Is container constant tree?
  static const Tbool isGraph            = false; //!< Is container non constant graph?
  static const Tbool isGraphConst       = false; //!< Is container constant graph?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/iterators/CSystemStringIterator.hpp>
#include <Depth/include/string/iterators/CSystemStringIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/string/CSystemString.inl>
/*==========================================================================*/
//! \example example-string-CSystemString.cpp
/*--------------------------------------------------------------------------*/
//! \test test-string-CSystemString.cpp
/*==========================================================================*/
#endif
