/*!
 *  \file    cprefix.hpp Contains 'C' prefix macros.
 *  \brief   'C' prefix macros.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: 'C' prefix macros.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Macro
    VERSION:   1.0
    CREATED:   02.11.2006 02:38:27

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
#ifndef __CPREFIX_HPP__
#define __CPREFIX_HPP__
/*==========================================================================*/
/* MACRO DECLARATIONS                                                       */
/*==========================================================================*/
/*!
    \def CPREFIX(function)
    Defines macros for extern 'C' functions. On some compilers we  should  use
    '_foo' name instead of 'foo' to define extern  \a  function.  This  macros
    helps to unify import process. Its also supports expressions with macros.
*/
#define CPREFIX(function) CPREFIX_HELPER(function)
/*!
    \def CPREFIX_HELPER(function)
    'C' prefix definition helper, which extracts macro from the expression.
*/
#if defined(__UNDERLINE__)
  #define CPREFIX_HELPER(function) _ ## function
#else
  #define CPREFIX_HELPER(function) function
#endif
/*==========================================================================*/
#endif
