/*!
 *  \file    CStreamStringBufferUnicode.hpp Unicode string buffer stream class
 *           gives ability to read/write byte sequences from/into the fixed
 *           Unicode string buffer.
 *  \brief   Unicode string buffer stream class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode string buffer stream class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   26.09.2008 23:29:59

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
#ifndef __CSTREAMSTRINGBUFFERUNICODE_HPP__
#define __CSTREAMSTRINGBUFFERUNICODE_HPP__
/*==========================================================================*/
#include <Depth/include/common/ISeekable.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/IReaderWriter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NText {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Unicode string buffer stream class.
/*!
    Unicode string buffer stream class gives ability to  perform  input/output
    operations directly into/from the fixed Unicode string buffer.
*/
class BASE_API CStreamStringBufferUnicode :
  public IReaderWriter,
  public NCommon::ISeekable
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CStreamStringBufferUnicode TDepthCheckType;

  // Check CStreamStringBufferUnicode class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cTextMode - Text mode flag (default is true).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::getSystemByteOrder()).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::getSystemLineEnding()).
  */
  CStreamStringBufferUnicode(const Tbool a_cTextMode = true, const EByteOrder a_cByteOrder = IStream::getSystemByteOrder(), const ELineEnding a_cLineEnding = IStream::getSystemLineEnding());
  //! Initialize Unicode string stream from the given Unicode 'C' string.
  /*!
      \param a_pUnicodeString - Unicode 'C' string.
      \param a_cTextMode - Text mode flag (default is true).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::getSystemByteOrder()).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::getSystemLineEnding()).
  */
  CStreamStringBufferUnicode(Twstr a_pUnicodeString, const Tbool a_cTextMode = true, const EByteOrder a_cByteOrder = IStream::getSystemByteOrder(), const ELineEnding a_cLineEnding = IStream::getSystemLineEnding());
  //! Initialize Unicode string stream from the given buffer of fixed size in Unicode encoding.
  /*!
      \param a_pBuffer - Buffer of fixed size in Unicode encoding.
      \param a_cSize - Size of the buffer.
      \param a_cTextMode - Text mode flag (default is true).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::getSystemByteOrder()).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::getSystemLineEnding()).
  */
  CStreamStringBufferUnicode(Twstr a_pBuffer, const Tuint a_cSize, const Tbool a_cTextMode = true, const EByteOrder a_cByteOrder = IStream::getSystemByteOrder(), const ELineEnding a_cLineEnding = IStream::getSystemLineEnding());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStringBufferUnicode class.
  */
  CStreamStringBufferUnicode(const CStreamStringBufferUnicode& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStreamStringBufferUnicode();

  //! Operator: Assign Unicode 'C' string.
  /*!
      \param a_pUnicodeString - Unicode 'C' string.
      \return Reference to the current class instance.
  */
  CStreamStringBufferUnicode& operator = (Twstr a_pUnicodeString);
  //! Operator: Assign another CStreamStringBufferUnicode class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStringBufferUnicode class.
      \return Reference to the current class instance.
  */
  CStreamStringBufferUnicode& operator = (const CStreamStringBufferUnicode& a_crInstance);

  //! Set Unicode 'C' string.
  /*!
      \param a_pUnicodeString - Unicode 'C' string.
      \return true  - if Unicode 'C' string was successfully set. \n
              false - if Unicode 'C' string was not successfully set. \n
  */
  Tbool set(Twstr a_pUnicodeString);
  //! Set buffer of fixed size in Unicode encoding.
  /*!
      \param a_pBuffer - Buffer of fixed size in Unicode encoding.
      \param a_cSize - Size of the buffer.
      \return true  - if Unicode buffer of fixed size was successfully set. \n
              false - if Unicode buffer of fixed size was not successfully set. \n
  */
  Tbool set(Twstr a_pBuffer, const Tuint a_cSize);
  //! Set another CStreamStringBufferUnicode class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStringBufferUnicode class.
      \return true  - if another Unicode string stream was successfully set. \n
              false - if another Unicode string stream was not successfully set. \n
  */
  Tbool set(const CStreamStringBufferUnicode& a_crInstance);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialization load CStreamStringBufferUnicode class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CStreamStringBufferUnicode class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CStreamStringBufferUnicode class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStreamStringBufferUnicode class instances.
  /*!
      \param a_rInstance - Reference to another CStreamStringBufferUnicode class instance.
  */
  void swap(CStreamStringBufferUnicode& a_rInstance);

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
  Twstr m_pBuffer;                      //!< Unicode string buffer.
  Tuint m_Size;                         //!< Size of Unicode string buffer.
  Tuint m_Index;                        //!< Current Unicode string stream index.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/text/CStreamStringBufferUnicode.inl>
/*==========================================================================*/
#endif
