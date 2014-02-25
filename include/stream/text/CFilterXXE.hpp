/*!
 *  \file    CFilterXXE.hpp XXE string filter class converts given ASCII
 *           and Unicode strings into the corresponding XXE-encoded
 *           representation.
 *  \brief   XXE string filter class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: XXE string filter class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   11.11.2009 21:42:45

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
#ifndef __CFILTERXXE_HPP__
#define __CFILTERXXE_HPP__
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
//! XXE string filter.
/*!
    XXE string filter class is intended to convert on a fly ASCII and  Unicode
    strings to the corresponding XXE-encoded representation.

    Examples:
    12345 -> 3AH6nB1I+
    abcde -> 3MK7XN4I+
*/
class BASE_API CFilterXXE :
  public NPack::IFilterFramePack<45>
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CFilterXXE TDepthCheckType;

  // Check CFilterXXE class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Create disconnected filter.
  /*!
      \param a_cIsWriteLineEnding - Is write line ending characters into the writer stream (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterXXE(const Tbool a_cIsWriteLineEnding = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_cIsWriteLineEnding - Is write line ending characters into the writer stream (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterXXE(IReader* a_pReader, const Tbool a_cIsWriteLineEnding = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given writer.
  /*!
      \param a_pWriter - Pointer to the writer interface.
      \param a_cIsWriteLineEnding - Is write line ending characters into the writer stream (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterXXE(IWriter* a_pWriter, const Tbool a_cIsWriteLineEnding = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader & writer.
  /*!
      \param a_pReaderWriter - Pointer to the reader & writer interface.
      \param a_cIsWriteLineEnding - Is write line ending characters into the writer stream (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterXXE(IReaderWriter* a_pReaderWriter, const Tbool a_cIsWriteLineEnding = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given separate reader and writer.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_pWriter - Pointer to the writer interface.
      \param a_cIsWriteLineEnding - Is write line ending characters into the writer stream (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterXXE(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cIsWriteLineEnding = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterXXE class.
  */
  CFilterXXE(const CFilterXXE& a_crInstance);
  //! Class virtual destructor.
  virtual ~CFilterXXE();

  //! Operator: Assign another CFilterXXE class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterXXE class.
      \return Reference to the current class instance.
  */
  CFilterXXE& operator = (const CFilterXXE& a_crInstance);

  //! Set another CFilterXXE class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterXXE class.
      \return true  - if another filter was successfully set. \n
              false - if another filter was not successfully set. \n
  */
  Tbool set(const CFilterXXE& a_crInstance);

  //! Is write line ending characters into the writer stream?
  /*!
      \return true  - if the line ending characters will be written into the writer stream. \n
              false - if the line ending characters will not be written into the writer stream. \n
  */
  Tbool isWriteLineEnding() const;

  //! Serialize CFilterXXE class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CFilterXXE class instances.
  /*!
      \param a_rInstance - Reference to another CFilterXXE class instance.
  */
  void swap(CFilterXXE& a_rInstance);

protected:
  // IFilterFramePack interface overriding methods.
  virtual Tbool onOpenReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);
  virtual Tbool onOpenWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);
  virtual Tbool onPackReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);
  virtual Tbool onPackWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);
  virtual Tbool onCloseReadFrame(IReader& a_rReader, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);
  virtual Tbool onCloseWriteFrame(IWriter& a_rWriter, Tbuffer a_pBuffer, Tuint& a_rCurrentSize, const Tuint a_cFullSize);

private:
  Tbool m_IsWriteLineEnding;            //!< Is write line ending characters into the writer stream?
  static Tbool m_sIsInitialized;        //!< Is XXE filter initialized?
  static Tbyte m_sEncodeTable[64];      //!< Encode table of the filter.
  static Tbyte m_sDecodeTable[256];     //!< Decode table of the filter.

  //! Calculate encode and decode tables.
  static void calculateTables();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/text/CFilterXXE.inl>
/*==========================================================================*/
//! \example example-stream-CFilterXXE.cpp
/*--------------------------------------------------------------------------*/
//! \test test-stream-CFilterXXE.cpp
/*==========================================================================*/
#endif
