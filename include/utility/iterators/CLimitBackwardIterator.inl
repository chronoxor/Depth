/*!
 *  \file    CLimitBackwardIterator.inl Limit backward iterator wrapper
 *           class. It wraps given backward iterator sequence into the
 *           single backward iterator.
 *  \brief   Limit backward iterator wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Limit backward iterator wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   03.04.2007 22:35:26

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
#ifndef __CLIMITBACKWARDITERATOR_INL__
#define __CLIMITBACKWARDITERATOR_INL__
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
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator>::CLimitBackwardIterator() :
  T_BackwardIterator(),
  m_StartLimit(NBase::CUnsignedInteger::getMax()),
  m_EndLimit(NBase::CUnsignedInteger::getMax())
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator>::CLimitBackwardIterator(const T_BackwardIterator& a_crCurrentIterator) :
  T_BackwardIterator(),
  m_StartLimit(NBase::CUnsignedInteger::getMax()),
  m_EndLimit(NBase::CUnsignedInteger::getMax())
{ CALL
  set(a_crCurrentIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator>::CLimitBackwardIterator(const T_BackwardIterator& a_crCurrentIterator, const Tuint a_cEndLimit) :
  T_BackwardIterator(),
  m_StartLimit(NBase::CUnsignedInteger::getMax()),
  m_EndLimit(NBase::CUnsignedInteger::getMax())
{ CALL
  set(a_crCurrentIterator);
  setEndLimit(a_cEndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator>::CLimitBackwardIterator(const T_BackwardIterator& a_crCurrentIterator, const Tuint a_cStartLimit, const Tuint a_cEndLimit) :
  T_BackwardIterator(),
  m_StartLimit(NBase::CUnsignedInteger::getMax()),
  m_EndLimit(NBase::CUnsignedInteger::getMax())
{ CALL
  set(a_crCurrentIterator);
  setStartLimit(a_cStartLimit);
  setEndLimit(a_cEndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator>::CLimitBackwardIterator(const CLimitBackwardIterator<T_BackwardIterator>& a_crInstance) :
  T_BackwardIterator(),
  m_StartLimit(NBase::CUnsignedInteger::getMax()),
  m_EndLimit(NBase::CUnsignedInteger::getMax())
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator>::~CLimitBackwardIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator>& CLimitBackwardIterator<T_BackwardIterator>::operator = (const T_BackwardIterator& a_crCurrentIterator)
{ CALL
  set(a_crCurrentIterator);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator>& CLimitBackwardIterator<T_BackwardIterator>::operator = (const CLimitBackwardIterator<T_BackwardIterator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator>& CLimitBackwardIterator<T_BackwardIterator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator>& CLimitBackwardIterator<T_BackwardIterator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator> CLimitBackwardIterator<T_BackwardIterator>::operator ++ (int)
{ CALL
  CLimitBackwardIterator<T_BackwardIterator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator> CLimitBackwardIterator<T_BackwardIterator>::operator -- (int)
{ CALL
  CLimitBackwardIterator<T_BackwardIterator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator> operator + (const CLimitBackwardIterator<T_BackwardIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CLimitBackwardIterator<T_BackwardIterator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator> operator - (const CLimitBackwardIterator<T_BackwardIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CLimitBackwardIterator<T_BackwardIterator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline void CLimitBackwardIterator<T_BackwardIterator>::set(const T_BackwardIterator& a_crCurrentIterator)
{ CALL
  T_BackwardIterator::set(a_crCurrentIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline void CLimitBackwardIterator<T_BackwardIterator>::set(const CLimitBackwardIterator<T_BackwardIterator>& a_crInstance)
{ CALL
  T_BackwardIterator::set(a_crInstance);
  setStartBound(a_crInstance.m_StartLimit);
  setEndBound(a_crInstance.m_EndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline void CLimitBackwardIterator<T_BackwardIterator>::setStartLimit(const Tuint a_cStartLimit)
{ CALL
  m_StartLimit = a_cStartLimit;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline void CLimitBackwardIterator<T_BackwardIterator>::setEndLimit(const Tuint a_cEndLimit)
{ CALL
  m_EndLimit = a_cEndLimit;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline Tuint CLimitBackwardIterator<T_BackwardIterator>::getStartLimit() const
{ CALL
  return m_StartLimit;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline Tuint CLimitBackwardIterator<T_BackwardIterator>::getEndLimit() const
{ CALL
  return m_EndLimit;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator> CLimitBackwardIterator<T_BackwardIterator>::getForward() const
{ CALL
  CLimitBackwardIterator<T_BackwardIterator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CLimitBackwardIterator<T_BackwardIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CLimitBackwardIterator<T_BackwardIterator> CLimitBackwardIterator<T_BackwardIterator>::getBackward() const
{ CALL
  CLimitBackwardIterator<T_BackwardIterator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CLimitBackwardIterator<T_BackwardIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline Tuint CLimitBackwardIterator<T_BackwardIterator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_BackwardIterator::isValid(), STR("Cannot step forward with the invalid iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while ((m_EndLimit > 0) && (counter > 0))
  {
    if (T_BackwardIterator::stepForward() > 0)
    {
      if (m_StartLimit < NBase::CUnsignedInteger::getMax())
        ++m_StartLimit;
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
template <class T_BackwardIterator>
inline Tuint CLimitBackwardIterator<T_BackwardIterator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_BackwardIterator::isValid(), STR("Cannot step backward with the invalid iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step backward by given steps.
  while ((m_StartLimit > 0) && (counter > 0))
  {
    if (T_BackwardIterator::stepBackward() > 0)
    {
      if (m_EndLimit < NBase::CUnsignedInteger::getMax())
        ++m_EndLimit;
      --m_StartLimit;
      --counter;
    }
    else
      break;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
template <class T_Archive>
inline Tbool CLimitBackwardIterator<T_BackwardIterator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::NIterators::CLimitBackwardIterator<T_BackwardIterator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((T_BackwardIterator&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline void CLimitBackwardIterator<T_BackwardIterator>::swap(CLimitBackwardIterator<T_BackwardIterator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((T_BackwardIterator&)(*this), (T_BackwardIterator&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
