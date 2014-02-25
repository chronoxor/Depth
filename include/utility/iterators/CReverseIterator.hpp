/*!
 *  \file    CReverseIterator.hpp Reverse iterator wrapper class. It reverses
 *           steps operations of the backward iterator.
 *  \brief   Reverse iterator wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reverse iterator wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   20.08.2006 21:53:29

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
#ifndef __CREVERSEITERATOR_HPP__
#define __CREVERSEITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
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
//! Reverse iterator wrapper class.
/*!
    This iterator wrapper reverses steps of the iterations. So 'stepForward()'
    operation becomes 'stepBackward()' and 'stepBackward()' operation  becomes
    'stepForward()'.
*/
template <class T_BackwardIterator>
class CReverseIterator :
  public T_BackwardIterator
{
  //! Type for MConceptIteratorAnyBackward constraint checking.
  typedef T_BackwardIterator TIteratorAnyBackwardCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CReverseIterator<T_BackwardIterator> TDepthCheckType;

  // Check T_BackwardIterator class constraint to be an any move backward iterator.
  REQUIRES_CONCEPT1(NConcept::NIterators, MConceptIteratorAnyBackward, TIteratorAnyBackwardCheckType);
  // Check CReverseIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef typename CReverseIterator<T_BackwardIterator>::TType TType;
  //! Iterator return type.
  typedef typename CReverseIterator<T_BackwardIterator>::TReturn TReturn;
  //! Iterator container type.
  typedef typename CReverseIterator<T_BackwardIterator>::TContainer TContainer;
  //! Iterator base type.
  typedef typename CReverseIterator<T_BackwardIterator>::TIterator TIterator;

  //! Default class constructor.
  CReverseIterator();
  //! Initialize with backward iterator.
  /*!
      \param a_crBackwardIterator - Constant reference to the backward iterator instance.
  */
  CReverseIterator(const T_BackwardIterator& a_crBackwardIterator);
  //! Class virtual destructor.
  virtual ~CReverseIterator();

  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CReverseIterator<T_BackwardIterator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CReverseIterator<T_BackwardIterator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CReverseIterator<T_BackwardIterator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CReverseIterator<T_BackwardIterator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherBackwardIterator>
  friend CReverseIterator<T_OtherBackwardIterator> operator + (const CReverseIterator<T_OtherBackwardIterator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherBackwardIterator>
  friend CReverseIterator<T_OtherBackwardIterator> operator - (const CReverseIterator<T_OtherBackwardIterator>& a_crInstance, const Tuint a_cStepCount);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CReverseIterator<T_BackwardIterator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CReverseIterator<T_BackwardIterator> getBackward() const;

  // IIteratorMoveBackward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  //! Serialize CReverseIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CReverseIterator class instances.
  /*!
      \param a_rInstance - Reference to another CReverseIterator class instance.
  */
  void swap(CReverseIterator<T_BackwardIterator>& a_rInstance);
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
//! Traits meta-class: reverse iterator's traits specialization.
template <class T_BackwardIterator>
class MTraitsIterator<NUtility::NIterators::CReverseIterator<T_BackwardIterator> > :
  public MType<NUtility::NIterators::CReverseIterator<T_BackwardIterator> >
{
public:
  //! Iterator value type.
  typedef typename NUtility::NIterators::CReverseIterator<T_BackwardIterator>::TType value;
  //! Iterator return type.
  typedef typename NUtility::NIterators::CReverseIterator<T_BackwardIterator>::TReturn result;
  //! Iterator container type.
  typedef typename NUtility::NIterators::CReverseIterator<T_BackwardIterator>::TContainer container;
  //! Iterator base type.
  typedef typename NUtility::NIterators::CReverseIterator<T_BackwardIterator>::TIterator iterator;

  static const Tbool isConst = MTraitsIterator<T_BackwardIterator>::isConst;                         //!< Is iterator constant?
  static const Tbool isCircled = MTraitsIterator<T_BackwardIterator>::isCircled;                     //!< Is iterator container circled?
  static const Tbool isMoveForward = MTraitsIterator<T_BackwardIterator>::isMoveForward;             //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward = MTraitsIterator<T_BackwardIterator>::isMoveBackward;           //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom = MTraitsIterator<T_BackwardIterator>::isMoveRandom;               //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative = MTraitsIterator<T_BackwardIterator>::isMoveAssociative;     //!< Is iterator supports associative moving?
  static const Tbool isMoveTree = MTraitsIterator<T_BackwardIterator>::isMoveTree;                   //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph = MTraitsIterator<T_BackwardIterator>::isMoveGraph;                 //!< Is iterator supports graph moving?
  static const Tbool isInsertForward = MTraitsIterator<T_BackwardIterator>::isInsertForward;         //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward = MTraitsIterator<T_BackwardIterator>::isInsertBackward;       //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom = MTraitsIterator<T_BackwardIterator>::isInsertRandom;           //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = MTraitsIterator<T_BackwardIterator>::isInsertAssociative; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree = MTraitsIterator<T_BackwardIterator>::isInsertTree;               //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph = MTraitsIterator<T_BackwardIterator>::isInsertGraph;             //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward = MTraitsIterator<T_BackwardIterator>::isRemoveForward;         //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward = MTraitsIterator<T_BackwardIterator>::isRemoveBackward;       //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom = MTraitsIterator<T_BackwardIterator>::isRemoveRandom;           //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = MTraitsIterator<T_BackwardIterator>::isRemoveAssociative; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree = MTraitsIterator<T_BackwardIterator>::isRemoveTree;               //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph = MTraitsIterator<T_BackwardIterator>::isRemoveGraph;             //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/iterators/CReverseIterator.inl>
/*==========================================================================*/
#endif
