/*!
 *  \file    CSet.hpp Template set container class.
 *  \brief   Template set container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template set container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template structures and containers
    VERSION:   1.0
    CREATED:   25.09.2006 23:26:13

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
#ifndef __CSET_HPP__
#define __CSET_HPP__
/*==========================================================================*/
#include <Depth/include/common/containers/IAssociative.hpp>
#include <Depth/include/common/containers/IAssociativeConst.hpp>
#include <Depth/include/common/containers/IDequeConst.hpp>
#include <Depth/include/concept/class/MConceptConstructible.hpp>
#include <Depth/include/concept/containers/MConceptAssociative.hpp>
#include <Depth/include/concept/containers/MConceptAssociativeConst.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/containers/CBinTreeRB.hpp>
#include <Depth/include/memory/allocators/CAllocatorMemory.hpp>
#include <Depth/include/traits/MTraitsContainer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* FORWARD CLASS DECLARATIONS                                               */
/*==========================================================================*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_KeyBinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Key&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSetIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_KeyBinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Key&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSetIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template set container class.
/*!
    Sets are the good structures for associative keys storing. They keep  only
    one key instance and have ability to  detect  if  given  key  is  in  set.
    Default implementation of  the  set  uses  Red-Black  trees  as  a  sorted
    container for storing keys.

    <b>Overview.</b>\n
    In computer science, a set is a collection (container) of  certain  values
    without any particular order, and no repeated values. It corresponds  with
    the mathematical concept of set, but with the restriction that it  has  to
    be finite. Disregarding sequence, and the fact that there are no  repeated
    values, it is the same as a list. A set can  be  seen  as  an  associative
    array (partial mapping) in which the  value  of  each  key-value  pair  is
    ignored.

    Sets can be implemented using various  data  structures.  Ideal  set  data
    structures make it efficient to check if an object is in the set, as  well
    as enabling other useful operations such  as  iterating  through  all  the
    objects in the set, performing a union or intersection  of  two  sets,  or
    taking the complement of a set in some  limited  domain.  Any  associative
    array data structure can be used to implement a set by letting the set  of
    keys be the elements of the set and ignoring the values.  Because  of  the
    similarity to associative arrays, sets are  commonly  implemented  in  the
    same ways, namely, a self-balancing binary search tree for sorted sets, or
    a hash table for unsorted sets. Other popular methods include  arrays  (in
    particular bit arrays). A Bloom map implements  a  set  probabilistically,
    using a very compact representation but risking a small  chance  of  false
    positives on queries.

    However, very few of these data structures support set operations such  as
    union or intersection efficiently. For these operations, more  specialized
    set data structures exist.

    One of the earliest languages to support sets was Pascal;  many  languages
    now include it, whether in the core language or in a standard library. The
    Java programming language offers the Set interface to support  sets  (with
    the HashSet class implementing it using a hash table), and  the  SortedSet
    sub-interface to support sorted sets (with the TreeSet class  implementing
    it using a binary search tree). In C++,  STL  provides  the  "set"  class,
    which implements a sorted set using a binary search tree;  and  SGI's  STL
    provides the "hash_set" class, which implements a set using a hash  table.
    Python has a built-in set type, but no set literal.

    <b>References.</b>\n
    \li Halmos, Paul R., Naive  Set  Theory,  Princeton,  N.J.:  Van  Nostrand
        (1960) ISBN 0-387-90092-6
    \li Stoll,  Robert  R.,  Set  Theory  and  Logic,  Mineola,  N.Y.:   Dover
        Publications (1979) ISBN 0-486-63829-4

    <b>Taken from:</b>\n
    Set (computer science) from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Set_%28computer_science%29
*/
template <typename T_Key, typename T_KeyBinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Key&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CSet :
  public NCommon::NContainers::IAssociative<CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Key, T_Key, CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CSetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NContainers::IAssociativeConst<CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Key, T_Key, CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CSetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NContainers::IDequeConst<CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CSetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
  // Friend class: Set iterator class (CSetIterator).
  friend class CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>;
  // Friend class: Constant set iterator class (CSetIteratorConst).
  friend class CSetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Key TConstructibleCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Key& TKeyPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_KeyBinaryPredicate TKeyPredicate2CheckType;
  //! Type for MConceptAssociative constraint checking.
  typedef T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator> TAssociativeContainerCheckType;
  //! Type for MConceptAssociativeConst constraint checking.
  typedef T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator> TAssociativeContainerConstCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TDepthCheckType;

  // Check T_Key template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_KeyBinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TKeyPredicate2CheckType, TKeyPredicate2ArgumentCheckType, TKeyPredicate2ArgumentCheckType);
  // Check T_AssociativeContainer template argument constraint to be a non constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociative, TAssociativeContainerCheckType);
  // Check T_AssociativeContainer template argument constraint to be a constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociativeConst, TAssociativeContainerConstCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CSet class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container associative key type.
  typedef T_Key TKey;
  //! Container associative value type.
  typedef T_Key TValue;

  //! Container value type.
  typedef T_Key TType;
  //! Container type.
  typedef CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TContainer;
  //! Non constant set iterator type.
  typedef CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TIterator;
  //! Constant set iterator type.
  typedef CSetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TIteratorConst;

  //! Container's key binary predicate type.
  typedef T_KeyBinaryPredicate TKeyLessThanPredicate;
  //! Base associative container type.
  typedef T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator> TAssociativeContainer;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty set.

      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSet(T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize set with one key.
  /*!
      Create an empty set, then insert key into it.

      \param a_crKey - Constant reference to the key to insert.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSet(const T_Key& a_crKey, T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSet class.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CSet(const CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CSet();

  //! Operator: Assign another CSet class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSet class.
      \return Reference to the current class instance.
  */
  CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator = (const CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Operator: Insert key into set.
  /*!
      \param a_crKey - Constant reference to the key to insert.
      \return Reference to the current class instance.
  */
  CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator += (const T_Key& a_crKey);
  //! Operator: Insert another set into set.
  /*!
      \param a_crSet - Constant reference to the set to insert.
      \return Reference to the current class instance.
  */
  CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator += (const CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSet);
  //! Operator: Remove key from set.
  /*!
      \param a_crKey - Constant reference to the key to remove.
      \return Reference to the current class instance.
  */
  CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -= (const T_Key& a_crKey);
  //! Operator: Remove another set from set.
  /*!
      \param a_crSet - Constant reference to the set to remove.
      \return Reference to the current class instance.
  */
  CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -= (const CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSet);

  //! Operator: Return non constant iterator to the set item with given key.
  /*!
      \param a_crKey - Constant reference to the searching key.
      \return Non constant iterator with given value or invalid empty iterator.
  */
  TIterator operator [] (const T_Key& a_crKey);
  //! Operator: Return constant iterator to the set item with given key.
  /*!
      \param a_crKey - Constant reference to the searching key.
      \return Constant iterator with given key or invalid empty iterator.
  */
  TIteratorConst operator [] (const T_Key& a_crKey) const;

  //! Set another CSet class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSet class.
      \return true  - if another set was successfully set. \n
              false - if another set was not successfully set. \n
  */
  Tbool set(const CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IAccociative interface overriding methods.
  virtual Tbool insert(const T_Key& a_crKey);
  virtual Tbool insert(const CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSet);
  virtual Tbool remove(const T_Key& a_crKey, const Tbool a_cRemoveSame = false);
  virtual Tbool remove(const CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crSet, const Tbool a_cRemoveSame = false);

  // IAccociativeConst interface overriding methods.
  virtual Tbool isLessThan(const T_Key& a_crKey1, const T_Key& a_crKey2) const;
  virtual TIterator      find(const T_Key& a_crKey);
  virtual TIteratorConst find(const T_Key& a_crKey) const;

  // IDequeConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;

  //! Serialization load CSet class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CSet class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CSet class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSet class instances.
  /*!
      \param a_rInstance - Reference to another CSet class instance.
  */
  void swap(CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance);

private:
  T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator> m_AssociativeContainer; //!< Associative container for the set.
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
//! Traits meta-class: set container traits specialization.
template <typename T_Key, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class MTraitsContainer<NContainers::CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> > :
  public MType<NContainers::CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst citerator;

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
  static const Tbool isTreeConst        = false; //!< Is container constant tree?
  static const Tbool isGraph            = false; //!< Is container non constant graph?
  static const Tbool isGraphConst       = false; //!< Is container constant graph?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CSetIterator.hpp>
#include <Depth/include/containers/iterators/CSetIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CSet.inl>
/*==========================================================================*/
//! \example example-containers-CSet.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CSet.cpp
/*==========================================================================*/
#endif
