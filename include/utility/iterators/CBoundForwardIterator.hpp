/*!
 *  \file    CBoundForwardIterator.hpp Bound forward iterator wrapper class.
 *           It wraps given forward iterator sequence into the single forward
 *           iterator.
 *  \brief   Bound forward iterator wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bound forward iterator wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   03.04.2007 21:05:52

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
#ifndef __CBOUNDFORWARDITERATOR_HPP__
#define __CBOUNDFORWARDITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Bound forward iterator wrapper class.
/*!
    This forward iterator wrapper bounds forward iterator  sequence  into  the
    single forward iterator. It gives  ability  to  step  forward  inside  the
    bound. So 'stepForward()' operations will work util it does not reache the
    end bound.
*/
template <class T_ForwardIterator>
class CBoundForwardIterator :
  public T_ForwardIterator
{
  //! Type for MConceptIteratorAnyForward constraint checking.
  typedef T_ForwardIterator TIteratorAnyForwardCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CBoundForwardIterator<T_ForwardIterator> TDepthCheckType;

  // Check T_ForwardIterator class constraint to be an any move forward iterator.
  REQUIRES_CONCEPT1(NConcept::NIterators, MConceptIteratorAnyForward, TIteratorAnyForwardCheckType);
  // Check CBoundForwardIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef typename CBoundForwardIterator<T_ForwardIterator>::TType TType;
  //! Iterator return type.
  typedef typename CBoundForwardIterator<T_ForwardIterator>::TReturn TReturn;
  //! Iterator container type.
  typedef typename CBoundForwardIterator<T_ForwardIterator>::TContainer TContainer;
  //! Iterator base type.
  typedef typename CBoundForwardIterator<T_ForwardIterator>::TIterator TIterator;

  //! Default class constructor.
  CBoundForwardIterator();
  //! Initialize with current forward iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current forward iterator instance.
  */
  CBoundForwardIterator(const T_ForwardIterator& a_crCurrentIterator);
  //! Initialize with current forward iterator and the end bound iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current forward iterator instance.
      \param a_crEndBoundIterator - Constant reference to the end bound forward iterator instance.
  */
  CBoundForwardIterator(const T_ForwardIterator& a_crCurrentIterator, const T_ForwardIterator& a_crEndBoundIterator);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoundForwardIterator class.
  */
  CBoundForwardIterator(const CBoundForwardIterator<T_ForwardIterator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CBoundForwardIterator();

  //! Operator: Assign another current forward iterator instance.
  /*!
      \param a_crCurrentIterator - Constant reference to the current forward iterator instance.
      \return Reference to the current class instance.
  */
  CBoundForwardIterator<T_ForwardIterator>& operator = (const T_ForwardIterator& a_crCurrentIterator);
  //! Operator: Assign another CBoundForwardIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoundForwardIterator class.
      \return Reference to the current class instance.
  */
  CBoundForwardIterator<T_ForwardIterator>& operator = (const CBoundForwardIterator<T_ForwardIterator>& a_crInstance);

  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CBoundForwardIterator<T_ForwardIterator>& operator ++ ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CBoundForwardIterator<T_ForwardIterator> operator ++ (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherForwardIterator>
  friend CBoundForwardIterator<T_OtherForwardIterator> operator + (const CBoundForwardIterator<T_OtherForwardIterator>& a_crInstance, const Tuint a_cStepCount);

  //! Set another current forward iterator instance.
  /*!
      \param a_crCurrentIterator - Constant reference to the current forward iterator instance.
  */
  void set(const T_ForwardIterator& a_crCurrentIterator);
  //! Set another CBoundForwardIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoundForwardIterator class.
  */
  void set(const CBoundForwardIterator<T_ForwardIterator>& a_crInstance);

  //! Set the end bound forward iterator value.
  /*!
      \param a_crEndBoundIterator - Constant reference to the end bound forward iterator instance.
  */
  void setEndBound(const T_ForwardIterator& a_crEndBoundIterator);

  //! Get the end bound forward iterator value.
  /*!
      \return Reference to the end bound forward iterator value.
  */
  T_ForwardIterator& getEndBound();
  //! Get the end bound forward iterator value (constant version).
  /*!
      \return Constant reference to the end bound forward iterator value.
  */
  const T_ForwardIterator& getEndBound() const;

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CBoundForwardIterator<T_ForwardIterator> getForward() const;

  // IIteratorMoveForward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);

  //! Serialize CBoundForwardIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBoundForwardIterator class instances.
  /*!
      \param a_rInstance - Reference to another CBoundForwardIterator class instance.
  */
  void swap(CBoundForwardIterator<T_ForwardIterator>& a_rInstance);

private:
  T_ForwardIterator m_EndBoundIterator; //!< End bound iterator.
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
//! Traits meta-class: bound forward iterator's traits specialization.
template <class T_ForwardIterator>
class MTraitsIterator<NUtility::NIterators::CBoundForwardIterator<T_ForwardIterator> > :
  public MType<NUtility::NIterators::CBoundForwardIterator<T_ForwardIterator> >
{
public:
  //! Iterator value type.
  typedef typename NUtility::NIterators::CBoundForwardIterator<T_ForwardIterator>::TType value;
  //! Iterator return type.
  typedef typename NUtility::NIterators::CBoundForwardIterator<T_ForwardIterator>::TReturn result;
  //! Iterator container type.
  typedef typename NUtility::NIterators::CBoundForwardIterator<T_ForwardIterator>::TContainer container;
  //! Iterator base type.
  typedef typename NUtility::NIterators::CBoundForwardIterator<T_ForwardIterator>::TIterator iterator;

  static const Tbool isConst = MTraitsIterator<T_ForwardIterator>::isConst;                         //!< Is iterator constant?
  static const Tbool isCircled = MTraitsIterator<T_ForwardIterator>::isCircled;                     //!< Is iterator container circled?
  static const Tbool isMoveForward = MTraitsIterator<T_ForwardIterator>::isMoveForward;             //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward = MTraitsIterator<T_ForwardIterator>::isMoveBackward;           //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom = MTraitsIterator<T_ForwardIterator>::isMoveRandom;               //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative = MTraitsIterator<T_ForwardIterator>::isMoveAssociative;     //!< Is iterator supports associative moving?
  static const Tbool isMoveTree = MTraitsIterator<T_ForwardIterator>::isMoveTree;                   //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph = MTraitsIterator<T_ForwardIterator>::isMoveGraph;                 //!< Is iterator supports graph moving?
  static const Tbool isInsertForward = MTraitsIterator<T_ForwardIterator>::isInsertForward;         //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward = MTraitsIterator<T_ForwardIterator>::isInsertBackward;       //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom = MTraitsIterator<T_ForwardIterator>::isInsertRandom;           //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = MTraitsIterator<T_ForwardIterator>::isInsertAssociative; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree = MTraitsIterator<T_ForwardIterator>::isInsertTree;               //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph = MTraitsIterator<T_ForwardIterator>::isInsertGraph;             //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward = MTraitsIterator<T_ForwardIterator>::isRemoveForward;         //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward = MTraitsIterator<T_ForwardIterator>::isRemoveBackward;       //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom = MTraitsIterator<T_ForwardIterator>::isRemoveRandom;           //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = MTraitsIterator<T_ForwardIterator>::isRemoveAssociative; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree = MTraitsIterator<T_ForwardIterator>::isRemoveTree;               //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph = MTraitsIterator<T_ForwardIterator>::isRemoveGraph;             //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/iterators/CBoundForwardIterator.inl>
/*==========================================================================*/
#endif
