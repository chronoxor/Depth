/*!
 *  \file    Onew.hpp Helper allocation operators that emulates classic C++
 *           'new' operators behavior.
 *  \brief   'new' helper operators.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: 'new' helper operators.

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
#ifndef __ONEW_HPP__
#define __ONEW_HPP__
/*==========================================================================*/
#if (!defined(__DEPTH_THIRD_PARTY__))
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NMemory {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* FUNCTION DECLARATIONS                                                    */
/*==========================================================================*/
//! Internal 'new' operator wrapper function.
/*!
    Internal 'new' operator wrapper function is invoked  by  overloaded  'new'
    operators. It allocates memory and returns pointer to the allocated memory
    buffer.

    \param a_cSize - Size of the allocated buffer.
    \param a_cpFunctionSignature - Function signature name, from where memory allocation was initiated.
    \param a_cpFileName - File name, from where memory allocation was initiated.
    \param a_cLine - Line in file, from where memory allocation was initiated.
    \return Pointer to the allocated buffer.
*/
BASE_API Tptr newWrapper(const Tuint a_cSize, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* OPERATOR DECLARATIONS                                                    */
/*==========================================================================*/
//! 'new' helper operator. Placement 'new' operator for one object.
/*!
    Placement 'new' helper operator constructs one object in the given buffer.

    \param a_cSize - Size of the one object.
    \param a_pPointer - Pointer to the buffer.
    \return Pointer to the constructed object.
*/
NDepth::NTypes::Tptr operator new (const size_t a_cSize, NDepth::NTypes::Tptr a_pPointer) throw();
/*--------------------------------------------------------------------------*/
//! 'new' helper operator. Placement 'new' operator for many objects.
/*!
    Placement 'new' helper operator  constructs  many  objects  in  the  given
    buffer.

    \param a_cSize - Size of the all objects.
    \param a_pPointer - Pointer to the buffer.
    \return Pointer to the constructed objects.
*/
NDepth::NTypes::Tptr operator new[] (const size_t a_cSize, NDepth::NTypes::Tptr a_pPointer) throw();
/*--------------------------------------------------------------------------*/
//! 'new' helper operator. Allocate buffer for one object.
/*!
    'new' helper operator allocates buffer for one object using static CMemory
    class  allocation  method.

    \param a_cSize - Size of the allocated buffer.
    \return Pointer to the allocated buffer.
*/
NDepth::NTypes::Tptr operator new (const size_t a_cSize) throw();
/*--------------------------------------------------------------------------*/
//! 'new' helper operator. Allocate buffer for many objects.
/*!
    'new' helper operator allocates  buffer  for  many  objects  using  static
    CMemory  class  allocation  method.

    \param a_cSize - Size of the allocated buffer.
    \return Pointer to the allocated buffer.
*/
NDepth::NTypes::Tptr operator new[] (const size_t a_cSize) throw();
/*--------------------------------------------------------------------------*/
//! 'new' helper operator. Allocate buffer for one object. Version with additional information provided.
/*!
    'new' helper operator allocates buffer for one object using static CMemory
    class  allocation  method.  Operator  works  with  additional  information
    provided.

    \param a_cSize - Size of the allocated buffer.
    \param a_cpFunctionSignature - Function signature name, from where memory allocation was initiated.
    \param a_cpFileName - File name, from where memory allocation was initiated.
    \param a_cLine - Line in file, from where memory allocation was initiated.
    \return Pointer to the allocated buffer.
*/
NDepth::NTypes::Tptr operator new (const size_t a_cSize, NDepth::NTypes::Tcsstr a_cpFunctionSignature, NDepth::NTypes::Tcstr a_cpFileName, const NDepth::NTypes::Tuint a_cLine) throw();
/*--------------------------------------------------------------------------*/
//! 'new' helper operator. Allocate buffer for many objects. Version with additional information provided.
/*!
    'new' helper operator allocates  buffer  for  many  objects  using  static
    CMemory  class  allocation  method.   Operator   works   with   additional
    information provided.

    \param a_cSize - Size of the allocated buffer.
    \param a_cpFunctionSignature - Function signature name, from where memory allocation was initiated.
    \param a_cpFileName - File name, from where memory allocation was initiated.
    \param a_cLine - Line in file, from where memory allocation was initiated.
    \return Pointer to the allocated buffer.
*/
NDepth::NTypes::Tptr operator new[] (const size_t a_cSize, NDepth::NTypes::Tcsstr a_cpFunctionSignature, NDepth::NTypes::Tcstr a_cpFileName, const NDepth::NTypes::Tuint a_cLine) throw();
/*==========================================================================*/
#include <Depth/include/memory/details/Onew.inl>
/*==========================================================================*/
#endif
/*==========================================================================*/
#endif
