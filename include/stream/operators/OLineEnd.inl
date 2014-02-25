/*!
 *  \file    OLineEnd.inl Line end stream control operator. It is used to
 *           manipulate (read, peek, push, write) with line end characters
 *           through stream operators.
 *  \brief   Line end stream control operator (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Line end stream control operator (inline).

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
#ifndef __OLINEEND_INL__
#define __OLINEEND_INL__
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
inline lineEnd::lineEnd() :
  m_IsASCII(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline lineEnd::lineEnd(const Tbool a_cIsASCII) :
  m_IsASCII(a_cIsASCII ? 1 : 2)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline lineEnd lineEnd::operator () () const
{ CALL
  return lineEnd();
}
/*--------------------------------------------------------------------------*/
inline lineEnd lineEnd::operator () (const Tbool a_cIsASCII) const
{ CALL
  return lineEnd(a_cIsASCII);
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator >> (IReader& a_rReader, const lineEnd& a_crLineEnd)
{ CALL
  if (a_crLineEnd.m_IsASCII > 0)
    a_rReader.readLineEnd(a_crLineEnd.m_IsASCII == 1);
  else
    a_rReader.readLineEnd();
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator > (IReader& a_rReader, const lineEnd& a_crLineEnd)
{ CALL
  if (a_crLineEnd.m_IsASCII > 0)
    a_rReader.peekLineEnd(a_crLineEnd.m_IsASCII == 1);
  else
    a_rReader.peekLineEnd();
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator < (IReader& a_rReader, const lineEnd& a_crLineEnd)
{ CALL
  if (a_crLineEnd.m_IsASCII > 0)
    a_rReader.pushLineEnd(a_crLineEnd.m_IsASCII == 1);
  else
    a_rReader.pushLineEnd();
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IWriter& operator << (IWriter& a_rWriter, const lineEnd& a_crLineEnd)
{ CALL
  if (a_crLineEnd.m_IsASCII > 0)
    a_rWriter.writeLineEnd(a_crLineEnd.m_IsASCII == 1);
  else
    a_rWriter.writeLineEnd();
  return a_rWriter;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
