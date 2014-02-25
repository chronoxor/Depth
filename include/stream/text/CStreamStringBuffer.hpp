/*!
 *  \file    CStreamStringBuffer.hpp String buffer stream class gives ability
 *           to read/write byte sequences from/into the fixed string buffer.
 *  \brief   String buffer stream class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: String buffer stream class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   26.09.2008 00:17:58

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
#ifndef __CSTREAMSTRINGBUFFER_HPP__
#define __CSTREAMSTRINGBUFFER_HPP__
/*==========================================================================*/
#include <Depth/include/stream/text/CStreamStringBufferASCII.hpp>
#include <Depth/include/stream/text/CStreamStringBufferUnicode.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NText {
/*==========================================================================*/
/* TYPES DECLARATIONS                                                       */
/*==========================================================================*/
#ifndef __UNICODE__
typedef CStreamStringBufferASCII CStreamStringBuffer;   //!< String stream buffer in the ASCII encoding class.
#else
typedef CStreamStringBufferUnicode CStreamStringBuffer; //!< String stream buffer in the Unicode encoding class.
#endif
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
