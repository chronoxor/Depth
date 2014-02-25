/*!
 *  \file    MIsBaseOfHelper.hpp Traits helper meta-class that helps to check
 *           if given types are base and derived classes.
 *  \brief   Traits helper meta-class: base class of derived checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits helper meta-class: base class of derived checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits details
    VERSION:   1.0
    CREATED:   15.12.2006 02:29:36

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
#ifndef __MISBASEOFHELPER_HPP__
#define __MISBASEOFHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MRemoveConstOrVolatile.hpp>
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
//! Traits helper meta-class: base class of derived checking trait.
/*!
    Traits helper meta-class checks if template arguments are base and derived
    classes.
*/
template <class T_Base, class T_Derived>
class MIsBaseOfHelper :
  public NDepth::NCommon::IStatic
{
  //! Base class type without constant and volatile qualifiers.
  typedef typename MRemoveConstOrVolatile<T_Base>::type TNoCVBase;
  //! Derived class type without constant and volatile qualifiers.
  typedef typename MRemoveConstOrVolatile<T_Derived>::type TNoCVDerived;

  //! One byte structure type.
  struct SOneByteStruct { Tbyte m_Value; };
  //! Two byte structure type.
  struct STwoByteStruct { Tbyte m_Value[2]; };

  //! Derived checker.
  template<typename T_Type>
  static SOneByteStruct BaseOfChecker(TNoCVDerived&, T_Type);
  //! Base checker.
  static STwoByteStruct BaseOfChecker(TNoCVBase&, Tsint);

  //! Base-derived checker structure.
  struct SBaseDerivedChecker
  {
    operator TNoCVBase& () const;
    operator TNoCVDerived& ();
  };

public:
  static const Tbool yes = (sizeof(BaseOfChecker(SBaseDerivedChecker(), (Tsint)0)) == sizeof(SOneByteStruct));
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
