/*!
 *  \file    MIsEmptyHelper.hpp Traits helper meta-class that helps to check
 *           if given type is an empty class or structure type.
 *  \brief   Traits helper meta-class: empty class or structure type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    13.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits helper meta-class: empty class or structure type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits details
    VERSION:   1.0
    CREATED:   13.12.2006 22:49:25

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
#ifndef __MISEMPTYHELPER_HPP__
#define __MISEMPTYHELPER_HPP__
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
//! Traits helper meta-class: empty class or structure type checking trait.
/*!
    Traits helper meta-class checks if template argument is an empty class  or
    structure type.
*/
template <typename T_Type>
class MIsEmptyHelper :
  public NDepth::NCommon::IStatic
{
  //! Empty class or structure check type.
  template <typename>
  class CType1
  {

  };

  //! Non empty class or structure check type.
  template <typename T_OtherType>
  class CType2 :
    public T_OtherType
  {

  };

public:
  static const Tbool yes = (sizeof(CType1<T_Type>) == sizeof(CType2<T_Type>));
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
