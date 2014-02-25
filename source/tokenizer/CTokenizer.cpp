/*!
 *  \file    CTokenizer.cpp Tokenizer class is used to split input stream into
 *           the string tokens based on the given rule.
 *  \brief   Tokenizer class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   23.04.2009 03:27:25

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
#include <Depth/include/algorithms/common/ACast.hpp>
#include <Depth/include/tokenizer/CTokenizer.hpp>
/*==========================================================================*/
#ifndef __CTOKENIZER_CPP__
#define __CTOKENIZER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
CTokenizer::~CTokenizer()
{ CALL
  // Delete a clone of the input iterator.
  if (m_pInputIterator != NULL)
    delete m_pInputIterator;
  // Delete a clone of the tokenizer function.
  if (m_pTokenFunction != NULL)
    delete m_pTokenFunction;
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizer::set(const CTokenizer& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CTokenizer class instance."))
  {
    return false;
  }

  // Delete a clone of the input iterator.
  if (m_pInputIterator != NULL)
    delete m_pInputIterator;
  // Delete a clone of the tokenizer function.
  if (m_pTokenFunction != NULL)
    delete m_pTokenFunction;

  m_pInputIterator = NULL;
  m_pTokenFunction = NULL;

  // Make a copy of the input iterator.
  if (a_crInstance.m_pInputIterator != NULL)
  {
    m_pInputIterator = a_crInstance.m_pInputIterator->clone();
    if (m_pInputIterator == NULL)
      return false;

    m_IsEndOfStream = !m_pInputIterator->isValid();
  }
  // Make a copy of the tokenizer function.
  if (a_crInstance.m_pTokenFunction != NULL)
  {
    m_pTokenFunction = a_crInstance.m_pTokenFunction->clone();
    if (m_pTokenFunction == NULL)
      return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CTokenizer::setTokenizerFunction(const ITokenizerFunction& a_crTokenizerFunction)
{ CALL
  // Delete a clone of the tokenizer function.
  if (m_pTokenFunction != NULL)
    delete m_pTokenFunction;

  // Store a clone of the given tokenizer function.
  m_pTokenFunction = a_crTokenizerFunction.clone();
  return (m_pTokenFunction != NULL);
}
/*--------------------------------------------------------------------------*/
CTokenizer::TIterator CTokenizer::getItTop()
{ CALL
  TIterator it_top;

  // Filling iterator inner structure.
  it_top.m_pContainer = this;
  it_top.m_IsParsed = true;
  if (isEmpty() || !m_pTokenFunction->reset() || (it_top.stepForward() == 0))
    it_top.m_IsParsed = false;
  return it_top;
}
/*--------------------------------------------------------------------------*/
CTokenizer::TIteratorConst CTokenizer::getItTop() const
{ CALL
  TIteratorConst it_top;

  // Filling iterator inner structure.
  it_top.m_pContainer = NAlgorithms::NCommon::constCast<CTokenizer*>(this);
  it_top.m_IsParsed = true;
  if (isEmpty() || !m_pTokenFunction->reset() || (it_top.stepForward() == 0))
    it_top.m_IsParsed = false;
  return it_top;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
