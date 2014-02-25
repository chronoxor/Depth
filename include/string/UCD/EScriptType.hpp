/*!
 *  \file    EScriptType.hpp Character script type enumeration.
 *  \brief   Character script type enumeration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character script type enumeration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 02:44:42

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
#ifndef __ESCRIPTTYPE_HPP__
#define __ESCRIPTTYPE_HPP__
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
//! Script type of the character.
/*!
    Character script type.

    Value for each character is taken from "Scripts.txt" file.
*/
enum EScriptType
{
  e_ScriptType_Arab,      //!< Script type is "Arabic".
  e_ScriptType_Armi,      //!< Script type is "Imperial Aramaic".
  e_ScriptType_Armn,      //!< Script type is "Armenian".
  e_ScriptType_Avst,      //!< Script type is "Avestan".
  e_ScriptType_Bali,      //!< Script type is "Balinese".
  e_ScriptType_Bamu,      //!< Script type is "Bamum".
  e_ScriptType_Batk,      //!< Script type is "Batak".
  e_ScriptType_Beng,      //!< Script type is "Bengali".
  e_ScriptType_Blis,      //!< Script type is "Blissymbols".
  e_ScriptType_Bopo,      //!< Script type is "Bopomofo".
  e_ScriptType_Brah,      //!< Script type is "Brahmi".
  e_ScriptType_Brai,      //!< Script type is "Braille".
  e_ScriptType_Bugi,      //!< Script type is "Buginese".
  e_ScriptType_Buhd,      //!< Script type is "Buhid".
  e_ScriptType_Cakm,      //!< Script type is "Chakma".
  e_ScriptType_Cans,      //!< Script type is "Unified Canadian Aboriginal Syllabics".
  e_ScriptType_Cari,      //!< Script type is "Carian".
  e_ScriptType_Cham,      //!< Script type is "Cham".
  e_ScriptType_Cher,      //!< Script type is "Cherokee".
  e_ScriptType_Cirt,      //!< Script type is "Cirth".
  e_ScriptType_Copt,      //!< Script type is "Coptic (Qaac)".
  e_ScriptType_Cprt,      //!< Script type is "Cypriot".
  e_ScriptType_Cyrl,      //!< Script type is "Cyrillic".
  e_ScriptType_Cyrs,      //!< Script type is "Cyrillic (Old Church Slavonic variant)".
  e_ScriptType_Deva,      //!< Script type is "Devanagari (Nagari)".
  e_ScriptType_Dsrt,      //!< Script type is "Deseret (Mormon)".
  e_ScriptType_Egyd,      //!< Script type is "Egyptian demotic".
  e_ScriptType_Egyh,      //!< Script type is "Egyptian hieratic".
  e_ScriptType_Egyp,      //!< Script type is "Egyptian hieroglyphs".
  e_ScriptType_Ethi,      //!< Script type is "Ethiopic (Ge'ez)".
  e_ScriptType_Geok,      //!< Script type is "Khutsuri (Asomtavruli and Nuskhuri)".
  e_ScriptType_Geor,      //!< Script type is "Georgian (Mkhedruli)".
  e_ScriptType_Glag,      //!< Script type is "Glagolitic".
  e_ScriptType_Goth,      //!< Script type is "Gothic".
  e_ScriptType_Grek,      //!< Script type is "Greek".
  e_ScriptType_Gujr,      //!< Script type is "Gujarati".
  e_ScriptType_Guru,      //!< Script type is "Gurmukhi".
  e_ScriptType_Hang,      //!< Script type is "Hangul (Hangul, Hangeul)".
  e_ScriptType_Hani,      //!< Script type is "Han (Hanzi, Kanji, Hanja)".
  e_ScriptType_Hans,      //!< Script type is "Han (Simplified variant)".
  e_ScriptType_Hant,      //!< Script type is "Han (Traditional variant)".
  e_ScriptType_Hano,      //!< Script type is "Hanunoo (Hanunoo)".
  e_ScriptType_Hebr,      //!< Script type is "Hebrew".
  e_ScriptType_Hira,      //!< Script type is "Hiragana".
  e_ScriptType_Hmng,      //!< Script type is "Pahawh Hmong".
  e_ScriptType_Hrkt,      //!< Script type is "Hiragana + Katakana".
  e_ScriptType_Hung,      //!< Script type is "Old Hungarian".
  e_ScriptType_Inds,      //!< Script type is "Indus (Harappan)".
  e_ScriptType_Ital,      //!< Script type is "Old Italic (Etruscan, Oscan, etc.)".
  e_ScriptType_Java,      //!< Script type is "Javanese".
  e_ScriptType_Jpan,      //!< Script type is "Japanese (alias for Han + Hiragana + Katakana)".
  e_ScriptType_Kali,      //!< Script type is "Kayah Li".
  e_ScriptType_Kana,      //!< Script type is "Katakana".
  e_ScriptType_Khar,      //!< Script type is "Kharoshthi".
  e_ScriptType_Khmr,      //!< Script type is "Khmer".
  e_ScriptType_Knda,      //!< Script type is "Kannada".
  e_ScriptType_Kore,      //!< Script type is "Korean (Hangul + Han)".
  e_ScriptType_Kthi,      //!< Script type is "Kaithi".
  e_ScriptType_Lana,      //!< Script type is "Tai Tham (Lanna)".
  e_ScriptType_Laoo,      //!< Script type is "Lao".
  e_ScriptType_Latf,      //!< Script type is "Latin (Fraktur variant)".
  e_ScriptType_Latg,      //!< Script type is "Latin (Gaelic variant)".
  e_ScriptType_Latn,      //!< Script type is "Latin".
  e_ScriptType_Lepc,      //!< Script type is "Lepcha (Rong)".
  e_ScriptType_Limb,      //!< Script type is "Limbu".
  e_ScriptType_Lina,      //!< Script type is "Linear A".
  e_ScriptType_Linb,      //!< Script type is "Linear B".
  e_ScriptType_Lisu,      //!< Script type is "Lisu (Fraser)".
  e_ScriptType_Lyci,      //!< Script type is "Lycian".
  e_ScriptType_Lydi,      //!< Script type is "Lydian".
  e_ScriptType_Mand,      //!< Script type is "Mandaic, Mandaean".
  e_ScriptType_Mani,      //!< Script type is "Manichaean".
  e_ScriptType_Maya,      //!< Script type is "Mayan hieroglyphs".
  e_ScriptType_Mero,      //!< Script type is "Meroitic".
  e_ScriptType_Mlym,      //!< Script type is "Malayalam".
  e_ScriptType_Mong,      //!< Script type is "Mongolian".
  e_ScriptType_Moon,      //!< Script type is "Moon (Moon code, Moon script, Moon type)".
  e_ScriptType_Mtei,      //!< Script type is "Meitei Mayek (Meithei, Meetei)".
  e_ScriptType_Mymr,      //!< Script type is "Myanmar (Burmese)".
  e_ScriptType_Nkgb,      //!< Script type is "Nakhi Geba ('Na-'Khi Ggo-baw, Naxi Geba)".
  e_ScriptType_Nkoo,      //!< Script type is "N'Ko".
  e_ScriptType_Ogam,      //!< Script type is "Ogham".
  e_ScriptType_Olck,      //!< Script type is "Ol Chiki (Ol Cemet', Ol, Santali)".
  e_ScriptType_Orkh,      //!< Script type is "Old Turkic, Orkhon Runic".
  e_ScriptType_Orya,      //!< Script type is "Oriya".
  e_ScriptType_Osma,      //!< Script type is "Osmanya".
  e_ScriptType_Perm,      //!< Script type is "Old Permic".
  e_ScriptType_Phag,      //!< Script type is "Phags-pa".
  e_ScriptType_Phli,      //!< Script type is "Inscriptional Pahlavi".
  e_ScriptType_Phlp,      //!< Script type is "Psalter Pahlavi".
  e_ScriptType_Phlv,      //!< Script type is "Book Pahlavi".
  e_ScriptType_Phnx,      //!< Script type is "Phoenician".
  e_ScriptType_Plrd,      //!< Script type is "Miao (Pollard)".
  e_ScriptType_Prti,      //!< Script type is "Inscriptional Parthian".
  e_ScriptType_Qaaa,      //!< Script type is "Reserved for private use (start)".
  e_ScriptType_Qabx,      //!< Script type is "Reserved for private use (end)".
  e_ScriptType_Rjng,      //!< Script type is "Rejang (Redjang, Kaganga)".
  e_ScriptType_Roro,      //!< Script type is "Rongorongo".
  e_ScriptType_Runr,      //!< Script type is "Runic".
  e_ScriptType_Samr,      //!< Script type is "Samaritan".
  e_ScriptType_Sara,      //!< Script type is "Sarati".
  e_ScriptType_Sarb,      //!< Script type is "Old South Arabian".
  e_ScriptType_Saur,      //!< Script type is "Saurashtra".
  e_ScriptType_Sgnw,      //!< Script type is "SignWriting".
  e_ScriptType_Shaw,      //!< Script type is "Shavian (Shaw)".
  e_ScriptType_Sinh,      //!< Script type is "Sinhala".
  e_ScriptType_Sund,      //!< Script type is "Sundanese".
  e_ScriptType_Sylo,      //!< Script type is "Syloti Nagri".
  e_ScriptType_Syrc,      //!< Script type is "Syriac".
  e_ScriptType_Syre,      //!< Script type is "Syriac (Estrangelo variant)".
  e_ScriptType_Syrj,      //!< Script type is "Syriac (Western variant)".
  e_ScriptType_Syrn,      //!< Script type is "Syriac (Eastern variant)".
  e_ScriptType_Tagb,      //!< Script type is "Tagbanwa".
  e_ScriptType_Taml,      //!< Script type is "Tamil".
  e_ScriptType_Tale,      //!< Script type is "Tai Le".
  e_ScriptType_Talu,      //!< Script type is "New Tai Lue".
  e_ScriptType_Tavt,      //!< Script type is "Tai Viet".
  e_ScriptType_Telu,      //!< Script type is "Telugu".
  e_ScriptType_Teng,      //!< Script type is "Tengwar".
  e_ScriptType_Tfng,      //!< Script type is "Tifinagh (Berber)".
  e_ScriptType_Tglg,      //!< Script type is "Tagalog (Baybayin, Alibata)".
  e_ScriptType_Thaa,      //!< Script type is "Thaana".
  e_ScriptType_Thai,      //!< Script type is "Thai".
  e_ScriptType_Tibt,      //!< Script type is "Tibetan".
  e_ScriptType_Ugar,      //!< Script type is "Ugaritic".
  e_ScriptType_Vaii,      //!< Script type is "Vai".
  e_ScriptType_Visp,      //!< Script type is "Visible Speech".
  e_ScriptType_Xpeo,      //!< Script type is "Old Persian".
  e_ScriptType_Xsux,      //!< Script type is "Cuneiform, Sumero-Akkadian".
  e_ScriptType_Yiii,      //!< Script type is "Yi".
  e_ScriptType_Zinh,      //!< Script type is "Code for inherited script".
  e_ScriptType_Zmth,      //!< Script type is "Mathematical notation".
  e_ScriptType_Zsym,      //!< Script type is "Symbols".
  e_ScriptType_Zxxx,      //!< Script type is "Code for unwritten documents".
  e_ScriptType_Zyyy,      //!< Script type is "Code for undetermined script".
  e_ScriptType_Zzzz       //!< Script type is "Code for uncoded script".
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
//! Serialization load of the EScriptType value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EScriptType instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EScriptType& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save of the EScriptType value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized EScriptType instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EScriptType& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize EScriptType value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EScriptType instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EScriptType& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/UCD/EScriptType.inl>
/*==========================================================================*/
#endif
