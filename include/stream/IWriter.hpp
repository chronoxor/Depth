/*!
 *  \file    IWriter.hpp Writer is a base stream interface for all
 *           implementations of stream classes which use byte output (files,
 *           pipes, sockets, etc.).
 *  \brief   Writer interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Writer interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   13.08.2008 03:18:33

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
#ifndef __IWRITER_HPP__
#define __IWRITER_HPP__
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
class CWriteIterator;
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
//! Writer interface.
/*!
    Writer interface is a base interface for all classes which  represent  any
    kind of output such as file writing, socket output, memory output, etc.

    Format string methods work like classical 'C' printf() function. But  they
    use more formalized and adapted for the Depth project control characters.

    Format is the string with control characters. Control character is '%' and
    '%%' for normal '%'. After it you  can  define  FLAGS,  WIDTH,  PRECISION,
    VALUES ("%[FLAGS][WIDTH][PRECISION]VALUES"):

    <b>FLAGS:</b>
    \li '-'  - left align (default align is right).
    \li '+'  - put '+' if number >= 0, '-' if number < 0.
    \li ' '  - put ' ' if number >= 0, '-' if number < 0.

    <b>WIDTH:</b>
    \li 'n'  - minimal field width (n >= 0).
    \li '0n' - minimal field width and setting unused space with '0' (n >=0).
    \li '*'  - minimal field width from next variable argument.
    \li '0*' - minimal field width from next  variable  argument  and  setting
               unused space with '0'.

    <b>PRECISION:</b>
    \li ','  - output thousands groups delimiters.
    \li '.n' - precision for real numbers (n >= 0).
    \li ',n' - precision  for  real  numbers  with thousands groups delimiters
               (n >= 0).
    \li '.*' - precision for real numbers from next variable argument.
    \li ',*' - precision for real numbers  with  thousands  groups  delimiters
               from next variable argument.

    <b>VALUES:</b>
    \li 'n'  - save count of successfully output characters into next variable
               argument.
    \li 's'  - output one ASCII character from next variable argument.
    \li 'w'  - output one Unicode character from next variable argument.
    \li 'x'  - output one ASCII/Unicode character from next variable argument.
    \li 'S'  - output ASCII string from next variable argument.
    \li 'W'  - output Unicode string from next variable argument.
    \li 'X'  - output ASCII/Unicode string from next variable argument.
    \li 'ZS' - output 'C' zero-terminated  ASCII  string  from  next  variable
               argument.
    \li 'ZW' - output 'C' zero-terminated Unicode string  from  next  variable
               argument.
    \li 'ZX' - output  'C'  zero-terminated  ASCII/Unicode  string  from  next
               variable argument.
    \li 'i'  - output signed integer number  from  next  variable  argument in
               lower/upper case form. Also  supports  case insensitive  flags:
               'i', 'I'.
    \li 'u'  - output unsigned integer number from next  variable  argument in
               lower/upper case form. Also  supports  case insensitive  flags:
               'u', 'U'.
    \li 'bi' - output signed integer number from  next  variable  argument  in
               lower/upper  case  binary  radix  form.  Also   supports   case
               insensitive flags: 'bi', 'bI', 'Bi', 'BI'.
    \li 'bu' - output unsigned integer number from next variable  argument  in
               lower/upper  case  binary  radix  form.  Also   supports   case
               insensitive flags: 'bu', 'bU', 'Bu', 'BU'.
    \li 'oi' - output signed integer number from  next  variable  argument  in
               lower/upper  case  octal  radix  form.   Also   supports   case
               insensitive flags: 'oi', 'oI', 'Oi', 'OI'.
    \li 'ou' - output unsigned integer number from next variable  argument  in
               lower/upper  case  octal  radix  form.   Also   supports   case
               insensitive flags: 'ou', 'oU', 'Ou', 'OU'.
    \li 'hi' - output signed integer number from  next  variable  argument  in
               lower/upper case hexadecimal radix  form.  Also  supports  case
               insensitive flags: 'hi', 'hI', 'Hi', 'HI'.
    \li 'hu' - output unsigned integer number from next variable  argument  in
               lower/upper case hexadecimal radix  form.  Also  supports  case
               insensitive flags: 'hu', 'hU', 'Hu', 'HU'.
    \li 'f'  - output  float  number  with  decimal  dot  from  next  variable
               argument.
    \li 'd'  - output  double  number  with  decimal  dot  from  next variable
               argument.
    \li 'r'  - output real number with decimal dot from next variable argument.
    \li 'ef' - output float number in exponent lower/upper case form from next
               variable argument. Also supports case insensitive flags:  'ef',
               'Ef'.
    \li 'ed' - output double number in exponent  lower/upper  case  form  from
               next variable argument. Also supports case  insensitive  flags:
               'ed', 'Ed'.
    \li 'er' - output real number in exponent lower/upper case form from  next
               variable argument. Also supports case insensitive flags:  'er',
               'Er'.
*/
class BASE_API IWriter :
  virtual public IStream
{
  // Friend interface: Filter interface (IFilter).
  friend class IFilter;
  // Friend interface: Reader & Writer interface (IReaderWriter).
  friend class IReaderWriter;
  // Friend interface: Exchange writer interface (IExchangeWriter).
  friend class IExchangeWriter;
  // Friend interface: Exchange reader & writer interface (IExchangeReaderWriter).
  friend class IExchangeReaderWriter;
  // Friend class: Stream helper class (CStreamHelper).
  friend class NDetails::CStreamHelper;

  //! Type for the MConceptDepthType constraint checking.
  typedef IWriter TDepthCheckType;

  // Check IWriter interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  //! Default interface protected constructor.
  /*!
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IWriter(const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IWriter interface.
  */
  IWriter(const IWriter& a_crInstance);

public:
  //! Interface virtual destructor.
  virtual ~IWriter();

  //! Operator: Assign another IWriter interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IWriter interface.
      \return Reference to the current interface instance.
  */
  IWriter& operator = (const IWriter& a_crInstance);

  //! Set another IWriter interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IWriter interface.
      \return true  - if another writer was successfully set. \n
              false - if another writer was not successfully set. \n
  */
  Tbool set(const IWriter& a_crInstance);

  //! Is writer opened?
  /*!
      \return true  - if writer is opened. \n
              false - if writer is not opened. \n
  */
  Tbool isOpened() const;
  //! Is writer met 'end of file'?
  /*!
      \return true  - if writer met 'end of file'. \n
              false - if writer did not meet 'end of file'. \n
  */
  Tbool isEOF() const;

  //! Get count of bytes which were written into the writer.
  /*!
      \return Count of bytes which were written into the writer.
  */
  Tuint getWrittenBytesCount() const;

  //! Open writer for output.
  /*!
      \return true  - if writer was opened successfully. \n
              false - if writer was not opened successfully. \n
  */
  Tbool open();

  //! Write bytes from the given buffer with fixed size.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Size of the buffer (in bytes).
      \return Count of written bytes.
  */
  Tuint writeBuffer(Tcptr a_cpBuffer, const Tuint a_cSize);
  //! Write bytes from the given buffer with the byte order correction.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSingleSize - Size of the single item (in bytes).
      \param a_cCount - Count of the single items in the buffer.
      \return Count of written bytes.
  */
  Tuint writeBuffer(Tcptr a_cpBuffer, const Tuint a_cSingleSize, const Tuint a_cCount);
  //! Write ASCII characters from the given buffer with fixed size.
  /*!
      \param a_cpBuffer - Constant pointer to the ASCII characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of written characters.
  */
  Tuint writeBuffer(Tcsstr a_cpBuffer, const Tuint a_cSize);
  //! Write Unicode characters from the given buffer with fixed size.
  /*!
      \param a_cpBuffer - Constant pointer to the Unicode characters buffer.
      \param a_cSize - Size of the buffer (in characters).
      \return Count of written characters.
  */
  Tuint writeBuffer(Tcwstr a_cpBuffer, const Tuint a_cSize);
  //! Write ASCII character.
  /*!
      \param a_cCharacter - ASCII character.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tschar a_cCharacter);
  //! Write Unicode character.
  /*!
      \param a_cCharacter - Unicode character.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Twchar a_cCharacter);
  //! Write ASCII zero terminated C string.
  /*!
      \param a_cpString - ASCII zero terminated C string.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tcsstr a_cpString);
  //! Write Unicode zero terminated C string.
  /*!
      \param a_cpString - Unicode zero terminated C string.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tcwstr a_cpString);
  //! Write ASCII string.
  /*!
      \param a_crString - Constant reference to the instance of the CStringASCII class.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const NString::CStringASCII& a_crString);
  //! Write Unicode string.
  /*!
      \param a_crString - Constant reference to the instance of the CStringUnicode class.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const NString::CStringUnicode& a_crString);
  //! Write system string.
  /*!
      \param a_crString - Constant reference to the instance of the CSystemString class.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const NString::CSystemString& a_crString);
  //! Write boolean number value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tbool a_cBoolean, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cWidth = 0);
  //! Write signed 1 byte integer value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tsint08 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Write unsigned 1 byte integer value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tuint08 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Write signed 2 bytes integer value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tsint16 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Write unsigned 2 bytes integer value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tuint16 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Write signed 4 bytes integer value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tsint32 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Write unsigned 4 bytes integer value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tuint32 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Write signed 8 bytes integer value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tsint64 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Write unsigned 8 bytes integer value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tuint64 a_cInteger, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cRadix = 0, const Tuint a_cWidth = 0);
  //! Write single accuracy real value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tfloat a_cReal, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cPrecision = 6, const Tuint a_cWidth = 0);
  //! Write double accuracy real value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(const Tdouble a_cReal, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cPrecision = 6, const Tuint a_cWidth = 0);
  //! Write pointer value.
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
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> write(Tcptr a_cpPointer, const Tuint a_cFormatFlags = IStream::FORMAT_DEFAULT, const Tuint a_cWidth = 0);
  //! Write formatted ASCII C string buffer.
  /*!
      \param a_cpFormatString - Constant pointer to the ASCII string buffer.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> writeFormat(const Tcsstr a_cpFormatString, ...);
  //! Write formatted ASCII C string buffer using variable arguments list.
  /*!
      \param a_cpFormatString - Constant pointer to the ASCII string buffer.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> writeFormatVarList(const Tcwstr a_cpFormatString, va_list a_VariableList);
  //! Write formatted Unicode C string buffer.
  /*!
      \param a_cpFormatString - Constant pointer to the Unicode string buffer.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> writeFormat(const Tcwstr a_cpFormatString, ...);
  //! Write formatted Unicode C string buffer using variable arguments list.
  /*!
      \param a_cpFormatString - Constant pointer to the Unicode string buffer.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> writeFormatVarList(const Tcsstr a_cpFormatString, va_list a_VariableList);
  //! Write formatted ASCII string.
  /*!
      \param a_cpFormatString - Constant pointer to the instance of the CStringASCII class.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> writeFormat(const NString::CStringASCII* a_cpFormatString, ...);
  //! Write formatted ASCII string using variable arguments list.
  /*!
      \param a_crFormatString - Constant reference to the instance of the CStringASCII class.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> writeFormatVarList(const NString::CStringASCII& a_crFormatString, va_list a_VariableList);
  //! Write formatted Unicode string.
  /*!
      \param a_cpFormatString - Constant pointer to the instance of the CStringUnicode class.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> writeFormat(const NString::CStringUnicode* a_cpFormatString, ...);
  //! Write formatted Unicode string using variable arguments list.
  /*!
      \param a_crFormatString - Constant reference to the instance of the CStringUnicode class.
      \param a_VariableList - Variable arguments list.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> writeFormatVarList(const NString::CStringUnicode& a_crFormatString, va_list a_VariableList);
  //! Write end of line symbols with the current stream line ending type.
  /*!
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> writeLineEnd();
  //! Write end of line symbols with the current stream line ending type.
  /*!
      \param a_cIsASCII - ASCII encoding flag.
      \return Successful flag and count of written bytes/characters.
  */
  NUtility::CPair<Tbool, Tuint> writeLineEnd(const Tbool a_cIsASCII);

  //! Flush writer.
  /*!
      Flush method force write  all  cache  data  from  the  buffer  (in  case
      buffered writers) to the output device.

      \return true  - if writer was flushed successfully. \n
              false - if writer was not flushed successfully. \n
  */
  Tbool flush();

  //! Close writer.
  /*!
      \return true  - if writer was closed successfully. \n
              false - if writer was not closed successfully. \n
  */
  Tbool close();

  //! Get write iterator.
  /*!
      Method returns write iterator for current IWriter class instance.

      \return Write iterator.
  */
  template <typename T_Type>
  CWriteIterator<T_Type> getItWrite();

  //! Serialize IWriter interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IWriter interface instances.
  /*!
      \param a_rInstance - Reference to another IWriter interface instance.
  */
  void swap(IWriter& a_rInstance);

protected:
  //! Abstract writer open method.
  /*!
      \return true  - if writer was opened successfully. \n
              false - if writer was not opened successfully. \n
  */
  virtual Tbool onOpen() = 0;
  //! Abstract writer open method.
  /*!
      \param a_cOpenType - Open type of the stream.
      \return true  - if writer was opened successfully. \n
              false - if writer was not opened successfully. \n
  */
  virtual Tbool onOpen(const EOpenType a_cOpenType);
  //! Abstract writer binary write method.
  /*!
      \param a_cpBuffer - Constant pointer to the byte buffer.
      \param a_cSize - Size of the buffer (in bytes).
      \return Count of written bytes.
  */
  virtual Tuint onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize) = 0;
  //! Abstract writer ASCII text write method.
  /*!
      \param a_cpBuffer - Constant pointer to the ASCII text buffer.
      \param a_cSize - Size of the ASCII text buffer (in characters).
      \return Count of written characters.
  */
  virtual Tuint onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize) = 0;
  //! Abstract writer Unicode text write method.
  /*!
      \param a_cpBuffer - Constant pointer to the Unicode text buffer.
      \param a_cSize - Size of the Unicode text buffer (in characters).
      \return Count of written characters.
  */
  virtual Tuint onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize) = 0;
  //! Abstract writer flush method.
  /*!
      \return true  - if writer was flushed successfully. \n
              false - if writer was not flushed successfully. \n
  */
  virtual Tbool onFlush() = 0;
  //! Abstract writer close method.
  /*!
      \return true  - if writer was closed successfully. \n
              false - if writer was not closed successfully. \n
  */
  virtual Tbool onClose() = 0;

protected:
  //! Set 'end of file' flag.
  /*!
      \param a_cEOF - 'end of file' flag (default is true).
  */
  void setEOF(const Tbool a_cEOF = true);

private:
  Tbool m_IsOpened;                     //!< Is writer opened for writing?
  Tbool m_IsEOF;                        //!< Is writer met 'end of file'?
  Tuint m_WrittenBytesCount;            //!< Count of bytes which were written into the writer.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/iterators/CWriteIterator.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/operators/OStreamWrite.hpp>
#include <Depth/include/stream/operators/OBuffer.hpp>
#include <Depth/include/stream/operators/OBufferConst.hpp>
#include <Depth/include/stream/operators/OLineEnd.hpp>
#include <Depth/include/stream/operators/OFormat.hpp>
#include <Depth/include/stream/operators/OFormatFlags.hpp>
#include <Depth/include/stream/operators/OFormatVarList.hpp>
#include <Depth/include/stream/operators/OFlush.hpp>
#include <Depth/include/stream/operators/OSkip.hpp>
#include <Depth/include/stream/operators/OTabulation.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/IWriter.inl>
/*==========================================================================*/
//! \example example-stream-IWriter.cpp
/*--------------------------------------------------------------------------*/
//! \test test-stream-IWriter.cpp
/*==========================================================================*/
#endif
