/*!
 *  \file    UCDParser.hpp Unicode characters database parser is used to parse
 *           UCD and create character properties tables for internal usage.
 *  \brief   Unicode characters database parser.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database parser.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      UCD parser utility
    VERSION:   1.0
    CREATED:   04.05.2009 22:56:44

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
#ifndef __UCDPARSER_HPP__
#define __UCDPARSER_HPP__
/*==========================================================================*/
// Common headers.
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/CSparseArray.hpp>
#include <Depth/include/containers/CStringBuffer.hpp>
#include <Depth/include/string/CString.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/string/UCD/CBinaryProperties.hpp>
#include <Depth/include/string/UCD/CCanonicalCombiningClass.hpp>
#include <Depth/include/string/UCD/EBidiClass.hpp>
#include <Depth/include/string/UCD/EDecompositionMapping.hpp>
#include <Depth/include/string/UCD/EEastAsianWidth.hpp>
#include <Depth/include/string/UCD/EGeneralCategory.hpp>
#include <Depth/include/string/UCD/EHangulSyllableType.hpp>
#include <Depth/include/string/UCD/EJoiningGroup.hpp>
#include <Depth/include/string/UCD/EJoiningType.hpp>
#include <Depth/include/string/UCD/ELineBreakClass.hpp>
#include <Depth/include/string/UCD/EScriptType.hpp>
#include <Depth/include/string/UCD/EUnicodeVersion.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NContainers;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific headers.
using namespace NDepth::NString::NUCD;
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtilities {
/*--------------------------------------------------------------------------*/
namespace NUCDParser {
/*==========================================================================*/
/* STRUCTURE DECLARATIONS                                                   */
/*==========================================================================*/
struct SUnicodeCharacterProperties                      //! Unicode character's properties.
{
  // UnicodeData.txt
  Tuint32                  m_Code;                      //!< Character code.
  Tsint32                  m_NameID;                    //!< Character name ID.
  Tsint32                  m_NameOldID;                 //!< Character old name ID.
  Tsint32                  m_NameJamoID;                //!< Character Jamo name ID.
  EGeneralCategory         m_GeneralCategory;           //!< General category.
  Tuint08                  m_CanonicalCombiningClass;   //!< Canonical combining class.
  EBidiClass               m_BidiClass;                 //!< Bidi class.
  Tsint32                  m_DecompositionMappingID;    //!< Decomposition mapping ID.
  Tsint32                  m_DecimalDigitID;            //!< Decimal digit ID.
  Tsint32                  m_DigitID;                   //!< Digit ID.
  Tsint32                  m_NumericID;                 //!< Numeric ID.
  Tbool                    m_BidiMirrored;              //!< Bidi mirrored flag.
  Tsint32                  m_UppercaseMapping;          //!< Uppercase mapping character.
  Tsint32                  m_LowercaseMapping;          //!< Lowercase mapping character.
  Tsint32                  m_TitlecaseMapping;          //!< Titlecase mapping character.
  // PropList.txt
  Tuint64                  m_BinaryProperties;          //!< Character binary properties.
  // ArabicShaping.txt
  EJoiningType             m_JoiningType;               //!< Joining type.
  EJoiningGroup            m_JoiningGroup;              //!< Joining group.
  // BidiMirroring.txt
  Tsint32                  m_BidiMirroringGlyph;        //!< Bidi Mirroring Glyph.
  Tbool                    m_BidiMirroringGlyphBestFit; //!< Bidi Mirroring Glyph best fit flag.
  // Blocks.txt
  Tsint32                  m_BlockNameID;               //!< Block name ID.
  // DerivedAge.txt
  EUnicodeVersion          m_UnicodeVersion;            //!< Unicode version.
  // EastAsianWidth.txt
  EEastAsianWidth          m_EastAsianWidth;            //!< East Asian width.
  // HangulSyllableType.txt
  EHangulSyllableType      m_HangulSyllableType;        //!< Hangul Syllable type.
  // LineBreak.txt
  ELineBreakClass          m_LineBreakClass;            //!< Line Break class.
  // Scripts.txt
  EScriptType              m_ScriptType;                //!< Script type.

  //! Default structure constructor.
  SUnicodeCharacterProperties();
};
/*--------------------------------------------------------------------------*/
struct SDecompositionMapping                            //! Decomposition mapping properties.
{
  Tsint32 m_DecompositionMappingType;                   //!< Decomposition mapping type.
  Tsint32 m_DecompositionMappingSize;                   //!< Decomposition mapping size.
  Tsint32 m_DecompositionMappingValues[18];             //!< Decomposition mapping values.
};
/*==========================================================================*/
/* GLOBAL VARIABLES DECLARATIONS                                            */
/*==========================================================================*/
//! Global container for the Unicode Character Database.
extern CSparseArray<SUnicodeCharacterProperties> the_UnicodeCharacterDatabase;
//! Global container for character names.
extern CStringBuffer<Tsstr>                      the_CharacterNames;
//! Global container for old character names.
extern CStringBuffer<Tsstr>                      the_CharacterNamesOld;
//! Global container for Jamo character names.
extern CStringBuffer<Tsstr>                      the_CharacterNamesJamo;
//! Global container for Decimal Digit values.
extern CStringBuffer<Tsstr>                      the_DecimalDigitValues;
//! Global container for Digit values.
extern CStringBuffer<Tsstr>                      the_DigitValues;
//! Global container for Numeric values.
extern CStringBuffer<Tsstr>                      the_NumericValues;
//! Global container for Block names.
extern CStringBuffer<Tsstr>                      the_BlockNames;
//! Global container for Decomposition Mapping values.
extern CArray<SDecompositionMapping>             the_DecompositionMappings;
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
