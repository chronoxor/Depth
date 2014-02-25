/*!
 *  \file    AToASCIIPrint.hpp Contains implementation of the fast ASCII to
 *           print characters converting string algorithm.
 *  \brief   Fast ASCII to print characters converting string algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Fast ASCII to print characters converting string algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String buffer algorithms
    VERSION:   1.0
    CREATED:   20.11.2009 02:57:17

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
#ifndef __ATOASCIIPRINT_HPP__
#define __ATOASCIIPRINT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/buffer/AStrLen.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NBuffer {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Fast ASCII to print characters converting string algorithm. Replace version. Zero terminated 'C' string version.
/*!
    Fast converting of the ASCII string buffer to print characters representation.

    \param a_pString - Pointer to the source & destination ASCII string buffer.
*/
BASE_API void toASCIIPrint(Tsstr a_pString);
//! Algorithm: Fast ASCII to print characters converting string algorithm. Replace version.
/*!
    Fast converting of the ASCII string buffer to print characters representation.

    \param a_pString - Pointer to the source & destination ASCII string buffer.
    \param a_cSize - Size of the source ASCII string buffer.
*/
BASE_API void toASCIIPrint(Tsstr a_pString, const Tuint a_cSize);
//! Algorithm: Fast ASCII to print characters converting string algorithm. Copy version. Zero terminated 'C' string version.
/*!
    Fast converting of the ASCII string buffer to print characters representation.

    \param a_pDestination - Pointer to the destination ASCII string buffer.
    \param a_cpSource - Constant pointer to the source ASCII string buffer.
*/
BASE_API void toASCIIPrint(Tsstr a_pDestination, Tcsstr a_cpSource);
//! Algorithm: Fast ASCII to print characters converting string algorithm.
/*!
    Fast converting of the ASCII string buffer to print characters representation.

    \param a_pDestination - Pointer to the destination ASCII string buffer.
    \param a_cpSource - Constant pointer to the source ASCII string buffer.
    \param a_cSize - Size of the source ASCII string buffer.
*/
BASE_API void toASCIIPrint(Tsstr a_pDestination, Tcsstr a_cpSource, const Tuint a_cSize);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/buffer/AToASCIIPrint.inl>
/*==========================================================================*/
#endif
