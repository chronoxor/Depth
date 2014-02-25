/*!
 *  \file    OFormatFlags.inl Format flags stream control operators. They are
 *           used to manipulate stream format flags through stream operators.
 *  \brief   Format flags stream control operators (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Format flags stream control operators (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   02.10.2008 01:48:42

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
#ifndef __OFORMATFLAGS_INL__
#define __OFORMATFLAGS_INL__
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
inline flags::flags(const Tuint a_cFormatFlags) :
  m_RemoveFormatFlags(CONSTU(~0)),
  m_AddFormatFlags(a_cFormatFlags)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline flags::flags(const Tuint a_cRemoveFormatFlags, const Tuint a_cAddFormatFlags) :
  m_RemoveFormatFlags(a_cRemoveFormatFlags),
  m_AddFormatFlags(a_cAddFormatFlags)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator >> (IReader& a_rReader, const flags& a_crFormatFlags)
{ CALL
  // Remove format flags.
  a_rReader.setCurrentFormatFlags(a_rReader.getCurrentFormatFlags() & ((~a_crFormatFlags.m_RemoveFormatFlags & 0x00FFFFFF) | 0xFF000000));
  // Remove parse flags.
  a_rReader.setCurrentParseFlags(a_rReader.getCurrentParseFlags() & ((~a_crFormatFlags.m_RemoveFormatFlags & 0xFF000000) | 0x00FFFFFF));
  // Add format flags.
  a_rReader.setCurrentFormatFlags(a_rReader.getCurrentFormatFlags() | ((a_crFormatFlags.m_AddFormatFlags & 0x00FFFFFF) | 0xFF000000));
  // Add parse flags.
  a_rReader.setCurrentParseFlags(a_rReader.getCurrentParseFlags() | ((a_crFormatFlags.m_AddFormatFlags & 0xFF000000) | 0x00FFFFFF));
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator > (IReader& a_rReader, const flags& a_crFormatFlags)
{ CALL
  // Remove format flags.
  a_rReader.setCurrentFormatFlags(a_rReader.getCurrentFormatFlags() & ((~a_crFormatFlags.m_RemoveFormatFlags & 0x00FFFFFF) | 0xFF000000));
  // Remove parse flags.
  a_rReader.setCurrentParseFlags(a_rReader.getCurrentParseFlags() & ((~a_crFormatFlags.m_RemoveFormatFlags & 0xFF000000) | 0x00FFFFFF));
  // Add format flags.
  a_rReader.setCurrentFormatFlags(a_rReader.getCurrentFormatFlags() | ((a_crFormatFlags.m_AddFormatFlags & 0x00FFFFFF) | 0xFF000000));
  // Add parse flags.
  a_rReader.setCurrentParseFlags(a_rReader.getCurrentParseFlags() | ((a_crFormatFlags.m_AddFormatFlags & 0xFF000000) | 0x00FFFFFF));
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator < (IReader& a_rReader, const flags& a_crFormatFlags)
{ CALL
  // Remove format flags.
  a_rReader.setCurrentFormatFlags(a_rReader.getCurrentFormatFlags() & ((~a_crFormatFlags.m_RemoveFormatFlags & 0x00FFFFFF) | 0xFF000000));
  // Remove parse flags.
  a_rReader.setCurrentParseFlags(a_rReader.getCurrentParseFlags() & ((~a_crFormatFlags.m_RemoveFormatFlags & 0xFF000000) | 0x00FFFFFF));
  // Add format flags.
  a_rReader.setCurrentFormatFlags(a_rReader.getCurrentFormatFlags() | ((a_crFormatFlags.m_AddFormatFlags & 0x00FFFFFF) | 0xFF000000));
  // Add parse flags.
  a_rReader.setCurrentParseFlags(a_rReader.getCurrentParseFlags() | ((a_crFormatFlags.m_AddFormatFlags & 0xFF000000) | 0x00FFFFFF));
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IWriter& operator << (IWriter& a_rWriter, const flags& a_crFormatFlags)
{ CALL
  // Remove format flags.
  a_rWriter.setCurrentFormatFlags(a_rWriter.getCurrentFormatFlags() & ((~a_crFormatFlags.m_RemoveFormatFlags & 0x00FFFFFF) | 0xFF000000));
  // Remove parse flags.
  a_rWriter.setCurrentParseFlags(a_rWriter.getCurrentParseFlags() & ((~a_crFormatFlags.m_RemoveFormatFlags & 0xFF000000) | 0x00FFFFFF));
  // Add format flags.
  a_rWriter.setCurrentFormatFlags(a_rWriter.getCurrentFormatFlags() | ((a_crFormatFlags.m_AddFormatFlags & 0x00FFFFFF) | 0xFF000000));
  // Add parse flags.
  a_rWriter.setCurrentParseFlags(a_rWriter.getCurrentParseFlags() | ((a_crFormatFlags.m_AddFormatFlags & 0xFF000000) | 0x00FFFFFF));
  return a_rWriter;
}
/*==========================================================================*/
inline prec::prec(const Tuint a_cPrecision) :
  m_Precision(a_cPrecision)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator >> (IReader& a_rReader, const prec& a_crPrecision)
{ CALL
  a_rReader.setCurrentPrecision(a_crPrecision.m_Precision);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator > (IReader& a_rReader, const prec& a_crPrecision)
{ CALL
  a_rReader.setCurrentPrecision(a_crPrecision.m_Precision);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator < (IReader& a_rReader, const prec& a_crPrecision)
{ CALL
  a_rReader.setCurrentPrecision(a_crPrecision.m_Precision);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IWriter& operator << (IWriter& a_rWriter, const prec& a_crPrecision)
{ CALL
  a_rWriter.setCurrentPrecision(a_crPrecision.m_Precision);
  return a_rWriter;
}
/*==========================================================================*/
inline width::width(const Tuint a_cWidth) :
  m_Width(a_cWidth)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator >> (IReader& a_rReader, const width& a_crWidth)
{ CALL
  a_rReader.setCurrentWidth(a_crWidth.m_Width);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator > (IReader& a_rReader, const width& a_crWidth)
{ CALL
  a_rReader.setCurrentWidth(a_crWidth.m_Width);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator < (IReader& a_rReader, const width& a_crWidth)
{ CALL
  a_rReader.setCurrentWidth(a_crWidth.m_Width);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IWriter& operator << (IWriter& a_rWriter, const width& a_crWidth)
{ CALL
  a_rWriter.setCurrentWidth(a_crWidth.m_Width);
  return a_rWriter;
}
/*==========================================================================*/
inline radix::radix(const Tuint a_cRadix) :
  m_Radix(a_cRadix)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator >> (IReader& a_rReader, const radix& a_crRadix)
{ CALL
  a_rReader.setCurrentRadix(a_crRadix.m_Radix);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator > (IReader& a_rReader, const radix& a_crRadix)
{ CALL
  a_rReader.setCurrentRadix(a_crRadix.m_Radix);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator < (IReader& a_rReader, const radix& a_crRadix)
{ CALL
  a_rReader.setCurrentRadix(a_crRadix.m_Radix);
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IWriter& operator << (IWriter& a_rWriter, const radix& a_crRadix)
{ CALL
  a_rWriter.setCurrentRadix(a_crRadix.m_Radix);
  return a_rWriter;
}
/*==========================================================================*/
inline BASE_API IReader& operator >> (IReader& a_rReader, const resetStream& a_crReset)
{ CALL
  IGNORE_UNUSED(a_crReset);

  a_rReader.setDefaultFormat();
  a_rReader.setDefaultParse();
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator > (IReader& a_rReader, const resetStream& a_crReset)
{ CALL
  IGNORE_UNUSED(a_crReset);

  a_rReader.setDefaultFormat();
  a_rReader.setDefaultParse();
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator < (IReader& a_rReader, const resetStream& a_crReset)
{ CALL
  IGNORE_UNUSED(a_crReset);

  a_rReader.setDefaultFormat();
  a_rReader.setDefaultParse();
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IWriter& operator << (IWriter& a_rWriter, const resetStream& a_crReset)
{ CALL
  IGNORE_UNUSED(a_crReset);

  a_rWriter.setDefaultFormat();
  a_rWriter.setDefaultParse();
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
