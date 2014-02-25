/*!
 *  \file    MAddFunctionPtr.hpp.tpl Traits meta-class that helps to add
 *           pointer qualifier to the function template parameter. Version
 *           with DEF_FUNCTION_ARITY arguments.
 *  \brief   Traits meta-class: add function pointer qualifier. Version with DEF_FUNCTION_ARITY arguments (template header).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.11.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: add function pointer qualifier. Version with DEF_FUNCTION_ARITY arguments (template header).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits details (templates)
    VERSION:   1.0
    CREATED:   27.11.2006 21:28:54

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
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: add function pointer qualifier (version with DEF_FUNCTION_ARITY arguments).
/*!
    This class specialize function's traits with DEF_FUNCTION_ARITY arguments.
*/
template <DEF_TEMPLATE_DECLARATION>
class MAddFunctionPtr<DEF_TEMPLATE_SPECIALIZATION> :
  public MType<DEF_TEMPLATE_TRAITS>
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
