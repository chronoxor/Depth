/*!
 *  \file    errors.hpp Contains errors definitions for the Depth project.
 *  \brief   Errors definitions.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Errors definitions.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Errors handling
    VERSION:   1.0
    CREATED:   29.12.2006 02:53:37

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
#ifndef __ERRORS_HPP__
#define __ERRORS_HPP__
/*==========================================================================*/
#include <Depth/include/base/NULL.hpp>
#include <Depth/include/errors/details/FError.hpp>
#include <Depth/include/errors/details/FWarning.hpp>
#include <Depth/include/errors/details/FAssert.hpp>
#include <Depth/include/errors/details/FAssume.hpp>
#include <Depth/include/errors/details/FVerify.hpp>
#include <Depth/include/errors/details/MStaticErrorHelper.hpp>
#include <Depth/include/errors/details/MStaticWarningHelper.hpp>
#include <Depth/include/errors/details/MStaticAssertHelper.hpp>
/*==========================================================================*/
/* ERROR MACRO DECLARATIONS                                                 */
/*==========================================================================*/
/*!
    \def ACCEPT(expression)
    Defines acceptation macros. If \a expression  is  'true'  it  returns  the
    'true' value as the current function result.
*/
#define ACCEPT(expression) { if (expression) return true; }
/*--------------------------------------------------------------------------*/
/*!
    \def CHECK(expression)
    Defines checking macros. If  \a  expression  is  'false'  it  returns  the
    'false' value as the current function result.
*/
#define CHECK(expression) { if (!(expression)) return false; }
/*--------------------------------------------------------------------------*/
/*!
    \def ERROR(message)
    Defines error macros. If code fragment wants to generate error  it  should
    use this macros and pass describing error \a  message.  This  macros  uses
    common Depth argument formatting algorithm.
*/
#define ERROR(message) NDepth::NErrors::NDetails::error(FUNCTION_SIGNATURE, FILE, LINE, message)
/*--------------------------------------------------------------------------*/
/*!
    \def WARNING(message)
    Defines warning macros. If code fragment  wants  to  generate  warning  it
    should use this macros and pass describing warning \a message. This macros
    uses common Depth argument formatting algorithm.
*/
#define WARNING(message) NDepth::NErrors::NDetails::warning(FUNCTION_SIGNATURE, FILE, LINE, message)
/*--------------------------------------------------------------------------*/
/*!
    \def ASSERT(condition, message)
    Defines assertion macros. Checks \a condition expression to be 'true'.  If
    it is 'true' the execution flows normally. Otherwise there are to cases of
    the behavior:
    \li In __DEBUG__ mode - shows an assertion \a message to the user  with  a
        prompt of the next action. If user chooses to  resume  execution,  the
        warning \a message will be displayed  and  the  closest  operation  to
        ASSERT is executed. Then the execution flows normally.
    \li In __RELEASE__ mode - Only the warning \a message  will  be  displayed
        and the closest operation to ASSERT is executed.  Then  the  execution
        flows normally.

    This macros uses common Depth argument formatting algorithm.

    Example:
    \code
    // Just check the pointer.
    ASSERT((ptr != NULL), STR("ptr must not be NULL!"));

    // Check the pointer. If it is NULL, then return 'false'.
    ASSERT((ptr != NULL), STR("ptr must not be NULL!"))
    {
      return false;
    }
    \endcode
*/
#define ASSERT(condition, message) if (!(condition) && !NDepth::NErrors::NDetails::assert(FUNCTION_SIGNATURE, FILE, LINE, false, STR(STRINGIZE(condition)), message))
/*--------------------------------------------------------------------------*/
/*!
    \def ASSUME(condition, message)
    Defines assumption macros. Checks \a condition expression to be 'true'. If
    it is 'true' the execution flows normally. Otherwise there are to cases of
    the behavior:
    \li In __DEBUG__ mode - shows an assumption \a message to the user with  a
        prompt of the next action. If user chooses to  resume  execution,  the
        warning \a message will be displayed  and  the  closest  operation  to
        ASSUME is executed. Then  \a  condition  expression  will  be  checked
        again. This loop will be done until \a condition  expression  will  be
        'true'.
    \li In __RELEASE__ mode - Only the error \a  message  will  be  displayed.
        Then the execution will be stopped.

    This macros uses common Depth argument formatting algorithm.

    Example:
    \code
    // Check the pointer. While it is NULL, try to allocate new buffer.
    Tstr ptr = NULL;
    ASSUME((ptr != NULL), STR("Pointer is NULL!"))
    {
      printf("Trying to allocate buffer!\n");
      ptr = new Tchar[256];
    }
    \endcode
*/
#if defined(__DEBUG__)
  #define ASSUME(condition, message) while (!(condition) && !NDepth::NErrors::NDetails::assume(FUNCTION_SIGNATURE, FILE, LINE, false, STR(STRINGIZE(condition)), message))
#else
  #define ASSUME(condition, message) if (!(condition) && !NDepth::NErrors::NDetails::assume(FUNCTION_SIGNATURE, FILE, LINE, false, STR(STRINGIZE(condition)), message))
#endif
/*--------------------------------------------------------------------------*/
/*!
    \def VERIFY(condition, message)
    Defines verification macros. Checks \a condition expression to be  'true'.
    If it is 'true' the execution flows normally. Otherwise error  \a  message
    will be shown and execution stops. This macros uses common Depth  argument
    formatting algorithm.

    Example:
    \code
    // Check the pointer. If it is NULL, execution will be stopped.
    VERIFY((ptr != NULL), STR("Pointer is NULL!"));
    \endcode
*/
#define VERIFY(condition, message) if (!(condition)) NDepth::NErrors::NDetails::verify(FUNCTION_SIGNATURE, FILE, LINE, false, STR(STRINGIZE(condition)), message)
/*--------------------------------------------------------------------------*/
/*!
    \def STATIC_ERROR(message)
    Stop compilation process. Additional parameter \a message explains error.
*/
#define STATIC_ERROR(message) typedef NDepth::NErrors::NDetails::MStaticErrorHelper<sizeof(message), sizeof(NDepth::NErrors::NDetails::MStaticErrorFailure)> JOIN(TStaticError, LINE);
/*--------------------------------------------------------------------------*/
/*!
    \def STATIC_WARNING(message)
    Show warning \a message but does not stop compile process.
*/
#define STATIC_WARNING(message) STATIC_WARNING_HELPER(message, LINE);
/*--------------------------------------------------------------------------*/
/*!
    \def STATIC_ASSERT(condition, message)
    Checks given \a condition at compile time to be  true.  Otherwise  compile
    error will be occurred. Additional parameter \a message  explains  current
    assertion checking.
*/
#define STATIC_ASSERT(condition, message) typedef NDepth::NErrors::NDetails::MStaticAssertHelper<sizeof(message), sizeof(NDepth::NErrors::NDetails::MStaticAssertFailure<(Tbool)(condition)>)> JOIN(TStaticAssert, LINE);
/*==========================================================================*/
//! \example example-errors-Errors.cpp
/*==========================================================================*/
#endif
