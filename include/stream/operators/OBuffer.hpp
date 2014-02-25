/*!
 *  \file    OBuffer.hpp Buffer stream control operator. It is used to
 *           manipulate (read, peek, push, write) with byte, ASCII,
 *           Unicode buffers through stream operators.
 *  \brief   Buffer stream control operator.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Buffer stream control operator.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 00:05:14

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
#ifndef __OBUFFER_HPP__
#define __OBUFFER_HPP__
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
//! Buffer stream control operator.
/*!
    Buffer stream control operator is used to manipulate  (read,  peek,  push,
    write) with byte, ASCII, Unicode buffers through stream operators.
*/
class BASE_API buffer
{
public:
  //! Input/output bytes into/from the given buffer with fixed size.
  /*!
      \param a_pBuffer - Pointer to the buffer.
      \param a_cSize - Size of the buffer (in bytes).
  */
  buffer(Tptr a_pBuffer, const Tuint a_cSize);
  //! Input/output bytes into/from the given buffer with the byte order correction.
  /*!
      \param a_pBuffer - Pointer to the buffer.
      \param a_cSingleSize - Size of the single item (in bytes).
      \param a_cCount - Count of the single items in the buffer.
  */
  buffer(Tptr a_pBuffer, const Tuint a_cSingleSize, const Tuint a_cCount);
  //! Input/output ASCII characters into/from the given buffer with fixed size.
  /*!
      \param a_pBuffer - Pointer to the ASCII characters buffer.
      \param a_cSize - Size of the buffer (in characters).
  */
  buffer(Tsstr a_pBuffer, const Tuint a_cSize);
  //! Input/output Unicode characters into/from the given buffer with fixed size.
  /*!
      \param a_pBuffer - Pointer to the Unicode characters buffer.
      \param a_cSize - Size of the buffer (in characters).
  */
  buffer(Twstr a_pBuffer, const Tuint a_cSize);

  //! Operator: Read buffer stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crBuffer - Constant reference to the buffer stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::readBuffer()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const buffer& a_crBuffer);
  //! Operator: Peek buffer stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crBuffer - Constant reference to the buffer stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::peekBuffer()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const buffer& a_crBuffer);
  //! Operator: Push buffer stream control operator into the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crBuffer - Constant reference to the buffer stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::pushBuffer()
  */
  friend BASE_API IReader& operator < (IReader& a_rReader, const buffer& a_crBuffer);
  //! Operator: Write buffer stream control operator into the given writer.
  /*!
      \param a_rWriter - Reference to the instance of the IWriter interface.
      \param a_crBuffer - Constant reference to the buffer stream control operator.
      \return Reference to the instance of the IWriter interface.
      \see NDepth::NStream::IWriter::writeBuffer()
  */
  friend BASE_API IWriter& operator << (IWriter& a_rWriter, const buffer& a_crBuffer);

private:
  Tuint m_Type;                         //!< Type of the buffer operation.
  Tuint m_SingleSize;                   //!< Size of the single item in the buffer (in bytes).
  Tuint m_Count;                        //!< Count of the single items in the buffer.
  Tptr  m_pBuffer;                      //!< Pointer to the buffer.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/operators/OBuffer.inl>
/*==========================================================================*/
#endif
