/*!
 *  \file    CFilterLineEnd.hpp Line end filter class helps to handle line end
 *           characters in the stream.
 *  \brief   Line end filter class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Line end filter class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   17.11.2009 02:04:19

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
#ifndef __CFILTERLINEEND_HPP__
#define __CFILTERLINEEND_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/IFilter.hpp>
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
//! Line end filter.
/*!
    Line end filter class  is  intended  to  write  /  read  a  fly  line  end
    characters into / from the given stream. This may be  helpful  to  perform
    new formatting for different text-to-binary encodings (e.g. Base64).

    Line end filter can be initialized to write line end characters  into  the
    stream by the given intervals (0 means not to write line end at all).

    Line end filter can be initialized to read and check line  end  characters
    from the stream by the  given  intervals  (0  means  read  but  not  check
    intervals).
*/
class BASE_API CFilterLineEnd :
  public IFilter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CFilterLineEnd TDepthCheckType;

  // Check CFilterLineEnd class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Create disconnected filter.
  /*!
      \param a_cReadInterval - Line end read interval (default is 0).
      \param a_cWriteInterval - Line end write interval (default is 76).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterLineEnd(const Tuint a_cReadInterval = 0, const Tuint a_cWriteInterval = 76, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_cReadInterval - Line end read interval (default is 0).
      \param a_cWriteInterval - Line end write interval (default is 76).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterLineEnd(IReader* a_pReader, const Tuint a_cReadInterval = 0, const Tuint a_cWriteInterval = 76, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given writer.
  /*!
      \param a_pWriter - Pointer to the writer interface.
      \param a_cReadInterval - Line end read interval (default is 0).
      \param a_cWriteInterval - Line end write interval (default is 76).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterLineEnd(IWriter* a_pWriter, const Tuint a_cReadInterval = 0, const Tuint a_cWriteInterval = 76, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader & writer.
  /*!
      \param a_pReaderWriter - Pointer to the reader & writer interface.
      \param a_cReadInterval - Line end read interval (default is 0).
      \param a_cWriteInterval - Line end write interval (default is 76).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterLineEnd(IReaderWriter* a_pReaderWriter, const Tuint a_cReadInterval = 0, const Tuint a_cWriteInterval = 76, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given separate reader and writer.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_pWriter - Pointer to the writer interface.
      \param a_cReadInterval - Line end read interval (default is 0).
      \param a_cWriteInterval - Line end write interval (default is 76).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterLineEnd(IReader* a_pReader, IWriter* a_pWriter, const Tuint a_cReadInterval = 0, const Tuint a_cWriteInterval = 76, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterLineEnd class.
  */
  CFilterLineEnd(const CFilterLineEnd& a_crInstance);
  //! Class virtual destructor.
  virtual ~CFilterLineEnd();

  //! Operator: Assign another CFilterLineEnd class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterLineEnd class.
      \return Reference to the current class instance.
  */
  CFilterLineEnd& operator = (const CFilterLineEnd& a_crInstance);

  //! Set another CFilterLineEnd class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterLineEnd class.
      \return true  - if another filter was successfully set. \n
              false - if another filter was not successfully set. \n
  */
  Tbool set(const CFilterLineEnd& a_crInstance);

  //! Get line end read interval.
  /*!
      \return Line end read interval.
  */
  Tuint getReadInterval() const;
  //! Get line end write interval.
  /*!
      \return Line end write interval.
  */
  Tuint getWriteInterval() const;

  //! Serialize CFilterLineEnd class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CFilterLineEnd class instances.
  /*!
      \param a_rInstance - Reference to another CFilterLineEnd class instance.
  */
  void swap(CFilterLineEnd& a_rInstance);

protected:
  // IReaderWriter interface overriding methods.
  virtual Tbool onOpen(const EOpenType a_cOpenType);

  // IFilter interface overriding methods.
  virtual Tuint onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize);

private:
  Tuint m_ReadInterval;                 //!< Line end read interval.
  Tuint m_WriteInterval;                //!< Line end write interval.
  Tuint m_CacheReadInterval;            //!< Cache line end read interval.
  Tuint m_CacheWriteInterval;           //!< Cache line end write interval.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/text/CFilterLineEnd.inl>
/*==========================================================================*/
//! \example example-stream-CFilterLineEnd.cpp
/*--------------------------------------------------------------------------*/
//! \test test-stream-CFilterLineEnd.cpp
/*==========================================================================*/
#endif
