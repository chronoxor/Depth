/*!
 *  \file    Odelete.hpp Helper delete operators that emulates classic C++
 *           'delete' operators behavior.
 *  \brief   'delete' helper operators.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: 'delete' helper operators.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Memory details
    VERSION:   1.0
    CREATED:   29.12.2006 21:13:23

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
#ifndef __ODELETE_HPP__
#define __ODELETE_HPP__
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
//! Internal 'delete' operator wrapper function.
/*!
    Internal 'delete' operator  wrapper  function  is  invoked  by  overloaded
    'delete' operators. It frees allocated memory buffer.

    \param a_pPointer - Pointer to the deleting buffer.
    \param a_cpFunctionSignature - Function signature name, from where memory freeing was initiated.
    \param a_cpFileName - File name, from where memory freeing was initiated.
    \param a_cLine - Line in file, from where memory freeing was initiated.
*/
BASE_API void deleteWrapper(Tptr a_pPointer, Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* OPERATOR DECLARATIONS                                                    */
/*==========================================================================*/
//! 'delete' helper operator. Placement 'delete' operator for one object.
/*!
    Delete if placement 'new' fails to  construct  one  object  in  the  given
    buffer.

    \param a_pPointer1 - Pointer to the buffer.
    \param a_pPointer2 - Pointer to the buffer.
*/
void operator delete (NDepth::NTypes::Tptr a_pPointer1, NDepth::NTypes::Tptr a_pPointer2) throw();
/*--------------------------------------------------------------------------*/
//! 'delete' helper operator. Placement 'delete' operator for many objects.
/*!
    Delete if placement 'new' fails to construct many  objects  in  the  given
    buffer.

    \param a_pPointer1 - Pointer to the buffer.
    \param a_pPointer2 - Pointer to the buffer.
*/
void operator delete[] (NDepth::NTypes::Tptr a_pPointer1, NDepth::NTypes::Tptr a_pPointer2) throw();
/*--------------------------------------------------------------------------*/
//! 'delete' helper operator. Delete buffer for one object.
/*!
    'delete' helper operator  deletes  buffer  for  one  object  using  static
    CMemory  class  free  method.

    \param a_pPointer - Pointer to the deleting buffer.
*/
void operator delete (NDepth::NTypes::Tptr a_pPointer) throw();
/*--------------------------------------------------------------------------*/
//! 'delete' helper operator. Delete buffer for many objects.
/*!
    'delete' helper operator deletes buffer  for  many  objects  using  static
    CMemory  class  free  method.

    \param a_pPointer - Pointer to the deleting buffer.
*/
void operator delete[] (NDepth::NTypes::Tptr a_pPointer) throw();
/*--------------------------------------------------------------------------*/
//! 'delete' helper operator. Delete buffer for one object. Version with additional information provided.
/*!
    'delete' helper operator  deletes  buffer  for  one  object  using  static
    CMemory class free method.  Operator  works  with  additional  information
    provided.

    \param a_pPointer - Pointer to the deleting buffer.
    \param a_cpFunctionSignature - Function signature name, from where memory freeing was initiated.
    \param a_cpFileName - File name, from where memory freeing was initiated.
    \param a_cLine - Line in file, from where memory freeing was initiated.
*/
void operator delete (NDepth::NTypes::Tptr a_pPointer, NDepth::NTypes::Tcsstr a_cpFunctionSignature, NDepth::NTypes::Tcstr a_cpFileName, const NDepth::NTypes::Tuint a_cLine) throw();
/*--------------------------------------------------------------------------*/
//! 'delete' helper operator. Delete buffer for many objects. Version with additional information provided.
/*!
    'delete' helper operator deletes buffer  for  many  objects  using  static
    CMemory class free method.  Operator  works  with  additional  information
    provided.

    \param a_pPointer - Pointer to the deleting buffer.
    \param a_cpFunctionSignature - Function signature name, from where memory freeing was initiated.
    \param a_cpFileName - File name, from where memory freeing was initiated.
    \param a_cLine - Line in file, from where memory freeing was initiated.
*/
void operator delete[] (NDepth::NTypes::Tptr a_pPointer, NDepth::NTypes::Tcsstr a_cpFunctionSignature, NDepth::NTypes::Tcstr a_cpFileName, const NDepth::NTypes::Tuint a_cLine) throw();
/*==========================================================================*/
#include <Depth/include/memory/details/Odelete.inl>
/*==========================================================================*/
#endif
/*==========================================================================*/
#endif
