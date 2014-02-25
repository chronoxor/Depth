/*!
 *  \file    ITokenizerFunction.hpp Tokenizer function interface is a base
 *           interface for all tokenize functions which are used to separate
 *           string tokens based on their corresponding rules.
 *  \brief   Tokenizer function interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer function interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   20.04.2009 20:28:52

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
#ifndef __ITOKENIZERFUNCTION_HPP__
#define __ITOKENIZERFUNCTION_HPP__
/*==========================================================================*/
#include <Depth/include/common/IClonable.hpp>
#include <Depth/include/string/CString.hpp>
#include <Depth/include/tokenizer/details/ITokenizerInputIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Tokenizer function interface.
/*!
    Tokenizer  function  interface  is  a  base  interface  for  all  tokenize
    functions which  are  used  to  separate  string  tokens  based  on  their
    corresponding rules.

    \see NDepth::NTokenizer::CTokenizerFunctionCharDelimiters
    \see NDepth::NTokenizer::CTokenizerFunctionOffsetDelimiters
    \see NDepth::NTokenizer::CTokenizerFunctionEscapedComma
*/
class TOKENIZER_API ITokenizerFunction :
  public NCommon::IClonable<ITokenizerFunction>
{
protected:
  //! Default interface protected constructor.
  ITokenizerFunction();

public:
  //! Interface virtual destructor.
  virtual ~ITokenizerFunction();

  //! Operator: Get next string token based on internal rules and the given input iterator.
  /*!
      \param a_rInputIterator - Reference to the input iterator.
      \param a_rIsEndOfStream - Reference to the end of input stream flag.
      \param a_rResult - Reference to the result string.
      \return true  - if the next token was parsed and end of input stream was not met. \n
              false - if the next token was not parsed and end of input stream was met. \n
      \see NDepth::NTokenizer::ITokenizerFunction::getNextToken()
  */
  Tbool operator () (NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult);

  //! Get next string token based on internal rules and the given input iterator.
  /*!
      Method input next string token from the given input  iterator  based  on
      internal parsing rules.

      \param a_rInputIterator - Reference to the input iterator.
      \param a_rIsEndOfStream - Reference to the end of input stream flag.
      \param a_rResult - Reference to the result string.
      \return true  - if the next token was parsed and end of input stream was not met. \n
              false - if the next token was was parsed and end of input stream was met. \n
  */
  virtual Tbool getNextToken(NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult) = 0;

  //! Reset tokenizer function.
  /*!
      \return true  - if the tokenizer function was successfully reset. \n
              false - if the tokenizer function was not successfully reset. \n
  */
  virtual Tbool reset() = 0;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tokenizer/ITokenizerFunction.inl>
/*==========================================================================*/
#endif
