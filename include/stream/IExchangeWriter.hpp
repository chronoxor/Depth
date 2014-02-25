/*!
 *  \file    IExchangeWriter.hpp Exchange stream writer is a base interface
 *           for all implementations of exchange stream classes which use
 *           interprocess communication byte output (files, pipes, sockets,
 *           etc.).
 *  \brief   Exchange writer interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Exchange writer interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   26.03.2009 22:22:34

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
#ifndef __IEXCHANGEWRITER_HPP__
#define __IEXCHANGEWRITER_HPP__
/*==========================================================================*/
#include <Depth/include/stream/IExchangeStream.hpp>
#include <Depth/include/stream/IWriter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Exchange writer interface.
/*!
    Exchange writer  interface  is  a  base  interface  for  all  interprocess
    communication writer stream classes (files, pipes, sockets, etc.).
*/
class BASE_API IExchangeWriter :
  virtual public IExchangeStream,
  public IWriter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef IExchangeWriter TDepthCheckType;

  // Check IExchangeWriter interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  //! Default interface protected constructor.
  /*!
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
      \param a_cIsExchange - Exchange stream flag (default is false).
  */
  IExchangeWriter(const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL, const Tbool a_cIsExchange = false);
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IExchangeWriter interface.
  */
  IExchangeWriter(const IExchangeWriter& a_crInstance);

public:
  //! Interface virtual destructor.
  virtual ~IExchangeWriter();

  //! Operator: Assign another IExchangeWriter interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IExchangeWriter interface.
      \return Reference to the current interface instance.
  */
  IExchangeWriter& operator = (const IExchangeWriter& a_crInstance);

  //! Set another IExchangeWriter interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IExchangeWriter interface.
      \return true  - if another exchange writer was successfully set. \n
              false - if another exchange writer was not successfully set. \n
  */
  Tbool set(const IExchangeWriter& a_crInstance);

  // IExchangeStream interface overriding methods.
  virtual Tbool setExchange(const Tbool a_cIsExchange);

  //! Serialize IExchangeWriter interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IExchangeWriter interface instances.
  /*!
      \param a_rInstance - Reference to another IExchangeWriter interface instance.
  */
  void swap(IExchangeWriter& a_rInstance);

protected:
  // IWriter interface overriding methods.
  virtual Tbool onOpen();
  virtual Tuint onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/IExchangeWriter.inl>
/*==========================================================================*/
#endif
