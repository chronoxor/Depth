/*!
 *  \file    CTokenizerInputIterator.hpp Tokenizer input iterator based on the
 *           given input iterator.
 *  \brief   Tokenizer input iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer input iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer details
    VERSION:   1.0
    CREATED:   20.04.2009 01:05:50

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
#ifndef __CTOKENIZERINPUTITERATOR_HPP__
#define __CTOKENIZERINPUTITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/base/MConceptChar.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/tokenizer/details/ITokenizerInputIterator.hpp>
#include <Depth/include/traits/MTraitsCharacter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Tokenizer input iterator class.
/*!
    Tokenizer input iterator class is an adapter iterator for the given  input
    one. It wraps the given iterator  in  order  to  adapt  it  for  tokenizer
    internal usage.
*/
template <class T_Iterator>
class CTokenizerInputIterator :
  public ITokenizerInputIterator
{
  //! Type for MConceptChar constraint checking.
  typedef typename T_Iterator::TType TCharCheckType;
  //! Type for MConceptIteratorAnyForward constraint checking.
  typedef T_Iterator TIteratorAnyForwardCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CTokenizerInputIterator<T_Iterator> TDepthCheckType;

  // Check T_Iterator::TType type constraint to be a character type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptChar, TCharCheckType);
  // Check T_Iterator class constraint to be an any forward iterator.
  REQUIRES_CONCEPT1(NConcept::NIterators, MConceptIteratorAnyForward, TIteratorAnyForwardCheckType);
  // Check CTokenizerInputIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CTokenizerInputIterator();
  //! Initialize with any forward iterator.
  /*!
      \param a_crIterator - Constant reference to the any forward iterator.
  */
  CTokenizerInputIterator(const T_Iterator& a_crIterator);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerInputIterator class.
  */
  CTokenizerInputIterator(const CTokenizerInputIterator<T_Iterator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTokenizerInputIterator();

  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherIterator>
  friend Tbool operator == (const CTokenizerInputIterator<T_OtherIterator>& a_crInstance1, const CTokenizerInputIterator<T_Iterator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherIterator>
  friend Tbool operator != (const CTokenizerInputIterator<T_OtherIterator>& a_crInstance1, const CTokenizerInputIterator<T_OtherIterator>& a_crInstance2);

  //! Operator: Assign any forward iterator.
  /*!
      \param a_crIterator - Constant reference to the any forward iterator.
      \return Reference to the current iterator class instance.
  */
  CTokenizerInputIterator<T_Iterator>& operator = (const T_Iterator& a_crIterator);
  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CTokenizerInputIterator<T_Iterator>& operator = (const CTokenizerInputIterator<T_Iterator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CTokenizerInputIterator<T_Iterator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTokenizerInputIterator<T_Iterator>& operator ++ ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CTokenizerInputIterator<T_Iterator> operator ++ (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherIterator>
  friend CTokenizerInputIterator<T_Iterator> operator + (const CTokenizerInputIterator<T_Iterator>& a_crInstance, const Tuint a_cStepCount);

  //! Set any forward iterator.
  /*!
      \param a_crIterator - Constant reference to the any forward iterator.
  */
  void set(const T_Iterator& a_crIterator);
  //! Set another CTokenizerInputIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerInputIterator class.
  */
  void set(const CTokenizerInputIterator<T_Iterator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CTokenizerInputIterator<T_Iterator> getForward() const;

  // ITokenizerInputIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual const Tuint& getValueRef() const;
  virtual const Tuint* getValuePtr() const;
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);

  // IClonable interface overriding methods.
  virtual ITokenizerInputIterator* clone() const;

  //! Serialize CTokenizerInputIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTokenizerInputIterator class instances.
  /*!
      \param a_rInstance - Reference to another CTokenizerInputIterator class instance.
  */
  void swap(CTokenizerInputIterator<T_Iterator>& a_rInstance);

private:
  T_Iterator m_Iterator;                //!< Wrapped input iterator.
  Tuint m_Value;                        //!< Current input iterator value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tokenizer/details/CTokenizerInputIterator.inl>
/*==========================================================================*/
#endif
