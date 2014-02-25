/*!
 *  \file    CStreamStdError.hpp Standard error stream class gives ability to
 *           write buffer into the 'stderr' system stream.
 *  \brief   Standard error stream class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Standard error stream class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   25.08.2008 21:08:00

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
#ifndef __CSTREAMSTDERROR_HPP__
#define __CSTREAMSTDERROR_HPP__
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
//! Standard error stream class.
/*!
    Standard  error  stream  class  provides  output  functionality  into  the
    'stderr' system stream.
*/
class BASE_API CStreamStdError :
  public IWriter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CStreamStdError TDepthCheckType;

  // Check CStreamStdError class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cForceOpen - Force open flag (default is false).
      \param a_cTextMode - Text mode flag (default is true).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::getSystemByteOrder()).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::getSystemLineEnding()).
  */
  CStreamStdError(const Tbool a_cForceOpen = false, const Tbool a_cTextMode = true, const EByteOrder a_cByteOrder = IStream::getSystemByteOrder(), const ELineEnding a_cLineEnding = IStream::getSystemLineEnding());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStdError class.
  */
  CStreamStdError(const CStreamStdError& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStreamStdError();

  //! Operator: Assign another CStreamStdError class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStdError class.
      \return Reference to the current class instance.
  */
  CStreamStdError& operator = (const CStreamStdError& a_crInstance);

  //! Set another CStreamStdError class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStdError class.
      \return true  - if another standard error stream was successfully set. \n
              false - if another standard error stream was not successfully set. \n
  */
  Tbool set(const CStreamStdError& a_crInstance);

  //! Serialize CStreamStdError class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStreamStdError class instances.
  /*!
      \param a_rInstance - Reference to another CStreamStdError class instance.
  */
  void swap(CStreamStdError& a_rInstance);

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
#include <Depth/include/stream/CStreamStdError.inl>
/*==========================================================================*/
//! \example example-stream-CStreamStdError.cpp
/*==========================================================================*/
#endif
