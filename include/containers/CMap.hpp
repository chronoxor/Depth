/*!
 *  \file    CMap.hpp Template map container class.
 *  \brief   Template map container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template map container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template structures and containers
    VERSION:   1.0
    CREATED:   27.09.2006 03:31:26

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
#ifndef __CMAP_HPP__
#define __CMAP_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FMapComparator.hpp>
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
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Key&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CMapIterator;
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Key&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CMapIteratorConst;
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
using namespace NIterators;
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template map container class.
/*!
    Maps are the good structures for associative keys/value storing. They keep
    only one same key/value instance and have ability to get value by the key.
    Default implementation of  the  map  uses  Red-Black  trees  as  a  sorted
    container for storing keys/values.

    <b>Overview.</b>\n
    An associative array (also  map,  hash,  dictionary,  finite  map,  lookup
    table, and in query-processing an index or index file) is an abstract data
    type composed of a collection of keys and a collection  of  values,  where
    each key is associated with one value. The operation of finding the  value
    associated with a key is called a lookup or indexing, and this is the most
    important operation supported by an associative  array.  The  relationship
    between a key and its value is sometimes called a mapping or binding.  For
    example, if the value associated with the key "bob" is 7, we say that  our
    array maps "bob" to 7. Associative arrays are very closely related to  the
    mathematical concept of a function with a finite domain. As a consequence,
    a common and important use of associative arrays is in memoization.

    From the perspective of a programmer using an associative array, it can be
    viewed as a generalization  of  an  array:  While  a  regular  array  maps
    integers to arbitrarily typed objects (integers, strings,  pointers,  and,
    in an OO sense, objects), an  associative  array  maps  arbitrarily  typed
    objects to arbitrarily typed objects. (Implementations  of  the  two  data
    structures, though, may be considerably different.)

    The operations that are usually defined for an associative array are:
    \li <b>Add:</b> Bind a new key to a new value
    \li <b>Reassign:</b> Bind an old key to a new value
    \li <b>Remove:</b> Unbind a key from a value and remove it  from  the  key
        set
    \li <b>Lookup:</b> Find the value (if any) that is bound to a key

    <b>Examples.</b>\n
    One can think of a telephone book as an example of an  associative  array,
    where names are the keys and phone numbers are the values. Another example
    would be a dictionary where words are the keys  and  definitions  are  the
    values. A database is a sort of generalized associative array.

    <b>Data structures for associative arrays.</b>\n
    Associative arrays are usually used  when  lookup  is  the  most  frequent
    operation. For this reason, implementations are usually designed to  allow
    speedy lookup, at the expense of slower insertion  and  a  larger  storage
    footprint than other data structures (such as association lists).

    <b>Efficient representations.</b>\n
    There are two main efficient data structures used to represent associative
    arrays, the hash table and the self-balancing  binary  search  tree.  Skip
    lists are also an alternative, though relatively new  and  not  as  widely
    used. Relative advantages and disadvantages include:

    \li Hash tables have faster average  lookup  and  insertion  time  (O(1)),
        while some kinds of  balanced  binary  trees  have  faster  worst-case
        lookup and insertion time (O(log n) instead of O(n)). Hash tables have
        seen extensive use in realtime systems, but trees  can  be  useful  in
        high-security realtime systems where untrusted users may  deliberately
        supply information that triggers  worst-case  performance  in  a  hash
        table, although careful design can  remove  that  issue.  Hash  tables
        shine in very large arrays, where O(1) performance is important.  Skip
        lists have worst-case operation time  of  O(n),  but  average-case  of
        O(log n), with much less insertion and deletion overhead than balanced
        binary trees.

    \li Hash tables can have more  compact  storage  for  small  value  types,
        especially when the values are bits.

    \li There are simple persistent versions of balanced binary  trees,  which
        are especially prominent in functional languages.

    \li Building a hash table requires a reasonable hash function for the  key
        type, which can be difficult to  write  well,  while  balanced  binary
        trees and skip lists only require a total ordering on the keys. On the
        other hand, with hash tables the data may be cyclically  or  partially
        ordered without any problems.

    \li Balanced binary trees and skip lists preserve ordering - allowing  one
        to efficiently iterate over the keys in order or to efficiently locate
        an association whose key is nearest to a given value. Hash  tables  do
        not preserve ordering and therefore cannot perform these operations as
        efficiently.

    \li Balanced binary trees can be easily adapted to  efficiently  assign  a
        single value to a large ordered range of keys, or to count the  number
        of keys in an ordered range.

    <b>Association lists.</b>\n
    A simple but  generally  inefficient  type  of  associative  array  is  an
    association list, often called an alist for short, which simply  stores  a
    linked list of key-value pairs. Each lookup does a linear  search  through
    the list looking for a key match.

    Strong advantages of association lists include:
    \li No knowledge is needed about the keys, such as  an  order  or  a  hash
        function.
    \li For small associative arrays, common in some applications, association
        lists can take less time and space than other data structures.
    \li Insertions are done in constant time by consing the new association to
        the head of the list.

    <b>Specialized representations.</b>\n
    If the keys have a specific type,  one  can  often  use  specialized  data
    structures to gain performance. For example,  integer-keyed  maps  can  be
    implemented  using  Patricia  trees  or  Judy  arrays,  and   are   useful
    space-saving replacements for sparse arrays. Because  this  type  of  data
    structure can perform longest-prefix matching, they're particularly useful
    in applications where a single value is assigned to most of a large  range
    of keys with a common prefix except for  a  few  exceptions,  such  as  in
    routing tables.

    String-keyed maps can avoid extra  comparisons  during  lookups  by  using
    tries.

    <b>Multimap.</b>\n
    A variation of the map (associative array) is the multimap, which  is  the
    same as map data structures, but allows a key to be mapped  to  more  than
    one value. Formally, a multimap can be thought of as a regular associative
    array that maps unique keys to  nonempty  multisets  of  values,  although
    actual implementation may vary. C++'s Standard Template  Library  provides
    the "multimap" class for the sorted multiset, and SGI's STL  provides  the
    "hash_multimap" class, which implements a multimap using a hash table.

    <b>Taken from:</b>\n
    Map (computer science) from Wikipedia, the free encyclopedia
    http://en.wikipedia.org/wiki/Map_%28computer_science%29
*/
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate = NAlgorithms::NFunctions::FBoolLessThan<const T_Key&>, template <typename, typename, class> class T_AssociativeContainer = CBinTreeRB, class T_Allocator = NMemory::NAllocators::CAllocatorMemory>
class CMap :
  public NCommon::NContainers::IAssociative<CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CMapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NContainers::IAssociativeConst<CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, CMapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NContainers::IDequeConst<CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Key, T_Value>, CMapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, CMapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
  // Friend class: Map iterator class (CMapIterator).
  friend class CMapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>;
  // Friend class: Constant map iterator class (CMapIteratorConst).
  friend class CMapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Key TKeyConstructibleCheckType;
  //! Type for MConceptConstructible constraint checking.
  typedef T_Value TValueConstructibleCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Key& TKeyPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_KeyBinaryPredicate TKeyPredicate2CheckType;
  //! Type for MConceptAssociative constraint checking.
  typedef T_AssociativeContainer<NUtility::CPair<T_Key, T_Value>, NAlgorithms::NFunctions::FMapComparator<T_Key, T_Value, T_KeyBinaryPredicate>, T_Allocator> TAssociativeContainerCheckType;
  //! Type for MConceptAssociativeConst constraint checking.
  typedef T_AssociativeContainer<NUtility::CPair<T_Key, T_Value>, NAlgorithms::NFunctions::FMapComparator<T_Key, T_Value, T_KeyBinaryPredicate>, T_Allocator> TAssociativeContainerConstCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TDepthCheckType;

  // Check T_Key template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TKeyConstructibleCheckType);
  // Check T_Value template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TValueConstructibleCheckType);
  // Check T_KeyBinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TKeyPredicate2CheckType, TKeyPredicate2ArgumentCheckType, TKeyPredicate2ArgumentCheckType);
  // Check T_AssociativeContainer template argument constraint to be a non constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociative, TAssociativeContainerCheckType);
  // Check T_AssociativeContainer template argument constraint to be a constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociativeConst, TAssociativeContainerConstCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CMap class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container associative key type.
  typedef T_Key TKey;
  //! Container associative value type.
  typedef T_Value TValue;

  //! Container key/value pair type.
  typedef NUtility::CPair<T_Key, T_Value> TType;
  //! Container type.
  typedef CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TContainer;
  //! Non constant map iterator type.
  typedef CMapIterator<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TIterator;
  //! Constant map iterator type.
  typedef CMapIteratorConst<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TIteratorConst;

  //! Container's key binary predicate type.
  typedef T_KeyBinaryPredicate TKeyLessThanPredicate;
  //! Base associative container type.
  typedef T_AssociativeContainer<NUtility::CPair<T_Key, T_Value>, NAlgorithms::NFunctions::FMapComparator<T_Key, T_Value, T_KeyBinaryPredicate>, T_Allocator> TAssociativeContainer;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty map.

      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CMap(T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize map with one key and its value.
  /*!
      Create an empty map, then insert key and its value into it.

      \param a_crKey - Constant reference to the key to insert.
      \param a_crValue - Constant reference to the value to insert.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CMap(const T_Key& a_crKey, const T_Value& a_crValue, T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize map with one key/value pair.
  /*!
      Create an empty map, then insert key/value pair into it.

      \param a_crKeyValuePair - Constant reference to the key/value pair to insert.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CMap(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair, T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMap class.
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CMap(const CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance, T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CMap();

  //! Operator: Assign another CMap class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMap class.
      \return Reference to the current class instance.
  */
  CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator = (const CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Operator: Insert key/value pair into map.
  /*!
      \param a_crKeyValuePair - Constant reference to the key/value pair to insert.
      \return Reference to the current class instance.
  */
  CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator += (const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair);
  //! Operator: Insert another map into map.
  /*!
      \param a_crMap - Constant reference to the map to insert.
      \return Reference to the current class instance.
  */
  CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator += (const CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crMap);
  //! Operator: Remove key from map.
  /*!
      \param a_crKey - Constant reference to the key to remove.
      \return Reference to the current class instance.
  */
  CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -= (const T_Key& a_crKey);
  //! Operator: Remove another map from map.
  /*!
      \param a_crMap - Constant reference to the map to remove.
      \return Reference to the current class instance.
  */
  CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -= (const CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crMap);

  //! Operator: Return non constant iterator to the map value with given key.
  /*!
      \param a_crKey - Constant reference to the searching key.
      \return Non constant iterator with given key or invalid empty iterator.
  */
  TIterator operator [] (const T_Key& a_crKey);
  //! Operator: Return constant iterator to the map value with given key.
  /*!
      \param a_crKey - Constant reference to the searching key.
      \return Constant iterator with given key or invalid empty iterator.
  */
  TIteratorConst operator [] (const T_Key& a_crKey) const;

  //! Set another CMap class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMap class.
      \return true  - if another map was successfully set. \n
              false - if another map was not successfully set. \n
  */
  Tbool set(const CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IContainerConst interface overriding methods.
  virtual Tbool isEmpty() const;
  virtual Tuint getSize() const;

  // IAccociative interface overriding methods.
  virtual Tbool insert(const T_Key& a_crKey, const T_Value& a_crValue);
  virtual Tbool insert(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair);
  virtual Tbool insert(const CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crMap);
  virtual Tbool remove(const T_Key& a_crKey, const Tbool a_cRemoveSame = false);
  virtual Tbool remove(const CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crMap, const Tbool a_cRemoveSame = false);

  // IAccociativeConst interface overriding methods.
  virtual Tbool isLessThan(const T_Key& a_crKey1, const T_Key& a_crKey2) const;
  virtual TIterator      find(const T_Key& a_crKey);
  virtual TIteratorConst find(const T_Key& a_crKey) const;

  // IDequeConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;

  //! Serialization load CMap class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CMap class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CMap class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CMap class instances.
  /*!
      \param a_rInstance - Reference to another CMap class instance.
  */
  void swap(CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance);

private:
  T_AssociativeContainer<NUtility::CPair<T_Key, T_Value>, NAlgorithms::NFunctions::FMapComparator<T_Key, T_Value, T_KeyBinaryPredicate>, T_Allocator> m_AssociativeContainer; //!< Associative container for the map.
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
//! Traits meta-class: map container traits specialization.
template <typename T_Key, typename T_Value, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class MTraitsContainer<NContainers::CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> > :
  public MType<NContainers::CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CMap<T_Key, T_Value, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIteratorConst citerator;

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
#include <Depth/include/containers/iterators/CMapIterator.hpp>
#include <Depth/include/containers/iterators/CMapIteratorConst.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/containers/CMap.inl>
/*==========================================================================*/
//! \example example-containers-CMap.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CMap.cpp
/*==========================================================================*/
#endif
