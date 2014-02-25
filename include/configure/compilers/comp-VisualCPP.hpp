/*!
 *  \file    comp-VisualCPP.hpp Contains Microsoft Visual C++ compiler
 *           configuration.
 *  \brief   Microsoft Visual C++ compiler configuration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.12.2005
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Microsoft Visual C++ compiler configuration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Configuration - compilers
    VERSION:   1.0
    CREATED:   28.12.2005 00:53:49

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
#ifndef __COMP_VISUALCPP_HPP__
#define __COMP_VISUALCPP_HPP__
/*==========================================================================*/
#if defined(__VISUALCPP__)
/*==========================================================================*/
/* COMPILER WARNINGS                                                        */
/*==========================================================================*/
#pragma warning(disable:4121)           // Disable warning: alignment of a member was sensitive to packing.
#pragma warning(disable:4127)           // Disable warning: conditional expression is constant.
#pragma warning(disable:4146)           // Disable warning: unary minus operator applied to unsigned type, result still unsigned.
#pragma warning(disable:4250)           // Disable warning: inherits 'virtual method' via dominance.
#pragma warning(disable:4251)           // Disable warning: class needs to have dll-interface.
#pragma warning(disable:4266)           // Disable warning: 'function' : no override available for virtual member function from base 'type'; function is hidden.
#pragma warning(disable:4275)           // Disable warning: non dll-interface class 'A' used as base for dll-interface class 'B'
#pragma warning(disable:4311)           // Disable warning: 'type cast' : pointer truncation from 'source' to 'destination'.
#pragma warning(disable:4312)           // Disable warning: conversion from 'source' to 'destination' of greater size.
#pragma warning(disable:4350)           // Disable warning: behavior change: 'member1' called instead of 'member2'
#pragma warning(disable:4351)           // Disable warning: new behavior: elements of array 'array' will be default initialized.
#pragma warning(disable:4365)           // Disable warning: 'action' : conversion from 'type_1' to 'type_2', signed/unsigned mismatch.
#pragma warning(disable:4371)           // Disable warning: layout of class may have changed from a previous version of the compiler due to better packing of member 'field'.
#pragma warning(disable:4390)           // Disable warning: ';' : empty controlled statement found; is this the intent?
#pragma warning(disable:4505)           // Disable warning: 'function' : unreferenced local function has been removed.
#pragma warning(disable:4512)           // Disable warning: assignment operator could not be generated.
#pragma warning(disable:4514)           // Disable warning: 'function' : unreferenced inline function has been removed.
#pragma warning(disable:4567)           // Disable warning: 'function' : behavior change due to parameter 'parameter': calling convention incompatible with previous compiler versions.
#pragma warning(disable:4623)           // Disable warning: 'derived class' : default constructor could not be generated because a base class default constructor is inaccessible.
#pragma warning(disable:4640)           // Disable warning: 'instance' : construction of local static object is not thread-safe
#pragma warning(disable:4668)           // Disable warning: 'symbol' is not defined as a preprocessor macro, replacing with '0' for 'directives'.
#pragma warning(disable:4710)           // Disable warning: 'function' : function not inlined.
#pragma warning(disable:4800)           // Disable warning: forcing value to bool 'true' or 'false' (performance warning).
#pragma warning(disable:4820)           // Disable warning: 'bytes' bytes padding added after construct 'member_name'.
#if (_MSC_VER >= 1600)
#pragma warning(disable:4986)           // Disable warning: 'operator new/delete': exception specification does not match previous declaration.
#endif
/*==========================================================================*/
/* COMPILER INCLUDES                                                        */
/*==========================================================================*/
#include <cstdarg>
#include <cstddef>
#include <typeinfo>
/*==========================================================================*/
/* COMPILER CONFIGURATIONS                                                  */
/*==========================================================================*/
// Configure default compilation mode as release.
#if (!defined(__DEBUG__) && !defined(__RELEASE__))
  #if defined(_DEBUG)
    //! Use debug compilation mode.
    #define __DEBUG__
  #else
    //! Use release compilation mode.
    #define __RELEASE__
  #endif
#endif
/*--------------------------------------------------------------------------*/
//! Use __declspec(dllexport) calling convenience.
#define __DLL_EXPORT__
/*--------------------------------------------------------------------------*/
//! Use __declspec(dllimport) calling convenience.
#define __DLL_IMPORT__
/*==========================================================================*/
/* COMPILER FEATURES                                                        */
/*==========================================================================*/
//! Support for the Cnull class.
#undef SYS_SUPPORT_CNULL
/*==========================================================================*/
/* COMPILER MACROS                                                          */
/*==========================================================================*/
/*!
    \def SYS_ALIGN
    Defines structure align attribute.
*/
#define SYS_ALIGN(value) __declspec(align(value))
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_ALIGNOF
    Defines structure align value.
*/
#define SYS_ALIGNOF(structure) __alignof(structure)
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_FILE
    Defines the current file name.
*/
#define SYS_FILE __FILE__
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_LINE
    Defines the current file line number.
*/
#define SYS_LINE __LINE__
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_DATE
    Defines the current date.
*/
#define SYS_DATE __DATE__
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_TIME
    Defines the current time.
*/
#define SYS_TIME __TIME__
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_FUNCTION_NAME
    Defines the current function name.
*/
#define SYS_FUNCTION_NAME __FUNCTION__
/*--------------------------------------------------------------------------*/
/*!
    \def SYS_FUNCTION_SIGNATURE
    Defines the current function signature name.
*/
#define SYS_FUNCTION_SIGNATURE __FUNCSIG__
/*==========================================================================*/
#endif
#endif
