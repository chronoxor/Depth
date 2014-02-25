/*!
 *  \file    CFilterBinaryText.hpp Binary/Text filter class converts ASCII
 *           and Unicode strings into binary byte stream and vice-versa.
 *  \brief   Binary/Text converter filter class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Binary/Text converter filter class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   03.11.2009 21:16:04

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
#ifndef __CFILTERBINARYTEXT_HPP__
#define __CFILTERBINARYTEXT_HPP__
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
//! Binary/Text converter filter.
/*!
    Binary/Text filter class is intended to convert on a fly ASCII and Unicode
    strings into binary byte stream and vice-versa.
*/
class BASE_API CFilterBinaryText :
  public IFilter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CFilterBinaryText TDepthCheckType;

  // Check CFilterBinaryText class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Create disconnected filter.
  /*!
      \param a_cIsReadASCII - Is text read stream is ASCII (default is NDepth::NConstants::CConstants::isASCII)?
      \param a_cIsWriteASCII - Is text write stream is ASCII (default is NDepth::NConstants::CConstants::isASCII)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBinaryText(const Tbool a_cIsReadASCII = NConstants::CConstants::isASCII, const Tbool a_cIsWriteASCII = NConstants::CConstants::isASCII, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_cIsReadASCII - Is text read stream is ASCII (default is NDepth::NConstants::CConstants::isASCII)?
      \param a_cIsWriteASCII - Is text write stream is ASCII (default is NDepth::NConstants::CConstants::isASCII)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBinaryText(IReader* a_pReader, const Tbool a_cIsReadASCII = NConstants::CConstants::isASCII, const Tbool a_cIsWriteASCII = NConstants::CConstants::isASCII, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given writer.
  /*!
      \param a_pWriter - Pointer to the writer interface.
      \param a_cIsReadASCII - Is text read stream is ASCII (default is NDepth::NConstants::CConstants::isASCII)?
      \param a_cIsWriteASCII - Is text write stream is ASCII (default is NDepth::NConstants::CConstants::isASCII)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBinaryText(IWriter* a_pWriter, const Tbool a_cIsReadASCII = NConstants::CConstants::isASCII, const Tbool a_cIsWriteASCII = NConstants::CConstants::isASCII, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader & writer.
  /*!
      \param a_pReaderWriter - Pointer to the reader & writer interface.
      \param a_cIsReadASCII - Is text read stream is ASCII (default is NDepth::NConstants::CConstants::isASCII)?
      \param a_cIsWriteASCII - Is text write stream is ASCII (default is NDepth::NConstants::CConstants::isASCII)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBinaryText(IReaderWriter* a_pReaderWriter, const Tbool a_cIsReadASCII = NConstants::CConstants::isASCII, const Tbool a_cIsWriteASCII = NConstants::CConstants::isASCII, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given separate reader and writer.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_pWriter - Pointer to the writer interface.
      \param a_cIsReadASCII - Is text read stream is ASCII (default is NDepth::NConstants::CConstants::isASCII)?
      \param a_cIsWriteASCII - Is text write stream is ASCII (default is NDepth::NConstants::CConstants::isASCII)?
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBinaryText(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cIsReadASCII = NConstants::CConstants::isASCII, const Tbool a_cIsWriteASCII = NConstants::CConstants::isASCII, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterBinaryText class.
  */
  CFilterBinaryText(const CFilterBinaryText& a_crInstance);
  //! Class virtual destructor.
  virtual ~CFilterBinaryText();

  //! Operator: Assign another CFilterBinaryText class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterBinaryText class.
      \return Reference to the current class instance.
  */
  CFilterBinaryText& operator = (const CFilterBinaryText& a_crInstance);

  //! Set another CFilterBinaryText class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterBinaryText class.
      \return true  - if another filter was successfully set. \n
              false - if another filter was not successfully set. \n
  */
  Tbool set(const CFilterBinaryText& a_crInstance);

  //! Is text read stream is ASCII?
  /*!
      \return true  - if the text read stream is ASCII. \n
              false - if the text read stream is Unicode. \n
  */
  Tbool isReadASCII() const;
  //! Is text read stream is Unicode?
  /*!
      \return true  - if the text read stream is Unicode. \n
              false - if the text read stream is ASCII. \n
  */
  Tbool isReadUnicode() const;

  //! Is text write stream is ASCII?
  /*!
      \return true  - if the text write stream is ASCII. \n
              false - if the text write stream is Unicode. \n
  */
  Tbool isWriteASCII() const;
  //! Is text write stream is Unicode?
  /*!
      \return true  - if the text write stream is Unicode. \n
              false - if the text write stream is ASCII. \n
  */
  Tbool isWriteUnicode() const;

  //! Serialize CFilterBinaryText class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CFilterBinaryText class instances.
  /*!
      \param a_rInstance - Reference to another CFilterBinaryText class instance.
  */
  void swap(CFilterBinaryText& a_rInstance);

protected:
  // IFilter interface overriding methods.
  virtual Tuint onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize);

private:
  Tbool m_IsReadASCII;                  //!< Is text read stream is ASCII?
  Tbool m_IsWriteASCII;                 //!< Is text write stream is ASCII?
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/text/CFilterBinaryText.inl>
/*==========================================================================*/
#endif
