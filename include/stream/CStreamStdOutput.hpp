/*!
 *  \file    CStreamStdOutput.hpp Standard output stream class gives ability
 *           to write buffer into the 'stdout' system stream.
 *  \brief   Standard output stream class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Standard output stream class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   25.08.2008 21:27:26

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
#ifndef __CSTREAMSTDOUTPUT_HPP__
#define __CSTREAMSTDOUTPUT_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/IWriter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Standard output stream class.
/*!
    Standard output  stream  class  provides  output  functionality  into  the
    'stdout' system stream.
*/
class BASE_API CStreamStdOutput :
  public IWriter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CStreamStdOutput TDepthCheckType;

  // Check CStreamStdOutput class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cForceOpen - Force open flag (default is false).
      \param a_cTextMode - Text mode flag (default is true).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::getSystemByteOrder()).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::getSystemLineEnding()).
  */
  CStreamStdOutput(const Tbool a_cForceOpen = false, const Tbool a_cTextMode = true, const EByteOrder a_cByteOrder = IStream::getSystemByteOrder(), const ELineEnding a_cLineEnding = IStream::getSystemLineEnding());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStdOutput class.
  */
  CStreamStdOutput(const CStreamStdOutput& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStreamStdOutput();

  //! Operator: Assign another CStreamStdOutput class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStdOutput class.
      \return Reference to the current class instance.
  */
  CStreamStdOutput& operator = (const CStreamStdOutput& a_crInstance);

  //! Set another CStreamStdOutput class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStdOutput class.
      \return true  - if another standard output stream was successfully set. \n
              false - if another standard output stream was not successfully set. \n
  */
  Tbool set(const CStreamStdOutput& a_crInstance);

  //! Serialize CStreamStdOutput class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStreamStdOutput class instances.
  /*!
      \param a_rInstance - Reference to another CStreamStdOutput class instance.
  */
  void swap(CStreamStdOutput& a_rInstance);

protected:
  // IWriter interface overriding methods.
  virtual Tbool onOpen();
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
#include <Depth/include/stream/CStreamStdOutput.inl>
/*==========================================================================*/
//! \example example-stream-CStreamStdOutput.cpp
/*==========================================================================*/
#endif
