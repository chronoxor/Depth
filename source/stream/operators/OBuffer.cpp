/*!
 *  \file    OBuffer.cpp Buffer stream control operator. It used to manipulate
 *           (read, peek, push, write) with byte, ASCII, Unicode buffers
 *           through stream operators.
 *  \brief   Buffer stream control operator (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Buffer stream control operator (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 00:05:14

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
#include <Depth/include/stream/operators/OBuffer.hpp>
/*==========================================================================*/
#ifndef __OBUFFER_CPP__
#define __OBUFFER_CPP__
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
BASE_API IReader& operator >> (IReader& a_rReader, const buffer& a_crBuffer)
{ CALL
  switch (a_crBuffer.m_Type)
  {
    case 0:
    {
      a_rReader.readBuffer((Tptr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
      break;
    }
    case 1:
    {
      a_rReader.readBuffer((Tptr)a_crBuffer.m_pBuffer, a_crBuffer.m_SingleSize, a_crBuffer.m_Count);
      break;
    }
    case 2:
    {
      a_rReader.readBuffer((Tsstr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
      break;
    }
    case 3:
    {
      a_rReader.readBuffer((Twstr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
      break;
    }
  }
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
BASE_API IReader& operator > (IReader& a_rReader, const buffer& a_crBuffer)
{ CALL
  switch (a_crBuffer.m_Type)
  {
    case 0:
    {
      a_rReader.peekBuffer((Tptr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
      break;
    }
    case 1:
    {
      a_rReader.peekBuffer((Tptr)a_crBuffer.m_pBuffer, a_crBuffer.m_SingleSize, a_crBuffer.m_Count);
      break;
    }
    case 2:
    {
      a_rReader.peekBuffer((Tsstr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
      break;
    }
    case 3:
    {
      a_rReader.peekBuffer((Twstr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
      break;
    }
  }
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
BASE_API IReader& operator < (IReader& a_rReader, const buffer& a_crBuffer)
{ CALL
  switch (a_crBuffer.m_Type)
  {
    case 0:
    {
      a_rReader.pushBuffer((Tcptr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
      break;
    }
    case 1:
    {
      a_rReader.pushBuffer((Tcptr)a_crBuffer.m_pBuffer, a_crBuffer.m_SingleSize, a_crBuffer.m_Count);
      break;
    }
    case 2:
    {
      a_rReader.pushBuffer((Tcsstr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
      break;
    }
    case 3:
    {
      a_rReader.pushBuffer((Tcwstr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
      break;
    }
  }
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
BASE_API IWriter& operator << (IWriter& a_rWriter, const buffer& a_crBuffer)
{ CALL
  switch (a_crBuffer.m_Type)
  {
    case 0:
    {
      a_rWriter.writeBuffer((Tcptr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
      break;
    }
    case 1:
    {
      a_rWriter.writeBuffer((Tcptr)a_crBuffer.m_pBuffer, a_crBuffer.m_SingleSize, a_crBuffer.m_Count);
      break;
    }
    case 2:
    {
      a_rWriter.writeBuffer((Tcsstr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
      break;
    }
    case 3:
    {
      a_rWriter.writeBuffer((Tcwstr)a_crBuffer.m_pBuffer, a_crBuffer.m_Count);
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
