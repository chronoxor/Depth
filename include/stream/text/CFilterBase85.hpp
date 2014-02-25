/*!
 *  \file    CFilterBase85.hpp Base85 string filter class converts given ASCII
 *           and Unicode strings into the corresponding hexadecimal
 *           representation.
 *  \brief   Base85 string filter class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base85 string filter class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   16.11.2009 20:42:08

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
#ifndef __CFILTERBASE85_HPP__
#define __CFILTERBASE85_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/pack/IFilterFramePack.hpp>
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
//! Base85 string filter.
/*!
    Base85 string filter class is intended to  convert  on  a  fly  ASCII  and
    Unicode strings to the corresponding Base85 representation.

    Examples:
    01234 -> <~0JP==1]~>
    abcde -> <~@:E_WAH~>
*/
class BASE_API CFilterBase85 :
  public NPack::IFilterFramePack<4>
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CFilterBase85 TDepthCheckType;

  // Check CFilterBase85 class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Create disconnected filter.
  /*!
      \param a_cIsWriteSuffixes - Is write Base85 suffixes into the writer stream (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBase85(const Tbool a_cIsWriteSuffixes = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_cIsWriteSuffixes - Is write Base85 suffixes into the writer stream (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBase85(IReader* a_pReader, const Tbool a_cIsWriteSuffixes = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given writer.
  /*!
      \param a_pWriter - Pointer to the writer interface.
      \param a_cIsWriteSuffixes - Is write Base85 suffixes into the writer stream (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBase85(IWriter* a_pWriter, const Tbool a_cIsWriteSuffixes = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader & writer.
  /*!
      \param a_pReaderWriter - Pointer to the reader & writer interface.
      \param a_cIsWriteSuffixes - Is write Base85 suffixes into the writer stream (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBase85(IReaderWriter* a_pReaderWriter, const Tbool a_cIsWriteSuffixes = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given separate reader and writer.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_pWriter - Pointer to the writer interface.
      \param a_cIsWriteSuffixes - Is write Base85 suffixes into the writer stream (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBase85(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cIsWriteSuffixes = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterBase85 class.
  */
  CFilterBase85(const CFilterBase85& a_crInstance);
  //! Class virtual destructor.
  virtual ~CFilterBase85();

  //! Operator: Assign another CFilterBase85 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterBase85 class.
      \return Reference to the current class instance.
  */
  CFilterBase85& operator = (const CFilterBase85& a_crInstance);

  //! Set another CFilterBase85 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterBase85 class.
      \return true  - if another filter was successfully set. \n
              false - if another filter was not successfully set. \n
  */
  Tbool set(const CFilterBase85& a_crInstance);

  //! Is write Base85 suffixes into the writer stream?
  /*!
      \return true  - if the Base85 suffixes will be written into the writer stream. \n
              false - if the Base85 suffixes will not be written into the writer stream. \n
  */
  Tbool isWriteSuffixes() const;

  //! Serialize CFilterBase85 class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CFilterBase85 class instances.
  /*!
      \param a_rInstance - Reference to another CFilterBase85 class instance.
  */
  void swap(CFilterBase85& a_rInstance);

protected:
  // IFilterFramePack interface overriding methods.
  virtual Tbool onOpenReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);
  virtual Tbool onOpenWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);
  virtual Tbool onPackReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);
  virtual Tbool onPackWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);
  virtual Tbool onCloseReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);
  virtual Tbool onCloseWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);

private:
  Tbool m_IsWriteSuffixes;              //!< Is write Base85 suffixes characters into the writer stream?
  static Tbool m_sIsInitialized;        //!< Is Base85 filter initialized?
  static Tbyte m_sEncodeTable[85];      //!< Encode table of the filter.
  static Tuint32 m_sDecodeTable[256];   //!< Decode table of the filter.

  //! Calculate encode and decode tables.
  static void calculateTables();

  //! Internal Base85 reader handler.
  /*!
      \param a_cReadHeader - If the read header is met, read it.
      \param a_rReader - Reference to the reader.
      \param a_pBuffer - Pointer to the read frame byte buffer.
      \param a_rCurrentSize - Reference to the current size of the buffer (in bytes).
      \param a_cFullSize - Full size of the buffer (in bytes).
      \return true  - if frame packing filter was successfully packed. \n
              false - if frame packing filter was not successfully packed. \n
  */
  static Tbool internalPackReadFrame(const Tbool a_cReadHeader, IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/text/CFilterBase85.inl>
/*==========================================================================*/
//! \example example-stream-CFilterBase85.cpp
/*--------------------------------------------------------------------------*/
//! \test test-stream-CFilterBase85.cpp
/*==========================================================================*/
#endif
