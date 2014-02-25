/*!
 *  \file    MIsPolymorphicHelper.hpp Traits helper meta-class that helps to
 *           check if given type is a polymorphic type.
 *  \brief   Traits helper meta-class: polymorphic type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    08.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits helper meta-class: polymorphic type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits details
    VERSION:   1.0
    CREATED:   08.05.2006 00:43:54

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
#ifndef __MISPOLYMORPHICHELPER_HPP__
#define __MISPOLYMORPHICHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MRemoveConstAndVolatile.hpp>
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
//! Traits helper meta-class: polymorphic type checking trait.
/*!
    Traits helper meta-class checks if  template  argument  is  a  polymorphic
    type.
*/
template <typename T_Type>
class MIsPolymorphicHelper :
  public NDepth::NCommon::IStatic
{
private:
  //! Non polymorphic base check type.
  class CType1 :
    public MRemoveConstAndVolatile<T_Type>::type
  {
  public:
    CType1();
  };

  //! Polymorphic base check type.
  class CType2 :
    public MRemoveConstAndVolatile<T_Type>::type
  {
  public:
    CType2();
    virtual ~CType2();
    virtual void dummy();
  };

public:
  static const Tbool yes = (sizeof(CType1) == sizeof(CType2));
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
