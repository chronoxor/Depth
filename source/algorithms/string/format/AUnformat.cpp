/*!
 *  \file    AUnformat.cpp Contains string unformat algorithm.
 *  \brief   String unformat algorithm (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.09.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: String unformat algorithm (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String format algorithms
    VERSION:   1.0
    CREATED:   29.09.2008 00:45:38

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
#include <Depth/include/algorithms/string/format/AUnformat.hpp>
#include <Depth/include/stream/text/CStreamString.hpp>
/*==========================================================================*/
#ifndef __AUNFORMAT_CPP__
#define __AUNFORMAT_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NFormat {
/*==========================================================================*/
/* ALGORITHM IMPLEMENTATIONS                                                */
/*==========================================================================*/
BASE_API Tbool unformat(const NDepth::NString::CStringASCII& a_crSourceString, const Tcsstr a_cpFormatString, ...)
{ CALL
  Tbool result = false;
  va_list variable_list;
  NStream::NText::CStreamStringASCII stream(a_crSourceString);

  va_start(variable_list, a_cpFormatString);
  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  result = stream.readFormatVarList(a_cpFormatString, variable_list).getFirst();
  if (!stream.close())
    return result;
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool unformatVarList(const NDepth::NString::CStringASCII& a_crSourceString, const Tcsstr a_cpFormatString, va_list a_VariableList)
{ CALL
  Tbool result = false;
  NStream::NText::CStreamStringASCII stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  result = stream.readFormatVarList(a_cpFormatString, a_VariableList).getFirst();
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool unformat(const NDepth::NString::CStringUnicode& a_crSourceString, const Tcwstr a_cpFormatString, ...)
{ CALL
  Tbool result = false;
  va_list variable_list;
  NStream::NText::CStreamStringUnicode stream(a_crSourceString);

  va_start(variable_list, a_cpFormatString);
  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  result = stream.readFormatVarList(a_cpFormatString, variable_list).getFirst();
  if (!stream.close())
    return result;
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool unformatVarList(const NDepth::NString::CStringUnicode& a_crSourceString, const Tcwstr a_cpFormatString, va_list a_VariableList)
{ CALL
  Tbool result = false;
  NStream::NText::CStreamStringUnicode stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  result = stream.readFormatVarList(a_cpFormatString, a_VariableList).getFirst();
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool unformat(const NDepth::NString::CStringASCII& a_crSourceString, const NDepth::NString::CStringASCII* a_cpFormatString, ...)
{ CALL
  // Check the given format string not to be NULL.
  ASSERT((a_cpFormatString != NULL), STR("Format string cannot be NULL."))
  {
    return false;
  }

  Tbool result = false;
  va_list variable_list;
  NStream::NText::CStreamStringASCII stream(a_crSourceString);

  va_start(variable_list, a_cpFormatString);
  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  result = stream.readFormatVarList(*a_cpFormatString, variable_list).getFirst();
  if (!stream.close())
    return result;
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool unformatVarList(const NDepth::NString::CStringASCII& a_crSourceString, const NDepth::NString::CStringASCII& a_crFormatString, va_list a_VariableList)
{ CALL
  Tbool result = false;
  NStream::NText::CStreamStringASCII stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  result = stream.readFormatVarList(a_crFormatString, a_VariableList).getFirst();
  if (!stream.close())
    return result;

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool unformat(const NDepth::NString::CStringUnicode& a_crSourceString, const NDepth::NString::CStringUnicode* a_cpFormatString, ...)
{ CALL
  // Check the given format string not to be NULL.
  ASSERT((a_cpFormatString != NULL), STR("Format string cannot be NULL."))
  {
    return false;
  }

  Tbool result = false;
  va_list variable_list;
  NStream::NText::CStreamStringUnicode stream(a_crSourceString);

  va_start(variable_list, a_cpFormatString);
  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  result = stream.readFormatVarList(*a_cpFormatString, variable_list).getFirst();
  if (!stream.close())
    return result;
  va_end(variable_list);

  return result;
}
/*--------------------------------------------------------------------------*/
BASE_API Tbool unformatVarList(const NDepth::NString::CStringUnicode& a_crSourceString, const NDepth::NString::CStringUnicode& a_crFormatString, va_list a_VariableList)
{ CALL
  Tbool result = false;
  NStream::NText::CStreamStringUnicode stream(a_crSourceString);

  if (!stream.open(NStream::IStream::e_OPEN_READ))
    return result;
  result = stream.readFormatVarList(a_crFormatString, a_VariableList).getFirst();
  if (!stream.close())
    return result;

  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
