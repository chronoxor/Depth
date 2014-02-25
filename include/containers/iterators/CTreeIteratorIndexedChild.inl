/*!
 *  \file    CTreeIteratorIndexedChild.inl Tree indexed child iterator
 *           definitions. It gives ability to do indexed child moving
 *           through the tree nodes.
 *  \brief   Tree indexed child iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree indexed child iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   11.07.2006 21:45:28

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
#ifndef __CTREEITERATORINDEXEDCHILD_INL__
#define __CTREEITERATORINDEXEDCHILD_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator>::CTreeIteratorIndexedChild(const Tuint a_cIndex/* = 0 */) :
  T_TreeIterator(),
  m_Index(a_cIndex)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator>::CTreeIteratorIndexedChild(const T_TreeIterator& a_crTreeIterator, const Tuint a_cIndex/* = 0 */) :
  T_TreeIterator(),
  m_Index(a_cIndex)
{ CALL
  set(a_crTreeIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator>::CTreeIteratorIndexedChild(const CTreeIteratorIndexedChild<T_TreeIterator>& a_crInstance) :
  T_TreeIterator(),
  m_Index()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator>::~CTreeIteratorIndexedChild()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator>& CTreeIteratorIndexedChild<T_TreeIterator>::operator = (const T_TreeIterator& a_crTreeIterator)
{ CALL
  set(a_crTreeIterator);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator>& CTreeIteratorIndexedChild<T_TreeIterator>::operator = (const CTreeIteratorIndexedChild<T_TreeIterator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator>& CTreeIteratorIndexedChild<T_TreeIterator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator>& CTreeIteratorIndexedChild<T_TreeIterator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator> CTreeIteratorIndexedChild<T_TreeIterator>::operator ++ (int)
{ CALL
  CTreeIteratorIndexedChild<T_TreeIterator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator> CTreeIteratorIndexedChild<T_TreeIterator>::operator -- (int)
{ CALL
  CTreeIteratorIndexedChild<T_TreeIterator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator> operator + (const CTreeIteratorIndexedChild<T_TreeIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTreeIteratorIndexedChild<T_TreeIterator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator> operator - (const CTreeIteratorIndexedChild<T_TreeIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTreeIteratorIndexedChild<T_TreeIterator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline void CTreeIteratorIndexedChild<T_TreeIterator>::set(const T_TreeIterator& a_crTreeIterator)
{ CALL
  T_TreeIterator::set(a_crTreeIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline void CTreeIteratorIndexedChild<T_TreeIterator>::set(const CTreeIteratorIndexedChild<T_TreeIterator>& a_crInstance)
{ CALL
  T_TreeIterator::set(a_crInstance);
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CTreeIteratorIndexedChild<T_Type>::setIndex(const Tuint a_cIndex)
{ CALL
  m_Index = a_cIndex;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CTreeIteratorIndexedChild<T_Type>::getIndex() const
{ CALL
  return m_Index;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator> CTreeIteratorIndexedChild<T_TreeIterator>::getForward() const
{ CALL
  CTreeIteratorIndexedChild<T_TreeIterator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CTreeIteratorIndexedChild<T_TreeIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorIndexedChild<T_TreeIterator> CTreeIteratorIndexedChild<T_TreeIterator>::getBackward() const
{ CALL
  CTreeIteratorIndexedChild<T_TreeIterator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CTreeIteratorIndexedChild<T_TreeIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline Tuint CTreeIteratorIndexedChild<T_TreeIterator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_TreeIterator::isValid(), STR("Cannot step forward with the invalid tree iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step indexed child by given steps.
  T_TreeIterator it_indexed_child(T_TreeIterator::getIndexedChild(m_Index));
  while (it_indexed_child.isValid() && (counter > 0))
  {
    T_TreeIterator::operator = (it_indexed_child);
    it_indexed_child = T_TreeIterator::getIndexedChild(m_Index);
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline Tuint CTreeIteratorIndexedChild<T_TreeIterator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_TreeIterator::isValid(), STR("Cannot step backward with the invalid tree iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step parent by given steps.
  T_TreeIterator it_parent(T_TreeIterator::getParent());
  while (it_parent.isValid() && (counter > 0))
  {
    T_TreeIterator::operator = (it_parent);
    it_parent = T_TreeIterator::getParent();
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
template <class T_Archive>
inline Tbool CTreeIteratorIndexedChild<T_TreeIterator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CTreeIteratorIndexedChild<T_TreeIterator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((T_TreeIterator&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline void CTreeIteratorIndexedChild<T_TreeIterator>::swap(CTreeIteratorIndexedChild<T_TreeIterator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((T_TreeIterator&)(*this), (T_TreeIterator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Index, a_rInstance.m_Index);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
