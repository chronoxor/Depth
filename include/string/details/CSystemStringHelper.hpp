/*!
 *  \file    CSystemStringHelper.hpp System string helper class contains
 *           strings encoding functionality.
 *  \brief   System string helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: System string helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String details
    VERSION:   1.0
    CREATED:   01.04.2008 21:27:16

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
#ifndef __CSYSTEMSTRINGHELPER_HPP__
#define __CSYSTEMSTRINGHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS IN OTHER NAMESPACE                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*--------------------------------------------------------------------------*/
class CSystemBase;
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! System string helper class.
/*!
    System string helper class contains utility methods for string  converting
    from/for the following encoding: UCS1, UCS2, UCS4, UTF8, UTF16, UTF32.
*/
class BASE_API CSystemStringHelper :
  public NDepth::NCommon::IStatic
{
  // Friend class: Base system class (CSystemBase).
  friend class NDepth::NSystem::CSystemBase;

public:
  //! Get maximum count of bytes per single ASCII character.
  /*!
      \return Maximum count of bytes per single ASCII character.
  */
  static Tuint getMaxBytesPerASCIIChar();
  //! Get maximum count of bytes per single Unicode character.
  /*!
      \return Maximum count of bytes per single Unicode character.
  */
  static Tuint getMaxBytesPerUnicodeChar();
  //! Get maximum count of bytes per single system character.
  /*!
      \return Maximum count of bytes per single system character.
  */
  static Tuint getMaxBytesPerSystemChar();

  //! Get count of ASCII encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getASCIICharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);
  //! Get count of Unicode encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getUnicodeCharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);
  //! Get count of system encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getSystemCharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);

  //! Count required buffer size to convert characters from ASCII encoding into system encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool ASCIIToSystemCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from Unicode encoding into system encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UnicodeToSystemCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-8 encoding into system encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToSystemCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from ASCII encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool ASCIIToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from Unicode encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UnicodeToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Count required buffer size to convert characters from system encoding into ASCII encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool SystemToASCIICount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from system encoding into Unicode encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool SystemToUnicodeCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from system encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool SystemToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-8 encoding into ASCII encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToASCIICount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-8 encoding into Unicode encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToUnicodeCount(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Convert characters from ASCII encoding into system encoding.
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
  static Tbool ASCIIToSystem(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from Unicode encoding into system encoding.
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
  static Tbool UnicodeToSystem(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
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

  //! Convert characters from system encoding into ASCII encoding.
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
  static Tbool SystemToASCII(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from system encoding into Unicode encoding.
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
  static Tbool SystemToUnicode(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
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

private:
  //! Get maximum bytes per character function type.
  typedef Tuint (*TGetMaxBytesFunction)();
  //! Get count of encoded characters in the buffer with fixed length function type.
  typedef Tbool (*TGetCharsCountFunction)(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);
  //! Count required buffer size to characters convert from one encoding into another one function type.
  typedef Tbool (*TEncodingCountFunction)(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from one encoding into another one function type.
  typedef Tbool (*TEncodingConvertFunction)(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  static TGetMaxBytesFunction ms_fGetMaxBytesPerASCIIChar;   //! Function pointer to get maximum bytes per ASCII character.
  static TGetMaxBytesFunction ms_fGetMaxBytesPerUnicodeChar; //! Function pointer to get maximum bytes per Unicode character.
  static TGetMaxBytesFunction ms_fGetMaxBytesPerSystemChar;  //! Function pointer to get maximum bytes per system character.

  static TGetCharsCountFunction ms_fGetASCIICharsCount;      //! Function pointer to get count of ASCII encoded characters in the buffer with fixed length.
  static TGetCharsCountFunction ms_fGetUnicodeCharsCount;    //! Function pointer to get count of Unicode encoded characters in the buffer with fixed length.
  static TGetCharsCountFunction ms_fGetSystemCharsCount;     //! Function pointer to get count of system encoded characters in the buffer with fixed length.

  static TEncodingCountFunction ms_fASCIIToSystemCount;      //! Function pointer to count required buffer size to convert ASCII encoded characters to system ones.
  static TEncodingCountFunction ms_fUnicodeToSystemCount;    //! Function pointer to count required buffer size to convert Unicode encoded characters to system ones.
  static TEncodingCountFunction ms_fUTF8ToSystemCount;       //! Function pointer to count required buffer size to convert UTF-8 encoded characters to system ones.
  static TEncodingCountFunction ms_fASCIIToUTF8Count;        //! Function pointer to count required buffer size to convert ASCII encoded characters to UTF-8 ones.
  static TEncodingCountFunction ms_fUnicodeToUTF8Count;      //! Function pointer to count required buffer size to convert Unicode encoded characters to UTF-8 ones.
  static TEncodingCountFunction ms_fSystemToASCIICount;      //! Function pointer to count required buffer size to convert system encoded characters to ASCII ones.
  static TEncodingCountFunction ms_fSystemToUnicodeCount;    //! Function pointer to count required buffer size to convert system encoded characters to Unicode ones.
  static TEncodingCountFunction ms_fSystemToUTF8Count;       //! Function pointer to count required buffer size to convert system encoded characters to UTF-8 ones.
  static TEncodingCountFunction ms_fUTF8ToASCIICount;        //! Function pointer to count required buffer size to convert UTF-8 encoded characters to ASCII ones.
  static TEncodingCountFunction ms_fUTF8ToUnicodeCount;      //! Function pointer to count required buffer size to convert UTF-8 encoded characters to Unicode ones.

  static TEncodingConvertFunction ms_fASCIIToSystem;         //! Function pointer to convert ASCII encoded characters to system ones.
  static TEncodingConvertFunction ms_fUnicodeToSystem;       //! Function pointer to convert Unicode encoded characters to system ones.
  static TEncodingConvertFunction ms_fASCIIToUTF8;           //! Function pointer to convert ASCII encoded characters to UTF-8 ones.
  static TEncodingConvertFunction ms_fUnicodeToUTF8;         //! Function pointer to convert Unicode encoded characters to UTF-8 ones.
  static TEncodingConvertFunction ms_fUTF8ToSystem;          //! Function pointer to convert UTF-8 encoded characters to system ones.
  static TEncodingConvertFunction ms_fSystemToASCII;         //! Function pointer to convert system encoded characters to ASCII ones.
  static TEncodingConvertFunction ms_fSystemToUnicode;       //! Function pointer to convert system encoded characters to Unicode ones.
  static TEncodingConvertFunction ms_fSystemToUTF8;          //! Function pointer to convert system encoded characters to UTF-8 ones.
  static TEncodingConvertFunction ms_fUTF8ToASCII;           //! Function pointer to convert UTF-8 encoded characters to ASCII ones.
  static TEncodingConvertFunction ms_fUTF8ToUnicode;         //! Function pointer to convert UTF-8 encoded characters to Unicode ones.

  //! Get maximum count of bytes per single UCS-1 character.
  /*!
      \return Maximum count of bytes per single UCS-1 character.
  */
  static Tuint getMaxBytesPerUCS1Char();
  //! Get maximum count of bytes per single UCS-2 character.
  /*!
      \return Maximum count of bytes per single UCS-2 character.
  */
  static Tuint getMaxBytesPerUCS2Char();
  //! Get maximum count of bytes per single UCS-4 character.
  /*!
      \return Maximum count of bytes per single UCS-4 character.
  */
  static Tuint getMaxBytesPerUCS4Char();
  //! Get maximum count of bytes per single UTF-8 character.
  /*!
      \return Maximum count of bytes per single UTF-8 character.
  */
  static Tuint getMaxBytesPerUTF8Char();
  //! Get maximum count of bytes per single UTF-16 character.
  /*!
      \return Maximum count of bytes per single UTF-16 character.
  */
  static Tuint getMaxBytesPerUTF16Char();
  //! Get maximum count of bytes per single UTF-32 character.
  /*!
      \return Maximum count of bytes per single UTF-32 character.
  */
  static Tuint getMaxBytesPerUTF32Char();

  //! Get count of UCS-1 encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getUCS1CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);
  //! Get count of UCS-2 encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getUCS2CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);
  //! Get count of UCS-4 encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getUCS4CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);
  //! Get count of UTF-8 encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getUTF8CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);
  //! Get count of UTF-16 encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getUTF16CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);
  //! Get count of UTF-32 encoded characters in the buffer with fixed length.
  /*!
      \param a_cpBuffer - Constant pointer to buffer with characters.
      \param a_cSize - Size of source buffer.
      \param a_rCount - Result count value (in characters).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool getUTF32CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount);

  //! Count required buffer size to convert characters from UCS-1 encoding into UCS-1 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS1ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-1 encoding into UCS-2 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS1ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-1 encoding into UCS-4 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS1ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-1 encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS1ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-1 encoding into UTF-16 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS1ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-1 encoding into UTF-32 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS1ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Count required buffer size to convert characters from UCS-2 encoding into UCS-1 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS2ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-2 encoding into UCS-2 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS2ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-2 encoding into UCS-4 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS2ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-2 encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS2ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-2 encoding into UTF-16 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS2ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-2 encoding into UTF-32 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS2ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Count required buffer size to convert characters from UCS-4 encoding into UCS-1 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS4ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-4 encoding into UCS-2 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS4ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-4 encoding into UCS-4 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS4ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-4 encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS4ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-4 encoding into UTF-16 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS4ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UCS-4 encoding into UTF-32 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UCS4ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Count required buffer size to convert characters from UTF-8 encoding into UCS-1 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-8 encoding into UCS-2 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-8 encoding into UCS-4 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-8 encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-8 encoding into UTF-16 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-8 encoding into UTF-32 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF8ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Count required buffer size to convert characters from UTF-16 encoding into UCS-1 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF16ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-16 encoding into UCS-2 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF16ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-16 encoding into UCS-4 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF16ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-16 encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF16ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-16 encoding into UTF-16 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF16ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-16 encoding into UTF-32 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF16ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Count required buffer size to convert characters from UTF-32 encoding into UCS-1 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF32ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-32 encoding into UCS-2 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF32ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-32 encoding into UCS-4 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF32ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-32 encoding into UTF-8 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF32ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-32 encoding into UTF-16 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF32ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Count required buffer size to convert characters from UTF-32 encoding into UTF-32 encoding.
  /*!
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to required buffer size (in bytes).
      \return true  - if counting was successful. \n
              false - if counting was not successful. \n
  */
  static Tbool UTF32ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Convert characters from UCS-1 encoding into UCS-1 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS1Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS1ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-1 encoding into UCS-2 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS2Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS1ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-1 encoding into UCS-4 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS4Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS1ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-1 encoding into UTF-8 encoding.
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
  static Tbool UCS1ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-1 encoding into UTF-16 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF16Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS1ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-1 encoding into UTF-32 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF32Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS1ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Convert characters from UCS-2 encoding into UCS-1 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS1Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS2ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-2 encoding into UCS-2 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS2Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS2ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-2 encoding into UCS-4 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS4Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS2ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-2 encoding into UTF-8 encoding.
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
  static Tbool UCS2ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-2 encoding into UTF-16 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF16Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS2ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-2 encoding into UTF-32 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF32Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS2ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Convert characters from UCS-4 encoding into UCS-1 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS1Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS4ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-4 encoding into UCS-2 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS2Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS4ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-4 encoding into UCS-4 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS4Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS4ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-4 encoding into UTF-8 encoding.
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
  static Tbool UCS4ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-4 encoding into UTF-16 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF16Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS4ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UCS-4 encoding into UTF-32 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF32Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UCS4ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Convert characters from UTF-8 encoding into UCS-1 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS1Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF8ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-8 encoding into UCS-2 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS2Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF8ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-8 encoding into UCS-4 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS4Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF8ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-8 encoding into UTF-8 encoding.
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
  static Tbool UTF8ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-8 encoding into UTF-16 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF16Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF8ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-8 encoding into UTF-32 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF32Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF8ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Convert characters from UTF-16 encoding into UCS-1 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS1Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF16ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-16 encoding into UCS-2 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS2Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF16ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-16 encoding into UCS-4 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS4Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF16ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-16 encoding into UTF-8 encoding.
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
  static Tbool UTF16ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-16 encoding into UTF-16 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF16Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF16ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-16 encoding into UTF-32 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF32Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF16ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);

  //! Convert characters from UTF-32 encoding into UCS-1 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS1Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF32ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-32 encoding into UCS-2 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS2Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF32ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-32 encoding into UCS-4 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUCS4Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF32ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-32 encoding into UTF-8 encoding.
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
  static Tbool UTF32ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-32 encoding into UTF-16 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF16Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF32ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
  //! Convert characters from UTF-32 encoding into UTF-32 encoding.
  /*!
      This method is unsafe! Destination block must have  appropriate  size  -
      count * getMaxBytesPerUTF32Char().

      \param a_pDestination - Pointer to destination string block.
      \param a_cpSource - Constant pointer to source string block.
      \param a_cCount - Count of converting characters.
      \param a_rResult - Reference to count of successfully converted characters (in bytes).
      \return true  - if converting was successful. \n
              false - if converting was not successful. \n
  */
  static Tbool UTF32ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/details/CSystemStringHelper.inl>
/*==========================================================================*/
#endif
