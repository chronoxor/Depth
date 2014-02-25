/*!
 *  \file    CSystemBaseMemory-Unix.cpp Base system class contains common
 *           functionality such as memory routines, math functions, error
 *           handling, standard I/O routines.
 *  \brief   Base system class - Unix OS - memory methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Unix OS - memory methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   07.01.2006 01:33:12

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
#include <Depth/include/system/CSystemBase.hpp>
/*--------------------------------------------------------------------------*/
#include "../Unix.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASEMEMORY_UNIX_CPP__
#define __CSYSTEMBASEMEMORY_UNIX_CPP__
/*==========================================================================*/
#if defined(__UNIX__)
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tptr CSystemBase::memoryAllocate(const Tuint a_cSize)
{ CALL
  return malloc(a_cSize);
}
/*--------------------------------------------------------------------------*/
Tptr CSystemBase::memoryAllocateZero(const Tuint a_cSize)
{ CALL
  return calloc(1, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tptr CSystemBase::memoryAllocateZero(const Tuint a_cOneElementSize, const Tuint a_cElementsCount)
{ CALL
  return calloc(a_cElementsCount, a_cOneElementSize);
}
/*--------------------------------------------------------------------------*/
Tptr CSystemBase::memoryReallocate(Tptr a_pPointer, const Tuint a_cSize)
{ CALL
  return realloc(a_pPointer, a_cSize);
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::memoryFree(Tptr a_pPointer)
{ CALL
  free(a_pPointer);
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
