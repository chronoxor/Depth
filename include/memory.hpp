/*!
 *  \file    memory.hpp Contains memory definitions for the Depth project.
 *  \brief   Memory definitions.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Memory definitions.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory management
    VERSION:   1.0
    CREATED:   01.03.2006 22:19:28

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
#ifndef __MEMORY_HPP__
#define __MEMORY_HPP__
/*==========================================================================*/
#include <Depth/include/base/NULL.hpp>
#include <Depth/include/memory/details/Onew.hpp>
#include <Depth/include/memory/details/Odelete.hpp>
/*==========================================================================*/
/*!
    \def cntr(ptr)
    Defines 'cntr' operator. Construct  one  or  many  objects  in  the  given
    \a ptr buffer.
*/
#define cntr(ptr) new (ptr)
/*--------------------------------------------------------------------------*/
/*!
    \def newex
    Defines 'newex' operator. Allocate buffer for one  or  many  objects  with
    additional information provided.
*/
#define newex new (FUNCTION_SIGNATURE, FILE, LINE)
/*==========================================================================*/
#endif
