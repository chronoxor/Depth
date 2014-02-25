/*!
 *  \file    MAddPointerVolatile.hpp Traits meta-class that helps to add
 *           'volatile' pointer qualifier to template parameter.
 *  \brief   Traits meta-class: adds 'volatile' pointer qualifier.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: adds 'volatile' pointer qualifier.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   09.03.2006 22:55:33

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
#ifndef __MADDPOINTERVOLATILE_HPP__
#define __MADDPOINTERVOLATILE_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MRemoveReference.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: adds 'volatile' pointer qualifier.
/*!
    Traits meta-class adds 'volatile' pointer qualifier to the given type  and
    put transformed type to  the  result  meta-class  type.  Here  comes  some
    examples of transformations:

    Expression:                                           Result type:
    MAddPointerVolatile<int>::type                        int* volatile
    MAddPointerVolatile<int&>::type                       int* volatile
    MAddPointerVolatile<int*>::type                       int** volatile
    MAddPointerVolatile<int const*&>::type                int const** volatile
*/
template <typename T_Type>
class MAddPointerVolatile :
  public MType<typename MRemoveReference<T_Type>::type*>
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
