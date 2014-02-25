/*!
 *  \file    CFilterUTF.hpp UTF string filter class converts given ASCII and
 *           Unicode strings into the UTF equivalents.
 *  \brief   UTF string filter class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.10.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: UTF string filter class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   26.10.2009 23:23:33

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
#ifndef __CFILTERUTF_HPP__
#define __CFILTERUTF_HPP__
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
//! UTF string filter.
/*!
    UTF string filter class is intended to convert on a fly ASCII and  Unicode
    strings to their UTF equivalents. Additionally  'Byte  order  flag'  (BOM)
    handling is supported.

    UTF string filter class is initialized with UTF type enumeration.  One  of
    its value is AUTODETECT. It means that filter will use UTF format  of  the
    current system.

    UTF string filter class can also be initialized with BOM store flag, which
    regulates if BOM value shuld be read/written from/into the stream.

    Supported BOM values:
    \li UTF-8 - EF BB BF
    \li UTF-16 (BE) - FE FF
    \li UTF-16 (LE) - FF FE
    \li UTF-32 (BE) - 00 00 FE FF
    \li UTF-32 (LE) - FF FE 00 00
*/
class BASE_API CFilterUTF :
  public IFilter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CFilterUTF TDepthCheckType;

  // Check CFilterUTF class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  enum EUTFType                         //! Supported UTF types.
  {
    e_AUTODETECT,                       //!< Autodetect of the UTF type.
    e_UTF8,                             //!< UTF-8.
    e_UTF16BE,                          //!< UTF-16 (Big-Endian).
    e_UTF16LE,                          //!< UTF-16 (Little-Endian).
    e_UTF32BE,                          //!< UTF-32 (Big-Endian).
    e_UTF32LE                           //!< UTF-32 (Little-Endian).
  };

  //! Default class constructor. Create disconnected filter.
  /*!
      \param a_cUTFType - UTF type (default is e_AUTODETECT).
      \param a_cIsBOMUsed - Is BOM flag is used in the filter (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterUTF(const EUTFType a_cUTFType = e_AUTODETECT, const Tbool a_cIsBOMUsed = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_cUTFType - UTF type (default is e_AUTODETECT).
      \param a_cIsBOMUsed - Is BOM flag is used in the filter (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterUTF(IReader* a_pReader, const EUTFType a_cUTFType = e_AUTODETECT, const Tbool a_cIsBOMUsed = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given writer.
  /*!
      \param a_pWriter - Pointer to the writer interface.
      \param a_cUTFType - UTF type (default is e_AUTODETECT).
      \param a_cIsBOMUsed - Is BOM flag is used in the filter (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterUTF(IWriter* a_pWriter, const EUTFType a_cUTFType = e_AUTODETECT, const Tbool a_cIsBOMUsed = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader & writer.
  /*!
      \param a_pReaderWriter - Pointer to the reader & writer interface.
      \param a_cUTFType - UTF type (default is e_AUTODETECT).
      \param a_cIsBOMUsed - Is BOM flag is used in the filter (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterUTF(IReaderWriter* a_pReaderWriter, const EUTFType a_cUTFType = e_AUTODETECT, const Tbool a_cIsBOMUsed = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given separate reader and writer.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_pWriter - Pointer to the writer interface.
      \param a_cUTFType - UTF type (default is e_AUTODETECT).
      \param a_cIsBOMUsed - Is BOM flag is used in the filter (default is true)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterUTF(IReader* a_pReader, IWriter* a_pWriter, const EUTFType a_cUTFType = e_AUTODETECT, const Tbool a_cIsBOMUsed = true, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterUTF class.
  */
  CFilterUTF(const CFilterUTF& a_crInstance);
  //! Class virtual destructor.
  virtual ~CFilterUTF();

  //! Operator: Assign another CFilterUTF class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterUTF class.
      \return Reference to the current class instance.
  */
  CFilterUTF& operator = (const CFilterUTF& a_crInstance);

  //! Set another CFilterUTF class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterUTF class.
      \return true  - if another filter was successfully set. \n
              false - if another filter was not successfully set. \n
  */
  Tbool set(const CFilterUTF& a_crInstance);

  //! Get the current UTF type.
  /*!
      \return Current UTF type.
  */
  EUTFType getUTFType() const;

  //! Is the BOM flag is used by the filter?
  /*!
      \return true  - if the BOM flag is used by the filter. \n
              false - if the BOM flag is not used by the filter. \n
  */
  Tbool isBOMUsed() const;

  //! Serialize CFilterUTF class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CFilterUTF class instances.
  /*!
      \param a_rInstance - Reference to another CFilterUTF class instance.
  */
  void swap(CFilterUTF& a_rInstance);

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
  Tschar   m_Cache[4];                  //!< Cache of read bytes.
  Tuint    m_CacheSize;                 //!< Cache size of read bytes.
  Tbool    m_IsBOMUsed;                 //!< Is the BOM flag is used by the filter?
  EUTFType m_UTFType;                   //!< UTF type of the filter.

  //! Read single UTF-8 character.
  /*!
      \param a_rReader - Reference to the reader.
      \param a_rResult - Result character in general form.
      \return true  - if character in general form has been successfully read. \n
              false - if character in general form has not been successfully read. \n
  */
  Tbool readUTF8(IReader& a_rReader, Tuint& a_rResult);
  //! Read single UTF-16 (Big-Endian/Little-Endian) character.
  /*!
      \param a_rReader - Reference to the reader.
      \param a_rResult - Result character in general form.
      \param a_cBigEndian - Big-Endian flag.
      \return true  - if character in general form has been successfully read. \n
              false - if character in general form has not been successfully read. \n
  */
  Tbool readUTF16(IReader& a_rReader, Tuint& a_rResult, const Tbool a_cBigEndian);
  //! Read single UTF-32 (Big-Endian/Little-Endian) character.
  /*!
      \param a_rReader - Reference to the reader.
      \param a_rResult - Result character in general form.
      \param a_cBigEndian - Big-Endian flag.
      \return true  - if character in general form has been successfully read. \n
              false - if character in general form has not been successfully read. \n
  */
  Tbool readUTF32(IReader& a_rReader, Tuint& a_rResult, const Tbool a_cBigEndian);

  //! Write single UTF-8 character.
  /*!
      \param a_rWriter - Reference to the writer.
      \param a_cCharacter - Character in general form.
      \return true  - if character in general form has been successfully written. \n
              false - if character in general form has not been successfully written. \n
  */
  Tbool writeUTF8(IWriter& a_rWriter, const Tuint a_cCharacter);
  //! Write single UTF-16 (Big-Endian/Little-Endian) character.
  /*!
      \param a_rWriter - Reference to the writer.
      \param a_cCharacter - Character in general form.
      \param a_cBigEndian - Big-Endian flag.
      \return true  - if character in general form has been successfully written. \n
              false - if character in general form has not been successfully written. \n
  */
  Tbool writeUTF16(IWriter& a_rWriter, const Tuint a_cCharacter, const Tbool a_cBigEndian);
  //! Write single UTF-32 (Big-Endian/Little-Endian) character.
  /*!
      \param a_rWriter - Reference to the writer.
      \param a_cCharacter - Character in general form.
      \param a_cBigEndian - Big-Endian flag.
      \return true  - if character in general form has been successfully written. \n
              false - if character in general form has not been successfully written. \n
  */
  Tbool writeUTF32(IWriter& a_rWriter, const Tuint a_cCharacter, const Tbool a_cBigEndian);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/text/CFilterUTF.inl>
/*==========================================================================*/
//! \example example-stream-CFilterUTF.cpp
/*--------------------------------------------------------------------------*/
//! \test test-stream-CFilterUTF.cpp
/*==========================================================================*/
#endif
