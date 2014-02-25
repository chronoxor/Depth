/*!
 *  \file    MInArrayHelper.hpp Traits helper meta-class that helps to check
 *           if given type is in array type.
 *  \brief   Traits helper meta-class: in array type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits helper meta-class: in array type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits details
    VERSION:   1.0
    CREATED:   13.12.2006 22:06:22

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
#ifndef __MINARRAYHELPER_HPP__
#define __MINARRAYHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
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
//! Traits helper meta-class: in array type checking trait.
/*!
    Traits helper meta-class checks if template argument is in array type.
*/
template <typename T_Type>
class MInArrayHelper :
  public NDepth::NCommon::IStatic
{
  //! One byte structure type.
  struct SOneByteStruct { Tbyte m_Value; };
  //! Two byte structure type.
  struct STwoByteStruct { Tbyte m_Value[2]; };

  //! In array type checker.
  template <typename T_OtherType>
  static SOneByteStruct InArrayChecker(T_OtherType(*)[1]);
  //! Non in array type checker.
  template <typename>
  static STwoByteStruct& InArrayChecker(...);

public:
  static const Tbool yes = (sizeof(InArrayChecker<T_Type>(0)) == sizeof(SOneByteStruct));
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
