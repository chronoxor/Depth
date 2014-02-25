/*!
 *  \file    CFilterFork.hpp Fork duplicate filter class simple duplicate
 *           data from another stream/filter and write it into the given
 *           stream.
 *  \brief   Fork duplicate filter class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    19.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Fork duplicate filter class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   19.03.2009 21:19:17

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
#ifndef __CFILTERFORK_HPP__
#define __CFILTERFORK_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/IFilter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Fork duplicate filter.
/*!
    Fork  duplicate  filter  class  simple   duplicate   data   from   another
    stream/filter and write it into the given stream.
*/
class BASE_API CFilterFork :
  public IFilter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CFilterFork TDepthCheckType;

  // Check CFilterFork class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Create disconnected filter.
  /*!
      \param a_pFork - Pointer to the fork writer interface (default is NULL).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterFork(IWriter* a_pFork = NULL, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_pFork - Pointer to the fork writer interface (default is NULL).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterFork(IReader* a_pReader, IWriter* a_pFork = NULL, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given writer.
  /*!
      \param a_pWriter - Pointer to the writer interface.
      \param a_pFork - Pointer to the fork writer interface (default is NULL).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterFork(IWriter* a_pWriter, IWriter* a_pFork = NULL, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader & writer.
  /*!
      \param a_pReaderWriter - Pointer to the reader & writer interface.
      \param a_pFork - Pointer to the fork writer interface (default is NULL).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterFork(IReaderWriter* a_pReaderWriter, IWriter* a_pFork = NULL, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given separate reader and writer.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_pWriter - Pointer to the writer interface.
      \param a_pFork - Pointer to the fork writer interface (default is NULL).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterFork(IReader* a_pReader, IWriter* a_pWriter, IWriter* a_pFork = NULL, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterFork class.
  */
  CFilterFork(const CFilterFork& a_crInstance);
  //! Class virtual destructor.
  virtual ~CFilterFork();

  //! Operator: Assign another CFilterFork class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterFork class.
      \return Reference to the current class instance.
  */
  CFilterFork& operator = (const CFilterFork& a_crInstance);

  //! Set another CFilterFork class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterFork class.
      \return true  - if another filter was successfully set. \n
              false - if another filter was not successfully set. \n
  */
  Tbool set(const CFilterFork& a_crInstance);

  //! Is filter forkable?
  /*!
      \return true  - if filter is forkable. \n
              false - if filter is not forkable. \n
  */
  virtual Tbool isForkable() const;

  //! Connect/disconnect fork writer with/form the current filter.
  /*!
      \param a_pFork - Pointer to the fork writer interface or NULL for disconnection.
      \return true  - if fork writer was successfully connected/disconnected. \n
              false - if fork writer was not successfully connected/disconnected. \n
  */
  Tbool setFork(IWriter* a_pFork);

  //! Get pointer to the current connected fork writer.
  /*!
      \return Pointer to the current connected fork writer interface.
  */
  IWriter* getFork();
  //! Get constant pointer to the current connected fork writer.
  /*!
      \return Constant pointer to the current connected fork writer interface.
  */
  const IWriter* getFork() const;

  //! Serialize CFilterFork class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CFilterFork class instances.
  /*!
      \param a_rInstance - Reference to another CFilterFork class instance.
  */
  void swap(CFilterFork& a_rInstance);

protected:
  IWriter* m_pFork;                     //!< Pointer to the current connected fork stream.

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

  // IFilter interface overriding methods.
  virtual Tuint onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/CFilterFork.inl>
/*==========================================================================*/
//! \example example-stream-CFilterFork.cpp
/*--------------------------------------------------------------------------*/
//! \test test-stream-CFilterFork.cpp
/*==========================================================================*/
#endif
