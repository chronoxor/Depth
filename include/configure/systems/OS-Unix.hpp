/*!
 *  \file    OS-Unix.hpp Contains Unix OS configuration.
 *  \brief   Unix OS configuration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.12.2005
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unix OS configuration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Configuration - OS
    VERSION:   1.0
    CREATED:   28.12.2005 20:21:25

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
#ifndef __OS_UNIX_HPP__
#define __OS_UNIX_HPP__
/*==========================================================================*/
#if defined(__UNIX__)
/*==========================================================================*/
/* OS CONFIGURATIONS                                                        */
/*==========================================================================*/
// Configure default application type as native.
#if (!defined(__CONSOLE__) && !defined(__NATIVE__))
  //! Use and compile native application.
  #define __NATIVE__
#endif
/*--------------------------------------------------------------------------*/
// Configure default library linking as dynamic.
#if (!defined(__LIB__) && !defined(__DLL__))
  //! Use dynamic library linking.
  #define __DLL__
#endif
/*--------------------------------------------------------------------------*/
// Configure default real number representation as float.
#if (!defined(__FLOAT__) && !defined(__DOUBLE__))
  //! Use float as a real.
  #define __FLOAT__
#endif
/*--------------------------------------------------------------------------*/
// Configure default string encoding as Unicode.
#if (!defined(__ASCII__) && !defined(__UNICODE__))
  //! Use Unicode as a string encoding.
  #define __ASCII__
#endif
/*--------------------------------------------------------------------------*/
// Configure default line ending as Unix.
#if (!defined(__WINDOWS_LINE_END__) && !defined(__UNIX_LINE_END__))
  //! Use Unix line ending.
  #define __UNIX_LINE_END__
#endif
/*==========================================================================*/
#endif
#endif
