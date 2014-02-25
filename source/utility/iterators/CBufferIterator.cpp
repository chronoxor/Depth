/*!
 *  \file    CBufferIterator.cpp Byte buffer non constant iterator
 *           definitions. It gives ability to get and modify single
 *           bytes inside the byte buffer and to do random moving
 *           through the bytes.
 *  \brief   Byte buffer non constant iterator class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Byte buffer non constant iterator class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities iterators
    VERSION:   1.0
    CREATED:   20.08.2008 01:19:57

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
#include <Depth/include/utility/CBuffer.hpp>
/*==========================================================================*/
#ifndef __CBUFFERITERATOR_CPP__
#define __CBUFFERITERATOR_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tuint CBufferIterator::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid byte buffer iterator."))
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
Tuint CBufferIterator::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid byte buffer iterator."))
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
Tbool CBufferIterator::stepIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot do indexed step with the invalid byte buffer container."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT(((a_cIndex < m_pContainer->getSize()) || (a_cIndex == 0)), STR("Cannot do indexed step with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_pContainer->getSize())
  {
    return false;
  }

  m_Index = a_cIndex;
  return true;
}
/*--------------------------------------------------------------------------*/
Tbool CBufferIterator::insertForward(const Tbyte& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new byte into the invalid byte buffer container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new byte to the invalid iterator of the non empty byte buffer (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
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
Tbool CBufferIterator::insertForward(const CBuffer& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new buffer into the invalid byte buffer container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new buffer to the invalid iterator of the non empty byte buffer (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
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
Tbool CBufferIterator::insertNext(const Tbyte& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new byte into the invalid byte buffer iterator."))
  {
    return false;
  }

  return m_pContainer->insertIndex(m_Index + 1, a_crItem);
}
/*--------------------------------------------------------------------------*/
Tbool CBufferIterator::insertNext(const CBuffer& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new buffer into the invalid byte buffer iterator."))
  {
    return false;
  }

  return m_pContainer->insertIndex(m_Index + 1, a_crItem);
}
/*--------------------------------------------------------------------------*/
Tbool CBufferIterator::insertBackward(const Tbyte& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new byte into the invalid byte buffer container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new byte to the invalid iterator of the non empty byte buffer (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
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
Tbool CBufferIterator::insertBackward(const CBuffer& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new buffer into the invalid byte buffer container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new buffer to the invalid iterator of the non empty byte buffer (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
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
Tbool CBufferIterator::insertPrev(const Tbyte& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new byte into the invalid byte buffer iterator."))
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
Tbool CBufferIterator::insertPrev(const CBuffer& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new buffer into the invalid byte buffer iterator."))
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
Tbool CBufferIterator::insertIndex(const Tuint a_cIndex, const Tbyte& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new byte into the invalid byte buffer container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new byte to the invalid iterator of the non empty byte buffer (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
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
Tbool CBufferIterator::insertIndex(const Tuint a_cIndex, const CBuffer& a_crItem)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new buffer into the invalid byte buffer container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_Index < m_pContainer->getSize())), STR("Cannot insert a new buffer to the invalid iterator of the non empty byte buffer (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
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
Tbool CBufferIterator::removeForward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
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
Tbool CBufferIterator::removeForward(Tbyte& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
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
Tbool CBufferIterator::removeForward(const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove buffer from the invalid byte buffer iterator."))
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
Tbool CBufferIterator::removeForward(const Tuint a_cSize, CBuffer& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove buffer from the invalid byte buffer iterator."))
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
Tbool CBufferIterator::removeNext()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove byte from the next forward byte buffer position without a corresponding byte, from the end byte buffer position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1);
}
/*--------------------------------------------------------------------------*/
Tbool CBufferIterator::removeNext(Tbyte& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove byte from the next forward byte buffer position without a corresponding byte, from the end byte buffer position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1, a_rItem);
}
/*--------------------------------------------------------------------------*/
Tbool CBufferIterator::removeNext(const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove buffer from the invalid byte buffer iterator."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove buffer from the next forward byte buffer position without a corresponding byte, from the end byte buffer position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CBufferIterator::removeNext(const Tuint a_cSize, CBuffer& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove buffer from the invalid byte buffer iterator."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT(((m_Index + 1) < m_pContainer->getSize()), STR("Cannot remove buffer from the next forward byte buffer position without a corresponding byte, from the end byte buffer position (index = %u, size = %u).") COMMA (m_Index + 1) COMMA m_pContainer->getSize())
  {
    return false;
  }

  return m_pContainer->removeIndex(m_Index + 1, a_cSize, a_rItem);
}
/*--------------------------------------------------------------------------*/
Tbool CBufferIterator::removeBackward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
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
Tbool CBufferIterator::removeBackward(Tbyte& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
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
Tbool CBufferIterator::removeBackward(const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove buffer from the invalid byte buffer iterator."))
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
Tbool CBufferIterator::removeBackward(const Tuint a_cSize, CBuffer& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove buffer from the invalid byte buffer iterator."))
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
Tbool CBufferIterator::removePrev()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT((m_Index > 0), STR("Cannot remove byte from the previous backward byte buffer position without a corresponding byte, from the begin byte buffer position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
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
Tbool CBufferIterator::removePrev(Tbyte& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT((m_Index > 0), STR("Cannot remove byte from the previous backward byte buffer position without a corresponding byte, from the begin byte buffer position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
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
Tbool CBufferIterator::removePrev(const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove buffer from the invalid byte buffer iterator."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT((m_Index > 0), STR("Cannot remove buffer from the previous backward byte buffer position without a corresponding byte, from the begin byte buffer position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
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
Tbool CBufferIterator::removePrev(const Tuint a_cSize, CBuffer& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove buffer from the invalid byte buffer iterator."))
  {
    return false;
  }
  // Check index value and the byte buffer bounds.
  ASSERT((m_Index > 0), STR("Cannot remove buffer from the previous backward byte buffer position without a corresponding byte, from the begin byte buffer position (index = %u, size = %u).") COMMA m_Index COMMA m_pContainer->getSize())
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
Tbool CBufferIterator::removeIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
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
Tbool CBufferIterator::removeIndex(const Tuint a_cIndex, Tbyte& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
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
Tbool CBufferIterator::removeIndex(const Tuint a_cIndex, const Tuint a_cSize)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
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
Tbool CBufferIterator::removeIndex(const Tuint a_cIndex, const Tuint a_cSize, CBuffer& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove byte from the invalid byte buffer iterator."))
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
