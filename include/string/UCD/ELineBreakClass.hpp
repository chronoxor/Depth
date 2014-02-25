/*!
 *  \file    ELineBreakClass.hpp Character line break class enumeration.
 *  \brief   Character line break class enumeration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character line break class enumeration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 03:16:56

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
#ifndef __ELINEBREAKCLASS_HPP__
#define __ELINEBREAKCLASS_HPP__
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
//! Line break class of the character.
/*!
    Line breaking class of the character.

    Value for each character is taken from "LineBreak.txt" file.
*/
enum ELineBreakClass
{
  // Non-tailorable Line Breaking Classes.
  e_LineBreakClass_BK,                  //!< Mandatory Break (e.g. NL, PS). Cause a line break (after).
  e_LineBreakClass_CR,                  //!< Carriage Return (e.g. CR). Cause a line break (after), except between CR and LF.
  e_LineBreakClass_LF,                  //!< Line Feed (e.g. LF). Cause a line break (after).
  e_LineBreakClass_CM,                  //!< Attached Characters and Combining Marks (e.g. combining marks, control codes). Prohibit a line break between the character and the preceding character.
  e_LineBreakClass_NL,                  //!< Next Line (e.g. NEL). Cause a line break (after).
  e_LineBreakClass_SG,                  //!< Surrogates (e.g. surrogates). Do not occur in well-formed text.
  e_LineBreakClass_WJ,                  //!< Word Joiner (e.g. WJ). Prohibit line breaks before and after.
  e_LineBreakClass_ZW,                  //!< Zero Width Space (e.g. ZWSP). Provide a break opportunity.
  e_LineBreakClass_GL,                  //!< Non-breaking ("Glue") (e.g. CGJ, NBSP, ZWNBSP). Prohibit line breaks before and after.
  e_LineBreakClass_SP,                  //!< Space (e.g. SPACE). Enable indirect line breaks.

  // Break Opportunities.
  e_LineBreakClass_B2,                  //!< Break Opportunity Before and After (e.g. Em dash). Provide a line break opportunity before and after the character.
  e_LineBreakClass_BA,                  //!< Break Opportunity After (e.g. spaces, hyphens). Generally provide a line break opportunity after the character.
  e_LineBreakClass_BB,                  //!< Break Opportunity Before (e.g. punctuation used in dictionaries). Generally provide a line break opportunity before the character.
  e_LineBreakClass_HY,                  //!< Hyphen (e.g. HYPHEN-MINUS). Provide a line break opportunity after the character, except in numeric context.
  e_LineBreakClass_CB,                  //!< Contingent Break Opportunity (e.g. inline objects). Provide a line break opportunity contingent on additional information.

  // Characters Prohibiting Certain Breaks.
  e_LineBreakClass_CL,                  //!< Closing Punctuation (e.g. '}', etc.). Prohibit line breaks before.
  e_LineBreakClass_CP,                  //!< Closing Close Parenthesis (e.g. ')', ']', etc.). Prohibit line breaks before.
  e_LineBreakClass_EX,                  //!< Exclamation/Interrogation (e.g. '!', '?', etc.). Prohibit line breaks before.
  e_LineBreakClass_IN,                  //!< Inseparable (e.g. leaders). Allow only indirect line breaks between pairs.
  e_LineBreakClass_NS,                  //!< Nonstarter (e.g. small kana). Allow only indirect line breaks before.
  e_LineBreakClass_OP,                  //!< Opening Punctuation (e.g. '(', '[', '{', etc.). Prohibit line breaks after.
  e_LineBreakClass_QU,                  //!< Ambiguous Quotation (e.g. quotation marks). Act like they are both opening and closing.

  // Numeric Context.
  e_LineBreakClass_IS,                  //!< Infix Separator (Numeric) (e.g. '.', ','). Prevent breaks after any and before numeric.
  e_LineBreakClass_NU,                  //!< Numeric (e.g. digits). Form numeric expressions for line breaking purposes.
  e_LineBreakClass_PO,                  //!< Postfix (Numeric) (e.g. '%'). Do not break following a numeric expression.
  e_LineBreakClass_PR,                  //!< Prefix (Numeric) (e.g. '$'). Do not break in front of a numeric expression.
  e_LineBreakClass_SY,                  //!< Symbols Allowing Break After (e.g. '/'). Prevent a break before, and allow a break after.

  // Other Characters.
  e_LineBreakClass_AI,                  //!< Ambiguous (Alphabetic or Ideographic) (e.g. Characters with Ambiguous East Asian Width). Act like AL when the resolved EAW is N; otherwise, act as ID.
  e_LineBreakClass_AL,                  //!< Ordinary Alphabetic and Symbol Characters (e.g. Alphabets and regular symbols). Are alphabetic characters or symbols that are used with alphabetic characters.
  e_LineBreakClass_H2,                  //!< Hangul LV Syllable (e.g. Hangul). Form Korean syllable blocks.
  e_LineBreakClass_H3,                  //!< Hangul LVT Syllable (e.g. Hangul). Form Korean syllable blocks.
  e_LineBreakClass_ID,                  //!< Ideographic (e.g. Ideographs). Break before or after, except in some numeric context.
  e_LineBreakClass_JL,                  //!< Hangul L Jamo (e.g. Conjoining jamo). Form Korean syllable blocks.
  e_LineBreakClass_JV,                  //!< Hangul V Jamo (e.g. Conjoining jamo). Form Korean syllable blocks.
  e_LineBreakClass_JT,                  //!< Hangul T Jamo (e.g. Conjoining jamo). Form Korean syllable blocks.
  e_LineBreakClass_SA,                  //!< Complex Context Dependent (South East Asian) (e.g. South East Asian: Thai, Lao, Khmer). Provide a line break opportunity contingent on additional, language-specific context analysis.
  e_LineBreakClass_XX                   //!< Unknown (e.g. unassigned, private-use). Have as yet unknown line breaking behavior or unassigned code positions.
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
//! Serialization load of the ELineBreakClass value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized ELineBreakClass instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::ELineBreakClass& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save of the ELineBreakClass value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized ELineBreakClass instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::ELineBreakClass& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize ELineBreakClass value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized ELineBreakClass instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::ELineBreakClass& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/UCD/ELineBreakClass.inl>
/*==========================================================================*/
#endif
