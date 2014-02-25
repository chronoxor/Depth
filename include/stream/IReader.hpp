/*!
 *  \file    IReader.hpp Reader is a base stream interface for all
 *           implementations of stream classes which use byte input (files,
 *           pipes, sockets, etc.).
 *  \brief   Reader interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reader interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   13.08.2008 00:57:40

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
#ifndef __IREADER_HPP__
#define __IREADER_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/IStream.hpp>
#include <Depth/include/string/CString.hpp>
#include <Depth/include/utility/CPair.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
template <typename T_Type>
class CReadIterator;
template <typename T_Type>
class CPeekIterator;
template <typename T_Type>
class CPushIterator;
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
namespace NOperators { }
/*==========================================================================*/
using namespace NIterators;
using namespace NOperators;
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Reader interface.
/*!
    Reader interface is a base interface for all classes which  represent  any
    kind of input such as file reading, socket input, memory input, etc.

    Reader interface also allows to  use  peek/push  technique.  If  the  peek
    buffer size is more than 0 (default is 0) it is  possible  to  peek  bytes
    from the reader without removing them. After the  bytes  are  peeked  they
    will be read again during the next  read  operation.  Additionally  it  is
    possible to push bytes back into the reader after they were read from  it.
    Count of bytes that could be peeked/pushed are depends on the size of  the
    peek buffer.

    Unformat string methods work like classical 'C' scanf() function. But they
    use more formalized and adapted for the Depth project control characters.

    Unformat is the string with control characters. Control character  is  '%'
    and '%%' for normal '%'. After it you can define FLAGS, WIDTH,  PRECISION,
    VALUES ("%[FLAGS][WIDTH][PRECISION]VALUES"):

    <b>FLAGS:</b>
    \li '-' - skip value. Input the next field, but do not assign its value to
              any variable argument.

    <b>WIDTH:</b>
    \li 'n' - count of string characters to read for string (n >= 0).
    \li '*' - count of string characters to read for string from next variable
              argument.

    <b>VALUES:</b>
    \li 's'  - input one ASCII character into next variable argument.
    \li 'w'  - input one Unicode character into next variable argument.
    \li 'x'  - input one ASCII/Unicode character into next variable argument.
    \li 'S'  - input ASCII string into next variable argument.
    \li 'W'  - input Unicode string into next variable argument.
    \li 'X'  - input ASCII/Unicode string into next variable argument.
    \li 'ZS' - input 'C'  zero-terminated  ASCII  string  into  next  variable
               argument.
    \li 'ZW' - input 'C' zero-terminated Unicode  string  into  next  variable
               argument.
    \li 'ZX' - input  'C'  zero-terminated  ASCII/Unicode  string   into  next
               variable argument.
    \li 'i'  - input signed integer number into next  variable  argument. Also
               supports case insensitive flags: 'I', 'bi', 'bI',  'Bi',  'BI',
               'oi', 'oI', 'Oi', 'OI', 'hi', 'hI', 'Hi', 'HI'.
    \li 'u'  - input unsigned integer number into next variable argument. Also
               supports case insensitive flags: 'U', 'bu',  'bU',  'Bu', 'BU',
               'ou', 'oU', 'Ou', 'OU', 'hu', 'hU', 'Hu', 'HU'.
    \li 'f'  - input float number into next variable  argument.  Also supports
               case insensitive flags: 'ef', 'Ef'.
    \li 'd'  - input double number into next variable argument.  Also supports
               case insensitive flags: 'ed', 'Ed'.
    \li 'r'  - input real number into next  variable  argument.  Also supports
               case insensitive flags: 'er', 'Er'.
*/
class BASE_API IReader :
  virtual public IStream
{
  // Friend interface: Filter interface (IFilter).
  friend class IFilter;
  // Friend interface: Reader & Writer interface (IReaderWriter).
  friend class IReaderWriter;
  // Friend interface: Exchange reader interface (IExchangeReader).
  friend class IExchangeReader;
  // Friend interface: Exchange reader & writer interface (IExchangeReaderWriter).
  friend class IExchangeReaderWriter;
  // Friend class: Stream helper class (CStreamHelper).
  friend class NDetails::CStreamHelper;

  //! Type for the MConceptDepthType constraint checking.
  typedef IReader TDepthCheckType;

  // Check IReader interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  //! Default interface protected constructor.
  /*!
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IReader(const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IReader interface.
  */
  IReader(const IReader& a_crInstance);

public:
  //! Interface virtual destructor.
  virtual ~IReader();

  //! Operator: Assign another IReader interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IReader interface.
      \return Reference to the current interface instance.
  */
  IReader& operator = (const IReader& a_crInstance);

  //! Set another IReader interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IReader interface.
      \return true  - if another reader was successfully set. \n
              false - if another reader was not successfully set. \n
  */
  Tbool set(const IReader& a_crInstance);

  //! Is reader opened?
  /*!
      \return true  - if reader is opened. \n
              false - if reader is not opened. \n
  */
  Tbool isOpened() const;
  //! Is reader met 'end of file'?
  /*!
      \return true  - if reader met 'end of file'. \n
              false - if reader did not meet 'end of file'. \n
  */
  Tbool isEOF() const;

  //! Get count of bytes which were read from the reader.
  /*!
      \return Count of bytes which were read from the reader.
  */
  Tuint getReadBytesCount() const;

  //! Set peek buffer size.
  /*!
      \param a_cPeekBufferSize - Peek buffer size (in bytes).
      \return true  - if buffer size was set successfully. \n
              false - if buffer size was not set successfully. \n
  */
  Tbool setPeekBufferSize(const Tuint a_cPeekBufferSize);
  //! Get peek buffer full size.
  /*!
      \return Peek buffer full size (in bytes).
  */
  Tuint getPeekBufferSize() const;
  //! Get peek buffer free size.
  /*!
      \return Peek buffer free size (in bytes).
  */
  Tuint getPeekBufferFreeSize() const;

  //! Open reader for input.
  /*!
      \return true  - if reader was opened successfully. \n
              false - if reader was not opened successfully. \n
  */
  Tbool open();

  //! Read bytes into the given buffer with fixed size.
  /*!
      \param a_pBuffer - Pointer to the buffer.
      \param a_cSize - Size of the buffer (in bytes).
      \return Count of read bytes.
  */
  Tuint readBuffer(Tptr a_pBuffer, const Tuint a_cSize);
  //! Read bytes into the given buffer with the byte order correction.
  /*!
      \param a_pBuffer - Pointer to the buffer.
      \param a_cSingleSize - Size of the single item (in bytes).
      \param a_cCount - Count of the single items in the buffer.
      \return Count of read bytes.
  */
  Tuint readBuffer(Tptr a_pBuffer, const Tuint a_cSingleSize, const Tuint a_cCount);
  //! Read ASCII characters into the given buffer with fixed size.
  /*!
      \param a_pBuffer - Pointer to the ASCII characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of read characters.
  */
  Tuint readBuffer(Tsstr a_pBuffer, const Tuint a_cSize);
  //! Read Unicode characters into the given buffer with fixed size.
  /*!
      \param a_pBuffer - Pointer to the Unicode characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of read characters.
  */
  Tuint readBuffer(Twstr a_pBuffer, const Tuint a_cSize);
  //! Read and skip the given count of bytes.
  /*!
      \param a_cSize - Size of bytes buffer to skip (in bytes).
      \return Count of read and skipped bytes.
  */
  Tuint readSkipBytes(const Tuint a_cSize);
  //! Read and skip the given count of ASCII characters.
  /*!
      \param a_cSize - Size of ASCII characters buffer to skip (in characters).
      \return Count of read and skipped ASCII characters.
  */
  Tuint readSkipASCII(const Tuint a_cSize);
  //! Read and skip the given count of Unicode characters.
  /*!
      \param a_cSize - Size of Unicode characters buffer to skip (in characters).
      \return Count of read and skipped Unicode characters.
  */
  Tuint readSkipUnicode(const Tuint a_cSize);
  //! Read ASCII character.
  /*!
      \param a_rCharacter - Reference to the ASCII character.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tschar& a_rCharacter);
  //! Read Unicode character.
  /*!
      \param a_rCharacter - Reference to the Unicode character.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Twchar& a_rCharacter);
  //! Read ASCII zero terminated C string.
  /*!
      \param a_rpString - Reference to the ASCII zero terminated C string.
      \param a_cSize - Size of read string in characters. If 0 then read to line end (default is 0).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tsstr& a_rpString, const Tuint a_cSize = 0);
  //! Read Unicode zero terminated C string.
  /*!
      \param a_rpString - Reference to the Unicode zero terminated C string.
      \param a_cSize - Size of read string in characters. If 0 then read to line end (default is 0).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Twstr& a_rpString, const Tuint a_cSize = 0);
  //! Read ASCII string.
  /*!
      \param a_rString - Reference to the ASCII string.
      \param a_cSize - Size of read string in characters. If 0 then read to line end (default is 0).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(NString::CStringASCII& a_rString, const Tuint a_cSize = 0);
  //! Read Unicode string.
  /*!
      \param a_rString - Reference to the Unicode string.
      \param a_cSize - Size of read string in characters. If 0 then read to line end (default is 0).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(NString::CStringUnicode& a_rString, const Tuint a_cSize = 0);
  //! Read system string.
  /*!
      \param a_rString - Reference to the system string.
      \param a_cSize - Size of read string in characters. If 0 then read to line end (default is 0).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(NString::CSystemString& a_rString, const Tuint a_cSize = 0);
  //! Read boolean number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rBoolean - Reference to the boolean number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tbool& a_rBoolean, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read signed 1 byte integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the signed 1 byte integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tsint08& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read unsigned 1 byte integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the unsigned 1 byte integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tuint08& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read signed 2 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the signed 2 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tsint16& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read unsigned 2 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the unsigned 2 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tuint16& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read signed 4 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the signed 4 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tsint32& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read unsigned 4 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the unsigned 4 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tuint32& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read signed 8 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the signed 8 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tsint64& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read unsigned 8 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the unsigned 8 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tuint64& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read single accuracy real number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rReal - Reference to the single accuracy real number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tfloat& a_rReal, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read double accuracy real number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rReal - Reference to the double accuracy real number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tdouble& a_rReal, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read pointer value.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rpPointer - Reference to the pointer value.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> read(Tptr& a_rpPointer, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Read formatted ASCII C string buffer.
  /*!
      \param a_cpFormatString - Constant pointer to the ASCII string buffer.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readFormat(const Tcsstr a_cpFormatString, ...);
  //! Read formatted ASCII C string buffer using variable arguments list.
  /*!
      \param a_cpFormatString - Constant pointer to the ASCII string buffer.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readFormatVarList(const Tcsstr a_cpFormatString, va_list a_VariableList);
  //! Read formatted Unicode C string buffer.
  /*!
      \param a_cpFormatString - Constant pointer to the Unicode string buffer.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readFormat(const Tcwstr a_cpFormatString, ...);
  //! Read formatted Unicode C string buffer using variable arguments list.
  /*!
      \param a_cpFormatString - Constant pointer to the Unicode string buffer.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readFormatVarList(const Tcwstr a_cpFormatString, va_list a_VariableList);
  //! Read formatted ASCII string.
  /*!
      \param a_cpFormatString - Constant pointer to the instance of the CStringASCII class.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readFormat(const NString::CStringASCII* a_cpFormatString, ...);
  //! Read formatted ASCII string using variable arguments list.
  /*!
      \param a_crFormatString - Constant reference to the instance of the CStringASCII class.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readFormatVarList(const NString::CStringASCII& a_crFormatString, va_list a_VariableList);
  //! Read formatted Unicode string.
  /*!
      \param a_cpFormatString - Constant pointer to the instance of the CStringUnicode class.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readFormat(const NString::CStringUnicode* a_cpFormatString, ...);
  //! Read formatted Unicode string using variable arguments list.
  /*!
      \param a_crFormatString - Constant reference to the instance of the CStringUnicode class.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readFormatVarList(const NString::CStringUnicode& a_crFormatString, va_list a_VariableList);
  //! Read end of line symbols.
  /*!
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readLineEnd();
  //! Read end of line symbols.
  /*!
      \param a_cIsASCII - ASCII encoding flag.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readLineEnd(const Tbool a_cIsASCII);
  //! Read and skip to end of line symbols.
  /*!
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readToLineEnd();
  //! Read and skip to end of line symbols.
  /*!
      \param a_cIsASCII - ASCII encoding flag.
      \return Successful flag and count of read bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> readToLineEnd(const Tbool a_cIsASCII);

  //! Peek bytes into the given buffer with fixed size.
  /*!
      \param a_pBuffer - Pointer to the buffer.
      \param a_cSize - Size of the buffer (in bytes).
      \return Count of peeked bytes.
  */
  Tuint peekBuffer(Tptr a_pBuffer, const Tuint a_cSize);
  //! Peek bytes into the given buffer with the byte order correction.
  /*!
      \param a_pBuffer - Pointer to the buffer.
      \param a_cSingleSize - Size of the single item (in bytes).
      \param a_cCount - Count of the single items in the buffer.
      \return Count of peeked bytes.
  */
  Tuint peekBuffer(Tptr a_pBuffer, const Tuint a_cSingleSize, const Tuint a_cCount);
  //! Peek ASCII characters into the given buffer with fixed size.
  /*!
      \param a_pBuffer - Pointer to the ASCII characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of peeked characters.
  */
  Tuint peekBuffer(Tsstr a_pBuffer, const Tuint a_cSize);
  //! Peek Unicode characters into the given buffer with fixed size.
  /*!
      \param a_pBuffer - Pointer to the Unicode characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of peeked characters.
  */
  Tuint peekBuffer(Twstr a_pBuffer, const Tuint a_cSize);
  //! Peek and skip the given count of bytes.
  /*!
      \param a_cSize - Size of bytes buffer to skip (in bytes).
      \return Count of peeked and skipped bytes.
  */
  Tuint peekSkipBytes(const Tuint a_cSize);
  //! Peek and skip the given count of ASCII characters.
  /*!
      \param a_cSize - Size of ASCII characters buffer to skip (in characters).
      \return Count of peeked and skipped ASCII characters.
  */
  Tuint peekSkipASCII(const Tuint a_cSize);
  //! Peek and skip the given count of Unicode characters.
  /*!
      \param a_cSize - Size of Unicode characters buffer to skip (in characters).
      \return Count of peeked and skipped Unicode characters.
  */
  Tuint peekSkipUnicode(const Tuint a_cSize);
  //! Peek ASCII character.
  /*!
      \param a_rCharacter - Reference to the ASCII character.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tschar& a_rCharacter);
  //! Peek Unicode character.
  /*!
      \param a_rCharacter - Reference to the Unicode character.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Twchar& a_rCharacter);
  //! Peek ASCII zero terminated C string.
  /*!
      \param a_rpString - Reference to the ASCII zero terminated C string.
      \param a_cSize - Size of peeked string in characters. If 0 then peek to line end (default is 0).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tsstr& a_rpString, const Tuint a_cSize = 0);
  //! Peek Unicode zero terminated C string.
  /*!
      \param a_rpString - Reference to the Unicode zero terminated C string.
      \param a_cSize - Size of peeked string in characters. If 0 then peek to line end (default is 0).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Twstr& a_rpString, const Tuint a_cSize = 0);
  //! Peek ASCII string.
  /*!
      \param a_rString - Reference to the ASCII string.
      \param a_cSize - Size of peeked string in characters. If 0 then peek to line end (default is 0).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(NString::CStringASCII& a_rString, const Tuint a_cSize = 0);
  //! Peek Unicode string.
  /*!
      \param a_rString - Reference to the Unicode string.
      \param a_cSize - Size of peeked string in characters. If 0 then peek to line end (default is 0).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(NString::CStringUnicode& a_rString, const Tuint a_cSize = 0);
  //! Peek system string.
  /*!
      \param a_rString - Reference to the system string.
      \param a_cSize - Size of peeked string in characters. If 0 then peek to line end (default is 0).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(NString::CSystemString& a_rString, const Tuint a_cSize = 0);
  //! Peek boolean number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rBoolean - Reference to the boolean number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tbool& a_rBoolean, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek signed 1 byte integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the signed 1 byte integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tsint08& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek unsigned 1 byte integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the unsigned 1 byte integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tuint08& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek signed 2 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the signed 2 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tsint16& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek unsigned 2 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the unsigned 2 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tuint16& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek signed 4 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the signed 4 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tsint32& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek unsigned 4 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the unsigned 4 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tuint32& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek signed 8 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the signed 8 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tsint64& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek unsigned 8 bytes integer number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rInteger - Reference to the unsigned 8 bytes integer number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tuint64& a_rInteger, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek single accuracy real number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rReal - Reference to the single accuracy real number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tfloat& a_rReal, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek double accuracy real number.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rReal - Reference to the double accuracy real number.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tdouble& a_rReal, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek pointer value.
  /*!
      Supported parse flags:
      \li \b PARSE_ASCII - use ASCII encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b PARSE_UNICODE - use UNICODE encoding to input formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_rpPointer - Reference to the pointer value.
      \param a_cParseFlags - Combination of parse flags (default is NDepth::NStream::IStream::PARSE_DEFAULT).
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peek(Tptr& a_rpPointer, const Tuint a_cParseFlags = IStream::PARSE_DEFAULT);
  //! Peek formatted ASCII C string buffer.
  /*!
      \param a_cpFormatString - Constant pointer to the ASCII string buffer.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekFormat(const Tcsstr a_cpFormatString, ...);
  //! Peek formatted ASCII C string buffer using variable arguments list.
  /*!
      \param a_cpFormatString - Constant pointer to the ASCII string buffer.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekFormatVarList(const Tcsstr a_cpFormatString, va_list a_VariableList);
  //! Peek formatted Unicode C string buffer.
  /*!
      \param a_cpFormatString - Constant pointer to the Unicode string buffer.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekFormat(const Tcwstr a_cpFormatString, ...);
  //! Peek formatted Unicode C string buffer using variable arguments list.
  /*!
      \param a_cpFormatString - Constant pointer to the Unicode string buffer.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekFormatVarList(const Tcwstr a_cpFormatString, va_list a_VariableList);
  //! Peek formatted ASCII string.
  /*!
      \param a_cpFormatString - Constant pointer to the instance of the CStringASCII class.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekFormat(const NString::CStringASCII* a_cpFormatString, ...);
  //! Peek formatted ASCII string using variable arguments list.
  /*!
      \param a_crFormatString - Constant reference to the instance of the CStringASCII class.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekFormatVarList(const NString::CStringASCII& a_crFormatString, va_list a_VariableList);
  //! Peek formatted Unicode string.
  /*!
      \param a_cpFormatString - Constant pointer to the instance of the CStringUnicode class.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekFormat(const NString::CStringUnicode* a_cpFormatString, ...);
  //! Peek formatted Unicode string using variable arguments list.
  /*!
      \param a_crFormatString - Constant reference to the instance of the CStringUnicode class.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekFormatVarList(const NString::CStringUnicode& a_crFormatString, va_list a_VariableList);
  //! Peek end of line symbols.
  /*!
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekLineEnd();
  //! Peek end of line symbols.
  /*!
      \param a_cIsASCII - ASCII encoding flag.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekLineEnd(const Tbool a_cIsASCII);
  //! Peek and skip to end of line symbols.
  /*!
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekToLineEnd();
  //! Peek and skip to end of line symbols.
  /*!
      \param a_cIsASCII - ASCII encoding flag.
      \return Successful flag and count of peeked bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> peekToLineEnd(const Tbool a_cIsASCII);

  //! Push bytes from the given buffer with fixed size into the reader peek buffer.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Size of the buffer (in bytes).
      \return Count of pushed bytes.
  */
  Tuint pushBuffer(Tcptr a_cpBuffer, const Tuint a_cSize);
  //! Push bytes from the given buffer with the byte order correction.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSingleSize - Size of the single item (in bytes).
      \param a_cCount - Count of the single items in the buffer.
      \return Count of pushed bytes.
  */
  Tuint pushBuffer(Tcptr a_cpBuffer, const Tuint a_cSingleSize, const Tuint a_cCount);
  //! Push ASCII characters from the given buffer with fixed size into the reader peek buffer.
  /*!
      \param a_cpBuffer - Constant pointer to the ASCII characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of pushed characters.
  */
  Tuint pushBuffer(Tcsstr a_cpBuffer, const Tuint a_cSize);
  //! Push Unicode characters from the given buffer with fixed size into the reader peek buffer.
  /*!
      \param a_cpBuffer - Constant pointer to the Unicode characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of pushed characters.
  */
  Tuint pushBuffer(Tcwstr a_cpBuffer, const Tuint a_cSize);
  //! Push ASCII character.
  /*!
      \param a_cCharacter - ASCII character.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tschar a_cCharacter);
  //! Push Unicode character.
  /*!
      \param a_cCharacter - Unicode character.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Twchar a_cCharacter);
  //! Push ASCII zero terminated C string.
  /*!
      \param a_cpString - ASCII zero terminated C string.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tcsstr a_cpString);
  //! Push Unicode zero terminated C string.
  /*!
      \param a_cpString - Unicode zero terminated C string.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tcwstr a_cpString);
  //! Push ASCII string.
  /*!
      \param a_crString - Constant reference to the instance of the CStringASCII class.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const NString::CStringASCII& a_crString);
  //! Push Unicode string.
  /*!
      \param a_crString - Constant reference to the instance of the CStringUnicode class.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const NString::CStringUnicode& a_crString);
  //! Push system string.
  /*!
      \param a_crString - Constant reference to the instance of the CSystemString class.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const NString::CSystemString& a_crString);
  //! Push boolean number value.
  /*!
      Supported format flags:
      \li \b FORMAT_DECIMAL - boolean number is represented as '0'/'1' instead of 'false'/'true'.
      \li \b FORMAT_LOWER - boolean number uses lower case (e.g. 'false'/'true'). This is the default flag.
      \li \b FORMAT_UPPER - boolean number uses upper case (e.g. 'FALSE'/'TRUE').
      \li \b FORMAT_LALIGN - boolean number is aligned to the left (e.g. 'true   ').
      \li \b FORMAT_RALIGN - boolean number is aligned to the right (e.g. '   true'). This is the default flag.
      \li \b FORMAT_ASCII - use ASCII encoding to output formatted values (integers, pointers, etc). Default value of this flag depends on system.
      \li \b FORMAT_UNICODE - use UNICODE encoding to output formatted values (integers, pointers, etc). Default value of this flag depends on system.

      \param a_cBoolean - Boolean number value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tbool a_cBoolean, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cWidth = 0);
  //! Push signed 1 byte integer value.
  /*!
      Supported format flags:
      \li \b FORMAT_PLUS - put '+' or '-' sign before integer number (e.g. '+1234567890', '-1234567890').
      \li \b FORMAT_SPACE - put ' ' or '-' sign before integer number (e.g. ' 1234567890', '-1234567890').
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

      \param a_cInteger - Signed 1 byte integer value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tsint08 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Push unsigned 1 byte integer value.
  /*!
      Supported format flags:
      \li \b FORMAT_PLUS - put '+' or '-' sign before integer number (e.g. '+1234567890', '-1234567890').
      \li \b FORMAT_SPACE - put ' ' or '-' sign before integer number (e.g. ' 1234567890', '-1234567890').
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

      \param a_cInteger - Unsigned 1 byte integer value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tuint08 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Push signed 2 bytes integer value.
  /*!
      Supported format flags:
      \li \b FORMAT_PLUS - put '+' or '-' sign before integer number (e.g. '+1234567890', '-1234567890').
      \li \b FORMAT_SPACE - put ' ' or '-' sign before integer number (e.g. ' 1234567890', '-1234567890').
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

      \param a_cInteger - Signed 2 bytes integer value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tsint16 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Push unsigned 2 bytes integer value.
  /*!
      Supported format flags:
      \li \b FORMAT_PLUS - put '+' or '-' sign before integer number (e.g. '+1234567890', '-1234567890').
      \li \b FORMAT_SPACE - put ' ' or '-' sign before integer number (e.g. ' 1234567890', '-1234567890').
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

      \param a_cInteger - Unsigned 2 bytes integer value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tuint16 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Push signed 4 bytes integer value.
  /*!
      Supported format flags:
      \li \b FORMAT_PLUS - put '+' or '-' sign before integer number (e.g. '+1234567890', '-1234567890').
      \li \b FORMAT_SPACE - put ' ' or '-' sign before integer number (e.g. ' 1234567890', '-1234567890').
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

      \param a_cInteger - Signed 4 bytes integer value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tsint32 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Push unsigned 4 bytes integer value.
  /*!
      Supported format flags:
      \li \b FORMAT_PLUS - put '+' or '-' sign before integer number (e.g. '+1234567890', '-1234567890').
      \li \b FORMAT_SPACE - put ' ' or '-' sign before integer number (e.g. ' 1234567890', '-1234567890').
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

      \param a_cInteger - Unsigned 4 bytes integer value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tuint32 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Push signed 8 bytes integer value.
  /*!
      Supported format flags:
      \li \b FORMAT_PLUS - put '+' or '-' sign before integer number (e.g. '+1234567890', '-1234567890').
      \li \b FORMAT_SPACE - put ' ' or '-' sign before integer number (e.g. ' 1234567890', '-1234567890').
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

      \param a_cInteger - Signed 8 bytes integer value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tsint64 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Push unsigned 8 bytes integer value.
  /*!
      Supported format flags:
      \li \b FORMAT_PLUS - put '+' or '-' sign before integer number (e.g. '+1234567890', '-1234567890').
      \li \b FORMAT_SPACE - put ' ' or '-' sign before integer number (e.g. ' 1234567890', '-1234567890').
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

      \param a_cInteger - Unsigned 8 bytes integer value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off (default is 0).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tuint64 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Push single accuracy real value.
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

      \param a_cReal - Single accuracy real value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cPrecision - Count of precision numbers after the decimal point (default is 6).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tfloat a_cReal, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cPrecision = 6, const Tuint a_cWidth = 0);
  //! Push double accuracy real value.
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

      \param a_cReal - Double accuracy real value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cPrecision - Count of precision numbers after the decimal point (default is 6).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(const Tdouble a_cReal, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cPrecision = 6, const Tuint a_cWidth = 0);
  //! Push pointer value.
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

      \param a_cpPointer - Pointer value.
      \param a_cFormatFlags - Combination of format flags (default is NDepth::NStream::IStream::FORMAT_DEFAULT).
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied (default is 0).
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> push(Tcptr a_cpPointer, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cWidth = 0);
  //! Push formatted ASCII C string buffer.
  /*!
      \param a_cpFormatString - Constant pointer to the ASCII string buffer.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> pushFormat(const Tcsstr a_cpFormatString, ...);
  //! Push formatted ASCII C string buffer using variable arguments list.
  /*!
      \param a_cpFormatString - Constant pointer to the ASCII string buffer.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> pushFormatVarList(const Tcsstr a_cpFormatString, va_list a_VariableList);
  //! Push formatted Unicode C string buffer.
  /*!
      \param a_cpFormatString - Constant pointer to the Unicode string buffer.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> pushFormat(const Tcwstr a_cpFormatString, ...);
  //! Push formatted Unicode C string buffer using variable arguments list.
  /*!
      \param a_cpFormatString - Constant pointer to the Unicode string buffer.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> pushFormatVarList(const Tcwstr a_cpFormatString, va_list a_VariableList);
  //! Push formatted ASCII string.
  /*!
      \param a_cpFormatString - Constant pointer to the instance of the CStringASCII class.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> pushFormat(const NString::CStringASCII* a_cpFormatString, ...);
  //! Push formatted ASCII string using variable arguments list.
  /*!
      \param a_crFormatString - Constant reference to the instance of the CStringASCII class.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> pushFormatVarList(const NString::CStringASCII& a_crFormatString, va_list a_VariableList);
  //! Push formatted Unicode string.
  /*!
      \param a_cpFormatString - Constant pointer to the instance of the CStringUnicode class.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> pushFormat(const NString::CStringUnicode* a_cpFormatString, ...);
  //! Push formatted Unicode string using variable arguments list.
  /*!
      \param a_crFormatString - Constant reference to the instance of the CStringUnicode class.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> pushFormatVarList(const NString::CStringUnicode& a_crFormatString, va_list a_VariableList);
  //! Push end of line symbols with the current stream line ending type.
  /*!
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> pushLineEnd();
  //! Push end of line symbols with the current stream line ending type.
  /*!
      \param a_cIsASCII - ASCII encoding flag.
      \return Successful flag and count of pushed bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> pushLineEnd(const Tbool a_cIsASCII);

  //! Flush reader.
  /*!
      Flush method force read all cache data from the buffer (in case buffered
      readers) of the input device.

      \return true  - if reader was flushed successfully. \n
              false - if reader was not flushed successfully. \n
  */
  Tbool flush();

  //! Close reader.
  /*!
      \return true  - if reader was closed successfully. \n
              false - if reader was not closed successfully. \n
  */
  Tbool close();

  //! Get read iterator.
  /*!
      Method returns read iterator for current IReader class instance.

      \return Read iterator.
  */
  template <typename T_Type>
  CReadIterator<T_Type> getItRead();
  //! Get peek iterator.
  /*!
      Method returns peek iterator for current IReader class instance.

      \return Peek iterator.
  */
  template <typename T_Type>
  CPeekIterator<T_Type> getItPeek();
  //! Get push iterator.
  /*!
      Method returns push iterator for current IReader class instance.

      \return Push iterator.
  */
  template <typename T_Type>
  CPushIterator<T_Type> getItPush();

  //! Serialization load IReader interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save IReader interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize IReader interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IReader interface instances.
  /*!
      \param a_rInstance - Reference to another IReader interface instance.
  */
  void swap(IReader& a_rInstance);

protected:
  //! Abstract reader open method.
  /*!
      \return true  - if reader was opened successfully. \n
              false - if reader was not opened successfully. \n
  */
  virtual Tbool onOpen() = 0;
  //! Abstract reader open method.
  /*!
      \param a_cOpenType - Open type of the stream.
      \return true  - if reader was opened successfully. \n
              false - if reader was not opened successfully. \n
  */
  virtual Tbool onOpen(const EOpenType a_cOpenType);
  //! Abstract reader binary read method.
  /*!
      \param a_pBuffer - Pointer to the byte buffer.
      \param a_cSize - Size of the buffer (in bytes).
      \return Count of read bytes.
  */
  virtual Tuint onReadBinary(Tptr a_pBuffer, const Tuint a_cSize) = 0;
  //! Abstract reader ASCII text read method.
  /*!
      \param a_pBuffer - Pointer to the ASCII text buffer.
      \param a_cSize - Size of the ASCII text buffer (in characters).
      \return Count of read characters.
  */
  virtual Tuint onReadText(Tsstr a_pBuffer, const Tuint a_cSize) = 0;
  //! Abstract reader Unicode text read method.
  /*!
      \param a_pBuffer - Pointer to the Unicode text buffer.
      \param a_cSize - Size of the Unicode text buffer (in characters).
      \return Count of read characters.
  */
  virtual Tuint onReadText(Twstr a_pBuffer, const Tuint a_cSize) = 0;
  //! Abstract reader flush method.
  /*!
      \return true  - if reader was flushed successfully. \n
              false - if reader was not flushed successfully. \n
  */
  virtual Tbool onFlush() = 0;
  //! Abstract reader close method.
  /*!
      \return true  - if reader was closed successfully. \n
              false - if reader was not closed successfully. \n
  */
  virtual Tbool onClose() = 0;

protected:
  //! Set 'end of file' flag.
  /*!
      \param a_cEOF - 'end of file' flag (default is true).
  */
  void setEOF(const Tbool a_cEOF = true);

private:
  Tbool   m_IsOpened;                   //!< Is reader opened for reading?
  Tbool   m_IsEOF;                      //!< Is reader met 'end of file'?
  Tuint   m_ReadBytesCount;             //!< Count of bytes which were read from the reader.
  Tuint   m_PeekBufferSize;             //!< Peek buffer full size.
  Tuint   m_PeekBufferFreeSize;         //!< Peek buffer free size.
  Tbuffer m_pPeekBuffer;                //!< Peek buffer.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/iterators/CReadIterator.hpp>
#include <Depth/include/stream/iterators/CPeekIterator.hpp>
#include <Depth/include/stream/iterators/CPushIterator.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/operators/OStreamRead.hpp>
#include <Depth/include/stream/operators/OStreamPeek.hpp>
#include <Depth/include/stream/operators/OStreamPush.hpp>
#include <Depth/include/stream/operators/OBuffer.hpp>
#include <Depth/include/stream/operators/OBufferConst.hpp>
#include <Depth/include/stream/operators/OLineEnd.hpp>
#include <Depth/include/stream/operators/OToLineEnd.hpp>
#include <Depth/include/stream/operators/OFormat.hpp>
#include <Depth/include/stream/operators/OFormatFlags.hpp>
#include <Depth/include/stream/operators/OFormatVarList.hpp>
#include <Depth/include/stream/operators/OFlush.hpp>
#include <Depth/include/stream/operators/OSkip.hpp>
#include <Depth/include/stream/operators/OTabulation.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/IReader.inl>
/*==========================================================================*/
//! \example example-stream-IReader.cpp
/*--------------------------------------------------------------------------*/
//! \test test-stream-IReader.cpp
/*==========================================================================*/
#endif
