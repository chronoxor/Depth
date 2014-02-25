/*!
 *  \file    UCDParser.cpp Unicode characters database parser is used to parse
 *           UCD and create character properties tables for internal usage.
 *  \brief   Unicode characters database parser (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unicode characters database parser (source).

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
#ifndef __UCDPARSER_CPP__
#define __UCDPARSER_CPP__
/*==========================================================================*/
// Temporary headers.
#include <Depth/todo/file/CFile.hpp>
/*--------------------------------------------------------------------------*/
// Common headers.
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/algorithms/common/ACountOf.hpp>
#include <Depth/include/algorithms/containers/AFind.hpp>
#include <Depth/include/algorithms/functions/FStringComparator.hpp>
#include <Depth/include/algorithms/string/format/AToValue.hpp>
#include <Depth/include/stream/text/CStreamStringBufferASCIIConst.hpp>
#include <Depth/include/tokenizer/CTokenizer.hpp>
/*--------------------------------------------------------------------------*/
// Local headers.
#include "CTokenizerFunctionUCDParser.hpp"
#include "UCDParser.hpp"
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NCommon;
using namespace NDepth::NAlgorithms::NContainers;
using namespace NDepth::NAlgorithms::NFunctions;
using namespace NDepth::NAlgorithms::NString::NFormat;
using namespace NDepth::NFiles;
using namespace NDepth::NStream::NText;
using namespace NDepth::NTokenizer;
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUtilities {
/*--------------------------------------------------------------------------*/
namespace NUCDParser {
/*==========================================================================*/
/* GLOBAL VARIABLES DECLARATIONS                                            */
/*==========================================================================*/
CSparseArray<SUnicodeCharacterProperties> the_UnicodeCharacterDatabase;
CStringBuffer<Tsstr> the_CharacterNames;
CStringBuffer<Tsstr> the_CharacterNamesOld;
CStringBuffer<Tsstr> the_CharacterNamesJamo;
CStringBuffer<Tsstr> the_DecimalDigitValues;
CStringBuffer<Tsstr> the_DigitValues;
CStringBuffer<Tsstr> the_NumericValues;
CStringBuffer<Tsstr> the_BlockNames;
CArray<SDecompositionMapping> the_DecompositionMappings;
/*==========================================================================*/
/* STRUCTURE IMPLEMENTATIONS                                                */
/*==========================================================================*/
SUnicodeCharacterProperties::SUnicodeCharacterProperties()
{ CALL
  m_Code = 0;
  m_NameID = -1;
  m_NameOldID = -1;
  m_NameJamoID = -1;
  m_GeneralCategory = e_GeneralCategory_Cn;
  m_CanonicalCombiningClass = CCanonicalCombiningClass::CCC_Spacing;
  m_BidiClass = e_BidiClass_L;
  m_DecompositionMappingID = -1;
  m_DecimalDigitID = -1;
  m_DigitID = -1;
  m_NumericID = -1;
  m_BidiMirrored = false;
  m_UppercaseMapping = -1;
  m_LowercaseMapping = -1;
  m_TitlecaseMapping = -1;
  m_BinaryProperties = CBinaryProperties::None;
  m_JoiningType = e_JoiningType_None;
  m_JoiningGroup = e_JoiningGroup_None;
  m_BidiMirroringGlyph = -1;
  m_BidiMirroringGlyphBestFit = false;
  m_BlockNameID = -1;
  m_UnicodeVersion = e_UnicodeVersion_Unassigned;
  m_EastAsianWidth = e_EastAsianWidth_Neutral;
  m_HangulSyllableType = e_HangulSyllableType_None;
  m_LineBreakClass = e_LineBreakClass_XX;
  m_ScriptType = e_ScriptType_Zzzz;
}
/*==========================================================================*/
/* CLASS DECLARATIONS & IMPLEMENTATIONS                                     */
/*==========================================================================*/
class UCDParser :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    Tbool error = false;

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    // Show progress information.
    stdoutput << STR("Parsing Unicode character database...") << ln;

    // Parse UnicodeData.txt file.
    error |= (error ? false : !parseUnicodeData(stdoutput));
    // Parse ArabicShaping.txt file.
    error |= (error ? false : !parseArabicShaping(stdoutput));
    // Parse BidiMirroring.txt file.
    error |= (error ? false : !parseBidiMirroring(stdoutput));
    // Parse PropList.txt & DerivedCoreProperties.txt files.
    error |= (error ? false : !parseBinaryProperties(stdoutput, STR("PropList.txt")));
    // Parse DerivedCoreProperties.txt file.
    error |= (error ? false : !parseBinaryProperties(stdoutput, STR("DerivedCoreProperties.txt")));
    // Parse Blocks.txt file.
    error |= (error ? false : !parseBlockName(stdoutput));
    // Parse Jamo.txt file.
    error |= (error ? false : !parseJamo(stdoutput));
    // Parse DerivedAge.txt file.
    error |= (error ? false : !parseUnicodeVersion(stdoutput));
    // Parse EastAsianWidth.txt file.
    error |= (error ? false : !parseEastAsianWidth(stdoutput));
    // Parse HangulSyllableType.txt file.
    error |= (error ? false : !parseHangulSyllableType(stdoutput));
    // Parse LineBreak.txt file.
    error |= (error ? false : !parseLineBreakClass(stdoutput));
    // Parse Scripts.txt file.
    error |= (error ? false : !parseScriptType(stdoutput));

    // Show progress information.
    stdoutput << STR("Generating Unicode character database table...") << ln;

    // Generate UCDTable files.
    error |= (error ? false : !generateUCDTable(stdoutput));

    // Show progress information.
    stdoutput << STR("Done!") << ln;

    return (error ? IApplication::EXIT_WITH_ERROR : IApplication::EXIT_WITH_SUCCESS);
  }

private:
  //! Parse UnicodeData.txt file.
  Tbool parseUnicodeData(CStreamStdOutput& a_crOutputStream);
  //! Parse ArabicShaping.txt file.
  Tbool parseArabicShaping(CStreamStdOutput& a_crOutputStream);
  //! Parse BidiMirroring.txt file.
  Tbool parseBidiMirroring(CStreamStdOutput& a_crOutputStream);
  //! Parse PropList.txt & DerivedCoreProperties.txt files.
  Tbool parseBinaryProperties(CStreamStdOutput& a_crOutputStream, const Tcstr a_cpFileName);
  //! Parse Blocks.txt file.
  Tbool parseBlockName(CStreamStdOutput& a_crOutputStream);
  //! Parse Jamo.txt file.
  Tbool parseJamo(CStreamStdOutput& a_crOutputStream);
  //! Parse DerivedAge.txt file.
  Tbool parseUnicodeVersion(CStreamStdOutput& a_crOutputStream);
  //! Parse EastAsianWidth.txt file.
  Tbool parseEastAsianWidth(CStreamStdOutput& a_crOutputStream);
  //! Parse HangulSyllableType.txt file.
  Tbool parseHangulSyllableType(CStreamStdOutput& a_crOutputStream);
  //! Parse LineBreak.txt file.
  Tbool parseLineBreakClass(CStreamStdOutput& a_crOutputStream);
  //! Parse Scripts.txt file.
  Tbool parseScriptType(CStreamStdOutput& a_crOutputStream);

  //! Parse integer number form the given string.
  Tbool parseInteger(const Tcsstr a_cpStringValue, Tsint& a_rResultValue);
  //! Parse real number form the given string.
  Tbool parseReal(const Tcsstr a_cpStringValue, Treal& a_rResultValue);

  //! Generate number table file.
  Tbool generateNumberTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName, const CStringBuffer<Tsstr>& a_crStringTable, const Tbool a_cGenerateReal);
  //! Generate string table file.
  Tbool generateStringTable(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName, const CStringBuffer<Tsstr>& a_crStringTable);
  //! Generate Decomposition Mapping file.
  Tbool generateDecompositionMapping(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName);
  //! Generate Unicode Character Properties file.
  Tbool generateUnicodeCharacterProperties(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName);
  //! Generate Unicode Character Properties index file.
  Tbool generateUnicodeCharacterPropertiesIndex(CStreamStdOutput& a_crOutputStream, const CStringASCII& a_crHeaderMessage, const Tcstr a_cpFileName);
  //! Generate UCDTable files.
  Tbool generateUCDTable(CStreamStdOutput& a_crOutputStream);
} the_Application;
/*--------------------------------------------------------------------------*/
#include "UCDParser-ArabicShaping.inl"
#include "UCDParser-BidiMirroring.inl"
#include "UCDParser-BinaryProperties.inl"
#include "UCDParser-BlockName.inl"
#include "UCDParser-EastAsianWidth.inl"
#include "UCDParser-HangulSyllableType.inl"
#include "UCDParser-Jamo.inl"
#include "UCDParser-LineBreakClass.inl"
#include "UCDParser-ScriptType.inl"
#include "UCDParser-UnicodeData.inl"
#include "UCDParser-UnicodeVersion.inl"
#include "UCDParser-UCDTable.inl"
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
