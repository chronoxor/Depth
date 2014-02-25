/*!
 *  \file    CTokenizerIterator.inl Tokenizer iterator definitions. It gives
 *           ability to parse input stream and get new tokens as iterator's
 *           values.
 *  \brief   Tokenizer iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer iterators
    VERSION:   1.0
    CREATED:   23.04.2009 21:21:59

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
#ifndef __CTOKENIZERITERATOR_INL__
#define __CTOKENIZERITERATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CTokenizerIterator::CTokenizerIterator() :
  NCommon::NIterators::IIteratorConst<CTokenizerIterator, NString::CString, NString::CString, CTokenizer>(),
  NCommon::NIterators::IIteratorMoveForward<CTokenizerIterator, NString::CString, NString::CString, CTokenizer>(),
  m_pContainer(NULL),
  m_Value(),
  m_IsParsed(false)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTokenizerIterator::CTokenizerIterator(CTokenizer* a_pContainer) :
  NCommon::NIterators::IIteratorConst<CTokenizerIterator, NString::CString, NString::CString, CTokenizer>(),
  NCommon::NIterators::IIteratorMoveForward<CTokenizerIterator, NString::CString, NString::CString, CTokenizer>(),
  m_pContainer(a_pContainer),
  m_Value(),
  m_IsParsed(false)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CTokenizerIterator::CTokenizerIterator(const CTokenizerIterator& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CTokenizerIterator, NString::CString, NString::CString, CTokenizer>(),
  NCommon::NIterators::IIteratorMoveForward<CTokenizerIterator, NString::CString, NString::CString, CTokenizer>(),
  m_pContainer(NULL),
  m_Value(),
  m_IsParsed(false)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CTokenizerIterator::~CTokenizerIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline TOKENIZER_API Tbool operator == (const CTokenizerIterator& a_crInstance1, const CTokenizerIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Value == a_crInstance2.m_Value) && (a_crInstance1.m_IsParsed == a_crInstance2.m_IsParsed));
}
/*--------------------------------------------------------------------------*/
inline TOKENIZER_API Tbool operator != (const CTokenizerIterator& a_crInstance1, const CTokenizerIterator& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Value != a_crInstance2.m_Value) || (a_crInstance1.m_IsParsed != a_crInstance2.m_IsParsed));
}
/*--------------------------------------------------------------------------*/
inline CTokenizerIterator& CTokenizerIterator::operator = (const CTokenizerIterator& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTokenizerIterator& CTokenizerIterator::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTokenizerIterator& CTokenizerIterator::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
inline CTokenizerIterator CTokenizerIterator::operator ++ (int)
{ CALL
  CTokenizerIterator temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
inline CTokenizerIterator operator + (const CTokenizerIterator& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTokenizerIterator temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
inline void CTokenizerIterator::set(const CTokenizerIterator& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_Value = a_crInstance.m_Value;
  m_IsParsed = a_crInstance.m_IsParsed;
}
/*--------------------------------------------------------------------------*/
inline CTokenizerIterator CTokenizerIterator::getForward() const
{ CALL
  CTokenizerIterator it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CTokenizerIterator(m_pContainer));
}
/*--------------------------------------------------------------------------*/
inline Tbool CTokenizerIterator::isValid() const
{ CALL
  return (isValidContainer() && m_IsParsed);
}
/*--------------------------------------------------------------------------*/
inline Tbool CTokenizerIterator::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
inline CTokenizer& CTokenizerIterator::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
inline CTokenizer* CTokenizerIterator::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
inline NString::CString& CTokenizerIterator::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_Value;
}
/*--------------------------------------------------------------------------*/
inline NString::CString* CTokenizerIterator::getValuePtr() const
{ CALL
  if (isValid())
    return &m_Value;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CTokenizerIterator::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTokenizer::NIterators::CTokenizerIterator")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CTokenizerIterator::swap(CTokenizerIterator& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_Value, a_rInstance.m_Value);
  NAlgorithms::NCommon::swap(m_IsParsed, a_rInstance.m_IsParsed);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
