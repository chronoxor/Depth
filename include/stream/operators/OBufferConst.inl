/*!
 *  \file    OBufferConst.inl Constant buffer stream control operator. It
 *           is used to manipulate (push, write) with byte, ASCII, Unicode
 *           constant buffers through stream operators.
 *  \brief   Constant buffer stream control operator (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant buffer stream control operator (inline).

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
#ifndef __OBUFFERCONST_INL__
#define __OBUFFERCONST_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* INLINE OPERATOR IMPLEMENTATIONS                                          */
/*==========================================================================*/
inline cbuffer::cbuffer(Tcptr a_cpBuffer, const Tuint a_cSize) :
  m_Type(0),
  m_SingleSize(1),
  m_Count(a_cSize),
  m_cpBuffer(a_cpBuffer)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline cbuffer::cbuffer(Tcptr a_cpBuffer, const Tuint a_cSingleSize, const Tuint a_cCount) :
  m_Type(1),
  m_SingleSize(a_cSingleSize),
  m_Count(a_cCount),
  m_cpBuffer(a_cpBuffer)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline cbuffer::cbuffer(Tcsstr a_cpBuffer, const Tuint a_cSize) :
  m_Type(2),
  m_SingleSize(sizeof(Tschar)),
  m_Count(a_cSize),
  m_cpBuffer((Tcptr)a_cpBuffer)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline cbuffer::cbuffer(Tcwstr a_cpBuffer, const Tuint a_cSize) :
  m_Type(3),
  m_SingleSize(sizeof(Twchar)),
  m_Count(a_cSize),
  m_cpBuffer((Tcptr)a_cpBuffer)
{ CALL

}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
