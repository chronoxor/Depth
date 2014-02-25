/*!
 *  \file    join.hpp Contains joining macros.
 *  \brief   Joining macros.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Joining macros.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Macro
    VERSION:   1.0
    CREATED:   02.11.2006 02:43:03

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
#ifndef __JOIN_HPP__
#define __JOIN_HPP__
/*==========================================================================*/
/* MACRO DECLARATIONS                                                       */
/*==========================================================================*/
/*!
    \def JOIN(value1, valu2)
    Concatenate given \a value1  with  given  \a  value2.  Its  also  supports
    expressions with macros.
*/
#define JOIN(value1, value2) JOIN_HELPER1(value1, value2)
/*!
    \def JOIN_HELPER1(value1, value2)
    Join definition helper, which extracts macro from the first expression.
*/
#define JOIN_HELPER1(value1, value2) JOIN_HELPER2(value1, value2)
/*!
    \def JOIN_HELPER2(value1, value2)
    Join definition helper, which extracts macro from the second expression.
*/
#define JOIN_HELPER2(value1, value2) value1 ## value2
/*==========================================================================*/
#endif
