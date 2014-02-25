/*!
 *  \file    OBufferConst.hpp Constant buffer stream control operator. It
 *           is used to manipulate (push, write) with byte, ASCII, Unicode
 *           constant buffers through stream operators.
 *  \brief   Constant buffer stream control operator.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant buffer stream control operator.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 00:56:20

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
#ifndef __OBUFFERCONST_HPP__
#define __OBUFFERCONST_HPP__
/*==========================================================================*/
#include <Depth/include/stream/IReader.hpp>
#include <Depth/include/stream/IWriter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* OPERATOR DECLARATIONS                                                    */
/*==========================================================================*/
//! Constant buffer stream control operator.
/*!
    Constant buffer stream control  operator  is  used  to  manipulate  (push,
    write)  with  byte,  ASCII,  Unicode  constant  buffers   through   stream
    operators.
*/
class BASE_API cbuffer
{
public:
  //! Output bytes from the given buffer with fixed size.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSize - Size of the buffer (in bytes).
  */
  cbuffer(Tcptr a_cpBuffer, const Tuint a_cSize);
  //! Output bytes from the given buffer with the byte order correction.
  /*!
      \param a_cpBuffer - Constant pointer to the buffer.
      \param a_cSingleSize - Size of the single item (in bytes).
      \param a_cCount - Count of the single items in the buffer.
  */
  cbuffer(Tcptr a_cpBuffer, const Tuint a_cSingleSize, const Tuint a_cCount);
  //! Output ASCII characters from the given buffer with fixed size.
  /*!
      \param a_cpBuffer - Constant pointer to the ASCII characters buffer.
      \param a_cSize - Size of the buffer (in characters).
  */
  cbuffer(Tcsstr a_cpBuffer, const Tuint a_cSize);
  //! Output Unicode characters from the given buffer with fixed size.
  /*!
      \param a_cpBuffer - Constant pointer to the Unicode characters buffer.
      \param a_cSize - Size of the buffer (in characters).
  */
  cbuffer(Tcwstr a_cpBuffer, const Tuint a_cSize);

  //! Operator: Push buffer constant stream control operator into the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crBufferConst - Constant reference to the constant buffer stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::pushBuffer()
  */
  friend BASE_API IReader& operator < (IReader& a_rReader, const cbuffer& a_crBufferConst);
  //! Operator: Write constant buffer stream control operator into the given writer.
  /*!
      \param a_rWriter - Reference to the instance of the IWriter interface.
      \param a_crBufferConst - Constant reference to the constant buffer stream control operator.
      \return Reference to the instance of the IWriter interface.
      \see NDepth::NStream::IWriter::writeBuffer()
  */
  friend BASE_API IWriter& operator << (IWriter& a_rWriter, const cbuffer& a_crBufferConst);

private:
  Tuint m_Type;                         //!< Type of the buffer operation.
  Tuint m_SingleSize;                   //!< Size of the single item in the buffer (in bytes).
  Tuint m_Count;                        //!< Count of the single items in the buffer.
  Tcptr m_cpBuffer;                     //!< Constant pointer to the buffer.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/operators/OBufferConst.inl>
/*==========================================================================*/
#endif
