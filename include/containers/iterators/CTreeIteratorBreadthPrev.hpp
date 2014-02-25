/*!
 *  \file    CTreeIteratorBreadthPrev.hpp Tree breadth previous iterator
 *           definitions. It gives ability to do breadth previous moving
 *           through the tree nodes.
 *  \brief   Tree breadth previous iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree breadth previous iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   13.07.2006 22:18:47

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
#ifndef __CTREEITERATORBREADTHPREV_HPP__
#define __CTREEITERATORBREADTHPREV_HPP__
/*==========================================================================*/
#include <Depth/include/concept/iterators/MConceptIteratorMoveTree.hpp>
#include <Depth/include/containers/CQueue.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Tree breadth previous iterator class.
/*!
    Tree breadth previous iterator represents  tree  iterations  method.  With
    this iterator you can perform tree breadth previous  looking  through  the
    tree items. Note that this iterator is only valid for forward  moving.  So
    if you try to do backward moving it will not do such movement and iterator
    value will not change.
*/
template <class T_TreeIterator, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CTreeIteratorBreadthPrev :
  public T_TreeIterator
{
  //! Type for MConceptIteratorMoveTree constraint checking.
  typedef T_TreeIterator TIteratorMoveTreeCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator> TDepthCheckType;

  // Check T_TreeIterator class constraint to be an any move tree iterator.
  REQUIRES_CONCEPT1(NConcept::NIterators, MConceptIteratorMoveTree, TIteratorMoveTreeCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CTreeIteratorBreadthPrev class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef typename T_TreeIterator::TType TType;
  //! Iterator return type.
  typedef typename T_TreeIterator::TReturn TReturn;
  //! Iterator container type.
  typedef typename T_TreeIterator::TContainer TContainer;
  //! Iterator base type.
  typedef typename T_TreeIterator::TIterator TIterator;

  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CTreeIteratorBreadthPrev();
  //! Initialize with tree iterator.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator instance.
  */
  CTreeIteratorBreadthPrev(const T_TreeIterator& a_crTreeIterator);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorBreadthPrev class.
  */
  CTreeIteratorBreadthPrev(const CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTreeIteratorBreadthPrev();

  //! Operator: Assign another tree iterator class instance.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator instance.
      \return Reference to the current iterator class instance.
  */
  CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>& operator = (const T_TreeIterator& a_crTreeIterator);
  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>& operator = (const CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>& a_crInstance);

  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherTreeIterator, class T_OtherAllocator>
  friend CTreeIteratorBreadthPrev<T_OtherTreeIterator, T_OtherAllocator> operator + (const CTreeIteratorBreadthPrev<T_OtherTreeIterator, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherTreeIterator, class T_OtherAllocator>
  friend CTreeIteratorBreadthPrev<T_OtherTreeIterator, T_OtherAllocator> operator - (const CTreeIteratorBreadthPrev<T_OtherTreeIterator, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Set another tree iterator class instance.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator instance.
      \return true  - if another iterator was successfully set. \n
              false - if another iterator was not successfully set. \n
  */
  Tbool set(const T_TreeIterator& a_crTreeIterator);
  //! Set another CTreeIteratorBreadthPrev class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorBreadthPrev class.
      \return true  - if another iterator was successfully set. \n
              false - if another iterator was not successfully set. \n
  */
  Tbool set(const CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator> getBackward() const;

  // IIteratorMoveTree interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  //! Serialize CTreeIteratorBreadthPrev class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTreeIteratorBreadthPrev class instances.
  /*!
      \param a_rInstance - Reference to another CTreeIteratorBreadthPrev class instance.
  */
  void swap(CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>& a_rInstance);

private:
  CQueue<T_TreeIterator, T_Allocator> m_Cache; //!< Cache of the iteration.
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
//! Traits meta-class: tree breadth previous iterator's traits specialization.
template <class T_TreeIterator, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator> > :
  public MType<NContainers::NIterators::CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CTreeIteratorBreadthPrev<T_TreeIterator, T_Allocator>::TIterator iterator;

  static const Tbool isConst = MTraitsIterator<T_TreeIterator>::isConst;                         //!< Is iterator constant?
  static const Tbool isCircled = MTraitsIterator<T_TreeIterator>::isCircled;                     //!< Is iterator container circled?
  static const Tbool isMoveForward = MTraitsIterator<T_TreeIterator>::isMoveForward;             //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward = MTraitsIterator<T_TreeIterator>::isMoveBackward;           //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom = MTraitsIterator<T_TreeIterator>::isMoveRandom;               //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative = MTraitsIterator<T_TreeIterator>::isMoveAssociative;     //!< Is iterator supports associative moving?
  static const Tbool isMoveTree = MTraitsIterator<T_TreeIterator>::isMoveTree;                   //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph = MTraitsIterator<T_TreeIterator>::isMoveGraph;                 //!< Is iterator supports graph moving?
  static const Tbool isInsertForward = MTraitsIterator<T_TreeIterator>::isInsertForward;         //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward = MTraitsIterator<T_TreeIterator>::isInsertBackward;       //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom = MTraitsIterator<T_TreeIterator>::isInsertRandom;           //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = MTraitsIterator<T_TreeIterator>::isInsertAssociative; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree = MTraitsIterator<T_TreeIterator>::isInsertTree;               //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph = MTraitsIterator<T_TreeIterator>::isInsertGraph;             //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward = MTraitsIterator<T_TreeIterator>::isRemoveForward;         //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward = MTraitsIterator<T_TreeIterator>::isRemoveBackward;       //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom = MTraitsIterator<T_TreeIterator>::isRemoveRandom;           //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = MTraitsIterator<T_TreeIterator>::isRemoveAssociative; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree = MTraitsIterator<T_TreeIterator>::isRemoveTree;               //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph = MTraitsIterator<T_TreeIterator>::isRemoveGraph;             //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CTreeIteratorBreadthPrev.inl>
/*==========================================================================*/
#endif
