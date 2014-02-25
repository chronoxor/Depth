/*!
 *  \file    CCharacterProperties.cpp Character properties class provides
 *           special information about ASCII/Unicode character.
 *  \brief   Character properties class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.10.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character properties class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   20.10.2009 20:48:38

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/string/CCharacterProperties.hpp>
#include <Depth/include/string/UCD/details/UCDTable.hpp>
/*==========================================================================*/
#ifndef __CCHARACTERPROPERTIES_CPP__
#define __CCHARACTERPROPERTIES_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
void CCharacterProperties::set(const Tschar a_cCharacter)
{ CALL
  m_Value = (Tuint)a_cCharacter;
  m_UCDIndex = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
}
/*--------------------------------------------------------------------------*/
void CCharacterProperties::set(const Twchar a_cCharacter)
{ CALL
  m_Value = (Tuint)a_cCharacter;
  m_UCDIndex = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
}
/*--------------------------------------------------------------------------*/
void CCharacterProperties::set(const Tuint a_cCharacter)
{ CALL
  m_Value = a_cCharacter;
  m_UCDIndex = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
}
/*--------------------------------------------------------------------------*/
void CCharacterProperties::set(const CCharacter& a_crCharacter)
{ CALL
  m_Value = a_crCharacter.m_Value;
  m_UCDIndex = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
}
/*--------------------------------------------------------------------------*/
Tuint CCharacterProperties::getCode() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return 0;
  }

  return NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_Code;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacterProperties::isValidName() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return false;
  }

  return (NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_NameID >= 0);
}
/*--------------------------------------------------------------------------*/
Tcsstr CCharacterProperties::getName() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_NameID;

  // Check if the Name property of the character is valid.
  ASSERT((index >= 0), STR("There is no Name property for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  return NUCD::NDetails::the_CharacterNames[index];
}
/*--------------------------------------------------------------------------*/
Tbool CCharacterProperties::isValidOldName() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return false;
  }

  return (NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_NameOldID >= 0);
}
/*--------------------------------------------------------------------------*/
Tcsstr CCharacterProperties::getOldName() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_NameOldID;

  // Check if the Old Name property of the character is valid.
  ASSERT((index >= 0), STR("There is no Old Name property for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  return NUCD::NDetails::the_CharacterNamesOld[index];
}
/*--------------------------------------------------------------------------*/
Tbool CCharacterProperties::isValidJamoName() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return false;
  }

  return (NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_NameJamoID >= 0);
}
/*--------------------------------------------------------------------------*/
Tcsstr CCharacterProperties::getJamoName() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_NameJamoID;

  // Check if the Jamo Name property of the character is valid.
  ASSERT((index >= 0), STR("There is no Jamo Name property for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  return NUCD::NDetails::the_CharacterNamesJamo[index];
}
/*--------------------------------------------------------------------------*/
NUCD::EGeneralCategory CCharacterProperties::getGeneralCategory() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::e_GeneralCategory_Cn;
  }

  return (NUCD::EGeneralCategory)(NUCD::e_GeneralCategory_Lu + NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_GeneralCategory);
}
/*--------------------------------------------------------------------------*/
Tuint08 CCharacterProperties::getCanonicalCombiningClass() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::CCanonicalCombiningClass::CCC_Spacing;
  }

  return NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_CanonicalCombiningClass;
}
/*--------------------------------------------------------------------------*/
NUCD::EBidiClass CCharacterProperties::getBidiClass() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::e_BidiClass_L;
  }

  return (NUCD::EBidiClass)(NUCD::e_BidiClass_L + NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_BidiClass);
}
/*--------------------------------------------------------------------------*/
Tbool CCharacterProperties::isValidDecompositionMapping() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return false;
  }

  return (NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_DecompositionMappingID >= 0);
}
/*--------------------------------------------------------------------------*/
NUCD::EDecompositionMapping CCharacterProperties::getDecompositionMappingType() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::e_DecompositionMapping_None;
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_DecompositionMappingID;

  // Check if the Decomposition Mapping Type property of the character is valid.
  ASSERT((index >= 0), STR("There is no Decomposition Mapping Type property for character with code %hU.") COMMA m_Value)
  {
    return NUCD::e_DecompositionMapping_None;
  }

  return (NUCD::EDecompositionMapping)(NUCD::e_DecompositionMapping_None + NUCD::NDetails::the_DecompositionMapping[index][0]);
}
/*--------------------------------------------------------------------------*/
Tuint CCharacterProperties::getDecompositionMappingSize() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return 0;
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_DecompositionMappingID;

  // Check if the Decomposition Mapping Size property of the character is valid.
  ASSERT((index >= 0), STR("There is no Decomposition Mapping Size property for character with code %hU.") COMMA m_Value)
  {
    return 0;
  }

  return NUCD::NDetails::the_DecompositionMapping[index][1];
}
/*--------------------------------------------------------------------------*/
Tsint CCharacterProperties::getDecompositionMappingValue(const Tuint a_cIndex) const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return -1;
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_DecompositionMappingID;

  // Check if the Decomposition Mapping Value property of the character is valid.
  ASSERT((index >= 0), STR("There is no Decomposition Mapping Value property for character with code %hU.") COMMA m_Value)
  {
    return -1;
  }
  // Check index value and the Decomposition Mapping Value property bounds.
  ASSERT(((Tsint32)a_cIndex < NUCD::NDetails::the_DecompositionMapping[index][1]), STR("Out of bounds index for the Decomposition Mapping Value property (index = %u, size = %u).") COMMA a_cIndex COMMA NUCD::NDetails::the_DecompositionMapping[index][1])
  {
    return -1;
  }

  return NUCD::NDetails::the_DecompositionMapping[index][2 + a_cIndex];
}
/*--------------------------------------------------------------------------*/
Tbool CCharacterProperties::isValidDecimalDigit() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return false;
  }

  return (NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_DecimalDigitID >= 0);
}
/*--------------------------------------------------------------------------*/
Tcsstr CCharacterProperties::getDecimalDigitName() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_DecimalDigitID;

  // Check if the Decimal Digit Name property of the character is valid.
  ASSERT((index >= 0), STR("There is no Decimal Digit Name property for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  return NUCD::NDetails::the_DecimalDigitNames[index];
}
/*--------------------------------------------------------------------------*/
Tsint CCharacterProperties::getDecimalDigitValue() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return 0;
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_DecimalDigitID;

  // Check if the Decimal Digit Value property of the character is valid.
  ASSERT((index >= 0), STR("There is no Decimal Digit Value property for character with code %hU.") COMMA m_Value)
  {
    return 0;
  }

  return NUCD::NDetails::the_DecimalDigitValues[index];
}
/*--------------------------------------------------------------------------*/
Tbool CCharacterProperties::isValidDigit() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return false;
  }

  return (NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_DigitID >= 0);
}
/*--------------------------------------------------------------------------*/
Tcsstr CCharacterProperties::getDigitName() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_DigitID;

  // Check if the Digit Name property of the character is valid.
  ASSERT((index >= 0), STR("There is no Digit Name property for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  return NUCD::NDetails::the_DigitNames[index];
}
/*--------------------------------------------------------------------------*/
Tsint CCharacterProperties::getDigitValue() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return 0;
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_DigitID;

  // Check if the Digit Value property of the character is valid.
  ASSERT((index >= 0), STR("There is no Digit Value property for character with code %hU.") COMMA m_Value)
  {
    return 0;
  }

  return NUCD::NDetails::the_DigitValues[index];
}
/*--------------------------------------------------------------------------*/
Tbool CCharacterProperties::isValidNumeric() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return false;
  }

  return (NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_NumericID >= 0);
}
/*--------------------------------------------------------------------------*/
Tcsstr CCharacterProperties::getNumericName() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_NumericID;

  // Check if the Numeric Name property of the character is valid.
  ASSERT((index >= 0), STR("There is no Numeric Name property for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  return NUCD::NDetails::the_NumericNames[index];
}
/*--------------------------------------------------------------------------*/
Treal CCharacterProperties::getNumericValue() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return 0.0;
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_NumericID;

  // Check if the Numeric Value property of the character is valid.
  ASSERT((index >= 0), STR("There is no Numeric Value property for character with code %hU.") COMMA m_Value)
  {
    return 0.0;
  }

  return (Treal)NUCD::NDetails::the_NumericValues[index];
}
/*--------------------------------------------------------------------------*/
Tbool CCharacterProperties::getBidiMirrored() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return false;
  }

  return (NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_BidiMirrored != 0);
}
/*--------------------------------------------------------------------------*/
Tsint CCharacterProperties::getLowercaseMapping() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return -1;
  }

  return NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_LowercaseMapping;
}
/*--------------------------------------------------------------------------*/
Tsint CCharacterProperties::getUppercaseMapping() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return -1;
  }

  return NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_UppercaseMapping;
}
/*--------------------------------------------------------------------------*/
Tsint CCharacterProperties::getTitlecaseMapping() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return -1;
  }

  return NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_TitlecaseMapping;
}
/*--------------------------------------------------------------------------*/
Tuint64 CCharacterProperties::getBinaryProperties() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::CBinaryProperties::None;
  }

  return NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_BinaryProperties;
}
/*--------------------------------------------------------------------------*/
NUCD::EJoiningType CCharacterProperties::getJoiningType() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::e_JoiningType_None;
  }

  return (NUCD::EJoiningType)(NUCD::e_JoiningType_None + NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_JoiningType);
}
/*--------------------------------------------------------------------------*/
NUCD::EJoiningGroup CCharacterProperties::getJoiningGroup() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::e_JoiningGroup_None;
  }

  return (NUCD::EJoiningGroup)(NUCD::e_JoiningGroup_None + NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_JoiningGroup);
}
/*--------------------------------------------------------------------------*/
Tsint CCharacterProperties::getBidiMirroringGlyph() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return -1;
  }

  return NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_BidiMirroringGlyph;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacterProperties::getBidiMirroringGlyphBestFit() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return false;
  }

  return (NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_BidiMirroringGlyphBestFit != 0);
}
/*--------------------------------------------------------------------------*/
Tbool CCharacterProperties::isValidBlockName() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return false;
  }

  return (NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_BlockNameID >= 0);
}
/*--------------------------------------------------------------------------*/
Tcsstr CCharacterProperties::getBlockName() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  Tsint index = NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_BlockNameID;

  // Check if the Block Name property of the character is valid.
  ASSERT((index >= 0), STR("There is no Block Name property for character with code %hU.") COMMA m_Value)
  {
    return ASC("");
  }

  return NUCD::NDetails::the_BlockNames[index];
}
/*--------------------------------------------------------------------------*/
NUCD::EUnicodeVersion CCharacterProperties::getUnicodeVersion() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::e_UnicodeVersion_Unassigned;
  }

  return (NUCD::EUnicodeVersion)(NUCD::e_UnicodeVersion_Unassigned + NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_UnicodeVersion);
}
/*--------------------------------------------------------------------------*/
NUCD::EEastAsianWidth CCharacterProperties::getEastAsianWidth() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::e_EastAsianWidth_Neutral;
  }

  return (NUCD::EEastAsianWidth)(NUCD::e_EastAsianWidth_Neutral + NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_EastAsianWidth);
}
/*--------------------------------------------------------------------------*/
NUCD::EHangulSyllableType CCharacterProperties::getHangulSyllableType() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::e_HangulSyllableType_None;
  }

  return (NUCD::EHangulSyllableType)(NUCD::e_HangulSyllableType_None + NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_HangulSyllableType);
}
/*--------------------------------------------------------------------------*/
NUCD::ELineBreakClass CCharacterProperties::getLineBreakClass() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::e_LineBreakClass_XX;
  }

  return (NUCD::ELineBreakClass)(NUCD::e_LineBreakClass_BK + NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_LineBreakClass);
}
/*--------------------------------------------------------------------------*/
NUCD::EScriptType CCharacterProperties::getScriptType() const
{ CALL
  // Check if the character has valid properties.
  ASSERT(isValid(), STR("Character properties are invalid for character with code %hU.") COMMA m_Value)
  {
    return NUCD::e_ScriptType_Zzzz;
  }

  return (NUCD::EScriptType)(NUCD::e_ScriptType_Arab + NUCD::NDetails::the_UnicodeCharacterProperties[m_UCDIndex].m_ScriptType);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
