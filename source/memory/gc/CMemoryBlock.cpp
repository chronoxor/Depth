/*!
 *  \file    CMemoryBlock.cpp GC memory block class. It describes one memory
 *           block and contains a pointer, an allocated size, and a place of
 *           allocation.
 *  \brief   GC memory block class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: GC memory block class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory garbage collection
    VERSION:   1.0
    CREATED:   20.06.2007 02:34:53

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
#include <Depth/include/algorithms/common/ACast.hpp>
#include <Depth/include/memory/gc/CMemoryBlock.hpp>
/*==========================================================================*/
#ifndef __CMEMORYBLOCK_CPP__
#define __CMEMORYBLOCK_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NGC {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tbool CMemoryBlock::contains(Tcptr a_cpPointer) const
{ CALL
  if (isValid())
  {
    const Tbyte* begin = NAlgorithms::NCommon::staticCast<const Tbyte*>(getPointer());
    const Tbyte* end = begin + getSize();

    return ((begin <= a_cpPointer) && (a_cpPointer <= end));
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
