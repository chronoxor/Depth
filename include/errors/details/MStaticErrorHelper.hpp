/*!
 *  \file    MStaticErrorHelper.hpp Helper meta-class that helps to implement
 *           static error construction.
 *  \brief   Static error helper meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static error helper meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Errors handling details
    VERSION:   1.0
    CREATED:   31.07.2006 00:52:17

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
#ifndef __MSTATICERRORHELPER_HPP__
#define __MSTATICERRORHELPER_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NErrors {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Static error test indicator.
/*!
    Incomplete type cannot  be used with 'sizeof()' operator, it will lead  to
    compiler error.
*/
class MStaticErrorFailure;
/*--------------------------------------------------------------------------*/
//! Static error helper.
/*!
    Static error helper uses size  of  error  test  indicator  as  a  template
    parameter to determine state of the given expression. Compile  error  will
    be generated.
*/
template <Tuint t_SizeOfMessage, Tuint t_SizeOfStaticErrorFailure>
class MStaticErrorHelper
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
