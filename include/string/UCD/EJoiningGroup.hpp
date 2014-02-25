/*!
 *  \file    EJoiningGroup.hpp Character joining group enumeration.
 *  \brief   Character joining group enumeration.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character joining group enumeration.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   01.04.2009 23:11:42

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
#ifndef __EJOININGGROUP_HPP__
#define __EJOININGGROUP_HPP__
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
//! Joining group of the character.
/*!
    Basic Arabic and Syriac character joining group.

    Value for each character is taken from "ArabicShaping.txt" file.
*/
enum EJoiningGroup
{
  e_JoiningGroup_None,                  //!< Joining group is "None".
  e_JoiningGroup_Ain,                   //!< Joining group is "Ain".
  e_JoiningGroup_Alaph,                 //!< Joining group is "Alaph".
  e_JoiningGroup_Alef,                  //!< Joining group is "Alef".
  e_JoiningGroup_Beh,                   //!< Joining group is "Beh".
  e_JoiningGroup_Beth,                  //!< Joining group is "Beth".
  e_JoiningGroup_Burushaski_Yeh_Barree, //!< Joining group is "Burushaski Yeh Barree".
  e_JoiningGroup_Dal,                   //!< Joining group is "Dal".
  e_JoiningGroup_Dalath_Rish,           //!< Joining group is "Dalath Rish".
  e_JoiningGroup_E,                     //!< Joining group is "E".
  e_JoiningGroup_Farsi_Yeh,             //!< Joining group is "Farsi Yeh".
  e_JoiningGroup_Fe,                    //!< Joining group is "Fe".
  e_JoiningGroup_Feh,                   //!< Joining group is "Feh".
  e_JoiningGroup_Final_Semkath,         //!< Joining group is "Final Semkath".
  e_JoiningGroup_Gaf,                   //!< Joining group is "Gaf".
  e_JoiningGroup_Gamal,                 //!< Joining group is "Gamal".
  e_JoiningGroup_Hah,                   //!< Joining group is "Hah".
  e_JoiningGroup_Hamza_On_Heh_Goal,     //!< Joining group is "Hamza On Heh Goal".
  e_JoiningGroup_He,                    //!< Joining group is "He".
  e_JoiningGroup_Heh,                   //!< Joining group is "Heh".
  e_JoiningGroup_Heh_Goal,              //!< Joining group is "Heh Goal".
  e_JoiningGroup_Heth,                  //!< Joining group is "Heth".
  e_JoiningGroup_Kaf,                   //!< Joining group is "Kaf".
  e_JoiningGroup_Kaph,                  //!< Joining group is "Kaph".
  e_JoiningGroup_Khaph,                 //!< Joining group is "Khaph".
  e_JoiningGroup_Knotted_Heh,           //!< Joining group is "Knotted Heh".
  e_JoiningGroup_Lam,                   //!< Joining group is "Lam".
  e_JoiningGroup_Lamadh,                //!< Joining group is "Lamadh".
  e_JoiningGroup_Meem,                  //!< Joining group is "Meem".
  e_JoiningGroup_Mim,                   //!< Joining group is "Mim".
  e_JoiningGroup_Noon,                  //!< Joining group is "Noon".
  e_JoiningGroup_Nun,                   //!< Joining group is "Nun".
  e_JoiningGroup_Nya,                   //!< Joining group is "Nya".
  e_JoiningGroup_Pe,                    //!< Joining group is "Pe".
  e_JoiningGroup_Qaf,                   //!< Joining group is "Qaf".
  e_JoiningGroup_Qaph,                  //!< Joining group is "Qaph".
  e_JoiningGroup_Reh,                   //!< Joining group is "Reh".
  e_JoiningGroup_Reversed_Pe,           //!< Joining group is "Reversed Pe".
  e_JoiningGroup_Sad,                   //!< Joining group is "Sad".
  e_JoiningGroup_Sadhe,                 //!< Joining group is "Sadhe".
  e_JoiningGroup_Seen,                  //!< Joining group is "Seen".
  e_JoiningGroup_Semkath,               //!< Joining group is "Semkath".
  e_JoiningGroup_Shin,                  //!< Joining group is "Shin".
  e_JoiningGroup_Swash_Kaf,             //!< Joining group is "Swash Kaf".
  e_JoiningGroup_Syriac_Waw,            //!< Joining group is "Syriac Waw".
  e_JoiningGroup_Tah,                   //!< Joining group is "Tah".
  e_JoiningGroup_Taw,                   //!< Joining group is "Taw".
  e_JoiningGroup_Teh_Marbuta,           //!< Joining group is "Teh Marbuta".
  e_JoiningGroup_Teth,                  //!< Joining group is "Teth".
  e_JoiningGroup_Waw,                   //!< Joining group is "Waw".
  e_JoiningGroup_Yeh,                   //!< Joining group is "Yeh".
  e_JoiningGroup_Yeh_Barree,            //!< Joining group is "Yeh Barree".
  e_JoiningGroup_Yeh_With_Tail,         //!< Joining group is "Yeh With Tail".
  e_JoiningGroup_Yudh,                  //!< Joining group is "Yudh".
  e_JoiningGroup_Yudh_He,               //!< Joining group is "Yudh He".
  e_JoiningGroup_Zain,                  //!< Joining group is "Zain".
  e_JoiningGroup_Zhain                  //!< Joining group is "Zhain".
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
//! Serialization load of the EJoiningGroup value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EJoiningGroup instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool load(T_Archive& a_rArchive, NString::NUCD::EJoiningGroup& a_rInstance);
/*--------------------------------------------------------------------------*/
//! Serialization save of the EJoiningGroup value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_crInstance - Constant reference to the serialized EJoiningGroup instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool save(T_Archive& a_rArchive, const NString::NUCD::EJoiningGroup& a_crInstance);
/*--------------------------------------------------------------------------*/
//! Serialize EJoiningGroup value.
/*!
    \param a_rArchive - Reference to the serialization archive.
    \param a_rInstance - Reference to the serialized EJoiningGroup instance.
    \return true  - if serialization has been successfully done. \n
            false - if serialization has not been successfully done. \n
*/
template <class T_Archive>
Tbool serialize(T_Archive& a_rArchive, NString::NUCD::EJoiningGroup& a_rInstance);
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/string/UCD/EJoiningGroup.inl>
/*==========================================================================*/
#endif
