/*!
 *  \file    CStreamHelper.hpp Stream helper class uses template method
 *           specialization to call read/peek and write/push stream methods.
 *  \brief   Stream helper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Stream helper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream details
    VERSION:   1.0
    CREATED:   04.09.2008 23:16:34

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
#ifndef __CSTREAMHELPER_HPP__
#define __CSTREAMHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/ACountOf.hpp>
#include <Depth/include/algorithms/common/AMax.hpp>
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/algorithms/numeric/AAbsolute.hpp>
#include <Depth/include/algorithms/string/buffer/AStrLen.hpp>
#include <Depth/include/base/CInteger.hpp>
#include <Depth/include/base/CPointer.hpp>
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/concept/base/MConceptInteger.hpp>
#include <Depth/include/concept/base/MConceptReal.hpp>
#include <Depth/include/concept/base/MConceptStringConst.inl>
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/stream/text/CStreamString.hpp>
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/traits/MGetSigned.hpp>
#include <Depth/include/traits/MGetUnsigned.hpp>
#include <Depth/include/traits/MIsUnsigned.hpp>
#include <Depth/include/traits/MTraitsString.hpp>
#include <Depth/include/utility/CPair.hpp>
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS IN OTHER NAMESPACE                            */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
class IReader;
class IWriter;
class IReaderWriter;
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Stream helper class.
/*!
    Stream helper class uses template method specialization to call  read/peek
    and write/push stream methods.
*/
class BASE_API CStreamHelper :
  public NDepth::NCommon::IStatic
{
public:
  //! Input bytes into the given buffer with fixed size.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_pBuffer - Pointer to the buffer.
      \param a_cSize - Size of the buffer (in bytes).
      \return Count of input bytes.
  */
  template <class T_Stream>
  static Tuint inputBuffer(const Tbool a_cPeekRead, T_Stream& a_rStream, Tptr a_pBuffer, const Tuint a_cSize);
  //! Input bytes into the given buffer with the byte order correction.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_pBuffer - Pointer to the buffer.
      \param a_cSingleSize - Size of the single item (in bytes).
      \param a_cCount - Count of the single items in the buffer.
      \return Count of input bytes.
  */
  template <class T_Stream>
  static Tuint inputBuffer(const Tbool a_cPeekRead, T_Stream& a_rStream, Tptr a_pBuffer, const Tuint a_cSingleSize, const Tuint a_cCount);
  //! Input ASCII characters into the given buffer with fixed size.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_pBuffer - Pointer to the ASCII characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of input characters.
  */
  template <class T_Stream>
  static Tuint inputBuffer(const Tbool a_cPeekRead, T_Stream& a_rStream, Tsstr a_pBuffer, const Tuint a_cSize);
  //! Input Unicode characters into the given buffer with fixed size.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_pBuffer - Pointer to the Unicode characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of input characters.
  */
  template <class T_Stream>
  static Tuint inputBuffer(const Tbool a_cPeekRead, T_Stream& a_rStream, Twstr a_pBuffer, const Tuint a_cSize);
  //! Input ASCII character.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_rCharacter - Reference to the ASCII character.
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputChar(const Tbool a_cPeekRead, T_Stream& a_rStream, Tschar& a_rCharacter);
  //! Input Unicode character.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_rCharacter - Reference to the Unicode character.
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputChar(const Tbool a_cPeekRead, T_Stream& a_rStream, Twchar& a_rCharacter);
  //! Input ASCII zero terminated C string.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_rpString - Reference to the ASCII zero terminated C string.
      \param a_cSize - Size of input string in characters. If 0 then input to line end (default is 0).
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputString(const Tbool a_cPeekRead, T_Stream& a_rStream, Tsstr& a_rpString, const Tuint a_cSize = 0);
  //! Input Unicode zero terminated C string.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_rpString - Reference to the Unicode zero terminated C string.
      \param a_cSize - Size of input string in characters. If 0 then input to line end (default is 0).
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputString(const Tbool a_cPeekRead, T_Stream& a_rStream, Twstr& a_rpString, const Tuint a_cSize = 0);
  //! Input ASCII string.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_rString - Reference to the ASCII string.
      \param a_cSize - Size of input string in characters. If 0 then input to line end (default is 0).
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputString(const Tbool a_cPeekRead, T_Stream& a_rStream, NString::CStringASCII& a_rString, const Tuint a_cSize = 0);
  //! Input Unicode string.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_rString - Reference to the Unicode string.
      \param a_cSize - Size of input string in characters. If 0 then input to line end (default is 0).
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputString(const Tbool a_cPeekRead, T_Stream& a_rStream, NString::CStringUnicode& a_rString, const Tuint a_cSize = 0);
  //! Input system string.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_rString - Reference to the system string.
      \param a_cSize - Size of input string in characters. If 0 then input to line end (default is 0).
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputString(const Tbool a_cPeekRead, T_Stream& a_rStream, NString::CSystemString& a_rString, const Tuint a_cSize = 0);
  //! Input boolean number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_rBoolean - Reference to the boolean number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputBool(const Tbool a_cPeekRead, T_Stream& a_rStream, Tbool& a_rBoolean, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Input integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_rInteger - Reference to the integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream, typename T_Integer>
  static NUtility::CPair<Tbool, Tuint> inputInteger(const Tbool a_cPeekRead, T_Stream& a_rStream, T_Integer& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Input real number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_rReal - Reference to the real number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream, typename T_Real>
  static NUtility::CPair<Tbool, Tuint> inputReal(const Tbool a_cPeekRead, T_Stream& a_rStream, T_Real& a_rReal, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Input pointer value.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_rpPointer - Reference to the pointer value.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputPointer(const Tbool a_cPeekRead, T_Stream& a_rStream, Tptr& a_rpPointer, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read formatted string using variable arguments list.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \param a_cpFormatString - Constant format string type.
      \param a_cFormatStringSize - Format string size (in characters).
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream, typename T_StringConst>
  static NUtility::CPair<Tbool, Tuint> inputFormat(const Tbool a_cPeekRead, T_Stream& a_rStream, T_StringConst a_cpFormatString, const Tuint a_cFormatStringSize, va_list a_VariableList);
  //! Input end of line symbols in ASCII encoding.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputLineEndASCII(const Tbool a_cPeekRead, T_Stream& a_rStream);
  //! Input end of line symbols in Unicode encoding.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputLineEndUnicode(const Tbool a_cPeekRead, T_Stream& a_rStream);
  //! Input and skip to end of line symbols in ASCII encoding.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputToLineEndASCII(const Tbool a_cPeekRead, T_Stream& a_rStream);
  //! Input and skip to end of line symbols in Unicode encoding.
  /*!
      \param a_cPeekRead - Peek/Read flag.
      \param a_rStream - Reference to the output stream.
      \return Successful flag and count of input bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> inputToLineEndUnicode(const Tbool a_cPeekRead, T_Stream& a_rStream);

  //! Output bytes from the given buffer with fixed size.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Size of the buffer (in bytes).
      \return Count of output bytes.
  */
  template <class T_Stream>
  static Tuint outputBuffer(T_Stream& a_rStream, Tcptr a_cpBuffer, const Tuint a_cSize);
  //! Output byte buffer with byte order correction.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_cpBuffer - Constant pointer to the byte buffer.
      \param a_cSingleSize - Size of the single item (in bytes).
      \param a_cCount - Count of the single items in the buffer.
      \return Count of output bytes.
  */
  template <class T_Stream>
  static Tuint outputBuffer(T_Stream& a_rStream, Tcptr a_cpBuffer, const Tuint a_cSingleSize, const Tuint a_cCount);
  //! Output ASCII characters from the given buffer with fixed size.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_cpBuffer - Constant pointer to the ASCII characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of output characters.
  */
  template <class T_Stream>
  static Tuint outputBuffer(T_Stream& a_rStream, Tcsstr a_cpBuffer, const Tuint a_cSize);
  //! Output Unicode characters from the given buffer with fixed size.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_cpBuffer - Constant pointer to the Unicode characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of output characters.
  */
  template <class T_Stream>
  static Tuint outputBuffer(T_Stream& a_rStream, Tcwstr a_cpBuffer, const Tuint a_cSize);
  //! Output ASCII character.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_cCharacter - ASCII character.
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> outputChar(T_Stream& a_rStream, const Tschar a_cCharacter);
  //! Output Unicode character.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_cCharacter - Unicode character.
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> outputChar(T_Stream& a_rStream, const Twchar a_cCharacter);
  //! Output ASCII zero terminated C string.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_cpString - ASCII zero terminated C string.
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> outputString(T_Stream& a_rStream, const Tcsstr a_cpString);
  //! Output Unicode zero terminated C string.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_cpString - Unicode zero terminated C string.
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> outputString(T_Stream& a_rStream, const Tcwstr a_cpString);
  //! Output ASCII string.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_crString - Constant reference to the instance of the CStringASCII class.
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> outputString(T_Stream& a_rStream, const NString::CStringASCII& a_crString);
  //! Output Unicode string.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_crString - Constant reference to the instance of the CStringUnicode class.
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> outputString(T_Stream& a_rStream, const NString::CStringUnicode& a_crString);
  //! Output system string.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_crString - Constant reference to the instance of the CSystemString class.
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> outputString(T_Stream& a_rStream, const NString::CSystemString& a_crString);
  //! Output boolean number value.
  /*!
      Supported format flags:
      \li \b FORMAT_DECIMAL - boolean number is represented as '0'/'1' instead of 'false'/'true'.
      \li \b FORMAT_LOWER - boolean number uses lower case (e.g. 'false'/'true'). This is the default flag.
      \li \b FORMAT_UPPER - boolean number uses upper case (e.g. 'FALSE'/'TRUE').
      \li \b FORMAT_LALIGN - boolean number is aligned to the left (e.g. 'true   ').
      \li \b FORMAT_RALIGN - boolean number is aligned to the right (e.g. '   true'). This is the default flag.
      \li \b FORMAT_ASCII - use ASCII encoding to output formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b FORMAT_UNICODE - use UNICODE encoding to output formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rStream - Reference to the output stream.
      \param a_cBoolean - Boolean number value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> outputBool(T_Stream& a_rStream, const Tbool a_cBoolean, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cWidth = 0);
  //! Output integer number.
  /*!
      Supported format flags:
      \li \b FORMAT_PLUS - put '+' or '-' sign before number (e.g. '+1234567890', '-1234567890').
      \li \b FORMAT_SPACE - put ' ' or '-' sign before number (e.g. ' 1234567890', '-1234567890').
      \li \b FORMAT_binary - integer number is represented in lower case binary form (e.g. '0b101010101').
      \li \b FORMAT_BINARY - integer number is represented in upper case binary form (e.g. '0B101010101').
      \li \b FORMAT_octal - integer number is represented in lower case octal form (e.g. '0o12345670').
      \li \b FORMAT_OCTAL - integer number is represented in upper case octal form (e.g. '0O12345670').
      \li \b FORMAT_DECIMAL - integer number is represented in decimal form (e.g. '1234567890'). This is the default flag.
      \li \b FORMAT_hex - integer number is represented in lower case hexadecimal form (e.g. '0x1234567890').
      \li \b FORMAT_HEX - integer number is represented in upper case hexadecimal form (e.g. '0X1234567890').
      \li \b FORMAT_LOWER - integer number uses lower case (e.g. '1234abcd'). This is the default flag.
      \li \b FORMAT_UPPER - integer number uses upper case (e.g. '1234ABCD').
      \li \b FORMAT_LALIGN - integer number is aligned to the left (e.g. '1234567890   ').
      \li \b FORMAT_RALIGN - integer number is aligned to the right (e.g. '   1234567890'). This is the default flag.
      \li \b FORMAT_FILL_0 - free width of the integer number is filled with 0 (e.g. '0001234567890').
      \li \b FORMAT_GROUPS - group thousands (e.g. '1,234,567,890'). Flag is valid only when radix is 10 or FORMAT_DECIMAL is provided.
      \li \b FORMAT_ASCII - use ASCII encoding to output formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b FORMAT_UNICODE - use UNICODE encoding to output formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rStream - Reference to the output stream.
      \param a_cInteger - Integer value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream, typename T_Integer>
  static NUtility::CPair<Tbool, Tuint> outputInteger(T_Stream& a_rStream, const T_Integer a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Output real value.
  /*!
      Supported format flags:
      \li \b FORMAT_PLUS - put '+' or '-' sign before real number (e.g. '+12345678.90', '-12345678.90').
      \li \b FORMAT_SPACE - put ' ' or '-' sign before real number (e.g. ' 12345678.90', '-12345678.90').
      \li \b FORMAT_LALIGN - real number is aligned to the left (e.g. '12345678.90   ').
      \li \b FORMAT_RALIGN - real number is aligned to the right (e.g. '   12345678.90'). This is the default flag.
      \li \b FORMAT_FILL_0 - free width of the real number is filled with 0 (e.g. '00012345678.90'). Flag is valid only when FORMAT_DOT is provided.
      \li \b FORMAT_GROUPS - group thousands (e.g. '12,345,678.90'). Flag is valid only when FORMAT_DOT is provided.
      \li \b FORMAT_DOT - real number is represented with dot character (e.g. '12345678.90'). This is the default flag.
      \li \b FORMAT_exp - real number is represented with lower case exponent form (e.g. '1.234567890e+007').
      \li \b FORMAT_EXP - real number is represented with upper case exponent form (e.g. '1.234567890E+007').
      \li \b FORMAT_ASCII - use ASCII encoding to output formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b FORMAT_UNICODE - use UNICODE encoding to output formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rStream - Reference to the output stream.
      \param a_cReal - Real value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cPrecision - Count of precision numbers after the decimal point (default is 6).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream, typename T_Real>
  static NUtility::CPair<Tbool, Tuint> outputReal(T_Stream& a_rStream, const T_Real a_cReal, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cPrecision = 6, const Tuint a_cWidth = 0);
  //! Output pointer value.
  /*!
      Supported format flags:
      \li \b FORMAT_hex - pointer is represented in lower case hexadecimal form (e.g. '0x12345678'). This is the default flag.
      \li \b FORMAT_HEX - pointer is represented in upper case hexadecimal form (e.g. '0X12345678').
      \li \b FORMAT_LOWER - pointer uses lower case (e.g. '0x0abcdef0'). This is the default flag.
      \li \b FORMAT_UPPER - pointer uses upper case (e.g. '0x0ABCDEF0').
      \li \b FORMAT_LALIGN - pointer is aligned to the left (e.g. '0x12345678   ').
      \li \b FORMAT_RALIGN - pointer is aligned to the right (e.g. '   0x12345678'). This is the default flag.
      \li \b FORMAT_ASCII - use ASCII encoding to output formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b FORMAT_UNICODE - use UNICODE encoding to output formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rStream - Reference to the output stream.
      \param a_cpPointer - Pointer value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream>
  static NUtility::CPair<Tbool, Tuint> outputPointer(T_Stream& a_rStream, Tcptr a_cpPointer, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cWidth = 0);
  //! Output formatted string using variable arguments list.
  /*!
      \param a_rStream - Reference to the output stream.
      \param a_cpFormatString - Constant format string type.
      \param a_cFormatStringSize - Format string size (in characters).
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of output bytes/characters.
  */
  template <class T_Stream, typename T_StringConst>
  static NUtility::CPair<Tbool, Tuint> outputFormat(T_Stream& a_rStream, T_StringConst a_cpFormatString, const Tuint a_cFormatStringSize, va_list a_VariableList);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/IReader.hpp>
#include <Depth/include/stream/IWriter.hpp>
#include <Depth/include/stream/IReaderWriter.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/details/CStreamHelper.inl>
/*==========================================================================*/
#endif
