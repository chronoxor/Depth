/*!
 *  \file    CTokenizerFunctionEscapedComma.hpp Escaped comma separated
 *           tokenizer function uses rules to parse tokens of the CSV
 *           (comma separated value) formats.
 *  \brief   Escaped comma separated tokenizer function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Escaped comma separated tokenizer function class.

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
#ifndef __CTOKENIZERFUNCTIONESCAPEDCOMMA_HPP__
#define __CTOKENIZERFUNCTIONESCAPEDCOMMA_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/tokenizer/ITokenizerFunction.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Escaped comma separated tokenizer function class.
/*!
    Escaped comma separated tokenizer function implements rules to parse input
    stream in CSV (comma separated value) format.

    CSV (comma separated value) format has the following parsing rules:
    \li If the "escape" character is met then  take  the  next  character  and
        check its value. If the next character is "quote" then append it  into
        the token. If the next character is "n" then append new line into  the
        token. If the next character is  "escape"  then  append  it  into  the
        token. Otherwise append "escape" and next character into the token.
    \li If the "quote" character is met then append all next  characters  into
        the token until next "quote" character is met.
    \li If the "comma" character is met then return current token and start  a
        new one.

    It is possible to  define  "escape",  "comma",  "quote"  characters  as  a
    character set strings. Escaped comma separated  tokenizer  function  could
    require that open and close quotes should be equal.

    Examples:
    Escape symbols = "'"
    Comma symbols = ","
    Quote symbols = "\"

    Input string = "Test 1,Test 2,Test 3"
    Tokens = <Test 1> <Test 2> <Test 3>

    Input string = "Test 1,'Test 2, with comma',Test 3"
    Tokens = <Test 1> <Test 2, with comma> <Test 3>

    Input string = "Test 1,\'Test 2 with escaped quotes\',Test 3"
    Tokens = <Test 1> <'Test 2 with quotes'> <Test 3>

    Input string = "Test 1,Test 2 with \n new line,Test 3"
    Tokens = <Test 1> <'Test 2 with [new line symbol] new line'> <Test 3>

    Input string = "Test 1,Test 2 with \\ escape,Test 3"
    Tokens = <Test 1> <'Test 2 with \ escape'> <Test 3>
*/
class TOKENIZER_API CTokenizerFunctionEscapedComma :
  public ITokenizerFunction
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CTokenizerFunctionEscapedComma TDepthCheckType;

  // Check CTokenizerFunctionEscapedComma class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize tokenizer function with control characters.
  /*!
      \param a_cEscape - Escape character (default is '\').
      \param a_cComma - Comma character (default is ',').
      \param a_cQuote - Quote character (default is '"').
  */
  CTokenizerFunctionEscapedComma(const Tchar a_cEscape = STR('\\'), const Tchar a_cComma = STR(','), const Tchar a_cQuote = STR('"'));
  //! Initialize tokenizer function with control character sets.
  /*!
      \param a_crEscape - Constant reference to the escape character set.
      \param a_crComma - Constant reference to the comma character set.
      \param a_crQuote - Constant reference to the quote character set.
      \param a_cIsEqualQuotesRequired - Open and close quotes should be equal (default is true).
  */
  CTokenizerFunctionEscapedComma(const NString::CString& a_crEscape, const NString::CString& a_crComma, const NString::CString& a_crQuote, const Tbool a_cIsEqualQuotesRequired = true);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionEscapedComma class.
  */
  CTokenizerFunctionEscapedComma(const CTokenizerFunctionEscapedComma& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTokenizerFunctionEscapedComma();

  //! Operator: Assign another CTokenizerFunctionEscapedComma class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionEscapedComma class.
      \return Reference to the current class instance.
  */
  CTokenizerFunctionEscapedComma& operator = (const CTokenizerFunctionEscapedComma& a_crInstance);

  //! Set control characters.
  /*!
      \param a_cEscape - Escape character (default is '\').
      \param a_cComma - Comma character (default is ',').
      \param a_cQuote - Quote character (default is '"').
      \return true  - if control characters were successfully set. \n
              false - if control characters were not successfully set. \n
  */
  Tbool set(const Tchar a_cEscape = STR('\\'), const Tchar a_cComma = STR(','), const Tchar a_cQuote = STR('"'));
  //! Set control character sets.
  /*!
      \param a_crEscape - Constant reference to the escape character set.
      \param a_crComma - Constant reference to the comma character set.
      \param a_crQuote - Constant reference to the quote character set.
      \param a_cIsEqualQuotesRequired - Open and close quotes should be equal (default is true).
      \return true  - if control character sets were successfully set. \n
              false - if control character sets were not successfully set. \n
  */
  Tbool set(const NString::CString& a_crEscape, const NString::CString& a_crComma, const NString::CString& a_crQuote, const Tbool a_cIsEqualQuotesRequired = true);
  //! Set another CTokenizerFunctionEscapedComma class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionEscapedComma class.
      \return true  - if another tokenizer function was successfully set. \n
              false - if another tokenizer function was not successfully set. \n
  */
  Tbool set(const CTokenizerFunctionEscapedComma& a_crInstance);

  // ITokenizerFunction interface overriding methods.
  virtual Tbool getNextToken(NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult);
  virtual Tbool reset();

  // IClonable interface overriding methods.
  virtual ITokenizerFunction* clone() const;

  //! Serialize CTokenizerFunctionEscapedComma class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTokenizerFunctionEscapedComma class instances.
  /*!
      \param a_rInstance - Reference to another CTokenizerFunctionEscapedComma class instance.
  */
  void swap(CTokenizerFunctionEscapedComma& a_rInstance);

private:
  NString::CString m_Escape;            //!< Escape character delimiters.
  NString::CString m_Comma;             //!< Comma character delimiters.
  NString::CString m_Quote;             //!< Quote character delimiters.
  Tbool m_IsEqualQuotesRequired;        //!< Should open and close quotes be equal?
  Tbool m_TokenReturned;                //!< Was token return during the last tokenizing?
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tokenizer/CTokenizerFunctionEscapedComma.inl>
/*==========================================================================*/
#endif
