/*!
 *  \file    MIsOr.hpp Traits meta-class that applied logical OR operation to
 *           all given boolean values as a template arguments.
 *  \brief   Traits meta-class: logical OR trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: logical OR trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   10.03.2006 21:10:28

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
#ifndef __MISOR_HPP__
#define __MISOR_HPP__
/*==========================================================================*/
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
//! Traits meta-class: logical OR trait.
/*!
    Traits meta-class applying logical OR  operation  to  all  given  template
    boolean values. After it you can use meta-class  attributes  to  determine
    new boolean state. Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsOr<true, false>::yes                                       true
    MIsOr<true, true, true>::yes                                  true
    MIsOr<true, true, true, true>::no                             false
    MIsOr<false, false, true>::no                                 false

*/
template <Tbool t_Expression1, Tbool t_Expression2, Tbool t_Expression3 = false, Tbool t_Expression4 = false, Tbool t_Expression5 = false, Tbool t_Expression6 = false, Tbool t_Expression7 = false, Tbool t_Expression8 = false, Tbool t_Expression9 = false, Tbool t_Expression10 = false>
class MIsOr :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: logical OR trait ('false' specialization).
template <>
class MIsOr<false, false, false, false, false, false, false, false, false, false> :
  public MTypeFalse
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
