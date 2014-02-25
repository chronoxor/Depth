/*!
 *  \file    align.hpp Contains structure align macros.
 *  \brief   Structure align macros.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Structure align macros.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Macro
    VERSION:   1.0
    CREATED:   14.01.2007 00:15:45

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
#ifndef __ALIGN_HPP__
#define __ALIGN_HPP__
/*==========================================================================*/
/* MACRO DECLARATIONS                                                       */
/*==========================================================================*/
/*!
    \def ALIGN
    Defines structure align attribute. It can be used to explicitly define the
    structure align. It forces structure align to be \a value bytes.

    Example:
    \code
    // Force SStructure to be aligned at 8 bytes.
    struct ALIGN(8) SStructure
    {
      Tsint m_A;
      Tsint m_B;
    };
    \endcode
*/
#define ALIGN(value) SYS_ALIGN(value)
/*--------------------------------------------------------------------------*/
/*!
    \def ALIGNOF
    Macro returns align in bytes of the given structure.

    Example:
    \code
    // Force SStructure to be aligned at 8 bytes.
    struct ALIGN(8) SStructure
    {
      Tsint m_A;
      Tsint m_B;
    };
    ...
    Tuint align = ALIGNOF(SStructure);
    \endcode
*/
#define ALIGNOF(structure) SYS_ALIGNOF(structure)
/*==========================================================================*/
#endif
