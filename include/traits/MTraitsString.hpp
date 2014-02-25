/*!
 *  \file    MTraitsString.hpp Traits meta-class that helps to determine
 *           string's attributes.
 *  \brief   Traits meta-class: string's traits.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: string's traits.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   13.04.2009 02:29:23

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
#ifndef __MTRAITSSTRING_HPP__
#define __MTRAITSSTRING_HPP__
/*==========================================================================*/
#include <Depth/include/string/CCharacter.hpp>
#include <Depth/include/string/CString.hpp>
#include <Depth/include/traits/MTraitsCharacter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: string's traits.
/*!
    Traits meta-class helps to determine string's attributes.
*/
template <typename T_Type>
class MTraitsString :
  public MType<T_Type>
{
public:
  static const Tbool isValid = false;                 //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = false;                //!< If given type is a system string type.

  //! String character type.
  typedef T_Type character;
  //! String unsigned character type.
  typedef T_Type ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (single byte string specialization).
template <>
class MTraitsString<Tschar*> :
  public MType<Tschar*>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant single byte string specialization).
template <>
class MTraitsString<const Tschar*> :
  public MType<Tschar*>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (volatile single byte string specialization).
template <>
class MTraitsString<volatile Tschar*> :
  public MType<Tschar*>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant volatile single byte string specialization).
template <>
class MTraitsString<const volatile Tschar*> :
  public MType<Tschar*>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (single byte string array specialization).
template <>
class MTraitsString<Tschar[]> :
  public MType<Tschar[]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant single byte string array specialization).
template <>
class MTraitsString<const Tschar[]> :
  public MType<Tschar[]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (volatile single byte string array specialization).
template <>
class MTraitsString<volatile Tschar[]> :
  public MType<Tschar[]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant volatile single byte string array specialization).
template <>
class MTraitsString<const volatile Tschar[]> :
  public MType<Tschar[]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (single byte fixed-size string array specialization).
template <Tuint t_N>
class MTraitsString<Tschar[t_N]> :
  public MType<Tschar[t_N]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant single byte fixed-size string array specialization).
template <Tuint t_N>
class MTraitsString<const Tschar[t_N]> :
  public MType<Tschar[t_N]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (volatile single byte fixed-size string array specialization).
template <Tuint t_N>
class MTraitsString<volatile Tschar[t_N]> :
  public MType<Tschar[t_N]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant volatile single byte fixed-size string array specialization).
template <Tuint t_N>
class MTraitsString<const volatile Tschar[t_N]> :
  public MType<Tschar[t_N]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef Tschar character;
  //! String unsigned character type.
  typedef Tscharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (wide string specialization).
template <>
class MTraitsString<Twchar*> :
  public MType<Twchar*>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant wide string specialization).
template <>
class MTraitsString<const Twchar*> :
  public MType<Twchar*>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (volatile wide string specialization).
template <>
class MTraitsString<volatile Twchar*> :
  public MType<Twchar*>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant volatile wide string specialization).
template <>
class MTraitsString<const volatile Twchar*> :
  public MType<Twchar*>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (wide string array specialization).
template <>
class MTraitsString<Twchar[]> :
  public MType<Twchar[]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant wide string array specialization).
template <>
class MTraitsString<const Twchar[]> :
  public MType<Twchar[]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (volatile wide string array specialization).
template <>
class MTraitsString<volatile Twchar[]> :
  public MType<Twchar[]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant volatile wide string array specialization).
template <>
class MTraitsString<const volatile Twchar[]> :
  public MType<Twchar[]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (wide fixed-size string array specialization).
template <Tuint t_N>
class MTraitsString<Twchar[t_N]> :
  public MType<Twchar[t_N]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant wide fixed-size string array specialization).
template <Tuint t_N>
class MTraitsString<const Twchar[t_N]> :
  public MType<Twchar[t_N]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (volatile wide fixed-size string array specialization).
template <Tuint t_N>
class MTraitsString<volatile Twchar[t_N]> :
  public MType<Twchar[t_N]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant volatile wide fixed-size string array specialization).
template <Tuint t_N>
class MTraitsString<const volatile Twchar[t_N]> :
  public MType<Twchar[t_N]>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = true;             //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = false;           //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef Twchar character;
  //! String unsigned character type.
  typedef Twcharu ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (ASCII string specialization).
template <>
class MTraitsString<NString::CStringASCII> :
  public MType<NString::CStringASCII>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef MTraitsCharacter<NString::CStringASCII::TType>::character character;
  //! String unsigned character type.
  typedef MTraitsCharacter<NString::CStringASCII::TType>::ucharacter ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant ASCII string specialization).
template <>
class MTraitsString<const NString::CStringASCII> :
  public MType<NString::CStringASCII>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef MTraitsCharacter<NString::CStringASCII::TType>::character character;
  //! String unsigned character type.
  typedef MTraitsCharacter<NString::CStringASCII::TType>::ucharacter ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (volatile ASCII string specialization).
template <>
class MTraitsString<volatile NString::CStringASCII> :
  public MType<NString::CStringASCII>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef MTraitsCharacter<NString::CStringASCII::TType>::character character;
  //! String unsigned character type.
  typedef MTraitsCharacter<NString::CStringASCII::TType>::ucharacter ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant volatile ASCII string specialization).
template <>
class MTraitsString<const volatile NString::CStringASCII> :
  public MType<NString::CStringASCII>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = true;                  //!< If given type is an ASCII string type.
  static const Tbool isUnicode = false;               //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_ASCII;    //!< If given type is a system string type.

  //! String character type.
  typedef MTraitsCharacter<NString::CStringASCII::TType>::character character;
  //! String unsigned character type.
  typedef MTraitsCharacter<NString::CStringASCII::TType>::ucharacter ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (Unicode string specialization).
template <>
class MTraitsString<NString::CStringUnicode> :
  public MType<NString::CStringUnicode>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef MTraitsCharacter<NString::CStringUnicode::TType>::character character;
  //! String unsigned character type.
  typedef MTraitsCharacter<NString::CStringUnicode::TType>::ucharacter ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant Unicode string specialization).
template <>
class MTraitsString<const NString::CStringUnicode> :
  public MType<NString::CStringUnicode>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef MTraitsCharacter<NString::CStringUnicode::TType>::character character;
  //! String unsigned character type.
  typedef MTraitsCharacter<NString::CStringUnicode::TType>::ucharacter ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (volatile Unicode string specialization).
template <>
class MTraitsString<volatile NString::CStringUnicode> :
  public MType<NString::CStringUnicode>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef MTraitsCharacter<NString::CStringUnicode::TType>::character character;
  //! String unsigned character type.
  typedef MTraitsCharacter<NString::CStringUnicode::TType>::ucharacter ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant volatile Unicode string specialization).
template <>
class MTraitsString<const volatile NString::CStringUnicode> :
  public MType<NString::CStringUnicode>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = false;                 //!< If given type is an ASCII string type.
  static const Tbool isUnicode = true;                //!< If given type is an Unicode string type.
  static const Tbool isSystem = SYS_CHAR_IS_UNICODE;  //!< If given type is a system string type.

  //! String character type.
  typedef MTraitsCharacter<NString::CStringUnicode::TType>::character character;
  //! String unsigned character type.
  typedef MTraitsCharacter<NString::CStringUnicode::TType>::ucharacter ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (system string specialization).
template <>
class MTraitsString<NString::CSystemString> :
  public MType<NString::CSystemString>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = SYS_CHAR_IS_ASCII;     //!< If given type is an ASCII string type.
  static const Tbool isUnicode = SYS_CHAR_IS_UNICODE; //!< If given type is an Unicode string type.
  static const Tbool isSystem = true;                 //!< If given type is a system string type.

  //! String character type.
  typedef Tbyte character;
  //! String unsigned character type.
  typedef Tbyte ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant system string specialization).
template <>
class MTraitsString<const NString::CSystemString> :
  public MType<NString::CSystemString>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = false;              //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = SYS_CHAR_IS_ASCII;     //!< If given type is an ASCII string type.
  static const Tbool isUnicode = SYS_CHAR_IS_UNICODE; //!< If given type is an Unicode string type.
  static const Tbool isSystem = true;                 //!< If given type is a system string type.

  //! String character type.
  typedef Tbyte character;
  //! String unsigned character type.
  typedef Tbyte ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (volatile system string specialization).
template <>
class MTraitsString<volatile NString::CSystemString> :
  public MType<NString::CSystemString>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = false;                 //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = SYS_CHAR_IS_ASCII;     //!< If given type is an ASCII string type.
  static const Tbool isUnicode = SYS_CHAR_IS_UNICODE; //!< If given type is an Unicode string type.
  static const Tbool isSystem = true;                 //!< If given type is a system string type.

  //! String character type.
  typedef Tbyte character;
  //! String unsigned character type.
  typedef Tbyte ucharacter;
};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string's traits (constant volatile system string specialization).
template <>
class MTraitsString<const volatile NString::CSystemString> :
  public MType<NString::CSystemString>
{
public:
  static const Tbool isValid = true;                  //!< If given type is a valid string type.
  static const Tbool isConst = true;                  //!< If given type is a constant string type.
  static const Tbool isVolatile = true;               //!< If given type is a volatile string type.
  static const Tbool isStringType = false;            //!< If given type is a base 'C' string type.
  static const Tbool isStringClass = true;            //!< If given type is a string class.
  static const Tbool isASCII = SYS_CHAR_IS_ASCII;     //!< If given type is an ASCII string type.
  static const Tbool isUnicode = SYS_CHAR_IS_UNICODE; //!< If given type is an Unicode string type.
  static const Tbool isSystem = true;                 //!< If given type is a system string type.

  //! String character type.
  typedef Tbyte character;
  //! String unsigned character type.
  typedef Tbyte ucharacter;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
