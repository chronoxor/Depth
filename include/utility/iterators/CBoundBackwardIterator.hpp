/*!
 *  \file    CBoundBackwardIterator.hpp Bound backward iterator wrapper
 *           class. It wraps given backward iterator sequence into the
 *           single backward iterator.
 *  \brief   Bound backward iterator wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bound backward iterator wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   03.04.2007 22:35:26

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
#ifndef __CBOUNDBACKWARDITERATOR_HPP__
#define __CBOUNDBACKWARDITERATOR_HPP__
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
//! Bound backward iterator wrapper class.
/*!
    This backward iterator wrapper bounds backward iterator sequence into  the
    single backward iterator. It gives ability to step  forward  and  backward
    inside the bound. So 'stepForward()' and 'stepBackward()'  operations will
    work util they does not reach the start or the end bound.
*/
template <class T_BackwardIterator>
class CBoundBackwardIterator :
  public T_BackwardIterator
{
  //! Type for MConceptIteratorAnyBackward constraint checking.
  typedef T_BackwardIterator TIteratorAnyBackwardCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CBoundBackwardIterator<T_BackwardIterator> TDepthCheckType;

  // Check T_BackwardIterator class constraint to be an any move backward iterator.
  REQUIRES_CONCEPT1(NConcept::NIterators, MConceptIteratorAnyBackward, TIteratorAnyBackwardCheckType);
  // Check CBoundBackwardIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef typename CBoundBackwardIterator<T_BackwardIterator>::TType TType;
  //! Iterator return type.
  typedef typename CBoundBackwardIterator<T_BackwardIterator>::TReturn TReturn;
  //! Iterator container type.
  typedef typename CBoundBackwardIterator<T_BackwardIterator>::TContainer TContainer;
  //! Iterator base type.
  typedef typename CBoundBackwardIterator<T_BackwardIterator>::TIterator TIterator;

  //! Default class constructor.
  CBoundBackwardIterator();
  //! Initialize with current backward iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current backward iterator instance.
  */
  CBoundBackwardIterator(const T_BackwardIterator& a_crCurrentIterator);
  //! Initialize with current backward iterator and the end bound iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current backward iterator instance.
      \param a_crEndBoundIterator - Constant reference to the end bound backward iterator instance.
  */
  CBoundBackwardIterator(const T_BackwardIterator& a_crCurrentIterator, const T_BackwardIterator& a_crEndBoundIterator);
  //! Initialize with current backward iterator, the start bound iterator and the end bound iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current backward iterator instance.
      \param a_crStartBoundIterator - Constant reference to the start bound backward iterator instance.
      \param a_crEndBoundIterator - Constant reference to the end bound backward iterator instance.
  */
  CBoundBackwardIterator(const T_BackwardIterator& a_crCurrentIterator, const T_BackwardIterator& a_crStartBoundIterator, const T_BackwardIterator& a_crEndBoundIterator);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoundBackwardIterator class.
  */
  CBoundBackwardIterator(const CBoundBackwardIterator<T_BackwardIterator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CBoundBackwardIterator();

  //! Operator: Assign another current backward iterator instance.
  /*!
      \param a_crCurrentIterator - Constant reference to the current backward iterator instance.
      \return Reference to the current class instance.
  */
  CBoundBackwardIterator<T_BackwardIterator>& operator = (const T_BackwardIterator& a_crCurrentIterator);
  //! Operator: Assign another CBoundBackwardIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoundBackwardIterator class.
      \return Reference to the current class instance.
  */
  CBoundBackwardIterator<T_BackwardIterator>& operator = (const CBoundBackwardIterator<T_BackwardIterator>& a_crInstance);

  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CBoundBackwardIterator<T_BackwardIterator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CBoundBackwardIterator<T_BackwardIterator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CBoundBackwardIterator<T_BackwardIterator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CBoundBackwardIterator<T_BackwardIterator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherBackwardIterator>
  friend CBoundBackwardIterator<T_OtherBackwardIterator> operator + (const CBoundBackwardIterator<T_OtherBackwardIterator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherBackwardIterator>
  friend CBoundBackwardIterator<T_OtherBackwardIterator> operator - (const CBoundBackwardIterator<T_OtherBackwardIterator>& a_crInstance, const Tuint a_cStepCount);

  //! Set another current backward iterator instance.
  /*!
      \param a_crCurrentIterator - Constant reference to the current backward iterator instance.
  */
  void set(const T_BackwardIterator& a_crCurrentIterator);
  //! Set another CBoundBackwardIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoundBackwardIterator class.
  */
  void set(const CBoundBackwardIterator<T_BackwardIterator>& a_crInstance);

  //! Set the start bound backward iterator value.
  /*!
      \param a_crStartBoundIterator - Constant reference to the start bound backward iterator instance.
  */
  void setStartBound(const T_BackwardIterator& a_crStartBoundIterator);
  //! Set the end bound backward iterator value.
  /*!
      \param a_crEndBoundIterator - Constant reference to the end bound backward iterator instance.
  */
  void setEndBound(const T_BackwardIterator& a_crEndBoundIterator);

  //! Get the start bound backward iterator value.
  /*!
      \return Reference to the start bound backward iterator value.
  */
  T_BackwardIterator& getStartBound();
  //! Get the start bound backward iterator value (constant version).
  /*!
      \return Constant reference to the start bound backward iterator value.
  */
  const T_BackwardIterator& getStartBound() const;
  //! Get the end bound backward iterator value.
  /*!
      \return Reference to the end bound backward iterator value.
  */
  T_BackwardIterator& getEndBound();
  //! Get the end bound backward iterator value (constant version).
  /*!
      \return Constant reference to the end bound backward iterator value.
  */
  const T_BackwardIterator& getEndBound() const;

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CBoundBackwardIterator<T_BackwardIterator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CBoundBackwardIterator<T_BackwardIterator> getBackward() const;

  // IIteratorMoveBackward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  //! Serialize CBoundBackwardIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBoundBackwardIterator class instances.
  /*!
      \param a_rInstance - Reference to another CBoundBackwardIterator class instance.
  */
  void swap(CBoundBackwardIterator<T_BackwardIterator>& a_rInstance);

private:
  T_BackwardIterator m_StartBoundIterator; //!< Start bound iterator.
  T_BackwardIterator m_EndBoundIterator;   //!< End bound iterator.
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
//! Traits meta-class: bound backward iterator's traits specialization.
template <class T_BackwardIterator>
class MTraitsIterator<NUtility::NIterators::CBoundBackwardIterator<T_BackwardIterator> > :
  public MType<NUtility::NIterators::CBoundBackwardIterator<T_BackwardIterator> >
{
public:
  //! Iterator value type.
  typedef typename NUtility::NIterators::CBoundBackwardIterator<T_BackwardIterator>::TType value;
  //! Iterator return type.
  typedef typename NUtility::NIterators::CBoundBackwardIterator<T_BackwardIterator>::TReturn result;
  //! Iterator container type.
  typedef typename NUtility::NIterators::CBoundBackwardIterator<T_BackwardIterator>::TContainer container;
  //! Iterator base type.
  typedef typename NUtility::NIterators::CBoundBackwardIterator<T_BackwardIterator>::TIterator iterator;

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
#include <Depth/include/utility/iterators/CBoundBackwardIterator.inl>
/*==========================================================================*/
#endif
