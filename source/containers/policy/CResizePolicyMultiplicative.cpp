/*!
 *  \file    CResizePolicyMultiplicative.cpp Multiplicative resize policy
 *           interface. It use multiplicative resize factor allocation
 *           strategy.
 *  \brief   Multiplicative resize policy class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Multiplicative resize policy class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers policy
    VERSION:   1.0
    CREATED:   16.03.2006 20:20:31

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#include <Depth/include/containers/policy/CResizePolicyMultiplicative.hpp>
/*==========================================================================*/
#ifndef __CRESIZEPOLICYMULTIPLICATIVE_CPP__
#define __CRESIZEPOLICYMULTIPLICATIVE_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NPolicy {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CResizePolicyMultiplicative::setResizeFactor(const Tuint a_cResizeFactor)
{ CALL
  if (a_cResizeFactor < 2)
  {
    m_ResizeFactor = 2;
    return false;
  }
  else
  {
    m_ResizeFactor = a_cResizeFactor;
    return true;
  }
}
/*--------------------------------------------------------------------------*/
Tuint CResizePolicyMultiplicative::resize(const Tuint a_cSize)
{ CALL
  // Check if we need to make a lower reallocation.
  if (a_cSize < m_LoCapacity)
  {
    if (a_cSize == 0)
    {
      m_LoCapacity = 0;
      m_HiCapacity = m_ResizeFactor;
    }
    else
    {
      Tuint n = (m_LoCapacity / (m_ResizeFactor * a_cSize)) + (((m_LoCapacity % (m_ResizeFactor * a_cSize)) == 0) ? 0 : 1);

      m_LoCapacity = m_LoCapacity / (n * m_ResizeFactor);
      if (m_LoCapacity == 1)
        m_LoCapacity = 0;
      m_HiCapacity /= n * m_ResizeFactor;
    }
  }
  // Check if we need to make a high reallocation.
  else if (a_cSize > m_HiCapacity)
  {
    Tuint capacity = ((m_HiCapacity == 0) ? 1 : m_HiCapacity);
    Tuint n = (a_cSize / (m_ResizeFactor * capacity)) + (((a_cSize % (m_ResizeFactor * capacity)) == 0) ? 0 : 1);

    m_HiCapacity = n * m_ResizeFactor * capacity;
    if (m_LoCapacity > 0)
      m_LoCapacity *= n * m_ResizeFactor;
    else
      m_LoCapacity = ((m_HiCapacity > m_ResizeFactor) ? m_ResizeFactor : 0);
  }
  return m_HiCapacity;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
