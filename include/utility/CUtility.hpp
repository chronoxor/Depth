/*!
 *  \file    CUtility.hpp Utility class contains common functionality for
 *           various programming aims.
 *  \brief   Static class with utility functionality.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class with utility functionality.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   04.01.2006 01:12:24

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
#ifndef __CUTILITY_HPP__
#define __CUTILITY_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/numeric/ARotate.hpp>
#include <Depth/include/common/IStatic.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Static class with utility functionality.
/*!
    Utility class gives lots of common functions for developer. Most  of  this
    utilities replace similar C macros.
*/
class BASE_API CUtility :
  public NDepth::NCommon::IStatic
{
public:
  //! Make 16-bit integer from bytes.
  /*!
      \param a_cByte1 - Byte 1.
      \param a_cByte2 - Byte 2.
      \return 16-bit integer variable.
  */
  static Tuint16 makeInteger(const Tbyte a_cByte1, const Tbyte a_cByte2);
  //! Make 32-bit integer from bytes.
  /*!
      \param a_cByte1 - Byte 1.
      \param a_cByte2 - Byte 2.
      \param a_cByte3 - Byte 3.
      \param a_cByte4 - Byte 4.
      \return 32-bit integer variable.
  */
  static Tuint32 makeInteger(const Tbyte a_cByte1, const Tbyte a_cByte2, const Tbyte a_cByte3, const Tbyte a_cByte4);
  //! Make 64-bit integer from bytes.
  /*!
      \param a_cByte1 - Byte 1.
      \param a_cByte2 - Byte 2.
      \param a_cByte3 - Byte 3.
      \param a_cByte4 - Byte 4.
      \param a_cByte5 - Byte 5.
      \param a_cByte6 - Byte 6.
      \param a_cByte7 - Byte 7.
      \param a_cByte8 - Byte 8.
      \return 64-bit integer variable.
  */
  static Tuint64 makeInteger(const Tbyte a_cByte1, const Tbyte a_cByte2, const Tbyte a_cByte3, const Tbyte a_cByte4, const Tbyte a_cByte5, const Tbyte a_cByte6, const Tbyte a_cByte7, const Tbyte a_cByte8);

  //! Reverse bytes in 16-bit integer value.
  /*!
      \param a_cX - 16-bit integer value.
      \return 16-bit integer value.
  */
  static Tuint16 reverseBytes(const Tuint16 a_cX);
  //! Reverse bytes in 32-bit integer value.
  /*!
      \param a_cX - 32-bit integer value.
      \return 32-bit integer value.
  */
  static Tuint32 reverseBytes(const Tuint32 a_cX);
  //! Reverse bytes in 64-bit integer value.
  /*!
      \param a_cX - 64-bit integer value.
      \return 64-bit integer value.
  */
  static Tuint64 reverseBytes(const Tuint64 a_cX);

  //! Reverse bits in 8-bit integer value.
  /*!
      \param a_cX - 8-bit integer value.
      \return 8-bit integer value.
  */
  static Tuint08 reverseBits(const Tuint08 a_cX);
  //! Reverse bits in 16-bit integer value.
  /*!
      \param a_cX - 16-bit integer value.
      \return 16-bit integer value.
  */
  static Tuint16 reverseBits(const Tuint16 a_cX);
  //! Reverse bits in 32-bit integer value.
  /*!
      \param a_cX - 32-bit integer value.
      \return 32-bit integer value.
  */
  static Tuint32 reverseBits(const Tuint32 a_cX);
  //! Reverse bits in 64-bit integer value.
  /*!
      \param a_cX - 64-bit integer value.
      \return 64-bit integer value.
  */
  static Tuint64 reverseBits(const Tuint64 a_cX);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/CUtility.inl>
/*==========================================================================*/
//! \example example-utility-CUtility.cpp
/*--------------------------------------------------------------------------*/
//! \test test-utility-CUtility.cpp
/*==========================================================================*/
#endif
