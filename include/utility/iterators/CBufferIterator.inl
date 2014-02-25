/*!
 *  \file    CBufferIterator.inl Byte buffer non constant iterator
 *           definitions. It gives ability to get and modify single
 *           bytes inside the byte buffer and to do random moving
 *           through the bytes.
 *  \brief   Byte buffer non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Byte buffer non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   20.08.2008 01:19:57

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
#ifndef __CBUFFERITERATOR_INL__
#define __CBUFFERITERATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CBufferIterator::CBufferIterator() :
  NCommon::NIterators::IIterator<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::NIterators::IIteratorMoveRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::NIterators::IIteratorInsertRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::NIterators::IIteratorRemoveRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CBufferIterator::CBufferIterator(CBuffer* a_pContainer) :
  NCommon::NIterators::IIterator<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::NIterators::IIteratorMoveRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::NIterators::IIteratorInsertRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::NIterators::IIteratorRemoveRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::ISeekable(),
  m_pContainer(a_pContainer),
  m_Index((a_pContainer != NULL) ? a_pContainer->getSize() : 0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CBufferIterator::CBufferIterator(const CBufferIterator& a_crInstance) :
  NCommon::NIterators::IIterator<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::NIterators::IIteratorMoveRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::NIterators::IIteratorInsertRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::NIterators::IIteratorRemoveRandom<CBufferIterator, Tbyte, Tbyte, CBuffer>(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator::~CBufferIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CBufferIterator& a_crInstance1, const CBufferIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator& CBufferIterator::operator = (const CBufferIterator& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator& CBufferIterator::operator += (const Tuint a_cStepCount)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator& CBufferIterator::operator -= (const Tuint a_cStepCount)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator& CBufferIterator::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator& CBufferIterator::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator CBufferIterator::operator ++ (int)
{ CALL
  CBufferIterator temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator CBufferIterator::operator -- (int)
{ CALL
  CBufferIterator temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CBufferIterator operator + (const CBufferIterator& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CBufferIterator temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CBufferIterator operator - (const CBufferIterator& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CBufferIterator temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator CBufferIterator::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator CBufferIterator::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
inline void CBufferIterator::set(const CBufferIterator& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator CBufferIterator::getForward() const
{ CALL
  CBufferIterator it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CBufferIterator(m_pContainer));
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator CBufferIterator::getBackward() const
{ CALL
  CBufferIterator it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CBufferIterator(m_pContainer));
}
/*--------------------------------------------------------------------------*/
inline CBufferIterator CBufferIterator::getIndex(const Tuint a_cIndex) const
{ CALL
  CBufferIterator it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CBufferIterator(m_pContainer));
}
/*--------------------------------------------------------------------------*/
inline Tbool CBufferIterator::isValid() const
{ CALL
  return (isValidContainer() && (m_Index < m_pContainer->getSize()));
}
/*--------------------------------------------------------------------------*/
inline Tbool CBufferIterator::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
inline CBuffer& CBufferIterator::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
inline CBuffer* CBufferIterator::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
inline Tbyte& CBufferIterator::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_pContainer->m_pBuffer[m_Index];
}
/*--------------------------------------------------------------------------*/
inline Tbyte* CBufferIterator::getValuePtr() const
{ CALL
  if (isValid())
    return &m_pContainer->m_pBuffer[m_Index];
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
inline Tbool CBufferIterator::remove(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  return removeIndex(a_cIndex, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline Tuint CBufferIterator::getSize() const
{ CALL
  return (isValidContainer() ? m_pContainer->getSize() : 0);
}
/*--------------------------------------------------------------------------*/
inline Tbool CBufferIterator::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
inline Tuint CBufferIterator::getPosition() const
{ CALL
  return (isValidContainer() ? m_Index : 0);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CBufferIterator::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::NIterators::CBufferIterator")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CBufferIterator::swap(CBufferIterator& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_Index, a_rInstance.m_Index);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
