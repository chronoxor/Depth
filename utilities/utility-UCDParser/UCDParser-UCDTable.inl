/*!
 *  \file    UCDParser-UCDTable.cpp Unicode characters database generator is
 *           used to generate a source file with character properties tables
 *           for internal usage.
 *  \brief   Unicode characters database table generator (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.09.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database table generator (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      UCD parser utility
    VERSION:   1.0
    CREATED:   28.09.2009 22:54:48

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
#ifndef __UCDPARSER_UCDTABLE_INL__
#define __UCDPARSER_UCDTABLE_INL__
/*==========================================================================*/
Tbool UCDParser::parseInteger(const Tcsstr a_cpStringValue, Tsint& a_rResultValue)
{ CALL
  Tbool error = false;

  // Open string stream for parsing.
  CStreamStringBufferASCIIConst stream(a_cpStringValue);
  CHECK(stream.setPeekBufferSize(1));
  CHECK(stream.open());

  // Parse the first integer value form the string stream.
  Tsint value = 0;
  NUtility::CPair<Tbool, Tuint> result = stream.read(value, IStream::PARSE_ASCII);
  if (result.getFirst())
    a_rResultValue = value;
  else
    error = true;

  // Parse arithmetic operations.
  while (!error)
  {
    // Try to get the operation type.
    Tschar operation = ASC('\0');
    result = stream.read(operation);
    if (result.getFirst())
    {
      // Try to get the next integer value.
      result = stream.read(value, IStream::PARSE_ASCII);
      if (result.getFirst())
      {
        switch (operation)
        {
          case ASC('+'):
          {
            a_rResultValue += value;
            break;
          }
          case ASC('-'):
          {
            a_rResultValue -= value;
            break;
          }
          case ASC('*'):
          {
            a_rResultValue *= value;
            break;
          }
          case ASC('/'):
          {
            a_rResultValue /= value;
            break;
          }
          default:
          {
            error = true;
            break;
          }
        }
      }
      else
      {
        error = true;
        break;
      }
    }
    else
      break;
  };

  // Close string stream.
  CHECK(stream.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool UCDParser::parseReal(const Tcsstr a_cpStringValue, Treal& a_rResultValue)
{ CALL
  Tbool error = false;

  // Open string stream for parsing.
  CStreamStringBufferASCIIConst stream(a_cpStringValue);
  CHECK(stream.setPeekBufferSize(1));
  CHECK(stream.open());

  // Parse the first real value form the string stream.
  Treal value = 0;
  NUtility::CPair<Tbool, Tuint> result = stream.read(value, IStream::PARSE_ASCII);
  if (result.getFirst())
    a_rResultValue = value;
  else
    error = true;

  // Parse arithmetic operations.
  while (!error)
  {
    // Try to get the operation type.
    Tschar operation = ASC('\0');
    result = stream.read(operation);
    if (result.getFirst())
    {
      // Try to get the next real value.
      result = stream.read(value, IStream::PARSE_ASCII);
      if (result.getFirst())
      {
        switch (operation)
        {
          case ASC('+'):
          {
            a_rResultValue += value;
            break;
          }
          case ASC('-'):
          {
            a_rResultValue -= value;
            break;
          }
          case ASC('*'):
          {
            a_rResultValue *= value;
            break;
          }
          case ASC('/'):
          {
            a_rResultValue /= value;
            break;
          }
          default:
          {
            error = true;
            break;
          }
        }
      }
      else
      {
        error = true;
        break;
      }
    }
    else
      break;
  };

  // Close string stream.
  CHECK(stream.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool UCDParser::generateNumberTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName, const CStringBuffer<Tsstr>& a_crStringTable, const Tbool a_cGenerateReal)
{ CALL
  Tbool error = false;

  // Open string table file.
  CFile file_StringTable(a_cpFileName);
  CHECK(file_StringTable.open(NStream::IStream::e_OPEN_WRITE));

  a_crOutputStream << STR("Generating") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file...") << ln;

  // Write string table.
  file_StringTable << ascii;
  file_StringTable << a_crHeaderMessage << ln;
  for (Tuint i = 0; i < a_crStringTable.getSize(); ++i)
  {
    if (a_cGenerateReal)
    {
      Treal value = 0.0;
      if (parseReal(a_crStringTable[i], value))
        file_StringTable << value;
      else
      {
        error = true;
        break;
      }
    }
    else
    {
      Tsint value = 0;
      if (parseInteger(a_crStringTable[i], value))
        file_StringTable << value;
      else
      {
        error = true;
        break;
      }
    }
    file_StringTable << ((i < (a_crStringTable.getSize() - 1)) ? ASC(',') : ASC(' ')) << ln;
  }

  if (error)
    a_crOutputStream << STR("Cannot generate") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file.") << ln;
  else
    a_crOutputStream << CString(a_cpFileName) << STR(' ') << STR("file successfully generated.") << ln;

  // Close string table file.
  CHECK(file_StringTable.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool UCDParser::generateStringTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName, const CStringBuffer<Tsstr>& a_crStringTable)
{ CALL
  Tbool error = false;

  // Open string table file.
  CFile file_StringTable(a_cpFileName);
  CHECK(file_StringTable.open(NStream::IStream::e_OPEN_WRITE));

  a_crOutputStream << STR("Generating") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file...") << ln;

  // Write string table.
  file_StringTable << ascii;
  file_StringTable << a_crHeaderMessage << ln;
  for (Tuint i = 0; i < a_crStringTable.getSize(); ++i)
  {
    file_StringTable << ASC('"') << a_crStringTable[i] << ASC('"') << ((i < (a_crStringTable.getSize() - 1)) ? ASC(',') : ASC(' ')) << ln;
  }

  if (error)
    a_crOutputStream << STR("Cannot generate") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file.") << ln;
  else
    a_crOutputStream << CString(a_cpFileName) << STR(' ') << STR("file successfully generated.") << ln;

  // Close string table file.
  CHECK(file_StringTable.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool UCDParser::generateDecompositionMapping(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName)
{ CALL
  Tbool error = false;

  // Open Decomposition Mapping file.
  CFile file_DecompositionMapping(a_cpFileName);
  CHECK(file_DecompositionMapping.open(NStream::IStream::e_OPEN_WRITE));

  a_crOutputStream << STR("Generating") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file...") << ln;

  // Write Decomposition Mappings.
  file_DecompositionMapping << ascii;
  file_DecompositionMapping << a_crHeaderMessage << ln;
  file_DecompositionMapping << space << ralign << width(12);
  for (Tuint i = 0; i < the_DecompositionMappings.getSize(); ++i)
  {
    file_DecompositionMapping << ASC('{') << ASC(' ') << the_DecompositionMappings[i].m_DecompositionMappingType << ASC(',') << ASC(' ') << the_DecompositionMappings[i].m_DecompositionMappingSize << ASC(',') << ASC(' ');
    for (Tuint j = 0; j < countOf(the_DecompositionMappings[i].m_DecompositionMappingValues); ++j)
      file_DecompositionMapping << the_DecompositionMappings[i].m_DecompositionMappingValues[j] << ((j < (countOf(the_DecompositionMappings[i].m_DecompositionMappingValues) - 1)) ? ASC(',') : ASC(' '));
    file_DecompositionMapping << ASC(' ') << ASC('}') << ((i < (the_DecompositionMappings.getSize() - 1)) ? ASC(',') : ASC(' ')) << ln;
  }

  if (error)
    a_crOutputStream << STR("Cannot generate") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file.") << ln;
  else
    a_crOutputStream << CString(a_cpFileName) << STR(' ') << STR("file successfully generated.") << ln;

  // Close Decomposition Mapping file.
  CHECK(file_DecompositionMapping.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool UCDParser::generateUnicodeCharacterProperties(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName)
{ CALL
  Tbool error = false;

  // Open UCD file.
  CFile file_UCD(a_cpFileName);
  CHECK(file_UCD.open(NStream::IStream::e_OPEN_WRITE));

  a_crOutputStream << STR("Generating") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file...") << ln;

  // Write Unicode Character properties.
  file_UCD << ascii;
  file_UCD << a_crHeaderMessage << ln;
  file_UCD << space << ralign << width(12);
  CSparseArray<SUnicodeCharacterProperties>::TIteratorConst it = the_UnicodeCharacterDatabase.getItFirst();
  while (it.isValid())
  {
    // Get the current Unicode Character property.
    const SUnicodeCharacterProperties& prop = it.getValueRef();

    // Write the current Unicode Character property.
    file_UCD << ASC('{') << ASC(' ');
    file_UCD << prop.m_Code << ASC(',') << ASC(' ');
    file_UCD << prop.m_NameID << ASC(',') << ASC(' ');
    file_UCD << prop.m_NameOldID << ASC(',') << ASC(' ');
    file_UCD << prop.m_NameJamoID << ASC(',') << ASC(' ');
    file_UCD << (prop.m_GeneralCategory - e_GeneralCategory_Lu) << ASC(',') << ASC(' ');
    file_UCD << prop.m_CanonicalCombiningClass << ASC(',') << ASC(' ');
    file_UCD << (prop.m_BidiClass - e_BidiClass_L) << ASC(',') << ASC(' ');
    file_UCD << prop.m_DecompositionMappingID << ASC(',') << ASC(' ');
    file_UCD << prop.m_DecimalDigitID << ASC(',') << ASC(' ');
    file_UCD << prop.m_DigitID << ASC(',') << ASC(' ');
    file_UCD << prop.m_NumericID << ASC(',') << ASC(' ');
    file_UCD << (prop.m_BidiMirrored ? 1 : 0) << ASC(',') << ASC(' ');
    file_UCD << prop.m_UppercaseMapping << ASC(',') << ASC(' ');
    file_UCD << prop.m_LowercaseMapping << ASC(',') << ASC(' ');
    file_UCD << prop.m_TitlecaseMapping << ASC(',') << ASC(' ');
    file_UCD << width(20) << prop.m_BinaryProperties << ASC("ull") << width(12) << ASC(',') << ASC(' ');
    file_UCD << (prop.m_JoiningType - e_JoiningType_None) << ASC(',') << ASC(' ');
    file_UCD << (prop.m_JoiningGroup - e_JoiningGroup_None) << ASC(',') << ASC(' ');
    file_UCD << prop.m_BidiMirroringGlyph << ASC(',') << ASC(' ');
    file_UCD << (prop.m_BidiMirroringGlyphBestFit ? 1 : 0) << ASC(',') << ASC(' ');
    file_UCD << prop.m_BlockNameID << ASC(',') << ASC(' ');
    file_UCD << (prop.m_UnicodeVersion - e_UnicodeVersion_Unassigned) << ASC(',') << ASC(' ');
    file_UCD << (prop.m_EastAsianWidth - e_EastAsianWidth_Neutral) << ASC(',') << ASC(' ');
    file_UCD << (prop.m_HangulSyllableType - e_HangulSyllableType_None) << ASC(',') << ASC(' ');
    file_UCD << (prop.m_LineBreakClass - e_LineBreakClass_BK) << ASC(',') << ASC(' ');
    file_UCD << (prop.m_ScriptType - e_ScriptType_Arab) << ASC(',') << ASC(' ');
    file_UCD << 0 << ASC(' ') << ASC('}');

    // Take the next value.
    if (it.stepForward() == 0)
    {
      file_UCD << ASC(' ') << ln;
      break;
    }
    else
      file_UCD << ASC(',') << ln;
  }

  if (error)
    a_crOutputStream << STR("Cannot generate") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file.") << ln;
  else
    a_crOutputStream << CString(a_cpFileName) << STR(' ') << STR("file successfully generated.") << ln;

  // Close UCD file.
  CHECK(file_UCD.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool UCDParser::generateUnicodeCharacterPropertiesIndex(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName)
{ CALL
  Tbool error = false;

  // Open UCD index file.
  CFile file_UCDIndex(a_cpFileName);
  CHECK(file_UCDIndex.open(NStream::IStream::e_OPEN_WRITE));

  a_crOutputStream << STR("Generating") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file...") << ln;

  // Write Unicode Character properties.
  Tuint index = 0;
  file_UCDIndex << ascii;
  file_UCDIndex << a_crHeaderMessage << ln;
  file_UCDIndex << space << ralign << width(12);
  CSparseArray<SUnicodeCharacterProperties>::TAssociativeContainer::TIteratorConst it = the_UnicodeCharacterDatabase.getItFirst().getSparse();
  while (it.isValid())
  {
    Tuint index1 = it.getValueRef().getBuffer()[0].m_Code;
    Tuint index2 = it.getValueRef().getBuffer()[it.getValueRef().getLength() - 1].m_Code;
    Tuint index3 = index;
    Tuint index4 = index + index2 - index1;
    file_UCDIndex << ASC('{') << ASC(' ') << index1 << ASC(',') << ASC(' ') << index2 << ASC(',') << ASC(' ') << index3 << ASC(',') << ASC(' ') << index4 << ASC(' ') << ASC('}');

    // Increase UCD table index.
    index = index4 + 1;

    // Take the next value.
    if (it.stepForward() == 0)
    {
      file_UCDIndex << ASC(' ') << ln;
      break;
    }
    else
      file_UCDIndex << ASC(',') << ln;
  }

  if (error)
    a_crOutputStream << STR("Cannot generate") << STR(' ') << CString(a_cpFileName) << STR(' ') << STR("file.") << ln;
  else
    a_crOutputStream << CString(a_cpFileName) << STR(' ') << STR("file successfully generated.") << ln;

  // Close UCD index file.
  CHECK(file_UCDIndex.close());

  return !error;
}
/*--------------------------------------------------------------------------*/
Tbool UCDParser::generateUCDTable(CStreamStdOutput& a_crOutputStream)
{ CALL
  Tbool error = false;

  CStringASCII header(ASC("/* This file was auto-generated by UCDParser utility. Don't modify it manually! */"));

  // Generate utilities tables.
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("UCDTable-CharacterNames.inl"), the_CharacterNames));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("UCDTable-CharacterNamesOld.inl"), the_CharacterNamesOld));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("UCDTable-CharacterNamesJamo.inl"), the_CharacterNamesJamo));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("UCDTable-DecimalDigitNames.inl"), the_DecimalDigitValues));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("UCDTable-DigitNames.inl"), the_DigitValues));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("UCDTable-NumericNames.inl"), the_NumericValues));
  error |= (error ? false : !generateStringTable(a_crOutputStream, header, STR("UCDTable-BlockNames.inl"), the_BlockNames));
  error |= (error ? false : !generateNumberTable(a_crOutputStream, header, STR("UCDTable-DecimalDigitValues.inl"), the_DecimalDigitValues, false));
  error |= (error ? false : !generateNumberTable(a_crOutputStream, header, STR("UCDTable-DigitValues.inl"), the_DigitValues, false));
  error |= (error ? false : !generateNumberTable(a_crOutputStream, header, STR("UCDTable-NumericValues.inl"), the_NumericValues, true));
  error |= (error ? false : !generateDecompositionMapping(a_crOutputStream, header, STR("UCDTable-DecompositionMapping.inl")));
  error |= (error ? false : !generateUnicodeCharacterProperties(a_crOutputStream, header, STR("UCDTable-UnicodeCharacterProperties.inl")));
  error |= (error ? false : !generateUnicodeCharacterPropertiesIndex(a_crOutputStream, header, STR("UCDTable-UCDIndexes.inl")));

  return !error;
}
/*==========================================================================*/
#endif
