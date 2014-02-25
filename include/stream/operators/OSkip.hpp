/*!
 *  \file    OSkip.hpp Skip stream control operators. They are used to skip
 *           bytes, ASCII or Unicode characters during reading or peeking
 *           through stream operators.
 *  \brief   Skip stream control operators.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Skip stream control operators.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 01:25:11

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
#ifndef __OSKIP_HPP__
#define __OSKIP_HPP__
/*==========================================================================*/
#include <Depth/include/stream/IReader.hpp>
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
//! Skip bytes stream control operator.
/*!
    Skip byte stream control operator is used to skip bytes during reading  or
    peeking through stream operators.
*/
class BASE_API skipBytes
{
public:
  //! Input and skip the given count of bytes.
  /*!
      \param a_cSize - Size of bytes buffer to skip (in bytes).
  */
  skipBytes(const Tuint a_cSize);

  //! Operator: Read skip bytes stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crSkipBytes - Constant reference to the skip bytes stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::readBuffer()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const skipBytes& a_crSkipBytes);
  //! Operator: Peek skip bytes stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crSkipBytes - Constant reference to the skip bytes stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::peekBuffer()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const skipBytes& a_crSkipBytes);

private:
  Tuint m_Size;                         //!< Size of bytes buffer to skip (in bytes).
};
/*--------------------------------------------------------------------------*/
//! Skip ASCII characters stream control operator.
/*!
    Skip ASCII characters stream  control  operator  is  used  to  skip  ASCII
    characters during reading or peeking through stream operators.
*/
class BASE_API skipASCII
{
public:
  //! Input and skip the given count of ASCII characters.
  /*!
      \param a_cSize - Size of ASCII characters buffer to skip (in characters).
  */
  skipASCII(const Tuint a_cSize);

  //! Operator: Read skip ASCII characters stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crSkipASCII - Constant reference to the skip ASCII characters stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::readBuffer()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const skipASCII& a_crSkipASCII);
  //! Operator: Peek skip ASCII characters stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crSkipASCII - Constant reference to the skip ASCII characters stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::peekBuffer()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const skipASCII& a_crSkipASCII);

private:
  Tuint m_Size;                         //!< Size of ASCII characters buffer to skip (in characters).
};
/*--------------------------------------------------------------------------*/
//! Skip Unicode characters stream control operator.
/*!
    Skip Unicode characters stream control operator is used  to  skip  Unicode
    characters during reading or peeking through stream operators.
*/
class BASE_API skipUnicode
{
public:
  //! Input and skip the given count of Unicode characters.
  /*!
      \param a_cSize - Size of Unicode characters buffer to skip (in characters).
  */
  skipUnicode(const Tuint a_cSize);

  //! Operator: Read skip Unicode characters stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crSkipUnicode - Constant reference to the skip Unicode characters stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::readBuffer()
  */
  friend BASE_API IReader& operator >> (IReader& a_rReader, const skipUnicode& a_crSkipUnicode);
  //! Operator: Peek skip Unicode characters stream control operator from the given reader.
  /*!
      \param a_rReader - Reference to the instance of the IReader interface.
      \param a_crSkipUnicode - Constant reference to the skip Unicode characters stream control operator.
      \return Reference to the instance of the IReader interface.
      \see NDepth::NStream::IReader::peekBuffer()
  */
  friend BASE_API IReader& operator > (IReader& a_rReader, const skipUnicode& a_crSkipUnicode);

private:
  Tuint m_Size;                         //!< Size of Unicode characters buffer to skip (in characters).
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/operators/OSkip.inl>
/*==========================================================================*/
#endif
