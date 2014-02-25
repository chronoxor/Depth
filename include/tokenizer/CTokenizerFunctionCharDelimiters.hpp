/*!
 *  \file    CTokenizerFunctionCharDelimiters.hpp Character delimiters
 *           tokenizer function uses a list of characters as token
 *           delimiters.
 *  \brief   Character delimiters tokenizer function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    21.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character delimiters tokenizer function class.

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
#ifndef __CTOKENIZERFUNCTIONCHARDELIMITERS_HPP__
#define __CTOKENIZERFUNCTIONCHARDELIMITERS_HPP__
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
//! Character delimiters tokenizer function class.
/*!
    Character delimiters tokenizer function uses a list of characters as token
    delimiters. The list of delimiters is split into two parts:
    \li Dropped delimiters are not returned as separate  tokens  and  will  be
        dropped during the parsing.
    \li Kept delimiters are treated  separate  tokens  and  will  be  returned
        during the parsing.

    Additionally there is a flag which regulates if empty token is returned if
    two delimiters appear close to each other during the parsing.

    Tokenizer  function  interface  is  a  base  interface  for  all  tokenize
    functions which  are  used  to  separate  string  tokens  based  on  their
    corresponding rules.

    Examples:
    Dropped delimiters = "-;|"
    Kept delimiters = ""
    Return empty = false
    Input string = ";;Hello|world||-foo--bar;yow;baz|"
    Tokens = <Hello> <world> <foo> <bar> <yow> <baz>

    Dropped delimiters = "-;"
    Kept delimiters = "|"
    Return empty = true
    Input string = ";;Hello|world||-foo--bar;yow;baz|"
    Tokens = <> <> <Hello> <|> <world> <|> <> <|> <> <foo> <> <bar> <yow> <baz> <|> <>

    Dropped delimiters = CCharacter::isSpace()
    Kept delimiters = CCharacter::isPunct()
    Return empty = false
    Input string = "This is,  a test"
    Tokens = <This> <is> <,> <a> <test>
*/
class TOKENIZER_API CTokenizerFunctionCharDelimiters :
  public ITokenizerFunction
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CTokenizerFunctionCharDelimiters TDepthCheckType;

  // Check CTokenizerFunctionCharDelimiters class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Creates default  character  delimiters  tokenizer  function  which  uses
      CCharacter::isSpace()    method    as     dropped     delimiters     and
      CCharacter::isPunct() method as kept delimiters.

      \param a_cDroppedIsSpace - Use CCharacter::isSpace() method as dropped character delimiters (default is true).
      \param a_cKeptIsPunct - Use CCharacter::isPunct() method as kept character delimiters (default is true).
      \param a_cReturnEmptyTokens - Return empty tokens (between two close delimiters) flag (default is false).
  */
  CTokenizerFunctionCharDelimiters(const Tbool a_cDroppedIsSpace = true, const Tbool a_cKeptIsPunct = true, const Tbool a_cReturnEmptyTokens = false);
  //! Initialize tokenizer function with dropped and kept delimiters.
  /*!
      \param a_crDropped - Constant reference to the string with dropped character delimiters.
      \param a_crKept - Constant reference to the string with kept character delimiters.
      \param a_cReturnEmptyTokens - Return empty tokens (between two close delimiters) flag (default is false).
  */
  CTokenizerFunctionCharDelimiters(const NString::CString& a_crDropped, const NString::CString& a_crKept, const Tbool a_cReturnEmptyTokens = false);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionCharDelimiters class.
  */
  CTokenizerFunctionCharDelimiters(const CTokenizerFunctionCharDelimiters& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTokenizerFunctionCharDelimiters();

  //! Operator: Assign another CTokenizerFunctionCharDelimiters class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionCharDelimiters class.
      \return Reference to the current class instance.
  */
  CTokenizerFunctionCharDelimiters& operator = (const CTokenizerFunctionCharDelimiters& a_crInstance);

  //! Set default delimiters.
  /*!
      Default character delimiters use CCharacter::isSpace() method as dropped
      delimiters and CCharacter::isPunct() method as kept delimiters.

      \param a_cDroppedIsSpace - Use CCharacter::isSpace() method as dropped character delimiters.
      \param a_cKeptIsPunct - Use CCharacter::isPunct() method as kept character delimiters.
      \param a_cReturnEmptyTokens - Return empty tokens (between two close delimiters) flag (default is false).
      \return true  - if default delimiters were successfully set. \n
              false - if default delimiters were not successfully set. \n
  */
  Tbool set(const Tbool a_cDroppedIsSpace, const Tbool a_cKeptIsPunct, const Tbool a_cReturnEmptyTokens = false);
  //! Set dropped and kept delimiters.
  /*!
      \param a_crDropped - Constant reference to the string with dropped character delimiters.
      \param a_crKept - Constant reference to the string with kept character delimiters.
      \param a_cReturnEmptyTokens - Return empty tokens (between two close delimiters) flag (default is false).
      \return true  - if dropped and kept delimiters were successfully set. \n
              false - if dropped and kept delimiters were not successfully set. \n
  */
  Tbool set(const NString::CString& a_crDropped, const NString::CString& a_crKept, const Tbool a_cReturnEmptyTokens = false);
  //! Set another CTokenizerFunctionCharDelimiters class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionCharDelimiters class.
      \return true  - if another tokenizer function was successfully set. \n
              false - if another tokenizer function was not successfully set. \n
  */
  Tbool set(const CTokenizerFunctionCharDelimiters& a_crInstance);

  // ITokenizerFunction interface overriding methods.
  virtual Tbool getNextToken(NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult);
  virtual Tbool reset();

  // IClonable interface overriding methods.
  virtual ITokenizerFunction* clone() const;

  //! Serialize CTokenizerFunctionCharDelimiters class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTokenizerFunctionCharDelimiters class instances.
  /*!
      \param a_rInstance - Reference to another CTokenizerFunctionCharDelimiters class instance.
  */
  void swap(CTokenizerFunctionCharDelimiters& a_rInstance);

private:
  NString::CString m_Dropped;           //!< Dropped character delimiters.
  NString::CString m_Kept;              //!< Kept character delimiters.
  Tbool m_DroppedIsSpace;               //!< Is CCharacter::isSpace() method used as dropped character delimiters?
  Tbool m_KeptIsPunct;                  //!< Is CCharacter::isPunct() method used as kept character delimiters?
  Tbool m_ReturnEmptyTokens;            //!< Are empty tokens (between two close delimiters) are returned?
  Tbool m_TokenReturned;                //!< Was token return during the last tokenizing?

  //! Check is the given character is dropped delimiter.
  /*!
      \param a_cCharacter - Character in general form.
      \return true  - if the given character is dropped delimiter. \n
              false - if the given character is not dropped delimiter. \n
  */
  Tbool isDropped(const Tuint a_cCharacter) const;
  //! Check is the given character is kept delimiter.
  /*!
      \param a_cCharacter - Character in general form.
      \return true  - if the given character is kept delimiter. \n
              false - if the given character is not kept delimiter. \n
  */
  Tbool isKept(const Tuint a_cCharacter) const;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tokenizer/CTokenizerFunctionCharDelimiters.inl>
/*==========================================================================*/
#endif
