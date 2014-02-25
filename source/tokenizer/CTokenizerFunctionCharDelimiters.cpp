/*!
 *  \file    CTokenizerFunctionCharDelimiters.cpp Character delimiters
 *           tokenizer function uses a list of characters as token
 *           delimiters.
 *  \brief   Character delimiters tokenizer function class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character delimiters tokenizer function class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   21.04.2009 03:27:49

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
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/tokenizer/CTokenizerFunctionCharDelimiters.hpp>
/*==========================================================================*/
#ifndef __CTOKENIZERFUNCTIONCHARDELIMITERS_CPP__
#define __CTOKENIZERFUNCTIONCHARDELIMITERS_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CTokenizerFunctionCharDelimiters::CTokenizerFunctionCharDelimiters(const Tbool a_cDroppedIsSpace/* = true */, const Tbool a_cKeptIsPunct/* = true */, const Tbool a_cReturnEmptyTokens/* = false */) :
  ITokenizerFunction(),
  m_Dropped(),
  m_Kept(),
  m_DroppedIsSpace(a_cDroppedIsSpace),
  m_KeptIsPunct(a_cKeptIsPunct),
  m_ReturnEmptyTokens(a_cReturnEmptyTokens),
  m_TokenReturned(false)
{ CALL

}
/*--------------------------------------------------------------------------*/
CTokenizerFunctionCharDelimiters::CTokenizerFunctionCharDelimiters(const NString::CString& a_crDropped, const NString::CString& a_crKept, const Tbool a_cReturnEmptyTokens/* = false */) :
  ITokenizerFunction(),
  m_Dropped(a_crDropped),
  m_Kept(a_crKept),
  m_DroppedIsSpace(false),
  m_KeptIsPunct(false),
  m_ReturnEmptyTokens(a_cReturnEmptyTokens),
  m_TokenReturned(false)
{ CALL

}
/*--------------------------------------------------------------------------*/
CTokenizerFunctionCharDelimiters::CTokenizerFunctionCharDelimiters(const CTokenizerFunctionCharDelimiters& a_crInstance) :
  ITokenizerFunction(),
  m_Dropped(a_crInstance.m_Dropped),
  m_Kept(a_crInstance.m_Kept),
  m_DroppedIsSpace(a_crInstance.m_DroppedIsSpace),
  m_KeptIsPunct(a_crInstance.m_KeptIsPunct),
  m_ReturnEmptyTokens(a_crInstance.m_ReturnEmptyTokens),
  m_TokenReturned(false)
{ CALL

}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionCharDelimiters::set(const Tbool a_cDroppedIsSpace, const Tbool a_cKeptIsPunct, const Tbool a_cReturnEmptyTokens/* = false */)
{ CALL
  if (!m_Dropped.clear())
    return false;
  if (!m_Kept.clear())
    return false;
  m_DroppedIsSpace = a_cDroppedIsSpace;
  m_KeptIsPunct = a_cKeptIsPunct;
  m_ReturnEmptyTokens = a_cReturnEmptyTokens;
  return reset();
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionCharDelimiters::set(const NString::CString& a_crDropped, const NString::CString& a_crKept, const Tbool a_cReturnEmptyTokens/* = false */)
{ CALL
  if (!m_Dropped.set(a_crDropped))
    return false;
  if (!m_Kept.set(a_crKept))
    return false;
  m_DroppedIsSpace = false;
  m_KeptIsPunct = false;
  m_ReturnEmptyTokens = a_cReturnEmptyTokens;
  return reset();
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionCharDelimiters::set(const CTokenizerFunctionCharDelimiters& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CTokenizerFunctionCharDelimiters class instance."))
  {
    return false;
  }

  if (!m_Dropped.set(a_crInstance.m_Dropped))
    return false;
  if (!m_Kept.set(a_crInstance.m_Kept))
    return false;
  m_DroppedIsSpace = a_crInstance.m_DroppedIsSpace;
  m_KeptIsPunct = a_crInstance.m_KeptIsPunct;
  m_ReturnEmptyTokens = a_crInstance.m_ReturnEmptyTokens;
  return reset();
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionCharDelimiters::getNextToken(NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult)
{ CALL
  // Check if the given input iterator is in valid state.
  ASSERT(a_rInputIterator.isValid(), STR("Cannot get next token from the invalid input iterator."))
  {
    return false;
  }

  // Clear result string.
  if (!a_rResult.clear())
    return false;

  // Do we need to return empty tokens?
  if (!m_ReturnEmptyTokens)
  {
    // We do not need to return empty tokens and we met end of input stream,
    // therefore we stop the tokenize process.
    if (a_rIsEndOfStream)
      return false;

    // Skip through all dropped delimiters.
    while (isDropped(a_rInputIterator.getValueRef()))
    {
      // Do we met end of input stream?
      if (a_rInputIterator.stepForward() == 0)
      {
        a_rIsEndOfStream = true;
        return false;
      }
    }

    // If the kept delimiter is found, return it.
    if (isKept(a_rInputIterator.getValueRef()))
    {
      if (!a_rResult.insertLast((NString::CString::TType)a_rInputIterator.getValueRef()))
        return false;

      // Do we met end of input stream?
      if (a_rInputIterator.stepForward() == 0)
        a_rIsEndOfStream = true;

      return true;
    }
    else
    {
      // Collect all non delimiters from the input stream.
      while (!isDropped(a_rInputIterator.getValueRef()) && !isKept(a_rInputIterator.getValueRef()))
      {
        if (!a_rResult.insertLast((NString::CString::TType)a_rInputIterator.getValueRef()))
          return false;

        // Do we met end of input stream?
        if (a_rInputIterator.stepForward() == 0)
        {
          a_rIsEndOfStream = true;
          break;
        }
      }
      return true;
    }
  }
  else
  {
    // Check empty token at the end of the input stream.
    if (a_rIsEndOfStream)
    {
      if (!m_TokenReturned)
      {
        // We have not returned empty token yet.
        m_TokenReturned = true;
        return true;
      }
      else
        return false;
    }

    // We met a kept delimiter that we have to collect and return.
    if (isKept(a_rInputIterator.getValueRef()))
    {
      if (!m_TokenReturned)
      {
        // We have not returned empty token yet.
        m_TokenReturned = true;
        return true;
      }
      else
      {
        // Collect the kept delimiter.
        if (!a_rResult.insertLast((NString::CString::TType)a_rInputIterator.getValueRef()))
          return false;

        // Do we met end of input stream?
        if (a_rInputIterator.stepForward() == 0)
          a_rIsEndOfStream = true;

        m_TokenReturned = false;
        return true;
      }
    }
    else if (!m_TokenReturned && isDropped(a_rInputIterator.getValueRef()))
    {
      // Return empty token before the dropped delimiter.
      m_TokenReturned = true;
      return true;
    }
    else
    {
      // Skip the dropped delimiter.
      if (isDropped(a_rInputIterator.getValueRef()))
      {
        // Do we met end of input stream?
        if (a_rInputIterator.stepForward() == 0)
        {
          a_rIsEndOfStream = true;
          m_TokenReturned = true;
          return true;
        }
      }

      // Collect all non delimiters from the input stream.
      while (!isDropped(a_rInputIterator.getValueRef()) && !isKept(a_rInputIterator.getValueRef()))
      {
        if (!a_rResult.insertLast((NString::CString::TType)a_rInputIterator.getValueRef()))
          return false;

        // Do we met end of input stream?
        if (a_rInputIterator.stepForward() == 0)
        {
          a_rIsEndOfStream = true;
          break;
        }
      }

      m_TokenReturned = true;
      return true;
    }
  }
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionCharDelimiters::isDropped(const Tuint a_cCharacter) const
{ CALL
  Tuint temp = 0;
  if (!m_Dropped.isEmpty())
    return NAlgorithms::NString::findChar(false, false, temp, m_Dropped, a_cCharacter);
  else if (m_DroppedIsSpace)
    return NString::CCharacter(a_cCharacter).isSpace();
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizerFunctionCharDelimiters::isKept(const Tuint a_cCharacter) const
{ CALL
  Tuint temp = 0;
  if (!m_Kept.isEmpty())
    return NAlgorithms::NString::findChar(false, false, temp, m_Kept, a_cCharacter);
  else if (m_KeptIsPunct)
    return NString::CCharacter(a_cCharacter).isPunct();
  else
    return false;
}
/*--------------------------------------------------------------------------*/
ITokenizerFunction* CTokenizerFunctionCharDelimiters::clone() const
{ CALL
  ITokenizerFunction* result = newex CTokenizerFunctionCharDelimiters(*this);

  if (result == NULL)
    WARNING(STR("Cannot create a new character delimiters tokenizer function instance (requested size is %u bytes).") COMMA (sizeof(CTokenizerFunctionCharDelimiters)));
  return result;
}
/*--------------------------------------------------------------------------*/
void CTokenizerFunctionCharDelimiters::swap(CTokenizerFunctionCharDelimiters& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Dropped, a_rInstance.m_Dropped);
  NAlgorithms::NCommon::swap(m_Kept, a_rInstance.m_Kept);
  NAlgorithms::NCommon::swap(m_DroppedIsSpace, a_rInstance.m_DroppedIsSpace);
  NAlgorithms::NCommon::swap(m_KeptIsPunct, a_rInstance.m_KeptIsPunct);
  NAlgorithms::NCommon::swap(m_ReturnEmptyTokens, a_rInstance.m_ReturnEmptyTokens);
  NAlgorithms::NCommon::swap(m_TokenReturned, a_rInstance.m_TokenReturned);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
