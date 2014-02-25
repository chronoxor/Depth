/*!
 *  \file    CCanonicalCombiningClass.cpp Character Canonical Combining class.
 *  \brief   Character Canonical Combining class (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Character Canonical Combining class (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unicode Character Database (UCD).
    VERSION:   1.0
    CREATED:   02.04.2009 22:45:54

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
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/string/UCD/CCanonicalCombiningClass.hpp>
/*==========================================================================*/
#ifndef __CCANONICALCOMBININGCLASS_CPP__
#define __CCANONICALCOMBININGCLASS_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NUCD {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_Spacing             = 0;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_Overlays            = 1;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_Nuktas              = 7;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_VoicingMarks        = 8;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_Viramas             = 9;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_StartFixedPosition  = 10;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_EndFixedPosition    = 199;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_BelowLeftAttached   = 200;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_BelowAttached       = 202;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_BelowRightAttached  = 204;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_LeftAttached        = 208;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_RightAttached       = 210;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_AboveLeftAttached   = 212;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_AboveAttached       = 214;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_AboveRightAttached  = 216;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_BelowLeft           = 218;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_Below               = 220;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_BelowRight          = 222;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_Left                = 224;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_Right               = 226;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_AboveLeft           = 228;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_Above               = 230;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_AboveRight          = 232;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_DoubleBelow         = 233;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_DoubleAbove         = 234;
BASE_API const Tuint08 CCanonicalCombiningClass::CCC_IotaSubscript       = 240;
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
