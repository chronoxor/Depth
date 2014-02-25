/*!
 *  \file    CBoundRandomIterator.hpp Bound random iterator wrapper class.
 *           It wraps given random iterator sequence into the single
 *           random iterator.
 *  \brief   Bound random iterator wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bound random iterator wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   04.04.2007 02:53:34

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
#ifndef __CBOUNDRANDOMITERATOR_HPP__
#define __CBOUNDRANDOMITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyRandom.hpp>
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
//! Bound random iterator wrapper class.
/*!
    This random iterator wrapper bounds  random  iterator  sequence  into  the
    single random iterator. It gives ability to  step  forward,  backward  and
    indexed  inside  the  bound.  So  'stepForward()',  'stepBackward()'   and
    'stepIndex()' operations will work util they does not reach the  start  or
    the end bound.
*/
template <class T_RandomIterator>
class CBoundRandomIterator :
  public T_RandomIterator
{
  //! Type for MConceptIteratorAnyRandom constraint checking.
  typedef T_RandomIterator TIteratorAnyRandomCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CBoundRandomIterator<T_RandomIterator> TDepthCheckType;

  // Check T_RandomIterator class constraint to be an any move Random iterator.
  REQUIRES_CONCEPT1(NConcept::NIterators, MConceptIteratorAnyRandom, TIteratorAnyRandomCheckType);
  // Check CBoundRandomIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef typename CBoundRandomIterator<T_RandomIterator>::TType TType;
  //! Iterator return type.
  typedef typename CBoundRandomIterator<T_RandomIterator>::TReturn TReturn;
  //! Iterator container type.
  typedef typename CBoundRandomIterator<T_RandomIterator>::TContainer TContainer;
  //! Iterator base type.
  typedef typename CBoundRandomIterator<T_RandomIterator>::TIterator TIterator;

  //! Default class constructor.
  CBoundRandomIterator();
  //! Initialize with current random iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current random iterator instance.
  */
  CBoundRandomIterator(const T_RandomIterator& a_crCurrentIterator);
  //! Initialize with current random iterator and the end bound iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current random iterator instance.
      \param a_crEndBoundIterator - Constant reference to the end bound random iterator instance.
  */
  CBoundRandomIterator(const T_RandomIterator& a_crCurrentIterator, const T_RandomIterator& a_crEndBoundIterator);
  //! Initialize with current random iterator, the start bound iterator and the end bound iterator.
  /*!
      \param a_crCurrentIterator - Constant reference to the current random iterator instance.
      \param a_crStartBoundIterator - Constant reference to the start bound random iterator instance.
      \param a_crEndBoundIterator - Constant reference to the end bound random iterator instance.
  */
  CBoundRandomIterator(const T_RandomIterator& a_crCurrentIterator, const T_RandomIterator& a_crStartBoundIterator, const T_RandomIterator& a_crEndBoundIterator);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoundRandomIterator class.
  */
  CBoundRandomIterator(const CBoundRandomIterator<T_RandomIterator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CBoundRandomIterator();

  //! Operator: Assign another current random iterator instance.
  /*!
      \param a_crCurrentIterator - Constant reference to the current random iterator instance.
      \return Reference to the current class instance.
  */
  CBoundRandomIterator<T_RandomIterator>& operator = (const T_RandomIterator& a_crCurrentIterator);
  //! Operator: Assign another CBoundRandomIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoundRandomIterator class.
      \return Reference to the current class instance.
  */
  CBoundRandomIterator<T_RandomIterator>& operator = (const CBoundRandomIterator<T_RandomIterator>& a_crInstance);

  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CBoundRandomIterator<T_RandomIterator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CBoundRandomIterator<T_RandomIterator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CBoundRandomIterator<T_RandomIterator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CBoundRandomIterator<T_RandomIterator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherRandomIterator>
  friend CBoundRandomIterator<T_OtherRandomIterator> operator + (const CBoundRandomIterator<T_OtherRandomIterator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherRandomIterator>
  friend CBoundRandomIterator<T_OtherRandomIterator> operator - (const CBoundRandomIterator<T_OtherRandomIterator>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Get new iterator under the given index.
  /*!
      \param a_cIndex - Indexed position to return.
      \return Iterator under the given index.
  */
  CBoundRandomIterator<T_RandomIterator> operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new iterator under the given index.
  /*!
      \param a_cIndex - Indexed position to return.
      \return Iterator under the given index.
  */
  CBoundRandomIterator<T_RandomIterator> operator [] (const Tuint a_cIndex) const;

  //! Set another current random iterator instance.
  /*!
      \param a_crCurrentIterator - Constant reference to the current random iterator instance.
  */
  void set(const T_RandomIterator& a_crCurrentIterator);
  //! Set another CBoundRandomIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoundRandomIterator class.
  */
  void set(const CBoundRandomIterator<T_RandomIterator>& a_crInstance);

  //! Set the start bound random iterator value.
  /*!
      \param a_crStartBoundIterator - Constant reference to the start bound random iterator instance.
  */
  void setStartBound(const T_RandomIterator& a_crStartBoundIterator);
  //! Set the end bound random iterator value.
  /*!
      \param a_crEndBoundIterator - Constant reference to the end bound random iterator instance.
  */
  void setEndBound(const T_RandomIterator& a_crEndBoundIterator);

  //! Get the start bound random iterator value.
  /*!
      \return Reference to the start bound random iterator value.
  */
  T_RandomIterator& getStartBound();
  //! Get the start bound random iterator value (constant version).
  /*!
      \return Constant reference to the start bound random iterator value.
  */
  const T_RandomIterator& getStartBound() const;
  //! Get the end bound random iterator value.
  /*!
      \return Reference to the end bound random iterator value.
  */
  T_RandomIterator& getEndBound();
  //! Get the end bound random iterator value (constant version).
  /*!
      \return Constant reference to the end bound random iterator value.
  */
  const T_RandomIterator& getEndBound() const;

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CBoundRandomIterator<T_RandomIterator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CBoundRandomIterator<T_RandomIterator> getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CBoundRandomIterator<T_RandomIterator> getIndex(const Tuint a_cIndex) const;

  // IIteratorMoveRandom interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool stepIndex(const Tuint a_cIndex);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialize CBoundRandomIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBoundRandomIterator class instances.
  /*!
      \param a_rInstance - Reference to another CBoundRandomIterator class instance.
  */
  void swap(CBoundRandomIterator<T_RandomIterator>& a_rInstance);

private:
  T_RandomIterator m_StartBoundIterator; //!< Start bound iterator.
  T_RandomIterator m_EndBoundIterator;   //!< End bound iterator.
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
//! Traits meta-class: bound random iterator's traits specialization.
template <class T_RandomIterator>
class MTraitsIterator<NUtility::NIterators::CBoundRandomIterator<T_RandomIterator> > :
  public MType<NUtility::NIterators::CBoundRandomIterator<T_RandomIterator> >
{
public:
  //! Iterator value type.
  typedef typename NUtility::NIterators::CBoundRandomIterator<T_RandomIterator>::TType value;
  //! Iterator return type.
  typedef typename NUtility::NIterators::CBoundRandomIterator<T_RandomIterator>::TReturn result;
  //! Iterator container type.
  typedef typename NUtility::NIterators::CBoundRandomIterator<T_RandomIterator>::TContainer container;
  //! Iterator base type.
  typedef typename NUtility::NIterators::CBoundRandomIterator<T_RandomIterator>::TIterator iterator;

  static const Tbool isConst = MTraitsIterator<T_RandomIterator>::isConst;                         //!< Is iterator constant?
  static const Tbool isCircled = MTraitsIterator<T_RandomIterator>::isCircled;                     //!< Is iterator container circled?
  static const Tbool isMoveForward = MTraitsIterator<T_RandomIterator>::isMoveForward;             //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward = MTraitsIterator<T_RandomIterator>::isMoveBackward;           //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom = MTraitsIterator<T_RandomIterator>::isMoveRandom;               //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative = MTraitsIterator<T_RandomIterator>::isMoveAssociative;     //!< Is iterator supports associative moving?
  static const Tbool isMoveTree = MTraitsIterator<T_RandomIterator>::isMoveTree;                   //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph = MTraitsIterator<T_RandomIterator>::isMoveGraph;                 //!< Is iterator supports graph moving?
  static const Tbool isInsertForward = MTraitsIterator<T_RandomIterator>::isInsertForward;         //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward = MTraitsIterator<T_RandomIterator>::isInsertBackward;       //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom = MTraitsIterator<T_RandomIterator>::isInsertRandom;           //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = MTraitsIterator<T_RandomIterator>::isInsertAssociative; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree = MTraitsIterator<T_RandomIterator>::isInsertTree;               //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph = MTraitsIterator<T_RandomIterator>::isInsertGraph;             //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward = MTraitsIterator<T_RandomIterator>::isRemoveForward;         //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward = MTraitsIterator<T_RandomIterator>::isRemoveBackward;       //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom = MTraitsIterator<T_RandomIterator>::isRemoveRandom;           //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = MTraitsIterator<T_RandomIterator>::isRemoveAssociative; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree = MTraitsIterator<T_RandomIterator>::isRemoveTree;               //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph = MTraitsIterator<T_RandomIterator>::isRemoveGraph;             //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/utility/iterators/CBoundRandomIterator.inl>
/*==========================================================================*/
#endif
