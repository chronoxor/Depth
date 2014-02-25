/*!
 *  \file    FUnitTestSameBuffers.hpp Helper function that checks if two
 *           buffers have the same content.
 *  \brief   Unit test same buffers helper function.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    31.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test same buffers helper function.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unit test details
    VERSION:   1.0
    CREATED:   31.01.2009 21:59:18

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
#ifndef __FUNITTESTSAMEBUFFERS_HPP__
#define __FUNITTESTSAMEBUFFERS_HPP__
/*==========================================================================*/
#include <Depth/include/unit.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* FUNCTION DECLARATIONS                                                    */
/*==========================================================================*/
//! Unit test same buffers helper function.
/*!
    Function checks if two buffers have the same content.

    \param a_cpBuffer1 - Constant pointer to the first buffer.
    \param a_cpBuffer2 - Constant pointer to the second buffer.
    \param a_cSize - Size of the buffers.
    \return true  - if two buffers have the same content. \n
            false - if two buffers do not have the same content. \n
*/
UNITTEST_API Tbool unitTestSameBuffers(NDepth::NTypes::Tcbuffer a_cpBuffer1, NDepth::NTypes::Tcbuffer a_cpBuffer2, const Tuint a_cSize);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
