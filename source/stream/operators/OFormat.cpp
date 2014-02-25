/*!
 *  \file    OFormat.cpp Format stream control operator. It is used to
 *           format output or unformat input through stream operators.
 *  \brief   Format stream control operator (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Format stream control operator (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 23:08:59

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
#include <Depth/include/stream/operators/OFormat.hpp>
/*==========================================================================*/
#ifndef __OFORMAT_CPP__
#define __OFORMAT_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* OPERATOR IMPLEMENTATIONS                                                 */
/*==========================================================================*/
BASE_API IReader& operator >> (IReader& a_rReader, const format& a_crFormat)
{ CALL
  switch (a_crFormat.m_Type)
  {
    case 0:
    {
      a_rReader.readFormatVarList(a_crFormat.m_FormatBufferASCII, a_crFormat.m_VariableList);
      break;
    }
    case 1:
    {
      a_rReader.readFormatVarList(a_crFormat.m_FormatBufferUnicode, a_crFormat.m_VariableList);
      break;
    }
    case 2:
    {
      a_rReader.readFormatVarList(a_crFormat.m_FormatStringASCII, a_crFormat.m_VariableList);
      break;
    }
    case 3:
    {
      a_rReader.readFormatVarList(a_crFormat.m_FormatStringUnicode, a_crFormat.m_VariableList);
      break;
    }
  }
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
BASE_API IReader& operator > (IReader& a_rReader, const format& a_crFormat)
{ CALL
  switch (a_crFormat.m_Type)
  {
    case 0:
    {
      a_rReader.peekFormatVarList(a_crFormat.m_FormatBufferASCII, a_crFormat.m_VariableList);
      break;
    }
    case 1:
    {
      a_rReader.peekFormatVarList(a_crFormat.m_FormatBufferUnicode, a_crFormat.m_VariableList);
      break;
    }
    case 2:
    {
      a_rReader.peekFormatVarList(a_crFormat.m_FormatStringASCII, a_crFormat.m_VariableList);
      break;
    }
    case 3:
    {
      a_rReader.peekFormatVarList(a_crFormat.m_FormatStringUnicode, a_crFormat.m_VariableList);
      break;
    }
  }
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
BASE_API IReader& operator < (IReader& a_rReader, const format& a_crFormat)
{ CALL
  switch (a_crFormat.m_Type)
  {
    case 0:
    {
      a_rReader.pushFormatVarList(a_crFormat.m_FormatBufferASCII, a_crFormat.m_VariableList);
      break;
    }
    case 1:
    {
      a_rReader.pushFormatVarList(a_crFormat.m_FormatBufferUnicode, a_crFormat.m_VariableList);
      break;
    }
    case 2:
    {
      a_rReader.pushFormatVarList(a_crFormat.m_FormatStringASCII, a_crFormat.m_VariableList);
      break;
    }
    case 3:
    {
      a_rReader.pushFormatVarList(a_crFormat.m_FormatStringUnicode, a_crFormat.m_VariableList);
      break;
    }
  }
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
BASE_API IWriter& operator << (IWriter& a_rWriter, const format& a_crFormat)
{ CALL
  switch (a_crFormat.m_Type)
  {
    case 0:
    {
      a_rWriter.writeFormatVarList(a_crFormat.m_FormatBufferASCII, a_crFormat.m_VariableList);
      break;
    }
    case 1:
    {
      a_rWriter.writeFormatVarList(a_crFormat.m_FormatBufferUnicode, a_crFormat.m_VariableList);
      break;
    }
    case 2:
    {
      a_rWriter.writeFormatVarList(a_crFormat.m_FormatStringASCII, a_crFormat.m_VariableList);
      break;
    }
    case 3:
    {
      a_rWriter.writeFormatVarList(a_crFormat.m_FormatStringUnicode, a_crFormat.m_VariableList);
      break;
    }
  }
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
