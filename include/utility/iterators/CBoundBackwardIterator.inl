/*!
 *  \file    CBoundBackwardIterator.inl Bound backward iterator wrapper
 *           class. It wraps given backward iterator sequence into the
 *           single backward iterator.
 *  \brief   Bound backward iterator wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bound backward iterator wrapper class (inline).

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
#ifndef __CBOUNDBACKWARDITERATOR_INL__
#define __CBOUNDBACKWARDITERATOR_INL__
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
inline CBoundBackwardIterator<T_BackwardIterator>::CBoundBackwardIterator() :
  T_BackwardIterator(),
  m_StartBoundIterator(),
  m_EndBoundIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator>::CBoundBackwardIterator(const T_BackwardIterator& a_crCurrentIterator) :
  T_BackwardIterator(),
  m_StartBoundIterator(),
  m_EndBoundIterator()
{ CALL
  set(a_crCurrentIterator);
  setStartBound(a_crCurrentIterator);
  setEndBound(a_crCurrentIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator>::CBoundBackwardIterator(const T_BackwardIterator& a_crCurrentIterator, const T_BackwardIterator& a_crEndBoundIterator) :
  T_BackwardIterator(),
  m_StartBoundIterator(),
  m_EndBoundIterator()
{ CALL
  set(a_crCurrentIterator);
  setStartBound(a_crCurrentIterator);
  setEndBound(a_crEndBoundIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator>::CBoundBackwardIterator(const T_BackwardIterator& a_crCurrentIterator, const T_BackwardIterator& a_crStartBoundIterator, const T_BackwardIterator& a_crEndBoundIterator) :
  T_BackwardIterator(),
  m_StartBoundIterator(),
  m_EndBoundIterator()
{ CALL
  set(a_crCurrentIterator);
  setStartBound(a_crStartBoundIterator);
  setEndBound(a_crEndBoundIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator>::CBoundBackwardIterator(const CBoundBackwardIterator<T_BackwardIterator>& a_crInstance) :
  T_BackwardIterator(),
  m_StartBoundIterator(),
  m_EndBoundIterator()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator>::~CBoundBackwardIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator>& CBoundBackwardIterator<T_BackwardIterator>::operator = (const T_BackwardIterator& a_crCurrentIterator)
{ CALL
  set(a_crCurrentIterator);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator>& CBoundBackwardIterator<T_BackwardIterator>::operator = (const CBoundBackwardIterator<T_BackwardIterator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator>& CBoundBackwardIterator<T_BackwardIterator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator>& CBoundBackwardIterator<T_BackwardIterator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator> CBoundBackwardIterator<T_BackwardIterator>::operator ++ (int)
{ CALL
  CBoundBackwardIterator<T_BackwardIterator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator> CBoundBackwardIterator<T_BackwardIterator>::operator -- (int)
{ CALL
  CBoundBackwardIterator<T_BackwardIterator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator> operator + (const CBoundBackwardIterator<T_BackwardIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CBoundBackwardIterator<T_BackwardIterator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator> operator - (const CBoundBackwardIterator<T_BackwardIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CBoundBackwardIterator<T_BackwardIterator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline void CBoundBackwardIterator<T_BackwardIterator>::set(const T_BackwardIterator& a_crCurrentIterator)
{ CALL
  T_BackwardIterator::set(a_crCurrentIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline void CBoundBackwardIterator<T_BackwardIterator>::set(const CBoundBackwardIterator<T_BackwardIterator>& a_crInstance)
{ CALL
  T_BackwardIterator::set(a_crInstance);
  setStartBound(a_crInstance.m_StartBoundIterator);
  setEndBound(a_crInstance.m_EndBoundIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline void CBoundBackwardIterator<T_BackwardIterator>::setStartBound(const T_BackwardIterator& a_crStartBoundIterator)
{ CALL
  m_StartBoundIterator = a_crStartBoundIterator;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline void CBoundBackwardIterator<T_BackwardIterator>::setEndBound(const T_BackwardIterator& a_crEndBoundIterator)
{ CALL
  m_EndBoundIterator = a_crEndBoundIterator;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline T_BackwardIterator& CBoundBackwardIterator<T_BackwardIterator>::getStartBound()
{ CALL
  return m_StartBoundIterator;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline const T_BackwardIterator& CBoundBackwardIterator<T_BackwardIterator>::getStartBound() const
{ CALL
  return m_StartBoundIterator;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline T_BackwardIterator& CBoundBackwardIterator<T_BackwardIterator>::getEndBound()
{ CALL
  return m_EndBoundIterator;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline const T_BackwardIterator& CBoundBackwardIterator<T_BackwardIterator>::getEndBound() const
{ CALL
  return m_EndBoundIterator;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator> CBoundBackwardIterator<T_BackwardIterator>::getForward() const
{ CALL
  CBoundBackwardIterator<T_BackwardIterator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CBoundBackwardIterator<T_BackwardIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CBoundBackwardIterator<T_BackwardIterator> CBoundBackwardIterator<T_BackwardIterator>::getBackward() const
{ CALL
  CBoundBackwardIterator<T_BackwardIterator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CBoundBackwardIterator<T_BackwardIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline Tuint CBoundBackwardIterator<T_BackwardIterator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_BackwardIterator::isValid(), STR("Cannot step forward with the invalid iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while (((T_BackwardIterator&)(*this) != m_EndBoundIterator) && (counter > 0))
  {
    if (T_BackwardIterator::stepForward() > 0)
      --counter;
    else
      break;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline Tuint CBoundBackwardIterator<T_BackwardIterator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_BackwardIterator::isValid(), STR("Cannot step backward with the invalid iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step backward by given steps.
  while (((T_BackwardIterator&)(*this) != m_StartBoundIterator) && (counter > 0))
  {
    if (T_BackwardIterator::stepBackward() > 0)
      --counter;
    else
      break;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
template <class T_Archive>
inline Tbool CBoundBackwardIterator<T_BackwardIterator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::NIterators::CBoundBackwardIterator<T_BackwardIterator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((T_BackwardIterator&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline void CBoundBackwardIterator<T_BackwardIterator>::swap(CBoundBackwardIterator<T_BackwardIterator>& a_rInstance)
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
