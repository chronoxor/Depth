/*!
 *  \file    MRequiresConceptX.hpp General declaration of the meta-class for
 *           conception checking.
 *  \brief   General meta-class for conception checking.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    18.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: General meta-class for conception checking.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Conception checking details (templates)
    VERSION:   1.0
    CREATED:   18.01.2006 20:08:34

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
#ifndef __MREQUIRESCONCEPTX_HPP__
#define __MREQUIRESCONCEPTX_HPP__
/*==========================================================================*/
#include <Depth/include/common/IStatic.hpp>
#include <Depth/include/concept/MConstraint.hpp>
#include <Depth/include/concept/MConcept.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! General meta-class for checking conseption.
/*!
    Now  checking  algorithm  supports  only  14  template   arguments.   This
    meta-class has private  constructor,  so  you  cannot  use  more  than  14
    template arguments. It will lead to compiler error if you try.

    Other versions of the same class uses template specialization to implement
    checking algorithm.
*/
template <class T_Concept, typename T_Type1 = void, typename T_Type2 = void, typename T_Type3 = void, typename T_Type4 = void, typename T_Type5 = void, typename T_Type6 = void, typename T_Type7 = void, typename T_Type8 = void, typename T_Type9 = void, typename T_Type10 = void, typename T_Type11 = void, typename T_Type12 = void, typename T_Type13 = void, typename T_Type14 = void, typename T_Unused = void>
class MRequiresConcept :
  public NDepth::NCommon::IStatic
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
