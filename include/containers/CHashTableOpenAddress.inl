/*!
 *  \file    CHashTableOpenAddress.inl Template open address hash table
 *           container class.
 *  \brief   Template open address hash table container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.06.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template open address hash table container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template structures and containers
    VERSION:   1.0
    CREATED:   13.06.2008 21:35:45

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
#ifndef __CHASHTABLEOPENADDRESS_INL__
#define __CHASHTABLEOPENADDRESS_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::CHashTableOpenAddress(const Tuint a_cInitialSize/* = 0 */, const Treal a_cGrowFactor/* = CONSTR(0.75) */, const Tuint a_cProbingStep/* = 1 */, T_KeyHashFunction a_fHashFunction/* = T_KeyHashFunction() */, T_KeyBinaryPredicate a_fLessThan/* = T_KeyBinaryPredicate() */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>(a_cGrowFactor, a_fHashFunction, a_fLessThan, a_cResizeFactor, a_crAllocator),
  m_ProbingStep((a_cProbingStep > 0) ? a_cProbingStep : 1),
  m_ppHashTable(NULL)
{ CALL
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::setGrowFactor(a_cGrowFactor);
  resize(a_cInitialSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::CHashTableOpenAddress(const T_Key& a_crKey, const T_Value& a_crValue, const Tuint a_cInitialSize/* = 0 */, const Treal a_cGrowFactor/* = CONSTR(0.75) */, const Tuint a_cProbingStep/* = 1 */, T_KeyHashFunction a_fHashFunction/* = T_KeyHashFunction() */, T_KeyBinaryPredicate a_fLessThan/* = T_KeyBinaryPredicate() */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>(a_cGrowFactor, a_fHashFunction, a_fLessThan, a_cResizeFactor, a_crAllocator),
  m_ProbingStep((a_cProbingStep > 0) ? a_cProbingStep : 1),
  m_ppHashTable(NULL)
{ CALL
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::setGrowFactor(a_cGrowFactor);
  resize(a_cInitialSize);
  insert(a_crKey, a_crValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::CHashTableOpenAddress(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair, const Tuint a_cInitialSize/* = 0 */, const Treal a_cGrowFactor/* = CONSTR(0.75) */, const Tuint a_cProbingStep/* = 1 */, T_KeyHashFunction a_fHashFunction/* = T_KeyHashFunction() */, T_KeyBinaryPredicate a_fLessThan/* = T_KeyBinaryPredicate() */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>(a_cGrowFactor, a_fHashFunction, a_fLessThan, a_cResizeFactor, a_crAllocator),
  m_ProbingStep((a_cProbingStep > 0) ? a_cProbingStep : 1),
  m_ppHashTable(NULL)
{ CALL
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::setGrowFactor(a_cGrowFactor);
  resize(a_cInitialSize);
  insert(a_crKeyValuePair);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::CHashTableOpenAddress(const CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_crInstance, const Tuint a_cInitialSize/* = 0 */, const Treal a_cGrowFactor/* = CONSTR(0.75) */, const Tuint a_cProbingStep/* = 1 */, T_KeyHashFunction a_fHashFunction/* = T_KeyHashFunction() */, T_KeyBinaryPredicate a_fLessThan/* = T_KeyBinaryPredicate() */, const Tuint a_cResizeFactor/* = T_ResizePolicy::getDefaultResizeFactor() */, const T_Allocator& a_crAllocator/* = T_Allocator() */) :
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>(a_cGrowFactor, a_fHashFunction, a_fLessThan, a_cResizeFactor, a_crAllocator),
  m_ProbingStep((a_cProbingStep > 0) ? a_cProbingStep : 1),
  m_ppHashTable(NULL)
{ CALL
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::setGrowFactor(a_cGrowFactor);
  resize(a_cInitialSize);
  insert(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::~CHashTableOpenAddress()
{ CALL
  clear();
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getProbingStep() const
{ CALL
  return m_ProbingStep;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::stepForward(TIterator& a_rIterator, const Tuint a_cStepCount/* = 1 */) const
{ CALL
  // Check if the iterator is from the current container.
  ASSERT(a_rIterator.getContainerPtr() == this, STR("Iterator should be from the same container."))
  {
    return 0;
  }
  // Check if the iterator is in the valid state.
  ASSERT(a_rIterator.isValid(), STR("Cannot step forward with the invalid non constant hash table iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while (counter > 0)
  {
    Tbool found = false;
    Tuint index = a_rIterator.m_Index;
    while (++index < CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity())
    {
      if (m_ppHashTable[index] != NULL)
      {
        a_rIterator.m_pNode = m_ppHashTable[index];
        a_rIterator.m_Index = index;
        found = true;
        break;
      }
    }
    if (!found)
      break;
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::stepForward(TIteratorConst& a_rIterator, const Tuint a_cStepCount/* = 1 */) const
{ CALL
  // Check if the iterator is from the current container.
  ASSERT(a_rIterator.getContainerPtr() == this, STR("Iterator should be from the same container."))
  {
    return 0;
  }
  // Check if the iterator is in the valid state.
  ASSERT(a_rIterator.isValid(), STR("Cannot step forward with the invalid constant hash table iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while (counter > 0)
  {
    Tbool found = false;
    Tuint index = a_rIterator.m_Index;
    while (++index < CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity())
    {
      if (m_ppHashTable[index] != NULL)
      {
        a_rIterator.m_cpNode = m_ppHashTable[index];
        a_rIterator.m_Index = index;
        found = true;
        break;
      }
    }
    if (!found)
      break;
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::stepBackward(TIterator& a_rIterator, const Tuint a_cStepCount/* = 1 */) const
{ CALL
  // Check if the iterator is from the current container.
  ASSERT(a_rIterator.getContainerPtr() == this, STR("Iterator should be from the same container."))
  {
    return 0;
  }
  // Check if the iterator is in the valid state.
  ASSERT(a_rIterator.isValid(), STR("Cannot step backward with the invalid non constant hash table iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step backward by given steps.
  while (counter > 0)
  {
    Tbool found = false;
    Tuint index = a_rIterator.m_Index;
    while (index-- > 0)
    {
      if (m_ppHashTable[index] != NULL)
      {
        a_rIterator.m_pNode = m_ppHashTable[index];
        a_rIterator.m_Index = index;
        found = true;
        break;
      }
    }
    if (!found)
      break;
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tuint CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::stepBackward(TIteratorConst& a_rIterator, const Tuint a_cStepCount/* = 1 */) const
{ CALL
  // Check if the iterator is from the current container.
  ASSERT(a_rIterator.getContainerPtr() == this, STR("Iterator should be from the same container."))
  {
    return 0;
  }
  // Check if the iterator is in the valid state.
  ASSERT(a_rIterator.isValid(), STR("Cannot step backward with the invalid constant hash table iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step backward by given steps.
  while (counter > 0)
  {
    Tbool found = false;
    Tuint index = a_rIterator.m_Index;
    while (index-- > 0)
    {
      if (m_ppHashTable[index] != NULL)
      {
        a_rIterator.m_cpNode = m_ppHashTable[index];
        a_rIterator.m_Index = index;
        found = true;
        break;
      }
    }
    if (!found)
      break;
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::clear()
{ CALL
  // Delete hash table buffer.
  if (m_ppHashTable != NULL)
  {
    // Delete all hash table nodes.
    for (Tuint i = 0; i < CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity(); ++i)
      if (m_ppHashTable[i] != NULL)
      {
        typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode* node = m_ppHashTable[i];

        // Delete hash table node.
        if (!CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Allocator.deleteOne(node))
        {
          WARNING(STR("Cannot remove hash table node from the hash table (requested size is %u bytes).") COMMA (sizeof(typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode)));
          return false;
        }
        --CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Size;
        ++CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FreeSize;
        m_ppHashTable[i] = NULL;
      }

    // Destroy hash table items.
    if (!CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Allocator.destroyMany(m_ppHashTable, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity()))
    {
      WARNING(STR("Cannot destroy hash table items while clearing the hash table (requested size is %u bytes).") COMMA (sizeof(typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode*) * CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity()));
      return false;
    }
    // Free hash table buffer.
    if (!CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Allocator.freeMany(m_ppHashTable, CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity()))
    {
      WARNING(STR("Cannot free hash table buffer while clearing the hash table (requested size is %u bytes).") COMMA (sizeof(typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode*) * CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity()));
      return false;
    }
  }

  // Update hash table's attributes.
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Size = 0;
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FreeSize = 0;
  CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FullSize = 0;
  m_ppHashTable = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getInsertPosition(const Tuint a_cHash, Tuint& a_rPosition) const
{ CALL
  Tuint new_hash = a_cHash;
  typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode* node = m_ppHashTable[new_hash];
  do
  {
    new_hash = (new_hash + m_ProbingStep) % CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity();
    node = (new_hash != a_cHash) ? m_ppHashTable[new_hash] : NULL;
  } while (node != NULL);

  if ((node == NULL) && (new_hash != a_cHash))
  {
    a_rPosition = new_hash;
    return true;
  }
  else
  {
    WARNING(STR("Hash table does not have any open address."));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::insertInternal(const NUtility::CPair<T_Key, T_Value>& a_crKeyValuePair, TIterator* a_pIterator/* = NULL */)
{ CALL
  // Get new size of the hash table after inserting.
  Tuint new_size = (Tuint)NMath::CMath::ceil((CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FullSize - CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FreeSize + 1) / CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_GrowFactor);
  // Resize the hash table if necessary.
  if (new_size > CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FullSize)
    if (!resize(new_size))
      return false;

  // Check if the hash table is accessible.
  ASSERT((m_ppHashTable != NULL), STR("Hash table is not accessible."))
  {
    return false;
  }

  // Get the hash index of the inserting key.
  Tuint hash = getHashIndex(a_crKeyValuePair.getFirst());

  // Try to get inserting position.
  Tuint position = hash;
  if (m_ppHashTable[position] != NULL)
    if (!getInsertPosition(hash, position))
      return false;

  // Create a new node.
  m_ppHashTable[position] = CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Allocator.template createOne<typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode>(a_crKeyValuePair);
  if (m_ppHashTable[position] == NULL)
  {
    WARNING(STR("Cannot create a new chain hash table node for the inserting into the hash table (requested size is %u bytes).") COMMA (sizeof(typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode)));
    return false;
  }
  --CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FreeSize;
  ++CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Size;

  // Update result iterator.
  if (a_pIterator != NULL)
  {
    a_pIterator->m_pContainer = this;
    a_pIterator->m_pNode = m_ppHashTable[position];
    a_pIterator->m_Index = hash;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::removeInternal(TIterator& a_rIterator, const Tbool a_cRemoveSame/* = false */)
{ CALL
  // Check if the iterator is from the current container.
  ASSERT(a_rIterator.getContainerPtr() == this, STR("Iterator should be from the same container."))
  {
    return false;
  }
  // Check if the iterator is in the valid state.
  ASSERT(a_rIterator.isValid(), STR("Cannot remove key/value pair from the invalid hash table iterator."))
  {
    return false;
  }

  // Get the hash index of the removing key.
  Tuint hash = a_rIterator.m_Index;

  // Get next iterator position.
  TIterator it_new(a_rIterator);
  if (it_new.stepBackward() != 1)
    if (it_new.stepForward() != 1)
    {
      it_new.m_pNode = NULL;
      it_new.m_Index = 0;
    }

  // Remove found item.
  Tbool remove = !a_cRemoveSame;
  if (m_ppHashTable[hash] != NULL)
  {
    Tuint new_hash = hash;
    typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode* node = m_ppHashTable[new_hash];
    while (node != NULL)
    {
      if (!isLessThan(node->m_KeyValuePair.getFirst(), a_rIterator.m_pNode->m_KeyValuePair.getFirst()) && !isLessThan(a_rIterator.m_pNode->m_KeyValuePair.getFirst(), node->m_KeyValuePair.getFirst()))
      {
        // Get next iterator position.
        if (it_new.m_pNode == node)
          if (it_new.stepForward() != 1)
          {
            it_new.m_pNode = NULL;
            it_new.m_Index = 0;
          }

        // Remove same nodes from the second one.
        if (remove)
        {
          if (!CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Allocator.deleteOne(node))
          {
            WARNING(STR("Cannot remove hash table node from the hash table (requested size is %u bytes).") COMMA (sizeof(typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode)));
            return false;
          }
          --CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Size;
        }
        else
          remove = true;

        // Update hash table parameters.
        m_ppHashTable[new_hash] = NULL;
        ++CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FreeSize;

        if (!a_cRemoveSame)
          break;
      }

      // Get next possible open address position.
      new_hash = (new_hash + m_ProbingStep) % CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity();
      node = (new_hash != hash) ? m_ppHashTable[new_hash] : NULL;
    }
    if (a_cRemoveSame)
    {
      typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode* node = a_rIterator.m_pNode;
      if (!CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Allocator.deleteOne(node))
      {
        WARNING(STR("Cannot remove hash table node from the hash table (requested size is %u bytes).") COMMA (sizeof(typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode)));
        return false;
      }
      --CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Size;
    }
  }
  a_rIterator = it_new;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline Tbool CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::resize(const Tuint a_cSize)
{ CALL
  Tbool result = true;
  // Get new size of the hash table after resizing.
  Tuint size = (Tuint)NMath::CMath::ceil((CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FullSize - CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FreeSize) / CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_GrowFactor);
  // Adjust new hash table size.
  if (size < a_cSize)
    size = a_cSize;

  // Clear hash table if necessary.
  if (size == 0)
    return clear();
  // Check if we need buffer reallocation.
  Tuint old_bound = CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity();
  Tuint new_bound = CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.resize(size);
  if ((m_ppHashTable == NULL) || (old_bound != new_bound))
  {
    // Create a new hash table buffer.
    Tuint old_size = ((m_ppHashTable == NULL) ? 0 : old_bound);
    Tuint new_size = CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity();
    typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode** old_buffer = m_ppHashTable;
    typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode** new_buffer = CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Allocator.template allocateMany<typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode*>(new_size);
    if (new_buffer != NULL)
    {
      // Initialize hash table buffer.
      CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Allocator.template initializeMany<typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode*, typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode*>(new_buffer, new_size, NULL);

      // Rehash table.
      CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Size = 0;
      CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FreeSize = size;
      CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FullSize = size;
      m_ppHashTable = new_buffer;
      for (Tuint i = 0; i < old_size; ++i)
        if (old_buffer[i] != NULL)
        {
          typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode* node = old_buffer[i];
          if (node != NULL)
          {
            // Get the hash index of the inserting key.
            Tuint hash = getHashIndex(node->m_KeyValuePair.getFirst());

            // Try to get inserting position.
            Tuint position = hash;
            if ((m_ppHashTable[position] == NULL) || getInsertPosition(hash, position))
            {
              // Insert node into the appropriate position.
              m_ppHashTable[position] = node;
              --CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FreeSize;
              ++CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Size;
            }
            else
              result = false;
          }
        }

      // Free old hash table buffer.
      if (old_buffer != NULL)
      {
        // Destroy old hash table items.
        if (!CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Allocator.destroyMany(old_buffer, old_size))
        {
          WARNING(STR("Cannot destroy old hash table items while resizing the hash table (requested size is %u bytes).") COMMA (sizeof(typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode*) * old_size));
          return false;
        }
        // Free old hash table buffer.
        if (!CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_Allocator.freeMany(old_buffer, old_bound))
        {
          WARNING(STR("Cannot free old hash table buffer while resizing the hash table (requested size is %u bytes).") COMMA (sizeof(typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode*) * old_bound));
          return false;
        }
      }
    }
    else
    {
      // Restore hash table resize policy.
      CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.resize(old_bound);
      WARNING(STR("Cannot allocate new hash table buffer while resizing the hash table (requested size is %u bytes).") COMMA (sizeof(typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode*) * new_size));
      return false;
    }
  }
  else
  {
    // Update hash table parameters.
    CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FreeSize += (size - CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FullSize);
    CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_FullSize = size;
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline typename CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIterator CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::find(const T_Key& a_crKey)
{ CALL
  TIterator it_find;

  // Filling iterator inner structure.
  it_find.m_pContainer = this;

  // Return index for empty hash table.
  if (CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::isEmpty())
    return it_find;

  // Get the hash index of the searching key.
  Tuint hash = getHashIndex(a_crKey);

  // Check the key in the hash table.
  if (m_ppHashTable[hash] != NULL)
  {
    // Find node with the same key.
    Tuint new_hash = hash;
    typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode* node = m_ppHashTable[new_hash];
    do
    {
      if (isLessThan(node->m_KeyValuePair.getFirst(), a_crKey) || isLessThan(a_crKey, node->m_KeyValuePair.getFirst()))
      {
        new_hash = (new_hash + m_ProbingStep) % CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity();
        node = (new_hash != hash) ? m_ppHashTable[new_hash] : NULL;
      }
      else
      {
        it_find.m_pNode = node;
        it_find.m_Index = hash;
        break;
      }
    } while (node != NULL);
  }
  return it_find;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline typename CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIteratorConst CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::find(const T_Key& a_crKey) const
{ CALL
  TIteratorConst it_find;

  // Filling iterator inner structure.
  it_find.m_cpContainer = this;

  // Return index for empty hash table.
  if (CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::isEmpty())
    return it_find;

  // Get the hash index of the searching key.
  Tuint hash = getHashIndex(a_crKey);

  // Check the key in the hash table.
  if (m_ppHashTable[hash] != NULL)
  {
    // Find node with the same key.
    Tuint new_hash = hash;
    const typename CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::SHashTableNode* node = m_ppHashTable[new_hash];
    do
    {
      if (isLessThan(node->m_KeyValuePair.getFirst(), a_crKey) || isLessThan(a_crKey, node->m_KeyValuePair.getFirst()))
      {
        new_hash = (new_hash + m_ProbingStep) % CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity();
        node = (new_hash != hash) ? m_ppHashTable[new_hash] : NULL;
      }
      else
      {
        it_find.m_cpNode = node;
        it_find.m_Index = hash;
        break;
      }
    } while (node != NULL);
  }
  return it_find;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline typename CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIterator CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  // Find first hash table node.
  if (!CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::isEmpty())
    for (Tuint index = 0; index < CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity(); ++index)
      if (m_ppHashTable[index] != NULL)
      {
        it_first.m_pNode = m_ppHashTable[index];
        it_first.m_Index = index;
        break;
      }
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline typename CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIteratorConst CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  // Find first hash table node.
  if (!CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::isEmpty())
    for (Tuint index = 0; index < CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity(); ++index)
      if (m_ppHashTable[index] != NULL)
      {
        it_first.m_cpNode = m_ppHashTable[index];
        it_first.m_Index = index;
        break;
      }
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline typename CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIterator CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  it_last.m_pContainer = this;
  // Find last hash table node.
  if (!CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::isEmpty())
  {
    Tuint index = CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity();
    while (index-- > 0)
    {
      if (m_ppHashTable[index] != NULL)
      {
        it_last.m_pNode = m_ppHashTable[index];
        it_last.m_Index = index;
        break;
      }
    }
  }
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline typename CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::TIteratorConst CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  it_last.m_cpContainer = this;
  // Find last hash table node.
  if (!CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::isEmpty())
  {
    Tuint index = CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::m_ResizePolicy.getHiCapacity();
    while (index-- > 0)
    {
      if (m_ppHashTable[index] != NULL)
      {
        it_last.m_cpNode = m_ppHashTable[index];
        it_last.m_Index = index;
        break;
      }
    }
  }
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, class T_KeyHashFunction, typename T_KeyBinaryPredicate, class T_ResizePolicy, class T_Allocator>
inline void CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>::swap(CHashTableOpenAddress<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>&)(*this), (CHashTable<T_Key, T_Value, T_KeyHashFunction, T_KeyBinaryPredicate, T_ResizePolicy, T_Allocator>&)a_rInstance);
  NAlgorithms::NCommon::swap(m_ProbingStep, a_rInstance.m_ProbingStep);
  NAlgorithms::NCommon::swap(m_ppHashTable, a_rInstance.m_ppHashTable);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
