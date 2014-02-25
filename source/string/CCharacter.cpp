/*!
 *  \file    CCharacter.cpp Character class wraps operations with a single
 *           ASCII/Unicode character.
 *  \brief   Character wrapper class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character wrapper class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String
    VERSION:   1.0
    CREATED:   28.08.2007 22:38:11

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
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/string/CCharacterProperties.hpp>
#include <Depth/include/string/UCD/details/UCDTable.hpp>
/*==========================================================================*/
#ifndef __CCHARACTER_CPP__
#define __CCHARACTER_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tchar CCharacter::getSystem() const
{ CALL
  // Check if the character is in the valid system form.
  ASSERT(isValidSystem(), STR("Cannot get system character from the one in general form (character code is %hU).") COMMA m_Value)
  {
    return 0;
  }

  return (Tchar)m_Value;
}
/*--------------------------------------------------------------------------*/
Tschar CCharacter::getASCII() const
{ CALL
  // Check if the character is in the valid ASCII form.
  ASSERT(isValidASCII(), STR("Cannot get ASCII character from the one in general form (character code is %hU).") COMMA m_Value)
  {
    return 0;
  }

  return (Tschar)m_Value;
}
/*--------------------------------------------------------------------------*/
Twchar CCharacter::getUnicode() const
{ CALL
  // Check if the character is in the valid Unicode form.
  ASSERT(isValidUnicode(), STR("Cannot get Unicode character from the one in general form (character code is %hU).") COMMA m_Value)
  {
    return 0;
  }

  return (Twchar)m_Value;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isAlnum() const
{ CALL
  return (isLetter() || isNumber());
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isAlpha() const
{ CALL
  return isLetter();
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isBlank() const
{ CALL
  return (isSeparator() || isOther());
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isCntrl() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
    return (NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory == NUCD::e_GeneralCategory_Cc);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isDigit() const
{ CALL
  return isNumber();
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isDecimalDigit() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
    return (NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory == NUCD::e_GeneralCategory_Nd);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isGraph() const
{ CALL
  return (isNumber() || isLetter() || isPunctuation());
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isPrint() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    NUCD::EGeneralCategory category = (NUCD::EGeneralCategory)(NUCD::e_GeneralCategory_Lu + NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory);
    return ((category != NUCD::e_GeneralCategory_Cc) && (category != NUCD::e_GeneralCategory_Cn));
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isPunct() const
{ CALL
  return isPunctuation();
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isSpace() const
{ CALL
  return isSeparator();
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isXDigit() const
{ CALL
  return (isDecimalDigit() || ((m_Value >= ASC('A')) && (m_Value <= ASC('F'))) || ((m_Value >= ASC('a')) && (m_Value <= ASC('f'))));
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isLetter() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    NUCD::EGeneralCategory category = (NUCD::EGeneralCategory)(NUCD::e_GeneralCategory_Lu + NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory);
    return ((category >= NUCD::e_GeneralCategory_Lu) && (category <= NUCD::e_GeneralCategory_Lo));
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isMark() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    NUCD::EGeneralCategory category = (NUCD::EGeneralCategory)(NUCD::e_GeneralCategory_Lu + NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory);
    return ((category >= NUCD::e_GeneralCategory_Mn) && (category <= NUCD::e_GeneralCategory_Me));
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isNumber() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    NUCD::EGeneralCategory category = (NUCD::EGeneralCategory)(NUCD::e_GeneralCategory_Lu + NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory);
    return ((category >= NUCD::e_GeneralCategory_Nd) && (category <= NUCD::e_GeneralCategory_No));
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isPunctuation() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    NUCD::EGeneralCategory category = (NUCD::EGeneralCategory)(NUCD::e_GeneralCategory_Lu + NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory);
    return ((category >= NUCD::e_GeneralCategory_Pc) && (category <= NUCD::e_GeneralCategory_Po));
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isSymbol() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    NUCD::EGeneralCategory category = (NUCD::EGeneralCategory)(NUCD::e_GeneralCategory_Lu + NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory);
    return ((category >= NUCD::e_GeneralCategory_Sm) && (category <= NUCD::e_GeneralCategory_So));
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isSeparator() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    NUCD::EGeneralCategory category = (NUCD::EGeneralCategory)(NUCD::e_GeneralCategory_Lu + NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory);
    return ((category >= NUCD::e_GeneralCategory_Zs) && (category <= NUCD::e_GeneralCategory_Zp));
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isOther() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    NUCD::EGeneralCategory category = (NUCD::EGeneralCategory)(NUCD::e_GeneralCategory_Lu + NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory);
    return ((category >= NUCD::e_GeneralCategory_Cc) && (category <= NUCD::e_GeneralCategory_Cn));
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isLower() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
    return (NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory == NUCD::e_GeneralCategory_Ll);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isUpper() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
    return (NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory == NUCD::e_GeneralCategory_Lu);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CCharacter::isTitle() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
    return (NUCD::NDetails::the_UnicodeCharacterProperties[index].m_GeneralCategory == NUCD::e_GeneralCategory_Lt);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
CCharacter CCharacter::toLowerCase() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    Tsint32 lowercase = NUCD::NDetails::the_UnicodeCharacterProperties[index].m_LowercaseMapping;
    if (lowercase >= 0)
      return CCharacter((Tuint)lowercase);
  }
  return CCharacter(m_Value);
}
/*--------------------------------------------------------------------------*/
CCharacter CCharacter::toUpperCase() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    Tsint32 uppercase = NUCD::NDetails::the_UnicodeCharacterProperties[index].m_UppercaseMapping;
    if (uppercase >= 0)
      return CCharacter((Tuint)uppercase);
  }
  return CCharacter(m_Value);
}
/*--------------------------------------------------------------------------*/
CCharacter CCharacter::toTitleCase() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    Tsint32 titlecase = NUCD::NDetails::the_UnicodeCharacterProperties[index].m_TitlecaseMapping;
    if (titlecase >= 0)
      return CCharacter((Tuint)titlecase);
  }
  return CCharacter(m_Value);
}
/*--------------------------------------------------------------------------*/
CCharacter CCharacter::toToggleCase() const
{ CALL
  Tsint32 index = NUCD::NDetails::getUCDIndex((Tuint32)m_Value);
  if (index >= 0)
  {
    Tsint32 lowercase = NUCD::NDetails::the_UnicodeCharacterProperties[index].m_LowercaseMapping;
    Tsint32 uppercase = NUCD::NDetails::the_UnicodeCharacterProperties[index].m_UppercaseMapping;
    if (lowercase >= 0)
      return CCharacter((Tuint)lowercase);
    if (uppercase >= 0)
      return CCharacter((Tuint)uppercase);
  }
  return CCharacter(m_Value);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
