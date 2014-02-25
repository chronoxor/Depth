/*!
 *  \file    EJoiningType.hpp Character joining type enumeration.
 *  \brief   Character joining type enumeration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character joining type enumeration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   01.04.2009 22:56:22

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
#ifndef __EJOININGTYPE_HPP__
#define __EJOININGTYPE_HPP__
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
//! Joining type of the character.
/*!
    Basic Arabic and Syriac character joining type.

    Value for each character is taken from "ArabicShaping.txt" file.
*/
enum EJoiningType
{
  e_JoiningType_None,                   //!< Joining type is "None".
  e_JoiningType_Left,                   //!< Joining type is "Left".
  e_JoiningType_Right,                  //!< Joining type is "Right".
  e_JoiningType_Dual,                   //!< Joining type is "Dual".
  e_JoiningType_Causing,                //!< Joining type is "Causing".
  e_JoiningType_Transparent             //!< Joining type is "Transparent".
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
//! Serialization load of the EJoiningType value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EJoiningType instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EJoiningType& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save of the EJoiningType value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized EJoiningType instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EJoiningType& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize EJoiningType value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EJoiningType instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EJoiningType& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/UCD/EJoiningType.inl>
/*==========================================================================*/
#endif
