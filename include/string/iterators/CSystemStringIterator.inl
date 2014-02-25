/*!
 *  \file    CSystemStringIterator.inl System string non constant iterator
 *           definitions. It gives ability to get and modify system string
 *           characters and to do random moving through the system string
 *           characters.
 *  \brief   System string non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: System string non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   07.08.2008 02:52:09

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
#ifndef __CSYSTEMSTRINGITERATOR_INL__
#define __CSYSTEMSTRINGITERATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CSystemStringIterator::CSystemStringIterator() :
  NCommon::NIterators::IIterator<CSystemStringIterator, Tbyte, Tbyte, CSystemString>(),
  NCommon::NIterators::IIteratorMoveRandom<CSystemStringIterator, Tbyte, Tbyte, CSystemString>(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator::CSystemStringIterator(CSystemString* a_pContainer) :
  NCommon::NIterators::IIterator<CSystemStringIterator, Tbyte, Tbyte, CSystemString>(),
  NCommon::NIterators::IIteratorMoveRandom<CSystemStringIterator, Tbyte, Tbyte, CSystemString>(),
  NCommon::ISeekable(),
  m_pContainer(a_pContainer),
  m_Index((a_pContainer != NULL) ? a_pContainer->getSize() : 0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator::CSystemStringIterator(const CSystemStringIterator& a_crInstance) :
  NCommon::NIterators::IIterator<CSystemStringIterator, Tbyte, Tbyte, CSystemString>(),
  NCommon::NIterators::IIteratorMoveRandom<CSystemStringIterator, Tbyte, Tbyte, CSystemString>(),
  NCommon::ISeekable(),
  m_pContainer(NULL),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator::~CSystemStringIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CSystemStringIterator& a_crInstance1, const CSystemStringIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CSystemStringIterator& a_crInstance1, const CSystemStringIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CSystemStringIterator& a_crInstance1, const CSystemStringIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CSystemStringIterator& a_crInstance1, const CSystemStringIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CSystemStringIterator& a_crInstance1, const CSystemStringIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CSystemStringIterator& a_crInstance1, const CSystemStringIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator& CSystemStringIterator::operator = (const CSystemStringIterator& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator& CSystemStringIterator::operator += (const Tuint a_cStepCount)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator& CSystemStringIterator::operator -= (const Tuint a_cStepCount)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator& CSystemStringIterator::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator& CSystemStringIterator::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator CSystemStringIterator::operator ++ (int)
{ CALL
  CSystemStringIterator temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator CSystemStringIterator::operator -- (int)
{ CALL
  CSystemStringIterator temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CSystemStringIterator operator + (const CSystemStringIterator& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSystemStringIterator temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CSystemStringIterator operator - (const CSystemStringIterator& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSystemStringIterator temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator CSystemStringIterator::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator CSystemStringIterator::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
inline void CSystemStringIterator::set(const CSystemStringIterator& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator CSystemStringIterator::getForward() const
{ CALL
  CSystemStringIterator it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CSystemStringIterator(m_pContainer));
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator CSystemStringIterator::getBackward() const
{ CALL
  CSystemStringIterator it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CSystemStringIterator(m_pContainer));
}
/*--------------------------------------------------------------------------*/
inline CSystemStringIterator CSystemStringIterator::getIndex(const Tuint a_cIndex) const
{ CALL
  CSystemStringIterator it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CSystemStringIterator(m_pContainer));
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringIterator::isValid() const
{ CALL
  return (isValidContainer() && (m_Index < m_pContainer->getSize()));
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringIterator::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
inline CSystemString& CSystemStringIterator::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
inline CSystemString* CSystemStringIterator::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
inline Tbyte& CSystemStringIterator::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_pContainer->m_pBuffer[m_Index];
}
/*--------------------------------------------------------------------------*/
inline Tbyte* CSystemStringIterator::getValuePtr() const
{ CALL
  if (isValid())
    return &m_pContainer->m_pBuffer[m_Index];
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
inline Tuint CSystemStringIterator::getSize() const
{ CALL
  return (isValidContainer() ? m_pContainer->getSize() : 0);
}
/*--------------------------------------------------------------------------*/
inline Tbool CSystemStringIterator::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
inline Tuint CSystemStringIterator::getPosition() const
{ CALL
  return (isValidContainer() ? m_Index : 0);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CSystemStringIterator::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NIterators::CSystemStringIterator")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CSystemStringIterator::swap(CSystemStringIterator& a_rInstance)
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
