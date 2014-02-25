/*!
 *  \file    CTokenizerInputContainer.inl Tokenizer input iterator based on
 *           the given input container.
 *  \brief   Tokenizer input container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tokenizer input container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Tokenizer details
    VERSION:   1.0
    CREATED:   20.04.2009 01:55:46

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
#ifndef __CTOKENIZERINPUTCONTAINER_INL__
#define __CTOKENIZERINPUTCONTAINER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTokenizer {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_Container>
inline CTokenizerInputContainer<T_Container>::CTokenizerInputContainer() :
  ITokenizerInputIterator(),
  m_Iterator(),
  m_Value(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizerInputContainer<T_Container>::CTokenizerInputContainer(const T_Container& a_crContainer) :
  ITokenizerInputIterator(),
  m_Iterator(),
  m_Value(0)
{ CALL
  set(a_crContainer);
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizerInputContainer<T_Container>::CTokenizerInputContainer(const CTokenizerInputContainer<T_Container>& a_crInstance) :
  ITokenizerInputIterator(),
  m_Iterator(),
  m_Value(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizerInputContainer<T_Container>::~CTokenizerInputContainer()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline Tbool operator == (const CTokenizerInputContainer<T_Container>& a_crInstance1, const CTokenizerInputContainer<T_Container>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Iterator == a_crInstance2.m_Iterator) && (a_crInstance1.m_Value == a_crInstance2.m_Value));
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline Tbool operator != (const CTokenizerInputContainer<T_Container>& a_crInstance1, const CTokenizerInputContainer<T_Container>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_Iterator != a_crInstance2.m_Iterator) || (a_crInstance1.m_Value != a_crInstance2.m_Value));
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizerInputContainer<T_Container>& CTokenizerInputContainer<T_Container>::operator = (const T_Container& a_crContainer)
{ CALL
  set(a_crContainer);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizerInputContainer<T_Container>& CTokenizerInputContainer<T_Container>::operator = (const CTokenizerInputContainer<T_Container>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizerInputContainer<T_Container>& CTokenizerInputContainer<T_Container>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizerInputContainer<T_Container>& CTokenizerInputContainer<T_Container>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizerInputContainer<T_Container> CTokenizerInputContainer<T_Container>::operator ++ (int)
{ CALL
  CTokenizerInputContainer<T_Container> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizerInputContainer<T_Container> operator + (const CTokenizerInputContainer<T_Container>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTokenizerInputContainer<T_Container> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline void CTokenizerInputContainer<T_Container>::set(const T_Container& a_crContainer)
{ CALL
  m_Iterator = NAlgorithms::NContainers::getItFirst(a_crContainer);
  m_Value = m_Iterator.isValid() ? (typename NTraits::MTraitsCharacter<typename T_Container::TType>::ucharacter)m_Iterator.getValueRef() : 0;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline void CTokenizerInputContainer<T_Container>::set(const CTokenizerInputContainer<T_Container>& a_crInstance)
{ CALL
  m_Iterator = a_crInstance.m_Iterator;
  m_Value = a_crInstance.m_Value;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline CTokenizerInputContainer<T_Container> CTokenizerInputContainer<T_Container>::getForward() const
{ CALL
  CTokenizerInputContainer<T_Container> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : (m_Iterator.isValidContainer() ? CTokenizerInputContainer<T_Container>(m_Iterator.getContainerRef()) : CTokenizerInputContainer<T_Container>()));
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline Tbool CTokenizerInputContainer<T_Container>::isValid() const
{ CALL
  return m_Iterator.isValid();
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline const Tuint& CTokenizerInputContainer<T_Container>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_Value;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline const Tuint* CTokenizerInputContainer<T_Container>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_Value;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline Tuint CTokenizerInputContainer<T_Container>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Perform step forward with the current input iterator.
  Tuint result = m_Iterator.stepForward(a_cStepCount);

  // Update input iterator value.
  m_Value = m_Iterator.isValid() ? (typename NTraits::MTraitsCharacter<typename T_Container::TType>::ucharacter)m_Iterator.getValueRef() : 0;

  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline ITokenizerInputIterator* CTokenizerInputContainer<T_Container>::clone() const
{ CALL
  ITokenizerInputIterator* result = newex CTokenizerInputContainer<T_Container>(*this);

  if (result == NULL)
    WARNING(STR("Cannot create a new tokenizer input container instance (requested size is %u bytes).") COMMA (sizeof(CTokenizerInputContainer<T_Container>)));
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
template <class T_Archive>
inline Tbool CTokenizerInputContainer<T_Container>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NTokenizer::NDetails::CTokenizerInputContainer<T_Container>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Iterator, STR("m_Iterator")));
    CHECK(a_rArchive.doValue(m_Value, STR("m_Value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Container>
inline void CTokenizerInputContainer<T_Container>::swap(CTokenizerInputContainer<T_Container>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Iterator, a_rInstance.m_Iterator);
  NAlgorithms::NCommon::swap(m_Value, a_rInstance.m_Value);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
