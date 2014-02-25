/*!
 *  \file    CHashTableIterator.hpp Hash table non constant iterator
 *           definitions. It gives ability to get and modify hash table items.
 *  \brief   Hash table non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Hash table non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   12.06.2008 23:55:07

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
#ifndef __CHASHTABLEITERATOR_HPP__
#define __CHASHTABLEITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorInsertAssociative.hpp>
#include <Depth/include/common/iterators/IIteratorMoveAssociative.hpp>
#include <Depth/include/common/iterators/IIteratorMoveBackward.hpp>
#include <Depth/include/common/iterators/IIteratorRemoveAssociative.hpp>
#include <Depth/include/containers/CHashTable.hpp>
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
//! Hash table non constant iterator class.
/*!
    Hash table non constant iterator represents hash table iterations  method.
    With this iterator you can perform looking into hash table items and  also
    modify them.
*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
class CHashTableIterator :
  public NCommon::NIterators::IIterator<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveBackward<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >,
  public NCommon::NIterators::IIteratorInsertAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >,
  public NCommon::NIterators::IIteratorRemoveAssociative<CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>, T_Key, T_Value, NUtility::CPair<T_Key, T_Value>, T_Value, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >
{
  // Friend class: Hash table class (CHashTable).
  friend class CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>;
  // Friend class: Chain hash table class (CHashTableChain).
  friend class CHashTableChain<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>;
  // Friend class: Open address hash table class (CHashTableOpenAddress).
  friend class CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>;
  // Friend class: Hash table constant iterator class (CHashTableIteratorConst).
  friend class CHashTableIteratorConst<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Key TKeyConstructibleCheckType;
  //! Type for MConceptConstructible constraint checking.
  typedef T_Value TValueConstructibleCheckType;
  //! Type for MConceptHashFunction argument constraint checking.
  typedef const T_Key& TKeyHashFunctionArgumentCheckType;
  //! Type for MConceptHashFunction constraint checking.
  typedef T_KeyHashFunction TKeyHashFunctionCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Key& TKeyPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_KeyBinaryPredicate TKeyPredicate2CheckType;
  //! Type for MConceptIResizePolicy constraint checking.
  typedef T_ResizePolicy TResizePolicyCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> TDepthCheckType;

  // Check T_Key template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TKeyConstructibleCheckType);
  // Check T_Value template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TValueConstructibleCheckType);
  // Check T_KeyHashFunction template argument constraint to be a suitable hash function.
  REQUIRES_CONCEPT2(NConcept::NFunctions, MConceptHashFunction, TKeyHashFunctionCheckType, TKeyHashFunctionArgumentCheckType);
  // Check T_KeyBinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TKeyPredicate2CheckType, TKeyPredicate2ArgumentCheckType, TKeyPredicate2ArgumentCheckType);
  // Check T_ResizePolicy template argument constraint to be a resize policy.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIResizePolicy, TResizePolicyCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CHashTableIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator associative key type.
  typedef T_Key TKey;
  //! Iterator associative value type.
  typedef T_Value TValue;

  //! Iterator value type.
  typedef NUtility::CPair<T_Key, T_Value> TType;
  //! Iterator return type.
  typedef T_Value TReturn;
  //! Iterator container type.
  typedef CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> TIterator;

  //! Container's key hash function type.
  typedef T_KeyHashFunction TKeyHashFunction;
  //! Container's key binary predicate type.
  typedef T_KeyBinaryPredicate TKeyLessThanPredicate;
  //! Container resize policy type.
  typedef T_ResizePolicy TResizePolicy;
  //! Container allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CHashTableIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashTableIterator class.
  */
  CHashTableIterator(const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CHashTableIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherKey, typename T_OtherValue, class T_OtherKeyHashFunction, typename T_OtherKeyBinaryPredicate, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator == (const CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CHashTableIteratorConst<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherKey, typename T_OtherValue, class T_OtherKeyHashFunction, typename T_OtherKeyBinaryPredicate, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator == (const CHashTableIteratorConst<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherKey, typename T_OtherValue, class T_OtherKeyHashFunction, typename T_OtherKeyBinaryPredicate, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator == (const CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherKey, typename T_OtherValue, class T_OtherKeyHashFunction, typename T_OtherKeyBinaryPredicate, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator != (const CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CHashTableIteratorConst<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherKey, typename T_OtherValue, class T_OtherKeyHashFunction, typename T_OtherKeyBinaryPredicate, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator != (const CHashTableIteratorConst<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherKey, typename T_OtherValue, class T_OtherKeyHashFunction, typename T_OtherKeyBinaryPredicate, class T_OtherResizePolicy, class T_OtherAllocator>
  friend Tbool operator != (const CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance1, const CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& operator = (const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherKey, typename T_OtherValue, class T_OtherKeyHashFunction, typename T_OtherKeyBinaryPredicate, class T_OtherResizePolicy, class T_OtherAllocator>
  friend CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator> operator + (const CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherKey, typename T_OtherValue, class T_OtherKeyHashFunction, typename T_OtherKeyBinaryPredicate, class T_OtherResizePolicy, class T_OtherAllocator>
  friend CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator> operator - (const CHashTableIterator<T_OtherKey, T_OtherValue, T_OtherKeyHashFunction, T_OtherKeyBinaryPredicate, T_OtherResizePolicy, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Find iterator with given key in hash table.
  /*!
      \param a_crKey - Constant reference to the searching key.
      \return Iterator with given key or invalid empty iterator.
  */
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> operator [] (const T_Key& a_crKey) const;

  //! Set another CHashTableIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashTableIterator class.
  */
  void set(const CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> getBackward() const;

  //! Get constant reference to the hash table iterator key.
  /*!
      Method returns constant reference to the hash table iterator  key.  Note
      that result may be  broken  if  iterator  is  not  initialized.  So  use
      'isValid()' method before to check its valid state.

      \return Constant reference to the hash table iterator key.
  */
  virtual const T_Key& getKeyRef() const;
  //! Get constant pointer to the hash table iterator key.
  /*!
      Method returns constant pointer to the hash  table  iterator  key.  Note
      that result  may  be  NULL  if  iterator  is  not  initialized.  So  use
      'isValid()' method before to check its valid state or use NULL  checking
      strategy to define iterator is not initialized state alternatively.

      \return Constant pointer to the hash table iterator key.
  */
  virtual const T_Key* getKeyPtr() const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& getContainerRef() const;
  virtual CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>* getContainerPtr() const;
  virtual T_Value& getValueRef() const;
  virtual T_Value* getValuePtr() const;

  // IIteratorMoveAssociative interface overriding methods.
  virtual CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> find(const T_Key& a_crKey) const;

  // IIteratorMoveBackward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  // IIteratorInsertAssociative interface overriding methods.
  virtual Tbool insert(const T_Key& a_crKey, const T_Value& a_crValue, const Tbool a_cUpdate = false);
  virtual Tbool insert(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair, const Tbool a_cUpdate = false);

  // IIteratorRemoveAssociative interface overriding methods.
  virtual Tbool remove();
  virtual Tbool remove(T_Value& a_rValue);
  virtual Tbool remove(T_Key& a_rKey, T_Value& a_rValue);
  virtual Tbool remove(NUtility::CPair<T_Key, T_Value>& a_rKeyValuePair);

  //! Serialization load CHashTableIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CHashTableIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CHashTableIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CHashTableIterator class instances.
  /*!
      \param a_rInstance - Reference to another CHashTableIterator class instance.
  */
  void swap(CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_rInstance);

private:
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>* m_pContainer;                     //!< Pointer to the iterator container.
  typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode* m_pNode; //!< Pointer to the current hash table node.
  Tuint m_Index;                        //!< Hash table index for the current item.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CHashTableIterator(CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>* a_pContainer);

  //! Get non constant reference to the hash table iterator key/value pair.
  /*!
      Method returns  non  constant  reference  to  the  hash  table  iterator
      key/value pair. This method is unsafe and only for internal usage.

      \return Non constant reference to the hash table iterator key/value pair.
  */
  NUtility::CPair<T_Key, T_Value>& getPairRef() const;
  //! Get non constant pointer to the hash table iterator key/value pair.
  /*!
      Method returns non constant pointer to the hash table iterator key/value
      pair. This method is unsafe and only for internal usage.

      \return Non constant pointer to the hash table iterator key/value pair.
  */
  NUtility::CPair<T_Key, T_Value>* getPairPtr() const;
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
//! Traits meta-class: hash table non constant iterator's traits specialization.
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> > :
  public MType<NContainers::NIterators::CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CHashTableIterator<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = true;  //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = false; //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false; //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = true;  //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = false; //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = false; //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = true;  //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CHashTableIterator.inl>
/*==========================================================================*/
#endif
