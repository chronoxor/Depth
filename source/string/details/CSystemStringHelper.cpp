/*!
 *  \file    CSystemStringHelper.cpp System string helper class contains
 *           strings encoding functionality.
 *  \brief   System string helper class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: System string helper class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String details
    VERSION:   1.0
    CREATED:   01.04.2008 21:27:16

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
#include <Depth/include/memory/CMemory.hpp>
#include <Depth/include/string/details/CSystemStringHelper.hpp>
/*==========================================================================*/
#ifndef __CSYSTEMSTRINGHELPER_CPP__
#define __CSYSTEMSTRINGHELPER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CSystemStringHelper::TGetMaxBytesFunction CSystemStringHelper::ms_fGetMaxBytesPerASCIIChar = 0;
CSystemStringHelper::TGetMaxBytesFunction CSystemStringHelper::ms_fGetMaxBytesPerUnicodeChar = 0;
CSystemStringHelper::TGetMaxBytesFunction CSystemStringHelper::ms_fGetMaxBytesPerSystemChar = 0;
CSystemStringHelper::TGetCharsCountFunction CSystemStringHelper::ms_fGetASCIICharsCount = 0;
CSystemStringHelper::TGetCharsCountFunction CSystemStringHelper::ms_fGetUnicodeCharsCount = 0;
CSystemStringHelper::TGetCharsCountFunction CSystemStringHelper::ms_fGetSystemCharsCount = 0;
CSystemStringHelper::TEncodingCountFunction CSystemStringHelper::ms_fASCIIToSystemCount = 0;
CSystemStringHelper::TEncodingCountFunction CSystemStringHelper::ms_fUnicodeToSystemCount = 0;
CSystemStringHelper::TEncodingCountFunction CSystemStringHelper::ms_fUTF8ToSystemCount = 0;
CSystemStringHelper::TEncodingCountFunction CSystemStringHelper::ms_fASCIIToUTF8Count = 0;
CSystemStringHelper::TEncodingCountFunction CSystemStringHelper::ms_fUnicodeToUTF8Count = 0;
CSystemStringHelper::TEncodingCountFunction CSystemStringHelper::ms_fSystemToASCIICount = 0;
CSystemStringHelper::TEncodingCountFunction CSystemStringHelper::ms_fSystemToUnicodeCount = 0;
CSystemStringHelper::TEncodingCountFunction CSystemStringHelper::ms_fSystemToUTF8Count = 0;
CSystemStringHelper::TEncodingCountFunction CSystemStringHelper::ms_fUTF8ToASCIICount = 0;
CSystemStringHelper::TEncodingCountFunction CSystemStringHelper::ms_fUTF8ToUnicodeCount = 0;
CSystemStringHelper::TEncodingConvertFunction CSystemStringHelper::ms_fASCIIToSystem = 0;
CSystemStringHelper::TEncodingConvertFunction CSystemStringHelper::ms_fUnicodeToSystem = 0;
CSystemStringHelper::TEncodingConvertFunction CSystemStringHelper::ms_fUTF8ToSystem = 0;
CSystemStringHelper::TEncodingConvertFunction CSystemStringHelper::ms_fASCIIToUTF8 = 0;
CSystemStringHelper::TEncodingConvertFunction CSystemStringHelper::ms_fUnicodeToUTF8 = 0;
CSystemStringHelper::TEncodingConvertFunction CSystemStringHelper::ms_fSystemToASCII = 0;
CSystemStringHelper::TEncodingConvertFunction CSystemStringHelper::ms_fSystemToUnicode = 0;
CSystemStringHelper::TEncodingConvertFunction CSystemStringHelper::ms_fSystemToUTF8 = 0;
CSystemStringHelper::TEncodingConvertFunction CSystemStringHelper::ms_fUTF8ToASCII = 0;
CSystemStringHelper::TEncodingConvertFunction CSystemStringHelper::ms_fUTF8ToUnicode = 0;
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::getUCS1CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  Tuint size = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  a_rCount = 0;
  while (size >= 1)
  {
    ++a_rCount;
    size -= 1;
    src += 1;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::getUCS2CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  Tuint size = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  a_rCount = 0;
  while (size >= 2)
  {
    #if defined(__BIG_ENDIAN__)
    if ((src[0] >= 0xD8) && (src[0] < 0xE0))
      return false;
    #else
    if ((src[1] >= 0xD8) && (src[1] < 0xE0))
      return false;
    #endif

    ++a_rCount;
    size -= 2;
    src += 2;
  }
  return (size == 0);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::getUCS4CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  Tuint size = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  a_rCount = 0;
  while (size >= 4)
  {
    ++a_rCount;
    size -= 4;
    src += 4;
  }
  return (size == 0);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::getUTF8CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  Tuint wc;
  Tuint inc_src = 0;
  Tuint size = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  a_rCount = 0;
  while (size >= 1)
  {
    wc = src[0];
    if (wc < 0x80)
      inc_src = 1;
    else if (wc < 0xC2)
      return false;
    else if (wc < 0xE0)
    {
      if (size < 2)
        break;
      if (!((src[1] ^ 0x80) < 0x40))
        return false;
      inc_src = 2;
    }
    else if (wc < 0xF0)
    {
      if (size < 3)
        break;
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((wc >= 0xE1) || (src[1] >= 0xA0))))
        return false;
      inc_src = 3;
    }
    else if (wc < 0xF8)
    {
      if (size < 4)
        break;
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((wc >= 0xF1) || (src[1] >= 0x90))))
        return false;
      inc_src = 4;
    }
    else if (wc < 0xFC)
    {
      if (size < 5)
        break;
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((wc >= 0xF9) || (src[1] >= 0x88))))
        return false;
      inc_src = 5;
    }
    else if (wc < 0xFE)
    {
      if (size < 6)
        break;
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((src[5] ^ 0x80) < 0x40) && ((wc >= 0xFD) || (src[1] >= 0x84))))
        return false;
      inc_src = 6;
    }
    else
      return false;

    ++a_rCount;
    size -= inc_src;
    src += inc_src;
  }
  return (size == 0);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::getUTF16CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  Tuint wc;
  Tuint inc_src = 0;
  Tuint size = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  a_rCount = 0;
  while (size >= 2)
  {
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 8) + src[1];
    #else
    wc = src[0] + (src[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      if (size < 4)
        break;

      #if defined(__BIG_ENDIAN__)
      Tuint wc_temp = (src[2] << 8) + src[3];
      #else
      Tuint wc_temp = src[2] + (src[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
        return false;
      inc_src = 4;
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
      return false;
    else
      inc_src = 2;

    ++a_rCount;
    size -= inc_src;
    src += inc_src;
  }
  return (size == 0);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::getUTF32CharsCount(Tcptr a_cpBuffer, const Tuint a_cSize, Tuint& a_rCount)
{ CALL
  Tuint wc;
  Tuint size = a_cSize;
  Tcbuffer src = (Tcbuffer)a_cpBuffer;

  a_rCount = 0;
  while (size >= 4)
  {
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif
    if (!((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000))))
      return false;

    ++a_rCount;
    size -= 4;
    src += 4;
  }
  return (size == 0);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  IGNORE_UNUSED(a_cpSource);

  a_rResult = a_cCount;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  IGNORE_UNUSED(a_cpSource);

  a_rResult = (a_cCount << 1);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  IGNORE_UNUSED(a_cpSource);

  a_rResult = (a_cCount << 2);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 1;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    wc = src[0];

    // Convert into the destination buffer.
    if (wc < 0x80)
      inc_dst = 1;
    else if (wc < 0x800)
      inc_dst = 2;
    else if (wc < 0x10000)
      inc_dst = 3;
    else if (wc < 0x200000)
      inc_dst = 4;
    else if (wc < 0x4000000)
      inc_dst = 5;
    else if (wc <= 0x7FFFFFFF)
      inc_dst = 6;
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 1;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    wc = src[0];

    // Convert into the destination buffer.
    if (!((wc >= 0xD800) && (wc < 0xE000)))
    {
      if (wc < 0x10000)
        inc_dst = 2;
      else if (wc < 0x110000)
        inc_dst = 4;
    }
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 1;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    wc = src[0];

    // Convert into the destination buffer.
    if (!((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000))))
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 1;
  Tuint inc_src = 2;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    if ((src[0] >= 0xD8) && (src[0] < 0xE0))
      return false;
    wc = (src[0] << 8) + src[1];
    #else
    if ((src[1] >= 0xD8) && (src[1] < 0xE0))
      return false;
    wc = src[0] + (src[1] << 8);
    #endif

    // Convert into the destination buffer.
    if (wc >= 0x100)
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  IGNORE_UNUSED(a_cpSource);

  a_rResult = a_cCount;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  IGNORE_UNUSED(a_cpSource);

  a_rResult = (a_cCount << 1);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 2;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    if ((src[0] >= 0xD8) && (src[0] < 0xE0))
      return false;
    wc = (src[0] << 8) + src[1];
    #else
    if ((src[1] >= 0xD8) && (src[1] < 0xE0))
      return false;
    wc = src[0] + (src[1] << 8);
    #endif

    // Convert into the destination buffer.
    if (wc < 0x80)
      inc_dst = 1;
    else if (wc < 0x800)
      inc_dst = 2;
    else if (wc < 0x10000)
      inc_dst = 3;
    else if (wc < 0x200000)
      inc_dst = 4;
    else if (wc < 0x4000000)
      inc_dst = 5;
    else if (wc <= 0x7FFFFFFF)
      inc_dst = 6;
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 2;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    if ((src[0] >= 0xD8) && (src[0] < 0xE0))
      return false;
    wc = (src[0] << 8) + src[1];
    #else
    if ((src[1] >= 0xD8) && (src[1] < 0xE0))
      return false;
    wc = src[0] + (src[1] << 8);
    #endif

    // Convert into the destination buffer.
    if (!((wc >= 0xD800) && (wc < 0xE000)))
    {
      if (wc < 0x10000)
        inc_dst = 2;
      else if (wc < 0x110000)
        inc_dst = 4;
    }
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 2;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    if ((src[0] >= 0xD8) && (src[0] < 0xE0))
      return false;
    wc = (src[0] << 8) + src[1];
    #else
    if ((src[1] >= 0xD8) && (src[1] < 0xE0))
      return false;
    wc = src[0] + (src[1] << 8);
    #endif

    // Convert into the destination buffer.
    if (!((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000))))
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 1;
  Tuint inc_src = 4;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif

    // Convert into the destination buffer.
    if (wc >= 0x100)
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 2;
  Tuint inc_src = 4;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif

    // Convert into the destination buffer.
    if (!((wc < 0x10000) && !((wc >= 0xD800) && (wc < 0xE000))))
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  IGNORE_UNUSED(a_cpSource);

  a_rResult = a_cCount;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 4;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif

    // Convert into the destination buffer.
    if (wc < 0x80)
      inc_dst = 1;
    else if (wc < 0x800)
      inc_dst = 2;
    else if (wc < 0x10000)
      inc_dst = 3;
    else if (wc < 0x200000)
      inc_dst = 4;
    else if (wc < 0x4000000)
      inc_dst = 5;
    else if (wc <= 0x7FFFFFFF)
      inc_dst = 6;
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 4;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif

    // Convert into the destination buffer.
    if (!((wc >= 0xD800) && (wc < 0xE000)))
    {
      if (wc < 0x10000)
        inc_dst = 2;
      else if (wc < 0x110000)
        inc_dst = 4;
    }
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 4;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif

    // Convert into the destination buffer.
    if (!((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000))))
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tbyte c;
  Tuint wc;
  Tuint inc_dst = 1;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    c = src[0];
    if (c < 0x80)
    {
      wc = c;
      inc_src = 1;
    }
    else if (c < 0xC2)
      return false;
    else if (c < 0xE0)
    {
      if (!((src[1] ^ 0x80) < 0x40))
        return false;
      wc = ((c & 0x1F) << 6) | (src[1] ^ 0x80);
      inc_src = 2;
    }
    else if (c < 0xF0)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (src[1] >= 0xA0))))
        return false;
      wc = ((c & 0x0F) << 12) | ((src[1] ^ 0x80) << 6) | (src[2] ^ 0x80);
      inc_src = 3;
    }
    else if (c < 0xF8)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (src[1] >= 0x90))))
        return false;
      wc = ((c & 0x07) << 18) | ((src[1] ^ 0x80) << 12) | ((src[2] ^ 0x80) << 6) | (src[3] ^ 0x80);
      inc_src = 4;
    }
    else if (c < 0xFC)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (src[1] >= 0x88))))
        return false;
      wc = ((c & 0x03) << 24) | ((src[1] ^ 0x80) << 18) | ((src[2] ^ 0x80) << 12) | ((src[3] ^ 0x80) << 6) | (src[4] ^ 0x80);
      inc_src = 5;
    }
    else if (c < 0xFE)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((src[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (src[1] >= 0x84))))
        return false;
      wc = ((c & 0x01) << 30) | ((src[1] ^ 0x80) << 24) | ((src[2] ^ 0x80) << 18) | ((src[3] ^ 0x80) << 12) | ((src[4] ^ 0x80) << 6) | (src[5] ^ 0x80);
      inc_src = 6;
    }
    else
      return false;

    // Convert into the destination buffer.
    if (wc >= 0x100)
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tbyte c;
  Tuint wc;
  Tuint inc_dst = 2;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    c = src[0];
    if (c < 0x80)
    {
      wc = c;
      inc_src = 1;
    }
    else if (c < 0xC2)
      return false;
    else if (c < 0xE0)
    {
      if (!((src[1] ^ 0x80) < 0x40))
        return false;
      wc = ((c & 0x1F) << 6) | (src[1] ^ 0x80);
      inc_src = 2;
    }
    else if (c < 0xF0)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (src[1] >= 0xA0))))
        return false;
      wc = ((c & 0x0F) << 12) | ((src[1] ^ 0x80) << 6) | (src[2] ^ 0x80);
      inc_src = 3;
    }
    else if (c < 0xF8)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (src[1] >= 0x90))))
        return false;
      wc = ((c & 0x07) << 18) | ((src[1] ^ 0x80) << 12) | ((src[2] ^ 0x80) << 6) | (src[3] ^ 0x80);
      inc_src = 4;
    }
    else if (c < 0xFC)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (src[1] >= 0x88))))
        return false;
      wc = ((c & 0x03) << 24) | ((src[1] ^ 0x80) << 18) | ((src[2] ^ 0x80) << 12) | ((src[3] ^ 0x80) << 6) | (src[4] ^ 0x80);
      inc_src = 5;
    }
    else if (c < 0xFE)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((src[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (src[1] >= 0x84))))
        return false;
      wc = ((c & 0x01) << 30) | ((src[1] ^ 0x80) << 24) | ((src[2] ^ 0x80) << 18) | ((src[3] ^ 0x80) << 12) | ((src[4] ^ 0x80) << 6) | (src[5] ^ 0x80);
      inc_src = 6;
    }
    else
      return false;

    // Convert into the destination buffer.
    if (!((wc < 0x10000) && !((wc >= 0xD800) && (wc < 0xE000))))
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tbyte c;
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    c = src[0];
    if (c < 0x80)
    {
      wc = c;
      inc_src = 1;
    }
    else if (c < 0xC2)
      return false;
    else if (c < 0xE0)
    {
      if (!((src[1] ^ 0x80) < 0x40))
        return false;
      wc = ((c & 0x1F) << 6) | (src[1] ^ 0x80);
      inc_src = 2;
    }
    else if (c < 0xF0)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (src[1] >= 0xA0))))
        return false;
      wc = ((c & 0x0F) << 12) | ((src[1] ^ 0x80) << 6) | (src[2] ^ 0x80);
      inc_src = 3;
    }
    else if (c < 0xF8)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (src[1] >= 0x90))))
        return false;
      wc = ((c & 0x07) << 18) | ((src[1] ^ 0x80) << 12) | ((src[2] ^ 0x80) << 6) | (src[3] ^ 0x80);
      inc_src = 4;
    }
    else if (c < 0xFC)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (src[1] >= 0x88))))
        return false;
      wc = ((c & 0x03) << 24) | ((src[1] ^ 0x80) << 18) | ((src[2] ^ 0x80) << 12) | ((src[3] ^ 0x80) << 6) | (src[4] ^ 0x80);
      inc_src = 5;
    }
    else if (c < 0xFE)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((src[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (src[1] >= 0x84))))
        return false;
      wc = ((c & 0x01) << 30) | ((src[1] ^ 0x80) << 24) | ((src[2] ^ 0x80) << 18) | ((src[3] ^ 0x80) << 12) | ((src[4] ^ 0x80) << 6) | (src[5] ^ 0x80);
      inc_src = 6;
    }
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  IGNORE_UNUSED(a_cpSource);

  a_rResult = a_cCount;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tbyte c;
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    c = src[0];
    if (c < 0x80)
    {
      wc = c;
      inc_src = 1;
    }
    else if (c < 0xC2)
      return false;
    else if (c < 0xE0)
    {
      if (!((src[1] ^ 0x80) < 0x40))
        return false;
      wc = ((c & 0x1F) << 6) | (src[1] ^ 0x80);
      inc_src = 2;
    }
    else if (c < 0xF0)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (src[1] >= 0xA0))))
        return false;
      wc = ((c & 0x0F) << 12) | ((src[1] ^ 0x80) << 6) | (src[2] ^ 0x80);
      inc_src = 3;
    }
    else if (c < 0xF8)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (src[1] >= 0x90))))
        return false;
      wc = ((c & 0x07) << 18) | ((src[1] ^ 0x80) << 12) | ((src[2] ^ 0x80) << 6) | (src[3] ^ 0x80);
      inc_src = 4;
    }
    else if (c < 0xFC)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (src[1] >= 0x88))))
        return false;
      wc = ((c & 0x03) << 24) | ((src[1] ^ 0x80) << 18) | ((src[2] ^ 0x80) << 12) | ((src[3] ^ 0x80) << 6) | (src[4] ^ 0x80);
      inc_src = 5;
    }
    else if (c < 0xFE)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((src[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (src[1] >= 0x84))))
        return false;
      wc = ((c & 0x01) << 30) | ((src[1] ^ 0x80) << 24) | ((src[2] ^ 0x80) << 18) | ((src[3] ^ 0x80) << 12) | ((src[4] ^ 0x80) << 6) | (src[5] ^ 0x80);
      inc_src = 6;
    }
    else
      return false;

    // Convert into the destination buffer.
    if (!((wc >= 0xD800) && (wc < 0xE000)))
    {
      if (wc < 0x10000)
        inc_dst = 2;
      else if (wc < 0x110000)
        inc_dst = 4;
    }
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tbyte c;
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    c = src[0];
    if (c < 0x80)
    {
      wc = c;
      inc_src = 1;
    }
    else if (c < 0xC2)
      return false;
    else if (c < 0xE0)
    {
      if (!((src[1] ^ 0x80) < 0x40))
        return false;
      wc = ((c & 0x1F) << 6) | (src[1] ^ 0x80);
      inc_src = 2;
    }
    else if (c < 0xF0)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (src[1] >= 0xA0))))
        return false;
      wc = ((c & 0x0F) << 12) | ((src[1] ^ 0x80) << 6) | (src[2] ^ 0x80);
      inc_src = 3;
    }
    else if (c < 0xF8)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (src[1] >= 0x90))))
        return false;
      wc = ((c & 0x07) << 18) | ((src[1] ^ 0x80) << 12) | ((src[2] ^ 0x80) << 6) | (src[3] ^ 0x80);
      inc_src = 4;
    }
    else if (c < 0xFC)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (src[1] >= 0x88))))
        return false;
      wc = ((c & 0x03) << 24) | ((src[1] ^ 0x80) << 18) | ((src[2] ^ 0x80) << 12) | ((src[3] ^ 0x80) << 6) | (src[4] ^ 0x80);
      inc_src = 5;
    }
    else if (c < 0xFE)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((src[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (src[1] >= 0x84))))
        return false;
      wc = ((c & 0x01) << 30) | ((src[1] ^ 0x80) << 24) | ((src[2] ^ 0x80) << 18) | ((src[3] ^ 0x80) << 12) | ((src[4] ^ 0x80) << 6) | (src[5] ^ 0x80);
      inc_src = 6;
    }
    else
      return false;

    // Convert into the destination buffer.
    if (!((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000))))
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 1;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 8) + src[1];
    #else
    wc = src[0] + (src[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      #if defined(__BIG_ENDIAN__)
      Tuint wc_temp = (src[2] << 8) + src[3];
      #else
      Tuint wc_temp = src[2] + (src[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
        return false;
      wc = 0x10000 + ((wc - 0xD800) << 10) + (wc_temp - 0xDC00);
      inc_src = 4;
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
      return false;
    else
      inc_src = 2;

    // Convert into the destination buffer.
    if (wc >= 0x100)
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 2;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 8) + src[1];
    #else
    wc = src[0] + (src[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      #if defined(__BIG_ENDIAN__)
      Tuint wc_temp = (src[2] << 8) + src[3];
      #else
      Tuint wc_temp = src[2] + (src[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
        return false;
      wc = 0x10000 + ((wc - 0xD800) << 10) + (wc_temp - 0xDC00);
      inc_src = 4;
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
      return false;
    else
      inc_src = 2;

    // Convert into the destination buffer.
    if (!((wc < 0x10000) && !((wc >= 0xD800) && (wc < 0xE000))))
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 8) + src[1];
    #else
    wc = src[0] + (src[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      #if defined(__BIG_ENDIAN__)
      Tuint wc_temp = (src[2] << 8) + src[3];
      #else
      Tuint wc_temp = src[2] + (src[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
        return false;
      wc = 0x10000 + ((wc - 0xD800) << 10) + (wc_temp - 0xDC00);
      inc_src = 4;
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
      return false;
    else
      inc_src = 2;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 8) + src[1];
    #else
    wc = src[0] + (src[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      #if defined(__BIG_ENDIAN__)
      Tuint wc_temp = (src[2] << 8) + src[3];
      #else
      Tuint wc_temp = src[2] + (src[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
        return false;
      wc = 0x10000 + ((wc - 0xD800) << 10) + (wc_temp - 0xDC00);
      inc_src = 4;
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
      return false;
    else
      inc_src = 2;

    // Convert into the destination buffer.
    if (wc < 0x80)
      inc_dst = 1;
    else if (wc < 0x800)
      inc_dst = 2;
    else if (wc < 0x10000)
      inc_dst = 3;
    else if (wc < 0x200000)
      inc_dst = 4;
    else if (wc < 0x4000000)
      inc_dst = 5;
    else if (wc <= 0x7FFFFFFF)
      inc_dst = 6;
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  IGNORE_UNUSED(a_cpSource);

  a_rResult = a_cCount;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 8) + src[1];
    #else
    wc = src[0] + (src[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      #if defined(__BIG_ENDIAN__)
      Tuint wc_temp = (src[2] << 8) + src[3];
      #else
      Tuint wc_temp = src[2] + (src[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
        return false;
      wc = 0x10000 + ((wc - 0xD800) << 10) + (wc_temp - 0xDC00);
      inc_src = 4;
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
      return false;
    else
      inc_src = 2;

    // Convert into the destination buffer.
    if (!((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000))))
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUCS1Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 1;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
      inc_src = 4;
    else
      return false;

    // Convert into the destination buffer.
    if (wc >= 0x100)
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUCS2Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 2;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
      inc_src = 4;
    else
      return false;

    // Convert into the destination buffer.
    if (!((wc < 0x10000) && !((wc >= 0xD800) && (wc < 0xE000))))
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUCS4Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
      inc_src = 4;
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUTF8Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
      inc_src = 4;
    else
      return false;

    // Convert into the destination buffer.
    if (wc < 0x80)
      inc_dst = 1;
    else if (wc < 0x800)
      inc_dst = 2;
    else if (wc < 0x10000)
      inc_dst = 3;
    else if (wc < 0x200000)
      inc_dst = 4;
    else if (wc < 0x4000000)
      inc_dst = 5;
    else if (wc <= 0x7FFFFFFF)
      inc_dst = 6;
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUTF16Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
      inc_src = 4;
    else
      return false;

    // Convert into the destination buffer.
    if (!((wc >= 0xD800) && (wc < 0xE000)))
    {
      if (wc < 0x10000)
        inc_dst = 2;
      else if (wc < 0x110000)
        inc_dst = 4;
    }
    else
      return false;

    // Take next character.
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUTF32Count(Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  IGNORE_UNUSED(a_cpSource);

  a_rResult = a_cCount;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  a_rResult = a_cCount;
  NMemory::CMemory::copy(a_pDestination, a_cpSource, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 2;
  Tuint inc_src = 1;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    wc = src[0];

    // Convert into the destination buffer.
    if ((wc < 0x10000) && !((wc >= 0xD800) && (wc < 0xE000)))
    {
      #if defined(__BIG_ENDIAN__)
      dst[0] = (Tbyte)(wc >> 8);
      dst[1] = (Tbyte)(wc);
      #else
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      #endif
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 1;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    wc = src[0];

    // Convert into the destination buffer.
    #if defined(__BIG_ENDIAN__)
    dst[0] = (Tbyte)(wc >> 24);
    dst[1] = (Tbyte)(wc >> 16);
    dst[2] = (Tbyte)(wc >> 8);
    dst[3] = (Tbyte)(wc);
    #else
    dst[0] = (Tbyte)(wc);
    dst[1] = (Tbyte)(wc >> 8);
    dst[2] = (Tbyte)(wc >> 16);
    dst[3] = (Tbyte)(wc >> 24);
    #endif

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 1;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    wc = src[0];

    // Convert into the destination buffer.
    if (wc < 0x80)
      inc_dst = 1;
    else if (wc < 0x800)
      inc_dst = 2;
    else if (wc < 0x10000)
      inc_dst = 3;
    else if (wc < 0x200000)
      inc_dst = 4;
    else if (wc < 0x4000000)
      inc_dst = 5;
    else if (wc <= 0x7FFFFFFF)
      inc_dst = 6;
    else
      return false;

    switch (inc_dst)
    {
      case 6: dst[5] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x4000000;
      case 5: dst[4] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x200000;
      case 4: dst[3] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x10000;
      case 3: dst[2] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x800;
      case 2: dst[1] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0xC0;
      case 1: dst[0] = (Tbyte)(wc);
    }

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 1;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    wc = src[0];

    // Convert into the destination buffer.
    if (!((wc >= 0xD800) && (wc < 0xE000)))
    {
      if (wc < 0x10000)
      {
        #if defined(__BIG_ENDIAN__)
        dst[0] = (Tbyte)(wc >> 8);
        dst[1] = (Tbyte)(wc);
        #else
        dst[0] = (Tbyte)(wc);
        dst[1] = (Tbyte)(wc >> 8);
        #endif
        inc_dst = 2;
      }
      else if (wc < 0x110000)
      {
        Tuint wc1 = 0xD800 + ((wc - 0x10000) >> 10);
        Tuint wc2 = 0xDC00 + ((wc - 0x10000) & 0X3FF);
        #if defined(__BIG_ENDIAN__)
        dst[0] = (Tbyte)(wc1 >> 8);
        dst[1] = (Tbyte)(wc1);
        dst[2] = (Tbyte)(wc2 >> 8);
        dst[3] = (Tbyte)(wc2);
        #else
        dst[0] = (Tbyte)(wc1);
        dst[1] = (Tbyte)(wc1 >> 8);
        dst[2] = (Tbyte)(wc2);
        dst[3] = (Tbyte)(wc2 >> 8);
        #endif
        inc_dst = 4;
      }
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS1ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 1;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    wc = src[0];

    // Convert into the destination buffer.
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
    {
      #if defined(__BIG_ENDIAN__)
      dst[0] = 0;
      dst[1] = (Tbyte)(wc >> 16);
      dst[2] = (Tbyte)(wc >> 8);
      dst[3] = (Tbyte)(wc);
      #else
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      dst[2] = (Tbyte)(wc >> 16);
      dst[3] = 0;
      #endif
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 1;
  Tuint inc_src = 2;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    if ((src[0] >= 0xD8) && (src[0] < 0xE0))
      return false;
    wc = (src[0] << 8) + src[1];
    #else
    if ((src[1] >= 0xD8) && (src[1] < 0xE0))
      return false;
    wc = src[0] + (src[1] << 8);
    #endif

    // Convert into the destination buffer.
    if (wc < 0x100)
      dst[0] = (Tbyte)(wc);
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  a_rResult = (a_cCount << 1);
  NMemory::CMemory::copy(a_pDestination, a_cpSource, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 2;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    if ((src[0] >= 0xD8) && (src[0] < 0xE0))
      return false;
    wc = (src[0] << 8) + src[1];
    #else
    if ((src[1] >= 0xD8) && (src[1] < 0xE0))
      return false;
    wc = src[0] + (src[1] << 8);
    #endif

    // Convert into the destination buffer.
    #if defined(__BIG_ENDIAN__)
    dst[0] = (Tbyte)(wc >> 24);
    dst[1] = (Tbyte)(wc >> 16);
    dst[2] = (Tbyte)(wc >> 8);
    dst[3] = (Tbyte)(wc);
    #else
    dst[0] = (Tbyte)(wc);
    dst[1] = (Tbyte)(wc >> 8);
    dst[2] = (Tbyte)(wc >> 16);
    dst[3] = (Tbyte)(wc >> 24);
    #endif

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 2;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    if ((src[0] >= 0xD8) && (src[0] < 0xE0))
      return false;
    wc = (src[0] << 8) + src[1];
    #else
    if ((src[1] >= 0xD8) && (src[1] < 0xE0))
      return false;
    wc = src[0] + (src[1] << 8);
    #endif

    // Convert into the destination buffer.
    if (wc < 0x80)
      inc_dst = 1;
    else if (wc < 0x800)
      inc_dst = 2;
    else if (wc < 0x10000)
      inc_dst = 3;
    else if (wc < 0x200000)
      inc_dst = 4;
    else if (wc < 0x4000000)
      inc_dst = 5;
    else if (wc <= 0x7FFFFFFF)
      inc_dst = 6;
    else
      return false;

    switch (inc_dst)
    {
      case 6: dst[5] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x4000000;
      case 5: dst[4] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x200000;
      case 4: dst[3] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x10000;
      case 3: dst[2] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x800;
      case 2: dst[1] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0xC0;
      case 1: dst[0] = (Tbyte)(wc);
    }

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 2;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    if ((src[0] >= 0xD8) && (src[0] < 0xE0))
      return false;
    wc = (src[0] << 8) + src[1];
    #else
    if ((src[1] >= 0xD8) && (src[1] < 0xE0))
      return false;
    wc = src[0] + (src[1] << 8);
    #endif

    // Convert into the destination buffer.
    if (!((wc >= 0xD800) && (wc < 0xE000)))
    {
      if (wc < 0x10000)
      {
        #if defined(__BIG_ENDIAN__)
        dst[0] = (Tbyte)(wc >> 8);
        dst[1] = (Tbyte)(wc);
        #else
        dst[0] = (Tbyte)(wc);
        dst[1] = (Tbyte)(wc >> 8);
        #endif
        inc_dst = 2;
      }
      else if (wc < 0x110000)
      {
        Tuint wc1 = 0xD800 + ((wc - 0x10000) >> 10);
        Tuint wc2 = 0xDC00 + ((wc - 0x10000) & 0X3FF);
        #if defined(__BIG_ENDIAN__)
        dst[0] = (Tbyte)(wc1 >> 8);
        dst[1] = (Tbyte)(wc1);
        dst[2] = (Tbyte)(wc2 >> 8);
        dst[3] = (Tbyte)(wc2);
        #else
        dst[0] = (Tbyte)(wc1);
        dst[1] = (Tbyte)(wc1 >> 8);
        dst[2] = (Tbyte)(wc2);
        dst[3] = (Tbyte)(wc2 >> 8);
        #endif
        inc_dst = 4;
      }
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS2ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 2;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    if ((src[0] >= 0xD8) && (src[0] < 0xE0))
      return false;
    wc = (src[0] << 8) + src[1];
    #else
    if ((src[1] >= 0xD8) && (src[1] < 0xE0))
      return false;
    wc = src[0] + (src[1] << 8);
    #endif

    // Convert into the destination buffer.
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
    {
      #if defined(__BIG_ENDIAN__)
      dst[0] = 0;
      dst[1] = (Tbyte)(wc >> 16);
      dst[2] = (Tbyte)(wc >> 8);
      dst[3] = (Tbyte)(wc);
      #else
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      dst[2] = (Tbyte)(wc >> 16);
      dst[3] = 0;
      #endif
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 1;
  Tuint inc_src = 4;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif

    // Convert into the destination buffer.
    if (wc < 0x100)
      dst[0] = (Tbyte)(wc);
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 2;
  Tuint inc_src = 4;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif

    // Convert into the destination buffer.
    if ((wc < 0x10000) && !((wc >= 0xD800) && (wc < 0xE000)))
    {
      #if defined(__BIG_ENDIAN__)
      dst[0] = (Tbyte)(wc >> 8);
      dst[1] = (Tbyte)(wc);
      #else
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      #endif
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  a_rResult = (a_cCount << 2);
  NMemory::CMemory::copy(a_pDestination, a_cpSource, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 4;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif

    // Convert into the destination buffer.
    if (wc < 0x80)
      inc_dst = 1;
    else if (wc < 0x800)
      inc_dst = 2;
    else if (wc < 0x10000)
      inc_dst = 3;
    else if (wc < 0x200000)
      inc_dst = 4;
    else if (wc < 0x4000000)
      inc_dst = 5;
    else if (wc <= 0x7FFFFFFF)
      inc_dst = 6;
    else
      return false;

    switch (inc_dst)
    {
      case 6: dst[5] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x4000000;
      case 5: dst[4] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x200000;
      case 4: dst[3] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x10000;
      case 3: dst[2] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x800;
      case 2: dst[1] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0xC0;
      case 1: dst[0] = (Tbyte)(wc);
    }

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 4;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif

    // Convert into the destination buffer.
    if (!((wc >= 0xD800) && (wc < 0xE000)))
    {
      if (wc < 0x10000)
      {
        #if defined(__BIG_ENDIAN__)
        dst[0] = (Tbyte)(wc >> 8);
        dst[1] = (Tbyte)(wc);
        #else
        dst[0] = (Tbyte)(wc);
        dst[1] = (Tbyte)(wc >> 8);
        #endif
        inc_dst = 2;
      }
      else if (wc < 0x110000)
      {
        Tuint wc1 = 0xD800 + ((wc - 0x10000) >> 10);
        Tuint wc2 = 0xDC00 + ((wc - 0x10000) & 0X3FF);
        #if defined(__BIG_ENDIAN__)
        dst[0] = (Tbyte)(wc1 >> 8);
        dst[1] = (Tbyte)(wc1);
        dst[2] = (Tbyte)(wc2 >> 8);
        dst[3] = (Tbyte)(wc2);
        #else
        dst[0] = (Tbyte)(wc1);
        dst[1] = (Tbyte)(wc1 >> 8);
        dst[2] = (Tbyte)(wc2);
        dst[3] = (Tbyte)(wc2 >> 8);
        #endif
        inc_dst = 4;
      }
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UCS4ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 4;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif

    // Convert into the destination buffer.
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
    {
      #if defined(__BIG_ENDIAN__)
      dst[0] = 0;
      dst[1] = (Tbyte)(wc >> 16);
      dst[2] = (Tbyte)(wc >> 8);
      dst[3] = (Tbyte)(wc);
      #else
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      dst[2] = (Tbyte)(wc >> 16);
      dst[3] = 0;
      #endif
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tbyte c;
  Tuint wc;
  Tuint inc_dst = 1;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    c = src[0];
    if (c < 0x80)
    {
      wc = c;
      inc_src = 1;
    }
    else if (c < 0xC2)
      return false;
    else if (c < 0xE0)
    {
      if (!((src[1] ^ 0x80) < 0x40))
        return false;
      wc = ((c & 0x1F) << 6) | (src[1] ^ 0x80);
      inc_src = 2;
    }
    else if (c < 0xF0)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (src[1] >= 0xA0))))
        return false;
      wc = ((c & 0x0F) << 12) | ((src[1] ^ 0x80) << 6) | (src[2] ^ 0x80);
      inc_src = 3;
    }
    else if (c < 0xF8)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (src[1] >= 0x90))))
        return false;
      wc = ((c & 0x07) << 18) | ((src[1] ^ 0x80) << 12) | ((src[2] ^ 0x80) << 6) | (src[3] ^ 0x80);
      inc_src = 4;
    }
    else if (c < 0xFC)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (src[1] >= 0x88))))
        return false;
      wc = ((c & 0x03) << 24) | ((src[1] ^ 0x80) << 18) | ((src[2] ^ 0x80) << 12) | ((src[3] ^ 0x80) << 6) | (src[4] ^ 0x80);
      inc_src = 5;
    }
    else if (c < 0xFE)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((src[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (src[1] >= 0x84))))
        return false;
      wc = ((c & 0x01) << 30) | ((src[1] ^ 0x80) << 24) | ((src[2] ^ 0x80) << 18) | ((src[3] ^ 0x80) << 12) | ((src[4] ^ 0x80) << 6) | (src[5] ^ 0x80);
      inc_src = 6;
    }
    else
      return false;

    // Convert into the destination buffer.
    if (wc < 0x100)
      dst[0] = (Tbyte)(wc);
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tbyte c;
  Tuint wc;
  Tuint inc_dst = 2;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    c = src[0];
    if (c < 0x80)
    {
      wc = c;
      inc_src = 1;
    }
    else if (c < 0xC2)
      return false;
    else if (c < 0xE0)
    {
      if (!((src[1] ^ 0x80) < 0x40))
        return false;
      wc = ((c & 0x1F) << 6) | (src[1] ^ 0x80);
      inc_src = 2;
    }
    else if (c < 0xF0)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (src[1] >= 0xA0))))
        return false;
      wc = ((c & 0x0F) << 12) | ((src[1] ^ 0x80) << 6) | (src[2] ^ 0x80);
      inc_src = 3;
    }
    else if (c < 0xF8)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (src[1] >= 0x90))))
        return false;
      wc = ((c & 0x07) << 18) | ((src[1] ^ 0x80) << 12) | ((src[2] ^ 0x80) << 6) | (src[3] ^ 0x80);
      inc_src = 4;
    }
    else if (c < 0xFC)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (src[1] >= 0x88))))
        return false;
      wc = ((c & 0x03) << 24) | ((src[1] ^ 0x80) << 18) | ((src[2] ^ 0x80) << 12) | ((src[3] ^ 0x80) << 6) | (src[4] ^ 0x80);
      inc_src = 5;
    }
    else if (c < 0xFE)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((src[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (src[1] >= 0x84))))
        return false;
      wc = ((c & 0x01) << 30) | ((src[1] ^ 0x80) << 24) | ((src[2] ^ 0x80) << 18) | ((src[3] ^ 0x80) << 12) | ((src[4] ^ 0x80) << 6) | (src[5] ^ 0x80);
      inc_src = 6;
    }
    else
      return false;

    // Convert into the destination buffer.
    if ((wc < 0x10000) && !((wc >= 0xD800) && (wc < 0xE000)))
    {
      #if defined(__BIG_ENDIAN__)
      dst[0] = (Tbyte)(wc >> 8);
      dst[1] = (Tbyte)(wc);
      #else
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      #endif
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tbyte c;
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    c = src[0];
    if (c < 0x80)
    {
      wc = c;
      inc_src = 1;
    }
    else if (c < 0xC2)
      return false;
    else if (c < 0xE0)
    {
      if (!((src[1] ^ 0x80) < 0x40))
        return false;
      wc = ((c & 0x1F) << 6) | (src[1] ^ 0x80);
      inc_src = 2;
    }
    else if (c < 0xF0)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (src[1] >= 0xA0))))
        return false;
      wc = ((c & 0x0F) << 12) | ((src[1] ^ 0x80) << 6) | (src[2] ^ 0x80);
      inc_src = 3;
    }
    else if (c < 0xF8)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (src[1] >= 0x90))))
        return false;
      wc = ((c & 0x07) << 18) | ((src[1] ^ 0x80) << 12) | ((src[2] ^ 0x80) << 6) | (src[3] ^ 0x80);
      inc_src = 4;
    }
    else if (c < 0xFC)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (src[1] >= 0x88))))
        return false;
      wc = ((c & 0x03) << 24) | ((src[1] ^ 0x80) << 18) | ((src[2] ^ 0x80) << 12) | ((src[3] ^ 0x80) << 6) | (src[4] ^ 0x80);
      inc_src = 5;
    }
    else if (c < 0xFE)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((src[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (src[1] >= 0x84))))
        return false;
      wc = ((c & 0x01) << 30) | ((src[1] ^ 0x80) << 24) | ((src[2] ^ 0x80) << 18) | ((src[3] ^ 0x80) << 12) | ((src[4] ^ 0x80) << 6) | (src[5] ^ 0x80);
      inc_src = 6;
    }
    else
      return false;

    // Convert into the destination buffer.
    #if defined(__BIG_ENDIAN__)
    dst[0] = (Tbyte)(wc >> 24);
    dst[1] = (Tbyte)(wc >> 16);
    dst[2] = (Tbyte)(wc >> 8);
    dst[3] = (Tbyte)(wc);
    #else
    dst[0] = (Tbyte)(wc);
    dst[1] = (Tbyte)(wc >> 8);
    dst[2] = (Tbyte)(wc >> 16);
    dst[3] = (Tbyte)(wc >> 24);
    #endif

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  a_rResult = a_cCount;
  NMemory::CMemory::copy(a_pDestination, a_cpSource, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tbyte c;
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    c = src[0];
    if (c < 0x80)
    {
      wc = c;
      inc_src = 1;
    }
    else if (c < 0xC2)
      return false;
    else if (c < 0xE0)
    {
      if (!((src[1] ^ 0x80) < 0x40))
        return false;
      wc = ((c & 0x1F) << 6) | (src[1] ^ 0x80);
      inc_src = 2;
    }
    else if (c < 0xF0)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (src[1] >= 0xA0))))
        return false;
      wc = ((c & 0x0F) << 12) | ((src[1] ^ 0x80) << 6) | (src[2] ^ 0x80);
      inc_src = 3;
    }
    else if (c < 0xF8)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (src[1] >= 0x90))))
        return false;
      wc = ((c & 0x07) << 18) | ((src[1] ^ 0x80) << 12) | ((src[2] ^ 0x80) << 6) | (src[3] ^ 0x80);
      inc_src = 4;
    }
    else if (c < 0xFC)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (src[1] >= 0x88))))
        return false;
      wc = ((c & 0x03) << 24) | ((src[1] ^ 0x80) << 18) | ((src[2] ^ 0x80) << 12) | ((src[3] ^ 0x80) << 6) | (src[4] ^ 0x80);
      inc_src = 5;
    }
    else if (c < 0xFE)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((src[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (src[1] >= 0x84))))
        return false;
      wc = ((c & 0x01) << 30) | ((src[1] ^ 0x80) << 24) | ((src[2] ^ 0x80) << 18) | ((src[3] ^ 0x80) << 12) | ((src[4] ^ 0x80) << 6) | (src[5] ^ 0x80);
      inc_src = 6;
    }
    else
      return false;

    // Convert into the destination buffer.
    if (!((wc >= 0xD800) && (wc < 0xE000)))
    {
      if (wc < 0x10000)
      {
        #if defined(__BIG_ENDIAN__)
        dst[0] = (Tbyte)(wc >> 8);
        dst[1] = (Tbyte)(wc);
        #else
        dst[0] = (Tbyte)(wc);
        dst[1] = (Tbyte)(wc >> 8);
        #endif
        inc_dst = 2;
      }
      else if (wc < 0x110000)
      {
        Tuint wc1 = 0xD800 + ((wc - 0x10000) >> 10);
        Tuint wc2 = 0xDC00 + ((wc - 0x10000) & 0X3FF);
        #if defined(__BIG_ENDIAN__)
        dst[0] = (Tbyte)(wc1 >> 8);
        dst[1] = (Tbyte)(wc1);
        dst[2] = (Tbyte)(wc2 >> 8);
        dst[3] = (Tbyte)(wc2);
        #else
        dst[0] = (Tbyte)(wc1);
        dst[1] = (Tbyte)(wc1 >> 8);
        dst[2] = (Tbyte)(wc2);
        dst[3] = (Tbyte)(wc2 >> 8);
        #endif
        inc_dst = 4;
      }
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF8ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tbyte c;
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    c = src[0];
    if (c < 0x80)
    {
      wc = c;
      inc_src = 1;
    }
    else if (c < 0xC2)
      return false;
    else if (c < 0xE0)
    {
      if (!((src[1] ^ 0x80) < 0x40))
        return false;
      wc = ((c & 0x1F) << 6) | (src[1] ^ 0x80);
      inc_src = 2;
    }
    else if (c < 0xF0)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((c >= 0xE1) || (src[1] >= 0xA0))))
        return false;
      wc = ((c & 0x0F) << 12) | ((src[1] ^ 0x80) << 6) | (src[2] ^ 0x80);
      inc_src = 3;
    }
    else if (c < 0xF8)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((c >= 0xF1) || (src[1] >= 0x90))))
        return false;
      wc = ((c & 0x07) << 18) | ((src[1] ^ 0x80) << 12) | ((src[2] ^ 0x80) << 6) | (src[3] ^ 0x80);
      inc_src = 4;
    }
    else if (c < 0xFC)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((c >= 0xF9) || (src[1] >= 0x88))))
        return false;
      wc = ((c & 0x03) << 24) | ((src[1] ^ 0x80) << 18) | ((src[2] ^ 0x80) << 12) | ((src[3] ^ 0x80) << 6) | (src[4] ^ 0x80);
      inc_src = 5;
    }
    else if (c < 0xFE)
    {
      if (!(((src[1] ^ 0x80) < 0x40) && ((src[2] ^ 0x80) < 0x40) && ((src[3] ^ 0x80) < 0x40) && ((src[4] ^ 0x80) < 0x40) && ((src[5] ^ 0x80) < 0x40) && ((c >= 0xFD) || (src[1] >= 0x84))))
        return false;
      wc = ((c & 0x01) << 30) | ((src[1] ^ 0x80) << 24) | ((src[2] ^ 0x80) << 18) | ((src[3] ^ 0x80) << 12) | ((src[4] ^ 0x80) << 6) | (src[5] ^ 0x80);
      inc_src = 6;
    }
    else
      return false;

    // Convert into the destination buffer.
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
    {
      #if defined(__BIG_ENDIAN__)
      dst[0] = 0;
      dst[1] = (Tbyte)(wc >> 16);
      dst[2] = (Tbyte)(wc >> 8);
      dst[3] = (Tbyte)(wc);
      #else
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      dst[2] = (Tbyte)(wc >> 16);
      dst[3] = 0;
      #endif
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 1;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 8) + src[1];
    #else
    wc = src[0] + (src[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      #if defined(__BIG_ENDIAN__)
      Tuint wc_temp = (src[2] << 8) + src[3];
      #else
      Tuint wc_temp = src[2] + (src[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
        return false;
      wc = 0x10000 + ((wc - 0xD800) << 10) + (wc_temp - 0xDC00);
      inc_src = 4;
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
      return false;
    else
      inc_src = 2;

    // Convert into the destination buffer.
    if (wc < 0x100)
      dst[0] = (Tbyte)(wc);
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 2;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 8) + src[1];
    #else
    wc = src[0] + (src[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      #if defined(__BIG_ENDIAN__)
      Tuint wc_temp = (src[2] << 8) + src[3];
      #else
      Tuint wc_temp = src[2] + (src[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
        return false;
      wc = 0x10000 + ((wc - 0xD800) << 10) + (wc_temp - 0xDC00);
      inc_src = 4;
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
      return false;
    else
      inc_src = 2;

    // Convert into the destination buffer.
    if ((wc < 0x10000) && !((wc >= 0xD800) && (wc < 0xE000)))
    {
      #if defined(__BIG_ENDIAN__)
      dst[0] = (Tbyte)(wc >> 8);
      dst[1] = (Tbyte)(wc);
      #else
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      #endif
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 8) + src[1];
    #else
    wc = src[0] + (src[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      #if defined(__BIG_ENDIAN__)
      Tuint wc_temp = (src[2] << 8) + src[3];
      #else
      Tuint wc_temp = src[2] + (src[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
        return false;
      wc = 0x10000 + ((wc - 0xD800) << 10) + (wc_temp - 0xDC00);
      inc_src = 4;
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
      return false;
    else
      inc_src = 2;

    // Convert into the destination buffer.
    #if defined(__BIG_ENDIAN__)
    dst[0] = (Tbyte)(wc >> 24);
    dst[1] = (Tbyte)(wc >> 16);
    dst[2] = (Tbyte)(wc >> 8);
    dst[3] = (Tbyte)(wc);
    #else
    dst[0] = (Tbyte)(wc);
    dst[1] = (Tbyte)(wc >> 8);
    dst[2] = (Tbyte)(wc >> 16);
    dst[3] = (Tbyte)(wc >> 24);
    #endif

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 8) + src[1];
    #else
    wc = src[0] + (src[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      #if defined(__BIG_ENDIAN__)
      Tuint wc_temp = (src[2] << 8) + src[3];
      #else
      Tuint wc_temp = src[2] + (src[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
        return false;
      wc = 0x10000 + ((wc - 0xD800) << 10) + (wc_temp - 0xDC00);
      inc_src = 4;
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
      return false;
    else
      inc_src = 2;

    // Convert into the destination buffer.
    if (wc < 0x80)
      inc_dst = 1;
    else if (wc < 0x800)
      inc_dst = 2;
    else if (wc < 0x10000)
      inc_dst = 3;
    else if (wc < 0x200000)
      inc_dst = 4;
    else if (wc < 0x4000000)
      inc_dst = 5;
    else if (wc <= 0x7FFFFFFF)
      inc_dst = 6;
    else
      return false;

    switch (inc_dst)
    {
      case 6: dst[5] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x4000000;
      case 5: dst[4] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x200000;
      case 4: dst[3] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x10000;
      case 3: dst[2] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x800;
      case 2: dst[1] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0xC0;
      case 1: dst[0] = (Tbyte)(wc);
    }

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  a_rResult = (a_cCount << 1);
  NMemory::CMemory::copy(a_pDestination, a_cpSource, a_rResult);
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF16ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 8) + src[1];
    #else
    wc = src[0] + (src[1] << 8);
    #endif
    if ((wc >= 0xD800) && (wc < 0xDC00))
    {
      #if defined(__BIG_ENDIAN__)
      Tuint wc_temp = (src[2] << 8) + src[3];
      #else
      Tuint wc_temp = src[2] + (src[3] << 8);
      #endif
      if (!((wc_temp >= 0xDC00) && (wc_temp < 0xE000)))
        return false;
      wc = 0x10000 + ((wc - 0xD800) << 10) + (wc_temp - 0xDC00);
      inc_src = 4;
    }
    else if ((wc >= 0xDC00) && (wc < 0xE000))
      return false;
    else
      inc_src = 2;

    // Convert into the destination buffer.
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
    {
      #if defined(__BIG_ENDIAN__)
      dst[0] = 0;
      dst[1] = (Tbyte)(wc >> 16);
      dst[2] = (Tbyte)(wc >> 8);
      dst[3] = (Tbyte)(wc);
      #else
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      dst[2] = (Tbyte)(wc >> 16);
      dst[3] = 0;
      #endif
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUCS1(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 1;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
      inc_src = 4;
    else
      return false;

    // Convert into the destination buffer.
    if (wc < 0x100)
      dst[0] = (Tbyte)(wc);
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUCS2(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 2;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
      inc_src = 4;
    else
      return false;

    // Convert into the destination buffer.
    if ((wc < 0x10000) && !((wc >= 0xD800) && (wc < 0xE000)))
    {
      #if defined(__BIG_ENDIAN__)
      dst[0] = (Tbyte)(wc >> 8);
      dst[1] = (Tbyte)(wc);
      #else
      dst[0] = (Tbyte)(wc);
      dst[1] = (Tbyte)(wc >> 8);
      #endif
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUCS4(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 4;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
      inc_src = 4;
    else
      return false;

    // Convert into the destination buffer.
    #if defined(__BIG_ENDIAN__)
    dst[0] = (Tbyte)(wc >> 24);
    dst[1] = (Tbyte)(wc >> 16);
    dst[2] = (Tbyte)(wc >> 8);
    dst[3] = (Tbyte)(wc);
    #else
    dst[0] = (Tbyte)(wc);
    dst[1] = (Tbyte)(wc >> 8);
    dst[2] = (Tbyte)(wc >> 16);
    dst[3] = (Tbyte)(wc >> 24);
    #endif

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUTF8(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
      inc_src = 4;
    else
      return false;

    // Convert into the destination buffer.
    if (wc < 0x80)
      inc_dst = 1;
    else if (wc < 0x800)
      inc_dst = 2;
    else if (wc < 0x10000)
      inc_dst = 3;
    else if (wc < 0x200000)
      inc_dst = 4;
    else if (wc < 0x4000000)
      inc_dst = 5;
    else if (wc <= 0x7FFFFFFF)
      inc_dst = 6;
    else
      return false;

    switch (inc_dst)
    {
      case 6: dst[5] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x4000000;
      case 5: dst[4] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x200000;
      case 4: dst[3] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x10000;
      case 3: dst[2] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0x800;
      case 2: dst[1] = (Tbyte)(0x80 | (wc & 0x3F)); wc = wc >> 6; wc |= 0xC0;
      case 1: dst[0] = (Tbyte)(wc);
    }

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUTF16(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  Tuint wc;
  Tuint inc_dst = 0;
  Tuint inc_src = 0;
  Tuint count = a_cCount;
  Tbuffer dst = (Tbuffer)a_pDestination;
  Tcbuffer src = (Tcbuffer)a_cpSource;

  a_rResult = 0;
  while (count-- > 0)
  {
    // Convert from the source buffer.
    #if defined(__BIG_ENDIAN__)
    wc = (src[0] << 24) + (src[1] << 16) + (src[2] << 8) + src[3];
    #else
    wc = src[0] + (src[1] << 8) + (src[2] << 16) + (src[3] << 24);
    #endif
    if ((wc < 0x110000) && !((wc >= 0xD800) && (wc < 0xE000)))
      inc_src = 4;
    else
      return false;

    // Convert into the destination buffer.
    if (!((wc >= 0xD800) && (wc < 0xE000)))
    {
      if (wc < 0x10000)
      {
        #if defined(__BIG_ENDIAN__)
        dst[0] = (Tbyte)(wc >> 8);
        dst[1] = (Tbyte)(wc);
        #else
        dst[0] = (Tbyte)(wc);
        dst[1] = (Tbyte)(wc >> 8);
        #endif
        inc_dst = 2;
      }
      else if (wc < 0x110000)
      {
        Tuint wc1 = 0xD800 + ((wc - 0x10000) >> 10);
        Tuint wc2 = 0xDC00 + ((wc - 0x10000) & 0X3FF);
        #if defined(__BIG_ENDIAN__)
        dst[0] = (Tbyte)(wc1 >> 8);
        dst[1] = (Tbyte)(wc1);
        dst[2] = (Tbyte)(wc2 >> 8);
        dst[3] = (Tbyte)(wc2);
        #else
        dst[0] = (Tbyte)(wc1);
        dst[1] = (Tbyte)(wc1 >> 8);
        dst[2] = (Tbyte)(wc2);
        dst[3] = (Tbyte)(wc2 >> 8);
        #endif
        inc_dst = 4;
      }
    }
    else
      return false;

    // Take next character.
    dst += inc_dst;
    src += inc_src;
    a_rResult += inc_dst;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemStringHelper::UTF32ToUTF32(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cCount, Tuint& a_rResult)
{ CALL
  a_rResult = (a_cCount << 2);
  NMemory::CMemory::copy(a_pDestination, a_cpSource, a_rResult);
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
