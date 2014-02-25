/*!
 *  \file    CTreeIteratorBreadthNext.inl Tree breadth next iterator
 *           definitions. It gives ability to do breadth next moving
 *           through the tree nodes.
 *  \brief   Tree breadth next iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree breadth next iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   12.07.2006 21:58:24

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
#ifndef __CTREEITERATORBREADTHNEXT_INL__
#define __CTREEITERATORBREADTHNEXT_INL__
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
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::CTreeIteratorBreadthNext() :
  T_TreeIterator(),
  m_Cache()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::CTreeIteratorBreadthNext(const T_TreeIterator& a_crTreeIterator) :
  T_TreeIterator(),
  m_Cache()
{ CALL
  set(a_crTreeIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::CTreeIteratorBreadthNext(const CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& a_crInstance) :
  T_TreeIterator(),
  m_Cache()
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::~CTreeIteratorBreadthNext()
{ CALL
  m_Cache.clear();
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::operator = (const T_TreeIterator& a_crTreeIterator)
{ CALL
  set(a_crTreeIterator);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::operator = (const CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::operator ++ (int)
{ CALL
  CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::operator -- (int)
{ CALL
  CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> operator + (const CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> operator - (const CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline Tbool CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::set(const T_TreeIterator& a_crTreeIterator)
{ CALL
  // Clear current cache.
  if (!m_Cache.clear())
    return false;
  // Copy iterator attributes.
  T_TreeIterator::operator = (a_crTreeIterator);
  // Update cache of the iteration.
  T_TreeIterator it_first_child;
  T_TreeIterator it_next_sibling(a_crTreeIterator);
  while (it_next_sibling.isValid())
  {
    it_first_child = it_next_sibling.getFirstChild();
    if (it_first_child.isValid())
      if (!m_Cache.insertLast(it_first_child))
        return false;
    it_next_sibling = it_next_sibling.getNextSibling();
  }
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline Tbool CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::set(const CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CTreeIteratorBreadthNext class instance."))
  {
    return false;
  }

  // Clear current cache.
  if (!m_Cache.clear())
    return false;
  // Copy iterator attributes.
  T_TreeIterator::operator = (a_crInstance);
  // Copy cache of the iteration.
  if (!m_Cache.set(a_crInstance.m_Cache))
    return false;
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::getForward() const
{ CALL
  CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>());
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::getBackward() const
{ CALL
  CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>());
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline Tuint CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_TreeIterator::isValid(), STR("Cannot step forward with the invalid tree iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step breadth next by given steps.
  T_TreeIterator it_cache;
  T_TreeIterator it_next_sibling;
  while (counter > 0)
  {
    Tbool stop = false;
    it_next_sibling = T_TreeIterator::getNextSibling();
    if (it_next_sibling.isValid())
    {
      T_TreeIterator::operator = (it_next_sibling);
      --counter;
    }
    else
    {
      if (m_Cache.isEmpty())
        break;
      else
      {
        if (m_Cache.removeFirst(it_cache))
        {
          T_TreeIterator::operator = (it_cache);
          --counter;
          // Update cache of the iteration.
          do
          {
            it_next_sibling = it_cache.getFirstChild();
            if (it_next_sibling.isValid())
              if (!m_Cache.insertLast(it_next_sibling))
              {
                stop = true;
                break;
              }
            it_cache = it_cache.getNextSibling();
          } while (it_cache.isValid());
        }
        else
          break;
      }
    }
    if (stop)
      break;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline Tuint CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  IGNORE_UNUSED(a_cStepCount);

  WARNING(STR("Cannot step backward with the breadth next tree iterator."));
  return 0;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
template <class T_Archive>
inline Tbool CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((T_TreeIterator&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator, class T_Allocator>
inline void CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>::swap(CTreeIteratorBreadthNext<T_TreeIterator, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((T_TreeIterator&)(*this), (T_TreeIterator&)a_rInstance);
  NAlgorithms::NCommon::swap(m_Cache, a_rInstance.m_Cache);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
