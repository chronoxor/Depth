/*!
 *  \file    CTokenizerFunctionOffsetDelimiters.cpp Offset delimiters
 *           tokenizer function uses a list of the offset indexes to
 *           split the input stream into tokens.
 *  \brief   Offset delimiters tokenizer function class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Offset delimiters tokenizer function class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   24.04.2009 03:23:11

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
#include <Depth/include/tokenizer.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/tokenizer/CTokenizerFunctionOffsetDelimiters.hpp>
/*==========================================================================*/
#ifndef __CTOKENIZERFUNCTIONOFFSETDELIMITERS_CPP__
#define __CTOKENIZERFUNCTIONOFFSETDELIMITERS_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CTokenizerFunctionOffsetDelimiters::set(const CTokenizerFunctionOffsetDelimiters& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CTokenizerFunctionOffsetDelimiters class instance."))
  {
    return false;
  }

  // Clear old offsets values.
  if (!m_Offsets.clear())
    return false;

  // Insert new offset values.
  if (!m_Offsets.set(a_crInstance.m_Offsets))
    return false;

  m_WrapOffsets = a_crInstance.m_WrapOffsets;
  m_ReturnLastPartially = a_crInstance.m_ReturnLastPartially;
  return reset();
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionOffsetDelimiters::getNextToken(NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult)
{ CALL
  // Check if the given input iterator is in valid state.
  ASSERT(a_rInputIterator.isValid(), STR("Cannot get next token from the invalid input iterator."))
  {
    return false;
  }
  // Check if the current offset array is not empty.
  ASSERT(!m_Offsets.isEmpty(), STR("Offset delimiters tokenizer function should be properly initialized."))
  {
    return false;
  }

  // Clear result string.
  if (!a_rResult.clear())
    return false;

  // We met end of input stream, therefore we stop the tokenize process.
  if (a_rIsEndOfStream)
    return false;

  // Check if we have to wrap offsets.
  if (m_CurrentOffset == m_Offsets.getSize())
  {
    if (m_WrapOffsets)
      m_CurrentOffset = 0;
    else
      return false;
  }

  Tuint i = 0;
  Tuint offset = m_Offsets[m_CurrentOffset];
  while (i < offset)
  {
    if (!a_rResult.insertLast((NString::CString::TType)a_rInputIterator.getValueRef()))
      return false;

    // Do we met end of input stream?
    if (a_rInputIterator.stepForward() == 0)
    {
       a_rIsEndOfStream = true;
       break;
    }
    ++i;
  }

  // Check if we have to return last partially parsed token.
  if (!m_ReturnLastPartially)
    if (i < (offset - 1))
      return false;

  ++m_CurrentOffset;
  return true;
}
/*--------------------------------------------------------------------------*/
ITokenizerFunction* CTokenizerFunctionOffsetDelimiters::clone() const
{ CALL
  ITokenizerFunction* result = newex CTokenizerFunctionOffsetDelimiters(*this);

  if (result == NULL)
    WARNING(STR("Cannot create a new character delimiters tokenizer function instance (requested size is %u bytes).") COMMA (sizeof(CTokenizerFunctionOffsetDelimiters)));
  return result;
}
/*--------------------------------------------------------------------------*/
void CTokenizerFunctionOffsetDelimiters::swap(CTokenizerFunctionOffsetDelimiters& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Offsets, a_rInstance.m_Offsets);
  NAlgorithms::NCommon::swap(m_CurrentOffset, a_rInstance.m_CurrentOffset);
  NAlgorithms::NCommon::swap(m_WrapOffsets, a_rInstance.m_WrapOffsets);
  NAlgorithms::NCommon::swap(m_ReturnLastPartially, a_rInstance.m_ReturnLastPartially);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
