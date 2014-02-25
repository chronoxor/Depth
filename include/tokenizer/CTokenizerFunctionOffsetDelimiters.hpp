/*!
 *  \file    CTokenizerFunctionOffsetDelimiters.hpp Offset delimiters
 *           tokenizer function uses a list of the offset indexes to
 *           split the input stream into tokens.
 *  \brief   Offset delimiters tokenizer function class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Offset delimiters tokenizer function class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer
    VERSION:   1.0
    CREATED:   24.04.2009 03:23:11

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
#ifndef __CTOKENIZERFUNCTIONOFFSETDELIMITERS_HPP__
#define __CTOKENIZERFUNCTIONOFFSETDELIMITERS_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ACopy.hpp>
#include <Depth/include/algorithms/iterators/AItCopy.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/CArray.hpp>
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
//! Offset delimiters tokenizer function class.
/*!
    Offset delimiters tokenizer function uses a list of the offset indexes  to
    split the input stream into tokens. Additional flags can be used  to  wrap
    around offset delimiters or to return last partially parsed token.

    Examples:
    Offsets = 2, 3, 4
    WrapOffsets = false
    ReturnLastpartially = false
    Input string = "1234567890"
    Tokens = <12> <345> <6789>

    Offsets = 2, 3, 4
    WrapOffsets = false
    ReturnLastpartially = true
    Input string = "1234567890"
    Tokens = <12> <345> <6789> <0>

    Offsets = 2, 3,
    WrapOffsets = true
    ReturnLastpartially = false
    Input string = "1234567890"
    Tokens = <12> <345> <67> <890>
*/
class TOKENIZER_API CTokenizerFunctionOffsetDelimiters :
  public ITokenizerFunction
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CTokenizerFunctionOffsetDelimiters TDepthCheckType;

  // Check CTokenizerFunctionOffsetDelimiters class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  /*!
      Creates offset delimiters tokenizer function which has only  one  offset
      (1) with wrapped and return last partially parsed token flags.
  */
  CTokenizerFunctionOffsetDelimiters();
  //! Initialize tokenizer function with iterator to the offset values container.
  /*!
      \param a_crIterator - Constant reference to the iterator to the offset values container.
      \param a_cWrapOffsets - Wrap offset delimiters flag (default is true).
      \param a_cReturnLastPartially - Return last partially parsed token flag (default is true).
  */
  template <class T_Iterator>
  CTokenizerFunctionOffsetDelimiters(const T_Iterator& a_crIterator, const Tbool a_cWrapOffsets = true, const Tbool a_cReturnLastPartially = true);
  //! Initialize tokenizer function with offset values container.
  /*!
      \param a_cContainerFlag - Offset values container overload version flag.
      \param a_crContainer - Constant reference to the offset values container.
      \param a_cWrapOffsets - Wrap offset delimiters flag (default is true).
      \param a_cReturnLastPartially - Return last partially parsed token flag (default is true).
  */
  template <class T_Container>
  CTokenizerFunctionOffsetDelimiters(const Tbool a_cContainerFlag, const T_Container& a_crContainer, const Tbool a_cWrapOffsets = true, const Tbool a_cReturnLastPartially = true);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionOffsetDelimiters class.
  */
  CTokenizerFunctionOffsetDelimiters(const CTokenizerFunctionOffsetDelimiters& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTokenizerFunctionOffsetDelimiters();

  //! Operator: Assign another CTokenizerFunctionOffsetDelimiters class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionOffsetDelimiters class.
      \return Reference to the current class instance.
  */
  CTokenizerFunctionOffsetDelimiters& operator = (const CTokenizerFunctionOffsetDelimiters& a_crInstance);

  //! Set offset delimiters taken from the iterator to the offset values container.
  /*!
      Initialize tokenizer function with offset values taken  from  the  given
      iterator to the offset values container.

      \param a_crIterator - Constant reference to the iterator to the offset values container.
      \param a_cWrapOffsets - Wrap offset delimiters flag (default is true).
      \param a_cReturnLastPartially - Return last partially parsed token flag (default is true).
      \return true - if offset delimiters were successfully set. \n
              false - if offset delimiters were not successfully set. \n
  */
  template <class T_Iterator>
  Tbool set(const T_Iterator& a_crIterator, const Tbool a_cWrapOffsets = true, const Tbool a_cReturnLastPartially = true);
  //! Set offset delimiters taken from the offset values container.
  /*!
      Initialize tokenizer function with offset values taken  from  the  given
      offset values container.

      \param a_cContainerFlag - Offset values container overload version flag.
      \param a_crContainer - Constant reference to the offset values container.
      \param a_cWrapOffsets - Wrap offset delimiters flag (default is true).
      \param a_cReturnLastPartially - Return last partially parsed token flag (default is true).
      \return true - if offset delimiters were successfully set. \n
              false - if offset delimiters were not successfully set. \n
  */
  template <class T_Container>
  Tbool set(const Tbool a_cContainerFlag, const T_Container& a_crContainer, const Tbool a_cWrapOffsets = true, const Tbool a_cReturnLastPartially = true);
  //! Set another CTokenizerFunctionOffsetDelimiters class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerFunctionOffsetDelimiters class.
      \return true  - if another tokenizer function was successfully set. \n
              false - if another tokenizer function was not successfully set. \n
  */
  Tbool set(const CTokenizerFunctionOffsetDelimiters& a_crInstance);

  // ITokenizerFunction interface overriding methods.
  virtual Tbool getNextToken(NDetails::ITokenizerInputIterator& a_rInputIterator, Tbool& a_rIsEndOfStream, NString::CString& a_rResult);
  virtual Tbool reset();

  // IClonable interface overriding methods.
  virtual ITokenizerFunction* clone() const;

  //! Serialize CTokenizerFunctionOffsetDelimiters class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTokenizerFunctionOffsetDelimiters class instances.
  /*!
      \param a_rInstance - Reference to another CTokenizerFunctionOffsetDelimiters class instance.
  */
  void swap(CTokenizerFunctionOffsetDelimiters& a_rInstance);

private:
  NContainers::CArray<Tuint> m_Offsets; //!< Offsets array.
  Tuint m_CurrentOffset;                //!< Current offset index.
  Tbool m_WrapOffsets;                  //!< Wrap offset delimiters flag.
  Tbool m_ReturnLastPartially;          //!< Return last partially parsed token flag.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tokenizer/CTokenizerFunctionOffsetDelimiters.inl>
/*==========================================================================*/
#endif
