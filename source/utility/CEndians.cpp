/*!
 *  \file    CEndians.cpp System byte order utilities definition.
 *  \brief   Static class system byte order utility methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static class system byte order utility methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Utilities
    VERSION:   1.0
    CREATED:   26.01.2006 02:44:14

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
#include <Depth/include/utility/CEndians.hpp>
/*==========================================================================*/
#ifndef __CENDIANS_CPP__
#define __CENDIANS_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtility {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
void CEndians::convert(Tptr a_pBuffer, const Tuint a_cOneElementSize)
{ CALL
  if (a_cOneElementSize > 1)
    for (Tuint i = 0; i < (a_cOneElementSize / 2); ++i)
      NAlgorithms::NNumeric::swapInt(((Tbuffer)a_pBuffer)[i], ((Tbuffer)a_pBuffer)[a_cOneElementSize - i - 1]);
}
/*--------------------------------------------------------------------------*/
void CEndians::convert(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cOneElementSize)
{ CALL
  if (a_cOneElementSize > 1)
    for (Tuint i = 0; i < (a_cOneElementSize / 2); ++i)
    {
      ((Tbuffer)a_pDestination)[i] = ((Tbuffer)a_cpSource)[a_cOneElementSize - i - 1];
      ((Tbuffer)a_pDestination)[a_cOneElementSize - i - 1] = ((Tbuffer)a_cpSource)[i];
    }
}
/*--------------------------------------------------------------------------*/
void CEndians::convert(Tptr a_pBuffer, const Tuint a_cOneElementSize, const Tuint a_cElementsCount)
{ CALL
  if (a_cOneElementSize > 1)
  {
    Tbuffer temp = (Tbuffer)a_pBuffer;
    Tuint temp_counter = a_cElementsCount;

    while (temp_counter-- > 0)
    {
      for (Tuint i = 0; i < (a_cOneElementSize / 2); ++i)
        NAlgorithms::NNumeric::swapInt(temp[i], temp[a_cOneElementSize - i - 1]);
      temp += a_cOneElementSize;
    }
  }
}
/*--------------------------------------------------------------------------*/
void CEndians::convert(Tptr a_pDestination, Tcptr a_cpSource, const Tuint a_cOneElementSize, const Tuint a_cElementsCount)
{ CALL
  if (a_cOneElementSize > 1)
  {
    Tbuffer temp_dst = (Tbuffer)a_pDestination;
    Tcbuffer temp_src = (Tcbuffer)a_cpSource;
    Tuint temp_counter = a_cElementsCount;

    while (temp_counter-- > 0)
    {
      for (Tuint i = 0; i < (a_cOneElementSize / 2); ++i)
      {
        temp_dst[i] = temp_src[a_cOneElementSize - i - 1];
        temp_dst[a_cOneElementSize - i - 1] = temp_src[i];
      }
      temp_dst += a_cOneElementSize;
      temp_src += a_cOneElementSize;
    }
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
