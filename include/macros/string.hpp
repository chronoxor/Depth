/*!
 *  \file    string.hpp Contains character (string) prefix macros.
 *  \brief   Character (string) prefix macros.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character (string) prefix macros.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Macro
    VERSION:   1.0
    CREATED:   02.11.2006 02:45:24

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
#ifndef __STRING_HPP__
#define __STRING_HPP__
/*==========================================================================*/
/* MACRO DECLARATIONS                                                       */
/*==========================================================================*/
/*!
    \def ASC(str)
    Defines ASCII character/string prefix. Its also supports expressions  with
    macros.
*/
#define ASC(str) ASC_HELPER(str)
/*!
    \def ASC_HELPER(str)
    ASCII character/string prefix definition helper, which extracts macro from
    the expression.
*/
#define ASC_HELPER(str) str
/*--------------------------------------------------------------------------*/
/*!
    \def UNC(str)
    Defines Unicode character/string prefix.  Its  also  supports  expressions
    with macros.
*/
#define UNC(str) UNC_HELPER(str)
/*!
    \def UNC_HELPER(str)
    Unicode character/string prefix definition helper,  which  extracts  macro
    from the expression.
*/
#define UNC_HELPER(str) L ## str
/*--------------------------------------------------------------------------*/
/*!
    \def STR(str)
    Defines character/string prefix  which  depends  on  corresponding  string
    encoding setting. Its also supports expressions with macros.
*/
#define STR(str) STR_HELPER(str)
/*!
    \def STR_HELPER(str)
    Character/string prefix definition helper, which extracts macro  from  the
    expression.
*/
#if defined(__ASCII__)
  #define STR_HELPER(str) str
#else
  #define STR_HELPER(str) L ## str
#endif
/*==========================================================================*/
#endif
