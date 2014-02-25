/*!
 *  \file    CTokenizerFunctionCommentAsChar.cpp Character comment
 *           tokenizer function uses rules to parse tokens of the
 *           character comment formats.
 *  \brief   Character comment tokenizer function class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character comment tokenizer function class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   15.06.2010 19:47:09

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
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/tokenizer/CTokenizerFunctionCommentAsChar.hpp>
/*==========================================================================*/
#ifndef __CTOKENIZERFUNCTIONCOMMENTASCHAR_CPP__
#define __CTOKENIZERFUNCTIONCOMMENTASCHAR_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CTokenizerFunctionCommentAsChar::set(const Tchar a_cComment/* = STR('#') */)
{ CALL
  m_Comment = a_cComment;
  return reset();
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionCommentAsChar::set(const CTokenizerFunctionCommentAsChar& a_crInstance)
{ CALL
  m_Comment = a_crInstance.m_Comment;
  return CTokenizerFunctionCharDelimiters::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionCommentAsChar::getNextToken(NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult)
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
    if (CTokenizerFunctionCharDelimiters::getNextToken(a_rInputIterator, a_rIsEndOfStream, a_rResult))
    {
      // If the token is a comment, then take the next one.
      if (!a_rResult.isEmpty() && (a_rResult[CONSTU(0)] == m_Comment))
      {
        // Skip comments.
        if (!skipToLineEnd(a_rInputIterator, a_rIsEndOfStream, true))
          return false;
        continue;
      }

      // If the token has a comment, then remove it.
      for (Tuint index = 0; index < a_rResult.getSize(); ++index)
      {
        if (a_rResult[index] == m_Comment)
        {
          a_rResult = a_rResult.getLeft(index);

          // Skip rest comments.
          skipToLineEnd(a_rInputIterator, a_rIsEndOfStream, true);

          break;
        }
      }

      // Trim start and end spaces.
      while (!a_rResult.isEmpty() && NString::CCharacter(a_rResult[CONSTU(0)]).isSpace())
        if (!a_rResult.removeFirst())
          return false;
      while (!a_rResult.isEmpty() && NString::CCharacter(a_rResult[a_rResult.getSize() - 1]).isSpace())
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
Tbool CTokenizerFunctionCommentAsChar::skipToLineEnd(NTokenizer::NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, const Tbool a_cForceSkip)
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
ITokenizerFunction* CTokenizerFunctionCommentAsChar::clone() const
{ CALL
  ITokenizerFunction* result = newex CTokenizerFunctionCommentAsChar(*this);

  if (result == NULL)
    WARNING(STR("Cannot create a new character delimiters tokenizer function instance (requested size is %u bytes).") COMMA (sizeof(CTokenizerFunctionCommentAsChar)));
  return result;
}
/*--------------------------------------------------------------------------*/
void CTokenizerFunctionCommentAsChar::swap(CTokenizerFunctionCommentAsChar& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CTokenizerFunctionCharDelimiters&)(*this), (CTokenizerFunctionCharDelimiters&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Comment, a_rInstance.m_Comment);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
