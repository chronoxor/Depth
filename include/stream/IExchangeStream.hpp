/*!
 *  \file    IExchangeStream.hpp Exchange stream is a base interface for all
 *           implementations of interprocess communication stream classes
 *           (files, pipes, sockets, etc.).
 *  \brief   Exchange stream interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Exchange stream interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   24.03.2009 21:59:39

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
#ifndef __IEXCHANGESTREAM_HPP__
#define __IEXCHANGESTREAM_HPP__
/*==========================================================================*/
#include <Depth/include/stream/IStream.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Exchange stream interface.
/*!
    Exchange stream  interface  is  a  base  interface  for  all  interprocess
    communication stream classes (files, pipes, sockets, etc.).

    Exchange streams use initialization header in binary input/output mode  in
    order to provide/get necessary information about current stream:
    \li Header version;
    \li Byte order type (big-endian or little-endian);
    \li Size of the character;
    \li Size of the wide character;
    \li Size of the signed integer number;
    \li Size of the unsigned integer number;
    \li Size of the pointer value;
    \li Real number type (float or double);

    For text input/output in ASCII encoding exchange streams use simple buffer
    input/output in binary mode.

    For text input/output in Unicode encoding exchange streams use  convertion
    into the UTF-8 encoding and then  simple  buffer  input/output  in  binary
    mode.
*/
class BASE_API IExchangeStream :
  virtual public IStream
{
  // Friend interface: Exchange reader interface (IExchangeReader).
  friend class IExchangeReader;
  // Friend interface: Exchange writer interface (IExchangeWriter).
  friend class IExchangeWriter;
  // Friend interface: Exchange reader & writer interface (IExchangeReaderWriter).
  friend class IExchangeReaderWriter;

  //! Type for the MConceptDepthType constraint checking.
  typedef IExchangeStream TDepthCheckType;

  // Check IExchangeStream interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  //! Default interface protected constructor.
  /*!
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
      \param a_cIsExchange - Exchange stream flag (default is false).
  */
  IExchangeStream(const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL, const Tbool a_cIsExchange = false);
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IExchangeStream interface.
  */
  IExchangeStream(const IExchangeStream& a_crInstance);

public:
  //! Interface virtual destructor.
  virtual ~IExchangeStream();

  //! Operator: Assign another IExchangeStream interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IExchangeStream interface.
      \return Reference to the current interface instance.
  */
  IExchangeStream& operator = (const IExchangeStream& a_crInstance);

  //! Set another IExchangeStream interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IExchangeStream interface.
  */
  void set(const IExchangeStream& a_crInstance);

  //! Is the current stream working as an exchange one?
  /*!
      \return true  - if the current stream is working as an exchange one. \n
              false - if the current stream is not working as an exchange one. \n
  */
  Tbool isExchange() const;
  //! Set exchange flag of the current stream.
  /*!
      \param a_cIsExchange - New exchange flag of the current stream.
      \return true  - if new exchange flag was successfully set for the current stream. \n
              false - if new exchange flag was not successfully set for the current stream. \n
  */
  virtual Tbool setExchange(const Tbool a_cIsExchange) = 0;

  //! Get version of the current exchange stream.
  /*!
      \return Version of the current exchange stream.
  */
  Tuint exchangeGetVersion() const;

  //! Is the current exchange stream byte order is big-endian?
  /*!
      \return true  - if the current exchange stream byte order is big-endian. \n
              false - if the current exchange stream byte order is little-endian. \n
  */
  Tbool exchangeIsBigEndian() const;
  //! Is the current exchange stream byte order is little-endian?
  /*!
      \return true  - if the current exchange stream byte order is little-endian. \n
              false - if the current exchange stream byte order is big-endian. \n
  */
  Tbool exchangeIsLittleEndian() const;

  //! Get size of the character in the current exchange stream.
  /*!
      \return Size of the character in the current exchange stream (in bytes).
  */
  Tuint exchangeGetSCharSize() const;
  //! Get size of the wide character in the current exchange stream.
  /*!
      \return Size of the wide character in the current exchange stream (in bytes).
  */
  Tuint exchangeGetWCharSize() const;

  //! Get size of the signed integer number in the current exchange stream.
  /*!
      \return Size of the signed integer number in the current exchange stream (in bytes).
  */
  Tuint exchangeGetSIntSize() const;
  //! Get size of the unsigned integer number in the current exchange stream.
  /*!
      \return Size of the unsigned integer number in the current exchange stream (in bytes).
  */
  Tuint exchangeGetUIntSize() const;

  //! Get size of the pointer value in the current exchange stream.
  /*!
      \return Size of the pointer value in the current exchange stream (in bytes).
  */
  Tuint exchangeGetPtrSize() const;

  //! Is the current exchange stream keeps real numbers as float ones?
  /*!
      \return true  - if the current exchange stream keeps real numbers as float ones. \n
              false - if the current exchange stream keeps real numbers as double ones. \n
  */
  Tbool exchangeIsRealFloat() const;
  //! Is the current exchange stream keeps real numbers as double ones?
  /*!
      \return true  - if the current exchange stream keeps real numbers as double ones. \n
              false - if the current exchange stream keeps real numbers as float ones. \n
  */
  Tbool exchangeIsRealDouble() const;

  //! Serialize IExchangeStream interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IExchangeStream interface instances.
  /*!
      \param a_rInstance - Reference to another IExchangeStream interface instance.
  */
  void swap(IExchangeStream& a_rInstance);

protected:
  Tbool m_IsExchange;                   //!< Is stream working as an exchange one?
  Tuint m_Version;                      //!< Version of the exchange stream.
  Tuint m_SCharSize;                    //!< Size of the character (in bytes).
  Tuint m_WCharSize;                    //!< Size of the wide character (in bytes).
  Tuint m_SIntSize;                     //!< Size of the signed integer number (in bytes).
  Tuint m_UIntSize;                     //!< Size of the unsigned integer number (in bytes).
  Tuint m_PtrSize;                      //!< Size of the pointer value (in bytes).
  Tbool m_IsRealFloat;                  //!< Is real number type is float?

private:
  // IStream interface overriding methods.
  virtual Tuint internalGetSCharSize() const;
  virtual Tuint internalGetWCharSize() const;
  virtual Tuint internalGetSIntSize() const;
  virtual Tuint internalGetUIntSize() const;
  virtual Tuint internalGetPtrSize() const;
  virtual Tbool internalIsRealFloat() const;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/IExchangeStream.inl>
/*==========================================================================*/
#endif
