/*!
 *  \file    IFilter.hpp Filter stream interface is a base interface for
 *           all implementations of stream filter classes which are used
 *           to perform additional data manipulation during input/output
 *           operations (e.g. buffering, encoding / decoding, inflating /
 *           deflating, etc.).
 *  \brief   Filter interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Filter interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   18.03.2009 02:49:24

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
#ifndef __IFILTER_HPP__
#define __IFILTER_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/IReaderWriter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Filter interface.
/*!
    Filter interface is a  base  interface  for  all  classes  which  performs
    filtering operations with data during stream input/output operations.

    The common use of the filter is when it is connected to the stream  or  to
    another filter and process data during input/output operations. The common
    usage schema is the following:

      Filter1 -> ... -> FilterN -> Stream (IReader or IWriter or IReaderWriter)

    Opening and reading/writing from/into the 'Filter1' will  cause  the  same
    operation in the 'Stream' with performing additional  data  processing  in
    each  filter  in  forward  order  form   'Filter1'   to   'FilterN'   (for
    writing/pushing  operations)  or  in  backward  order  form  'FilterN'  to
    'Filter1' (for reading/peeking operations).
*/
class BASE_API IFilter :
  public IReaderWriter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef IFilter TDepthCheckType;

  // Check IFilter interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  //! Default interface protected constructor. Create disconnected filter.
  /*!
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IFilter(const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IFilter(IReader* a_pReader, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given writer.
  /*!
      \param a_pWriter - Pointer to the writer interface.
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IFilter(IWriter* a_pWriter, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader & writer.
  /*!
      \param a_pReaderWriter - Pointer to the reader & writer interface.
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IFilter(IReaderWriter* a_pReaderWriter, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given separate reader and writer.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_pWriter - Pointer to the writer interface.
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IFilter(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IFilter interface.
  */
  IFilter(const IFilter& a_crInstance);

public:
  //! Interface virtual destructor.
  virtual ~IFilter();

  //! Operator: Assign another IFilter interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IFilter interface.
      \return Reference to the current interface instance.
  */
  IFilter& operator = (const IFilter& a_crInstance);

  //! Set another IFilter interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IFilter interface.
      \return true  - if another filter was successfully set. \n
              false - if another filter was not successfully set. \n
  */
  Tbool set(const IFilter& a_crInstance);

  //! Is filter readable?
  /*!
      \return true  - if filter is readable. \n
              false - if filter is not readable. \n
  */
  virtual Tbool isReadable() const;
  //! Is filter writable?
  /*!
      \return true  - if filter is writable. \n
              false - if filter is not writable. \n
  */
  virtual Tbool isWritable() const;

  //! Connect/disconnect reader with/form the current filter.
  /*!
      \param a_pReader - Pointer to the reader interface or NULL for disconnection.
      \return true  - if reader was successfully connected/disconnected. \n
              false - if reader was not successfully connected/disconnected. \n
  */
  Tbool setReader(IReader* a_pReader);
  //! Connect/disconnect writer with/form the current filter.
  /*!
      \param a_pWriter - Pointer to the writer interface or NULL for disconnection.
      \return true  - if writer was successfully connected/disconnected. \n
              false - if writer was not successfully connected/disconnected. \n
  */
  Tbool setWriter(IWriter* a_pWriter);
  //! Connect/disconnect reader & writer with/form the current filter.
  /*!
      \param a_pReaderWriter - Pointer to the reader & writer interface or NULL for disconnection.
      \return true  - if reader & writer was successfully connected/disconnected. \n
              false - if reader & writer was not successfully connected/disconnected. \n
  */
  Tbool setReaderWriter(IReaderWriter* a_pReaderWriter);
  //! Connect/disconnect separate reader and writer with/form the current filter.
  /*!
      \param a_pReader - Pointer to the reader interface or NULL for disconnection.
      \param a_pWriter - Pointer to the writer interface or NULL for disconnection.
      \return true  - if reader and writer were successfully connected/disconnected. \n
              false - if reader and writer were not successfully connected/disconnected. \n
  */
  Tbool setReaderWriter(IReader* a_pReader, IWriter* a_pWriter);

  //! Get pointer to the current connected reader.
  /*!
      \return Pointer to the current connected reader interface.
  */
  IReader* getReader();
  //! Get constant pointer to the current connected reader.
  /*!
      \return Constant pointer to the current connected reader interface.
  */
  const IReader* getReader() const;

  //! Get pointer to the current connected writer.
  /*!
      \return Pointer to the current connected writer interface.
  */
  IWriter* getWriter();
  //! Get constant pointer to the current connected writer.
  /*!
      \return Constant pointer to the current connected writer interface.
  */
  const IWriter* getWriter() const;

  //! Serialize IFilter interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IFilter interface instances.
  /*!
      \param a_rInstance - Reference to another IFilter interface instance.
  */
  void swap(IFilter& a_rInstance);

protected:
  // IReaderWriter interface overriding methods.
  virtual Tbool onOpen(const EOpenType a_cOpenType);
  virtual Tuint onReadBinary(Tptr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onReadText(Tsstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onReadText(Twstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onWriteBinary(Tcptr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onWriteText(Tcsstr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onWriteText(Tcwstr a_cpBuffer, const Tuint a_cSize);
  virtual Tbool onFlush();
  virtual Tbool onClose();

  //! Abstract filter binary read method.
  /*!
      This method should be overridden  in  the  filters'  implementations  in
      order to perform additional manipulations with data read from the  given
      reader.

      \param a_rReader - Reference to the reader.
      \param a_pBuffer - Pointer to the byte buffer.
      \param a_cSize - Size of the buffer (in bytes).
      \return Count of read and filtered bytes.
  */
  virtual Tuint onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize) = 0;
  //! Abstract filter ASCII text read method.
  /*!
      This method should be overridden  in  the  filters'  implementations  in
      order to perform additional manipulations with data read from the  given
      reader.

      \param a_rReader - Reference to the reader.
      \param a_pBuffer - Pointer to the ASCII text buffer.
      \param a_cSize - Size of the ASCII text buffer (in characters).
      \return Count of read and filtered characters.
  */
  virtual Tuint onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize) = 0;
  //! Abstract filter Unicode text read method.
  /*!
      This method should be overridden  in  the  filters'  implementations  in
      order to perform additional manipulations with data read from the  given
      reader.

      \param a_rReader - Reference to the reader.
      \param a_pBuffer - Pointer to the Unicode text buffer.
      \param a_cSize - Size of the Unicode text buffer (in characters).
      \return Count of read and filtered characters.
  */
  virtual Tuint onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize) = 0;

  //! Abstract filter binary write method.
  /*!
      This method should be overridden  in  the  filters'  implementations  in
      order to perform additional manipulations with data  before  write  into
      the given writer.

      \param a_rWriter - Reference to the writer.
      \param a_cpBuffer - Constant pointer to the byte buffer.
      \param a_cSize - Size of the buffer (in bytes).
      \return Count of filtered and written bytes.
  */
  virtual Tuint onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize) = 0;
  //! Abstract filter ASCII text write method.
  /*!
      This method should be overridden  in  the  filters'  implementations  in
      order to perform additional manipulations with data  before  write  into
      the given writer.

      \param a_rWriter - Reference to the writer.
      \param a_cpBuffer - Constant pointer to the ASCII text buffer.
      \param a_cSize - Size of the ASCII text buffer (in characters).
      \return Count of filtered and written characters.
  */
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize) = 0;
  //! Abstract filter Unicode text write method.
  /*!
      This method should be overridden  in  the  filters'  implementations  in
      order to perform additional manipulations with data  before  write  into
      the given writer.

      \param a_rWriter - Reference to the writer.
      \param a_cpBuffer - Constant pointer to the Unicode text buffer.
      \param a_cSize - Size of the Unicode text buffer (in characters).
      \return Count of filtered and written characters.
  */
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize) = 0;

private:
  IReader* m_pReader;                   //!< Pointer to the current connected reader stream.
  IWriter* m_pWriter;                   //!< Pointer to the current connected writer stream.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/IFilter.inl>
/*==========================================================================*/
#endif
