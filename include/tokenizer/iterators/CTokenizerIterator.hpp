/*!
 *  \file    CTokenizerIterator.hpp Tokenizer iterator definitions. It gives
 *           ability to parse input stream and get new tokens as iterator's
 *           values.
 *  \brief   Tokenizer iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer iterators
    VERSION:   1.0
    CREATED:   23.04.2009 21:21:59

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
#ifndef __CTOKENIZERITERATOR_HPP__
#define __CTOKENIZERITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorConst.hpp>
#include <Depth/include/common/iterators/IIteratorMoveForward.hpp>
#include <Depth/include/tokenizer/CTokenizer.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Tokenizer iterator class.
/*!
    Tokenizer iterator parses input stream  of  the  tokenizer  using  current
    tokenizer function and stores tokens as iterator's values. Parsing is done
    with  'stepForward()'  method.  Parsed  tokens  could  be  returned  using
    'getValueRef()' or 'getValuePtr()' methods.
*/
class TOKENIZER_API CTokenizerIterator :
  public NCommon::NIterators::IIteratorConst<CTokenizerIterator, NString::CString, NString::CString, CTokenizer>,
  public NCommon::NIterators::IIteratorMoveForward<CTokenizerIterator, NString::CString, NString::CString, CTokenizer>
{
  // Friend class: Tokenizer class (CTokenizer).
  friend class NDepth::NTokenizer::CTokenizer;

  //! Type for MConceptDepthType constraint checking.
  typedef CTokenizerIterator TDepthCheckType;

  // Check CTokenizerIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef NString::CString TType;
  //! Iterator return type.
  typedef NString::CString TReturn;
  //! Iterator container type.
  typedef CTokenizer TContainer;
  //! Iterator base type.
  typedef CTokenizerIterator TIterator;

  //! Default class constructor.
  CTokenizerIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerIterator class.
  */
  CTokenizerIterator(const CTokenizerIterator& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTokenizerIterator();

  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  friend TOKENIZER_API Tbool operator == (const CTokenizerIterator& a_crInstance1, const CTokenizerIterator& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  friend TOKENIZER_API Tbool operator != (const CTokenizerIterator& a_crInstance1, const CTokenizerIterator& a_crInstance2);

  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CTokenizerIterator& operator = (const CTokenizerIterator& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CTokenizerIterator& operator += (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTokenizerIterator& operator ++ ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CTokenizerIterator operator ++ (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  friend CTokenizerIterator operator + (const CTokenizerIterator& a_crInstance, const Tuint a_cStepCount);

  //! Set another CTokenizerIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerIterator class.
  */
  void set(const CTokenizerIterator& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CTokenizerIterator getForward() const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CTokenizer& getContainerRef() const;
  virtual CTokenizer* getContainerPtr() const;
  virtual NString::CString& getValueRef() const;
  virtual NString::CString* getValuePtr() const;

  // IIteratorMoveForward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);

  //! Serialize CTokenizerIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTokenizerIterator class instances.
  /*!
      \param a_rInstance - Reference to another CTokenizerIterator class instance.
  */
  void swap(CTokenizerIterator& a_rInstance);

private:
  CTokenizer* m_pContainer;             //!< Pointer to the iterator container.
  mutable NString::CString m_Value;     //!< Current token value.
  Tbool m_IsParsed;                     //!< Is current token value parsed?

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CTokenizerIterator(CTokenizer* a_pContainer);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* ITERATOR TRAITS SPECIALIZATION DECLARATIONS                              */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: tokenizer constant iterator's traits specialization.
template <>
class MTraitsIterator<NTokenizer::NIterators::CTokenizerIterator> :
  public MType<NTokenizer::NIterators::CTokenizerIterator>
{
public:
  //! Iterator value type.
  typedef NTokenizer::NIterators::CTokenizerIterator::TType value;
  //! Iterator return type.
  typedef NTokenizer::NIterators::CTokenizerIterator::TReturn result;
  //! Iterator container type.
  typedef NTokenizer::NIterators::CTokenizerIterator::TContainer container;
  //! Iterator base type.
  typedef NTokenizer::NIterators::CTokenizerIterator::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = false; //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = false; //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = false; //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false; //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = false; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = false; //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = false; //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tokenizer/iterators/CTokenizerIterator.inl>
/*==========================================================================*/
#endif
