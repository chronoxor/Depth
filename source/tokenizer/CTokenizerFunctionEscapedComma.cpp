/*!
 *  \file    CTokenizerFunctionEscapedComma.cpp Escaped comma separated
 *           tokenizer function uses rules to parse tokens of the CSV
 *           (comma separated value) formats.
 *  \brief   Escaped comma separated tokenizer function class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Escaped comma separated tokenizer function class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   24.04.2009 23:41:14

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
#include <Depth/include/algorithms/string/AFindChar.hpp>
#include <Depth/include/stream/IStream.hpp>
#include <Depth/include/tokenizer/CTokenizerFunctionEscapedComma.hpp>
/*==========================================================================*/
#ifndef __CTOKENIZERFUNCTIONESCAPEDCOMMA_CPP__
#define __CTOKENIZERFUNCTIONESCAPEDCOMMA_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CTokenizerFunctionEscapedComma::CTokenizerFunctionEscapedComma(const Tchar a_cEscape/* = STR('\\') */, const Tchar a_cComma/* = STR(',') */, const Tchar a_cQuote/* = STR('"') */) :
  ITokenizerFunction(),
  m_Escape(a_cEscape),
  m_Comma(a_cComma),
  m_Quote(a_cQuote),
  m_IsEqualQuotesRequired(true),
  m_TokenReturned(false)
{ CALL

}
/*--------------------------------------------------------------------------*/
CTokenizerFunctionEscapedComma::CTokenizerFunctionEscapedComma(const NString::CString& a_crEscape, const NString::CString& a_crComma, const NString::CString& a_crQuote, const Tbool a_cIsEqualQuotesRequired/* = true */) :
  ITokenizerFunction(),
  m_Escape(a_crEscape),
  m_Comma(a_crComma),
  m_Quote(a_crQuote),
  m_IsEqualQuotesRequired(a_cIsEqualQuotesRequired),
  m_TokenReturned(false)
{ CALL

}
/*--------------------------------------------------------------------------*/
CTokenizerFunctionEscapedComma::CTokenizerFunctionEscapedComma(const CTokenizerFunctionEscapedComma& a_crInstance) :
  ITokenizerFunction(),
  m_Escape(a_crInstance.m_Escape),
  m_Comma(a_crInstance.m_Comma),
  m_Quote(a_crInstance.m_Quote),
  m_IsEqualQuotesRequired(a_crInstance.m_IsEqualQuotesRequired),
  m_TokenReturned(false)
{ CALL

}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionEscapedComma::set(const Tchar a_cEscape/* = STR('\\') */, const Tchar a_cComma/* = STR(',') */, const Tchar a_cQuote/* = STR('"') */)
{ CALL
  if (!m_Escape.set(a_cEscape))
    return false;
  if (!m_Comma.set(a_cComma))
    return false;
  if (!m_Quote.set(a_cQuote))
    return false;
  m_IsEqualQuotesRequired = true;
  return reset();
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionEscapedComma::set(const NString::CString& a_crEscape, const NString::CString& a_crComma, const NString::CString& a_crQuote, const Tbool a_cIsEqualQuotesRequired/* = true */)
{ CALL
  if (!m_Escape.set(a_crEscape))
    return false;
  if (!m_Comma.set(a_crComma))
    return false;
  if (!m_Quote.set(a_crQuote))
    return false;
  m_IsEqualQuotesRequired = a_cIsEqualQuotesRequired;
  return reset();
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionEscapedComma::set(const CTokenizerFunctionEscapedComma& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CTokenizerFunctionEscapedComma class instance."))
  {
    return false;
  }

  if (!m_Escape.set(a_crInstance.m_Escape))
    return false;
  if (!m_Comma.set(a_crInstance.m_Comma))
    return false;
  if (!m_Quote.set(a_crInstance.m_Quote))
    return false;
  m_IsEqualQuotesRequired = a_crInstance.m_IsEqualQuotesRequired;
  return reset();
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionEscapedComma::getNextToken(NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult)
{ CALL
  // Check if the given input iterator is in valid state.
  ASSERT(a_rInputIterator.isValid(), STR("Cannot get next token from the invalid input iterator."))
  {
    return false;
  }

  // Clear result string.
  if (!a_rResult.clear())
    return false;

  // We met end of input stream, therefore we stop the tokenize process.
  if (a_rIsEndOfStream)
  {
    if (m_TokenReturned)
    {
      // Return the last empty token.
      m_TokenReturned = false;
      return true;
    }
    else
      return false;
  }

  Tchar quote = 0;
  Tbool quoting = false;

  m_TokenReturned = false;
  while (!a_rIsEndOfStream)
  {
    Tuint temp = 0;

    // Perform escape operation.
    if (NAlgorithms::NString::findChar(false, false, temp, m_Escape, a_rInputIterator.getValueRef()))
    {
      // Do we met end of input stream?
      if (a_rInputIterator.stepForward() == 0)
      {
        a_rIsEndOfStream = true;

        // Append current character to the token.
        if (a_rInputIterator.isValid() && !a_rResult.insertLast((NString::CString::TType)a_rInputIterator.getValueRef()))
          return false;

        return true;
      }

      if (a_rInputIterator.getValueRef() == STR('n'))
      {
        // Append new line symbol.
        if (!a_rResult.insertLast(NStream::IStream::getSystemLineEndingString()))
          return false;
      }
      else
      {
        // Append current character to the token.
        if (!a_rResult.insertLast((NString::CString::TType)a_rInputIterator.getValueRef()))
          return false;
      }
    }
    // Perform comma operation.
    else if (NAlgorithms::NString::findChar(false, false, temp, m_Comma, a_rInputIterator.getValueRef()))
    {
      // If parsing is not inside the quote area then stop and return current token.
      if (!quoting)
      {
        // Do we met end of input stream?
        if (a_rInputIterator.stepForward() == 0)
          a_rIsEndOfStream = true;

        m_TokenReturned = true;
        return true;
      }
      else
      {
        // If we inside the quote area then append current character to the token.
        if (!a_rResult.insertLast((NString::CString::TType)a_rInputIterator.getValueRef()))
          return false;
      }
    }
    // Perform quote operation.
    else if (NAlgorithms::NString::findChar(false, false, temp, m_Quote, a_rInputIterator.getValueRef()) && (!quoting || !m_IsEqualQuotesRequired || (quote == (Tchar)a_rInputIterator.getValueRef())))
    {
      quote = (Tchar)a_rInputIterator.getValueRef();
      quoting = !quoting;
    }
    else
    {
      // Append current character to the token.
      if (!a_rResult.insertLast((NString::CString::TType)a_rInputIterator.getValueRef()))
        return false;
    }

    // Do we met end of input stream?
    if (a_rInputIterator.stepForward() == 0)
    {
      a_rIsEndOfStream = true;
      break;
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
ITokenizerFunction* CTokenizerFunctionEscapedComma::clone() const
{ CALL
  ITokenizerFunction* result = newex CTokenizerFunctionEscapedComma(*this);

  if (result == NULL)
    WARNING(STR("Cannot create a new character delimiters tokenizer function instance (requested size is %u bytes).") COMMA (sizeof(CTokenizerFunctionEscapedComma)));
  return result;
}
/*--------------------------------------------------------------------------*/
void CTokenizerFunctionEscapedComma::swap(CTokenizerFunctionEscapedComma& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Escape, a_rInstance.m_Escape);
  NAlgorithms::NCommon::swap(m_Comma, a_rInstance.m_Comma);
  NAlgorithms::NCommon::swap(m_Quote, a_rInstance.m_Quote);
  NAlgorithms::NCommon::swap(m_IsEqualQuotesRequired, a_rInstance.m_IsEqualQuotesRequired);
  NAlgorithms::NCommon::swap(m_TokenReturned, a_rInstance.m_TokenReturned);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
