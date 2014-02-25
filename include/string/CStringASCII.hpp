/*!
 *  \file    CStringASCII.hpp ASCII string class provides base string
 *           functionality in the ASCII encoding.
 *  \brief   ASCII string class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: ASCII string class.

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
#ifndef __CSTRINGASCII_HPP__
#define __CSTRINGASCII_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IRandom.hpp>
#include <Depth/include/common/containers/IRandomConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/string/CSystemString.hpp>
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
class CStringASCIIIterator;
class CStringASCIIIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
class CStringUnicode;
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! ASCII string class.
/*!
    ASCII string  class  provides  base  string  functionality  in  the  ASCII
    encoding.
*/
class BASE_API CStringASCII :
  public NCommon::NContainers::IRandom<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>,
  public NCommon::NContainers::IRandomConst<CStringASCII, Tschar, CStringASCIIIterator, CStringASCIIIteratorConst>
{
  // Friend class: ASCII string iterator class (CStringASCIIIterator).
  friend class NDepth::NString::NIterators::CStringASCIIIterator;
  // Friend class: Constant ASCII string iterator class (CStringASCIIIteratorConst).
  friend class NDepth::NString::NIterators::CStringASCIIIteratorConst;
  // Friend class: Unicode string class (CStringUnicode).
  friend class CStringUnicode;

  //! Type for the MConceptDepthType constraint checking.
  typedef CStringASCII TDepthCheckType;

  // Check CStringASCII class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef Tschar TType;
  //! Container type.
  typedef CStringASCII TContainer;
  //! Non constant ASCII string iterator type.
  typedef CStringASCIIIterator TIterator;
  //! Constant ASCII string iterator type.
  typedef CStringASCIIIteratorConst TIteratorConst;

  static const CStringASCII EMPTY;      //!< Empty ASCII string.

  //! Default class constructor.
  /*!
      Creates empty ASCII string without or with '\\0' terminated character.

      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CStringASCII(const Tbool a_cAppendZero = false);
  //! Initialize ASCII string with the given single ASCII character.
  /*!
      \param a_cASCIICharacter - ASCII character.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CStringASCII(const Tschar a_cASCIICharacter, const Tbool a_cAppendZero = false);
  //! Initialize ASCII string with the given single Unicode character.
  /*!
      \param a_cUnicodeCharacter - Unicode character.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CStringASCII(const Twchar a_cUnicodeCharacter, const Tbool a_cAppendZero = false);
  //! Initialize ASCII string with the given ASCII 'C' string.
  /*!
      \param a_cpASCIIString - ASCII 'C' string.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CStringASCII(Tcsstr a_cpASCIIString, const Tbool a_cAppendZero = false);
  //! Initialize ASCII string with the given Unicode 'C' string.
  /*!
      \param a_cpUnicodeString - Unicode 'C' string.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CStringASCII(Tcwstr a_cpUnicodeString, const Tbool a_cAppendZero = false);
  //! Initialize ASCII string with the given buffer of fixed size in ASCII encoding.
  /*!
      \param a_cpBuffer - Buffer of fixed size in ASCII encoding.
      \param a_cSize - Size of the buffer.
  */
  CStringASCII(Tcsstr a_cpBuffer, const Tuint a_cSize);
  //! Initialize ASCII string with the given buffer of fixed size in Unicode encoding.
  /*!
      \param a_cpBuffer - Buffer of fixed size in Unicode encoding.
      \param a_cSize - Size of the buffer.
  */
  CStringASCII(Tcwstr a_cpBuffer, const Tuint a_cSize);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSystemString class.
  */
  CStringASCII(const CSystemString& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringASCII class.
  */
  CStringASCII(const CStringASCII& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringUnicode class.
  */
  CStringASCII(const CStringUnicode& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringASCII();

  //! Operator: Equal to another CStringASCII class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringASCII class.
      \param a_crInstance2 - Constant reference to another instance of the CStringASCII class.
      \return true  - if CStringASCII class instance is equal to another one. \n
              false - if CStringASCII class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2);
  //! Operator: Not equal to another CStringASCII class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringASCII class.
      \param a_crInstance2 - Constant reference to another instance of the CStringASCII class.
      \return true  - if CStringASCII class instance is not equal to another one. \n
              false - if CStringASCII class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2);

  //! Operator: Lexicographically less than another CStringASCII class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringASCII class.
      \param a_crInstance2 - Constant reference to another instance of the CStringASCII class.
      \return true  - if CStringASCII class instance is lexicographically less than another one. \n
              false - if CStringASCII class instance is not lexicographically less than another one. \n
  */
  friend BASE_API Tbool operator < (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2);
  //! Operator: Lexicographically more than another CStringASCII class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringASCII class.
      \param a_crInstance2 - Constant reference to another instance of the CStringASCII class.
      \return true  - if CStringASCII class instance is lexicographically more than another one. \n
              false - if CStringASCII class instance is not lexicographically more than another one. \n
  */
  friend BASE_API Tbool operator > (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2);
  //! Operator: Lexicographically less or equal than another CStringASCII class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringASCII class.
      \param a_crInstance2 - Constant reference to another instance of the CStringASCII class.
      \return true  - if CStringASCII class instance is lexicographically less or equal than another one. \n
              false - if CStringASCII class instance is not lexicographically less or equal than another one. \n
  */
  friend BASE_API Tbool operator <= (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2);
  //! Operator: Lexicographically more or equal than another CStringASCII class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringASCII class.
      \param a_crInstance2 - Constant reference to another instance of the CStringASCII class.
      \return true  - if CStringASCII class instance is lexicographically more or equal than another one. \n
              false - if CStringASCII class instance is not lexicographically more or equal than another one. \n
  */
  friend BASE_API Tbool operator >= (const CStringASCII& a_crInstance1, const CStringASCII& a_crInstance2);

  //! Operator: Append another ASCII string to the end position of the current one.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CStringASCII class.
      \param a_crString - Constant reference to another instance of the CStringASCII class.
      \return New instance of CStringASCII class with appended ASCII string.
  */
  friend BASE_API CStringASCII operator + (const CStringASCII& a_crInstance, const CStringASCII& a_crString);

  //! Operator: Assign single ASCII character.
  /*!
      \param a_cASCIICharacter - ASCII character.
      \return Reference to the current class instance.
  */
  CStringASCII& operator = (const Tschar a_cASCIICharacter);
  //! Operator: Assign single Unicode character.
  /*!
      \param a_cUnicodeCharacter - Unicode character.
      \return Reference to the current class instance.
  */
  CStringASCII& operator = (const Twchar a_cUnicodeCharacter);
  //! Operator: Assign ASCII 'C' string.
  /*!
      \param a_cpASCIIString - ASCII 'C' string.
      \return Reference to the current class instance.
  */
  CStringASCII& operator = (Tcsstr a_cpASCIIString);
  //! Operator: Assign Unicode 'C' string.
  /*!
      \param a_cpUnicodeString - Unicode 'C' string.
      \return Reference to the current class instance.
  */
  CStringASCII& operator = (Tcwstr a_cpUnicodeString);
  //! Operator: Assign another CSystemString class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSystemString class.
      \return Reference to the current class instance.
  */
  CStringASCII& operator = (const CSystemString& a_crInstance);
  //! Operator: Assign another CStringASCII class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringASCII class.
      \return Reference to the current class instance.
  */
  CStringASCII& operator = (const CStringASCII& a_crInstance);
  //! Operator: Assign another CStringUnicode class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringUnicode class.
      \return Reference to the current class instance.
  */
  CStringASCII& operator = (const CStringUnicode& a_crInstance);

  //! Operator: Append another ASCII string to the end position of the current one.
  /*!
      \param a_crString - Constant reference to another instance of the CStringASCII class.
      \return Reference to the current class instance.
  */
  CStringASCII& operator += (const CStringASCII& a_crString);

  //! Operator: Indexing into the non constant ASCII string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Non constant reference to ASCII string item under the given index.
  */
  Tschar& operator [] (const Tsint a_cIndex);
  //! Operator: Indexing into the non constant ASCII string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Non constant reference to ASCII string item under the given index.
  */
  Tschar& operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the constant ASCII string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Constant reference to ASCII string item under the given index.
  */
  const Tschar& operator [] (const Tsint a_cIndex) const;
  //! Operator: Indexing into the constant ASCII string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Constant reference to ASCII string item under the given index.
  */
  const Tschar& operator [] (const Tuint a_cIndex) const;

  //! Operator: Get pointer to the ASCII string buffer.
  /*!
      \return Pointer to the ASCII string buffer.
      \see NDepth::NString::CStringASCII::getBuffer()
  */
  operator Tsstr ();
  //! Operator: Get constant pointer to the ASCII string buffer.
  /*!
      \return Constant pointer to the ASCII string buffer.
      \see NDepth::NString::CStringASCII::getBuffer()
  */
  operator Tcsstr () const;

  //! Operator: Get system string.
  /*!
      \return System string.
  */
  operator CSystemString () const;

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
  //! Set buffer of fixed size in ASCII encoding.
  /*!
      \param a_cpBuffer - Buffer of fixed size in ASCII encoding.
      \param a_cSize - Size of the buffer.
      \return true  - if buffer of fixed size was successfully set. \n
              false - if buffer of fixed size was not successfully set. \n
  */
  Tbool set(Tcsstr a_cpBuffer, const Tuint a_cSize);
  //! Set buffer of fixed size in Unicode encoding.
  /*!
      \param a_cpBuffer - Buffer of fixed size in Unicode encoding.
      \param a_cSize - Size of the buffer.
      \return true  - if buffer of fixed size was successfully set. \n
              false - if buffer of fixed size was not successfully set. \n
  */
  Tbool set(Tcwstr a_cpBuffer, const Tuint a_cSize);
  //! Set another CSystemString class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSystemString class.
      \return true  - if another system string was successfully set. \n
              false - if another system string was not successfully set. \n
  */
  Tbool set(const CSystemString& a_crInstance);
  //! Set another CStringASCII class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringASCII class.
      \return true  - if another ASCII string was successfully set. \n
              false - if another ASCII string was not successfully set. \n
  */
  Tbool set(const CStringASCII& a_crInstance);
  //! Set another CStringUnicode class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringUnicode class.
      \return true  - if another Unicode string was successfully set. \n
              false - if another Unicode string was not successfully set. \n
  */
  Tbool set(const CStringUnicode& a_crInstance);

  //! Get system string with or without '\\0' terminated character based on the current ASCII string.
  /*!
      \param a_rSystemString - Reference to the system string.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
      \return true  - if ASCII string was successfully converted to the system string. \n
              false - if ASCII string was not successfully converted to the system string. \n
  */
  Tbool getSystemString(CSystemString& a_rSystemString, const Tbool a_cAppendZero = false) const;

  //! Get ASCII string free size.
  /*!
      Method returns count of free characters in the ASCII string.

      \return Count of free characters in the ASCII string.
  */
  Tuint getFreeSize() const;

  //! Get ASCII string lower capacity bound value.
  /*!
      Method returns lower bound size value before ASCII string reallocation.

      \return ASCII string lower capacity bound value.
  */
  Tuint getLoCapacity() const;
  //! Get ASCII string higher capacity bound value.
  /*!
      Method returns higher bound size value before ASCII string reallocation.

      \return ASCII string higher capacity bound value.
  */
  Tuint getHiCapacity() const;

  //! Get ponter to the ASCII string buffer.
  /*!
      Method returns pointer to the ASCII string buffer. Using of this pointer
      is quite dangerous cause it may lead to memory errors. That is  why  you
      always have to check string bounds while working with this pointer.

      \return Pointer to the ASCII string buffer.
  */
  Tsstr getBuffer();
  //! Get constant ponter to the ASCII string buffer.
  /*!
      Method returns constant pointer to the ASCII  string  buffer.  Using  of
      this pointer is quite dangerous cause it may lead to memory errors. That
      is why you always have to check string bounds while  working  with  this
      pointer.

      \return Constant pointer to the ASCII string buffer.
  */
  Tcsstr getBuffer() const;

  //! Get left sub-string from the current ASCII string.
  /*!
      \param a_cSize - Size of the left sub-string (in ASCII characters).
      \return Left sub-string.
  */
  CStringASCII getLeft(const Tuint a_cSize) const;
  //! Get right sub-string from the current ASCII string.
  /*!
      \param a_cSize - Size of the right sub-string (in ASCII characters).
      \return Right sub-string.
  */
  CStringASCII getRight(const Tuint a_cSize) const;
  //! Get middle sub-string from the current ASCII string.
  /*!
      \param a_cIndex - Index of middle sub-string.
      \param a_cSize - Size of the middle sub-string (in ASCII characters).
      \return Middle sub-string.
  */
  CStringASCII getMiddle(const Tuint a_cIndex, const Tuint a_cSize) const;

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IRandom interface overriding methods.
  virtual Tbool insertFirst(const Tschar& a_crItem);
  virtual Tbool insertFirst(const CStringASCII& a_crItem);
  virtual Tbool insertLast(const Tschar& a_crItem);
  virtual Tbool insertLast(const CStringASCII& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const Tschar& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const CStringASCII& a_crItem);
  virtual Tbool removeFirst();
  virtual Tbool removeFirst(Tschar& a_rItem);
  virtual Tbool removeFirst(const Tuint a_cSize);
  virtual Tbool removeFirst(const Tuint a_cSize, CStringASCII& a_rItem);
  virtual Tbool removeLast();
  virtual Tbool removeLast(Tschar& a_rItem);
  virtual Tbool removeLast(const Tuint a_cSize);
  virtual Tbool removeLast(const Tuint a_cSize, CStringASCII& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex);
  virtual Tbool removeIndex(const Tuint a_cIndex, Tschar& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex, const Tuint a_cSize);
  virtual Tbool removeIndex(const Tuint a_cIndex, const Tuint a_cSize, CStringASCII& a_rItem);
  virtual Tbool remove(const Tuint a_cIndex, const Tuint a_cSize);

  // IRandomConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;
  virtual TIterator      getItIndex(const Tuint a_cIndex);
  virtual TIteratorConst getItIndex(const Tuint a_cIndex) const;

  //! Reverse ASCII string.
  /*!
      Reverse order of the ASCII string characters.
  */
  void reverse();
  //! Convert ASCII string to lower case.
  /*!
      Convert case of each character in ASCII string to lower case.
  */
  void toLowerCase();
  //! Convert ASCII string to upper case.
  /*!
      Convert case of each character in ASCII string to upper case.
  */
  void toUpperCase();
  //! Convert ASCII string to title case.
  /*!
      Convert case of each character in ASCII string to title case.
  */
  void toTitleCase();
  //! Convert ASCII string to toggle case.
  /*!
      Convert case of each character in ASCII string to toggle case.
  */
  void toToggleCase();

  //! Resize ASCII string to the given size.
  /*!
      Method updates ASCII string to the given size.

      \param a_cSize - New ASCII string size (in ASCII characters).
      \param a_cValue - Initialize value (default is ASC('\\0')).
      \return true  - if ASCII string was successfully resized. \n
              false - if ASCII string was not successfully resized. \n
  */
  Tbool resize(const Tuint a_cSize, const Tschar a_cValue = ASC('\0'));
  //! Resize ASCII string by given size.
  /*!
      Method updates ASCII string by adding/removing given size.

      \param a_cSize - Additional ASCII string size (may be less than 0).
      \param a_cValue - Initialize value (default is ASC('\\0')).
      \return true  - if ASCII string was successfully resized. \n
              false - if ASCII string was not successfully resized. \n
  */
  Tbool resizeBy(const Tsint a_cSize, const Tschar a_cValue = ASC('\0'));

  //! Replace sub-string of the current ASCII string with another one.
  /*!
      \param a_cIndex - Index of the replaced sub-string.
      \param a_cSize - Size of the replaced sub-string (in ASCII characters).
      \param a_crString - Constant reference to replacement instance of the CStringASCII class.
      \return true  - if sub-string was replaced successfully. \n
              false - if sub-string was not replaced successfully. \n
  */
  Tbool replace(const Tuint a_cIndex, const Tuint a_cSize, const CStringASCII& a_crString);

  //! Insert 'C' zero ASC('\\0') at the end of the ASCII string.
  /*!
      \return true  - if 'C' zero was inserted successfully. \n
              false - if 'C' zero was not inserted successfully. \n
  */
  Tbool insertCEnd();
  //! Remove 'C' zero ASC('\\0') from the end of the ASCII string.
  /*!
      \return true  - if 'C' zero was removed successfully. \n
              false - if 'C' zero was not found at the end of the string. \n
  */
  Tbool removeCEnd();

  //! Compare two ASCII strings taken into account their cases.
  /*!
      Method  returns  value  less  than  0  if   the   first   ASCII   string
      lexicographically less than the second one. Method returns  value  great
      than 0 if the first ASCII string lexicographically great than the second
      one. Method returns 0 if the first ASCII string lexicographically equals
      to the second one.

      If sizes  of  the  ASCII  strings  are  different,  method  returns  the
      difference between the first ASCII string size and the second one.

      If sizes of the ASCII strings are equal, method returns  the  difference
      between the first two different characters on a same place in the  ASCII
      strings.

      \param a_crString1 - Constant reference to the first ASCII string.
      \param a_crString2 - Constant reference to the second ASCII string.
      \return One of the following values: \n
              <0 - if the first ASCII string is lexicographically less than the second one. \n
              =0 - two ASCII strings are equal. \n
              >0 - if the first ASCII string is lexicographically great than the second one. \n
  */
  static Tsint compare(const CStringASCII& a_crString1, const CStringASCII& a_crString2);
  //! Compare two ASCII strings ignoring their cases.
  /*!
      Method  returns  value  less  than  0  if   the   first   ASCII   string
      lexicographically less than the second one. Method returns  value  great
      than 0 if the first ASCII string lexicographically great than the second
      one. Method returns 0 if the first ASCII string lexicographically equals
      to the second one.

      If sizes  of  the  ASCII  strings  are  different,  method  returns  the
      difference between the first ASCII string size and the second one.

      If sizes of the ASCII strings are equal, method returns  the  difference
      between the first two different characters in lowercase on a same  place
      in the ASCII strings.

      \param a_crString1 - Constant reference to the first ASCII string.
      \param a_crString2 - Constant reference to the second ASCII string.
      \return One of the following values: \n
              <0 - if the first ASCII string is lexicographically less than the second one. \n
              =0 - two ASCII strings are equal. \n
              >0 - if the first ASCII string is lexicographically great than the second one. \n
  */
  static Tsint compareIgnoreCase(const CStringASCII& a_crString1, const CStringASCII& a_crString2);

  //! Serialization load CStringASCII class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CStringASCII class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CStringASCII class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringASCII class instances.
  /*!
      \param a_rInstance - Reference to another CStringASCII class instance.
  */
  void swap(CStringASCII& a_rInstance);

private:
  Tuint m_Size;                         //!< ASCII string size.
  Tuint m_HiCapacity;                   //!< ASCII string higher capacity bound.
  Tsstr m_pBuffer;                      //!< ASCII string buffer.

  //! Get count of ASCII encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getASCIICharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);

  //! Count required buffer size to convert characters from ASCII encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool ASCIIToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-8 encoding into ASCII encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToASCIICount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Convert characters from ASCII encoding into UTF-8 encoding.
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
  static Tbool ASCIIToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-8 encoding into ASCII encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerASCIIChar().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF8ToASCII(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
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
//! Traits meta-class: ASCII string container traits specialization.
template <>
class MTraitsContainer<NString::CStringASCII> :
  public MType<NString::CStringASCII>
{
public:
  //! Container value type.
  typedef NString::CStringASCII::TType value;
  //! Container type.
  typedef NString::CStringASCII::TContainer container;
  //! Container non constant iterator type.
  typedef NString::CStringASCII::TIterator iterator;
  //! Container constant iterator type.
  typedef NString::CStringASCII::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = true;  //!< Is container non constant queue?
  static const Tbool isQueueConst       = true;  //!< Is container constant queue?
  static const Tbool isDeque            = true;  //!< Is container non constant deque?
  static const Tbool isDequeConst       = true;  //!< Is container constant deque?
  static const Tbool isRandom           = true;  //!< Is container non constant random?
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
#include <Depth/include/string/iterators/CStringASCIIIterator.hpp>
#include <Depth/include/string/iterators/CStringASCIIIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/string/CStringUnicode.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/string/CStringASCII.inl>
/*==========================================================================*/
//! \example example-string-CStringASCII.cpp
/*--------------------------------------------------------------------------*/
//! \test test-string-CStringASCII.cpp
/*==========================================================================*/
#endif
