/*!
 *  \file    CStreamBuffer.hpp Byte buffer stream class gives ability to
 *           read/write byte sequences from/into the static or dynamic byte
 *           buffer.
 *  \brief   Byte buffer stream class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Byte buffer stream class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   20.08.2008 20:58:46

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
#ifndef __CSTREAMBUFFER_HPP__
#define __CSTREAMBUFFER_HPP__
/*==========================================================================*/
#include <Depth/include/common/ISeekable.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/IReaderWriter.hpp>
#include <Depth/include/utility/CBuffer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Byte buffer stream class.
/*!
    Byte buffer stream class gives ability to perform input/output  operations
    directly into/from the byte buffer.

    When the buffer stream is dynamic (created from the initial  buffer  size)
    any write operation which bounds outside the buffer will resize  the  byte
    buffer dynamically.

    When the buffer stream is static (created from the given buffer  of  fixed
    size), its size will be limited to the base buffer size.
*/
class BASE_API CStreamBuffer :
  public IReaderWriter,
  public NCommon::ISeekable,
  public NUtility::CBuffer
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CStreamBuffer TDepthCheckType;

  // Check CStreamBuffer class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize dynamic or static buffer stream of fixed size.
  /*!
      Creates dynamic or static buffer stream with the given size.

      \param a_cSize - Initial size of the dynamic or static buffer stream in bytes (default is 0).
      \param a_cStatic - Static buffer flag (default is false).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::getSystemByteOrder()).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::getSystemLineEnding()).
  */
  CStreamBuffer(const Tuint a_cSize = 0, const Tbool a_cStatic = false, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::getSystemByteOrder(), const ELineEnding a_cLineEnding = IStream::getSystemLineEnding());
  //! Initialize dynamic or static buffer stream from the given buffer of fixed size.
  /*!
      Creates dynamic or static buffer stream from the given buffer  of  fixed
      size. Given byte buffer will be copied to the created one.

      \param a_cpBuffer - Constant pointer to the byte buffer.
      \param a_cSize - Size of the byte buffer in bytes.
      \param a_cStatic - Static buffer flag (default is false).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::getSystemByteOrder()).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::getSystemLineEnding()).
  */
  CStreamBuffer(Tcbuffer a_cpBuffer, const Tuint a_cSize, const Tbool a_cStatic = false, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::getSystemByteOrder(), const ELineEnding a_cLineEnding = IStream::getSystemLineEnding());
  //! Initialize dynamic or static buffer stream from the given buffer of fixed size.
  /*!
      Creates dynamic or static buffer stream from the given buffer  of  fixed
      size. If the static flag is not set, dynamic buffer will be created  and
      the given buffer will be copied into it.  Otherwise  given  byte  buffer
      will be copied to the dynamically created one.

      \param a_pBuffer - Pointer to the byte buffer.
      \param a_cSize - Size of the byte buffer in bytes.
      \param a_cStatic - Static buffer flag (default is true).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::getSystemByteOrder()).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::getSystemLineEnding()).
  */
  CStreamBuffer(Tbuffer a_pBuffer, const Tuint a_cSize, const Tbool a_cStatic = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::getSystemByteOrder(), const ELineEnding a_cLineEnding = IStream::getSystemLineEnding());
  //! Initialize buffer stream from the given byte buffer.
  /*!
      \param a_crBuffer - Constant reference to the instance of the CBuffer class.
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::getSystemByteOrder()).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::getSystemLineEnding()).
  */
  CStreamBuffer(const NUtility::CBuffer& a_crBuffer, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::getSystemByteOrder(), const ELineEnding a_cLineEnding = IStream::getSystemLineEnding());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamBuffer class.
  */
  CStreamBuffer(const CStreamBuffer& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStreamBuffer();

  //! Operator: Assign CBuffer class instance.
  /*!
      \param a_crBuffer - Constant reference to another instance of the CBuffer class.
      \return Reference to the current class instance.
  */
  CStreamBuffer& operator = (const NUtility::CBuffer& a_crBuffer);
  //! Operator: Assign another CStreamBuffer class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamBuffer class.
      \return Reference to the current class instance.
  */
  CStreamBuffer& operator = (const CStreamBuffer& a_crInstance);

  //! Set dynamic or static buffer stream of fixed size.
  /*!
      Prepare dynamic or static buffer stream with the given size.

      \param a_cSize - Initial size of the dynamic or static buffer stream in bytes.
      \param a_cStatic - Static buffer flag (default is false).
      \return true  - if buffer stream was successfully set. \n
              false - if buffer stream was not successfully set. \n
  */
  Tbool set(const Tuint a_cSize, const Tbool a_cStatic = false);
  //! Set dynamic or static buffer stream from the given buffer of fixed size.
  /*!
      Prepare dynamic or static buffer stream from the given buffer  of  fixed
      size. Given byte buffer will be copied to the created one.

      \param a_cpBuffer - Constant pointer to the byte buffer.
      \param a_cSize - Size of the byte buffer in bytes.
      \param a_cStatic - Static buffer flag (default is false).
      \return true  - if buffer stream was successfully set. \n
              false - if buffer stream was not successfully set. \n
  */
  Tbool set(Tcbuffer a_cpBuffer, const Tuint a_cSize, const Tbool a_cStatic = false);
  //! Set dynamic or static buffer stream from the given buffer of fixed size.
  /*!
      Prepare dynamic or static buffer stream from the given buffer  of  fixed
      size. If the static flag is not set, dynamic buffer will be created  and
      the given buffer will be copied into it.  Otherwise  given  byte  buffer
      will be copied to the dynamically created one.

      \param a_pBuffer - Pointer to the byte buffer.
      \param a_cSize - Size of the byte buffer in bytes.
      \param a_cStatic - Static buffer flag (default is true).
      \return true  - if buffer stream was successfully set. \n
              false - if buffer stream was not successfully set. \n
  */
  Tbool set(Tbuffer a_pBuffer, const Tuint a_cSize, const Tbool a_cStatic = true);
  //! Set CBuffer class instance.
  /*!
      \param a_crBuffer - Constant reference to the instance of the CBuffer class.
      \return true  - if buffer stream was successfully set. \n
              false - if buffer stream was not successfully set. \n
  */
  Tbool set(const NUtility::CBuffer& a_crBuffer);
  //! Set another CStreamBuffer class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamBuffer class.
      \return true  - if another buffer stream was successfully set. \n
              false - if another buffer stream was not successfully set. \n
  */
  Tbool set(const CStreamBuffer& a_crInstance);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialization load CStreamBuffer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CStreamBuffer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CStreamBuffer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStreamBuffer class instances.
  /*!
      \param a_rInstance - Reference to another CStreamBuffer class instance.
  */
  void swap(CStreamBuffer& a_rInstance);

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

private:
  Tuint m_Index;                        //!< Current byte buffer stream index.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/CStreamBuffer.inl>
/*==========================================================================*/
//! \example example-stream-CStreamBuffer.cpp
/*--------------------------------------------------------------------------*/
//! \test test-stream-CStreamBuffer.cpp
/*==========================================================================*/
#endif
