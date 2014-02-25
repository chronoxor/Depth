/*!
 *  \file    CBinaryProperties.hpp Character binary properties constants.
 *  \brief   Character binary properties constants.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character binary properties constants.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 20:48:08

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
#ifndef __CBINARYPROPERTIES_HPP__
#define __CBINARYPROPERTIES_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NUCD {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Static class of binary properties constants of the character.
/*!
    Character binary properties constants.

    Value   for   each   character   is   taken   from   "PropList.txt"    and
    "DerivedCoreProperties.txt" files.
*/
class BASE_API CBinaryProperties :
  public NDepth::NCommon::IStatic
{
public:
  static const Tuint64 None;            //<! Empty character binary property.
  static const Tuint64 AHex;            //<! ASCII characters commonly used for the representation of hexadecimal numbers.
  static const Tuint64 Alpha;           //<! Characters with the Alphabetic property. Generated from: Lu + Ll + Lt + Lm + Lo + Nl + Other_Alphabetic.
  static const Tuint64 Bidi_C;          //<! Those format control characters which have specific functions in the Bidirectional Algorithm.
  static const Tuint64 Bidi_M;          //<! Bidi Mirrored character.
  static const Tuint64 Cased;           //<! Characters which are considered to be either uppercase, lowercase or titlecase characters. This property is not identical to the Changes_When_Casemapped property. For more information, see D120 in Section 3.13, "Default Case Algorithms" in Unicode. Generated from: Lowercase + Uppercase + Lt.
  static const Tuint64 CaseIgnorable;   //<! Characters which are ignored for casing purposes. For more information, see D121 in Section 3.13, "Default Case Algorithms" in Unicode. Generated from: Mn + Me + Cf + Lm + Sk + Word_Break=MidLetter + Word_Break=MidNumLet.
  static const Tuint64 CWLower;         //<! Characters whose normalized forms are not stable under a toLowercase mapping. For more information, see D124 in Section 3.13, "Default Case Algorithms" in Unicode. Generated from: toLowercase(toNFD(X)) != toNFD(X).
  static const Tuint64 CWUpper;         //<! Characters whose normalized forms are not stable under a toUppercase mapping. For more information, see D125 in Section 3.13, "Default Case Algorithms" in Unicode. Generated from: toUppercase(toNFD(X)) != toNFD(X).
  static const Tuint64 CWTitle;         //<! Characters whose normalized forms are not stable under a toTitlecase mapping. For more information, see D126 in Section 3.13, "Default Case Algorithms" in Unicode. Generated from: toTitlecase(toNFD(X)) != toNFD(X).
  static const Tuint64 CWCasefold;      //<! Characters whose normalized forms are not stable under case folding. For more information, see D127 in Section 3.13, "Default Case Algorithms" in Unicode. Generated from: toCasefold(toNFD(X)) != toNFD(X).
  static const Tuint64 CWCasemap;       //<! Characters which may change when they undergo case mapping. For more information, see D128 in Section 3.13, "Default Case Algorithms" in Unicode. Generated from: Changes_When_Lowercased(X) or Changes_When_Uppercased(X) or Changes_When_Titlecased(X).
  static const Tuint64 Dash;            //<! Those punctuation characters explicitly called out as dashes in the Unicode Standard, plus compatibility equivalents to those. Most of these have the Pd General Category, but some have the Sm General Category because of their use in mathematics.
  static const Tuint64 Dep;             //<! For a machine-readable list of deprecated characters. No characters will ever be removed from the standard, but the usage of deprecated characters is strongly discouraged.
  static const Tuint64 DI;              //<! For programmatic determination of default ignorable code points. New characters that should be ignored in rendering (unless explicitly supported) will be assigned in these ranges, permitting programs to correctly handle the default rendering of such characters when not otherwise supported. For more information, see the FAQ Display of Unsupported Characters, and Section 5.20 in Unicode.Generated from Other_Default_Ignorable_Code_Point + Cf (format characters) + Variation_Selector - White_Space - FFF9..FFFB (annotation characters) - 0600..0603, 06DD, 070F (exceptional Cf characters that should be visible).
  static const Tuint64 Dia;             //<! Characters that linguistically modify the meaning of another character to which they apply. Some diacritics are not combining characters, and some combining characters are not diacritics.
  static const Tuint64 Ext;             //<! Characters whose principal function is to extend the value or shape of a preceding alphabetic character. Typical of these are length and iteration marks.
  static const Tuint64 Hex;             //<! Characters commonly used for the representation of hexadecimal numbers, plus their compatibility equivalents.
  static const Tuint64 Hyphen;          //<! Those dashes used to mark connections between pieces of words, plus the Katakana middle dot. The Katakana middle dot functions like a hyphen, but is shaped like a dot rather than a dash.
  static const Tuint64 Ideo;            //<! Characters considered to be CJKV (Chinese, Japanese, Korean, and Vietnamese) ideographs.
  static const Tuint64 IDSB;            //<! Used in Ideographic Description Sequences.
  static const Tuint64 IDST;            //<! Used in Ideographic Description Sequences.
  static const Tuint64 Join_C;          //<! Those format control characters which have specific functions for control of cursive joining and ligation.
  static const Tuint64 LOE;             //<! There are a small number of characters that do not use logical order. These characters require special handling in most processing.
  static const Tuint64 Lower;           //<! Characters with the Lowercase property. Generated from: Ll + Other_Lowercase.
  static const Tuint64 Math;            //<! Characters with the Math property. Generated from: Sm + Other_Math.
  static const Tuint64 NChar;           //<! Code points that are permanently reserved for internal use.
  static const Tuint64 OAlpha;          //<! Used in deriving the "Alphabetic" property.
  static const Tuint64 ODI;             //<! Used in deriving the "Default Ignorable Code Point" property.
  static const Tuint64 OGr_Ext;         //<! Used in deriving  the "Grapheme Extend" property.
  static const Tuint64 OIDC;            //<! Used for backwards compatibility of "ID Continue".
  static const Tuint64 OIDS;            //<! Used for backwards compatibility of "ID Start".
  static const Tuint64 OLower;          //<! Used in deriving the "Lowercase" property.
  static const Tuint64 OMath;           //<! Used in deriving  the "Math" property.
  static const Tuint64 OUpper;          //<! Used in deriving the "Uppercase" property.
  static const Tuint64 QMark;           //<! Those punctuation characters that function as quotation marks.
  static const Tuint64 Radical;         //<! Used in Ideographic Description Sequences.
  static const Tuint64 SD;              //<! Characters with a "soft dot", like i or j. An accent placed on these characters causes the dot to disappear. An explicit dot above can be added where required, such as in Lithuanian.
  static const Tuint64 Term;            //<! Those punctuation characters that generally mark the end of textual units.
  static const Tuint64 UIdeo;           //<! Used in Ideographic Description Sequences.
  static const Tuint64 Upper;           //<! Characters with the Uppercase property. Generated from: Lu + Other_Uppercase.
  static const Tuint64 VS;              //<! Indicates all those characters that qualify as Variation Selectors. For details on the behavior of these characters, see  StandardizedVariants.html and Section 16.4, Variation Selectors in Unicode.
  static const Tuint64 WSpace;          //<! Those separator characters and control characters which should be treated by programming languages as "white space" for the purpose of parsing elements.
  static const Tuint64 STerm;           //<! Sentence Terminal. Used in UAX #29: Text Boundaries.
  static const Tuint64 Gr_Base;         //<! For programmatic determination of grapheme cluster boundaries. For more information, see UAX #29: Text Boundaries Breaks. Generated from: [0..10FFFF] - Cc - Cf - Cs - Co - Cn - Zl - Zp - Grapheme_Extend.
  static const Tuint64 Gr_Ext;          //<! For programmatic determination of grapheme cluster boundaries. For more information, see UAX #29: Text Boundaries Breaks. Generated from: Me + Mn + Other_Grapheme_Extend.
  static const Tuint64 Gr_Link;         //<! Deprecated property, once proposed for programmatic determination of grapheme cluster boundaries. Generated from: Canonical_Combining_Class=Virama.
  static const Tuint64 Pat_Syn;         //<! Used for pattern syntax as described in UAX #31: Identifier and Pattern Syntax.
  static const Tuint64 Pat_WS;          //<! Used for pattern syntax as described in UAX #31: Identifier and Pattern Syntax.
  static const Tuint64 IDC;             //<! Used to determine programming identifiers, as described in UAX #31: Identifier and Pattern Syntax.
  static const Tuint64 IDS;             //<! Used to determine programming identifiers, as described in UAX #31: Identifier and Pattern Syntax.
  static const Tuint64 XIDC;            //<! Used to determine programming identifiers, as described in UAX #31: Identifier and Pattern Syntax.
  static const Tuint64 XIDS;            //<! Used to determine programming identifiers, as described in UAX #31: Identifier and Pattern Syntax.
  static const Tuint64 CE;              //<! Composition Exclusion character.
  static const Tuint64 Comp_Ex;         //<! Full Composition Exclusion character.
  static const Tuint64 XO_NFC;          //<! Character expands on NFC.
  static const Tuint64 XO_NFD;          //<! Character expands on NFD.
  static const Tuint64 XO_NFKC;         //<! Character expands on NFKC.
  static const Tuint64 XO_NFKD;         //<! Character expands on NFKD.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
