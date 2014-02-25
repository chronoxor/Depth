/*!
 *  \file    debug.hpp Contains debugging definitions for the Depth project.
 *  \brief   Debugging definitions.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Debugging definitions.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Debugging
    VERSION:   1.0
    CREATED:   30.12.2006 20:18:53

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
#ifndef __DEBUG_HPP__
#define __DEBUG_HPP__
/*==========================================================================*/
#include <Depth/include/base/NULL.hpp>
#include <Depth/include/debug/details/FLog.hpp>
#include <Depth/include/debug/details/FTrace.hpp>
#include <Depth/include/debug/details/CCallFrameContext.hpp>
/*==========================================================================*/
/* ERROR MACRO DECLARATIONS                                                 */
/*==========================================================================*/
/*!
    \def LOG(message)
    Defines log macros. It produces new log entry with the given  \a  message.
    This log entry will be passed to the  current  logger.  This  macros  uses
    common Depth argument formatting algorithm.
*/
#define LOG(message) NDepth::NDebug::NDetails::log(FUNCTION_SIGNATURE, FILE, LINE, message)
/*--------------------------------------------------------------------------*/
/*!
    \def TRACE(message)
    Defines trace macros. It produces  new  trace  entry  with  the  given  \a
    message. This trace entry will be send to the debugger for  display.  This
    macros uses common Depth argument formatting algorithm.
*/
#define TRACE(message) NDepth::NDebug::NDetails::trace(FUNCTION_SIGNATURE, FILE, LINE, message)
/*--------------------------------------------------------------------------*/
/*!
    \def CALL
    Defines call stack frame context. This macro should be placed  just  after
    begin of any function or method. It declares new call  stack  frame  which
    will be pushed into the call stack of the current thread. After  returning
    from the function or method the call stack frame context is  removed  from
    the call stack and is destroyed. This macros uses  common  Depth  argument
    formatting algorithm.

    Example:
    \code
    void any_function()
    { CALL // Update call stack with the new call stack frame context.
      ...
    }
    \endcode
*/
#define CALL //NDepth::NDebug::NDetails::CCallFrameContext _call_frame_context(FUNCTION_SIGNATURE, FILE, LINE);
/*==========================================================================*/
#endif
