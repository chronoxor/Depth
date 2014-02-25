/*!
 *  \file    CTokenizerFunctionUCDParser.cpp Tokenizer function of the UCD
 *           parser.
 *  \brief   UCD parser tokenizer function class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: UCD parser tokenizer function class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      UCD parser utility
    VERSION:   1.0
    CREATED:   07.05.2009 00:35:23

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
#ifndef __CTOKENIZERFUNCTIONUCDPARSER_CPP__
#define __CTOKENIZERFUNCTIONUCDPARSER_CPP__
/*==========================================================================*/
#include "CTokenizerFunctionUCDParser.hpp"
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtilities {
/*--------------------------------------------------------------------------*/
namespace NUCDParser {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CTokenizerFunctionUCDParser::CTokenizerFunctionUCDParser(const Tbool a_cSkipComments/* = true */) :
  NTokenizer::CTokenizerFunctionCharDelimiters(NString::CString(STR(";\n")), NString::CString::EMPTY, true),
  m_SkipComments(a_cSkipComments)
{ CALL

}
/*--------------------------------------------------------------------------*/
CTokenizerFunctionUCDParser::CTokenizerFunctionUCDParser(const CTokenizerFunctionUCDParser& a_crInstance) :
  NTokenizer::CTokenizerFunctionCharDelimiters(a_crInstance),
  m_SkipComments(a_crInstance.m_SkipComments)
{ CALL

}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionUCDParser::set(const Tbool a_cSkipComments/* = true */)
{ CALL
  m_SkipComments = a_cSkipComments;
  return reset();
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionUCDParser::set(const CTokenizerFunctionUCDParser& a_crInstance)
{ CALL
  m_SkipComments = a_crInstance.m_SkipComments;
  return NTokenizer::CTokenizerFunctionCharDelimiters::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionUCDParser::getNextToken(NTokenizer::NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult)
{ CALL
  // Check if the given input iterator is in valid state.
  ASSERT(a_rInputIterator.isValid(), STR("Cannot get next token from the invalid input iterator."))
  {
    return false;
  }

  // Clear result string.
  if (!a_rResult.clear())
    return false;

  Tbool stop = false;
  while (!stop)
  {
    // Skip line end characters.
    if (!skipToLineEnd(a_rInputIterator, a_rIsEndOfStream, false))
      return false;

    // Get next token.
    if (NTokenizer::CTokenizerFunctionCharDelimiters::getNextToken(a_rInputIterator, a_rIsEndOfStream, a_rResult))
    {
      // If the token is a single space, then take the next one.
      if (a_rResult == NString::CString(STR(' ')))
        continue;

      // If the token is a comment, then take the next one.
      if (!a_rResult.isEmpty() && (a_rResult[CONSTU(0)] == STR('#')))
      {
        if (m_SkipComments)
        {
          // Skip comments.
          if (!skipToLineEnd(a_rInputIterator, a_rIsEndOfStream, true))
            return false;
          continue;
        }
        else
        {
          // Check for end of stream.
          if (a_rIsEndOfStream)
            return false;

          // Append remain comment characters.
          while (a_rInputIterator.getValueRef() != STR('\n'))
          {
            if (!a_rResult.insertLast((NString::CString::TType)a_rInputIterator.getValueRef()))
              return false;

            // Do we met the end of the input stream?
            if (a_rInputIterator.stepForward() == 0)
            {
              a_rIsEndOfStream = true;
              return false;
            }
          }

          // Do we met the end of the input stream?
          if (a_rInputIterator.stepForward() == 0)
          {
            a_rIsEndOfStream = true;
            return false;
          }

          // Return comment.
          return true;
        }
      }

      // If the token has a comment, then remove it.
      if (m_SkipComments)
      {
        for (Tuint index = 0; index < a_rResult.getSize(); ++index)
        {
          if (a_rResult[index] == STR('#'))
          {
            a_rResult = a_rResult.getLeft(index);

            // Skip rest comments.
            skipToLineEnd(a_rInputIterator, a_rIsEndOfStream, true);

            break;
          }
        }
      }

      // Trim start and end spaces.
      while (!a_rResult.isEmpty() && (a_rResult[CONSTU(0)] == STR(' ')))
        if (!a_rResult.removeFirst())
          return false;
      while (!a_rResult.isEmpty() && (a_rResult[a_rResult.getSize() - 1] == STR(' ')))
        if (!a_rResult.removeLast())
          return false;

      // Return the current token.
      return true;
    }
    else
      return false;
  }
  // Never falls here...
  return false;
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionUCDParser::skipToLineEnd(NTokenizer::NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, const Tbool a_cForceSkip)
{ CALL
  // Check for end of stream.
  if (a_rIsEndOfStream)
    return false;

  // Check for comments.
  Tbool skip = a_cForceSkip;
  while (skip || (a_rInputIterator.getValueRef() == STR('\r')) || (a_rInputIterator.getValueRef() == STR('\n')))
  {
    // Skip through all characters until the line end.
    while (a_rInputIterator.getValueRef() != STR('\n'))
    {
      // Do we met the end of the input stream?
      if (a_rInputIterator.stepForward() == 0)
      {
        a_rIsEndOfStream = true;
        return false;
      }
    }

    // Reset the skip flag.
    if (a_rInputIterator.getValueRef() == STR('\n'))
      skip = false;

    // Do we met the end of the input stream?
    if (a_rInputIterator.stepForward() == 0)
    {
      a_rIsEndOfStream = true;
      return false;
    }
  }
  return true;
}
/*--------------------------------------------------------------------------*/
NTokenizer::ITokenizerFunction* CTokenizerFunctionUCDParser::clone() const
{ CALL
  ITokenizerFunction* result = newex CTokenizerFunctionUCDParser(*this);

  if (result == NULL)
    WARNING(STR("Cannot create a new UCD parser tokenizer function instance (requested size is %u bytes).") COMMA (sizeof(CTokenizerFunctionUCDParser)));
  return result;
}
/*--------------------------------------------------------------------------*/
void CTokenizerFunctionUCDParser::swap(CTokenizerFunctionUCDParser& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((NTokenizer::CTokenizerFunctionCharDelimiters&)(*this), (NTokenizer::CTokenizerFunctionCharDelimiters&)a_rInstance);
  NAlgorithms::NCommon::swap(m_SkipComments, a_rInstance.m_SkipComments);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
