/*!
 *  \file    OFlush.hpp Flush stream control operator. It is used to flush
 *           stream through stream operators.
 *  \brief   Flush stream control operator.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Flush stream control operator.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   02.10.2008 01:39:54

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
#ifndef __OFLUSH_HPP__
#define __OFLUSH_HPP__
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
//! Flush stream control operator.
/*!
    Flush stream control operator is  used  to  flush  stream  through  stream
    operators.
*/
class BASE_API flushStream
{
public:
  //! Operator: Read flush stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crFlush - Constant reference to the flush stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::flush()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const flushStream& a_crFlush);
  //! Operator: Peek flush stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crFlush - Constant reference to the flush stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::flush()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const flushStream& a_crFlush);
  //! Operator: Push flush stream control operator into the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crFlush - Constant reference to the flush stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::flush()
  */
  friend BASE_API IReader& operator < (IReader& a_rReader, const flushStream& a_crFlush);
  //! Operator: Write flush stream control operator into the given writer.
  /*!
      \param a_rWriter - Reference to the instance of the IWriter interface.
      \param a_crFlush - Constant reference to the flush stream control operator.
      \return Reference to the instance of the IWriter interface.
      \see NDepth::NStream::IWriter::flush()
  */
  friend BASE_API IWriter& operator << (IWriter& a_rWriter, const flushStream& a_crFlush);
};
extern BASE_API flushStream flush;      //!< Global instance of the flush stream control operator.
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/operators/OFlush.inl>
/*==========================================================================*/
#endif
