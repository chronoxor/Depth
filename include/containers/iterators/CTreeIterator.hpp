/*!
 *  \file    CTreeIterator.hpp Tree constant iterator definitions. It
 *           gives ability to get and modify tree items.
 *  \brief   Tree non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    24.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   24.06.2006 23:27:45

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
#ifndef __CTREEITERATOR_HPP__
#define __CTREEITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorInsertTree.hpp>
#include <Depth/include/common/iterators/IIteratorMoveTree.hpp>
#include <Depth/include/common/iterators/IIteratorRemoveTree.hpp>
#include <Depth/include/containers/CTree.hpp>
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
//! Tree non constant iterator class.
/*!
    Tree non constant iterator represents tree iterations  method.  With  this
    iterator you can perform looking into tree items and also modify them.
*/
template <typename T_Type, class T_Allocator>
class CTreeIterator :
  public NCommon::NIterators::IIterator<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >,
  public NCommon::NIterators::IIteratorInsertTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >,
  public NCommon::NIterators::IIteratorRemoveTree<CTreeIterator<T_Type, T_Allocator>, T_Type, T_Type, CTree<T_Type, T_Allocator> >
{
  // Friend class: Tree class (CTree).
  friend class CTree<T_Type, T_Allocator>;
  // Friend class: Tree constant iterator class (CTreeIteratorConst).
  friend class CTreeIteratorConst<T_Type, T_Allocator>;
  // Friend structure: Tree node structure (CTree::STreeNode).
  friend struct CTree<T_Type, T_Allocator>::STreeNode;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TConstructibleCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CTreeIterator<T_Type, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CTreeIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef T_Type TReturn;
  //! Iterator container type.
  typedef CTree<T_Type, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CTreeIterator<T_Type, T_Allocator> TIterator;

  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CTreeIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIterator class.
  */
  CTreeIterator(const CTreeIterator<T_Type, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CTreeIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator == (const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CTreeIteratorConst<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend Tbool operator != (const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance1, const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CTreeIterator<T_Type, T_Allocator>& operator = (const CTreeIterator<T_Type, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CTreeIterator<T_Type, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CTreeIterator<T_Type, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTreeIterator<T_Type, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CTreeIterator<T_Type, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CTreeIterator<T_Type, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CTreeIterator<T_Type, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend CTreeIterator<T_OtherType, T_OtherAllocator> operator + (const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, class T_OtherAllocator>
  friend CTreeIterator<T_OtherType, T_OtherAllocator> operator - (const CTreeIterator<T_OtherType, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Set another CTreeIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CTreeIterator class.
  */
  void set(const CTreeIterator<T_Type, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CTreeIterator<T_Type, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CTreeIterator<T_Type, T_Allocator> getBackward() const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CTree<T_Type, T_Allocator>& getContainerRef() const;
  virtual CTree<T_Type, T_Allocator>* getContainerPtr() const;
  virtual T_Type& getValueRef() const;
  virtual T_Type* getValuePtr() const;

  // IIteratorMoveTree interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool isRoot() const;
  virtual CTreeIterator<T_Type, T_Allocator> getRoot() const;
  virtual CTreeIterator<T_Type, T_Allocator> getParent() const;
  virtual Tuint getSiblingIndex() const;
  virtual Tuint getSiblingsCount() const;
  virtual Tuint getPrevSiblingsCount() const;
  virtual Tuint getNextSiblingsCount() const;
  virtual CTreeIterator<T_Type, T_Allocator> getFirstSibling() const;
  virtual CTreeIterator<T_Type, T_Allocator> getLastSibling() const;
  virtual CTreeIterator<T_Type, T_Allocator> getPrevSibling() const;
  virtual CTreeIterator<T_Type, T_Allocator> getNextSibling() const;
  virtual CTreeIterator<T_Type, T_Allocator> getIndexSibling(const Tuint a_cIndex) const;
  virtual Tuint getChildCount() const;
  virtual CTreeIterator<T_Type, T_Allocator> getFirstChild() const;
  virtual CTreeIterator<T_Type, T_Allocator> getLastChild() const;
  virtual CTreeIterator<T_Type, T_Allocator> getIndexChild(const Tuint a_cIndex) const;

  // IIteratorInsertTree interface overriding methods.
  virtual Tbool insertForward(const T_Type& a_crItem);
  virtual Tbool insertNext(const T_Type& a_crItem);
  virtual Tbool insertBackward(const T_Type& a_crItem);
  virtual Tbool insertPrev(const T_Type& a_crItem);
  virtual Tbool insertParent(const T_Type& a_crItem, const Tbool a_cUpdate = false);
  virtual Tbool insertFirstSibling(const T_Type& a_crItem, const Tbool a_cUpdate = false);
  virtual Tbool insertLastSibling(const T_Type& a_crItem, const Tbool a_cUpdate = false);
  virtual Tbool insertPrevSibling(const T_Type& a_crItem, const Tbool a_cUpdate = false);
  virtual Tbool insertNextSibling(const T_Type& a_crItem, const Tbool a_cUpdate = false);
  virtual Tbool insertIndexSibling(const Tuint a_cIndex, const T_Type& a_crItem, const Tbool a_cUpdate = false);
  virtual Tbool insertFirstChild(const T_Type& a_crItem, const Tbool a_cUpdate = false);
  virtual Tbool insertLastChild(const T_Type& a_crItem, const Tbool a_cUpdate = false);
  virtual Tbool insertIndexChild(const Tuint a_cIndex, const T_Type& a_crItem, const Tbool a_cUpdate = false);
  virtual Tbool insertSubTreeFirstSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate = false);
  virtual Tbool insertSubTreeLastSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate = false);
  virtual Tbool insertSubTreePrevSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate = false);
  virtual Tbool insertSubTreeNextSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate = false);
  virtual Tbool insertSubTreeIndexSibling(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate = false);
  virtual Tbool insertSubTreeFirstChild(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate = false);
  virtual Tbool insertSubTreeLastChild(CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate = false);
  virtual Tbool insertSubTreeIndexChild(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree, const Tbool a_cUpdate = false);
  virtual Tbool flatten(const Tbool a_cChildToRight = true);

  // IIteratorRemoveTree interface overriding methods.
  virtual Tbool removeForward();
  virtual Tbool removeForward(T_Type& a_rItem);
  virtual Tbool removeNext();
  virtual Tbool removeNext(T_Type& a_rItem);
  virtual Tbool removeBackward();
  virtual Tbool removeBackward(T_Type& a_rItem);
  virtual Tbool removePrev();
  virtual Tbool removePrev(T_Type& a_rItem);
  virtual Tbool removeFirstSibling();
  virtual Tbool removeFirstSibling(T_Type& a_rItem);
  virtual Tbool removeLastSibling();
  virtual Tbool removeLastSibling(T_Type& a_rItem);
  virtual Tbool removePrevSibling();
  virtual Tbool removePrevSibling(T_Type& a_rItem);
  virtual Tbool removeNextSibling();
  virtual Tbool removeNextSibling(T_Type& a_rItem);
  virtual Tbool removeIndexSibling(const Tuint a_cIndex);
  virtual Tbool removeIndexSibling(const Tuint a_cIndex, T_Type& a_rItem);
  virtual Tbool removeAllSiblings();
  virtual Tbool removeFirstChild();
  virtual Tbool removeFirstChild(T_Type& a_rItem);
  virtual Tbool removeLastChild();
  virtual Tbool removeLastChild(T_Type& a_rItem);
  virtual Tbool removeIndexChild(const Tuint a_cIndex);
  virtual Tbool removeIndexChild(const Tuint a_cIndex, T_Type& a_rItem);
  virtual Tbool removeAllChild();
  virtual Tuint subTree(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount = 0, const Tuint a_NextSiblingCount = 0);
  virtual Tuint subTreeForwardSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_NextSiblingCount = 0);
  virtual Tuint subTreeBackwardSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount = 0);
  virtual Tuint subTreeFirstSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_NextSiblingCount = 0);
  virtual Tuint subTreeLastSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount = 0);
  virtual Tuint subTreePrevSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount = 0);
  virtual Tuint subTreeNextSibling(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_NextSiblingCount = 0);
  virtual Tuint subTreeIndexSibling(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount = 0, const Tuint a_NextSiblingCount = 0);
  virtual Tbool subTreeAllSiblings(CTree<T_Type, T_Allocator>& a_rSubTree);
  virtual Tuint subTreeFirstChild(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_NextSiblingCount = 0);
  virtual Tuint subTreeLastChild(CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount = 0);
  virtual Tuint subTreeIndexChild(const Tuint a_cIndex, CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount = 0, const Tuint a_NextSiblingCount = 0);
  virtual Tbool subTreeAllChild(CTree<T_Type, T_Allocator>& a_rSubTree);

  //! Serialize CTreeIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CTreeIterator class instances.
  /*!
      \param a_rInstance - Reference to another CTreeIterator class instance.
  */
  void swap(CTreeIterator<T_Type, T_Allocator>& a_rInstance);

private:
  CTree<T_Type, T_Allocator>* m_pContainer;                //!< Pointer to the iterator container.
  typename CTree<T_Type, T_Allocator>::STreeNode* m_pNode; //!< Pointer to the current tree node.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CTreeIterator(CTree<T_Type, T_Allocator>* a_pContainer);

  //! Internal engine of the all extract sub-tree methods.
  /*!
      Method extracts sub-tree from  the  current  sibling  position  and  its
      previous and next siblings. It also checks and updates parent  container
      in the given tree iterator.

      \param a_rIterator - Reference to the tree iterator to be updated.
      \param a_rSubTree - Reference to the destination extracted sub-tree.
      \param a_PrevSiblingCount - Count of previous siblings to extract (default is 0).
      \param a_NextSiblingCount - Count of next siblings to extract (default is 0).
      \return Count of extracted siblings.
  */
  Tuint subTreeEngine(CTreeIterator<T_Type, T_Allocator>& a_rIterator, CTree<T_Type, T_Allocator>& a_rSubTree, const Tuint a_PrevSiblingCount = 0, const Tuint a_NextSiblingCount = 0);
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
//! Traits meta-class: tree non constant iterator's traits specialization.
template <typename T_Type, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CTreeIterator<T_Type, T_Allocator> > :
  public MType<NContainers::NIterators::CTreeIterator<T_Type, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CTreeIterator<T_Type, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CTreeIterator<T_Type, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CTreeIterator<T_Type, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CTreeIterator<T_Type, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = false; //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = true;  //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = true;  //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = true;  //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = false; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = true;  //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = true;  //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = true;  //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = true;  //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CTreeIterator.inl>
/*==========================================================================*/
#endif
