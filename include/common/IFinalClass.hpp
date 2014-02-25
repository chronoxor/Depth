/*!
 *  \file    IFinalClass.hpp Interface for all final inherited classes. If
 *           class closes hierarchy leaf, it should be a final class.
 *  \brief   Final inherited interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Final inherited interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common
    VERSION:   1.0
    CREATED:   12.12.2006 00:37:56

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
#ifndef __IFINALCLASS_HPP__
#define __IFINALCLASS_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* INTERFACE DECLARATIONS                                                   */
/*==========================================================================*/
//! Final inherited interface.
/*!
    Forcing class to be final inherited class which closes hierarchy leaf. The
    following example shows how to use the final class approach.

    Example:
    \code
    class A {};
    class B : public A, virtual private IFinalClass {};
    // Error: class C : public B {};

    int main(int argc, char* argv[])
    {
      A a;
      B b;
      // Error: C c;
      return 0;
    }
    \endcode
*/
class BASE_API IFinalClass
{
protected:
  //! Default interface protected constructor.
  IFinalClass();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/common/IFinalClass.inl>
/*==========================================================================*/
//! \example example-common-IFinalClass.cpp
/*==========================================================================*/
#endif
