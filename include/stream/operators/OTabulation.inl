/*!
 *  \file    OTabulation.inl Tabulation stream control operator. It is used to
 *           manipulate (read, peek, push, write) with tab characters through
 *           stream operators.
 *  \brief   Tabulation stream control operator (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tabulation stream control operator (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   21.01.2009 00:23:26

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
#ifndef __OTABULATION_INL__
#define __OTABULATION_INL__
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
inline tabulation::tabulation() :
  m_IsASCII(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline tabulation::tabulation(const Tbool a_cIsASCII) :
  m_IsASCII(a_cIsASCII ? 1 : 2)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline tabulation tabulation::operator () () const
{ CALL
  return tabulation();
}
/*--------------------------------------------------------------------------*/
inline tabulation tabulation::operator () (const Tbool a_cIsASCII) const
{ CALL
  return tabulation(a_cIsASCII);
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator >> (IReader& a_rReader, const tabulation& a_crTab)
{ CALL
  Tschar sc;
  Twchar wc;
  if ((a_crTab.m_IsASCII == 1) || ((a_crTab.m_IsASCII == 0) && (a_rReader.getCurrentParseFlags() & IStream::PARSE_ASCII)))
    a_rReader.read(sc);
  else
    a_rReader.read(wc);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator > (IReader& a_rReader, const tabulation& a_crTab)
{ CALL
  Tschar sc;
  Twchar wc;
  if ((a_crTab.m_IsASCII == 1) || ((a_crTab.m_IsASCII == 0) && (a_rReader.getCurrentParseFlags() & IStream::PARSE_ASCII)))
    a_rReader.peek(sc);
  else
    a_rReader.peek(wc);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator < (IReader& a_rReader, const tabulation& a_crTab)
{ CALL
  if ((a_crTab.m_IsASCII == 1) || ((a_crTab.m_IsASCII == 0) && (a_rReader.getCurrentFormatFlags() & IStream::FORMAT_ASCII)))
    a_rReader.push(ASC('\t'));
  else
    a_rReader.push(UNC('\t'));
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IWriter& operator << (IWriter& a_rWriter, const tabulation& a_crTab)
{ CALL
  if ((a_crTab.m_IsASCII == 1) || ((a_crTab.m_IsASCII == 0) && (a_rWriter.getCurrentFormatFlags() & IStream::FORMAT_ASCII)))
    a_rWriter.write(ASC('\t'));
  else
    a_rWriter.write(UNC('\t'));
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
