/*!
 *  \file    CCopyPolicyAssign.inl Assign copy policy class. This class uses
 *           assign operator to copy items from one memory block to another.
 *  \brief   Assign copy policy class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Assign copy policy class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers policy
    VERSION:   1.0
    CREATED:   16.03.2006 22:02:25

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
#ifndef __CCOPYPOLICYASSIGN_INL__
#define __CCOPYPOLICYASSIGN_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NPolicy {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline void CCopyPolicyAssign::copy(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount)
{ CALL
  Tuint counter = a_cCount;

  while (counter-- > 0)
    *a_pDestination++ = *a_cpSource++;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CCopyPolicyAssign::copyReverse(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount)
{ CALL
  Tuint counter = a_cCount;

  a_cpSource = a_cpSource + counter - 1;
  while (counter-- > 0)
    *a_pDestination++ = *a_cpSource--;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CCopyPolicyAssign::move(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount)
{ CALL
  Tuint counter = a_cCount;

  if (counter > 0)
  {
    if ((a_pDestination <= a_cpSource) || (a_pDestination >= (a_cpSource + counter)))
    {
      // Non-Overlapping Buffers: copy from lower addresses to higher addresses
      while (counter-- > 0)
        *a_pDestination++ = *a_cpSource++;
    }
    else
    {
      // Overlapping Buffers: copy from higher addresses to lower addresses
      a_pDestination = a_pDestination + counter - 1;
      a_cpSource = a_cpSource + counter - 1;
      while (counter-- > 0)
        *a_pDestination-- = *a_cpSource--;
    }
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CCopyPolicyAssign::moveReverse(T_Type* a_pDestination, const T_Type* a_cpSource, const Tuint a_cCount)
{ CALL
  Tuint counter = a_cCount;

  if (counter > 0)
  {
    if ((a_pDestination >= (a_cpSource + counter)) || (a_cpSource >= (a_pDestination + counter)))
    {
      // Non-Overlapping Buffers: copy from lower addresses to higher addresses
      a_cpSource = a_cpSource + counter - 1;
      while (counter-- > 0)
        *a_pDestination++ = *a_cpSource--;
    }
    else
    {
      // Overlapping Buffers: copy from higher addresses to lower addresses
      T_Type *min, *max;
      Tbool first_block_copy;
      Tsint length;
      if (a_pDestination >= a_cpSource)
      {
        min = (T_Type*)a_cpSource;
        max = (T_Type*)a_pDestination;
        first_block_copy = true;
      }
      else
      {
        min = (T_Type*)a_pDestination;
        max = (T_Type*)a_cpSource;
        first_block_copy = false;
      }
      length = counter - (max - min);
      min = max;
      max = max + length - 1;
      if (first_block_copy)
      {
        a_cpSource = min - 1;
        a_pDestination = max + 1;
      }
      else
      {
        a_cpSource = min + counter - 1;
        a_pDestination = max - counter + 1;
      }
      length /= 2;
      counter -= length;
      while (length-- > 0)
      {
        NAlgorithms::NCommon::swap(*min, *max);
        ++min;
        --max;
      }
      if (first_block_copy)
      {
        while (counter-- > 0)
          *a_pDestination++ = *a_cpSource--;
      }
      else
      {
        while (counter-- > 0)
          *a_pDestination-- = *a_cpSource++;
      }
    }
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
