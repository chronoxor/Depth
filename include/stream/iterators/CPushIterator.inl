/*!
 *  \file    CPushIterator.inl Push iterator definitions for the reader
 *           stream. It gives ability to push sequence of items into the
 *           reader.
 *  \brief   Push iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Push iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   20.08.2008 03:19:25

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
#ifndef __CPUSHITERATOR_INL__
#define __CPUSHITERATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline CPushIterator<T_Type>::CPushIterator() :
  NCommon::NIterators::IIterator<CPushIterator<T_Type>, T_Type, T_Type, IReader>(),
  NCommon::NIterators::IIteratorMoveForward<CPushIterator<T_Type>, T_Type, T_Type, IReader>(),
  NCommon::NIterators::IIteratorInsertForward<CPushIterator<T_Type>, T_Type, T_Type, IReader>(),
  m_pContainer(NULL),
  m_IsValid(true),
  m_Value()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPushIterator<T_Type>::CPushIterator(IReader* a_pContainer) :
  NCommon::NIterators::IIterator<CPushIterator<T_Type>, T_Type, T_Type, IReader>(),
  NCommon::NIterators::IIteratorMoveForward<CPushIterator<T_Type>, T_Type, T_Type, IReader>(),
  NCommon::NIterators::IIteratorInsertForward<CPushIterator<T_Type>, T_Type, T_Type, IReader>(),
  m_pContainer(a_pContainer),
  m_IsValid(true),
  m_Value()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPushIterator<T_Type>::CPushIterator(const CPushIterator<T_Type>& a_crInstance) :
  NCommon::NIterators::IIterator<CPushIterator<T_Type>, T_Type, T_Type, IReader>(),
  NCommon::NIterators::IIteratorMoveForward<CPushIterator<T_Type>, T_Type, T_Type, IReader>(),
  NCommon::NIterators::IIteratorInsertForward<CPushIterator<T_Type>, T_Type, T_Type, IReader>(),
  m_pContainer(NULL),
  m_IsValid(true),
  m_Value()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPushIterator<T_Type>::~CPushIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator == (const CPushIterator<T_Type>& a_crInstance1, const CPushIterator<T_Type>& a_crInstance2)
{ CALL
  IGNORE_UNUSED(a_crInstance1);
  IGNORE_UNUSED(a_crInstance2);

  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool operator != (const CPushIterator<T_Type>& a_crInstance1, const CPushIterator<T_Type>& a_crInstance2)
{ CALL
  IGNORE_UNUSED(a_crInstance1);
  IGNORE_UNUSED(a_crInstance2);

  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPushIterator<T_Type>& CPushIterator<T_Type>::operator = (const CPushIterator<T_Type>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPushIterator<T_Type>& CPushIterator<T_Type>::operator += (const Tuint a_cStepCount)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPushIterator<T_Type>& CPushIterator<T_Type>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPushIterator<T_Type> CPushIterator<T_Type>::operator ++ (int)
{ CALL
  CPushIterator<T_Type> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPushIterator<T_Type> operator + (const CPushIterator<T_Type>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CPushIterator<T_Type> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPushIterator<T_Type>::set(const CPushIterator<T_Type>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_IsValid = a_crInstance.m_IsValid;
  m_Value = a_crInstance.m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CPushIterator<T_Type> CPushIterator<T_Type>::getForward() const
{ CALL
  CPushIterator<T_Type> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CPushIterator<T_Type>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPushIterator<T_Type>::isValid() const
{ CALL
  return (isValidContainer() && m_IsValid);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPushIterator<T_Type>::isValidContainer() const
{ CALL
  return ((m_pContainer != NULL) && (m_pContainer->isOpened()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline IReader& CPushIterator<T_Type>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline IReader* CPushIterator<T_Type>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type& CPushIterator<T_Type>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_Value;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* CPushIterator<T_Type>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_Value;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CPushIterator<T_Type>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid push iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while (counter > 0)
  {
    if (!m_pContainer->push(m_Value).getFirst())
    {
      m_IsValid = false;
      break;
    }
    else
      --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPushIterator<T_Type>::insertNext(const T_Type& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new item into the invalid push iterator."))
  {
    return false;
  }

  // Assign new current value.
  m_Value = a_crItem;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CPushIterator<T_Type>::insertBackward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid reader container."))
  {
    return false;
  }

  // Push the given value into the reader.
  if (!m_pContainer->push(a_crItem).getFirst())
  {
    m_IsValid = false;
    return false;
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CPushIterator<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStream::NIterators::CPushIterator<T_Type>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CPushIterator<T_Type>::swap(CPushIterator<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_IsValid, a_rInstance.m_IsValid);
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
