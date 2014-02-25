/*!
 *  \file    IStream.hpp Stream is a base interface for all implementations of
 *           stream classes (readers, writers).
 *  \brief   Stream interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Stream interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   12.08.2008 23:53:13

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
#ifndef __ISTREAM_HPP__
#define __ISTREAM_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
class IFilter;
class IReader;
class IWriter;
class IExchangeStream;
class IExchangeReader;
class IExchangeWriter;
class IExchangeReaderWriter;
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*--------------------------------------------------------------------------*/
class CStreamHelper;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Stream interface.
/*!
    Stream interface is a base interface  for  all  stream  classes  (readers,
    writers).

    Stream input/output mode could be binary or text:
    \li Binary input simple reads/writes  any value as a binary stream  (array
        of bytes).
    \li Text input/output reads/writes any value as a text string.

    For example for integer value 255 binary input/output will  be  0xFF  (one
    byte) and corresponding text input/output will be "255". By default stream
    uses binary input/output mode.

    Stream byte order depends on the system ending:
    \li Universal byte order (Big-endian byte order).  It  is  used  to  setup
        communication of the Depth streams under different platforms.
    \li Big-endian byte order.  With  it  stream  inputs/outputs  number  from
        high-order byte. 'Big Endian' means that the high-order  byte  of  the
        number is stored in memory at the lowest address,  and  the  low-order
        byte at the highest address.
    \li Little-endian byte order. With it stream  inputs/outputs  number  from
        low-order byte. 'Little Endian' means that the low-order byte  of  the
        number is stored in memory at the lowest address, and  the  high-order
        byte at the highest address.

    By default stream uses universal byte order, which is  Little-endian  byte
    order.

    Stream line ending mode reflects one of the method to separate strings  of
    text in files:
    \li Universal line  ending  (Unix  line  ending).  It  is  used  to  setup
        communication of the Depth streams under different platforms.
    \li Unix line ending (0x0A).
    \li Windows line ending (0x0D, 0x0A).

    By default stream uses universal line ending, which is Unix line ending.
*/
class BASE_API IStream
{
  // Friend interface: Reader interface (IReader).
  friend class IReader;
  // Friend interface: Writer interface (IWriter).
  friend class IWriter;
  // Friend interface: Reader & Writer interface (IReaderWriter).
  friend class IReaderWriter;
  // Friend interface: Exchange stream interface (IExchangeStream).
  friend class IExchangeStream;
  // Friend class: Stream helper class (CStreamHelper).
  friend class NDetails::CStreamHelper;

  //! Type for the MConceptDepthType constraint checking.
  typedef IStream TDepthCheckType;

  // Check IStream interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  enum EByteOrder                       //! Stream byte order type.
  {
    e_BYTE_ORDER_UNIVERSAL,             //!< Universal byte order (Big-endian byte order).
    e_BYTE_ORDER_BIG_ENDIAN,            //!< Big-endian byte order.
    e_BYTE_ORDER_LITTLE_ENDIAN          //!< Little-endian byte order.
  };

  enum ELineEnding                      //! Stream line ending type.
  {
    e_LINE_ENDING_UNIVERSAL,            //!< Universal line ending (Unix line ending).
    e_LINE_ENDING_UNIX,                 //!< Unix line ending (0x0A).
    e_LINE_ENDING_WINDOWS               //!< Windows line ending (0x0D, 0x0A).
  };

  enum EOpenType                        //! Stream open type.
  {
    e_OPEN_READ,                        //!< Open stream for reading.
    e_OPEN_WRITE,                       //!< Open stream for writing.
    e_OPEN_READWRITE                    //!< Open stream for both reading and writing.
  };

  static const Tuint FORMAT_DEFAULT;    //!< Format flag: Default set of format flags (FORMAT_DECIMAL | FORMAT_LOWER | FORMAT_RALIGN | FORMAT_DOT | [FORMAT_ASCII | FORMAT_UNICODE]).
  static const Tuint FORMAT_PLUS;       //!< Format flag: Put '+' or '-' sign before number.
  static const Tuint FORMAT_SPACE;      //!< Format flag: Put ' ' or '-' sign before number.
  static const Tuint FORMAT_binary;     //!< Format flag: Put integer number in lower case binary form (0b and 01234567). Flag is ignored when the 'radix' parameter is provided.
  static const Tuint FORMAT_BINARY;     //!< Format flag: Put integer number in upper case binary form (0B and 01234567). Flag is ignored when the 'radix' parameter is provided.
  static const Tuint FORMAT_octal;      //!< Format flag: Put integer number in lower case octal form (0o and 0o1234567). Flag is ignored when the 'radix' parameter is provided.
  static const Tuint FORMAT_OCTAL;      //!< Format flag: Put integer number in upper case octal form (0O and 0O1234567). Flag is ignored when the 'radix' parameter is provided.
  static const Tuint FORMAT_DECIMAL;    //!< Format flag: Put integer number in decimal form (0123456789). Flag is ignored when the 'radix' parameter is provided.
  static const Tuint FORMAT_hex;        //!< Format flag: Put integer number in lower case hexadecimal form (0x and 0123456789abcdef). Flag is ignored when the 'radix' parameter is provided.
  static const Tuint FORMAT_HEX;        //!< Format flag: Put integer number in upper case hexadecimal form (0X and 0123456789abcdef). Flag is ignored when the 'radix' parameter is provided.
  static const Tuint FORMAT_LOWER;      //!< Format flag: Put integer letters in lower case form (e.g. 0x53da32cb).
  static const Tuint FORMAT_UPPER;      //!< Format flag: Put integer letters in upper case form (e.g. 0x53DA32CB).
  static const Tuint FORMAT_LALIGN;     //!< Format flag: Align output characters to the left part of the width.
  static const Tuint FORMAT_RALIGN;     //!< Format flag: Align output characters to the right part of the width.
  static const Tuint FORMAT_FILL_0;     //!< Format flag: Fill remain part of output width with '0' characters.
  static const Tuint FORMAT_GROUPS;     //!< Format flag: Use group character to separate thousands (e.g. 1,253,546,312).
  static const Tuint FORMAT_DOT;        //!< Format flag: Use dot character to represent a real number (e.g. 52.063).
  static const Tuint FORMAT_exp;        //!< Format flag: Use lower case exponent form to represent a real number (e.g. 52.063e+1).
  static const Tuint FORMAT_EXP;        //!< Format flag: Use upper case exponent form to represent a real number (e.g. 52.063E+1).
  static const Tuint FORMAT_ASCII;      //!< Format flag: Use ASCII encoding to output formatted values (integers, pointers, etc).
  static const Tuint FORMAT_UNICODE;    //!< Format flag: Use UNICODE encoding to output formatted values (integers, pointers, etc).

  static const Tuint PARSE_DEFAULT;     //!< Parsing flag: Default set of parsing flags ([PARSE_ASCII | PARSE_UNICODE]).
  static const Tuint PARSE_ASCII;       //!< Parsing flag: Use ASCII encoding to input formatted values (integers, pointers, etc).
  static const Tuint PARSE_UNICODE;     //!< Parsing flag: Use UNICODE encoding to input formatted values (integers, pointers, etc).

protected:
  //! Default interface protected constructor.
  /*!
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is e_LINE_ENDING_UNIVERSAL).
  */
  IStream(const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = e_LINE_ENDING_UNIVERSAL);
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IStream interface.
  */
  IStream(const IStream& a_crInstance);

public:
  //! Interface virtual destructor.
  virtual ~IStream();

  //! Operator: Assign another IStream interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IStream interface.
      \return Reference to the current interface instance.
  */
  IStream& operator = (const IStream& a_crInstance);

  //! Set another IStream interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IStream interface.
  */
  void set(const IStream& a_crInstance);

  //! Is stream is auto-flushed?
  /*!
      \return true  - if stream is auto-flushed. \n
              false - if stream is not auto-flushed. \n
  */
  Tbool isAutoFlush() const;
  //! Set/remove stream auto-flush flag.
  /*!
      \param a_cAutoFlush - Stream auto-flush flag.
  */
  void setAutoFlush(const Tbool a_cAutoFlush);

  //! Is stream in the binary input/output mode?
  /*!
      \return true  - if stream is in the binary input/output mode. \n
              false - if stream is in the text input/output mode. \n
  */
  Tbool isBinaryMode() const;
  //! Is stream in the text input/output mode?
  /*!
      \return true  - if stream is in the text input/output mode. \n
              false - if stream is in the binary input/output mode. \n
  */
  Tbool isTextMode() const;

  //! Set input/output mode of the current stream in to the binary one.
  void setBinaryMode();
  //! Set input/output mode of the current stream in to the text one.
  void setTextMode();

  //! Set byte order type of the current stream.
  /*!
      \param a_cByteOrder - Byte order type.
  */
  void setByteOrder(const EByteOrder a_cByteOrder);
  //! Get byte order type of the current stream.
  /*!
      \return Byte order type of the current stream.
  */
  EByteOrder getByteOrder() const;

  //! Set line ending type of the current stream.
  /*!
      \param a_cLineEnding - Line ending type.
  */
  void setLineEnding(const ELineEnding a_cLineEnding);
  //! Get line ending type of the current stream.
  /*!
      \return Line ending type of the current stream.
  */
  ELineEnding getLineEnding() const;
  //! Get line ending string of the current stream.
  /*!
      \return Constant pointer to the line ending string of the current stream.
  */
  Tcstr getLineEndingString() const;
  //! Get line ending string of the current stream in ASCII encoding.
  /*!
      \return Constant pointer to the line ending string of the current stream in ASCII encoding.
  */
  Tcsstr getLineEndingStringASCII() const;
  //! Get line ending string of the current stream in Unicode encoding.
  /*!
      \return Constant pointer to the line ending string of the current stream in Unicode encoding.
  */
  Tcwstr getLineEndingStringUnicode() const;
  //! Get size of the line ending string of the current stream.
  /*!
      \return Size of the line ending string of the current stream.
  */
  Tuint getLineEndingStringSize() const;

  //! Set format flags of the current stream.
  /*!
      \param a_cFormatFlags - Combination of format flags.
  */
  void setCurrentFormatFlags(const Tuint a_cFormatFlags);
  //! Get format flags of the current stream.
  /*!
      \return Format flags of the current stream.
  */
  Tuint getCurrentFormatFlags() const;
  //! Set parse flags of the current stream.
  /*!
      \param a_cParseFlags - Combination of parse flags.
  */
  void setCurrentParseFlags(const Tuint a_cParseFlags);
  //! Get parse flags of the current stream.
  /*!
      \return Parse flags of the current stream.
  */
  Tuint getCurrentParseFlags() const;
  //! Set count of precision numbers after the decimal point of the current stream.
  /*!
      \param a_cPrecision - Count of precision numbers after the decimal point.
  */
  void setCurrentPrecision(const Tuint a_cPrecision);
  //! Get count of precision numbers after the decimal point of the current stream.
  /*!
      \return Count of precision numbers after the decimal point of the current stream.
  */
  Tuint getCurrentPrecision() const;
  //! Set width of the align place of the current stream.
  /*!
      \param a_cWidth - Width of the align place. If it greater than 0, align rules are applied.
  */
  void setCurrentWidth(const Tuint a_cWidth);
  //! Get width of the align place of the current stream.
  /*!
      \return Width of the align place of the current stream.
  */
  Tuint getCurrentWidth() const;
  //! Set radix of the output integer value of the current stream.
  /*!
      \param a_cRadix - Radix of the output integer value. Could be in range [1, 36], 0 means the radix transformation is off.
  */
  void setCurrentRadix(const Tuint a_cRadix);
  //! Get radix of the output integer value of the current stream.
  /*!
      \return Radix of the output integer value of the current stream.
  */
  Tuint getCurrentRadix() const;

  //! Set default format values of the stream.
  void setDefaultFormat();
  //! Set default parse values of the stream.
  void setDefaultParse();

  //! Get system byte order type.
  /*!
      \return Byte order type of the current system.
  */
  static EByteOrder getSystemByteOrder();
  //! Get system line ending type.
  /*!
      \return Line ending type of the current system.
  */
  static ELineEnding getSystemLineEnding();
  //! Get system line ending string.
  /*!
      \return Constant pointer to the line ending string of the current system.
  */
  static Tcstr getSystemLineEndingString();
  //! Get system line ending string in ASCII encoding.
  /*!
      \return Constant pointer to the line ending string of the current system in ASCII encoding.
  */
  static Tcsstr getSystemLineEndingStringASCII();
  //! Get system line ending string in Unicode encoding.
  /*!
      \return Constant pointer to the line ending string of the current system in Unicode encoding.
  */
  static Tcwstr getSystemLineEndingStringUnicode();
  //! Get size of the system line ending string.
  /*!
      \return Size of the the line ending string of the current system.
  */
  static Tuint getSystemLineEndingStringSize();

  //! Serialize IStream interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IStream interface instances.
  /*!
      \param a_rInstance - Reference to another IStream interface instance.
  */
  void swap(IStream& a_rInstance);

private:
  Tbool       m_IsAutoFlush;            //!< Is stream auto-flushed?
  Tbool       m_IsTextMode;             //!< Is stream inputs/outputs in text mode?
  EByteOrder  m_ByteOrder;              //!< Byte order type of the stream.
  ELineEnding m_LineEnding;             //!< Line ending type of the stream.

  Tuint m_FormatFlags;                  //!< Current format flags.
  Tuint m_ParseFlags;                   //!< Current parse flags.
  Tuint m_Precision;                    //!< Current count of precision numbers after the decimal point.
  Tuint m_Width;                        //!< Current width of the align place.
  Tuint m_Radix;                        //!< Current radix of the output integer value.

  //! Get size of the character in the current exchange stream. Only for internal usage.
  /*!
      \return Size of the character in the current exchange stream (in bytes).
  */
  virtual Tuint internalGetSCharSize() const;
  //! Get size of the wide character in the current exchange stream. Only for internal usage.
  /*!
      \return Size of the wide character in the current exchange stream (in bytes).
  */
  virtual Tuint internalGetWCharSize() const;

  //! Get size of the signed integer number in the current exchange stream. Only for internal usage.
  /*!
      \return Size of the signed integer number in the current exchange stream (in bytes).
  */
  virtual Tuint internalGetSIntSize() const;
  //! Get size of the unsigned integer number in the current exchange stream. Only for internal usage.
  /*!
      \return Size of the unsigned integer number in the current exchange stream (in bytes).
  */
  virtual Tuint internalGetUIntSize() const;

  //! Get size of the pointer value in the current exchange stream. Only for internal usage.
  /*!
      \return Size of the pointer value in the current exchange stream (in bytes).
  */
  virtual Tuint internalGetPtrSize() const;

  //! Is the current exchange stream keeps real numbers as float ones? Only for internal usage.
  /*!
      \return true  - if the current exchange stream keeps real numbers as float ones. \n
              false - if the current exchange stream keeps real numbers as double ones. \n
  */
  virtual Tbool internalIsRealFloat() const;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* SERIALIZATION FUNCTION DECLARATIONS                                      */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
//! Serialization load byte order type of the stream.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized byte order type of the stream instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NStream::IStream::EByteOrder& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save byte order type of the stream.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized byte order type of the stream instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NStream::IStream::EByteOrder& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize byte order type of the stream.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized byte order type of the stream instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NStream::IStream::EByteOrder& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization load line ending type of the stream.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized line ending type of the stream instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NStream::IStream::ELineEnding& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save line ending type of the stream.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized line ending type of the stream instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NStream::IStream::ELineEnding& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize line ending type of the stream.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized line ending type of the stream instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NStream::IStream::ELineEnding& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization load open type of the stream.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized open type of the stream instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NStream::IStream::EOpenType& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save open type of the stream.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized open type of the stream instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NStream::IStream::EOpenType& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize open type of the stream.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized open type of the stream instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NStream::IStream::EOpenType& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/IStream.inl>
/*==========================================================================*/
#endif
