/*!
 *  \file    UCDTable.hpp Unicode Character Database table was generated with
 *           UCDParser utility and used as a source of Unicode information.
 *  \brief   Generated Unicode Character Database table.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.09.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Generated Unicode Character Database table.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD) details.
    VERSION:   1.0
    CREATED:   28.09.2009 23:03:58

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
#ifndef __UCDTABLE_HPP__
#define __UCDTABLE_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NUCD {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* STRUCTURE DECLARATIONS                                                   */
/*==========================================================================*/
struct BASE_API SUnicodeCharacterProperties //! Unicode character's properties.
{
  // Main fields.
  Tuint32 m_Code;                           //!< Character code.
  Tsint32 m_NameID : 16;                    //!< Character name ID (could be -1).
  Tsint32 m_NameOldID : 12;                 //!< Character old name ID (could be -1).
  Tsint32 m_NameJamoID : 7;                 //!< Character Jamo name ID (could be -1).
  Tuint32 m_GeneralCategory : 5;            //!< General category.
  Tuint08 m_CanonicalCombiningClass;        //!< Canonical combining class.
  Tuint32 m_BidiClass : 5;                  //!< Bidi class.
  Tsint32 m_DecompositionMappingID : 18;    //!< Decomposition mapping ID (could be -1).
  Tsint32 m_DecimalDigitID : 9;             //!< Decimal digit ID (could be -1).
  Tsint32 m_DigitID : 9;                    //!< Digit ID (could be -1).
  Tsint32 m_NumericID : 10;                 //!< Numeric ID (could be -1).
  Tuint32 m_BidiMirrored : 1;               //!< Bidi mirrored flag.
  Tsint32 m_UppercaseMapping;               //!< Uppercase mapping character.
  Tsint32 m_LowercaseMapping;               //!< Lowercase mapping character.
  Tsint32 m_TitlecaseMapping;               //!< Titlecase mapping character.
  Tuint64 m_BinaryProperties;               //!< Character binary properties.
  Tuint32 m_JoiningType : 3;                //!< Joining type.
  Tuint32 m_JoiningGroup : 6;               //!< Joining group.
  Tsint32 m_BidiMirroringGlyph;             //!< Bidi Mirroring Glyph.
  Tuint32 m_BidiMirroringGlyphBestFit : 1;  //!< Bidi Mirroring Glyph best fit flag.
  Tsint32 m_BlockNameID : 9;                //!< Block name ID (could be -1).
  Tuint32 m_UnicodeVersion : 4;             //!< Unicode version.
  Tuint32 m_EastAsianWidth : 3;             //!< East Asian width.
  Tuint32 m_HangulSyllableType : 3;         //!< Hangul Syllable type.
  Tuint32 m_LineBreakClass : 6;             //!< Line Break class.
  Tuint32 m_ScriptType : 8;                 //!< Script type.

  // Utility fields.
  Tuint32 m_Padding : 17;                   //!< Structure align padding.
};
/*==========================================================================*/
/* GLOBAL VARIABLES DECLARATIONS                                            */
/*==========================================================================*/
//! Global table of Unicode Character Database indexes.
extern BASE_API const Tuint32 the_UCDIndexes[][4];
//! Global table of the Unicode Character Database.
extern BASE_API const SUnicodeCharacterProperties the_UnicodeCharacterProperties[];
//! Global table of character names.
extern BASE_API Tcsstr the_CharacterNames[];
//! Global table of old character names.
extern BASE_API Tcsstr the_CharacterNamesOld[];
//! Global table of Jamo character names.
extern BASE_API Tcsstr the_CharacterNamesJamo[];
//! Global table of Decimal Digit names & values.
extern BASE_API Tcsstr the_DecimalDigitNames[];
extern BASE_API const Tsint the_DecimalDigitValues[];
//! Global table of Digit names & values.
extern BASE_API Tcsstr the_DigitNames[];
extern BASE_API const Tsint the_DigitValues[];
//! Global table of Numeric names & values.
extern BASE_API Tcsstr the_NumericNames[];
extern BASE_API const Tdouble the_NumericValues[];
//! Global table of Block names.
extern BASE_API Tcsstr the_BlockNames[];
//! Global table of Decomposition Mapping.
extern BASE_API const Tsint32 the_DecompositionMapping[][20];
/*==========================================================================*/
/* GLOBAL FUNCTIONS DECLARATIONS                                            */
/*==========================================================================*/
//! Get Unicode Character Database index from the Unicode Character value.
/*!
    \param a_cUnicodeCharacter - Unicode Character value.
    \return Unicode Character Database index.
*/
BASE_API Tsint32 getUCDIndex(const Tuint32 a_cUnicodeCharacter);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
