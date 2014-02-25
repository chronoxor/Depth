/*!
 *  \file    OStreamPush.hpp Set of the stream push operators are used to
 *           push common values (character, string, boolean, integer, real,
 *           pointer) into the stream.
 *  \brief   Stream push operators.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Stream push operators.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 03:58:22

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
#ifndef __OSTREAMPUSH_HPP__
#define __OSTREAMPUSH_HPP__
/*==========================================================================*/
#include <Depth/include/stream/IReader.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* OPERATOR DECLARATIONS                                                    */
/*==========================================================================*/
//! Operator: Push ASCII character into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cCharacter - ASCII character.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tschar a_cCharacter);
/*--------------------------------------------------------------------------*/
//! Operator: Push Unicode character into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cCharacter - Unicode character.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Twchar a_cCharacter);
/*--------------------------------------------------------------------------*/
//! Operator: Push ASCII zero terminated C string into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cpString - Constant pointer to the ASCII zero terminated C string.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, Tcsstr a_cpString);
/*--------------------------------------------------------------------------*/
//! Operator: Push Unicode zero terminated C string into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cpString - Constant pointer to the Unicode zero terminated C string.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, Tcwstr a_cpString);
/*--------------------------------------------------------------------------*/
//! Operator: Push ASCII string into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_crString - Constant reference to the ASCII string.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const NString::CStringASCII& a_crString);
/*--------------------------------------------------------------------------*/
//! Operator: Push Unicode string into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_crString - Constant reference to the Unicode string.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const NString::CStringUnicode& a_crString);
/*--------------------------------------------------------------------------*/
//! Operator: Push system string into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_crString - Constant reference to the system string.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const NString::CSystemString& a_crString);
/*--------------------------------------------------------------------------*/
//! Operator: Push boolean number value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cBoolean - Boolean number.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tbool a_cBoolean);
/*--------------------------------------------------------------------------*/
//! Operator: Push signed 1 byte integer value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cInteger - Signed 1 byte integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tsint08 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Push unsigned 1 byte integer value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cInteger - Unsigned 1 byte integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tuint08 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Push signed 2 bytes integer value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cInteger - Signed 2 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tsint16 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Push unsigned 2 bytes integer value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cInteger - Unsigned 2 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tuint16 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Push signed 4 bytes integer value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cInteger - Signed 4 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tsint32 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Push unsigned 4 bytes integer value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cInteger - Unsigned 4 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tuint32 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Push signed 8 bytes integer value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cInteger - Signed 8 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tsint64 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Push unsigned 8 bytes integer value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cInteger - Unsigned 8 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tuint64 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Push single accuracy real value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cReal - Single accuracy real value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tfloat a_cReal);
/*--------------------------------------------------------------------------*/
//! Operator: Push double accuracy real value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cReal - Double accuracy real value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, const Tdouble a_cReal);
/*--------------------------------------------------------------------------*/
//! Operator: Push pointer value into the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_cpPointer - Pointer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::push()
*/
IReader& operator < (IReader& a_rReader, Tcptr a_cpPointer);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/operators/OStreamPush.inl>
/*==========================================================================*/
#endif
