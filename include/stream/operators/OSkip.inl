/*!
 *  \file    OSkip.inl Skip stream control operators. They are used to skip
 *           bytes, ASCII or Unicode characters during reading or peeking
 *           through stream operators.
 *  \brief   Skip stream control operators (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Skip stream control operators (inline).

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
#ifndef __OSKIP_INL__
#define __OSKIP_INL__
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
inline skipBytes::skipBytes(const Tuint a_cSize) :
  m_Size(a_cSize)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator >> (IReader& a_rReader, const skipBytes& a_crSkipBytes)
{ CALL
  a_rReader.readSkipBytes(a_crSkipBytes.m_Size);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator > (IReader& a_rReader, const skipBytes& a_crSkipBytes)
{ CALL
  a_rReader.peekSkipBytes(a_crSkipBytes.m_Size);
  return a_rReader;
}
/*==========================================================================*/
inline skipASCII::skipASCII(const Tuint a_cSize) :
  m_Size(a_cSize)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator >> (IReader& a_rReader, const skipASCII& a_crSkipASCII)
{ CALL
  a_rReader.readSkipASCII(a_crSkipASCII.m_Size);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator > (IReader& a_rReader, const skipASCII& a_crSkipASCII)
{ CALL
  a_rReader.peekSkipASCII(a_crSkipASCII.m_Size);
  return a_rReader;
}
/*==========================================================================*/
inline skipUnicode::skipUnicode(const Tuint a_cSize) :
  m_Size(a_cSize)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator >> (IReader& a_rReader, const skipUnicode& a_crSkipUnicode)
{ CALL
  a_rReader.readSkipUnicode(a_crSkipUnicode.m_Size);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator > (IReader& a_rReader, const skipUnicode& a_crSkipUnicode)
{ CALL
  a_rReader.peekSkipUnicode(a_crSkipUnicode.m_Size);
  return a_rReader;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
