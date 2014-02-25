/*!
 *  \file    CReverseRandomIterator.inl Reverse random access iterator wrapper
 *           class. It reverses move operations of the random access iterator.
 *  \brief   Reverse random access iterator wrapper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Reverse random access iterator wrapper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   16.04.2007 02:28:22

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
#ifndef __CREVERSERANDOMITERATOR_INL__
#define __CREVERSERANDOMITERATOR_INL__
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
inline CReverseRandomIterator<T_RandomIterator>::CReverseRandomIterator() :
  T_RandomIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator>::CReverseRandomIterator(const T_RandomIterator& a_crRandomIterator) :
  T_RandomIterator()
{ CALL
  set(a_crRandomIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator>::~CReverseRandomIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_RandomIterator>
inline Tbool operator < (const CReverseRandomIterator<T_RandomIterator>& a_crInstance1, const CReverseRandomIterator<T_RandomIterator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.getContainerPtr() == a_crInstance2.getContainerPtr()) && (a_crInstance1.getPosition() < a_crInstance2.getPosition()));
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tbool operator > (const CReverseRandomIterator<T_RandomIterator>& a_crInstance1, const CReverseRandomIterator<T_RandomIterator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.getContainerPtr() == a_crInstance2.getContainerPtr()) && (a_crInstance1.getPosition() > a_crInstance2.getPosition()));
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tbool operator <= (const CReverseRandomIterator<T_RandomIterator>& a_crInstance1, const CReverseRandomIterator<T_RandomIterator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.getContainerPtr() == a_crInstance2.getContainerPtr()) && (a_crInstance1.getPosition() <= a_crInstance2.getPosition()));
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tbool operator >= (const CReverseRandomIterator<T_RandomIterator>& a_crInstance1, const CReverseRandomIterator<T_RandomIterator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.getContainerPtr() == a_crInstance2.getContainerPtr()) && (a_crInstance1.getPosition() >= a_crInstance2.getPosition()));
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator>& CReverseRandomIterator<T_RandomIterator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator>& CReverseRandomIterator<T_RandomIterator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator> CReverseRandomIterator<T_RandomIterator>::operator ++ (int)
{ CALL
  CReverseRandomIterator<T_RandomIterator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator> CReverseRandomIterator<T_RandomIterator>::operator -- (int)
{ CALL
  CReverseRandomIterator<T_RandomIterator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator> operator + (const CReverseRandomIterator<T_RandomIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CReverseRandomIterator<T_RandomIterator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator> operator - (const CReverseRandomIterator<T_RandomIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CReverseRandomIterator<T_RandomIterator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator> CReverseRandomIterator<T_RandomIterator>::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator> CReverseRandomIterator<T_RandomIterator>::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator> CReverseRandomIterator<T_RandomIterator>::getForward() const
{ CALL
  return T_RandomIterator::getBackward();
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator> CReverseRandomIterator<T_RandomIterator>::getBackward() const
{ CALL
  return T_RandomIterator::getForward();
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline CReverseRandomIterator<T_RandomIterator> CReverseRandomIterator<T_RandomIterator>::getIndex(const Tuint a_cIndex) const
{ CALL
  return T_RandomIterator::getIndex((T_RandomIterator::getSize() > 0) ? (T_RandomIterator::getSize() - a_cIndex - 1) : 0);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tuint CReverseRandomIterator<T_RandomIterator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  return T_RandomIterator::stepBackward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tuint CReverseRandomIterator<T_RandomIterator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  return T_RandomIterator::stepForward(a_cStepCount);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tbool CReverseRandomIterator<T_RandomIterator>::stepIndex(const Tuint a_cIndex)
{ CALL
  return T_RandomIterator::stepIndex((T_RandomIterator::getSize() > 0) ? (T_RandomIterator::getSize() - a_cIndex - 1) : 0);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tuint CReverseRandomIterator<T_RandomIterator>::getSize() const
{ CALL
  return T_RandomIterator::getSize();
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tbool CReverseRandomIterator<T_RandomIterator>::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline Tuint CReverseRandomIterator<T_RandomIterator>::getPosition() const
{ CALL
  return ((T_RandomIterator::getSize() > 0) ? (T_RandomIterator::getSize() - T_RandomIterator::getPosition() - 1) : 0);
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
template <class T_Archive>
inline Tbool CReverseRandomIterator<T_RandomIterator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NUtility::NIterators::CReverseRandomIterator<T_RandomIterator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((T_RandomIterator&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_RandomIterator>
inline void CReverseRandomIterator<T_RandomIterator>::swap(CReverseRandomIterator<T_RandomIterator>& a_rInstance)
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
