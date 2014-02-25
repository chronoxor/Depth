/*!
 *  \file    CReverseIterator.inl Reverse iterator wrapper class. It reverses
 *           steps operations of the backward iterator.
 *  \brief   Reverse iterator wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reverse iterator wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   20.08.2006 21:53:29

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
#ifndef __CREVERSEITERATOR_INL__
#define __CREVERSEITERATOR_INL__
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
inline CReverseIterator<T_BackwardIterator>::CReverseIterator() :
  T_BackwardIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CReverseIterator<T_BackwardIterator>::CReverseIterator(const T_BackwardIterator& a_crBackwardIterator) :
  T_BackwardIterator()
{ CALL
  set(a_crBackwardIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CReverseIterator<T_BackwardIterator>::~CReverseIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CReverseIterator<T_BackwardIterator>& CReverseIterator<T_BackwardIterator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CReverseIterator<T_BackwardIterator>& CReverseIterator<T_BackwardIterator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CReverseIterator<T_BackwardIterator> CReverseIterator<T_BackwardIterator>::operator ++ (int)
{ CALL
  CReverseIterator<T_BackwardIterator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CReverseIterator<T_BackwardIterator> CReverseIterator<T_BackwardIterator>::operator -- (int)
{ CALL
  CReverseIterator<T_BackwardIterator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CReverseIterator<T_BackwardIterator> operator + (const CReverseIterator<T_BackwardIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CReverseIterator<T_BackwardIterator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CReverseIterator<T_BackwardIterator> operator - (const CReverseIterator<T_BackwardIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CReverseIterator<T_BackwardIterator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CReverseIterator<T_BackwardIterator> CReverseIterator<T_BackwardIterator>::getForward() const
{ CALL
  return T_BackwardIterator::getBackward();
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline CReverseIterator<T_BackwardIterator> CReverseIterator<T_BackwardIterator>::getBackward() const
{ CALL
  return T_BackwardIterator::getForward();
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline Tuint CReverseIterator<T_BackwardIterator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  return T_BackwardIterator::stepBackward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline Tuint CReverseIterator<T_BackwardIterator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  return T_BackwardIterator::stepForward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
template <class T_Archive>
inline Tbool CReverseIterator<T_BackwardIterator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::NIterators::CReverseIterator<T_BackwardIterator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((T_BackwardIterator&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_BackwardIterator>
inline void CReverseIterator<T_BackwardIterator>::swap(CReverseIterator<T_BackwardIterator>& a_rInstance)
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
