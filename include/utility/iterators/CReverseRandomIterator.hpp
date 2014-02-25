/*!
 *  \file    CReverseRandomIterator.hpp Reverse random access iterator wrapper
 *           class. It reverses move operations of the random access iterator.
 *  \brief   Reverse random access iterator wrapper class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reverse random access iterator wrapper class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   16.04.2007 02:28:22

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
#ifndef __CREVERSERANDOMITERATOR_HPP__
#define __CREVERSERANDOMITERATOR_HPP__
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
//! Reverse random access iterator wrapper class.
/*!
    This iterator wrapper  reverses  move  operations  of  the  random  access
    iterator.  So  'stepForward()'  operation  becomes  'stepBackward()'   and
    'stepBackward()'  operation  becomes  'stepForward()'.  For  'stepIndex()'
    operation and for all  'ISeekable'  operations  the  inverse  movement  is
    applied.
*/
template <class T_RandomIterator>
class CReverseRandomIterator :
  public T_RandomIterator
{
  //! Type for MConceptIteratorAnyRandom constraint checking.
  typedef T_RandomIterator TIteratorAnyRandomCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CReverseRandomIterator<T_RandomIterator> TDepthCheckType;

  // Check T_RandomIterator class constraint to be an any move backward iterator.
  REQUIRES_CONCEPT1(NConcept::NIterators, MConceptIteratorAnyRandom, TIteratorAnyRandomCheckType);
  // Check CReverseRandomIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef typename CReverseRandomIterator<T_RandomIterator>::TType TType;
  //! Iterator return type.
  typedef typename CReverseRandomIterator<T_RandomIterator>::TReturn TReturn;
  //! Iterator container type.
  typedef typename CReverseRandomIterator<T_RandomIterator>::TContainer TContainer;
  //! Iterator base type.
  typedef typename CReverseRandomIterator<T_RandomIterator>::TIterator TIterator;

  //! Default class constructor.
  CReverseRandomIterator();
  //! Initialize with random access iterator.
  /*!
      \param a_crRandomIterator - Constant reference to the random access iterator instance.
  */
  CReverseRandomIterator(const T_RandomIterator& a_crRandomIterator);
  //! Class virtual destructor.
  virtual ~CReverseRandomIterator();

  //! Operator: Less than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherRandomIterator>
  friend Tbool operator < (const CReverseRandomIterator<T_OtherRandomIterator>& a_crInstance1, const CReverseRandomIterator<T_OtherRandomIterator>& a_crInstance2);
  //! Operator: More than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <class T_OtherRandomIterator>
  friend Tbool operator > (const CReverseRandomIterator<T_OtherRandomIterator>& a_crInstance1, const CReverseRandomIterator<T_OtherRandomIterator>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <class T_OtherRandomIterator>
  friend Tbool operator <= (const CReverseRandomIterator<T_OtherRandomIterator>& a_crInstance1, const CReverseRandomIterator<T_OtherRandomIterator>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <class T_OtherRandomIterator>
  friend Tbool operator >= (const CReverseRandomIterator<T_OtherRandomIterator>& a_crInstance1, const CReverseRandomIterator<T_OtherRandomIterator>& a_crInstance2);

  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CReverseRandomIterator<T_RandomIterator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CReverseRandomIterator<T_RandomIterator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CReverseRandomIterator<T_RandomIterator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CReverseRandomIterator<T_RandomIterator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherRandomIterator>
  friend CReverseRandomIterator<T_OtherRandomIterator> operator + (const CReverseRandomIterator<T_OtherRandomIterator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherRandomIterator>
  friend CReverseRandomIterator<T_OtherRandomIterator> operator - (const CReverseRandomIterator<T_OtherRandomIterator>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Get new iterator under the given index.
  /*!
      \param a_cIndex - Indexed position to return.
      \return Iterator under the given index.
  */
  CReverseRandomIterator<T_RandomIterator> operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new iterator under the given index.
  /*!
      \param a_cIndex - Indexed position to return.
      \return Iterator under the given index.
  */
  CReverseRandomIterator<T_RandomIterator> operator [] (const Tuint a_cIndex) const;

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CReverseRandomIterator<T_RandomIterator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CReverseRandomIterator<T_RandomIterator> getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CReverseRandomIterator<T_RandomIterator> getIndex(const Tuint a_cIndex) const;

  // IIteratorMoveRandom interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool stepIndex(const Tuint a_cIndex);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialize CReverseRandomIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CReverseRandomIterator class instances.
  /*!
      \param a_rInstance - Reference to another CReverseRandomIterator class instance.
  */
  void swap(CReverseRandomIterator<T_RandomIterator>& a_rInstance);
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
template <class T_RandomIterator>
class MTraitsIterator<NUtility::NIterators::CReverseRandomIterator<T_RandomIterator> > :
  public MType<NUtility::NIterators::CReverseRandomIterator<T_RandomIterator> >
{
public:
  //! Iterator value type.
  typedef typename NUtility::NIterators::CReverseRandomIterator<T_RandomIterator>::TType value;
  //! Iterator return type.
  typedef typename NUtility::NIterators::CReverseRandomIterator<T_RandomIterator>::TReturn result;
  //! Iterator container type.
  typedef typename NUtility::NIterators::CReverseRandomIterator<T_RandomIterator>::TContainer container;
  //! Iterator base type.
  typedef typename NUtility::NIterators::CReverseRandomIterator<T_RandomIterator>::TIterator iterator;

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
#include <Depth/include/utility/iterators/CReverseRandomIterator.inl>
/*==========================================================================*/
#endif
