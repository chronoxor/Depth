/*!
 *  \file    FSerializeSplitFunction.hpp Serialization helper function that
 *           splits 'serialize()' free function into 'load()' and 'save()'
 *           ones depends on the archive type.
 *  \brief   Serialization free function splitter function.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Serialization free function splitter function.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Serialization
    VERSION:   1.0
    CREATED:   05.01.2007 03:31:42

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
#ifndef __FSERIALIZESPLITFUNCTION_HPP__
#define __FSERIALIZESPLITFUNCTION_HPP__
/*==========================================================================*/
#include <Depth/include/serialization/details/CFunctionLoadChooser.hpp>
#include <Depth/include/serialization/details/CFunctionSaveChooser.hpp>
#include <Depth/include/traits/MIfThenElse.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*==========================================================================*/
/* FUNCTION DECLARATIONS                                                    */
/*==========================================================================*/
//! Serialization free function splitter function.
/*!
    Serialization free function splitter function  splits  'serialize()'  free
    function into 'load()' and 'save()' ones depends on the archive type.  For
    loading archive the 'load()' serialization function will  be  called.  For
    saving archive the 'save()' serialization function will be called.

    Example:
    \code
    class CSomeObject;

    template <class T_Archive>
    Tbool load(T_Archive& a_rArchive, CSomeObject& a_rInstance)
    {
       // Load CSomeObject instance from the archive.
       ...
    }

    template <class T_Archive>
    Tbool save(T_Archive& a_rArchive, const CSomeObject& a_crInstance)
    {
      // Save CSomeObject instance into the archive.
      ...
    }

    template <class T_Archive>
    Tbool serialize(T_Archive& a_rArchive, CSomeObject& a_rInstance)
    {
      // Split main serialization free function into the 'load()' and 'save()' ones.
      return serializeSplitFunction(a_rArchive, a_rInstance);
    }
    \endcode

    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized type instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive, typename T_Type>
Tbool serializeSplitFunction(T_Archive& a_rArchive, T_Type& a_rInstance);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/serialization/FSerializeSplitFunction.inl>
/*==========================================================================*/
#endif
