/*!
 *  \file    CLimitRandomIterator.inl Limit random iterator wrapper class.
 *           It wraps given random iterator sequence into the single
 *           random iterator.
 *  \brief   Limit random iterator wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Limit random iterator wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   04.04.2007 02:53:34

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
#ifndef __CLIMITRANDOMITERATOR_INL__
#define __CLIMITRANDOMITERATOR_INL__
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
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator>::CLimitRandomIterator() :
  T_RandomIterator(),
  m_StartLimit(0),
  m_EndLimit(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator>::CLimitRandomIterator(const T_RandomIterator& a_crCurrentIterator) :
  T_RandomIterator(),
  m_StartLimit(0),
  m_EndLimit(0)
{ CALL
  set(a_crCurrentIterator);
  setStartLimit(a_crCurrentIterator.isValid() ? a_crCurrentIterator.getPosition() : 0);
  setEndLimit(a_crCurrentIterator.isValid() ? (a_crCurrentIterator.getSize() - a_crCurrentIterator.getPosition() - 1) : 0);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator>::CLimitRandomIterator(const T_RandomIterator& a_crCurrentIterator, const Tuint a_cEndLimit) :
  T_RandomIterator(),
  m_StartLimit(0),
  m_EndLimit(0)
{ CALL
  set(a_crCurrentIterator);
  setStartLimit(a_crCurrentIterator.isValid() ? a_crCurrentIterator.getPosition() : 0);
  setEndLimit(a_cEndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator>::CLimitRandomIterator(const T_RandomIterator& a_crCurrentIterator, const Tuint a_cStartLimit, const Tuint a_cEndLimit) :
  T_RandomIterator(),
  m_StartLimit(NBase::CUnsignedInteger::getMax()),
  m_EndLimit(NBase::CUnsignedInteger::getMax())
{ CALL
  set(a_crCurrentIterator);
  setStartLimit(a_cStartLimit);
  setEndLimit(a_cEndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator>::CLimitRandomIterator(const CLimitRandomIterator<T_RandomIterator>& a_crInstance) :
  T_RandomIterator(),
  m_StartLimit(NBase::CUnsignedInteger::getMax()),
  m_EndLimit(NBase::CUnsignedInteger::getMax())
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator>::~CLimitRandomIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator>& CLimitRandomIterator<T_RandomIterator>::operator = (const T_RandomIterator& a_crCurrentIterator)
{ CALL
  set(a_crCurrentIterator);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator>& CLimitRandomIterator<T_RandomIterator>::operator = (const CLimitRandomIterator<T_RandomIterator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator>& CLimitRandomIterator<T_RandomIterator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator>& CLimitRandomIterator<T_RandomIterator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> CLimitRandomIterator<T_RandomIterator>::operator ++ (int)
{ CALL
  CLimitRandomIterator<T_RandomIterator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> CLimitRandomIterator<T_RandomIterator>::operator -- (int)
{ CALL
  CLimitRandomIterator<T_RandomIterator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> operator + (const CLimitRandomIterator<T_RandomIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CLimitRandomIterator<T_RandomIterator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> operator - (const CLimitRandomIterator<T_RandomIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CLimitRandomIterator<T_RandomIterator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> CLimitRandomIterator<T_RandomIterator>::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> CLimitRandomIterator<T_RandomIterator>::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline void CLimitRandomIterator<T_RandomIterator>::set(const T_RandomIterator& a_crCurrentIterator)
{ CALL
  T_RandomIterator::set(a_crCurrentIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline void CLimitRandomIterator<T_RandomIterator>::set(const CLimitRandomIterator<T_RandomIterator>& a_crInstance)
{ CALL
  T_RandomIterator::set(a_crInstance);
  setStartLimit(a_crInstance.m_StartLimit);
  setEndLimit(a_crInstance.m_EndLimit);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline void CLimitRandomIterator<T_RandomIterator>::setStartLimit(const Tuint a_cStartLimit)
{ CALL
  m_StartLimit = (T_RandomIterator::getPosition() < a_cStartLimit) ? T_RandomIterator::getPosition() : a_cStartLimit;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline void CLimitRandomIterator<T_RandomIterator>::setEndLimit(const Tuint a_cEndLimit)
{ CALL
  m_EndLimit = (T_RandomIterator::isValid() ? (((T_RandomIterator::getSize() - T_RandomIterator::getPosition()) > a_cEndLimit) ? a_cEndLimit : (T_RandomIterator::getSize() - T_RandomIterator::getPosition() - 1)) : 0);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tuint CLimitRandomIterator<T_RandomIterator>::getStartLimit() const
{ CALL
  return m_StartLimit;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tuint CLimitRandomIterator<T_RandomIterator>::getEndLimit() const
{ CALL
  return m_EndLimit;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> CLimitRandomIterator<T_RandomIterator>::getForward() const
{ CALL
  CLimitRandomIterator<T_RandomIterator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CLimitRandomIterator<T_RandomIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> CLimitRandomIterator<T_RandomIterator>::getBackward() const
{ CALL
  CLimitRandomIterator<T_RandomIterator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CLimitRandomIterator<T_RandomIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CLimitRandomIterator<T_RandomIterator> CLimitRandomIterator<T_RandomIterator>::getIndex(const Tuint a_cIndex) const
{ CALL
  CLimitRandomIterator<T_RandomIterator> it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CLimitRandomIterator<T_RandomIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tuint CLimitRandomIterator<T_RandomIterator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_RandomIterator::isValid(), STR("Cannot step forward with the invalid iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while ((m_EndLimit > 0) && (counter > 0))
  {
    if (T_RandomIterator::stepForward() > 0)
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
template <class T_RandomIterator>
inline Tuint CLimitRandomIterator<T_RandomIterator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_RandomIterator::isValid(), STR("Cannot step backward with the invalid iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step Random by given steps.
  while ((m_StartLimit > 0) && (counter > 0))
  {
    if (T_RandomIterator::stepBackward() > 0)
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
template <class T_RandomIterator>
inline Tbool CLimitRandomIterator<T_RandomIterator>::stepIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(T_RandomIterator::isValidContainer(), STR("Cannot do indexed step with the invalid container."))
  {
    return false;
  }

  // Check index value and the container's bounds.
  ASSERT(((a_cIndex < getSize()) || (a_cIndex == 0)), STR("Cannot do indexed step with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA getSize())
  {
    return false;
  }

  return T_RandomIterator::stepIndex(T_RandomIterator::getPosition() - m_StartLimit + a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tuint CLimitRandomIterator<T_RandomIterator>::getSize() const
{ CALL
  return (T_RandomIterator::isValid() ? (m_EndLimit - m_StartLimit + 1) : 0);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tbool CLimitRandomIterator<T_RandomIterator>::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tuint CLimitRandomIterator<T_RandomIterator>::getPosition() const
{ CALL
  return m_StartLimit;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
template <class T_Archive>
inline Tbool CLimitRandomIterator<T_RandomIterator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::NIterators::CLimitRandomIterator<T_RandomIterator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((T_RandomIterator&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline void CLimitRandomIterator<T_RandomIterator>::swap(CLimitRandomIterator<T_RandomIterator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((T_RandomIterator&)(*this), (T_RandomIterator&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
