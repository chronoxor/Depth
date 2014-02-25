/*!
 *  \file    CTokenizer.hpp Tokenizer class is used to split input stream into
 *           the string tokens based on the given rule.
 *  \brief   Tokenizer class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer class.

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
#ifndef __CTOKENIZER_HPP__
#define __CTOKENIZER_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IStackConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/tokenizer/CTokenizerFunctionCharDelimiters.hpp>
#include <Depth/include/tokenizer/details/CTokenizerInputContainer.hpp>
#include <Depth/include/tokenizer/details/CTokenizerInputIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
class CTokenizerIterator;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Tokenizer class.
/*!
    Tokenizer class split the input stream into the tokens (separated strings)
    based on the tokenize rule. The input stream is represented with  a  given
    forward iterator or container. Tokenize rule is provided through the given
    tokenizer function which implements ITokenizerFunction interface.

    After the tokenizer is prepared it can be used by getting its iterator and
    iterate forward through parsed tokens.

    Example:
    \code
    // Create the default tokenizer.
    CTokenizer tokenizer(reader.getItRead<Tchar>());

    // Iterate through all tokens.
    CTokenizer::TIterator it = tokenizer.getItTop();
    while (it.isValid())
    {
      // Show the next token.
      CString token = *it;
      ...
      // Do something with token...
      ...
      // Get the next token.
      if (it.stepForward() == 0)
        break;
    }
    \endcode

    Serialization: Tokenizer cannot be serialized.
*/
class TOKENIZER_API CTokenizer :
  public NCommon::NContainers::IStackConst<CTokenizer, NString::CString, CTokenizerIterator, CTokenizerIterator>
{
  // Friend class: Tokenizer iterator class (CTokenizerIterator).
  friend class NDepth::NTokenizer::NIterators::CTokenizerIterator;

  //! Type for the MConceptDepthType constraint checking.
  typedef CTokenizer TDepthCheckType;

  // Check CTokenizer class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container value type.
  typedef NString::CString TType;
  //! Container type.
  typedef CTokenizer TContainer;
  //! Non constant tokenizer iterator type.
  typedef CTokenizerIterator TIterator;
  //! Constant tokenizer iterator type.
  typedef CTokenizerIterator TIteratorConst;

  //! Default class constructor.
  CTokenizer();
  //! Initialize tokenizer with given input iterator and tokenizer function.
  /*!
      \param a_crInputIterator - Constant reference to the input iterator.
      \param a_crTokenizerFunction - Constant reference to tokenizer function (default is NDepth::NTokenizer::CTokenizerFunctionCharDelimiters()).
  */
  template <class T_Iterator>
  CTokenizer(const T_Iterator& a_crInputIterator, const ITokenizerFunction& a_crTokenizerFunction = CTokenizerFunctionCharDelimiters());
  //! Initialize tokenizer with given input container and tokenizer function.
  /*!
      \param a_cContainerFlag - Input container overload version flag.
      \param a_crInputContainer - Constant reference to the input container.
      \param a_crTokenizerFunction - Constant reference to tokenizer function (default is NDepth::NTokenizer::CTokenizerFunctionCharDelimiters()).
  */
  template <class T_Container>
  CTokenizer(const Tbool a_cContainerFlag, const T_Container& a_crInputContainer, const ITokenizerFunction& a_crTokenizerFunction = CTokenizerFunctionCharDelimiters());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizer class.
  */
  CTokenizer(const CTokenizer& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTokenizer();

  //! Operator: Assign another CTokenizer class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizer class.
      \return Reference to the current class instance.
  */
  CTokenizer& operator = (const CTokenizer& a_crInstance);

  //! Set new input iterator and tokenizer function.
  /*!
      \param a_crInputIterator - Constant reference to the input iterator.
      \param a_crTokenizerFunction - Constant reference to tokenizer function (default is NDepth::NTokenizer::CTokenizerFunctionCharDelimiters()).
      \return true  - if new input iterator and tokenizer function were successfully set. \n
              false - if new input iterator and tokenizer function were not successfully set. \n
  */
  template <class T_Iterator>
  Tbool set(const T_Iterator& a_crInputIterator, const ITokenizerFunction& a_crTokenizerFunction = CTokenizerFunctionCharDelimiters());
  //! Set new input container and tokenizer function.
  /*!
      \param a_cContainerFlag - Input container overload version flag.
      \param a_crInputContainer - Constant reference to the input container.
      \param a_crTokenizerFunction - Constant reference to tokenizer function (default is NDepth::NTokenizer::CTokenizerFunctionCharDelimiters()).
      \return true  - if new input container and tokenizer function were successfully set. \n
              false - if new input container and tokenizer function were not successfully set. \n
  */
  template <class T_Container>
  Tbool set(const Tbool a_cContainerFlag, const T_Container& a_crInputContainer, const ITokenizerFunction& a_crTokenizerFunction = CTokenizerFunctionCharDelimiters());
  //! Set another CTokenizer class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizer class.
      \return true  - if another tokenizer was successfully set. \n
              false - if another tokenizer was not successfully set. \n
  */
  Tbool set(const CTokenizer& a_crInstance);

  //! Set new input iterator.
  /*!
      \param a_crInputIterator - Constant reference to the input iterator.
      \return true  - if new input iterator was successfully set. \n
              false - if new input iterator was not successfully set. \n
  */
  template <class T_Iterator>
  Tbool setInputIterator(const T_Iterator& a_crInputIterator);
  //! Set new input container.
  /*!
      \param a_crInputContainer - Constant reference to the input container.
      \return true  - if new input container was successfully set. \n
              false - if new input container was not successfully set. \n
  */
  template <class T_Container>
  Tbool setInputContainer(const T_Container& a_crInputContainer);
  //! Set new tokenizer function.
  /*!
      \param a_crTokenizerFunction - Constant reference to the tokenizer function.
      \return true  - if new tokenizer function was successfully set. \n
              false - if new tokenizer function was not successfully set. \n
  */
  Tbool setTokenizerFunction(const ITokenizerFunction& a_crTokenizerFunction);

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IStackConst interface overriding methods.
  virtual TIterator      getItTop();
  virtual TIteratorConst getItTop() const;

  //! Serialize CTokenizer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTokenizer class instances.
  /*!
      \param a_rInstance - Reference to another CTokenizer class instance.
  */
  void swap(CTokenizer& a_rInstance);

private:
  NDetails::ITokenizerInputIterator* m_pInputIterator; //!< Pointer to the current instance of the tokenizer input iterator.
  ITokenizerFunction*                m_pTokenFunction; //!< Pointer to the current instance of the tokenizer function.
  Tbool                              m_IsEndOfStream;  //!< End of input stream flag.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* CONTAINER TRAITS SPECIALIZATION DECLARATIONS                             */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: tokenizer container traits specialization.
template <>
class MTraitsContainer<NTokenizer::CTokenizer> :
  public MType<NTokenizer::CTokenizer>
{
public:
  //! Container value type.
  typedef NTokenizer::CTokenizer::TType value;
  //! Container type.
  typedef NTokenizer::CTokenizer::TContainer container;
  //! Container non constant iterator type.
  typedef NTokenizer::CTokenizer::TIterator iterator;
  //! Container constant iterator type.
  typedef NTokenizer::CTokenizer::TIteratorConst citerator;

  static const Tbool isConst            = true;  //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = true;  //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = false; //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = false; //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = false; //!< Is container constant random?
  static const Tbool isAssociative      = false; //!< Is container non constant associative?
  static const Tbool isAssociativeConst = false; //!< Is container constant associative?
  static const Tbool isTree             = false; //!< Is container non constant tree?
  static const Tbool isTreeConst        = false; //!< Is container constant tree?
  static const Tbool isGraph            = false; //!< Is container non constant graph?
  static const Tbool isGraphConst       = false; //!< Is container constant graph?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tokenizer/iterators/CTokenizerIterator.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/tokenizer/CTokenizer.inl>
/*==========================================================================*/
//! \example example-tokenizer-CTokenizerCharDelimiters.cpp
//! \example example-tokenizer-CTokenizerOffsetDelimiters.cpp
/*--------------------------------------------------------------------------*/
//! \test test-tokenizer-CTokenizerCharDelimiters.cpp
//! \test test-tokenizer-CTokenizerOffsetDelimiters.cpp
/*==========================================================================*/
#endif
