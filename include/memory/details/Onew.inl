/*!
 *  \file    Onew.inl Helper allocation operator that emulates classic C++
 *           'new' operator behavior.
 *  \brief   'new' helper operator (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: 'new' helper operator (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory details
    VERSION:   1.0
    CREATED:   29.12.2006 20:59:36

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
#ifndef __ONEW_INL__
#define __ONEW_INL__
/*==========================================================================*/
#if (!defined(__DEPTH_THIRD_PARTY__))
/*==========================================================================*/
/* INLINE OPERATOR IMPLEMENTATIONS                                          */
/*==========================================================================*/
inline NDepth::NTypes::Tptr operator new (const size_t, NDepth::NTypes::Tptr a_pPointer) throw()
{
  return a_pPointer;
}
/*--------------------------------------------------------------------------*/
inline NDepth::NTypes::Tptr operator new[] (const size_t, NDepth::NTypes::Tptr a_pPointer) throw()
{
  return a_pPointer;
}
/*--------------------------------------------------------------------------*/
inline NDepth::NTypes::Tptr operator new (const size_t a_cSize) throw()
{
  return NDepth::NMemory::NDetails::newWrapper((NDepth::NTypes::Tuint)a_cSize, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
inline NDepth::NTypes::Tptr operator new[] (const size_t a_cSize) throw()
{
  return NDepth::NMemory::NDetails::newWrapper((NDepth::NTypes::Tuint)a_cSize, FUNCTION_SIGNATURE, FILE, LINE);
}
/*--------------------------------------------------------------------------*/
inline NDepth::NTypes::Tptr operator new (const size_t a_cSize, NDepth::NTypes::Tcsstr a_cpFunctionSignature, NDepth::NTypes::Tcstr a_cpFileName, const NDepth::NTypes::Tuint a_cLine) throw()
{
  return NDepth::NMemory::NDetails::newWrapper((NDepth::NTypes::Tuint)a_cSize, a_cpFunctionSignature, a_cpFileName, a_cLine);
}
/*--------------------------------------------------------------------------*/
inline NDepth::NTypes::Tptr operator new[] (const size_t a_cSize, NDepth::NTypes::Tcsstr a_cpFunctionSignature, NDepth::NTypes::Tcstr a_cpFileName, const NDepth::NTypes::Tuint a_cLine) throw()
{
  return NDepth::NMemory::NDetails::newWrapper((NDepth::NTypes::Tuint)a_cSize, a_cpFunctionSignature, a_cpFileName, a_cLine);
}
/*==========================================================================*/
#endif
/*==========================================================================*/
#endif
