/*!
 *  \file    CLimitForwardIterator.inl Limit forward iterator wrapper class.
 *           It wraps given forward iterator sequence into the single forward
 *           iterator.
 *  \brief   Limit forward iterator wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Limit forward iterator wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   03.04.2007 21:05:52

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
#ifndef __CLIMITFORWARDITERATOR_INL__
#define __CLIMITFORWARDITERATOR_INL__
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
template <class T_ForwardIterator>
inline CLimitForwardIterator<T_ForwardIterator>::CLimitForwardIterator() :
  T_ForwardIterator(),
  m_EndLimit(NBase::CUnsignedInteger::getMax())
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CLimitForwardIterator<T_ForwardIterator>::CLimitForwardIterator(const T_ForwardIterator& a_crCurrentIterator) :
  T_ForwardIterator(),
  m_EndLimit(NBase::CUnsignedInteger::getMax())
{ CALL
  set(a_crCurrentIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CLimitForwardIterator<T_ForwardIterator>::CLimitForwardIterator(const T_ForwardIterator& a_crCurrentIterator, const Tuint a_cEndLimit) :
  T_ForwardIterator(),
  m_EndLimit(NBase::CUnsignedInteger::getMax())
{ CALL
  set(a_crCurrentIterator);
  setEndLimit(a_cEndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CLimitForwardIterator<T_ForwardIterator>::CLimitForwardIterator(const CLimitForwardIterator<T_ForwardIterator>& a_crInstance) :
  T_ForwardIterator(),
  m_EndLimit(NBase::CUnsignedInteger::getMax())
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CLimitForwardIterator<T_ForwardIterator>::~CLimitForwardIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CLimitForwardIterator<T_ForwardIterator>& CLimitForwardIterator<T_ForwardIterator>::operator = (const T_ForwardIterator& a_crCurrentIterator)
{ CALL
  set(a_crCurrentIterator);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CLimitForwardIterator<T_ForwardIterator>& CLimitForwardIterator<T_ForwardIterator>::operator = (const CLimitForwardIterator<T_ForwardIterator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CLimitForwardIterator<T_ForwardIterator>& CLimitForwardIterator<T_ForwardIterator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CLimitForwardIterator<T_ForwardIterator> CLimitForwardIterator<T_ForwardIterator>::operator ++ (int)
{ CALL
  CLimitForwardIterator<T_ForwardIterator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CLimitForwardIterator<T_ForwardIterator> operator + (const CLimitForwardIterator<T_ForwardIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CLimitForwardIterator<T_ForwardIterator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline void CLimitForwardIterator<T_ForwardIterator>::set(const T_ForwardIterator& a_crCurrentIterator)
{ CALL
  T_ForwardIterator::set(a_crCurrentIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline void CLimitForwardIterator<T_ForwardIterator>::set(const CLimitForwardIterator<T_ForwardIterator>& a_crInstance)
{ CALL
  T_ForwardIterator::set(a_crInstance);
  setEndBound(a_crInstance.m_EndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline void CLimitForwardIterator<T_ForwardIterator>::setEndLimit(const Tuint a_cEndLimit)
{ CALL
  m_EndLimit = a_cEndLimit;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline Tuint CLimitForwardIterator<T_ForwardIterator>::getEndLimit() const
{ CALL
  return m_EndLimit;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CLimitForwardIterator<T_ForwardIterator> CLimitForwardIterator<T_ForwardIterator>::getForward() const
{ CALL
  CLimitForwardIterator<T_ForwardIterator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CLimitForwardIterator<T_ForwardIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline Tuint CLimitForwardIterator<T_ForwardIterator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_ForwardIterator::isValid(), STR("Cannot step forward with the invalid iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while ((m_EndLimit > 0) && (counter > 0))
  {
    if (T_ForwardIterator::stepForward() > 0)
    {
      --m_EndLimit;
      --counter;
    }
    else
      break;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
template <class T_Archive>
inline Tbool CLimitForwardIterator<T_ForwardIterator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::NIterators::CLimitForwardIterator<T_ForwardIterator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((T_ForwardIterator&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline void CLimitForwardIterator<T_ForwardIterator>::swap(CLimitForwardIterator<T_ForwardIterator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((T_ForwardIterator&)(*this), (T_ForwardIterator&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
