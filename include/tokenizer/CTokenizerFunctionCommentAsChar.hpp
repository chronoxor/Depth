/*!
 *  \file    CTokenizerFunctionCommentAsChar.hpp Character comment
 *           tokenizer function uses rules to parse tokens of the
 *           character comment formats.
 *  \brief   Character comment tokenizer function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.06.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character comment tokenizer function class.

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
#ifndef __CTOKENIZERFUNCTIONCOMMENTASCHAR_HPP__
#define __CTOKENIZERFUNCTIONCOMMENTASCHAR_HPP__
/*==========================================================================*/
#include <Depth/include/tokenizer/CTokenizerFunctionCharDelimiters.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Character comment tokenizer function class.
/*!
    Character comment tokenizer  function  implements  rules  to  parse  input
    stream in character comment format.

    Examples:
    Comment character = "#"

    Input string = "Test 1#,Test 2,Test 3"
    Tokens = <Test 1>

    Input string = "Test 1#Test 2,\nTest 3"
    Tokens = <Test 1> <Test 3>
*/
class TOKENIZER_API CTokenizerFunctionCommentAsChar :
  public CTokenizerFunctionCharDelimiters
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CTokenizerFunctionCommentAsChar TDepthCheckType;

  // Check CTokenizerFunctionCommentAsChar class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize tokenizer function with comment character.
  /*!
      \param a_cComment - Comment character (default is '#').
  */
  CTokenizerFunctionCommentAsChar(const Tchar a_cComment = STR('#'));
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionCommentAsChar class.
  */
  CTokenizerFunctionCommentAsChar(const CTokenizerFunctionCommentAsChar& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTokenizerFunctionCommentAsChar();

  //! Operator: Assign another CTokenizerFunctionCommentAsChar class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionCommentAsChar class.
      \return Reference to the current class instance.
  */
  CTokenizerFunctionCommentAsChar& operator = (const CTokenizerFunctionCommentAsChar& a_crInstance);

  //! Set comment character.
  /*!
      \param a_cComment - Comment character (default is '#').
      \return true  - if comment character was successfully set. \n
              false - if comment character was not successfully set. \n
  */
  Tbool set(const Tchar a_cComment = STR('#'));
  //! Set another CTokenizerFunctionCommentAsChar class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionCommentAsChar class.
      \return true  - if another tokenizer function was successfully set. \n
              false - if another tokenizer function was not successfully set. \n
  */
  Tbool set(const CTokenizerFunctionCommentAsChar& a_crInstance);

  // ITokenizerFunction interface overriding methods.
  virtual Tbool getNextToken(NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult);
  virtual Tbool reset();

  // IClonable interface overriding methods.
  virtual ITokenizerFunction* clone() const;

  //! Serialize CTokenizerFunctionCommentAsChar class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTokenizerFunctionCommentAsChar class instances.
  /*!
      \param a_rInstance - Reference to another CTokenizerFunctionCommentAsChar class instance.
  */
  void swap(CTokenizerFunctionCommentAsChar& a_rInstance);

private:
  Tchar m_Comment;                      //!< Comment character.

  //! Skip character until the line end.
  /*!
      \param a_rInputIterator - Reference to the input iterator.
      \param a_rIsEndOfStream - Reference to the end of input stream flag.
      \param a_cForceSkip - Force skip flag.
      \return true  - if characters were skipped and end of input stream was not met. \n
              false - if characters were not skipped and end of input stream was met. \n
  */
  Tbool skipToLineEnd(NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, const Tbool a_cForceSkip);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tokenizer/CTokenizerFunctionCommentAsChar.inl>
/*==========================================================================*/
#endif
