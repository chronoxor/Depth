/*!
 *  \file    EDecompositionMapping.hpp Character decomposition mapping type
 *           enumeration.
 *  \brief   Character decomposition mapping type enumeration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character decomposition mapping type enumeration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 22:11:13

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
#ifndef __EDECOMPOSITIONMAPPING_HPP__
#define __EDECOMPOSITIONMAPPING_HPP__
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
//! Decomposition mapping type of the character.
/*!
    Character decomposition mappings type.

    The tags supplied with certain decomposition mappings  generally  indicate
    formatting information. Where  no  such  tag  is  given,  the  mapping  is
    canonical. Conversely, the presence of a  formatting  tag  also  indicates
    that the mapping is a compatibility mapping and not a  canonical  mapping.
    In the absence of other formatting information in a compatibility mapping,
    the tag is used to distinguish it from canonical mappings.

    In some instances a canonical  mapping  or  a  compatibility  mapping  may
    consist of a single character. For a  canonical  mapping,  this  indicates
    that the character is a canonical equivalent of another single  character.
    For a compatibility mapping,  this  indicates  that  the  character  is  a
    compatibility equivalent of another single character.

    Value for each character is taken from "UnicodeData.txt" file.
*/
enum EDecompositionMapping
{
  e_DecompositionMapping_None,          //!< Decomposition mapping type is "<none>".
  e_DecompositionMapping_Canonical,     //!< Decomposition mapping type is "<canonical>".
  e_DecompositionMapping_Font,          //!< Decomposition mapping type is "<font>". A font variant (e.g. a blackletter form).
  e_DecompositionMapping_NoBreak,       //!< Decomposition mapping type is "<noBreak>". A no-break version of a space or hyphen.
  e_DecompositionMapping_Initial,       //!< Decomposition mapping type is "<initial>". An initial presentation form (Arabic).
  e_DecompositionMapping_Medial,        //!< Decomposition mapping type is "<medial>". A medial presentation form (Arabic).
  e_DecompositionMapping_Final,         //!< Decomposition mapping type is "<final>". A final presentation form (Arabic).
  e_DecompositionMapping_Isolated,      //!< Decomposition mapping type is "<isolated>". An isolated presentation form (Arabic).
  e_DecompositionMapping_Circle,        //!< Decomposition mapping type is "<circle>". An encircled form.
  e_DecompositionMapping_Super,         //!< Decomposition mapping type is "<super>". A superscript form.
  e_DecompositionMapping_Sub,           //!< Decomposition mapping type is "<sub>". A subscript form.
  e_DecompositionMapping_Vertical,      //!< Decomposition mapping type is "<vertical>". A vertical layout presentation form.
  e_DecompositionMapping_Wide,          //!< Decomposition mapping type is "<wide>". A wide (or zenkaku) compatibility character.
  e_DecompositionMapping_Narrow,        //!< Decomposition mapping type is "<narrow>". A narrow (or hankaku) compatibility character.
  e_DecompositionMapping_Small,         //!< Decomposition mapping type is "<small>". A small variant form (CNS compatibility).
  e_DecompositionMapping_Square,        //!< Decomposition mapping type is "<square>". A CJK squared font variant.
  e_DecompositionMapping_Fraction,      //!< Decomposition mapping type is "<fraction>". A vulgar fraction form.
  e_DecompositionMapping_Compat         //!< Decomposition mapping type is "<compat>". Otherwise unspecified compatibility character.
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
//! Serialization load of the EDecompositionMapping value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EDecompositionMapping instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EDecompositionMapping& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save of the EDecompositionMapping value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized EDecompositionMapping instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EDecompositionMapping& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize EDecompositionMapping value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EDecompositionMapping instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EDecompositionMapping& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/UCD/EDecompositionMapping.inl>
/*==========================================================================*/
#endif
