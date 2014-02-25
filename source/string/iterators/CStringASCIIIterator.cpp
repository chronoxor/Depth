/*!
 *  \file    CStringASCIIIterator.cpp ASCII string non constant iterator
 *           definitions. It gives ability to get and modify ASCII string
 *           characters and to do random moving through the ASCII string
 *           characters.
 *  \brief   ASCII string non constant iterator class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: ASCII string non constant iterator class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String iterators
    VERSION:   1.0
    CREATED:   07.08.2008 02:52:09

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/string/CStringASCII.hpp>
/*==========================================================================*/
#ifndef __CSTRINGASCIIITERATOR_CPP__
#define __CSTRINGASCIIITERATOR_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tuint CStringASCIIIterator::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid ASCII string iterator."))
  {
    return 0;
  }

  // Get available steps count.
  Tuint steps = NAlgorithms::NCommon::min(a_cStepCount, (m_pContainer->getSize() - m_Index - 1));
  // Step forward by given steps.
  m_Index += steps;
  // Return step count, that we have done.
  return steps;
}
/*--------------------------------------------------------------------------*/
Tuint CStringASCIIIterator::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid ASCII string iterator."))
  {
    return 0;
  }

  // Get available steps count.
  Tuint steps = NAlgorithms::NCommon::min(a_cStepCount, m_Index);
  // Step forward by given steps.
  m_Index -= steps;
  // Return step count, that we have done.
  return steps;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::stepIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot do indexed step with the invalid ASCII string container."))
  {
    return false;
  }
  // Check index value and the ASCII string bounds.
  ASSERT(((a_cIndex < m_pContainer->getSize()) || (a_cIndex == 0)), STR("Cannot do indexed step with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_pContainer->getSize())
  {
    return false;
  }

  m_Index = a_cIndex;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::insertForward(const Tschar& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new character into the invalid ASCII string container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new character to the invalid iterator of the non empty ASCII string (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  Tbool empty = m_pContainer->isEmpty();

  if (m_pContainer->insertIndex((empty ? 0 : (m_Index + 1)), a_crItem))
  {
    if (empty)
      m_Index = 0;
    else
      ++m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::insertForward(const CStringASCII& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new sub-string into the invalid ASCII string container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new sub-string to the invalid iterator of the non empty ASCII string (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  Tbool empty = m_pContainer->isEmpty();

  if (m_pContainer->insertIndex((empty ? 0 : (m_Index + 1)), a_crItem))
  {
    if (empty)
      m_Index = 0;
    else
      ++m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::insertNext(const Tschar& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new character into the invalid ASCII string iterator."))
  {
    return false;
  }

  return m_pContainer->insertIndex(m_Index + 1, a_crItem);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::insertNext(const CStringASCII& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new sub-string into the invalid ASCII string iterator."))
  {
    return false;
  }

  return m_pContainer->insertIndex(m_Index + 1, a_crItem);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::insertBackward(const Tschar& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new character into the invalid ASCII string container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new character to the invalid iterator of the non empty ASCII string (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  Tbool empty = m_pContainer->isEmpty();

  if (m_pContainer->insertIndex((empty ? 0 : m_Index), a_crItem))
  {
    if (empty)
      m_Index = 0;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::insertBackward(const CStringASCII& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new sub-string into the invalid ASCII string container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new sub-string to the invalid iterator of the non empty ASCII string (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  Tbool empty = m_pContainer->isEmpty();

  if (m_pContainer->insertIndex((empty ? 0 : m_Index), a_crItem))
  {
    if (empty)
      m_Index = 0;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::insertPrev(const Tschar& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new character into the invalid ASCII string iterator."))
  {
    return false;
  }

  if (m_pContainer->insertIndex(m_Index, a_crItem))
  {
    ++m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::insertPrev(const CStringASCII& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new sub-string into the invalid ASCII string iterator."))
  {
    return false;
  }

  if (m_pContainer->insertIndex(m_Index, a_crItem))
  {
    m_Index += a_crItem.getSize();
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::insertIndex(const Tuint a_cIndex, const Tschar& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new character into the invalid ASCII string container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new character to the invalid iterator of the non empty ASCII string (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  Tbool empty = m_pContainer->isEmpty();

  if (m_pContainer->insertIndex(a_cIndex, a_crItem))
  {
    if (empty)
      m_Index = 0;
    else if (m_Index >= a_cIndex)
      ++m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::insertIndex(const Tuint a_cIndex, const CStringASCII& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new sub-string into the invalid ASCII string container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new sub-string to the invalid iterator of the non empty ASCII string (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  Tbool empty = m_pContainer->isEmpty();

  if (m_pContainer->insertIndex(a_cIndex, a_crItem))
  {
    if (empty)
      m_Index = 0;
    else if (m_Index >= a_cIndex)
      m_Index += a_crItem.getSize();
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeForward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index))
  {
    if ((m_Index > 0) && (m_Index == m_pContainer->getSize()))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeForward(Tschar& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index, a_rItem))
  {
    if ((m_Index > 0) && (m_Index == m_pContainer->getSize()))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeForward(const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sub-string from the invalid ASCII string iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index, a_cSize))
  {
    if ((m_Index > 0) && (m_Index == m_pContainer->getSize()))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeForward(const Tuint a_cSize, CStringASCII& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sub-string from the invalid ASCII string iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index, a_cSize, a_rItem))
  {
    if ((m_Index > 0) && (m_Index == m_pContainer->getSize()))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeNext()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }
  // Check index value and the ASCII string bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove character from the next forward ASCII string position without a corresponding character, from the end ASCII string position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeNext(Tschar& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }
  // Check index value and the ASCII string bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove character from the next forward ASCII string position without a corresponding character, from the end ASCII string position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1, a_rItem);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeNext(const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sub-string from the invalid ASCII string iterator."))
  {
    return false;
  }
  // Check index value and the ASCII string bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove sub-string from the next forward ASCII string position without a corresponding character, from the end ASCII string position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeNext(const Tuint a_cSize, CStringASCII& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sub-string from the invalid ASCII string iterator."))
  {
    return false;
  }
  // Check index value and the ASCII string bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove sub-string from the next forward ASCII string position without a corresponding character, from the end ASCII string position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1, a_cSize, a_rItem);
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeBackward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index))
  {
    if (m_Index > 0)
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeBackward(Tschar& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index, a_rItem))
  {
    if (m_Index > 0)
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeBackward(const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sub-string from the invalid ASCII string iterator."))
  {
    return false;
  }

  Tuint index = ((a_cSize == 0) ? m_Index : (((m_Index + 1) > a_cSize) ? (m_Index - a_cSize + 1) : 0));
  Tuint size = ((a_cSize == 0) ? 0 : (((m_Index + 1) > a_cSize) ? a_cSize : (m_Index + 1)));
  if (m_pContainer->removeIndex(index, size))
  {
    m_Index = ((index > 0) ? (index - 1) : 0);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeBackward(const Tuint a_cSize, CStringASCII& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sub-string from the invalid ASCII string iterator."))
  {
    return false;
  }

  Tuint index = ((a_cSize == 0) ? m_Index : (((m_Index + 1) > a_cSize) ? (m_Index - a_cSize + 1) : 0));
  Tuint size = ((a_cSize == 0) ? 0 : (((m_Index + 1) > a_cSize) ? a_cSize : (m_Index + 1)));
  if (m_pContainer->removeIndex(index, size, a_rItem))
  {
    m_Index = ((index > 0) ? (index - 1) : 0);
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removePrev()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }
  // Check index value and the ASCII string bounds.
  ASSERT((m_Index > 0), STR("Cannot remove character from the previous backward ASCII string position without a corresponding character, from the begin ASCII string position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index - 1))
  {
    --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removePrev(Tschar& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }
  // Check index value and the ASCII string bounds.
  ASSERT((m_Index > 0), STR("Cannot remove character from the previous backward ASCII string position without a corresponding character, from the begin ASCII string position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  if (m_pContainer->removeIndex(m_Index - 1, a_rItem))
  {
    --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removePrev(const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sub-string from the invalid ASCII string iterator."))
  {
    return false;
  }
  // Check index value and the ASCII string bounds.
  ASSERT((m_Index > 0), STR("Cannot remove sub-string from the previous backward ASCII string position without a corresponding character, from the begin ASCII string position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  Tuint index = ((a_cSize == 0) ? (m_Index - 1) : ((m_Index > a_cSize) ? (m_Index - a_cSize) : 0));
  Tuint size = ((a_cSize == 0) ? 0 : ((m_Index > a_cSize) ? a_cSize : m_Index));
  if (m_pContainer->removeIndex(index, size))
  {
    m_Index = index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removePrev(const Tuint a_cSize, CStringASCII& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove sub-string from the invalid ASCII string iterator."))
  {
    return false;
  }
  // Check index value and the ASCII string bounds.
  ASSERT((m_Index > 0), STR("Cannot remove sub-string from the previous backward ASCII string position without a corresponding character, from the begin ASCII string position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
  {
    return false;
  }

  Tuint index = ((a_cSize == 0) ? (m_Index - 1) : ((m_Index > a_cSize) ? (m_Index - a_cSize) : 0));
  Tuint size = ((a_cSize == 0) ? 0 : ((m_Index > a_cSize) ? a_cSize : m_Index));
  if (m_pContainer->removeIndex(index, size, a_rItem))
  {
    m_Index = index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(a_cIndex))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeIndex(const Tuint a_cIndex, Tschar& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }

  if (m_pContainer->removeIndex(a_cIndex, a_rItem))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
      --m_Index;
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeIndex(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }

  // Calculate real count of removing items.
  Tuint size = NAlgorithms::NCommon::min(m_pContainer->getSize() - a_cIndex, a_cSize);

  if (m_pContainer->removeIndex(a_cIndex, a_cSize))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
    {
      if (m_Index >= (a_cIndex + size))
        m_Index -= size;
      else
        m_Index = a_cIndex;
    }
    return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CStringASCIIIterator::removeIndex(const Tuint a_cIndex, const Tuint a_cSize, CStringASCII& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove character from the invalid ASCII string iterator."))
  {
    return false;
  }

  // Calculate real count of removing items.
  Tuint size = NAlgorithms::NCommon::min(m_pContainer->getSize() - a_cIndex, a_cSize);

  if (m_pContainer->removeIndex(a_cIndex, a_cSize, a_rItem))
  {
    if ((m_Index > 0) && (m_Index >= a_cIndex))
    {
      if (m_Index >= (a_cIndex + size))
        m_Index -= size;
      else
        m_Index = a_cIndex;
    }
    return true;
  }
  else
    return false;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
