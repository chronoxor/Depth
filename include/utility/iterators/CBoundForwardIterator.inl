/*!
 *  \file    CBoundForwardIterator.inl Bound forward iterator wrapper class.
 *           It wraps given forward iterator sequence into the single forward
 *           iterator.
 *  \brief   Bound forward iterator wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Bound forward iterator wrapper class (inline).

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
#ifndef __CBOUNDFORWARDITERATOR_INL__
#define __CBOUNDFORWARDITERATOR_INL__
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
inline CBoundForwardIterator<T_ForwardIterator>::CBoundForwardIterator() :
  T_ForwardIterator(),
  m_EndBoundIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CBoundForwardIterator<T_ForwardIterator>::CBoundForwardIterator(const T_ForwardIterator& a_crCurrentIterator) :
  T_ForwardIterator(),
  m_EndBoundIterator()
{ CALL
  set(a_crCurrentIterator);
  setEndBound(a_crCurrentIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CBoundForwardIterator<T_ForwardIterator>::CBoundForwardIterator(const T_ForwardIterator& a_crCurrentIterator, const T_ForwardIterator& a_crEndBoundIterator) :
  T_ForwardIterator(),
  m_EndBoundIterator()
{ CALL
  set(a_crCurrentIterator);
  setEndBound(a_crEndBoundIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CBoundForwardIterator<T_ForwardIterator>::CBoundForwardIterator(const CBoundForwardIterator<T_ForwardIterator>& a_crInstance) :
  T_ForwardIterator(),
  m_EndBoundIterator()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CBoundForwardIterator<T_ForwardIterator>::~CBoundForwardIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CBoundForwardIterator<T_ForwardIterator>& CBoundForwardIterator<T_ForwardIterator>::operator = (const T_ForwardIterator& a_crCurrentIterator)
{ CALL
  set(a_crCurrentIterator);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CBoundForwardIterator<T_ForwardIterator>& CBoundForwardIterator<T_ForwardIterator>::operator = (const CBoundForwardIterator<T_ForwardIterator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CBoundForwardIterator<T_ForwardIterator>& CBoundForwardIterator<T_ForwardIterator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CBoundForwardIterator<T_ForwardIterator> CBoundForwardIterator<T_ForwardIterator>::operator ++ (int)
{ CALL
  CBoundForwardIterator<T_ForwardIterator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CBoundForwardIterator<T_ForwardIterator> operator + (const CBoundForwardIterator<T_ForwardIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CBoundForwardIterator<T_ForwardIterator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline void CBoundForwardIterator<T_ForwardIterator>::set(const T_ForwardIterator& a_crCurrentIterator)
{ CALL
  T_ForwardIterator::set(a_crCurrentIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline void CBoundForwardIterator<T_ForwardIterator>::set(const CBoundForwardIterator<T_ForwardIterator>& a_crInstance)
{ CALL
  T_ForwardIterator::set(a_crInstance);
  setEndBound(a_crInstance.m_EndBoundIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline void CBoundForwardIterator<T_ForwardIterator>::setEndBound(const T_ForwardIterator& a_crEndBoundIterator)
{ CALL
  m_EndBoundIterator = a_crEndBoundIterator;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline T_ForwardIterator& CBoundForwardIterator<T_ForwardIterator>::getEndBound()
{ CALL
  return m_EndBoundIterator;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline const T_ForwardIterator& CBoundForwardIterator<T_ForwardIterator>::getEndBound() const
{ CALL
  return m_EndBoundIterator;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline CBoundForwardIterator<T_ForwardIterator> CBoundForwardIterator<T_ForwardIterator>::getForward() const
{ CALL
  CBoundForwardIterator<T_ForwardIterator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CBoundForwardIterator<T_ForwardIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline Tuint CBoundForwardIterator<T_ForwardIterator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_ForwardIterator::isValid(), STR("Cannot step forward with the invalid iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while (((T_ForwardIterator&)(*this) != m_EndBoundIterator) && (counter > 0))
  {
    if (T_ForwardIterator::stepForward() > 0)
      --counter;
    else
      break;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
template <class T_Archive>
inline Tbool CBoundForwardIterator<T_ForwardIterator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::NIterators::CBoundForwardIterator<T_ForwardIterator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((T_ForwardIterator&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_ForwardIterator>
inline void CBoundForwardIterator<T_ForwardIterator>::swap(CBoundForwardIterator<T_ForwardIterator>& a_rInstance)
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
