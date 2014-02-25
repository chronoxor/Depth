/*!
 *  \file    CTokenizerInputContainer.hpp Tokenizer input iterator based on
 *           the given input container.
 *  \brief   Tokenizer input container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer input container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer details
    VERSION:   1.0
    CREATED:   20.04.2009 01:55:46

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
#ifndef __CTOKENIZERINPUTCONTAINER_HPP__
#define __CTOKENIZERINPUTCONTAINER_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/concept/base/MConceptChar.hpp>
#include <Depth/include/concept/containers/MConceptContainerConst.hpp>
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
//! Tokenizer input container class.
/*!
    Tokenizer input container class is an adapter iterator for the given input
    container. It wraps the given container in order to adapt it for tokenizer
    internal usage.
*/
template <class T_Container>
class CTokenizerInputContainer :
  public ITokenizerInputIterator
{
  //! Type for MConceptChar constraint checking.
  typedef typename T_Container::TType TCharCheckType;
  //! Type for MConceptContainerConst constraint checking.
  typedef T_Container TContainerConstCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CTokenizerInputContainer<T_Container> TDepthCheckType;

  // Check T_Container::TType type constraint to be a character type.
  REQUIRES_CONCEPT1(NConcept::NBase, MConceptChar, TCharCheckType);
  // Check T_Container class constraint to be a constant container.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptContainerConst, TContainerConstCheckType);
  // Check CTokenizerInputContainer class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CTokenizerInputContainer();
  //! Initialize with constant container.
  /*!
      \param a_crContainer - Constant reference to the constant container.
  */
  CTokenizerInputContainer(const T_Container& a_crContainer);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerInputContainer class.
  */
  CTokenizerInputContainer(const CTokenizerInputContainer<T_Container>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTokenizerInputContainer();

  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherIterator>
  friend Tbool operator == (const CTokenizerInputContainer<T_OtherIterator>& a_crInstance1, const CTokenizerInputContainer<T_Container>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherIterator>
  friend Tbool operator != (const CTokenizerInputContainer<T_OtherIterator>& a_crInstance1, const CTokenizerInputContainer<T_OtherIterator>& a_crInstance2);

  //! Operator: Assign constant container.
  /*!
      \param a_crContainer - Constant reference to the constant container.
      \return Reference to the current iterator class instance.
  */
  CTokenizerInputContainer<T_Container>& operator = (const T_Container& a_crContainer);
  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CTokenizerInputContainer<T_Container>& operator = (const CTokenizerInputContainer<T_Container>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CTokenizerInputContainer<T_Container>& operator += (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTokenizerInputContainer<T_Container>& operator ++ ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CTokenizerInputContainer<T_Container> operator ++ (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherIterator>
  friend CTokenizerInputContainer<T_Container> operator + (const CTokenizerInputContainer<T_Container>& a_crInstance, const Tuint a_cStepCount);

  //! Set constant container.
  /*!
      \param a_crContainer - Constant reference to the constant container.
  */
  void set(const T_Container& a_crContainer);
  //! Set another CTokenizerInputContainer class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTokenizerInputContainer class.
  */
  void set(const CTokenizerInputContainer<T_Container>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CTokenizerInputContainer<T_Container> getForward() const;

  // ITokenizerInputIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual const Tuint& getValueRef() const;
  virtual const Tuint* getValuePtr() const;
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);

  // IClonable interface overriding methods.
  virtual ITokenizerInputIterator* clone() const;

  //! Serialize CTokenizerInputContainer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTokenizerInputContainer class instances.
  /*!
      \param a_rInstance - Reference to another CTokenizerInputContainer class instance.
  */
  void swap(CTokenizerInputContainer<T_Container>& a_rInstance);

private:
  typename T_Container::TIteratorConst m_Iterator; //!< Wrapped input iterator.
  Tuint m_Value;                                   //!< Current input iterator value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/tokenizer/details/CTokenizerInputContainer.inl>
/*==========================================================================*/
#endif
