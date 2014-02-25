/*!
 *  \file    CEndians.hpp System byte order utilities definition.
 *  \brief   Static class with system byte order utility methods.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class with system byte order utility methods.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   26.01.2006 02:44:14

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
#ifndef __CENDIANS_HPP__
#define __CENDIANS_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/numeric/ASwapInt.hpp>
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
//! Static class with system byte order utility methods.
/*!
    This class helps to define current system byte  order.  Also  it  contains
    methods for converting memory buffer from one byte order to another one.

    System byte order depends on system endings.
    - Big-endian byte order. With it  reader  inputs  number  from  high-order
      byte. 'Big Endian' means that the  high-order  byte  of  the  number  is
      stored in memory at the lowest address, and the low-order  byte  at  the
      highest address.
    - Little-endian byte order. With it reader inputs  number  from  low-order
      byte. 'Little Endian' means that the low-order byte  of  the  number  is
      stored in memory at the lowest address, and the high-order byte  at  the
      highest address.
*/
class BASE_API CEndians :
  public NDepth::NCommon::IStatic
{
public:
  //! Is current system byte order big endian?
  /*!
      \return true  - if current system byte order is big endian. \n
              false - if current system byte order is little endian. \n
  */
  static Tbool isBigEndian();
  //! Is current system byte order little endian?
  /*!
      \return true  - if current system byte order is little endian. \n
              false - if current system byte order is big endian. \n
  */
  static Tbool isLittleEndian();

  //! Convert bytes from one system byte order to another.
  /*!
      \param a_pBuffer - Buffer to convert.
      \param a_cOneElementSize - Size of one buffer element in bytes.
  */
  static void convert(Tptr a_pBuffer, const Tuint a_cOneElementSize);
  //! Convert bytes from one system byte order to another.
  /*!
      \param a_pDestination - Destination buffer.
      \param a_cpSource - Source buffer to convert.
      \param a_cOneElementSize - Size of one buffer element in bytes.
  */
  static void convert(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cOneElementSize);

  //! Convert bytes from one system byte order to another.
  /*!
      \param a_pBuffer - Buffer to convert.
      \param a_cOneElementSize - Size of one buffer element in bytes.
      \param a_cElementsCount - Count of buffer elements.
  */
  static void convert(Tptr a_pBuffer, const Tuint a_cOneElementSize, const Tuint a_cElementsCount);
  //! Convert bytes from one system byte order to another.
  /*!
      \param a_pDestination - Destination buffer.
      \param a_cpSource - Source buffer to convert.
      \param a_cOneElementSize - Size of one buffer element in bytes.
      \param a_cElementsCount - Count of buffer elements.
  */
  static void convert(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cOneElementSize, const Tuint a_cElementsCount);

  //! Convert 1 byte from one system byte order to another.
  /*!
      \param a_pBuffer - Buffer to convert.
  */
  static void convert8(Tptr a_pBuffer);
  //! Convert 1 byte from one system byte order to another.
  /*!
      \param a_pDestination - Destination buffer.
      \param a_cpSource - Source buffer to convert.
  */
  static void convert8(Tptr a_pDestination, Tcptr a_cpSource);

  //! Convert 2 bytes from one system byte order to another.
  /*!
      \param a_pBuffer - Buffer to convert.
  */
  static void convert16(Tptr a_pBuffer);
  //! Convert 2 bytes from one system byte order to another.
  /*!
      \param a_pDestination - Destination buffer.
      \param a_cpSource - Source buffer to convert.
  */
  static void convert16(Tptr a_pDestination, Tcptr a_cpSource);

  //! Convert 4 bytes from one system byte order to another.
  /*!
      \param a_pBuffer - Buffer to convert.
  */
  static void convert32(Tptr a_pBuffer);
  //! Convert 4 bytes from one system byte order to another.
  /*!
      \param a_pDestination - Destination buffer.
      \param a_cpSource - Source buffer to convert.
  */
  static void convert32(Tptr a_pDestination, Tcptr a_cpSource);

  //! Convert 8 bytes from one system byte order to another.
  /*!
      \param a_pBuffer - Buffer to convert.
  */
  static void convert64(Tptr a_pBuffer);
  //! Convert 8 bytes from one system byte order to another.
  /*!
      \param a_pDestination - Destination buffer.
      \param a_cpSource - Source buffer to convert.
  */
  static void convert64(Tptr a_pDestination, Tcptr a_cpSource);

  //! Convert float from one system byte order to another.
  /*!
      \param a_pBuffer - Buffer to convert.
  */
  static void convertFloat(Tptr a_pBuffer);
  //! Convert float from one system byte order to another.
  /*!
      \param a_pDestination - Destination buffer.
      \param a_cpSource - Source buffer to convert.
  */
  static void convertFloat(Tptr a_pDestination, Tcptr a_cpSource);

  //! Convert double from one system byte order to another.
  /*!
      \param a_pBuffer - Buffer to convert.
  */
  static void convertDouble(Tptr a_pBuffer);
  //! Convert double from one system byte order to another.
  /*!
      \param a_pDestination - Destination buffer.
      \param a_cpSource - Source buffer to convert.
  */
  static void convertDouble(Tptr a_pDestination, Tcptr a_cpSource);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/CEndians.inl>
/*==========================================================================*/
#endif
