/*!
 *  \file    CBinTreeAA.hpp Template A.Andersson balanced binary tree
 *           container class.
 *  \brief   Template A.Andersson balanced binary tree container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template A.Andersson balanced binary tree container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   31.08.2006 22:51:48

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
#ifndef __CBINTREEAA_HPP__
#define __CBINTREEAA_HPP__
/*==========================================================================*/
#include <Depth/include/containers/CBinTree.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template A.Andersson balanced binary tree container class.
/*!
    <b>Overview.</b>\n
    Andersson trees are simple and easy to implement  balanced  binary  search
    trees that are based on the foundations of red black trees.  Consequently,
    Andersson trees have similar performance and structuring properties as red
    black trees without the difficult implementation. Red black trees  are  an
    abstraction of the symmetric binary B-tree, which is a clever  abstraction
    of a B-tree of order 4.  Andersson  trees  are  a  simplification  of  the
    symmetric binary B-tree that use a B-tree of order  3  to  remove  several
    unpleasant cases in the implementation. If the last  two  sentences  meant
    absolutely nothing to you, that's okay. This background isn't necessary to
    understand Andersson trees or implement them well.  Andersson  trees  were
    introduced by Arne Andersson in his  paper  "Balanced  Search  Trees  Made
    Simple". They were further studied by a  few  people,  most  notably  Mark
    Allen Weiss, who discussed them briefly in his books  on  data  structures
    and algorithm analysis.

    Andersson trees are a very simple  alternative  to  the  more  traditional
    balanced binary search trees. The performance properties are very close to
    that of red black trees, and the effort required in implementing  them  is
    minimal for anyone who is comfortable writing basic binary search trees.

    <b>Performance.</b>\n
    The performance of an AA tree is equivalent to the performance of  a  red-
    black tree. While an AA tree makes more rotations than a  red-black  tree,
    the simpler algorithms tend to be faster, and all of this balances out  to
    result in similar performance. A red-black tree is more consistent in  its
    performance than an AA tree, but an AA tree tends  to  be  flatter,  which
    results in slightly faster search times.

    <b>Taken from:</b>\n
    AA tree from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/AA_tree
*/
template <typename T_Type, typename T_BinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Type&>, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CBinTreeAA :
  public CBinTree<T_Type, T_BinaryPredicate, T_Allocator>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator> TDepthCheckType;

  // Check CBinTreeAA class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container associative key type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TKey TKey;
  //! Container associative value type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TValue TValue;

  //! Container value type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TType TType;
  //! Container type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TContainer TContainer;
  //! Non constant binary tree iterator type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIterator TIterator;
  //! Constant binary tree iterator type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst TIteratorConst;

  //! Container binary predicate type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TLessThanPredicate TLessThanPredicate;
  //! Container allocator type.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::TAllocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty AA balanced binary tree.

      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeAA(T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize AA balanced binary tree with one item.
  /*!
      Create an empty AA balanced binary tree, then insert item into it  as  a
      root node.

      \param a_crItem - Constant reference to the item to insert.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeAA(const T_Type& a_crItem, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBinTreeAA class.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_BinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CBinTreeAA(const CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>& a_crInstance, T_BinaryPredicate a_fLessThan = T_BinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CBinTreeAA();

  //! Serialize CBinTreeAA class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CBinTreeAA class instances.
  /*!
      \param a_rInstance - Reference to another CBinTreeAA class instance.
  */
  void swap(CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>& a_rInstance);

protected:
  //! Binary tree node structure.
  typedef typename CBinTree<T_Type, T_BinaryPredicate, T_Allocator>::SBinTreeNode SBinTreeNode;

  // CBinTree class overriding methods.
  virtual Tbool insertAndBalance(SBinTreeNode* a_pNode);
  virtual Tbool removeAndBalance(SBinTreeNode* a_pNode);

private:
  //! Skew AA balanced binary tree node.
  /*!
      Skew is a right rotation when an insertion or deletion  creates  a  left
      red link.

      \param a_pNode - Pointer to the AA balanced binary tree node.
  */
  void skew(SBinTreeNode* a_pNode);
  //! Split AA balanced binary tree node.
  /*!
      Split is a conditional left  rotation  when  an  insertion  or  deletion
      creates two consecutive red links.

      \param a_pNode - Pointer to the AA balanced binary tree node.
      \return true  - if split operation completed successfully. \n
              false - if split operation did not completed successfully. \n
  */
  Tbool split(SBinTreeNode* a_pNode);

  //! Set level value for the given AA balanced binary tree node.
  /*!
      \param a_rNode - Reference to the AA balanced binary tree node.
      \param a_cLevel - Level value.
  */
  static void setLevel(SBinTreeNode& a_rNode, const Tuint a_cLevel);
  //! Get level value of the AA balanced binary tree node.
  /*!
      \param a_crNode - Constant reference to the AA balanced binary tree node.
      \return Level value of the AA balanced binary tree node.
  */
  static Tuint getLevel(const SBinTreeNode& a_crNode);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* CONTAINER TRAITS SPECIALIZATION DECLARATIONS                             */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: A.Andersson balanced binary tree container traits specialization.
template <typename T_Type, typename T_BinaryPredicate, class T_Allocator>
class MTraitsContainer<NContainers::CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator> > :
  public MType<NContainers::CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CBinTreeAA<T_Type, T_BinaryPredicate, T_Allocator>::TIteratorConst citerator;

  static const Tbool isConst            = false; //!< Is container constant?
  static const Tbool isCircleSL         = false; //!< Is container non constant single linked circle?
  static const Tbool isCircleSLConst    = false; //!< Is container constant single linked circle?
  static const Tbool isCircleDL         = false; //!< Is container non constant double linked circle?
  static const Tbool isCircleDLConst    = false; //!< Is container constant double linked circle?
  static const Tbool isStack            = false; //!< Is container non constant stack?
  static const Tbool isStackConst       = false; //!< Is container constant stack?
  static const Tbool isQueue            = false; //!< Is container non constant queue?
  static const Tbool isQueueConst       = true;  //!< Is container constant queue?
  static const Tbool isDeque            = false; //!< Is container non constant deque?
  static const Tbool isDequeConst       = true;  //!< Is container constant deque?
  static const Tbool isRandom           = false; //!< Is container non constant random?
  static const Tbool isRandomConst      = false; //!< Is container constant random?
  static const Tbool isAssociative      = true;  //!< Is container non constant associative?
  static const Tbool isAssociativeConst = true;  //!< Is container constant associative?
  static const Tbool isTree             = false; //!< Is container non constant tree?
  static const Tbool isTreeConst        = true;  //!< Is container constant tree?
  static const Tbool isGraph            = false; //!< Is container non constant graph?
  static const Tbool isGraphConst       = false; //!< Is container constant graph?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/CBinTreeAA.inl>
/*==========================================================================*/
//! \example example-containers-CBinTreeAA.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CBinTreeAA.cpp
/*==========================================================================*/
#endif
