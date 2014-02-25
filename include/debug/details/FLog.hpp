/*!
 *  \file    FLog.hpp Helper function that writes log message into the current
 *           logger.
 *  \brief   Log helper function.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Log helper function.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Debugging details
    VERSION:   1.0
    CREATED:   30.12.2006 20:48:32

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
#ifndef __FLOG_HPP__
#define __FLOG_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NDebug {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* FUNCTION DECLARATIONS                                                    */
/*==========================================================================*/
//! Log helper function.
/*!
    Log helper function writes given log message into the current logger. This
    function uses common Depth argument formatting algorithm.

    \param a_cpFunctionSignature - Function signature name, which writes the log message.
    \param a_cpFileName - File name, from where the log message has been written.
    \param a_cLine - Line in file, from where the log message has been written.
    \param a_cpMessage - Log message to be written.
*/
BASE_API void log(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcstr a_cpMessage, ...);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
