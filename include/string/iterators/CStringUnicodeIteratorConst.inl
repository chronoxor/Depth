/*!
 *  \file    CStringUnicodeIteratorConst.inl Unicode string constant iterator
 *           definitions. It gives ability to get Unicode string characters
 *           and to do random moving through the Unicode string characters.
 *  \brief   Unicode string constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode string constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   07.08.2008 22:18:24

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
#ifndef __CSTRINGUNICODEITERATORCONST_INL__
#define __CSTRINGUNICODEITERATORCONST_INL__
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
inline CStringUnicodeIteratorConst::CStringUnicodeIteratorConst() :
  NCommon::NIterators::IIteratorConst<CStringUnicodeIteratorConst, Twchar, Twchar, CStringUnicode>(),
  NCommon::NIterators::IIteratorMoveRandom<CStringUnicodeIteratorConst, Twchar, Twchar, CStringUnicode>(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst::CStringUnicodeIteratorConst(const CStringUnicode* a_cpContainer) :
  NCommon::NIterators::IIteratorConst<CStringUnicodeIteratorConst, Twchar, Twchar, CStringUnicode>(),
  NCommon::NIterators::IIteratorMoveRandom<CStringUnicodeIteratorConst, Twchar, Twchar, CStringUnicode>(),
  NCommon::ISeekable(),
  m_cpContainer(a_cpContainer),
  m_Index((a_cpContainer != NULL) ? a_cpContainer->getSize() : 0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst::CStringUnicodeIteratorConst(const CStringUnicodeIterator& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CStringUnicodeIteratorConst, Twchar, Twchar, CStringUnicode>(),
  NCommon::NIterators::IIteratorMoveRandom<CStringUnicodeIteratorConst, Twchar, Twchar, CStringUnicode>(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst::CStringUnicodeIteratorConst(const CStringUnicodeIteratorConst& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CStringUnicodeIteratorConst, Twchar, Twchar, CStringUnicode>(),
  NCommon::NIterators::IIteratorMoveRandom<CStringUnicodeIteratorConst, Twchar, Twchar, CStringUnicode>(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst::~CStringUnicodeIteratorConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CStringUnicodeIterator& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator == (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CStringUnicodeIterator& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator != (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CStringUnicodeIterator& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator < (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CStringUnicodeIterator& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator > (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CStringUnicodeIterator& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator <= (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CStringUnicodeIterator& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline BASE_API Tbool operator >= (const CStringUnicodeIteratorConst& a_crInstance1, const CStringUnicodeIteratorConst& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst& CStringUnicodeIteratorConst::operator = (const CStringUnicodeIterator& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst& CStringUnicodeIteratorConst::operator = (const CStringUnicodeIteratorConst& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst& CStringUnicodeIteratorConst::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst& CStringUnicodeIteratorConst::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst& CStringUnicodeIteratorConst::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst& CStringUnicodeIteratorConst::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst CStringUnicodeIteratorConst::operator ++ (int)
{ CALL
  CStringUnicodeIteratorConst temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst CStringUnicodeIteratorConst::operator -- (int)
{ CALL
  CStringUnicodeIteratorConst temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CStringUnicodeIteratorConst operator + (const CStringUnicodeIteratorConst& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CStringUnicodeIteratorConst temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
inline BASE_API CStringUnicodeIteratorConst operator - (const CStringUnicodeIteratorConst& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CStringUnicodeIteratorConst temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst CStringUnicodeIteratorConst::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst CStringUnicodeIteratorConst::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
inline void CStringUnicodeIteratorConst::set(const CStringUnicodeIterator& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_pContainer;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
inline void CStringUnicodeIteratorConst::set(const CStringUnicodeIteratorConst& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_cpContainer;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst CStringUnicodeIteratorConst::getForward() const
{ CALL
  CStringUnicodeIteratorConst it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CStringUnicodeIteratorConst(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst CStringUnicodeIteratorConst::getBackward() const
{ CALL
  CStringUnicodeIteratorConst it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CStringUnicodeIteratorConst(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
inline CStringUnicodeIteratorConst CStringUnicodeIteratorConst::getIndex(const Tuint a_cIndex) const
{ CALL
  CStringUnicodeIteratorConst it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CStringUnicodeIteratorConst(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicodeIteratorConst::isValid() const
{ CALL
  return (isValidContainer() && (m_Index < m_cpContainer->getSize()));
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicodeIteratorConst::isValidContainer() const
{ CALL
  return (m_cpContainer != NULL);
}
/*--------------------------------------------------------------------------*/
inline const CStringUnicode& CStringUnicodeIteratorConst::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_cpContainer;
}
/*--------------------------------------------------------------------------*/
inline const CStringUnicode* CStringUnicodeIteratorConst::getContainerPtr() const
{ CALL
  return m_cpContainer;
}
/*--------------------------------------------------------------------------*/
inline const Twchar& CStringUnicodeIteratorConst::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_cpContainer->m_pBuffer[m_Index];
}
/*--------------------------------------------------------------------------*/
inline const Twchar* CStringUnicodeIteratorConst::getValuePtr() const
{ CALL
  if (isValid())
    return &m_cpContainer->m_pBuffer[m_Index];
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
inline Tuint CStringUnicodeIteratorConst::getSize() const
{ CALL
  return (isValidContainer() ? m_cpContainer->getSize() : 0);
}
/*--------------------------------------------------------------------------*/
inline Tbool CStringUnicodeIteratorConst::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
inline Tuint CStringUnicodeIteratorConst::getPosition() const
{ CALL
  return (isValidContainer() ? m_Index : 0);
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStringUnicodeIteratorConst::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Constant iterator value cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStringUnicodeIteratorConst::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NString::NIterators::CStringUnicodeIterator")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CStringUnicodeIteratorConst::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
inline void CStringUnicodeIteratorConst::swap(CStringUnicodeIteratorConst& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpContainer, a_rInstance.m_cpContainer);
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
