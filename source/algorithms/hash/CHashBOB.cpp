/*!
 *  \file    CHashBOB.cpp BOB hash function algorithm.
 *  \brief   BOB hash function algorithm (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: BOB hash function algorithm (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   10.03.2007 23:05:41

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
#include <Depth/include/algorithms/hash/CHashBOB.hpp>
/*==========================================================================*/
#ifndef __CHASHBOB_CPP__
#define __CHASHBOB_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NHash {
/*==========================================================================*/
/* ALGORITHM IMPLEMENTATIONS                                                */
/*==========================================================================*/
Tuint CHashBOB::hash(Tcbuffer a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint i = a_cSize;
  while (i-- > 0)
  {
    m_Hash += (*a_cpBuffer++);
    m_Hash += (m_Hash << 10);
    m_Hash ^= (m_Hash >> 6);
  }
  return a_cSize;
}
/*--------------------------------------------------------------------------*/
Tbool CHashBOB::close()
{ CALL
  m_Hash += (m_Hash << 3);
  m_Hash ^= (m_Hash >> 11);
  m_Hash += (m_Hash << 15);
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
