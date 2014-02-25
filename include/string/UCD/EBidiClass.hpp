/*!
 *  \file    EBidiClass.hpp Character Bidirectional Behavior class
 *           enumeration.
 *  \brief   Character Bidirectional Behavior class enumeration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character Bidirectional Behavior class enumeration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 22:27:57

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
#ifndef __EBIDICLASS_HPP__
#define __EBIDICLASS_HPP__
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
//! Bidirectional Behavior class of the character.
/*!
    Character Bidirectional Behavior class.

    These are the categories required by the Bidirectional Behavior  Algorithm
    in the Unicode Standard.

    Value for each character is taken from "UnicodeData.txt" file.
*/
enum EBidiClass
{
  e_BidiClass_L,               //!< Bidirectional Behavior class is "Left-to-Right".
  e_BidiClass_LRE,             //!< Bidirectional Behavior class is "Left-to-Right Embedding".
  e_BidiClass_LRO,             //!< Bidirectional Behavior class is "Left-to-Right Override".
  e_BidiClass_R,               //!< Bidirectional Behavior class is "Right-to-Left".
  e_BidiClass_AL,              //!< Bidirectional Behavior class is "Right-to-Left Arabic".
  e_BidiClass_RLE,             //!< Bidirectional Behavior class is "Right-to-Left Embedding".
  e_BidiClass_RLO,             //!< Bidirectional Behavior class is "Right-to-Left Override".
  e_BidiClass_PDF,             //!< Bidirectional Behavior class is "Pop Directional Format".
  e_BidiClass_EN,              //!< Bidirectional Behavior class is "European Number".
  e_BidiClass_ES,              //!< Bidirectional Behavior class is "European Number Separator".
  e_BidiClass_ET,              //!< Bidirectional Behavior class is "European Number Terminator".
  e_BidiClass_AN,              //!< Bidirectional Behavior class is "Arabic Number".
  e_BidiClass_CS,              //!< Bidirectional Behavior class is "Common Number Separator".
  e_BidiClass_NSM,             //!< Bidirectional Behavior class is "Non-Spacing Mark".
  e_BidiClass_BN,              //!< Bidirectional Behavior class is "Boundary Neutral".
  e_BidiClass_B,               //!< Bidirectional Behavior class is "Paragraph Separator".
  e_BidiClass_S,               //!< Bidirectional Behavior class is "Segment Separator".
  e_BidiClass_WS,              //!< Bidirectional Behavior class is "Whitespace".
  e_BidiClass_ON               //!< Bidirectional Behavior class is "Other Neutrals".
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
//! Serialization load of the EBidiClass value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EBidiClass instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EBidiClass& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save of the EBidiClass value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized EBidiClass instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EBidiClass& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize EBidiClass value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EBidiClass instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EBidiClass& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/UCD/EBidiClass.inl>
/*==========================================================================*/
#endif
