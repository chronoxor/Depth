/*!
 *  \file    EEastAsianWidth.hpp Character East Asian width enumeration.
 *  \brief   Character East Asian width enumeration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character East Asian width enumeration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   01.04.2009 23:33:33

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
#ifndef __EEASTASIANWIDTH_HPP__
#define __EEASTASIANWIDTH_HPP__
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
//! East Asian width of the character.
/*!
    Properties for determining the choice of wide vs. narrow  glyphs  in  East
    Asian contexts.

    <b>ED1. East_Asian_Width:</b> In the context of interoperating  with  East
    Asian legacy character encodings and implementing East  Asian  typography,
    East_Asian_Width is a categorization of character.  It  can  take  on  two
    abstract values, narrow and wide.

    In legacy implementations, there is often a  corresponding  difference  in
    encoding length (one or two bytes) as well as a  difference  in  displayed
    width. However, the actual display width of a glyph is given by  the  font
    and may be further adjusted by layout. An important class  of  fixed-width
    legacy fonts contains glyphs of just two widths,  with  the  wider  glyphs
    twice as wide as the narrower glyphs.

    Note: For convenience, the classification  further  distinguishes  between
    explicitly and implicitly wide and narrow characters.

    <b>ED2. East Asian Fullwidth (F):</b> All characters that are  defined  as
    Fullwidth in the Unicode Standard  [Unicode]  by  having  a  compatibility
    decomposition of type  <wide>  to  characters  elsewhere  in  the  Unicode
    Standard that are implicitly narrow but unmarked.

    Note: The Unicode property value aliases drop the common prefix East Asian
    for this and the following property values.

    <b>ED3. East Asian Halfwidth (H):</b> All characters that  are  explicitly
    defined as Halfwidth in the Unicode Standard  by  having  a  compatibility
    decomposition of type <narrow> to  characters  elsewhere  in  the  Unicode
    Standard that are implicitly wide but unmarked, plus the WON SIGN.

    <b>ED4. East Asian Wide (W):</b> All  other  characters  that  are  always
    wide. These characters occur only in the context of East Asian  typography
    where they are wide characters (such as  the  Unified  Han  Ideographs  or
    Squared Katakana Symbols). This category  includes  characters  that  have
    explicit halfwidth counterparts.

    <b>ED5. East Asian Narrow (Na):</b> All other characters that  are  always
    narrow and have explicit fullwidth or wide counterparts. These  characters
    are implicitly narrow in East Asian typography and legacy  character  sets
    because they have explicit fullwidth or wide counterparts. All of ASCII is
    an example of East Asian Narrow characters.

    It is useful to distinguish characters  explicitly  defined  as  halfwidth
    from other narrow characters. In particular, halfwidth punctuation behaves
    in some  important  ways  like  ideographic  punctuation,  and  knowing  a
    character is a halfwidth character can aid in font selection when  binding
    a font to unstyled text.

    <b>ED6. East Asian Ambiguous (A):</b> All characters that can be sometimes
    wide  and  sometimes  narrow.  Ambiguous  characters  require   additional
    information not contained in the character code to further  resolve  their
    width.

    Ambiguous characters occur in East Asian legacy  character  sets  as  wide
    characters, but as narrow  (i.e.,  normal-width)  characters  in  non-East
    Asian usage. (Examples are the basic Greek and Cyrillic alphabet found  in
    East Asian character sets, but also some  of  the  mathematical  symbols.)
    Private-use  characters  are  considered  ambiguous  by  default,  because
    additional information is required to know whether they should be  treated
    as wide or narrow.

    Figure 1. Venn Diagram Showing the Set  Relations  for  Five  of  the  Six
    Categories

    \image html EastAsianWidth.png "East Asian width of the characters."

    When they are treated  as  wide  characters,  ambiguous  characters  would
    typically be rendered upright in vertical text runs.

    Because East Asian legacy character sets do not  always  include  complete
    case pairs of Latin characters, two  members  of  a  case  pair  may  have
    different East_Asian_Width properties:

    \code
    Ambiguous:    01D4    LATIN SMALL LETTER U WITH CARON
    NEA Neutral:  01D3    LATIN CAPITAL LETTER U WITH CARON
    \endcode

    Canonical  equivalents  of  ambiguous  characters  may  not  be  ambiguous
    themselves. For  example,  the  angstrom  sign  is  Ambiguous,  while  its
    decomposition, latin capital letter a with ring, is Neutral.

    <b>ED7. Neutral  (Not  East  Asian):</b>  All  other  characters.  Neutral
    characters do not occur in legacy East Asian character sets. By extension,
    they also do not occur in East Asian typography. For example, there is  no
    traditional Japanese way of typesetting Devanagari. Canonical  equivalents
    of narrow and neutral characters may not themselves be narrow  or  neutral
    respectively. For example, the character latin capital letter a with  ring
    is Neutral, but its decomposition starts with a Narrow character.

    Value for each character is taken from "EastAsianWidth.txt" file.
*/
enum EEastAsianWidth
{
  e_EastAsianWidth_Neutral,             //!< East Asian width is "Neutral".
  e_EastAsianWidth_Fullwidth,           //!< East Asian width is "Fullwidth".
  e_EastAsianWidth_Halfwidth,           //!< East Asian width is "Halfwidth".
  e_EastAsianWidth_Wide,                //!< East Asian width is "Wide".
  e_EastAsianWidth_Narrow,              //!< East Asian width is "Narrow".
  e_EastAsianWidth_Ambiguous            //!< East Asian width is "Ambiguous".
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
//! Serialization load of the EEastAsianWidth value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EEastAsianWidth instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EEastAsianWidth& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save of the EEastAsianWidth value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized EEastAsianWidth instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EEastAsianWidth& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize EEastAsianWidth value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EEastAsianWidth instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EEastAsianWidth& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/UCD/EEastAsianWidth.inl>
/*==========================================================================*/
#endif
