/*!
 *  \file    MStaticAssertHelper.hpp Helper meta-class that helps to implement
 *           static assertion tester.
 *  \brief   Static assertion helper meta-class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Static assertion helper meta-class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Errors handling details
    VERSION:   1.0
    CREATED:   30.05.2006 20:04:23

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
#ifndef __MSTATICASSERTHELPER_HPP__
#define __MSTATICASSERTHELPER_HPP__
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
//! Static assert test indicator (incomplete general declaration).
/*!
    Incomplete type cannot  be used with 'sizeof()' operator. So if  assertion
    expression falis, then compiler will choose the incomplete assertion  test
    indicator. This will lead to compile error.
*/
template <Tbool t_X>
class MStaticAssertFailure;
/*--------------------------------------------------------------------------*/
//! Static assert test indicator (valid specialization).
/*!
    If assertion expression is true, then  compiler  will  choose  this  valid
    assertion test indicator. This will not lead to compile error.
*/
template <>
class MStaticAssertFailure<true>
{
public:
  Tbool m_Indicator;                    //! Help value to increase indicator size.
};
/*--------------------------------------------------------------------------*/
//! Static assert helper.
/*!
    Static assert helper uses size of assert  test  indicator  as  a  template
    parameter to  determine  state  of  the  given  expression.  If  assertion
    expression fails, compile error will be generated.
*/
template <Tuint t_SizeOfMessage, Tuint t_SizeOfStaticAssertFailure>
class MStaticAssertHelper
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
