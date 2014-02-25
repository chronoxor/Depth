/*!
 *  \file    CTreeIteratorIndexedChild.hpp Tree indexed child iterator
 *           definitions. It gives ability to do indexed child moving
 *           through the tree nodes.
 *  \brief   Tree indexed child iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree indexed child iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   11.07.2006 21:45:28

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
#ifndef __CTREEITERATORINDEXEDCHILD_HPP__
#define __CTREEITERATORINDEXEDCHILD_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorMoveTree.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
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
//! Tree indexed child iterator class.
/*!
    Tree indexed child iterator represents tree iterations method.  With  this
    iterator you can perform tree  indexed  child  looking  through  the  tree
    items.
*/
template <class T_TreeIterator>
class CTreeIteratorIndexedChild :
  public T_TreeIterator
{
  //! Type for MConceptIteratorMoveTree constraint checking.
  typedef T_TreeIterator TIteratorMoveTreeCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CTreeIteratorIndexedChild<T_TreeIterator> TDepthCheckType;

  // Check T_TreeIterator class constraint to be an any move tree iterator.
  REQUIRES_CONCEPT1(NConcept::NIterators, MConceptIteratorMoveTree, TIteratorMoveTreeCheckType);
  // Check CTreeIteratorIndexedChild class constraint to be a real Depth type.
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

  //! Default class constructor.
  /*
      \param a_cIndex - Index for child iterations (default is 0).
  */
  CTreeIteratorIndexedChild(const Tuint a_cIndex = 0);
  //! Initialize with tree iterator.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator instance.
      \param a_cIndex - Index for child iterations (default is 0).
  */
  CTreeIteratorIndexedChild(const T_TreeIterator& a_crTreeIterator, const Tuint a_cIndex = 0);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorIndexedChild class.
  */
  CTreeIteratorIndexedChild(const CTreeIteratorIndexedChild<T_TreeIterator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTreeIteratorIndexedChild();

  //! Operator: Assign another tree iterator instance.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator instance.
      \return Reference to the current iterator class instance.
  */
  CTreeIteratorIndexedChild<T_TreeIterator>& operator = (const T_TreeIterator& a_crTreeIterator);
  //! Operator: Assign another CTreeIteratorIndexedChild class instance.
  /*!
      \param a_crInstance - Another instance of the CTreeIteratorIndexedChild class.
      \return Reference to the current iterator class instance.
  */
  CTreeIteratorIndexedChild<T_TreeIterator>& operator = (const CTreeIteratorIndexedChild<T_TreeIterator>& a_crInstance);

  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTreeIteratorIndexedChild<T_TreeIterator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTreeIteratorIndexedChild<T_TreeIterator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CTreeIteratorIndexedChild<T_TreeIterator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CTreeIteratorIndexedChild<T_TreeIterator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherTreeIterator>
  friend CTreeIteratorIndexedChild<T_OtherTreeIterator> operator + (const CTreeIteratorIndexedChild<T_OtherTreeIterator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherTreeIterator>
  friend CTreeIteratorIndexedChild<T_OtherTreeIterator> operator - (const CTreeIteratorIndexedChild<T_OtherTreeIterator>& a_crInstance, const Tuint a_cStepCount);

  //! Set another tree iterator instance.
  /*!
      \param a_crTreeIterator - Constant reference to the tree iterator instance.
  */
  void set(const T_TreeIterator& a_crTreeIterator);
  //! Set another CTreeIteratorIndexedChild class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIteratorIndexedChild class.
  */
  void set(const CTreeIteratorIndexedChild<T_TreeIterator>& a_crInstance);

  //! Set child iterator index.
  /*!
      \param a_cIndex - Index for child iterations.
  */
  void setIndex(const Tuint a_cIndex);
  //! Get child iterator index.
  /*!
      \return Current child iterator index.
  */
  Tuint getIndex() const;

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CTreeIteratorIndexedChild<T_TreeIterator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CTreeIteratorIndexedChild<T_TreeIterator> getBackward() const;

  // IIteratorMoveTree interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  //! Serialize CTreeIteratorIndexedChild class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTreeIteratorIndexedChild class instances.
  /*!
      \param a_rInstance - Reference to another CTreeIteratorIndexedChild class instance.
  */
  void swap(CTreeIteratorIndexedChild<T_TreeIterator>& a_rInstance);

private:
  Tuint m_Index;                        //!< Index of the current tree child item.
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
//! Traits meta-class: tree indexed child iterator's traits specialization.
template <class T_TreeIterator>
class MTraitsIterator<NContainers::NIterators::CTreeIteratorIndexedChild<T_TreeIterator> > :
  public MType<NContainers::NIterators::CTreeIteratorIndexedChild<T_TreeIterator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CTreeIteratorIndexedChild<T_TreeIterator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CTreeIteratorIndexedChild<T_TreeIterator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CTreeIteratorIndexedChild<T_TreeIterator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CTreeIteratorIndexedChild<T_TreeIterator>::TIterator iterator;

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
#include <Depth/include/containers/iterators/CTreeIteratorIndexedChild.inl>
/*==========================================================================*/
#endif
