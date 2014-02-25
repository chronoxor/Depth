/*!
 *  \file    file.hpp Contains current file name macros.
 *  \brief   Current file name macros.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Current file name macros.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Macro
    VERSION:   1.0
    CREATED:   02.11.2006 02:35:16

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
#ifndef __FILE_HPP__
#define __FILE_HPP__
/*==========================================================================*/
/* MACRO DECLARATIONS                                                       */
/*==========================================================================*/
/*!
    \def FILE
    Defines the current file name which depends  on  library  string  encoding
    setting.
*/
#define FILE STR(SYS_FILE)
/*!
    \def ASC_FILE
    Defines the current file name in ASCII encoding.
*/
#define ASC_FILE ASC(SYS_FILE)
/*!
    \def UNC_FILE
    Defines the current file name in Unicode encoding.
*/
#define UNC_FILE UNC(SYS_FILE)
/*==========================================================================*/
#endif
