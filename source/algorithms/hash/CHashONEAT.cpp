/*!
 *  \file    CHashONEAT.cpp ONEAT hash function algorithm.
 *  \brief   ONEAT hash function algorithm (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: ONEAT hash function algorithm (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   11.03.2007 01:15:52

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
#include <Depth/include/algorithms/hash/CHashONEAT.hpp>
/*==========================================================================*/
#ifndef __CHASHONEAT_CPP__
#define __CHASHONEAT_CPP__
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
Tuint CHashONEAT::hash(Tcbuffer a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint i = a_cSize;
  // Update current size.
  m_Size += a_cSize;
  // Hash begin of the key.
  switch (m_Index)
  {
    case  1: if (i-- > 0) { m_A += ((Tuint)(*a_cpBuffer++) <<  8); ++m_Index;        } else return a_cSize;
    case  2: if (i-- > 0) { m_A += ((Tuint)(*a_cpBuffer++) << 16); ++m_Index;        } else return a_cSize;
    case  3: if (i-- > 0) { m_A += ((Tuint)(*a_cpBuffer++) << 24); ++m_Index;        } else return a_cSize;
    case  4: if (i-- > 0) { m_B += (*a_cpBuffer++);                ++m_Index;        } else return a_cSize;
    case  5: if (i-- > 0) { m_B += ((Tuint)(*a_cpBuffer++) <<  8); ++m_Index;        } else return a_cSize;
    case  6: if (i-- > 0) { m_B += ((Tuint)(*a_cpBuffer++) << 16); ++m_Index;        } else return a_cSize;
    case  7: if (i-- > 0) { m_B += ((Tuint)(*a_cpBuffer++) << 24); ++m_Index;        } else return a_cSize;
    case  8: if (i-- > 0) { m_C += (*a_cpBuffer++);                ++m_Index;        } else return a_cSize;
    case  9: if (i-- > 0) { m_C += ((Tuint)(*a_cpBuffer++) <<  8); ++m_Index;        } else return a_cSize;
    case 10: if (i-- > 0) { m_C += ((Tuint)(*a_cpBuffer++) << 16); ++m_Index;        } else return a_cSize;
    case 11: if (i-- > 0) { m_C += ((Tuint)(*a_cpBuffer++) << 24); ++m_Index; mix(); } else return a_cSize;
  }
  // Hash most of the key.
  while (i >= 12)
  {
    m_A += (a_cpBuffer[ 0] + ((Tuint)a_cpBuffer[ 1] << 8) + ((Tuint)a_cpBuffer[ 2] << 16) + ((Tuint)a_cpBuffer[ 3] << 24));
    m_B += (a_cpBuffer[ 4] + ((Tuint)a_cpBuffer[ 5] << 8) + ((Tuint)a_cpBuffer[ 6] << 16) + ((Tuint)a_cpBuffer[ 7] << 24));
    m_C += (a_cpBuffer[ 8] + ((Tuint)a_cpBuffer[ 9] << 8) + ((Tuint)a_cpBuffer[10] << 16) + ((Tuint)a_cpBuffer[11] << 24));
    mix();
    a_cpBuffer += 12;
    i -= 12;
  }
  // Update current index.
  m_Index = i;
  // Hash rest of the key.
  switch (m_Index)
  {
    case 11: m_C += ((Tuint)a_cpBuffer[10] << 16);
    case 10: m_C += ((Tuint)a_cpBuffer[ 9] <<  8);
    case  9: m_C += a_cpBuffer[8];
    case  8: m_B += ((Tuint)a_cpBuffer[ 7] << 24);
    case  7: m_B += ((Tuint)a_cpBuffer[ 6] << 16);
    case  6: m_B += ((Tuint)a_cpBuffer[ 5] <<  8);
    case  5: m_B += a_cpBuffer[4];
    case  4: m_A += ((Tuint)a_cpBuffer[ 3] << 24);
    case  3: m_A += ((Tuint)a_cpBuffer[ 2] << 16);
    case  2: m_A += ((Tuint)a_cpBuffer[ 1] <<  8);
    case  1: m_A += a_cpBuffer[0];
  }
  return a_cSize;
}
/*--------------------------------------------------------------------------*/
Tbool CHashONEAT::close()
{ CALL
  // Add hash size.
  m_C += m_Size;
  // Final mixing.
  mix();
  return true;
}
/*--------------------------------------------------------------------------*/
void CHashONEAT::mix()
{ CALL
  m_A -= m_B; m_A -= m_C; m_A ^= (m_C >> 13);
  m_B -= m_C; m_B -= m_A; m_B ^= (m_A <<  8);
  m_C -= m_A; m_C -= m_B; m_C ^= (m_B >> 13);
  m_A -= m_B; m_A -= m_C; m_A ^= (m_C >> 12);
  m_B -= m_C; m_B -= m_A; m_B ^= (m_A << 16);
  m_C -= m_A; m_C -= m_B; m_C ^= (m_B >>  5);
  m_A -= m_B; m_A -= m_C; m_A ^= (m_C >>  3);
  m_B -= m_C; m_B -= m_A; m_B ^= (m_A << 10);
  m_C -= m_A; m_C -= m_B; m_C ^= (m_B >> 15);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
