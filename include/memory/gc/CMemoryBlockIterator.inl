/*!
 *  \file    CMemoryBlockIterator.inl GC allocated memory blocks iterator
 *           definitions. It gives ability to enumerate all GC allocated
 *           memory blocks.
 *  \brief   Memory blocks iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory blocks iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory garbage collection
    VERSION:   1.0
    CREATED:   25.06.2007 22:47:17

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
#ifndef __CMEMORYBLOCKITERATOR_INL__
#define __CMEMORYBLOCKITERATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NGC {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CMemoryBlockIterator::CMemoryBlockIterator() :
  NCommon::NIterators::IIteratorConst<CMemoryBlockIterator, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>(),
  NCommon::NIterators::IIteratorMoveAssociative<CMemoryBlockIterator, Tcptr, CMemoryBlock, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>(),
  NCommon::NIterators::IIteratorMoveBackward<CMemoryBlockIterator, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>(),
  m_cpContainer(NULL),
  m_cpBlock(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator::CMemoryBlockIterator(const CMemoryBlockContainer* a_cpContainer) :
  NCommon::NIterators::IIteratorConst<CMemoryBlockIterator, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>(),
  NCommon::NIterators::IIteratorMoveAssociative<CMemoryBlockIterator, Tcptr, CMemoryBlock, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>(),
  NCommon::NIterators::IIteratorMoveBackward<CMemoryBlockIterator, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>(),
  m_cpContainer(a_cpContainer),
  m_cpBlock(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator::CMemoryBlockIterator(const CMemoryBlockIterator& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CMemoryBlockIterator, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>(),
  NCommon::NIterators::IIteratorMoveAssociative<CMemoryBlockIterator, Tcptr, CMemoryBlock, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>(),
  NCommon::NIterators::IIteratorMoveBackward<CMemoryBlockIterator, CMemoryBlock, CMemoryBlock, CMemoryBlockContainer>(),
  m_cpContainer(NULL),
  m_cpBlock(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator::~CMemoryBlockIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CMemoryBlockIterator& a_crInstance1, const CMemoryBlockIterator& a_crInstance2)
{ CALL
  return (a_crInstance1.m_cpBlock == a_crInstance2.m_cpBlock);
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CMemoryBlockIterator& a_crInstance1, const CMemoryBlockIterator& a_crInstance2)
{ CALL
  return (a_crInstance1.m_cpBlock != a_crInstance2.m_cpBlock);
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator& CMemoryBlockIterator::operator = (const CMemoryBlockIterator& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator& CMemoryBlockIterator::operator += (const Tuint a_cStepCount)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator& CMemoryBlockIterator::operator -= (const Tuint a_cStepCount)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator& CMemoryBlockIterator::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator& CMemoryBlockIterator::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator CMemoryBlockIterator::operator ++ (int)
{ CALL
  CMemoryBlockIterator temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator CMemoryBlockIterator::operator -- (int)
{ CALL
  CMemoryBlockIterator temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CMemoryBlockIterator operator + (const CMemoryBlockIterator& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CMemoryBlockIterator temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CMemoryBlockIterator operator - (const CMemoryBlockIterator& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CMemoryBlockIterator temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator CMemoryBlockIterator::operator [] (const Tcptr& a_cpPointer) const
{ CALL
  return find(a_cpPointer);
}
/*--------------------------------------------------------------------------*/
inline void CMemoryBlockIterator::set(const CMemoryBlockIterator& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_cpContainer;
  m_cpBlock = a_crInstance.m_cpBlock;
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator CMemoryBlockIterator::getForward() const
{ CALL
  CMemoryBlockIterator it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CMemoryBlockIterator(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator CMemoryBlockIterator::getBackward() const
{ CALL
  CMemoryBlockIterator it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CMemoryBlockIterator(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
inline Tbool CMemoryBlockIterator::isValid() const
{ CALL
  return (isValidContainer() && (m_cpBlock != NULL));
}
/*--------------------------------------------------------------------------*/
inline Tbool CMemoryBlockIterator::isValidContainer() const
{ CALL
  return (m_cpContainer != NULL);
}
/*--------------------------------------------------------------------------*/
inline const CMemoryBlockContainer& CMemoryBlockIterator::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_cpContainer;
}
/*--------------------------------------------------------------------------*/
inline const CMemoryBlockContainer* CMemoryBlockIterator::getContainerPtr() const
{ CALL
  return m_cpContainer;
}
/*--------------------------------------------------------------------------*/
inline const CMemoryBlock& CMemoryBlockIterator::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return *m_cpBlock;
}
/*--------------------------------------------------------------------------*/
inline const CMemoryBlock* CMemoryBlockIterator::getValuePtr() const
{ CALL
  if (isValid())
    return m_cpBlock;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
inline CMemoryBlockIterator CMemoryBlockIterator::find(const Tcptr& a_cpPointer) const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Cannot find GC allocated memory block with given pointer with the invalid iterator container."));

  return m_cpContainer->find(a_cpPointer);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CMemoryBlockIterator::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("GC allocated memory blocks iterator cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CMemoryBlockIterator::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NMemory::NGC::CMemoryBlockIterator")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CMemoryBlockIterator::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void CMemoryBlockIterator::swap(CMemoryBlockIterator& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpContainer, a_rInstance.m_cpContainer);
  NAlgorithms::NCommon::swap(m_cpBlock, a_rInstance.m_cpBlock);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
