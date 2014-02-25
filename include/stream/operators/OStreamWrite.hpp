/*!
 *  \file    OStreamWrite.hpp Set of the stream write operators are used to
 *           write common values (character, string, boolean, integer, real,
 *           pointer) into the stream.
 *  \brief   Stream write operators.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Stream write operators.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 03:20:14

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
#ifndef __OSTREAMWRITE_HPP__
#define __OSTREAMWRITE_HPP__
/*==========================================================================*/
#include <Depth/include/stream/IWriter.hpp>
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
//! Operator: Write ASCII character into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cCharacter - ASCII character.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tschar a_cCharacter);
/*--------------------------------------------------------------------------*/
//! Operator: Write Unicode character into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cCharacter - Unicode character.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Twchar a_cCharacter);
/*--------------------------------------------------------------------------*/
//! Operator: Write ASCII zero terminated C string into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cpString - Constant pointer to the ASCII zero terminated C string.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, Tcsstr a_cpString);
/*--------------------------------------------------------------------------*/
//! Operator: Write Unicode zero terminated C string into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cpString - Constant pointer to the Unicode zero terminated C string.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, Tcwstr a_cpString);
/*--------------------------------------------------------------------------*/
//! Operator: Write ASCII string into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_crString - Constant reference to the ASCII string.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const NString::CStringASCII& a_crString);
/*--------------------------------------------------------------------------*/
//! Operator: Write Unicode string into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_crString - Constant reference to the Unicode string.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const NString::CStringUnicode& a_crString);
/*--------------------------------------------------------------------------*/
//! Operator: Write system string into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_crString - Constant reference to the system string.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const NString::CSystemString& a_crString);
/*--------------------------------------------------------------------------*/
//! Operator: Write boolean number value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cBoolean - Boolean number.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tbool a_cBoolean);
/*--------------------------------------------------------------------------*/
//! Operator: Write signed 1 byte integer value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cInteger - Signed 1 byte integer value.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tsint08 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Write unsigned 1 byte integer value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cInteger - Unsigned 1 byte integer value.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tuint08 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Write signed 2 bytes integer value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cInteger - Signed 2 bytes integer value.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tsint16 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Write unsigned 2 bytes integer value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cInteger - Unsigned 2 bytes integer value.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tuint16 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Write signed 4 bytes integer value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cInteger - Signed 4 bytes integer value.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tsint32 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Write unsigned 4 bytes integer value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cInteger - Unsigned 4 bytes integer value.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tuint32 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Write signed 8 bytes integer value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cInteger - Signed 8 bytes integer value.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tsint64 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Write unsigned 8 bytes integer value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cInteger - Unsigned 8 bytes integer value.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tuint64 a_cInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Write single accuracy real value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cReal - Single accuracy real value.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tfloat a_cReal);
/*--------------------------------------------------------------------------*/
//! Operator: Write double accuracy real value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cReal - Double accuracy real value.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, const Tdouble a_cReal);
/*--------------------------------------------------------------------------*/
//! Operator: Write pointer value into the given writer.
/*!
    \param a_rWriter - Reference to the instance of the IWriter interface.
    \param a_cpPointer - Pointer value.
    \return Reference to the instance of the IWriter interface.
    \see NDepth::NStream::IWriter::write()
*/
IWriter& operator << (IWriter& a_rWriter, Tcptr a_cpPointer);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/operators/OStreamWrite.inl>
/*==========================================================================*/
#endif
