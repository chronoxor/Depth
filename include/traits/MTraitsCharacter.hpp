/*!
 *  \file    MTraitsCharacter.hpp Traits meta-class that helps to determine
 *           character's attributes.
 *  \brief   Traits meta-class: character's traits.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: character's traits.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   13.04.2009 02:15:49

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
#ifndef __MTRAITSCHARACTER_HPP__
#define __MTRAITSCHARACTER_HPP__
/*==========================================================================*/
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/traits/MType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: character's traits.
/*!
    Traits meta-class helps to determine character's attributes.
*/
template <typename T_Type>
class MTraitsCharacter :
  public MType<T_Type>
{
public:
  static const Tbool isValid = false;                //!< If given type is a valid character type.
  static const Tbool isConst = false;                //!< If given type is a constant character type.
  static const Tbool isVolatile = false;             //!< If given type is a volatile character type.
  static const Tbool isASCII = false;                //!< If given type is an ASCII character type.
  static const Tbool isUnicode = false;              //!< If given type is an Unicode character type.
  static const Tbool isSystem = false;               //!< If given type is a system character type.

  //! Character type.
  typedef T_Type character;
  //! Unsigned character type.
  typedef T_Type ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: character's traits (ASCII character specialization).
template <>
class MTraitsCharacter<Tschar> :
  public MType<Tschar>
{
public:
  static const Tbool isValid = true;                 //!< If given type is a valid character type.
  static const Tbool isConst = false;                //!< If given type is a constant character type.
  static const Tbool isVolatile = false;             //!< If given type is a volatile character type.
  static const Tbool isASCII = true;                 //!< If given type is an ASCII character type.
  static const Tbool isUnicode = false;              //!< If given type is an Unicode character type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;   //!< If given type is a system character type.

  //! Character type.
  typedef Tschar character;
  //! Unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: character's traits (constant ASCII character specialization).
template <>
class MTraitsCharacter<const Tschar> :
  public MType<Tschar>
{
public:
  static const Tbool isValid = true;                 //!< If given type is a valid character type.
  static const Tbool isConst = true;                 //!< If given type is a constant character type.
  static const Tbool isVolatile = false;             //!< If given type is a volatile character type.
  static const Tbool isASCII = true;                 //!< If given type is an ASCII character type.
  static const Tbool isUnicode = false;              //!< If given type is an Unicode character type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;   //!< If given type is a system character type.

  //! Character type.
  typedef Tschar character;
  //! Unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: character's traits (volatile ASCII character specialization).
template <>
class MTraitsCharacter<volatile Tschar> :
  public MType<Tschar>
{
public:
  static const Tbool isValid = true;                 //!< If given type is a valid character type.
  static const Tbool isConst = false;                //!< If given type is a constant character type.
  static const Tbool isVolatile = true;              //!< If given type is a volatile character type.
  static const Tbool isASCII = true;                 //!< If given type is an ASCII character type.
  static const Tbool isUnicode = false;              //!< If given type is an Unicode character type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;   //!< If given type is a system character type.

  //! Character type.
  typedef Tschar character;
  //! Unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: character's traits (constant volatile ASCII character specialization).
template <>
class MTraitsCharacter<const volatile Tschar> :
  public MType<Tschar>
{
public:
  static const Tbool isValid = true;                 //!< If given type is a valid character type.
  static const Tbool isConst = true;                 //!< If given type is a constant character type.
  static const Tbool isVolatile = true;              //!< If given type is a volatile character type.
  static const Tbool isASCII = true;                 //!< If given type is an ASCII character type.
  static const Tbool isUnicode = false;              //!< If given type is an Unicode character type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;   //!< If given type is a system character type.

  //! Character type.
  typedef Tschar character;
  //! Unsigned character type.
  typedef Tscharu ucharacter;
};
/*-------------------------------------------------------------------------*/
//! Traits meta-class: character's traits (Unicode character specialization).
template <>
class MTraitsCharacter<Twchar> :
  public MType<Twchar>
{
public:
  static const Tbool isValid = true;                 //!< If given type is a valid character type.
  static const Tbool isConst = false;                //!< If given type is a constant character type.
  static const Tbool isVolatile = false;             //!< If given type is a volatile character type.
  static const Tbool isASCII = false;                //!< If given type is an ASCII character type.
  static const Tbool isUnicode = true;               //!< If given type is an Unicode character type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE; //!< If given type is a system character type.

  //! Character type.
  typedef Twchar character;
  //! Unsigned character type.
  typedef Twcharu ucharacter;
};
/*-------------------------------------------------------------------------*/
//! Traits meta-class: character's traits (constant Unicode character specialization).
template <>
class MTraitsCharacter<const Twchar> :
  public MType<Twchar>
{
public:
  static const Tbool isValid = true;                 //!< If given type is a valid character type.
  static const Tbool isConst = true;                 //!< If given type is a constant character type.
  static const Tbool isVolatile = false;             //!< If given type is a volatile character type.
  static const Tbool isASCII = false;                //!< If given type is an ASCII character type.
  static const Tbool isUnicode = true;               //!< If given type is an Unicode character type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE; //!< If given type is a system character type.

  //! Character type.
  typedef Twchar character;
  //! Unsigned character type.
  typedef Twcharu ucharacter;
};
/*-------------------------------------------------------------------------*/
//! Traits meta-class: character's traits (volatile Unicode character specialization).
template <>
class MTraitsCharacter<volatile Twchar> :
  public MType<Twchar>
{
public:
  static const Tbool isValid = true;                 //!< If given type is a valid character type.
  static const Tbool isConst = false;                //!< If given type is a constant character type.
  static const Tbool isVolatile = true;              //!< If given type is a volatile character type.
  static const Tbool isASCII = false;                //!< If given type is an ASCII character type.
  static const Tbool isUnicode = true;               //!< If given type is an Unicode character type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE; //!< If given type is a system character type.

  //! Character type.
  typedef Twchar character;
  //! Unsigned character type.
  typedef Twcharu ucharacter;
};
/*-------------------------------------------------------------------------*/
//! Traits meta-class: character's traits (constant volatile Unicode character specialization).
template <>
class MTraitsCharacter<const volatile Twchar> :
  public MType<Twchar>
{
public:
  static const Tbool isValid = true;                 //!< If given type is a valid character type.
  static const Tbool isConst = true;                 //!< If given type is a constant character type.
  static const Tbool isVolatile = true;              //!< If given type is a volatile character type.
  static const Tbool isASCII = false;                //!< If given type is an ASCII character type.
  static const Tbool isUnicode = true;               //!< If given type is an Unicode character type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE; //!< If given type is a system character type.

  //! Character type.
  typedef Twchar character;
  //! Unsigned character type.
  typedef Twcharu ucharacter;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
