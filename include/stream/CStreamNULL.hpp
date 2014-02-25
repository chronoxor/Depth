/*!
 *  \file    CStreamNULL.hpp NULL stream class gives ability to read zero
 *           buffer of any size and to write buffer to the nowhere.
 *  \brief   NULL stream class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: NULL stream class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   16.08.2008 00:50:42

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
#ifndef __CSTREAMNULL_HPP__
#define __CSTREAMNULL_HPP__
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
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! NULL stream class.
/*!
    NULL  stream  class  provides  input/output  functionality  from/into  the
    nowhere. It works like the /dev/zero Unix file. When the buffer is written
    into the NULL stream it returns count of bytes in buffer. When the  buffer
    is read from the NULL stream it fills the buffer with 0 values.
*/
class BASE_API CStreamNULL :
  public IReaderWriter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CStreamNULL TDepthCheckType;

  // Check CStreamNULL class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::getSystemByteOrder()).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::getSystemLineEnding()).
  */
  CStreamNULL(const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::getSystemByteOrder(), const ELineEnding a_cLineEnding = IStream::getSystemLineEnding());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamNULL class.
  */
  CStreamNULL(const CStreamNULL& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStreamNULL();

  //! Operator: Assign another CStreamNULL class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamNULL class.
      \return Reference to the current class instance.
  */
  CStreamNULL& operator = (const CStreamNULL& a_crInstance);

  //! Set another CStreamNULL class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamNULL class.
      \return true  - if another NULL stream was successfully set. \n
              false - if another NULL stream was not successfully set. \n
  */
  Tbool set(const CStreamNULL& a_crInstance);

  //! Serialize CStreamNULL class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStreamNULL class instances.
  /*!
      \param a_rInstance - Reference to another CStreamNULL class instance.
  */
  void swap(CStreamNULL& a_rInstance);

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
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/CStreamNULL.inl>
/*==========================================================================*/
//! \example example-stream-CStreamNULL.cpp
/*--------------------------------------------------------------------------*/
//! \test test-stream-CStreamNULL.cpp
/*==========================================================================*/
#endif
