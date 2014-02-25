/*!
 *  \file    OLineEnd.hpp Line end stream control operator. It is used to
 *           manipulate (read, peek, push, write) with line end characters
 *           through stream operators.
 *  \brief   Line end stream control operator.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Line end stream control operator.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   02.10.2008 20:06:52

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
#ifndef __OLINEEND_HPP__
#define __OLINEEND_HPP__
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
//! Line end stream control operator.
/*!
    Line end stream control operator is used to manipulate (read, peek,  push,
    write) with line end characters through stream operators.
*/
class BASE_API lineEnd
{
public:
  //! //! Default class constructor.
  lineEnd();
  //! //! Initialize with ASCII/Unicode flag.
  /*!
      \param a_cIsASCII - ASCII encoding flag.
  */
  lineEnd(const Tbool a_cIsASCII);

  //! Operator: Get new line end stream control operator with the given encoding.
  /*!
      \return New instance of the line end stream control operator with the given encoding.
  */
  lineEnd operator () () const;
  //! Operator: Get new line end stream control operator with the given encoding.
  /*!
      \param a_cIsASCII - ASCII encoding flag.
      \return New instance of the line end stream control operator with the given encoding.
  */
  lineEnd operator () (const Tbool a_cIsASCII) const;

  //! Operator: Read line end stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crLineEnd - Constant reference to the line end stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::readLineEnd()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const lineEnd& a_crLineEnd);
  //! Operator: Peek line end stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crLineEnd - Constant reference to the line end stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::peekLineEnd()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const lineEnd& a_crLineEnd);
  //! Operator: Push line end stream control operator into the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crLineEnd - Constant reference to the line end stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::pushLineEnd()
  */
  friend BASE_API IReader& operator < (IReader& a_rReader, const lineEnd& a_crLineEnd);
  //! Operator: Write line end stream control operator into the given writer.
  /*!
      \param a_rWriter - Reference to the instance of the IWriter interface.
      \param a_crLineEnd - Constant reference to the line end stream control operator.
      \return Reference to the instance of the IWriter interface.
      \see NDepth::NStream::IWriter::writeLineEnd()
  */
  friend BASE_API IWriter& operator << (IWriter& a_rWriter, const lineEnd& a_crLineEnd);

  Tuint m_IsASCII;                      //!< ASCII encoding flag.
};
extern BASE_API lineEnd ln;             //!< Global instance of the line end stream control operator.
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/operators/OLineEnd.inl>
/*==========================================================================*/
#endif
