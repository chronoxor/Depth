/*!
 *  \file    CStreamStdInput.hpp Standard input stream class gives ability to
 *           read buffer from the 'stdin' system stream.
 *  \brief   Standard input stream class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Standard input stream class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   25.08.2008 21:23:11

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
#ifndef __CSTREAMSTDINPUT_HPP__
#define __CSTREAMSTDINPUT_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/IReader.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Standard input stream class.
/*!
    Standard input stream class provides input functionality from the  'stdin'
    system stream.
*/
class BASE_API CStreamStdInput :
  public IReader
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CStreamStdInput TDepthCheckType;

  // Check CStreamStdInput class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      \param a_cForceOpen - Force open flag (default is false).
      \param a_cTextMode - Text mode flag (default is true).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::getSystemByteOrder()).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::getSystemLineEnding()).
  */
  CStreamStdInput(const Tbool a_cForceOpen = false, const Tbool a_cTextMode = true, const EByteOrder a_cByteOrder = IStream::getSystemByteOrder(), const ELineEnding a_cLineEnding = IStream::getSystemLineEnding());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStdInput class.
  */
  CStreamStdInput(const CStreamStdInput& a_crInstance);
  //! Class virtual destructor.
  virtual ~CStreamStdInput();

  //! Operator: Assign another CStreamStdInput class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStdInput class.
      \return Reference to the current class instance.
  */
  CStreamStdInput& operator = (const CStreamStdInput& a_crInstance);

  //! Set another CStreamStdInput class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CStreamStdInput class.
      \return true  - if another standard input stream was successfully set. \n
              false - if another standard input stream was not successfully set. \n
  */
  Tbool set(const CStreamStdInput& a_crInstance);

  //! Serialize CStreamStdInput class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CStreamStdInput class instances.
  /*!
      \param a_rInstance - Reference to another CStreamStdInput class instance.
  */
  void swap(CStreamStdInput& a_rInstance);

protected:
  // IReader interface overriding methods.
  virtual Tbool onOpen();
  virtual Tuint onReadBinary(Tptr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onReadText(Tsstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onReadText(Twstr a_pBuffer, const Tuint a_cSize);
  virtual Tbool onFlush();
  virtual Tbool onClose();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/CStreamStdInput.inl>
/*==========================================================================*/
//! \example example-stream-CStreamStdInput.cpp
/*==========================================================================*/
#endif
