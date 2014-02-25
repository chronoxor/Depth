/*!
 *  \file    CHashTableChain.hpp Template chain hash table container class.
 *  \brief   Template chain hash table container class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template chain hash table container class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template structures and containers
    VERSION:   1.0
    CREATED:   12.06.2008 20:53:50

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
#ifndef __CHASHTABLECHAIN_HPP__
#define __CHASHTABLECHAIN_HPP__
/*==========================================================================*/
#include <Depth/include/containers/CHashTable.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Template chain hash table container class.
/*!
    Hash tables are efficient structures for  associative  keys/value  storing
    and accessing. They use hash function  to  convert  string  key  into  the
    integer and use the index to quick access value data.

    Chain hash table resolves collisions of the same hash values  by  creating
    linked list for the duplicated hash.
*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
class CHashTableChain :
  public CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>
{
  //! Type for MConceptDepthType constraint checking.
  typedef CHashTableChain<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> TDepthCheckType;

  // Check CHashTableChain class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Container associative key type.
  typedef typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TKey TKey;
  //! Container associative value type.
  typedef typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TValue TValue;

  //! Container key/value pair type.
  typedef typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TType TType;
  //! Container type.
  typedef typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TContainer TContainer;
  //! Non constant hash table iterator type.
  typedef typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIterator TIterator;
  //! Constant hash table iterator type.
  typedef typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIteratorConst TIteratorConst;

  //! Container's key hash function type.
  typedef typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TKeyHashFunction TKeyHashFunction;
  //! Container's key binary predicate type.
  typedef typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TKeyLessThanPredicate TKeyLessThanPredicate;
  //! Container resize policy type.
  typedef typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TResizePolicy TResizePolicy;
  //! Container allocator type.
  typedef typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TAllocator TAllocator;

  //! Default class constructor.
  /*!
      Create an empty hash table.

      \param a_cInitialSize - Hash table initial size (default is 0).
      \param a_cGrowFactor - Hash table grow factor threshold (default is 0.75).
      \param a_fHashFunction - Hash function (default is T_KeyHashFunction()).
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_cResizeFactor - Hash table resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CHashTableChain(const Tuint a_cInitialSize = 0, const Treal a_cGrowFactor = CONSTR(0.75), T_KeyHashFunction a_fHashFunction = T_KeyHashFunction(), T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize hash table with one key and its value.
  /*!
      Create an empty hash table, then insert key and its value into it.

      \param a_crKey - Constant reference to the key to insert.
      \param a_crValue - Constant reference to the value to insert.
      \param a_cInitialSize - Hash table initial size (default is 0).
      \param a_cGrowFactor - Hash table grow factor threshold (default is 0.75).
      \param a_fHashFunction - Hash function (default is T_KeyHashFunction()).
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_cResizeFactor - Hash table resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CHashTableChain(const T_Key& a_crKey, const T_Value& a_crValue, const Tuint a_cInitialSize = 0, const Treal a_cGrowFactor = CONSTR(0.75), T_KeyHashFunction a_fHashFunction = T_KeyHashFunction(), T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Initialize hash table with one key/value pair.
  /*!
      Create an empty hash table, then insert key/value pair into it.

      \param a_crKeyValuePair - Constant reference to the key/value pair to insert.
      \param a_cInitialSize - Hash table initial size (default is 0).
      \param a_cGrowFactor - Hash table grow factor threshold (default is 0.75).
      \param a_fHashFunction - Hash function (default is T_KeyHashFunction()).
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_cResizeFactor - Hash table resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CHashTableChain(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair, const Tuint a_cInitialSize = 0, const Treal a_cGrowFactor = CONSTR(0.75), T_KeyHashFunction a_fHashFunction = T_KeyHashFunction(), T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashTable class.
      \param a_cInitialSize - Hash table initial size (default is 0).
      \param a_cGrowFactor - Hash table grow factor threshold (default is 0.75).
      \param a_fHashFunction - Hash function (default is T_KeyHashFunction()).
      \param a_fLessThan - 'LessThan' binary comparator function (default is T_KeyBinaryPredicate()).
      \param a_cResizeFactor - Hash table resize factor (default is T_ResizePolicy::getDefaultResizeFactor()).
      \param a_crAllocator - Constant reference to the memory allocator (default is T_Allocator()).
  */
  CHashTableChain(const CHashTableChain<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance, const Tuint a_cInitialSize = 0, const Treal a_cGrowFactor = CONSTR(0.75), T_KeyHashFunction a_fHashFunction = T_KeyHashFunction(), T_KeyBinaryPredicate a_fLessThan = T_KeyBinaryPredicate(), const Tuint a_cResizeFactor = T_ResizePolicy::getDefaultResizeFactor(), const T_Allocator& a_crAllocator = T_Allocator());
  //! Class virtual destructor.
  virtual ~CHashTableChain();

  // IContainer interface overriding methods.
  virtual Tbool clear();

  // IAccociativeConst interface overriding methods.
  virtual TIterator      find(const T_Key& a_crKey);
  virtual TIteratorConst find(const T_Key& a_crKey) const;

  // IDequeConst interface overriding methods.
  virtual TIterator      getItFirst();
  virtual TIteratorConst getItFirst() const;
  virtual TIterator      getItLast();
  virtual TIteratorConst getItLast() const;

  // CHashTable class overriding methods.
  virtual Tbool resize(const Tuint a_cSize);

  //! Serialize CHashTableChain class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CHashTableChain class instances.
  /*!
      \param a_rInstance - Reference to another CHashTableChain class instance.
  */
  void swap(CHashTableChain<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_rInstance);

protected:
  struct SHashTableChainNode :          //! Hash table chain node structure.
    public CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode
  {
  public:
    SHashTableChainNode* m_pNext;       //! Pointer to the next value with the same key hash.

    //! Initialize hash table chain node with given key and value.
    /*!
        \param a_crKey - Constant reference to the key.
        \param a_crValue - Constant reference to the value.
        \param a_pNext - Pointer to the next hash table chain node (default is NULL).
    */
    SHashTableChainNode(const T_Key& a_crKey, const T_Value& a_crValue, SHashTableChainNode* a_pNext = NULL);
    //! Initialize hash table chain node with the given key/value pair.
    /*!
        \param a_crKeyValuePair - Constant reference to the key/value pair.
        \param a_pNext - Pointer to the next hash table chain node (default is NULL).
    */
    SHashTableChainNode(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair, SHashTableChainNode* a_pNext = NULL);
  };

  SHashTableChainNode** m_ppHashTable;  //!< Pointer to the chain hash table.

  // CHashTable class overriding methods.
  virtual Tuint stepForward(TIterator& a_rIterator, const Tuint a_cStepCount = 1) const;
  virtual Tuint stepForward(TIteratorConst& a_rIterator, const Tuint a_cStepCount = 1) const;
  virtual Tuint stepBackward(TIterator& a_rIterator, const Tuint a_cStepCount = 1) const;
  virtual Tuint stepBackward(TIteratorConst& a_rIterator, const Tuint a_cStepCount = 1) const;
  virtual Tbool insertInternal(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair, TIterator* a_pIterator = NULL);
  virtual Tbool removeInternal(TIterator& a_rIterator, const Tbool a_cRemoveSame = false);

  //! Internal insert engine. Insert hash table node directly into the hash table.
  /*!
      \param a_cIndex - Index to the parent node.
      \param a_pNode - Pointer to the inserting node.
  */
  void insertInternal(const Tuint a_cIndex, SHashTableChainNode* a_pNode);
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
//! Traits meta-class: chain hash table container traits specialization.
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
class MTraitsContainer<NContainers::CHashTableChain<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> > :
  public MType<NContainers::CHashTableChain<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >
{
public:
  //! Container value type.
  typedef typename NContainers::CHashTableChain<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TType value;
  //! Container type.
  typedef typename NContainers::CHashTableChain<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TContainer container;
  //! Container non constant iterator type.
  typedef typename NContainers::CHashTableChain<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIterator iterator;
  //! Container constant iterator type.
  typedef typename NContainers::CHashTableChain<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIteratorConst citerator;

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
#include <Depth/include/containers/CHashTableChain.inl>
/*==========================================================================*/
//! \example example-containers-CHashTableChain.cpp
/*--------------------------------------------------------------------------*/
//! \test test-containers-CHashTableChain.cpp
/*==========================================================================*/
#endif
