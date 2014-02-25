/*!
 *  \file    CStringUnicode.hpp Unicode string class provides base string
 *           functionality in the Unicode encoding.
 *  \brief   Unicode string class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode string class.

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
#ifndef __CSTRINGUNICODE_HPP__
#define __CSTRINGUNICODE_HPP__
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
class CStringUnicodeIterator;
class CStringUnicodeIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
class CStringASCII;
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Unicode string class.
/*!
    Unicode string class provides base string  functionality  in  the  Unicode
    encoding.
*/
class BASE_API CStringUnicode :
  public NCommon::NContainers::IRandom<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>,
  public NCommon::NContainers::IRandomConst<CStringUnicode, Twchar, CStringUnicodeIterator, CStringUnicodeIteratorConst>
{
  // Friend class: Unicode string iterator class (CStringUnicodeIterator).
  friend class NDepth::NString::NIterators::CStringUnicodeIterator;
  // Friend class: Constant Unicode string iterator class (CStringUnicodeIteratorConst).
  friend class NDepth::NString::NIterators::CStringUnicodeIteratorConst;
  // Friend class: ASCII string class (CStringASCII).
  friend class CStringASCII;

  //! Type for the MConceptDepthType constraint checking.
  typedef CStringUnicode TDepthCheckType;

  // Check CStringUnicode class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef Twchar TType;
  //! Container type.
  typedef CStringUnicode TContainer;
  //! Non constant Unicode string iterator type.
  typedef CStringUnicodeIterator TIterator;
  //! Constant Unicode string iterator type.
  typedef CStringUnicodeIteratorConst TIteratorConst;

  static const CStringUnicode EMPTY;    //!< Empty Unicode string.

  //! Default class constructor.
  /*!
      Creates empty Unicode string without or with '\\0' terminated character.

      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CStringUnicode(const Tbool a_cAppendZero = false);
  //! Initialize Unicode string with the given single ASCII character.
  /*!
      \param a_cASCIICharacter - ASCII character.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CStringUnicode(const Tschar a_cASCIICharacter, const Tbool a_cAppendZero = false);
  //! Initialize Unicode string with the given single Unicode character.
  /*!
      \param a_cUnicodeCharacter - Unicode character.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CStringUnicode(const Twchar a_cUnicodeCharacter, const Tbool a_cAppendZero = false);
  //! Initialize Unicode string with the given ASCII 'C' string.
  /*!
      \param a_cpASCIIString - ASCII 'C' string.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CStringUnicode(Tcsstr a_cpASCIIString, const Tbool a_cAppendZero = false);
  //! Initialize Unicode string with the given Unicode 'C' string.
  /*!
      \param a_cpUnicodeString - Unicode 'C' string.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
  */
  CStringUnicode(Tcwstr a_cpUnicodeString, const Tbool a_cAppendZero = false);
  //! Initialize Unicode string with the given buffer of fixed size in ASCII encoding.
  /*!
      \param a_cpBuffer - Buffer of fixed size in ASCII encoding.
      \param a_cSize - Size of the buffer.
  */
  CStringUnicode(Tcsstr a_cpBuffer, const Tuint a_cSize);
  //! Initialize Unicode string with the given buffer of fixed size in Unicode encoding.
  /*!
      \param a_cpBuffer - Buffer of fixed size in Unicode encoding.
      \param a_cSize - Size of the buffer.
  */
  CStringUnicode(Tcwstr a_cpBuffer, const Tuint a_cSize);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSystemString class.
  */
  CStringUnicode(const CSystemString& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringASCII class.
  */
  CStringUnicode(const CStringASCII& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringUnicode class.
  */
  CStringUnicode(const CStringUnicode& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStringUnicode();

  //! Operator: Equal to another CStringUnicode class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringUnicode class.
      \param a_crInstance2 - Constant reference to another instance of the CStringUnicode class.
      \return true  - if CStringUnicode class instance is equal to another one. \n
              false - if CStringUnicode class instance is not equal to another one. \n
  */
  friend BASE_API Tbool operator == (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2);
  //! Operator: Not equal to another CStringUnicode class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringUnicode class.
      \param a_crInstance2 - Constant reference to another instance of the CStringUnicode class.
      \return true  - if CStringUnicode class instance is not equal to another one. \n
              false - if CStringUnicode class instance is equal to another one. \n
  */
  friend BASE_API Tbool operator != (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2);

  //! Operator: Lexicographically less than another CStringUnicode class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringUnicode class.
      \param a_crInstance2 - Constant reference to another instance of the CStringUnicode class.
      \return true  - if CStringUnicode class instance is lexicographically less than another one. \n
              false - if CStringUnicode class instance is not lexicographically less than another one. \n
  */
  friend BASE_API Tbool operator < (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2);
  //! Operator: Lexicographically more than another CStringUnicode class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringUnicode class.
      \param a_crInstance2 - Constant reference to another instance of the CStringUnicode class.
      \return true  - if CStringUnicode class instance is lexicographically more than another one. \n
              false - if CStringUnicode class instance is not lexicographically more than another one. \n
  */
  friend BASE_API Tbool operator > (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2);
  //! Operator: Lexicographically less or equal than another CStringUnicode class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringUnicode class.
      \param a_crInstance2 - Constant reference to another instance of the CStringUnicode class.
      \return true  - if CStringUnicode class instance is lexicographically less or equal than another one. \n
              false - if CStringUnicode class instance is not lexicographically less or equal than another one. \n
  */
  friend BASE_API Tbool operator <= (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2);
  //! Operator: Lexicographically more or equal than another CStringUnicode class instance.
  /*!
      \param a_crInstance1 - Constant reference to the current instance of the CStringUnicode class.
      \param a_crInstance2 - Constant reference to another instance of the CStringUnicode class.
      \return true  - if CStringUnicode class instance is lexicographically more or equal than another one. \n
              false - if CStringUnicode class instance is not lexicographically more or equal than another one. \n
  */
  friend BASE_API Tbool operator >= (const CStringUnicode& a_crInstance1, const CStringUnicode& a_crInstance2);

  //! Operator: Append another Unicode string to the end position of the current one.
  /*!
      \param a_crInstance - Constant reference to the current instance of the CStringUnicode class.
      \param a_crString - Constant reference to another instance of the CStringUnicode class.
      \return New instance of CStringUnicode class with appended Unicode string.
  */
  friend BASE_API CStringUnicode operator + (const CStringUnicode& a_crInstance, const CStringUnicode& a_crString);

  //! Operator: Assign single ASCII character.
  /*!
      \param a_cASCIICharacter - ASCII character.
      \return Reference to the current class instance.
  */
  CStringUnicode& operator = (const Tschar a_cASCIICharacter);
  //! Operator: Assign single Unicode character.
  /*!
      \param a_cUnicodeCharacter - Unicode character.
      \return Reference to the current class instance.
  */
  CStringUnicode& operator = (const Twchar a_cUnicodeCharacter);
  //! Operator: Assign ASCII 'C' string.
  /*!
      \param a_cpASCIIString - ASCII 'C' string.
      \return Reference to the current class instance.
  */
  CStringUnicode& operator = (Tcsstr a_cpASCIIString);
  //! Operator: Assign Unicode 'C' string.
  /*!
      \param a_cpUnicodeString - Unicode 'C' string.
      \return Reference to the current class instance.
  */
  CStringUnicode& operator = (Tcwstr a_cpUnicodeString);
  //! Operator: Assign another CSystemString class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSystemString class.
      \return Reference to the current class instance.
  */
  CStringUnicode& operator = (const CSystemString& a_crInstance);
  //! Operator: Assign another CStringASCII class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringASCII class.
      \return Reference to the current class instance.
  */
  CStringUnicode& operator = (const CStringASCII& a_crInstance);
  //! Operator: Assign another CStringUnicode class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStringUnicode class.
      \return Reference to the current class instance.
  */
  CStringUnicode& operator = (const CStringUnicode& a_crInstance);

  //! Operator: Append another Unicode string to the end position of the current one.
  /*!
      \param a_crString - Constant reference to another instance of the CStringUnicode class.
      \return Reference to the current class instance.
  */
  CStringUnicode& operator += (const CStringUnicode& a_crString);

  //! Operator: Indexing into the non constant Unicode string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Non constant reference to Unicode string item under the given index.
  */
  Twchar& operator [] (const Tsint a_cIndex);
  //! Operator: Indexing into the non constant Unicode string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Non constant reference to Unicode string item under the given index.
  */
  Twchar& operator [] (const Tuint a_cIndex);
  //! Operator: Indexing into the constant Unicode string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Constant reference to Unicode string item under the given index.
  */
  const Twchar& operator [] (const Tsint a_cIndex) const;
  //! Operator: Indexing into the constant Unicode string buffer.
  /*!
      \param a_cIndex - Indexed pointer position to return.
      \return Constant reference to Unicode string item under the given index.
  */
  const Twchar& operator [] (const Tuint a_cIndex) const;

  //! Operator: Get pointer to the Unicode string buffer.
  /*!
      \return Pointer to the Unicode string buffer.
      \see NDepth::NString::CStringUnicode::getBuffer()
  */
  operator Twstr ();
  //! Operator: Get constant pointer to the Unicode string buffer.
  /*!
      \return Constant pointer to the Unicode string buffer.
      \see NDepth::NString::CStringUnicode::getBuffer()
  */
  operator Tcwstr () const;

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

  //! Get system string with or without '\\0' terminated character based on the current Unicode string.
  /*!
      \param a_rSystemString - Reference to the system string.
      \param a_cAppendZero - Append '\\0' terminated character (default is false).
      \return true  - if Unicode string was successfully converted to the system string. \n
              false - if Unicode string was not successfully converted to the system string. \n
  */
  Tbool getSystemString(CSystemString& a_rSystemString, const Tbool a_cAppendZero = false) const;

  //! Get Unicode string free size.
  /*!
      Method returns count of free characters in the Unicode string.

      \return Count of free characters in the Unicode string.
  */
  Tuint getFreeSize() const;

  //! Get Unicode string lower capacity bound value.
  /*!
      Method returns lower bound size value before Unicode string reallocation.

      \return Unicode string lower capacity bound value.
  */
  Tuint getLoCapacity() const;
  //! Get Unicode string higher capacity bound value.
  /*!
      Method returns higher bound size value before Unicode string reallocation.

      \return Unicode string higher capacity bound value.
  */
  Tuint getHiCapacity() const;

  //! Get ponter to the Unicode string buffer.
  /*!
      Method returns pointer to the  Unicode  string  buffer.  Using  of  this
      pointer is quite dangerous cause it may lead to memory errors.  That  is
      why you always have to check  string  bounds  while  working  with  this
      pointer.

      \return Pointer to the Unicode string buffer.
  */
  Twstr getBuffer();
  //! Get constant ponter to the Unicode string buffer.
  /*!
      Method returns constant pointer to the Unicode string buffer.  Using  of
      this pointer is quite dangerous cause it may lead to memory errors. That
      is why you always have to check string bounds while  working  with  this
      pointer.

      \return Constant pointer to the Unicode string buffer.
  */
  Tcwstr getBuffer() const;

  //! Get left sub-string from the current Unicode string.
  /*!
      \param a_cSize - Size of the left sub-string (in Unicode characters).
      \return Left sub-string.
  */
  CStringUnicode getLeft(const Tuint a_cSize) const;
  //! Get right sub-string from the current Unicode string.
  /*!
      \param a_cSize - Size of the right sub-string (in Unicode characters).
      \return Right sub-string.
  */
  CStringUnicode getRight(const Tuint a_cSize) const;
  //! Get middle sub-string from the current Unicode string.
  /*!
      \param a_cIndex - Index of middle sub-string.
      \param a_cSize - Size of the middle sub-string (in Unicode characters).
      \return Middle sub-string.
  */
  CStringUnicode getMiddle(const Tuint a_cIndex, const Tuint a_cSize) const;

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IRandom interface overriding methods.
  virtual Tbool insertFirst(const Twchar& a_crItem);
  virtual Tbool insertFirst(const CStringUnicode& a_crItem);
  virtual Tbool insertLast(const Twchar& a_crItem);
  virtual Tbool insertLast(const CStringUnicode& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const Twchar& a_crItem);
  virtual Tbool insertIndex(const Tuint a_cIndex, const CStringUnicode& a_crItem);
  virtual Tbool removeFirst();
  virtual Tbool removeFirst(Twchar& a_rItem);
  virtual Tbool removeFirst(const Tuint a_cSize);
  virtual Tbool removeFirst(const Tuint a_cSize, CStringUnicode& a_rItem);
  virtual Tbool removeLast();
  virtual Tbool removeLast(Twchar& a_rItem);
  virtual Tbool removeLast(const Tuint a_cSize);
  virtual Tbool removeLast(const Tuint a_cSize, CStringUnicode& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex);
  virtual Tbool removeIndex(const Tuint a_cIndex, Twchar& a_rItem);
  virtual Tbool removeIndex(const Tuint a_cIndex, const Tuint a_cSize);
  virtual Tbool removeIndex(const Tuint a_cIndex, const Tuint a_cSize, CStringUnicode& a_rItem);
  virtual Tbool remove(const Tuint a_cIndex, const Tuint a_cSize);

  // IRandomConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;
  virtual TIterator      getItIndex(const Tuint a_cIndex);
  virtual TIteratorConst getItIndex(const Tuint a_cIndex) const;

  //! Reverse Unicode string.
  /*!
      Reverse order of the Unicode string characters.
  */
  void reverse();
  //! Convert Unicode string to lower case.
  /*!
      Convert case of each character in Unicode string to lower case.
  */
  void toLowerCase();
  //! Convert Unicode string to upper case.
  /*!
      Convert case of each character in Unicode string to upper case.
  */
  void toUpperCase();
  //! Convert Unicode string to title case.
  /*!
      Convert case of each character in Unicode string to title case.
  */
  void toTitleCase();
  //! Convert Unicode string to toggle case.
  /*!
      Convert case of each character in Unicode string to toggle case.
  */
  void toToggleCase();

  //! Resize Unicode string to the given size.
  /*!
      Method updates Unicode string to the given size.

      \param a_cSize - New Unicode string size (in Unicode characters).
      \param a_cValue - Initialize value (default is UNC('\\0')).
      \return true  - if Unicode string was successfully resized. \n
              false - if Unicode string was not successfully resized. \n
  */
  Tbool resize(const Tuint a_cSize, const Twchar a_cValue = UNC('\0'));
  //! Resize Unicode string by given size.
  /*!
      Method updates Unicode string by adding/removing given size.

      \param a_cSize - Additional Unicode string size (may be less than 0).
      \param a_cValue - Initialize value (default is UNC('\\0')).
      \return true  - if Unicode string was successfully resized. \n
              false - if Unicode string was not successfully resized. \n
  */
  Tbool resizeBy(const Tsint a_cSize, const Twchar a_cValue = UNC('\0'));

  //! Replace sub-string of the current Unicode string with another one.
  /*!
      \param a_cIndex - Index of the replaced sub-string.
      \param a_cSize - Size of the replaced sub-string (in Unicode characters).
      \param a_crString - Constant reference to replacement instance of the CStringUnicode class.
      \return true  - if sub-string was replaced successfully. \n
              false - if sub-string was not replaced successfully. \n
  */
  Tbool replace(const Tuint a_cIndex, const Tuint a_cSize, const CStringUnicode& a_crString);

  //! Insert 'C' zero UNC('\\0') at the end of the Unicode string.
  /*!
      \return true  - if 'C' zero was inserted successfully. \n
              false - if 'C' zero was not inserted successfully. \n
  */
  Tbool insertCEnd();
  //! Remove 'C' zero UNC('\\0') from the end of the Unicode string.
  /*!
      \return true  - if 'C' zero was removed successfully. \n
              false - if 'C' zero was not found at the end of the string. \n
  */
  Tbool removeCEnd();

  //! Compare two Unicode strings taken into account their cases.
  /*!
      Method  returns  value  less  than  0  if  the  first   Unicode   string
      lexicographically less than the second one. Method returns  value  great
      than 0 if the first Unicode  string  lexicographically  great  than  the
      second  one.  Method   returns   0   if   the   first   Unicode   string
      lexicographically equals to the second one.

      If sizes of the  Unicode  strings  are  different,  method  returns  the
      difference between the first Unicode string size and the second one.

      If sizes of the Unicode strings are equal, method returns the difference
      between the first two different  characters  on  a  same  place  in  the
      Unicode strings.

      \param a_crString1 - Constant reference to the first Unicode string.
      \param a_crString2 - Constant reference to the second Unicode string.
      \return One of the following values: \n
              <0 - if the first Unicode string is lexicographically less than the second one. \n
              =0 - two Unicode strings are equal. \n
              >0 - if the first Unicode string is lexicographically great than the second one. \n
  */
  static Tsint compare(const CStringUnicode& a_crString1, const CStringUnicode& a_crString2);
  //! Compare two Unicode strings ignoring their cases.
  /*!
      Method  returns  value  less  than  0  if  the  first   Unicode   string
      lexicographically less than the second one. Method returns  value  great
      than 0 if the first Unicode  string  lexicographically  great  than  the
      second  one.  Method   returns   0   if   the   first   Unicode   string
      lexicographically equals to the second one.

      If sizes of the  Unicode  strings  are  different,  method  returns  the
      difference between the first Unicode string size and the second one.

      If sizes of the Unicode strings are equal, method returns the difference
      between the first two different characters in lowercase on a same  place
      in the Unicode strings.

      \param a_crString1 - Constant reference to the first Unicode string.
      \param a_crString2 - Constant reference to the second Unicode string.
      \return One of the following values: \n
              <0 - if the first Unicode string is lexicographically less than the second one. \n
              =0 - two Unicode strings are equal. \n
              >0 - if the first Unicode string is lexicographically great than the second one. \n
  */
  static Tsint compareIgnoreCase(const CStringUnicode& a_crString1, const CStringUnicode& a_crString2);

  //! Serialization load CStringUnicode class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CStringUnicode class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CStringUnicode class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStringUnicode class instances.
  /*!
      \param a_rInstance - Reference to another CStringUnicode class instance.
  */
  void swap(CStringUnicode& a_rInstance);

private:
  Tuint m_Size;                         //!< Unicode string size.
  Tuint m_HiCapacity;                   //!< Unicode string higher capacity bound.
  Twstr m_pBuffer;                      //!< Unicode string buffer.

  //! Get count of Unicode encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getUnicodeCharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);

  //! Count required buffer size to convert characters from Unicode encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UnicodeToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-8 encoding into Unicode encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToUnicodeCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Convert characters from Unicode encoding into UTF-8 encoding.
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
  static Tbool UnicodeToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-8 encoding into Unicode encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUnicodeChar().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF8ToUnicode(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
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
//! Traits meta-class: Unicode string container traits specialization.
template <>
class MTraitsContainer<NString::CStringUnicode> :
  public MType<NString::CStringUnicode>
{
public:
  //! Container value type.
  typedef NString::CStringUnicode::TType value;
  //! Container type.
  typedef NString::CStringUnicode::TContainer container;
  //! Container non constant iterator type.
  typedef NString::CStringUnicode::TIterator iterator;
  //! Container constant iterator type.
  typedef NString::CStringUnicode::TIteratorConst citerator;

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
#include <Depth/include/string/iterators/CStringUnicodeIterator.hpp>
#include <Depth/include/string/iterators/CStringUnicodeIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/string/CStringASCII.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/string/CStringUnicode.inl>
/*==========================================================================*/
//! \example example-string-CStringUnicode.cpp
/*--------------------------------------------------------------------------*/
//! \test test-string-CStringUnicode.cpp
/*==========================================================================*/
#endif
