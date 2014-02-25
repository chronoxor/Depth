/*!
 *  \file    IExchangeStream.cpp Exchange stream is a base interface for all
 *           implementations of interprocess communication stream classes
 *           (files, pipes, sockets, etc.).
 *  \brief   Exchange stream interface (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Exchange stream interface (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   24.03.2009 21:59:39

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/IExchangeStream.hpp>
/*==========================================================================*/
#ifndef __IEXCHANGESTREAM_CPP__
#define __IEXCHANGESTREAM_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* INTERFACE IMPLEMENTATIONS                                                */
/*==========================================================================*/
void IExchangeStream::set(const IExchangeStream& a_crInstance)
{ CALL
  // Initialize new reader.
  IStream::set(a_crInstance);

  // Set exchange stream parameters.
  m_IsExchange = a_crInstance.m_IsExchange;
  m_Version = a_crInstance.m_Version;
  m_SCharSize = a_crInstance.m_SCharSize;
  m_WCharSize = a_crInstance.m_WCharSize;
  m_SIntSize = a_crInstance.m_SIntSize;
  m_UIntSize = a_crInstance.m_UIntSize;
  m_PtrSize = a_crInstance.m_PtrSize;
  m_IsRealFloat = a_crInstance.m_IsRealFloat;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
