/*!
 *  \file    FSerialize.hpp Serialization 'serialize()' free function general
 *           template declaration.
 *  \brief   Serialization 'serialize()' free function.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Serialization 'serialize()' free function.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Serialization
    VERSION:   1.0
    CREATED:   05.01.2007 00:27:46

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
#ifndef __FSERIALIZE_HPP__
#define __FSERIALIZE_HPP__
/*==========================================================================*/
#include <Depth/include/serialization/FSerializeSplitFunction.hpp>
#include <Depth/include/serialization/FSerializeSplitMethod.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*==========================================================================*/
/* FUNCTION DECLARATIONS                                                    */
/*==========================================================================*/
//! Serialization 'serialize()' free function (general template declaration).
/*!
    General template  declaration  of  the  serialization  'serialize()'  free
    function considers its template instance argument as a serializable  class
    instance  and  invokes  its  corresponding  'serialize()'  method.   Other
    'serialize()' function overloading may change the behavior  (for  instance
    for serialization of base types).

    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized class instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive, class T_Class>
Tbool serialize(T_Archive& a_rArchive, T_Class& a_rInstance);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/serialization/FSerialize.inl>
/*==========================================================================*/
#endif
