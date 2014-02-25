/*!
 *  \file    IFilterFramePack.hpp Frame packing filter stream interface is a
 *           base interface for all implementations of stream frame packing
 *           filter classes which are used to perform data pack operations
 *           using read and write frame buffering operations.
 *  \brief   Frame packing filter interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Frame packing filter interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   10.11.2009 03:39:25

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
#ifndef __IFILTERFRAMEPACK_HPP__
#define __IFILTERFRAMEPACK_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/stream/IFilter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NPack {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Frame packing filter interface.
/*!
    Frame packing filter interface is a base interface for all  classes  which
    performs  frame  pack  filtering  operations  with  data   during   stream
    input/output operations.

    Frame packing filter is initialized by providing input/output  frame  size
    in bytes through template arguments.

    Frame packing filter implementations should override 'onOpenReadFrame()' /
    'onOpenWriteFrame()'   methods   to   provide   special   packing    frame
    initializations.

    Frame packing filter implementations should override 'onPackReadFrame()' /
    'onPackWriteFrame()'   methods   to   provide   special   packing    frame
    functionality.

    Frame packing filter implementations should override  'onCloseReadFrame()'
    /  'onCloseWriteFrame()'  methods  to  provide   special   packing   frame
    deinitializations.
*/
template <Tuint t_ReadFrameSize, Tuint t_WriteFrameSize = t_ReadFrameSize>
class IFilterFramePack :
  public IFilter
{
  STATIC_ASSERT((t_ReadFrameSize > 0), STR("Read frame buffer size should be greater than 0."))
  STATIC_ASSERT((t_WriteFrameSize > 0), STR("Write frame buffer size should be greater than 0."))

  //! Type for the MConceptDepthType constraint checking.
  typedef IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize> TDepthCheckType;

  // Check IFilterFramePack interface constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

protected:
  //! Default interface protected constructor. Create disconnected filter.
  /*!
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IFilterFramePack(const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IFilterFramePack(IReader* a_pReader, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given writer.
  /*!
      \param a_pWriter - Pointer to the writer interface.
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IFilterFramePack(IWriter* a_pWriter, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader & writer.
  /*!
      \param a_pReaderWriter - Pointer to the reader & writer interface.
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IFilterFramePack(IReaderWriter* a_pReaderWriter, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given separate reader and writer.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_pWriter - Pointer to the writer interface.
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  IFilterFramePack(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Interface protected copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the IFilterFramePack interface.
  */
  IFilterFramePack(const IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>& a_crInstance);

public:
  //! Interface virtual destructor.
  virtual ~IFilterFramePack();

  //! Operator: Assign another IFilterFramePack interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IFilterFramePack interface.
      \return Reference to the current interface instance.
  */
  IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>& operator = (const IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>& a_crInstance);

  //! Set another IFilterFramePack interface instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the IFilterFramePack interface.
      \return true  - if another filter was successfully set. \n
              false - if another filter was not successfully set. \n
  */
  Tbool set(const IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>& a_crInstance);

  //! Get current size of the read frame buffer.
  /*!
      Method returns current size of the read frame buffer.

      \return Current size of the read frame buffer in bytes.
  */
  Tuint getReadFrameSize() const;
  //! Get current size of the write frame buffer.
  /*!
      Method returns current size of the write frame buffer.

      \return Current size of the write frame buffer in bytes.
  */
  Tuint getWriteFrameSize() const;

  //! Get free size of the read frame buffer.
  /*!
      Method returns free size of the read frame buffer.

      \return Free size of the read frame buffer in bytes.
  */
  Tuint getReadFrameFreeSize() const;
  //! Get free size of the write frame buffer.
  /*!
      Method returns free size of the write frame buffer.

      \return Free size of the write frame buffer in bytes.
  */
  Tuint getWriteFrameFreeSize() const;

  //! Get full size of the read frame buffer.
  /*!
      Method returns full size of the read frame buffer.

      \return Full size of the read frame buffer in bytes.
  */
  Tuint getReadFrameFullSize() const;
  //! Get full size of the write frame buffer.
  /*!
      Method returns full size of the write frame buffer.

      \return Full size of the write frame buffer in bytes.
  */
  Tuint getWriteFrameFullSize() const;

  //! Get pointer to the read frame buffer.
  /*!
      Method returns pointer to the read frame buffer.

      \return Pointer to the read frame buffer.
  */
  Tbuffer getReadFrame();
  //! Get constant pointer to the read frame buffer.
  /*!
      Method returns constant pointer to the read frame buffer.

      \return Constant pointer to the read frame buffer.
  */
  Tcbuffer getReadFrame() const;

  //! Get pointer to the write frame buffer.
  /*!
      Method returns pointer to the write frame buffer.

      \return Pointer to the write frame buffer.
  */
  Tbuffer getWriteFrame();
  //! Get constant pointer to the write frame buffer.
  /*!
      Method returns constant pointer to the write frame buffer.

      \return Constant pointer to the write frame buffer.
  */
  Tcbuffer getWriteFrame() const;

  //! Serialize IFilterFramePack interface instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two IFilterFramePack interface instances.
  /*!
      \param a_rInstance - Reference to another IFilterFramePack interface instance.
  */
  void swap(IFilterFramePack<t_ReadFrameSize, t_WriteFrameSize>& a_rInstance);

protected:
  // IReaderWriter interface overriding methods.
  virtual Tbool onOpen(const EOpenType a_cOpenType);
  virtual Tbool onClose();

  // IFilter interface overriding methods.
  virtual Tuint onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize);

  //! Abstract frame packing filter open reader handler.
  /*!
      This  method  should  be  overridden  in  the  frame  packing   filters'
      implementations in order to perform additional manipulations  with  read
      packing filter initialization.

      \param a_rReader - Reference to the reader.
      \param a_pBuffer - Pointer to the read frame byte buffer.
      \param a_rCurrentSize - Reference to the current size of the buffer (in bytes).
      \param a_cFullSize - Full size of the buffer (in bytes).
      \return true  - if frame packing filter was successfully opened for reading. \n
              false - if frame packing filter was not successfully opened for reading. \n
  */
  virtual Tbool onOpenReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize) = 0;
  //! Abstract frame packing filter open writer handler.
  /*!
      This  method  should  be  overridden  in  the  frame  packing   filters'
      implementations in order to perform additional manipulations with  write
      packing filter initialization.

      \param a_rWriter - Reference to the writer.
      \param a_pBuffer - Pointer to the write frame byte buffer.
      \param a_rCurrentSize - Reference to the current size of the buffer (in bytes).
      \param a_cFullSize - Full size of the buffer (in bytes).
      \return true  - if frame packing filter was successfully opened for writing. \n
              false - if frame packing filter was not successfully opened for writing. \n
  */
  virtual Tbool onOpenWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize) = 0;

  //! Abstract frame packing filter pack reader handler.
  /*!
      This  method  should  be  overridden  in  the  frame  packing   filters'
      implementations in order to perform packing of the read buffer.

      \param a_rReader - Reference to the reader.
      \param a_pBuffer - Pointer to the read frame byte buffer.
      \param a_rCurrentSize - Reference to the current size of the buffer (in bytes).
      \param a_cFullSize - Full size of the buffer (in bytes).
      \return true  - if frame packing filter was successfully packed. \n
              false - if frame packing filter was not successfully packed. \n
  */
  virtual Tbool onPackReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize) = 0;
  //! Abstract frame packing filter pack writer handler.
  /*!
      This  method  should  be  overridden  in  the  frame  packing   filters'
      implementations in order to perform packing of the write buffer.

      \param a_rWriter - Reference to the writer.
      \param a_pBuffer - Pointer to the write frame byte buffer.
      \param a_rCurrentSize - Reference to the current size of the buffer (in bytes).
      \param a_cFullSize - Full size of the buffer (in bytes).
      \return true  - if frame packing filter was successfully packed. \n
              false - if frame packing filter was not successfully packed. \n
  */
  virtual Tbool onPackWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize) = 0;

  //! Abstract frame packing filter close reader handler.
  /*!
      This  method  should  be  overridden  in  the  frame  packing   filters'
      implementations in order to perform additional manipulations  with  read
      packing filter deinitialization.

      \param a_rReader - Reference to the reader.
      \param a_pBuffer - Pointer to the read frame byte buffer.
      \param a_rCurrentSize - Reference to the current size of the buffer (in bytes).
      \param a_cFullSize - Full size of the buffer (in bytes).
      \return true  - if frame packing filter was successfully closed. \n
              false - if frame packing filter was not successfully closed. \n
  */
  virtual Tbool onCloseReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize) = 0;
  //! Abstract frame packing filter close writer handler.
  /*!
      This  method  should  be  overridden  in  the  frame  packing   filters'
      implementations in order to perform additional manipulations with  write
      packing filter deinitialization.

      \param a_rWriter - Reference to the writer.
      \param a_pBuffer - Pointer to the write frame byte buffer.
      \param a_rCurrentSize - Reference to the current size of the buffer (in bytes).
      \param a_cFullSize - Full size of the buffer (in bytes).
      \return true  - if frame packing filter was successfully closed. \n
              false - if frame packing filter was not successfully closed. \n
  */
  virtual Tbool onCloseWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize) = 0;

private:
  Tuint m_ReadFrameSize;                //!< Current read frame size.
  Tuint m_WriteFrameSize;               //!< Current write frame size.
  Tbyte m_ReadFrame[t_ReadFrameSize];   //!< Read frame buffer.
  Tbyte m_WriteFrame[t_WriteFrameSize]; //!< Write frame buffer.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/pack/IFilterFramePack.inl>
/*==========================================================================*/
#endif
