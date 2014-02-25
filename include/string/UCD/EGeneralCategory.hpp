/*!
 *  \file    EGeneralCategory.hpp Character General Category type enumeration.
 *  \brief   Character General Category type enumeration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character General Category type enumeration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 23:07:14

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
#ifndef __EGENERALCATEGORY_HPP__
#define __EGENERALCATEGORY_HPP__
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
//! General Category type of the character.
/*!
    Character General Category type.

    This is a useful breakdown into various character types which can be  used
    as a default categorization in implementations.

    Value for each character is taken from "UnicodeData.txt" file.
*/
enum EGeneralCategory
{
  e_GeneralCategory_Lu,            //!< General Category type is "Letter, Uppercase".
  e_GeneralCategory_Ll,            //!< General Category type is "Letter, Lowercase".
  e_GeneralCategory_Lt,            //!< General Category type is "Letter, Titlecase".
  e_GeneralCategory_Lm,            //!< General Category type is "Letter, Modifier".
  e_GeneralCategory_Lo,            //!< General Category type is "Letter, Other".
  e_GeneralCategory_Mn,            //!< General Category type is "Mark, Nonspacing".
  e_GeneralCategory_Mc,            //!< General Category type is "Mark, Spacing Combining".
  e_GeneralCategory_Me,            //!< General Category type is "Mark, Enclosing".
  e_GeneralCategory_Nd,            //!< General Category type is "Number, Decimal Digit".
  e_GeneralCategory_Nl,            //!< General Category type is "Number, Letter".
  e_GeneralCategory_No,            //!< General Category type is "Number, Other".
  e_GeneralCategory_Pc,            //!< General Category type is "Punctuation, Connector".
  e_GeneralCategory_Pd,            //!< General Category type is "Punctuation, Dash".
  e_GeneralCategory_Ps,            //!< General Category type is "Punctuation, Open".
  e_GeneralCategory_Pe,            //!< General Category type is "Punctuation, Close".
  e_GeneralCategory_Pi,            //!< General Category type is "Punctuation, Initial quote (may behave like Ps or Pe depending on usage)".
  e_GeneralCategory_Pf,            //!< General Category type is "Punctuation, Final quote (may behave like Ps or Pe depending on usage)".
  e_GeneralCategory_Po,            //!< General Category type is "Punctuation, Other".
  e_GeneralCategory_Sm,            //!< General Category type is "Symbol, Math".
  e_GeneralCategory_Sc,            //!< General Category type is "Symbol, Currency".
  e_GeneralCategory_Sk,            //!< General Category type is "Symbol, Modifier".
  e_GeneralCategory_So,            //!< General Category type is "Symbol, Other".
  e_GeneralCategory_Zs,            //!< General Category type is "Separator, Space".
  e_GeneralCategory_Zl,            //!< General Category type is "Separator, Line".
  e_GeneralCategory_Zp,            //!< General Category type is "Separator, Paragraph".
  e_GeneralCategory_Cc,            //!< General Category type is "Other, Control".
  e_GeneralCategory_Cf,            //!< General Category type is "Other, Format".
  e_GeneralCategory_Cs,            //!< General Category type is "Other, Surrogate".
  e_GeneralCategory_Co,            //!< General Category type is "Other, Private Use".
  e_GeneralCategory_Cn             //!< General Category type is "Other, Not Assigned (no characters in the file have this property)".
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
//! Serialization load of the EGeneralCategory value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EGeneralCategory instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EGeneralCategory& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save of the EGeneralCategory value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized EGeneralCategory instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EGeneralCategory& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize EGeneralCategory value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EGeneralCategory instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EGeneralCategory& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/UCD/EGeneralCategory.inl>
/*==========================================================================*/
#endif
