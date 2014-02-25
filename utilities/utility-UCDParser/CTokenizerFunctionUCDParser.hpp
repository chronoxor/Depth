/*!
 *  \file    CTokenizerFunctionUCDParser.hpp Tokenizer function of the UCD
 *           parser.
 *  \brief   UCD parser tokenizer function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: UCD parser tokenizer function class.

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
#ifndef __CTOKENIZERFUNCTIONUCDPARSER_HPP__
#define __CTOKENIZERFUNCTIONUCDPARSER_HPP__
/*==========================================================================*/
#include <Depth/include/tokenizer/CTokenizerFunctionCharDelimiters.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtilities {
/*--------------------------------------------------------------------------*/
namespace NUCDParser {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! UCD parser tokenizer function class.
class CTokenizerFunctionUCDParser :
  public NTokenizer::CTokenizerFunctionCharDelimiters
{
public:
  //! Default class constructor.
  /*!
      \param a_cSkipComments - Skip comments flag (default is true).
  */
  CTokenizerFunctionUCDParser(const Tbool a_cSkipComments = true);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionUCDParser class.
  */
  CTokenizerFunctionUCDParser(const CTokenizerFunctionUCDParser& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTokenizerFunctionUCDParser();

  //! Operator: Assign another CTokenizerFunctionUCDParser class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionUCDParser class.
      \return Reference to the current class instance.
  */
  CTokenizerFunctionUCDParser& operator = (const CTokenizerFunctionUCDParser& a_crInstance);

  //! Set skip comments flag.
  /*!
      \param a_cSkipComments - Skip comments flag (default is true).
      \return true  - if skip comments flag was successfully set. \n
              false - if skip comments flag was not successfully set. \n
  */
  Tbool set(const Tbool a_cSkipComments = true);
  //! Set another CTokenizerFunctionUCDParser class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionUCDParser class.
      \return true  - if another tokenizer function was successfully set. \n
              false - if another tokenizer function was not successfully set. \n
  */
  Tbool set(const CTokenizerFunctionUCDParser& a_crInstance);

  // ITokenizerFunction interface overriding methods.
  virtual Tbool getNextToken(NTokenizer::NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult);
  virtual Tbool reset();

  // IClonable interface overriding methods.
  virtual ITokenizerFunction* clone() const;

  //! Serialize CTokenizerFunctionUCDParser class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTokenizerFunctionUCDParser class instances.
  /*!
      \param a_rInstance - Reference to another CTokenizerFunctionUCDParser class instance.
  */
  void swap(CTokenizerFunctionUCDParser& a_rInstance);

private:
  Tbool m_SkipComments;                 //!< Skip comments flag.

  //! Skip character until the line end.
  /*!
      \param a_rInputIterator - Reference to the input iterator.
      \param a_rIsEndOfStream - Reference to the end of input stream flag.
      \param a_cForceSkip - Force skip flag.
      \return true  - if characters were skipped and end of input stream was not met. \n
              false - if characters were not skipped and end of input stream was met. \n
  */
  Tbool skipToLineEnd(NTokenizer::NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, const Tbool a_cForceSkip);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include "CTokenizerFunctionUCDParser.inl"
/*==========================================================================*/
#endif
