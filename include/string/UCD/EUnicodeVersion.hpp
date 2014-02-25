/*!
 *  \file    EUnicodeVersion.hpp Character version enumeration.
 *  \brief   Character version enumeration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character version enumeration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   01.04.2009 22:34:42

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
#ifndef __EUNICODEVERSION_HPP__
#define __EUNICODEVERSION_HPP__
/*==========================================================================*/
#include <Depth/include/serialization.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NUCD {
/*==========================================================================*/
/* ENUMERATION DECLARATIONS                                                 */
/*==========================================================================*/
//! Unicode version of the character.
/*!
    Value  shows  when  various  code  points  were   designated/assigned   in
    successive versions of the Unicode standard.

    Value for each character is taken from "DerivedAge.txt" file.
*/
enum EUnicodeVersion
{
  e_UnicodeVersion_Unassigned,          //!< Character is not assigned in Unicode.
  e_UnicodeVersion_1_1,                 //!< Unicode version is "1.1".
  e_UnicodeVersion_2_0,                 //!< Unicode version is "2.0".
  e_UnicodeVersion_2_1,                 //!< Unicode version is "2.1".
  e_UnicodeVersion_3_0,                 //!< Unicode version is "3.0".
  e_UnicodeVersion_3_1,                 //!< Unicode version is "3.1".
  e_UnicodeVersion_3_2,                 //!< Unicode version is "3.2".
  e_UnicodeVersion_4_0,                 //!< Unicode version is "4.0".
  e_UnicodeVersion_4_1,                 //!< Unicode version is "4.1".
  e_UnicodeVersion_5_0,                 //!< Unicode version is "5.0".
  e_UnicodeVersion_5_1,                 //!< Unicode version is "5.1".
  e_UnicodeVersion_5_2                  //!< Unicode version is "5.2".
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* SERIALIZATION FUNCTION DECLARATIONS                                      */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
//! Serialization load of the EUnicodeVersion value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EUnicodeVersion instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EUnicodeVersion& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save of the EUnicodeVersion value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized EUnicodeVersion instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EUnicodeVersion& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize EUnicodeVersion value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EUnicodeVersion instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EUnicodeVersion& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/UCD/EUnicodeVersion.inl>
/*==========================================================================*/
#endif
