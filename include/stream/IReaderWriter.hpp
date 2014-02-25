/*!
 *  \file    IReaderWriter.hpp Reader & Writer is a base stream interface for
 *           all implementations of stream classes which use byte input and
 *           output at the same time.
 *  \brief   Reader & Writer interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reader & Writer interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   15.08.2008 22:43:09

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
#ifndef __IREADERWRITER_HPP__
#define __IREADERWRITER_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/IReader.hpp>
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
//! Reader & Writer interface.
/*!
    Reader and Writer interface is a base  interface  for  all  classes  which
    contain both reader and writer functionality and could be used  for  input
    and output at the same time.
*/
class BASE_API IReaderWriter :
  public IReader,
  public IWriter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef IReaderWriter TDepthCheckType;

  // Check IReaderWriter interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  //! Default interface protected constructor.
  /*!
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IReaderWriter(const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IReaderWriter interface.
  */
  IReaderWriter(const IReaderWriter& a_crInstance);

public:
  //! Interface virtual destructor.
  virtual ~IReaderWriter();

  //! Operator: Assign another IReaderWriter interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IReaderWriter interface.
      \return Reference to the current interface instance.
  */
  IReaderWriter& operator = (const IReaderWriter& a_crInstance);

  //! Set another IReaderWriter interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IReaderWriter interface.
      \return true  - if another reader & writer was successfully set. \n
              false - if another reader & writer was not successfully set. \n
  */
  Tbool set(const IReaderWriter& a_crInstance);

  //! Is stream opened?
  /*!
      \return true  - if stream is opened. \n
              false - if stream is not opened. \n
  */
  Tbool isOpened() const;
  //! Is stream opened for reading?
  /*!
      \return true  - if stream is opened for reading. \n
              false - if stream is not opened for reading. \n
  */
  Tbool isOpenedRead() const;
  //! Is stream opened for writing?
  /*!
      \return true  - if stream is opened for writing. \n
              false - if stream is not opened for writing. \n
  */
  Tbool isOpenedWrite() const;
  //! Is stream opened for both reading and writing?
  /*!
      \return true  - if stream is opened for both reading and writing. \n
              false - if stream is not opened for both reading and writing. \n
  */
  Tbool isOpenedReadWrite() const;
  //! Is stream met read or write 'end of file'?
  /*!
      \return true  - if stream met read or write 'end of file'. \n
              false - if stream did not meet read or write 'end of file'. \n
  */
  Tbool isEOF() const;
  //! Is stream met read 'end of file'?
  /*!
      \return true  - if stream met read 'end of file'. \n
              false - if stream did not meet read 'end of file'. \n
  */
  Tbool isEOFRead() const;
  //! Is stream met write 'end of file'?
  /*!
      \return true  - if stream met write 'end of file'. \n
              false - if stream did not meet write 'end of file'. \n
  */
  Tbool isEOFWrite() const;
  //! Is stream met both read and write 'end of file'?
  /*!
      \return true  - if stream met both read and write 'end of file'. \n
              false - if stream did not meet both read and write 'end of file'. \n
  */
  Tbool isEOFReadWrite() const;

  //! Open stream.
  /*!
      \param a_cOpenType - Open type of the stream.
      \return true  - if stream was opened successfully. \n
              false - if stream was not opened successfully. \n
  */
  Tbool open(const EOpenType a_cOpenType);
  //! Open stream for reading.
  /*!
      \return true  - if stream was opened successfully. \n
              false - if stream was not opened successfully. \n
  */
  Tbool openRead();
  //! Open stream for writing.
  /*!
      \return true  - if stream was opened successfully. \n
              false - if stream was not opened successfully. \n
  */
  Tbool openWrite();
  //! Open stream for reading and writing.
  /*!
      \return true  - if stream was opened successfully. \n
              false - if stream was not opened successfully. \n
  */
  Tbool openReadWrite();

  //! Flush stream.
  /*!
      \return true  - if stream was flushed successfully. \n
              false - if stream was not flushed successfully. \n
  */
  Tbool flush();

  //! Close stream.
  /*!
      \return true  - if stream was closed successfully. \n
              false - if stream was not closed successfully. \n
  */
  Tbool close();

  //! Serialize IReaderWriter interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IReaderWriter interface instances.
  /*!
      \param a_rInstance - Reference to another IReaderWriter interface instance.
  */
  void swap(IReaderWriter& a_rInstance);

protected:
  //! Abstract reader open method.
  /*!
      \return true  - if reader was opened successfully. \n
              false - if reader was not opened successfully. \n
  */
  virtual Tbool onOpen();
  //! Abstract reader & writer open method.
  /*!
      \param a_cOpenType - Open type of the stream.
      \return true  - if reader & writer was opened successfully. \n
              false - if reader & writer was not opened successfully. \n
  */
  virtual Tbool onOpen(const EOpenType a_cOpenType) = 0;
  //! Abstract reader & writer flush method.
  /*!
      \return true  - if reader & writer was flushed successfully. \n
              false - if reader & writer was not flushed successfully. \n
  */
  virtual Tbool onFlush() = 0;
  //! Abstract reader & writer close method.
  /*!
      \return true  - if reader & writer was closed successfully. \n
              false - if reader & writer was not closed successfully. \n
  */
  virtual Tbool onClose() = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/IReaderWriter.inl>
/*==========================================================================*/
#endif
