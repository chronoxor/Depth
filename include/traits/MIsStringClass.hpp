/*!
 *  \file    MIsStringClass.hpp Traits meta-class that helps to check if
 *           given type is a string class.
 *  \brief   Traits meta-class: string class checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.05.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: string class checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   06.05.2008 21:02:51

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
#ifndef __MISSTRINGCLASS_HPP__
#define __MISSTRINGCLASS_HPP__
/*==========================================================================*/
#include <Depth/include/string/CString.hpp>
#include <Depth/include/traits/MTypeTrue.hpp>
#include <Depth/include/traits/MTypeFalse.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: string class checking trait.
/*!
    Traits meta-class checks if template argument  is  a  string  class.  Here
    comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsStringClass<char*>::yes                                    false
    MIsStringClass<CStringASCII>::yes                             true
    MIsStringClass<CStringUnicode>::yes                           true
    MIsStringClass<CSystemString>::yes                            true
*/
template <typename T_Type>
class MIsStringClass :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (ASCII string specialization).
template <>
class MIsStringClass<NString::CStringASCII> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (constant ASCII string specialization).
template <>
class MIsStringClass<const NString::CStringASCII> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (volatile ASCII string specialization).
template <>
class MIsStringClass<volatile NString::CStringASCII> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (constant volatile ASCII string specialization).
template <>
class MIsStringClass<const volatile NString::CStringASCII> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (Unicode string specialization).
template <>
class MIsStringClass<NString::CStringUnicode> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (constant Unicode string specialization).
template <>
class MIsStringClass<const NString::CStringUnicode> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (volatile Unicode string specialization).
template <>
class MIsStringClass<volatile NString::CStringUnicode> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (constant volatile Unicode string specialization).
template <>
class MIsStringClass<const volatile NString::CStringUnicode> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (system string specialization).
template <>
class MIsStringClass<NString::CSystemString> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (constant system string specialization).
template <>
class MIsStringClass<const NString::CSystemString> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (volatile system string specialization).
template <>
class MIsStringClass<volatile NString::CSystemString> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: string class checking trait (constant volatile system string specialization).
template <>
class MIsStringClass<const volatile NString::CSystemString> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
