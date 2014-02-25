/*!
 *  \file    EHangulSyllableType.hpp Character Hangul Syllable type
 *           enumeration.
 *  \brief   Character Hangul Syllable type enumeration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character Hangul Syllable type enumeration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   01.04.2009 23:59:25

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
#ifndef __EHANGULSYLLABLETYPE_HPP__
#define __EHANGULSYLLABLETYPE_HPP__
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
//! Joining Hangul Syllable type of the character.
/*!
    Character Hangul Syllable type.

    Value for each character is taken from "HangulSyllableType.txt" file.
*/
enum EHangulSyllableType
{
  e_HangulSyllableType_None,            //!< Hangul Syllable type is "None".
  e_HangulSyllableType_Leading_Jamo,    //!< Hangul Syllable type is "Leading Jamo".
  e_HangulSyllableType_Vowel_Jamo,      //!< Hangul Syllable type is "Vowel Jamo".
  e_HangulSyllableType_Trailing_Jamo,   //!< Hangul Syllable type is "Trailing Jamo".
  e_HangulSyllableType_LV_Syllable,     //!< Hangul Syllable type is "LV Syllable".
  e_HangulSyllableType_LVT_Syllable     //!< Hangul Syllable type is "LVT Syllable".
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
//! Serialization load of the EHangulSyllableType value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EHangulSyllableType instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EHangulSyllableType& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save of the EHangulSyllableType value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized EHangulSyllableType instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EHangulSyllableType& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize EHangulSyllableType value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EHangulSyllableType instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EHangulSyllableType& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/UCD/EHangulSyllableType.inl>
/*==========================================================================*/
#endif
