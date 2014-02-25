/*!
 *  \file    MIsConvertibleHelper.hpp Traits helper meta-class that helps to
 *           check if given types are convertible.
 *  \brief   Traits helper meta-class: convertible types checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits helper meta-class: convertible types derived checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits details
    VERSION:   1.0
    CREATED:   15.12.2006 21:53:39

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
#ifndef __MISCONVERTIBLEHELPER_HPP__
#define __MISCONVERTIBLEHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MIsAnd.hpp>
#include <Depth/include/traits/MIsNot.hpp>
#include <Depth/include/traits/MIsArray.hpp>
#include <Depth/include/traits/MIsConst.hpp>
#include <Depth/include/traits/MIsFunction.hpp>
#include <Depth/include/traits/MIsIntegral.hpp>
#include <Depth/include/traits/MIsReal.hpp>
#include <Depth/include/traits/MIsVolatile.hpp>
#include <Depth/include/traits/MIsVoid.hpp>
#include <Depth/include/traits/MAddReference.hpp>
#include <Depth/include/traits/MRemoveReference.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits helper meta-class: convertible checker.
template <class T_Source, class T_Destination>
class MIsConvertibleChecker :
  public NDepth::NCommon::IStatic
{
  //! One byte structure type.
  struct SOneByteStruct { Tbyte m_Value; };
  //! Two byte structure type.
  struct STwoByteStruct { Tbyte m_Value[2]; };

  //! Successful convertible checker.
  static SOneByteStruct ConvertibleChecker(T_Destination);
  //! Failed convertible checker.
  static STwoByteStruct ConvertibleChecker(...);

  //! Convertible checker maker method.
  static T_Source ConvertibleCheckerMaker();

public:
  static const Tbool yes = (sizeof(ConvertibleChecker(ConvertibleCheckerMaker())) == sizeof(SOneByteStruct));
};
/*--------------------------------------------------------------------------*/
//! Traits helper meta-class: integral or reference type checking trait.
template <typename T_Type>
class MIsIntegralOrReference :
  public MIfThenElse<MIsOr<MIsIntegral<T_Type>::yes, MIsAnd<MIsIntegral<typename MRemoveReference<T_Type>::type>::yes, MIsConst<typename MRemoveReference<T_Type>::type>::yes, MIsNot<MIsVolatile<typename MRemoveReference<T_Type>::type>::yes>::yes>::yes>::yes, MTypeTrue, MTypeFalse>::type
{

};
/*--------------------------------------------------------------------------*/
//! Traits helper meta-class: convertible types checking trait.
/*!
    Traits helper meta-class checks  if  template  arguments  are  convertible
    types.
*/
template <class T_Source, class T_Destination, bool t_SpecialCase = MIsOr<MIsVoid<T_Source>::yes, MIsVoid<T_Destination>::yes, MIsFunction<T_Destination>::yes, MIsArray<T_Destination>::yes, MIsAnd<MIsReal<typename MRemoveReference<T_Source>::type>::yes, MIsIntegralOrReference<T_Destination>::yes>::yes>::yes>
class MIsConvertibleHelper :
  public NDepth::NCommon::IStatic
{
public:
  static const Tbool yes = MIsConvertibleChecker<typename MAddReference<T_Source>::type, T_Destination>::yes;
  static const Tbool no = !MIsConvertibleChecker<typename MAddReference<T_Source>::type, T_Destination>::yes;
};
/*--------------------------------------------------------------------------*/
//! Traits helper meta-class: convertible types checking trait. Special case specialization.
template <class T_Source, class T_Destination>
class MIsConvertibleHelper<T_Source, T_Destination, true> :
  public NDepth::NCommon::IStatic
{
public:
  static const Tbool yes = MIsOr<MIsVoid<T_Destination>::yes, MIsAnd<MIsIntegralOrReference<T_Destination>::yes, MIsNot<MIsVoid<T_Source>::yes>::yes>::yes>::yes;
  static const Tbool no = !MIsOr<MIsVoid<T_Destination>::yes, MIsAnd<MIsIntegralOrReference<T_Destination>::yes, MIsNot<MIsVoid<T_Source>::yes>::yes>::yes>::yes;
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
